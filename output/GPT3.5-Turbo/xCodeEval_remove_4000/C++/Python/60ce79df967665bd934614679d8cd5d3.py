import math

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
        print("{:.12f} {:.12f}".format(self.x, self.y))
    
    def __eq__(self, other):
        return dblcmp(other.x - self.x) == 0 and dblcmp(other.y - self.y) == 0
    
    def __lt__(self, other):
        return dblcmp(other.x - self.x) == 0 and dblcmp(self.y - other.y) < 0 or self.x < other.x
    
    def len(self):
        return math.hypot(self.x, self.y)
    
    def len2(self):
        return self.x * self.x + self.y * self.y
    
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
        p = self
        c = math.acos((a.sub(p).dot(b.sub(p))) / (a.distance(p) * b.distance(p)))
        return c
    
    def trunc(self, r):
        l = self.len()
        if not dblcmp(l):
            return self
        r /= l
        return Point(self.x * r, self.y * r)
    
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
    def __init__(self, a=Point(), b=Point()):
        self.a = a
        self.b = b
    
    def __eq__(self, other):
        return self.a == other.a and self.b == other.b
    
    def __init__(self, p, angle):
        self.a = p
        if dblcmp(angle - pi / 2) == 0:
            self.b = self.a.add(Point(0, 1))
        else:
            self.b = self.a.add(Point(1, math.tan(angle)))
    
    def __init__(self, a, b, c):
        if dblcmp(a) == 0:
            self.a = Point(0, -c / b)
            self.b = Point(1, -c / b)
        elif dblcmp(b) == 0:
            self.a = Point(-c / a, 0)
            self.b = Point(-c / a, 1)
        else:
            self.a = Point(0, -c / b)
            self.b = Point(1, (-c - a) / b)
    
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
        return d1 == 0 or d2 == 0
    
    def linecrossline(self, v):
        if self.parallel(v):
            return v.relation(self.a) == 3
        return 2
    
    def crosspoint(self, v):
        a1 = v.b.sub(v.a).det(self.a.sub(v.a))
        a2 = v.b.sub(v.a).det(self.b.sub(v.a))
        return Point((self.a.x * a2 - self.b.x * a1) / (a2 - a1), (self.a.y * a2 - self.b.y * a1) / (a2 - a1))
    
    def dispointtoline(self, p):
        return abs(p.sub(self.a).det(self.b.sub(self.a))) / self.length()
    
    def dispointtoseg(self, p):
        if dblcmp(p.sub(self.b).dot(self.a.sub(self.b))) < 0 or dblcmp(p.sub(self.a).dot(self.b.sub(self.a))) < 0:
            return min(p.distance(self.a), p.distance(self.b))
        return self.dispointtoline(p)
    
    def lineprog(self, p):
        return self.a.add(self.b.sub(self.a).mul(self.b.sub(self.a).dot(p.sub(self.a)) / self.b.sub(self.a).len2()))
    
    def symmetrypoint(self, p):
        q = self.lineprog(p)
        return Point(2 * q.x - p.x, 2 * q.y - p.y)

