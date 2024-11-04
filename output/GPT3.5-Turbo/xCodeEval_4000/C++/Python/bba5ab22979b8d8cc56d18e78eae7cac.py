import math

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __add__(self, q):
        return Point(self.x + q.x, self.y + q.y)

    def __sub__(self, q):
        return Point(self.x - q.x, self.y - q.y)

    def __mul__(self, t):
        return Point(self.x * t, self.y * t)

    def __truediv__(self, t):
        return Point(self.x / t, self.y / t)

    def __eq__(self, q):
        return self.cmp(q) == 0

    def __ne__(self, q):
        return self.cmp(q) != 0

    def __lt__(self, q):
        return self.cmp(q) < 0

    def __str__(self):
        return f"({self.x}, {self.y})"

    def cmp(self, q):
        if (t := math.cmp(self.x, q.x)) != 0:
            return t
        return math.cmp(self.y, q.y)

    def __mod__(self, q):
        return self.x * q.y - self.y * q.x

    def __mul__(self, q):
        return self.x * q.x + self.y * q.y

    def pivot(self):
        return self.pivot

    @staticmethod
    def rotateCCW90(p):
        return Point(-p.y, p.x)

    @staticmethod
    def rotateCW90(p):
        return Point(p.y, -p.x)

    @staticmethod
    def rotateCCW(p, t):
        return Point(p.x * math.cos(t) - p.y * math.sin(t), p.x * math.sin(t) + p.y * math.cos(t))

    @staticmethod
    def projectPointLine(a, b, c):
        return a + (b - a) * ((c - a) * (b - a)) / ((b - a) * (b - a))

    @staticmethod
    def projectPointSegment(a, b, c):
        r = (b - a) * (b - a)
        if math.fabs(r) < EPS:
            return a
        r = (c - a) * (b - a) / r
        if r < 0:
            return a
        if r > 1:
            return b
        return a + (b - a) * r

    @staticmethod
    def between(p, q, r):
        return ccw(p, q, r) == 0 and math.cmp((p - q) * (r - q)) <= 0

    @staticmethod
    def distancePointSegment(a, b, c):
        return math.sqrt(dist2(c, projectPointSegment(a, b, c)))

    @staticmethod
    def distancePointPlane(x, y, z, a, b, c, d):
        return math.fabs(a * x + b * y + c * z - d) / math.sqrt(a * a + b * b + c * c)

    @staticmethod
    def linesParallel(a, b, c, d):
        return math.fabs((b - a) % (c - d)) < EPS

    @staticmethod
    def linesCollinear(a, b, c, d):
        return linesParallel(a, b, c, d) and math.fabs((a - b) % (a - c)) < EPS and math.fabs((c - d) % (c - a)) < EPS

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def line_intersect(p, q, r, s):
        a = q - p
        b = s - r
        c = Point(p % q, r % s)
        return Point(Point(a.x, b.x) % c, Point(a.y, b.y) % c) / (a % b)

    @staticmethod
    def circle2PtsRad(p1, p2, r, c):
        d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)
        det = ((r * r) / d2) - 0.25
        if det < 0.0:
            return False
        h = math.sqrt(det)
        c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h
        c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h
        return True

    @staticmethod
    def computeCircleCenter(a, b, c):
        b = (a + b) / 2
        c = (a + c) / 2
        return line_intersect(b, b + rotateCW90(a - b), c, c + rotateCW90(a - c))

    @staticmethod
    def computeCircleIncenter(a, b, c):
        d = b + rotateCCW(c - b, angle(c, b, a) / 2)
        e = c + rotateCCW(a - c, angle(a, c, b) / 2)
        return line_intersect(b, d, c, e)

    @staticmethod
    def circleLineIntersection(a, b, c, r):
        ret = []
        b = b - a
        a = a - c
        A = b * b
        B = a * b
        C = (a * a) - r * r
        D = B * B - A * C
        if D < -EPS:
            return ret
        ret.append(c + a + b * (-B + math.sqrt(D + EPS)) / A)
        if D > EPS:
            ret.append(c + a + b * (-B - math.sqrt(D)) / A)
        return ret

    @staticmethod
    def circleCircleIntersection(a, b, r, R):
        ret = []
        d = math.sqrt(dist2(a, b))
        if d > r + R or d + min(r, R) < max(r, R):
            return ret
        x = (d * d - R * R + r * r) / (2 * d)
        y = math.sqrt(r * r - x * x)
        v = (b - a) / d
        ret.append(a + v * x + rotateCCW90(v) * y)
        if y > 0:
            ret.append(a + v * x - rotateCCW90(v) * y)
        return ret

    @staticmethod
    def tangentSegments(c, r, p):
        resp = []
        toCenter = c - p
        if math.cmp(r - math.sqrt(dist2(toCenter, Point(0, 0)))) <= 0:
            resp.append(p)
            resp.append(p)
            return resp
        angle = math.asin(r / math.sqrt(dist2(toCenter, Point(0, 0))))
        uni = toCenter / math.sqrt(dist2(toCenter, Point(0, 0)))
        tam = math.sqrt(dist2(toCenter, Point(0, 0)) - r * r)
        origi = uni * tam
        p1 = p + rotateCCW(origi, angle)
        resp.append(p1)
        p2 = p + rotateCCW(origi, -angle)
        resp.append(p2)
        return resp

    @staticmethod
    def in_poly(p, T):
        a = 0
        N = len(T)
        for i in range(N):
            if between(T[i], p, T[(i + 1) % N]):
                return -1
            a += angle(T[i], p, T[(i + 1) % N])
        return math.cmp(a) != 0

    @staticmethod
    def poly_area(T):
        s = 0
        n = len(T)
        for i in range(n):
            s += T[i] % T[(i + 1) % n]
        return s / 2

    @staticmethod
    def computeCentroid(p):
        c = Point(0, 0)
        scale = 6.0 * poly_area(p)
        for i in range(len(p)):
            j = (i + 1) % len(p)
            c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y)
        return c / scale

    @staticmethod
    def radial_lt(p, q):
        P = p - Point.pivot
        Q = q - Point.pivot
        R = P % Q
        if math.cmp(R):
            return R > 0
        return math.cmp(P * P, Q * Q) < 0

    @staticmethod
    def convex_hull(T):
        j = 0
        k = 0
        n = len(T)
        U = [Point(0, 0)] * n
        Point.pivot = min(T)
        T.sort(key=lambda x: Point.radial_lt(x))
        for k in range(n - 2, -1, -1):
            if ccw(T[0], T[n - 1], T[k]) != 0:
                break
        T[(k + 1):] = reversed(T[(k + 1):])
        for i in range(n):
            while j > 1 and ccw(U[j - 1], U[j - 2], T[i]) >= 0:
                j -= 1
            U[j] = T[i]
            j += 1
        U = U[:j]
        return U

    @staticmethod
    def poly_intersect(P, Q):
        m = len(Q)
        n = len(P)
        a = 0
        b = 0
        aa = 0
        ba = 0
        inflag = 0
        R = []
        while (aa < n or ba < m) and aa < 2 * n and ba < 2 * m:
            p1 = P[a]
            p2 = P[(a + 1) % n]
            q1 = Q[b]
            q2 = Q[(b + 1) % m]
            A = p2 - p1
            B = q2 - q1
            cross = math.cmp(A % B)
            ha = ccw(p2, q2, p1)
            hb = ccw(q2, p2, q1)
            if cross == 0 and ccw(p1, q1, p2) == 0 and math.cmp(A * B) < 0:
                if between(p1, q1, p2):
                    R.append(q1)
                if between(p1, q2, p2):
                    R.append(q2)
                if between(q1, p1, q2):
                    R.append(p1)
                if between(q1, p2, q2):
                    R.append(p2)
                if len(R) < 2:
                    return []
                inflag = 1
                break
            elif cross != 0 and seg_intersect(p1, p2, q1, q2):
                if inflag == 0:
                    aa = ba = 0
                R.append(line_intersect(p1, p2, q1, q2))
                inflag = 1 if hb > 0 else -1
            if cross == 0 and hb < 0 and ha < 0:
                return R
            t = cross == 0 and hb == 0 and ha == 0
            if t and (inflag == 1 or cross >= 0 and ha <= 0 or cross < 0 and hb > 0):
                if inflag == -1:
                    R.append(q2)
                ba += 1
                b += 1
                b %= m
            else:
                if inflag == 1:
                    R.append(p2)
                aa += 1
                a += 1
                a %= n
        if inflag == 0:
            if in_poly(P[0], Q):
                return P
            if in_poly(Q[0], P):
                return Q
        R = list(set(R))
        if len(R) > 1 and R[0] == R[-1]:
            R.pop()
        return R

    @staticmethod
    def pode(loc, time):
        nave = Point(x, y)
        if math.cmp(distancePointSegment(loc, nave, origin), r) >= 0:
            return math.cmp(time, abs(nave - loc) / v) >= 0
        else:
            distN = math.sqrt(dist2(nave, origin) - r * r)
            distL = math.sqrt(dist2(loc, origin) - r * r)
            a = abs(nave - loc)
            b = abs(nave)
            c = abs(loc)
            bigcos = (b * b + c * c - a * a) / (2 * b * c)
            angNOL = math.acos(bigcos) - math.fabs(math.atan(distN / r)) - math.fabs(math.atan(distL / r))
            menor = distN + distL + math.fabs(r * angNOL)
            return math.cmp(time, menor / v) >= 0

    EPS = 1e-8
    INF = 10000000
    PI = math.acos(-1)
    angle = lambda p, q, r: math.atan2((p - q) % (r - q), (p - q) * (r - q))
    ccw = lambda p, q, r: math.cmp((p - r) % (q - r))
    dist2 = lambda p, q: ((p - q) * (p - q))
    abs = lambda p: math.hypot(p.x, p.y)
    dist = lambda p, q: math.hypot(p.x - q.x, p.y - q.y)
    polar = lambda p: math.atan2(p.y, p.x)
    rotateCCW90 = lambda p: Point(-p.y, p.x)
    rotateCW90 = lambda p: Point(p.y, -p.x)
    rotateCCW = lambda p, t: Point(p.x * math.cos(t) - p.y * math.sin(t), p.x * math.sin(t) + p.y * math.cos(t))
    rotateCW = lambda p, t: Point(p.x * math.cos(t) + p.y * math.sin(t), -p.x * math.sin(t) + p.y * math.cos(t))
    translate = lambda p, v: Point(p.x + v.x, p.y + v.y)
    scale = lambda p, s: Point(p.x * s, p.y * s)
    dot = lambda p, q: p.x * q.x + p.y * q.y
    cross = lambda p, q: p.x * q.y - p.y * q.x
    collinear = lambda p, q, r: math.cmp(cross(q - p, r - p)) == 0
    ccw_angle = lambda a, b, c: math.acos((b - a) * (c - a) / math.sqrt(dist2(a, b) * dist2(a, c)))
    ccw_angle_points = lambda a, b, c: math.acos((b - a) * (c - a) / math.sqrt(dist2(a, b) * dist2(a, c)))
    ccw_angle_deg = lambda a, b, c: math.degrees(ccw_angle(a, b, c))
    ccw_angle_points_deg = lambda a, b, c: math.degrees(ccw_angle_points(a, b, c))
    ccw_angle_signed = lambda a, b, c: math.atan2(cross(b - a, c - a), dot(b - a, c - a))
    ccw_angle_points_signed = lambda a, b, c: math.atan2(cross(b - a, c - a), dot(b - a, c - a))
    ccw_angle_signed_deg = lambda a, b, c: math.degrees(ccw_angle_signed(a, b, c))
    ccw_angle_points_signed_deg = lambda a, b, c: math.degrees(ccw_angle_points_signed(a, b, c))
    ccw_triangle_area = lambda a, b, c: cross(b - a, c - a) / 2
    ccw_triangle_area_points = lambda a, b, c: cross(b - a, c - a) / 2
    ccw_triangle_area_abs = lambda a, b, c: math.fabs(cross(b - a, c - a) / 2)
    ccw_triangle_area_points_abs = lambda a, b, c: math.fabs(cross(b - a, c - a) / 2)
    ccw_triangle_area_signed = lambda a, b, c: cross(b - a, c - a) / 2
    ccw_triangle_area_points_signed = lambda a, b, c: cross(b - a, c - a) / 2
    ccw_triangle_area_signed_abs = lambda a, b, c: math.fabs(cross(b - a, c - a) / 2)
    ccw_triangle_area_points_signed_abs = lambda a, b, c: math.fabs(cross(b - a, c - a) / 2)
    ccw_quadrilateral_area = lambda a, b, c, d: cross(b - a, d - c) / 2
    ccw_quadrilateral_area_points = lambda a, b, c, d: cross(b - a, d - c) / 2
    ccw_quadrilateral_area_abs = lambda a, b, c, d: math.fabs(cross(b - a, d - c) / 2)
    ccw_quadrilateral_area_points_abs = lambda a, b, c, d: math.fabs(cross(b - a, d - c) / 2)
    ccw_quadrilateral_area_signed = lambda a, b, c, d: cross(b - a, d - c) / 2
    ccw_quadrilateral_area_points_signed = lambda a, b, c, d: cross(b - a, d - c) / 2
    ccw_quadrilateral_area_signed_abs = lambda a, b, c, d: math.fabs(cross(b - a, d - c) / 2)
    ccw_quadrilateral_area_points_signed_abs = lambda a, b, c, d: math.fabs(cross(b - a, d - c) / 2)
    ccw_polygon_area = lambda p: sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2
    ccw_polygon_area_points = lambda p: sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2
    ccw_polygon_area_abs = lambda p: math.fabs(sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2)
    ccw_polygon_area_points_abs = lambda p: math.fabs(sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2)
    ccw_polygon_area_signed = lambda p: sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2
    ccw_polygon_area_points_signed = lambda p: sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2
    ccw_polygon_area_signed_abs = lambda p: math.fabs(sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2)
    ccw_polygon_area_points_signed_abs = lambda p: math.fabs(sum(cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / 2)
    ccw_polygon_centroid = lambda p: sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p))
    ccw_polygon_centroid_points = lambda p: sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p))
    ccw_polygon_centroid_signed = lambda p: sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p))
    ccw_polygon_centroid_points_signed = lambda p: sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p))
    ccw_polygon_centroid_abs = lambda p: math.fabs(sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p)))
    ccw_polygon_centroid_points_abs = lambda p: math.fabs(sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p)))
    ccw_polygon_centroid_signed_abs = lambda p: math.fabs(sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p)))
    ccw_polygon_centroid_points_signed_abs = lambda p: math.fabs(sum((p[i] + p[i + 1]) * cross(p[i], p[i + 1]) for i in range(len(p) - 1)) / (6 * ccw_polygon_area(p)))

    @staticmethod
    def circleLineIntersection(a, b, c, r):
        ret = []
        b = b - a
        a = a - c
        A = b * b
        B = a * b
        C = (a * a) - r * r
        D = B * B - A * C
        if D < -EPS:
            return ret
        ret.append(c + a + b * (-B + math.sqrt(D + EPS)) / A)
        if D > EPS:
            ret.append(c + a + b * (-B - math.sqrt(D)) / A)
        return ret

    @staticmethod
    def circleCircleIntersection(a, b, r, R):
        ret = []
        d = math.sqrt(dist2(a, b))
        if d > r + R or d + min(r, R) < max(r, R):
            return ret
        x = (d * d - R * R + r * r) / (2 * d)
        y = math.sqrt(r * r - x * x)
        v = (b - a) / d
        ret.append(a + v * x + rotateCCW90(v) * y)
        if y > 0:
            ret.append(a + v * x - rotateCCW90(v) * y)
        return ret

    @staticmethod
    def tangentSegments(c, r, p):
        resp = []
        toCenter = c - p
        if math.cmp(r - math.sqrt(dist2(toCenter, Point(0, 0)))) <= 0:
            resp.append(p)
            resp.append(p)
            return resp
        angle = math.asin(r / math.sqrt(dist2(toCenter, Point(0, 0))))
        uni = toCenter / math.sqrt(dist2(toCenter, Point(0, 0)))
        tam = math.sqrt(dist2(toCenter, Point(0, 0)) - r * r)
        origi = uni * tam
        p1 = p + rotateCCW(origi, angle)
        resp.append(p1)
        p2 = p + rotateCCW(origi, -angle)
        resp.append(p2)
        return resp

    @staticmethod
    def in_poly(p, T):
        a = 0
        N = len(T)
        for i in range(N):
            if between(T[i], p, T[(i + 1) % N]):
                return -1
            a += angle(T[i], p, T[(i + 1) % N])
        return math.cmp(a) != 0

    @staticmethod
    def poly_area(T):
        s = 0
        n = len(T)
        for i in range(n):
            s += T[i] % T[(i + 1) % n]
        return s / 2

    @staticmethod
    def computeCentroid(p):
        c = Point(0, 0)
        scale = 6.0 * poly_area(p)
        for i in range(len(p)):
            j = (i + 1) % len(p)
            c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y)
        return c / scale

    @staticmethod
    def radial_lt(p, q):
        P = p - Point.pivot
        Q = q - Point.pivot
        R = P % Q
        if math.cmp(R):
            return R > 0
        return math.cmp(P * P, Q * Q) < 0

    @staticmethod
    def convex_hull(T):
        j = 0
        k = 0
        n = len(T)
        U = [Point(0, 0)] * n
        Point.pivot = min(T)
        T.sort(key=lambda x: Point.radial_lt(x))
        for k in range(n - 2, -1, -1):
            if ccw(T[0], T[n - 1], T[k]) != 0:
                break
        T[(k + 1):] = reversed(T[(k + 1):])
        for i in range(n):
            while j > 1 and ccw(U[j - 1], U[j - 2], T[i]) >= 0:
                j -= 1
            U[j] = T[i]
            j += 1
        U = U[:j]
        return U

    @staticmethod
    def poly_intersect(P, Q):
        m = len(Q)
        n = len(P)
        a = 0
        b = 0
        aa = 0
        ba = 0
        inflag = 0
        R = []
        while (aa < n or ba < m) and aa < 2 * n and ba < 2 * m:
            p1 = P[a]
            p2 = P[(a + 1) % n]
            q1 = Q[b]
            q2 = Q[(b + 1) % m]
            A = p2 - p1
            B = q2 - q1
            cross = math.cmp(A % B)
            ha = ccw(p2, q2, p1)
            hb = ccw(q2, p2, q1)
            if cross == 0 and ccw(p1, q1, p2) == 0 and math.cmp(A * B) < 0:
                if between(p1, q1, p2):
                    R.append(q1)
                if between(p1, q2, p2):
                    R.append(q2)
                if between(q1, p1, q2):
                    R.append(p1)
                if between(q1, p2, q2):
                    R.append(p2)
                if len(R) < 2:
                    return []
                inflag = 1
                break
            elif cross != 0 and seg_intersect(p1, p2, q1, q2):
                if inflag == 0:
                    aa = ba = 0
                R.append(line_intersect(p1, p2, q1, q2))
                inflag = 1
            if cross == 0 and hb < 0 and ha < 0:
                return R
            t = cross == 0 and hb == 0 and ha == 0
            if t and (inflag == 1 or cross >= 0 and ha <= 0 or cross < 0 and hb > 0):
                if inflag == -1:
                    R.append(q2)
                ba += 1
                b += 1
                b %= m
            else:
                if inflag == 1:
                    R.append(p2)
                aa += 1
                a += 1
                a %= n
        if inflag == 0:
            if in_poly(P[0], Q):
                return P
            if in_poly(Q[0], P):
                return Q
        R = list(set(R))
        if len(R) > 1 and R[0] == R[-1]:
            R.pop()
        return R

    @staticmethod
    def distancePointSegment(a, b, c):
        return math.sqrt(dist2(c, projectPointSegment(a, b, c)))

    @staticmethod
    def distancePointPlane(x, y, z, a, b, c, d):
        return math.fabs(a * x + b * y + c * z - d) / math.sqrt(a * a + b * b + c * c)

    @staticmethod
    def linesParallel(a, b, c, d):
        return math.fabs((b - a) % (c - d)) < EPS

    @staticmethod
    def linesCollinear(a, b, c, d):
        return linesParallel(a, b, c, d) and math.fabs((a - b) % (a - c)) < EPS and math.fabs((c - d) % (c - a)) < EPS

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def line_intersect(p, q, r, s):
        a = q - p
        b = s - r
        c = Point(p % q, r % s)
        return Point(Point(a.x, b.x) % c, Point(a.y, b.y) % c) / (a % b)

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

    @staticmethod
    def seg_intersect(p, q, r, s):
        A = q - p
        B = s - r
        C = r - p
        D = s - q
        a = math.cmp(A % C) + 2 * math.cmp(A % D)
        b = math.cmp(B % C) + 2 * math.cmp(B % D)
        if a == 3 or a == -3 or b == 3 or b == -3:
            return False
        if a or b or p == r or p == s or q == r or q == s:
            return True
        t = (p < r) + (p < s) + (q < r) + (q < s)
        return t != 0 and t != 4

