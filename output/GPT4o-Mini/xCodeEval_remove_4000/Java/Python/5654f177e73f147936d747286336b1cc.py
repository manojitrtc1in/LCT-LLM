import sys
import random
from collections import defaultdict
from math import sqrt, inf

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

class Id2:
    def __init__(self, a):
        self.pow = 1
        while self.pow < len(a):
            self.pow *= 2
        self.flag = [False] * (2 * self.pow)
        self.max = [-(inf // 2)] * (2 * self.pow)
        self.delta = [0] * (2 * self.pow)
        for i in range(len(a)):
            self.max[self.pow + i] = a[i]
        for i in range(self.pow - 1, 0, -1):
            self.max[i] = self.f(self.max[2 * i], self.max[2 * i + 1])

    def get(self, v, tl, tr, l, r):
        self.push(v, tl, tr)
        if l > r:
            return -(inf // 2)
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

class Id5:
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

    def __lt__(self, other):
        if self.y != other.y:
            return self.y > other.y
        return self.x < other.x

    def __str__(self):
        return f"{self.x} {self.y}"

class Rect:
    def __init__(self, x1, x2, y1, y2, number):
        self.x1 = x1
        self.x2 = x2
        self.y1 = y1
        self.y2 = y2
        self.number = number

class Id6:
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

class Id4:
    def __init__(self, a):
        self.pow = 1
        while self.pow < len(a):
            self.pow *= 2
        self.sum = [0] * (2 * self.pow)
        self.id3 = [0] * (2 * self.pow)
        self.id7 = [0] * (2 * self.pow)
        self.maxSum = [0] * (2 * self.pow)
        for i in range(len(a)):
            self.sum[self.pow + i] = a[i]
            self.maxSum[self.pow + i] = max(a[i], 0)
            self.id3[self.pow + i] = self.maxSum[self.pow + i]
            self.id7[self.pow + i] = self.maxSum[self.pow + i]
        for i in range(self.pow - 1, 0, -1):
            self.update(i)

    def get(self, v, tl, tr, l, r):
        if r <= tl or l >= tr:
            return [0, 0, 0, 0]
        if l <= tl and r >= tr:
            return [self.id3[v], self.maxSum[v], self.id7[v], self.sum[v]]
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
            self.id3[v] = self.maxSum[v]
            self.id7[v] = self.maxSum[v]
            return
        tm = (tl + tr) // 2
        if x < tm:
            self.set(2 * v, tl, tm, x, value)
        else:
            self.set(2 * v + 1, tm, tr, x, value)
        self.update(v)

    def update(self, i):
        self.sum[i] = self.f(self.sum[2 * i], self.sum[2 * i + 1])
        self.maxSum[i] = max(self.maxSum[2 * i], max(self.maxSum[2 * i + 1], self.id7[2 * i] + self.id3[2 * i + 1]))
        self.id3[i] = max(self.id3[2 * i], self.id3[2 * i + 1] + self.sum[2 * i])
        self.id7[i] = max(self.id7[2 * i + 1], self.id7[2 * i] + self.sum[2 * i + 1])

    def f(self, a, b):
        return a + b

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return f"{self.x} {self.y}"

    def dist2(self):
        return self.x * self.x + self.y * self.y

    def add(self, v):
        return Point(self.x + v.x, self.y + v.y)

class Circle:
    def __init__(self, p, r):
        self.p = p
        self.r = r

    def angle(self):
        z = self.r / sqrt(2)
        z -= z % 1e-5
        return Point(self.p.x - z, self.p.y - z)

    def inside(self, p):
        return self.id0(p.x - self.p.x, p.y - self.p.y) <= self.sq(self.r)

    def id0(self, x, y):
        return self.sq(x) + self.sq(y)

    def sq(self, x):
        return x * x

class Fraction:
    def __init__(self, x, y, need_norm):
        self.x = x
        self.y = y
        if y < 0:
            self.x *= -1
            self.y *= -1
        if need_norm:
            gcd = self.gcd(self.x, self.y)
            self.x //= gcd
            self.y //= gcd

    def __lt__(self, other):
        res = self.x * other.y - self.y * other.x
        return res > 0

    def __str__(self):
        return f"{self.x}/{self.y}"

    def gcd(self, x, y):
        while y > 0:
            x, y = y, x % y
        return x

class Event:
    def __init__(self, f, type):
        self.f = f
        self.type = type

    def __lt__(self, other):
        c = self.f < other.f
        if c != 0:
            return c
        return self.type < other.type

class Stack:
    def __init__(self, n):
        self.st = [0] * n
        self.sz = 0

    def is_empty(self):
        return self.sz == 0

    def peek(self):
        return self.st[self.sz - 1]

    def pop(self):
        self.sz -= 1
        return self.st[self.sz]

    def clear(self):
        self.sz = 0

    def add(self, x):
        self.st[self.sz] = x
        self.sz += 1

    def get(self, x):
        return self.st[x]

class FastScanner:
    def __init__(self, f):
        self.br = open(f, 'r')
        self.st = []

    def next_line(self):
        return self.br.readline().strip()

    def next(self):
        while not self.st:
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
        self.max = inf // 2
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
            x, y = y, x % y
        return x

    def shuffle(self, a):
        for i in range(len(a)):
            x = self.random.randint(0, i)
            a[x], a[i] = a[i], a[x]

    def read_graph(self, n, m):
        to = [[] for _ in range(n)]
        sz = [0] * n
        x = [0] * m
        y = [0] * m
        for i in range(m):
            x[i] = self.in.next_int() - 1
            y[i] = self.in.next_int() - 1
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

    def solve(self):
        n = self.in.next_int()
        m = self.in.next_int()
        q = self.in.next_int()
        v = [self.in.next_int() for _ in range(n)]
        self.inv = [0] * n
        for i in range(len(v)):
            self.inv[v[i] - 1] = i
        a = [self.in.next_int() - 1 for _ in range(m)]
        b = [self.in.next_int() - 1 for _ in range(m)]
        type = [False] * q
        x = [0] * q
        removed = [False] * m
        for i in range(q):
            if self.in.next_int() == 1:
                x[i] = self.in.next_int() - 1
                type[i] = True
            else:
                x[i] = self.in.next_int() - 1
                removed[x[i]] = True
        dsu = DSU(n)
        for i in range(m):
            if not removed[i]:
                dsu.unite(a[i], b[i])
        for i in range(q - 1, -1, -1):
            if not type[i]:
                dsu.unite(a[x[i]], b[x[i]])
        for i in range(q):
            if type[i]:
                self.out.write(f"{dsu.poll(x[i])}\n")
            else:
                dsu.pop_edge()

    def run(self):
        self.in = FastScanner(sys.stdin)
        self.out = sys.stdout
        self.solve()

if __name__ == "__main__":
    E().run()
