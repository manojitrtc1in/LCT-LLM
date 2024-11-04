#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX_K 1000
#define MAX_N 100

int N, K;
int64_t A[MAX_N][MAX_K];
int64_t A_sum[MAX_N];
int64_t best;

void add_item(int64_t *knapsack, int size, int64_t sum) {
    for (int k = K - size; k >= 0; k--) {
        if (knapsack[k + size] < knapsack[k] + sum) {
            knapsack[k + size] = knapsack[k] + sum;
        }
    }
}

void recurse(int start, int end, int64_t *knapsack) {
    if (start >= end)
        return;

    if (end - start == 1) {
        int64_t sum = 0;
        if (best < knapsack[K]) {
            best = knapsack[K];
        }

        for (int prefix = 1; prefix <= A[start][0]; prefix++) {
            sum += A[start][prefix];
            if (best < sum + knapsack[K - prefix]) {
                best = sum + knapsack[K - prefix];
            }
        }

        return;
    }

    int mid = (start + end) / 2;
    int64_t state[MAX_K + 1];
    memcpy(state, knapsack, sizeof(int64_t) * (K + 1));

    for (int i = start; i < mid; i++) {
        add_item(state, A[i][0], A_sum[i]);
    }

    recurse(mid, end, state);
    memcpy(state, knapsack, sizeof(int64_t) * (K + 1));

    for (int i = mid; i < end; i++) {
        add_item(state, A[i][0], A_sum[i]);
    }

    recurse(start, mid, state);
}

void solve() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        A[i][0] = t;

        for (int j = 1; j <= t; j++) {
            scanf("%lld", &A[i][j]);
        }

        if (t > K) {
            A[i][0] = K;
        }

        A_sum[i] = 0;
        for (int j = 1; j <= A[i][0]; j++) {
            A_sum[i] += A[i][j];
        }
    }

    best = 0;
    int64_t knapsack[MAX_K + 1] = {0};
    recurse(0, N, knapsack);
    printf("%lld\n", best);
}

int main() {
    solve();
    return 0;
}
