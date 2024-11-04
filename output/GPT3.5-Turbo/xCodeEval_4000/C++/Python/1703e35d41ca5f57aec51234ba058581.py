import cmath
import math

class point(complex):
    def __init__(self, x, y):
        super().__init__(x, y)
    
    def __repr__(self):
        return f"point({self.real}, {self.imag})"
    
    def __str__(self):
        return f"({self.real}, {self.imag})"
    
    def __add__(self, other):
        return point(self.real + other.real, self.imag + other.imag)
    
    def __sub__(self, other):
        return point(self.real - other.real, self.imag - other.imag)
    
    def __mul__(self, other):
        return point(self.real * other.real - self.imag * other.imag, self.real * other.imag + self.imag * other.real)
    
    def __truediv__(self, other):
        return point((self * other.conjugate()).real / (other * other.conjugate()).real, (self * other.conjugate()).imag / (other * other.conjugate()).real)
    
    def __abs__(self):
        return math.hypot(self.imag, self.real)
    
    def __neg__(self):
        return point(-self.real, -self.imag)
    
    def __eq__(self, other):
        return abs(self - other) < EPS
    
    def __ne__(self, other):
        return not self.__eq__(other)
    
    def __lt__(self, other):
        return (self.real, self.imag) < (other.real, other.imag)
    
    def __le__(self, other):
        return (self.real, self.imag) <= (other.real, other.imag)
    
    def __gt__(self, other):
        return (self.real, self.imag) > (other.real, other.imag)
    
    def __ge__(self, other):
        return (self.real, self.imag) >= (other.real, other.imag)
    
    def X(self):
        return self.real
    
    def Y(self):
        return self.imag
    
    def vec(self, other):
        return other - self
    
    def polar(self, r, t):
        return r * cmath.exp(point(0, t))
    
    def angle(self):
        return cmath.phase(self)
    
    def length(self):
        return abs(self)
    
    def lengthSqr(self):
        return self.dot(self)
    
    def dot(self, other):
        return (self * other.conjugate()).real
    
    def cross(self, other):
        return (self * other.conjugate()).imag
    
    def rotate(self, t):
        return self.polar(self.length(), self.angle() + t)
    
    def rotateabout(self, t, a):
        return self.vec(a).rotate(t) + a
    
    def reflect(self, m):
        return (self / m.conjugate()) * m
    
    def normalize(self):
        return self / self.length()
    
    def same(self, other):
        return self.vec(other).lengthSqr() < EPS
    
    def mid(self, other):
        return (self + other) / point(2, 0)
    
    def perp(self):
        return point(-self.imag, self.real)
    
    def colliner(self, other):
        return self.pointOnLine(other)
    
    def pointOnLine(self, a, b):
        return abs(self.cross(self.vec(a, b))) < EPS
    
    def pointOnRay(self, a, b):
        return self.dot(self.vec(a, b)) > -EPS
    
    def pointOnSegment(self, a, b):
        if not self.colliner(a, b):
            return False
        return self.pointOnRay(a, b) and self.pointOnRay(b, a)
    
    def pointLineDist(self, a, b):
        return abs(self.cross(self.vec(a, b))) / self.vec(a, b).length()
    
    def pointSegmentDist(self, a, b):
        if self.dot(self.vec(a, b)) < EPS:
            return self.vec(a, self).length()
        if self.dot(self.vec(b, a)) < EPS:
            return self.vec(b, self).length()
        return self.pointLineDist(a, b)
    
    def segmentLatticePointsCount(self, x1, y1, x2, y2):
        return abs(math.gcd(x1 - x2, y1 - y2)) + 1
    
    def triangleAreaBH(self, b, h):
        return b * h / 2
    
    def triangleArea2sidesAngle(self, a, b, t):
        return abs(a * b * math.sin(t) / 2)
    
    def triangleArea2anglesSide(self, t1, t2, s):
        return abs(s * s * math.sin(t1) * math.sin(t2) / (2 * math.sin(t1 + t2)))
    
    def triangleArea3sides(self, a, b, c):
        s = (a + b + c) / 2
        return math.sqrt(s * (s - a) * (s - b) * (s - c))
    
    def triangleArea3points(self, a, b, c):
        return abs(self.cross(a, b) + self.cross(b, c) + self.cross(c, a)) / 2
    
    def picksTheorm(self, a, b):
        return a - b // 2 + 1
    
    def cosRule(self, a, b, c):
        res = (b * b + c * c - a * a) / (2 * b * c)
        if abs(res - 1) < EPS:
            res = 1
        if abs(res + 1) < EPS:
            res = -1
        return math.acos(res)
    
    def sinRuleAngle(self, s1, s2, a1):
        res = s2 * math.sin(a1) / s1
        if abs(res - 1) < EPS:
            res = 1
        if abs(res + 1) < EPS:
            res = -1
        return math.asin(res)
    
    def sinRuleSide(self, s1, a1, a2):
        return abs(s1 * math.sin(a2) / math.sin(a1))
    
    def circleLineIntersection(self, p0, p1, cen, rad):
        a = self.dot(p1 - p0, p1 - p0)
        b = 2 * self.dot(p1 - p0, p0 - cen)
        c = self.dot(p0 - cen, p0 - cen) - rad * rad
        det = b * b - 4 * a * c
        res = 0
        if abs(det) < EPS:
            det = 0
            res = 1
        elif det < 0:
            res = 0
        else:
            res = 2
        det = math.sqrt(det)
        t1 = (-b + det) / (2 * a)
        t2 = (-b - det) / (2 * a)
        r1 = p0 + t1 * (p1 - p0)
        r2 = p0 + t2 * (p1 - p0)
        return res, r1, r2
    
    def circleCircleIntersection(self, c1, r1, c2, r2):
        if self.same(c1, c2) and abs(r1 - r2) < EPS:
            return [c1], []
        len = self.length(self.vec(c1, c2))
        if abs(len - (r1 + r2)) < EPS or abs(abs(r1 - r2) - len) < EPS:
            d = self.vec(c1, c2)
            c = c1 if r1 > r2 else c2
            r = r1 if r1 > r2 else r2
            return [c + self.normalize(d) * r], []
        if len > r1 + r2 or len < abs(r1 - r2):
            return [], []
        a = self.cosRule(r2, r1, len)
        c1c2 = self.normalize(self.vec(c1, c2)) * r1
        res1 = self.rotate(c1c2, a) + c1
        res2 = self.rotate(c1c2, -a) + c1
        return [res1, res2], []
    
    def circle2(self, p1, p2):
        cen = self.mid(p1, p2)
        r = self.length(self.vec(p1, p2)) / 2
        return cen, r
    
    def circle3(self, p1, p2, p3):
        m1 = self.mid(p1, p2)
        m2 = self.mid(p2, p3)
        perp1 = self.perp(self.vec(p1, p2))
        perp2 = self.perp(self.vec(p2, p3))
        res = self.intersect(m1, m1 + perp1, m2, m2 + perp2)
        return res, self.length(self.vec(res, p1))
    
    def circlePoint(self, cen, r, p):
        lensqr = self.lengthSqr(self.vec(cen, p))
        if abs(lensqr - r * r) < EPS:
            return BOUNDRY
        if lensqr < r * r:
            return IN
        return OUT
    
    def tangentPoints(self, cen, r, p):
        s = self.circlePoint(cen, r, p)
        if s != OUT:
            return [p], [p]
        cp = self.vec(cen, p)
        h = self.length(cp)
        a = self.acos(r / h)
        cp = self.normalize(cp) * r
        r1 = self.rotate(cp, a) + cen
        r2 = self.rotate(cp, -a) + cen
        return [r1, r2]
    
    def polygonArea(self, p):
        res = 0
        for i in range(len(p)):
            j = (i + 1) % len(p)
            res += self.cross(p[i], p[j])
        return abs(res) / 2
    
    def polygonCentroid(self, polygon):
        a = 0
        x = 0.0
        y = 0.0
        for i in range(len(polygon)):
            j = (i + 1) % len(polygon)
            x += (polygon[i].X() + polygon[j].X()) * (polygon[i].X() * polygon[j].Y() - polygon[j].X() * polygon[i].Y())
            y += (polygon[i].Y() + polygon[j].Y()) * (polygon[i].X() * polygon[j].Y() - polygon[j].X() * polygon[i].Y())
            a += polygon[i].X() * polygon[j].Y() - polygon[i].Y() * polygon[j].X()
        a *= 0.5
        x /= 6 * a
        y /= 6 * a
        return point(x, y)
    
    def picksTheorm(self, p):
        area = 0
        bound = 0
        for i in range(len(p)):
            j = (i + 1) % len(p)
            area += self.cross(p[i], p[j])
            v = self.vec(p[i], p[j])
            bound += abs(math.gcd(int(v.X()), int(v.Y())))
        area /= 2
        area = abs(area)
        return round(area - bound / 2 + 1)
    
    def polygonCut(self, p, a, b):
        res = []
        for i in range(len(p)):
            j = (i + 1) % len(p)
            in1 = self.cross(self.vec(a, b), self.vec(a, p[i])) > EPS
            in2 = self.cross(self.vec(a, b), self.vec(a, p[j])) > EPS
            if in1:
                res.append(p[i])
            if in1 ^ in2:
                r = self.intersect(a, b, p[i], p[j])
                res.append(r)
        return res
    
    def convexPolygonIntersect(self, p, q):
        res = q
        for i in range(len(p)):
            j = (i + 1) % len(p)
            temp = self.polygonCut(res, p[i], p[j])
            res = temp
            if not res:
                return []
        return res
    
    def voronoi(self, pnts, rect):
        res = []
        for i in range(len(pnts)):
            res.append(rect)
            for j in range(len(pnts)):
                if j == i:
                    continue
                p = self.perp(self.vec(pnts[i], pnts[j]))
                m = self.mid(pnts[i], pnts[j])
                temp = self.polygonCut(res[-1], m, m + p)
                res[-1] = temp
        return res
    
    def pointInPolygon(self, p, pnt):
        p2 = pnt + point(1, 0)
        cnt = 0
        for i in range(len(p)):
            j = (i + 1) % len(p)
            if self.pointOnSegment(p[i], p[j], pnt):
                return BOUNDRY
            r = self.intersect(pnt, p2, p[i], p[j])
            if not self.pointOnRay(pnt, p2, r):
                continue
            if self.same(r, p[i]) or self.same(r, p[j]):
                if abs(r.Y() - min(p[i].Y(), p[j].Y())) < EPS:
                    continue
            if not self.pointOnSegment(p[i], p[j], r):
                continue
            cnt += 1
        return IN if cnt & 1 else OUT
    
    def sortAntiClockWise(self, pnts):
        mn = point(float('inf'), float('inf'))
        for p in pnts:
            if p < mn:
                mn = p
        pnts.sort(key=lambda x: (x.Y(), x.X()))
        pnts.sort(key=lambda x: self.cross(self.vec(mn, x), self.vec(mn, pnts[1])))
    
    def convexHull(self, pnts):
        self.sortAntiClockWise(pnts)
        convex = [pnts[0]]
        if len(pnts) == 1:
            return convex
        convex.append(pnts[1])
        if len(pnts) == 2:
            if self.same(pnts[0], pnts[1]):
                convex.pop()
            return convex
        for i in range(2, len(pnts) + 1):
            c = pnts[i % len(pnts)]
            while len(convex) > 1:
                b = convex[-1]
                a = convex[-2]
                if self.cross(self.vec(b, a), self.vec(b, c)) < -EPS:
                    break
                convex.pop()
            if i < len(pnts):
                convex.append(pnts[i])
        return convex
    
    def Xc(self):
        return self.real
    
    def Yc(self):
        return self.imag
    
    def Vc(self):
        return self.Vc
    
    def Xb(self):
        return self.Xb
    
    def Yb(self):
        return self.Yb
    
    def Vb(self):
        return self.Vb
    
    def r(self):
        return self.r
    
    def arc_length(self, a, b, r):
        Ang = self.angle(a) - self.angle(b)
        if Ang < 0:
            Ang += 2 * math.pi
        if Ang > math.pi:
            Ang = 2 * math.pi - Ang
        return Ang * r
    
    def main(self):
        Xc, Yc, Vc = self.Xc(), self.Yc(), self.Vc()
        Xb, Yb, Vb, r = self.Xb(), self.Yb(), self.Vb(), self.r()
        planet = point(Xc, Yc)
        ship = point(Xb, Yb)
        R = self.length(planet)
        w = Vc / R
        left = 0
        right = 1 << 30
        for _ in range(300):
            mid = (right + left) / 2
            new_planet = self.rotate(planet, w * mid)
            distance = 0
            if self.pointSegmentDist(ship, new_planet, point(0, 0)) < r:
                a, b, c, d = self.tangentPoints(point(0, 0), r, ship)
                c, d = self.tangentPoints(point(0, 0), r, new_planet)
                distance = 1 << 30
                distance = min(distance, self.length(self.vec(ship, a))
                               + self.length(self.vec(c, new_planet))
                               + self.arc_length(a, c, r))
                distance = min(distance, self.length(self.vec(ship, b))
                               + self.length(self.vec(c, new_planet))
                               + self.arc_length(b, c, r))
                distance = min(distance, self.length(self.vec(ship, a))
                               + self.length(self.vec(d, new_planet))
                               + self.arc_length(a, d, r))
                distance = min(distance, self.length(self.vec(ship, b))
                               + self.length(self.vec(d, new_planet))
                               + self.arc_length(b, d, r))
            else:
                distance = self.length(self.vec(ship, new_planet))
            if distance / Vb < mid:
                right = mid
            else:
                left = mid
        return left
    
print(main())
