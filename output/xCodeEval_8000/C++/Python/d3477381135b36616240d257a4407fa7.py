b, d = map(int, input().split())
a = input()
c = input()

an = len(a)
cn = len(c)

t = [0] * cn
for i in range(cn):
    k = 0
    for j in range(an):
        if a[j] == c[(i+k)%cn]:
            k += 1
    t[i] = k

s = sum(t[i] for i in range(cn))
s //= cn * d
print(s)
