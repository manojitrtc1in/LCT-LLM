#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long ll;
typedef struct {
    int size;
    int* arr;
} vi;
typedef struct {
    int size;
    vi* arr;
} vvi;
typedef struct {
    int size;
    ll* arr;
} vll;
typedef struct {
    int size;
    vll* arr;
} vvll;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void smax(ll* a, ll b) {
    if (b > *a) {
        *a = b;
    }
}

ll sum(vi a) {
    ll s = 0;
    for (int i = 0; i < a.size; i++) {
        s += a.arr[i];
    }
    return s;
}

void do_copy(ll* src, ll* dest, int size) {
    memcpy(dest, src, sizeof(ll) * size);
}

void add_to_knap(vi carr, ll* dp, int k) {
    ll v = sum(carr);
    int k1 = carr.size;
    for (int j = k; j >= k1; j--) {
        smax(&dp[j], dp[j - k1] + v);
    }
}

ll rec(vvi arrs, ll** dps, ll* sums, int l, int r, int dpi, int k) {
    ll ans = 0;
    vi carr = arrs.arr[l];
    ll* dp = dps[dpi];
    if (l + 1 == r) {
        smax(&ans, dp[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, carr.size); i++) {
            sum += carr.arr[i];
            smax(&ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dp, dps[dpi + 1], k + 1);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs.arr[i], dps[dpi + 1], k);
        }
        smax(&ans, rec(arrs, dps, sums, m, r, dpi + 1, k));
        do_copy(dp, dps[dpi + 1], k + 1);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs.arr[i], dps[dpi + 1], k);
        }
        smax(&ans, rec(arrs, dps, sums, l, m, dpi + 1, k));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vll sums;
    sums.size = n;
    sums.arr = (ll*)malloc(sizeof(ll) * n);
    vvi arrs;
    arrs.size = n;
    arrs.arr = (vi*)malloc(sizeof(vi) * n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs.arr[i].size = t;
        arrs.arr[i].arr = (int*)malloc(sizeof(int) * t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs.arr[i].arr[j]);
        }
        if (t > k) {
            arrs.arr[i].size = k;
        }
        sums.arr[i] = sum(arrs.arr[i]);
    }
    ll** dps = (ll**)malloc(sizeof(ll*) * 13);
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll*)malloc(sizeof(ll) * (k + 1));
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j <= k; j++) {
            dps[i][j] = 0;
        }
    }
    printf("%lld\n", rec(arrs, dps, sums.arr, 0, n, 0, k));
    for (int i = 0; i < n; i++) {
        free(arrs.arr[i].arr);
    }
    free(arrs.arr);
    free(sums.arr);
    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
}

int main() {
    solve();
    return 0;
}
