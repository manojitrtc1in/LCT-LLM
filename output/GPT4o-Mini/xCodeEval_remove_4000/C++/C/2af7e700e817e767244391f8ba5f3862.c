#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef long long ll;
typedef struct {
    double real;
    double imag;
} Point;

typedef struct {
    Point first;
    Point second;
} Line;

typedef struct {
    Point center;
    double r;
} Circle;

double dot(Point a, Point b) {
    return (a.real * b.real + a.imag * b.imag);
}

double cross(Point a, Point b) {
    return (a.real * b.imag - a.imag * b.real);
}

double id3(Line a, Point b) {
    if (dot((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, 
             (Point){b.real - a.first.real, b.imag - a.first.imag}) < 1e-9) 
        return sqrt(pow(b.real - a.first.real, 2) + pow(b.imag - a.first.imag, 2));
    if (dot((Point){a.first.real - a.second.real, a.first.imag - a.second.imag}, 
             (Point){b.real - a.second.real, b.imag - a.second.imag}) < 1e-9) 
        return sqrt(pow(b.real - a.second.real, 2) + pow(b.imag - a.second.imag, 2));
    return fabs(cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, 
                       (Point){b.real - a.first.real, b.imag - a.first.imag})) / 
           sqrt(pow(a.second.real - a.first.real, 2) + pow(a.second.imag - a.first.imag, 2));
}

int id0(Line a, Line b) {
    return (cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, 
                   (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) * 
            cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, 
                   (Point){b.second.real - a.first.real, b.second.imag - a.first.imag}) < 1e-9) &&
           (cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, 
                   (Point){a.first.real - b.first.real, a.first.imag - b.first.imag}) * 
            cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, 
                   (Point){a.second.real - b.first.real, a.second.imag - b.first.imag}) < 1e-9);
}

Point intersection_l(Line a, Line b) {
    Point da = {a.second.real - a.first.real, a.second.imag - a.first.imag};
    Point db = {b.second.real - b.first.real, b.second.imag - b.first.imag};
    double t = cross(db, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) / 
                cross(db, da);
    return (Point){a.first.real + da.real * t, a.first.imag + da.imag * t};
}

double id8(Line a, Line b) {
    if (id0(a, b) == 1) {
        return 0;
    }
    return fmin(fmin(id3(a, b.first), id3(a, b.second)), 
                fmin(id3(b, a.first), id3(b, a.second)));
}

typedef struct {
    ll a;
    ll b;
} Fraction;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    scanf("%d", &n);
    Vert inputs[n];
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < 5; q++) {
            scanf("%d", &inputs[i].hoge[q]);
        }
    }
    int ans[n];
    int ans_size = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int q = 0; q < n; q++) {
            if (i == q) continue;
            for (int j = q + 1; j < n; j++) {
                if (i == j) continue;
                Vert A, B;
                for (int t = 0; t < 5; t++) {
                    A.hoge[t] = inputs[q].hoge[t] - inputs[i].hoge[t];
                    B.hoge[t] = inputs[j].hoge[t] - inputs[i].hoge[t];
                }
                if (sign(A, B) == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0) break;
        }
        if (ok == 1) {
            ans[ans_size++] = i;
        }
    }
    printf("%d\n", ans_size);
    for (int i = 0; i < ans_size; i++) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}
