#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MOD 1000000007

void printInt64(int64_t value) {
    printf("%lld", value);
}

int64_t readInt64() {
    int64_t value;
    scanf("%lld", &value);
    return value;
}

void solve() {
    int64_t a = readInt64();
    int64_t b = readInt64();

    int64_t r = 0;
    for (int64_t i = 1; i <= b - 1; i++) {
        r += i;
        if (r >= MOD) {
            r -= MOD;
        }
    }

    int64_t res = (a * r) % MOD;

    int64_t k = 0;
    for (int64_t i = 1; i <= a; i++) {
        k += (i * r) % MOD;
        if (k >= MOD) {
            k -= MOD;
        }
    }

    res += (b * k) % MOD;
    if (res >= MOD) {
        res -= MOD;
    }

    printInt64(res);
    printf("\n");
}

int main() {
    solve();
    return 0;
}
