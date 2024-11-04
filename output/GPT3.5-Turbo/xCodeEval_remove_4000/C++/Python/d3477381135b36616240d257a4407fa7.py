b, d = map(int, input().split())
a, c = input().split()
an, cn = len(a), len(c)

t = [0] * cn
for i in range(cn):
    k = 0
    for j in range(an):
        if a[j] == c[(i+k)%cn]:
            k += 1
    t[i] = k

s = 0
for _ in range(b):
    s += t[s%cn]
s //= cn*d
print(s)
