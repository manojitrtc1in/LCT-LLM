import math
from collections import namedtuple

INF = 10000000
EPS = 1e-8

def cmp(x, y=0, tol=EPS):
    if x <= y + tol:
        return -1 if x + tol < y else 0
    return 1

Point = namedtuple('Point', ['x', 'y'])

def point(x=0, y=0):
    return Point(x, y)

def add(p, q):
    return point(p.x + q.x, p.y + q.y)

def sub(p, q):
    return point(p.x - q.x, p.y - q.y)

def mul(p, t):
    return point(p.x * t, p.y * t)

def div(p, t):
    return point(p.x / t, p.y / t)

def dot(p, q):
    return p.x * q.x + p.y * q.y

def cross(p, q):
    return p.x * q.y - p.y * q.x

def cmp_point(p, q):
    if t := cmp(p.x, q.x):
        return t
    return cmp(p.y, q.y)

def eq(p, q):
    return cmp_point(p, q) == 0

def ne(p, q):
    return cmp_point(p, q) != 0

def lt(p, q):
    return cmp_point(p, q) < 0

def abs_point(p):
    return math.hypot(p.x, p.y)

def arg(p):
    return math.atan2(p.y, p.x)

def ccw(p, q, r):
    return cmp(cross(sub(p, r), sub(q, r)))

def angle(p, q, r):
    u = sub(p, q)
    v = sub(r, q)
    return math.atan2(cross(u, v), dot(u, v))

def dist2(p, q):
    return dot(sub(p, q), sub(p, q))

def id19(p):
    return point(-p.y, p.x)

def id5(p):
    return point(p.y, -p.x)

def id14(p, t):
    return point(p.x * math.cos(t) - p.y * math.sin(t), p.x * math.sin(t) + p.y * math.cos(t))

def id9(a, b, c):
    return add(a, mul(sub(b, a), dot(sub(c, a), sub(b, a)) / dot(sub(b, a), sub(b, a))))

def id20(a, b, c):
    r = dot(sub(b, a), sub(b, a))
    if abs(r) < EPS:
        return a
    r = dot(sub(c, a), sub(b, a)) / r
    if r < 0:
        return a
    if r > 1:
        return b
    return add(a, mul(sub(b, a), r))

def between(p, q, r):
    return ccw(p, q, r) == 0 and cmp(dot(sub(p, q), sub(r, q))) <= 0

def id10(a, b, c):
    return math.sqrt(dist2(c, id20(a, b, c)))

def id2(x, y, z, a, b, c, d):
    return abs(a * x + b * y + c * z - d) / math.sqrt(a * a + b * b + c * c)

def lines_parallel(a, b, c, d):
    return abs(cross(sub(b, a), sub(c, d))) < EPS

def id0(a, b, c, d):
    return lines_parallel(a, b, c, d) and abs(cross(sub(a, b), sub(a, c))) < EPS and abs(cross(sub(c, d), sub(c, a))) < EPS

def id13(p, q, r, s):
    A = sub(q, p)
    B = sub(s, r)
    C = sub(r, p)
    D = sub(s, q)
    a = cmp(cross(A, C)) + 2 * cmp(cross(A, D))
    b = cmp(cross(B, C)) + 2 * cmp(cross(B, D))
    if a == 3 or a == -3 or b == 3 or b == -3:
        return False
    if a or b or eq(p, r) or eq(p, s) or eq(q, r) or eq(q, s):
        return True
    t = (lt(p, r)) + (lt(p, s)) + (lt(q, r)) + (lt(q, s))
    return t != 0 and t != 4

def id8(p, q, r, s):
    a = sub(q, p)
    b = sub(s, r)
    c = point(cross(p, q), cross(r, s))
    return div(point(cross(Point(a.x, b.x), c), cross(Point(a.y, b.y), c)), cross(a, b))

