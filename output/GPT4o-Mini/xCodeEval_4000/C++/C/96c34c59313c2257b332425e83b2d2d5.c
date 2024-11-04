#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define EPS 1e-12L

typedef struct {
    long double real;
    long double imag;
} Point;

typedef struct {
    Point center;
    long double r;
} Circle;

typedef struct {
    long long a;
    long long b;
} Fraction;

long double dot(Point a, Point b) {
    return (a.real * b.real + a.imag * b.imag);
}

long double cross(Point a, Point b) {
    return (a.real * b.imag - a.imag * b.real);
}

long double Dist_Line_Point(Point a1, Point a2, Point b) {
    if (dot((Point){a2.real - a1.real, a2.imag - a1.imag}, (Point){b.real - a1.real, b.imag - a1.imag}) < EPS) 
        return sqrt(pow(b.real - a1.real, 2) + pow(b.imag - a1.imag, 2));
    if (dot((Point){a1.real - a2.real, a1.imag - a2.imag}, (Point){b.real - a2.real, b.imag - a2.imag}) < EPS) 
        return sqrt(pow(b.real - a2.real, 2) + pow(b.imag - a2.imag, 2));
    return fabs(cross((Point){a2.real - a1.real, a2.imag - a1.imag}, (Point){b.real - a1.real, b.imag - a1.imag})) / 
           sqrt(pow(a2.real - a1.real, 2) + pow(a2.imag - a1.imag, 2));
}

bool is_intersected_ls(Point a1, Point a2, Point b1, Point b2) {
    return (cross((Point){a2.real - a1.real, a2.imag - a1.imag}, (Point){b1.real - a1.real, b1.imag - a1.imag}) * 
            cross((Point){a2.real - a1.real, a2.imag - a1.imag}, (Point){b2.real - a1.real, b2.imag - a1.imag}) < EPS) &&
           (cross((Point){b2.real - b1.real, b2.imag - b1.imag}, (Point){a1.real - b1.real, a1.imag - b1.imag}) * 
            cross((Point){b2.real - b1.real, b2.imag - b1.imag}, (Point){a2.real - b1.real, a2.imag - b1.imag}) < EPS);
}

Point intersection_l(Point a1, Point a2, Point b1, Point b2) {
    Point da = {a2.real - a1.real, a2.imag - a1.imag};
    Point db = {b2.real - b1.real, b2.imag - b1.imag};
    return (Point){a1.real + da.real * cross(db, (Point){b1.real - a1.real, b1.imag - a1.imag}) / 
            cross(db, da), a1.imag + da.imag * cross(db, (Point){b1.real - a1.real, b1.imag - a1.imag}) / 
            cross(db, da)};
}

long double Dist_Line_Line(Point a1, Point a2, Point b1, Point b2) {
    if (is_intersected_ls(a1, a2, b1, b2)) {
        return 0;
    }
    return fmin(fmin(Dist_Line_Point(a1, a2, b1), Dist_Line_Point(a1, a2, b2)), 
                fmin(Dist_Line_Point(b1, b2, a1), Dist_Line_Point(b1, b2, a2)));
}

Fraction create_fraction(long long c, long long d) {
    long long gcd = llabs(c) > llabs(d) ? llabs(d) : llabs(c);
    while (gcd) {
        long long temp = c % gcd;
        c = gcd;
        gcd = temp;
    }
    return (Fraction){c / gcd, d / gcd};
}

void solve() {
    long long n, w;
    scanf("%lld %lld", &n, &w);
    Fraction *FI = malloc(n * sizeof(Fraction));
    
    for (long long i = 0; i < n; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        Fraction Left = create_fraction(-a, b - w);
        Fraction Right = create_fraction(-a, b + w);
        FI[i] = Left; // Store left fraction
        FI[i + n] = Right; // Store right fraction
    }
    
    // Sorting logic would go here (not implemented)
    
    long long ans = 0;
    // Compressor and Segment Tree logic would go here (not implemented)
    
    printf("%lld\n", ans);
    free(FI);
}

int main() {
    solve();
    return 0;
}