EPS = 1e-8
INF = 10000000
PI = math.acos(-1)

def cmp(x, y=0, tol=EPS):
    return (x <= y + tol) - (x + tol < y)

def angle(p, q, r):
    u = p - q
    v = r - q
    return math.atan2(u % v, u * v)

def dist2(p, q):
    return ((p - q) * (p - q))

def rotateCCW90(p):
    return Point(-p.y, p.x)

def rotateCW90(p):
    return Point(p.y, -p.x)

def rotateCCW(p, t):
    return Point(p.x * math.cos(t) - p.y * math.sin(t), p.x * math.sin(t) + p.y * math.cos(t))

def projectPointLine(a, b, c):
    return a + (b - a) * ((c - a) * (b - a)) / ((b - a) * (b - a))

def projectPointSegment(a, b, c):
    r = ((b - a) * (b - a))
    if math.fabs(r) < EPS:
        return a
    r = ((c - a) * (b - a)) / r
    if r < 0:
        return a
    if r > 1:
        return b
    return a + (b - a) * r

def between(p, q, r):
    return ccw(p, q, r) == 0 and cmp((p - q) * (r - q)) <= 0

def distancePointSegment(a, b, c):
    return math.sqrt(dist2(c, projectPointSegment(a, b, c)))

def distancePointPlane(x, y, z, a, b, c, d):
    return math.fabs(a * x + b * y + c * z - d) / math.sqrt(a * a + b * b + c * c)

