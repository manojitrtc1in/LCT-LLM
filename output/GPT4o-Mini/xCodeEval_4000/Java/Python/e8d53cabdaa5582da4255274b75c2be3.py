import sys
import math
from collections import defaultdict

mod = 1000000007

class Fraction:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.norm()

    def norm(self):
        gcd = self.gcd(self.x, self.y)
        self.x //= gcd
        self.y //= gcd

    @staticmethod
    def gcd(x, y):
        while y:
            x, y = y, x % y
        return x

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
        unique_primes = list(set(div))
        ans = []
        for prime in unique_primes:
            ans.append(prime)
        return ans

class Fenvik:
    def __init__(self, n):
        self.sum = [0] * n

    def add(self, x, d):
        for i in range(x, len(self.sum)):
            self.sum[i] += d

    def sum_range(self, r):
        ans = 0
        for i in range(r, -1, (i & (i + 1)) - 1):
            ans += self.sum[i]
        return ans

    def sum(self, l, r):
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

    def add(self, line):
        self._add(1, 0, self.pow, line)

    def _add(self, v, l, r, line):
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
            self._add(2 * v, l, m, line)
        if self.better(line.value(r), self.ch[v].value(r)):
            self._add(2 * v + 1, m, r, line)

    def better(self, a, b):
        return self.branch_up ^ (a < b)

    def get(self, x):
        return self._get(1, 0, self.pow, x)

    def _get(self, v, l, r, x):
        if self.ch[v] is None:
            return self.neutral
        if v >= self.pow:
            return self.ch[v].value(x)
        ans = self.ch[v].value(x)
        m = (l + r) // 2
        if x <= m:
            ans = max(ans, self._get(2 * v, l, m, x))
        if x >= m:
            ans = max(ans, self._get(2 * v + 1, m, r, x))
        return ans

def merge_sort(s, a, l, r):
    if r - l <= 1:
        return True
    m = (l + r) // 2
    if not merge_sort(s, a, l, m):
        return False
    if not merge_sort(s, a, m, r):
        return False
    i, j, k = l, m, l
    global x, b
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

def rev(a):
    res = [0] * len(a)
    for i in range(len(a)):
        res[a[i]] = i
    return res

def solve():
    global x, b
    s = input().strip()
    for sz in range(1, 10**6):  # Arbitrary large limit
        a = list(range(sz))
        x = 0
        b = [0] * sz
        if not merge_sort(s, a, 0, sz):
            continue
        if x < len(s):
            continue
        a = rev(a)
        print(sz)
        print(' '.join(str(i + 1) for i in a))
        return

if __name__ == "__main__":
    solve()
