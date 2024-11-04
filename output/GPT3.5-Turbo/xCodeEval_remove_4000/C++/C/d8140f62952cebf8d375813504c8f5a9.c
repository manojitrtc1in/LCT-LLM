#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Po;

Po s, p, o;
double R_, R, r, ss, vs, vp;
double alpha, beta, theta, delta;

double sqr(double x) {
    return x * x;
}

double fmod(double x, double y) {
    return x - y * floor(x / y);
}

void _R(double *x) {
    *x = fmod(*x, 2 * M_PI);
    if (*x < 0) {
        *x += 2 * M_PI;
    }
}

double d() {
    if (theta <= beta || theta >= 2 * M_PI - beta) {
        return sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * cos(theta));
    } else {
        delta = M_PI - beta - fabs(M_PI - theta);
        return ss + delta * r;
    }
}

int f(double x) {
    theta = x * vp + alpha;
    _R(&theta);
    return d() <= vs * x;
}

int main() {
    scanf("%lf %lf", &p.x, &p.y);
    scanf("%lf", &vp);
    scanf("%lf %lf", &s.x, &s.y);
    scanf("%lf %lf", &vs, &r);

    R_ = sqrt(sqr(s.x) + sqr(s.y));
    R = sqrt(sqr(p.x) + sqr(p.y));
    vp /= R;
    ss = sqrt(sqr(R_) - sqr(r)) + sqrt(sqr(R) - sqr(r));
    alpha = atan2(p.y, p.x) - atan2(s.y, s.x);
    _R(&alpha);
    beta = acos(r / R_) + acos(r / R);
    _R(&beta);

    double ll = 0, rr = 1e10;
    for (int i = 0; i < 1000; i++) {
        double m = (ll + rr) / 2;
        if (f(m)) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);
    return 0;
}
