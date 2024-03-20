def sosoo(n) :
    if n == 1 :
        return False
    for i in range(2,int(n**0.5)+1) :
        if n % i == 0 :
            return False
    return True

T = int(input())

for case in range(T) :
    soo = int(input())
    a = soo//2
    b = a
    while True :
        if sosoo(a) and sosoo(b) :
            print(a,b)
            break
        else:
            a -= 1
            b += 1

