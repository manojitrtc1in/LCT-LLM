#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
typedef struct {
    int size;
    int* arr;
} Array;

Array createArray(int size) {
    Array array;
    array.size = size;
    array.arr = (int*)malloc(size * sizeof(int));
    return array;
}

void destroyArray(Array* array) {
    free(array->arr);
}

void readInt(int* x) {
    scanf("%d", x);
}

void printInt(int x) {
    printf("%d", x);
}

void printNewLine() {
    printf("\n");
}

void copyArray(Array* dest, Array* src) {
    memcpy(dest->arr, src->arr, src->size * sizeof(int));
}

void addToKnapsack(int i, int dpi, int k, ll* dps, ll* sums, Array* arrs) {
    ll v = sums[i];
    int k1 = arrs[i].size;
    for (int j = k; j >= k1; j--) {
        dps[dpi * (k + 1) + j] = max(dps[dpi * (k + 1) + j], dps[dpi * (k + 1) + j - k1] + v);
    }
}

ll rec(int l, int r, int dpi, int k, ll* dps, ll* sums, Array* arrs) {
    ll ans = 0;
    if (l + 1 == r) {
        ans = max(ans, dps[dpi * (k + 1) + k]);
        ll sum = 0;
        for (int i = 0; i < min(k, arrs[l].size); i++) {
            sum += arrs[l].arr[i];
            ans = max(ans, dps[dpi * (k + 1) + k - i - 1] + sum);
        }
    } else {
        int m = (l + r) / 2;
        copyArray(&dps[(dpi + 1) * (k + 1)], &dps[dpi * (k + 1)]);
        for (int i = l; i < m; i++) {
            addToKnapsack(i, dpi + 1, k, dps, sums, arrs);
        }
        ans = max(ans, rec(m, r, dpi + 1, k, dps, sums, arrs));
        copyArray(&dps[(dpi + 1) * (k + 1)], &dps[dpi * (k + 1)]);
        for (int i = m; i < r; i++) {
            addToKnapsack(i, dpi + 1, k, dps, sums, arrs);
        }
        ans = max(ans, rec(l, m, dpi + 1, k, dps, sums, arrs));
    }
    return ans;
}

void solve() {
    int n, k;
    readInt(&n);
    readInt(&k);
    Array sums = createArray(n);
    Array* arrs = (Array*)malloc(n * sizeof(Array));
    for (int i = 0; i < n; i++) {
        int t;
        readInt(&t);
        arrs[i] = createArray(t);
        for (int j = 0; j < t; j++) {
            readInt(&arrs[i].arr[j]);
        }
        if (t > k) {
            arrs[i].size = k;
        }
        for (int j = k; j < t; j++) {
            sums.arr[i] += arrs[i].arr[j];
        }
    }
    ll* dps = (ll*)malloc(13 * (k + 1) * sizeof(ll));
    memset(dps, 0, 13 * (k + 1) * sizeof(ll));
    printInt(rec(0, n, 0, k, dps, sums.arr, arrs));
    destroyArray(&sums);
    for (int i = 0; i < n; i++) {
        destroyArray(&arrs[i]);
    }
    free(arrs);
    free(dps);
}

int main() {
    solve();
    return 0;
}
