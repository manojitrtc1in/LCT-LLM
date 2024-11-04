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
        return self.x == q.x and self.y == q.y
    
    def __ne__(self, q):
        return self.x != q.x or self.y != q.y
    
    def __lt__(self, q):
        return self.x < q.x or (self.x == q.x and self.y < q.y)
    
    def __str__(self):
        return f"({self.x}, {self.y})"
    
    def cmp(self, q):
        if self.x < q.x:
            return -1
        elif self.x > q.x:
            return 1
        elif self.y < q.y:
            return -1
        elif self.y > q.y:
            return 1
        else:
            return 0

class Polygon:
    def __init__(self):
        self.points = []
    
    def add_point(self, point):
        self.points.append(point)
    
    def __len__(self):
        return len(self.points)
    
    def __getitem__(self, index):
        return self.points[index]
    
    def __setitem__(self, index, value):
        self.points[index] = value
    
    def __iter__(self):
        return iter(self.points)
    
    def __str__(self):
        return ', '.join(str(point) for point in self.points)

def cmp(x, y=0, tol=1e-8):
    if x <= y + tol:
        if x + tol < y:
            return -1
        else:
            return 0
    else:
        return 1

def ccw(p, q, r):
    return cmp((p-r) % (q-r))

def angle(p, q, r):
    u = p - q
    v = r - q
    return math.atan2(u % v, u * v)

def dist2(p, q):
    return ((p-q) * (p-q))

def rotateCCW90(p):
    return Point(-p.y, p.x)

def rotateCW90(p):
    return Point(p.y, -p.x)

def rotateCCW(p, t):
    return Point(p.x * math.cos(t) - p.y * math.sin(t), p.x * math.sin(t) + p.y * math.cos(t))

def projectPointLine(a, b, c):
    return a + (b-a) * ((c-a)* (b-a))/ ((b-a) * (b-a))

def projectPointSegment(a, b, c):
    r = ((b-a) * (b-a))
    if math.fabs(r) < 1e-8:
        return a
    r = ((c-a) * (b-a))/r
    if r < 0:
        return a
    if r > 1:
        return b
    return a + (b-a)*r

def between(p, q, r):
    return ccw(p, q, r) == 0 and cmp((p - q) * (r - q)) <= 0

def distancePointSegment(a, b, c):
    return math.sqrt(dist2(c, projectPointSegment(a, b, c)))

def distancePointPlane(x, y, z, a, b, c, d):
    return math.fabs(a*x+b*y+c*z-d)/math.sqrt(a*a+b*b+c*c)

def linesParallel(a, b, c, d):
    return math.fabs((b-a) % (c-d)) < 1e-8

def linesCollinear(a, b, c, d):
    return linesParallel(a, b, c, d) and math.fabs((a-b) % (a-c)) < 1e-8 and math.fabs((c-d) % (c-a)) < 1e-8

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

def line_intersect(p, q, r, s):
    a = q - p
    b = s - r
    c = Point(p % q, r % s)
    return Point(Point(a.x, b.x) % c, Point(a.y, b.y) % c) / (a % b)

