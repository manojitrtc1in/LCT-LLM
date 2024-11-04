import cmath
import math
from typing import List, Tuple

class Point:
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y

class Segment:
    def __init__(self, p1: Point, p2: Point):
        self.p1 = p1
        self.p2 = p2

class STATE:
    IN = 0
    OUT = 1
    BOUNDRY = 2

def intersect(a: Point, b: Point, p: Point, q: Point) -> Tuple[bool, Point]:
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    ret = (d1 * q - d2 * p) / (d1 - d2)
    if abs(d1 - d2) > 1e-7:
        return True, ret
    return False, ret

def point_on_line(a: Point, b: Point, p: Point) -> bool:
    return abs(cross(vec(a, b), vec(a, p))) < 1e-7

def point_on_ray(a: Point, b: Point, p: Point) -> bool:
    return dot(vec(a, p), vec(a, b)) > -1e-7

def point_on_segment(a: Point, b: Point, p: Point) -> bool:
    if not collinear(a, b, p):
        return False
    return point_on_ray(a, b, p) and point_on_ray(b, a, p)

def point_line_dist(a: Point, b: Point, p: Point) -> float:
    return abs(cross(vec(a, b), vec(a, p))) / length(vec(a, b))

def point_segment_dist(a: Point, b: Point, p: Point) -> float:
    if dot(vec(a, b), vec(a, p)) < 1e-7:
        return length(vec(a, p))
    if dot(vec(b, a), vec(b, p)) < 1e-7:
        return length(vec(b, p))
    return point_line_dist(a, b, p)

def segment_lattice_points_count(x1: int, y1: int, x2: int, y2: int) -> int:
    return abs(math.gcd(x1 - x2, y1 - y2)) + 1

def triangle_area_bh(b: float, h: float) -> float:
    return b * h / 2

def triangle_area_2sides_angle(a: float, b: float, t: float) -> float:
    return abs(a * b * math.sin(t) / 2)

def triangle_area_2angles_side(t1: float, t2: float, s: float) -> float:
    return abs(s * s * math.sin(t1) * math.sin(t2) / (2 * math.sin(t1 + t2)))

def triangle_area_3sides(a: float, b: float, c: float) -> float:
    s = (a + b + c) / 2
    return math.sqrt(s * (s - a) * (s - b) * (s - c))

def triangle_area_3points(a: Point, b: Point, c: Point) -> float:
    return abs(cross(a, b) + cross(b, c) + cross(c, a)) / 2

def picks_theorem(a: int, b: int) -> int:
    return a - b // 2 + 1

def cos_rule(a: float, b: float, c: float) -> float:
    res = (b * b + c * c - a * a) / (2 * b * c)
    if abs(res - 1) < 1e-7:
        res = 1
    if abs(res + 1) < 1e-7:
        res = -1
    return math.acos(res)

def sin_rule_angle(s1: float, s2: float, a1: float) -> float:
    res = s2 * math.sin(a1) / s1
    if abs(res - 1) < 1e-7:
        res = 1
    if abs(res + 1) < 1e-7:
        res = -1
    return math.asin(res)

def sin_rule_side(s1: float, a1: float, a2: float) -> float:
    return abs(s1 * math.sin(a2) / math.sin(a1))

def circle_line_intersection(p0: Point, p1: Point, cen: Point, rad: float) -> Tuple[int, Point, Point]:
    a, b, c, t1, t2 = 0, 0, 0, 0, 0
    a = dot(p1 - p0, p1 - p0)
    b = 2 * dot(p1 - p0, p0 - cen)
    c = dot(p0 - cen, p0 - cen) - rad * rad
    det = b * b - 4 * a * c
    res = 0
    if abs(det) < 1e-7:
        det = 0
        res = 1
    elif det < 0:
        res = 0
    else:
        res = 2
    det = math.sqrt(det)
    t1 = (-b + det) / (2 * a)
    t2 = (-b - det) / (2 * a)
    r1 = p0 + t1 * (p1 - p0)
    r2 = p0 + t2 * (p1 - p0)
    return res, r1, r2

