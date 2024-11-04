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

double dot(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double det(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

double dist_sqr(Point p1, Point p2) {
    return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

double dist_sqr_point_line(Point p, Line l) {
    Point v0 = {l.b.x - l.a.x, l.b.y - l.a.y};
    Point v1 = {p.x - l.a.x, p.y - l.a.y};
    return pow(fabs(det(v0, v1)), 2) / dist_sqr(v0, v0);
}

double dist_sqr_point_segment(Point p, Segment s) {
    Point v0 = {s.b.x - s.a.x, s.b.y - s.a.y};
    Point v1 = {p.x - s.a.x, p.y - s.a.y};
    Point v2 = {p.x - s.b.x, p.y - s.b.y};
    if (dot(v0, v1) * dot(v0, v2) <= 0) {
        return dist_sqr_point_line(p, (Line){s.a, s.b});
    } else {
        return fmin(dist_sqr(p, s.a), dist_sqr(p, s.b));
    }
}

int main() {
    Point s, p;
    double vp, vs, r;
    scanf("%lf %lf %lf %lf %lf %lf", &p.x, &p.y, &vp, &s.x, &s.y, &vs);
    scanf("%lf", &r);

    double R_ = sqrt(pow(s.x, 2) + pow(s.y, 2));
    double R = sqrt(pow(p.x, 2) + pow(p.y, 2));
    vp /= R;

    double ss = sqrt(pow(R_, 2) - pow(r, 2)) + sqrt(pow(R, 2) - pow(r, 2));
    double alpha = atan2(p.y, p.x) - atan2(s.y, s.x);
    double beta = acos(r / R_) + acos(r / R);

    double ll = 0, rr = (ss + M_PI * R) * vs;
    for (int i = 0; i < 100; i++) {
        double m = (ll + rr) / 2;
        double theta = m * vp + alpha;
        while (theta < 0) {
            theta += 2 * M_PI;
        }
        while (theta >= 2 * M_PI) {
            theta -= 2 * M_PI;
        }
        double d;
        if (theta <= beta || theta >= 2 * M_PI - beta) {
            d = sqrt(pow(R_, 2) + pow(R, 2) - 2 * R_ * R * cos(theta));
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
