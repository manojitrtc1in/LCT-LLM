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
        return dblcmp(self.x - other.x) == 0 and dblcmp(self.y - other.y) < 0 or self.x < other.x

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

    def rad(self, a, b):
        c = math.acos((a.sub(self).dot(b.sub(self))) / (a.distance(self) * b.distance(self)))
        return c

    def rotleft(self):
        return Point(-self.y, self.x)

    def rotright(self):
        return Point(self.y, -self.x)

    def rotate(self, p, angle):
        v = self.sub(p)
        c = math.cos(angle)
        s = math.sin(angle)
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c)

class Line:
    def __init__(self, a=None, b=None):
        if a is None and b is None:
            self.a = Point()
            self.b = Point()
        elif isinstance(a, Point) and isinstance(b, Point):
            self.a = a
            self.b = b
        elif isinstance(a, Point) and isinstance(b, float):
            self.a = a
            if dblcmp(b - pi / 2) == 0:
                self.b = self.a.add(Point(0, 1))
            else:
                self.b = self.a.add(Point(1, math.tan(b)))
        else:
            _a, _b, _c = a, b, c
            if dblcmp(_a) == 0:
                self.a = Point(0, -_c / _b)
                self.b = Point(1, -_c / _b)
            elif dblcmp(_b) == 0:
                self.a = Point(-_c / _a, 0)
                self.b = Point(-_c / _a, 1)
            else:
                self.a = Point(0, -_c / _b)
                self.b = Point(1, (-_c - _a) / _b)

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

    def pointonseg(self, p):
        return dblcmp(p.sub(self.a).det(self.b.sub(self.a))) == 0 and dblcmp(p.sub(self.a).dot(p.sub(self.b))) <= 0

    def parallel(self, v):
        return dblcmp(self.b.sub(self.a).det(v.b.sub(v.a))) == 0

    def segcrossseg(self, v):
        d1 = dblcmp(self.b.sub(self.a).det(v.a.sub(self.a)))
        d2 = dblcmp(self.b.sub(self.a).det(v.b.sub(self.a)))
        d3 = dblcmp(v.b.sub(v.a).det(self.a.sub(v.a)))
        d4 = dblcmp(v.b.sub(v.a).det(self.b.sub(v.a)))
        if (d1 ^ d2) == -2 and (d3 ^ d4) == -2:
            return 2
        return (d1 == 0 and dblcmp(v.a.sub(self.a).dot(v.a.sub(self.b))) <= 0 or
                d2 == 0 and dblcmp(v.b.sub(self.a).dot(v.b.sub(self.b))) <= 0 or
                d3 == 0 and dblcmp(self.a.sub(v.a).dot(self.a.sub(v.b))) <= 0 or
                d4 == 0 and dblcmp(self.b.sub(v.a).dot(self.b.sub(v.b))) <= 0)

    def linecrossseg(self, v):
        d1 = dblcmp(self.b.sub(self.a).det(v.a.sub(self.a)))
        d2 = dblcmp(self.b.sub(self.a).det(v.b.sub(self.a)))
        if (d1 ^ d2) == -2:
            return 2
        return (d1 == 0 or d2 == 0)

    def linecrossline(self, v):
        if self.parallel(v):
            return v.relation(self.a) == 3
        return 2

    def crosspoint(self, v):
        a1 = v.b.sub(v.a).det(self.a.sub(v.a))
        a2 = v.b.sub(v.a).det(self.b.sub(v.a))
        return Point((self.a.x * a2 - v.a.x * a1) / (a2 - a1), (self.a.y * a2 - v.a.y * a1) / (a2 - a1))

    def dispointtoline(self, p):
        return abs(p.sub(self.a).det(self.b.sub(self.a))) / self.length()

    def dispointtoseg(self, p):
        if dblcmp(p.sub(self.b).dot(self.a.sub(self.b))) < 0 or dblcmp(p.sub(self.a).dot(self.b.sub(self.a))) < 0:
            return min(p.distance(self.a), p.distance(self.b))
        return self.dispointtoline(p)

    def lineprog(self, p):
        return self.a.add(self.b.sub(self.a).mul(self.b.sub(self.a).dot(p.sub(self.a)) / self.b.sub(self.a).len() ** 2))

    def symmetrypoint(self, p):
        q = self.lineprog(p)
        return Point(2 * q.x - p.x, 2 * q.y - p.y)

