T = int(input())

for i in range(T) :
    x, y = map(int,input().split())
    len_ = y - x
    i = 0
    lens = 0
    while True :        
        if lens >= len_ :
            break
        i += 2
        lens += i                
    if lens - i/2 >= len_ :
        print(i-1)
    else :
        print(i)