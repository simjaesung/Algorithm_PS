T = int(input())

for live in range(T) :
    k = int(input())
    n = int(input()) #k = 층, n = 호수
    A = [list(range(1,n+1))]
    m = 0
    
    for s in range(k) :
        t = 0
        a = []
        for i in range(n) :
            t += A[m][i]
            a.append(t)
        A.append(a)
        m += 1
    print(A[k][n-1])