inf =False
with open("text_4.txt",'r') as inf:
    try:
        lines=inf.readlines()
        print(lines)
        m = max(len(line) for line in lines)
        for line in lines:
            if len(line) == m:
                print('longest line: ',line)
    except IOError as e:
        print(e)
    finally:
        if inf: inf.close() 