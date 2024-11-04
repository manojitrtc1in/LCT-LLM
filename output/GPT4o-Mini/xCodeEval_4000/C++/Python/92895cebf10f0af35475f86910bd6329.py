import math
import sys

MOD = 1000000007
EPS = 1e-2
PI = 3.14159265358979323846264

class Po:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __sub__(self, other):
        return Po(self.x - other.x, self.y - other.y)

    def __add__(self, other):
        return Po(self.x + other.x, self.y + other.y)

    def __mul__(self, k):
        return Po(self.x * k, self.y * k)

    def length_sqr(self):
        return self.x ** 2 + self.y ** 2

    def length(self):
        return math.sqrt(self.length_sqr())

    def atan(self):
        return math.atan2(self.y, self.x)

    def input(self):
        self.x, self.y = map(float, input().split())

def sgn(x):
    return -1 if x < -EPS else (1 if x > EPS else 0)

def dist_sqr(a, b):
    return (a.x - b.x) ** 2 + (a.y - b.y) ** 2

def isIntersect(l1, l2):
    return (
        min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) and
        min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) and
        min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) and
        min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) and
        sgn(det(l1.a, l2.a, l2.b)) * sgn(det(l1.b, l2.a, l2.b)) <= 0 and
        sgn(det(l2.a, l1.a, l1.b)) * sgn(det(l2.b, l1.a, l1.b)) <= 0
    )

def det(a, b, c):
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)

def d():
    if theta <= beta or theta >= 2 * PI - beta:
        return math.sqrt(R_ ** 2 + R ** 2 - 2 * R_ * R * math.cos(theta))
    else:
        delta = PI - beta - abs(PI - theta)
        return ss + delta * r

def f(x):
    global theta
    theta = x * vp + alpha
    theta = theta % (2 * PI)
    return d() <= vs * x

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    
    p = Po()
    p.input()
    vp = float(data[1])
    s = Po()
    s.input()
    vs, r = map(float, data[2].split())

    R_ = s.length()
    R = p.length()
    vp /= R
    ss = math.sqrt(R_ ** 2 - r ** 2) + math.sqrt(R ** 2 - r ** 2)
    alpha = p.atan() - s.atan()
    alpha = alpha % (2 * PI)
    beta = math.acos(r / R_) + math.acos(r / R)
    beta = beta % (2 * PI)

    ll = 0
    rr = (ss + PI * R) * vs
    for _ in range(200):
        m = (ll + rr) / 2
        if f(m):
            rr = m
        else:
            ll = m
    print(f"{ll:.10f}")
