#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define RADIX 10
#define MOD 998244353
#define MAX_N 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list) {
    list->size = 0;
    list->capacity = 10;
    list->data = (int *)malloc(list->capacity * sizeof(int));
}

void addToArrayList(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
}

long long pow_mod(int a, int k, long long p) {
    long long ans = 1;
    long long curr = a;
    while (k > 0) {
        if (k & 1) {
            ans = (ans * curr) % p;
        }
        k >>= 1;
        curr = (curr * curr) % p;
    }
    return ans;
}

long long inverse(int a, long long p) {
    return pow_mod(a, p - 2, p);
}

void readInt(int *x) {
    scanf("%d", x);
}

void readIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

long long solve2(int *u, int *v, int n, int m) {
    long long dp[1 << RADIX] = {0};
    for (int j = 0; j < RADIX; j++) {
        dp[1 << j] = 1;
    }

    int cmp[RADIX][RADIX] = {0};
    for (int i = 0; i < m; i++) {
        int small = fmin(u[i], v[i]);
        int larger = fmax(u[i], v[i]);
        cmp[small][larger] = -1;
        cmp[larger][small] = 1;
    }

    bool isValid[1 << RADIX][RADIX] = {false};
    int map[1 << RADIX][RADIX] = {0};

    for (int mask = 0; mask < (1 << RADIX); mask++) {
        for (int j = 0; j < RADIX; j++) {
            bool ok = true;
            int next = 1 << j;
            for (int k = 0; k < RADIX; k++) {
                if ((1 << k & mask) == 0)
                    continue;

                if (cmp[j][k] == -1) {
                    next |= 1 << k;
                } else if (cmp[j][k] == 1) {
                    ok = false;
                }
            }
            isValid[mask][j] = ok;
            map[mask][j] = next;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        long long next[1 << RADIX] = {0};
        for (int mask = 0; mask < (1 << RADIX); mask++) {
            for (int j = 0; j < RADIX; j++) {
                if (!isValid[mask][j])
                    continue;
                int mask2 = map[mask][j];
                long long val = next[mask2] + dp[mask];
                next[mask2] = (val < MOD) ? val : val - MOD;
            }
        }
        memcpy(dp, next, sizeof(dp));
    }

    long long sum = 0;
    for (int mask = 0; mask < (1 << RADIX); mask++) {
        sum = (sum + dp[mask]) % MOD;
    }

    return sum;
}

int main() {
    int t = 1; // For simplicity, we assume t = 1
    int n, m;
    readInt(&n);
    readInt(&m);

    int u[MAX_N], v[MAX_N];
    readIntArray(u, m);
    readIntArray(v, m);

    long long ans = solve2(u, v, n, m);
    printf("%lld\n", ans);

    return 0;
}
