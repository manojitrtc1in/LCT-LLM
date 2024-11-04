#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long ll;
typedef struct {
    ll* arr;
    int size;
} vll;

typedef struct {
    vll* arr;
    int size;
} vvll;

typedef struct {
    int* arr;
    int size;
} vi;

typedef struct {
    vi* arr;
    int size;
} vvi;

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

void add_to_knap(int i, int dpi, vvll dps, vll sums, vvi arrs, int k) {
    ll* dp = dps.arr[dpi].arr;
    ll v = sums.arr[i];
    int k1 = arrs.arr[i].size;
    for (int j = k; j >= k1; j--) {
        smax(&dp[j], dp[j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, vvll dps, vll sums, vvi arrs, int k) {
    ll ans = 0;
    vi carr = arrs.arr[l];
    ll* dp = dps.arr[dpi].arr;
    if (l + 1 == r) {
        smax(&ans, dp[k]);
        ll sum = 0;
        for (int i = 0; i < k && i < carr.size; i++) {
            sum += carr.arr[i];
            smax(&ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dp, dps.arr[dpi + 1].arr, k + 1);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, dps, sums, arrs, k);
        }
        smax(&ans, rec(m, r, dpi + 1, dps, sums, arrs, k));
        do_copy(dp, dps.arr[dpi + 1].arr, k + 1);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, dps, sums, arrs, k);
        }
        smax(&ans, rec(l, m, dpi + 1, dps, sums, arrs, k));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vll sums;
    sums.arr = (ll*)malloc(sizeof(ll) * n);
    sums.size = n;
    vvi arrs;
    arrs.arr = (vi*)malloc(sizeof(vi) * n);
    arrs.size = n;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs.arr[i].arr = (int*)malloc(sizeof(int) * t);
        arrs.arr[i].size = t;
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs.arr[i].arr[j]);
        }
        if (t > k) {
            arrs.arr[i].size = k;
        }
        sums.arr[i] = sum(arrs.arr[i]);
    }
    vvll dps;
    dps.arr = (vll*)malloc(sizeof(vll) * 13);
    dps.size = 13;
    for (int i = 0; i < 13; i++) {
        dps.arr[i].arr = (ll*)malloc(sizeof(ll) * (k + 1));
        dps.arr[i].size = k + 1;
    }
    printf("%lld\n", rec(0, n, 0, dps, sums, arrs, k));
}

int main() {
    solve();
    return 0;
}
