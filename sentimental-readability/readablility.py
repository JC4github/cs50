from cs50 import get_string

sentence = get_string("Text: ")
L = 0
S = 0
for letter in sentence::
    if (ord(letter) >= ord("A") and ord(letter) <= ord("Z")) or (ord(letter) >= ord("a") and ord(letter) <= ord("z")):
        L += 1

index = 0.0588 * L - 0.296 * S - 15.8
