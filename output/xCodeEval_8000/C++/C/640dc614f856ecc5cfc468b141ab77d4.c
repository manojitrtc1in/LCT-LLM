#include <stdio.h>
#include <math.h>

typedef long long i64;
typedef struct {
    i64 fi;
    i64 se;
} pii;

pii func(i64 m, i64 n, i64 s) {
    if (m == 0) {
        pii result;
        result.fi = n;
        result.se = s;
        return result;
    }
    i64 k = cbrt(m);
    i64 x = k * k * k, y = (k - 1) * (k - 1) * (k - 1);
    pii result1 = func(m - x, n + 1, s + x);
    pii result2 = func(x - y - 1, n + 1, s + y);
    if (result1.fi > result2.fi) {
        return result1;
    } else {
        return result2;
    }
}

void Input(i64* x) {
    scanf("%lld", x);
}

void Solve(i64 x) {
    pii Token = func(x, 0, 0);
    printf("%lld %lld\n", Token.fi, Token.se);
}

int main() {
    i64 x;
    Input(&x);
    Solve(x);
    return 0;
}
