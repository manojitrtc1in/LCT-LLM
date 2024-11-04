import sys
from collections import defaultdict

def RD():
    return map(int, sys.stdin.readline().split())

def dfs():
    F = [0] * (1 << n)
    F[0] = 1
    for s in range((1 << n) - 1):
        if F[s]:
            for i in range(n):
                if not (s & (1 << i)) and (pos == -1 or pos == i) and not (s & adj[i]):
                    F[s | (1 << i)] += F[s]
    return F[(1 << n) - 1]

n, k = RD()
k -= 2000
adj = [0] * n
for _ in range(RD()):
    x, y = RD()
    adj[x - 1] |= (1 << (y - 1))
P = [-1] * n

if dfs() < k:
    print("The times have changed")
else:
    s = (1 << n) - 1
    A = [0] * n
    for i in range(n):
        for j in range(n):
            if s & (1 << j):
                P[A[i]] = i
                t = dfs()
                if t < k:
                    k -= t
                    P[j] = -1
                else:
                    s ^= (1 << j)
                    print(j + 1, end=' ')
                    break
