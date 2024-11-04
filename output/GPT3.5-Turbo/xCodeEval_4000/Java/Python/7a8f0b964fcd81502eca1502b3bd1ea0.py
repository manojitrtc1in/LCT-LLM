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

    def inc(self, v):
        self.x += v.x
        self.y += v.y
        return self

    def sub(self, v):
        return Point2D(self.x - v.x, self.y - v.y)

    def dec(self, v):
        self.x -= v.x
        self.y -= v.y
        return self

    def mul(self, K):
        return Point2D(K * self.x, K * self.y)

    def scale(self, K):
        self.x *= K
        self.y *= K
        return self

    def len(self):
        return math.sqrt(self.x * self.x + self.y * self.y)

    def norm(self, newLen=1.0):
        return self.mul(newLen / self.len())

    def normalize(self, newLen=1.0):
        return self.scale(newLen / self.len())

    def scalarProduct(self, v):
        return self.x * v.x + self.y * v.y

    def crossProduct(self, v):
        return self.x * v.y - v.x * self.y

    def rotate90(self):
        return Point2D(-self.y, self.x)

    def rotate(self, angle):
        cos = math.cos(angle)
        sin = math.sin(angle)
        return Point2D(self.x * cos - self.y * sin, self.x * sin + self.y * cos)

    def turn90(self):
        return Point2D(-self.y, self.x)

    def turn(self, angle):
        cos = math.cos(angle)
        sin = math.sin(angle)
        return Point2D(self.x * cos - self.y * sin, self.x * sin + self.y * cos)

    def __eq__(self, other):
        return math.isclose(self.x, other.x, rel_tol=1e-9) and math.isclose(self.y, other.y, rel_tol=1e-9)

    def __str__(self):
        return f"({self.x:.3f}, {self.y:.3f})"

class Line2D:
    def __init__(self, p1=None, p2=None):
        self.p1 = p1
        self.p2 = p2
        self.A = 0.0
        self.B = 0.0
        self.C = 0.0

        if p1 is not None and p2 is not None:
            self.set(p1, p2)

    def set(self, p1, p2):
        self.p1 = p1
        self.p2 = p2
        self.A = p2.y - p1.y
        self.B = p1.x - p2.x
        self.C = -(self.A * p1.x + self.B * p1.y)
        return self

    def move(self, v):
        self.p1.inc(v)
        self.p2.inc(v)
        self.C = -(self.A * self.p1.x + self.B * self.p1.y)
        return self

    def shift(self, r):
        v = self.normal().normalize(r)
        self.p1.dec(v)
        self.p2.dec(v)
        self.C = -(self.A * self.p1.x + self.B * self.p1.y)
        return self

    def calc(self, p):
        return self.A * p.x + self.B * p.y + self.C

    def lay(self, p):
        return math.isclose(self.calc(p), 0.0, rel_tol=1e-9)

    def contains(self, p):
        if not self.lay(p):
            return False
        return 0.0 <= self.getT(p) <= 1.0

    def getT(self, p):
        if not self.lay(p):
            return float('nan')
        if math.isclose(self.A, 0.0, rel_tol=1e-9):
            return (self.p1.x - p.x) / self.B
        if math.isclose(self.B, 0.0, rel_tol=1e-9):
            return (p.y - self.p1.y) / self.A
        raise ValueError("Bad line")

    def getPoint(self, t):
        return Point2D(self.p1.x - self.B * t, self.p1.y + self.A * t)

    def dist(self, p):
        return abs(self.calc(p)) / math.sqrt(self.A * self.A + self.B * self.B)

    def dir(self):
        return Point2D(-self.B, self.A)

    def normal(self):
        return Point2D(self.A, self.B)

    def projection(self, p):
        t = (self.B * (self.p1.x - p.x) - self.A * (self.p1.y - p.y)) / (self.A * self.A + self.B * self.B)
        return Point2D(self.p1.x - self.B * t, self.p1.y + self.A * t)

    def projection(self, l):
        return Line2D(self.projection(l.p1), self.projection(l.p2))

    def __str__(self):
        return f"[{self.p1}, {self.p2}], {self.A:.3f}x + {self.B:.3f}y + {self.C:.3f} = 0"

