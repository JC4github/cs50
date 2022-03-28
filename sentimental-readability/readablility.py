from cs50 import get_string

sentence = get_string("Text: ")
L = 0
S = 0
words = 1
letters = 0
sentence = 0
for letter in sentence:
    if (ord(letter) >= ord("A") and ord(letter) <= ord("Z")) or (ord(letter) >= ord("a") and ord(letter) <= ord("z")):
        letters += 1
    elif (ord(letter) == ord(" ")):
        words += 1
    elif ord(letter) == ord("!") or ord(letter) == ord(".") or ord(letter) == ord("?"):
        sentence += 1

L = round((letters / words) * 100, 3)
S = round((sentence / words) * 100, 3)
index = round((0.0588 * L) - (0.296 * S) - 15.8, 3)

