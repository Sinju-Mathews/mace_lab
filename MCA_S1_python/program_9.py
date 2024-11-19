str=input("enter a string:")
if str.lower().endswith('ing'):
    str+='ly'
else:
    str+='ing'
print(str)