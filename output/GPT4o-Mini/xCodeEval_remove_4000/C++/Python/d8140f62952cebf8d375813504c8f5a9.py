import sys
import math

MOD = 1000000007
EPS = 1e-2
PI = 3.14159265358979323846264

def fmod(x, y):
    return x - y * math.floor(x / y)

def _R(x):
    x = fmod(x, 2 * PI)
    if x < 0:
        x += 2 * PI
    return x

class Po:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def input(self):
        self.x, self.y = map(float, sys.stdin.readline().split())

    def length(self):
        return math.sqrt(self.x ** 2 + self.y ** 2)

    def atan(self):
        return math.atan2(self.y, self.x)

    def __sub__(self, other):
        return Po(self.x - other.x, self.y - other.y)

    def __add__(self, other):
        return Po(self.x + other.x, self.y + other.y)

    def __mul__(self, k):
        return Po(self.x * k, self.y * k)

    def __truediv__(self, k):
        return Po(self.x / k, self.y / k)

def d():
    if theta <= beta or theta >= 2 * PI - beta:
        return math.sqrt(R_ ** 2 + R ** 2 - 2 * R_ * R * math.cos(theta))
    else:
        delta = PI - beta - abs(PI - theta)
        return ss + delta * r

def f(x):
    global theta
    theta = x * vp + alpha
    _R(theta)
    return d() <= vs * x

s = Po()
p = Po()
R_ = R = r = ss = vs = vp = alpha = beta = theta = delta = 0

def main():
    global R_, R, r, ss, vs, vp, alpha, beta, theta, delta

    s.input()
    vp = float(sys.stdin.readline())
    p.input()
    vs, r = map(float, sys.stdin.readline().split())

    R_ = s.length()
    R = p.length()
    vp /= R
    ss = math.sqrt(R_ ** 2 - r ** 2) + math.sqrt(R ** 2 - r ** 2)
    alpha = p.atan() - s.atan()
    _R(alpha)
    beta = math.acos(r / R_) + math.acos(r / R)
    _R(beta)

    ll = 0
    rr = 1e10
    for _ in range(1000):
        m = (ll + rr) / 2
        if f(m):
            rr = m
        else:
            ll = m

    print(f"{ll:.10f}")

if __name__ == "__main__":
    main()
