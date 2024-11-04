import cmath
from math import fabs, acos, sin, sqrt, gcd
from typing import List, Tuple

EPS = 1e-9

class Point:
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y

    def __sub__(self, other: 'Point') -> 'Point':
        return Point(self.x - other.x, self.y - other.y)

    def __add__(self, other: 'Point') -> 'Point':
        return Point(self.x + other.x, self.y + other.y)

    def __mul__(self, scalar: float) -> 'Point':
        return Point(self.x * scalar, self.y * scalar)

    def __rmul__(self, scalar: float) -> 'Point':
        return self.__mul__(scalar)

    def __truediv__(self, scalar: float) -> 'Point':
        return Point(self.x / scalar, self.y / scalar)

    def __repr__(self) -> str:
        return f"({self.x}, {self.y})"

    def length(self) -> float:
        return abs(complex(self.x, self.y))

    def dot(self, other: 'Point') -> float:
        return self.x * other.x + self.y * other.y

    def cross(self, other: 'Point') -> float:
        return self.x * other.y - self.y * other.x

    def angle(self) -> float:
        return cmath.phase(complex(self.x, self.y))

    def rotate(self, angle: float) -> 'Point':
        return complex(self.x, self.y) * cmath.exp(complex(0, angle))

    def normalize(self) -> 'Point':
        length = self.length()
        return Point(self.x / length, self.y / length)

    def midpoint(self, other: 'Point') -> 'Point':
        return (self + other) / 2

    def perp(self) -> 'Point':
        return Point(-self.y, self.x)

    def intersect(self, other: 'Point', p: 'Point', q: 'Point') -> 'Point':
        d1 = (p - self).cross(q - self)
        d2 = (q - self).cross(other - self)
        return (d1 * q - d2 * p) / (d1 - d2)

    def collinear(self, b: 'Point', p: 'Point') -> bool:
        return fabs(self.cross(b) + b.cross(p) + p.cross(self)) < EPS

    def distance(self, p: 'Point') -> float:
        return abs(self - p)

    def angle_between(self, other: 'Point') -> float:
        theta = abs(self.angle() - other.angle())
        if theta > cmath.pi:
            theta = 2 * cmath.pi - theta
        return theta

    def to_tuple(self) -> Tuple[float, float]:
        return self.x, self.y

def operator_mul(a: float, b: Point) -> Point:
    return a * b

def operator_mul_reverse(b: Point, a: float) -> Point:
    return a * b

def intersect(a: Point, b: Point, p: Point, q: Point) -> Tuple[bool, Point]:
    d1 = (p - a).cross(b - a)
    d2 = (q - a).cross(b - a)
    ret = (d1 * q - d2 * p) / (d1 - d2)
    if fabs(d1 - d2) > EPS:
        return True, ret
    return False, ret

def id8(a: Point, b: Point, p: Point) -> bool:
    return fabs((a - p).cross(b - a)) < EPS

def id23(a: Point, b: Point, p: Point) -> bool:
    return (a - p).dot(b - a) > -EPS

def id4(a: Point, b: Point, p: Point) -> bool:
    if not a.collinear(b, p):
        return False
    return id23(a, b, p) and id23(b, a, p)

def id14(a: Point, b: Point, p: Point) -> float:
    return fabs((a - p).cross(b - a)) / (b - a).length()

def id22(a: Point, b: Point, p: Point) -> float:
    if (a - p).dot(b - a) < EPS:
        return (a - p).length()
    if (b - p).dot(a - b) < EPS:
        return (b - p).length()
    return id14(a, b, p)

def id16(x1: int, y1: int, x2: int, y2: int) -> int:
    return abs(gcd(x1 - x2, y1 - y2)) + 1

def id2(b: float, h: float) -> float:
    return b * h / 2

def id5(a: float, b: float, t: float) -> float:
    return fabs(a * b * sin(t) / 2)

def id19(t1: float, t2: float, s: float) -> float:
    return fabs(s * s * sin(t1) * sin(t2) / (2 * sin(t1 + t2)))

def id20(a: float, b: float, c: float) -> float:
    s = (a + b + c) / 2
    return sqrt(s * (s - a) * (s - b) * (s - c))

def id10(a: Point, b: Point, c: Point) -> float:
    return fabs(a.cross(b) + b.cross(c) + c.cross(a)) / 2

def id18(a: int, b: int) -> int:
    return a - b // 2 + 1

def cosRule(a: float, b: float, c: float) -> float:
    res = (b * b + c * c - a * a) / (2 * b * c)
    if fabs(res - 1) < EPS:
        res = 1
    if fabs(res + 1) < EPS:
        res = -1
    return acos(res)

def id26(s1: float, s2: float, a1: float) -> float:
    res = s2 * sin(a1) / s1
    if fabs(res - 1) < EPS:
        res = 1
    if fabs(res + 1) < EPS:
        res = -1
    return asin(res)

