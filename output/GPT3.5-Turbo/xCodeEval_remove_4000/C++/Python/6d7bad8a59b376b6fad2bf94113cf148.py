import math
import random

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = math.acos(-1.0)

N = 70

x, k, n, q = 0, 0, 0, 0
c = [0] * N
a = [(0, 0)] * N

def read():
    global x, k, n, q, c, a
    try:
        x, k, n, q = map(int, input().split())
        c = list(map(int, input().split()))
        for i in range(q):
            a[i] = tuple(map(int, input().split()))
            a[i] = (a[i][0] - 1, a[i][1])
        return True
    except:
        return False

def get(pos, mx):
    global x, k, n, q, c, a
    mx = n - x - pos
    pr = [0] * k
    for i in range(q):
        if pos < a[i][0]:
            if a[i][0] <= pos + k:
                pr[a[i][0] - pos - 1] = a[i][1]
                mx = 1
            else:
                mx = min(mx, a[i][0] - (pos + k))
    res = [[INF64] * N for _ in range(N)]
    for mask in range(1 << k):
        if bin(mask).count('1') == x:
            if mask & 1:
                for i in range(1, k + 1):
                    if not (mask >> i) & 1:
                        res[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1]
            else:
                res[num[mask]][num[mask >> 1]] = 0
    return res

def solve():
    global x, k, n, q, c, a
    cnt = 0
    for mask in range(1 << k):
        if bin(mask).count('1') == x:
            num[mask] = cnt
            cnt += 1
    
    cur = [[INF64] * N for _ in range(N)]
    for i in range(cnt):
        cur[i][i] = 0
    a.sort()
    i = 0
    while i < n - x:
        mx = 0
        tmp = get(i, mx)
        i += mx
        cur = matrix_multiply(cur, matrix_power(tmp, mx))
    
    print(cur[0][0])

def matrix_multiply(a, b):
    n = len(a)
    m = len(b[0])
    res = [[INF64] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            for k in range(len(b)):
                res[i][j] = min(res[i][j], a[i][k] + b[k][j])
    return res

def matrix_power(a, b):
    res = [[INF64] * N for _ in range(N)]
    for i in range(N):
        res[i][i] = 0
    while b:
        if b & 1:
            res = matrix_multiply(res, a)
        a = matrix_multiply(a, a)
        b >>= 1
    return res

num = [0] * (1 << 8)

while read():
    solve()
