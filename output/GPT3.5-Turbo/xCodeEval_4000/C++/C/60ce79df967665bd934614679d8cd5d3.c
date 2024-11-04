#include<stdio.h>
#include<math.h>

#define pi 3.14159265358979323846

typedef struct {
    double x, y;
} point;

typedef struct {
    point p;
    double r;
} circle;

double dist(point a, point b, circle c) {
    double rd = atan2(b.y - a.y, b.x - a.x);
    double d = hypot(b.x - a.x, b.y - a.y);
    double ds = d - 2 * c.r * sin(rd / 2);
    return ds;
}

int main() {
    double xp, yp, vp;
    double x, y, v, r;
    circle c;
    int i, j, k = 1000;
    double low = 0, high = 1e6;

    scanf("%lf%lf%lf", &xp, &yp, &vp);
    point p = {xp, yp};
    scanf("%lf%lf%lf%lf", &x, &y, &v, &r);
    c.p.x = 0;
    c.p.y = 0;
    c.r = r;

    double d = 2 * pi * hypot(p.x, p.y);

    while (k--) {
        double mid = (low + high) / 2.0;
        double s = vp * mid;
        double w = fmod(s, d);
        w = (w / d) * 2 * pi;

        point where;
        where.x = p.x * cos(w) - p.y * sin(w);
        where.y = p.x * sin(w) + p.y * cos(w);

        double md = dist(where, (point){x, y}, c);

        if (mid * v - md >= 0) {
            high = mid;
        } else {
            low = mid;
        }
    }

    printf("%.12lf\n", low);
    return 0;
}
