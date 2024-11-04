#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long int ll;

ll** create_2d_array(int rows, int cols) {
    ll** arr = (ll**)malloc(rows * sizeof(ll*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (ll*)malloc(cols * sizeof(ll));
        memset(arr[i], 0, cols * sizeof(ll));
    }
    return arr;
}

void destroy_2d_array(ll** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

void copy_array(ll** src, ll** dest, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        memcpy(dest[i], src[i], cols * sizeof(ll));
    }
}

void add_to_knap(int* arr, int size, ll** dp, int k, int dpi) {
    ll v = 0;
    for (int i = 0; i < size; i++) {
        v += arr[i];
        for (int j = k; j >= size; j--) {
            dp[dpi][j] = max(dp[dpi][j], dp[dpi][j - size] + v);
        }
    }
}

ll rec(int l, int r, ll** dp, int k, int dpi, int** arrs, ll* sums) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = dp[dpi][k];
        ll sum = 0;
        for (int i = 0; i < min(k, (int)arrs[l][0]); i++) {
            sum += arrs[l][i + 1];
            ans = max(ans, dp[dpi][k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copy_array(dp[dpi], dp[dpi + 1], k + 1, k + 1);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs[i] + 1, arrs[i][0], dp[dpi + 1], k, dpi + 1);
        }
        ans = rec(m, r, dp, k, dpi + 1, arrs, sums);
        copy_array(dp[dpi], dp[dpi + 1], k + 1, k + 1);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs[i] + 1, arrs[i][0], dp[dpi + 1], k, dpi + 1);
        }
        ans = max(ans, rec(l, m, dp, k, dpi + 1, arrs, sums));
    }
    return ans;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int** arrs = (int**)malloc(n * sizeof(int*));
    ll* sums = (ll*)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int*)malloc((t + 1) * sizeof(int));
        arrs[i][0] = t;
        for (int j = 1; j <= t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i][0] = k;
        }
        sums[i] = 0;
        for (int j = 1; j <= arrs[i][0]; j++) {
            sums[i] += arrs[i][j];
        }
    }
    ll** dp = create_2d_array(13, k + 1);
    printf("%lld\n", rec(0, n, dp, k, 0, arrs, sums));
    destroy_2d_array(dp, 13);
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
