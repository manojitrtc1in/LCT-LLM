#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

typedef long long i64;
typedef struct {
    i64 fi;
    i64 se;
} pii;

i64 x;

pii func(i64 m, i64 n, i64 s) {
    if (m == 0) return (pii){n, s};
    i64 k = cbrt(m);
    i64 x = k * k * k, y = (k - 1) * (k - 1) * (k - 1);
    pii result1 = func(m - x, n + 1, s + x);
    pii result2 = func(x - y - 1, n + 1, s + y);
    return (result1.fi > result2.fi) ? result1 : result2;
}

void Input() {
    scanf("%lld", &x);
}

void Solve() {
    pii Token = func(x, 0, 0);
    printf("%lld %lld\n", Token.fi, Token.se);
}

void ControlIO(int argc, char* argv[]) {
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    if (argc > 2) {
        freopen(argv[2], "w", stdout);
    }
}

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);
    Input();
    Solve();
    return 0;
}
