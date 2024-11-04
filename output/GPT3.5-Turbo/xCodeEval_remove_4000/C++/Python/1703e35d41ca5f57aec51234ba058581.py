import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def cross(a, b):
    return a.x * b.y - a.y * b.x

def dot(a, b):
    return a.x * b.x + a.y * b.y

def length(a):
    return math.sqrt(a.x * a.x + a.y * a.y)

def normalize(a):
    len = length(a)
    return Point(a.x / len, a.y / len)

def rotate(a, angle):
    x = a.x * math.cos(angle) - a.y * math.sin(angle)
    y = a.x * math.sin(angle) + a.y * math.cos(angle)
    return Point(x, y)

def angle(a):
    return math.atan2(a.y, a.x)

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    ret = Point((d1 * q.x - d2 * p.x) / (d1 - d2), (d1 * q.y - d2 * p.y) / (d1 - d2))
    if math.fabs(d1 - d2) > EPS:
        return True, ret
    return False, ret

def id8(a, b, p):
    return math.fabs(cross(vec(a,b),vec(a,p))) < EPS

def id22(a, b, p):
    return dot(vec(a,p), vec(a,b)) > -EPS

def id4(a, b, p):
    if not colliner(a,b,p):
        return False
    return id22(a, b, p) and id22(b, a, p)

def id13(a, b, p):
    return math.fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)))

def id21(a, b, p):
    if dot(vec(a,b),vec(a,p)) < EPS:
        return length(vec(a,p))
    if dot(vec(b,a),vec(b,p)) < EPS:
        return length(vec(b,p))
    return id13(a, b, p)

def id15(x1, y1, x2, y2):
    return abs(math.gcd(x1 - x2, y1 - y2)) + 1

def id2(b, h):
    return b * h / 2

def id5(a, b, t):
    return math.fabs(a * b * math.sin(t) / 2)

def id18(t1, t2, s):
    return math.fabs(s * s * math.sin(t1) * math.sin(t2) / (2 * math.sin(t1 + t2)))

def id19(a, b, c):
    s = (a + b + c) / 2
    return math.sqrt(s * (s - a) * (s - b) * (s - c))

def id10(a, b, c):
    return math.fabs(cross(a,b) + cross(b,c) + cross(c,a)) / 2

def id17(a, b):
    return a - b / 2 + 1

def cosRule(a, b, c):
    res = (b * b + c * c - a * a) / (2 * b * c)
    if math.fabs(res-1) < EPS:
        res = 1
    if math.fabs(res+1) < EPS:
        res = -1
    return math.acos(res)

def id26(s1, s2, a1):
    res = s2 * math.sin(a1) / s1
    if math.fabs(res-1) < EPS:
        res = 1
    if math.fabs(res+1) < EPS:
        res = -1
    return math.asin(res)

def id0(s1, a1, a2):
    res = s1 * math.sin(a2) / math.sin(a1)
    return math.fabs(res)

def id12(p0, p1, cen, rad):
    a, b, c, t1, t2 = 0, 0, 0, 0, 0
    a = dot(p1-p0,p1-p0)
    b = 2 * dot(p1-p0,p0-cen)
    c = dot(p0-cen,p0-cen) - rad * rad
    det = b * b - 4 * a * c
    res = 0
    if math.fabs(det) < EPS:
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

def id3(c1, r1, c2, r2):
    if same(c1,c2) and math.fabs(r1 - r2) < EPS:
        res1 = c1
        res2 = c2
        return 1, res1, res2
    len = length(vec(c1,c2))
    if math.fabs(len - (r1 + r2)) < EPS or math.fabs(math.fabs(r1 - r2) - len) < EPS:
        d, c, r = 0, 0, 0
        if r1 > r2:
            d = vec(c1,c2)
            c = c1
            r = r1
        else:
            d = vec(c2,c1)
            c = c2
            r = r2
        res1 = normalize(d) * r + c
        res2 = normalize(d) * r + c
        return 1, res1, res2
    if len > r1 + r2 or len < math.fabs(r1 - r2):
        return 0, None, None
    a = cosRule(r2, r1, len)
    id11 = normalize(vec(c1,c2)) * r1
    res1 = rotate(id11,a) + c1
    res2 = rotate(id11,-a) + c1
    return 2, res1, res2

