#include <stdio.h>
#include <stdbool.h>
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
    vll* arrs;
} vvll;

void smax(ll* a, ll b) {
    if (b > *a) {
        *a = b;
    }
}

void do_copy(int dpi, vvll* dps, int k) {
    memcpy(dps[dpi + 1].arr, dps[dpi].arr, sizeof(dps->arr[0]) * (k + 1));
}

void add_to_knap(int i, int dpi, vvll* dps, vvi* arrs, ll* sums, int k) {
    ll v = sums[i];
    int k1 = arrs[i].size;
    for (int j = k; j >= k1; j--) {
        smax(&dps[dpi].arr[j], dps[dpi].arr[j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, vvll* dps, vvi* arrs, ll* sums, int k) {
    ll ans = 0;
    vi* carr = &arrs->arrs[l];
    vll* dp = &dps->arr[dpi];
    if (l + 1 == r) {
        smax(&ans, dp->arr[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, carr->size); i++) {
            sum += carr->arr[i];
            smax(&ans, dp->arr[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi, dps, k);
        for (int i = l; i < m - 1; i++) {
            add_to_knap(i, dpi + 1, dps, arrs, sums, k);
        }
        smax(&ans, rec(m, r, dpi + 1, dps, arrs, sums, k));
        do_copy(dpi, dps, k);
        for (int i = m; i < r - 1; i++) {
            add_to_knap(i, dpi + 1, dps, arrs, sums, k);
        }
        smax(&ans, rec(l, m, dpi + 1, dps, arrs, sums, k));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vvi arrs;
    arrs.size = n;
    arrs.arrs = (vi*)malloc(n * sizeof(vi));
    ll* sums = (ll*)malloc(n * sizeof(ll));
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
        sums[i] = 0;
        for (int j = 0; j < arrs.arrs[i].size; j++) {
            sums[i] += arrs.arrs[i].arr[j];
        }
    }
    vvll dps;
    dps.size = 13;
    dps.arr = (vll*)malloc(13 * sizeof(vll));
    for (int i = 0; i < 13; i++) {
        dps.arr[i].size = k + 1;
        dps.arr[i].arr = (ll*)malloc((k + 1) * sizeof(ll));
        memset(dps.arr[i].arr, 0, (k + 1) * sizeof(ll));
    }
    printf("%lld\n", rec(0, n, 0, &dps, &arrs, sums, k));
}

int main() {
    solve();
    return 0;
}
