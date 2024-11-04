#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define EPS 1e-8
#define INF 10000000

typedef struct {
    double x, y;
} point;

point origin = {0, 0};

int cmp(double x, double y) {
    return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

double abs_point(point p) {
    return hypot(p.x, p.y);
}

double angle(point p, point q, point r) {
    point u = {p.x - q.x, p.y - q.y};
    point v = {r.x - q.x, r.y - q.y};
    return atan2(u.x * v.y - u.y * v.x, u.x * v.x + u.y * v.y);
}

double dist2(point p, point q) {
    return ((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

point projectPointSegment(point a, point b, point c) {
    double r = dist2(a, b);
    if (fabs(r) < EPS) return a;
    r = ((c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y)) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return (point){a.x + (b.x - a.x) * r, a.y + (b.y - a.y) * r};
}

double distancePointSegment(point a, point b, point c) {
    return sqrt(dist2(c, projectPointSegment(a, b, c)));
}

bool pode(point loc, double time, point nave, double r, double v) {
    if (cmp(distancePointSegment(loc, nave, origin), r) >= 0) {
        return cmp(time, abs_point((point){nave.x - loc.x, nave.y - loc.y}) / v) >= 0;
    } else {
        double distN = sqrt(dist2(nave, origin) - r * r);
        double distL = sqrt(dist2(loc, origin) - r * r);
        double angNOL = fabs(angle(nave, origin, loc)) - fabs(atan(distN / r)) - fabs(atan(distL / r));
        double menor = distN + distL + fabs(r * angNOL);
        return cmp(time, menor / v) >= 0;
    }
}

int main() {
    int xp, yp, vp, x, y, v, r;
    scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
    
    double R = hypot(yp, xp);
    double initial = atan2(yp, xp);
    double bot = 0;
    double timeTot = 1000000.0;
    double t1 = (2 * M_PI * R) / vp;
    double top = timeTot;

    while (top - bot > EPS) {
        double mid = (top + bot) / 2;
        double angle = ((2 * M_PI * mid) / t1) + initial;
        point loc = {cos(angle) * R, sin(angle) * R};

        if (pode(loc, mid, (point){x, y}, r, v)) {
            top = mid - EPS;
        } else {
            bot = mid + EPS;
        }
    }
    
    printf("%.7f\n", bot);
    return 0;
}
