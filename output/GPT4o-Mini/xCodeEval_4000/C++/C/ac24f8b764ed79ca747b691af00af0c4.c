#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007
#define EPS 1e-2
#define PI 3.14159265358979323846264

typedef struct {
    double x, y;
} Po;

void inputPo(Po *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

double length_sqr(Po p) {
    return p.x * p.x + p.y * p.y;
}

double length(Po p) {
    return sqrt(length_sqr(p));
}

double atan(Po p) {
    return atan2(p.y, p.x);
}

double dot(Po a, Po b) {
    return a.x * b.x + a.y * b.y;
}

double det(Po a, Po b) {
    return a.x * b.y - a.y * b.x;
}

double dist_sqr(Po a, Po b) {
    return length_sqr((Po){a.x - b.x, a.y - b.y});
}

double dist(Po a, Po b) {
    return sqrt(dist_sqr(a, b));
}

double d(Po s, Po p, double R_, double R, double r, double theta, double beta, double ss, double vp) {
    if (theta <= beta || theta >= 2 * PI - beta) {
        return sqrt(R_ * R_ + R * R - 2 * R_ * R * cos(theta));
    } else {
        double delta = PI - beta - fabs(PI - theta);
        return ss + delta * r;
    }
}

bool f(double x, Po s, Po p, double R_, double R, double r, double vs, double vp, double alpha) {
    double theta = x * vp + alpha;
    if (theta < 0) theta += 2 * PI;
    return d(s.length(), p.length(), R_, R, r, theta, acos(r / R_) + acos(r / R), sqrt(length_sqr(R_) - r * r) + sqrt(length_sqr(R) - r * r), vs) <= vs * x;
}

int main() {
    Po s, p;
    double R_, R, r, ss, vs, vp;
    double alpha, beta, theta, delta;

    inputPo(&p);
    scanf("%lf", &vp);
    inputPo(&s);
    scanf("%lf %lf", &vs, &r);

    R_ = length(s);
    R = length(p);
    vp /= R;
    ss = sqrt(length_sqr(R_) - r * r) + sqrt(length_sqr(R) - r * r);
    alpha = atan(p) - atan(s);
    if (alpha < 0) alpha += 2 * PI;
    beta = acos(r / R_) + acos(r / R);
    if (beta < 0) beta += 2 * PI;

    double ll = 0, rr = (ss + PI * R) * vs;
    for (int i = 0; i < 100; i++) {
        double m = (ll + rr) / 2;
        if (f(m, s, p, R_, R, r, vs, vp, alpha)) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);
    return 0;
}
