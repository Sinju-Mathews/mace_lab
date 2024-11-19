n=int(input('enter a number :'))
print('factors of ',n,':',end=" ")
for i in range(1,n+1):
    if not n%i:
        print(i,end=" ")