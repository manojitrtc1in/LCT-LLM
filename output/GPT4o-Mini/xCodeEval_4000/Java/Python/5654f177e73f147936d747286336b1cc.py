import sys
import random
from collections import defaultdict
from heapq import heappop, heappush

class DSU:
    def __init__(self, n):
        self.sz = [1] * n
        self.p = list(range(n))

    def get(self, x):
        if x == self.p[x]:
            return x
        par = self.get(self.p[x])
        self.p[x] = par
        return par

    def unite(self, a, b):
        pa = self.get(a)
        pb = self.get(b)
        if pa == pb:
            return False
        if self.sz[pa] < self.sz[pb]:
            self.p[pa] = pb
            self.sz[pb] += self.sz[pa]
        else:
            self.p[pb] = pa
            self.sz[pa] += self.sz[pb]
        return True

class SegmentTreeAdd:
    def __init__(self, a):
        self.pow = 1
        while self.pow < len(a):
            self.pow *= 2
        self.flag = [False] * (2 * self.pow)
        self.max = [float('-inf')] * (2 * self.pow)
        self.delta = [0] * (2 * self.pow)
        for i in range(len(a)):
            self.max[self.pow + i] = a[i]
        for i in range(self.pow - 1, 0, -1):
            self.max[i] = self.f(self.max[2 * i], self.max[2 * i + 1])

    def get(self, v, tl, tr, l, r):
        self.push(v, tl, tr)
        if l > r:
            return float('-inf')
        if l == tl and r == tr:
            return self.max[v]
        tm = (tl + tr) // 2
        return self.f(self.get(2 * v, tl, tm, l, min(r, tm)),
                      self.get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r))

    def set(self, v, tl, tr, l, r, x):
        self.push(v, tl, tr)
        if l > tr or r < tl:
            return
        if l <= tl and r >= tr:
            self.delta[v] += x
            self.flag[v] = True
            self.push(v, tl, tr)
            return
        tm = (tl + tr) // 2
        self.set(2 * v, tl, tm, l, r, x)
        self.set(2 * v + 1, tm + 1, tr, l, r, x)
        self.max[v] = self.f(self.max[2 * v], self.max[2 * v + 1])

    def push(self, v, tl, tr):
        if self.flag[v]:
            if v < self.pow:
                self.flag[2 * v] = True
                self.flag[2 * v + 1] = True
                self.delta[2 * v] += self.delta[v]
                self.delta[2 * v + 1] += self.delta[v]
            self.flag[v] = False
            self.max[v] += self.delta[v]
            self.delta[v] = 0

    def f(self, a, b):
        return max(a, b)

class SegmentTreeSet:
    def __init__(self, a):
        self.pow = 1
        while self.pow < len(a):
            self.pow *= 2
        self.flag = [False] * (2 * self.pow)
        self.sum = [0] * (2 * self.pow)
        self.delta = [0] * (2 * self.pow)
        for i in range(len(a)):
            self.sum[self.pow + i] = a[i]

    def get(self, v, tl, tr, l, r):
        self.push(v, tl, tr)
        if l > r:
            return 0
        if l == tl and r == tr:
            return self.sum[v]
        tm = (tl + tr) // 2
        return self.f(self.get(2 * v, tl, tm, l, min(r, tm)),
                      self.get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r))

    def set(self, v, tl, tr, l, r, x):
        self.push(v, tl, tr)
        if l > tr or r < tl:
            return
        if l <= tl and r >= tr:
            self.delta[v] = x
            self.flag[v] = True
            self.push(v, tl, tr)
            return
        tm = (tl + tr) // 2
        self.set(2 * v, tl, tm, l, r, x)
        self.set(2 * v + 1, tm + 1, tr, l, r, x)
        self.sum[v] = self.f(self.sum[2 * v], self.sum[2 * v + 1])

    def push(self, v, tl, tr):
        if self.flag[v]:
            if v < self.pow:
                self.flag[2 * v] = True
                self.flag[2 * v + 1] = True
                self.delta[2 * v] = self.delta[v]
                self.delta[2 * v + 1] = self.delta[v]
            self.flag[v] = False
            self.sum[v] = self.delta[v] * (tr - tl + 1)

    def f(self, a, b):
        return a + b

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"{self.x} {self.y}"

    def __lt__(self, other):
        return (self.y, self.x) < (other.y, other.x)

