#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define MAX_N 100000

typedef struct {
    int l;
    int r;
    double p;
} Interval;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int q;
    scanf("%d", &q);
    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m = a[0];
    for (int i = 1; i < n; i++) {
        m = max(m, a[i]);
    }

    Interval itrv[q];
    for (int i = 0; i < q; i++) {
        scanf("%d %d %lf", &itrv[i].l, &itrv[i].r, &itrv[i].p);
        itrv[i].l--;
    }
    for (int i = 0; i < q; i++) {
        for (int j = i + 1; j < q; j++) {
            if (itrv[i].r - itrv[i].l > itrv[j].r - itrv[j].l) {
                Interval temp = itrv[i];
                itrv[i] = itrv[j];
                itrv[j] = temp;
            }
        }
    }
    Interval last = {0, n, 0};

    double cur[MAX_N * 2 + 1];
    for (int i = 0; i <= q * 2; i++) {
        cur[i] = 1.0;
    }

    for (int i = 0; i < q; i++) {
        Interval interval = itrv[i];
        int l = interval.l;
        int r = interval.r;
        double p = interval.p;

        int be = -1;
        int en = -1;
        for (int j = 0; j < i; j++) {
            if (itrv[j].r > l) {
                be = j;
                break;
            }
        }
        for (int j = i + 1; j < q; j++) {
            if (itrv[j].l < r) {
                en = j;
                break;
            }
        }

        double nv[MAX_N * 2 + 1];
        for (int j = 0; j <= q * 2; j++) {
            nv[j] = 1.0;
        }
        int pv = l;
        for (int j = be; j < en; j++) {
            int zer = 0;
            while (pv < itrv[j].l) {
                int dif = a[pv] - m + q;
                if (dif > zer) {
                    zer = dif;
                }
                pv++;
            }
            for (int k = 0; k < zer; k++) {
                nv[k] = 0.0;
            }
            double *tmp = cur;
            for (int k = 0; k <= q * 2; k++) {
                nv[k] *= tmp[k];
            }
            tmp += q * 2 + 1;
        }

        int zer = 0;
        while (pv < r) {
            int dif = a[pv] - m + q;
            if (dif > zer) {
                zer = dif;
            }
            pv++;
        }
        for (int j = 0; j < zer; j++) {
            nv[j] = 0.0;
        }

        double nx[MAX_N * 2 + 1];
        for (int j = 0; j <= q * 2; j++) {
            nx[j] = (1 - p) * nv[j];
        }
        for (int j = 0; j < q * 2; j++) {
            nx[j + 1] += p * nv[j];
        }

        for (int j = 0; j <= q * 2; j++) {
            cur[j] = nx[j];
        }
        last = interval;
    }

    double ans = m;
    double sum = 0.0;
    for (int i = 0; i <= q * 2; i++) {
        if (i < q) {
            if (cur[i] < 1e-6) {
                cur[i] = 0.0;
            }
        }
        ans += (i - q) * (cur[i] - sum);
        sum = cur[i];
    }
    printf("%.15lf\n", ans);

    return 0;
}
