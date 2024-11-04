import math
import sys
from typing import List

EPS = 1e-8

class PT:
    def __init__(self, x: float = 0, y: float = 0):
        self.x = x
        self.y = y
    
    def __add__(self, o):
        return PT(self.x + o.x, self.y + o.y)
    
    def __iadd__(self, o):
        self.x += o.x
        self.y += o.y
        return self
    
    def __sub__(self, o):
        return PT(self.x - o.x, self.y - o.y)
    
    def __isub__(self, o):
        self.x -= o.x
        self.y -= o.y
        return self
    
    def __neg__(self):
        return PT(-self.x, -self.y)
    
    def __mul__(self, c: float):
        return PT(self.x * c, self.y * c)
    
    def __imul__(self, c: float):
        self.x *= c
        self.y *= c
        return self
    
    def __rmul__(self, c: float):
        return self * c
    
    def __truediv__(self, c: float):
        return PT(self.x / c, self.y / c)
    
    def __itruediv__(self, c: float):
        self.x /= c
        self.y /= c
        return self
    
    def __lt__(self, o):
        if math.isclose(self.x, o.x, rel_tol=EPS):
            return self.y < o.y
        return self.x < o.x
    
    def __eq__(self, o):
        return math.isclose(self.x, o.x, rel_tol=EPS) and math.isclose(self.y, o.y, rel_tol=EPS)
    
    def __ne__(self, o):
        return not self == o

def sqr(v: float) -> float:
    return v * v

def sgn(v: float) -> int:
    if v < -EPS:
        return -1
    elif v > EPS:
        return 1
    else:
        return 0

def dis(v: PT) -> float:
    return math.sqrt(sqr(v.x) + sqr(v.y))

def dis2(v: PT) -> float:
    return sqr(v.x) + sqr(v.y)

def dis(p1: PT, p2: PT) -> float:
    return dis(p1 - p2)

def dis2(p1: PT, p2: PT) -> float:
    return dis2(p1 - p2)

def vect(v1: PT, v2: PT) -> float:
    return v1.x * v2.y - v2.x * v1.y

def vect(p: PT, p1: PT, p2: PT) -> float:
    return vect(p1 - p, p2 - p)

def scal(v1: PT, v2: PT) -> float:
    return v1.x * v2.x + v1.y * v2.y

def scal(p: PT, p1: PT, p2: PT) -> float:
    return scal(p1 - p, p2 - p)

def sect(p: PT) -> int:
    if sgn(p.x) == 0 and sgn(p.y) == 0:
        return 0
    if sgn(p.x) == 0:
        return 2 if sgn(p.y) > 0 else 4
    if sgn(p.y) == 0:
        return 1 if sgn(p.x) > 0 else 3
    if sgn(p.x) == 1:
        return 1 if sgn(p.y) == 1 else 4
    return 2 if sgn(p.y) == 1 else 3

def ang(v: PT) -> float:
    return math.atan2(v.y, v.x)

def ang(p1: PT, p2: PT) -> float:
    return ang(p2 - p1)

def ang(p: PT, p1: PT, p2: PT) -> float:
    dy = vect(p, p1, p2)
    dx = scal(p, p1, p2)
    if not sgn(dy):
        dy = 0
    if not sgn(dx):
        dx = 0
    return math.atan2(dy, dx)

def ang2(p: PT, p1: PT, p2: PT) -> float:
    return math.acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2))

def proj(p: PT, p1: PT, p2: PT) -> PT:
    return p1 + (p2 - p1) * scal(p1, p, p2) / dis2(p1, p2)

def rot(v: PT, t: float) -> PT:
    return PT(v.x * math.cos(t) - v.y * math.sin(t), v.x * math.sin(t) + v.y * math.cos(t))

def rot(p: PT, o: PT, t: float) -> PT:
    return rot(p - o, t) + o

def polar(o: PT, r: float, t: float) -> PT:
    return o + r * PT(math.cos(t), math.sin(t))

def id2(p: PT, p1: PT, p2: PT) -> float:
    return abs(vect(p, p1, p2)) / dis(p1, p2)

def id8(p: PT, p1: PT, p2: PT) -> float:
    if sgn(scal(p1, p, p2)) < 0:
        return dis(p, p1)
    if sgn(scal(p2, p, p1)) < 0:
        return dis(p, p2)
    return id2(p, p1, p2)

