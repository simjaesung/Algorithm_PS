a = int(input()) % 42
b = int(input()) % 42
c = int(input()) % 42
d = int(input()) % 42
e = int(input()) % 42
f = int(input()) % 42
g = int(input()) % 42
h = int(input()) % 42
i = int(input()) % 42
j = int(input()) % 42

A = [a, b, c, d, e, f, g, h, i, j]
A = set(A)
A = list(A)
another = 0
while A :
    A.pop()
    another += 1
print(another)