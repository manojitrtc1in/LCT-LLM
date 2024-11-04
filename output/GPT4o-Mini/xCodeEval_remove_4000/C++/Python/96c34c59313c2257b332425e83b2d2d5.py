from collections import deque
from fractions import Fraction as F
import sys

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
        x = next((k for k in sorted(self.zipper.keys()) if k >= now), None)
        if x is None:
            return -1
        return self.zipper[x]

def solve():
    n, w = map(int, input().split())
    FI = []
    for _ in range(n):
        a, b = map(int, input().split())
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

    seg = [0] * (2 * n)
    zip.exec()
    
    for left, right in FI:
        hoge = zip.fetch()
        ans += sum(seg[hoge:2 * n])
        seg[hoge] += 1

    print(ans)

if __name__ == "__main__":
    input = sys.stdin.read
    solve()
