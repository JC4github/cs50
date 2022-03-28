from cs50 import get_float

while True:
    amount = get_float("Change owed: ")
    if amount > 0:
        break

quarter = 0.25
dim = 0.10
nickel = 0.05
pennie = 0.01

coins = 0

while amount > 0.00000001:
    while (amount - quarter) >= 0:
        coins += 1
        amount = round(amount - quarter, 2)
    while (amount - dim) >= 0:
        coins += 1
        amount = round(amount - dim, 2)
    while (amount - nickel) >= 0:
        coins += 1
        amount = round(amount - nickel, 2)
    while (amount - pennie) >= 0:
        coins += 1
        amount = round(amount - pennie, 2)

print(coins)