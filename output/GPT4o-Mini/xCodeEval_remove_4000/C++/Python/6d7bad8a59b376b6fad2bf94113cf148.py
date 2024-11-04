import sys
import time
import random
from itertools import combinations

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = -1.0 ** 0.5

N = 70

x, k, n, q = 0, 0, 0, 0
c = [0] * N
a = [(0, 0)] * N

def read():
    global x, k, n, q
    data = sys.stdin.read().split()
    if len(data) < 4:
        return False
    x, k, n, q = map(int, data[:4])
    for i in range(k):
        c[i] = int(data[4 + i])
    for i in range(q):
        a[i] = (int(data[4 + k + 2 * i]) - 1, int(data[4 + k + 2 * i + 1]))
    return True

def mat_mult(a, b):
    c = [[INF64] * N for _ in range(N)]
    for i in range(cnt):
        for j in range(cnt):
            for k in range(cnt):
                c[i][j] = min(c[i][j], a[i][k] + b[k][j])
    return c

def mat_binpow(a, b):
    res = [[0 if i == j else INF64 for j in range(cnt)] for i in range(cnt)]
    while b:
        if b & 1:
            res = mat_mult(res, a)
        a = mat_mult(a, a)
        b >>= 1
    return res

num = [0] * (1 << 8)
cnt = 0

def get(pos):
    global cnt
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
    return res, mx

def solve():
    global cnt
    cnt = 0
    for mask in range(1 << k):
        if bin(mask).count('1') == x:
            num[mask] = cnt
            cnt += 1
    
    cur = [[0 if i == j else INF64 for j in range(cnt)] for i in range(cnt)]
    a.sort()
    i = 0
    while i < n - x:
        tmp, mx = get(i)
        i += mx
        cur = mat_mult(cur, mat_binpow(tmp, mx))
    
    print(cur[0][0])

def main():
    sys.stdin = open("input.txt", "r")
    tt = time.clock()
    
    while read():
        solve()
        print("TIME =", time.clock() - tt)
        tt = time.clock()

if __name__ == "__main__":
    main()
