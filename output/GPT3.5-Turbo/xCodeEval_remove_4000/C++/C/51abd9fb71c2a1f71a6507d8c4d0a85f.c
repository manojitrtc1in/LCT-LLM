#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LINF 1000000000000000000LL

typedef long long i64;
typedef long double ld;

typedef struct {
    i64 fi;
    i64 se;
} pii;

typedef struct {
    i64 fi;
    pii se;
} pip;

typedef struct {
    pii fi;
    i64 se;
} ppi;

i64 Min = LINF, Max = -LINF;
i64 n;
pii A[100];

i64 Pow(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 tmp = Pow(a, b/2);
    if (b % 2 == 0) return (tmp * tmp);
    return (tmp * tmp * a);
}

void Try(i64 id, i64 x1, i64 x2, i64 x3) {
    if (id == n) {
        Min = (x1+1)*(x2+2)*(x3+2);
        Min = (x1+2)*(x2+1)*(x3+2);
        Min = (x1+2)*(x2+2)*(x3+1);
        Max = (x1+1)*(x2+2)*(x3+2);
        Max = (x1+2)*(x2+1)*(x3+2);
        Max = (x1+2)*(x2+2)*(x3+1);
        return;
    }
    i64 key = A[id].fi, v = A[id].se;
    for (i64 i=0; i<=v; i++) {
        for (i64 j=0; j<=v; j++) {
            for (i64 k=0; k<=v; k++) {
                if (i + j + k != v) continue;
                Try(id+1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k));
            }
        }
    }
}

void Input() {
    scanf("%lld", &n);
}

void Solve() {
    i64 Map[100] = {0};
    i64 N = n;
    for (i64 i=2; i<=sqrt(n); i++) {
        while (n % i == 0) {
            Map[i]++;
            n /= i;
        }
    }
    if (n > 1) Map[n]++;
    i64 idx = 0;
    for (i64 i=2; i<100; i++) {
        if (Map[i] > 0) {
            A[idx].fi = i;
            A[idx].se = Map[i];
            idx++;
        }
    }
    n = idx;
    Try(0, 1, 1, 1);
    printf("%lld %lld\n", (Min - N), (Max - N));
}

int main() {
    Input();
    Solve();
    return 0;
}
