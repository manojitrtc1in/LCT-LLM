import math
from cmath import rect, phase
from collections import namedtuple
from itertools import combinations
from fractions import gcd

EPS = 1e-7
OO = 1e9

Point = complex

def sz(a):
    return len(a)

def all(n):
    return n

def vec(a, b):
    return b - a

def polar(r, t):
    return r * rect(1, t)

def angle(v):
    return phase(v)

def length(v):
    return abs(v)

def lengthSqr(v):
    return (v.real ** 2 + v.imag ** 2)

def dot(a, b):
    return (a.conjugate() * b).real

def cross(a, b):
    return (a.conjugate() * b).imag

def rotate(v, t):
    return polar(length(v), angle(v) + t)

def mid(a, b):
    return (a + b) / 2

def perp(a):
    return Point(-a.imag, a.real)

def same(a, b):
    return lengthSqr(vec(a, b)) < EPS

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    if abs(d1 - d2) > EPS:
        return (d1 * q - d2 * p) / (d1 - d2), True
    return None, False

def pointOnLine(a, b, p):
    return abs(cross(vec(a, b), vec(a, p))) < EPS

def pointOnRay(a, b, p):
    return dot(vec(a, p), vec(a, b)) > -EPS

def pointOnSegment(a, b, p):
    return pointOnLine(a, b, p) and pointOnRay(a, b, p) and pointOnRay(b, a, p)

def pointLineDist(a, b, p):
    return abs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)))

def pointSegmentDist(a, b, p):
    if dot(vec(a, b), vec(a, p)) < EPS:
        return length(vec(a, p))
    if dot(vec(b, a), vec(b, p)) < EPS:
        return length(vec(b, p))
    return pointLineDist(a, b, p)

def segmentLatticePointsCount(x1, y1, x2, y2):
    return abs(gcd(x1 - x2, y1 - y2)) + 1

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
    if same(c1, c2) and abs(r1 - r2) < EPS:
        return (1, c1) if abs(r1) < EPS else (OO, c1, c1)
    length = abs(vec(c1, c2))
    if abs(length - (r1 + r2)) < EPS or abs(abs(r1 - r2) - length) < EPS:
        d, c, r = (vec(c1, c2), c1, r1) if r1 > r2 else (vec(c2, c1), c2, r2)
        return (1, normalize(d) * r + c)
    if length > r1 + r2 or length < abs(r1 - r2):
        return 0
    a = cosRule(r2, r1, length)
    c1c2 = normalize(vec(c1, c2)) * r1
    res1 = rotate(c1c2, a) + c1
    res2 = rotate(c1c2, -a) + c1
    return 2, res1, res2

def circle2(p1, p2):
    cen = mid(p1, p2)
    r = length(vec(p1, p2)) / 2
    return cen, r

def circle3(p1, p2, p3):
    m1 = mid(p1, p2)
    m2 = mid(p2, p3)
    perp1 = perp(vec(p1, p2))
    perp2 = perp(vec(p2, p3))
    cen, res = intersect(m1, m1 + perp1, m2, m2 + perp2)
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
    s = circlePoint(cen, r, p)
    if s != 'OUT':
        return (p, p) if s == 'BOUNDRY' else (p, p)
    cp = vec(cen, p)
    h = length(cp)
    a = math.acos(r / h)
    cp = normalize(cp) * r
    r1 = rotate(cp, a) + cen
    r2 = rotate(cp, -a) + cen
    return r1, r2

def getCommonTangents(c1, r1, c2, r2):
    if r1 < r2:
        r1, r2, c1, c2 = r2, r1, c2, c1
    d = length(c1 - c2)
    theta = math.acos((r1 - r2) / d)
    v = c2 - c1
    v /= abs(v)
    v1 = v * rect(1, theta)
    v2 = v * rect(1, -theta)
    res = []
    res.append((c1 + v1 * r1, c2 + v1 * r2))
    res.append((c1 + v2 * r1, c2 + v2 * r2))
    theta = math.acos((r1 + r2) / d)
    v1 = v * rect(1, theta)
    v2 = v * rect(1, -theta)
    res.append((c1 + v1 * r1, c2 - v1 * r2))
    res.append((c1 + v2 * r1, c2 - v2 * r2))
    return res

