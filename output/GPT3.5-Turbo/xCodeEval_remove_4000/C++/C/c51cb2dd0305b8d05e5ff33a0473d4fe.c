#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point a;
    point b;
} segment;

double cross(point p, point q) {
    return p.x * q.y - p.y * q.x;
}

point vec(point a, point b) {
    point v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

point rotate(point p, double theta) {
    point res;
    res.x = p.x * cos(theta) - p.y * sin(theta);
    res.y = p.x * sin(theta) + p.y * cos(theta);
    return res;
}

point normalize(point p) {
    double len = sqrt(p.x * p.x + p.y * p.y);
    point res;
    res.x = p.x / len;
    res.y = p.y / len;
    return res;
}

point mid(point a, point b) {
    point m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

int intersect(point a, point b, point p, point q, point *ret) {
    double d1 = cross(vec(p, a), vec(b, a));
    double d2 = cross(vec(q, a), vec(b, a));
    if (fabs(d1 - d2) > 1e-9) {
        ret->x = (d1 * q.x - d2 * p.x) / (d1 - d2);
        ret->y = (d1 * q.y - d2 * p.y) / (d1 - d2);
        return 1;
    }
    return 0;
}

int id4(point a, point b, point p) {
    if (cross(vec(a, b), vec(a, p)) != 0) return 0;
    if (vec(a, p).x * vec(a, b).x < 0) return 0;
    if (vec(b, p).x * vec(b, a).x < 0) return 0;
    return 1;
}

double length(point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

int id13(point p0, point p1, point cen, double rad, point *r1, point *r2) {
    double a, b, c, t1, t2;
    a = vec(p1, p0).x * vec(p1, p0).x + vec(p1, p0).y * vec(p1, p0).y;
    b = 2 * (vec(p1, p0).x * vec(p0, cen).x + vec(p1, p0).y * vec(p0, cen).y);
    c = vec(p0, cen).x * vec(p0, cen).x + vec(p0, cen).y * vec(p0, cen).y - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < 1e-9) {
        det = 0;
        res = 1;
    } else if (det < 0) {
        res = 0;
    } else {
        res = 2;
    }
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    r1->x = p0.x + t1 * vec(p1, p0).x;
    r1->y = p0.y + t1 * vec(p1, p0).y;
    r2->x = p0.x + t2 * vec(p1, p0).x;
    r2->y = p0.y + t2 * vec(p1, p0).y;
    return res;
}

double calcArc(point a, point b, double r) {
    double theta = fabs(atan2(b.y, b.x) - atan2(a.y, a.x));
    if (theta > M_PI) theta = 2 * M_PI - theta;
    double res = theta * r;
    return res;
}

double calcDis(point a, point c, double r, point st, point en) {
    double arc = calcArc(a, c, r);
    double res = arc + fabs(length(vec(a, st))) + fabs(length(vec(c, en)));
    return res;
}

double Calc(point st, point en, double r) {
    point a, b, c, d;
    id13((point){0, 0}, r, st, a, b);
    id13((point){0, 0}, r, en, c, d);
    double res = calcDis(a, c, r, st, en);
    res = fmin(res, calcDis(a, d, r, st, en));
    res = fmin(res, calcDis(b, c, r, st, en));
    res = fmin(res, calcDis(b, d, r, st, en));
    return res;
}

int main() {
    double xp, yp, vp, x, y, v, r, R;
    point st, en;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = length((point){xp, yp});
    double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        if (can(m)) ans = m, hi = m - 1e-9;
        else lo = m + 1e-9;
    }
    printf("%.10lf\n", ans);
    return 0;
}
