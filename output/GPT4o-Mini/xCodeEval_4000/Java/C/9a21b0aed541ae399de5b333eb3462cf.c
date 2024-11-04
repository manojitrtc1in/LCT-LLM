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

void readArrayInt(int *array, int size) {
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
    scanf("%d", &i1);
    
    for (int i2 = 0; i2 < i1; i2++) {
        int quantity[3];
        readArrayInt(quantity, 3);
        
        int *countValue = (int *)malloc(quantity[0] * sizeof(int));
        clearCountValue(countValue, quantity[0]);
        
        int *base = (int *)malloc(quantity[0] * sizeof(int));
        readArrayInt(base, quantity[0]);
        
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
        free(countValue);
        free(base);
    }
    
    return 0;
}

void graphStart(Graph *g, int length) {
    g->used = (int *)calloc(length, sizeof(int));
    g->ancestor = (int *)malloc(length * sizeof(int));
    g->ancestor[0] = -1;
    g->quantity = 0;
}

void graphRibMatrixToDefault(Graph *g, int length, int quantity, int readConsole, int **value) {
    g->base = (int **)malloc(length * sizeof(int *));
    for (int i = 0; i < length; i++) {
        g->base[i] = (int *)malloc(length * sizeof(int));
    }
    
    for (int i = 0; i < quantity; i++) {
        int input[2];
        if (readConsole) {
            scanf("%d %d", &input[0], &input[1]);
        } else {
            input[0] = value[i][0];
            input[1] = value[i][1];
        }
        g->base[input[0] - 1][g->base[input[0] - 1][0]++] = input[1] - 1;
        g->base[input[1] - 1][g->base[input[1] - 1][0]++] = input[0] - 1;
    }
    graphStart(g, length);
}

void graphDfs(Graph *g, int position) {
    g->used[position] = 1;
    g->quantity++;
    for (int index = 0; index < g->base[position][0]; index++) {
        int next = g->base[position][index];
        if (!g->used[next]) {
            g->ancestor[next] = position;
            graphDfs(g, next);
        } else if (next != g->ancestor[position]) {
            // Handle cycle detection
            printf("Cycle detected\n");
            exit(1);
        }
    }
}

int graphDijkstra(Graph *g, int start, int stop, int size) {
    start--;
    stop--;
    int *dist = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        dist[i] = (i != start) ? INT_MAX : 0;
        g->ancestor[i] = start;
    }

    // Implement Dijkstra's algorithm
    // ...

    free(dist);
    return (dist[stop] == INT_MAX) ? -1 : dist[stop];
}
