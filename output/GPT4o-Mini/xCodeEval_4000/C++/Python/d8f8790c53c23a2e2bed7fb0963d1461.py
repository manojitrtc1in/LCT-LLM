from collections import deque
from fractions import Fraction
import sys
import itertools

eps = 1e-12
MAX_MOD = 1000000007
GYAKU = 500000004
MOD = 998244353

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

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

def solve():
    n, w = map(int, sys.stdin.readline().split())
    FI = []
    
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        Left = Fraction(-a, b - w)
        Right = Fraction(-a, b + w)

        if Left.denominator < 0:
            Left = Fraction(-Left.numerator, -Left.denominator)
        if Right.denominator < 0:
            Right = Fraction(-Right.numerator, -Right.denominator)

        Right = Fraction(-Right.numerator, Right.denominator)
        FI.append((Left, Right))

    FI.sort()
    ans = 0
    zip = Compressor()

    for left, right in FI:
        right = Fraction(-right.numerator, right.denominator)
        zip.add(right)

    seg = [0] * (2 * n)

    zip.exec()

    for left, right in FI:
        hoge = zip.fetch()
        ans += sum(seg[hoge:2 * n])
        seg[hoge] += 1

    print(ans)

if __name__ == "__main__":
    sys.stdin = open(0)  # For reading input
    solve()
