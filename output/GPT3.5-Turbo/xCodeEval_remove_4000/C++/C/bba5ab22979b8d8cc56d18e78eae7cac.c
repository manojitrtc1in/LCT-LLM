#include <stdio.h>
#include <math.h>

#define EPS 1e-8

typedef struct {
    double x, y;
} point;

typedef struct {
    point p;
    double r;
} circle;

int cmp(double x, double y, double tol) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

point make_point(double x, double y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

point add_points(point p, point q) {
    point sum;
    sum.x = p.x + q.x;
    sum.y = p.y + q.y;
    return sum;
}

point subtract_points(point p, point q) {
    point diff;
    diff.x = p.x - q.x;
    diff.y = p.y - q.y;
    return diff;
}

point multiply_point(point p, double t) {
    point product;
    product.x = p.x * t;
    product.y = p.y * t;
    return product;
}

point divide_point(point p, double t) {
    point quotient;
    quotient.x = p.x / t;
    quotient.y = p.y / t;
    return quotient;
}

double dot_product(point p, point q) {
    return p.x * q.x + p.y * q.y;
}

double cross_product(point p, point q) {
    return p.x * q.y - p.y * q.x;
}

int point_cmp(point p, point q) {
    if (int t = cmp(p.x, q.x, EPS)) return t;
    return cmp(p.y, q.y, EPS);
}

int point_equal(point p, point q) {
    return point_cmp(p, q) == 0;
}

int point_less(point p, point q) {
    return point_cmp(p, q) < 0;
}

double point_distance(point p, point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

point pivot;

double point_abs(point p) {
    return hypot(p.x, p.y);
}

double point_arg(point p) {
    return atan2(p.y, p.x);
}

int ccw(point p, point q, point r) {
    return cmp(cross_product(subtract_points(p, r), subtract_points(q, r)), 0, EPS);
}

double angle(point p, point q, point r) {
    point u = subtract_points(p, q);
    point v = subtract_points(r, q);
    return atan2(cross_product(u, v), dot_product(u, v));
}

double dist2(point p, point q) {
    return dot_product(subtract_points(p, q), subtract_points(p, q));
}

point id19(point p) {
    return make_point(-p.y, p.x);
}

point id5(point p) {
    return make_point(p.y, -p.x);
}

point id14(point p, double t) {
    return make_point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}

point id9(point a, point b, point c) {
    return add_points(a, multiply_point(subtract_points(b, a), dot_product(subtract_points(c, a), subtract_points(b, a)) / dot_product(subtract_points(b, a), subtract_points(b, a))));
}

point id20(point a, point b, point c) {
    double r = dot_product(subtract_points(c, a), subtract_points(b, a)) / dot_product(subtract_points(b, a), subtract_points(b, a));
    if (fabs(r) < EPS) return a;
    if (r < 0) return a;
    if (r > 1) return b;
    return add_points(a, multiply_point(subtract_points(b, a), r));
}

int between(point p, point q, point r) {
    return ccw(p, q, r) == 0 && cmp(dot_product(subtract_points(p, q), subtract_points(r, q)), 0, EPS) <= 0;
}

double id10(point a, point b, point c) {
    return sqrt(dist2(c, id20(a, b, c)));
}

double id2(double x, double y, double z, double a, double b, double c, double d) {
    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}

int linesParallel(point a, point b, point c, point d) {
    return cmp(fabs(cross_product(subtract_points(b, a), subtract_points(c, d))), 0, EPS);
}

int id0(point a, point b, point c, point d) {
    return linesParallel(a, b, c, d) && cmp(fabs(cross_product(subtract_points(a, b), subtract_points(a, c))), 0, EPS) && cmp(fabs(cross_product(subtract_points(c, d), subtract_points(c, a))), 0, EPS);
}

int id13(point p, point q, point r, point s) {
    point A = subtract_points(q, p);
    point B = subtract_points(s, r);
    point C = subtract_points(r, p);
    point D = subtract_points(s, q);
    int a = cmp(cross_product(A, C)) + 2 * cmp(cross_product(A, D));
    int b = cmp(cross_product(B, C)) + 2 * cmp(cross_product(B, D));
    if (a == 3 || a == -3 || b == 3 || b == -3) return 0;
    if (a || b || point_equal(p, r) || point_equal(p, s) || point_equal(q, r) || point_equal(q, s)) return 1;
    int t = (point_less(p, r)) + (point_less(p, s)) + (point_less(q, r)) + (point_less(q, s));
    return t != 0 && t != 4;
}

point id8(point p, point q, point r, point s) {
    point a = subtract_points(q, p);
    point b = subtract_points(s, r);
    point c = make_point(dot_product(make_point(a.x, b.x), make_point(p.x * q.y - q.x * p.y, r.x * s.y - s.x * r.y)), dot_product(make_point(a.y, b.y), make_point(p.x * q.y - q.x * p.y, r.x * s.y - s.x * r.y))) / cross_product(a, b);
    return c;
}

int id1(point p1, point p2, double r, point *c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = ((r * r) / d2) - 0.25;
    if (det < 0.0) return 0;
    double h = sqrt(det);
    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return 1;
}

point id4(point a, point b, point c) {
    b = divide_point(add_points(a, b), 2);
    c = divide_point(add_points(a, c), 2);
    return id8(b, add_points(b, id5(subtract_points(a, b))), c, add_points(c, id5(subtract_points(a, c))));
}

point id18(point a, point b, point c) {
    point d = add_points(b, id14(subtract_points(c, b), angle(c, b, a) / 2));
    point e = add_points(c, id14(subtract_points(a, c), angle(a, c, b) / 2));
    return id8(b, d, c, e);
}

int in_poly(point p, point *T, int N) {
    double a = 0;
    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i + 1) % N])) return -1;
        a += angle(T[i], p, T[(i + 1) % N]);
    }
    return cmp(a, 0, EPS) != 0;
}

