m = int(input())
n = int(input())
T = []
for i in range(m,n+1) :
    t = 0
    for u in range(1,i + 1) :
        if i % u == 0 :
            t += 1
    if t == 2 :
        T.append(i)
if sum(T) == 0 :
    print(-1)
else :
    print(sum(T))
    print(T[0])