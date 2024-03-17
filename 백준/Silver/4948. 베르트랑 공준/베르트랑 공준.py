def sosoo(n) :
    
    soo = [True for i in range(2*n+1)]

    for i in range(2,int((2*n)**0.5)+1) :
        if soo[i] == True :
            u = 2
            while i * u <= 2*n :
                soo[i * u] = False
                u += 1
    return [i for i in range(n+1,2*n+1) if soo[i]]

while True :
    a = int(input())
    if a==0 : break
    print(len(sosoo(a)))