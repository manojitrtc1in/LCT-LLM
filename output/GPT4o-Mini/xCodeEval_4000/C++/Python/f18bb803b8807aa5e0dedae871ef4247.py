import sys
from collections import defaultdict
from bisect import bisect_left

class B1T:
    def __init__(self, n):
        self.bit = [0] * (n + 1)
        self.n = n

    def add(self, djg, x):
        while djg <= self.n:
            self.bit[djg] += x
            djg += (djg & -djg)

    def sum(self, djg):
        s0m = 0
        while djg:
            s0m += self.bit[djg]
            djg -= (djg & -djg)
        return s0m

def read_int():
    return int(sys.stdin.readline().strip())

n, w = map(int, sys.stdin.readline().strip().split())
x = [0] * n
y = [0] * n
cnt = defaultdict(int)

for i in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    x[i] = 1.00 * a / (b + w)
    y[i] = 1.00 * a / (b - w)
    cnt[y[i]] += 1

ans = 0
for i in range(n):
    ans += cnt[y[i]] - 1
ans //= 2

as_ = sorted(set(x))
cnta = len(as_)
bs = sorted((y[i], i) for i in range(n))

bit = B1T(100007)
now = 0

for i in range(n):
    while now < n and bs[now][0] < bs[i][0]:
        id_ = bisect_left(as_, x[bs[now][1]])
        bit.add(100006 - id_, 1)
        now += 1
    id_ = bisect_left(as_, x[bs[i][1]])
    ans += bit.sum(100006 - id_)

print(ans)
