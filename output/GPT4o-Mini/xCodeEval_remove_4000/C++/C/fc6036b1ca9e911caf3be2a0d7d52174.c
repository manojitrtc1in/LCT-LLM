#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100
#define MAX_K 1000

typedef long long int64;

typedef struct {
    int size;
    int64 *data;
} Vector;

void vector_init(Vector *v, int size) {
    v->size = size;
    v->data = (int64 *)malloc(size * sizeof(int64));
    memset(v->data, 0, size * sizeof(int64));
}

void vector_free(Vector *v) {
    free(v->data);
}

void vector_add(Vector *v, int index, int64 value) {
    if (index < v->size) {
        v->data[index] = value;
    }
}

int64 vector_get(Vector *v, int index) {
    return (index < v->size) ? v->data[index] : 0;
}

int64 vector_sum(Vector *v) {
    int64 sum = 0;
    for (int i = 0; i < v->size; i++) {
        sum += v->data[i];
    }
    return sum;
}

void add_item(Vector *knapsack, int size, int64 sum, int K) {
    for (int k = K - size; k >= 0; k--) {
        int64 current = vector_get(knapsack, k);
        vector_add(knapsack, k + size, current + sum);
    }
}

void recurse(int start, int end, Vector *knapsack, Vector *A, int64 *A_sum, int K, int64 *best) {
    if (start >= end) return;

    if (end - start == 1) {
        int64 sum = 0;
        *best = (*best > vector_get(knapsack, K)) ? *best : vector_get(knapsack, K);

        for (int prefix = 1; prefix <= A[start].size; prefix++) {
            sum += A[start].data[prefix - 1];
            *best = (*best > sum + vector_get(knapsack, K - prefix)) ? *best : (sum + vector_get(knapsack, K - prefix));
        }
        return;
    }

    int mid = (start + end) / 2;
    Vector state;
    vector_init(&state, K + 1);
    memcpy(state.data, knapsack->data, (K + 1) * sizeof(int64));

    for (int i = start; i < mid; i++) {
        add_item(&state, A[i].size, A_sum[i], K);
    }

    recurse(mid, end, &state, A, A_sum, K, best);
    memcpy(state.data, knapsack->data, (K + 1) * sizeof(int64));

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
    int64 A_sum[MAX_N];
    
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

        A_sum[i] = vector_sum(&A[i]);
    }

    int64 best = 0;
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