def circle_circle_intersection(c1: Point, r1: float, c2: Point, r2: float) -> Tuple[int, Point, Point]:
    if same(c1, c2) and abs(r1 - r2) < 1e-7:
        res1 = res2 = c1
        return 1 if abs(r1) < 1e-7 else float('inf'), res1, res2
    len = length(vec(c1, c2))
    if abs(len - (r1 + r2)) < 1e-7 or abs(abs(r1 - r2) - len) < 1e-7:
        d, c, r = (vec(c1, c2), c1, r1) if r1 > r2 else (vec(c2, c1), c2, r2)
        res1 = res2 = normalize(d) * r + c
        return 1, res1, res2
    if len > r1 + r2 or len < abs(r1 - r2):
        return 0, None, None
    a = cos_rule(r2, r1, len)
    c1c2 = normalize(vec(c1, c2)) * r1
    res1 = rotate(c1c2, a) + c1
    res2 = rotate(c1c2, -a) + c1
    return 2, res1, res2

def circle2(p1: Point, p2: Point) -> Tuple[Point, float]:
    cen = mid(p1, p2)
    r = length(vec(p1, p2)) / 2
    return cen, r

def circle3(p1: Point, p2: Point, p3: Point) -> Tuple[bool, Point, float]:
    m1 = mid(p1, p2)
    m2 = mid(p2, p3)
    perp1 = perp(vec(p1, p2))
    perp2 = perp(vec(p2, p3))
    res = intersect(m1, m1 + perp1, m2, m2 + perp2)
    cen = res[1]
    r = length(vec(cen, p1))
    return res[0], cen, r

def circle_point(cen: Point, r: float, p: Point) -> STATE:
    lensqr = length_sqr(vec(cen, p))
    if abs(lensqr - r * r) < 1e-7:
        return STATE.BOUNDRY
    if lensqr < r * r:
        return STATE.IN
    return STATE.OUT

def tangent_points(cen: Point, r: float, p: Point) -> Tuple[Point, Point]:
    s = circle_point(cen, r, p)
    if s != STATE.OUT:
        return p, p
    cp = vec(cen, p)
    h = length(cp)
    a = math.acos(r / h)
    cp = normalize(cp) * r
    r1 = rotate(cp, a) + cen
    r2 = rotate(cp, -a) + cen
    return r1, r2

def get_common_tangents(c1: Point, r1: float, c2: Point, r2: float) -> List[Segment]:
    if r1 < r2:
        r1, r2 = r2, r1
        c1, c2 = c2, c1
    d = length(c1 - c2)
    theta = math.acos((r1 - r2) / d)
    v = c2 - c1
    v1 = v * cmath.exp(complex(0, theta))
    v2 = v * cmath.exp(complex(0, -theta))
    res = []
    res.append(Segment(c1 + v1 * r1, c2 + v1 * r2))
    res.append(Segment(c1 + v2 * r1, c2 + v2 * r2))
    theta = math.acos((r1 + r2) / d)
    v1 = v * cmath.exp(complex(0, theta))
    v2 = v * cmath.exp(complex(0, -theta))
    res.append(Segment(c1 + v1 * r1, c2 - v1 * r2))
    res.append(Segment(c1 + v2 * r1, c2 - v2 * r2))
    return res

def polygon_area(p: List[Point]) -> float:
    res = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        res += cross(p[i], p[j])
    return abs(res) / 2

def polygon_centroid(polygon: List[Point]) -> Point:
    a = 0
    x, y = 0.0, 0.0
    for i in range(len(polygon)):
        j = (i + 1) % len(polygon)
        x += (polygon[i].x + polygon[j].x) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)
        y += (polygon[i].y + polygon[j].y) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)
        a += polygon[i].x * polygon[j].y - polygon[i].y * polygon[j].x
    a *= 0.5
    x /= 6 * a
    y /= 6 * a
    return Point(x, y)

def picks_theorem(p: List[Point]) -> int:
    area = 0
    bound = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        area += cross(p[i], p[j])
        v = vec(p[i], p[j])
        bound += abs(math.gcd(int(v.x), int(v.y)))
    area /= 2
    area = abs(area)
    return round(area - bound / 2 + 1)

