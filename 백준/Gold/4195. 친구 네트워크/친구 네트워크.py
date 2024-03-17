import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def find(x) :
    if parent[x] != x :
        parent[x] = find(parent[x])
    return parent[x]

def union(x,y) :
    w,v = find(x), find(y)
    if w != v :
        parent[v] = w
        friend[w] += friend[v]

n = int(input())
for _ in range(n) :
    m = int(input())
    parent = dict()
    friend = dict()
    for _ in range(m) :
        a = input().split()
        if a[0] not in parent :
            parent[a[0]] = a[0]
            friend[a[0]] = 1
        if a[1] not in parent :
            parent[a[1]] = a[1]
            friend[a[1]] = 1
        union(a[0],a[1])
        print(friend[find(a[0])])
