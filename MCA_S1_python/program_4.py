num1 = list(map(int, input("Enter number collection 1 (space-separated): ").split()))
num2 = list(map(int, input("Enter number collection 2 (space-separated): ").split()))

print("Same length:", len(num1) == len(num2))
print("Same sum:", sum(num1) == sum(num2))
print("Has same elements:",bool(set(num1)&set(num2)))