#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define MOD 1000000007

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);

    int64_t r = 0;
    for (int i = 1; i <= b - 1; i++) {
        r += i;
        if (r >= MOD) {
            r -= MOD;
        }
    }

    int64_t res = (int64_t)a * r % MOD;

    int64_t k = 0;
    for (int i = 1; i <= a; i++) {
        k += (int64_t)i * r % MOD;
        if (k >= MOD) {
            k -= MOD;
        }
    }

    res += (int64_t)b * k % MOD;
    if (res >= MOD) {
        res -= MOD;
    }

    printf("%lld\n", res);
}

int main() {
    srand(time(NULL));
    solve();
    return 0;
}
