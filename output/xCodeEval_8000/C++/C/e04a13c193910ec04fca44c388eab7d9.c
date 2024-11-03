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

vector* create_vector(int size) {
    vector* vec = (vector*)malloc(sizeof(vector));
    vec->size = size;
    vec->arr = (int*)malloc(size * sizeof(int));
    return vec;
}

void destroy_vector(vector* vec) {
    free(vec->arr);
    free(vec);
}

void read_int(int* x) {
    scanf("%d", x);
}

void read_vector(vector* vec) {
    for (int i = 0; i < vec->size; i++) {
        read_int(&vec->arr[i]);
    }
}

void print_int(int x) {
    printf("%d", x);
}

void print_vector(vector* vec) {
    for (int i = 0; i < vec->size; i++) {
        print_int(vec->arr[i]);
        if (i != vec->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

ll sum(vector* vec) {
    ll s = 0;
    for (int i = 0; i < vec->size; i++) {
        s += vec->arr[i];
    }
    return s;
}

void copy_vector(vector* src, vector* dest) {
    memcpy(dest->arr, src->arr, src->size * sizeof(int));
}

void add_to_knap(vector* arr, int k, vector* dp) {
    ll v = sum(arr);
    int k1 = arr->size;
    for (int j = k; j >= k1; j--) {
        dp->arr[j] = max(dp->arr[j], dp->arr[j - k1] + v);
    }
}

ll rec(int l, int r, int k, vector** dps, vector** arrs) {
    ll ans = 0;
    vector* dp = dps[l];
    vector* carr = arrs[l];
    if (l + 1 == r) {
        ans = dp->arr[k];
        ll sum = 0;
        for (int i = 0; i < carr->size && i <= k; i++) {
            sum += carr->arr[i];
            ans = max(ans, dp->arr[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copy_vector(dp, dps[l + 1]);
        for (int i = l; i < m; i++) {
            add_to_knap(arrs[i], k, dps[l + 1]);
        }
        ans = rec(m, r, k, dps, arrs);
        copy_vector(dp, dps[l + 1]);
        for (int i = m; i < r; i++) {
            add_to_knap(arrs[i], k, dps[l + 1]);
        }
        ans = max(ans, rec(l, m, k, dps, arrs));
    }
    return ans;
}

void solve() {
    int n, k;
    read_int(&n);
    read_int(&k);
    vector** dps = (vector**)malloc((n + 1) * sizeof(vector*));
    vector** arrs = (vector**)malloc(n * sizeof(vector*));
    for (int i = 0; i <= n; i++) {
        dps[i] = create_vector(k + 1);
    }
    for (int i = 0; i < n; i++) {
        int t;
        read_int(&t);
        vector* arr = create_vector(t);
        read_vector(arr);
        if (t > k) {
            arr->size = k;
        }
        arrs[i] = arr;
    }
    print_int(rec(0, n, k, dps, arrs));
    printf("\n");
    for (int i = 0; i <= n; i++) {
        destroy_vector(dps[i]);
    }
    for (int i = 0; i < n; i++) {
        destroy_vector(arrs[i]);
    }
    free(dps);
    free(arrs);
}

int main() {
    solve();
    return 0;
}
