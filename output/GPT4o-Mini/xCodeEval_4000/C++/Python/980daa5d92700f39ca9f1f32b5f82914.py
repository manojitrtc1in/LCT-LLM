import math
from cmath import rect, phase
from collections import namedtuple
from itertools import combinations
from fractions import Fraction

Point = complex

EPS = 1e-8
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
    if abs(d1 - d2) > EPS:
        ret = (d1 * q - d2 * p) / (d1 - d2)
        return True, ret
    return False, None

def pointOnLine(a, b, p):
    return abs(cross(vec(a, b), vec(a, p))) < EPS

def pointOnRay(a, b, p):
    return dot(vec(a, p), vec(a, b)) > -EPS

def pointOnSegment(a, b, p):
    return pointOnLine(a, b, p) and pointOnRay(a, b, p) and pointOnRay(b, a, p)

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

def triangleArea3sides(a, b, c):
    s = (a + b + c) / 2
    return math.sqrt(s * (s - a) * (s - b) * (s - c))

def picksTheorem(a, b):
    return a - b / 2 + 1

def cosRule(a, b, c):
    res = (b * b + c * c - a * a) / (2 * b * c)
    if abs(res - 1) < EPS:
        res = 1
    if abs(res + 1) < EPS:
        res = -1
    return math.acos(res)

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
        return p, p, s == 'BOUNDRY'
    cp = vec(cen, p)
    h = length(cp)
    a = math.acos(r / h)
    cp = cp / length(cp) * r
    r1 = rotate(cp, a) + cen
    r2 = rotate(cp, -a) + cen
    return r1, r2, 2

def calcArc(a, b, r):
    theta = abs(phase(b) - phase(a))
    if theta > math.pi:
        theta = 2 * math.pi - theta
    return theta * r

def calcDis(a, c, st, en):
    arc = calcArc(a, c, r)
    return arc + abs(length(vec(a, st))) + abs(length(vec(c, en)))

def can(t, st, en, vp, r, v):
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
    dis = calcDis(st, fin)
    return dis < v * t + EPS

xp, yp, vp, x, y, v, r = map(float, input().split())
R = length(Point(xp, yp))
ans = 10000000
hi = 1000000
lo = 0.0

for _ in range(100):
    m = lo + (hi - lo) / 2.0
    if can(m, Point(x, y), Point(xp, yp), vp, r, v):
        ans = m
        hi = m - EPS
    else:
        lo = m + EPS

print(f"{ans:.10f}")
