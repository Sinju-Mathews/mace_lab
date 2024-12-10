ouf=False
with open("text_3.txt",'w+') as ouf:
    try:
        line = input("enter some text :")
        while line:
            ouf.write(line+'\n')
            line = input("more text plz :) ")
        ouf.seek(0,0)
        texts=ouf.readlines()
        print('file contents :')
        for text in texts:
           print(text)
    except IOError as e:
        print(e)
    finally:
        if ouf: ouf.close()
