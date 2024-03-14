from collections import deque
import sys
input = sys.stdin.readline
v, e = map(int, input().split())

graph = [[] for _ in range(v+1)]
indegree = [0 for _ in range(v+1)]

for i in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1
    

def topology_sort() :
    result = []
    dq = deque()

    for i in range(1,v+1) :
        if indegree[i] == 0 :
            dq.append(i)
            
    while dq :
        k = dq.pop()
        result.append(k)
        for i in graph[k] :
            indegree[i] -= 1
            if indegree[i] == 0 :
                dq.append(i)
        
    for i in result :
        print(i,end=' ')

topology_sort()

