#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

#define EPS 1e-9
#define OO 1e18

typedef struct {
    long double x, y;
} point;

typedef enum {
    IN, OUT, BOUNDRY
} STATE;

long double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

long double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

point vec(point a, point b) {
    return (point){b.x - a.x, b.y - a.y};
}

long double length(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

long double lengthSqr(point a) {
    return a.x * a.x + a.y * a.y;
}

point normalize(point a) {
    long double len = length(a);
    return (point){a.x / len, a.y / len};
}

point rotate(point p, long double angle) {
    return (point){p.x * cos(angle) - p.y * sin(angle), p.x * sin(angle) + p.y * cos(angle)};
}

point mid(point a, point b) {
    return (point){(a.x + b.x) / 2, (a.y + b.y) / 2};
}

bool intersect(const point a, const point b, const point p, const point q, point *ret) {
    long double d1 = cross(vec(p, a), vec(b, a));
    long double d2 = cross(vec(q, a), vec(b, a));
    *ret = (point){(d1 * q.x - d2 * p.x) / (d1 - d2), (d1 * q.y - d2 * p.y) / (d1 - d2)};
    if (fabs(d1 - d2) > EPS) return true;
    return false;
}

bool id4(const point a, const point b, const point p) {
    return fabs(cross(vec(a, b), vec(a, p))) < EPS && dot(vec(a, p), vec(a, b)) > -EPS && dot(vec(b, a), vec(b, p)) > -EPS;
}

long double id21(const point a, const point b, const point p) {
    if (dot(vec(a, b), vec(a, p)) < EPS)
        return length(vec(a, p));
    if (dot(vec(b, a), vec(b, p)) < EPS)
        return length(vec(b, p));
    return fabs(cross(vec(a, b), vec(a, p))) / length(vec(a, b));
}

int id1(const point cen, const long double r, const point p, point *r1, point *r2) {
    STATE s = circlePoint(cen, r, p);
    if (s != OUT) {
        *r1 = *r2 = p;
        return s == BOUNDRY;
    }
    point cp = vec(cen, p);
    long double h = length(cp);
    long double a = acos(r / h);
    cp = normalize(cp);
    *r1 = (point){cp.x * r + cen.x, cp.y * r + cen.y};
    *r2 = (point){cp.x * r * cos(-a) + cen.x, cp.y * r * sin(-a) + cen.y};
    return 2;
}

long double arc_length(point a, point b, long double r) {
    long double Ang = atan2(a.y, a.x) - atan2(b.y, b.x);
    if (Ang < 0) {
        Ang += 2 * M_PI;
    }
    if (Ang > M_PI) {
        Ang = 2 * M_PI - Ang;
    }
    return Ang * r;
}

int main() {
    int Xc, Yc, Vc, Xb, Yb, Vb, r;
    scanf("%d %d %d", &Xc, &Yc, &Vc);
    scanf("%d %d %d %d", &Xb, &Yb, &Vb, &r);
    point planet = {Xc, Yc};
    point ship = {Xb, Yb};
    long double R = length(planet);
    long double w = Vc / R;
    long double left = 0, right = 1ll << 30;

    for (int i = 0; i < 300; i++) {
        long double mid = (right + left) / 2;
        point id23 = rotate(planet, w * mid);
        long double distance;

        if (id21(ship, id23, (point){0, 0}) < r) {
            point a, b, c, d;
            id1((point){0, 0}, r, ship, &a, &b);
            id1((point){0, 0}, r, id23, &c, &d);
            distance = 1ll << 30;
            distance = fmin(distance, length(vec(ship, a)) + length(vec(c, id23)) + arc_length(a, c, r));
            distance = fmin(distance, length(vec(ship, b)) + length(vec(c, id23)) + arc_length(b, c, r));
            distance = fmin(distance, length(vec(ship, a)) + length(vec(d, id23)) + arc_length(a, d, r));
            distance = fmin(distance, length(vec(ship, b)) + length(vec(d, id23)) + arc_length(b, d, r));
        } else {
            distance = length(vec(ship, id23));
        }

        if (distance / Vb < mid) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%.10Lf\n", left);
    return 0;
}
