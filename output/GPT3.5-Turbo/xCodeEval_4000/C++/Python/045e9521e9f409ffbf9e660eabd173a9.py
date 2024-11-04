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
        p2 = p1 - p0 * (a / d)
        x3 = p2.x + h * (p1.y - p0.y) / d
        y3 = p2.y - h * (p1.x - p0.x) / d
        x4 = p2.x - h * (p1.y - p0.y) / d
        y4 = p2.y + h * (p1.x - p0.x) / d
        return [Point(x3, y3), Point(x4, y4)]

class CDeliveringCarcinogen:
    def solve(self):
        XP, YP, VP = map(float, input().split())
        X, Y, V, R = map(float, input().split())
        orig = Point(X, Y)
        zero = Point(0, 0)
        forbidden = Circle(zero, R ** 2)
        RR = math.sqrt(XP ** 2 + YP ** 2)
        init = math.atan2(YP, XP)
        low = 0.0
        high = 1e5
        while high - low > 1e-9:
            t = (low + high) / 2
            angle = (t * VP) / RR
            new = Point(RR * math.cos(angle + init), RR * math.sin(angle + init))
            straight = Circle(new, orig)
            dist = straight.distance(zero)
            if dist >= R:
                if straight.distance(orig) <= t * V:
                    low = t
                else:
                    high = t
            else:
                def solve(a, b):
                    ang1 = math.atan2(a.y, a.x)
                    ang2 = math.atan2(b.y, b.x)
                    if ang2 < ang1:
                        ang2 += 2 * math.pi
                    ang = ang2 - ang1
                    if ang > math.pi:
                        ang = 2 * math.pi - ang
                    return orig.distance(a) + new.distance(b) + ang * R

                thales1 = Circle(orig, zero)
                thales2 = Circle(new, zero)
                inter1 = thales1.intersections(forbidden)
                inter2 = thales2.intersections(forbidden)
                dist = min(solve(inter1[0], inter2[0]), solve(inter1[0], inter2[1]))
                dist = min(dist, min(solve(inter1[1], inter2[0]), solve(inter1[1], inter2[1])))
                if dist <= t * V:
                    low = t
                else:
                    high = t
        print("{:.10f}".format(low))

solver = CDeliveringCarcinogen()
solver.solve()
