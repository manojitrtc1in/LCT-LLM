import math
from typing import List, Tuple

DB = float
PI = math.acos(-1)
INF = 1e10
EPS = 1e-8

def sqr(v: DB) -> DB:
    return v * v

def sgn(v: DB) -> int:
    if v < -EPS:
        return -1
    return 1 if v > EPS else 0

class PT:
    def __init__(self, x: DB = 0, y: DB = 0):
        self.x = x
        self.y = y

    def __add__(self, o: 'PT') -> 'PT':
        return PT(self.x + o.x, self.y + o.y)

    def __sub__(self, o: 'PT') -> 'PT':
        return PT(self.x - o.x, self.y - o.y)

    def __neg__(self) -> 'PT':
        return PT(-self.x, -self.y)

    def __mul__(self, c: DB) -> 'PT':
        return PT(self.x * c, self.y * c)

    def __truediv__(self, c: DB) -> 'PT':
        return PT(self.x / c, self.y / c)

    def __lt__(self, o: 'PT') -> bool:
        return sgn(self.x - o.x) < 0 if sgn(self.x - o.x) != 0 else sgn(self.y - o.y) < 0

    def __eq__(self, o: 'PT') -> bool:
        return sgn(self.x - o.x) == 0 and sgn(self.y - o.y) == 0

    def __ne__(self, o: 'PT') -> bool:
        return sgn(self.x - o.x) != 0 or sgn(self.y - o.y) != 0

def dis(v: PT) -> DB:
    return math.sqrt(sqr(v.x) + sqr(v.y))

def dis2(v: PT) -> DB:
    return sqr(v.x) + sqr(v.y)

def vect(v1: PT, v2: PT) -> DB:
    return v1.x * v2.y - v2.x * v1.y

def scal(v1: PT, v2: PT) -> DB:
    return v1.x * v2.x + v1.y * v2.y

def sect(p: PT) -> int:
    if sgn(p.x) == 0 and sgn(p.y) == 0:
        return 0
    if sgn(p.x) == 0:
        return 2 if sgn(p.y) > 0 else 4
    if sgn(p.y) == 0:
        return 1 if sgn(p.x) > 0 else 3
    return 1 if sgn(p.x) == 1 and sgn(p.y) == 1 else 4 if sgn(p.x) == 1 else 2 if sgn(p.y) == 1 else 3

def ang(v: PT) -> DB:
    return math.atan2(v.y, v.x)

def ang2(p: PT, p1: PT, p2: PT) -> DB:
    return math.acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2))

def proj(p: PT, p1: PT, p2: PT) -> PT:
    return p1 + (p2 - p1) * scal(p1, p, p2) / dis2(p1, p2)

def normalLine(p1: PT, p2: PT) -> PT:
    return PT(-(p2.y - p1.y), p2.x - p1.x)

def gravityCenter(p: List[PT], n: int) -> PT:
    o = PT()
    for i in range(n):
        o += p[i]
    return o / n

def main():
    n = int(input())
    p = [PT() for _ in range(n)]
    for i in range(n):
        x, y = map(float, input().split())
        p[i] = PT(x, y)

    g = gravityCenter(p, n)
    for i in range(n):
        p[i] -= g

    p.sort()
    q = PT()
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

    v = sorted(set(v))
    ans = 0
    for i in range(len(v)):
        d = [scal(v[i], proj(p[j], PT(), v[i])) / dis(v[i]) for j in range(n)]
        d.sort()
        flg = True
        for j in range(n // 2):
            if sgn(d[j] + d[n - 1 - j]):
                flg = False
        ans += flg

    print(ans)

if __name__ == "__main__":
    main()
