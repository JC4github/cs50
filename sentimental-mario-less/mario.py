from cs50 import get_int

height = get_int("Height: ")
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
