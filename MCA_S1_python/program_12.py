per=int(input('enter percentage:'))
if per >100:
    print('percentage should not exceed 100')
elif per >=95:
    print('grade : S')
elif per >=85:
    print('grade : A+')
elif per >=75:
    print('grade : A')
elif per >=65:
    print('grade : B+')
elif per >=55:
    print('grade : B')
elif per >=45:
    print('grade : C')
elif per >=40:
    print('grade : D')
elif per <40 and per>0:
    print('grade : FAILED ')
else :
    print('wrong input')
