#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define EPS 1e-8

typedef struct {
    double x, y;
} point;

double cmp(double x, double y) {
    return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

point add(point p, point q) {
    return (point){p.x + q.x, p.y + q.y};
}

point sub(point p, point q) {
    return (point){p.x - q.x, p.y - q.y};
}

point mul(point p, double t) {
    return (point){p.x * t, p.y * t};
}

double dot(point p, point q) {
    return p.x * q.x + p.y * q.y;
}

double cross(point p, point q) {
    return p.x * q.y - p.y * q.x;
}

double abs_point(point p) {
    return hypot(p.x, p.y);
}

double angle(point p, point q, point r) {
    point u = sub(p, q), v = sub(r, q);
    return atan2(cross(u, v), dot(u, v));
}

double dist2(point p, point q) {
    return dot(sub(p, q), sub(p, q));
}

point projectPointLine(point a, point b, point c) {
    return add(a, mul(sub(b, a), (dot(sub(c, a), sub(b, a)) / dot(sub(b, a), sub(b, a)))));
}

point projectPointSegment(point a, point b, point c) {
    double r = dot(sub(b, a), sub(b, a));
    if (fabs(r) < EPS) return a;
    r = dot(sub(c, a), sub(b, a)) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return add(a, mul(sub(b, a), r));
}

bool between(point p, point q, point r) {
    return cmp(cross(sub(p, q), sub(r, q)), 0) == 0 && cmp(dot(sub(p, q), sub(r, q)), 0) <= 0;
}

double distancePointSegment(point a, point b, point c) {
    return sqrt(dist2(c, projectPointSegment(a, b, c)));
}

bool seg_intersect(point p, point q, point r, point s) {
    point A = sub(q, p), B = sub(s, r), C = sub(r, p), D = sub(s, q);
    int a = cmp(cross(A, C), 0) + 2 * cmp(cross(A, D), 0);
    int b = cmp(cross(B, C), 0) + 2 * cmp(cross(B, D), 0);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || (cmp(p.x, r.x) == 0 && cmp(p.y, r.y) == 0) || (cmp(p.x, s.x) == 0 && cmp(p.y, s.y) == 0) || (cmp(q.x, r.x) == 0 && cmp(q.y, r.y) == 0) || (cmp(q.x, s.x) == 0 && cmp(q.y, s.y) == 0)) return true;
    int t = (cmp(p.x, r.x) < 0) + (cmp(p.x, s.x) < 0) + (cmp(q.x, r.x) < 0) + (cmp(q.x, s.x) < 0);
    return t != 0 && t != 4;
}

point line_intersect(point p, point q, point r, point s) {
    point a = sub(q, p), b = sub(s, r), c = (point){cross(p, q), cross(r, s)};
    return (point){cross((point){a.x, b.x}, c), cross((point){a.y, b.y}, c)} / cross(a, b);
}

int in_poly(point p, point* T, int N) {
    double a = 0;
    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i + 1) % N])) return -1;
        a += angle(T[i], p, T[(i + 1) % N]);
    }
    return cmp(a, 0) != 0;
}

double poly_area(point* T, int N) {
    double s = 0;
    for (int i = 0; i < N; i++)
        s += cross(T[i], T[(i + 1) % N]);
    return s / 2;
}

int main() {
    int xp, yp, vp, x, y, v, r;
    scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
    
    double R = hypot(yp, xp);
    double initial = atan2(yp, xp);
    double bot = 0;
    double timeTot = (2 * M_PI * R) / vp;
    double top = 100000000000000.0;

    while (cmp(top, bot) > 0) {
        double mid = (top + bot) / 2;
        double angle = ((2 * M_PI * mid) / timeTot) + initial;
        point loc = {cos(angle) * R, sin(angle) * R};

        point nave = {x, y};
        if (cmp(distancePointSegment(loc, nave, (point){0, 0}), r) >= 0) {
            if (cmp(mid, abs_point(sub(nave, loc)) / v) >= 0) {
                top = mid;
            } else {
                bot = mid;
            }
        } else {
            double distN = sqrt(dist2(nave, (point){0, 0}) - r * r);
            double distL = sqrt(dist2(loc, (point){0, 0}) - r * r);
            double a = abs_point(sub(nave, loc));
            double b = abs_point(nave);
            double c = abs_point(loc);
            double bigcos = ((b * b) + (c * c) - (a * a)) / (2 * b * c);
            double angNOL = acos(bigcos) - fabs(atan(distN / r)) - fabs(atan(distL / r));
            double menor = distN + distL + fabs(r * angNOL);
            if (cmp(mid, menor / v) >= 0) {
                top = mid;
            } else {
                bot = mid;
            }
        }
    }
    printf("%.7f\n", bot);
    return 0;
}
