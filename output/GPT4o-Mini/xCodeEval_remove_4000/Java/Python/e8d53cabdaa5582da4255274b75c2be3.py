import sys
import math
from collections import defaultdict

mod = 1000000007

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
        while y:
            x, y = y, x % y
        return x

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

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

class Line:
    def __init__(self, k, b):
        self.k = k
        self.b = b

    def value(self, x):
        return self.k * x + self.b

class SegmentTree:
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
        return a if self.branch_up ^ (a < b) else b

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

    def add_line(self, line):
        self.add(1, 0, self.pow, line)

    def get_value(self, x):
        return self.get(1, 0, self.pow, x)

class FastScanner:
    def __init__(self, f):
        self.br = f
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

def merge_sort(s, a, l, r):
    if r - l <= 1:
        return True
    m = (l + r) // 2
    if not merge_sort(s, a, l, m):
        return False
    if not merge_sort(s, a, m, r):
        return False
    i, j, k = l, m, l
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
    s = input()
    for sz in range(1, sys.maxsize):
        a = list(range(sz))
        global x, b
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

def main():
    global input
    input = sys.stdin.read
    solve()

if __name__ == "__main__":
    main()
