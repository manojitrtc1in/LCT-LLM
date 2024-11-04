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

int k;
vvll dps;
vll sums;
vvi arrs;

void do_copy(int dpi) {
    memcpy(dps.arr[dpi + 1].arr, dps.arr[dpi].arr, sizeof(ll) * (k + 1));
}

void add_to_knap(int i, int dpi) {
    ll v = sums.arr[i];
    int k1 = arrs.arr[i].size;
    for (int j = k; j >= k1; j--) {
        dps.arr[dpi].arr[j] = max(dps.arr[dpi].arr[j], dps.arr[dpi].arr[j - k1] + v);
    }
}

ll rec(int l, int r, int dpi) {
    ll ans = 0;
    vi carr = arrs.arr[l];
    vll dp = dps.arr[dpi];
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
        sums.arr[i] = 0;
        for (int j = 0; j < arrs.arr[i].size; j++) {
            sums.arr[i] += arrs.arr[i].arr[j];
        }
    }
    dps.size = 13;
    dps.arr = (vll*)malloc(sizeof(vll) * 13);
    for (int i = 0; i < 13; i++) {
        dps.arr[i].size = k + 1;
        dps.arr[i].arr = (ll*)malloc(sizeof(ll) * (k + 1));
    }
    printf("%lld\n", rec(0, n, 0));
}

int main() {
    solve();
    return 0;
}
