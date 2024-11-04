import sys
import math
from collections import defaultdict

mod = 1000000007

class Fraction:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.norm()

    def gcd(self, x, y):
        while y:
            x, y = y, x % y
        return x

    def norm(self):
        g = self.gcd(self.x, self.y)
        self.x //= g
        self.y //= g

    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

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
        lst = self.factorization(x)
        ans = f"{x} = "
        ans += " * ".join(map(str, lst))
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
        inx = self.in(x1=self.x1, x2=self.x2, x=x)
        iny = self.in(y1=self.y1, y2=self.y2, y=y)
        return inx * iny

    def additional(self, r):
        if self.equals(r):
            return 0
        if self.inside(r.x1, r.y1) == 4 or self.inside(r.x2, r.y2) == 4 or self.inside(r.x1, r.y2) == 4 or self.inside(r.x2, r.y1) == 4:
            return 1
        if self.inside(r.x1, r.y1) == 1 or self.inside(r.x2, r.y2) == 1:
            return 1
        return 2

    def in(self, min, max, x):
        if x == min or x == max:
            return 1
        if min < x < max:
            return 2
        return 0

class Fenvik:
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

    def sum_range(self, l, r):
        if l > r:
            return 0
        return self.sum(r) - self.sum(l - 1)

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

class Line:
    def __init__(self, k, b):
        self.k = k
        self.b = b

    def value(self, x):
        return self.k * x + self.b

class LiChaoTree:
    def __init__(self, n, branch_up):
        self.branch_up = branch_up
        self.neutral = float('-inf') if branch_up else float('inf')
        self.pow = 1
        while self.pow < n:
            self.pow *= 2
        self.ch = [None] * (2 * self.pow)

    def better(self, a, b):
        return self.branch_up ^ (a < b)

    def function(self, a, b):
        return a if self.better(a, b) else b

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
            line, self.ch[v] = self.ch[v], line
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

class F:
    def __init__(self):
        self.in_ = sys.stdin
        self.out = sys.stdout

    def pow(self, x, p):
        if p <= 0:
            return 1
        ans = self.pow(x, p // 2)
        ans = (ans * ans) % mod
        if p % 2 == 1:
            ans = (ans * x) % mod
        return ans

    def mod_inv(self, x):
        return self.pow(x, mod - 2)

    def merge_sort(self, s, a, l, r):
        if r - l <= 1:
            return True
        m = (l + r) // 2
        if not self.merge_sort(s, a, l, m):
            return False
        if not self.merge_sort(s, a, m, r):
            return False
        i, j, k = l, m, l
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
            self.x += 1
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
        s = self.in_.readline().strip()
        l, r = 0, 100001
        while True:
            sz = (l + r) // 2
            a = list(range(sz))
            self.x = 0
            self.b = [0] * sz
            if not self.merge_sort(s, a, 0, sz):
                r = sz
                continue
            if self.x < len(s):
                l = sz
                continue
            a = self.rev(a)
            self.out.write(f"{sz}\n")
            self.out.write(" ".join(str(x + 1) for x in a) + "\n")
            return

    def run(self):
        self.solve()

if __name__ == "__main__":
    F().run()
