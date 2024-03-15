n = int(input())
G = [[] for _ in range(n)]
visited = [False]*n

m = int(input())

for i in range(m) :
    a,b = map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

def DFS(G, v):
    visited[v] = True
    # print(v+1,end = ' ')
    for w in G[v] :
        if visited[w] == False :
            DFS(G,w)
DFS(G,0)
print(visited.count(True)-1)