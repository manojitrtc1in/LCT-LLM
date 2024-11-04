from collections import deque
import sys
import math
from typing import List, Tuple

input = sys.stdin.read
def read_ints():
    return list(map(int, input().split()))

class SegmentTreeSAMRQ:
    def __init__(self, maxn: int, id5: bool):
        self.N = 0
        self.T = [(float('inf'), -float('inf'))] * (2 * maxn)
        self.def_val = (float('inf'), -float('inf'))
        self.qdef = (float('inf'), -float('inf'))
        self.id5 = id5

    def merge(self, l: Tuple[int, int], r: Tuple[int, int]) -> Tuple[int, int]:
        return (min(l[0], r[0]), max(l[1], r[1]))

    def apply_val(self, l: Tuple[int, int], r: Tuple[int, int]) -> Tuple[int, int]:
        return r

    def init_from_iterable(self, st: List[int]):
        self.N = len(st)
        for i in range(self.N):
            self.T[self.N + i] = st[i]
        for i in range(self.N - 1, 0, -1):
            self.T[i] = self.merge(self.T[i << 1], self.T[i << 1 | 1])

    def init(self, size: int):
        self.N = size
        for i in range(1, 2 * self.N):
            self.T[i] = self.def_val

    def update(self, i: int, v: Tuple[int, int]):
        i += self.N - self.id5
        self.T[i] = self.apply_val(self.T[i], v)
        while i > 1:
            i >>= 1
            self.T[i] = self.merge(self.T[i << 1], self.T[i << 1 | 1])

    def query(self, l: int, r: int) -> Tuple[int, int]:
        ql = self.qdef
        qr = self.qdef
        l += self.N - self.id5
        r += self.N - self.id5
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
id0 = 20

N = int(input())
R = read_ints()

if N == 1:
    print(0)
    sys.exit()

T = [SegmentTreeSAMRQ(MAXN * 3, False) for _ in range(id0)]
RANGE = [[(0, 0)] * (MAXN * 3) for _ in range(id0)]

for i in range(id0):
    T[i].init(3 * N)

for j in range(3 * N):
    T[0].update(j, RANGE[0][j] := (max(0, j - R[j % N]), min(3 * N - 1, j + R[j % N])))

for i in range(1, id0):
    for j in range(3 * N):
        T[i].update(j, RANGE[i][j] := T[i - 1].query(RANGE[i - 1][j][0], RANGE[i - 1][j][1]))

ans = [0] * N

for i in range(N):
    ans[i] = 1
    cur = (N + i, N + i)
    for j in range(id0 - 1, -1, -1):
        nxt = T[j].query(cur[0], cur[1])
        if nxt[1] - nxt[0] + 1 < N:
            ans[i] += 1 << j
            cur = nxt

print(*ans)
