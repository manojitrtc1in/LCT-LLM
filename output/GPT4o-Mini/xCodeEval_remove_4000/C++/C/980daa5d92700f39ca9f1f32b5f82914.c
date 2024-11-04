#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>
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

point operator_multiply_double(point b, double a) {
    return (point){a * b.real, a * b.imag};
}

point operator_multiply_point(point b, double a) {
    return (point){a * b.real, a * b.imag};
}

double cross(point a, point b) {
    return a.real * b.imag - a.imag * b.real;
}

double dot(point a, point b) {
    return a.real * b.real + a.imag * b.imag;
}

point vec(point a, point b) {
    return (point){b.real - a.real, b.imag - a.imag};
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

bool intersect(const point a, const point b, const point p, const point q, point *ret) {
    double d1 = cross(vec(a, b), vec(a, p));
    double d2 = cross(vec(a, b), vec(a, q));
    *ret = operator_multiply_double(q, d1) - operator_multiply_double(p, d2);
    if (fabs(d1 - d2) > EPS) return true;
    return false;
}

bool id4(const point a, const point b, const point p) {
    return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}

int id13(const point p0, const point p1, const point cen, double rad, point *r1, point *r2) {
    double a, b, c, t1, t2;
    a = dot(vec(p0, p1), vec(p0, p1));
    b = 2 * dot(vec(p0, p1), vec(p0, cen));
    c = dot(vec(cen, p0), vec(cen, p0)) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < EPS) det = 0, res = 1;
    else if (det < 0) res = 0;
    else res = 2;
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    *r1 = (point){p0.real + t1 * (p1.real - p0.real), p0.imag + t1 * (p1.imag - p0.imag)};
    *r2 = (point){p0.real + t2 * (p1.real - p0.real), p0.imag + t2 * (p1.imag - p0.imag)};
    return res;
}

double calcArc(point a, point b, double r) {
    double theta = fabs(atan2(b.imag, b.real) - atan2(a.imag, a.real));
    if (theta > M_PI) theta = 2 * M_PI - theta;
    return theta * r;
}

double calcDis(point a, point c, point st, point en, double r) {
    double arc = calcArc(a, c, r);
    return arc + fabs(length(vec(a, st))) + fabs(length(vec(c, en)));
}

bool can(double t, point st, point en, double vp, double r, double v) {
    point start = st;
    point fin = en;
    double theta = t * vp / r;
    fin = rotate(fin, theta);
    point a, b;
    bool intersection = false;
    int num = id13(start, fin, (point){0, 0}, r, &a, &b);
    if (num) {
        if (id4(start, fin, a)) intersection = true;
        if (num == 2 && id4(start, fin, b)) intersection = true;
    }
    if (num <= 1 || !intersection) {
        return length(vec(start, fin)) < v * t + EPS;
    }
    double dis = calcDis(st, fin, start, fin, r);
    return dis < v * t + EPS;
}

int main() {
    double xp, yp, vp, x, y, v, r;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    double R = length((point){xp, yp});
    double ans = 10000000, hi = 1000000, lo = 0.0;

    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        if (can(m, (point){x, y}, (point){xp, yp}, vp, r, v)) {
            ans = m;
            hi = m - EPS;
        } else {
            lo = m + EPS;
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}
