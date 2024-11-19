word=input("enter a word: ")
print({w:word.count(w) for w in word})
list=['anju', 'manju', 'anu', 'renu']
print(list)
print("names starts with a :",[l for l in list if l.startswith('a') ])