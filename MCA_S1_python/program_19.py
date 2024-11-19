for i in range(1,21):
    if(not i%5 and not i%3):
        print('fizzbuzz')
    elif(not i%3):
        print('fizz')
    elif(not i%5):
        print('buzz')
    else:
        print(i)