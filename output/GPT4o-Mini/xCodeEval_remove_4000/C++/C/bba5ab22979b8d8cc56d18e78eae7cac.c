#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 10000000
#define EPS 1e-8

typedef struct {
    double x, y;
} point;

point pivot;

int cmp(double x, double y) {
    return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

point create_point(double x, double y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

point add(point p, point q) { return create_point(p.x + q.x, p.y + q.y); }
point sub(point p, point q) { return create_point(p.x - q.x, p.y - q.y); }
point mul(point p, double t) { return create_point(p.x * t, p.y * t); }
point div(point p, double t) { return create_point(p.x / t, p.y / t); }
double dot(point p, point q) { return p.x * q.x + p.y * q.y; }
double cross(point p, point q) { return p.x * q.y - p.y * q.x; }

int point_cmp(point p, point q) {
    if (int t = cmp(p.x, q.x)) return t;
    return cmp(p.y, q.y);
}

bool point_eq(point p, point q) { return point_cmp(p, q) == 0; }
bool point_neq(point p, point q) { return point_cmp(p, q) != 0; }
bool point_lt(point p, point q) { return point_cmp(p, q) < 0; }

double abs_point(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef struct {
    point *points;
    int size;
} polygon;

double angle(point p, point q, point r) {
    point u = sub(p, q), v = sub(r, q);
    return atan2(cross(u, v), dot(u, v));
}

double dist2(point p, point q) { return dot(sub(p, q), sub(p, q)); }

point id19(point p) { return create_point(-p.y, p.x); }
point id5(point p) { return create_point(p.y, -p.x); }
point id14(point p, double t) { 
    return create_point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)); 
}

int ccw(point p, point q, point r) {
    return cmp(cross(sub(p, r), sub(q, r)));
}

bool between(point p, point q, point r) {
    return ccw(p, q, r) == 0 && cmp(cross(sub(p, q), sub(r, q))) <= 0;
}

double id10(point a, point b, point c) {
    return sqrt(dist2(c, id20(a, b, c)));
}

double id2(double x, double y, double z, double a, double b, double c, double d) {
    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}

bool linesParallel(point a, point b, point c, point d) { 
    return fabs(cross(sub(b, a), sub(c, d))) < EPS; 
}

bool id0(point a, point b, point c, point d) { 
    return linesParallel(a, b, c, d) && fabs(cross(sub(a, b), sub(a, c))) < EPS && fabs(cross(sub(c, d), sub(c, a))) < EPS; 
}

bool id13(point p, point q, point r, point s) {
    point A = sub(q, p), B = sub(s, r), C = sub(r, p), D = sub(s, q);
    int a = cmp(cross(A, C)) + 2 * cmp(cross(A, D));
    int b = cmp(cross(B, C)) + 2 * cmp(cross(B, D));
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || point_eq(p, r) || point_eq(p, s) || point_eq(q, r) || point_eq(q, s)) return true;
    int t = (point_lt(p, r)) + (point_lt(p, s)) + (point_lt(q, r)) + (point_lt(q, s));
    return t != 0 && t != 4;
}

point id8(point p, point q, point r, point s) {
    point a = sub(q, p), b = sub(s, r), c = create_point(cross(a, b), cross(r, s));
    return div(create_point(cross(create_point(a.x, b.x), c), cross(create_point(a.y, b.y), c)), cross(a, b));
}

bool id1(point p1, point p2, double r, point *c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = (r * r / d2) - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; 
}

point id4(point a, point b, point c) {
    b = div(add(a, b), 2);
    c = div(add(a, c), 2);
    return id8(b, add(b, id5(sub(a, b))), c, add(c, id5(sub(a, c))));
}

point id18(point a, point b, point c) {
    point d = add(b, id14(sub(c, b), angle(c, b, a) / 2));
    point e = add(c, id14(sub(a, c), angle(a, c, b) / 2));
    return id8(b, d, c, e);
}

polygon id11(point a, point b, point c, double r) {
    polygon ret;
    ret.points = (point *)malloc(2 * sizeof(point));
    ret.size = 0;
    b = sub(b, a);
    a = sub(a, c);
    double A = dot(b, b);
    double B = dot(a, b);
    double C = (dot(a, a) - r * r);
    double D = B * B - A * C;
    if (D < -EPS) return ret;
    ret.points[ret.size++] = add(c, add(a, mul(b, (-B + sqrt(D + EPS)) / A)));
    if (D > EPS)
        ret.points[ret.size++] = add(c, add(a, mul(b, (-B - sqrt(D)) / A)));
    return ret;
}

polygon id3(point a, point b, double r, double R) {
    polygon ret;
    ret.points = (point *)malloc(2 * sizeof(point));
    ret.size = 0;
    double d = sqrt(dist2(a, b));
    if (d > r + R || d + fmin(r, R) < fmax(r, R)) return ret;
    double x = (d * d - R * R + r * r) / (2 * d);
    double y = sqrt(r * r - x * x);
    point v = div(sub(b, a), d);
    ret.points[ret.size++] = add(a, add(mul(v, x), id19(v) * y));
    if (y > 0)
        ret.points[ret.size++] = add(a, add(mul(v, x), id19(v) * -y));
    return ret;
}

polygon id7(point c, double r, point p) {
    polygon resp;
    resp.points = (point *)malloc(2 * sizeof(point));
    resp.size = 0;
    point toCenter = sub(c, p);
    if (cmp(r - sqrt(dist2(toCenter, create_point(0, 0)))) <= 0) {
        resp.points[resp.size++] = p;
        resp.points[resp.size++] = p;
        return resp;
    }
    double angle = asin(r / sqrt(dist2(toCenter, create_point(0, 0))));
    point uni = div(toCenter, sqrt(dist2(toCenter, create_point(0, 0))));
    double tam = sqrt(dist2(toCenter, create_point(0, 0)) - r * r);
    point origi = mul(uni, tam);
    point p1 = add(p, id14(origi, angle));
    resp.points[resp.size++] = p1;
    point p2 = add(p, id14(origi, -angle));
    resp.points[resp.size++] = p2;
    return resp;
}

