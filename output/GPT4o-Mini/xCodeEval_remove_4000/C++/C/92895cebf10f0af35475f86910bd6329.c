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

Po create_po(DB x, DB y) {
    Po p;
    p.x = x;
    p.y = y;
    return p;
}

void input_po(Po *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

DB length_sqr(Po p) {
    return p.x * p.x + p.y * p.y;
}

DB length(Po p) {
    return sqrt(length_sqr(p));
}

DB atan(Po p) {
    return atan2(p.y, p.x);
}

DB dot(Po a, Po b) {
    return a.x * b.x + a.y * b.y;
}

DB det(Po a, Po b) {
    return a.x * b.y - a.y * b.x;
}

DB id1(Po a, Po b) {
    return length_sqr(create_po(a.x - b.x, a.y - b.y));
}

DB id1(Po p, Po a, Po b) {
    Po v0 = create_po(b.x - a.x, b.y - a.y);
    Po v1 = create_po(p.x - a.x, p.y - a.y);
    Po v2 = create_po(p.x - b.x, p.y - b.y);
    if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0) {
        return id1(p, create_po(a.x, a.y), create_po(b.x, b.y));
    } else {
        return fmin(length_sqr(v1), length_sqr(v2));
    }
}

bool isIntersect(Po a1, Po b1, Po a2, Po b2) {
    return
        fmin(a1.x, b1.x) <= fmax(a2.x, b2.x) &&
        fmin(a2.x, b2.x) <= fmax(a1.x, b1.x) &&
        fmin(a1.y, b1.y) <= fmax(a2.y, b2.y) &&
        fmin(a2.y, b2.y) <= fmax(a1.y, b1.y) &&
        sgn(det(a1, a2, b2)) * sgn(det(b1, a2, b2)) <= 0 &&
        sgn(det(a2, a1, b1)) * sgn(det(b2, a1, b1)) <= 0;
}

DB d(DB R_, DB R, DB r, DB theta, DB beta, DB ss) {
    if (theta <= beta || theta >= 2 * PI - beta) {
        return sqrt(R_ * R_ + R * R - 2 * R_ * R * cos(theta));
    } else {
        DB delta = PI - beta - fabs(PI - theta);
        return ss + delta * r;
    }
}

bool f(DB x, DB vs, DB vp, DB R_, DB R, DB r, DB alpha, DB beta) {
    DB theta = x * vp + alpha;
    theta = fmod(theta, 2 * PI);
    if (theta < 0) theta += 2 * PI;
    return d(R_, R, r, theta, beta, ss) <= vs * x;
}

int main() {
    Po s, p;
    DB R_, R, r, ss, vs, vp;
    DB alpha, beta;

    input_po(&p);
    scanf("%lf", &vp);
    input_po(&s);
    scanf("%lf %lf", &vs, &r);

    R_ = length(s);
    R = length(p);
    vp /= R;
    ss = sqrt(R_ * R_ - r * r) + sqrt(R * R - r * r);
    alpha = atan(p) - atan(s);
    alpha = fmod(alpha, 2 * PI);
    if (alpha < 0) alpha += 2 * PI;
    beta = acos(r / R_) + acos(r / R);
    beta = fmod(beta, 2 * PI);
    if (beta < 0) beta += 2 * PI;

    DB ll = 0, rr = (ss + PI * R) * vs;
    for (int i = 0; i < 200; i++) {
        DB m = (ll + rr) / 2;
        if (f(m, vs, vp, R_, R, r, alpha, beta)) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);
    return 0;
}
