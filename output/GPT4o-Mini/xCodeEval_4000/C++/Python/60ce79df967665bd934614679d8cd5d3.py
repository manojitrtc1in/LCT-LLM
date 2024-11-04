import math
import sys

eps = 1e-8
pi = math.acos(-1.0)

def dblcmp(d):
    if abs(d) < eps:
        return 0
    return 1 if d > eps else -1

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def input(self):
        self.x, self.y = map(float, input().split())

    def output(self):
        print(f"{self.x:.12f} {self.y:.12f}")

    def __eq__(self, other):
        return dblcmp(other.x - self.x) == 0 and dblcmp(other.y - self.y) == 0

    def __lt__(self, other):
        return dblcmp(other.x - self.x) == 0 and dblcmp(self.y - other.y) < 0 or self.x < other.x

    def len(self):
        return math.hypot(self.x, self.y)

    def distance(self, p):
        return math.hypot(self.x - p.x, self.y - p.y)

    def add(self, p):
        return Point(self.x + p.x, self.y + p.y)

    def sub(self, p):
        return Point(self.x - p.x, self.y - p.y)

    def mul(self, b):
        return Point(self.x * b, self.y * b)

    def div(self, b):
        return Point(self.x / b, self.y / b)

    def dot(self, p):
        return self.x * p.x + self.y * p.y

    def det(self, p):
        return self.x * p.y - self.y * p.x

    def rotate(self, p, angle):
        v = self.sub(p)
        c = math.cos(angle)
        s = math.sin(angle)
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c)

class Line:
    def __init__(self, a=None, b=None):
        if a is not None and b is not None:
            self.a = a
            self.b = b
        else:
            self.a = Point()
            self.b = Point()

    def input(self):
        self.a.input()
        self.b.input()

    def adjust(self):
        if self.b < self.a:
            self.a, self.b = self.b, self.a

    def length(self):
        return self.a.distance(self.b)

    def angle(self):
        k = math.atan2(self.b.y - self.a.y, self.b.x - self.a.x)
        if dblcmp(k) < 0:
            k += pi
        if dblcmp(k - pi) == 0:
            k -= pi
        return k

    def relation(self, p):
        c = dblcmp(p.sub(self.a).det(self.b.sub(self.a)))
        if c < 0:
            return 1
        if c > 0:
            return 2
        return 3

    def dispointtoline(self, p):
        return abs(p.sub(self.a).det(self.b.sub(self.a))) / self.length()

    def dispointtoseg(self, p):
        if dblcmp(p.sub(self.b).dot(self.a.sub(self.b))) < 0 or dblcmp(p.sub(self.a).dot(self.b.sub(self.a))) < 0:
            return min(p.distance(self.a), p.distance(self.b))
        return self.dispointtoline(p)

class Circle:
    def __init__(self, p=None, r=0):
        if p is not None:
            self.p = p
        else:
            self.p = Point()
        self.r = r

    def input(self):
        self.p.input()
        self.r = float(input())

    def output(self):
        print(f"{self.p.x:.2f} {self.p.y:.2f} {self.r:.2f}")

    def area(self):
        return pi * self.r ** 2

    def relation(self, b):
        dst = b.distance(self.p)
        if dblcmp(dst - self.r) < 0:
            return 2
        if dblcmp(dst - self.r) == 0:
            return 1
        return 0

def dist(a, b):
    l = Line(a, b)
    p11, p12 = Point(), Point()
    if not c.pointcrossline(l, p11, p12):
        return a.distance(b)
    rd = Point(0, 0).rad(p11, p12)
    rd = min(rd, 2 * pi - rd)

    ds = a.distance(b) - p11.distance(p12) + rd * r
    l1, l2 = Line(), Line()
    c.tangentline(a, l1, l2)
    p1 = [l1.b, l2.b]
    c.tangentline(b, l1, l2)
    p2 = [l1.b, l2.b]
    for i in range(2):
        for j in range(2):
            ds = min(ds, a.distance(p1[i]) + Point(0, 0).rad(p1[i], p2[j]) * r + b.distance(p2[j]))
    return ds

xp, yp, vp = map(float, input().split())
p = Point(xp, yp)
x, y, v, r = map(float, input().split())
c = Circle(Point(0, 0), r)

d = 2 * pi * p.distance(Point(0, 0))
low, high = 0, 1e6
k = 1000
while k:
    mid = (low + high) / 2.0
    s = vp * mid
    w = s % d
    w = (w / d) * 2 * pi
    where = p.rotate(Point(0, 0), w)
    md = dist(where, Point(x, y))
    if dblcmp(mid * v - md) >= 0:
        high = mid
    else:
        low = mid
    k -= 1

print(f"{low:.12f}")
