#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef long long int64_t;

void add_item(int64_t *knapsack, int size, int64_t sum, int K) {
    for (int k = K - size; k >= 0; k--)
        knapsack[k + size] = knapsack[k + size] > knapsack[k] + sum ? knapsack[k + size] : knapsack[k] + sum;
}

void recurse(int start, int end, int N, int K, int64_t **A, int64_t *A_sum, int64_t *best, int64_t *knapsack) {
    if (start >= end)
        return;

    if (end - start == 1) {
        int64_t sum = 0;
        *best = *best > knapsack[K] ? *best : knapsack[K];

        for (int prefix = 1; prefix <= A[start][0]; prefix++) {
            sum += A[start][prefix];
            *best = *best > sum + knapsack[K - prefix] ? *best : sum + knapsack[K - prefix];
        }

        return;
    }

    int mid = (start + end) / 2;
    int64_t *state = (int64_t *)malloc((K + 1) * sizeof(int64_t));
    for (int i = 0; i <= K; i++) {
        state[i] = knapsack[i];
    }

    for (int i = start; i < mid; i++)
        add_item(state, A[i][0], A_sum[i], K);

    recurse(mid, end, N, K, A, A_sum, best, state);
    free(state);
    state = (int64_t *)malloc((K + 1) * sizeof(int64_t));

    for (int i = 0; i <= K; i++) {
        state[i] = knapsack[i];
    }

    for (int i = mid; i < end; i++)
        add_item(state, A[i][0], A_sum[i], K);

    recurse(start, mid, N, K, A, A_sum, best, state);
    free(state);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);
    int64_t **A = (int64_t **)malloc(N * sizeof(int64_t *));
    int64_t *A_sum = (int64_t *)malloc(N * sizeof(int64_t));

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        A[i] = (int64_t *)malloc(t * sizeof(int64_t));

        for (int j = 0; j < t; j++) {
            scanf("%lld", &A[i][j]);
        }

        if (t > K) {
            A[i] = (int64_t *)realloc(A[i], K * sizeof(int64_t));
        }

        A_sum[i] = 0;

        for (int j = 0; j < t; j++) {
            A_sum[i] += A[i][j];
        }
    }

    int64_t best = 0;
    int64_t *knapsack = (int64_t *)malloc((K + 1) * sizeof(int64_t));

    for (int i = 0; i <= K; i++) {
        knapsack[i] = 0;
    }

    recurse(0, N, N, K, A, A_sum, &best, knapsack);
    printf("%lld\n", best);

    for (int i = 0; i < N; i++) {
        free(A[i]);
    }

    free(A);
    free(A_sum);
    free(knapsack);
}

int main() {
    solve();
    return 0;
}
