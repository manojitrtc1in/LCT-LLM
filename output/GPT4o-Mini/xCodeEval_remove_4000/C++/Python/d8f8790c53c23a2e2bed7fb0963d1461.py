from collections import deque
from itertools import combinations
from fractions import Fraction as F
import sys
import math

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

class Compressor:
    def __init__(self):
        self.id6 = False
        self.zipper = {}
        self.unzipper = {}
        self.fetcher = deque()

    def add(self, now):
        assert not self.id6
        self.zipper[now] = 1
        self.fetcher.append(now)

    def exec(self):
        assert not self.id6
        cnt = 0
        for key in sorted(self.zipper.keys()):
            self.zipper[key] = cnt
            self.unzipper[cnt] = key
            cnt += 1
        self.id6 = True

    def fetch(self):
        assert self.id6
        hoge = self.fetcher.popleft()
        return self.zipper[hoge]

    def zip(self, now):
        assert self.id6
        assert now in self.zipper
        return self.zipper[now]

    def unzip(self, a):
        assert self.id6
        assert a < len(self.unzipper)
        return self.unzipper[a]

    def next(self, now):
        x = next((k for k in sorted(self.zipper.keys()) if k > now), None)
        if x is None:
            return len(self.zipper)
        return self.zipper[x]

    def back(self, now):
        x = next((k for k in sorted(self.zipper.keys()) if k < now), None)
        if x is None:
            return -1
        return self.zipper[x]

def init():
    sys.stdin = open(0)
    sys.stdout = open(1, 'w', buffering=1)
    print(f"{0:.200f}")

def solve():
    n, w = map(int, input().split())
    FI = []
    for _ in range(n):
        a, b = map(int, input().split())
        Left = F(-a, b - w)
        Right = F(-a, b + w)

        Left = (Left.numerator, Left.denominator)
        Right = (Right.numerator, Right.denominator)

        if Left[1] < 0:
            Left = (-Left[0], -Left[1])
        if Right[1] < 0:
            Right = (-Right[0], -Right[1])

        Right = (-Right[0], Right[1])
        FI.append((Left, Right))

    FI.sort()
    ans = 0
    zip = Compressor()
    for left, right in FI:
        right = (-right[0], right[1])
        zip.add(right)

    seg = [0] * (2 * n)
    zip.exec()
    
    for left, right in FI:
        hoge = zip.fetch()
        ans += sum(seg[hoge:2 * n])
        seg[hoge] += 1

    print(ans)

if __name__ == "__main__":
    init()
    solve()
