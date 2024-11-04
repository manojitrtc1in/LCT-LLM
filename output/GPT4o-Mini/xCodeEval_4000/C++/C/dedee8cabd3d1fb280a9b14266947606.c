#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define INF 0x7fffffff
#define MAX_N 1001

typedef long long LL;

LL A[MAX_N], pl, pr, vl, vr, k;
LL cnt;

void dfs(int k, int n) {
    A[cnt++] = n;
    if (k == 9) return;
    else {
        dfs(k + 1, n * 10 + 4);
        dfs(k + 1, n * 10 + 7);
    }
}

LL I(LL l, LL r, LL l_, LL r_) {
    if (l < l_) l = l_;
    if (r > r_) r = r_;
    return (r - l + 1 > 0) ? (r - l + 1) : 0;
}

int main() {
    cnt = 0;
    dfs(0, 0);
    qsort(A, cnt, sizeof(LL), (int (*)(const void *, const void *))strcmp);
    A[cnt++] = INF;

    scanf("%lld %lld %lld %lld %lld", &pl, &pr, &vl, &vr, &k);

    for (int i = 0; i < cnt - k; i++) {
        LL l1 = A[i - 1] + 1, r1 = A[i], l2 = A[i + k - 1], r2 = A[i + k] - 1;
        LL d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr);
        LL d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
        cnt += d1 + d2;
        if (d2 && d2 && k == 1) --cnt;
    }

    printf("%.12lf\n", (double)cnt / ((pr - pl + 1) * (vr - vl + 1)));
    return 0;
}
