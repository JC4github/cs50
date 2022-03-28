from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height < 9 and height > 0:
        break

spaces = height - 1
blocks = 1
for i in range(height):
    for space in range(spaces):
        print(" ", end="")

    for block in range(blocks):
        print("#", end="")

    print()
    spaces -= 1
    blocks += 1
