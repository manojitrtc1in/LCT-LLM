import sys
from typing import List
from math import gcd

class F:
    def __init__(self):
        self.systemIO = True

    def pow(self, x: int, p: int, mod: int) -> int:
        if p <= 0:
            return 1
        th = self.pow(x, p // 2, mod)
        th *= th
        th %= mod
        if p % 2 == 1:
            th *= x
        return th

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
                c[i] %= mod
        return c

    def mult(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        n = len(a)
        c = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    c[i][j] += a[i][k] * b[k][j]
                    c[i][j] %= mod
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
                c[i] %= mod
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
        ans = (ans * ans) % mod
        if p % 2 == 1:
            ans = (ans * x) % mod
        return ans

    def modInv(self, x: int) -> int:
        return self.pow(x, mod - 2)

    def mergeSort(self, s: str, a: List[int], l: int, r: int) -> bool:
        if r - l <= 1:
            return True
        m = (l + r) >> 1
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

    def solve(self) -> None:
        s = input().strip()
        l = 0
        r = 100001
        while True:
            sz = (l + r) >> 1
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
            print(sz)
            print(' '.join(str(a[i] + 1) for i in range(len(a))))
            return

    def run(self) -> None:
        self.solve()

if __name__ == '__main__':
    f = F()
    f.run()
