#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_N 2000
#define MAX_K 2000

int64_t max(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

void add_item(int64_t knapsack[], int size, int64_t sum, int K) {
    for (int k = K - size; k >= 0; k--) {
        knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum);
    }
}

void recurse(int start, int end, int64_t knapsack[], int N, int K, int64_t A[][MAX_K], int64_t A_sum[]) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        int64_t sum = 0;
        int64_t best = knapsack[K];

        for (int prefix = 1; prefix <= A[start][0]; prefix++) {
            sum += A[start][prefix];
            best = max(best, sum + knapsack[K - prefix]);
        }

        knapsack[K] = best;
        return;
    }

    int mid = (start + end) / 2;
    int64_t state[MAX_K];

    for (int i = start; i < mid; i++) {
        add_item(state, A[i][0], A_sum[i], K);
    }

    recurse(mid, end, state, N, K, A, A_sum);
    for (int i = mid; i < end; i++) {
        add_item(knapsack, A[i][0], A_sum[i], K);
    }

    recurse(start, mid, knapsack, N, K, A, A_sum);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    int64_t A[N][MAX_K];
    int64_t A_sum[N];

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);

        for (int j = 0; j < t; j++) {
            scanf("%lld", &A[i][j]);
        }

        if (t > K) {
            t = K;
        }

        A[i][0] = t;
        A_sum[i] = 0;

        for (int j = 0; j < t; j++) {
            A_sum[i] += A[i][j];
        }
    }

    int64_t knapsack[MAX_K] = {0};
    recurse(0, N, knapsack, N, K, A, A_sum);

    printf("%lld\n", knapsack[K]);
}

int main() {
    solve();
    return 0;
}
