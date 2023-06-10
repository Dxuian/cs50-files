from cs50 import SQL
from flask import jsonify
db  = SQL("sqlite:///birthdays.db")
ROWS = jsonify(db.execute("SELECT  * FROM birthdays WHERE ID=1;"))
print(ROWS)