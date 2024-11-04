#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    list->data = malloc(list->capacity * sizeof(int));
}

void addToArrayList(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
}

long solve2(int *u, int *v, int n, int m) {
    long dp[1 << RADIX] = {0};
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

    int isValid[1 << RADIX][RADIX] = {0};
    int map[1 << RADIX][RADIX] = {0};

    for (int mask = 0; mask < (1 << RADIX); mask++) {
        for (int j = 0; j < RADIX; j++) {
            int ok = 1;
            int next = 1 << j;
            for (int k = 0; k < RADIX; k++) {
                if ((1 << k & mask) == 0) continue;
                if (cmp[j][k] == -1) {
                    next |= 1 << k;
                } else if (cmp[j][k] == 1) {
                    ok = 0;
                }
            }
            isValid[mask][j] = ok;
            map[mask][j] = next;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        long next[1 << RADIX] = {0};
        for (int mask = 0; mask < (1 << RADIX); mask++) {
            for (int j = 0; j < RADIX; j++) {
                if (!isValid[mask][j]) continue;
                int mask2 = map[mask][j];
                long val = next[mask2] + dp[mask];
                next[mask2] = val < MOD ? val : val - MOD;
            }
        }
        memcpy(dp, next, sizeof(dp));
    }

    long sum = 0;
    for (int mask = 0; mask < (1 << RADIX); mask++) {
        sum += dp[mask];
    }

    return sum % MOD;
}

int main() {
    int t = 1; // Change this if multiple test cases are needed
    int n, m;
    scanf("%d %d", &n, &m);
    
    int u[MAX_N], v[MAX_N];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    long ans = solve2(u, v, n, m);
    printf("%ld\n", ans);

    return 0;
}
