from collections import deque
from fractions import Fraction as F
import sys

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

class Compressor:
    def __init__(self):
        self.is_zipped = False
        self.zipper = {}
        self.unzipper = {}
        self.fetcher = deque()

    def add(self, now):
        assert not self.is_zipped
        self.zipper[now] = 1
        self.fetcher.append(now)

    def exec(self):
        assert not self.is_zipped
        cnt = 0
        for key in sorted(self.zipper.keys()):
            self.zipper[key] = cnt
            self.unzipper[cnt] = key
            cnt += 1
        self.is_zipped = True

    def fetch(self):
        assert self.is_zipped
        hoge = self.fetcher.popleft()
        return self.zipper[hoge]

    def zip(self, now):
        assert self.is_zipped
        assert now in self.zipper
        return self.zipper[now]

    def unzip(self, a):
        assert self.is_zipped
        assert a < len(self.unzipper)
        return self.unzipper[a]

    def next(self, now):
        x = next((k for k in sorted(self.zipper.keys()) if k > now), None)
        if x is None:
            return len(self.zipper)
        return self.zipper[x]

    def back(self, now):
        x = next((k for k in sorted(self.zipper.keys()) if k >= now), None)
        if x is None:
            return -1
        return self.zipper[x] - 1

class SegmentTree:
    def __init__(self, n, f, M1):
        self.sz = 1
        while self.sz < n:
            self.sz <<= 1
        self.seg = [M1] * (2 * self.sz)
        self.f = f
        self.M1 = M1

    def set(self, k, x):
        self.seg[k + self.sz] = x

    def build(self):
        for k in range(self.sz - 1, 0, -1):
            self.seg[k] = self.f(self.seg[2 * k], self.seg[2 * k + 1])

    def update(self, k, x):
        k += self.sz
        self.seg[k] = x
        while k > 1:
            k //= 2
            self.seg[k] = self.f(self.seg[2 * k], self.seg[2 * k + 1])

    def query(self, a, b):
        L, R = self.M1, self.M1
        a += self.sz
        b += self.sz
        while a < b:
            if a & 1:
                L = self.f(L, self.seg[a])
                a += 1
            if b & 1:
                b -= 1
                R = self.f(self.seg[b], R)
            a //= 2
            b //= 2
        return self.f(L, R)

def solve():
    n, w = map(int, sys.stdin.readline().split())
    FI = []
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        Left = F(-a, b - w)
        Right = F(-a, b + w)
        Right = F(-Right.numerator, Right.denominator)
        FI.append((Left, Right))

    FI.sort()
    ans = 0
    zip = Compressor()
    for left, right in FI:
        right = F(-right.numerator, right.denominator)
        zip.add(right)

    seg = SegmentTree(2 * n, lambda a, b: a + b, 0)
    zip.exec()
    for left, right in FI:
        hoge = zip.fetch()
        ans += seg.query(hoge, 2 * n)
        tmp = seg[hoge]
        seg.update(hoge, tmp + 1)

    print(ans)

if __name__ == "__main__":
    sys.stdin = open(0)
    solve()
