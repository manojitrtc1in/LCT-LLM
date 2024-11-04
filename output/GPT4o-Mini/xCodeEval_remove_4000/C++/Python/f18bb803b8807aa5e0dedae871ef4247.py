from collections import defaultdict
import sys
import bisect

class B1T:
    def __init__(self, n):
        self.bit = [0] * (n + 1)
        self.n = n

    def add(self, djg, x):
        while djg <= self.n:
            self.bit[djg] += x
            djg += (djg & -djg)

    def sum(self, djg):
        id0 = 0
        while djg:
            id0 += self.bit[djg]
            djg -= (djg & -djg)
        return id0

def read():
    return int(sys.stdin.readline().strip())

n, w = map(int, sys.stdin.readline().strip().split())
x = [0] * n
y = [0] * n
cnt = defaultdict(int)
as_ = [0] * n
cnta = 0
bs = [(0, 0)] * n

for i in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    x[i] = 1.00 * a / (b + w)
    y[i] = 1.00 * a / (b - w)
    cnt[y[i]] += 1

ans = 0
for i in range(n):
    ans += cnt[y[i]] - 1
ans //= 2

for i in range(n):
    as_[i] = x[i]

as_ = sorted(set(as_))
cnta = len(as_)

for i in range(n):
    bs[i] = (y[i], i)

bs.sort()

bit = B1T(100007)
now = 0

for i in range(n):
    while now < n and bs[now][0] < bs[i][0]:
        id_ = bisect.bisect_left(as_, x[bs[now][1]])
        bit.add(100006 - id_, 1)
        now += 1
    id_ = bisect.bisect_left(as_, x[bs[i][1]])
    ans += bit.sum(100006 - id_)

print(ans)
