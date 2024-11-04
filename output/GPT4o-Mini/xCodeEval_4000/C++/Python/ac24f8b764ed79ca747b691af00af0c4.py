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

def _R(x):
    x = x % (2 * PI)
    if x < 0:
        x += 2 * PI
    return x

def d(theta, R_, R, r, ss, vs, vp):
    if theta <= beta or theta >= 2 * PI - beta:
        return math.sqrt(R_ ** 2 + R ** 2 - 2 * R_ * R * math.cos(theta))
    else:
        delta = PI - beta - abs(PI - theta)
        return ss + delta * r

def f(x, theta, R_, R, r, ss, vs, vp):
    theta = x * vp + alpha
    theta = _R(theta)
    return d(theta, R_, R, r, ss, vs, vp) <= vs * x

def main():
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
    alpha = _R(alpha)
    beta = math.acos(r / R_) + math.acos(r / R)
    beta = _R(beta)

    ll = 0
    rr = (ss + PI * R) * vs

    for _ in range(100):
        m = (ll + rr) / 2
        if f(m, alpha, R_, R, r, ss, vs, vp):
            rr = m
        else:
            ll = m

    print(f"{ll:.10f}")

if __name__ == "__main__":
    main()
