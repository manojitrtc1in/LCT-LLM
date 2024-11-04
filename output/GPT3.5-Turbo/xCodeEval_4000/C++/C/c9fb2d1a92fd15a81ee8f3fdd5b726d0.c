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
} vvi;
typedef struct {
    int size;
    ll* arr;
} vll;
typedef struct {
    int size;
    vll* arrs;
} vvll;

int k;
vvll dps;
vll sums;
vvi arrs;

void do_copy(int dpi) {
    memcpy(dps.arrs[dpi + 1].arr, dps.arrs[dpi].arr, sizeof(dps.arrs[0].arr[0]) * (k + 1));
}

void add_to_knap(int i, int dpi) {
    ll v = sums.arr[i];
    int k1 = arrs.arrs[i].size;
    for (int j = k; j >= k1; j--) {
        dps.arrs[dpi].arr[j] = max(dps.arrs[dpi].arr[j], dps.arrs[dpi].arr[j - k1] + v);
    }
}

ll rec(int l, int r, int dpi) {
    ll ans = 0;
    vi carr = arrs.arrs[l];
    vll dp = dps.arrs[dpi];
    if (l + 1 == r) {
        ans = max(ans, dp.arr[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, carr.size); i++) {
            sum += carr.arr[i];
            ans = max(ans, dp.arr[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dpi);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1);
        }
        ans = max(ans, rec(m, r, dpi + 1));
        do_copy(dpi);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1);
        }
        ans = max(ans, rec(l, m, dpi + 1));
    }
    return ans;
}

void solve() {
    int n;
    scanf("%d %d", &n, &k);
    sums.size = n;
    sums.arr = (ll*)malloc(sizeof(ll) * n);
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
        if (t > k) {
            arrs.arrs[i].size = k;
        }
        sums.arr[i] = 0;
        for (int j = 0; j < arrs.arrs[i].size; j++) {
            sums.arr[i] += arrs.arrs[i].arr[j];
        }
    }
    dps.size = 13;
    dps.arrs = (vll*)malloc(sizeof(vll) * 13);
    for (int i = 0; i < 13; i++) {
        dps.arrs[i].size = k + 1;
        dps.arrs[i].arr = (ll*)malloc(sizeof(ll) * (k + 1));
    }
    printf("%lld\n", rec(0, n, 0));
}

int main() {
    solve();
    return 0;
}
