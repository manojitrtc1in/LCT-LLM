#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point a;
    Point b;
} Segment;

typedef struct {
    Point center;
    double radius;
} Circle;

typedef enum {
    IN,
    OUT,
    BOUNDARY
} State;

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double length(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

Point vec(Point a, Point b) {
    Point v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

Point rotate(Point v, double t) {
    Point r;
    r.x = v.x * cos(t) - v.y * sin(t);
    r.y = v.x * sin(t) + v.y * cos(t);
    return r;
}

Point rotateabout(Point v, double t, Point a) {
    Point r = rotate(vec(a, v), t);
    r.x += a.x;
    r.y += a.y;
    return r;
}

Point normalize(Point p) {
    double len = length(p);
    p.x /= len;
    p.y /= len;
    return p;
}

int circleLineIntersection(Point p0, Point p1, Point cen, double rad, Point *r1, Point *r2) {
    double a, b, c, t1, t2;
    a = dot(vec(p1, p0), vec(p1, p0));
    b = 2 * dot(vec(p1, p0), vec(p0, cen));
    c = dot(vec(p0, cen), vec(p0, cen)) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < 1e-7)
        det = 0, res = 1;
    else if (det < 0)
        res = 0;
    else
        res = 2;
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    r1->x = p0.x + t1 * (p1.x - p0.x);
    r1->y = p0.y + t1 * (p1.y - p0.y);
    r2->x = p0.x + t2 * (p1.x - p0.x);
    r2->y = p0.y + t2 * (p1.y - p0.y);
    return res;
}

int tangentPoints(Point cen, double r, Point p, Point *r1, Point *r2) {
    State s = circlePoint(cen, r, p);
    if (s != OUT) {
        *r1 = *r2 = p;
        return s == BOUNDARY;
    }
    Point cp = vec(cen, p);
    double h = length(cp);
    double a = acos(r / h);
    cp = normalize(cp);
    cp.x *= r;
    cp.y *= r;
    *r1 = rotate(cp, a);
    r1->x += cen.x;
    r1->y += cen.y;
    *r2 = rotate(cp, -a);
    r2->x += cen.x;
    r2->y += cen.y;
    return 2;
}

double calcArc(Point a, Point b, double r) {
    double theta = fabs(atan2(b.y, b.x) - atan2(a.y, a.x));
    if (theta > M_PI)
        theta = 2 * M_PI - theta;
    double res = theta * r;
    return res;
}

double calcDis(Point a, Point c, Point st, Point en, double r) {
    double arc = calcArc(a, c, r);
    double res = arc + fabs(length(vec(a, st))) + fabs(length(vec(c, en)));
    return res;
}

double calc(Point st, Point en, double xp, double yp, double vp, double x, double y, double v, double r, double R) {
    Point start = st;
    Point fin = en;
    double theta = vp * R / r;
    fin = rotate(fin, theta);
    Point a, b;
    int intersection = 0;
    int num = circleLineIntersection(start, fin, (Point){0, 0}, r, &a, &b);
    if (num) {
        if (a.x >= start.x && a.x <= fin.x && a.y >= start.y && a.y <= fin.y)
            intersection = 1;
        if (num == 2 && b.x >= start.x && b.x <= fin.x && b.y >= start.y && b.y <= fin.y)
            intersection = 1;
    }
    if (num <= 1 || !intersection) {
        double dis = length(vec(start, fin));
        return dis < v * R + 1e-7;
    }
    double dis = calcDis(a, c, st, fin, r);
    dis = fmin(dis, calcDis(a, d, st, fin, r));
    dis = fmin(dis, calcDis(b, c, st, fin, r));
    dis = fmin(dis, calcDis(b, d, st, fin, r));
    return dis < v * R + 1e-7;
}

int main() {
    double xp, yp, vp, x, y, v, r, R;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = sqrt(xp * xp + yp * yp);
    double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        if (can(m))
            ans = m, hi = m - 1e-7;
        else
            lo = m + 1e-7;
    }
    printf("%.10lf\n", ans);
    return 0;
}
