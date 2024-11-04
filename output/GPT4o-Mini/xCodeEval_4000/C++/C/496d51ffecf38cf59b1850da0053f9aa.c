#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 101
#define eps 0.0000001

long powcnt[N];
long ans;

void preprocess(long num) {
    for (long i = 30; i >= 0; i--) {
        if (num >= (1 << i)) {
            num -= (1 << i);
            powcnt[i]++;
        }
    }
}

void solve(long curp) {
    for (long i = curp; i <= 30; i++) {
        if (powcnt[i] > 0) {
            powcnt[i]--;
            ans++;
            for (long j = curp; j < i; j++) {
                powcnt[j]++;
            }
            break;
        }
    }
}

int main() {
    int n, m;
    ans = 0;
    memset(powcnt, 0, sizeof(powcnt));

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        long x;
        scanf("%ld", &x);
        preprocess(x);
    }

    long *v = (long *)malloc(m * sizeof(long));
    for (int i = 0; i < m; i++) {
        scanf("%ld", &v[i]);
    }

    qsort(v, m, sizeof(long), (int (*)(const void *, const void *))compare);
    for (int i = 0; i < m; i++) {
        solve(v[i]);
    }

    printf("%ld\n", ans);
    free(v);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}
