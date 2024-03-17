a, b = map(str, input().split())
(a, b) = (list(a), list(b))
a.reverse()
b.reverse()
(A, B) = ("".join(a), "".join(b))
A , B = int(A), int(B)
c = [A, B]
print(max(c))