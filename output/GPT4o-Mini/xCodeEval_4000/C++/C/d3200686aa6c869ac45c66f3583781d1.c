#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define PB push_back

typedef long long LL;
typedef double DB;

const int N = 1001;
const LL INF = 0x7fffffffffffffff;

LL A[N], pl, pr, vl, vr, k;
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
    if (l < l_) l = l_;
    if (r > r_) r = r_;
    return (r - l + 1 > 0) ? (r - l + 1) : 0;
}

int main() {
    dfs(0, 0);
    qsort(A, 10, sizeof(LL), cmpfunc);
    A[10] = INF;

    scanf("%lld %lld %lld %lld %lld", &pl, &pr, &vl, &vr, &k);

    for (int i = 0; i < 10 - k; ++i) {
        int l1 = A[i - 1] + 1, r1 = A[i], l2 = A[i + k - 1], r2 = A[i + k] - 1;
        LL d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr);
        LL d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
        cnt += d1 + d2;
        if (d2 && d2 && k == 1) --cnt;
    }

    printf("%.12lf\n", (DB)cnt / ((pr - pl + 1) * (vr - vl + 1)));
}

int cmpfunc(const void *a, const void *b) {
    return (*(LL*)a - *(LL*)b);
}