def id0(s1: float, a1: float, a2: float) -> float:
    res = s1 * sin(a2) / sin(a1)
    return fabs(res)

def id13(p0: Point, p1: Point, cen: Point, rad: float) -> Tuple[int, Point, Point]:
    a = (p1 - p0).dot(p1 - p0)
    b = 2 * (p1 - p0).dot(p0 - cen)
    c = (p0 - cen).dot(p0 - cen) - rad * rad
    det = b * b - 4 * a * c
    res = 0
    if fabs(det) < EPS:
        det = 0
        res = 1
    elif det < 0:
        res = 0
    else:
        res = 2
    det = sqrt(det)
    t1 = (-b + det) / (2 * a)
    t2 = (-b - det) / (2 * a)
    r1 = p0 + t1 * (p1 - p0)
    r2 = p0 + t2 * (p1 - p0)
    return res, r1, r2

def id3(c1: Point, r1: float, c2: Point, r2: float) -> Tuple[int, Point, Point]:
    if c1 == c2 and fabs(r1 - r2) < EPS:
        return c1, c2
    length = (c1 - c2).length()
    if fabs(length - (r1 + r2)) < EPS or fabs(fabs(r1 - r2) - length) < EPS:
        v = (c2 - c1).normalize() * r1
        return c1 + v, c2 + v
    if length > r1 + r2 or length < fabs(r1 - r2):
        return None
    a = cosRule(r2, r1, length)
    id11 = (c2 - c1).normalize() * r1
    return c1 + id11.rotate(a), c1 + id11.rotate(-a)

def circle2(p1: Point, p2: Point) -> Tuple[Point, float]:
    cen = p1.midpoint(p2)
    r = (p1 - p2).length() / 2
    return cen, r

def circle3(p1: Point, p2: Point, p3: Point) -> Tuple[bool, Point, float]:
    m1 = p1.midpoint(p2)
    m2 = p2.midpoint(p3)
    id7 = (p1 - p2).perp()
    id15 = (p2 - p3).perp()
    res, cen = intersect(m1, m1 + id7, m2, m2 + id15)
    r = (cen - p1).length()
    return res, cen, r

class STATE:
    IN = 0
    OUT = 1
    BOUNDRY = 2

def circlePoint(cen: Point, r: float, p: Point) -> STATE:
    lensqr = (cen - p).length() ** 2
    if fabs(lensqr - r * r) < EPS:
        return STATE.BOUNDRY
    if lensqr < r * r:
        return STATE.IN
    return STATE.OUT

def id1(cen: Point, r: float, p: Point) -> Tuple[STATE, Point, Point]:
    s = circlePoint(cen, r, p)
    if s != STATE.OUT:
        return s, p, p
    cp = p - cen
    h = cp.length()
    a = acos(r / h)
    cp = cp.normalize() * r
    r1 = cp.rotate(a) + cen
    r2 = cp.rotate(-a) + cen
    return s, r1, r2

def id12(c1: Point, r1: float, c2: Point, r2: float) -> List[Tuple[Point, Point]]:
    if r1 < r2:
        r1, r2 = r2, r1
        c1, c2 = c2, c1
    d = (c1 - c2).length()
    theta = acos((r1 - r2) / d)
    v = (c2 - c1).normalize()
    v1 = v.rotate(theta)
    v2 = v.rotate(-theta)
    res = []
    res.append((c1 + v1 * r1, c2 + v1 * r2))
    res.append((c1 + v2 * r1, c2 + v2 * r2))
    theta = acos((r1 + r2) / d)
    v1 = v.rotate(theta)
    v2 = v.rotate(-theta)
    res.append((c1 + v1 * r1, c2 - v1 * r2))
    res.append((c1 + v2 * r1, c2 - v2 * r2))
    return res

def polygonArea(p: List[Point]) -> float:
    res = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        res += p[i].cross(p[j])
    return fabs(res) / 2

def id9(polygon: List[Point]) -> Point:
    a = 0
    x = 0.0
    y = 0.0
    for i in range(len(polygon)):
        j = (i + 1) % len(polygon)
        x += (polygon[i].x + polygon[j].x) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)
        y += (polygon[i].y + polygon[j].y) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)
        a += polygon[i].x * polygon[j].y - polygon[i].y * polygon[j].x
    a *= 0.5
    x /= 6 * a
    y /= 6 * a
    return Point(x, y)

def id18(p: List[Point]) -> int:
    area = 0
    bound = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        area += p[i].cross(p[j])
        v = p[i] - p[j]
        bound += abs(gcd(int(v.x), int(v.y)))
    area /= 2
    area = fabs(area)
    return round(area - bound / 2 + 1)

