import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Segment:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

class Circle:
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

def cross(a, b):
    return a.x * b.y - a.y * b.x

def dot(a, b):
    return a.x * b.x + a.y * b.y

def length(v):
    return math.sqrt(v.x * v.x + v.y * v.y)

def normalize(p):
    len_p = length(p)
    return Point(p.x / len_p, p.y / len_p)

def rotate(v, t):
    cos_t = math.cos(t)
    sin_t = math.sin(t)
    x = v.x * cos_t - v.y * sin_t
    y = v.x * sin_t + v.y * cos_t
    return Point(x, y)

def intersect(a, b, p, q):
    d1 = cross(p - a, b - a)
    d2 = cross(q - a, b - a)
    ret = (d1 * q - d2 * p) / (d1 - d2)
    if math.fabs(d1 - d2) > 1e-7:
        return True, ret
    return False, None

def point_on_line(a, b, p):
    return math.fabs(cross(a - b, a - p)) < 1e-7

def point_on_ray(a, b, p):
    return dot(a - p, b - a) > -1e-7

def point_on_segment(a, b, p):
    if not point_on_line(a, b, p):
        return False
    return point_on_ray(a, b, p) and point_on_ray(b, a, p)

def point_line_dist(a, b, p):
    return math.fabs(cross(a - b, a - p)) / length(a - b)

def point_segment_dist(a, b, p):
    if dot(a - b, a - p) < 1e-7:
        return length(a - p)
    if dot(b - a, b - p) < 1e-7:
        return length(b - p)
    return point_line_dist(a, b, p)

def segment_lattice_points_count(x1, y1, x2, y2):
    return abs(math.gcd(x1 - x2, y1 - y2)) + 1

def triangle_area_bh(b, h):
    return b * h / 2

def triangle_area_2sides_angle(a, b, t):
    return math.fabs(a * b * math.sin(t) / 2)

def triangle_area_2angles_side(t1, t2, s):
    return math.fabs(s * s * math.sin(t1) * math.sin(t2) / (2 * math.sin(t1 + t2)))

def triangle_area_3sides(a, b, c):
    s = (a + b + c) / 2
    return math.sqrt(s * (s - a) * (s - b) * (s - c))

def triangle_area_3points(a, b, c):
    return math.fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2

def picks_theorem(a, b):
    return a - b // 2 + 1

def cos_rule(a, b, c):
    res = (b * b + c * c - a * a) / (2 * b * c)
    if math.fabs(res - 1) < 1e-7:
        res = 1
    if math.fabs(res + 1) < 1e-7:
        res = -1
    return math.acos(res)

def sin_rule_angle(s1, s2, a1):
    res = s2 * math.sin(a1) / s1
    if math.fabs(res - 1) < 1e-7:
        res = 1
    if math.fabs(res + 1) < 1e-7:
        res = -1
    return math.asin(res)

def sin_rule_side(s1, a1, a2):
    return s1 * math.sin(a2) / math.sin(a1)

def circle_line_intersection(p0, p1, cen, rad):
    a = dot(p1 - p0, p1 - p0)
    b = 2 * dot(p1 - p0, p0 - cen)
    c = dot(p0 - cen, p0 - cen) - rad * rad
    det = b * b - 4 * a * c
    res = []
    if math.fabs(det) < 1e-7:
        det = 0
        res.append(p0 + (-b + math.sqrt(det)) / (2 * a) * (p1 - p0))
    elif det > 0:
        res.append(p0 + (-b + math.sqrt(det)) / (2 * a) * (p1 - p0))
        res.append(p0 + (-b - math.sqrt(det)) / (2 * a) * (p1 - p0))
    return res

def circle_circle_intersection(c1, r1, c2, r2):
    if c1 == c2 and math.fabs(r1 - r2) < 1e-7:
        return [c1], 1 if math.fabs(r1) < 1e-7 else float('inf')
    len = length(c1 - c2)
    if math.fabs(len - (r1 + r2)) < 1e-7 or math.fabs(math.fabs(r1 - r2) - len) < 1e-7:
        d = normalize(c2 - c1)
        return [c1 + d * r1], 1 if math.fabs(r1) < 1e-7 else float('inf')
    if len > r1 + r2 or len < math.fabs(r1 - r2):
        return [], 0
    a = cos_rule(r2, r1, len)
    c1c2 = normalize(c2 - c1) * r1
    return [rotate(c1c2, a) + c1, rotate(c1c2, -a) + c1], 2

def circle2(p1, p2):
    cen = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2)
    r = length(p1 - p2) / 2
    return cen, r

def circle3(p1, p2, p3):
    m1 = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2)
    m2 = Point((p2.x + p3.x) / 2, (p2.y + p3.y) / 2)
    perp1 = Point(-(p1.y - p2.y), p1.x - p2.x)
    perp2 = Point(-(p2.y - p3.y), p2.x - p3.x)
    res, _ = intersect(m1, m1 + perp1, m2, m2 + perp2)
    r = length(p1 - res)
    return res, r

def circle_point(cen, r, p):
    lensqr = length(p - cen) ** 2
    if math.fabs(lensqr - r * r) < 1e-7:
        return 'BOUNDARY'
    if lensqr < r * r:
        return 'IN'
    return 'OUT'

def tangent_points(cen, r, p):
    s = circle_point(cen, r, p)
    if s != 'OUT':
        return [p, p]
    cp = normalize(p - cen) * r
    a = rotate(cp, math.acos(r / length(cp))) + cen
    b = rotate(cp, -math.acos(r / length(cp))) + cen
    return [a, b]

