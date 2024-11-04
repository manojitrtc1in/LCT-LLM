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

    def __repr__(self):
        return f"({self.x}, {self.y})"

    def cmp(self, q):
        if (t := self.cmp(self.x, q.x)) != 0:
            return t
        return self.cmp(self.y, q.y)

    @staticmethod
    def cmp(x, y=0, tol=1e-8):
        if x <= y + tol:
            return -1 if x + tol < y else 0
        return 1

    @staticmethod
    def pivot():
        return Point.pivot

    @staticmethod
    def abs(p):
        return math.hypot(p.x, p.y)

    @staticmethod
    def arg(p):
        return math.atan2(p.y, p.x)


class Polygon:
    def __init__(self, points=[]):
        self.points = points

    def __repr__(self):
        return str(self.points)

    def __len__(self):
        return len(self.points)

    def __getitem__(self, i):
        return self.points[i]

    def __setitem__(self, i, p):
        self.points[i] = p

    def __delitem__(self, i):
        del self.points[i]

    def __iter__(self):
        return iter(self.points)

    def __contains__(self, p):
        return p in self.points

    def append(self, p):
        self.points.append(p)

    def extend(self, points):
        self.points.extend(points)

    def insert(self, i, p):
        self.points.insert(i, p)

    def remove(self, p):
        self.points.remove(p)

    def pop(self, i=-1):
        return self.points.pop(i)

    def index(self, p):
        return self.points.index(p)

    def count(self, p):
        return self.points.count(p)

    def reverse(self):
        self.points.reverse()

    def sort(self, key=None, reverse=False):
        self.points.sort(key=key, reverse=reverse)

    def area(self):
        s = 0
        n = len(self.points)
        for i in range(n):
            s += self.points[i] % self.points[(i+1) % n]
        return s / 2


def ccw(p, q, r):
    return Point.cmp((p-r) % (q-r))


def angle(p, q, r):
    u = p - q
    v = r - q
    return math.atan2(u % v, u * v)


def dist2(p, q):
    return ((p-q) * (p-q))


def id19(p):
    return Point(-p.y, p.x)


def id5(p):
    return Point(p.y, -p.x)


def id14(p, t):
    return Point(p.x*math.cos(t)-p.y*math.sin(t), p.x*math.sin(t)+p.y*math.cos(t))


def id9(a, b, c):
    return a + (b-a)*((c-a)* (b-a))/ ((b-a) * (b-a))


def id20(a, b, c):
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
    return ccw(p, q, r) == 0 and Point.cmp((p - q) * (r - q)) <= 0


def id10(a, b, c):
    return math.sqrt(dist2(c, id20(a, b, c)))


def id2(x, y, z, a, b, c, d):
    return math.fabs(a*x+b*y+c*z-d)/math.sqrt(a*a+b*b+c*c)


def linesParallel(a, b, c, d):
    return math.fabs((b-a) % (c-d)) < 1e-8


def id0(a, b, c, d):
    return linesParallel(a, b, c, d) and math.fabs((a-b) % (a-c)) < 1e-8 and math.fabs((c-d) % (c-a)) < 1e-8


def id13(p, q, r, s):
    A = q - p
    B = s - r
    C = r - p
    D = s - q
    a = Point.cmp(A % C) + 2 * Point.cmp(A % D)
    b = Point.cmp(B % C) + 2 * Point.cmp(B % D)
    if a == 3 or a == -3 or b == 3 or b == -3:
        return False
    if a or b or p == r or p == s or q == r or q == s:
        return True
    t = (p < r) + (p < s) + (q < r) + (q < s)
    return t != 0 and t != 4


def id8(p, q, r, s):
    a = q - p
    b = s - r
    c = Point(p % q, r % s)
    return Point(Point(a.x, b.x) % c, Point(a.y, b.y) % c) / (a % b)


def id1(p1, p2, r, c):
    d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)
    det = ((r * r) / d2) - 0.25
    if det < 0.0:
        return False
    h = math.sqrt(det)
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h
    return True


def id4(a, b, c):
    b = (a + b) / 2
    c = (a + c) / 2
    return id8(b, b+id5(a-b), c, c+id5(a-c))


def id18(a, b, c):
    d = b + id14(c-b, angle(c,b,a)/2)
    e = c + id14(a-c, angle(a,c,b)/2)
    return id8(b, d, c, e)


def id11(a, b, c, r):
    ret = []
    b = b - a
    a = a - c
    A = b * b
    B = a * b
    C = (a * a) - r*r
    D = B*B - A*C
    if D < -1e-8:
        return ret
    ret.append(c+a+b*(-B+math.sqrt(D+1e-8))/A)
    if D > 1e-8:
        ret.append(c+a+b*(-B-math.sqrt(D))/A)
    return ret


