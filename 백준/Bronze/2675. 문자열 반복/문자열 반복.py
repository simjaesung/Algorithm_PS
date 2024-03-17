n = int(input())

for i in range(n) :
    a, b = map(str, input().split())
    a = int(a)
    b = list(b)
    t = []
    for u in b :
        c = u * a
        t.append(c)
        p = ''.join(t)
    print(p)