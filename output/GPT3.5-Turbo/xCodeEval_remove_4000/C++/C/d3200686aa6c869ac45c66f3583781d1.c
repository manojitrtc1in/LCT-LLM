#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001

typedef long long LL;

LL A[MAX_N], B[MAX_N];
LL pl, pr, vl, vr, k;
LL cnt;

void dfs(int k, int n) {
    A[k] = n;
    if (k == 9) return;
    else {
        dfs(k + 1, n * 10 + 4);
        dfs(k + 1, n * 10 + 7);
    }
}

LL I(int l, int r, int l_, int r_) {
    if (l > r || l_ > r_) return 0;
    if (l_ <= l && r <= r_) return r - l + 1;
    if (l <= l_ && r_ <= r) return r_ - l_ + 1;
    if (l <= l_ && l_ <= r && r <= r_) return r - l_ + 1;
    if (l_ <= l && l <= r_ && r_ <= r) return r_ - l + 1;
    return 0;
}

int main() {
    dfs(0, 0);
    qsort(A, MAX_N, sizeof(LL), cmpfunc);
    A[MAX_N - 1] = 0x7fffffff;
    scanf("%lld %lld %lld %lld %lld", &pl, &pr, &vl, &vr, &k);

    for (int i = 0; i < MAX_N - k; i++) {
        int l1 = A[i - 1] + 1, r1 = A[i], l2 = A[i + k - 1], r2 = A[i + k] - 1;
        LL d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr), d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
        cnt += d1 + d2;
        if (d1 && d2 && k == 1) cnt--;
    }

    printf("%.12lf\n", (double)cnt / ((pr - pl + 1) * (vr - vl + 1)));

    return 0;
}