class Circle2D:
    def __init__(self, c=None, r=0.0):
        self.c = c
        self.r = r

        if c is not None:
            self.set(c, r)

    def set(self, c, r):
        self.c = c
        self.r = r
        return self

    def area(self):
        return math.pi * self.r * self.r

    def lay(self, p):
        return self.r - 1e-9 <= p.len() <= self.r + 1e-9

    def contains(self, p):
        return p.len() < self.r + 1e-9

class Main:
    def __init__(self):
        self.initTime = 0
        self.rnd = random.Random(7777)

    def main(self):
        self.initTime = self.getCurrentTimeMillis()
        self.run()

    def run(self):
        self.solve()

    def solve(self):
        EPS = 1e-7

        pp = Point2D()
        rP = 0.0
        vP = 0.0
        omegaP = 0.0

        ps = Point2D()
        vs = 0.0

        star = Circle2D()

        xp = self.nextDouble()
        yp = self.nextDouble()

        pp.set(xp, yp)
        rP = math.sqrt(xp * xp + yp * yp)
        vP = self.nextDouble()

        ps.set(self.nextDouble(), self.nextDouble())
        vs = self.nextDouble()

        tvp = 1

        vP /= tvp
        vs /= tvp

        omegaP = vP / rP
        star.set(Point2D(0.0, 0.0), self.nextDouble())

        ans = 3e6

        left = 0
        right = ans

        for it in range(10000):
            mid = 0.5 * (left + right)

            if self.can(mid):
                right = mid
                ans = min(ans, mid)
            else:
                left = mid

        self.out.println(ans / tvp)

    def can(self, t):
        return self.distPlanetar(self.ps, self.pp.rotate(t * self.vP / self.rP)) < t * self.vs

    def distPlanetar(self, p1, p2):
        if self.hasCSC(p1, p2, self.star):
            tp1 = self.tppc(p1, self.star)
            tp2 = self.tppc(p2, self.star)

            ret = 1e100

            ret = min(ret, self.distWithStar(p1, p2, tp1[0], tp2[0]))
            ret = min(ret, self.distWithStar(p1, p2, tp1[0], tp2[1]))
            ret = min(ret, self.distWithStar(p1, p2, tp1[1], tp2[0]))
            ret = min(ret, self.distWithStar(p1, p2, tp1[1], tp2[1]))

            return ret

        return self.dist(p1, p2)

    def hasCSC(self, p1, p2, c):
        A = p2.y - p1.y
        B = p1.x - p2.x
        d = A * A + B * B

        dist = 0.0

        if abs(d) < EPS:
            dist = self.dist(p1, c.c)
        else:
            t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d
            if 0.0 <= t <= 1.0:
                dist = math.sqrt(self.sqr(p1.x - B * t - c.c.x) + self.sqr(p1.y + A * t - c.c.y))
            else:
                dist = min(self.dist(p1, c.c), self.dist(p2, c.c))

        return dist <= c.r + EPS

    def distWithStar(self, p1, p2, tp1, tp2):
        phi = math.acos(max(-1.0, min(1.0, tp1.scalarProduct(tp2) / tp1.len() / tp2.len())))
        return self.dist(p1, tp1) + self.dist(p2, tp2) + self.star.r * phi

    def cll(self, l1, l2):
        det = -self.det2x2(l1.A, l1.B, l2.A, l2.B)
        if abs(det) < EPS:
            return None
        return Point2D(self.det2x2(l1.C, l1.B, l2.C, l2.B) / det, self.det2x2(l1.A, l1.C, l2.A, l2.C) / det)

    def css(self, s1, s2):
        its = self.cll(s1, s2)
        return its if its is not None and s1.contains(its) and s2.contains(its) else None

    def clc(self, l, c):
        d = l.dist(c.c)
        if d > c.r + EPS:
            return None
        h = l.projection(c.c)
        v = l.dir().normalize(math.sqrt(c.r * c.r - d * d))
        return [h.sub(v), h.add(v)]

    def ccc(self, c1, c2):
        d = self.dist(c1.c, c2.c)
        if math.isclose(d, 0.0, rel_tol=1e-9) and math.isclose(c1.r, 0.0, rel_tol=1e-9) and math.isclose(c2.r, 0.0, rel_tol=1e-9):
            return [c1.c]
        if d < c1.r - c2.r - EPS or d > c1.r + c2.r + EPS or d < EPS:
            return None
        cos = self.getCos(d, c1.r, c2.r)
        sin = math.sqrt(1.0 - cos * cos)
        v = c2.c.sub(c1.c).normalize(c1.r)
        return [c1.c.add(v.rotate(cos, sin)), c1.c.add(v.rotate(cos, -sin))]

    def tcpc(self, p, c):
        if c.r < EPS or not c.lay(p):
            return None
        n = c.c.sub(p).turn90()
        return Line2D(p.sub(n), p.add(n))

    def tppc(self, p, c):
        d = self.dist(p, c.c)
        cos = c.r / d
        sin = math.sqrt(1.0 - cos * cos)
        v = p.sub(c.c).normalize(c.r)
        return [v.rotate(cos, sin), v.rotate(cos, -sin)]

    def tpc(self, p, c):
        d = self.dist(p, c.c)
        sin = c.r / d
        cos = math.sqrt(1.0 - sin * sin)
        v = c.c.sub(p).normalize(math.sqrt(d * d - c.r * c.r))
        return [Line2D(p, p.add(v.rotate(cos, sin))), Line2D(p, p.add(v.rotate(cos, -sin)))]

    def intcc(self, c1, c2):
        h = self.tpc(c2.c, Circle2D(c1.c, c1.r + c2.r))
        if h is not None:
            h[0].shift(-c1.r)
            h[1].shift(c1.r)
        return h

    def outtcc(self, c1, c2):
        if c1.r > c2.r - EPS:
            return self.outtcc(c2, c1)
        h = self.tpc(c1.c, Circle2D(c2.c, c2.r - c1.r))
        if h is not None:
            h[0].shift(-c1.r)
            h[1].shift(c1.r)
        return h

    def sqr(self, x):
        return x * x

    def det2x2(self, a11, a12, a21, a22):
        return a11 * a22 - a12 * a21

    def cross(self, p0, p1, p2):
        return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y)

    def getCos(self, a, b, c):
        return 0.5 * (a * a + b * b - c * c) / (a * b)

    def getPolarAngle(self, c, p):
        return math.atan2(p.y - c.y, p.x - c.x)

    def distSqr(self, p1, p2):
        return self.sqr(p2.x - p1.x) + self.sqr(p2.y - p1.y)

    def dist(self, p1, p2):
        return math.sqrt(self.distSqr(p1, p2))

    def between(self, a, x, b):
        return a <= x and x <= b

    def range(self, a, x, b):
        return self.between(a - EPS, x, b + EPS)

    def interval(self, a, x, b):
        return self.between(a + EPS, x, b - EPS)

    def sqrt(self, x):
        return math.sqrt(max(0.0, x))

    def acos(self, x):
        return math.acos(max(-1.0, min(1.0, x)))

    def asin(self, x):
        return math.asin(max(-1.0, min(1.0, x)))

    def check(self, state):
        if not state:
            print(sys.exc_info()[2])
            raise RuntimeError()

    def nextToken(self):
        return next(sys.stdin).strip()

    def nextInt(self):
        return int(self.nextToken())

    def nextLong(self):
        return int(self.nextToken())

    def nextDouble(self):
        return float(self.nextToken())

    def nextIntArray(self, size):
        return [self.nextInt() for _ in range(size)]

    def nextLongArray(self, size):
        return [self.nextLong() for _ in range(size)]

    def nextDoubleArray(self, size):
        return [self.nextDouble() for _ in range(size)]

    def nextLine(self):
        return self.nextToken()

    def EOF(self):
        return False

    def printArray(self, array):
        print(' '.join(map(str, array)))

    def printCollection(self, collection):
        print(' '.join(map(str, collection)))

    def getCurrentTimeMillis(self):
        return int(round(time.time() * 1000))

    def main(self):
        self.initTime = self.getCurrentTimeMillis()
        self.run()

    def run(self):
        self.solve()

    def solve(self):
        pass

if __name__ == "__main__":
    Main().main()
