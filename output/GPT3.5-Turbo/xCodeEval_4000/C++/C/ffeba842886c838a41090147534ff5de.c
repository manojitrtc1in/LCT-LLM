#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef long long int ll;

typedef struct {
    int size;
    int* data;
} vector;

vector* create_vector(int size) {
    vector* vec = (vector*)malloc(sizeof(vector));
    vec->size = size;
    vec->data = (int*)malloc(size * sizeof(int));
    return vec;
}

void destroy_vector(vector* vec) {
    free(vec->data);
    free(vec);
}

void add_item(vector* knapsack, int size, ll sum) {
    for (int k = knapsack->size - size; k >= 0; k--) {
        knapsack->data[k + size] = knapsack->data[k + size] > knapsack->data[k] + sum ? knapsack->data[k + size] : knapsack->data[k] + sum;
    }
}

void recurse(int start, int end, vector* knapsack, vector* A, ll* A_sum, int K, ll* best) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        ll sum = 0;
        *best = *best > knapsack->data[K] ? *best : knapsack->data[K];

        for (int prefix = 1; prefix <= A->data[start]; prefix++) {
            sum += A->data[prefix - 1];
            *best = *best > sum + knapsack->data[K - prefix] ? *best : sum + knapsack->data[K - prefix];
        }

        return;
    }

    int mid = (start + end) / 2;
    vector* state = create_vector(K + 1);
    memcpy(state->data, knapsack->data, (K + 1) * sizeof(int));

    for (int i = start; i < mid; i++) {
        add_item(state, A->data[i], A_sum[i]);
    }

    recurse(mid, end, state, A, A_sum, K, best);
    destroy_vector(state);

    state = create_vector(K + 1);
    memcpy(state->data, knapsack->data, (K + 1) * sizeof(int));

    for (int i = mid; i < end; i++) {
        add_item(state, A->data[i], A_sum[i]);
    }

    recurse(start, mid, state, A, A_sum, K, best);
    destroy_vector(state);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    vector* A = create_vector(N);
    ll* A_sum = (ll*)malloc(N * sizeof(ll));

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        A->data[i] = t;

        for (int j = 0; j < t; j++) {
            int a;
            scanf("%d", &a);
            A_sum[i] += a;
        }

        if (t > K) {
            A->data[i] = K;
        }
    }

    ll best = 0;
    vector* knapsack = create_vector(K + 1);
    recurse(0, N, knapsack, A, A_sum, K, &best);

    printf("%lld\n", best);

    destroy_vector(A);
    free(A_sum);
    destroy_vector(knapsack);
}

int main() {
    solve();
    return 0;
}
