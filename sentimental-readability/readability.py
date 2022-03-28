from cs50 import get_string

sentence = get_string("Text: ")
L = 0
S = 0
words = 1
letters = 0
sentences = 0
for letter in sentence:
    if (ord(letter) >= ord("A") and ord(letter) <= ord("Z")) or (ord(letter) >= ord("a") and ord(letter) <= ord("z")):
        letters += 1
    elif (ord(letter) == ord(" ")):
        words += 1
    elif ord(letter) == ord("!") or ord(letter) == ord(".") or ord(letter) == ord("?"):
        sentences += 1

L = round((letters / words) * 100, 3)
S = round((sentences / words) * 100, 3)
index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index < 1:
    print("Before Grade 1")

elif index > 16:
    print("Grade 16+")

else:
    print(f"Grade {index}")
