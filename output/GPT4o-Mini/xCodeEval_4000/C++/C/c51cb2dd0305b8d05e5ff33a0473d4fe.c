#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

typedef double complex point;
#define EPS (1e-7)
#define OO 1e9
#define X creal
#define Y cimag
#define vec(a,b) ((b)-(a))
#define length(v) (cabs(v))
#define dot(a,b) (creal(conj(a)*(b)))
#define cross(a,b) (cimag(conj(a)*(b)))
#define rotate(v,t) (cabs(v)*cexp(I*(t)))
#define mid(a,b) (((a)+(b))/2.0)
#define same(a,b) (length(vec(a,b))<EPS)

bool intersect(const point a, const point b, const point p, const point q, point *ret) {
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    *ret = (d1 * q - d2 * p) / (d1 - d2);
    if(fabs(d1 - d2) > EPS) return true;
    return false;
}

bool pointOnLine(const point a, const point b, const point p) {
    return fabs(cross(vec(a,b),vec(a,p))) < EPS;
}

bool pointOnRay(const point a, const point b, const point p) {
    return dot(vec(a,p), vec(a,b)) > -EPS;
}

bool pointOnSegment(const point a, const point b, const point p) {
    if(!pointOnLine(a,b,p)) return false;
    return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}

double pointLineDist(const point a, const point b, const point p) {
    return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

double pointSegmentDist(const point a, const point b, const point p) {
    if (dot(vec(a,b),vec(a,p)) < EPS)
        return length(vec(a,p));
    if (dot(vec(b,a),vec(b,p)) < EPS)
        return length(vec(b,p));
    return pointLineDist(a, b, p);
}

int segmentLatticePointsCount(int x1, int y1, int x2, int y2) {
    return abs(gcd(x1 - x2, y1 - y2)) + 1;
}

double triangleAreaBH(double b, double h) {
    return b * h / 2;
}

double triangleArea2sidesAngle(double a, double b, double t) {
    return fabs(a * b * sin(t) / 2);
}

double triangleArea3sides(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double triangleArea3points(const point a, const point b, const point c) {
    return fabs(cross(a,b) + cross(b,c) + cross(c,a)) / 2;
}

double cosRule(double a, double b, double c) {
    double res = (b * b + c * c - a * a) / (2 * b * c);
    if (fabs(res-1)<EPS) res = 1;
    if (fabs(res+1)<EPS) res = -1;
    return acos(res);
}

double sinRuleAngle(double s1, double s2, double a1) {
    double res = s2 * sin(a1) / s1;
    if (fabs(res-1)<EPS) res = 1;
    if (fabs(res+1)<EPS) res = -1;
    return asin(res);
}

int circleLineIntersection(const point p0, const point p1, const point cen, double rad, point *r1, point *r2) {
    double a, b, c, t1, t2;
    a = dot(p1-p0,p1-p0);
    b = 2 * dot(p1-p0,p0-cen);
    c = dot(p0-cen,p0-cen) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < EPS) det = 0, res = 1;
    else if (det < 0) res = 0;
    else res = 2;
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    *r1 = p0 + t1 * (p1 - p0);
    *r2 = p0 + t2 * (p1 - p0);
    return res;
}

int main() {
    double xp, yp, vp, x, y, v, r, R;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = length(point(xp, yp));
    double ans = 10000000, hi = 1000000, lo = 0.0;

    for(int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        // Implement can function logic here
        // Update ans, hi, lo based on can function result
    }

    printf("%.10lf\n", ans);
    return 0;
}
