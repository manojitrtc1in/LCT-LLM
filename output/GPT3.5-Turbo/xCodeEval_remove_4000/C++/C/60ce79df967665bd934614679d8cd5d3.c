#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

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

double dist(point a, point b);
double rad(point a, point b, point c);
int dblcmp(double d);
int pointcrossline(line v, point *p1, point *p2);
int pointcrosscircle(circle c, line l, point *p1, point *p2);
int tangentline(point q, circle c, line *l1, line *l2);

double xp, yp, vp;
double x, y, v, r;
circle c;

double dist(point a, point b) {
    line l;
    point p11, p12;

    l.a = a;
    l.b = b;

    if (!pointcrossline(l, &p11, &p12)) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }

    double rd = rad(point(0, 0), p11, p12);
    rd = fmin(rd, 2 * PI - rd);

    double ds = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) - sqrt(pow(p11.x - p12.x, 2) + pow(p11.y - p12.y, 2)) + rd * r;

    line l1, l2;
    tangentline(a, c, &l1, &l2);
    point p1[3];
    p1[0] = l1.b;
    p1[1] = l2.b;
    tangentline(b, c, &l1, &l2);
    point p2[3];
    p2[0] = l1.b;
    p2[1] = l2.b;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ds = fmin(ds, sqrt(pow(a.x - p1[i].x, 2) + pow(a.y - p1[i].y, 2)) + rad(point(0, 0), p1[i], p2[j]) * r + sqrt(pow(b.x - p2[j].x, 2) + pow(b.y - p2[j].y, 2)));
        }
    }

    return ds;
}

double rad(point a, point b, point c) {
    point p = a;
    double c = acos((a.x - p.x) * (b.x - p.x) + (a.y - p.y) * (b.y - p.y)) / (sqrt(pow(a.x - p.x, 2) + pow(a.y - p.y, 2)) * sqrt(pow(b.x - p.x, 2) + pow(b.y - p.y, 2)));
    return c;
}

int dblcmp(double d) {
    if (fabs(d) < 1e-8) {
        return 0;
    }
    return d > 0 ? 1 : -1;
}

int pointcrossline(line v, point *p1, point *p2) {
    if (dblcmp(v.a.x - v.b.x) == 0) {
        if (dblcmp(v.a.y - v.b.y) == 0) {
            return 0;
        }
        *p1 = v.a;
        *p2 = v.b;
        return 1;
    }
    if (dblcmp(v.a.x - v.b.x) == 0) {
        *p1 = v.a;
        *p2 = v.b;
        return 1;
    }
    double a1 = v.b.y - v.a.y;
    double b1 = v.a.x - v.b.x;
    double c1 = v.b.x * v.a.y - v.a.x * v.b.y;
    double k = -a1 / b1;
    double bb = -c1 / b1;
    double d = sqrt(r * r * (1 + k * k) - bb * bb);
    *p1 = (point) {(-k * bb + d) / (1 + k * k), (bb + k * d) / (1 + k * k)};
    *p2 = (point) {(-k * bb - d) / (1 + k * k), (bb - k * d) / (1 + k * k)};
    return 2;
}

int pointcrosscircle(circle c, line l, point *p1, point *p2) {
    double a = l.b.y - l.a.y;
    double b = l.a.x - l.b.x;
    double c = l.b.x * l.a.y - l.a.x * l.b.y;
    double d = fabs(a * c.p.x + b * c.p.y + c) / sqrt(a * a + b * b);
    if (dblcmp(d - c.r) > 0) {
        return 0;
    }
    double x0 = c.p.x;
    double y0 = c.p.y;
    double x1 = l.a.x;
    double y1 = l.a.y;
    double x2 = l.b.x;
    double y2 = l.b.y;
    double dx = x2 - x1;
    double dy = y2 - y1;
    double A = dx * dx + dy * dy;
    double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
    double C = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) - c.r * c.r;
    double delta = B * B - 4 * A * C;
    double t1 = (-B + sqrt(delta)) / (2 * A);
    double t2 = (-B - sqrt(delta)) / (2 * A);
    *p1 = (point) {x1 + t1 * dx, y1 + t1 * dy};
    *p2 = (point) {x1 + t2 * dx, y1 + t2 * dy};
    return 2;
}

int tangentline(point q, circle c, line *l1, line *l2) {
    int x = c.p.x;
    int y = c.p.y;
    int r = c.r;
    int x0 = q.x;
    int y0 = q.y;
    int dx = x0 - x;
    int dy = y0 - y;
    int dist = sqrt(dx * dx + dy * dy);
    if (dist < r) {
        return 0;
    }
    if (dist == r) {
        l1->a = q;
        l1->b = q;
        l2->a = q;
        l2->b = q;
        return 1;
    }
    double d = sqrt(dist * dist - r * r);
    double l = r * r / dist;
    double h = sqrt(r * r - l * l);
    l1->a.x = x0 + l * dx / dist + h * dy / dist;
    l1->a.y = y0 + l * dy / dist - h * dx / dist;
    l1->b.x = x0 + l * dx / dist - h * dy / dist;
    l1->b.y = y0 + l * dy / dist + h * dx / dist;
    l2->a.x = x0 + l * dx / dist + h * dy / dist;
    l2->a.y = y0 + l * dy / dist - h * dx / dist;
    l2->b.x = x0 + l * dx / dist - h * dy / dist;
    l2->b.y = y0 + l * dy / dist + h * dx / dist;
    return 2;
}

int main() {
    scanf("%lf %lf %lf", &xp, &yp, &vp);
    point p = {xp, yp};
    scanf("%lf %lf %lf %lf", &x, &y, &v, &r);
    c.p = (point) {0, 0};
    c.r = r;

    double d = 2 * PI * sqrt(xp * xp + yp * yp);
    int k = 1000;
    double low = 0, high = 1e6;
    while (k--) {
        double mid = (low + high) / 2.0;
        double s = vp * mid;
        double w = fmod(s, d);
        w = (w / d) * 2 * PI;
        point where = {xp * cos(w) - yp * sin(w), xp * sin(w) + yp * cos(w)};
        double md = dist(where, (point) {x, y});
        if (dblcmp(mid * v - md) >= 0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.12lf\n", low);
    return 0;
}
