list=[-1,21,2,8,52,-90,33,-45]
print("list :",list)
print("positive numbers: ",[l for l in list if l>0])
print("square of numbers: ",[l*l for l in list])
print("without even numbers: ",[l for l in list if l%2])
word=input("enter a word: ")
vowels="aeiou"
print("vowels in word :",[w for w in word if w in vowels])
start=int(input("enter starting year:"))
end=int(input("enter ending year:"))
print("leap years :",[y for y in range (start,end+1) if (y%4==0 and (y%100!=0 or y%400==0))  ])