class Fenvik:
    def __init__(self, n):
        self.t = [0] * n

    def add(self, x, delta):
        for i in range(x, len(self.t)):
            self.t[i] += delta

    def sum(self, r):
        ans = 0
        x = r
        while x >= 0:
            ans += self.t[x]
            x = (x & (x + 1)) - 1
        return ans

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l - 1)

class SegmentTreeMaxSum:
    def __init__(self, a):
        self.pow = 1
        while self.pow < len(a):
            self.pow *= 2
        self.sum = [0] * (2 * self.pow)
        self.maxPrefSum = [0] * (2 * self.pow)
        self.maxSufSum = [0] * (2 * self.pow)
        self.maxSum = [0] * (2 * self.pow)
        for i in range(len(a)):
            self.sum[self.pow + i] = a[i]
            self.maxSum[self.pow + i] = max(a[i], 0)
            self.maxPrefSum[self.pow + i] = self.maxSum[self.pow + i]
            self.maxSufSum[self.pow + i] = self.maxSum[self.pow + i]
        for i in range(self.pow - 1, 0, -1):
            self.update(i)

    def get(self, v, tl, tr, l, r):
        if r <= tl or l >= tr:
            return [0, 0, 0, 0]
        if l <= tl and r >= tr:
            return [self.maxPrefSum[v], self.maxSum[v], self.maxSufSum[v], self.sum[v]]
        tm = (tl + tr) // 2
        left = self.get(2 * v, tl, tm, l, r)
        right = self.get(2 * v + 1, tm, tr, l, r)
        return [
            max(left[0], right[0] + left[3]),
            max(left[1], max(right[1], left[2] + right[0])),
            max(right[2], left[2] + right[3]),
            left[3] + right[3]
        ]

    def set(self, v, tl, tr, x, value):
        if v >= self.pow:
            self.sum[v] = value
            self.maxSum[v] = max(value, 0)
            self.maxPrefSum[v] = self.maxSum[v]
            self.maxSufSum[v] = self.maxSum[v]
            return
        tm = (tl + tr) // 2
        if x < tm:
            self.set(2 * v, tl, tm, x, value)
        else:
            self.set(2 * v + 1, tm, tr, x, value)
        self.update(v)

    def update(self, i):
        self.sum[i] = self.f(self.sum[2 * i], self.sum[2 * i + 1])
        self.maxSum[i] = max(self.maxSum[2 * i], max(self.maxSum[2 * i + 1], self.maxSufSum[2 * i] + self.maxPrefSum[2 * i + 1]))
        self.maxPrefSum[i] = max(self.maxPrefSum[2 * i], self.maxPrefSum[2 * i + 1] + self.sum[2 * i])
        self.maxSufSum[i] = max(self.maxSufSum[2 * i + 1], self.maxSufSum[2 * i] + self.sum[2 * i + 1])

    def f(self, a, b):
        return a + b

class FastScanner:
    def __init__(self, f):
        self.br = f
        self.st = None

    def next_line(self):
        return self.br.readline().strip()

    def next(self):
        while self.st is None or not self.st:
            self.st = self.next_line().split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

