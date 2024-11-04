import math

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

class Line:
    def __init__(self, a=Point(), b=Point()):
        self.a = a
        self.b = b

class Seg:
    def __init__(self, a=Point(), b=Point()):
        self.a = a
        self.b = b

def dot(a, b):
    return a.x * b.x + a.y * b.y

def det(a, b):
    return a.x * b.y - a.y * b.x

def dist_sqr(p, l):
    v0 = Point(l.b.x - l.a.x, l.b.y - l.a.y)
    v1 = Point(p.x - l.a.x, p.y - l.a.y)
    return abs(det(v0, v1)) ** 2 / dot(v0, v0)

def isIntersect(l1, l2):
    return (
        min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) and
        min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) and
        min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) and
        min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) and
        det(l1.a, l2.a, l2.b) * det(l1.b, l2.a, l2.b) <= 0 and
        det(l2.a, l1.a, l1.b) * det(l2.b, l1.a, l1.b) <= 0
    )

def f(x):
    theta = x * vp + alpha
    theta = theta % (2 * math.pi)
    if theta <= beta or theta >= 2 * math.pi - beta:
        return math.sqrt(R_ ** 2 + R ** 2 - 2 * R_ * R * math.cos(theta)) <= vs * x
    else:
        delta = math.pi - beta - abs(math.pi - theta)
        return ss + delta * r <= vs * x

def RD():
    return float(input())

def OT(x):
    print("{:.10f}".format(x))

p = Point()
p.x, p.y = map(float, input().split())
vp = RD()
s = Point()
s.x, s.y = map(float, input().split())
vs, r = map(float, input().split())

R_ = math.sqrt(s.x ** 2 + s.y ** 2)
R = math.sqrt(p.x ** 2 + p.y ** 2)
vp /= R
ss = math.sqrt(R_ ** 2 - r ** 2) + math.sqrt(R ** 2 - r ** 2)
alpha = math.atan2(p.y, p.x) - math.atan2(s.y, s.x)
alpha = alpha % (2 * math.pi)
beta = math.acos(r / R_) + math.acos(r / R)
beta = beta % (2 * math.pi)

ll = 0
rr = (ss + math.pi * R) * vs
for i in range(100):
    m = (ll + rr) / 2
    if f(m):
        rr = m
    else:
        ll = m

OT(ll)
