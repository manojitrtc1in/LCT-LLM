import math
from collections import namedtuple

EPS = 1e-8
INF = 10000000

def cmp(x, y=0, tol=EPS):
    if x <= y + tol:
        return -1 if x + tol < y else 0
    return 1

Point = namedtuple('Point', ['x', 'y'])

def point_add(p, q):
    return Point(p.x + q.x, p.y + q.y)

def point_sub(p, q):
    return Point(p.x - q.x, p.y - q.y)

def point_mul(p, t):
    return Point(p.x * t, p.y * t)

def point_div(p, t):
    return Point(p.x / t, p.y / t)

def point_dot(p, q):
    return p.x * q.x + p.y * q.y

def point_cross(p, q):
    return p.x * q.y - p.y * q.x

def point_cmp(p, q):
    if t := cmp(p.x, q.x):
        return t
    return cmp(p.y, q.y)

def point_eq(p, q):
    return point_cmp(p, q) == 0

def point_ne(p, q):
    return point_cmp(p, q) != 0

def point_lt(p, q):
    return point_cmp(p, q) < 0

def point_abs(p):
    return math.hypot(p.x, p.y)

def point_arg(p):
    return math.atan2(p.y, p.x)

def ccw(p, q, r):
    return cmp(point_cross(point_sub(p, r), point_sub(q, r))

def angle(p, q, r):
    u = point_sub(p, q)
    v = point_sub(r, q)
    return math.atan2(point_cross(u, v), point_dot(u, v))

def dist2(p, q):
    return point_dot(point_sub(p, q), point_sub(p, q))

def rotate_ccw90(p):
    return Point(-p.y, p.x)

def rotate_cw90(p):
    return Point(p.y, -p.x)

def rotate_ccw(p, t):
    return Point(p.x * math.cos(t) - p.y * math.sin(t), p.x * math.sin(t) + p.y * math.cos(t))

def project_point_line(a, b, c):
    return point_add(a, point_mul(point_sub(b, a), (point_dot(point_sub(c, a), point_sub(b, a)) / dist2(a, b)))

def project_point_segment(a, b, c):
    r = dist2(a, b)
    if abs(r) < EPS:
        return a
    r = point_dot(point_sub(c, a), point_sub(b, a)) / r
    if r < 0:
        return a
    if r > 1:
        return b
    return point_add(a, point_mul(point_sub(b, a), r))

def between(p, q, r):
    return ccw(p, q, r) == 0 and cmp(point_cross(point_sub(p, q), point_sub(r, q))) <= 0

def distance_point_segment(a, b, c):
    return math.sqrt(dist2(c, project_point_segment(a, b, c)))

def distance_point_plane(x, y, z, a, b, c, d):
    return abs(a * x + b * y + c * z - d) / math.sqrt(a * a + b * b + c * c)

def lines_parallel(a, b, c, d):
    return abs(point_cross(point_sub(b, a), point_sub(c, d))) < EPS

def lines_collinear(a, b, c, d):
    return lines_parallel(a, b, c, d) and abs(point_cross(point_sub(a, b), point_sub(a, c))) < EPS and abs(point_cross(point_sub(c, d), point_sub(c, a))) < EPS

def seg_intersect(p, q, r, s):
    A = point_sub(q, p)
    B = point_sub(s, r)
    C = point_sub(r, p)
    D = point_sub(s, q)
    a = cmp(point_cross(A, C)) + 2 * cmp(point_cross(A, D))
    b = cmp(point_cross(B, C)) + 2 * cmp(point_cross(B, D))
    if a == 3 or a == -3 or b == 3 or b == -3:
        return False
    if a or b or point_eq(p, r) or point_eq(p, s) or point_eq(q, r) or point_eq(q, s):
        return True
    t = (point_lt(p, r)) + (point_lt(p, s)) + (point_lt(q, r)) + (point_lt(q, s))
    return t != 0 and t != 4

def line_intersect(p, q, r, s):
    a = point_sub(q, p)
    b = point_sub(s, r)
    c = Point(point_cross(p, q), point_cross(r, s))
    return point_div(Point(point_cross(Point(a.x, b.x), c), point_cross(Point(a.y, b.y), c)), point_cross(a, b))

def circle_2_pts_rad(p1, p2, r):
    d2 = (p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2
    det = (r * r / d2) - 0.25
    if det < 0.0:
        return False, None
    h = math.sqrt(det)
    c = Point((p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h, (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h)
    return True, c

def compute_circle_center(a, b, c):
    b = point_div(point_add(a, b), 2)
    c = point_div(point_add(a, c), 2)
    return line_intersect(b, point_add(b, rotate_cw90(point_sub(a, b))), c, point_add(c, rotate_cw90(point_sub(a, c))))

def compute_circle_incenter(a, b, c):
    d = point_add(b, rotate_ccw(point_sub(c, b), angle(c, b, a) / 2))
    e = point_add(c, rotate_ccw(point_sub(a, c), angle(a, c, b) / 2))
    return line_intersect(b, d, c, e)

def circle_line_intersection(a, b, c, r):
    ret = []
    b = point_sub(b, a)
    a = point_sub(a, c)
    A = point_dot(b, b)
    B = point_dot(a, b)
    C = point_dot(a, a) - r * r
    D = B * B - A * C
    if D < -EPS:
        return ret
    ret.append(point_add(c, point_add(a, point_mul(b, (-B + math.sqrt(D + EPS)) / A)))
    if D > EPS:
        ret.append(point_add(c, point_add(a, point_mul(b, (-B - math.sqrt(D)) / A)))
    return ret

def circle_circle_intersection(a, b, r, R):
    ret = []
    d = math.sqrt(dist2(a, b))
    if d > r + R or d + min(r, R) < max(r, R):
        return ret
    x = (d * d - R * R + r * r) / (2 * d)
    y = math.sqrt(r * r - x * x)
    v = point_div(point_sub(b, a), d)
    ret.append(point_add(a, point_add(point_mul(v, x), rotate_ccw90(v) * y)))
    if y > 0:
        ret.append(point_add(a, point_add(point_mul(v, x), rotate_ccw90(v) * -y)))
    return ret

def tangent_segments(c, r, p):
    resp = []
    to_center = point_sub(c, p)
    if cmp(r - math.sqrt(dist2(to_center, Point(0, 0)))) <= 0:
        resp.append(p)
        resp.append(p)
        return resp
    angle = math.asin(r / math.sqrt(dist2(to_center, Point(0, 0))))
    uni = point_div(to_center, math.sqrt(dist2(to_center, Point(0, 0))))
    tam = math.sqrt(dist2(to_center, Point(0, 0)) - r * r)
    origi = point_mul(uni, tam)
    p1 = point_add(p, rotate_ccw(origi, angle))
    resp.append(p1)
    p2 = point_add(p, rotate_ccw(origi, -angle))
    resp.append(p2)
    return resp

def in_poly(p, T):
    a = 0
    N = len(T)
    for i in range(N):
        if between(T[i], p, T[(i + 1) % N]):
            return -1
        a += angle(T[i], p, T[(i + 1) % N])
    return cmp(a) != 0

def poly_area(T):
    s = 0
    n = len(T)
    for i in range(n):
        s += point_cross(T[i], T[(i + 1) % n])
    return s / 2

def compute_centroid(p):
    c = Point(0, 0)
    scale = 6.0 * poly_area(p)
    for i in range(len(p)):
        j = (i + 1) % len(p)
        c = point_add(c, point_mul(point_add(p[i], p[j]), (p[i].x * p[j].y - p[j].x * p[i].y)))
    return point_div(c, scale)

def radial_lt(p, q):
    P = point_sub(p, Point(0, 0))
    Q = point_sub(q, Point(0, 0))
    R = point_cross(P, Q)
    if cmp(R):
        return R > 0
    return cmp(point_dot(P, P), point_dot(Q, Q)) < 0

def convex_hull(T):
    j = 0
    k = 0
    n = len(T)
    U = [None] * n
    pivot = min(T, key=lambda p: (p.y, p.x))
    T.sort(key=lambda p: (math.atan2(p.y - pivot.y, p.x - pivot.x), point_abs(point_sub(p, pivot))))
    for k in range(n - 2, -1, -1):
        if ccw(T[0], T[n - 1], T[k]) == 0:
            break
    T = T[:k + 1][::-1] + T
    for i in range(n):
        while j > 1 and ccw(U[j - 1], U[j - 2], T[i]) >= 0:
            j -= 1
        U[j] = T[i]
        j += 1
    return U[:j]

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
        A = point_sub(p2, p1)
        B = point_sub(q2, q1)
        cross = cmp(point_cross(A, B))
        ha = ccw(p2, q2, p1)
        hb = ccw(q2, p2, q1)
        if cross == 0 and ccw(p1, q1, p2) == 0 and cmp(point_dot(A, B)) < 0:
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
        if t and inflag == 1 or not t and (cross >= 0 and ha <= 0 or hb > 0):
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
    R = list(dict.fromkeys(R))
    if len(R) > 1 and point_eq(R[0], R[-1]):
        R.pop()
    return R

PI = math.acos(-1)

xp, yp, vp, x, y, v, r = map(int, input().split())
R = math.hypot(yp, xp)
initial = math.atan2(yp, xp)
bot = 0
timeTot = (2 * PI * R) / vp
top = 100000000000000.0

while cmp(top, bot) == 1:
    mid = (top + bot) / 2
    angle = (2 * PI * mid / timeTot) + initial
    loc = Point(math.cos(angle) * R, math.sin(angle) * R)

    if pode(loc, mid):
        top = mid
    else:
        bot = mid

print(f"{bot:.7f}")
