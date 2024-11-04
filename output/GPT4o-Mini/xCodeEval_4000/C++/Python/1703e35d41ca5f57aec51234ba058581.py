import math
from cmath import rect, phase
from collections import namedtuple
from itertools import combinations
from fractions import Fraction

Point = complex

EPS = 1e-5
OO = 1e9

def vec(a, b):
    return b - a

def length(v):
    return abs(v)

def lengthSqr(v):
    return (v.real ** 2 + v.imag ** 2)

def dot(a, b):
    return (a.conjugate() * b).real

def cross(a, b):
    return (a.conjugate() * b).imag

def rotate(v, t):
    return rect(length(v), phase(v) + t)

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    ret = (d1 * q - d2 * p) / (d1 - d2)
    if abs(d1 - d2) > EPS:
        return True, ret
    return False, None

def pointOnLine(a, b, p):
    return abs(cross(vec(a, b), vec(a, p))) < EPS

def pointOnRay(a, b, p):
    return dot(vec(a, p), vec(a, b)) > -EPS

def pointOnSegment(a, b, p):
    if not pointOnLine(a, b, p):
        return False
    return pointOnRay(a, b, p) and pointOnRay(b, a, p)

def pointLineDist(a, b, p):
    return abs(cross(vec(a, b), vec(a, p))) / length(vec(a, b))

def pointSegmentDist(a, b, p):
    if dot(vec(a, b), vec(a, p)) < EPS:
        return length(vec(a, p))
    if dot(vec(b, a), vec(b, p)) < EPS:
        return length(vec(b, p))
    return pointLineDist(a, b, p)

def segmentLatticePointsCount(x1, y1, x2, y2):
    return abs(Fraction(x1 - x2, y1 - y2).denominator) + 1

def triangleAreaBH(b, h):
    return b * h / 2

def triangleArea2sidesAngle(a, b, t):
    return abs(a * b * math.sin(t) / 2)

def triangleArea2anglesSide(t1, t2, s):
    return abs(s * s * math.sin(t1) * math.sin(t2) / (2 * math.sin(t1 + t2)))

def triangleArea3sides(a, b, c):
    s = (a + b + c) / 2
    return math.sqrt(s * (s - a) * (s - b) * (s - c))

def triangleArea3points(a, b, c):
    return abs(cross(a, b) + cross(b, c) + cross(c, a)) / 2

def picksTheorm(a, b):
    return a - b / 2 + 1

def cosRule(a, b, c):
    res = (b * b + c * c - a * a) / (2 * b * c)
    if abs(res - 1) < EPS:
        res = 1
    if abs(res + 1) < EPS:
        res = -1
    return math.acos(res)

def sinRuleAngle(s1, s2, a1):
    res = s2 * math.sin(a1) / s1
    if abs(res - 1) < EPS:
        res = 1
    if abs(res + 1) < EPS:
        res = -1
    return math.asin(res)

def sinRuleSide(s1, a1, a2):
    return abs(s1 * math.sin(a2) / math.sin(a1))

def circleLineIntersection(p0, p1, cen, rad):
    a = dot(p1 - p0, p1 - p0)
    b = 2 * dot(p1 - p0, p0 - cen)
    c = dot(p0 - cen, p0 - cen) - rad * rad
    det = b * b - 4 * a * c
    if abs(det) < EPS:
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

def circleCircleIntersection(c1, r1, c2, r2):
    if abs(c1 - c2) < EPS and abs(r1 - r2) < EPS:
        return 1, c1, c1
    len_ = length(vec(c1, c2))
    if abs(len_ - (r1 + r2)) < EPS or abs(abs(r1 - r2) - len_) < EPS:
        d, c, r = (vec(c1, c2), c1, r1) if r1 > r2 else (vec(c2, c1), c2, r2)
        res1 = normalize(d) * r + c
        return 1, res1, res1
    if len_ > r1 + r2 or len_ < abs(r1 - r2):
        return 0, None, None
    a = cosRule(r2, r1, len_)
    c1c2 = normalize(vec(c1, c2)) * r1
    res1 = rotate(c1c2, a) + c1
    res2 = rotate(c1c2, -a) + c1
    return 2, res1, res2

def circle2(p1, p2):
    cen = (p1 + p2) / 2
    r = length(vec(p1, p2)) / 2
    return cen, r

def circle3(p1, p2, p3):
    m1 = (p1 + p2) / 2
    m2 = (p2 + p3) / 2
    perp1 = Point(-vec(p1, p2).imag, vec(p1, p2).real)
    perp2 = Point(-vec(p2, p3).imag, vec(p2, p3).real)
    res, cen = intersect(m1, m1 + perp1, m2, m2 + perp2)
    r = length(vec(cen, p1))
    return res, cen, r

def circlePoint(cen, r, p):
    lensqr = lengthSqr(vec(cen, p))
    if abs(lensqr - r * r) < EPS:
        return 'BOUNDRY'
    if lensqr < r * r:
        return 'IN'
    return 'OUT'

