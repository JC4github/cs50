from cs50 import get_float

while True:
    amount = get_float("Change owed: ")
    if amount > 0:
        break
