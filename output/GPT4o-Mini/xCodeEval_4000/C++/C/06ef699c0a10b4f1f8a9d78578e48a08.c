#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_N 100000
#define MAX_K 100

typedef long long ll;
typedef struct {
    ll *data;
    size_t size;
} Array;

typedef struct {
    ll **data;
    size_t rows;
    size_t cols;
} Matrix;

void init_array(Array *arr, size_t size) {
    arr->data = (ll *)malloc(size * sizeof(ll));
    arr->size = size;
    memset(arr->data, 0, size * sizeof(ll));
}

void init_matrix(Matrix *mat, size_t rows, size_t cols) {
    mat->data = (ll **)malloc(rows * sizeof(ll *));
    for (size_t i = 0; i < rows; i++) {
        mat->data[i] = (ll *)malloc(cols * sizeof(ll));
        memset(mat->data[i], 0, cols * sizeof(ll));
    }
    mat->rows = rows;
    mat->cols = cols;
}

void free_array(Array *arr) {
    free(arr->data);
}

void free_matrix(Matrix *mat) {
    for (size_t i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
}

void chmax(ll *a, ll b) {
    if (*a < b) {
        *a = b;
    }
}

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    
    Matrix a;
    init_matrix(&a, n, k);
    
    for (ll i = 0; i < n; i++) {
        ll t;
        scanf("%lld", &t);
        for (ll j = 0; j < t && j < k; j++) {
            scanf("%lld", &a.data[i][j]);
        }
    }
    
    Array w;
    init_array(&w, n);
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) {
            w.data[i] += a.data[i][j];
        }
    }
    
    ll ans = 0;
    void solve(void (*solve)(void (*)(void), Array, ll, ll), Array dp, ll l, ll r) {
        if (r - l == 1) {
            ll sum = 0;
            for (ll i = 0; i <= a.data[l].size; i++) {
                chmax(&ans, dp.data[k - i] + sum);
                if (i != a.data[l].size) sum += a.data[l][i];
            }
            return;
        }
        ll m = (r + l) / 2;
        Array dp2;
        init_array(&dp2, k + 1);
        memcpy(dp2.data, dp.data, (k + 1) * sizeof(ll));
        
        for (ll i = m; i < r; i++) {
            for (int j = k - 1; j >= 0; j--) {
                if (a.data[i].size + j <= k) {
                    chmax(&dp2.data[j + a.data[i].size], dp2.data[j] + w.data[i]);
                }
            }
        }
        solve(solve, dp2, l, m);
        
        for (ll i = l; i < m; i++) {
            for (int j = k - 1; j >= 0; j--) {
                if (a.data[i].size + j <= k) {
                    chmax(&dp.data[j + a.data[i].size], dp.data[j] + w.data[i]);
                }
            }
        }
        solve(solve, dp, m, r);
        
        free_array(&dp2);
    }
    
    Array dp;
    init_array(&dp, k + 1);
    solve(solve, dp, 0, n);
    
    printf("%lld\n", ans);
    
    free_array(&w);
    free_array(&dp);
    free_matrix(&a);
    
    return 0;
}