def onLine(p: PT, p1: PT, p2: PT) -> bool:
    return not sgn(vect(p, p1, p2))

def onSeg(p: PT, p1: PT, p2: PT) -> bool:
    return not onLine(p, p1, p2) and sgn(scal(p, p1, p2)) <= 0

def inAngle(p: PT, p0: PT, p1: PT, p2: PT) -> bool:
    d0 = vect(p0, p1, p2)
    d1 = vect(p0, p1, p)
    d2 = vect(p0, p2, p)
    if sgn(d0) >= 0:
        return sgn(d1) >= 0 and sgn(d2) <= 0
    return sgn(d1) >= 0 or sgn(d2) <= 0

def id12(p: PT, q: List[PT], n: int) -> int:
    o = (q[0] + q[1] + q[2]) / 3
    if o == p:
        return 1
    l, h = 0, n
    while h - l > 1:
        m = (l + h) // 2
        if inAngle(p, o, q[l % n], q[m % n]):
            h = m
        else:
            l = m
    l %= n
    h %= n
    if not sgn(vect(q[l], q[h], p)):
        return 2
    return sgn(vect(q[l], q[h], o) * vect(q[l], q[h], p)) > 0

def id6(p1: PT, p2: PT, p3: PT, p4: PT, p: PT) -> int:
    s1 = vect(p1, p2, p3)
    s2 = vect(p1, p2, p4)
    if not sgn(s1 - s2):
        return 0 if sgn(s1) else 2
    p = p3 - (p4 - p3) * s1 / (s2 - s1)
    return 1

def id0(p1: PT, p2: PT, p3: PT, p4: PT, p: PT) -> int:
    ret = id6(p1, p2, p3, p4, p)
    if ret == 1:
        return onSeg(p, p1, p2) and onSeg(p, p3, p4)
    if ret == 2 and (onSeg(p1, p3, p4) or onSeg(p2, p3, p4)):
        return 2
    return 0

def inPolygon(p: PT, q: List[PT], n: int) -> int:
    c = 0
    r = PT(float('inf'), float('inf'))
    t = PT()
    for i in range(n):
        if onLine(p, q[i], q[(i + 1) % n]):
            return 2
        if id0(p, r, q[i], q[(i + 1) % n], t) == 1:
            c += 1
    return c % 2

def id7(o: PT, r: float, p1: PT, p2: PT, q: List[PT] = None) -> int:
    a = dis2(p1, p2)
    b = scal(p1, o, p2)
    c = dis2(o, p1) - sqr(r)
    d2 = sqr(b) - a * c
    if sgn(d2) < 0:
        return 0
    d = math.sqrt(abs(d2))
    if q is not None:
        q[0] = p1 + (p2 - p1) * (b + d) / a
    if sgn(d2) == 0:
        return 1
    if q is not None:
        q[1] = p1 + (p2 - p1) * (b - d) / a
    return 2

def id3(o1: PT, r1: float, o2: PT, r2: float, q: List[PT] = None) -> int:
    if o1 == o2:
        return 0 if sgn(r1 - r2) else 3
    d = dis(o1, o2)
    e = (sqr(r1) - sqr(r2) + sqr(d)) / (2 * d)
    f2 = sqr(r1) - sqr(e)
    if sgn(f2) < 0:
        return 0
    f = math.sqrt(abs(f2))
    dx = o2.x - o1.x
    dy = o2.y - o1.y
    if q is not None:
        q[0] = PT(o1.x + (e * dx - f * dy) / d, o1.y + (e * dy + f * dx) / d)
    if sgn(f2) == 0:
        return 1
    if q is not None:
        q[1] = PT(o1.x + (e * dx + f * dy) / d, o1.y + (e * dy - f * dx) / d)
    return 2

def normalLine(p1: PT, p2: PT) -> PT:
    return PT(-(p2.y - p1.y), p2.x - p1.x)

def innerCenter(a: PT, b: PT, c: PT) -> PT:
    A = dis(b, c)
    B = dis(c, a)
    C = dis(a, b)
    return PT((A * a.x + B * b.x + C * c.x) / (A + B + C), (A * a.y + B * b.y + C * c.y) / (A + B + C))

