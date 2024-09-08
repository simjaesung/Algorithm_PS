a = int(input())
if a == 1 :
        print(1)
else:
    d = 6
    route = 2
    house = 1
    while True :
        if a <= house + d :
            print(route)
            break
        house = house + d
        d += 6
        route += 1