#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef long long i64;
typedef struct {
    i64 fi, se;
} pii;

#define MAX_SIZE 100
#define LINF 1e18

i64 n, Min = LINF, Max = -LINF;
pii A[MAX_SIZE];
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
i64 keyCount = sizeof(keymod) / sizeof(i64);

i64 Pow(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 tmp = Pow(a, b / 2);
    if (b % 2 == 0) return (tmp * tmp);
    return (tmp * tmp * a);
}

void Try(i64 id, i64 x1, i64 x2, i64 x3) {
    if (id == n) {
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
            A[n].fi = i;
            A[n].se++;
            n /= i;
        }
    }
    if (n > 1) {
        A[n].fi = n;
        A[n].se++;
    }
    Try(0, 1, 1, 1);
    printf("%lld %lld\n", Min - N, Max - N);
}

int main(int argc, char* argv[]) {
    Input();
    Solve();
    
    int T;
    scanf("%d", &T);
    while (T--) {
        Input();
        Solve();
    }

    return 0;
}
