#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 400000

int primes[MAXN];

void id0(int n) {
    if (n <= 32) {
        int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
            if (n < primes[i]) {
                for (int j = 0; j < i; j++) {
                    printf("%d ", primes[j]);
                }
                printf("\n");
                return;
            }
        }
        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
            printf("%d ", primes[i]);
        }
        printf("\n");
        return;
    }

    int u = n + 32;
    double lu = log(u);
    int ret[(int)(u / lu + u / lu / lu * 1.5)];
    ret[0] = 2;
    int pos = 1;

    int isnp[(n + 1) / 32 / 2 + 1];
    int sup = (n + 1) / 32 / 2 + 1;

    int id3[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for (int k = 0; k < sizeof(id3) / sizeof(id3[0]); k++) {
        int tp = id3[k];
        ret[pos++] = tp;
        int ptn[tp];
        for (int i = (tp - 3) / 2; i < tp << 5; i += tp) {
            ptn[i >> 5] |= 1 << (i & 31);
        }
        for (int j = 0; j < sup; j += tp) {
            for (int i = 0; i < tp && i + j < sup; i++) {
                isnp[j + i] |= ptn[i];
            }
        }
    }

    int magic[] = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
    int h = n / 2;
    for (int i = 0; i < sup; i++) {
        for (int j = ~isnp[i]; j != 0; j &= j - 1) {
            int pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27];
            int p = 2 * pp + 3;
            if (p > n) {
                break;
            }
            ret[pos++] = p;
            if ((long)p * p > n) {
                continue;
            }
            for (int q = (p * p - 3) / 2; q <= h; q += p) {
                isnp[q >> 5] |= 1 << q;
            }
        }
    }

    for (int i = 0; i < pos; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}

void solve() {
    long n;
    scanf("%ld", &n);
    long ans = 0;
    id0(400000);
    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        long plus = pi(n / primes[i]) - (i + 1);
        if (plus <= 0) {
            break;
        }
        ans += plus;
    }

    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        int p = primes[i];
        if ((long)p * p * p <= n) {
            ans++;
        } else {
            break;
        }
    }
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}