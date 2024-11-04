#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAX_Q 200005
#define MAX_N 200005

typedef struct {
    int l, r;
    double p;
} Interval;

int n, q;
int a[MAX_N];
double cur[MAX_Q * 2 + 1];

int cmp(const void *a, const void *b) {
    Interval *ia = (Interval *)a;
    Interval *ib = (Interval *)b;
    return (ia->r - ia->l) - (ib->r - ib->l);
}

int main() {
    scanf("%d", &n);
    scanf("%d", &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }

    Interval itrv[MAX_Q];
    for (int i = 0; i < q; i++) {
        scanf("%d %d %lf", &itrv[i].l, &itrv[i].r, &itrv[i].p);
        itrv[i].l--;
    }
    
    qsort(itrv, q, sizeof(Interval), cmp);
    itrv[q] = (Interval){0, n, 0};

    double cur[MAX_Q * 2 + 1] = {1.0};

    for (int i = 0; i <= q; i++) {
        int l = itrv[i].l;
        int r = itrv[i].r;
        double p = itrv[i].p;

        int zer = 0;
        for (int pv = l; pv < r; pv++) {
            int dif = a[pv] - m + q;
            if (dif > zer) {
                zer = dif;
            }
        }

        for (int j = 0; j < zer; j++) {
            cur[j] = 0;
        }

        double nx[MAX_Q * 2 + 1] = {0};
        for (int j = 0; j <= q * 2; j++) {
            nx[j] += (1 - p) * cur[j];
        }
        for (int j = 0; j < q * 2; j++) {
            nx[j + 1] += p * cur[j];
        }

        memcpy(cur, nx, sizeof(cur));
    }

    double ans = m, sum = 0;
    for (int i = 0; i <= q * 2; i++) {
        if (i < q) assert(cur[i] < 1e-6);
        ans += (i - q) * (cur[i] - sum);
        sum = cur[i];
    }
    assert(cur[q * 2] > 1 - 1e-6);
    printf("%lf\n", ans);
    return 0;
}
