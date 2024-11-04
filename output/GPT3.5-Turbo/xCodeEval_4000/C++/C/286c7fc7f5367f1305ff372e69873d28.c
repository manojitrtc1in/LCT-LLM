#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 20
#define MAX_BITS (1 << MAX_N)
#define INF 1000000000

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    long long a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // Sort the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                long long temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int d[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        long long c = a[i];
        for (long long j = 2; j * j <= c; j++) {
            while (c % j == 0) {
                d[i]++;
                c /= j;
            }
        }
        if (c != 1) {
            d[i]++;
        }
    }

    int reachable[MAX_BITS];
    for (int i = 0; i < MAX_BITS; i++) {
        reachable[i] = INF;
    }
    reachable[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << i); j++) {
            long long rem = a[i];
            bool good = true;
            for (int k = 0; k < i; k++) {
                if ((j & (1 << k)) != 0) {
                    if (rem % a[k] != 0) {
                        good = false;
                        break;
                    }
                    rem /= a[k];
                }
            }
            int qty = 0;
            for (long long c = 2; c * c <= rem; c++) {
                while (rem % c == 0) {
                    qty++;
                    rem /= c;
                }
            }
            if (rem != 1) {
                qty++;
            }
            int lim;
            if (i == 0) {
                lim = 0;
            } else {
                lim = 1 << (i - 1);
            }
            if (good) {
                for (int k = 0; k < (1 << i); k++) {
                    if ((j & k) == 0 && reachable[j + k] != INF && j + k >= lim) {
                        reachable[(1 << i) + k] = min(reachable[(1 << i) + k], reachable[j + k] + qty + (d[i] == 1 ? 0 : 1));
                    }
                }
            }
        }
    }

    int answer = INF;
    for (int i = (1 << (n - 1)); i < (1 << n); i++) {
        if (reachable[i] != 0) {
            answer = min(answer, reachable[i] + (__builtin_popcount(i) == 1 ? 0 : 1));
        }
    }

    printf("%d\n", answer);

    return 0;
}
