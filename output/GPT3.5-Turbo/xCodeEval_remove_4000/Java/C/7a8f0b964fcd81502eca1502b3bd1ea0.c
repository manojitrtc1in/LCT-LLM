#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EPS 1e-7

typedef struct {
    double x;
    double y;
} id9;

typedef struct {
    id9 p1;
    id9 p2;
    double A;
    double B;
    double C;
} id5;

typedef struct {
    id9 c;
    double r;
} id6;

double sqr(double x) {
    return x * x;
}

double id13(double a11, double a12, double a21, double a22) {
    return a11 * a22 - a12 * a21;
}

double cross(id9 p0, id9 p1, id9 p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double getCos(double a, double b, double c) {
    return 0.5 * (a * a + b * b - c * c) / (a * b);
}

double id0(id9 c, id9 p) {
    return atan2(p.y - c.y, p.x - c.x);
}

double id2(id9 p1, id9 p2) {
    return sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
}

double dist(id9 p1, id9 p2) {
    return sqrt(id2(p1, p2));
}

int between(double a, double x, double b) {
    return a <= x && x <= b;
}

int range(double a, double x, double b) {
    return between(a - EPS, x, b + EPS);
}

int interval(double a, double x, double b) {
    return between(a + EPS, x, b - EPS);
}

double sqrt(double x) {
    if (x < -EPS) {
        printf("Invalid argument for sqrt\n");
        exit(1);
    }
    return sqrt(fmax(0.0, x));
}

double acos(double x) {
    if (!range(-1.0, x, 1.0)) {
        printf("Invalid argument for acos\n");
        exit(1);
    }
    return acos(fmax(-1.0, fmin(1.0, x)));
}

double asin(double x) {
    if (!range(-1.0, x, 1.0)) {
        printf("Invalid argument for asin\n");
        exit(1);
    }
    return asin(fmax(-1.0, fmin(1.0, x)));
}

void check(int state) {
    if (!state) {
        printf("Error\n");
        exit(1);
    }
}

id9 id9_set(double x, double y) {
    id9 p;
    p.x = x;
    p.y = y;
    return p;
}

id9 id9_copy(id9 p) {
    return id9_set(p.x, p.y);
}

id9 id9_add(id9 v1, id9 v2) {
    return id9_set(v1.x + v2.x, v1.y + v2.y);
}

id9 id9_inc(id9 *v1, id9 v2) {
    v1->x += v2.x;
    v1->y += v2.y;
    return *v1;
}

id9 id9_sub(id9 v1, id9 v2) {
    return id9_set(v1.x - v2.x, v1.y - v2.y);
}

id9 id9_dec(id9 *v1, id9 v2) {
    v1->x -= v2.x;
    v1->y -= v2.y;
    return *v1;
}

id9 id9_mul(id9 v, double K) {
    return id9_set(K * v.x, K * v.y);
}

id9 id9_scale(id9 *v, double K) {
    v->x *= K;
    v->y *= K;
    return *v;
}

double id9_len(id9 v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

id9 id9_norm(id9 v, double newLen) {
    return id9_scale(&v, newLen / id9_len(v));
}

id9 id9_normalize(id9 *v, double newLen) {
    return id9_scale(v, newLen / id9_len(*v));
}

double id9_scalarProduct(id9 v1, id9 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double id9_crossProduct(id9 v1, id9 v2) {
    return v1.x * v2.y - v2.x * v1.y;
}

id9 id9_rotate90(id9 v) {
    return id9_set(-v.y, v.x);
}

id9 id9_rotate(id9 v, double angle) {
    double cos = cos(angle);
    double sin = sin(angle);
    return id9_set(v.x * cos - v.y * sin, v.x * sin + v.y * cos);
}

id9 id9_turn90(id9 v) {
    return id9_set(-v.y, v.x);
}

id9 id9_turn(id9 v, double angle) {
    double cos = cos(angle);
    double sin = sin(angle);
    return id9_set(v.x * cos - v.y * sin, v.x * sin + v.y * cos);
}

id9 id9_turn(id9 v, double cos, double sin) {
    return id9_set(v.x * cos - v.y * sin, v.x * sin + v.y * cos);
}

int id9_equals(id9 p1, id9 p2) {
    return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

id5 id5_set(id9 p1, id9 p2) {
    id5 l;
    l.p1 = p1;
    l.p2 = p2;
    l.A = p2.y - p1.y;
    l.B = p1.x - p2.x;
    l.C = -(l.A * p1.x + l.B * p1.y);
    return l;
}

id5 id5_set_p_l(id9 p, id5 l) {
    id5 line;
    line.p1 = p;
    line.p2 = id9_add(p, id9_turn90(id9_sub(l.p2, l.p1)));
    line.A = -l.B;
    line.B = l.A;
    line.C = -(line.A * line.p1.x + line.B * line.p1.y);
    return line;
}

id5 id5_set_r_l(double r, id5 l) {
    id9 v = id9_normalize(id9_turn90(id9_sub(l.p2, l.p1)), r);
    id5 line;
    line.p1 = id9_dec(&l.p1, v);
    line.p2 = id9_dec(&l.p2, v);
    line.A = l.A;
    line.B = l.B;
    line.C = -(line.A * line.p1.x + line.B * line.p1.y);
    return line;
}

id5 id5_move(id5 l, id9 v) {
    id9_inc(&l.p1, v);
    id9_inc(&l.p2, v);
    l.C = -(l.A * l.p1.x + l.B * l.p1.y);
    return l;
}

id5 id5_shift(id5 l, double r) {
    id9 v = id9_normalize(id9_turn90(id9_sub(l.p2, l.p1)), r);
    id9_dec(&l.p1, v);
    id9_dec(&l.p2, v);
    l.C = -(l.A * l.p1.x + l.B * l.p1.y);
    return l;
}

double id5_calc(id5 l, id9 p) {
    return l.A * p.x + l.B * p.y + l.C;
}

int id5_lay(id5 l, id9 p) {
    return range(r, dist(c, p), r);
}

int id5_contains(id5 l, id9 p) {
    if (!id5_lay(l, p))
        return 0;
    return range(0.0, id5_getT(l, p), 1.0);
}

double id5_getT(id5 l, id9 p) {
    if (!id5_lay(l, p))
        return NAN;
    if (fabs(l.A) > EPS)
        return (p.y - l.p1.y) / l.A;
    if (fabs(l.B) > EPS)
        return (l.p1.x - p.x) / l.B;
    printf("Bad line\n");
    exit(1);
}

id9 id5_getPoint(id5 l, double t) {
    return id9_set(l.p1.x - l.B * t, l.p1.y + l.A * t);
}

double id5_dist(id5 l, id9 p) {
    return fabs(id5_calc(l, p)) / sqrt(l.A * l.A + l.B * l.B);
}

id9 id5_dir(id5 l) {
    return id9_set(-l.B, l.A);
}

id9 id5_normal(id5 l) {
    return id9_set(l.A, l.B);
}

id9 id5_projection(id5 l, id9 p) {
    double t = (l.B * (l.p1.x - p.x) - l.A * (l.p1.y - p.y)) / (l.A * l.A + l.B * l.B);
    return id9_set(l.p1.x - l.B * t, l.p1.y + l.A * t);
}

id5 id5_projection_l(id5 l1, id5 l2) {
    return id5_set_p_l(id5_projection(l1, l2.p1), l2);
}

id9 id6_set(double x, double y, double r) {
    id9 c = id9_set(x, y);
    id6 circle;
    circle.c = c;
    circle.r = r;
    return circle;
}

double id6_area(id6 c) {
    return PI * c.r * c.r;
}

int id6_lay(id6 c, id9 p) {
    return range(c.r, dist(c.c, p), c.r);
}

int id6_contains(id6 c, id9 p) {
    return dist(c.c, p) < c.r + EPS;
}

double id4(id9 p1, id9 p2) {
    if (hasCSC(p1, p2, star)) {
        id9 tp1[2], tp2[2];
        id10(p1, star, tp1);
        id10(p2, star, tp2);
        double ret = 1e100;
        ret = fmin(ret, id1(p1, p2, tp1[0], tp2[0]));
        ret = fmin(ret, id1(p1, p2, tp1[0], tp2[1]));
        ret = fmin(ret, id1(p1, p2, tp1[1], tp2[0]));
        ret = fmin(ret, id1(p1, p2, tp1[1], tp2[1]));
        return ret;
    }
    return dist(p1, p2);
}

int hasCSC(id9 p1, id9 p2, id6 c) {
    double A = p2.y - p1.y;
    double B = p1.x - p2.x;
    double d = A * A + B * B;
    double dist = 0.0;
    if (fabs(d) < EPS) {
        dist = dist(p1, c.c);
    } else {
        double t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d;
        if (0.0 <= t && t <= 1.0) {
            dist = sqrt(sqr(p1.x - B * t - c.c.x) + sqr(p1.y + A * t - c.c.y));
        } else {
            dist = fmin(dist(p1, c.c), dist(p2, c.c));
        }
    }
    return dist <= c.r + EPS;
}

double id1(id9 p1, id9 p2, id9 tp1, id9 tp2) {
    double phi = acos(fmax(-1.0, fmin(1.0, id9_scalarProduct(tp1, tp2) / id9_len(tp1) / id9_len(tp2))));
    return dist(p1, tp1) + dist(p2, tp2) + star.r * phi;
}

id9 cll(id5 l1, id5 l2) {
    double det = -id13(l1.A, l1.B, l2.A, l2.B);
    if (fabs(det) < EPS)
        return id9_set(NAN, NAN);
    return id9_set(id13(l1.C, l1.B, l2.C, l2.B) / det, id13(l1.A, l1.C, l2.A, l2.C) / det);
}

id9 css(id5 s1, id5 s2) {
    id9 its = cll(s1, s2);
    if (its.x != its.x || its.y != its.y)
        return id9_set(NAN, NAN);
    if (s1.p1.x <= its.x && its.x <= s1.p2.x && s1.p1.y <= its.y && its.y <= s1.p2.y &&
        s2.p1.x <= its.x && its.x <= s2.p2.x && s2.p1.y <= its.y && its.y <= s2.p2.y)
        return its;
    return id9_set(NAN, NAN);
}

void clc(id5 l, id6 c, id9 *tp1, id9 *tp2) {
    double d = dist(l.p1, c.c);
    if (d > c.r + EPS) {
        *tp1 = id9_set(NAN, NAN);
        *tp2 = id9_set(NAN, NAN);
        return;
    }
    id9 h = id5_projection(l, c.c);
    id9 v = id5_dir(l);
    double len = sqrt(c.r * c.r - d * d);
    *tp1 = id9_sub(h, id9_mul(v, len));
    *tp2 = id9_add(h, id9_mul(v, len));
}

void ccc(id6 c1, id6 c2, id9 *tp1, id9 *tp2) {
    double d = dist(c1.c, c2.c);
    if (d < EPS && c1.r < EPS && c2.r < EPS) {
        *tp1 = c1.c;
        *tp2 = c1.c;
        return;
    }
    if (d < fabs(c1.r - c2.r) - EPS || d > c1.r + c2.r + EPS || d < EPS) {
        *tp1 = id9_set(NAN, NAN);
        *tp2 = id9_set(NAN, NAN);
        return;
    }
    double cos = getCos(d, c1.r, c2.r);
    double sin = sqrt(1.0 - cos * cos);
    id9 v = id9_normalize(id9_sub(c2.c, c1.c), c1.r);
    *tp1 = id9_add(c1.c, id9_turn(v, cos, sin));
    *tp2 = id9_add(c1.c, id9_turn(v, cos, -sin));
}

id5 tcpc(id9 p, id6 c) {
    if (c.r < EPS || !id6_lay(c, p))
        return id5_set(id9_set(NAN, NAN), id9_set(NAN, NAN));
    id9 n = id9_turn90(id9_sub(c.c, p));
    return id5_set(id9_sub(p, n), id9_add(p, n));
}

void id10(id9 p, id6 c, id9 *tp1, id9 *tp2) {
    double d = dist(p, c.c);
    double cos = c.r / d;
    double sin = sqrt(1.0 - cos * cos);
    id9 v = id9_normalize(id9_sub(p, c.c), c.r);
    *tp1 = id9_turn(v, cos, sin);
    *tp2 = id9_turn(v, cos, -sin);
}

id5 tpc(id9 p, id6 c) {
    double d = dist(p, c.c);
    double sin = c.r / d;
    double cos = sqrt(1.0 - sin * sin);
    id9 v = id9_normalize(id9_sub(c.c, p), sqrt(d * d - c.r * c.r));
    id5 lines;
    lines.p1 = p;
    lines.p2 = id9_add(p, id9_turn(v, cos, sin));
    return lines;
}

void intcc(id6 c1, id6 c2, id5 *h) {
    tpc(c2.c, id6_set(c1.c, c1.r + c2.r), &h[0]);
    if (h[0].p1.x != h[0].p1.x || h[0].p1.y != h[0].p1.y) {
        return;
    }
    h[0].p1 = id9_dec(&h[0].p1, c1.r);
    h[0].p2 = id9_dec(&h[0].p2, c1.r);
}

void id7(id6 c1, id6 c2, id5 *h) {
    if (c1.r > c2.r + EPS) {
        id7(c2, c1, h);
        return;
    }
    tpc(c1.c, id6_set(c2.c, c2.r - c1.r), &h[0]);
    if (h[0].p1.x != h[0].p1.x || h[0].p1.y != h[0].p1.y) {
        return;
    }
    h[0].p1 = id9_dec(&h[0].p1, c1.r);
    h[0].p2 = id9_dec(&h[0].p2, c1.r);
}

double id1(id9 p1, id9 p2, id9 tp1, id9 tp2) {
    double phi = acos(fmax(-1.0, fmin(1.0, id9_scalarProduct(tp1, tp2) / id9_len(tp1) / id9_len(tp2))));
    return dist(p1, tp1) + dist(p2, tp2) + star.r * phi;
}

int main() {
    double xp, yp, rP, vP, omegaP, vs;
    id9 pp, ps;
    id6 star;
    double tvp;
    double ans = 3e6;
    double left, right, mid;
    int it;

    scanf("%lf %lf", &xp, &yp);
    pp = id9_set(xp, yp);
    rP = sqrt(xp * xp + yp * yp);
    scanf("%lf", &vP);
    scanf("%lf %lf", &ps.x, &ps.y);
    scanf("%lf", &vs);
    tvp = 1;
    vP /= tvp;
    vs /= tvp;
    omegaP = vP / rP;
    scanf("%lf", &star.r);

    left = 0;
    right = ans;

    for (it = 0; it < 10000; it++) {
        mid = 0.5 * (left + right);
        if (can(mid)) {
            right = mid;
            ans = fmin(ans, mid);
        } else {
            left = mid;
        }
    }

    printf("%.6lf\n", ans / tvp);

    return 0;
}

int can(double t) {
    return id4(ps, pp_rotate(t * vP / rP)) < t * vs;
}

double id4(id9 p1, id9 p2) {
    if (hasCSC(p1, p2, star)) {
        id9 tp1[2], tp2[2];
        id10(p1, star, tp1);
        id10(p2, star, tp2);
        double ret = 1e100;
        ret = fmin(ret, id1(p1, p2, tp1[0], tp2[0]));
        ret = fmin(ret, id1(p1, p2, tp1[0], tp2[1]));
        ret = fmin(ret, id1(p1, p2, tp1[1], tp2[0]));
        ret = fmin(ret, id1(p1, p2, tp1[1], tp2[1]));
        return ret;
    }
    return dist(p1, p2);
}