def get_common_tangents(c1, r1, c2, r2):
    if r1 < r2:
        r1, r2 = r2, r1
        c1, c2 = c2, c1
    d = length(c1 - c2)
    theta = math.acos((r1 - r2) / d)
    v = normalize(c2 - c1)
    v1 = rotate(v, theta)
    v2 = rotate(v, -theta)
    res = []
    res.append(Segment(c1 + v1 * r1, c2 + v1 * r2))
    res.append(Segment(c1 + v2 * r1, c2 + v2 * r2))
    theta = math.acos((r1 + r2) / d)
    v1 = rotate(v, theta)
    v2 = rotate(v, -theta)
    res.append(Segment(c1 + v1 * r1, c2 - v1 * r2))
    res.append(Segment(c1 + v2 * r1, c2 - v2 * r2))
    return res

def polygon_area(p):
    res = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        res += cross(p[i], p[j])
    return math.fabs(res) / 2

def polygon_centroid(polygon):
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

def picks_theorem(p):
    area = polygon_area(p)
    bound = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        v = p[j] - p[i]
        bound += abs(math.gcd(int(v.x), int(v.y)))
    return round(area - bound / 2 + 1)

def polygon_cut(p, a, b):
    res = []
    for i in range(len(p)):
        j = (i + 1) % len(p)
        in1 = cross(b - a, p[i] - a) > 1e-7
        in2 = cross(b - a, p[j] - a) > 1e-7
        if in1:
            res.append(p[i])
        if in1 != in2:
            _, r = intersect(a, b, p[i], p[j])
            res.append(r)
    return res

def convex_polygon_intersect(p, q):
    res = q
    for i in range(len(p)):
        j = (i + 1) % len(p)
        temp = polygon_cut(res, p[i], p[j])
        res = temp
        if not res:
            return []
    return res

def voronoi(pnts, rect):
    res = []
    for i in range(len(pnts)):
        res.append(rect)
        for j in range(len(pnts)):
            if j == i:
                continue
            p = (pnts[i] - pnts[j]).perpendicular()
            m = (pnts[i] + pnts[j]) / 2
            temp = polygon_cut(res[-1], m, m + p)
            res[-1] = temp
    return res

def point_in_polygon(p, pnt):
    p2 = pnt + Point(1, 0)
    cnt = 0
    for i in range(len(p)):
        j = (i + 1) % len(p)
        if point_on_segment(p[i], p[j], pnt):
            return 'BOUNDARY'
        intersect, r = intersect(pnt, p2, p[i], p[j])
        if not intersect:
            continue
        if not point_on_ray(pnt, p2, r):
            continue
        if r == p[i] or r == p[j]:
            if math.fabs(r.y - min(p[i].y, p[j].y)) < 1e-7:
                continue
        if not point_on_segment(p[i], p[j], r):
            continue
        cnt += 1
    return 'IN' if cnt & 1 else 'OUT'

def sort_anti_clockwise(pnts):
    mn = Point(float('inf'), float('inf'))
    for p in pnts:
        if (p.y, p.x) < (mn.y, mn.x):
            mn = p
    pnts.sort(key=lambda p: (math.atan2(p.y - mn.y, p.x - mn.x), p.y, p.x))

def convex_hull(pnts):
    sort_anti_clockwise(pnts)
    convex = []
    convex.append(pnts[0])
    if len(pnts) == 1:
        return convex
    convex.append(pnts[1])
    if len(pnts) == 2:
        if pnts[0] == pnts[1]:
            convex.pop()
        return convex
    for i in range(2, len(pnts) + 1):
        c = pnts[i % len(pnts)]
        while len(convex) > 1:
            b = convex[-1]
            a = convex[-2]
            if cross(b - a, b - c) < -1e-7:
                break
            convex.pop()
        if i < len(pnts):
            convex.append(pnts[i])
    return convex

def xp_yp_vp_x_y_v_r_R():
    xp, yp, vp, x, y, v, r, R = map(float, input().split())
    return xp, yp, vp, x, y, v, r, R

def calc_arc(a, b):
    theta = abs(math.atan2(b.y, b.x) - math.atan2(a.y, a.x))
    if theta > math.pi:
        theta = 2 * math.pi - theta
    res = theta * r
    return res

def calc_dis(a, c):
    arc = calc_arc(a, c)
    res = arc + math.fabs(length(a - st)) + math.fabs(length(c - en))
    return res

def calc(st, en):
    a, b, c, d = tangent_points(Point(0, 0), r, st)
    res = calc_dis(a, c)
    res = min(res, calc_dis(a, d))
    res = min(res, calc_dis(b, c))
    res = min(res, calc_dis(b, d))
    return res

def can(t):
    start = st = Point(x, y)
    fin = en = Point(xp, yp)
    theta = t * vp / R
    fin = en = rotate(fin, theta)
    a, b = circle_line_intersection(start, fin, Point(0, 0), r)
    if len(a) > 0:
        if point_on_segment(start, fin, a[0]):
            intersection = True
        if len(a) == 2 and point_on_segment(start, fin, a[1]):
            intersection = True
    if len(a) <= 1 or not intersection:
        return length(start - fin) < v * t + 1e-7
    dis = calc(st, fin)
    return dis < v * t + 1e-7

def main():
    xp, yp, vp, x, y, v, r, R = xp_yp_vp_x_y_v_r_R()
    ans = 10000000
    hi = 1000000
    lo = 0.0
    for _ in range(100):
        m = lo + (hi - lo) / 2.0
        if can(m):
            ans = m
            hi = m
        else:
            lo = m
    print("{:.10f}".format(ans))

if __name__ == '__main__':
    main()
