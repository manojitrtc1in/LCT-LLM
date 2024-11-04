#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define eps 1e-8
#define pi acos(-1.0)

typedef struct {
    double x, y;
} point;

typedef struct {
    point a, b;
} line;

typedef struct {
    point p;
    double r;
} circle;

int dblcmp(double d) {
    if (fabs(d) < eps) return 0;
    return d > eps ? 1 : -1;
}

double sqr(double x) {
    return x * x;
}

void point_input(point *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

void point_output(point p) {
    printf("%.12f %.12f\n", p.x, p.y);
}

double point_distance(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

point point_add(point a, point b) {
    return (point){a.x + b.x, a.y + b.y};
}

point point_sub(point a, point b) {
    return (point){a.x - b.x, a.y - b.y};
}

point point_mul(point p, double b) {
    return (point){p.x * b, p.y * b};
}

point point_div(point p, double b) {
    return (point){p.x / b, p.y / b};
}

double point_dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double point_det(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

point point_rotate(point p, double angle) {
    double c = cos(angle), s = sin(angle);
    return (point){p.x * c - p.y * s, p.x * s + p.y * c};
}

void line_input(line *l) {
    point_input(&l->a);
    point_input(&l->b);
}

double line_length(line l) {
    return point_distance(l.a, l.b);
}

double line_dispointtoline(line l, point p) {
    return fabs(point_det(point_sub(p, l.a), point_sub(l.b, l.a))) / line_length(l);
}

int circle_relation(circle c, point b) {
    double dst = point_distance(c.p, b);
    if (dblcmp(dst - c.r) < 0) return 2;
    if (dblcmp(dst - c.r) == 0) return 1;
    return 0;
}

void circle_input(circle *c) {
    point_input(&c->p);
    scanf("%lf", &c->r);
}

double circle_area(circle c) {
    return pi * sqr(c.r);
}

double circle_circumference(circle c) {
    return 2 * pi * c.r;
}

double dist(point a, point b, circle c) {
    line l = {a, b};
    point p11, p12;

    if (!circle_relation(c, a) && !circle_relation(c, b)) return point_distance(a, b);
    
    double ds = point_distance(a, b);
    return ds;
}

int main() {
    double xp, yp, vp;
    double x, y, v, r;
    circle c;

    scanf("%lf %lf %lf", &xp, &yp, &vp);
    point p = {xp, yp};
    scanf("%lf %lf %lf %lf", &x, &y, &v, &r);
    c = (circle){.p = {0, 0}, .r = r};

    double d = 2 * pi * point_distance(p, (point){0, 0});
    int k = 1000;
    double low = 0, high = 1e6;

    while (k--) {
        double mid = (low + high) / 2.0;
        double s = vp * mid;
        double w = fmod(s, d);
        w = (w / d) * 2 * pi;

        point where = point_rotate(p, w);
        double md = dist(where, (point){x, y}, c);

        if (dblcmp(mid * v - md) >= 0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.12lf\n", low);
    return 0;
}
