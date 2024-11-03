#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1005
#define MAX_K 1005

int N, K;
int A[MAX_N][MAX_K];
int A_sum[MAX_N];
int64_t best;

void add_item(int64_t knapsack[], int size, int64_t sum) {
    for (int k = K - size; k >= 0; k--) {
        if (knapsack[k + size] < knapsack[k] + sum) {
            knapsack[k + size] = knapsack[k] + sum;
        }
    }
}

void recurse(int start, int end, int64_t knapsack[]) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        int64_t sum = 0;
        if (knapsack[K] < 0) {
            knapsack[K] = 0;
        }
        best = (best > knapsack[K]) ? best : knapsack[K];

        for (int prefix = 1; prefix <= A[start][0]; prefix++) {
            sum += A[start][prefix];
            if (knapsack[K - prefix] + sum > knapsack[K]) {
                knapsack[K] = knapsack[K - prefix] + sum;
            }
        }

        return;
    }

    int mid = (start + end) / 2;
    int64_t state[MAX_K];
    for (int i = 0; i <= K; i++) {
        state[i] = knapsack[i];
    }

    for (int i = start; i < mid; i++) {
        add_item(state, A[i][0], A_sum[i]);
    }

    recurse(mid, end, state);
    for (int i = mid; i < end; i++) {
        add_item(state, A[i][0], A_sum[i]);
    }

    recurse(start, mid, state);
}

void solve() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i][0]);
        for (int j = 1; j <= A[i][0]; j++) {
            scanf("%d", &A[i][j]);
        }

        if (A[i][0] > K) {
            A[i][0] = K;
        }

        A_sum[i] = 0;
        for (int j = 1; j <= A[i][0]; j++) {
            A_sum[i] += A[i][j];
        }
    }

    best = 0;
    int64_t knapsack[MAX_K] = {0};
    recurse(0, N, knapsack);
    printf("%lld\n", best);
}

int main() {
    solve();
    return 0;
}
