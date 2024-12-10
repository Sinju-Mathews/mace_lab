def sumoflist(l1):
    if len(l1) == 1:
        return l1[0]
    else:
        return l1[-1] + sumoflist(l1[:-1])

l1 = list(map(int, input("Enter the numbers list: ").split()))
print("Sum =", sumoflist(l1))