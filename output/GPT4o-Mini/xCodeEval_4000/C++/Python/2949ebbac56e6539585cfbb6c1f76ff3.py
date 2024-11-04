import math
from functools import cmp_to_key

INF = 1e10
EPS = 1e-8

def sqr(v):
    return v * v

def sgn(v):
    if v < -EPS:
        return -1
    elif v > EPS:
        return 1
    return 0

class PT:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __add__(self, o):
        return PT(self.x + o.x, self.y + o.y)

    def __sub__(self, o):
        return PT(self.x - o.x, self.y - o.y)

    def __neg__(self):
        return PT(-self.x, -self.y)

    def __mul__(self, c):
        return PT(self.x * c, self.y * c)

    def __truediv__(self, c):
        return PT(self.x / c, self.y / c)

    def __lt__(self, o):
        return sgn(self.x - o.x) < 0 if sgn(self.x - o.x) else sgn(self.y - o.y) < 0

    def __eq__(self, o):
        return not sgn(self.x - o.x) and not sgn(self.y - o.y)

    def __ne__(self, o):
        return sgn(self.x - o.x) or sgn(self.y - o.y)

def dis(v):
    return math.sqrt(sqr(v.x) + sqr(v.y))

def dis2(v):
    return sqr(v.x) + sqr(v.y)

def vect(v1, v2):
    return v1.x * v2.y - v2.x * v1.y

def scal(v1, v2):
    return v1.x * v2.x + v1.y * v2.y

def sect(p):
    if sgn(p.x) == 0 and sgn(p.y) == 0:
        return 0
    if sgn(p.x) == 0:
        return 2 if sgn(p.y) > 0 else 4
    if sgn(p.y) == 0:
        return 1 if sgn(p.x) > 0 else 3
    if sgn(p.x) == 1:
        return 1 if sgn(p.y) == 1 else 4
    return 2 if sgn(p.y) == 1 else 3

def ang(v):
    return math.atan2(v.y, v.x)

def proj(p, p1, p2):
    return p1 + (p2 - p1) * scal(p1, p, p2) / dis2(p1, p2)

def normalLine(p1, p2):
    return PT(-(p2.y - p1.y), p2.x - p1.x)

def gravityCenter(p, n):
    o = PT()
    for i in range(n):
        o += p[i]
    return o / n

def main():
    n = int(input())
    p = [PT(*map(float, input().split())) for _ in range(n)]
    g = gravityCenter(p, n)
    for i in range(n):
        p[i] -= g
    p.sort()

    q = None
    for i in range(n):
        fp = next((j for j in range(n) if p[j] == -p[i]), None)
        if fp is None:
            q = p[i]
            break
        if i == n - 1:
            print("-1")
            return

    v = []
    for i in range(n):
        m = (p[i] + q) / 2
        nv = normalLine(PT(), m)
        if sect(nv) >= 3:
            nv = -nv
        v.append(nv)

    v = sorted(set(v), key=cmp_to_key(lambda a, b: sgn(vect(a, b))))

    ans = 0
    d = [0] * n
    for vi in v:
        for j in range(n):
            d[j] = scal(vi, proj(p[j], PT(), vi)) / dis(vi)
        d.sort()
        flg = all(sgn(d[j] + d[n - 1 - j]) == 0 for j in range(n // 2))
        ans += flg

    print(ans)

if __name__ == "__main__":
    main()
