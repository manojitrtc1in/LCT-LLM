import sys
from collections import defaultdict

MOD = int(1e9) + 7
N = 50
M = 20

def read_int():
    return int(sys.stdin.readline().strip())

def read_string():
    return sys.stdin.readline().strip()

S = [None] * N
f = [0] * (1 << M)
ok = [0] * (M + 1)

n = read_int()
for i in range(n):
    S[i] = read_string()
m = len(S[0])

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
        if (s & (1 << i)):
            f[s ^ (1 << i)] |= f[s]

for s in range(1 << m):
    step = bin(s).count('1') + 1
    for i in range(m):
        if not (s & (1 << i)):
            d = f[s | (1 << i)] ^ f[s]
            ok[step] += bin(d).count('1')

ans = 0.0
for i in range(1, m + 1):
    if ok[i]:
        t = ok[i] * i
        for j in range(1, i):
            t *= j
        for j in range(m - i + 1, m + 1):
            t /= j
        ans += t

ans /= n
print(f"{ans:.15f}")
