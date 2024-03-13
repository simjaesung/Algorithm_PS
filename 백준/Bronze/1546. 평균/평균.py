n = int(input())
score = list(map(int,input().split()))
high = max(score)
fake_score = list(score)
fake_score.remove(high)

add = 0
while fake_score :
    add += fake_score.pop()

adds = add / high * 100
average =(adds + 100) / n
print(average)