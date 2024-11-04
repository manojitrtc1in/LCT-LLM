import sys
import math
from collections import defaultdict

class F:
    def __init__(self):
        self.mod = 1000000007
        self.to = defaultdict(list)

    def pow(self, x, p, mod):
        if p <= 0:
            return 1
        th = self.pow(x, p // 2, mod)
        th = (th * th) % mod
        if p % 2 == 1:
            th = (th * x) % mod
        return th

    class Fraction:
        def __init__(self, x, y):
            self.x = x
            self.y = y

        def norm(self):
            gcd = self.gcd(self.x, self.y)
            self.x //= gcd
            self.y //= gcd

        def compareTo(self, o):
            if self.x > o.x:
                return 1
            if self.x < o.x:
                return -1
            if self.y > o.y:
                return 1
            if self.y < o.y:
                return -1
            return 0

    def sum(self, a, b):
        c = self.Fraction(a.x * b.y + a.y * b.x, a.y * b.y)
        c.norm()
        return c

    def gcd(self, x, y):
        if y == 0:
            return x
        if x == 0:
            return y
        return self.gcd(y, x % y)

    class Pair:
        def __init__(self, x, y):
            self.x = x
            self.y = y

        def clone(self):
            return F.Pair(self.x, self.y)

        def compareTo(self, o):
            if self.x > o.x:
                return 1
            if self.x < o.x:
                return -1
            if self.y > o.y:
                return 1
            if self.y < o.y:
                return -1
            return 0

    def mult1(self, a, b):
        n = len(a)
        c = [0] * n
        for i in range(n):
            for k in range(n):
                c[i] += a[i ^ k] * b[k]
                c[i] %= self.mod
        return c

    def mult(self, a, b):
        n = len(a)
        c = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    c[i][j] += a[i][k] * b[k][j]
                    c[i][j] %= self.mod
        return c

    def pow_matrix(self, x, p):
        if p == 0:
            e = [[1 if i == j else 0 for j in range(len(x))] for i in range(len(x))]
            return e
        ans = self.pow_matrix(x, p // 2)
        ans = self.mult(ans, ans)
        if p % 2 == 1:
            ans = self.mult(ans, x)
        return ans

    def mult_vector(self, a, b):
        n = len(a)
        c = [0] * n
        for i in range(n):
            for k in range(n):
                c[i] += a[k] * b[k ^ i]
                c[i] %= self.mod
        return c

    def pow_vector(self, x, p):
        if p == 0:
            e = [1] + [0] * (len(x) - 1)
            return e
        ans = self.pow_vector(x, p // 2)
        ans = self.mult_vector(ans, ans)
        if p % 2 == 1:
            ans = self.mult_vector(ans, x)
        return ans

    def modInv(self, x):
        return self.pow(x, self.mod - 2)

    class id5:
        def __init__(self, max):
            self.div = [0] * (max + 1)
            self.primes = []
            for i in range(2, len(self.div)):
                if self.div[i] == 0:
                    self.div[i] = i
                    self.primes.append(i)
                for j in self.primes:
                    if i * j > max:
                        break
                    self.div[i * j] = j

        def factorization(self, x):
            ans = []
            while self.div[x] > 0:
                ans.append(self.div[x])
                x //= self.div[x]
            return ans

        def id1(self, x):
            div = self.factorization(x)
            length = len(div)
            set_ = set()
            for mask in range(1 << length):
                th = 1
                for i in range(length):
                    if (mask & (1 << i)) > 0:
                        th *= div[i]
                set_.add(th)
            return list(set_)

        def id0(self, x):
            div = self.factorization(x)
            pr = 0
            for i in range(len(div)):
                if i == 0 or div[i] != div[i - 1]:
                    pr += 1
            primes = [0] * pr
            sz = [0] * pr
            pr = -1
            for i in range(len(div)):
                if i == 0 or div[i] != div[i - 1]:
                    pr += 1
                    primes[pr] = div[i]
                    sz[pr] = 1
                else:
                    sz[pr] += 1
            pr += 1
            pow_ = [[] for _ in range(pr)]
            for i in range(len(pow_)):
                pow_[i] = [1] * (sz[i] + 1)
                for j in range(1, len(pow_[i])):
                    pow_[i][j] = pow_[i][j - 1] * primes[i]
            th = [0] * pr
            ans = set()
            while self.next(th, sz):
                z = 1
                for i in range(len(th)):
                    z *= pow_[i][th[i]]
                ans.add(z)
            return list(ans)

        def next(self, th, max):
            for i in range(len(th) - 1, -1, -1):
                if th[i] != max[i]:
                    th[i] += 1
                    for j in range(i + 1, len(max)):
                        th[j] = 0
                    return True
            return False

        def id2(self, x):
            if x == 1:
                return "1 = 1"
            list_ = self.factorization(x)
            ans = f"{x} = "
            for i in range(len(list_)):
                ans += str(list_[i])
                if i < len(list_) - 1:
                    ans += " * "
            return ans

    class Rect:
        def __init__(self, x1, y1, x2, y2):
            self.x1 = x1
            self.y1 = y1
            self.x2 = x2
            self.y2 = y2

        def __str__(self):
            return f"{self.x1} {self.y1} {self.x2} {self.y2}"

        def equals(self, r):
            return self.x1 == r.x1 and self.y1 == r.y1 and self.x2 == r.x2 and self.y2 == r.y2

        def inside(self, x, y):
            inx = self.in_(self.x1, self.x2, x)
            iny = self.in_(self.y1, self.y2, y)
            return inx * iny

        def additional(self, r):
            if self.equals(r):
                return 0
            if self.inside(r.x1, r.y1) == 4 or self.inside(r.x2, r.y2) == 4 or self.inside(r.x1, r.y2) == 4 or self.inside(r.x2, r.y1) == 4:
                return 1
            if self.inside(r.x1, r.y1) == 1 or self.inside(r.x2, r.y2) == 1:
                return 1
            return 2

    def in_(self, min, max, x):
        if x == min or x == max:
            return 1
        if min < x < max:
            return 2
        return 0

    def sum_mod(self, x, y):
        if x + y >= self.mod:
            return x + y - self.mod
        return x + y

    def mult(self, x, y):
        return x * y % self.mod

    def div(self, x, y):
        return x * self.modInv(y) % self.mod

    class id6:
        def __init__(self, n):
            self.sum = [0] * n

        def add(self, x, d):
            for i in range(x, len(self.sum)):
                i |= (i + 1)
                self.sum[i] += d

        def sum_(self, r):
            ans = 0
            for i in range(r, -1, -1):
                i &= (i + 1) - 1
                ans += self.sum[i]
            return ans

        def sum_range(self, l, r):
            if l > r:
                return 0
            return self.sum_(r) - self.sum_(l - 1)

    class id3:
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
            return self.f(self.get(2 * v, tl, tm, l, min(r, tm)), self.get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r))

        def set_(self, v, tl, tr, l, r, x):
            self.push(v, tl, tr)
            if l > tr or r < tl:
                return
            if l <= tl and r >= tr:
                self.delta[v] += x
                self.flag[v] = True
                self.push(v, tl, tr)
                return
            tm = (tl + tr) // 2
            self.set_(2 * v, tl, tm, l, r, x)
            self.set_(2 * v + 1, tm + 1, tr, l, r, x)
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

    class Circle:
        def __init__(self, x, y, r):
            self.x = x
            self.y = y
            self.r = r

        def clone(self):
            return F.Circle(self.x, self.y, self.r)

        def compareTo(self, o):
            if self.r != o.r:
                return self.r - o.r
            if self.x != o.x:
                return self.x - o.x
            return self.y - o.y

    class Point:
        def __init__(self, angle, type_):
            self.angle = angle
            self.type = type_

        def __str__(self):
            return f"{self.angle} {self.type}"

        def compareTo(self, o):
            if self.angle > o.angle:
                return 1
            if self.angle < o.angle:
                return -1
            return self.type - o.type

    def inside(self, small, big):
        return (small.x - big.x) ** 2 + (small.y - big.y) ** 2 <= (big.r - small.r) ** 2

    def tangent(self, c1, c2):
        a = c1.clone()
        b = c2.clone()
        minr = min(a.r, b.r)
        a.r -= minr
        b.r -= minr
        b.x -= a.x
        b.y -= a.y
        a0 = math.atan2(b.y, b.x)
        length = math.sqrt(b.x ** 2 + b.y ** 2)
        da = 0
        if a.r == 0:
            da = math.asin(b.r / length) + math.pi / 2
        else:
            da = math.acos(a.r / length)
        return [a0 - da, a0 + da]

    def norm(self, ans):
        for i in range(len(ans)):
            while ans[i] < 0:
                ans[i] += 2 * math.pi
            while ans[i] > 2 * math.pi:
                ans[i] -= 2 * math.pi
        if ans[0] > ans[1]:
            return [0, ans[1], ans[0], 2 * math.pi]
        return ans

    def mergeSort(self, s, a, l, r):
        if r - l <= 1:
            return True
        m = (l + r) // 2
        if not self.mergeSort(s, a, l, m):
            return False
        if not self.mergeSort(s, a, m, r):
            return False
        i = l
        j = m
        k = l
        while i < m and j < r:
            if self.x == len(s):
                return False
            if s[self.x] == '0':
                self.b[k] = a[i]
                i += 1
            else:
                self.b[k] = a[j]
                j += 1
            k += 1
        while i < m:
            self.b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            self.b[k] = a[j]
            j += 1
            k += 1
        for p in range(l, r):
            a[p] = self.b[p]
        return True

    def rev(self, a):
        res = [0] * len(a)
        for i in range(len(a)):
            res[a[i]] = i
        return res

    def solve(self):
        s = input().strip()
        l = 0
        r = 100001
        while True:
            sz = (l + r) // 2
            a = list(range(sz))
            self.x = 0
            self.b = [0] * sz
            if not self.mergeSort(s, a, 0, sz):
                r = sz
                continue
            if self.x < len(s):
                l = sz
                continue
            a = self.rev(a)
            print(sz)
            print(" ".join(str(x + 1) for x in a))
            return

    class Line:
        def __init__(self, k, b):
            self.k = k
            self.b = b

        def __str__(self):
            return f"{self.k}x + {self.b}"

        def value(self, x):
            return self.k * x + self.b

    class id4:
        def __init__(self, n, branchUp):
            self.branchUp = branchUp
            self.neutral = float('-inf') if branchUp else float('inf')
            self.pow = 1
            while self.pow < n:
                self.pow *= 2
            self.ch = [None] * (2 * self.pow)

        def better(self, a, b):
            return self.branchUp ^ (a < b)

        def function(self, a, b):
            return a if self.branchUp ^ (a < b) else b

        def add(self, v, l, r, line):
            if self.ch[v] is None:
                self.ch[v] = line
                return
            if v >= self.pow:
                if v % 2 == 0:
                    if self.better(line.value(l), self.ch[v].value(l)):
                        self.ch[v] = line
                else:
                    if self.better(line.value(r), self.ch[v].value(r)):
                        self.ch[v] = line
                return
            m = (l + r) // 2
            if self.better(line.value(m), self.ch[v].value(m)):
                c = line
                line = self.ch[v]
                self.ch[v] = c
            if self.better(line.value(l), self.ch[v].value(l)):
                self.add(2 * v, l, m, line)
            if self.better(line.value(r), self.ch[v].value(r)):
                self.add(2 * v + 1, m, r, line)

        def get(self, v, l, r, x):
            if self.ch[v] is None:
                return self.neutral
            if v >= self.pow:
                return self.ch[v].value(x)
            ans = self.ch[v].value(x)
            m = (l + r) // 2
            if x <= m:
                ans = self.function(ans, self.get(2 * v, l, m, x))
            if x >= m:
                ans = self.function(ans, self.get(2 * v + 1, m, r, x))
            return ans

        def add_line(self, line):
            self.add(1, 0, self.pow, line)

        def get_value(self, x):
            return self.get(1, 0, self.pow, x)

    def run(self):
        self.solve()

if __name__ == "__main__":
    F().run()
