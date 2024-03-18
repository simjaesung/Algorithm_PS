C = int(input())

for i in range(C):
    arr = [int(x) for x in input().split()]
    average = (sum(arr)-arr[0])/arr[0]
    count = 0
    for j in range(1, len(arr)):
        if arr[j] > average:
            count += 1
    print('%0.3f' % round(count/arr[0]*100, 3), '%', sep='')