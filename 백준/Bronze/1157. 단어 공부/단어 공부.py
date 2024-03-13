a = list(map(str,input()))
A = []
for i in a :
    t = i.upper()
    A.append(t)
    if len(A)==len(a):
        break
A.sort() 
B = set(A)
B = list(B)
B.sort() 
C = []
for u in B :
    c = A.count(u)
    C.append(c)
if C.count(max(C)) >= 2 : 
    print("?")
else :
    m = C.index(max(C))
    print(B[m])