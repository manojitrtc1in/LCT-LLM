#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

#define EPS 1e-9
#define OO 1e9

typedef struct {
    double x, y;
} point;

typedef enum { IN, OUT, BOUNDRY } STATE;

point operator_mul_double(point b, double a) {
    return (point){a * b.x, a * b.y};
}

point operator_add(point a, point b) {
    return (point){a.x + b.x, a.y + b.y};
}

point operator_sub(point a, point b) {
    return (point){a.x - b.x, a.y - b.y};
}

double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double length(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

double lengthSqr(point a) {
    return a.x * a.x + a.y * a.y;
}

point normalize(point a) {
    double len = length(a);
    return (point){a.x / len, a.y / len};
}

point rotate(point a, double angle) {
    return (point){a.x * cos(angle) - a.y * sin(angle), a.x * sin(angle) + a.y * cos(angle)};
}

bool intersect(point a, point b, point p, point q, point *ret) {
    double d1 = cross(operator_sub(p, a), operator_sub(b, a));
    double d2 = cross(operator_sub(q, a), operator_sub(b, a));
    *ret = operator_mul_double(q, d1) - operator_mul_double(p, d2);
    if (fabs(d1 - d2) > EPS) return true;
    return false;
}

bool id4(point a, point b, point p) {
    return fabs(cross(operator_sub(a, b), operator_sub(a, p))) < EPS;
}

int id13(point p0, point p1, point cen, double rad, point *r1, point *r2) {
    double a, b, c, t1, t2;
    a = dot(operator_sub(p1, p0), operator_sub(p1, p0));
    b = 2 * dot(operator_sub(p1, p0), operator_sub(p0, cen));
    c = dot(operator_sub(p0, cen), operator_sub(p0, cen)) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < EPS) det = 0, res = 1;
    else if (det < 0) res = 0;
    else res = 2;
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    *r1 = operator_add(p0, operator_mul_double(operator_sub(p1, p0), t1));
    *r2 = operator_add(p0, operator_mul_double(operator_sub(p1, p0), t2));
    return res;
}

void circle2(point p1, point p2, point *cen, double *r) {
    *cen = (point){(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
    *r = length(operator_sub(p1, p2)) / 2;
}

bool can(double t) {
    point start = (point){x, y};
    point fin = (point){xp, yp};
    double theta = t * vp / R;
    fin = rotate(fin, theta);
    point a, b;
    bool intersection = false;
    int num = id13(start, fin, (point){0, 0}, r, &a, &b);
    if (num) {
        if (id4(start, fin, a)) intersection = true;
        if (num == 2 && id4(start, fin, b)) intersection = true;
    }
    if (num <= 1 || !intersection) {
        return length(operator_sub(start, fin)) < v * t + EPS;
    }
    double dis = Calc(start, fin);
    return dis < v * t + EPS;
}

int main() {
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = length((point){xp, yp});
    double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        if (can(m)) ans = m, hi = m - EPS;
        else lo = m + EPS;
    }
    printf("%.10lf\n", ans);
    return 0;
}
