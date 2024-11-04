#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define EPS 1e-7

typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    Point2D c;
    double r;
} Circle2D;

typedef struct {
    Point2D p1;
    Point2D p2;
    double A;
    double B;
    double C;
} Line2D;

double sqr(double x) {
    return x * x;
}

double det2x2(double a11, double a12, double a21, double a22) {
    return a11 * a22 - a12 * a21;
}

double cross(Point2D p0, Point2D p1, Point2D p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double getCos(double a, double b, double c) {
    return 0.5 * (a * a + b * b - c * c) / (a * b);
}

double getPolarAngle(Point2D c, Point2D p) {
    return atan2(p.y - c.y, p.x - c.x);
}

double distSqr(Point2D p1, Point2D p2) {
    return sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
}

double dist(Point2D p1, Point2D p2) {
    return sqrt(distSqr(p1, p2));
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
        fprintf(stderr, "Invalid argument for sqrt: %f\n", x);
        exit(1);
    }
    return sqrt(fmax(0.0, x));
}

double acos(double x) {
    if (!range(-1.0, x, 1.0)) {
        fprintf(stderr, "Invalid argument for acos: %f\n", x);
        exit(1);
    }
    return acos(fmax(-1.0, fmin(1.0, x)));
}

double asin(double x) {
    if (!range(-1.0, x, 1.0)) {
        fprintf(stderr, "Invalid argument for asin: %f\n", x);
        exit(1);
    }
    return asin(fmax(-1.0, fmin(1.0, x)));
}

void check(int state) {
    if (!state) {
        fprintf(stderr, "Error\n");
        exit(1);
    }
}

Point2D point2D(double x, double y) {
    Point2D p;
    p.x = x;
    p.y = y;
    return p;
}

Point2D point2DAdd(Point2D p1, Point2D p2) {
    return point2D(p1.x + p2.x, p1.y + p2.y);
}

Point2D point2DSub(Point2D p1, Point2D p2) {
    return point2D(p1.x - p2.x, p1.y - p2.y);
}

Point2D point2DMul(Point2D p, double K) {
    return point2D(p.x * K, p.y * K);
}

Point2D point2DScale(Point2D p, double K) {
    return point2D(p.x * K, p.y * K);
}

