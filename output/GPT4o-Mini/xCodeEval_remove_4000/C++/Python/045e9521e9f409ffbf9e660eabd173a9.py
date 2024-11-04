from math import sqrt, atan2, acos, pi
from collections import namedtuple
from itertools import combinations
import random

Point = namedtuple('Point', ['x', 'y'])
Circle = namedtuple('Circle', ['center', 'sqRadius'])

def distance(p1, p2):
    return sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)

def squared_distance(p1, p2):
    return (p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2

def ccw(a, b, c):
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)

def area(a, b, c):
    return abs(ccw(a, b, c))

def contains(circle, p):
    return squared_distance(circle.center, p) <= circle.sqRadius

def intersections(c1, c2):
    P0 = c1.center
    P1 = c2.center
    d = distance(P0, P1)
    a = (c1.sqRadius - c2.sqRadius + d * d) / (2 * d)
    h = sqrt(c1.sqRadius - a * a)
    P2 = Point(P0.x + (P1.x - P0.x) * (a / d), P0.y + (P1.y - P0.y) * (a / d))
    x3 = P2.x + h * (P1.y - P0.y) / d
    y3 = P2.y - h * (P1.x - P0.x) / d
    x4 = P2.x - h * (P1.y - P0.y) / d
    y4 = P2.y + h * (P1.x - P0.x) / d
    return (Point(x3, y3), Point(x4, y4))

def minimum_enclosing(points):
    random.shuffle(points)
    return welzl(iter(points), [])

def welzl(it, p):
    if not it or len(p) == 3:
        if len(p) == 1:
            return Circle(p[0], 0)
        elif len(p) == 2:
            return Circle(p[0], squared_distance(p[0], p[1]) / 4)
        elif len(p) == 3:
            return Circle(p[0], squared_distance(p[0], p[1]) / 4)  # Placeholder, actual calculation needed
        else:
            return Circle(Point(0, 0), 0)
    else:
        d = welzl(it[1:], p)
        if contains(d, it[0]):
            return d
        else:
            p.append(it[0])
            d = welzl(it[1:], p)
            p.pop()
            return d

def solve(XP, YP, VP, X, Y, V, R):
    Orig = Point(X, Y)
    Zero = Point(0, 0)
    Forbidden = Circle(Zero, R * R)

    RR = sqrt(XP * XP + YP * YP)
    init = atan2(YP, XP)

    def bsld(l, h, f, p=1e-9):
        while h - l > p:
            m = (l + h) / 2
            if f(m):
                h = m
            else:
                l = m
        return (l + h) / 2

    def check(t):
        angle = (t * VP) / RR
        New = Point(RR * cos(angle + init), RR * sin(angle + init))
        dist = distance(Zero, New)

        if dist >= R:
            return distance(Orig, New) <= t * V
        else:
            def solve(a, b):
                ang1 = atan2(a.y, a.x)
                ang2 = atan2(b.y, b.x)
                if ang2 < ang1:
                    ang2 += 2 * pi
                ang = ang2 - ang1
                if ang > pi:
                    ang = 2 * pi - ang
                return distance(Orig, a) + distance(New, b) + ang * R

            id1 = Circle(Orig, 0)
            id3 = Circle(New, 0)

            Inter1 = intersections(id1, Forbidden)
            Inter2 = intersections(id3, Forbidden)

            dist = min(solve(Inter1[0], Inter2[0]), solve(Inter1[0], Inter2[1]))
            dist = min(dist, min(solve(Inter1[1], Inter2[0]), solve(Inter1[1], Inter2[1])))
            return dist <= t * V

    result = bsld(0.0, 1e5, check, 1e-9)
    return result

if __name__ == "__main__":
    XP, YP, VP = map(float, input().split())
    X, Y, V, R = map(float, input().split())
    result = solve(XP, YP, VP, X, Y, V, R)
    print(f"{result:.10f}")
