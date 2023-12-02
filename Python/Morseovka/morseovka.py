from os.path import realpath, dirname, join

with open(join(dirname(realpath(__file__)), "morseovka.txt"), "r", encoding="utf_8") as file:
    morse_code = {line[0]: line[2:] for line in file.read().split("\n")}

text = input("Přelož... ")

output = '/'.join([' '.join([morse_code[char.upper()] for char in word]) for word in text.split()])
print(output)