def polygonCut(p: List[Point], a: Point, b: Point) -> List[Point]:
    res = []
    for i in range(len(p)):
        j = (i + 1) % len(p)
        in1 = (b - a).cross(p[i] - a) > EPS
        in2 = (b - a).cross(p[j] - a) > EPS
        if in1:
            res.append(p[i])
        if in1 != in2:
            r = a.intersect(b, p[i], p[j])
            res.append(r)
    return res

def id25(p: List[Point], q: List[Point]) -> List[Point]:
    res = q
    for i in range(len(p)):
        j = (i + 1) % len(p)
        temp = polygonCut(res, p[i], p[j])
        res = temp
        if not res:
            return []
    return res

def id21(pnts: List[Point], rect: List[Point]) -> List[List[Point]]:
    res = []
    for i in range(len(pnts)):
        res.append(rect)
        for j in range(len(pnts)):
            if j == i:
                continue
            p = (pnts[i] - pnts[j]).perp()
            m = pnts[i].midpoint(pnts[j])
            temp = polygonCut(res[-1], m, m + p)
            res[-1] = temp
    return res

def id24(p: List[Point], pnt: Point) -> STATE:
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        if id4(p[i], p[j], pnt):
            return STATE.BOUNDRY
        res, r = pnt.intersect(p2, p[i], p[j])
        if not res:
            continue
        if not id23(pnt, p2, r):
            continue
        if r == p[i] or r == p[j]:
            if fabs(r.y - min(p[i].y, p[j].y)) < EPS:
                continue
        if not id4(p[i], p[j], r):
            continue
        cnt += 1
    return STATE.IN if cnt & 1 else STATE.OUT

def cmp(about: Point):
    def compare(p: Point, q: Point) -> bool:
        cr = (about - p).cross(about - q)
        if fabs(cr) < EPS:
            return (p.y, p.x) < (q.y, q.x)
        return cr > 0
    return compare

def id6(pnts: List[Point]) -> None:
    mn = Point(float('inf'), float('inf'))
    for p in pnts:
        if (p.y, p.x) < (mn.y, mn.x):
            mn = p
    pnts.sort(key=cmp(mn))

def id17(pnts: List[Point]) -> List[Point]:
    id6(pnts)
    convex = []
    convex.append(pnts[0])
    if len(pnts) == 1:
        return convex
    convex.append(pnts[1])
    if len(pnts) == 2:
        if pnts[0] == pnts[1]:
            convex.pop()
        return convex
    for i in range(2, len(pnts) + 1):
        c = pnts[i % len(pnts)]
        while len(convex) > 1:
            b = convex[-1]
            a = convex[-2]
            if (b - a).cross(b - c) < -EPS:
                break
            convex.pop()
        if i < len(pnts):
            convex.append(pnts[i])
    return convex

def xp_yp_vp_x_y_v_r_R_polygon(st: Point, en: Point, xp: float, yp: float, vp: float, x: float, y: float, v: float, r: float, R: float) -> float:
    def calc_arc(a: Point, b: Point) -> float:
        theta = abs(b.angle() - a.angle())
        if theta > cmath.pi:
            theta = 2 * cmath.pi - theta
        res = theta * r
        return res

    def calc_dis(a: Point, c: Point) -> float:
        arc = calc_arc(a, c)
        res = arc + abs((a - st).length()) + abs((c - en).length())
        return res

    def calc(start: Point, fin: Point) -> float:
        a, b, c, d = id1(Point(0, 0), r, start)
        res = calc_dis(a, c)
        res = min(res, calc_dis(a, d))
        res = min(res, calc_dis(b, c))
        res = min(res, calc_dis(b, d))
        return res

    def can(t: float) -> bool:
        start = st = Point(x, y)
        fin = en = Point(xp, yp)
        theta = t * vp / R
        fin = en = fin.rotate(theta)
        a, b = id13(start, fin, Point(0, 0), r)
        intersection = False
        if a:
            if id4(start, fin, a):
                intersection = True
            if b and id4(start, fin, b):
                intersection = True
        if a is None or not intersection:
            return (start - fin).length() < v * t + EPS
        dis = calc(st, fin)
        return dis < v * t + EPS

    ans = 10000000
    hi = 1000000
    lo = 0.0
    for _ in range(100):
        m = lo + (hi - lo) / 2.0
        if can(m):
            ans = m
            hi = m - EPS
        else:
            lo = m + EPS
    return ans

def main() -> None:
    xp, yp, vp, x, y, v, r = map(float, input().split())
    R = sqrt(xp * xp + yp * yp)
    st = en = Point(x, y)
    ans = xp_yp_vp_x_y_v_r_R_polygon(st, en, xp, yp, vp, x, y, v, r, R)
    print(f"{ans:.10f}")

if __name__ == '__main__':
    main()
