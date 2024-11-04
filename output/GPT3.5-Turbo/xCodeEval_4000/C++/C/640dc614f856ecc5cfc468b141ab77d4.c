#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long i64;
typedef long double ld;
typedef struct {
    i64 first;
    i64 second;
} pii;

i64 x;

pii func(i64 m, i64 n, i64 s) {
    if (m == 0) return (pii) {n, s};
    i64 k = cbrt(m);
    i64 x = k * k * k, y = (k-1)*(k-1)*(k-1);
    pii res1 = func(m-x, n+1, s+x);
    pii res2 = func(x-y-1, n+1, s+y);
    if (res1.first > res2.first) {
        return res1;
    } else {
        return res2;
    }
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