def polygon_cut(p: List[Point], a: Point, b: Point) -> List[Point]:
    res = []
    for i in range(len(p)):
        j = (i + 1) % len(p)
        in1 = cross(vec(a, b), vec(a, p[i])) > 1e-7
        in2 = cross(vec(a, b), vec(a, p[j])) > 1e-7
        if in1:
            res.append(p[i])
        if in1 != in2:
            r = intersect(a, b, p[i], p[j])[1]
            res.append(r)
    return res

def convex_polygon_intersect(p: List[Point], q: List[Point]) -> List[Point]:
    res = q
    for i in range(len(p)):
        j = (i + 1) % len(p)
        temp = []
        polygon_cut(res, p[i], p[j], temp)
        res = temp
        if not res:
            return []
    return res

def voronoi(pnts: List[Point], rect: List[Point]) -> List[List[Point]]:
    res = []
    for i in range(len(pnts)):
        res.append(rect)
        for j in range(len(pnts)):
            if j == i:
                continue
            p = perp(vec(pnts[i], pnts[j]))
            m = mid(pnts[i], pnts[j])
            temp = []
            polygon_cut(res[-1], m, m + p, temp)
            res[-1] = temp
    return res

def point_in_polygon(p: List[Point], pnt: Point) -> STATE:
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        if point_on_segment(p[i], p[j], pnt):
            return STATE.BOUNDRY
        r = intersect(pnt, p2, p[i], p[j])[1]
        if not point_on_ray(pnt, p2, r):
            continue
        if same(r, p[i]) or same(r, p[j]):
            if abs(r.y - min(p[i].y, p[j].y)) < 1e-7:
                continue
        if not point_on_segment(p[i], p[j], r):
            continue
        cnt += 1
    return STATE.IN if cnt & 1 else STATE.OUT

def cmp_about(about: Point):
    def cmp(p: Point, q: Point) -> bool:
        cr = cross(vec(about, p), vec(about, q))
        if abs(cr) < 1e-7:
            return (p.y, p.x) < (q.y, q.x)
        return cr > 0
    return cmp

def sort_anti_clockwise(pnts: List[Point]) -> None:
    mn = Point(float('inf'), float('inf'))
    for p in pnts:
        if (p.y, p.x) < (mn.y, mn.x):
            mn = p
    pnts.sort(key=cmp_about(mn))

def convex_hull(pnts: List[Point]) -> List[Point]:
    sort_anti_clockwise(pnts)
    convex = []
    convex.append(pnts[0])
    if len(pnts) == 1:
        return convex
    convex.append(pnts[1])
    if len(pnts) == 2:
        if same(pnts[0], pnts[1]):
            convex.pop()
        return convex
    for i in range(2, len(pnts) + 1):
        c = pnts[i % len(pnts)]
        while len(convex) > 1:
            b = convex[-1]
            a = convex[-2]
            if cross(vec(b, a), vec(b, c)) < -1e-7:
                break
            convex.pop()
        if i < len(pnts):
            convex.append(pnts[i])
    return convex

def xp_yp_vp_x_y_v_r_R: List[float]
    xp, yp, vp, x, y, v, r, R = xp_yp_vp_x_y_v_r_R
    pi = math.acos(-1)
    st = en = Point(x, y)
    theta = t * vp / R
    fin = en = rotate(fin, theta)
    a, b = Point(), Point()
    intersection = False
    num, a, b = circle_line_intersection(start, fin, Point(0, 0), r)
    if num:
        if point_on_segment(start, fin, a):
            intersection = True
        if num == 2 and point_on_segment(start, fin, b):
            intersection = True
    if num <= 1 or not intersection:
        return length(vec(start, fin)) < v * t + 1e-7
    dis = Calc(st, fin)
    return dis < v * t + 1e-7

def main() -> None:
    xp, yp, vp, x, y, v, r = map(float, input().split())
    R = length(Point(xp, yp))
    ans = 10000000
    hi, lo = 1000000, 0.0
    for _ in range(100):
        m = lo + (hi - lo) / 2.0
        if can(m):
            ans = m
            hi = m - 1e-7
        else:
            lo = m + 1e-7
    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()
