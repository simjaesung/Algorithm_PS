T = int(input())
#h = 높이 ,w:방수, n : 손님
for i in range(T) :
    h, w, n = map(int,input().split())
    height = n % h
    if height == 0 :
        height = h
    import math
    room_number = math.ceil(n / h)
    if room_number < 10 :
        print('{0}0{1}'.format(height, room_number))
    else :
        print('{0}{1}'.format(height, room_number))
