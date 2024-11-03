#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_N 100000
#define MAX_K 100

int64_t A[MAX_N][MAX_K];
int64_t A_sum[MAX_N];
int64_t knapsack[MAX_K + 1];

int64_t max(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

void add_item(int64_t knapsack[], int size, int64_t sum, int K) {
    for (int k = K - size; k >= 0; k--) {
        knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum);
    }
}

void recurse(int start, int end, int N, int K) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        int64_t sum = 0;
        int64_t best = knapsack[K];

        for (int prefix = 1; prefix <= K; prefix++) {
            sum += A[start][prefix - 1];
            best = max(best, sum + knapsack[K - prefix]);
        }

        knapsack[K] = best;

        return;
    }

    int mid = (start + end) / 2;
    int64_t state[MAX_K + 1];

    for (int i = 0; i <= K; i++) {
        state[i] = knapsack[i];
    }

    for (int i = start; i < mid; i++) {
        add_item(state, K, A_sum[i], K);
    }

    recurse(mid, end, N, K);
    for (int i = 0; i <= K; i++) {
        knapsack[i] = state[i];
    }

    for (int i = mid; i < end; i++) {
        add_item(knapsack, K, A_sum[i], K);
    }

    recurse(start, mid, N, K);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);

        for (int j = 0; j < t; j++) {
            scanf("%lld", &A[i][j]);
        }

        if (t > K) {
            t = K;
        }

        for (int j = t; j < K; j++) {
            A[i][j] = 0;
        }

        A_sum[i] = 0;
        for (int j = 0; j < K; j++) {
            A_sum[i] += A[i][j];
        }
    }

    for (int i = 0; i <= K; i++) {
        knapsack[i] = 0;
    }

    recurse(0, N, N, K);

    printf("%lld\n", knapsack[K]);
}

int main() {
    solve();
    return 0;
}