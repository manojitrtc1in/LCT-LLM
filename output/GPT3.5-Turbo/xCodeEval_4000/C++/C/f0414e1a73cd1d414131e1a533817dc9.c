#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_N 200000
#define MAX_K 200000

int64_t A[MAX_N][MAX_K];
int64_t A_sum[MAX_N];
int64_t knapsack[MAX_K + 1];
int64_t best;

void add_item(int64_t knapsack[], int size, int64_t sum) {
    for (int k = MAX_K - size; k >= 0; k--) {
        knapsack[k + size] = knapsack[k + size] > knapsack[k] + sum ? knapsack[k + size] : knapsack[k] + sum;
    }
}

void recurse(int start, int end, const int64_t knapsack[]) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        int64_t sum = 0;
        best = best > knapsack[MAX_K] ? best : knapsack[MAX_K];

        for (int prefix = 1; prefix <= MAX_K; prefix++) {
            sum += A[start][prefix - 1];
            best = best > sum + knapsack[MAX_K - prefix] ? best : sum + knapsack[MAX_K - prefix];
        }

        return;
    }

    int mid = (start + end) / 2;
    int64_t state[MAX_K + 1];

    for (int i = start; i < mid; i++) {
        add_item(state, MAX_K, A_sum[i]);
    }

    recurse(mid, end, state);
    for (int i = mid; i < end; i++) {
        add_item(state, MAX_K, A_sum[i]);
    }

    recurse(start, mid, state);
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

    best = 0;
    for (int i = 0; i <= K; i++) {
        knapsack[i] = 0;
    }

    recurse(0, N, knapsack);

    printf("%lld\n", best);
}

int main() {
    solve();
    return 0;
}
