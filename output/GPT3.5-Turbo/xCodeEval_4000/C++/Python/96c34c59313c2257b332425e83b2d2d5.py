class Fraction:
    def __init__(self, c, d):
        hoge = gcd(abs(c), abs(d))
        c //= hoge
        d //= hoge
        if d < 0:
            d *= -1
            c *= -1
        self.a = c
        self.b = d

    def __lt__(self, rhs):
        return self.a * rhs.b < rhs.a * self.b

def solve():
    n, w = map(int, input().split())
    FI = []
    for _ in range(n):
        a, b = map(int, input().split())
        Left = Fraction(-a, b - w)
        Right = Fraction(-a, b + w)
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

solve()
