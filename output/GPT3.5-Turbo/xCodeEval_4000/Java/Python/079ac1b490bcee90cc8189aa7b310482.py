import sys
from typing import List
from math import gcd
from collections import deque

class F:
    def __init__(self):
        self.systemIO = True
        self.mod = 1000000007
        self.in = self.FastScanner(sys.stdin) if self.systemIO else self.FastScanner(open("input.txt"))
        self.out = sys.stdout if self.systemIO else open("output.txt", "w")
    
    def pow(self, x: int, p: int, mod: int) -> int:
        if p <= 0:
            return 1
        th = self.pow(x, p // 2, mod)
        th *= th
        th %= mod
        if p % 2 == 1:
            th *= x
        return th % mod
    
    class Fraction:
        def __init__(self, x: int, y: int):
            self.x = x
            self.y = y
        
        def norm(self):
            gcd_val = gcd(self.x, self.y)
            self.x //= gcd_val
            self.y //= gcd_val
        
        def __lt__(self, other):
            if self.x > other.x:
                return 1
            if self.x < other.x:
                return -1
            if self.y > other.y:
                return 1
            if self.y < other.y:
                return -1
            return 0
    
    def sum(self, a: Fraction, b: Fraction) -> Fraction:
        c = self.Fraction(a.x * b.y + a.y * b.x, a.y * b.y)
        c.norm()
        return c
    
    def gcd(self, x: int, y: int) -> int:
        if y == 0:
            return x
        if x == 0:
            return y
        return self.gcd(y, x % y)
    
    class Pair:
        def __init__(self, x: int, y: int):
            self.x = x
            self.y = y
        
        def clone(self):
            return self.Pair(self.x, self.y)
        
        def __lt__(self, other):
            if self.x > other.x:
                return 1
            if self.x < other.x:
                return -1
            if self.y > other.y:
                return 1
            if self.y < other.y:
                return -1
            return 0
    
    def mult1(self, a: List[int], b: List[int]) -> List[int]:
        n = len(a)
        c = [0] * n
        for i in range(n):
            for k in range(n):
                c[i] += a[i ^ k] * b[k]
                c[i] %= self.mod
        return c
    
    def mult(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        n = len(a)
        c = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    c[i][j] += a[i][k] * b[k][j]
                    c[i][j] %= self.mod
        return c
    
    def pow(self, x: List[List[int]], p: int) -> List[List[int]]:
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
    
    def mult(self, a: List[int], b: List[int]) -> List[int]:
        n = len(a)
        c = [0] * n
        for i in range(n):
            for k in range(n):
                c[i] += a[k] * b[k ^ i]
                c[i] %= self.mod
        return c
    
    def pow(self, x: List[int], p: int) -> List[int]:
        if p == 0:
            e = [0] * len(x)
            e[0] = 1
            return e
        ans = self.pow(x, p // 2)
        ans = self.mult(ans, ans)
        if p % 2 == 1:
            ans = self.mult(ans, x)
        return ans
    
    def pow(self, x: int, p: int) -> int:
        if p <= 0:
            return 1
        ans = self.pow(x, p // 2)
        ans = (ans * ans) % self.mod
        if p % 2 == 1:
            ans = (ans * x) % self.mod
        return ans
    
    def modInv(self, x: int) -> int:
        return self.pow(x, self.mod - 2)
    
    class Factorizator:
        def __init__(self, max_val: int):
            self.div = [0] * (max_val + 1)
            self.primes = []
            for i in range(2, len(self.div)):
                if self.div[i] == 0:
                    self.div[i] = i
                    self.primes.append(i)
                for j in self.primes:
                    if i * j > max_val:
                        break
                    self.div[i * j] = j
        
        def factorization(self, x: int) -> List[int]:
            ans = []
            while self.div[x] > 0:
                ans.append(self.div[x])
                x //= self.div[x]
            return ans
        
        def all_divisors(self, x: int) -> List[int]:
            div = self.factorization(x)
            length = len(div)
            s = set()
            for mask in range(1 << length):
                th = 1
                for i in range(length):
                    if (mask & (1 << i)) > 0:
                        th *= div[i]
                s.add(th)
            ans = list(s)
            ans.sort()
            return ans
        
        def divisors(self, x: int) -> List[int]:
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
            s = set()
            while True:
                z = 1
                for i in range(pr):
                    z *= pow[i][th[i]]
                s.add(z)
                for i in range(pr - 1, -1, -1):
                    if th[i] != sz[i]:
                        th[i] += 1
                        for j in range(i + 1, pr):
                            th[j] = 0
                        break
                else:
                    break
            ans = list(s)
            ans.sort()
            return ans
        
        def factorizationToString(self, x: int) -> str:
            if x == 1:
                return "1 = 1"
            div = self.factorization(x)
            ans = f"{x} = "
            for i in range(len(div)):
                ans += str(div[i])
                if i < len(div) - 1:
                    ans += " * "
            return ans
    
    class Rect:
        def __init__(self, x1: int, y1: int, x2: int, y2: int):
            self.x1 = x1
            self.y1 = y1
            self.x2 = x2
            self.y2 = y2
        
        def __str__(self):
            return f"{self.x1} {self.y1} {self.x2} {self.y2}"
        
        def equals(self, r):
            return self.x1 == r.x1 and self.y1 == r.y1 and self.x2 == r.x2 and self.y2 == r.y2
        
        def inside(self, x: int, y: int) -> int:
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
        
    def in_(self, min_val: int, max_val: int, x: int) -> int:
        if x == min_val or x == max_val:
            return 1
        if min_val < x < max_val:
            return 2
        return 0
    
    def sum(self, x: int, y: int) -> int:
        if x + y >= self.mod:
            return x + y - self.mod
        return x + y
    
    def mult(self, x: int, y: int) -> int:
        return x * y % self.mod
    
    def div(self, x: int, y: int) -> int:
        return x * self.modInv(y) % self.mod
    
    class Fenvik:
        def __init__(self, n: int):
            self.sum = [0] * n
        
        def add(self, x: int, d: int):
            i = x
            while i < len(self.sum):
                self.sum[i] += d
                i |= i + 1
        
        def sum_(self, r: int) -> int:
            ans = 0
            i = r
            while i >= 0:
                ans += self.sum[i]
                i = (i & (i + 1)) - 1
            return ans
        
        def sum_(self, l: int, r: int) -> int:
            if l > r:
                return 0
            return self.sum_(r) - self.sum_(l - 1)
    
    class SegmentTreeAdd:
        def __init__(self, a: List[int]):
            self.pow = 1
            while self.pow < len(a):
                self.pow *= 2
            self.flag = [False] * (2 * self.pow)
            self.max = [float('-inf')] * (2 * self.pow)
            self.delta = [0] * (2 * self.pow)
            for i in range(len(self.max)):
                self.max[i] = float('-inf') / 2 if i < self.pow else 0
            for i in range(len(a)):
                self.max[self.pow + i] = a[i]
            for i in range(self.pow - 1, 0, -1):
                self.max[i] = self.f(self.max[2 * i], self.max[2 * i + 1])
        
        def f(self, a: int, b: int) -> int:
            return max(a, b)
        
        def add(self, v: int, tl: int, tr: int, l: int, r: int, x: int):
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
        
        def push(self, v: int, tl: int, tr: int):
            if self.flag[v]:
                if v < self.pow:
                    self.flag[2 * v] = True
                    self.flag[2 * v + 1] = True
                    self.delta[2 * v] += self.delta[v]
                    self.delta[2 * v + 1] += self.delta[v]
                self.flag[v] = False
                self.max[v] += self.delta[v]
                self.delta[v] = 0
        
        def get(self, v: int, tl: int, tr: int, x: int) -> int:
            self.push(v, tl, tr)
            if self.max[v] == float('-inf'):
                return 0
            if v >= self.pow:
                return self.max[v]
            ans = self.max[v]
            m = (tl + tr) // 2
            if x <= m:
                ans = self.f(ans, self.get(2 * v, tl, m, x))
            if x >= m:
                ans = self.f(ans, self.get(2 * v + 1, m + 1, tr, x))
            return ans
    
    class Circle:
        def __init__(self, x: int, y: int, r: int):
            self.x = x
            self.y = y
            self.r = r
        
        def clone(self):
            return self.Circle(self.x, self.y, self.r)
        
        def __lt__(self, other):
            if self.r != other.r:
                return self.r - other.r
            if self.x != other.x:
                return self.x - other.x
            return self.y - other.y
    
    class Point:
        def __init__(self, angle: float, type: int):
            self.angle = angle
            self.type = type
        
        def __lt__(self, other):
            if self.angle > other.angle:
                return 1
            if self.angle < other.angle:
                return -1
            return self.type - other.type
    
    def inside(self, small: Circle, big: Circle) -> bool:
        return (small.x - big.x) * (small.x - big.x) + (small.y - big.y) * (small.y - big.y) <= (big.r - small.r) * (big.r - small.r)
    
    def tangent(self, c1: Circle, c2: Circle) -> List[float]:
        a = c1.clone()
        b = c2.clone()
        minr = min(a.r, b.r)
        a.r -= minr
        b.r -= minr
        b.x -= a.x
        b.y -= a.y
        a0 = atan2(b.y, b.x)
        length = sqrt(b.x * b.x + b.y * b.y)
        da = 0
        if a.r == 0:
            da = asin(b.r / length) + pi / 2
        else:
            da = acos(a.r / length)
        ans = [a0 - da, a0 + da]
        return ans
    
    def norm(self, ans: List[float]) -> List[float]:
        for i in range(len(ans)):
            while ans[i] < 0:
                ans[i] += 2 * pi
            while ans[i] > 2 * pi:
                ans[i] -= 2 * pi
        if ans[0] > ans[1]:
            return [0, ans[1], ans[0], 2 * pi]
        return ans
    
    def mergeSort(self, s: str, a: List[int], l: int, r: int) -> bool:
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
    
    def rev(self, a: List[int]) -> List[int]:
        res = [0] * len(a)
        for i in range(len(a)):
            res[a[i]] = i
        return res
    
    def solve(self):
        s = self.in.next()
        l = 0
        r = 100001
        while True:
            sz = (l + r) // 2
            a = [i for i in range(sz)]
            x = 0
            b = [0] * sz
            if not self.mergeSort(s, a, 0, sz):
                r = sz
                continue
            if x < len(s):
                l = sz
                continue
            a = self.rev(a)
            self.out.println(sz)
            for i in range(len(a)):
                self.out.print(a[i] + 1 + " ")
            return
    
    def run(self):
        self.solve()
        self.out.close()
    
    class FastScanner:
        def __init__(self, f):
            self.br = BufferedReader(InputStreamReader(f))
            self.st = None
        
        def nextLine(self):
            try:
                return self.br.readLine()
            except IOException:
                return None
        
        def next(self):
            while self.st is None or not self.st.hasMoreTokens():
                try:
                    self.st = StringTokenizer(self.br.readLine())
                except IOException:
                    return None
            return self.st.nextToken()
        
        def nextInt(self):
            return int(self.next())
        
        def nextLong(self):
            return int(self.next())
        
        def nextDouble(self):
            return float(self.next())
    
    def main(self):
        self.F().run()

if __name__ == "__main__":
    F().main()