class E:
    def __init__(self):
        self.mod = 1000000007
        self.random = random.Random()
        self.max = float('inf') / 2
        self.eps = 1e-10
        self.inv = []

    def signum(self, x):
        if x > self.eps:
            return 1
        if x < -self.eps:
            return -1
        return 0

    def abs(self, x):
        return -x if x < 0 else x

    def min(self, x, y):
        return x if x < y else y

    def max(self, x, y):
        return x if x > y else y

    def gcd(self, x, y):
        while y > 0:
            c = y
            y = x % y
            x = c
        return x

    def shuffle(self, a):
        for i in range(len(a)):
            x = self.random.randint(0, i)
            a[x], a[i] = a[i], a[x]

    def add(self, map, l):
        if l in map:
            map[l] += 1
        else:
            map[l] = 1

    def remove(self, map, s):
        if map[s] > 1:
            map[s] -= 1
        else:
            del map[s]

    def read_graph(self, n, m):
        to = [[] for _ in range(n)]
        sz = [0] * n
        x = [0] * m
        y = [0] * m
        for i in range(m):
            x[i] = self.in_.next_int() - 1
            y[i] = self.in_.next_int() - 1
            sz[x[i]] += 1
            sz[y[i]] += 1
        for i in range(n):
            to[i] = [0] * sz[i]
            sz[i] = 0
        for i in range(m):
            to[x[i]][sz[x[i]]] = y[i]
            to[y[i]][sz[y[i]]] = x[i]
            sz[x[i]] += 1
            sz[y[i]] += 1
        return to

    def kuhn(self, v, edge, used, mt):
        used[v] = True
        for u in edge[v]:
            if mt[u] < 0 or (not used[mt[u]] and self.kuhn(mt[u], edge, used, mt)):
                mt[u] = v
                return True
        return False

    def matching(self, edge):
        n = len(edge)
        mt = [-1] * n
        used = [False] * n
        ans = 0
        for i in range(n):
            if not used[i] and self.kuhn(i, edge, used, mt):
                used = [False] * n
                ans += 1
        return ans

    def solve(self):
        n = self.in_.next_int()
        m = self.in_.next_int()
        q = self.in_.next_int()
        v = [self.in_.next_int() for _ in range(n)]
        self.inv = [0] * n
        for i in range(n):
            self.inv[v[i] - 1] = i
        a = [self.in_.next_int() - 1 for _ in range(m)]
        b = [self.in_.next_int() - 1 for _ in range(m)]
        type_ = [False] * q
        x = [0] * q
        removed = [False] * m
        for i in range(q):
            if self.in_.next_int() == 1:
                x[i] = self.in_.next_int() - 1
                type_[i] = True
            else:
                x[i] = self.in_.next_int() - 1
                removed[x[i]] = True
        dsu = DSU1(v, m)
        for i in range(m):
            if not removed[i]:
                dsu.unite(a[i], b[i])
        for i in range(q - 1, -1, -1):
            if not type_[i]:
                dsu.unite(a[x[i]], b[x[i]])
        for i in range(q):
            if type_[i]:
                self.out.write(f"{dsu.poll(x[i])}\n")
            else:
                dsu.pop_edge()

    def run(self):
        try:
            self.in_ = FastScanner(sys.stdin)
            self.out = sys.stdout
            self.solve()
        except Exception as e:
            print(e)

class DSU1:
    def __init__(self, v, m):
        n = len(v)
        self.p = list(range(n))
        self.sz = [1] * n
        self.q = [None] * n
        self.less = Stack(m)
        self.more = Stack(m)
        self.used = [False] * (n + 1)
        self.inv = [0] * n
        for i in range(n):
            self.q[i] = []
            self.q[i].append(-v[i])

    def get(self, x):
        while x != self.p[x]:
            x = self.p[x]
        return x

    def unite(self, a, b):
        pa = self.get(a)
        pb = self.get(b)
        if pa == pb:
            self.less.add(-1)
            self.more.add(-1)
            return False
        if self.sz[pa] < self.sz[pb]:
            self.p[pa] = pb
            self.sz[pb] += self.sz[pa]
            self.less.add(pa)
            self.more.add(pb)
            for i in self.q[pa]:
                self.q[pb].append(i)
        else:
            self.p[pb] = pa
            self.sz[pa] += self.sz[pb]
            self.less.add(pb)
            self.more.add(pa)
            for i in self.q[pb]:
                self.q[pa].append(i)
        return True

    def pop_edge(self):
        pa = self.less.pop()
        pb = self.more.pop()
        if pa < 0:
            return
        self.p[pa] = pa
        self.sz[pb] -= self.sz[pa]

    def poll(self, x):
        px = self.get(x)
        while self.q[px]:
            v = -self.q[px].pop()
            if not self.used[v] and self.get(self.inv[v - 1]) == px:
                self.used[v] = True
                return v
        return 0

if __name__ == "__main__":
    E().run()
