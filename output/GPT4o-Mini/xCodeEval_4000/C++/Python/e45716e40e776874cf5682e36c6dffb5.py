import sys
from collections import defaultdict
from itertools import accumulate

class SegmentTree:
    def __init__(self, n, a=None):
        self.inf = 10**18
        self.n = n
        self.n0 = 1
        while self.n0 < n:
            self.n0 <<= 1

        self.max_v = [0] * (4 * self.n0)
        self.smax_v = [-self.inf] * (4 * self.n0)
        self.max_c = [0] * (4 * self.n0)
        self.min_v = [0] * (4 * self.n0)
        self.smin_v = [self.inf] * (4 * self.n0)
        self.min_c = [0] * (4 * self.n0)
        self.sum = [0] * (4 * self.n0)
        self.len = [0] * (4 * self.n0)
        self.ladd = [0] * (4 * self.n0)
        self.lval = [self.inf] * (4 * self.n0)

        self.len[0] = self.n0
        for i in range(0, self.n0 - 1):
            self.len[2 * i + 1] = self.len[2 * i + 2] = self.len[i] >> 1

        for i in range(n):
            self.max_v[self.n0 - 1 + i] = self.min_v[self.n0 - 1 + i] = self.sum[self.n0 - 1 + i] = (a[i] if a is not None else 0)
            self.max_c[self.n0 - 1 + i] = self.min_c[self.n0 - 1 + i] = 1

        for i in range(n, self.n0):
            self.max_v[self.n0 - 1 + i] = self.smax_v[self.n0 - 1 + i] = -self.inf
            self.min_v[self.n0 - 1 + i] = self.smin_v[self.n0 - 1 + i] = self.inf
            self.max_c[self.n0 - 1 + i] = self.min_c[self.n0 - 1 + i] = 0

        for i in range(self.n0 - 2, -1, -1):
            self.update(i)

    def update_node_max(self, k, x):
        self.sum[k] += (x - self.max_v[k]) * self.max_c[k]
        if self.max_v[k] == self.min_v[k]:
            self.max_v[k] = self.min_v[k] = x
        elif self.max_v[k] == self.smin_v[k]:
            self.max_v[k] = self.smin_v[k] = x
        else:
            self.max_v[k] = x
        if self.lval[k] != self.inf and x < self.lval[k]:
            self.lval[k] = x

    def update_node_min(self, k, x):
        self.sum[k] += (x - self.min_v[k]) * self.min_c[k]
        if self.max_v[k] == self.min_v[k]:
            self.max_v[k] = self.min_v[k] = x
        elif self.smax_v[k] == self.min_v[k]:
            self.min_v[k] = self.smax_v[k] = x
        else:
            self.min_v[k] = x
        if self.lval[k] != self.inf and self.lval[k] < x:
            self.lval[k] = x

    def push(self, k):
        if self.n0 - 1 <= k:
            return
        if self.lval[k] != self.inf:
            self.update_all(2 * k + 1, self.lval[k])
            self.update_all(2 * k + 2, self.lval[k])
            self.lval[k] = self.inf
            return
        if self.ladd[k] != 0:
            self.add_all(2 * k + 1, self.ladd[k])
            self.add_all(2 * k + 2, self.ladd[k])
            self.ladd[k] = 0

        if self.max_v[k] < self.max_v[2 * k + 1]:
            self.update_node_max(2 * k + 1, self.max_v[k])
        if self.min_v[2 * k + 1] < self.min_v[k]:
            self.update_node_min(2 * k + 1, self.min_v[k])

        if self.max_v[k] < self.max_v[2 * k + 2]:
            self.update_node_max(2 * k + 2, self.max_v[k])
        if self.min_v[2 * k + 2] < self.min_v[k]:
            self.update_node_min(2 * k + 2, self.min_v[k])

    def update(self, k):
        self.sum[k] = self.sum[2 * k + 1] + self.sum[2 * k + 2]

        if self.max_v[2 * k + 1] < self.max_v[2 * k + 2]:
            self.max_v[k] = self.max_v[2 * k + 2]
            self.max_c[k] = self.max_c[2 * k + 2]
            self.smax_v[k] = max(self.max_v[2 * k + 1], self.smax_v[2 * k + 2])
        elif self.max_v[2 * k + 1] > self.max_v[2 * k + 2]:
            self.max_v[k] = self.max_v[2 * k + 1]
            self.max_c[k] = self.max_c[2 * k + 1]
            self.smax_v[k] = max(self.smax_v[2 * k + 1], self.max_v[2 * k + 2])
        else:
            self.max_v[k] = self.max_v[2 * k + 1]
            self.max_c[k] = self.max_c[2 * k + 1] + self.max_c[2 * k + 2]
            self.smax_v[k] = max(self.smax_v[2 * k + 1], self.smax_v[2 * k + 2])

        if self.min_v[2 * k + 1] < self.min_v[2 * k + 2]:
            self.min_v[k] = self.min_v[2 * k + 1]
            self.min_c[k] = self.min_c[2 * k + 1]
            self.smin_v[k] = min(self.smin_v[2 * k + 1], self.min_v[2 * k + 2])
        elif self.min_v[2 * k + 1] > self.min_v[2 * k + 2]:
            self.min_v[k] = self.min_v[2 * k + 2]
            self.min_c[k] = self.min_c[2 * k + 2]
            self.smin_v[k] = min(self.min_v[2 * k + 1], self.smin_v[2 * k + 2])
        else:
            self.min_v[k] = self.min_v[2 * k + 1]
            self.min_c[k] = self.min_c[2 * k + 1] + self.min_c[2 * k + 2]
            self.smin_v[k] = min(self.smin_v[2 * k + 1], self.smin_v[2 * k + 2])

    def _update_min(self, x, a, b, k, l, r):
        if b <= l or r <= a or self.max_v[k] <= x:
            return
        if a <= l and r <= b and self.smax_v[k] < x:
            self.update_node_max(k, x)
            return

        self.push(k)
        self._update_min(x, a, b, 2 * k + 1, l, (l + r) // 2)
        self._update_min(x, a, b, 2 * k + 2, (l + r) // 2, r)
        self.update(k)

    def _update_max(self, x, a, b, k, l, r):
        if b <= l or r <= a or x <= self.min_v[k]:
            return
        if a <= l and r <= b and x < self.smin_v[k]:
            self.update_node_min(k, x)
            return

        self.push(k)
        self._update_max(x, a, b, 2 * k + 1, l, (l + r) // 2)
        self._update_max(x, a, b, 2 * k + 2, (l + r) // 2, r)
        self.update(k)

    def add_all(self, k, x):
        self.max_v[k] += x
        if self.smax_v[k] != -self.inf:
            self.smax_v[k] += x
        self.min_v[k] += x
        if self.smin_v[k] != self.inf:
            self.smin_v[k] += x

        self.sum[k] += self.len[k] * x
        if self.lval[k] != self.inf:
            self.lval[k] += x
        else:
            self.ladd[k] += x

    def update_all(self, k, x):
        self.max_v[k] = x
        self.smax_v[k] = -self.inf
        self.min_v[k] = x
        self.smin_v[k] = self.inf
        self.max_c[k] = self.min_c[k] = self.len[k]

        self.sum[k] = x * self.len[k]
        self.lval[k] = x
        self.ladd[k] = 0

    def _add_val(self, x, a, b, k, l, r):
        if b <= l or r <= a:
            return
        if a <= l and r <= b:
            self.add_all(k, x)
            return

        self.push(k)
        self._add_val(x, a, b, 2 * k + 1, l, (l + r) // 2)
        self._add_val(x, a, b, 2 * k + 2, (l + r) // 2, r)
        self.update(k)

    def _update_val(self, x, a, b, k, l, r):
        if b <= l or r <= a:
            return
        if a <= l and r <= b:
            self.update_all(k, x)
            return

        self.push(k)
        self._update_val(x, a, b, 2 * k + 1, l, (l + r) // 2)
        self._update_val(x, a, b, 2 * k + 2, (l + r) // 2, r)
        self.update(k)

    def _query_max(self, a, b, k, l, r):
        if b <= l or r <= a:
            return -self.inf
        if a <= l and r <= b:
            return self.max_v[k]
        self.push(k)
        lv = self._query_max(a, b, 2 * k + 1, l, (l + r) // 2)
        rv = self._query_max(a, b, 2 * k + 2, (l + r) // 2, r)
        return max(lv, rv)

    def _query_min(self, a, b, k, l, r):
        if b <= l or r <= a:
            return self.inf
        if a <= l and r <= b:
            return self.min_v[k]
        self.push(k)
        lv = self._query_min(a, b, 2 * k + 1, l, (l + r) // 2)
        rv = self._query_min(a, b, 2 * k + 2, (l + r) // 2, r)
        return min(lv, rv)

    def _query_sum(self, a, b, k, l, r):
        if b <= l or r <= a:
            return 0
        if a <= l and r <= b:
            return self.sum[k]
        self.push(k)
        lv = self._query_sum(a, b, 2 * k + 1, l, (l + r) // 2)
        rv = self._query_sum(a, b, 2 * k + 2, (l + r) // 2, r)
        return lv + rv

    def update_min(self, a, b, x):
        self._update_min(x, a, b, 0, 0, self.n0)

    def update_max(self, a, b, x):
        self._update_max(x, a, b, 0, 0, self.n0)

    def add_val(self, a, b, x):
        self._add_val(x, a, b, 0, 0, self.n0)

    def update_val(self, a, b, x):
        self._update_val(x, a, b, 0, 0, self.n0)

    def query_max(self, a, b):
        return self._query_max(a, b, 0, 0, self.n0)

    def query_min(self, a, b):
        return self._query_min(a, b, 0, 0, self.n0)

    def query_sum(self, a, b):
        return self._query_sum(a, b, 0, 0, self.n0)

def main():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    v = [i - 1 for i in range(n)]
    seg = SegmentTree(n, v)

    d = defaultdict(list)
    for i in range(n):
        for j in range(1, int(a[i]**0.5) + 1):
            if a[i] % j == 0:
                d[j].append(i)
                if a[i] != j * j:
                    d[a[i] // j].append(i)

    ans = 0
    for i in range(200000, 0, -1):
        w = d[i]
        if len(w) <= 1:
            continue

        s = [w[0], w[1], w[-2], w[-1]]
        F = lambda l, r: seg.update_max(l, r, r - 1)
        pre = seg.query_sum(0, n)
        F(w[0] + 1, w[-1])
        F(0, w[-2])
        F(w[1] + 1, n)
        ans += (seg.query_sum(0, n) - pre) * i

    print(ans)

if __name__ == "__main__":
    main()