def id1(p1, p2, r):
    d2 = dist2(p1, p2)
    det = (r * r) / d2 - 0.25
    if det < 0.0:
        return False
    h = math.sqrt(det)
    c = point((p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h, (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h)
    return True, c

def id4(a, b, c):
    b = div(add(a, b), 2)
    c = div(add(a, c), 2)
    return id8(b, add(b, id5(sub(a, b))), c, add(c, id5(sub(a, c))))

def id18(a, b, c):
    d = add(b, id14(sub(c, b), angle(c, b, a) / 2))
    e = add(c, id14(sub(a, c), angle(a, c, b) / 2))
    return id8(b, d, c, e)

def id11(a, b, c, r):
    ret = []
    b = sub(b, a)
    a = sub(a, c)
    A = dot(b, b)
    B = dot(a, b)
    C = dot(a, a) - r * r
    D = B * B - A * C
    if D < -EPS:
        return ret
    ret.append(add(c, add(a, mul(b, (-B + math.sqrt(D + EPS)) / A))))
    if D > EPS:
        ret.append(add(c, add(a, mul(b, (-B - math.sqrt(D)) / A))))
    return ret

def id3(a, b, r, R):
    ret = []
    d = math.sqrt(dist2(a, b))
    if d > r + R or d + min(r, R) < max(r, R):
        return ret
    x = (d * d - R * R + r * r) / (2 * d)
    y = math.sqrt(r * r - x * x)
    v = div(sub(b, a), d)
    ret.append(add(a, add(mul(v, x), id19(v) * y)))
    if y > 0:
        ret.append(add(a, add(mul(v, x), id19(v) * -y)))
    return ret

def id7(c, r, p):
    resp = []
    to_center = sub(c, p)
    if cmp(r - math.sqrt(dist2(to_center, point(0, 0)))) <= 0:
        resp.append(p)
        resp.append(p)
        return resp
    angle = math.asin(r / math.sqrt(dist2(to_center, point(0, 0))))
    uni = div(to_center, math.sqrt(dist2(to_center, point(0, 0))))
    tam = math.sqrt(dist2(to_center, point(0, 0)) - r * r)
    origi = mul(uni, tam)
    p1 = add(p, id14(origi, angle))
    resp.append(p1)
    p2 = add(p, id14(origi, -angle))
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
        s += cross(T[i], T[(i + 1) % n])
    return s / 2

def id17(p):
    c = point(0, 0)
    scale = 6.0 * poly_area(p)
    for i in range(len(p)):
        j = (i + 1) % len(p)
        c = add(c, mul(add(p[i], p[j]), p[i].x * p[j].y - p[j].x * p[i].y))
    return div(c, scale)

def id6(p, q):
    P = sub(p, point(0, 0))
    Q = sub(q, point(0, 0))
    R = cross(P, Q)
    if cmp(R):
        return R > 0
    return cmp(dist2(P, point(0, 0)), dist2(Q, point(0, 0))) < 0

def id15(T):
    j = 0
    k = 0
    n = len(T)
    U = [None] * n
    pivot = min(T, key=lambda p: (p.x, p.y))
    T.sort(key=lambda p: (math.atan2(p.y - pivot.y, p.x - pivot.x), p))
    for k in range(n - 2, -1, -1):
        if ccw(T[0], T[n - 1], T[k]) == 0:
            continue
    T = T[k + 1:] + T[:k + 1][::-1]
    for i in range(n):
        while j > 1 and ccw(U[j - 1], U[j - 2], T[i]) >= 0:
            j -= 1
        U[j] = T[i]
        j += 1
    return U[:j]

def id16(P, Q):
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
        A = sub(p2, p1)
        B = sub(q2, q1)
        cross = cmp(cross(A, B))
        ha = ccw(p2, q2, p1)
        hb = ccw(q2, p2, q1)
        if cross == 0 and ccw(p1, q1, p2) == 0 and cmp(dot(A, B)) < 0:
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
        elif cross != 0 and id13(p1, p2, q1, q2):
            if inflag == 0:
                aa = ba = 0
            R.append(id8(p1, p2, q1, q2))
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
    if len(R) > 1 and eq(R[0], R[-1]):
        R.pop()
    return R

PI = math.acos(-1)
xp, yp, vp, x, y, v, r = map(int, input().split())
origin = point(0, 0)

def pode(loc, time):
    nave = point(x, y)
    if cmp(id10(loc, nave, origin), r) >= 0:
        return cmp(time, abs_point(sub(nave, loc)) / v) >= 0
    else:
        distN = math.sqrt(dist2(nave, origin) - r * r)
        distL = math.sqrt(dist2(loc, origin) - r * r)
        a = abs_point(sub(nave, loc))
        b = abs_point(nave)
        c = abs_point(loc)
        bigcos = (b * b + c * c - a * a) / (2 * b * c)
        id12 = math.acos(bigcos) - abs(math.atan(distN / r)) - abs(math.atan(distL / r))
        menor = distN + distL + abs(r * id12)
        return cmp(time, menor / v) >= 0

def main():
    R = math.hypot(yp, xp)
    initial = math.atan2(yp, xp)
    bot = 0
    timeTot = (2 * PI * R) / vp
    top = 100000000000000.0
    while cmp(top, bot) == 1:
        mid = (top + bot) / 2
        angle = (2 * PI * mid / timeTot) + initial
        loc = point(math.cos(angle) * R, math.sin(angle) * R)
        if pode(loc, mid):
            top = mid
        else:
            bot = mid
    print(f"{bot:.7f}")

main()
