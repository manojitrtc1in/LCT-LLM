#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define INF 10000000
#define EPS 1e-8

int cmp(double x, double y, double tol) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef struct {
    double x, y;
} point;

point point_init(double x, double y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

point point_add(point p, point q) { return point_init(p.x + q.x, p.y + q.y); }
point point_sub(point p, point q) { return point_init(p.x - q.x, p.y - q.y); }
point point_mul(point p, double t) { return point_init(p.x * t, p.y * t); }
point point_div(point p, double t) { return point_init(p.x / t, p.y / t); }
double point_dot(point p, point q) { return p.x * q.x + p.y * q.y; }
double point_cross(point p, point q) { return p.x * q.y - p.y * q.x; }

double abs_point(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef struct {
    point *points;
    int size;
} polygon;

typedef struct {
    point center;
    double radius;
} circle;

int ccw(point p, point q, point r) {
    return cmp(point_cross(point_sub(p, r), point_sub(q, r), 0), 0);
}

double angle(point p, point q, point r) {
    point u = point_sub(p, q), v = point_sub(r, q);
    return atan2(point_cross(u, v), point_dot(u, v));
}

double dist2(point p, point q) { return point_dot(point_sub(p, q), point_sub(p, q)); }

point id19(point p) { return point_init(-p.y, p.x); }
point id5(point p) { return point_init(p.y, -p.x); }
point id14(point p, double t) {
    return point_init(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}

point id9(point a, point b, point c) {
    return point_add(a, point_mul(point_sub(b, a), point_dot(point_sub(c, a), point_sub(b, a)) / point_dot(point_sub(b, a), point_sub(b, a))));
}

point id20(point a, point b, point c) {
    double r = point_dot(point_sub(b, a), point_sub(b, a));
    if (fabs(r) < EPS) return a;
    r = point_dot(point_sub(c, a), point_sub(b, a)) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return point_add(a, point_mul(point_sub(b, a), r));
}

bool between(point p, point q, point r) {
    return ccw(p, q, r) == 0 && cmp(point_cross(point_sub(p, q), point_sub(r, q), 0), 0) <= 0;
}

double id10(point a, point b, point c) {
    return sqrt(dist2(c, id20(a, b, c)));
}

double id2(double x, double y, double z, double a, double b, double c, double d) {
    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}

bool linesParallel(point a, point b, point c, point d) {
    return fabs(point_cross(point_sub(b, a), point_sub(c, d)) < EPS);
}

bool id0(point a, point b, point c, point d) {
    return linesParallel(a, b, c, d) && fabs(point_cross(point_sub(a, b), point_sub(a, c)) < EPS) && fabs(point_cross(point_sub(c, d), point_sub(c, a)) < EPS);
}

bool id13(point p, point q, point r, point s) {
    point A = point_sub(q, p), B = point_sub(s, r), C = point_sub(r, p), D = point_sub(s, q);
    int a = cmp(point_cross(A, C), 0) + 2 * cmp(point_cross(A, D), 0);
    int b = cmp(point_cross(B, C), 0) + 2 * cmp(point_cross(B, D), 0);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || point_equal(p, r) || point_equal(p, s) || point_equal(q, r) || point_equal(q, s)) return true;
    int t = (point_less(p, r) + point_less(p, s) + point_less(q, r) + point_less(q, s));
    return t != 0 && t != 4;
}

point id8(point p, point q, point r, point s) {
    point a = point_sub(q, p), b = point_sub(s, r), c = point_init(point_cross(p, q), point_cross(r, s));
    return point_div(point_init(point_cross(point_init(a.x, 0), c), point_cross(point_init(0, b.y), c)), point_cross(a, b));
}

bool id1(point p1, point p2, double r, point *c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = ((r * r) / d2) - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

point id4(point a, point b, point c) {
    b = point_div(point_add(a, b), 2);
    c = point_div(point_add(a, c), 2);
    return id8(b, point_add(b, id5(point_sub(a, b))), c, point_add(c, id5(point_sub(a, c))));
}

point id18(point a, point b, point c) {
    point d = point_add(b, id14(point_sub(c, b), angle(c, b, a) / 2));
    point e = point_add(c, id14(point_sub(a, c), angle(a, c, b) / 2));
    return id8(b, d, c, e);
}

polygon id11(point a, point b, point c, double r) {
    polygon ret;
    ret.points = malloc(2 * sizeof(point));
    ret.size = 0;
    b = point_sub(b, a);
    a = point_sub(a, c);
    double A = point_dot(b, b);
    double B = point_dot(a, b);
    double C = (point_dot(a, a) - r * r);
    double D = B * B - A * C;
    if (D < -EPS) return ret;
    ret.points[ret.size++] = point_add(c, point_add(a, point_mul(b, (-B + sqrt(D + EPS)) / A)));
    if (D > EPS)
        ret.points[ret.size++] = point_add(c, point_add(a, point_mul(b, (-B - sqrt(D)) / A)));
    return ret;
}

polygon id3(point a, point b, double r, double R) {
    polygon ret;
    ret.points = malloc(2 * sizeof(point));
    ret.size = 0;
    double d = sqrt(dist2(a, b));
    if (d > r + R || d + fmin(r, R) < fmax(r, R)) return ret;
    double x = (d * d - R * R + r * r) / (2 * d);
    double y = sqrt(r * r - x * x);
    point v = point_div(point_sub(b, a), d);
    ret.points[ret.size++] = point_add(a, point_add(point_mul(v, x), id19(v) * y));
    if (y > 0)
        ret.points[ret.size++] = point_add(a, point_add(point_mul(v, x), id19(v) * -y));
    return ret;
}

polygon id7(point c, double r, point p) {
    polygon resp;
    resp.points = malloc(2 * sizeof(point));
    resp.size = 0;
    point toCenter = point_sub(c, p);
    if (cmp(r - sqrt(dist2(toCenter, point_init(0, 0))), 0) <= 0) {
        resp.points[resp.size++] = p;
        resp.points[resp.size++] = p;
        return resp;
    }
    double angle = asin(r / sqrt(dist2(toCenter, point_init(0, 0))));
    point uni = point_div(toCenter, sqrt(dist2(toCenter, point_init(0, 0))));
    double tam = sqrt(dist2(toCenter, point_init(0, 0)) - r * r);
    point origi = point_mul(uni, tam);
    point p1 = point_add(p, id14(origi, angle));
    resp.points[resp.size++] = p1;
    point p2 = point_add(p, id14(origi, -angle));
    resp.points[resp.size++] = p2;
    return resp;
}

int in_poly(point p, polygon T) {
    double a = 0; int N = T.size;
    for (int i = 0; i < N; i++) {
        if (between(T.points[i], p, T.points[(i + 1) % N])) return -1;
        a += angle(T.points[i], p, T.points[(i + 1) % N]);
    }
    return cmp(a, 0, 0) != 0;
}

double poly_area(polygon T) {
    double s = 0; int n = T.size;
    for (int i = 0; i < n; i++)
        s += point_cross(T.points[i], T.points[(i + 1) % n]);
    return s / 2;
}

point id17(polygon *p) {
    point c = point_init(0, 0);
    double scale = 6.0 * poly_area(*p);
    for (int i = 0; i < p->size; i++) {
        int j = (i + 1) % p->size;
        c = point_add(c, point_mul(point_add(p->points[i], p->points[j]), (p->points[i].x * p->points[j].y - p->points[j].x * p->points[i].y)));
    }
    return point_div(c, scale);
}

bool id6(point p, point q) {
    point P = point_sub(p, point_init(0, 0)), Q = point_sub(q, point_init(0, 0));
    double R = point_cross(P, Q);
    if (cmp(R, 0, 0)) return R > 0;
    return cmp(point_dot(P, P), point_dot(Q, Q)) < 0;
}

polygon id15(polygon *T) {
    int j = 0, k, n = T->size; polygon U;
    U.points = malloc(n * sizeof(point));
    U.size = 0;
    point pivot = T->points[0];
    for (int i = 1; i < n; i++) {
        if (T->points[i].y < pivot.y || (T->points[i].y == pivot.y && T->points[i].x < pivot.x)) {
            pivot = T->points[i];
        }
    }
    // Sort points based on angle with pivot
    // (Sorting logic not implemented here)
    for (k = n - 2; k >= 0 && ccw(T->points[0], T->points[n - 1], T->points[k]) == 0; k--);
    // Reverse logic not implemented here
    for (int i = 0; i < n; i++) {
        while (j > 1 && ccw(U.points[j - 1], U.points[j - 2], T->points[i]) >= 0) j--;
        U.points[j++] = T->points[i];
    }
    U.size = j;
    return U;
}

polygon id16(polygon *P, polygon *Q) {
    int m = Q->size, n = P->size;
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
    polygon R;
    R.points = malloc((m + n) * sizeof(point));
    R.size = 0;
    while ((aa < n || ba < m) && aa < 2 * n && ba < 2 * m) {
        point p1 = P->points[a], p2 = P->points[(a + 1) % n], q1 = Q->points[b], q2 = Q->points[(b + 1) % m];
        point A = point_sub(p2, p1), B = point_sub(q2, q1);
        int cross = cmp(point_cross(A, B), 0), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(point_dot(A, B), 0) < 0) {
            if (between(p1, q1, p2)) R.points[R.size++] = q1;
            if (between(p1, q2, p2)) R.points[R.size++] = q2;
            if (between(q1, p1, q2)) R.points[R.size++] = p1;
            if (between(q1, p2, q2)) R.points[R.size++] = p2;
            if (R.size < 2) return (polygon){NULL, 0};
            inflag = 1; break;
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
        if (in_poly(P->points[0], *Q)) return *P;
        if (in_poly(Q->points[0], *P)) return *Q;
    }
    // Remove duplicates logic not implemented here
    return R;
}

const double PI = acos(-1);
int xp, yp, vp, x, y, v, r;

point origin = point_init(0, 0);
int pode(point loc, double time) {
    point nave = point_init(x, y);
    if (cmp(id10(loc, nave, origin), r) >= 0) {
        return cmp(time, abs_point(point_sub(nave, loc)) / v) >= 0;
    } else {
        double distN = sqrt(dist2(nave, origin) - r * r);
        double distL = sqrt(dist2(loc, origin) - r * r);
        double id12 = fabs(angle(nave, origin, loc)) - fabs(atan(distN / r)) - fabs(atan(distL / r));
        double menor = distN + distL + fabs(r * id12);
        return cmp(time, menor / v) >= 0;
    }
}

int main() {
    scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
    int cont = 1000000;
    double R = hypot(yp, xp);
    double initial = atan2(yp, xp);
    double bot = 0;
    double timeTot = 1000000.0;
    double t1 = (2 * PI * R) / vp;

    double top = timeTot;
    while (top - bot > EPS) {
        double mid = (top + bot) / 2;

        double angle = ((2 * PI * mid) / t1) + initial;
        point loc = point_init(cos(angle) * R, sin(angle) * R);

        if (pode(loc, mid)) {
            top = mid - EPS;
        } else {
            bot = mid + EPS;
        }
    }
    printf("%.7f\n", bot);
    return 0;
}