def outerCenter(a: PT, b: PT, c: PT) -> PT:
    d1 = (dis2(a) - dis2(b)) / 2
    d2 = (dis2(a) - dis2(c)) / 2
    x = (d1 * (a.y - c.y) - d2 * (a.y - b.y)) / vect(a - b, a - c)
    y = (d1 * (a.x - c.x) - d2 * (a.x - b.x)) / vect(a - c, a - b)
    return PT(x, y)

def gravityCenter(p: List[PT], n: int) -> PT:
    o = PT()
    for i in range(n):
        o += p[i]
    return o / n

def id9(p1: PT, r1: float, p2: PT, r2: float) -> float:
    d = dis(p1 - p2)
    if sgn(d - r1 - r2) >= 0:
        return 0
    p = (r1 + r2 + d) / 2
    s = math.sqrt(p * (p - r1) * (p - r2) * (p - d))
    l = 2 * s / d
    return r1 * r1 * math.asin(l / r1) + r2 * r2 * math.asin(l / r2) - s * 2

def isSimple(p: List[PT], n: int) -> bool:
    for i in range(n):
        for j in range(i + 3, n):
            if 0:
                return False
    return True

def id1(p: List[PT], n: int) -> bool:
    for i in range(n):
        if sgn(vect(p[i], p[(i + 1) % n], p[(i + 2) % n])) <= 0:
            return False
    return True

def id10(p: List[PT], n: int) -> float:
    S = 0
    for i in range(n):
        S += vect(p[i], p[(i + 1) % n])
    return abs(S) / 2

def id5(p: List[PT], n: int, q: List[PT]) -> int:
    p.sort()
    n = len(set(p))
    if n == 1:
        q[0] = p[0]
        return 1
    m = 0
    for i in range(n):
        for m >= 2 and sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0:
            m -= 1
        q[m] = p[i]
        m += 1
    m0 = m
    for i in range(n - 2, -1, -1):
        for m > m0 and sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0:
            m -= 1
        q[m] = p[i]
        m += 1
    return m - 1

class HP:
    def __init__(self, s: PT = PT(), e: PT = PT()):
        self.s = s
        self.e = e
    
    def __lt__(self, o):
        if sect(self.e - self.s) != sect(o.e - o.s):
            return sect(self.e - self.s) < sect(o.e - o.s)
        d = vect(self.s, self.e, o.e - o.s + self.s)
        return sgn(d) > 0
    
    def __eq__(self, o):
        return not sgn(vect(o.s, self.e - self.s + o.s, o.e))

def id4(p: List[HP], n: int) -> int:
    p[n] = HP(PT(-float('inf'), -float('inf')), PT(float('inf'), -float('inf')))
    p[n + 1] = HP(PT(float('inf'), -float('inf')), PT(float('inf'), float('inf')))
    p[n + 2] = HP(PT(float('inf'), float('inf')), PT(-float('inf'), float('inf')))
    p[n + 3] = HP(PT(-float('inf'), float('inf')), PT(-float('inf'), -float('inf')))
    p.sort()
    n = len(set(p))
    l, r = 0, 0
    for i in range(n):
        c = PT()
        while r - l >= 2:
            id6(p[r - 2].s, p[r - 2].e, p[r - 1].s, p[r - 1].e, c)
            if sgn(vect(p[i].s, p[i].e, c)) > 0:
                break
            r -= 1
        while r - l >= 2:
            id6(p[l].s, p[l].e, p[l + 1].s, p[l + 1].e, c)
            if sgn(vect(p[i].s, p[i].e, c)) > 0:
                break
            l += 1
        if r - l < 2:
            p[r] = p[i]
            r += 1
        else:
            id6(p[r - 1].s, p[r - 1].e, p[i].s, p[i].e, c)
            if sgn(vect(p[0].s, p[0].e, c)) > 0:
                p[r] = p[i]
                r += 1
    m = 0
    for i in range(l, r):
        t = float('inf')
        t = min(t, abs(p[i].s.x))
        t = min(t, abs(p[i].s.y))
        t = min(t, abs(p[i].e.x))
        t = min(t, abs(p[i].e.y))
        if sgn(t - float('inf')):
            p[m] = p[i]
            m += 1
    return m

