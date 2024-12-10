import re
inf = False
try:
    with open("text1.txt", 'r') as inf:
        lines = inf.readlines()            
except IOError as e:
    print(e)
finally:
    if inf: inf.close()
emails = []
pattern =re.compile(r'\w+@\w+\.\w+')
for line in lines:
    emails.extend(pattern.findall(line))
print("Email Addresses:",emails)

