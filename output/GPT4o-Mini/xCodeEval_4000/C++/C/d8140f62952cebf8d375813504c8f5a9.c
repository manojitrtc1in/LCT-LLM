#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007
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

double atan2_custom(double y, double x) {
    return atan2(y, x);
}

void input(Po *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

double d(double R_, double R, double r, double theta, double ss, double vp) {
    double delta, beta = acos(r / R_) + acos(r / R);
    if (theta <= beta || theta >= 2 * PI - beta) {
        return sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * cos(theta));
    } else {
        delta = PI - beta - fabs(PI - theta);
        return ss + delta * r;
    }
}

bool f(double x, double R_, double R, double r, double ss, double vp, double alpha) {
    double theta = fmod(x * vp + alpha, 2 * PI);
    if (theta < 0) theta += 2 * PI;
    return d(R_, R, r, theta, ss, vp) <= vs * x;
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
    alpha = atan2_custom(p.y, p.x) - atan2_custom(s.y, s.x);
    if (alpha < 0) alpha += 2 * PI;
    beta = acos(r / R_) + acos(r / R);
    
    double ll = 0, rr = 1e10;
    for (int i = 0; i < 1000; i++) {
        double m = (ll + rr) / 2;
        if (f(m, R_, R, r, ss, vp, alpha)) rr = m; else ll = m;
    }
    printf("%.10lf\n", ll);
}
