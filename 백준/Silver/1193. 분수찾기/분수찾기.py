x = int(input())

d = 1
sums = 0
while True :
    sums += d
    if x <= sums :
        break
    d += 1

a = sums - x
if d % 2 == 1 :
    print('{0}/{1}'.format(a+1,d-a))
else :
    print('{0}/{1}'.format(d-a,a+1))
