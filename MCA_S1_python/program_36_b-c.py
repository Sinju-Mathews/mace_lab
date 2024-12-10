import re
inf =False
with open("text_4.txt",'r') as inf:
    try:
        lines=inf.readlines()
        print(lines)
        pattern=re.compile(r'\b\d{10}\b')
        numbers=[]
        nocomm=[]
        for line in lines:
            numbers.extend(pattern.findall(line))
            nocomm.extend(re.findall('^(?!#).*',line))   
        print ('numbers:',numbers)
        print ('list with no comments :',nocomm)
    except IOError as e:
        print(e)
    finally:
        if inf: inf.close()