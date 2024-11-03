#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;

ll sum(int *arr, int size) {
    ll s = 0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }
    return s;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *sums = (int *)malloc(n * sizeof(int));
    int **arrs = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arrs[i] = (int *)malloc(t * sizeof(int));
        for (int j = 0; j < t; j++) {
            scanf("%d", &arrs[i][j]);
        }
        if (t > k) {
            arrs[i] = realloc(arrs[i], k * sizeof(int));
        }
        sums[i] = sum(arrs[i], t);
    }

    ll **dps = (ll **)malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = (ll *)malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }

    for (int i = 0; i < n; i++) {
        dps[0][k] = max(dps[0][k], dps[0][k]);
        ll v = sums[i];
        int k1 = arrs[i].size();
        for (int j = k; j >= k1; j--) {
            dps[0][j] = max(dps[0][j], dps[0][j - k1] + v);
        }
    }

    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            for (int i = 1; i <= 12; i++) {
                for (int j = k; j >= 0; j--) {
                    dps[i][j] = max(dps[i][j], dps[i - 1][j]);
                    ll sum = 0;
                    for (int x = 0; x < min(k, arrs[l].size()); x++) {
                        sum += arrs[l][x];
                        dps[i][j] = max(dps[i][j], dps[i - 1][j - x - 1] + sum);
                    }
                }
            }
        }
    }

    printf("%lld\n", dps[12][k]);

    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
    free(sums);
    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
}

int main() {
    solve();
    return 0;
}
