import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import date

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    stocks = db.execute("SELECT symbol, name, SUM(shares), price, total FROM stocks WHERE user_id = ? GROUP BY symbol ORDER BY date", session["user_id"])
    sumbalance = 0
    for stock in stocks:
        result = lookup(stock["symbol"])
        stock["price"] = result["price"]
        stock["total"] = result["price"] * stock["SUM(shares)"]
        sumbalance = sumbalance + stock["total"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    sumbalance = sumbalance + cash[0]["cash"]
    return render_template("index.html", stocks=stocks, cash=cash, sumbalance=sumbalance)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        tickerSymbol = request.form.get("symbol").upper()
        shares = float(request.form.get("shares"))
        if not tickerSymbol:
            return apology("Must include a symbol")
        elif shares <= 0:
            return apology("Invalid share amount")
        elif lookup(tickerSymbol) == None:
            return apology("Symbol is invalid")
        else:
            result = lookup(tickerSymbol)
            total = shares * result["price"]
            balance = db.execute("SELECT cash FROM users where id = ?", session["user_id"])
            if (total > balance[0]["cash"]):
                return apology("insufficient balance")
            else:
                newBalance = balance[0]["cash"] - total
                action = "buy"
                db.execute("INSERT INTO stocks (user_id, symbol, name, shares, price, total, action, date) VALUES(?, ?, ?, ?, ?, ?, ?, ?)", session["user_id"], tickerSymbol, result["name"], shares, result["price"], total, action, date.today())
                db.execute("UPDATE users SET cash = ? WHERE id = ?", newBalance, session["user_id"])
                return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
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
    if request.method == "POST":
        tickerSymbol = request.form.get("symbol")
        if not tickerSymbol:
            return apology("Must include a symbol")
        else:
            result = lookup(tickerSymbol)
            return render_template("quoted.html", result=result)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        name = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        users = db.execute("SELECT username FROM users WHERE username = ?", name)

        if not name or not password:
            return apology("Must include a username and/or password")
        elif len(users) != 0:
            return apology("User name already exists")
        elif password != confirmation:
            return apology("Passwords does not match")
        else:
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", name, generate_password_hash(password, method='pbkdf2:sha256', salt_length=8))
            return redirect("/login")
    else:
        return render_template("register.html")




@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        tickerSymbol = request.form.get("symbol").upper()
        shares = float(request.form.get("shares"))
        if not tickerSymbol:
            return apology("Must include a symbol")
        elif shares <= 0:
            return apology("Invalid share amount")
        elif lookup(tickerSymbol) == None:
            return apology("Symbol is invalid")
        else:
            ownshares = db.execute("SELECT SUM(share) FROM stocks where id = ? AND symbol = ?", session["user_id"], tickerSymbol)
            if ownshares[0]["SUM(share)"] < shares:
                return apology("insufficient shares")
            else:
            result = lookup(tickerSymbol)
            total = shares * result["price"]
            balance = db.execute("SELECT cash FROM users where id = ?", session["user_id"])
            newBalance = balance[0]["cash"] + total
            action = "sell"
            sh
            db.execute("INSERT INTO stocks (user_id, symbol, name, shares, price, total, action, date) VALUES(?, ?, ?, ?, ?, ?, ?, ?)", session["user_id"], tickerSymbol, result["name"], shares, result["price"], total, action, date.today())
            db.execute("UPDATE users SET cash = ? WHERE id = ?", newBalance, session["user_id"])
            return redirect("/")

    else:
        symbols = db.execute("SELECT DISTICT symbol FROM stocks WHERE id = ?", session["user_id"])
        return render_template("sell.html", symbols=symbols)
