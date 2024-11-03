#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long int ll;

ll sum(int* arr, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res;
}

void smax(ll* a, ll b) {
    if (b > *a) {
        *a = b;
    }
}

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

void solve(int n, int k, int** arrs) {
    ll* sums = (ll*)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        sums[i] = sum(arrs[i], k);
    }

    ll** dps = (ll**)malloc(13 * sizeof(ll*));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll*)malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }

    for (int i = 0; i < n; i++) {
        ll v = sums[i];
        int k1 = k;
        int* carr = arrs[i];
        for (int j = k; j >= k1; j--) {
            smax(&dps[0][j], dps[0][j - k1] + v);
        }
    }

    for (int dpi = 0; dpi < 12; dpi++) {
        memcpy(dps[dpi + 1], dps[dpi], (k + 1) * sizeof(ll));
        for (int i = 0; i < n; i++) {
            ll v = sums[i];
            int k1 = arrs[i][0];
            for (int j = k; j >= k1; j--) {
                smax(&dps[dpi + 1][j], dps[dpi][j - k1] + v);
            }
        }
    }

    printf("%lld\n", dps[12][k]);

    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
    free(sums);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int** arrs = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int*)malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
    }

    solve(n, k, arrs);

    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);

    return 0;
}
