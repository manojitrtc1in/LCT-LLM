import random

def bpow(a, b, mod=10**9 + 7):
    res = a
    ret = 1
    while b > 0:
        if b % 2:
            ret = (ret * res) % mod
        res = (res * res) % mod
        b //= 2
    return ret % mod

def Random():
    seed = random.randint(0, 2**32 - 1)
    random.seed(seed)

def fact(n, mod=10**9 + 7):
    fuc = 1
    for i in range(2, n + 1):
        fuc = fuc * i % mod
    return fuc

def Cnk(n, r, mod=10**9 + 7):
    r = min(r, n - r)
    ans = 1
    for i in range(n, n - r, -1):
        ans = (ans * i) % mod
    for i in range(1, r + 1):
        ans = (ans * bpow(i, mod - 2)) % mod
    return ans

a = [''] * 128
c = [''] * 128
t = [0] * 128

b, d = map(int, input().split())
a = list(input().strip())
c = list(input().strip())
s = 0
n = len(c)

for i in range(n):
    k = t[i]
    for j in range(len(a)):
        if a[j] == c[(i + k) % n]:
            k += 1
    t[i] = k

for i in range(b):
    s += t[s % n]

print(s // n // d)
