
line = input("Enter a line of text: ")
words = {w: line.split().count(w) for w in line.split()}
chars = {c: line.count(c) for c in line}
print("occurence of words",words)
print("occurence of characters",chars)