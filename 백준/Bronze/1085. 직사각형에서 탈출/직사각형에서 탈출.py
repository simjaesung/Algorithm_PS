x, y, w, h = map(int,input().split())
X = []
Y = []
if x <= w-x :
    X.append(x)
else :
    X.append(w-x)

if y <= h-y :
    Y.append(y)
else :
    Y.append(h-y)

if X[0] <= Y[0] :
    print(X[0])
else :
    print(Y[0])