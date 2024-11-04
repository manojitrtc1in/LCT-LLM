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
    vector* v = (vector*)malloc(sizeof(vector));
    v->size = size;
    v->arr = (int*)malloc(sizeof(int) * size);
    return v;
}

void destroy_vector(vector* v) {
    free(v->arr);
    free(v);
}

void read_int(int* x) {
    scanf("%d", x);
}

void read_vector(vector* v) {
    for (int i = 0; i < v->size; i++) {
        read_int(&v->arr[i]);
    }
}

void print_int(int x) {
    printf("%d", x);
}

void print_vector(vector* v) {
    for (int i = 0; i < v->size; i++) {
        print_int(v->arr[i]);
        if (i < v->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

ll sum(vector* v) {
    ll s = 0;
    for (int i = 0; i < v->size; i++) {
        s += v->arr[i];
    }
    return s;
}

void copy_vector(vector* dest, vector* src) {
    memcpy(dest->arr, src->arr, sizeof(int) * src->size);
}

void add_to_knap(int i, int dpi, int k, vector** dps, vector** arrs, ll* sums) {
    ll v = sums[i];
    int k1 = arrs[i]->size;
    for (int j = k; j >= k1; j--) {
        dps[dpi]->arr[j] = max(dps[dpi]->arr[j], dps[dpi]->arr[j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, int k, vector** dps, vector** arrs, ll* sums) {
    ll ans = 0;
    vector* carr = arrs[l];
    vector* dp = dps[dpi];
    if (l + 1 == r) {
        ans = dp->arr[k];
        ll sum = 0;
        for (int i = 0; i < min(k, carr->size); i++) {
            sum += carr->arr[i];
            ans = max(ans, dp->arr[k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copy_vector(dps[dpi + 1], dp);
        for (int i = l; i < m; i++) {
            add_to_knap(i, dpi + 1, k, dps, arrs, sums);
        }
        ans = rec(m, r, dpi + 1, k, dps, arrs, sums);
        copy_vector(dps[dpi + 1], dp);
        for (int i = m; i < r; i++) {
            add_to_knap(i, dpi + 1, k, dps, arrs, sums);
        }
        ans = max(ans, rec(l, m, dpi + 1, k, dps, arrs, sums));
    }
    return ans;
}

void solve() {
    int n, k;
    read_int(&n);
    read_int(&k);
    vector** dps = (vector**)malloc(sizeof(vector*) * 13);
    for (int i = 0; i < 13; i++) {
        dps[i] = create_vector(k + 1);
    }
    vector* sums = create_vector(n);
    vector** arrs = (vector**)malloc(sizeof(vector*) * n);
    for (int i = 0; i < n; i++) {
        arrs[i] = create_vector(k);
        read_vector(arrs[i]);
        if (arrs[i]->size > k) {
            arrs[i]->size = k;
        }
        sums->arr[i] = sum(arrs[i]);
    }
    print_int(rec(0, n, 0, k, dps, arrs, sums->arr));
    printf("\n");
    for (int i = 0; i < n; i++) {
        destroy_vector(arrs[i]);
    }
    destroy_vector(sums);
    for (int i = 0; i < 13; i++) {
        destroy_vector(dps[i]);
    }
    free(dps);
    free(arrs);
}

int main() {
    solve();
    return 0;
}
