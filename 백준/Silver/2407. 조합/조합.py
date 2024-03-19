a, b = map(int, input().split())
b = min(a-b,b)

ans = 1

for i in range(b):
    ans *= a-i
for i in range(1,b+1):
    ans //= i
    
print(ans)