#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef struct {
    size_t first;
    size_t second;
} Pair;

Pair make_pair(size_t first, size_t second) {
    Pair pair;
    pair.first = first;
    pair.second = second;
    return pair;
}

typedef struct {
    size_t* data;
    size_t size;
    size_t capacity;
} Vector;

Vector create_vector() {
    Vector vector;
    vector.data = NULL;
    vector.size = 0;
    vector.capacity = 0;
    return vector;
}

void push_back(Vector* vector, size_t value) {
    if (vector->size == vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        size_t* new_data = (size_t*)realloc(vector->data, new_capacity * sizeof(size_t));
        if (new_data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
    vector->data[vector->size++] = value;
}

void destroy_vector(Vector* vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

typedef struct {
    size_t* data;
    size_t front;
    size_t rear;
    size_t size;
    size_t capacity;
} Queue;

Queue create_queue(size_t capacity) {
    Queue queue;
    queue.data = (size_t*)malloc(capacity * sizeof(size_t));
    if (queue.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue.front = 0;
    queue.rear = 0;
    queue.size = 0;
    queue.capacity = capacity;
    return queue;
}

void enqueue(Queue* queue, size_t value) {
    if (queue->size == queue->capacity) {
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

size_t dequeue(Queue* queue) {
    if (queue->size == 0) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    size_t value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

bool is_empty(Queue* queue) {
    return queue->size == 0;
}

void destroy_queue(Queue* queue) {
    free(queue->data);
    queue->data = NULL;
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = 0;
}

size_t min(size_t a, size_t b) {
    return a < b ? a : b;
}

size_t max(size_t a, size_t b) {
    return a > b ? a : b;
}

size_t abs_diff(size_t a, size_t b) {
    return a < b ? b - a : a - b;
}

size_t gcd(size_t a, size_t b) {
    return b == 0 ? a : gcd(b, a % b);
}

typedef struct {
    size_t* parent;
    size_t* rank;
    size_t size;
} UnionFind;

UnionFind create_union_find(size_t size) {
    UnionFind union_find;
    union_find.parent = (size_t*)malloc(size * sizeof(size_t));
    if (union_find.parent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    union_find.rank = (size_t*)malloc(size * sizeof(size_t));
    if (union_find.rank == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    union_find.size = size;
    for (size_t i = 0; i < size; i++) {
        union_find.parent[i] = i;
        union_find.rank[i] = 0;
    }
    return union_find;
}

size_t find(UnionFind* union_find, size_t s) {
    if (union_find->parent[s] != s) {
        union_find->parent[s] = find(union_find, union_find->parent[s]);
    }
    return union_find->parent[s];
}

void lazy_union(UnionFind* union_find, size_t i, size_t j) {
    i = find(union_find, i);
    j = find(union_find, j);
    if (i != j) {
        if (union_find->rank[i] < union_find->rank[j]) {
            union_find->parent[i] = j;
        } else {
            union_find->parent[j] = i;
            if (union_find->rank[i] == union_find->rank[j]) {
                union_find->rank[i]++;
            }
        }
    }
}

void destroy_union_find(UnionFind* union_find) {
    free(union_find->parent);
    union_find->parent = NULL;
    free(union_find->rank);
    union_find->rank = NULL;
    union_find->size = 0;
}

typedef struct {
    size_t** data;
    size_t size;
    size_t capacity;
} Matrix;

Matrix create_matrix(size_t size) {
    Matrix matrix;
    matrix.data = (size_t**)malloc(size * sizeof(size_t*));
    if (matrix.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        matrix.data[i] = (size_t*)malloc(size * sizeof(size_t));
        if (matrix.data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        memset(matrix.data[i], 0, size * sizeof(size_t));
    }
    matrix.size = size;
    matrix.capacity = size;
    return matrix;
}

void set_value(Matrix* matrix, size_t row, size_t col, size_t value) {
    matrix->data[row][col] = value;
}

size_t get_value(Matrix* matrix, size_t row, size_t col) {
    return matrix->data[row][col];
}

void destroy_matrix(Matrix* matrix) {
    for (size_t i = 0; i < matrix->size; i++) {
        free(matrix->data[i]);
        matrix->data[i] = NULL;
    }
    free(matrix->data);
    matrix->data = NULL;
    matrix->size = 0;
    matrix->capacity = 0;
}

void all_pairs_tree_shortest_path(Matrix* matrix) {
    size_t n = matrix->size;
    size_t* depth = (size_t*)malloc(n * sizeof(size_t));
    if (depth == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t* parent = (size_t*)malloc(n * sizeof(size_t));
    if (parent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++) {
        depth[i] = INT_MAX;
        parent[i] = 0;
    }
    depth[0] = 0;
    parent[0] = 0;
    Queue queue = create_queue(n);
    enqueue(&queue, 0);
    while (!is_empty(&queue)) {
        size_t u = dequeue(&queue);
        for (size_t v = 0; v < n; v++) {
            if (get_value(matrix, u, v) && depth[u] + 1 < depth[v]) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                enqueue(&queue, v);
            }
        }
    }
    free(depth);
    free(parent);
    destroy_queue(&queue);
}

size_t all_pairs_tree_shortest_path_distance(Matrix* matrix, size_t u, size_t v) {
    size_t n = matrix->size;
    size_t* depth = (size_t*)malloc(n * sizeof(size_t));
    if (depth == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t* parent = (size_t*)malloc(n * sizeof(size_t));
    if (parent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++) {
        depth[i] = INT_MAX;
        parent[i] = 0;
    }
    depth[0] = 0;
    parent[0] = 0;
    Queue queue = create_queue(n);
    enqueue(&queue, 0);
    while (!is_empty(&queue)) {
        size_t u = dequeue(&queue);
        for (size_t v = 0; v < n; v++) {
            if (get_value(matrix, u, v) && depth[u] + 1 < depth[v]) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                enqueue(&queue, v);
            }
        }
    }
    size_t distance = 0;
    while (u != v) {
        distance++;
        u = parent[u];
    }
    free(depth);
    free(parent);
    destroy_queue(&queue);
    return distance;
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

size_t all_pairs_tree_shortest_path_distance(Matrix* matrix, size_t u, size_t v) {
    return get_value(matrix, u, v);
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

void all_pairs_tree_shortest_path(Matrix* matrix) {
    size_t n = matrix->size;
    size_t* depth = (size_t*)malloc(n * sizeof(size_t));
    if (depth == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t* parent = (size_t*)malloc(n * sizeof(size_t));
    if (parent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++) {
        depth[i] = INT_MAX;
        parent[i] = 0;
    }
    depth[0] = 0;
    parent[0] = 0;
    Queue queue = create_queue(n);
    enqueue(&queue, 0);
    while (!is_empty(&queue)) {
        size_t u = dequeue(&queue);
        for (size_t v = 0; v < n; v++) {
            if (get_value(matrix, u, v) && depth[u] + 1 < depth[v]) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                enqueue(&queue, v);
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            set_value(matrix, i, j, depth[j] - depth[i]);
        }
    }
    free(depth);
    free(parent);
    destroy_queue(&queue);
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

size_t all_pairs_tree_shortest_path_distance(Matrix* matrix, size_t u, size_t v) {
    return get_value(matrix, u, v);
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

void all_pairs_tree_shortest_path(Matrix* matrix) {
    size_t n = matrix->size;
    size_t* depth = (size_t*)malloc(n * sizeof(size_t));
    if (depth == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t* parent = (size_t*)malloc(n * sizeof(size_t));
    if (parent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++) {
        depth[i] = INT_MAX;
        parent[i] = 0;
    }
    depth[0] = 0;
    parent[0] = 0;
    Queue queue = create_queue(n);
    enqueue(&queue, 0);
    while (!is_empty(&queue)) {
        size_t u = dequeue(&queue);
        for (size_t v = 0; v < n; v++) {
            if (get_value(matrix, u, v) && depth[u] + 1 < depth[v]) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                enqueue(&queue, v);
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            set_value(matrix, i, j, depth[j] - depth[i]);
        }
    }
    free(depth);
    free(parent);
    destroy_queue(&queue);
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

size_t all_pairs_tree_shortest_path_distance(Matrix* matrix, size_t u, size_t v) {
    return get_value(matrix, u, v);
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

void all_pairs_tree_shortest_path(Matrix* matrix) {
    size_t n = matrix->size;
    size_t* depth = (size_t*)malloc(n * sizeof(size_t));
    if (depth == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t* parent = (size_t*)malloc(n * sizeof(size_t));
    if (parent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++) {
        depth[i] = INT_MAX;
        parent[i] = 0;
    }
    depth[0] = 0;
    parent[0] = 0;
    Queue queue = create_queue(n);
    enqueue(&queue, 0);
    while (!is_empty(&queue)) {
        size_t u = dequeue(&queue);
        for (size_t v = 0; v < n; v++) {
            if (get_value(matrix, u, v) && depth[u] + 1 < depth[v]) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                enqueue(&queue, v);
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            set_value(matrix, i, j, depth[j] - depth[i]);
        }
    }
    free(depth);
    free(parent);
    destroy_queue(&queue);
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

size_t all_pairs_tree_shortest_path_distance(Matrix* matrix, size_t u, size_t v) {
    return get_value(matrix, u, v);
}

void destroy_all_pairs_tree_shortest_path(Matrix* matrix) {
    destroy_matrix(matrix);
}

void all_pairs_tree_shortest_path(Matrix* matrix) {
    size_t n = matrix->size;
    size_t* depth = (size_t*)malloc(n * sizeof(size_t));
    if (depth == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
