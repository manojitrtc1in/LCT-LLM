import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Segment:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

def cross(p1, p2):
    return p1.x * p2.y - p1.y * p2.x

def dot(p1, p2):
    return p1.x * p2.x + p1.y * p2.y

def length(p):
    return math.sqrt(p.x * p.x + p.y * p.y)

def normalize(p):
    len = length(p)
    return Point(p.x / len, p.y / len)

def rotate(p, angle):
    x = p.x * math.cos(angle) - p.y * math.sin(angle)
    y = p.x * math.sin(angle) + p.y * math.cos(angle)
    return Point(x, y)

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    ret = Point((d1 * q.x - d2 * p.x) / (d1 - d2), (d1 * q.y - d2 * p.y) / (d1 - d2))
    if math.fabs(d1 - d2) > EPS:
        return True
    return False

def id8(a, b, p):
    return math.fabs(cross(vec(a,b),vec(a,p))) < EPS

def id23(a, b, p):
    return dot(vec(a,p), vec(a,b)) > -EPS

def id4(a, b, p):
    if not colliner(a,b,p):
        return False
    return id23(a, b, p) and id23(b, a, p)

def id14(a, b, p):
    return math.fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)))

def id22(a, b, p):
    if dot(vec(a,b),vec(a,p)) < EPS:
        return length(vec(a,p))
    if dot(vec(b,a),vec(b,p)) < EPS:
        return length(vec(b,p))
    return id14(a, b, p)

def id16(x1, y1, x2, y2):
    return abs(math.gcd(x1 - x2, y1 - y2)) + 1

def id2(b, h):
    return b * h / 2

def id5(a, b, t):
    return math.fabs(a * b * math.sin(t) / 2)

def id19(t1, t2, s):
    return math.fabs(s * s * math.sin(t1) * math.sin(t2) / (2 * math.sin(t1 + t2)))

def id20(a, b, c):
    s = (a + b + c) / 2
    return math.sqrt(s * (s - a) * (s - b) * (s - c))

def id10(a, b, c):
    return math.fabs(cross(a,b) + cross(b,c) + cross(c,a)) / 2

def id18(a, b):
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

def id13(p0, p1, cen, rad):
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
    return res

def id3(c1, r1, c2, r2):
    if same(c1,c2) and math.fabs(r1 - r2) < EPS:
        res1 = res2 = c1
        return 1 if math.fabs(r1) < EPS else OO
    len = length(vec(c1,c2))
    if math.fabs(len - (r1 + r2)) < EPS or math.fabs(math.fabs(r1 - r2) - len) < EPS:
        d, c, r = (vec(c1,c2), c1, r1) if r1 > r2 else (vec(c2,c1), c2, r2)
        res1 = res2 = normalize(d) * r + c
        return 1
    if len > r1 + r2 or len < math.fabs(r1 - r2):
        return 0
    a = cosRule(r2, r1, len)
    id11 = normalize(vec(c1,c2)) * r1
    res1 = rotate(id11,a) + c1
    res2 = rotate(id11,-a) + c1
    return 2

def circle2(p1, p2):
    cen = mid(p1,p2)
    r = length(vec(p1,p2)) / 2
    return cen, r

def circle3(p1, p2, p3):
    m1 = mid(p1,p2)
    m2 = mid(p2,p3)
    id7 = perp(vec(p1,p2))
    id15 = perp(vec(p2,p3))
    res = intersect(m1, m1 + id7, m2, m2 + id15, cen)
    r = length(vec(cen,p1))
    return res, r

def circlePoint(cen, r, p):
    lensqr = lengthSqr(vec(cen,p))
    if math.fabs(lensqr - r * r) < EPS:
        return BOUNDRY
    if lensqr < r * r:
        return IN
    return OUT

def id1(cen, r, p):
    s = circlePoint(cen, r, p)
    if s != OUT:
        r1 = r2 = p
        return s == BOUNDRY
    cp = vec(cen,p)
    h = length(cp)
    a = math.acos(r / h)
    cp = normalize(cp) * r
    r1 = rotate(cp,a) + cen
    r2 = rotate(cp,-a) + cen
    return 2

def id12(c1, r1, c2, r2):
    if r1 < r2:
        r1, r2 = r2, r1
        c1, c2 = c2, c1
    d = length(c1 - c2)
    theta = math.acos((r1 - r2) / d)
    v = c2 - c1
    v = v / hypot(v.imag(), v.real())
    v1 = v * exp(0, theta)
    v2 = v * exp(0, -theta)
    res = []
    res.append(Segment(c1 + v1 * r1, c2 + v1 * r2))
    res.append(Segment(c1 + v2 * r1, c2 + v2 * r2))
    theta = math.acos((r1 + r2) / d)
    v1 = v * exp(0, theta)
    v2 = v * exp(0, -theta)
    res.append(Segment(c1 + v1 * r1, c2 - v1 * r2))
    res.append(Segment(c1 + v2 * r1, c2 - v2 * r2))
    return res

def polygonArea(p):
    res = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        res += cross(p[i],p[j])
    return math.fabs(res) / 2

def id9(polygon):
    a = 0
    x, y = 0.0, 0.0
    for i in range(len(polygon)):
        j = (i + 1) % len(polygon)

        x += (polygon[i].x + polygon[j].x) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)
        y += (polygon[i].y + polygon[j].y) * (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y)

        a += polygon[i].x * polygon[j].y - polygon[i].y * polygon[j].x

    a *= 0.5
    x /= 6 * a
    y /= 6 * a

    return Point(x, y)

def id18(p):
    area = 0
    bound = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        area += cross(p[i],p[j])
        v = vec(p[i],p[j])
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
            r = intersect(a, b, p[i], p[j])
            res.append(r)
    return res

def id25(p, q):
    res = q
    for i in range(len(p)):
        j = (i + 1) % len(p)
        temp = []
        polygonCut(res, p[i], p[j], temp)
        res = temp
        if len(res) == 0:
            return
    return res

def id21(pnts, rect):
    res = []
    for i in range(len(pnts)):
        res.append(rect)
        for j in range(len(pnts)):
            if j == i:
                continue
            p = perp(vec(pnts[i],pnts[j]))
            m = mid(pnts[i],pnts[j])
            temp = []
            polygonCut(res[-1], m, m + p, temp)
            res[-1] = temp
    return res

def id24(p, pnt):
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        if id4(p[i], p[j], pnt):
            return BOUNDRY
        r = Point(0, 0)
        if not intersect(pnt, p2, p[i], p[j], r):
            continue
        if not id23(pnt, p2, r):
            continue
        if same(r,p[i]) or same(r,p[j]):
            if math.fabs(r.y - min(p[i].y, p[j].y)) < EPS:
                continue
        if not id4(p[i], p[j], r):
            continue
        cnt += 1
    return IN if cnt & 1 else OUT

def cmp(about):
    def compare(p, q):
        cr = cross(vec(about, p), vec(about, q))
        if math.fabs(cr) < EPS:
            return (p.y, p.x) < (q.y, q.x)
        return cr > 0
    return compare

def id6(pnts):
    mn = Point(float('inf'), float('inf'))
    for i in range(len(pnts)):
        if (pnts[i].y, pnts[i].x) < (mn.y, mn.x):
            mn = pnts[i]

    pnts.sort(key=cmp(mn))

def id17(pnts, convex):
    id6(pnts)
    convex = []
    convex.append(pnts[0])
    if len(pnts) == 1:
        return
    convex.append(pnts[1])
    if len(pnts) == 2:
        if same(pnts[0], pnts[1]):
            convex.pop()
        return
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
