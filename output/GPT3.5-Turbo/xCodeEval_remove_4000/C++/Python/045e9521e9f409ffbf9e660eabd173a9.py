import math

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __mul__(self, f):
        return Point(self.x * f, self.y * f)

    def squared_distance(self, other):
        return (self.x - other.x) ** 2 + (self.y - other.y) ** 2

    def distance(self, other):
        return math.sqrt(self.squared_distance(other))

class Circle:
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

    def contains(self, point):
        return point.squared_distance(self.center) <= self.radius ** 2

    def intersections(self, other):
        p0 = self.center
        p1 = other.center
        d = p0.distance(p1)
        a = (self.radius ** 2 - other.radius ** 2 + d ** 2) / (2 * d)
        h = math.sqrt(self.radius ** 2 - a ** 2)
        p2 = (p1 - p0) * (a / d) + p0
        x3 = p2.x + h * (p1.y - p0.y) / d
        y3 = p2.y - h * (p1.x - p0.x) / d
        x4 = p2.x - h * (p1.y - p0.y) / d
        y4 = p2.y + h * (p1.x - p0.x) / d
        return [Point(x3, y3), Point(x4, y4)]

class Segment:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def dx(self):
        return self.p1.x - self.p2.x

    def dy(self):
        return self.p1.y - self.p2.y

    def squared_length(self):
        return self.dx() ** 2 + self.dy() ** 2

    def length(self):
        return math.sqrt(self.squared_length())

    def contains(self, point):
        return (point.x <= max(self.p1.x, self.p2.x) and point.x >= min(self.p1.x, self.p2.x) and
                point.y <= max(self.p1.y, self.p2.y) and point.y >= min(self.p1.y, self.p2.y))

    def distance(self, point):
        u = ((point.x - self.p2.x) * self.dx() + (point.y - self.p2.y) * self.dy()) / self.squared_length()
        if u > 1:
            u = 1
        if u < 0:
            u = 0
        proj = Point(self.p2.x + u * self.dx(), self.p2.y + u * self.dy())
        return proj.distance(point)

class CDeliveringCarcinogen:
    def solve(self):
        XP, YP, VP = map(float, input().split())
        X, Y, V, R = map(float, input().split())
        orig = Point(X, Y)
        zero = Point(0, 0)
        forbidden = Circle(zero, R ** 2)
        RR = math.sqrt(XP ** 2 + YP ** 2)
        init = math.atan2(YP, XP)
        t = self.binary_search(0, 1e5, lambda t: self.check(t, VP, RR, init, orig, forbidden, V))
        print("{:.10f}".format(t))

    def check(self, t, VP, RR, init, orig, forbidden, V):
        angle = (t * VP) / RR
        new = Point(RR * math.cos(angle + init), RR * math.sin(angle + init))
        straight = Segment(new, orig)
        dist = straight.distance(zero)
        if dist >= R:
            return straight.length() <= t * V
        else:
            inter1 = forbidden.intersections(Circle(orig, zero))
            inter2 = forbidden.intersections(Circle(new, zero))
            dist = min(self.solve_points(inter1[0], inter2[0], orig, new, R),
                       self.solve_points(inter1[0], inter2[1], orig, new, R))
            dist = min(dist, self.solve_points(inter1[1], inter2[0], orig, new, R))
            dist = min(dist, self.solve_points(inter1[1], inter2[1], orig, new, R))
            return dist <= t * V

    def solve_points(self, a, b, orig, new, R):
        ang1 = math.atan2(a.y, a.x)
        ang2 = math.atan2(b.y, b.x)
        if ang2 < ang1:
            ang2 += 2 * math.pi
        ang = ang2 - ang1
        if ang > math.pi:
            ang = 2 * math.pi - ang
        return orig.distance(a) + new.distance(b) + ang * R

    def binary_search(self, low, high, f):
        while low <= high:
            mid = (low + high) / 2
            if f(mid):
                low = mid + 1
            else:
                high = mid - 1
        return (low + high) / 2

solver = CDeliveringCarcinogen()
solver.solve()
