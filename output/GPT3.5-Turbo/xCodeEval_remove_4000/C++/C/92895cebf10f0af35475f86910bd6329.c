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

typedef struct {
    Po a, b;
} Line;

Line makeLine(Po a, Po b) {
    Line l;
    l.a = a;
    l.b = b;
    return l;
}

typedef struct {
    Po a, b;
} Seg;

Seg makeSeg(Po a, Po b) {
    Seg s;
    s.a = a;
    s.b = b;
    return s;
}

double dot(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}

double dotPo(Po a, Po b) {
    return dot(a.x, a.y, b.x, b.y);
}

double dotLine(Line l1, Line l2) {
    return dot(l1.b.x - l1.a.x, l1.b.y - l1.a.y, l2.b.x - l2.a.x, l2.b.y - l2.a.y);
}

double det(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

double detPo(Po a, Po b) {
    return det(a.x, a.y, b.x, b.y);
}

double detLine(Line l1, Line l2) {
    return det(l1.b.x - l1.a.x, l1.b.y - l1.a.y, l2.b.x - l2.a.x, l2.b.y - l2.a.y);
}

double sqr(double a) {
    return a * a;
}

double length_sqrPo(Po p) {
    return sqr(p.x) + sqr(p.y);
}

double lengthPo(Po p) {
    return sqrt(length_sqrPo(p));
}

double id1Po(Po a, Po b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

double id1LinePo(Line l, Po p) {
    Po v0 = makePo(l.b.x - l.a.x, l.b.y - l.a.y);
    Po v1 = makePo(p.x - l.a.x, p.y - l.a.y);
    return sqr(fabs(detPo(v0, v1))) / length_sqrPo(v0);
}

double id1LineSeg(Line l, Seg s) {
    Po v0 = makePo(l.b.x - l.a.x, l.b.y - l.a.y);
    Po v1 = makePo(s.a.x - l.a.x, s.a.y - l.a.y);
    Po v2 = makePo(s.b.x - l.a.x, s.b.y - l.a.y);
    if (sgn(detPo(v0, v1)) * sgn(detPo(v0, v2)) <= 0) {
        return id1LinePo(l, s);
    } else {
        return fmin(length_sqrPo(v1), length_sqrPo(v2));
    }
}

int sgn(double x) {
    return x < -1e-2 ? -1 : x > 1e-2;
}

int sgnPo(Po p) {
    return sgn(p.x) || sgn(p.y);
}

int sgnLine(Line l) {
    return sgnPo(makePo(l.b.x - l.a.x, l.b.y - l.a.y));
}

int sgnSeg(Seg s) {
    return sgnLine(makeLine(s.a, s.b));
}

int isIntersect(Seg l1, Seg l2) {
    if (fmin(l1.a.x, l1.b.x) <= fmax(l2.a.x, l2.b.x) &&
        fmin(l2.a.x, l2.b.x) <= fmax(l1.a.x, l1.b.x) &&
        fmin(l1.a.y, l1.b.y) <= fmax(l2.a.y, l2.b.y) &&
        fmin(l2.a.y, l2.b.y) <= fmax(l1.a.y, l1.b.y) &&
        sgn(det(l1.a, l2.a, l2.b)) * sgn(det(l1.b, l2.a, l2.b)) <= 0 &&
        sgn(det(l2.a, l1.a, l1.b)) * sgn(det(l2.b, l1.a, l1.b)) <= 0) {
        return 1;
    } else {
        return 0;
    }
}

double id1Seg(Seg l1, Seg l2) {
    if (isIntersect(l1, l2)) {
        return 0;
    } else {
        return fmin(fmin(id1LinePo(makeLine(l1.a, l1.b), l2.a), id1LinePo(makeLine(l1.a, l1.b), l2.b)),
                    fmin(id1LinePo(makeLine(l2.a, l2.b), l1.a), id1LinePo(makeLine(l2.a, l2.b), l1.b)));
    }
}

double atanPo(Po p) {
    return atan2(p.y, p.x);
}

double atanLine(Line l) {
    return atanPo(makePo(l.b.x - l.a.x, l.b.y - l.a.y));
}

double atanSeg(Seg s) {
    return atanLine(makeLine(s.a, s.b));
}

double f(double x, double vp, double alpha, double beta, double ss, double vs, double r, double R_, double R) {
    double theta, delta;
    theta = x * vp + alpha;
    theta = fmod(theta, 2 * M_PI);
    if (theta < 0) {
        theta += 2 * M_PI;
    }
    if (theta <= beta || theta >= 2 * M_PI - beta) {
        return sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * cos(theta));
    } else {
        delta = M_PI - beta - fabs(M_PI - theta);
        return ss + delta * r;
    }
}

int main() {
    Po s, p;
    double vp, vs, r;
    double R_, R, ss;
    double alpha, beta;
    double ll, rr;
    double m;

    scanf("%lf %lf", &p.x, &p.y);
    scanf("%lf", &vp);
    scanf("%lf %lf", &s.x, &s.y);
    scanf("%lf %lf", &vs, &r);

    R_ = lengthPo(s);
    R = lengthPo(p);
    vp /= R;
    ss = sqrt(sqr(R_) - sqr(r)) + sqrt(sqr(R) - sqr(r));
    alpha = atanPo(p) - atanPo(s);
    alpha = fmod(alpha, 2 * M_PI);
    if (alpha < 0) {
        alpha += 2 * M_PI;
    }
    beta = acos(r / R_) + acos(r / R);
    ll = 0;
    rr = (ss + M_PI * R) * vs;
    for (int i = 0; i < 200; i++) {
        m = (ll + rr) / 2;
        if (f(m, vp, alpha, beta, ss, vs, r, R_, R) <= vs * m) {
            rr = m;
        } else {
            ll = m;
        }
    }
    printf("%.10lf\n", ll);

    return 0;
}
