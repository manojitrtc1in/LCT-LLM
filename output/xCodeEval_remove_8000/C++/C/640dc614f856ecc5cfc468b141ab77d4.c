#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef long long i64;
typedef long double ld;

typedef struct {
    i64 first;
    i64 second;
} pii;

pii mp(i64 a, i64 b) {
    pii p;
    p.first = a;
    p.second = b;
    return p;
}

i64 max(i64 a, i64 b) {
    return (a > b) ? a : b;
}

i64 cbrt(i64 x) {
    return (i64)round(cbrtl((long double)x));
}

i64 x;

pii func(i64 m, i64 n, i64 s) {
    if (m == 0) return mp(n, s);
    i64 k = cbrt(m);
    i64 x = k * k * k, y = (k-1)*(k-1)*(k-1);
    return max(func(m-x, n+1, s+x), func(x-y-1, n+1, s+y));
}

void Input() {
    scanf("%lld", &x);
}

void Solve() {
    pii Token = func(x, 0, 0);
    printf("%lld %lld\n", Token.first, Token.second);
}

int main() {
    Input();
    Solve();
    return 0;
}
