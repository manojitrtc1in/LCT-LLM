#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int64_t* data;
    int size;
} Vector;

Vector* create_vector(int size) {
    Vector* vector = malloc(sizeof(Vector));
    vector->data = malloc(size * sizeof(int64_t));
    vector->size = size;
    return vector;
}

void destroy_vector(Vector* vector) {
    free(vector->data);
    free(vector);
}

void add_item(Vector* knapsack, int size, int64_t sum) {
    for (int k = knapsack->size - size; k >= 0; k--) {
        knapsack->data[k + size] = max(knapsack->data[k + size], knapsack->data[k] + sum);
    }
}

void recurse(int start, int end, Vector* knapsack, Vector** A, int64_t* A_sum, int K, int64_t* best) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        int64_t sum = 0;
        *best = max(*best, knapsack->data[K]);

        for (int prefix = 1; prefix <= A[start]->size; prefix++) {
            sum += A[start]->data[prefix - 1];
            *best = max(*best, sum + knapsack->data[K - prefix]);
        }

        return;
    }

    int mid = (start + end) / 2;
    Vector* state = create_vector(K + 1);
    for (int i = start; i < mid; i++) {
        add_item(state, A[i]->size, A_sum[i]);
    }
    recurse(mid, end, state, A, A_sum, K, best);
    destroy_vector(state);

    state = create_vector(K + 1);
    for (int i = mid; i < end; i++) {
        add_item(state, A[i]->size, A_sum[i]);
    }
    recurse(start, mid, state, A, A_sum, K, best);
    destroy_vector(state);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    Vector** A = malloc(N * sizeof(Vector*));
    int64_t* A_sum = malloc(N * sizeof(int64_t));

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        A[i] = create_vector(t);

        for (int j = 0; j < t; j++) {
            scanf("%lld", &A[i]->data[j]);
        }

        if (t > K) {
            A[i]->size = K;
        }

        for (int j = 0; j < A[i]->size; j++) {
            A_sum[i] += A[i]->data[j];
        }
    }

    int64_t best = 0;
    Vector* knapsack = create_vector(K + 1);
    recurse(0, N, knapsack, A, A_sum, K, &best);
    printf("%lld\n", best);

    for (int i = 0; i < N; i++) {
        destroy_vector(A[i]);
    }
    free(A);
    free(A_sum);
    destroy_vector(knapsack);
}

int main() {
    solve();
    return 0;
}
