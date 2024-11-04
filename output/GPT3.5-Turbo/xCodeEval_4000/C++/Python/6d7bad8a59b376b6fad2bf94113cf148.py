import random
import math

def read():
    global x, k, n, q, c, a
    x, k, n, q = map(int, input().split())
    c = list(map(int, input().split()))
    a = []
    for _ in range(q):
        a.append(tuple(map(int, input().split())))
        a[-1] = (a[-1][0] - 1, a[-1][1])

def get(pos):
    global mx
    mx = n - x - pos
    pr = [0] * k
    for i in range(q):
        if pos < a[i][0]:
            if a[i][0] <= pos + k:
                pr[a[i][0] - pos - 1] = a[i][1]
                mx = 1
            else:
                mx = min(mx, a[i][0] - (pos + k))
    res = [[math.inf] * cnt for _ in range(cnt)]
    for mask in range(1 << k):
        if bin(mask).count('1') == x:
            if mask & 1:
                for i in range(1, k + 1):
                    if not (mask >> i) & 1:
                        res[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1]
            else:
                res[num[mask]][num[mask >> 1]] = 0
    return res

def binpow(a, b):
    res = [[0] * cnt for _ in range(cnt)]
    for i in range(cnt):
        res[i][i] = 0
    while b:
        if b & 1:
            res = multiply(res, a)
        a = multiply(a, a)
        b >>= 1
    return res

def multiply(a, b):
    c = [[math.inf] * cnt for _ in range(cnt)]
    for i in range(cnt):
        for j in range(cnt):
            for k in range(cnt):
                c[i][j] = min(c[i][j], a[i][k] + b[k][j])
    return c

def solve():
    global cnt
    cnt = 0
    for mask in range(1 << k):
        if bin(mask).count('1') == x:
            num[mask] = cnt
            cnt += 1
    
    cur = [[0] * cnt for _ in range(cnt)]
    for i in range(cnt):
        for j in range(cnt):
            cur[i][j] = 0 if i == j else math.inf
    a.sort()
    i = 0
    while i < n - x:
        mx = 0
        tmp = get(i)
        i += mx
        cur = multiply(cur, binpow(tmp, mx))
    
    print(cur[0][0])

while True:
    try:
        read()
        solve()
    except EOFError:
        break
