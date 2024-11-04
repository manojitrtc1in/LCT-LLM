#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200005

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int vertex;
    int weight;
} edge;

typedef struct {
    int value;
    int index;
} pq_node;

typedef struct {
    pq_node* heap;
    int size;
    int capacity;
} priority_queue;

void init_priority_queue(priority_queue* pq, int capacity) {
    pq->heap = (pq_node*)malloc(sizeof(pq_node) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
}

void swap(pq_node* a, pq_node* b) {
    pq_node temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(priority_queue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heap[left].value < pq->heap[smallest].value) {
        smallest = left;
    }

    if (right < pq->size && pq->heap[right].value < pq->heap[smallest].value) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        min_heapify(pq, smallest);
    }
}

void insert(priority_queue* pq, int value, int index) {
    if (pq->size == pq->capacity) {
        return;
    }

    pq->heap[pq->size].value = value;
    pq->heap[pq->size].index = index;
    int i = pq->size;
    pq->size++;

    while (i > 0 && pq->heap[i].value < pq->heap[(i - 1) / 2].value) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pop(priority_queue* pq) {
    if (pq->size == 0) {
        return;
    }

    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    min_heapify(pq, 0);
}

int top(priority_queue* pq) {
    if (pq->size == 0) {
        return -1;
    }

    return pq->heap[0].value;
}

void solve(int ind, int n, int t, int* vis, int* adj[MAX_SIZE], priority_queue* pq, int c) {
    if (ind == n) {
        insert(pq, c, -1);
        if (pq->size > t) {
            pop(pq);
        }
        return;
    }

    solve(ind + 1, n, t, vis, adj, pq, c);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (adj[ind][i].vertex != -1 && vis[adj[ind][i].vertex] == 0) {
            vis[adj[ind][i].vertex] = 1;
            c += adj[ind][i].weight;
            if (pq->size < t || c < top(pq)) {
                solve(ind + 1, n, t, vis, adj, pq, c);
            }
            c -= adj[ind][i].weight;
            vis[adj[ind][i].vertex] = 0;
        }
    }
}

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);

    int* vis = (int*)calloc(MAX_SIZE, sizeof(int));
    int** adj = (int**)malloc(sizeof(int*) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        adj[i] = (int*)malloc(sizeof(int) * MAX_SIZE);
        for (int j = 0; j < MAX_SIZE; j++) {
            adj[i][j].vertex = -1;
            adj[i][j].weight = -1;
        }
    }

    while (m--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        x--, y--;
        int i = 0;
        while (adj[x][i].vertex != -1) {
            i++;
        }
        adj[x][i].vertex = y;
        adj[x][i].weight = w;
    }

    priority_queue pq;
    init_priority_queue(&pq, t);

    solve(0, n, t, vis, adj, &pq, 0);

    printf("%d\n", top(&pq));

    free(vis);
    for (int i = 0; i < MAX_SIZE; i++) {
        free(adj[i]);
    }
    free(adj);
    free(pq.heap);

    return 0;
}
