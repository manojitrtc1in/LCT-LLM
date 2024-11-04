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

def same(a, b):
    return abs(a - b) < EPS

def mid(a, b):
    return (a + b) / 2

def perp(v):
    return Point(-v.imag, v.real)

def vec(a, b):
    return b - a

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    if abs(d1 - d2) > EPS:
        ret = (d1 * q - d2 * p) / (d1 - d2)
        return True, ret
    return False, None

def id4(a, b, p):
    return abs(cross(vec(a, b), vec(a, p))) < EPS

def id23(a, b, p):
    return dot(vec(a, p), vec(a, b)) > -EPS

def id1(cen, r, p):
    lensqr = lengthSqr(vec(cen, p))
    if abs(lensqr - r * r) < EPS:
        return 1  # BOUNDRY
    if lensqr < r * r:
        return 0  # IN
    return 2  # OUT

def id13(p0, p1, cen, rad):
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

def calcArc(a, b, r):
    theta = abs(cmath.phase(b) - cmath.phase(a))
    if theta > math.pi:
        theta = 2 * math.pi - theta
    return theta * r

def calcDis(a, c, st, en):
    arc = calcArc(a, c, r)
    return arc + length(vec(a, st)) + length(vec(c, en))

def can(t, st, en, vp, r):
    start = st
    fin = en
    theta = t * vp / R
    fin = rotate(fin, theta)
    num, a, b = id13(start, fin, Point(0, 0), r)
    intersection = False
    if num:
        if id4(start, fin, a):
            intersection = True
        if num == 2 and id4(start, fin, b):
            intersection = True
    if num <= 1 or not intersection:
        return length(vec(start, fin)) < v * t + EPS
    dis = calcDis(st, fin)
    return dis < v * t + EPS

def main():
    global r, R
    xp, yp, vp, x, y, v, r = map(float, input().split())
    R = length(Point(xp, yp))
    ans = 1e7
    hi = 1e6
    lo = 0.0
    for _ in range(100):
        m = lo + (hi - lo) / 2.0
        if can(m, Point(x, y), Point(xp, yp), vp, r):
            ans = m
            hi = m
        else:
            lo = m
    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()
