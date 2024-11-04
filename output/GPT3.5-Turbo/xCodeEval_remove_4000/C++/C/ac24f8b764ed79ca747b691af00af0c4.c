#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Po;

Po makePo(double x, double y) {
    Po p;
    p.x = x;
    p.y = y;
    return p;
}

Po addPo(Po a, Po b) {
    Po p;
    p.x = a.x + b.x;
    p.y = a.y + b.y;
    return p;
}

Po subPo(Po a, Po b) {
    Po p;
    p.x = a.x - b.x;
    p.y = a.y - b.y;
    return p;
}

Po mulPo(Po p, double k) {
    Po res;
    res.x = p.x * k;
    res.y = p.y * k;
    return res;
}

Po divPo(Po p, double k) {
    Po res;
    res.x = p.x / k;
    res.y = p.y / k;
    return res;
}

double length_sqr(Po p) {
    return p.x * p.x + p.y * p.y;
}

double length(Po p) {
    return sqrt(length_sqr(p));
}

double dot(Po a, Po b) {
    return a.x * b.x + a.y * b.y;
}

double det(Po a, Po b) {
    return a.x * b.y - a.y * b.x;
}

double id1(Po a, Po b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double id1(Po p, Po l1, Po l2) {
    Po v0 = subPo(l2, l1);
    Po v1 = subPo(p, l1);
    return det(v0, v1) * det(v0, v1) / length_sqr(v0);
}

int sgn(double x) {
    if (x < -1e-2) return -1;
    if (x > 1e-2) return 1;
    return 0;
}

int sgn2(double x, double y) {
    return sgn(x - y);
}

int isIntersect(Po l1a, Po l1b, Po l2a, Po l2b) {
    double x1 = l1a.x, y1 = l1a.y, x2 = l1b.x, y2 = l1b.y;
    double x3 = l2a.x, y3 = l2a.y, x4 = l2b.x, y4 = l2b.y;
    return (x1 <= x4 && x3 <= x2 && y1 <= y4 && y3 <= y2 &&
            sgn(det(makePo(x1, y1), makePo(x3, y3), makePo(x4, y4))) * sgn(det(makePo(x2, y2), makePo(x3, y3), makePo(x4, y4))) <= 0 &&
            sgn(det(makePo(x3, y3), makePo(x1, y1), makePo(x2, y2))) * sgn(det(makePo(x4, y4), makePo(x1, y1), makePo(x2, y2))) <= 0);
}

double id1(Po p, Po l1a, Po l1b, Po l2a, Po l2b) {
    if (isIntersect(l1a, l1b, l2a, l2b)) return 0;
    else return fmin(fmin(id1(p, l1a, l2a, l2b), id1(p, l1b, l2a, l2b)), fmin(id1(p, l2a, l1a, l1b), id1(p, l2b, l1a, l1b)));
}

double f(double x, double vp, double vs, double r, double R_, double R, double ss, double alpha, double beta) {
    double theta, delta;
    theta = x * vp + alpha;
    theta = fmod(theta, 2 * M_PI);
    if (theta < 0) theta += 2 * M_PI;
    if (theta <= beta || theta >= 2 * M_PI - beta) return sqrt(R_ * R_ + R * R - 2 * R_ * R * cos(theta));
    else {
        delta = M_PI - beta - fabs(M_PI - theta);
        return ss + delta * r;
    }
}

int main() {
    Po s, p;
    double vp, vs, r;
    double R_, R, ss, alpha, beta;
    double ll, rr, m;
    int i;

    scanf("%lf %lf", &p.x, &p.y);
    scanf("%lf", &vp);
    scanf("%lf %lf", &s.x, &s.y);
    scanf("%lf %lf", &vs, &r);

    R_ = length(s);
    R = length(p);
    vp /= R;
    ss = sqrt(R_ * R_ - r * r) + sqrt(R * R - r * r);
    alpha = atan2(p.y, p.x) - atan2(s.y, s.x);
    alpha = fmod(alpha, 2 * M_PI);
    if (alpha < 0) alpha += 2 * M_PI;
    beta = acos(r / R_) + acos(r / R);
    ll = 0;
    rr = (ss + M_PI * R) * vs;
    for (i = 0; i < 100; i++) {
        m = (ll + rr) / 2;
        if (f(m, vp, vs, r, R_, R, ss, alpha, beta) <= vs * m) rr = m;
        else ll = m;
    }
    printf("%.10lf\n", ll);

    return 0;
}