class Circle:
    def __init__(self, p=None, r=0):
        if p is None:
            self.p = Point()
            self.r = 0
        else:
            self.p = p
            self.r = r

    def input(self):
        self.p.input()
        self.r = float(input())

    def output(self):
        print(f"{self.p.x:.2f} {self.p.y:.2f} {self.r:.2f}")

    def __eq__(self, other):
        return self.p == other.p and dblcmp(self.r - other.r) == 0

    def __lt__(self, other):
        return self.p < other.p or (self.p == other.p and dblcmp(self.r - other.r) < 0)

    def area(self):
        return pi * self.r ** 2

    def circumference(self):
        return 2 * pi * self.r

    def relation(self, b):
        dst = b.distance(self.p)
        if dblcmp(dst - self.r) < 0:
            return 2
        if dblcmp(dst - self.r) == 0:
            return 1
        return 0

    def relationseg(self, v):
        dst = v.dispointtoseg(self.p)
        if dblcmp(dst - self.r) < 0:
            return 2
        if dblcmp(dst - self.r) == 0:
            return 1
        return 0

    def relationline(self, v):
        dst = v.dispointtoline(self.p)
        if dblcmp(dst - self.r) < 0:
            return 2
        if dblcmp(dst - self.r) == 0:
            return 1
        return 0

    def getcircle(self, a, b, r, c1, c2):
        x = Circle(a, r)
        y = Circle(b, r)
        t = x.pointcrosscircle(y, c1.p, c2.p)
        if not t:
            return 0
        c1.r = c2.r = r
        return t

    def pointcrossline(self, v, p1, p2):
        if not self.relationseg(v):
            return 0
        a = v.lineprog(self.p)
        d = v.dispointtoline(self.p)
        d = math.sqrt(self.r ** 2 - d ** 2)
        if dblcmp(d) == 0:
            p1.x = p2.x = a.x
            p1.y = p2.y = a.y
            return 1
        p1 = a.sub(v.b.sub(v.a).trunc(d))
        p2 = a.add(v.b.sub(v.a).trunc(d))
        return 2

    def relationcircle(self, v):
        d = self.p.distance(v.p)
        if dblcmp(d - self.r - v.r) > 0:
            return 5
        if dblcmp(d - self.r - v.r) == 0:
            return 4
        l = abs(self.r - v.r)
        if dblcmp(d - self.r - v.r) < 0 and dblcmp(d - l) > 0:
            return 3
        if dblcmp(d - l) == 0:
            return 2
        if dblcmp(d - l) < 0:
            return 1

    def pointcrosscircle(self, v, p1, p2):
        rel = self.relationcircle(v)
        if rel == 1 or rel == 5:
            return 0
        d = self.p.distance(v.p)
        l = (d + (self.r ** 2 - v.r ** 2) / d) / 2
        h = math.sqrt(self.r ** 2 - l ** 2)
        p1 = self.p.add(v.p.sub(self.p).trunc(l).add(v.p.sub(self.p).rotleft().trunc(h)))
        p2 = self.p.add(v.p.sub(self.p).trunc(l).add(v.p.sub(self.p).rotright().trunc(h)))
        if rel == 2 or rel == 4:
            return 1
        return 2

    def tangentline(self, q, u, v):
        x = self.relation(q)
        if x == 2:
            return 0
        if x == 1:
            u = Line(q, q.add(q.sub(self.p).rotleft()))
            v = u
            return 1
        d = self.p.distance(q)
        l = self.r ** 2 / d
        h = math.sqrt(self.r ** 2 - l ** 2)
        u = Line(q, self.p.add(q.sub(self.p).trunc(l).add(q.sub(self.p).rotleft().trunc(h))))
        v = Line(q, self.p.add(q.sub(self.p).trunc(l).add(q.sub(self.p).rotright().trunc(h))))
        return 2

    def areacircle(self, v):
        rel = self.relationcircle(v)
        if rel >= 4:
            return 0.0
        if rel <= 2:
            return min(self.area(), v.area())
        d = self.p.distance(v.p)
        hf = (self.r + v.r + d) / 2.0
        ss = 2 * math.sqrt(hf * (hf - self.r) * (hf - v.r) * (hf - d))
        a1 = math.acos((self.r ** 2 + d ** 2 - v.r ** 2) / (2.0 * self.r * d))
        a1 = a1 * self.r ** 2
        a2 = math.acos((v.r ** 2 + d ** 2 - self.r ** 2) / (2.0 * v.r * d))
        a2 = a2 * v.r ** 2
        return a1 + a2 - ss

    def areatriangle(self, a, b):
        if dblcmp(self.p.sub(a).det(self.p.sub(b)) == 0):
            return 0.0
        q = [None] * 5
        len_q = 0
        q[len_q] = a
        l = Line(a, b)
        p1, p2 = Point(), Point()
        if self.pointcrossline(l, q[1], q[2]) == 2:
            if dblcmp(a.sub(q[1]).dot(b.sub(q[1])) < 0):
                q[len_q] = q[1]
            if dblcmp(a.sub(q[2]).dot(b.sub(q[2])) < 0):
                q[len_q] = q[2]
        len_q += 1
        q[len_q] = b
        if len_q == 4 and (dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1]))) > 0):
            q[1], q[2] = q[2], q[1]
        res = 0
        for i in range(len_q - 1):
            if self.relation(q[i]) == 0 or self.relation(q[i + 1]) == 0:
                arg = self.p.rad(q[i], q[i + 1])
                res += self.r ** 2 * arg / 2.0
            else:
                res += abs(q[i].sub(self.p).det(q[i + 1].sub(self.p)) / 2.0)
        return res

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
    p1 = [Point(), Point()]
    p1[0] = l1.b
    p1[1] = l2.b
    c.tangentline(b, l1, l2)
    p2 = [Point(), Point()]
    p2[0] = l1.b
    p2[1] = l2.b
    for i in range(2):
        for j in range(2):
            ds = min(ds, a.distance(p1[i]) + Point(0, 0).rad(p1[i], p2[j]) * r + b.distance(p2[j]))
    return ds

xp, yp, vp = map(float, input().split())
p = Point(xp, yp)
x, y, v, r = map(float, input().split())
c = Circle(Point(0, 0), r)
d = 2 * pi * p.distance(Point(0, 0))
k = 1000
low, high = 0, 1e6

while k > 0:
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
