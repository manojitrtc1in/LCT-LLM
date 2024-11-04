import math
import random
import sys

class FastScanner:
    def __init__(self, f):
        if isinstance(f, str):
            self.br = open(f, 'r')
        else:
            self.br = f
        self.st = None

    def nextLine(self):
        return self.br.readline().strip()

    def next(self):
        if self.st is None or not self.st:
            self.st = self.br.readline().strip().split()
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

class F:
    def __init__(self):
        self.in_ = FastScanner(sys.stdin)
        self.out = sys.stdout
        self.systemIO = True

    def pow(self, x, p, mod):
        if p <= 0:
            return 1
        th = self.pow(x, p // 2, mod)
        th *= th
        th %= mod
        if p % 2 == 1:
            th *= x
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
            return self.Pair(self.x, self.y)

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
                c[i] %= mod
        return c

    def mult(self, a, b):
        n = len(a)
        c = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    c[i][j] += a[i][k] * b[k][j]
                    c[i][j] %= mod
        return c

    def pow(self, x, p):
        if p == 0:
            e = [[0] * len(x) for _ in range(len(x))]
            for i in range(len(e)):
                e[i][i] = 1
            return e
        ans = self.pow(x, p // 2)
        ans = self.mult(ans, ans)
        if p % 2 == 1:
            ans = self.mult(ans, x)
        return ans

    def mult(self, a, b):
        n = len(a)
        c = [0] * n
        for i in range(n):
            for k in range(n):
                c[i] += a[k] * b[k ^ i]
                c[i] %= mod
        return c

    def pow(self, x, p):
        if p == 0:
            e = [0] * len(x)
            e[0] = 1
            return e
        ans = self.pow(x, p // 2)
        ans = self.mult(ans, ans)
        if p % 2 == 1:
            ans = self.mult(ans, x)
        return ans

    def pow(self, x, p):
        if p <= 0:
            return 1
        ans = self.pow(x, p // 2)
        ans = (ans * ans) % mod
        if p % 2 == 1:
            ans = (ans * x) % mod
        return ans

    def modInv(self, x):
        return self.pow(x, mod - 2)

    random = random.Random(566)
    to = []

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
            ans = list(set_)
            ans.sort()
            return ans

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
            pow = [[0] * (sz[i] + 1) for i in range(pr)]
            for i in range(pr):
                pow[i][0] = 1
                for j in range(1, len(pow[i])):
                    pow[i][j] = pow[i][j - 1] * primes[i]
            th = [0] * pr
            ans = set()
            while True:
                z = 1
                for i in range(len(th)):
                    z *= pow[i][th[i]]
                ans.add(z)
                for i in range(len(th) - 1, -1, -1):
                    if th[i] != sz[i]:
                        th[i] += 1
                        for j in range(i + 1, len(sz)):
                            th[j] = 0
                        break
                else:
                    break
            ans = list(ans)
            ans.sort()
            return ans

        def next(self, th, sz):
            for i in range(len(th) - 1, -1, -1):
                if th[i] != sz[i]:
                    th[i] += 1
                    for j in range(i + 1, len(sz)):
                        th[j] = 0
                    return True
            return False

        def id2(self, x):
            if x == 1:
                return "1 = 1"
            div = self.factorization(x)
            ans = str(x) + " = "
            for i in range(len(div)):
                ans += str(div[i])
                if i < len(div) - 1:
                    ans += " * "
            return ans

    class Rect:
        def __init__(self, x1, y1, x2, y2):
            self.x1 = x1
            self.y1 = y1
            self.x2 = x2
            self.y2 = y2

        def __str__(self):
            return str(self.x1) + " " + str(self.y1) + " " + str(self.x2) + " " + str(self.y2)

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
        if x > min and x < max:
            return 2
        return 0

    def sum(self, x, y):
        if x + y >= mod:
            return x + y - mod
        return x + y

    def mult(self, x, y):
        return x * y % mod

    def div(self, x, y):
        return x * self.modInv(y) % mod

    mod = 1000000007

    class id6:
        def __init__(self, n):
            self.sum = [0] * n

        def add(self, x, d):
            for i in range(x, len(self.sum)):
                self.sum[i] += d

        def sum(self, r):
            ans = 0
            for i in range(r, -1, -1):
                ans += self.sum[i]
            return ans

        def sum(self, l, r):
            if l > r:
                return 0
            return self.sum(r) - self.sum(l - 1)

    class id3:
        def __init__(self, a):
            self.pow = 1
            while self.pow < len(a):
                self.pow *= 2
            self.flag = [False] * (2 * self.pow)
            self.max = [float('-inf')] * (2 * self.pow)
            self.delta = [0] * (2 * self.pow)
            for i in range(len(self.max)):
                self.max[i] = float('-inf') / 2
            for i in range(len(a)):
                self.max[self.pow + i] = a[i]
            for i in range(self.pow - 1, 0, -1):
                self.max[i] = self.f(self.max[2 * i], self.max[2 * i + 1])

        def add(self, v, tl, tr, l, r, x):
            self.push(v, tl, tr)
            if l > tr or r < tl:
                return
            if l <= tl and r >= tr:
                self.delta[v] += x
                self.flag[v] = True
                self.push(v, tl, tr)
                return
            m = (tl + tr) // 2
            self.add(2 * v, tl, m, l, r, x)
            self.add(2 * v + 1, m + 1, tr, l, r, x)
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

        def get(self, v, tl, tr, x):
            self.push(v, tl, tr)
            if self.max[v] == float('-inf'):
                return float('-inf')
            if v >= self.pow:
                return self.max[v]
            ans = self.max[v]
            m = (tl + tr) // 2
            if x <= m:
                ans = self.f(ans, self.get(2 * v, tl, m, x))
            if x >= m:
                ans = self.f(ans, self.get(2 * v + 1, m + 1, tr, x))
            return ans

        def get(self, x):
            return self.get(1, 0, self.pow, x)

    class Circle:
        def __init__(self, x, y, r):
            self.x = x
            self.y = y
            self.r = r

        def clone(self):
            return self.Circle(self.x, self.y, self.r)

        def compareTo(self, o):
            if self.r != o.r:
                return self.r - o.r
            if self.x != o.x:
                return self.x - o.x
            return self.y - o.y

    class Point:
        def __init__(self, angle, type):
            self.angle = angle
            self.type = type

        def __str__(self):
            return str(self.angle) + " " + str(self.type)

        def compareTo(self, o):
            if self.angle > o.angle:
                return 1
            if self.angle < o.angle:
                return -1
            return self.type - o.type

    def inside(self, small, big):
        return (small.x - big.x) * (small.x - big.x) + (small.y - big.y) * (small.y - big.y) <= (big.r - small.r) * (big.r - small.r)

    def tangent(self, c1, c2):
        a = c1.clone()
        b = c2.clone()
        minr = min(a.r, b.r)
        a.r -= minr
        b.r -= minr
        b.x -= a.x
        b.y -= a.y
        a0 = math.atan2(b.y, b.x)
        length = math.sqrt(b.x * b.x + b.y * b.y)
        da = 0
        if a.r == 0:
            da = math.asin(b.r / length) + math.pi / 2
        else:
            da = math.acos(a.r / length)
        ans = [a0 - da, a0 + da]
        return ans

    def norm(self, ans):
        for i in range(len(ans)):
            while ans[i] < 0:
                ans[i] += 2 * math.pi
            while ans[i] > 2 * math.pi:
                ans[i] -= 2 * math.pi
        if ans[0] > ans[1]:
            answer = [0, ans[1], ans[0], 2 * math.pi]
            return answer
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
            if x == len(s):
                return False
            if s[x] == '0':
                b[k] = a[i]
                i += 1
            else:
                b[k] = a[j]
                j += 1
            k += 1
        while i < m:
            b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            b[k] = a[j]
            j += 1
            k += 1
        for p in range(l, r):
            a[p] = b[p]
        return True

    def rev(self, a):
        res = [0] * len(a)
        for i in range(len(a)):
            res[a[i]] = i
        return res

    def solve(self):
        s = self.in_.next()
        sz = 1
        while True:
            a = [0] * sz
            for i in range(sz):
                a[i] = i
            x = 0
            b = [0] * sz
            if not self.mergeSort(s, a, 0, sz):
                continue
            if x < len(s):
                continue
            a = self.rev(a)
            self.out.println(sz)
            for i in range(sz):
                self.out.print(a[i] + 1 + " ")
            return

    def run(self):
        self.solve()
        self.out.close()

if __name__ == '__main__':
    F().run()
