inf = False
try:
    with open('text1.txt', 'r') as inf:
        lines = inf.readlines()
        odd=[lines[i] for i in range(len(lines)) if i%2]
        print("File as List:",lines)
        print("odd lines in the List:",odd)
except IOError as e:
    print(e)
finally:
    if inf: inf.close()