double poly_area(point *T, int N) {
    double s = 0;
    for (int i = 0; i < N; i++)
        s += cross_product(T[i], T[(i + 1) % N]);
    return s / 2;
}

point id17(point *p, int n) {
    point c = make_point(0, 0);
    double scale = 6.0 * poly_area(p, n);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        c = add_points(c, multiply_point(add_points(p[i], p[j]), p[i].x * p[j].y - p[j].x * p[i].y));
    }
    return divide_point(c, scale);
}

int id6(point p, point q) {
    point P = subtract_points(p, pivot);
    point Q = subtract_points(q, pivot);
    double R = cross_product(P, Q);
    if (cmp(R, 0, EPS)) return R > 0;
    return cmp(dot_product(P, P), dot_product(Q, Q), EPS) < 0;
}

void id15(point *T, int N, point *U, int *M) {
    int j = 0, k;
    pivot = T[0];
    for (int i = 0; i < N; i++) {
        while (j > 1 && ccw(U[j - 1], U[j - 2], T[i]) >= 0) j--;
        U[j++] = T[i];
    }
    for (k = N - 2; k >= 0 && ccw(T[0], T[N - 1], T[k]) == 0; k--);
    for (int i = k + 1; i < N; i++) {
        while (j > 1 && ccw(U[j - 1], U[j - 2], T[i]) >= 0) j--;
        U[j++] = T[i];
    }
    *M = j;
}

