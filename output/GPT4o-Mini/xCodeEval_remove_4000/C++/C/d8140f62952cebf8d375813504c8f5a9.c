#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef long long LL;
typedef double DB;

#define MOD 1000000007
#define EPS 1e-2
#define PI 3.14159265358979323846264

typedef struct {
    DB x, y;
} Po;

inline void inputPo(Po *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

inline DB sqr(DB a) {
    return a * a;
}

inline DB length(Po p) {
    return sqrt(sqr(p.x) + sqr(p.y));
}

inline DB atan(Po p) {
    return atan2(p.y, p.x);
}

inline void normalizeAngle(DB *x) {
    *x = fmod(*x, 2 * PI);
    if (*x < 0) *x += 2 * PI;
}

inline DB distance(Po a, Po b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline bool f(DB x, DB R_, DB R, DB r, DB vs, DB vp, DB alpha, DB beta, DB *delta) {
    DB theta = x * vp + alpha;
    normalizeAngle(&theta);
    if (theta <= beta || theta >= 2 * PI - beta) {
        return distance((Po){R_, R}, (Po){R_, R}) <= vs * x;
    } else {
        *delta = PI - beta - fabs(PI - theta);
        return distance((Po){R_, R}, (Po){R_, R}) + *delta * r <= vs * x;
    }
}

int main() {
    Po s, p;
    DB R_, R, r, ss, vs, vp;
    DB alpha, beta, theta, delta;

    inputPo(&p);
    scanf("%lf", &vp);
    inputPo(&s);
    scanf("%lf %lf", &vs, &r);

    R_ = length(s);
    R = length(p);
    vp /= R;
    ss = sqrt(sqr(R_) - sqr(r)) + sqrt(sqr(R) - sqr(r));
    alpha = atan(p) - atan(s);
    normalizeAngle(&alpha);
    beta = acos(r / R_) + acos(r / R);
    normalizeAngle(&beta);

    DB ll = 0, rr = 1e10;
    for (int i = 0; i < 1000; i++) {
        DB m = (ll + rr) / 2;
        if (f(m, R_, R, r, vs, vp, alpha, beta, &delta)) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);
    return 0;
}
