#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_N 1000
#define MAX_K 1000

int64_t max(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

void add_item(int64_t *knapsack, int size, int64_t sum, int K) {
    for (int k = K - size; k >= 0; k--) {
        knapsack[k + size] = max(knapsack[k + size], knapsack[k] + sum);
    }
}

void recurse(int start, int end, int N, int K, int64_t **A, int64_t *A_sum, int64_t *knapsack, int64_t *best) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        int64_t sum = 0;
        *best = max(*best, knapsack[K]);

        for (int prefix = 1; prefix <= A[start][0]; prefix++) {
            sum += A[start][prefix];
            *best = max(*best, sum + knapsack[K - prefix]);
        }

        return;
    }

    int mid = (start + end) / 2;
    int64_t *state = malloc((K + 1) * sizeof(int64_t));
    memcpy(state, knapsack, (K + 1) * sizeof(int64_t));

    for (int i = start; i < mid; i++) {
        add_item(state, A[i][0], A_sum[i], K);
    }

    recurse(mid, end, N, K, A, A_sum, state, best);
    free(state);

    state = malloc((K + 1) * sizeof(int64_t));
    memcpy(state, knapsack, (K + 1) * sizeof(int64_t));

    for (int i = mid; i < end; i++) {
        add_item(state, A[i][0], A_sum[i], K);
    }

    recurse(start, mid, N, K, A, A_sum, state, best);
    free(state);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    int64_t **A = malloc(N * sizeof(int64_t *));
    int64_t *A_sum = malloc(N * sizeof(int64_t));

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        A[i] = malloc((t + 1) * sizeof(int64_t));
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

    int64_t *knapsack = calloc(K + 1, sizeof(int64_t));
    int64_t best = 0;

    recurse(0, N, N, K, A, A_sum, knapsack, &best);

    printf("%lld\n", best);

    free(knapsack);
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
    free(A_sum);
}

int main() {
    solve();
    return 0;
}
