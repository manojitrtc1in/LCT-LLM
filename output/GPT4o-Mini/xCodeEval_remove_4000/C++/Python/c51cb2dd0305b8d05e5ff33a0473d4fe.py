import cmath
import math
from collections import namedtuple
from itertools import combinations

EPS = 1e-9
Point = complex

def cross(a, b):
    return (a.real * b.imag) - (a.imag * b.real)

def dot(a, b):
    return (a.real * b.real) + (a.imag * b.imag)

def length(v):
    return abs(v)

def lengthSqr(v):
    return v.real * v.real + v.imag * v.imag

def normalize(v):
    return v / length(v)

def rotate(v, angle):
    return v * cmath.exp(Point(0, angle))

def vec(a, b):
    return b - a

def mid(a, b):
    return (a + b) / 2

def perp(v):
    return Point(-v.imag, v.real)

def same(a, b):
    return abs(a - b) < EPS

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    if abs(d1 - d2) > EPS:
        ret = (d1 * q - d2 * p) / (d1 - d2)
        return True, ret
    return False, None

def id4(a, b, p):
    return cross(vec(a, b), vec(a, p)) < EPS and dot(vec(a, p), vec(a, b)) > -EPS and dot(vec(b, a), vec(b, p)) > -EPS

def id1(cen, r, p):
    lensqr = lengthSqr(vec(cen, p))
    if abs(lensqr - r * r) < EPS:
        return 1
    if lensqr < r * r:
        return 0
    cp = vec(cen, p)
    h = length(cp)
    a = math.acos(r / h)
    cp = normalize(cp) * r
    r1 = rotate(cp, a) + cen
    r2 = rotate(cp, -a) + cen
    return 2, r1, r2

def can(t):
    start = Point(x, y)
    fin = Point(xp, yp)
    theta = t * vp / R
    fin = rotate(fin, theta)
    intersection = False
    num, a, b = id1(Point(0, 0), r, start)
    if num:
        if id4(start, fin, a):
            intersection = True
        if num == 2 and id4(start, fin, b):
            intersection = True
    if num <= 1 or not intersection:
        return length(start - fin) < v * t + EPS
    dis = calcDis(start, fin)
    return dis < v * t + EPS

def calcDis(a, c):
    arc = calcArc(a, c)
    return arc + length(vec(a, Point(x, y))) + length(vec(c, Point(xp, yp)))

def calcArc(a, b):
    theta = abs(cmath.phase(b) - cmath.phase(a))
    if theta > math.pi:
        theta = 2 * math.pi - theta
    return theta * r

xp, yp, vp, x, y, v, r = map(float, input().split())
R = length(Point(xp, yp))
ans = 1e7
hi = 1e6
lo = 0.0

for _ in range(100):
    m = lo + (hi - lo) / 2.0
    if can(m):
        ans = m
        hi = m - EPS
    else:
        lo = m + EPS

print(f"{ans:.10f}")
