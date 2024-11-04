import sys
from typing import List, Tuple

class Fraction:
    def __init__(self, a: int, b: int):
        self.a = a
        self.b = b

    def __lt__(self, rhs: 'Fraction') -> bool:
        return self.a * rhs.b < rhs.a * self.b

def solve(n: int, w: int, arr: List[Tuple[int, int]]) -> int:
    FI = []
    for a, b in arr:
        Left = Fraction(-a, b - w)
        Right = Fraction(-a, b + w)
        hoge = gcd(abs(Left.a), abs(Left.b))
        Left.a //= hoge
        Left.b //= hoge
        hoge = gcd(abs(Right.a), abs(Right.b))
        Right.a //= hoge
        Right.b //= hoge
        if Left.b < 0:
            Left.a *= -1
            Left.b *= -1
        if Right.b < 0:
            Right.a *= -1
            Right.b *= -1
        Right.a *= -1
        FI.append((Left, Right))
    FI.sort()
    ans = 0
    zip = Compressor()
    for i in range(len(FI)):
        FI[i][1].a *= -1
        zip.add(FI[i][1])
    seg = SegmentTree(2 * n)
    zip.exec()
    for i in range(len(FI)):
        hoge = zip.fetch()
        ans += seg.query(hoge, 2 * n)
        tmp = seg[hoge]
        seg.update(hoge, tmp + 1)
    return ans

def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return gcd(b, a % b)

class Compressor:
    def __init__(self):
        self.is_zipped = False
        self.zipper = {}
        self.unzipper = {}
        self.fetcher = []

    def add(self, now):
        assert self.is_zipped == False
        self.zipper[now] = 1
        self.fetcher.append(now)

    def exec(self):
        assert self.is_zipped == False
        cnt = 0
        for key in self.zipper:
            self.zipper[key] = cnt
            self.unzipper[cnt] = key
            cnt += 1
        self.is_zipped = True

    def fetch(self):
        assert self.is_zipped == True
        hoge = self.fetcher[0]
        self.fetcher.pop(0)
        return self.zipper[hoge]

    def zip(self, now):
        assert self.is_zipped == True
        assert now in self.zipper
        return self.zipper[now]

    def unzip(self, a):
        assert self.is_zipped == True
        assert a < len(self.unzipper)
        return self.unzipper[a]

    def next(self, now):
        x = self.zipper.upper_bound(now)
        if x == self.zipper.end():
            return len(self.zipper)
        return x[1]

    def back(self, now):
        x = self.zipper.lower_bound(now)
        if x == self.zipper.begin():
            return -1
        x -= 1
        return x[1]

class SegmentTree:
    def __init__(self, n):
        self.sz = 1
        while self.sz < n:
            self.sz <<= 1
        self.seg = [0] * (2 * self.sz + 1)

    def set(self, k, x):
        self.seg[k + self.sz] = x

    def build(self):
        for k in range(self.sz - 1, 0, -1):
            self.seg[k] = self.seg[2 * k] + self.seg[2 * k + 1]

    def update(self, k, x):
        k += self.sz
        self.seg[k] = x
        while k >>= 1:
            self.seg[k] = self.seg[2 * k] + self.seg[2 * k + 1]

    def query(self, a, b):
        L = 0
        R = 0
        a += self.sz
        b += self.sz
        while a < b:
            if a & 1:
                L += self.seg[a]
                a += 1
            if b & 1:
                b -= 1
                R += self.seg[b]
            a >>= 1
            b >>= 1
        return L + R

def main() -> None:
    n, w = map(int, input().split())
    arr = []
    for _ in range(n):
        a, b = map(int, input().split())
        arr.append((a, b))
    ans = solve(n, w, arr)
    print(ans)

if __name__ == '__main__':
    main()
