#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX_N 100
#define MAX_K 100

typedef struct {
    int64_t *data;
    size_t size;
} Vector;

void vector_init(Vector *v, size_t size) {
    v->data = (int64_t *)malloc(size * sizeof(int64_t));
    v->size = size;
    memset(v->data, 0, size * sizeof(int64_t));
}

void vector_free(Vector *v) {
    free(v->data);
}

void add_item(Vector *knapsack, int size, int64_t sum, int K) {
    for (int k = K - size; k >= 0; k--) {
        if (knapsack->data[k + size] < knapsack->data[k] + sum) {
            knapsack->data[k + size] = knapsack->data[k] + sum;
        }
    }
}

void recurse(int start, int end, Vector *knapsack, Vector *A, int64_t *A_sum, int K, int64_t *best) {
    if (start >= end) return;

    if (end - start == 1) {
        int64_t sum = 0;
        if (*best < knapsack->data[K]) {
            *best = knapsack->data[K];
        }

        for (int prefix = 1; prefix <= A[start].size; prefix++) {
            sum += A[start].data[prefix - 1];
            if (*best < sum + knapsack->data[K - prefix]) {
                *best = sum + knapsack->data[K - prefix];
            }
        }
        return;
    }

    int mid = (start + end) / 2;
    Vector state;
    vector_init(&state, K + 1);
    memcpy(state.data, knapsack->data, (K + 1) * sizeof(int64_t));

    for (int i = start; i < mid; i++) {
        add_item(&state, A[i].size, A_sum[i], K);
    }

    recurse(mid, end, &state, A, A_sum, K, best);
    memcpy(state.data, knapsack->data, (K + 1) * sizeof(int64_t));

    for (int i = mid; i < end; i++) {
        add_item(&state, A[i].size, A_sum[i], K);
    }

    recurse(start, mid, &state, A, A_sum, K, best);
    vector_free(&state);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);
    Vector A[MAX_N];
    int64_t A_sum[MAX_N];

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        vector_init(&A[i], t);
        for (int j = 0; j < t; j++) {
            scanf("%lld", &A[i].data[j]);
        }
        if (t > K) {
            A[i].size = K;
        }
        A_sum[i] = 0;
        for (int j = 0; j < A[i].size; j++) {
            A_sum[i] += A[i].data[j];
        }
    }

    int64_t best = 0;
    Vector knapsack;
    vector_init(&knapsack, K + 1);
    recurse(0, N, &knapsack, A, A_sum, K, &best);
    printf("%lld\n", best);

    for (int i = 0; i < N; i++) {
        vector_free(&A[i]);
    }
    vector_free(&knapsack);
}

int main() {
    solve();
    return 0;
}
