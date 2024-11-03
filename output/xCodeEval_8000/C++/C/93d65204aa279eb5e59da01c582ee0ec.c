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
    vll* dps;
} vvll;

void read_int(int* f) {
    scanf("%d", f);
}

void read_vint(vi* arr) {
    read_int(&arr->size);
    arr->arr = (int*)malloc(arr->size * sizeof(int));
    for (int i = 0; i < arr->size; i++) {
        read_int(&arr->arr[i]);
    }
}

void read_vvint(vvi* arr) {
    read_int(&arr->size);
    arr->arrs = (vi*)malloc(arr->size * sizeof(vi));
    arr->sums = (ll*)malloc(arr->size * sizeof(ll));
    for (int i = 0; i < arr->size; i++) {
        read_vint(&arr->arrs[i]);
        arr->sums[i] = 0;
        for (int j = 0; j < arr->arrs[i].size; j++) {
            arr->sums[i] += arr->arrs[i].arr[j];
        }
    }
}

void print_ll(ll f) {
    printf("%lld", f);
}

void println_ll(ll f) {
    printf("%lld\n", f);
}

void print_vll(vll* arr) {
    for (int i = 0; i < arr->size; i++) {
        print_ll(arr->arr[i]);
        printf(" ");
    }
    printf("\n");
}

void print_vvll(vvll* arr) {
    for (int i = 0; i < arr->size; i++) {
        print_vll(&arr->dps[i]);
    }
}

void copy_dps(vvll* dps, int dpi) {
    memcpy(&dps->dps[dpi + 1].arr[0], &dps->dps[dpi].arr[0], dps->dps[0].size * sizeof(ll));
}

void add_to_knap(vvi* arrs, vvll* dps, int i, int dpi, int k) {
    ll v = arrs->sums[i];
    int k1 = arrs->arrs[i].size;
    for (int j = k; j >= k1; j--) {
        dps->dps[dpi].arr[j] = max(dps->dps[dpi].arr[j], dps->dps[dpi].arr[j - k1] + v);
    }
}

ll rec(vvi* arrs, vvll* dps, int l, int r, int dpi, int k) {
    ll ans = 0;
    vi* carr = &arrs->arrs[l];
    vll* dp = &dps->dps[dpi];
    if (l + 1 == r) {
        ans = max(ans, dp->arr[k]);
        ll sum = 0;
        for (int i = 0; i < min(k, carr->size); i++) {
            sum += carr->arr[i];
            ans = max(ans, dp->arr[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copy_dps(dps, dpi);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs, dps, i, dpi + 1, k);
        }
        ans = max(ans, rec(arrs, dps, m, r, dpi + 1, k));
        copy_dps(dps, dpi);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs, dps, i, dpi + 1, k);
        }
        ans = max(ans, rec(arrs, dps, l, m, dpi + 1, k));
    }
    return ans;
}

void solve() {
    int n, k;
    read_int(&n);
    read_int(&k);
    vvi arrs;
    read_vvint(&arrs);
    vvll dps;
    dps.size = 13;
    dps.dps = (vll*)malloc(dps.size * sizeof(vll));
    for (int i = 0; i < dps.size; i++) {
        dps.dps[i].size = k + 1;
        dps.dps[i].arr = (ll*)malloc((k + 1) * sizeof(ll));
        memset(dps.dps[i].arr, 0, (k + 1) * sizeof(ll));
    }
    println_ll(rec(&arrs, &dps, 0, n, 0, k));
}

int main() {
    solve();
    return 0;
}
