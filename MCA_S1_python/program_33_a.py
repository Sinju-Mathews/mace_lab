inf = False
try:
    with open('text1.txt', 'r') as inf:
        lines = inf.readlines()
        print("File as List:",lines)
            
except IOError as e:
    print(e)
finally:
    if inf: inf.close()
