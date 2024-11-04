#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

point rotate(point p, double t) {
    point res;
    res.x = p.x * cos(t) - p.y * sin(t);
    res.y = p.x * sin(t) + p.y * cos(t);
    return res;
}

int circleLineIntersection(point p0, point p1, point cen, double rad, point* r1, point* r2) {
    double a, b, c, t1, t2;
    a = (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y);
    b = 2 * ((p1.x - p0.x) * (p0.x - cen.x) + (p1.y - p0.y) * (p0.y - cen.y));
    c = cen.x * cen.x + cen.y * cen.y + p0.x * p0.x + p0.y * p0.y - 2 * (cen.x * p0.x + cen.y * p0.y) - rad * rad;
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

double length(point p) {
    return sqrt(p.x * p.x + p.y * p.y);
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
    double res = arc + fabs(length((point) {a.x - st.x, a.y - st.y})) + fabs(length((point) {c.x - en.x, c.y - en.y}));
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
    int num = circleLineIntersection(st, en, (point) {0, 0}, r, &c, &d);
    double res = calcDis(a, c, r, st, en);
    res = fmin(res, calcDis(a, d, r, st, en));
    res = fmin(res, calcDis(b, c, r, st, en));
    res = fmin(res, calcDis(b, d, r, st, en));
    return res;
}

int main() {
    double xp, yp, vp, x, y, v, r, R;
    point st, en;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = length((point) {xp, yp});
    double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        st.x = x;
        st.y = y;
        en.x = xp;
        en.y = yp;
        double theta = m * vp / R;
        en = rotate(en, theta);
        point a, b;
        int num = circleLineIntersection(st, en, (point) {0, 0}, r, &a, &b);
        if (num <= 1 || (num > 1 && (a.x != b.x || a.y != b.y))) {
            double dis = length((point) {en.x - st.x, en.y - st.y});
            if (dis < v * m + 1e-7)
                ans = m, hi = m;
            else
                lo = m;
        } else {
            double dis = Calc(st, en, r);
            if (dis < v * m + 1e-7)
                ans = m, hi = m;
            else
                lo = m;
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}