class PT3:
    def __init__(self, x: float = 0, y: float = 0, z: float = 0):
        self.x = x
        self.y = y
        self.z = z
    
    def __add__(self, o):
        return PT3(self.x + o.x, self.y + o.y, self.z + o.z)
    
    def __iadd__(self, o):
        self.x += o.x
        self.y += o.y
        self.z += o.z
        return self
    
    def __sub__(self, o):
        return PT3(self.x - o.x, self.y - o.y, self.z - o.z)
    
    def __isub__(self, o):
        self.x -= o.x
        self.y -= o.y
        self.z -= o.z
        return self
    
    def __neg__(self):
        return PT3(-self.x, -self.y, -self.z)
    
    def __mul__(self, c: float):
        return PT3(self.x * c, self.y * c, self.z * c)
    
    def __imul__(self, c: float):
        self.x *= c
        self.y *= c
        self.z *= c
        return self
    
    def __rmul__(self, c: float):
        return self * c
    
    def __truediv__(self, c: float):
        return PT3(self.x / c, self.y / c, self.z / c)
    
    def __itruediv__(self, c: float):
        self.x /= c
        self.y /= c
        self.z /= c
        return self
    
    def __lt__(self, o):
        if math.isclose(self.x, o.x, rel_tol=EPS):
            if math.isclose(self.y, o.y, rel_tol=EPS):
                return self.z < o.z
            return self.y < o.y
        return self.x < o.x
    
    def __eq__(self, o):
        return math.isclose(self.x, o.x, rel_tol=EPS) and math.isclose(self.y, o.y, rel_tol=EPS) and math.isclose(self.z, o.z, rel_tol=EPS)
    
    def __ne__(self, o):
        return not self == o

def dis(v: PT3) -> float:
    return math.sqrt(sqr(v.x) + sqr(v.y) + sqr(v.z))

def dis2(v: PT3) -> float:
    return sqr(v.x) + sqr(v.y) + sqr(v.z)

def dis(p1: PT3, p2: PT3) -> float:
    return dis(p1 - p2)

def dis2(p1: PT3, p2: PT3) -> float:
    return dis2(p1 - p2)

def vect(v1: PT3, v2: PT3) -> PT3:
    return PT3(v1.y * v2.z - v2.y * v1.z, -(v1.x * v2.z - v2.x * v1.z), v1.x * v2.y - v2.x * v1.y)

def vect(p: PT3, p1: PT3, p2: PT3) -> PT3:
    return vect(p1 - p, p2 - p)

def scal(v1: PT3, v2: PT3) -> float:
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z

def scal(p: PT3, p1: PT3, p2: PT3) -> float:
    return scal(p1 - p, p2 - p)

def id11(p: PT3, a: float, b: float, c: float, d: float) -> float:
    return abs(a * p.x + b * p.y + c * p.z + d) / math.sqrt(sqr(a) + sqr(b) + sqr(c))

def makePlane(p1: PT3, p2: PT3, p3: PT3) -> Tuple[float, float, float, float]:
    q = vect(p1, p2, p3)
    a, b, c = q.x, q.y, q.z
    d = -(a * p1.x + b * p1.y + c * p1.z)
    return a, b, c, d

N = 2100
d = [0.0] * N
p = [PT()] * N
v = []

def cmp1(a: PT, b: PT) -> bool:
    if sect(a) != sect(b):
        return sect(a) < sect(b)
    d = vect(a, b)
    return sgn(d) > 0

def cmp2(a: PT, b: PT) -> bool:
    return sect(a) == sect(b) and sgn(vect(a, b)) == 0

def solve(n: int) -> int:
    g = gravityCenter(p, n)
    for i in range(n):
        p[i] -= g
    p.sort()
    q = PT()
    for i in range(n):
        fp = p.index(-p[i])
        if p[fp] != -p[i]:
            q = p[i]
            break
        if i == n - 1:
            return -1
    for i in range(n):
        m = (p[i] + q) / 2
        nv = normalLine(PT(), m)
        if sect(nv) >= 3:
            nv = -nv
        v.append(nv)
    v.sort(key=cmp1)
    v = list(set(v))
    ans = 0
    for i in range(len(v)):
        d = [0.0] * n
        for j in range(n):
            d[j] = scal(v[i], proj(p[j], PT(), v[i])) / dis(v[i])
        d.sort()
        flg = True
        for j in range(n // 2):
            if sgn(d[j] + d[n - 1 - j]):
                flg = False
        ans += flg
    return ans

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        x, y = map(float, input().split())
        p[i] = PT(x, y)
    print(solve(n))
