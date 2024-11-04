import sys
from collections import deque
from math import inf

class SegmentTreeSAMRQ:
    def __init__(self, maxn, one_indexed):
        self.N = 0
        self.T = [None] * (2 * maxn)
        self.def_val = (inf, -inf)
        self.qdef = (inf, -inf)

    def merge(self, l, r):
        return (min(l[0], r[0]), max(l[1], r[1]))

    def apply_val(self, l, r):
        return r

    def init_from_iterable(self, iterable):
        self.N = len(iterable)
        for i in range(self.N):
            self.T[self.N + i] = iterable[i]
        for i in range(self.N - 1, 0, -1):
            self.T[i] = self.merge(self.T[i << 1], self.T[i << 1 | 1])

    def init(self, size):
        self.N = size
        for i in range(1, 2 * self.N):
            self.T[i] = self.def_val

    def update(self, i, v):
        i += self.N - 1
        self.T[i] = self.apply_val(self.T[i], v)
        while i > 1:
            i >>= 1
            self.T[i] = self.merge(self.T[i << 1], self.T[i << 1 | 1])

    def query(self, l, r):
        ql = self.qdef
        qr = self.qdef
        l += self.N - 1
        r += self.N - 1
        while l <= r:
            if l & 1:
                ql = self.merge(ql, self.T[l])
                l += 1
            if not (r & 1):
                qr = self.merge(self.T[r], qr)
                r -= 1
            l >>= 1
            r >>= 1
        return self.merge(ql, qr)

MAXN = int(1e5) + 5
MAXLGN = 20

N = int(sys.stdin.readline().strip())
R = list(map(int, sys.stdin.readline().strip().split()))
ans = [0] * N
T = [SegmentTreeSAMRQ(MAXN * 3, False) for _ in range(MAXLGN)]
RANGE = [[(0, 0)] * (MAXN * 3) for _ in range(MAXLGN)]

if N == 1:
    print(0)
    sys.exit()

for i in range(MAXLGN):
    T[i].init(3 * N)

for j in range(3 * N):
    T[0].update(j, RANGE[0][j] = (max(0, j - R[j % N]), min(3 * N - 1, j + R[j % N])))

for i in range(1, MAXLGN):
    for j in range(3 * N):
        T[i].update(j, RANGE[i][j] = T[i - 1].query(RANGE[i - 1][j][0], RANGE[i - 1][j][1]))

for i in range(N):
    ans[i] = 1
    cur = (N + i, N + i)
    for j in range(MAXLGN - 1, -1, -1):
        nxt = T[j].query(cur[0], cur[1])
        if nxt[1] - nxt[0] + 1 < N:
            ans[i] += 1 << j
            cur = nxt

print(' '.join(map(str, ans)))