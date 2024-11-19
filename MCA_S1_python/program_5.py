d1={'name':"sinju", 'course':"MCA", 'roll no':"51"}
d2={"college":"MACE","place":"kothamangalam"}
print("d1 :",d1)
k=input("enter a key to search: ")
print("already exist :",k in d1)
print("d2 :",d2)
d1.update(d2)
print("merged d1 and d2 :", d1)
print("Ascending :",sorted(d1.items()))
print("descending :",sorted(d1.items(),reverse=True))
print("inverse dictionary :",{v:k for k,v in d1.items()})
