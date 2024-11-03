#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
typedef struct {
    int size;
    int* arr;
} vi;
typedef struct {
    int size;
    vi* arrs;
    ll* sums;
} vvi;
typedef struct {
    int size;
    ll* arr;
} vll;
typedef struct {
    int size;
    vll* dps;
} vvll;

void smax(ll* a, ll b) {
    if (b > *a) {
        *a = b;
    }
}

void do_copy(vll* dps, int dpi) {
    memcpy(dps[dpi + 1].arr, dps[dpi].arr, sizeof(dps[0].arr[0]) * (dps[0].size + 1));
}

void add_to_knap(vvi* arrs, ll* sums, vll* dps, int i, int dpi, int k) {
    ll v = sums[i];
    int k1 = arrs[i].size;
    for (int j = k; j >= k1; j--) {
        smax(&dps[dpi].arr[j], dps[dpi].arr[j - k1] + v);
    }
}

ll rec(vvi* arrs, ll* sums, vll* dps, int l, int r, int dpi, int k) {
    ll ans = 0;
    vi carr = arrs->arrs[l];
    vll dp = dps[dpi];
    if (l + 1 == r) {
        smax(&ans, dp.arr[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, carr.size); i++) {
            sum += carr.arr[i];
            smax(&ans, dp.arr[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dps, dpi);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs, sums, dps, i, dpi + 1, k);
        }
        smax(&ans, rec(arrs, sums, dps, m, r, dpi + 1, k));
        do_copy(dps, dpi);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs, sums, dps, i, dpi + 1, k);
        }
        smax(&ans, rec(arrs, sums, dps, l, m, dpi + 1, k));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vll sums;
    sums.size = n;
    sums.arr = (ll*)malloc(n * sizeof(ll));
    vvi arrs;
    arrs.size = n;
    arrs.arrs = (vi*)malloc(n * sizeof(vi));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs.arrs[i].size = t;
        arrs.arrs[i].arr = (int*)malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs.arrs[i].arr[j]);
        }
        if (t > k) {
            arrs.arrs[i].size = k;
        }
        sums.arr[i] = 0;
        for (int j = 0; j < arrs.arrs[i].size; j++) {
            sums.arr[i] += arrs.arrs[i].arr[j];
        }
    }
    vvll dps;
    dps.size = 13;
    dps.dps = (vll*)malloc(13 * sizeof(vll));
    for (int i = 0; i < 13; i++) {
        dps.dps[i].size = k + 1;
        dps.dps[i].arr = (ll*)malloc((k + 1) * sizeof(ll));
        memset(dps.dps[i].arr, 0, (k + 1) * sizeof(ll));
    }
    printf("%lld\n", rec(&arrs, sums.arr, dps.dps, 0, n, 0, k));
    for (int i = 0; i < n; i++) {
        free(arrs.arrs[i].arr);
    }
    free(arrs.arrs);
    free(sums.arr);
    for (int i = 0; i < 13; i++) {
        free(dps.dps[i].arr);
    }
    free(dps.dps);
}

int main() {
    solve();
    return 0;
}
