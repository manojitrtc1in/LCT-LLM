#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point a, b;
} Line;

typedef struct {
    Point a, b;
} Segment;

double sqr(double x) {
    return x * x;
}

double dist_sqr(Point a, Point b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

double dist_sqr(Point p, Line l) {
    Point v0 = {l.b.x - l.a.x, l.b.y - l.a.y};
    Point v1 = {p.x - l.a.x, p.y - l.a.y};
    return sqr(fabs(v0.x * v1.y - v0.y * v1.x)) / dist_sqr(v0, v0);
}

double dist_sqr(Point p, Segment l) {
    Point v0 = {l.b.x - l.a.x, l.b.y - l.a.y};
    Point v1 = {p.x - l.a.x, p.y - l.a.y};
    Point v2 = {p.x - l.b.x, p.y - l.b.y};
    if ((v0.x * v1.x + v0.y * v1.y) * (v0.x * v2.x + v0.y * v2.y) <= 0) {
        return dist_sqr(p, (Line) {l.a, l.b});
    } else {
        return fmin(dist_sqr(p, l.a), dist_sqr(p, l.b));
    }
}

int main() {
    Point s, p;
    double vp, vs, r;
    scanf("%lf %lf %lf %lf %lf %lf", &p.x, &p.y, &vp, &s.x, &s.y, &vs);
    scanf("%lf", &r);

    double R_ = sqrt(sqr(s.x) + sqr(s.y));
    double R = sqrt(sqr(p.x) + sqr(p.y));
    vp /= R;
    double ss = sqrt(sqr(R_) - sqr(r)) + sqrt(sqr(R) - sqr(r));
    double alpha = atan2(p.y, p.x) - atan2(s.y, s.x);
    double beta = acos(r / R_) + acos(r / R);

    double ll = 0, rr = 1e10;
    for (int i = 0; i < 1000; i++) {
        double m = (ll + rr) / 2;
        double theta = m * vp + alpha;
        if (theta < 0) {
            theta += 2 * M_PI;
        } else if (theta >= 2 * M_PI) {
            theta -= 2 * M_PI;
        }
        double d;
        if (theta <= beta || theta >= 2 * M_PI - beta) {
            d = sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * cos(theta));
        } else {
            double delta = M_PI - beta - fabs(M_PI - theta);
            d = ss + delta * r;
        }
        if (d <= vs * m) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);
    return 0;
}
