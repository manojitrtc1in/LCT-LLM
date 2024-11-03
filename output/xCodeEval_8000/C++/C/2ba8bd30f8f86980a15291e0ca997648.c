#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    vll* arrs;
    ll* sums;
} vvll;

void smax(ll* a, ll b) {
    if (b > *a) {
        *a = b;
    }
}

void do_copy(ll* src, ll* dest, int size) {
    memcpy(dest, src, sizeof(ll) * size);
}

void add_to_knap(int i, int dpi, int k, vvll* dps, vvi* arrs, ll* sums) {
    ll* dp = dps->arrs[dpi].arr;
    ll v = sums[i];
    int k1 = arrs->arrs[i].size;
    for (int j = k; j >= k1; j--) {
        smax(&dp[j], dp[j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, int k, vvll* dps, vvi* arrs, ll* sums) {
    ll ans = 0;
    vll* carr = &arrs->arrs[l];
    ll* dp = dps->arrs[dpi].arr;
    if (l + 1 == r) {
        smax(&ans, dp[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, carr->size); i++) {
            sum += carr->arr[i];
            smax(&ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dp, dps->arrs[dpi + 1].arr, k + 1);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k, dps, arrs, sums);
        }
        smax(&ans, rec(m, r, dpi + 1, k, dps, arrs, sums));
        do_copy(dp, dps->arrs[dpi + 1].arr, k + 1);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, k, dps, arrs, sums);
        }
        smax(&ans, rec(l, m, dpi + 1, k, dps, arrs, sums));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vvi arrs;
    arrs.size = n;
    arrs.arrs = (vi*)malloc(sizeof(vi) * n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs.arrs[i].size = t;
        arrs.arrs[i].arr = (int*)malloc(sizeof(int) * t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs.arrs[i].arr[j]);
        }
    }
    ll* sums = (ll*)malloc(sizeof(ll) * n);
    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        for (int j = 0; j < arrs.arrs[i].size; j++) {
            sums[i] += arrs.arrs[i].arr[j];
        }
    }
    vvll dps;
    dps.size = 13;
    dps.arrs = (vll*)malloc(sizeof(vll) * 13);
    for (int i = 0; i < 13; i++) {
        dps.arrs[i].size = k + 1;
        dps.arrs[i].arr = (ll*)malloc(sizeof(ll) * (k + 1));
        memset(dps.arrs[i].arr, 0, sizeof(ll) * (k + 1));
    }
    printf("%lld\n", rec(0, n, 0, k, &dps, &arrs, sums));
    for (int i = 0; i < n; i++) {
        free(arrs.arrs[i].arr);
    }
    free(arrs.arrs);
    free(sums);
    for (int i = 0; i < 13; i++) {
        free(dps.arrs[i].arr);
    }
    free(dps.arrs);
}

int main() {
    solve();
    return 0;
}
