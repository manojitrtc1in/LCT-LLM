#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int ll;

void add_item(ll *knapsack, int size, ll sum, int K) {
    for (int k = K - size; k >= 0; k--)
        knapsack[k + size] = knapsack[k + size] > knapsack[k] + sum ? knapsack[k + size] : knapsack[k] + sum;
}

void recurse(int start, int end, ll *knapsack, int K, int N, int **A, ll *A_sum, ll *best) {
    if (start >= end)
        return;

    if (end - start == 1) {
        ll sum = 0;
        *best = *best > knapsack[K] ? *best : knapsack[K];

        for (int prefix = 1; prefix <= A[start][0]; prefix++) {
            sum += A[start][prefix];
            *best = *best > sum + knapsack[K - prefix] ? *best : sum + knapsack[K - prefix];
        }

        return;
    }

    int mid = (start + end) / 2;
    ll *state = (ll *)malloc((K + 1) * sizeof(ll));
    for (int i = 0; i <= K; i++)
        state[i] = knapsack[i];

    for (int i = start; i < mid; i++)
        add_item(state, A[i][0], A_sum[i], K);

    recurse(mid, end, state, K, N, A, A_sum, best);
    free(state);
    state = (ll *)malloc((K + 1) * sizeof(ll));
    for (int i = 0; i <= K; i++)
        state[i] = knapsack[i];

    for (int i = mid; i < end; i++)
        add_item(state, A[i][0], A_sum[i], K);

    recurse(start, mid, state, K, N, A, A_sum, best);
    free(state);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);
    int **A = (int **)malloc(N * sizeof(int *));
    ll *A_sum = (ll *)malloc(N * sizeof(ll));

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        A[i] = (int *)malloc((t + 1) * sizeof(int));
        A[i][0] = t;

        for (int j = 1; j <= t; j++)
            scanf("%d", &A[i][j]);

        if (t > K) {
            int *temp = (int *)realloc(A[i], (K + 1) * sizeof(int));
            if (temp != NULL)
                A[i] = temp;
            A[i][0] = K;
        }

        A_sum[i] = 0;
        for (int j = 1; j <= A[i][0]; j++)
            A_sum[i] += A[i][j];
    }

    ll best = 0;
    ll *knapsack = (ll *)malloc((K + 1) * sizeof(ll));
    for (int i = 0; i <= K; i++)
        knapsack[i] = 0;

    recurse(0, N, knapsack, K, N, A, A_sum, &best);
    printf("%lld\n", best);

    for (int i = 0; i < N; i++)
        free(A[i]);
    free(A);
    free(A_sum);
    free(knapsack);
}

int main() {
    solve();
    return 0;
}
