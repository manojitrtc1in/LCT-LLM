import math

class Po:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return math.isclose(self.x, other.x) and math.isclose(self.y, other.y)

    def __ne__(self, other):
        return not self.__eq__(other)

    def __add__(self, other):
        return Po(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Po(self.x - other.x, self.y - other.y)

    def __mul__(self, k):
        return Po(self.x * k, self.y * k)

    def __truediv__(self, k):
        return Po(self.x / k, self.y / k)

    def __neg__(self):
        return Po(-self.x, -self.y)

    def __str__(self):
        return f"({self.x}, {self.y})"

    def length_sqr(self):
        return self.x ** 2 + self.y ** 2

    def length(self):
        return math.sqrt(self.length_sqr())

    def atan(self):
        return math.atan2(self.y, self.x)

    def input(self):
        self.x, self.y = map(float, input().split())

class Line:
    def __init__(self, a=Po(), b=Po()):
        self.a = a
        self.b = b

    def __str__(self):
        return f"{self.a}-{self.b}"

class Seg:
    def __init__(self, a=Po(), b=Po()):
        self.a = a
        self.b = b

    def __str__(self):
        return f"{self.a}-{self.b}"

    def length(self):
        return (self.b - self.a).length()

def dot(x1, y1, x2, y2):
    return x1 * x2 + y1 * y2

def dot(a, b):
    return dot(a.x, a.y, b.x, b.y)

def dot(p0, p1, p2):
    return dot(p1 - p0, p2 - p0)

def dot(l1, l2):
    return dot(l1.b - l1.a, l2.b - l2.a)

def det(x1, y1, x2, y2):
    return x1 * y2 - x2 * y1

def det(a, b):
    return det(a.x, a.y, b.x, b.y)

def det(p0, p1, p2):
    return det(p1 - p0, p2 - p0)

def det(l1, l2):
    return det(l1.b - l1.a, l2.b - l2.a)

def id1(a, b):
    return (a.x - b.x) ** 2 + (a.y - b.y) ** 2

def id1(p, l):
    v0 = l.b - l.a
    v1 = p - l.a
    return (det(v0, v1) ** 2) / v0.length_sqr()

def id1(p, l):
    v0 = l.b - l.a
    v1 = p - l.a
    v2 = p - l.b
    if dot(v0, v1) * dot(v0, v2) <= 0:
        return id1(p, Line(l))
    else:
        return min(v1.length_sqr(), v2.length_sqr())

def id1(l, p):
    return id1(p, l)

def id1(l, p):
    return id1(p, l)

def id1(l1, l2):
    if det(l1, l2) != 0:
        return 0
    return id1(l1.a, l2)

def id1(l1, l2):
    v0 = l1.b - l1.a
    v1 = l2.a - l1.a
    v2 = l2.b - l1.a
    c1 = det(v0, v1)
    c2 = det(v0, v2)
    if c1 * c2 <= 0:
        return 0
    else:
        return min(abs(c1), abs(c2)) ** 2 / v0.length_sqr()

def isIntersect(l1, l2):
    return (
        min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) and
        min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) and
        min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) and
        min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) and
        det(l1.a, l2.a, l2.b) * det(l1.b, l2.a, l2.b) <= 0 and
        det(l2.a, l1.a, l1.b) * det(l2.b, l1.a, l1.b) <= 0
    )

def id1(l1, l2):
    if isIntersect(l1, l2):
        return 0
    else:
        return min(id1(l1.a, l2), id1(l1.b, l2), id1(l2.a, l1), id1(l2.b, l1))

def id0(p, l):
    return p == l.a or p == l.b

def id2(p, l):
    return (
        det(p, l.a, l.b) == 0 and
        l.a.x <= p.x <= l.b.x and
        l.a.y <= p.y <= l.b.y
    )

def intersect(l1, l2):
    return l1.a + (l1.b - l1.a) * (det(l2.a, l1.a, l2.b) / det(l2, l1))

def intersect(p, l):
    return intersect(Line(p, p + Po(l.a.y - l.b.y, l.b.x - l.a.x)), l)

def rotate(p, alpha, o=Po()):
    p.x -= o.x
    p.y -= o.y
    return Po(p.x * math.cos(alpha) - p.y * math.sin(alpha), p.y * math.cos(alpha) + p.x * math.sin(alpha)) + o

def f(x):
    theta = x * vp + alpha
    theta %= 2 * math.pi
    return d() <= vs * x

p = Po()
p.input()
vp = float(input())
s = Po()
s.input()
vs, r = map(float, input().split())

R_ = s.length()
R = p.length()
vp /= R
ss = math.sqrt(R_ ** 2 - r ** 2) + math.sqrt(R ** 2 - r ** 2)
alpha = p.atan() - s.atan()
alpha %= 2 * math.pi
beta = math.acos(r / R_) + math.acos(r / R)
ll = 0
rr = (ss + math.pi * R) * vs
for _ in range(100):
    m = (ll + rr) / 2
    if f(m):
        rr = m
    else:
        ll = m
print(ll)
