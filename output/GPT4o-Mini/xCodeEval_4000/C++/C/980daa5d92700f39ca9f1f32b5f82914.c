#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

#define EPS (1e-8)
#define OO 1e9
#define MAXPOINTS 100000

typedef double complex point;

#define X creal
#define Y cimag
#define vec(a,b) ((b)-(a))
#define length(v) (cabs(v))
#define same(a,b) (length(vec(a,b))<EPS)

bool intersect(const point a, const point b, const point p, const point q, point *ret) {
    double d1 = creal(conj(vec(p, a)) * vec(b, a));
    double d2 = creal(conj(vec(q, a)) * vec(b, a));
    *ret = (d1 * q - d2 * p) / (d1 - d2);
    return fabs(d1 - d2) > EPS;
}

bool pointOnLine(const point a, const point b, const point p) {
    return fabs(creal(conj(vec(a, b)) * vec(a, p))) < EPS;
}

bool pointOnRay(const point a, const point b, const point p) {
    return creal(conj(vec(a, p)) * vec(a, b)) > -EPS;
}

bool pointOnSegment(const point a, const point b, const point p) {
    return pointOnLine(a, b, p) && pointOnRay(a, b, p) && pointOnRay(b, a, p);
}

double pointLineDist(const point a, const point b, const point p) {
    return fabs(creal(conj(vec(a, b)) * vec(a, p)) / length(vec(a, b)));
}

double pointSegmentDist(const point a, const point b, const point p) {
    if (creal(conj(vec(a, b)) * vec(a, p)) < EPS)
        return length(vec(a, p));
    if (creal(conj(vec(b, a)) * vec(b, p)) < EPS)
        return length(vec(b, p));
    return pointLineDist(a, b, p);
}

double triangleArea3points(const point a, const point b, const point c) {
    return fabs(creal(conj(a) * b + conj(b) * c + conj(c) * a)) / 2;
}

double circleLineIntersection(const point p0, const point p1, const point cen, double rad, point *r1, point *r2) {
    double a, b, c, t1, t2;
    a = creal(conj(vec(p1, p0)) * vec(p1, p0));
    b = 2 * creal(conj(vec(p1, p0)) * vec(p0, cen));
    c = creal(conj(vec(p0, cen)) * vec(p0, cen)) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < EPS)
        det = 0, res = 1;
    else if (det < 0)
        res = 0;
    else
        res = 2;
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    *r1 = p0 + t1 * (p1 - p0);
    *r2 = p0 + t2 * (p1 - p0);
    return res;
}

bool can(double t, point st, point en, double vp, double v, double r) {
    point start = st;
    point fin = en;
    double theta = t * vp / r;
    fin = en * cexp(I * theta);
    point a, b;
    bool intersection = false;
    int num = circleLineIntersection(start, fin, 0, r, &a, &b);
    if (num) {
        if (pointOnSegment(start, fin, a)) intersection = true;
        if (num == 2 && pointOnSegment(start, fin, b)) intersection = true;
    }
    if (num <= 1 || !intersection) {
        return length(vec(start, fin)) < v * t + EPS;
    }
    // Additional distance calculation would go here
    return false; // Placeholder
}

int main() {
    double xp, yp, vp, x, y, v, r;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    double R = length(0 + I * yp);
    double ans = 10000000, hi = 1000000, lo = 0.0;

    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        if (can(m, x + I * y, xp + I * yp, vp, v, r)) {
            ans = m;
            hi = m - EPS;
        } else {
            lo = m + EPS;
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}
