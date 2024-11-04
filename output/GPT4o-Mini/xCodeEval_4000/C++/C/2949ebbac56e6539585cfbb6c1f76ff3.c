#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef double DB;
const DB PI = acos(-1);
const DB INF = 1e10;
const DB EPS = 1e-8;

inline DB sqr(const DB v) { return v * v; }
inline int sgn(const DB v) { return v < -EPS ? -1 : v > EPS; }

struct PT {
    DB x, y;
};

inline struct PT create_pt(DB x, DB y) {
    struct PT p;
    p.x = x;
    p.y = y;
    return p;
}

inline struct PT pt_add(const struct PT a, const struct PT b) { return create_pt(a.x + b.x, a.y + b.y); }
inline struct PT pt_sub(const struct PT a, const struct PT b) { return create_pt(a.x - b.x, a.y - b.y); }
inline struct PT pt_neg(const struct PT p) { return create_pt(-p.x, -p.y); }
inline struct PT pt_mul(const struct PT p, const DB c) { return create_pt(p.x * c, p.y * c); }
inline struct PT pt_div(const struct PT p, const DB c) { return create_pt(p.x / c, p.y / c); }
inline int pt_less(const struct PT a, const struct PT b) {
    return sgn(a.x - b.x) ? sgn(a.x - b.x) < 0 : sgn(a.y - b.y) < 0;
}
inline int pt_eq(const struct PT a, const struct PT b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
inline int pt_neq(const struct PT a, const struct PT b) { return sgn(a.x - b.x) || sgn(a.y - b.y); }

DB dis(const struct PT v) { return sqrt(sqr(v.x) + sqr(v.y)); }
DB dis2(const struct PT v) { return sqr(v.x) + sqr(v.y); }
DB dis_pts(const struct PT p1, const struct PT p2) { return dis(pt_sub(p1, p2)); }
DB dis2_pts(const struct PT p1, const struct PT p2) { return dis2(pt_sub(p1, p2)); }

DB vect(const struct PT v1, const struct PT v2) { return v1.x * v2.y - v2.x * v1.y; }
DB vect_pts(const struct PT p, const struct PT p1, const struct PT p2) { return vect(pt_sub(p1, p), pt_sub(p2, p)); }
DB scal(const struct PT v1, const struct PT v2) { return v1.x * v2.x + v1.y * v2.y; }
DB scal_pts(const struct PT p, const struct PT p1, const struct PT p2) { return scal(pt_sub(p1, p), pt_sub(p2, p)); }

int sect(const struct PT p) {
    if (sgn(p.x) == 0 && sgn(p.y) == 0) return 0;
    if (sgn(p.x) == 0) return sgn(p.y) > 0 ? 2 : 4;
    if (sgn(p.y) == 0) return sgn(p.x) > 0 ? 1 : 3;
    if (sgn(p.x) == 1) return sgn(p.y) == 1 ? 1 : 4;
    return sgn(p.y) == 1 ? 2 : 3;
}

DB ang(const struct PT v) { return atan2(v.y, v.x); }
DB ang_pts(const struct PT p1, const struct PT p2) { return ang(pt_sub(p2, p1)); }
DB ang_three_pts(const struct PT p, const struct PT p1, const struct PT p2) {
    DB dy = vect_pts(p, p1, p2);
    DB dx = scal_pts(p, p1, p2);
    if (!sgn(dy)) dy = 0;
    if (!sgn(dx)) dx = 0;
    return atan2(dy, dx);
}
DB ang2(const struct PT p, const struct PT p1, const struct PT p2) { return acos(scal_pts(p, p1, p2) / dis_pts(p, p1) / dis_pts(p, p2)); }

struct PT proj(const struct PT p, const struct PT p1, const struct PT p2) {
    return pt_add(p1, pt_mul(pt_sub(p2, p1), scal_pts(p1, p, p2) / dis2_pts(p1, p2)));
}
struct PT rot(const struct PT v, const DB t) { return create_pt(v.x * cos(t) - v.y * sin(t), v.x * sin(t) + v.y * cos(t)); }
struct PT rot_pts(const struct PT p, const struct PT o, const DB t) { return rot(pt_sub(p, o), t); }
struct PT polar(const struct PT o, const DB r, const DB t) { return pt_add(o, pt_mul(create_pt(cos(t), sin(t)), r)); }

DB disToLine(const struct PT p, const struct PT p1, const struct PT p2) { return fabs(vect(p, p1, p2)) / dis_pts(p1, p2); }
DB disToSeg(const struct PT p, const struct PT p1, const struct PT p2) {
    if (sgn(scal_pts(p1, p, p2)) < 0) return dis_pts(p, p1);
    if (sgn(scal_pts(p2, p, p1)) < 0) return dis_pts(p, p2);
    return disToLine(p, p1, p2);
}

int onLine(const struct PT p, const struct PT p1, const struct PT p2) { return !sgn(vect(p, p1, p2)); }
int onSeg(const struct PT p, const struct PT p1, const struct PT p2) { return !onLine(p, p1, p2) && sgn(scal_pts(p, p1, p2)) <= 0; }
int inAngle(const struct PT p, const struct PT p0, const struct PT p1, const struct PT p2) {
    DB d0 = vect(p0, p1, p2);
    DB d1 = vect(p0, p1, p);
    DB d2 = vect(p0, p2, p);
    if (sgn(d0) >= 0) return sgn(d1) >= 0 && sgn(d2) <= 0;
    return sgn(d1) >= 0 || sgn(d2) <= 0;
}
int inConvex(const struct PT p, const struct PT q[], int n) {
    struct PT o = pt_div(pt_add(pt_add(q[0], q[1]), q[2]), 3);
    if (pt_eq(o, p)) return 1;
    int l = 0, h = n;
    while (h - l > 1) {
        int m = (l + h) / 2;
        if (inAngle(p, o, q[l % n], q[m % n])) h = m;
        else l = m;
    }
    l %= n, h %= n;
    if (!sgn(vect(q[l], q[h], p))) return 2;
    return sgn(vect(q[l], q[h], o) * vect(q[l], q[h], p)) > 0;
}

int posLineLine(const struct PT p1, const struct PT p2, const struct PT p3, const struct PT p4, struct PT *p) {
    DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
    if (!sgn(s1 - s2)) return sgn(s1) ? 0 : 2;
    *p = pt_sub(p3, pt_mul(pt_sub(p4, p3), s1 / (s2 - s1)));
    return 1;
}

int posSegSeg(const struct PT p1, const struct PT p2, const struct PT p3, const struct PT p4, struct PT *p) {
    int ret = posLineLine(p1, p2, p3, p4, p);
    if (ret == 1) return onSeg(*p, p1, p2) && onSeg(*p, p3, p4);
    if (ret == 2 && (onSeg(p1, p3, p4) || onSeg(p2, p3, p4))) return 2;
    return 0;
}

int inPolygon(const struct PT p, const struct PT q[], int n) {
    int c = 0;
    struct PT r = create_pt(INF, INF * sqrt(3)), t;
    for (int i = 0; i < n; ++i) {
        if (onLine(p, q[i], q[(i + 1) % n])) return 2;
        if (posSegSeg(p, r, q[i], q[(i + 1) % n], &t) == 1) ++c;
    }
    return c % 2;
}

int posCirLine(const struct PT o, const DB r, const struct PT p1, const struct PT p2, struct PT q[]) {
    DB a = dis2_pts(p1, p2);
    DB b = scal_pts(p1, o, p2);
    DB c = dis2_pts(o, p1) - sqr(r);
    DB d2 = sqr(b) - a * c;
    if (sgn(d2) < 0) return 0;
    DB d = sqrt(fabs(d2));
    if (q != NULL) q[0] = pt_add(p1, pt_mul(pt_sub(p2, p1), (b + d) / a));
    if (sgn(d2) == 0) return 1;
    if (q != NULL) q[1] = pt_add(p1, pt_mul(pt_sub(p2, p1), (b - d) / a));
    return 2;
}

int posCirCir(const struct PT o1, const DB r1, const struct PT o2, const DB r2, struct PT q[]) {
    if (pt_eq(o1, o2)) return sgn(r1 - r2) ? 0 : 3;
    DB d = dis_pts(o1, o2);
    DB e = (sqr(r1) - sqr(r2) + sqr(d)) / (2 * d);
    DB f2 = sqr(r1) - sqr(e);
    if (sgn(f2) < 0) return 0;
    DB f = sqrt(fabs(f2));
    DB dx = o2.x - o1.x, dy = o2.y - o1.y;
    if (q != NULL) q[0] = create_pt(o1.x + (e * dx - f * dy) / d, o1.y + (e * dy + f * dx) / d);
    if (sgn(f2) == 0) return 1;
    if (q != NULL) q[1] = create_pt(o1.x + (e * dx + f * dy) / d, o1.y + (e * dy - f * dx) / d);
    return 2;
}

struct PT normalLine(const struct PT p1, const struct PT p2) { return create_pt(-(p2.y - p1.y), p2.x - p1.x); }

struct PT innerCenter(const struct PT a, const struct PT b, const struct PT c) {
    DB A = dis_pts(b, c);
    DB B = dis_pts(c, a);
    DB C = dis_pts(a, b);
    return create_pt((A * a.x + B * b.x + C * c.x) / (A + B + C), (A * a.y + B * b.y + C * c.y) / (A + B + C));
}
struct PT outerCenter(const struct PT a, const struct PT b, const struct PT c) {
    DB d1 = (dis2_pts(a) - dis2_pts(b)) / 2;
    DB d2 = (dis2_pts(a) - dis2_pts(c)) / 2;
    DB x = (d1 * (a.y - c.y) - d2 * (a.y - b.y)) / vect(a - b, a - c);
    DB y = (d1 * (a.x - c.x) - d2 * (a.x - b.x)) / vect(a - c, a - b);
    return create_pt(x, y);
}
struct PT gravityCenter(const struct PT p[], int n) {
    struct PT o = {0, 0};
    for (int i = 0; i < n; ++i)
        o = pt_add(o, p[i]);
    return pt_div(o, n);
}

DB Circle_Shared_Area(const struct PT p1, const DB r1, const struct PT p2, const DB r2) {
    DB d = dis_pts(p1, p2);
    if (sgn(d - r1 - r2) >= 0) return 0;
    DB p = (r1 + r2 + d) / 2;
    DB s = sqrt(p * (p - r1) * (p - r2) * (p - d));
    DB l = 2 * s / d;
    return r1 * r1 * asin(l / r1) + r2 * r2 * asin(l / r2) - s * 2;
}

int isSimple(const struct PT p[], int n) {
    for (int i = 0; i < n; ++i) for (int j = i + 3; j < n; ++j)
        if (0) return 0;
    return 1;
}

int isConvex(const struct PT p[], int n) {
    for (int i = 0; i < n; ++i) if (sgn(vect(p[i], p[(i + 1) % n], p[(i + 2) % n])) <= 0) return 0;
    return 1;
}

DB Polygon_Area(const struct PT p[], int n) {
    DB S = 0;
    for (int i = 0; i < n; ++i) S += vect(p[i], p[(i + 1) % n]);
    return fabs(S) / 2;
}

int Convex_Hull(struct PT p[], int n, struct PT q[]) {
    qsort(p, n, sizeof(struct PT), cmp1);
    n = unique(p, p + n) - p;
    if (n == 1) {
        q[0] = p[0];
        return 1;
    }
    int m = 0;
    for (int i = 0; i < n; ++i) {
        for (; m >= 2 && sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0; --m);
        q[m++] = p[i];
    }
    for (int i = n - 2, m0 = m; i >= 0; --i) {
        for (; m > m0 && sgn(vect(q[m - 2], q[m - 1], p[i])) <= 0; --m);
        q[m++] = p[i];
    }
    return --m;
}

struct HP {
    struct PT s, e;
};

int Half_Plane_Intersection(struct HP *p, int n) {
    p[n++] = (struct HP){create_pt(-INF, -INF), create_pt(INF, -INF)};
    p[n++] = (struct HP){create_pt(INF, -INF), create_pt(INF, INF)};
    p[n++] = (struct HP){create_pt(INF, INF), create_pt(-INF, INF)};
    p[n++] = (struct HP){create_pt(-INF, INF), create_pt(-INF, -INF)};
    qsort(p, n, sizeof(struct HP), cmp1);
    n = unique(p, p + n) - p;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        struct PT c;
        for (; r - l >= 2; --r) {
            posLineLine(p[r - 2].s, p[r - 2].e, p[r - 1].s, p[r - 1].e, &c);
            if (sgn(vect(p[i].s, p[i].e, c)) > 0) break;
        }
        for (; r - l >= 2; ++l) {
            posLineLine(p[l].s, p[l].e, p[l + 1].s, p[l + 1].e, &c);
            if (sgn(vect(p[i].s, p[i].e, c)) > 0) break;
        }
        if (r - l < 2) p[r++] = p[i];
        else {
            posLineLine(p[r - 1].s, p[r - 1].e, p[i].s, p[i].e, &c);
            if (sgn(vect(p[0].s, p[0].e, c)) > 0) p[r++] = p[i];
        }
    }
    int m = 0;
    for (int i = l; i < r; ++i) {
        DB t = INF;
        t = fmin(t, fabs(p[i].s.x));
        t = fmin(t, fabs(p[i].s.y));
        t = fmin(t, fabs(p[i].e.x));
        t = fmin(t, fabs(p[i].e.y));
        if (sgn(t - INF)) p[m++] = p[i];
    }
    return m;
}

