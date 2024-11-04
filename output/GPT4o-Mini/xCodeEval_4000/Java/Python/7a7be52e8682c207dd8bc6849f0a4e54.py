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

        def __lt__(self, other):
            if self.x != other.x:
                return self.x < other.x
            return self.y < other.y

        @staticmethod
        def gcd(x, y):
            if y == 0:
                return x
            return F.Fraction.gcd(y, x % y)

    def sum_fractions(self, a, b):
        c = self.Fraction(a.x * b.y + a.y * b.x, a.y * b.y)
        c.norm()
        return c

    class Pair:
        def __init__(self, x, y):
            self.x = x
            self.y = y

        def __lt__(self, other):
            if self.x != other.x:
                return self.x < other.x
            return self.y < other.y

    def mult1(self, a, b):
        n = len(a)
        c = [0] * n
        for i in range(n):
            for k in range(n):
                c[i] = (c[i] + a[i ^ k] * b[k]) % self.mod
        return c

    def mult(self, a, b):
        n = len(a)
        c = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % self.mod
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
                c[i] = (c[i] + a[k] * b[k ^ i]) % self.mod
        return c

    def pow_vector(self, x, p):
        if p == 0:
            e = [0] * len(x)
            e[0] = 1
            return e
        ans = self.pow_vector(x, p // 2)
        ans = self.mult_vector(ans, ans)
        if p % 2 == 1:
            ans = self.mult_vector(ans, x)
        return ans

    def mod_inv(self, x):
        return self.pow(x, self.mod - 2)

    class Factorizator:
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

        def all_divisors(self, x):
            div = self.factorization(x)
            length = len(div)
            set_div = set()
            for mask in range(1 << length):
                th = 1
                for i in range(length):
                    if (mask & (1 << i)) > 0:
                        th *= div[i]
                set_div.add(th)
            return list(set_div)

        def divisors(self, x):
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
            for i in range(len(pow)):
                pow[i][0] = 1
                for j in range(1, len(pow[i])):
                    pow[i][j] = pow[i][j - 1] * primes[i]
            th = [0] * pr
            ans = set()
            while self.next(th, sz):
                z = 1
                for i in range(len(th)):
                    z *= pow[i][th[i]]
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

        def factorization_to_string(self, x):
            if x == 1:
                return "1 = 1"
            list_factors = self.factorization(x)
            ans = f"{x} = "
            ans += " * ".join(map(str, list_factors))
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
            inx = self.in_range(self.x1, self.x2, x)
            iny = self.in_range(self.y1, self.y2, y)
            return inx * iny

        def additional(self, r):
            if self.equals(r):
                return 0
            if self.inside(r.x1, r.y1) == 4 or self.inside(r.x2, r.y2) == 4 or self.inside(r.x1, r.y2) == 4 or self.inside(r.x2, r.y1) == 4:
                return 1
            if self.inside(r.x1, r.y1) == 1 or self.inside(r.x2, r.y2) == 1:
                return 1
            return 2

        @staticmethod
        def in_range(min, max, x):
            if x == min or x == max:
                return 1
            if min < x < max:
                return 2
            return 0

    def sum_mod(self, x, y):
        if x + y >= self.mod:
            return x + y - self.mod
        return x + y

    def mult_mod(self, x, y):
        return x * y % self.mod

    def div_mod(self, x, y):
        return x * self.mod_inv(y) % self.mod

    class Fenvik:
        def __init__(self, n):
            self.sum = [0] * n

        def add(self, x, d):
            for i in range(x, len(self.sum)):
                self.sum[i] += d

        def sum_range(self, r):
            ans = 0
            for i in range(r, -1, -1):
                ans += self.sum[i]
            return ans

        def sum_range_l_r(self, l, r):
            if l > r:
                return 0
            return self.sum_range(r) - self.sum_range(l - 1)

    class SegmentTreeAdd:
        def __init__(self, a):
            self.pow = 1
            while self.pow < len(a):
                self.pow *= 2
            self.max = [float('-inf')] * (2 * self.pow)
            for i in range(len(a)):
                self.max[self.pow + i] = a[i]
            for i in range(self.pow - 1, 0, -1):
                self.max[i] = max(self.max[2 * i], self.max[2 * i + 1])

        def get(self, v, tl, tr, l, r):
            if l > r:
                return float('-inf')
            if l == tl and r == tr:
                return self.max[v]
            tm = (tl + tr) // 2
            return max(self.get(2 * v, tl, tm, l, min(r, tm)), self.get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r))

        def set(self, v, tl, tr, l, r, x):
            if l > tr or r < tl:
                return
            if l <= tl and r >= tr:
                self.max[v] += x
                return
            tm = (tl + tr) // 2
            self.set(2 * v, tl, tm, l, r, x)
            self.set(2 * v + 1, tm + 1, tr, l, r, x)
            self.max[v] = max(self.max[2 * v], self.max[2 * v + 1])

    class Circle:
        def __init__(self, x, y, r):
            self.x = x
            self.y = y
            self.r = r

        def __lt__(self, other):
            if self.r != other.r:
                return self.r < other.r
            if self.x != other.x:
                return self.x < other.x
            return self.y < other.y

    class Point:
        def __init__(self, angle, type):
            self.angle = angle
            self.type = type

        def __lt__(self, other):
            if self.angle != other.angle:
                return self.angle < other.angle
            return self.type < other.type

    def inside(self, small, big):
        return (small.x - big.x) ** 2 + (small.y - big.y) ** 2 <= (big.r - small.r) ** 2

    def tangent(self, c1, c2):
        a = c1
        b = c2
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

    def merge_sort(self, s, a, l, r):
        if r - l <= 1:
            return True
        m = (l + r) // 2
        if not self.merge_sort(s, a, l, m):
            return False
        if not self.merge_sort(s, a, m, r):
            return False
        i = l
        j = m
        k = l
        b = [0] * (r - l)
        x = 0
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
            x += 1
        while i < m:
            b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            b[k] = a[j]
            j += 1
            k += 1
        for p in range(l, r):
            a[p] = b[p - l]
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
            x = 0
            if not self.merge_sort(s, a, 0, sz):
                r = sz
                continue
            if x < len(s):
                l = sz
                continue
            a = self.rev(a)
            print(sz)
            print(' '.join(str(i + 1) for i in a))
            return

    def run(self):
        self.solve()

if __name__ == "__main__":
    F().run()
