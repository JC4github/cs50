from cs50 import get_int

height = get_int("Height: ")
spaces = height - 1
for i in range(height):
    for space in range(spaces):
        print(" ", end="")
        spaces -= 1
    