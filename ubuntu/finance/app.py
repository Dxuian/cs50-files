import os
import json
import math
import pandas
from cs50 import SQL
from flask import Flask, flash, redirect, jsonify ,render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from time import time
from helpers import apology, login_required, lookup, usd
import re

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    uid = session["user_id"]
    USER = db.execute("select username from users where id=?",uid)
    BAL= db.execute("select cash from users where id=?",uid)
    holding = db.execute("select * from shares where uid=?",uid)
    for x in holding:
        x["current_price"] = usd(x["current_price"])


    print("                 /::\    \             |:\____\                /::\    \                /::\    \                        /::\    \               /::::\    \               /::\____\                /::\    \            /::\    \                /::\____\                /::\    \                /::\____\                /::\    \                \n\:::\    \            |::|   |               /::::\    \              /::::\    \                      /::::\    \             /::::::\    \             /::::|   |               /::::\    \           \:::\    \              /:::/    /                \:::\    \              /::::|   |               /::::\    \               \n\:::\    \           |::|   |              /::::::\    \            /::::::\    \                    /::::::\    \           /::::::::\    \           /:::::|   |              /::::::\    \           \:::\    \            /:::/    /                  \:::\    \            /:::::|   |              /::::::\    \              \n\:::\    \          |::|   |             /:::/\:::\    \          /:::/\:::\    \                  /:::/\:::\    \         /:::/~~\:::\    \         /::::::|   |             /:::/\:::\    \           \:::\    \          /:::/    /                    \:::\    \          /::::::|   |             /:::/\:::\    \             \n\:::\    \         |::|   |            /:::/__\:::\    \        /:::/__\:::\    \                /:::/__\:::\    \       /:::/    \:::\    \       /:::/|::|   |            /:::/__\:::\    \           \:::\    \        /:::/____/                      \:::\    \        /:::/|::|   |            /:::/  \:::\    \     \n      /::::\    \        |::|   |           /::::\   \:::\    \      /::::\   \:::\    \               \:::\   \:::\    \     /:::/    / \:::\    \     /:::/ |::|   |           /::::\   \:::\    \          /::::\    \      /::::\    \                      /::::\    \      /:::/ |::|   |           /:::/    \:::\    \           \n/::::::\    \       |::|___|______    /::::::\   \:::\    \    /::::::\   \:::\    \            ___\:::\   \:::\    \   /:::/____/   \:::\____\   /:::/  |::|___|______    /::::::\   \:::\    \        /::::::\    \    /::::::\    \   _____    ____    /::::::\    \    /:::/  |::|   | _____    /:::/    / \:::\    \          \n/:::/\:::\    \      /::::::::\    \  /:::/\:::\   \:::\____\  /:::/\:::\   \:::\    \          /\   \:::\   \:::\    \ |:::|    |     |:::|    | /:::/   |::::::::\    \  /:::/\:::\   \:::\    \      /:::/\:::\    \  /:::/\:::\    \ /\    \  /\   \  /:::/\:::\    \  /:::/   |::|   |/\    \  /:::/    /   \:::\ ___\         \n/:::/  \:::\____\    /::::::::::\____\/:::/  \:::\   \:::|    |/:::/__\:::\   \:::\____\        /::\   \:::\   \:::\____\|:::|____|     |:::|    |/:::/    |:::::::::\____\/:::/__\:::\   \:::\____\    /:::/  \:::\____\/:::/  \:::\    /::\____\/::\   \/:::/  \:::\____\/:: /    |::|   /::\____\/:::/____/  ___\:::|    |        \n/:::/    \::/    /   /:::/~~~~/~~      \::/    \:::\  /:::|____|\:::\   \:::\   \::/    /        \:::\   \:::\   \::/    / \:::\    \   /:::/    / \::/    / ~~~~~/:::/    /\:::\   \:::\   \::/    /   /:::/    \::/    /\::/    \:::\  /:::/    /\:::\  /:::/    \::/    /\::/    /|::|  /:::/    /\:::\    \ /\  /:::|____|        \n/:::/    / \/____/   /:::/    /          \/_____/\:::\/:::/    /  \:::\   \:::\   \/____/          \:::\   \:::\   \/____/   \:::\    \ /:::/    /   \/____/      /:::/    /  \:::\   \:::\   \/____/   /:::/    / \/____/  \/____/ \:::\/:::/    /  \:::\/:::/    / \/____/  \/____/ |::| /:::/    /  \:::\    /::\ \::/    /         \n/:::/    /           /:::/    /                    \::::::/    /    \:::\   \:::\    \               \:::\   \:::\    \        \:::\    /:::/    /                /:::/    /    \:::\   \:::\    \      /:::/    /                    \::::::/    /    \::::::/    /                   |::|/:::/    /    \:::\   \:::\ \/____/          \n/:::/    /           /:::/    /                      \::::/    /      \:::\   \:::\____\               \:::\   \:::\____\        \:::\__/:::/    /                /:::/    /      \:::\   \:::\____\    /:::/    /                      \::::/    /      \::::/____/                    |::::::/    /      \:::\   \:::\____\            \n\::/    /            \::/    /                        \::/____/        \:::\   \::/    /                \:::\  /:::/    /         \::::::::/    /                /:::/    /        \:::\   \::/    /    \::/    /                       /:::/    /        \:::\    \                    |:::::/    /        \:::\  /:::/    /            \n\/____/              \/____/                          ~~               \:::\   \/____/                  \:::\/:::/    /           \::::::/    /                /:::/    /          \:::\   \/____/      \/____/                       /:::/    /          \:::\    \                   |::::/    /          \:::\/:::/    /             \n\:::\    \                       \::::::/    /             \::::/    /                /:::/    /            \:::\    \                                       /:::/    /            \:::\    \                  /:::/    /            \::::::/    /              \n  ")

    arr = []
    y= 0
    # pri = []
    # val = []
    for x in holding:
        arr.append(lookup(x["symbol"]))
    for x in arr:
        x["price"] = usd(x["price"])
    RET = json.dumps(arr)
    holdin = json.dumps(holding)
    if len(holding)==0:
        return render_template("index.html",zer="0")
    return render_template("index.html",ret=RET,user=USER[0]["username"],bal=usd(BAL[0]["cash"]),holdings=holdin,zer="1")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method=="GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        checker  = request.form.get("shares")
        try:
            shares= int(shares)
        except:
             return (render_template("buy.html",listing="N",a="post"),400)
        z =  shares
        listing =  lookup(symbol)
        if listing==None:
            return (render_template("buy.html",listing="N",a="post"),400)
        elif (z<1 and (z%1==0)):
            return (render_template("buy.html",listing="L",a="post"),400)
        else:
             x = session['user_id'] ;
             shares = shares*listing["price"]
             print(" |\___   ___\\  ___ \ |\   ____\|\___   ___\\  \|\   ___  \|\   ____\ \n\|___ \  \_\ \   __/|\ \  \___|\|___ \  \_\ \  \ \  \\ \  \ \  \___|\n\ \  \ \ \  \_|/_\ \_____  \   \ \  \ \ \  \ \  \\ \  \ \  \  ___\n\ \  \ \ \  \_|\ \|____|\  \   \ \  \ \ \  \ \  \\ \  \ \  \|\  \\n\ \__\ \ \_______\____\_\  \   \ \__\ \ \__\ \__\\ \__\ \_______\\n        \|__|  \|_______|\_________\   \|__|  \|__|\|__| \|__|\|_______|\n\|_________|\n")
             monies = db.execute("SELECT cash from users WHERE id=?",x)
             print(x,(monies[0]["cash"]))
             if monies[0]["cash"]<shares:
                 return render_template("buy.html",listing="nomoni",a="post")
             else:
                 db.execute("UPDATE users SET cash=? where id=?",monies[0]["cash"]-shares,x)
                 db.execute("insert into purchases (who,when_time,what,price,amt,shares) VALUES ((select username from users where id=?),datetime(),? ,?,?,?)",x,symbol,listing["price"],shares,z)
                 if((len(db.execute("select * from shares where (uid=? AND symbol=?);",x,symbol)))==0):
                    db.execute("insert into shares (uid,who,share_held,symbol,current_price) values (?,(select username from users where id=?),?,?,?)",x,x,z,symbol,listing["price"])
                    return redirect("/")
                 else:
                    db.execute("UPDATE shares SET share_held = share_held + ? WHERE (uid=? AND symbol=?);",int(z),x,symbol)
                    return redirect("/")





    return apology("TODO")