void id16(point *P, int N, point *Q, int M, point *R, int *K) {
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
    *K = 0;
    while ((aa < N || ba < M) && aa < 2 * N && ba < 2 * M) {
        point p1 = P[a], p2 = P[(a + 1) % N], q1 = Q[b], q2 = Q[(b + 1) % M];
        point A = subtract_points(p2, p1), B = subtract_points(q2, q1);
        int cross = cmp(cross_product(A, B), 0, EPS), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(dot_product(subtract_points(p1, q1), subtract_points(p2, q1)), 0, EPS) < 0) {
            if (between(p1, q1, p2)) R[(*K)++] = q1;
            if (between(p1, q2, p2)) R[(*K)++] = q2;
            if (between(q1, p1, q2)) R[(*K)++] = p1;
            if (between(q1, p2, q2)) R[(*K)++] = p2;
            if (*K < 2) return;
            inflag = 1;
            break;
        } else if (cross != 0 && id13(p1, p2, q1, q2)) {
            if (inflag == 0) aa = ba = 0;
            R[(*K)++] = id8(p1, p2, q1, q2);
            inflag = (hb > 0) ? 1 : -1;
        }
        if (cross == 0 && hb < 0 && ha < 0) return;
        int t = cross == 0 && hb == 0 && ha == 0;
        if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
            if (inflag == -1) R[(*K)++] = q2;
            ba++; b++; b %= M;
        } else {
            if (inflag == 1) R[(*K)++] = p2;
            aa++; a++; a %= N;
        }
    }
    if (inflag == 0) {
        if (in_poly(P[0], Q, M)) {
            for (int i = 0; i < N; i++) R[(*K)++] = P[i];
            return;
        }
        if (in_poly(Q[0], P, N)) {
            for (int i = 0; i < M; i++) R[(*K)++] = Q[i];
            return;
        }
    }
}

int in_poly(point p, point *T, int N) {
    double a = 0;
    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i + 1) % N])) return -1;
        a += angle(T[i], p, T[(i + 1) % N]);
    }
    return cmp(a, 0, EPS) != 0;
}

double id11(point a, point b, point c, double r, point *ret) {
    double d = point_distance(a, b);
    if (d > r + r || d + fmin(r, r) < fmax(r, r)) return 0;
    double x = (d * d - r * r + r * r) / (d + d);
    double y = sqrt(r * r - x * x);
    point v = divide_point(subtract_points(b, a), d);
    ret[0] = add_points(a, multiply_point(v, x));
    if (y > 0) ret[1] = add_points(ret[0], multiply_point(id5(v), y));
    return y;
}

double id3(point a, point b, double r, double R, point *ret) {
    double d = point_distance(a, b);
    if (d > r + R || d + fmin(r, R) < fmax(r, R)) return 0;
    double x = (d * d - R * R + r * r) / (d + d);
    double y = sqrt(r * r - x * x);
    point v = divide_point(subtract_points(b, a), d);
    ret[0] = add_points(a, multiply_point(v, x));
    if (y > 0) ret[1] = add_points(ret[0], multiply_point(id5(v), y));
    return y;
}

int id7(point c, double r, point p, point *resp) {
    point toCenter = subtract_points(c, p);
    if (cmp(r - point_abs(toCenter), 0, EPS) <= 0) {
        resp[0] = p;
        resp[1] = p;
        return 2;
    }
    double angle = asin(r / point_abs(toCenter));
    point uni = divide_point(toCenter, point_abs(toCenter));
    double tam = sqrt(point_abs(toCenter) - r * r);
    point origi = multiply_point(uni, tam);
    point p1 = add_points(p, id14(origi, angle));
    resp[0] = p1;
    point p2 = add_points(p, id14(origi, -angle));
    resp[1] = p2;
    return 2;
}

int main() {
    int xp, yp, vp, x, y, v, r;
    scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
    double R = hypot(yp, xp);
    double initial = atan2(yp, xp);
    double bot = 0;
    double timeTot = (2 * M_PI * R) / vp;
    double top = 100000000000000.0;
    while (cmp(top, bot, EPS) == 1) {
        double mid = (top + bot) / 2;
        double angle = ((2 * M_PI * mid) / timeTot) + initial;
        point loc = make_point(cos(angle) * R, sin(angle) * R);
        if (pode(loc, mid)) {
            top = mid;
        } else {
            bot = mid;
        }
    }
    printf("%.7f\n", bot);
    return 0;
}
