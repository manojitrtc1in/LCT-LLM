class SegmentTree_SAM_RQ:
    def __init__(self, MAXN, ONE_INDEXED):
        self.N = 0
        self.T = []
        self.def = (float('inf'), -float('inf'))
        self.qdef = (float('inf'), -float('inf'))
        self.MAXN = MAXN
        self.ONE_INDEXED = ONE_INDEXED

    def merge(self, l, r):
        return (min(l[0], r[0]), max(l[1], r[1]))

    def applyVal(self, l, r):
        return r

    def init(self, st, en):
        self.N = en - st
        self.T = [0] * (2 * self.MAXN)
        for i in range(self.N):
            self.T[self.N + i] = (st + i)
        for i in range(self.N - 1, 0, -1):
            self.T[i] = self.merge(self.T[i << 1], self.T[i << 1 | 1])

    def init(self, size):
        self.N = size
        self.T = [self.def] * (2 * self.N)

    def update(self, i, v):
        i += self.N - self.ONE_INDEXED
        self.T[i] = self.applyVal(self.T[i], v)
        while i > 1:
            self.T[i >> 1] = self.merge(self.T[i], self.T[i ^ 1])
            i >>= 1

    def query(self, l, r):
        ql = self.qdef
        qr = self.qdef
        l += self.N - self.ONE_INDEXED
        r += self.N - self.ONE_INDEXED
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


MAXN = 1e5 + 5
MAXLGN = 20

N = 0
R = [0] * MAXN
ans = [0] * MAXN
T = [SegmentTree_SAM_RQ(MAXN * 3, False) for _ in range(MAXLGN)]
RANGE = [[(0, 0)] * (MAXN * 3) for _ in range(MAXLGN)]

N = int(input())
R = list(map(int, input().split()))
if N == 1:
    print(0)
    exit(0)
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
print(*ans)
