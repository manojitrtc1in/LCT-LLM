class Fraction:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, rhs):
        return self.a * rhs.b < rhs.a * self.b

def solve():
    n, w = map(int, input().split())
    FI = []
    for _ in range(n):
        a, b = map(int, input().split())
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
    print(ans)

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

class Compressor:
    def __init__(self):
        self.id6 = False
        self.zipper = {}
        self.unzipper = {}
        self.fetcher = []

    def add(self, now):
        assert self.id6 == False
        self.zipper[now] = 1
        self.fetcher.append(now)

    def exec(self):
        assert self.id6 == False
        cnt = 0
        for key in self.zipper:
            self.zipper[key] = cnt
            self.unzipper[cnt] = key
            cnt += 1
        self.id6 = True

    def fetch(self):
        assert self.id6 == True
        hoge = self.fetcher[0]
        self.fetcher.pop(0)
        return self.zipper[hoge]

    def zip(self, now):
        assert self.id6 == True
        assert now in self.zipper
        return self.zipper[now]

    def unzip(self, a):
        assert self.id6 == True
        assert a < len(self.unzipper)
        return self.unzipper[a]

    def next(self, now):
        x = self.zipper.upper_bound(now)
        if x == self.zipper.end():
            return len(self.zipper)
        return x.second

    def back(self, now):
        x = self.zipper.lower_bound(now)
        if x == self.zipper.begin():
            return -1
        x -= 1
        return x.second

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

solve()
