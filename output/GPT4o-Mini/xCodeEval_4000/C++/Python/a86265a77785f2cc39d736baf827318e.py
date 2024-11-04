import sys
from functools import lru_cache

mod = 998244353

def read():
    return int(sys.stdin.readline().strip())

def ksm(a, b):
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % mod
        a = a * a % mod
        b >>= 1
    return ans

def C(n, m):
    return fac[n] * inv[m] % mod * inv[n - m] % mod

n, k = read(), read()
aa = [0] * (n + 1)
bb = [0] * (n + 1)

for i in range(1, n + 1):
    aa[i] = read()
    bb[i - 1] = aa[i]

fac = [1] * (n + 1)
inv = [0] * (n + 1)

for i in range(1, n + 1):
    fac[i] = fac[i - 1] * i % mod

inv[n] = ksm(fac[n], mod - 2)
for i in range(n - 1, -1, -1):
    inv[i] = inv[i + 1] * (i + 1) % mod

ans = 1
cnt = 0

for i in range(1, n + 1):
    if aa[i] == bb[i - 1]:
        ans = ans * k % mod
    else:
        cnt += 1

tmpans = 0
for i in range(0, cnt + 1, 2):
    anss = ksm(k - 2, cnt - i) * C(i, i // 2) % mod * C(cnt, i) % mod
    tmpans = (tmpans + anss) % mod

ans = tmpans * ans % mod

Ans = ksm(k, n)
Ans = (Ans - ans) % mod

print(Ans * ksm(2, mod - 2) % mod)
