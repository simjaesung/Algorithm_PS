n = int(input())
answer = n

for i in range(n) :
    a = []
    sentense = list(map(str, input()))
    for u in range(len(sentense)-1) :
        if sentense[u] != sentense[u+1] :
            a.append(sentense[u])
    a.append(sentense[len(sentense)-1])

    a.sort()

    for k in range(len(a)-1) :
        if a[k] == a[k + 1] :
            answer -= 1
            break

print(answer)