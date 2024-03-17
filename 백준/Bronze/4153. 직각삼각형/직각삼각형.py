while True :
    A = list(map(int,input().split()))
    A.sort()
    if 0 in A : break

    if (A[0])**2 + (A[1])**2 == (A[2])**2 :
        print('right')
    else :
        print('wrong')