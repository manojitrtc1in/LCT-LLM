#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef double DB;

#define MOD 1000000007
#define PI 3.14159265358979323846264

typedef struct {
    DB x, y;
} Po;

DB sqr(DB a) {
    return a * a;
}

DB length(Po p) {
    return sqrt(sqr(p.x) + sqr(p.y));
}

DB atan(Po p) {
    return atan2(p.y, p.x);
}

void input(Po *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

DB d(DB R_, DB R, DB r, DB ss, DB vs, DB vp, DB theta, DB beta) {
    if (theta <= beta || theta >= 2 * PI - beta) {
        return sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * cos(theta));
    } else {
        DB delta = PI - beta - fabs(PI - theta);
        return ss + delta * r;
    }
}

bool f(DB x, DB R_, DB R, DB r, DB ss, DB vs, DB vp, DB alpha, DB beta) {
    DB theta = fmod(x * vp + alpha, 2 * PI);
    if (theta < 0) theta += 2 * PI;
    return d(R_, R, r, ss, vs, vp, theta, beta) <= vs * x;
}

int main() {
    Po s, p;
    DB R_, R, r, ss, vs, vp;
    DB alpha, beta;

    freopen("in.txt", "r", stdin);

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
    beta = acos(r / R_) + acos(r / R);
    if (beta < 0) beta += 2 * PI;

    DB ll = 0, rr = (ss + PI * R) * vs;
    for (int i = 0; i < 100; i++) {
        DB m = (ll + rr) / 2;
        if (f(m, R_, R, r, ss, vs, vp, alpha, beta)) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);
}
