import sys
import math
import random

class Point2D:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def set(self, x, y):
        self.x = x
        self.y = y
        return self

    def copy(self):
        return Point2D(self.x, self.y)

    def add(self, v):
        return Point2D(self.x + v.x, self.y + v.y)

    def sub(self, v):
        return Point2D(self.x - v.x, self.y - v.y)

    def mul(self, K):
        return Point2D(K * self.x, K * self.y)

    def len(self):
        return math.sqrt(self.x * self.x + self.y * self.y)

    def normalize(self, newLen=1.0):
        return self.mul(newLen / self.len())

    def scalar_product(self, v):
        return self.x * v.x + self.y * v.y

    def rotate(self, angle):
        cos = math.cos(angle)
        sin = math.sin(angle)
        return Point2D(self.x * cos - self.y * sin, self.x * sin + self.y * cos)

    def __eq__(self, other):
        return abs(self.x - other.x) < 1e-7 and abs(self.y - other.y) < 1e-7

    def __str__(self):
        return f"({self.x:.3f}, {self.y:.3f})"


class Circle2D:
    def __init__(self, c, r):
        self.c = c.copy()
        self.r = r

    def area(self):
        return math.pi * self.r * self.r

    def contains(self, p):
        return self.c.dist(p) < self.r + 1e-7


class Line2D:
    def __init__(self, p1, p2):
        self.set(p1.copy(), p2.copy())

    def set(self, p1, p2):
        self.p1 = p1
        self.p2 = p2
        self.A = p2.y - p1.y
        self.B = p1.x - p2.x
        self.C = -(self.A * p1.x + self.B * p1.y)
        return self

    def calc(self, p):
        return self.A * p.x + self.B * p.y + self.C

    def lay(self, p):
        return abs(self.calc(p)) < 1e-7

    def contains(self, p):
        return self.lay(p) and self.get_t(p) >= 0 and self.get_t(p) <= 1

    def get_t(self, p):
        if not self.lay(p):
            return float('nan')
        if abs(self.A) > 1e-7:
            return (p.y - self.p1.y) / self.A
        if abs(self.B) > 1e-7:
            return (self.p1.x - p.x) / self.B
        raise RuntimeError("Bad line")

    def dist(self, p):
        return abs(self.calc(p)) / math.sqrt(self.A * self.A + self.B * self.B)

    def projection(self, p):
        t = (self.B * (self.p1.x - p.x) - self.A * (self.p1.y - p.y)) / (self.A * self.A + self.B * self.B)
        return Point2D(self.p1.x - self.B * t, self.p1.y + self.A * t)


class Main:
    def __init__(self):
        self.EPS = 1e-7
        self.rP = 0.0
        self.vP = 0.0
        self.omegaP = 0.0
        self.vs = 0.0
        self.star = None

    def run(self):
        self.in_file = sys.stdin
        self.out_file = sys.stdout
        self.solve()

    def solve(self):
        xp = self.next_double()
        yp = self.next_double()
        pp = Point2D(xp, yp)
        self.rP = math.sqrt(xp * xp + yp * yp)
        self.vP = self.next_double()
        ps = Point2D(self.next_double(), self.next_double())
        self.vs = self.next_double()

        tvp = 1
        self.vP /= tvp
        self.vs /= tvp
        self.omegaP = self.vP / self.rP
        self.star = Circle2D(Point2D(0.0, 0.0), self.next_double())

        ans = 3e6
        left = 0
        right = ans

        for it in range(10000):
            mid = 0.5 * (left + right)
            if self.can(mid, ps, pp):
                right = mid
                ans = min(ans, mid)
            else:
                left = mid

        self.out_file.write(f"{ans / tvp}\n")

    def can(self, t, ps, pp):
        return self.dist_planetar(ps, pp.rotate(t * self.vP / self.rP)) < t * self.vs

    def dist_planetar(self, p1, p2):
        if self.has_csc(p1, p2, self.star):
            tp1 = self.tppc(p1, self.star)
            tp2 = self.tppc(p2, self.star)
            ret = float('inf')
            ret = min(ret, self.dist_with_star(p1, p2, tp1[0], tp2[0]))
            ret = min(ret, self.dist_with_star(p1, p2, tp1[0], tp2[1]))
            ret = min(ret, self.dist_with_star(p1, p2, tp1[1], tp2[0]))
            ret = min(ret, self.dist_with_star(p1, p2, tp1[1], tp2[1]))
            return ret
        return self.dist(p1, p2)

    def has_csc(self, p1, p2, c):
        A = p2.y - p1.y
        B = p1.x - p2.x
        d = A * A + B * B
        dist = 0.0

        if abs(d) < self.EPS:
            dist = self.dist(p1, c.c)
        else:
            t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d
            if 0.0 <= t <= 1.0:
                dist = math.sqrt(self.sqr(p1.x - B * t - c.c.x) + self.sqr(p1.y + A * t - c.c.y))
            else:
                dist = min(self.dist(p1, c.c), self.dist(p2, c.c))

        return dist <= c.r + self.EPS

    def dist_with_star(self, p1, p2, tp1, tp2):
        phi = math.acos(max(-1.0, min(1.0, tp1.scalar_product(tp2) / tp1.len() / tp2.len())))
        return self.dist(p1, tp1) + self.dist(p2, tp2) + self.star.r * phi

    def dist(self, p1, p2):
        return math.sqrt(self.sqr(p2.x - p1.x) + self.sqr(p2.y - p1.y))

    def sqr(self, x):
        return x * x

    def next_token(self):
        return next(self.tokenizer)

    def next_double(self):
        return float(self.next_token())

    def next_line(self):
        self.tokenizer = iter(self.in_file.readline().strip().split())

if __name__ == "__main__":
    main = Main()
    main.run()
