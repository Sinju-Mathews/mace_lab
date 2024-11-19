#factorial
n=int(input('enter a number: '))
fact=1
for i in range(2,n+1):
    fact*=i
print('factorial :',fact)

#fibonacci
f0,f1=0,1
m=int(input('enter a number: '))
for i in range(m):
    print(f0,end=' ')
    f0,f1=f1,f0+f1

#sum of a list
nums=list(map(int,input('\nenter some numbers :').split()))
sum=0
print(nums)
for n in nums:
    sum+=n
else:
    print('sum :',sum)