import os
import json
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
import re

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # TODO: Add the user's entry into the databasse
        NAME = request.form.get("name")
        MONTH = request.form.get("month")
        DATE = request.form.get("date")
        db.execute("INSERT INTO 'birthdays' (name , month , day) VALUES(?,?,?);",NAME,MONTH,DATE)
        return redirect("/")

    elif request.method=="GET":

        # TODO: Display the entries in the database on index.html
        ROWS = db.execute("SELECT  * from birthdays;")
        x = str(ROWS).replace("&#39;", "")
        y = str(x).replace("[", "")
        z = str(y).replace("]", "")
        ma=json.dumps(ROWS)



        # print(str(z))
        return render_template("index.html",rows=ma)




