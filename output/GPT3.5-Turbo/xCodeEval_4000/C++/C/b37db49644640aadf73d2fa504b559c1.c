#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 100005
#define MAXQ 100005

int a[MAXN];
int n, q;

typedef struct {
    int l, r;
    double p;
} Interval;

Interval itrv[MAXQ];

double cur[MAXQ * 2 + 1];

void main() {
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

    for (int i = 0; i < q; i++) {
        scanf("%d %d %lf", &itrv[i].l, &itrv[i].r, &itrv[i].p);
        itrv[i].l--;
    }
    itrv[q].l = 0;
    itrv[q].r = n;
    itrv[q].p = 0;

    for (int i = 0; i <= q * 2; i++) {
        cur[i] = 1.0;
    }

    for (int i = 0; i < q; i++) {
        int l = itrv[i].l;
        int r = itrv[i].r;
        double p = itrv[i].p;

        int pv = l;
        for (int j = l; j < r; j++) {
            int zer = 0;
            while (pv < j) {
                int dif = a[pv] - m + q;
                if (dif > zer) {
                    zer = dif;
                }
                pv++;
            }
            for (int k = 0; k < zer; k++) {
                cur[k] = 0;
            }
            for (int k = 0; k <= q * 2; k++) {
                cur[k] *= itrv[i].p;
            }
        }

        int zer = 0;
        while (pv < r) {
            int dif = a[pv] - m + q;
            if (dif > zer) {
                zer = dif;
            }
            pv++;
        }
        for (int k = 0; k < zer; k++) {
            cur[k] = 0;
        }

        double nx[q * 2 + 1];
        for (int k = 0; k <= q * 2; k++) {
            nx[k] = (1 - p) * cur[k];
        }
        for (int k = 0; k < q * 2; k++) {
            nx[k + 1] += p * cur[k];
        }

        for (int k = 0; k <= q * 2; k++) {
            cur[k] = nx[k];
        }
    }

    double ans = m;
    double sum = 0;
    for (int i = 0; i <= q * 2; i++) {
        if (i < q) {
            if (cur[i] > 1e-6) {
                printf("Error: cur[%d] > 1e-6\n", i);
            }
        }
        ans += (i - q) * (cur[i] - sum);
        sum = cur[i];
    }
    if (cur[q * 2] < 1 - 1e-6) {
        printf("Error: cur[%d] < 1 - 1e-6\n", q * 2);
    }
    printf("%.15lf\n", ans);
}

int main() {
    main();
    return 0;
}
