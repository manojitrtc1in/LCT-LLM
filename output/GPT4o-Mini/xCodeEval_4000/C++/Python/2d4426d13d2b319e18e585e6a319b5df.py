import sys
from collections import defaultdict
from math import atan2, pi

def input():
    return sys.stdin.readline().strip()

def Mask(x):
    return 1 << x

def Maskx(a, x):
    return a << x

def Full(a):
    return (1 << a) - 1

def bit_count(x):
    return bin(x).count('1')

n = int(input())
s = [input() for _ in range(n)]
m = len(s[0])
dy = [0] * (Mask(20) + 5)
dp = [0.0] * (Mask(20) + 5)

for i in range(n):
    for j in range(i + 1, n):
        num = 0
        for k in range(m):
            num |= Maskx(s[i][k] == s[j][k], k)
        dy[num] |= Mask(i) | Mask(j)

for i in range(Mask(m) - 1, -1, -1):
    for j in range(i, 0, -1):
        if j & -j:
            lst = j & -j
            dy[i ^ lst] |= dy[i]

dp[0] = 1.0
ans = 0.0

for i in range(Mask(m)):
    v = dp[i] / (m - bit_count(i))
    for j in range(Full(m) ^ i):
        if j & -j:
            dp[i | (j & -j)] += v
    ans += dp[i] * bit_count(dy[i])

print(ans / n)
