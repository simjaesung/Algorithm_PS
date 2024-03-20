num = list(map(str, input()))
dial = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV','WXYZ']
time = 0
for i in num :
    for u in dial :
        if i in u :
            time += dial.index(u) + 3

print(time)
