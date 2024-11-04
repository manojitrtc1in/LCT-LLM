#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int64_t *arr;
    int size;
} vector;

vector* create_vector(int size) {
    vector *v = (vector*)malloc(sizeof(vector));
    v->arr = (int64_t*)malloc(size * sizeof(int64_t));
    v->size = size;
    return v;
}

void destroy_vector(vector *v) {
    free(v->arr);
    free(v);
}

void add_item(vector *knapsack, int size, int64_t sum) {
    for (int k = knapsack->size - size; k >= 0; k--) {
        knapsack->arr[k + size] = knapsack->arr[k + size] > knapsack->arr[k] + sum ? knapsack->arr[k + size] : knapsack->arr[k] + sum;
    }
}

void recurse(int start, int end, vector *knapsack, vector *A, vector *A_sum, int K, int64_t *best) {
    if (start >= end) {
        return;
    }

    if (end - start == 1) {
        int64_t sum = 0;
        *best = *best > knapsack->arr[K] ? *best : knapsack->arr[K];

        for (int prefix = 1; prefix <= A->arr[start]; prefix++) {
            sum += A->arr[prefix - 1];
            *best = *best > sum + knapsack->arr[K - prefix] ? *best : sum + knapsack->arr[K - prefix];
        }

        return;
    }

    int mid = (start + end) / 2;
    vector *state = create_vector(K + 1);
    for (int i = start; i < mid; i++) {
        add_item(state, A->arr[i], A_sum->arr[i]);
    }
    recurse(mid, end, state, A, A_sum, K, best);
    destroy_vector(state);

    state = create_vector(K + 1);
    for (int i = mid; i < end; i++) {
        add_item(state, A->arr[i], A_sum->arr[i]);
    }
    recurse(start, mid, state, A, A_sum, K, best);
    destroy_vector(state);
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    vector *A = create_vector(N);
    vector *A_sum = create_vector(N);

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);

        A->arr[i] = t;

        for (int j = 0; j < t; j++) {
            int64_t a;
            scanf("%lld", &a);
            A_sum->arr[i] += a;
        }

        if (t > K) {
            A->arr[i] = K;
        }
    }

    int64_t best = 0;
    vector *knapsack = create_vector(K + 1);
    recurse(0, N, knapsack, A, A_sum, K, &best);
    printf("%lld\n", best);

    destroy_vector(A);
    destroy_vector(A_sum);
    destroy_vector(knapsack);
}

int main() {
    solve();
    return 0;
}