@app.route("/history")
@login_required
def history():
    x = session["user_id"]
    purl = db.execute("select * from purchases where who=(select username from users where id=?)",x)
    if len(purl)==0:
        return render_template("history.html",purl="0")
    else:
        SEND = json.dumps(purl)
        return render_template("history.html",send=SEND)
    """Show history of transactions"""



    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method=="GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")
        val=lookup(symbol)
        if val is not None:
            return (render_template("quoted.html",name=val["name"],price=usd(val["price"]),symbol=val["symbol"]),200)
        else:
            return (render_template("quoted.html",name=str(val)),400)



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method=="GET":
        return render_template("register.html")
    else:
        name = request.form.get("username")
        pwd = request.form.get("confirmation")
        con = request.form.get("password")



        if (re.search("\s",name)==None and re.search("\s",pwd)==None and len(pwd)!=0 and len(con)!=0 and len(name)!=0):
            if(pwd!=con):
                  return (render_template("register.html",ver="c"),400)
            ch =  db.execute("select * from users where username=?;",name)
            if len(ch)==0:
                db.execute("INSERT INTO users (username,hash) VALUES(?,?)",name, generate_password_hash(pwd))
                return redirect("/")

            else:

                return (render_template("register.html",ver="a"),400)
        else:
             return (render_template("register.html",ver="b"),400)







@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    x = session["user_id"]
    if request.method=="GET":
        HOLD =  db.execute("select * from shares where uid=?",x)
        HOLD = json.dumps(HOLD)
        return render_template("sell.html",hold=HOLD)
    else:
        symbol = request.form.get("symbol")
        num = int(request.form.get("shares"))
        cur = db.execute("select * from shares where uid=? and symbol=?",x,symbol)
        print(cur)
        if lookup(symbol)==None:
            return (render_template("sell.html",cur="N"),400)
        elif num>cur[0]["share_held"]:
            return (render_template("sell.html",cur="less"),400)
        else:
            price= (lookup(symbol))["price"]
            db.execute("insert into purchases(who,when_time,what,price,amt,shares) values((select username from users where id=?),datetime(),?,?,?,?)",x,symbol,-price,-price*num,num)
            db.execute("update shares set share_held= share_held - ? where (symbol=? and uid=?)",num,symbol,x)
            db.execute("update users set cash= cash+ ? where(id=?)",(price*num),x)
            return redirect("/")

    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
