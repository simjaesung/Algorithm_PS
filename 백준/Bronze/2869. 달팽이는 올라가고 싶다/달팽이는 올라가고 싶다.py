a,b,v = map(int,input().split())

day = a - b
t = v - b
import math

lastday = t / day
print(math.ceil(lastday))