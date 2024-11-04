#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007
#define EPS 1e-2
#define PI 3.14159265358979323846264

typedef struct {
    double x, y;
} Po;

double sqr(double a) {
    return a * a;
}

double length(Po p) {
    return sqrt(sqr(p.x) + sqr(p.y));
}

double atan(Po p) {
    return atan2(p.y, p.x);
}

void input(Po *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

double d(double R_, double R, double r, double theta, double ss, double vp) {
    double delta;
    if (theta <= acos(r / R_) || theta >= 2 * PI - acos(r / R)) {
        return sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * cos(theta));
    } else {
        delta = PI - acos(r / R_) - fabs(PI - theta);
        return ss + delta * r;
    }
}

bool f(double x, double R_, double R, double r, double ss, double vp, double alpha) {
    double theta = x * vp + alpha;
    if (theta < 0) theta += 2 * PI;
    if (theta >= 2 * PI) theta -= 2 * PI;
    return d(R_, R, r, theta, ss, vp) <= x;
}

int main() {
    Po s, p;
    double R_, R, r, ss, vs, vp;
    double alpha, beta, theta, delta;

    input(&p);
    scanf("%lf", &vp);
    input(&s);
    scanf("%lf %lf", &vs, &r);

    R_ = length(s);
    R = length(p);
    vp /= R;
    ss = sqrt(sqr(R_) - sqr(r)) + sqrt(sqr(R) - sqr(r));
    alpha = atan(p) - atan(s);
    if (alpha < 0) alpha += 2 * PI;
    if (alpha >= 2 * PI) alpha -= 2 * PI;
    beta = acos(r / R_) + acos(r / R);
    if (beta < 0) beta += 2 * PI;
    if (beta >= 2 * PI) beta -= 2 * PI;

    double ll = 0, rr = (ss + PI * R) * vs;
    for (int i = 0; i < 200; i++) {
        double m = (ll + rr) / 2;
        if (f(m, R_, R, r, ss, vs, alpha)) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);
}
