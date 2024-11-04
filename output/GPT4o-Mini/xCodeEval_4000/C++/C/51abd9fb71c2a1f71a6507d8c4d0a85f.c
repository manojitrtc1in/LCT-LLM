#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define MAX_PRIME_FACTORS 100
#define INF LLONG_MAX

typedef long long i64;
typedef struct {
    i64 fi;
    i64 se;
} pii;

i64 n, Min = INF, Max = -INF;
pii A[MAX_PRIME_FACTORS];
i64 A_size = 0;

i64 Pow(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 tmp = Pow(a, b / 2);
    if (b % 2 == 0) return (tmp * tmp);
    return (tmp * tmp * a);
}

void Try(i64 id, i64 x1, i64 x2, i64 x3) {
    if (id == A_size) {
        Min = fmin(Min, (x1 + 1) * (x2 + 2) * (x3 + 2));
        Min = fmin(Min, (x1 + 2) * (x2 + 1) * (x3 + 2));
        Min = fmin(Min, (x1 + 2) * (x2 + 2) * (x3 + 1));
        Max = fmax(Max, (x1 + 1) * (x2 + 2) * (x3 + 2));
        Max = fmax(Max, (x1 + 2) * (x2 + 1) * (x3 + 2));
        Max = fmax(Max, (x1 + 2) * (x2 + 2) * (x3 + 1));
        return;
    }
    i64 key = A[id].fi, v = A[id].se;
    for (i64 i = 0; i <= v; i++) {
        for (i64 j = 0; j <= v; j++) {
            for (i64 k = 0; k <= v; k++) {
                if (i + j + k != v) continue;
                Try(id + 1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k));
            }
        }
    }
}

void Input() {
    scanf("%lld", &n);
}

void Solve() {
    i64 N = n;
    i64 i;
    for (i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            A[A_size].fi = i;
            A[A_size].se++;
            n /= i;
        }
        if (A[A_size].se > 0) A_size++;
    }
    if (n > 1) {
        A[A_size].fi = n;
        A[A_size].se = 1;
        A_size++;
    }
    Try(0, 1, 1, 1);
    printf("%lld %lld\n", (Min - N), (Max - N));
}

int main(int argc, char* argv[]) {
    Input();
    Solve();
    return 0;
}
