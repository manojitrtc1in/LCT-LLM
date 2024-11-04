from collections import defaultdict
import sys
import math

MOD = 1000000007
INF = float('inf')
EPS = 1e-6

def check_min(a, b):
    if b < a:
        return b
    return a

def check_max(a, b):
    if b > a:
        return b
    return a

def count_bits(x):
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1)
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2)
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4)
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8)
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16)
    return x

def low_bit(x):
    return x & -x

def high_bit(x):
    p = low_bit(x)
    while p != x:
        x -= p
        p = low_bit(x)
    return p

def inc(a, b):
    a += b
    if a >= MOD:
        a -= MOD

def sum_mod(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dec(a, b):
    a -= b
    if a < 0:
        a += MOD

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def mul(a, b):
    a = (a * b) % MOD

def pdt(a, b):
    return (a * b) % MOD

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def dfs(k=0, n=0):
    A.append(n)
    if k == 9:
        return
    else:
        dfs(k + 1, n * 10 + 4)
        dfs(k + 1, n * 10 + 7)

def I(l, r, l_, r_):
    l = check_max(l, l_)
    r = check_min(r, r_)
    return max(0, r - l + 1)

A = []
cnt = 0

dfs()
A.sort()
A.append(INF)

pl, pr, vl, vr, k = read_ints()

for i in range(len(A) - k):
    l1 = A[i - 1] + 1
    r1 = A[i]
    l2 = A[i + k - 1]
    r2 = A[i + k] - 1
    d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr)
    d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr)
    cnt += d1 + d2
    if d2 and d2 and k == 1:
        cnt -= 1

print(f"{cnt / ((pr - pl + 1) * (vr - vl + 1)):.12f}")