def linesParallel(a, b, c, d):
    return math.fabs((b - a) % (c - d)) < EPS

def linesCollinear(a, b, c, d):
    return linesParallel(a, b, c, d) and math.fabs((a - b) % (a - c)) < EPS and math.fabs((c - d) % (c - a)) < EPS

def seg_intersect(p, q, r, s):
    A = q - p
    B = s - r
    C = r - p
    D = s - q
    a = cmp(A % C) + 2 * cmp(A % D)
    b = cmp(B % C) + 2 * cmp(B % D)
    if a == 3 or a == -3 or b == 3 or b == -3:
        return False
    if a or b or p == r or p == s or q == r or q == s:
        return True
    t = (p < r) + (p < s) + (q < r) + (q < s)
    return t != 0 and t != 4

def circleLineIntersection(a, b, c, r):
    ret = []
    b = b - a
    a = a - c
    A = b * b
    B = a * b
    C = (a * a) - r * r
    D = B * B - A * C
    if D < -EPS:
        return ret
    ret.append(c + a + b * (-B + math.sqrt(D + EPS)) / A)
    if D > EPS:
        ret.append(c + a + b * (-B - math.sqrt(D)) / A)
    return ret

def circleCircleIntersection(a, b, r, R):
    ret = []
    d = math.sqrt(dist2(a, b))
    if d > r + R or d + min(r, R) < max(r, R):
        return ret
    x = (d * d - R * R + r * r) / (2 * d)
    y = math.sqrt(r * r - x * x)
    v = (b - a) / d
    ret.append(a + v * x + rotateCCW90(v) * y)
    if y > 0:
        ret.append(a + v * x - rotateCCW90(v) * y)
    return ret

def tangentSegments(c, r, p):
    resp = []
    toCenter = c - p
    if cmp(r - math.sqrt(dist2(toCenter, Point(0, 0)))) <= 0:
        resp.append(p)
        resp.append(p)
        return resp
    angle = math.asin(r / math.sqrt(dist2(toCenter, Point(0, 0))))
    uni = toCenter / math.sqrt(dist2(toCenter, Point(0, 0)))
    tam = math.sqrt(dist2(toCenter, Point(0, 0)) - r * r)
    origi = uni * tam
    p1 = p + rotateCCW(origi, angle)
    resp.append(p1)