def polygonArea(p):
    res = 0
    for i in range(sz(p)):
        j = (i + 1) % sz(p)
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
    for i in range(sz(p)):
        j = (i + 1) % sz(p)
        area += cross(p[i], p[j])
        v = vec(p[i], p[j])
        bound += abs(gcd(int(v.real), int(v.imag)))
    area /= 2
    area = abs(area)
    return round(area - bound / 2 + 1)

def polygonCut(p, a, b):
    res = []
    for i in range(sz(p)):
        j = (i + 1) % sz(p)
        in1 = cross(vec(a, b), vec(a, p[i])) > EPS
        in2 = cross(vec(a, b), vec(a, p[j])) > EPS
        if in1:
            res.append(p[i])
        if in1 ^ in2:
            r, _ = intersect(a, b, p[i], p[j])
            res.append(r)
    return res

def convexPolygonIntersect(p, q):
    res = q
    for i in range(sz(p)):
        j = (i + 1) % sz(p)
        temp = polygonCut(res, p[i], p[j])
        res = temp
        if not res:
            return []
    return res

def pointInPolygon(p, pnt):
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(sz(p)):
        j = (i + 1) % sz(p)
        if pointOnSegment(p[i], p[j], pnt):
            return 'BOUNDRY'
        r, _ = intersect(pnt, p2, p[i], p[j])
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
    if sz(pnts) == 1:
        return convex
    convex.append(pnts[1])
    if sz(pnts) == 2:
        if same(pnts[0], pnts[1]):
            convex.pop()
        return convex
    for i in range(2, sz(pnts) + 1):
        c = pnts[i % sz(pnts)]
        while sz(convex) > 1:
            b = convex[-1]
            a = convex[-2]
            if cross(vec(b, a), vec(b, c)) < -EPS:
                break
            convex.pop()
        if i < sz(pnts):
            convex.append(pnts[i])
    return convex

def calcArc(a, b, r):
    theta = abs(angle(b) - angle(a))
    if theta > math.pi:
        theta = 2 * math.pi - theta
    return theta * r

def calcDis(a, c, st, en):
    arc = calcArc(a, c, r)
    return arc + abs(length(vec(a, st))) + abs(length(vec(c, en)))

def Calc(st, en):
    a, b = tangentPoints(Point(0, 0), r, st)
    c, d = tangentPoints(Point(0, 0), r, en)
    res = calcDis(a, c, st, en)
    res = min(res, calcDis(a, d, st, en))
    res = min(res, calcDis(b, c, st, en))
    res = min(res, calcDis(b, d, st, en))
    return res

def can(t, st, en, vp, v, r):
    start = st
    fin = en
    theta = t * vp / R
    fin = rotate(fin, theta)
    intersection = False
    num, a, b = circleLineIntersection(start, fin, Point(0, 0), r)
    if num:
        if pointOnSegment(start, fin, a):
            intersection = True
        if num == 2 and pointOnSegment(start, fin, b):
            intersection = True
    if num <= 1 or not intersection:
        return length(vec(start, fin)) < v * t + EPS
    dis = Calc(st, fin)
    return dis < v * t + EPS

def main():
    xp, yp, vp, x, y, v, r = map(float, input().split())
    R = length(Point(xp, yp))
    ans = 10000000
    hi = 1000000
    lo = 0.0
    for _ in range(100):
        m = lo + (hi - lo) / 2.0
        if can(m, Point(x, y), Point(xp, yp), vp, v, r):
            ans = m
            hi = m - EPS
        else:
            lo = m + EPS
    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()
