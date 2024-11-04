#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

#define EPS (1e-7)
#define OO 1e9
#define MAXPOINTS 100000

typedef double complex point;

#define X creal
#define Y cimag
#define vec(a,b) ((b)-(a))
#define length(v) (cabs(v))
#define dot(a,b) (creal(conj(a)*(b)))
#define cross(a,b) (cimag(conj(a)*(b)))
#define rotate(v,t) (cexp(I*(t)) * (v))
#define mid(a,b) (((a)+(b))/2.0)
#define same(a,b) (length(vec(a,b))<EPS)

bool intersect(const point a, const point b, const point p, const point q, point *ret) {
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    *ret = (d1 * q - d2 * p) / (d1 - d2);
    return fabs(d1 - d2) > EPS;
}

bool pointOnSegment(const point a, const point b, const point p) {
    return same(a, b) ? false : (dot(vec(a,b), vec(a,p)) > -EPS && dot(vec(b,a), vec(b,p)) > -EPS);
}

long double pointLineDist(const point a, const point b, const point p) {
    return fabs(cross(vec(a,b), vec(a,p)) / length(vec(a,b)));
}

long double pointSegmentDist(const point a, const point b, const point p) {
    if (dot(vec(a,b), vec(a,p)) < EPS)
        return length(vec(a,p));
    if (dot(vec(b,a), vec(b,p)) < EPS)
        return length(vec(b,p));
    return pointLineDist(a, b, p);
}

int circleLineIntersection(const point p0, const point p1, const point cen, long double rad, point *r1, point *r2) {
    long double a, b, c, t1, t2;
    a = dot(p1-p0, p1-p0);
    b = 2 * dot(p1-p0, p0-cen);
    c = dot(p0-cen, p0-cen) - rad * rad;
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

long double calcArc(point a, point b, long double r) {
    long double theta = fabs(atan2(Y(b), X(b)) - atan2(Y(a), X(a)));
    if (theta > M_PI) theta = 2 * M_PI - theta;
    return theta * r;
}

long double calcDis(point a, point c, point st, point en, long double r) {
    long double arc = calcArc(a, c, r);
    return arc + fabs(length(vec(a, st))) + fabs(length(vec(c, en)));
}

bool can(long double t, point st, point en, long double vp, long double R, long double r) {
    point start = st;
    point fin = en;
    long double theta = t * vp / R;
    fin = rotate(fin, theta);
    point a, b;
    bool intersection = false;
    int num = circleLineIntersection(start, fin, 0, r, &a, &b);
    if (num) {
        if (pointOnSegment(start, fin, a)) intersection = true;
        if (num == 2 && pointOnSegment(start, fin, b)) intersection = true;
    }
    if (num <= 1 || !intersection) {
        return length(vec(start, fin)) < vp * t + EPS;
    }
    long double dis = calcDis(st, fin, start, fin, r);
    return dis < vp * t + EPS;
}

int main() {
    long double xp, yp, vp, x, y, v, r, R;
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = length(0 + I * yp);
    long double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        long double m = lo + (hi - lo) / 2.0L;
        if (can(m, x + I * y, xp + I * yp, v, R, r)) {
            ans = m;
            hi = m;
        } else {
            lo = m;
        }
    }
    printf("%.10Lf\n", ans);
    return 0;
}
