#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double eps = 1e-8;
const double pi = acos(-1.0);

int dblcmp(double d) {
    if (fabs(d) < eps) return 0;
    return d > eps ? 1 : -1;
}

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

inline double sqr(double x) { return x * x; }

void point_input(point *p) {
    scanf("%lf%lf", &p->x, &p->y);
}

void point_output(point p) {
    printf("%.12f %.12f\n", p.x, p.y);
}

bool point_equal(point a, point b) {
    return dblcmp(a.x - b.x) == 0 && dblcmp(a.y - b.y) == 0;
}

bool point_less(point a, point b) {
    return dblcmp(a.x - b.x) == 0 ? dblcmp(a.y - b.y) < 0 : a.x < b.x;
}

double point_len(point p) {
    return hypot(p.x, p.y);
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

double point_rad(point a, point b, point p) {
    double c = acos((point_sub(a, p).dot(point_sub(b, p))) / (point_distance(a, p) * point_distance(b, p)));
    return c;
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

double line_angle(line l) {
    double k = atan2(l.b.y - l.a.y, l.b.x - l.a.x);
    if (dblcmp(k) < 0) k += pi;
    if (dblcmp(k - pi) == 0) k -= pi;
    return k;
}

int line_relation(line l, point p) {
    int c = dblcmp(point_sub(p, l.a).det(point_sub(l.b, l.a)));
    if (c < 0) return 1;
    if (c > 0) return 2;
    return 3;
}

bool line_point_on_seg(line l, point p) {
    return dblcmp(point_sub(p, l.a).det(point_sub(l.b, l.a))) == 0 && dblcmp(point_sub(p, l.a).dot(point_sub(p, l.b))) <= 0;
}

bool line_parallel(line l1, line l2) {
    return dblcmp(point_sub(l1.b, l1.a).det(point_sub(l2.b, l2.a))) == 0;
}

point line_cross_point(line l1, line l2) {
    double a1 = point_sub(l2.b, l2.a).det(point_sub(l1.a, l2.a));
    double a2 = point_sub(l2.b, l2.a).det(point_sub(l1.b, l2.a));
    return (point){(l1.a.x * a2 - l1.b.x * a1) / (a2 - a1), (l1.a.y * a2 - l1.b.y * a1) / (a2 - a1)};
}

double circle_area(circle c) {
    return pi * sqr(c.r);
}

double circle_circumference(circle c) {
    return 2 * pi * c.r;
}

int main() {
    double xp, yp, vp;
    double x, y, v, r;
    circle c;

    scanf("%lf %lf %lf", &xp, &yp, &vp);
    point p = {xp, yp};
    scanf("%lf %lf %lf %lf", &x, &y, &v, &r);
    c = (circle){{0, 0}, r};

    double d = 2 * pi * point_distance(p, (point){0, 0});
    int k = 1000;
    double low = 0, high = 1e6;

    while (k--) {
        double mid = (low + high) / 2.0;
        double s = vp * mid;
        double w = fmod(s, d);
        w = (w / d) * 2 * pi;

        point where = point_rotate(p, w);
        double md = point_distance(where, (point){x, y});

        if (dblcmp(mid * v - md) >= 0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.12lf\n", low);
    return 0;
}