def circle2(p1, p2):
    cen = mid(p1,p2)
    r = length(vec(p1,p2)) / 2
    return cen, r

def circle3(p1, p2, p3):
    m1 = mid(p1,p2)
    m2 = mid(p2,p3)
    id7 = perp(vec(p1,p2))
    id14 = perp(vec(p2,p3))
    res, cen = intersect(m1, m1 + id7, m2, m2 + id14)
    r = length(vec(cen,p1))
    return res, cen, r

class STATE:
    IN = 0
    OUT = 1
    BOUNDRY = 2

def circlePoint(cen, r, p):
    lensqr = lengthSqr(vec(cen,p))
    if math.fabs(lensqr - r * r) < EPS:
        return STATE.BOUNDRY
    if lensqr < r * r:
        return STATE.IN
    return STATE.OUT

def id1(cen, r, p):
    s = circlePoint(cen, r, p)
    if s != STATE.OUT:
        r1 = p
        r2 = p
        if math.fabs(r) < EPS:
            return s == STATE.BOUNDRY, r1, r2
    cp = vec(cen,p)
    h = length(cp)
    a = math.acos(r / h)
    cp = normalize(cp) * r
    r1 = rotate(cp,a) + cen
    r2 = rotate(cp,-a) + cen
    return 2, r1, r2

def polygonArea(p):
    res = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        res += cross(p[i],p[j])
    return math.fabs(res) / 2

def id9(polygon):
    a = 0
    x = 0.0
    y = 0.0
    for i in range(len(polygon)):
        j = (i + 1) % len(polygon)
        x += (polygon[i].x + polygon[j].x) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)
        y += (polygon[i].y + polygon[j].y) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)
        a += polygon[i].x * polygon[j].y - polygon[i].y * polygon[j].x
    a *= 0.5
    x /= 6 * a
    y /= 6 * a
    return Point(x, y)

def id17(polygon):
    area = 0
    bound = 0
    for i in range(len(polygon)):
        j = (i + 1) % len(polygon)
        area += cross(polygon[i],polygon[j])
        v = vec(polygon[i],polygon[j])
        bound += abs(math.gcd(int(v.x), int(v.y)))
    area /= 2
    area = math.fabs(area)
    return round(area - bound / 2 + 1)

def polygonCut(p, a, b):
    res = []
    for i in range(len(p)):
        j = (i + 1) % len(p)
        in1 = cross(vec(a,b),vec(a,p[i])) > EPS
        in2 = cross(vec(a,b),vec(a,p[j])) > EPS
        if in1:
            res.append(p[i])
        if in1 ^ in2:
            res.append(intersect(a, b, p[i], p[j]))
    return res

def id25(p, q):
    res = q
    for i in range(len(p)):
        j = (i + 1) % len(p)
        temp = polygonCut(res, p[i], p[j])
        res = temp
        if len(res) == 0:
            return
    return res

def id20(pnts, rect):
    res = []
    for i in range(len(pnts)):
        res.append(rect)
        for j in range(len(pnts)):
            if j == i:
                continue
            p = perp(vec(pnts[i],pnts[j]))
            m = mid(pnts[i],pnts[j])
            temp = polygonCut(res[-1], m, m + p)
            res[-1] = temp
    return res

def id24(p, pnt):
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        if id4(p[i], p[j], pnt):
            return STATE.BOUNDRY
        r, res = intersect(pnt, p2, p[i], p[j])
        if not r:
            continue
        if not id22(pnt, p2, res):
            continue
        if same(res,p[i]) or same(res,p[j]):
            if math.fabs(res.y - min(p[i].y, p[j].y)) < EPS:
                continue
        if not id4(p[i], p[j], res):
            continue
        cnt += 1
    return STATE.IN if cnt & 1 else STATE.OUT

def cmp(about):
    def compare(p, q):
        cr = cross(vec(about, p), vec(about, q))
        if math.fabs(cr) < EPS:
            return (p.y, p.x) < (q.y, q.x)
        return cr > 0
    return compare

def id6(pnts):
    mn = Point(1 / 0.0, 1 / 0.0)
    for i in range(len(pnts)):
        if (pnts[i].y, pnts[i].x) < (mn.y, mn.x):
            mn = pnts[i]
    pnts.sort(key=cmp(mn))

