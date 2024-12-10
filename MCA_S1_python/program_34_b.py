import re
inf = False
try:
    with open("text2.txt", 'r') as inf:
        lines = inf.readlines()
        print("File as List:", lines)
except IOError as e:
    print("Error reading file:", e)

vow = []
pattern = re.compile(r'^[aeiouAEIOU].*[aeiouAEIOU]$')

if lines:
    for line in lines:
        words = line.split()
        vow.extend([word for word in words if pattern.match(word)])

print("Words that start and end with a vowel:", vow)
