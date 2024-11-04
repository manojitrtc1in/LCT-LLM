from math import comb

S = []
n = int(input())
for _ in range(n):
    S.append(input())

m = len(S[0])
f = [0] * (1 << m)
ok = [0] * (m + 1)

for i in range(n):
    for j in range(n):
        if i != j:
            s = 0
            for k in range(m):
                if S[i][k] == S[j][k]:
                    s |= (1 << k)
            f[s] |= (1 << i)

for s in range((1 << m) - 1, -1, -1):
    for i in range(m):
        if (s & (1 << i)) == 0:
            f[s ^ (1 << i)] |= f[s]

for s in range(1, 1 << m):
    step = bin(s).count('1') + 1
    for i in range(m):
        if (s & (1 << i)) == 0:
            d = f[s | (1 << i)] ^ f[s]
            ok[step] += bin(d).count('1')

ans = 0
for i in range(m):
    if ok[i]:
        t = ok[i] * i
        for j in range(1, i):
            t *= j
        for j in range(m - i + 1, m + 1):
            t //= j
        ans += t

ans /= n
print(ans)