struct PT3 {
    DB x, y, z;
};

inline struct PT3 create_pt3(DB x, DB y, DB z) {
    struct PT3 p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

inline struct PT3 pt3_add(const struct PT3 a, const struct PT3 b) { return create_pt3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline struct PT3 pt3_sub(const struct PT3 a, const struct PT3 b) { return create_pt3(a.x - b.x, a.y - b.y, a.z - b.z); }
inline struct PT3 pt3_neg(const struct PT3 p) { return create_pt3(-p.x, -p.y, -p.z); }
inline struct PT3 pt3_mul(const struct PT3 p, const DB c) { return create_pt3(p.x * c, p.y * c, p.z * c); }
inline struct PT3 pt3_div(const struct PT3 p, const DB c) { return create_pt3(p.x / c, p.y / c, p.z / c); }
inline int pt3_less(const struct PT3 a, const struct PT3 b) {
    if (sgn(a.x - b.x)) return sgn(a.x - b.x) < 0;
    if (sgn(a.y - b.y)) return sgn(a.y - b.y) < 0;
    return sgn(a.z - b.z) < 0;
}
inline int pt3_eq(const struct PT3 a, const struct PT3 b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y) && !sgn(a.z - b.z); }
inline int pt3_neq(const struct PT3 a, const struct PT3 b) { return sgn(a.x - b.x) || sgn(a.y - b.y) || sgn(a.z - b.z); }

DB dis3(const struct PT3 v) { return sqrt(sqr(v.x) + sqr(v.y) + sqr(v.z)); }
DB dis2_3(const struct PT3 v) { return sqr(v.x) + sqr(v.y) + sqr(v.z); }
DB dis_pts3(const struct PT3 p1, const struct PT3 p2) { return dis3(pt3_sub(p1, p2)); }
DB dis2_pts3(const struct PT3 p1, const struct PT3 p2) { return dis2_3(pt3_sub(p1, p2)); }

struct PT3 vect3(const struct PT3 v1, const struct PT3 v2) { return create_pt3(v1.y * v2.z - v2.y * v1.z, -(v1.x * v2.z - v2.x * v1.z), v1.x * v2.y - v2.x * v1.y); }
struct PT3 vect3_pts(const struct PT3 p, const struct PT3 p1, const struct PT3 p2) { return vect3(pt3_sub(p1, p), pt3_sub(p2, p)); }
DB scal3(const struct PT3 v1, const struct PT3 v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
DB scal3_pts(const struct PT3 p, const struct PT3 p1, const struct PT3 p2) { return scal3(pt3_sub(p1, p), pt3_sub(p2, p)); }

DB disToPlane(const struct PT3 p, const DB a, const DB b, const DB c, const DB d) { return fabs(a * p.x + b * p.y + c * p.z + d) / sqrt(sqr(a) + sqr(b) + sqr(c)); }

void makePlane(const struct PT3 p1, const struct PT3 p2, const struct PT3 p3, DB *a, DB *b, DB *c, DB *d) {
    struct PT3 q = vect3(p1, p2, p3);
    *a = q.x, *b = q.y, *c = q.z;
    *d = -(*a * p1.x + *b * p1.y + *c * p1.z);
}

const int N = 2100;
DB d[N];
struct PT p[N];
struct PT v[N];

int cmp1(const void *a, const void *b) {
    struct PT *pt1 = (struct PT *)a;
    struct PT *pt2 = (struct PT *)b;
    if (sect(*pt1) != sect(*pt2)) return sect(*pt1) < sect(*pt2) ? -1 : 1;
    DB d = vect(*pt1, *pt2);
    return sgn(d) > 0 ? -1 : 1;
}

int cmp2(const void *a, const void *b) {
    struct PT *pt1 = (struct PT *)a;
    struct PT *pt2 = (struct PT *)b;
    return sect(*pt1) == sect(*pt2) && sgn(vect(*pt1, *pt2)) == 0 ? 0 : 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
    struct PT g = gravityCenter(p, n);
    for (int i = 0; i < n; ++i) p[i] = pt_sub(p[i], g);
    qsort(p, n, sizeof(struct PT), cmp1);
    struct PT q;
    for (int i = 0; i < n; ++i) {
        int fp = lower_bound(p, p + n, pt_neg(p[i])) - p;
        if (pt_neq(p[fp], pt_neg(p[i]))) {
            q = p[i];
            break;
        }
        if (i == n - 1) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        struct PT m = pt_div(pt_add(p[i], q), 2);
        struct PT nv = normalLine(create_pt(0, 0), m);
        if (sect(nv) >= 3) nv = pt_neg(nv);
        v.push_back(nv);
    }
    qsort(v, sizeof(v) / sizeof(v[0]), sizeof(struct PT), cmp1);
    v.resize(unique(v.begin(), v.end(), cmp2) - v.begin());
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < n; ++j)
            d[j] = scal(v[i], proj(p[j], create_pt(0, 0), v[i])) / dis(v[i]);
        qsort(d, n, sizeof(DB), cmp1);
        int flg = 1;
        for (int j = 0; j < n / 2; ++j)
            if (sgn(d[j] + d[n - 1 - j])) flg = 0;
        ans += flg;
    }
    printf("%d\n", ans);
    return 0;
}