double point2DLen(Point2D p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

Point2D point2DNorm(Point2D p, double newLen) {
    return point2DScale(p, newLen / point2DLen(p));
}

Point2D point2DNormalize(Point2D p, double newLen) {
    return point2DScale(p, newLen / point2DLen(p));
}

double point2DScalarProduct(Point2D p1, Point2D p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double point2DCrossProduct(Point2D p1, Point2D p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

Point2D point2DRotate90(Point2D p) {
    return point2D(-p.y, p.x);
}

Point2D point2DRotate(Point2D p, double angle) {
    double cos = cos(angle);
    double sin = sin(angle);
    return point2D(p.x * cos - p.y * sin, p.x * sin + p.y * cos);
}

Point2D point2DTurn90(Point2D p) {
    return point2D(-p.y, p.x);
}

Point2D point2DTurn(Point2D p, double angle) {
    double cos = cos(angle);
    double sin = sin(angle);
    return point2D(p.x * cos - p.y * sin, p.x * sin + p.y * cos);
}

int point2DEquals(Point2D p1, Point2D p2) {
    return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

void point2DToString(Point2D p, char* str) {
    sprintf(str, "(%.3f, %.3f)", p.x, p.y);
}

Point2D point2DCopy(Point2D p) {
    return point2D(p.x, p.y);
}

Line2D line2D(Point2D p1, Point2D p2) {
    Line2D l;
    l.p1 = p1;
    l.p2 = p2;
    l.A = p2.y - p1.y;
    l.B = p1.x - p2.x;
    l.C = -(l.A * p1.x + l.B * p1.y);
    return l;
}

Line2D line2DSet(Point2D p, Line2D l) {
    l.p1 = p;
    l.p2 = point2DAdd(p, point2DRotate90(line2DNormal(l)));
    l.A = -l.B;
    l.B = l.A;
    l.C = -(l.A * p.x + l.B * p.y);
    return l;
}

Line2D line2DSetR(double r, Line2D l) {
    Point2D v = point2DScale(line2DNormal(l), r);
    l.p1 = point2DSub(l.p1, v);
    l.p2 = point2DSub(l.p2, v);
    l.C = -(l.A * l.p1.x + l.B * l.p1.y);
    return l;
}

Line2D line2DMove(Line2D l, Point2D v) {
    l.p1 = point2DAdd(l.p1, v);
    l.p2 = point2DAdd(l.p2, v);
    l.C = -(l.A * l.p1.x + l.B * l.p1.y);
    return l;
}

Line2D line2DShift(Line2D l, double r) {
    Point2D v = point2DScale(line2DNormal(l), r);
    l.p1 = point2DSub(l.p1, v);
    l.p2 = point2DSub(l.p2, v);
    l.C = -(l.A * l.p1.x + l.B * l.p1.y);
    return l;
}

double line2DCalc(Line2D l, Point2D p) {
    return l.A * p.x + l.B * p.y + l.C;
}

int line2DLay(Line2D l, Point2D p) {
    return fabs(line2DCalc(l, p)) < EPS;
}

int line2DContains(Line2D l, Point2D p) {
    if (!line2DLay(l, p)) {
        return 0;
    }
    return range(0.0, line2DGetT(l, p), 1.0);
}

double line2DGetT(Line2D l, Point2D p) {
    if (!line2DLay(l, p)) {
        return NAN;
    }
    if (fabs(l.A) > EPS) {
        return (p.y - l.p1.y) / l.A;
    }
    if (fabs(l.B) > EPS) {
        return (l.p1.x - p.x) / l.B;
    }
    fprintf(stderr, "Bad line\n");
    exit(1);
}

Point2D line2DGetPoint(Line2D l, double t) {
    return point2D(l.p1.x - l.B * t, l.p1.y + l.A * t);
}

double line2DDist(Line2D l, Point2D p) {
    return fabs(line2DCalc(l, p)) / sqrt(l.A * l.A + l.B * l.B);
}

Point2D line2DDir(Line2D l) {
    return point2D(-l.B, l.A);
}

Point2D line2DNormal(Line2D l) {
    return point2D(l.A, l.B);
}

Point2D line2DProjection(Line2D l, Point2D p) {
    double t = (l.B * (l.p1.x - p.x) - l.A * (l.p1.y - p.y)) / (l.A * l.A + l.B * l.B);
    return point2D(l.p1.x - l.B * t, l.p1.y + l.A * t);
}

Line2D line2DProjectionLine(Line2D l1, Line2D l2) {
    return line2D(line2DProjection(l1, l2.p1), line2DProjection(l1, l2.p2));
}

int hasCSC(Point2D p1, Point2D p2, Circle2D c) {
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

double distWithStar(Point2D p1, Point2D p2, Point2D tp1, Point2D tp2, Circle2D star) {
    double phi = acos(fmax(-1.0, fmin(1.0, point2DScalarProduct(tp1, tp2) / point2DLen(tp1) / point2DLen(tp2))));
    return dist(p1, tp1) + dist(p2, tp2) + star.r * phi;
}

int distPlanetar(Point2D p1, Point2D p2, Circle2D star) {
    if (hasCSC(p1, p2, star)) {
        Point2D tp1[2], tp2[2];
        tp1[0] = point2DSub(p1, star.c);
        tp1[1] = point2DAdd(p1, star.c);
        tp2[0] = point2DSub(p2, star.c);
        tp2[1] = point2DAdd(p2, star.c);
        double ret = 1e100;
        ret = fmin(ret, distWithStar(p1, p2, tp1[0], tp2[0], star));
        ret = fmin(ret, distWithStar(p1, p2, tp1[0], tp2[1], star));
        ret = fmin(ret, distWithStar(p1, p2, tp1[1], tp2[0], star));
        ret = fmin(ret, distWithStar(p1, p2, tp1[1], tp2[1], star));
        return ret;
    }
    return dist(p1, p2);
}

int can(double t, Point2D ps, Point2D pp, double vs, double rP, double vP, double omegaP, Circle2D star) {
    return distPlanetar(ps, point2DRotate(pp, t * vP / rP), star) < t * vs;
}

double solve(double xp, double yp, double vp, double xs, double ys, double vs, double r, double tvp) {
    Point2D pp = point2D(xp, yp);
    double rP = sqrt(xp * xp + yp * yp);
    double vP = vp;
    double omegaP = vP / rP;
    Point2D ps = point2D(xs, ys);
    vs /= tvp;
    omegaP = vP / rP;
    Circle2D star = {point2D(0.0, 0.0), r};
    double ans = 3e6;
    double left = 0;
    double right = ans;
    for (int it = 0; it < 10000; it++) {
        double mid = 0.5 * (left + right);
        if (can(mid, ps, pp, vs, rP, vP, omegaP, star)) {
            right = mid;
            ans = fmin(ans, mid);
        } else {
            left = mid;
        }
    }
    return ans / tvp;
}

int main() {
    double xp, yp, vp, xs, ys, vs, r, tvp;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &xs, &ys, &vs, &r, &tvp);
    double result = solve(xp, yp, vp, xs, ys, vs, r, tvp);
    printf("%.6f\n", result);
    return 0;
}