def circle2PtsRad(p1, p2, r):
    d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)
    det = ((r * r) / d2) - 0.25
    if det < 0.0:
        return False
    h = math.sqrt(det)
    c = Point((p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h, (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h)
    return True, c

def computeCircleCenter(a, b, c):
    b = (a + b) / 2
    c = (a + c) / 2
    return line_intersect(b, b + rotateCW90(a - b), c, c + rotateCW90(a - c))

def computeCircleIncenter(a, b, c):
    d = b + rotateCCW(c - b, angle(c, b, a) / 2)
    e = c + rotateCCW(a - c, angle(a, c, b) / 2)
    return line_intersect(b, d, c, e)

def circleLineIntersection(a, b, c, r):
    ret = []
    b = b - a
    a = a - c
    A = b * b
    B = a * b
    C = (a * a) - r * r
    D = B * B - A * C
    if D < -1e-8:
        return ret
    ret.append(c + a + b * (-B + math.sqrt(D + 1e-8)) / A)
    if D > 1e-8:
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
    p2 = p + rotateCCW(origi, -angle)
    resp.append(p2)
    return resp

def in_poly(p, T):
    a = 0
    N = len(T)
    for i in range(N):
        if between(T[i], p, T[(i+1) % N]):
            return -1
        a += angle(T[i], p, T[(i+1) % N])
    return cmp(a) != 0

def poly_area(T):
    s = 0
    n = len(T)
    for i in range(n):
        s += T[i] % T[(i+1) % n]
    return s / 2

def computeCentroid(p):
    c = Point(0, 0)
    scale = 6.0 * poly_area(p)
    for i in range(len(p)):
        j = (i+1) % len(p)
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y)
    return c / scale

def radial_lt(p, q):
    P = p - Point.pivot
    Q = q - Point.pivot
    R = P % Q
    if cmp(R):
        return R > 0
    return cmp(P * P, Q * Q) < 0

def convex_hull(T):
    j = 0
    k = 0
    n = len(T)
    U = Polygon()
    Point.pivot = min(T)
    T.sort(key=radial_lt)
    for k in range(n-2, -1, -1):
        if ccw(T[0], T[n-1], T[k]) != 0:
            break
    T[k+1:] = reversed(T[k+1:])
    for i in range(n):
        while j > 1 and ccw(U[j-1], U[j-2], T[i]) >= 0:
            j -= 1
        U[j] = T[i]
        j += 1
    U.points = U.points[:j]
    return U

def poly_intersect(P, Q):
    m = len(Q)
    n = len(P)
    a = 0
    b = 0
    aa = 0
    ba = 0
    inflag = 0
    R = Polygon()
    while (aa < n or ba < m) and aa < 2*n and ba < 2*m:
        p1 = P[a]
        p2 = P[(a+1) % n]
        q1 = Q[b]
        q2 = Q[(b+1) % m]
        A = p2 - p1
        B = q2 - q1
        cross = cmp(A % B)
        ha = ccw(p2, q2, p1)
        hb = ccw(q2, p2, q1)
        if cross == 0 and ccw(p1, q1, p2) == 0 and cmp(A * B) < 0:
            if between(p1, q1, p2):
                R.add_point(q1)
            if between(p1, q2, p2):
                R.add_point(q2)
            if between(q1, p1, q2):
                R.add_point(p1)
            if between(q1, p2, q2):
                R.add_point(p2)
            if len(R) < 2:
                return Polygon()
            inflag = 1
            break
        elif cross != 0 and seg_intersect(p1, p2, q1, q2):
            if inflag == 0:
                aa = ba = 0
            R.add_point(line_intersect(p1, p2, q1, q2))
            inflag = 1 if hb > 0 else -1
        if cross == 0 and hb < 0 and ha < 0:
            return R
        t = cross == 0 and hb == 0 and ha == 0
        if t and (inflag == 1 or cross >= 0 and ha <= 0 or cross < 0 and hb > 0):
            if inflag == -1:
                R.add_point(q2)
            ba += 1
            b += 1
            b %= m
        else:
            if inflag == 1:
                R.add_point(p2)
            aa += 1
            a += 1
            a %= n
    if inflag == 0:
        if in_poly(P[0], Q):
            return P
        if in_poly(Q[0], P):
            return Q
    R.points = list(dict.fromkeys(R.points))
    if len(R) > 1 and R[0] == R[-1]:
        R.points.pop()
    return R

INF = 10000000
EPS = 1e-8

def main():
    xp, yp, vp, x, y, v, r = map(int, input().split())
    cont = 1000000
    R = math.hypot(yp, xp)
    initial = math.atan2(yp, xp)
    bot = 0
    timeTot = 1000000.0
    t1 = (2 * math.pi * R) / vp
    top = timeTot
    while top - bot > EPS:
        mid = (top + bot) / 2
        angle = ((2 * math.pi * mid) / t1) + initial
        loc = Point(math.cos(angle) * R, math.sin(angle) * R)
        if pode(loc, mid):
            top = mid - EPS
        else:
            bot = mid + EPS
    print("{:.7f}".format(bot))

if __name__ == "__main__":
    main()
