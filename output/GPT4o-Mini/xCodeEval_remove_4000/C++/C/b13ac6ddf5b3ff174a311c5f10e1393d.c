#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long LL;
typedef double DB;
#define MAXN 50
#define MAXL 20

char s[MAXN][MAXL + 1];
int N, L;
LL can[1 << MAXL];

void FLC(LL *A, int x) {
    memset(A, x, sizeof(LL) * (1 << MAXL));
}

int count_bits(int x) {
    return __builtin_popcount(x);
}

double work() {
    FLC(can, ~0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int same = 0;
            for (int k = 0; k < L; k++) {
                if (s[i][k] == s[j][k]) {
                    same |= 1 << k;
                }
            }
            can[same] &= ~(1LL << i);
        }
    }

    for (int mask = (1 << L) - 1; mask >= 0; mask--) {
        for (int p = 0; p < L; p++) {
            if (mask & (1 << p)) {
                can[mask ^ (1 << p)] &= can[mask];
            }
        }
    }

    double ret = 0;
    double cnt[25] = {0};

    for (int mask = (1 << L) - 1; mask >= 0; mask--) {
        int l = count_bits(mask);
        for (int p = 0; p < L; p++) {
            if (mask & (1 << p)) {
                LL r = can[mask ^ (1 << p)] ^ can[mask];
                cnt[l] += count_bits(r);
            }
        }
    }

    for (int i = 1; i <= L; i++) {
        double t = cnt[i] * i;
        double c = 1;
        for (int j = 1; j <= i - 1; j++) {
            c *= L - j + 1;
            c /= j;
        }
        ret += t / c / (L - i + 1);
    }
    return ret / N;
}

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%s", s[i]);
        }
        L = strlen(s[0]);
        double ans = work();
        printf("%.12f\n", ans);
    }
    return 0;
}
