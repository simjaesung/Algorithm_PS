import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def DFS(G, v):
    visited_D[v] = True
    d = distance[v]
    for w in G[v] :
        if visited_D[w[0]-1] == False :
            # if distance[w[0]-1] < w[1]+d :
            distance[w[0]-1] = w[1]+d
            DFS(G,w[0]-1)    

n = int(input())
G = [[] for _ in range(n)]
distance = [0 for _ in range(n)]


for _ in range(n) :
    a = list(map(int,input().split()))
    for i in range(1,len(a)-1,2) :
        if i == -1 : break
        G[a[0]-1].append([a[i],a[i+1]])


visited_D = [False]*n
DFS(G,0)

k = distance.index(max(distance))
distance = [0 for _ in range(n)]
visited_D = [False]*n
DFS(G,k)
print(max(distance))