class Circle:
    def __init__(self, p=Point(), r=0):
        self.p = p
        self.r = r
    
    def __init__(self, x=0, y=0, r=0):
        self.p = Point(x, y)
        self.r = r
    
    def __init__(self, a, b, c):
        self.p = Line(a.add(b).div(2), a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(Line(c.add(b).div(2), c.add(b).div(2).add(b.sub(c).rotleft())))
        self.r = self.p.distance(a)
    
    def __init__(self, a, b, c, t):
        u, v = Line(), Line()
        m = math.atan2(b.y - a.y, b.x - a.x)
        n = math.atan2(c.y - a.y, c.x - a.x)
        u.a = a
        u.b = u.a.add(Point(math.cos((n + m) / 2), math.sin((n + m) / 2)))
        v.a = b
        m = math.atan2(a.y - b.y, a.x - b.x)
        n = math.atan2(c.y - b.y, c.x - b.x)
        v.b = v.a.add(Point(math.cos((n + m) / 2), math.sin((n + m) / 2)))
        self.p = u.crosspoint(v)
        self.r = Line(a, b).dispointtoseg(self.p)
    
    def input(self):
        self.p.input()
        self.r = float(input())
    
    def output(self):
        print("{:.2f} {:.2f} {:.2f}".format(self.p.x, self.p.y, self.r))
    
    def __eq__(self, other):
        return self.p == other.p and dblcmp(self.r - other.r) == 0
    
    def __lt__(self, other):
        return self.p < other.p or (self.p == other.p and dblcmp(self.r - other.r) < 0)
    
    def area(self):
        return pi * self.r * self.r
    
    def circumference(self):
        return 2 * pi * self.r
    
    def relation(self, b):
        d = self.p.distance(b)
        if dblcmp(d - self.r) < 0:
            return 2
        if dblcmp(d - self.r) == 0:
            return 1
        return 0
    
    def relationseg(self, v):
        d = v.dispointtoseg(self.p)
        if dblcmp(d - self.r) < 0:
            return 2
        if dblcmp(d - self.r) == 0:
            return 1
        return 0
    
    def relationline(self, v):
        d = v.dispointtoline(self.p)
        if dblcmp(d - self.r) < 0:
            return 2
        if dblcmp(d - self.r) == 0:
            return 1
        return 0
    
    def getcircle(self, a, b, r, c1, c2):
        x = Circle(a, r + a.r)
        y = Circle(b, r + b.r)
        t = x.pointcrosscircle(y, c1.p, c2.p)
        if not t:
            return 0
        c1.r = c2.r = r
        return t
    
    def getcircle(self, u, q, r1, c1, c2):
        dis = u.dispointtoline(q)
        if dblcmp(dis - r1 * 2) > 0:
            return 0
        if dblcmp(dis) == 0:
            c1.p = q.add(u.b.sub(u.a).rotleft().trunc(r1))
            c2.p = q.add(u.b.sub(u.a).rotright().trunc(r1))
            c1.r = c2.r = r1
            return 2
        u1 = Line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)), u.b.add(u.b.sub(u.a).rotleft().trunc(r1)))
        u2 = Line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)), u.b.add(u.b.sub(u.a).rotright().trunc(r1)))
        cc = Circle(q, r1)
        p1, p2 = Point(), Point()
        if not cc.pointcrossline(u1, p1, p2):
            cc.pointcrossline(u2, p1, p2)
        c1 = Circle(p1, r1)
        if p1 == p2:
            c2 = c1
            return 1
        c2 = Circle(p2, r1)
        return 2
    
    def getcircle(self, u, v, r1, c1, c2, c3, c4):
        if u.parallel(v):
            return 0
        u1 = Line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)), u.b.add(u.b.sub(u.a).rotleft().trunc(r1)))
        u2 = Line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)), u.b.add(u.b.sub(u.a).rotright().trunc(r1)))
        v1 = Line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)), v.b.add(v.b.sub(v.a).rotleft().trunc(r1)))
        v2 = Line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)), v.b.add(v.b.sub(v.a).rotright().trunc(r1)))
        c1.r = c2.r = c3.r = c4.r = r1
        c1.p = u1.crosspoint(v1)
        c2.p = u1.crosspoint(v2)
        c3.p = u2.crosspoint(v1)
        c4.p = u2.crosspoint(v2)
        return 4
    
    def getcircle(self, cx, cy, r1, c1, c2):
        x = Circle(cx.p, r1 + cx.r)
        y = Circle(cy.p, r1 + cy.r)
        t = x.pointcrosscircle(y, c1.p, c2.p)
        if not t:
            return 0
        c1.r = c2.r = r1
        return t
    
    def pointcrossline(self, v, p1, p2):
        if not self.relationseg(v):
            return 0
        a = v.lineprog(self.p)
        d = v.dispointtoline(self.p)
        d = math.sqrt(self.r * self.r - d * d)
        if dblcmp(d) == 0:
            p1 = a
            p2 = a
            return 1
        p1 = a.sub(v.b.sub(v.a).trunc(d))
        p2 = a.add(v.b.sub(v.a).trunc(d))
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
        l = sqr(self.r) / d
        h = math.sqrt(sqr(self.r) - sqr(l))
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
        a1 = math.acos((self.r * self.r + d * d - v.r * v.r) / (2.0 * self.r * d))
        a1 = a1 * self.r * self.r
        a2 = math.acos((v.r * v.r + d * d - self.r * self.r) / (2.0 * v.r * d))
        a2 = a2 * v.r * v.r
        return a1 + a2 - ss
    
    def areatriangle(self, a, b):
        if dblcmp(self.p.sub(a).det(self.p.sub(b))) == 0:
            return 0.0
        q = [Point() for _ in range(5)]
        len = 0
        q[len] = a
        l = Line(a, b)
        p1, p2 = Point(), Point()
        if l.pointcrossline(self, p1, p2) == 2:
            if dblcmp(a.sub(p1).dot(b.sub(p1))) < 0:
                q[len] = p1
                len += 1
            if dblcmp(a.sub(p2).dot(b.sub(p2))) < 0:
                q[len] = p2
                len += 1
        q[len] = b
        if len == 4 and dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1]))) > 0:
            q[1], q[2] = q[2], q[1]
        res = 0
        for i in range(len - 1):
            if self.relation(q[i]) == 0 or self.relation(q[i + 1]) == 0:
                arg = self.p.rad(q[i], q[i + 1])
                res += self.r * self.r * arg / 2.0
            else:
                res += abs(q[i].sub(self.p).det(q[i + 1].sub(self.p))) / 2.0
        return res

def dist(a, b):
    l = Line(a, b)
    p11, p12 = Point(), Point()
    if not c.pointcrossline(l, p11, p12):
        return a.distance(b)
    rd = Point(0, 0).rad(p11, p12)
    rd = min(rd, 2 * pi - rd)
    ds = a.distance(b) - p11.distance(p12) + rd * c.r
    l1, l2 = Line(), Line()
    c.tangentline(a, l1, l2)
    p1 = [Point() for _ in range(3)]
    p1[0] = l1.b
    p1[1] = l2.b
    c.tangentline(b, l1, l2)
    p2 = [Point() for _ in range(3)]
    p2[0] = l1.b
    p2[1] = l2.b
    for i in range(2):
        for j in range(2):
            ds = min(ds, a.distance(p1[i]) + Point(0, 0).rad(p1[i], p2[j]) * c.r + b.distance(p2[j]))
    return ds

xp, yp, vp = map(float, input().split())
p = Point(xp, yp)
x, y, v, r = map(float, input().split())
c = Circle(0, 0, r)
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
print("{:.12f}".format(low))
