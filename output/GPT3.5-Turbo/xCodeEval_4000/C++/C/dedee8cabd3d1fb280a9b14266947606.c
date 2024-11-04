#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001

int A[MAX_N];
long long pl, pr, vl, vr, k;
long long cnt;

void dfs(int k, int n) {
    A[k] = n;
    if (k == 9) return;
    else {
        dfs(k + 1, n * 10 + 4);
        dfs(k + 1, n * 10 + 7);
    }
}

long long I(int l, int r, int l_, int r_) {
    if (l > r || l_ > r_) return 0;
    int max_l = (l > l_) ? l : l_;
    int min_r = (r < r_) ? r : r_;
    return (max_l <= min_r) ? (min_r - max_l + 1) : 0;
}

int main() {
    dfs(0, 0);
    qsort(A, MAX_N, sizeof(int), cmpfunc);
    A[MAX_N - 1] = 2147483647;
    scanf("%lld %lld %lld %lld %lld", &pl, &pr, &vl, &vr, &k);

    for (int i = 0; i < MAX_N - k; i++) {
        int l1 = A[i - 1] + 1, r1 = A[i], l2 = A[i + k - 1], r2 = A[i + k] - 1;
        long long d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr), d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
        cnt += d1 + d2;
        if (d1 && d2 && k == 1) cnt--;
    }

    printf("%.12lf\n", (double)cnt / ((pr - pl + 1) * (vr - vl + 1)));
    return 0;
}