def tangentPoints(cen, r, p):
    state = circlePoint(cen, r, p)
    if state != 'OUT':
        return p, p, state == 'BOUNDRY'
    cp = vec(cen, p)
    h = length(cp)
    a = math.acos(r / h)
    cp = normalize(cp) * r
    r1 = rotate(cp, a) + cen
    r2 = rotate(cp, -a) + cen
    return r1, r2, 2

def polygonArea(p):
    res = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        res += cross(p[i], p[j])
    return abs(res) / 2

def polygonCentroid(polygon):
    a = 0
    x = 0.0
    y = 0.0
    for i in range(len(polygon)):
        j = (i + 1) % len(polygon)
        x += (polygon[i].real + polygon[j].real) * (polygon[i].real * polygon[j].imag - polygon[j].real * polygon[i].imag)
        y += (polygon[i].imag + polygon[j].imag) * (polygon[i].real * polygon[j].imag - polygon[j].real * polygon[i].imag)
        a += polygon[i].real * polygon[j].imag - polygon[i].imag * polygon[j].real
    a *= 0.5
    x /= 6 * a
    y /= 6 * a
    return Point(x, y)

def picksTheorm(p):
    area = 0
    bound = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        area += cross(p[i], p[j])
        v = vec(p[i], p[j])
        bound += abs(Fraction(int(v.real), int(v.imag)).denominator)
    area /= 2
    area = abs(area)
    return round(area - bound / 2 + 1)

def polygonCut(p, a, b):
    res = []
    for i in range(len(p)):
        j = (i + 1) % len(p)
        in1 = cross(vec(a, b), vec(a, p[i])) > EPS
        in2 = cross(vec(a, b), vec(a, p[j])) > EPS
        if in1:
            res.append(p[i])
        if in1 ^ in2:
            r = intersect(a, b, p[i], p[j])[1]
            res.append(r)
    return res

def convexPolygonIntersect(p, q):
    res = q
    for i in range(len(p)):
        j = (i + 1) % len(p)
        temp = polygonCut(res, p[i], p[j])
        res = temp
        if not res:
            return []
    return res

def voronoi(pnts, rect):
    res = []
    for i in range(len(pnts)):
        res.append(rect)
        for j in range(len(pnts)):
            if j == i:
                continue
            p = Point(-vec(pnts[i], pnts[j]).imag, vec(pnts[i], pnts[j]).real)
            m = (pnts[i] + pnts[j]) / 2
            temp = polygonCut(res[-1], m, m + p)
            res[-1] = temp
    return res

def pointInPolygon(p, pnt):
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        if pointOnSegment(p[i], p[j], pnt):
            return 'BOUNDRY'
        r = intersect(pnt, p2, p[i], p[j])[1]
        if not r:
            continue
        if not pointOnRay(pnt, p2, r):
            continue
        if same(r, p[i]) or same(r, p[j]):
            if abs(r.imag - min(p[i].imag, p[j].imag)) < EPS:
                continue
        if not pointOnSegment(p[i], p[j], r):
            continue
        cnt += 1
    return 'IN' if cnt & 1 else 'OUT'

def sortAntiClockWise(pnts):
    mn = Point(float('inf'), float('inf'))
    for p in pnts:
        if (p.imag, p.real) < (mn.imag, mn.real):
            mn = p
    pnts.sort(key=lambda p: (math.atan2(p.imag - mn.imag, p.real - mn.real), p.imag, p.real))

def convexHull(pnts):
    sortAntiClockWise(pnts)
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
            if cross(vec(b, a), vec(b, c)) < -EPS:
                break
            convex.pop()
        if i < len(pnts):
            convex.append(pnts[i])
    return convex

Xc, Yc, Vc = map(int, input().split())
Xb, Yb, Vb, r = map(int, input().split())
planet = Point(Xc, Yc)
ship = Point(Xb, Yb)
R = length(planet)
w = Vc / R
left = 0
right = 1 << 30

for _ in range(300):
    mid = (right + left) / 2
    new_planet = rotate(planet, w * mid)
    if pointSegmentDist(ship, new_planet, Point(0, 0)) < r:
        a, b = tangentPoints(Point(0, 0), r, ship)
        c, d = tangentPoints(Point(0, 0), r, new_planet)
        distance = OO
        distance = min(distance, length(vec(ship, a)) + length(vec(c, new_planet)) + arc_length(a, c, r))
        distance = min(distance, length(vec(ship, b)) + length(vec(c, new_planet)) + arc_length(b, c, r))
        distance = min(distance, length(vec(ship, a)) + length(vec(d, new_planet)) + arc_length(a, d, r))
        distance = min(distance, length(vec(ship, b)) + length(vec(d, new_planet)) + arc_length(b, d, r))
    else:
        distance = length(vec(ship, new_planet))

    if distance / Vb < mid:
        right = mid
    else:
        left = mid

print(f"{left:.10f}")
