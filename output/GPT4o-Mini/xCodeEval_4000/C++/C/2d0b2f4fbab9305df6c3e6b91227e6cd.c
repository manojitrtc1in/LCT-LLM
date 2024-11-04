#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int first;
    int second;
    int third;
} tuple;

typedef struct {
    tuple *data;
    size_t size;
} vector_tuple;

typedef struct {
    size_t *data;
    size_t size;
} vector_size_t;

typedef struct {
    size_t *data;
    size_t size;
} Heap;

void init_vector_tuple(vector_tuple *v, size_t size) {
    v->data = (tuple *)malloc(size * sizeof(tuple));
    v->size = size;
}

void init_vector_size_t(vector_size_t *v, size_t size) {
    v->data = (size_t *)malloc(size * sizeof(size_t));
    v->size = size;
}

void init_heap(Heap *heap, size_t size) {
    heap->data = (size_t *)malloc(size * sizeof(size_t));
    heap->size = 0;
}

void push_heap(Heap *heap, size_t value) {
    heap->data[heap->size++] = value;
    // Implement heapify up if needed
}

size_t pop_heap(Heap *heap) {
    size_t value = heap->data[0];
    // Implement heapify down if needed
    heap->size--;
    return value;
}

int refill(int k, vector_tuple *left, vector_tuple *right) {
    int val = 0;

    // Implement the comparison function and heap logic
    // This is a simplified version, actual logic needs to be implemented

    while (k > 0 && heap.size > 0) {
        size_t i = pop_heap(&heap);

        if (left->data[i].first < right->data[i].second) {
            int w = fmin(k, left->data[i].third);
            k -= w;
            val += w * (right->data[i].second - left->data[i].first);
        }
    }
    return val;
}

int a176() {
    size_t n, m, k;
    scanf("%zu %zu %zu", &n, &m, &k);

    vector_tuple a[n];
    for (size_t i = 0; i < n; ++i) {
        char str[100]; // Assuming max length of string
        scanf("%s", str);
        init_vector_tuple(&a[i], m);
        for (size_t j = 0; j < m; ++j) {
            scanf("%d %d %d", &a[i].data[j].first, &a[i].data[j].second, &a[i].data[j].third);
        }
    }

    int val = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                val = fmax(val, refill(k, &a[i], &a[j]));
            }
        }
    }

    return val;
}

int main() {
    printf("%d\n", a176());
    return EXIT_SUCCESS;
}