def id3(a, b, r, R):
    ret = []
    d = math.sqrt(dist2(a, b))
    if d > r+R or d+min(r, R) < max(r, R):
        return ret
    x = (d*d-R*R+r*r)/(2*d)
    y = math.sqrt(r*r-x*x)
    v = (b-a)/d
    ret.append(a+v*x + id19(v)*y)
    if y > 0:
        ret.append(a+v*x - id19(v)*y)
    return ret


def id7(c, r, p):
    resp = []
    toCenter = c - p
    if Point.cmp(r - math.sqrt(dist2(toCenter, Point(0,0)))) <= 0:
        resp.append(p)
        resp.append(p)
        return resp
    angle = math.asin(r/math.sqrt(dist2(toCenter, Point(0,0))))
    uni = toCenter / math.sqrt(dist2(toCenter, Point(0,0)))
    tam = math.sqrt(dist2(toCenter, Point(0,0)) - r *r)
    origi = uni * tam
    p1 = p + id14(origi, angle)
    resp.append(p1)
    p2 = p + id14(origi, -angle)
    resp.append(p2)
    return resp


def in_poly(p, T):
    a = 0
    N = len(T)
    for i in range(N):
        if between(T[i], p, T[(i+1) % N]):
            return -1
        a += angle(T[i], p, T[(i+1) % N])
    return Point.cmp(a) != 0


def poly_area(T):
    s = 0
    n = len(T)
    for i in range(n):
        s += T[i] % T[(i+1) % n]
    return s / 2


def id17(p):
    c = Point(0, 0)
    scale = 6.0 * poly_area(p)
    for i in range(len(p)):
        j = (i+1) % len(p)
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y)
    return c / scale


def id6(p, q):
    P = p - Point.pivot()
    Q = q - Point.pivot()
    R = P % Q
    if Point.cmp(R):
        return R > 0
    return Point.cmp(P * P, Q * Q) < 0


def id15(T):
    j = 0
    k = 0
    n = len(T)
    U = Polygon([None] * n)
    Point.pivot = min(T)
    T.sort(key=lambda p: id6(p, Point.pivot))
    for k in range(n-2, -1, -1):
        if ccw(T[0], T[n-1], T[k]) != 0:
            break
    T[(k+1):] = reversed(T[(k+1):])
    for i in range(n):
        while j > 1 and ccw(U[j-1], U[j-2], T[i]) >= 0:
            j -= 1
        U[j] = T[i]
        j += 1
    U.points = U.points[:j]
    return U


def id16(P, Q):
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
        cross = Point.cmp(A % B)
        ha = ccw(p2, q2, p1)
        hb = ccw(q2, p2, q1)
        if cross == 0 and ccw(p1, q1, p2) == 0 and Point.cmp(A * B) < 0:
            if between(p1, q1, p2):
                R.append(q1)
            if between(p1, q2, p2):
                R.append(q2)
            if between(q1, p1, q2):
                R.append(p1)
            if between(q1, p2, q2):
                R.append(p2)
            if len(R) < 2:
                return Polygon()
            inflag = 1
            break
        elif cross != 0 and id13(p1, p2, q1, q2):
            if inflag == 0:
                aa = ba = 0
            R.append(id8(p1, p2, q1, q2))
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
    R.points = list(dict.fromkeys(R.points))
    if len(R) > 1 and R[0] == R[-1]:
        R.pop()
    return R


PI = math.acos(-1)


def pode(loc, time):
    nave = Point(x, y)
    if Point.cmp(id10(loc, nave, Point(0, 0)), r) >= 0:
        return Point.cmp(time, Point.abs(nave-loc)/v) >= 0
    else:
        distN = math.sqrt(dist2(nave, Point(0, 0)) - r * r)
        distL = math.sqrt(dist2(loc, Point(0, 0)) - r * r)
        id12 = math.fabs(angle(nave, Point(0, 0), loc)) - math.fabs(math.atan(distN/r)) - math.fabs(math.atan(distL/r))
        menor = distN + distL + math.fabs(r*id12)
        return Point.cmp(time, menor/v) >= 0


xp, yp, vp, x, y, v, r = map(int, input().split())
cont = 1000000
R = math.hypot(yp, xp)
initial = math.atan2(yp, xp)
bot = 0
timeTot = 1000000.0
t1 = (2 * PI * R) / vp
top = timeTot
while top - bot > 1e-8:
    mid = (top + bot) / 2
    angle = ((2 * PI * mid) / t1) + initial
    loc = Point(math.cos(angle) * R, math.sin(angle) * R)
    if pode(loc, mid):
        top = mid - 1e-8
    else:
        bot = mid + 1e-8
print(f"{bot:.7f}")
