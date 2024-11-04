#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

typedef double complex point;
#define EPS 1e-5
#define OO 1e9
#define X creal
#define Y cimag
#define vec(a,b) ((b)-(a))
#define length(v) (cabs(v))
#define dot(a,b) (creal(conj(a)*(b)))
#define cross(a,b) (cimag(conj(a)*(b)))
#define rotate(v,t) (cexp(I*(t)) * (v))
#define normalize(p) ((p) / length(p))

int Xc, Yc, Vc;
int Xb, Yb, Vb, r;
double pi = acos(-1.0);
point planet;
point ship;

double arc_length(point a, point b, double r) {
    double Ang = atan2(Y(a), X(a)) - atan2(Y(b), X(b));
    if (Ang < 0) {
        Ang += 2 * pi;
    }
    if (Ang > pi) {
        Ang = 2 * pi - Ang;
    }
    return Ang * r;
}

double pointSegmentDist(point a, point b, point p) {
    double d1 = length(vec(a, p));
    double d2 = length(vec(b, p));
    if (dot(vec(a, b), vec(a, p)) < EPS)
        return d1;
    if (dot(vec(b, a), vec(b, p)) < EPS)
        return d2;
    return fabs(cross(vec(a, b), vec(a, p))) / length(vec(a, b));
}

void tangentPoints(point cen, double r, point p, point *r1, point *r2) {
    double lensqr = length(vec(cen, p));
    if (lensqr < r * r) {
        *r1 = *r2 = p;
        return;
    }
    point cp = vec(cen, p);
    double h = length(cp);
    double a = acos(r / h);
    cp = normalize(cp) * r;
    *r1 = rotate(cp, a) + cen;
    *r2 = rotate(cp, -a) + cen;
}

int main() {
    scanf("%d %d %d", &Xc, &Yc, &Vc);
    scanf("%d %d %d %d", &Xb, &Yb, &Vb, &r);
    planet = CMPLX(Xc, Yc);
    ship = CMPLX(Xb, Yb);
    double R = length(planet);
    double w = Vc / R;
    double left = 0, right = 1ll << 30;

    for (int i = 0; i < 300; i++) {
        double mid = (right + left) / 2;
        point new_planet = rotate(planet, w * mid);
        double distance;

        if (pointSegmentDist(ship, new_planet, CMPLX(0, 0)) < r) {
            point a, b, c, d;
            tangentPoints(CMPLX(0, 0), r, ship, &a, &b);
            tangentPoints(CMPLX(0, 0), r, new_planet, &c, &d);
            distance = OO;
            distance = fmin(distance, length(vec(ship, a)) + length(vec(c, new_planet)) + arc_length(a, c, r));
            distance = fmin(distance, length(vec(ship, b)) + length(vec(c, new_planet)) + arc_length(b, c, r));
            distance = fmin(distance, length(vec(ship, a)) + length(vec(d, new_planet)) + arc_length(a, d, r));
            distance = fmin(distance, length(vec(ship, b)) + length(vec(d, new_planet)) + arc_length(b, d, r));
        } else {
            distance = length(vec(ship, new_planet));
        }

        if (distance / Vb < mid) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%.10f\n", left);
    return 0;
}
