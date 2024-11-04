import cmath
import math
from collections import namedtuple

point = complex

EPS = 1e-9

def cross(a, b):
    return (a.real * b.imag - a.imag * b.real)

def dot(a, b):
    return (a.real * b.real + a.imag * b.imag)

def length(v):
    return abs(v)

def lengthSqr(v):
    return v.real * v.real + v.imag * v.imag

def normalize(v):
    return v / length(v)

def rotate(v, angle):
    return v * complex(math.cos(angle), math.sin(angle))

def same(a, b):
    return abs(a - b) < EPS

def mid(a, b):
    return (a + b) / 2

def perp(v):
    return complex(-v.imag, v.real)

def vec(a, b):
    return b - a

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    if abs(d1 - d2) > EPS:
        ret = (d1 * q - d2 * p) / (d1 - d2)
        return True, ret
    return False, None

def id1(cen, r, p):
    lensqr = lengthSqr(vec(cen, p))
    if abs(lensqr - r * r) < EPS:
        return 1, p, p
    if lensqr < r * r:
        cp = vec(cen, p)
        h = length(cp)
        a = math.acos(r / h)
        cp = normalize(cp) * r
        r1 = rotate(cp, a) + cen
        r2 = rotate(cp, -a) + cen
        return 2, r1, r2
    return 0, None, None

def arc_length(a, b, r):
    Ang = math.atan2(a.imag, a.real) - math.atan2(b.imag, b.real)
    if Ang < 0:
        Ang += 2 * math.pi
    if Ang > math.pi:
        Ang = 2 * math.pi - Ang
    return Ang * r

def main():
    Xc, Yc, Vc = map(int, input().split())
    Xb, Yb, Vb, r = map(int, input().split())
    planet = point(Xc, Yc)
    ship = point(Xb, Yb)
    R = length(planet)
    w = Vc / R
    left, right = 0, 1 << 30
    
    for _ in range(300):
        mid = (right + left) / 2
        id23 = rotate(planet, w * mid)
        
        if id21(ship, id23, point(0, 0)) < r:
            a, b, c, d = None, None, None, None
            _, a, b = id1(point(0, 0), r, ship)
            _, c, d = id1(point(0, 0), r, id23)
            distance = 1 << 30
            
            distance = min(distance, length(vec(ship, a)) + length(vec(c, id23)) + arc_length(a, c, r))
            distance = min(distance, length(vec(ship, b)) + length(vec(c, id23)) + arc_length(b, c, r))
            distance = min(distance, length(vec(ship, a)) + length(vec(d, id23)) + arc_length(a, d, r))
            distance = min(distance, length(vec(ship, b)) + length(vec(d, id23)) + arc_length(b, d, r))
        else:
            distance = length(vec(ship, id23))
        
        if distance / Vb < mid:
            right = mid
        else:
            left = mid
    
    print(f"{left:.10f}")

if __name__ == "__main__":
    main()
