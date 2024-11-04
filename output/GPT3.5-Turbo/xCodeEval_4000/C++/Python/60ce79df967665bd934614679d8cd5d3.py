import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def distance(self, p):
        return math.sqrt((self.x - p.x)**2 + (self.y - p.y)**2)
    
    def rotate(self, p, angle):
        cos_angle = math.cos(angle)
        sin_angle = math.sin(angle)
        x = p.x + (self.x - p.x) * cos_angle - (self.y - p.y) * sin_angle
        y = p.y + (self.x - p.x) * sin_angle + (self.y - p.y) * cos_angle
        return Point(x, y)

class Circle:
    def __init__(self, p, r):
        self.p = p
        self.r = r
    
    def distance(self, p):
        return self.p.distance(p) - self.r
    
    def point_cross_line(self, line):
        d = line.distance(self.p)
        if d > self.r:
            return []
        elif d == self.r:
            return [line.line_prog(self.p)]
        else:
            h = math.sqrt(self.r**2 - d**2)
            p1 = line.line_prog(self.p).add(line.b.sub(line.a).trunc(h))
            p2 = line.line_prog(self.p).add(line.b.sub(line.a).trunc(-h))
            return [p1, p2]
    
    def tangent_line(self, p):
        d = self.p.distance(p)
        if d < self.r:
            return []
        elif d == self.r:
            return [Line(p, p)]
        else:
            l = math.sqrt(d**2 - self.r**2)
            angle = math.atan2(self.p.y - p.y, self.p.x - p.x)
            p1 = p.add(Point(math.cos(angle + math.pi/2) * l, math.sin(angle + math.pi/2) * l))
            p2 = p.add(Point(math.cos(angle - math.pi/2) * l, math.sin(angle - math.pi/2) * l))
            return [Line(p, p1), Line(p, p2)]

class Line:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    
    def distance(self, p):
        return abs((self.b.x - self.a.x) * (self.a.y - p.y) - (self.a.x - p.x) * (self.b.y - self.a.y)) / self.length()
    
    def line_prog(self, p):
        length = self.length()
        return Point(self.a.x + (self.b.x - self.a.x) * ((p.x - self.a.x) * (self.b.x - self.a.x) + (p.y - self.a.y) * (self.b.y - self.a.y)) / length**2,
                     self.a.y + (self.b.y - self.a.y) * ((p.x - self.a.x) * (self.b.x - self.a.x) + (p.y - self.a.y) * (self.b.y - self.a.y)) / length**2)
    
    def length(self):
        return self.a.distance(self.b)

def dist(a, b, c):
    line = Line(a, b)
    p1, p2 = c.point_cross_line(line)
    if not p1:
        return a.distance(b)
    rd = Point(0, 0).rotate(p1, p2).distance(p2)
    rd = min(rd, 2 * math.pi - rd)
    ds = a.distance(b) - p1.distance(p2) + rd * c.r
    l1, l2 = c.tangent_line(a)
    p1 = [l.b for l in l1]
    p2 = [l.b for l in l2]
    for i in range(2):
        for j in range(2):
            ds = min(ds, a.distance(p1[i]) + Point(0, 0).rotate(p1[i], p2[j]).distance(p2[j]) * c.r + b.distance(p2[j]))
    return ds

xp, yp, vp = map(float, input().split())
p = Point(xp, yp)
x, y, v, r = map(float, input().split())
c = Circle(Point(0, 0), r)

d = 2 * math.pi * p.distance(Point(0, 0))
k = 1000
low, high = 0, 1e6
while k > 0:
    mid = (low + high) / 2
    s = vp * mid
    w = s % d
    w = (w / d) * 2 * math.pi
    where = p.rotate(Point(0, 0), w)
    md = dist(where, Point(x, y), c)
    if mid * v - md >= 0:
        high = mid
    else:
        low = mid
    k -= 1

print("{:.12f}".format(low))
