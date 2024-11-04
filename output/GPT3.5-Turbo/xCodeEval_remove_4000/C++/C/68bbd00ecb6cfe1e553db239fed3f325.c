#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

ll sum(ll *arr, int size) {
    ll s = 0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }
    return s;
}

void do_copy(ll *src, ll *dest, int size) {
    memcpy(dest, src, sizeof(ll) * size);
}

void add_to_knap(ll *arr, int arr_size, ll *dp, int dp_size, int k) {
    ll sum = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
        for (int j = k; j >= i + 1; j--) {
            dp[j] = max(dp[j], dp[j - i - 1] + sum);
        }
    }
}

ll rec(int l, int r, ll **dps, ll *sums, ll **arrs, int k) {
    ll ans = 0;
    ll *dp = dps[l];
    int arr_size = r - l;
    if (l + 1 == r) {
        ans = dp[k];
        ll sum = 0;
        for (int i = 0; i < arr_size && i < k; i++) {
            sum += arrs[l][i];
            ans = max(ans, dp[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        do_copy(dp, dps[l + 1], k + 1);
        add_to_knap(arrs[l], arr_size, dps[l + 1], k + 1, k);
        ans = rec(m, r, dps, sums, arrs, k);
        do_copy(dp, dps[l + 1], k + 1);
        add_to_knap(arrs[m], arr_size, dps[l + 1], k + 1, k);
        ans = max(ans, rec(l, m, dps, sums, arrs, k));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll **dps = (ll **)malloc((n + 1) * sizeof(ll *));
    for (int i = 0; i <= n; i++) {
        dps[i] = (ll *)malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }
    ll *sums = (ll *)malloc(n * sizeof(ll));
    ll **arrs = (ll **)malloc(n * sizeof(ll *));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (ll *)malloc(t * sizeof(ll));
        for (int j = 0; j < t; j++) {
            scanf("%lld", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i] = realloc(arrs[i], k * sizeof(ll));
        }
        sums[i] = sum(arrs[i], t);
    }
    printf("%lld\n", rec(0, n, dps, sums, arrs, k));
    for (int i = 0; i <= n; i++) {
        free(dps[i]);
    }
    free(dps);
    free(sums);
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
}

int main() {
    solve();
    return 0;
}
