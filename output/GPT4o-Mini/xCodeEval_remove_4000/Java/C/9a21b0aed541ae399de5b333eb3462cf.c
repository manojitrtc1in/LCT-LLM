#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int *base;
    int *used;
    int quantity;
    int *ancestor;
} Graph;

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    int dividend;
    int divider;
} Division;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void readInt(int *result) {
    scanf("%d", result);
}

void readArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void writeInt(int number) {
    printf("%d\n", number);
}

void clearCountValue(int *countValue, int size) {
    for (int i = 0; i < size; i++) {
        countValue[i] = 0;
    }
}

int main() {
    int i1;
    readInt(&i1);
    for (int i2 = 0; i2 < i1; i2++) {
        int quantity[3];
        readArray(quantity, 3);
        int *base = malloc(quantity[0] * sizeof(int));
        int *countValue = malloc(quantity[0] * sizeof(int));
        clearCountValue(countValue, quantity[0]);
        readArray(base, quantity[0]);
        
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i]]++;
        }
        
        int min = 0;
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]]]--;
            if (countValue[base[i - quantity[2]]] == 0) {
                min--;
            }
            countValue[base[i]]++;
            if (countValue[base[i]] == 1) {
                min++;
            }
            if (min < 0) {
                min = 0;
            }
        }
        
        writeInt(min);
        free(base);
        free(countValue);
    }
    return 0;
}

void graphStart(Graph *g, int length) {
    g->used = malloc(length * sizeof(int));
    g->ancestor = malloc(length * sizeof(int));
    memset(g->used, 0, length * sizeof(int));
    g->ancestor[0] = -1;
    g->quantity = 0;
}

void graphDfs(Graph *g, int position) {
    g->used[position] = 1;
    g->quantity++;
    for (int index = 0; index < g->base[position]; index += 2) {
        int next = g->base[position][index];
        if (!g->used[next]) {
            g->ancestor[next] = position;
            graphDfs(g, next);
        } else if (next != g->ancestor[position]) {
            // Handle exception
        }
    }
}

int graphDijkstra(Graph *g, int start, int stop, int size) {
    start--;
    stop--;
    int *dist = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        dist[i] = (i != start) ? INT_MAX : 0;
        g->ancestor[i] = start;
    }

    // Implement priority queue logic here for Dijkstra's algorithm

    free(dist);
    return (dist[stop] == INT_MAX) ? -1 : dist[stop];
}

// Additional functions for sorting and other operations can be implemented similarly.
