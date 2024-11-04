import sys
import math
import random
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])
Circle = namedtuple('Circle', ['center', 'sqRadius'])
Segment = namedtuple('Segment', ['start', 'end'])

def distance(p1, p2):
    return math.sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)

def squared_distance(p1, p2):
    return (p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2

def intersects(c1, c2):
    d = distance(c1.center, c2.center)
    return d <= math.sqrt(c1.sqRadius + c2.sqRadius)

def solve_intersections(c1, c2):
    d = distance(c1.center, c2.center)
    a = (c1.sqRadius - c2.sqRadius + d ** 2) / (2 * d)
    h = math.sqrt(c1.sqRadius - a ** 2)
    p2 = Point(c2.center.x - c1.center.x, c2.center.y - c1.center.y)
    p2 = Point(p2.x * (a / d), p2.y * (a / d))
    p2 = Point(c1.center.x + p2.x, c1.center.y + p2.y)
    
    x3 = p2.x + h * (c2.center.y - c1.center.y) / d
    y3 = p2.y - h * (c2.center.x - c1.center.x) / d
    x4 = p2.x - h * (c2.center.y - c1.center.y) / d
    y4 = p2.y + h * (c2.center.x - c1.center.x) / d
    
    return (Point(x3, y3), Point(x4, y4))

def angle_between(p1, p2):
    return math.atan2(p2.y, p2.x) - math.atan2(p1.y, p1.x)

def minimum_enclosing_circle(points):
    random.shuffle(points)
    return welzl(points, [], 0)

def welzl(points, boundary, n):
    if n == 0 or len(boundary) == 3:
        if len(boundary) == 0:
            return Circle(Point(0, 0), 0)
        elif len(boundary) == 1:
            return Circle(boundary[0], 0)
        elif len(boundary) == 2:
            return Circle(boundary[0], squared_distance(boundary[0], boundary[1]) / 4)
        elif len(boundary) == 3:
            return Circle(boundary[0], squared_distance(boundary[0], boundary[1]) / 4)  # Simplified for example
    else:
        p = points[n]
        d = welzl(points, boundary, n - 1)
        if squared_distance(d.center, p) <= d.sqRadius:
            return d
        boundary.append(p)
        d = welzl(points, boundary, n - 1)
        boundary.pop()
        return d

class CDeliveringCarcinogen:
    def solve(self, cin, cout):
        XP, YP, VP = map(float, cin.readline().split())
        X, Y, V, R = map(float, cin.readline().split())
        
        Orig = Point(X, Y)
        Zero = Point(0, 0)
        Forbidden = Circle(Zero, R * R)
        
        RR = math.sqrt(XP ** 2 + YP ** 2)
        init = math.atan2(YP, XP)
        
        def check(t):
            angle = (t * VP) / RR
            New = Point(RR * math.cos(angle + init), RR * math.sin(angle + init))
            straight = Segment(New, Orig)
            dist = distance(Zero, New)
            if dist >= R:
                return distance(New, Orig) <= t * V
            else:
                def solve(a, b):
                    ang1 = math.atan2(a.y, a.x)
                    ang2 = math.atan2(b.y, b.x)
                    if ang2 < ang1:
                        ang2 += 2 * math.pi
                    ang = ang2 - ang1
                    if ang > math.pi:
                        ang = 2 * math.pi - ang
                    return distance(Orig, a) + distance(New, b) + ang * R

                Thales1 = Circle(Orig, 0)
                Thales2 = Circle(New, 0)

                Inter1 = solve_intersections(Thales1, Forbidden)
                Inter2 = solve_intersections(Thales2, Forbidden)

                dist = min(solve(Inter1[0], Inter2[0]), solve(Inter1[0], Inter2[1]))
                dist = min(dist, min(solve(Inter1[1], Inter2[0]), solve(Inter1[1], Inter2[1])))
                return dist <= t * V

        low, high = 0.0, 1e5
        while high - low > 1e-9:
            mid = (low + high) / 2
            if check(mid):
                high = mid
            else:
                low = mid
        
        cout.write(f"{high:.10f}\n")

if __name__ == "__main__":
    solver = CDeliveringCarcinogen()
    solver.solve(sys.stdin, sys.stdout)
