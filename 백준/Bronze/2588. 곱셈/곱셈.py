A, B, C = map(int, input())
a, b, c = map(int, input())
X = (100 * A + 10 * B + C) * c
Y = (100 * A + 10 * B + C) * b
Z = (100 * A + 10 * B + C) * a
W = X + 10 * Y + 100 * Z
print(X)
print(Y)
print(Z)
print(W)