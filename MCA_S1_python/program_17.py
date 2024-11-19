nums=list(map(int,input('enter some numbers :').split()))
for n in range(len(nums)):
    if nums[n]>100:
        nums[n]='over'
print(nums)