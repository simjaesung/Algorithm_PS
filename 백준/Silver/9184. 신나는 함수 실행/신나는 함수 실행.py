import sys 
input = sys.stdin.readline

D = dict()

def w(a,b,c) :
    global D
    if (a, b, c) in D: return D[(a, b, c)]
    elif a <= 0 or b <= 0 or c <= 0 : return 1
    elif a > 20 or b > 20 or c > 20 : return w(20,20,20)
    elif a < b and b < c :
        D[a,b,c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c)
    
    else : 
        D[a,b,c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1)
    return D[a,b,c]
    
while True :
    a,b,c = map(int,input().split())
    if a == -1 and b == -1 and c == -1 : break
    print("w({}, {}, {}) = {}".format(a,b,c,w(a,b,c)))