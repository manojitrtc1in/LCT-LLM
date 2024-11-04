from cmath import phase
from math import acos, sqrt, fabs, sin, cos, pi
from collections import namedtuple
from itertools import combinations
import sys

EPS = 1e-9

Point = namedtuple('Point', ['x', 'y'])
Segment = namedtuple('Segment', ['start', 'end'])

def cross(a, b):
    return a.x * b.y - a.y * b.x

def dot(a, b):
    return a.x * b.x + a.y * b.y

def length(v):
    return sqrt(v.x ** 2 + v.y ** 2)

def lengthSqr(v):
    return v.x ** 2 + v.y ** 2

def vec(a, b):
    return Point(b.x - a.x, b.y - a.y)

def normalize(v):
    l = length(v)
    return Point(v.x / l, v.y / l)

def rotate(v, angle):
    return Point(v.x * cos(angle) - v.y * sin(angle), v.x * sin(angle) + v.y * cos(angle))

def same(a, b):
    return fabs(a.x - b.x) < EPS and fabs(a.y - b.y) < EPS

def mid(a, b):
    return Point((a.x + b.x) / 2, (a.y + b.y) / 2)

def perp(v):
    return Point(-v.y, v.x)

def intersect(a, b, p, q):
    d1 = cross(vec(p, a), vec(b, a))
    d2 = cross(vec(q, a), vec(b, a))
    if fabs(d1 - d2) > EPS:
        ret_x = (d1 * q.x - d2 * p.x) / (d1 - d2)
        ret_y = (d1 * q.y - d2 * p.y) / (d1 - d2)
        return Point(ret_x, ret_y), True
    return None, False

def id4(a, b, p):
    return cross(vec(a, b), vec(a, p)) < EPS and dot(vec(a, p), vec(a, b)) > -EPS and dot(vec(b, a), vec(b, p)) > -EPS

def id1(cen, r, p):
    lensqr = lengthSqr(vec(cen, p))
    if fabs(lensqr - r * r) < EPS:
        return 1
    if lensqr < r * r:
        return 0
    cp = vec(cen, p)
    h = length(cp)
    a = acos(r / h)
    cp = normalize(cp) * r
    r1 = rotate(cp, a)
    r2 = rotate(cp, -a)
    return 2, r1, r2

def can(t, st, en, xp, yp, vp, x, y, v, r):
    start = st
    fin = en
    theta = t * vp / r
    fin = rotate(fin, theta)
    a, b = None, None
    intersection = False
    num = id1(Point(0, 0), r, start)
    if num:
        if id4(start, fin, a):
            intersection = True
        if num == 2 and id4(start, fin, b):
            intersection = True
    if num <= 1 or not intersection:
        return length(vec(start, fin)) < v * t + EPS
    dis = calcDis(st, fin)
    return dis < v * t + EPS

def calcArc(a, b, r):
    theta = abs(phase(b) - phase(a))
    if theta > pi:
        theta = 2 * pi - theta
    return theta * r

def calcDis(a, c, st, en):
    arc = calcArc(a, c, r)
    return arc + fabs(length(vec(a, st))) + fabs(length(vec(c, en)))

def main():
    xp, yp, vp, x, y, v, r = map(float, input().split())
    R = length(Point(xp, yp))
    ans = 1e7
    hi = 1e6
    lo = 0.0
    for _ in range(100):
        m = lo + (hi - lo) / 2.0
        if can(m, Point(x, y), Point(xp, yp), xp, yp, vp, x, y, v, r):
            ans = m
            hi = m - EPS
        else:
            lo = m + EPS
    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()
