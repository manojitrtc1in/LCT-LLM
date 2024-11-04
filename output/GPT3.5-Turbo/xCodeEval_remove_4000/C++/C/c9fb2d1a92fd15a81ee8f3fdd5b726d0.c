#include <stdio.h>
#include <stdlib.h>
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

ll rec(int l, int r, int k, ll **dps, ll *sums, int **arrs) {
    ll ans = 0;
    int m = (l + r) / 2;
    if (l + 1 == r) {
        ans = dps[l][k];
        ll sum = 0;
        for (int i = 0; i < k && i < arrs[l][0]; i++) {
            sum += arrs[l][i + 1];
            ans = max(ans, dps[l][k - i - 1] + sum);
        }
    } else {
        for (int i = l; i < m; i++) {
            for (int j = k; j >= arrs[i][0]; j--) {
                dps[i + 1][j] = max(dps[i + 1][j], dps[i][j - arrs[i][0]] + sums[i]);
            }
        }
        ans = rec(m, r, k, dps, sums, arrs);
        for (int i = m; i < r; i++) {
            for (int j = k; j >= arrs[i][0]; j--) {
                dps[i + 1][j] = max(dps[i + 1][j], dps[i][j - arrs[i][0]] + sums[i]);
            }
        }
        ans = max(ans, rec(l, m, k, dps, sums, arrs));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll *sums = (ll *)malloc(n * sizeof(ll));
    int **arrs = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int *)malloc((t + 1) * sizeof(int));
        arrs[i][0] = t;
        for (int j = 1; j <= t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i][0] = k;
        }
        sums[i] = sum(arrs[i] + 1, arrs[i][0]);
    }
    ll **dps = (ll **)malloc((n + 1) * sizeof(ll *));
    for (int i = 0; i <= n; i++) {
        dps[i] = (ll *)malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }
    printf("%lld\n", rec(0, n, k, dps, sums, arrs));
    for (int i = 0; i <= n; i++) {
        free(dps[i]);
    }
    free(dps);
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
    free(sums);
}

int main() {
    solve();
    return 0;
}
