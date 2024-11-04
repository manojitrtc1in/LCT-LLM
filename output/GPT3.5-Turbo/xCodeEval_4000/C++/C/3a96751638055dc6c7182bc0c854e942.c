#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
typedef struct {
    int size;
    int* arr;
} vector;

vector create_vector(int size) {
    vector v;
    v.size = size;
    v.arr = (int*)malloc(size * sizeof(int));
    return v;
}

void destroy_vector(vector* v) {
    free(v->arr);
}

void read_int(int* x) {
    scanf("%d", x);
}

void print_int(int x) {
    printf("%d", x);
}

void print_newline() {
    printf("\n");
}

void copy_dp(vector* dp, int dpi) {
    memcpy(dp[dpi + 1].arr, dp[dpi].arr, dp[0].size * sizeof(int));
}

void add_to_knap(int i, int dpi, vector* arrs, vector* dp, int k) {
    ll v = 0;
    int k1 = arrs[i].size;
    for (int j = 0; j < k1; j++) {
        v += arrs[i].arr[j];
    }
    for (int j = k; j >= k1; j--) {
        dp[dpi].arr[j] = max(dp[dpi].arr[j], dp[dpi].arr[j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, vector* arrs, vector* dp, int k) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = dp[dpi].arr[k];
        ll sum = 0;
        for (int i = 0; i < arrs[l].size && i < k; i++) {
            sum += arrs[l].arr[i];
            ans = max(ans, dp[dpi].arr[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copy_dp(dp, dpi);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, arrs, dp, k);
        }
        ans = rec(m, r, dpi + 1, arrs, dp, k);
        copy_dp(dp, dpi);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, arrs, dp, k);
        }
        ans = max(ans, rec(l, m, dpi + 1, arrs, dp, k));
    }
    return ans;
}

void solve() {
    int n, k;
    read_int(&n);
    read_int(&k);
    vector sums = create_vector(n);
    vector* arrs = (vector*)malloc(n * sizeof(vector));
    for (int i = 0; i < n; i++) {
        int t;
        read_int(&t);
        arrs[i] = create_vector(t);
        for (int j = 0; j < t; j++) {
            read_int(&arrs[i].arr[j]);
        }
        if (t > k) {
            arrs[i].size = k;
        }
        for (int j = k; j < t; j++) {
            sums.arr[i] += arrs[i].arr[j];
        }
    }
    vector* dp = (vector*)malloc((k + 1) * sizeof(vector));
    for (int i = 0; i <= k; i++) {
        dp[i] = create_vector(n + 1);
    }
    for (int i = 0; i < n; i++) {
        dp[0].arr[i] = sums.arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[j].arr[i + 1] = dp[j].arr[i];
            if (j <= arrs[i].size) {
                dp[j].arr[i + 1] = max(dp[j].arr[i + 1], dp[j - 1].arr[i] + sums.arr[i]);
            }
        }
    }
    print_int(rec(0, n, 0, arrs, dp, k));
    print_newline();
    destroy_vector(&sums);
    for (int i = 0; i < n; i++) {
        destroy_vector(&arrs[i]);
    }
    free(arrs);
    for (int i = 0; i <= k; i++) {
        destroy_vector(&dp[i]);
    }
    free(dp);
}

int main() {
    solve();
    return 0;
}
