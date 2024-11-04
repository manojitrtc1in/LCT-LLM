import math
import sys

MOD = 1000000007
EPS = 1e-2
PI = 3.14159265358979323846264

class Po:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x}, {self.y})"

    def length_sqr(self):
        return self.x ** 2 + self.y ** 2

    def length(self):
        return math.sqrt(self.length_sqr())

    def atan(self):
        return math.atan2(self.y, self.x)

def fmod(x, y):
    return x - y * math.floor(x / y)

def _R(x):
    x = fmod(x, 2 * PI)
    if x < 0:
        x += 2 * PI
    return x

def d(theta, R_, R, r, ss, vs, vp):
    if theta <= beta or theta >= 2 * PI - beta:
        return math.sqrt(R_ ** 2 + R ** 2 - 2 * R_ * R * math.cos(theta))
    else:
        delta = PI - beta - abs(PI - theta)
        return ss + delta * r

def check_f(x, vp, theta, R_, R, r, ss, vs):
    theta = x * vp + alpha
    theta = _R(theta)
    return d(theta, R_, R, r, ss, vs, vp) <= vs * x

def main():
    global alpha, beta, R_, R, r, ss, vs, vp

    input_data = sys.stdin.read().strip().splitlines()
    p = Po(*map(float, input_data[0].split()))
    vp = float(input_data[1])
    s = Po(*map(float, input_data[2].split()))
    vs, r = map(float, input_data[3].split())

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
        if check_f(m, vp, alpha, R_, R, r, ss, vs):
            rr = m
        else:
            ll = m

    print(f"{ll:.10f}")

if __name__ == "__main__":
    main()
