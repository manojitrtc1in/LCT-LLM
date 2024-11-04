#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <complex.h>
#include <string.h>

#define EPS 1e-9
#define OO 2

typedef struct {
    double real;
    double imag;
} point;

typedef enum {
    IN, OUT, BOUNDRY
} STATE;

point operator_mul_double(point b, double a) {
    return (point){a * b.real, a * b.imag};
}

point operator_add(point a, point b) {
    return (point){a.real + b.real, a.imag + b.imag};
}

point operator_sub(point a, point b) {
    return (point){a.real - b.real, a.imag - b.imag};
}

double cross(point a, point b) {
    return a.real * b.imag - a.imag * b.real;
}

double dot(point a, point b) {
    return a.real * b.real + a.imag * b.imag;
}

double length(point a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

point normalize(point a) {
    double len = length(a);
    return (point){a.real / len, a.imag / len};
}

point rotate(point a, double angle) {
    return (point){a.real * cos(angle) - a.imag * sin(angle), a.real * sin(angle) + a.imag * cos(angle)};
}

bool intersect(point a, point b, point p, point q, point *ret) {
    double d1 = cross(operator_sub(p, a), operator_sub(b, a));
    double d2 = cross(operator_sub(q, a), operator_sub(b, a));
    *ret = operator_mul_double(q, d1) - operator_mul_double(p, d2);
    if (fabs(d1 - d2) > EPS) return true;
    return false;
}

bool id4(point a, point b, point p) {
    return fabs(cross(operator_sub(b, a), operator_sub(p, a))) < EPS;
}

long double id14(point a, point b, point p) {
    return fabs(cross(operator_sub(b, a), operator_sub(p, a))) / length(operator_sub(b, a));
}

int id13(point p0, point p1, point cen, double rad, point *r1, point *r2) {
    double a, b, c, t1, t2;
    a = dot(operator_sub(p1, p0), operator_sub(p1, p0));
    b = 2 * dot(operator_sub(p1, p0), operator_sub(p0, cen));
    c = dot(operator_sub(p0, cen), operator_sub(p0, cen)) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < EPS) {
        det = 0; res = 1;
    } else if (det < 0) {
        res = 0;
    } else {
        res = 2;
    }
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    *r1 = operator_add(p0, operator_mul_double(operator_sub(p1, p0), t1));
    *r2 = operator_add(p0, operator_mul_double(operator_sub(p1, p0), t2));
    return res;
}

long double calcArc(point a, point b, double r) {
    long double theta = fabs(atan2(b.imag, b.real) - atan2(a.imag, a.real));
    if (theta > M_PI) theta = 2 * M_PI - theta;
    return theta * r;
}

long double calcDis(point a, point c, point st, point en, double r) {
    long double arc = calcArc(a, c, r);
    return arc + fabs(length(operator_sub(a, st))) + fabs(length(operator_sub(c, en)));
}

bool can(long double t, point st, point en, double vp, double r) {
    point start = st;
    point fin = en;
    long double theta = t * vp / r;
    fin = rotate(fin, theta);
    point a, b;
    bool intersection = false;
    int num = id13(start, fin, (point){0, 0}, r, &a, &b);
    if (num) {
        if (id4(start, fin, a)) intersection = true;
        if (num == 2 && id4(start, fin, b)) intersection = true;
    }
    if (num <= 1 || !intersection) {
        return length(operator_sub(start, fin)) < vp * t + EPS;
    }
    long double dis = calcDis(st, fin, start, fin, r);
    return dis < vp * t + EPS;
}

int main() {
    double xp, yp, vp, x, y, v, r;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    long double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        long double m = lo + (hi - lo) / 2.0L;
        if (can(m, (point){x, y}, (point){xp, yp}, vp, r)) {
            ans = m; hi = m;
        } else {
            lo = m;
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}
