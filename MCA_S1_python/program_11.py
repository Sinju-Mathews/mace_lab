str=input("enter a string:")
if len(str)<2:
    print('')
else:
    print(str[:2]+str[-2:])