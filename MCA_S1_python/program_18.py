str=input('enter a string:')
vowels='aeiouAEIOU'
count=0
for s in str:
    if s in vowels:
        count+=1
print(count)