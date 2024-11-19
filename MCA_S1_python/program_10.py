str=input("enter a string:").split()
str.sort(key=len,reverse=True)
print(str[0])
if len(str[0])==len(str[1]):
    print('BINGO')
