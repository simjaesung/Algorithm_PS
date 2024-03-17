n = int(input())
a = n // 3 
b = n % 3
t = 0
if b == 0 :
    l = 0
    for i in range(a) :
        t += 3
        l += 1
        if t % 5 == 0 :
            l -= 2
else :
    l = 0
    for u in range(a) :
        b += 3
        l += 1
        if b % 5 == 0 :
            if b == 15 :
                l -= 2
                b = 0
            else :
                l = b//5
                b = 0
    if b % 3 != 0 :
        l = -1
print(l)