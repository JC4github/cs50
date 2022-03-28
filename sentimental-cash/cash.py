from cs50 import get_float

while True:
    amount = get_float("Change owed: ")
    if amount > 0:
        break

quarter = 0.25
dim = 0.10
nickel = 0.05
pennie = 0.01