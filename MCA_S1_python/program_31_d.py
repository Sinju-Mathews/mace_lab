def sumofn(n):
    if n == 1:
        return 0
    else:
        return n-1 + sumofn(n-2)

n = int(input("Enter the limit: "))
print("Sum =", sumofn(n))