def id16(pnts):
    id6(pnts)
    convex = []
    convex.append(pnts[0])
    if len(pnts) == 1:
        return convex
    convex.append(pnts[1])
    if len(pnts) == 2:
        if same(pnts[0], pnts[1]):
            convex.pop()
        return convex
    for i in range(2, len(pnts) + 1):
        c = pnts[i % len(pnts)]
        while len(convex) > 1:
            b = convex[-1]
            a = convex[-2]
            if cross(vec(b, a), vec(b, c)) < -EPS:
                break
            convex.pop()
        if i < len(pnts):
            convex.append(pnts[i])
    return convex

def id25(p, q):
    res = q
    for i in range(len(p)):
        j = (i + 1) % len(p)
        temp = polygonCut(res, p[i], p[j])
        res = temp
        if len(res) == 0:
            return
    return res

def id20(pnts, rect):
    res = []
    for i in range(len(pnts)):
        res.append(rect)
        for j in range(len(pnts)):
            if j == i:
                continue
            p = perp(vec(pnts[i],pnts[j]))
            m = mid(pnts[i],pnts[j])
            temp = polygonCut(res[-1], m, m + p)
            res[-1] = temp
    return res

def id24(p, pnt):
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        if id4(p[i], p[j], pnt):
            return STATE.BOUNDRY
        r, res = intersect(pnt, p2, p[i], p[j])
        if not r:
            continue
        if not id22(pnt, p2, res):
            continue
        if same(res,p[i]) or same(res,p[j]):
            if math.fabs(res.y - min(p[i].y, p[j].y)) < EPS:
                continue
        if not id4(p[i], p[j], res):
            continue
        cnt += 1
    return STATE.IN if cnt & 1 else STATE.OUT

def id6(pnts):
    mn = Point(1 / 0.0, 1 / 0.0)
    for i in range(len(pnts)):
        if (pnts[i].y, pnts[i].x) < (mn.y, mn.x):
            mn = pnts[i]
    pnts.sort(key=cmp(mn))

def id16(pnts):
    id6(pnts)
    convex = []
    convex.append(pnts[0])
    if len(pnts) == 1:
        return convex
    convex.append(pnts[1])
    if len(pnts) == 2:
        if same(pnts[0], pnts[1]):
            convex.pop()
        return convex
    for i in range(2, len(pnts) + 1):
        c = pnts[i % len(pnts)]
        while len(convex) > 1:
            b = convex[-1]
            a = convex[-2]
            if cross(vec(b, a), vec(b, c)) < -EPS:
                break
            convex.pop()
        if i < len(pnts):
            convex.append(pnts[i])
    return convex

def arc_length(a, b, r):
    Ang = angle(a) - angle(b)
    if Ang < 0:
        Ang += 2 * math.pi
    if Ang > math.pi:
        Ang = 2 * math.pi - Ang
    return Ang * r

Xc, Yc, Vc = map(int, input().split())
Xb, Yb, Vb, r = map(int, input().split())
planet = Point(Xc, Yc)
ship = Point(Xb, Yb)
R = length(planet)
w = Vc / R
left = 0
right = 1 << 30
for i in range(300):
    mid = (right + left) / 2
    id23 = rotate(planet, w * mid)
    distance = 0
    if id21(ship, id23, Point(0, 0)) < r:
        a, b, c, d = Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)
        id1(Point(0, 0), r, ship, a, b)
        id1(Point(0, 0), r, id23, c, d)
        distance = 1 << 30
        distance = min(distance, length(vec(ship, a)) + length(vec(c, id23)) + arc_length(a, c, r))
        distance = min(distance, length(vec(ship, b)) + length(vec(c, id23)) + arc_length(b, c, r))
        distance = min(distance, length(vec(ship, a)) + length(vec(d, id23)) + arc_length(a, d, r))
        distance = min(distance, length(vec(ship, b)) + length(vec(d, id23)) + arc_length(b, d, r))
    else:
        distance = length(vec(ship, id23))
    if distance / Vb < mid:
        right = mid
    else:
        left = mid
print("{:.10f}".format(left))
