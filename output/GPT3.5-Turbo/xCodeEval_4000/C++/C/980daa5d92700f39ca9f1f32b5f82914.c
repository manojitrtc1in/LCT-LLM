#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point p1;
    point p2;
} segment;

double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

point vec(point a, point b) {
    point v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

point rotate(point v, double t) {
    point r;
    r.x = v.x * cos(t) - v.y * sin(t);
    r.y = v.x * sin(t) + v.y * cos(t);
    return r;
}

int circleLineIntersection(point p0, point p1, point cen, double rad, point *r1, point *r2) {
    double a, b, c, t1, t2;
    a = (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y);
    b = 2 * ((p1.x - p0.x) * (p0.x - cen.x) + (p1.y - p0.y) * (p0.y - cen.y));
    c = cen.x * cen.x + cen.y * cen.y + p0.x * p0.x + p0.y * p0.y - 2 * (cen.x * p0.x + cen.y * p0.y) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < 1e-8)
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

double length(point v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

double calcArc(point a, point b, double r) {
    double theta = fabs(atan2(b.y, b.x) - atan2(a.y, a.x));
    if (theta > M_PI)
        theta = 2 * M_PI - theta;
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
    double theta = atan2(st.y, st.x);
    a.x = r * cos(theta);
    a.y = r * sin(theta);
    theta = atan2(en.y, en.x);
    b.x = r * cos(theta);
    b.y = r * sin(theta);
    double res = calcDis(a, b, r, st, en);
    return res;
}

int main() {
    double xp, yp, vp, x, y, v, r, R;
    point st, en;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = sqrt(xp * xp + yp * yp);
    double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        double theta = m * vp / R;
        en.x = xp * cos(theta) - yp * sin(theta);
        en.y = xp * sin(theta) + yp * cos(theta);
        point a, b;
        int num = circleLineIntersection(st, en, (point){0, 0}, r, &a, &b);
        if (num) {
            if (a.x >= st.x && a.x <= en.x && a.y >= st.y && a.y <= en.y)
                ans = m, hi = m - 1e-8;
            else if (b.x >= st.x && b.x <= en.x && b.y >= st.y && b.y <= en.y)
                ans = m, hi = m - 1e-8;
            else
                lo = m + 1e-8;
        } else {
            double dis = Calc(st, en, r);
            if (dis < v * m + 1e-8)
                ans = m, hi = m - 1e-8;
            else
                lo = m + 1e-8;
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}
