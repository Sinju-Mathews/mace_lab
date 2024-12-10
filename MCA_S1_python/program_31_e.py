def reverseString(s):
    if len(s) <= 1:
        return s
    else:
        return s[-1]+reverseString(s[:-1])

s = input("Enter a string: ")
print("Reversed string:", reverseString(s))