int in_poly(point p, polygon T) {
    double a = 0; 
    int N = T.size;
    for (int i = 0; i < N; i++) {
        if (between(T.points[i], p, T.points[(i + 1) % N])) return -1;
        a += angle(T.points[i], p, T.points[(i + 1) % N]);
    }
    return cmp(a) != 0;
}

double poly_area(polygon T) {
    double s = 0; 
    int n = T.size;
    for (int i = 0; i < n; i++)
        s += cross(T.points[i], T.points[(i + 1) % n]);
    return s / 2;
}

point id17(polygon *p) {
    point c = create_point(0, 0);
    double scale = 6.0 * poly_area(*p);
    for (int i = 0; i < p->size; i++) {
        int j = (i + 1) % p->size;
        c = add(c, mul(add(p->points[i], p->points[j]), (p->points[i].x * p->points[j].y - p->points[j].x * p->points[i].y)));
    }
    return div(c, scale);
}

bool id6(point p, point q) {
    point P = sub(p, pivot), Q = sub(q, pivot);
    double R = cross(P, Q);
    if (cmp(R)) return R > 0;
    return cmp(dist2(P, create_point(0, 0)), dist2(Q, create_point(0, 0))) < 0;
}

polygon id15(point *T, int n) {
    int j = 0, k;
    polygon U;
    U.points = (point *)malloc(n * sizeof(point));
    U.size = 0;
    pivot = *min_element(T, T + n);
    qsort(T, n, sizeof(point), id6);
    for (k = n - 2; k >= 0 && ccw(T[0], T[n - 1], T[k]) == 0; k--);
    reverse((k + 1) + T);
    for (int i = 0; i < n; i++) {
        while (j > 1 && ccw(U.points[j - 1], U.points[j - 2], T[i]) >= 0) j--;
        U.points[j++] = T[i];
    }
    U.size = j;
    return U;
}

polygon id16(polygon P, polygon Q) {
    int m = Q.size, n = P.size;
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
    polygon R;
    R.points = (point *)malloc((m + n) * sizeof(point));
    R.size = 0;
    while ((aa < n || ba < m) && aa < 2 * n && ba < 2 * m) {
        point p1 = P.points[a], p2 = P.points[(a + 1) % n], q1 = Q.points[b], q2 = Q.points[(b + 1) % m];
        point A = sub(p2, p1), B = sub(q2, q1);
        int cross = cmp(cross(A, B)), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(dot(A, B)) < 0) {
            if (between(p1, q1, p2)) R.points[R.size++] = q1;
            if (between(p1, q2, p2)) R.points[R.size++] = q2;
            if (between(q1, p1, q2)) R.points[R.size++] = p1;
            if (between(q1, p2, q2)) R.points[R.size++] = p2;
            if (R.size < 2) return (polygon){NULL, 0};
            inflag = 1; 
            break;
        } else if (cross != 0 && id13(p1, p2, q1, q2)) {
            if (inflag == 0) aa = ba = 0;
            R.points[R.size++] = id8(p1, p2, q1, q2);
            inflag = (hb > 0) ? 1 : -1;
        }
        if (cross == 0 && hb < 0 && ha < 0) return R;
        bool t = cross == 0 && hb == 0 && ha == 0;
        if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
            if (inflag == -1) R.points[R.size++] = q2;
            ba++; b++; b %= m;
        } else {
            if (inflag == 1) R.points[R.size++] = p2;
            aa++; a++; a %= n;
        }
    }
    if (inflag == 0) {
        if (in_poly(P.points[0], Q) == 1) return P;
        if (in_poly(Q.points[0], P) == 1) return Q;
    }
    R.size = unique(R.points, R.points + R.size);
    if (R.size > 1 && point_eq(R.points[0], R.points[R.size - 1])) R.size--;
    return R;
}

const double PI = acos(-1);
int xp, yp, vp, x, y, v, r;

point origin = create_point(0, 0);
int pode(point loc, double time) {
    point nave = create_point(x, y);
    if (cmp(id10(loc, nave, origin), r) >= 0) {
        return cmp(time, abs_point(sub(nave, loc)) / v) >= 0;
    } else {
        double distN = sqrt(dist2(nave, origin) - r * r);
        double distL = sqrt(dist2(loc, origin) - r * r);
        double a = abs_point(sub(nave, loc));
        double b = abs_point(nave);
        double c = abs_point(loc);
        double bigcos = (b * b + c * c - a * a) / (2 * b * c);
        double id12 = acos(bigcos) - fabs(atan(distN / r)) - fabs(atan(distL / r));
        double menor = distN + distL + fabs(r * id12);
        return cmp(time, menor / v) >= 0;
    }
}

int main() { 
    scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
    double R = hypot(yp, xp);
    double initial = atan2(yp, xp);
    double bot = 0;
    double timeTot = (2 * PI * R) / vp;
    double top = 100000000000000.0;
    while (cmp(top, bot) == 1) {
        double mid = (top + bot) / 2;
        double angle = ((2 * PI * mid) / timeTot) + initial; 
        point loc = create_point(cos(angle) * R, sin(angle) * R);
        if (pode(loc, mid)) {
            top = mid;
        } else {
            bot = mid;
        }
    }
    printf("%.7f\n", bot);
    return 0;
}
