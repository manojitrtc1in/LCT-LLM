import sys
from collections import defaultdict

def read():
    return int(sys.stdin.readline().strip())

Maxn = 100005
l = [0] * Maxn
r = [0] * Maxn
n, m = map(int, sys.stdin.readline().split())
sum = [0] * Maxn
dp1 = [0] * Maxn
dp2 = [0] * Maxn
bit = [0] * Maxn

def modify(pos, val):
    while pos < Maxn:
        bit[pos] = max(bit[pos], val)
        pos += pos & -pos

def query(pos):
    ans = 0
    while pos:
        ans = max(ans, bit[pos])
        pos -= pos & -pos
    return ans

for i in range(n):
    l[i], r[i] = map(int, sys.stdin.readline().split())
    sum[l[i]] += 1
    sum[r[i] + 1] -= 1

for i in range(1, m + 1):
    sum[i] += sum[i - 1]

dp1[0] = 0
for i in range(1, m + 1):
    dp1[i] = query(sum[i] + 1) + 1
    modify(sum[i] + 1, dp1[i])

bit = [0] * Maxn
for i in range(m, 0, -1):
    dp2[i] = query(sum[i] + 1) + 1
    modify(sum[i] + 1, dp2[i])

ans = 0
for i in range(1, m + 1):
    ans = max(ans, dp1[i] + dp2[i] - 1)

print(ans)
