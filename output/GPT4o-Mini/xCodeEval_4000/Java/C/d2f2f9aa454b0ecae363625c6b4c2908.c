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

void clearMap(int *countValue, int size) {
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
        int *countValue = (int *)calloc(quantity[0], sizeof(int));
        int *base = (int *)malloc(quantity[0] * sizeof(int));
        readArrayInt(base, quantity[0]);
        
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i]]++;
        }
        
        int min = 0;
        for (int i = 0; i < quantity[0]; i++) {
            if (countValue[i] > 0) {
                min++;
            }
        }
        
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

void startGraph(Graph *graph, int length) {
    graph->used = (int *)calloc(length, sizeof(int));
    graph->ancestor = (int *)malloc(length * sizeof(int));
    graph->ancestor[0] = -1;
    graph->quantity = 0;
}

void ribMatrixToDefault(Graph *graph, int length, int quantity, int **value) {
    graph->base = (int **)malloc(length * sizeof(int *));
    for (int i = 0; i < length; i++) {
        graph->base[i] = (int *)malloc(length * sizeof(int));
    }
    for (int i = 0; i < quantity; i++) {
        int *input = value[i];
        graph->base[input[0] - 1][input[1] - 1] = 1;
        graph->base[input[1] - 1][input[0] - 1] = 1;
    }
    startGraph(graph, length);
}

void dfs(Graph *graph, int position) {
    graph->used[position] = 1;
    graph->quantity++;
    for (int index = 0; index < graph->base[position][index]; index++) {
        int next = graph->base[position][index];
        if (!graph->used[next]) {
            graph->ancestor[next] = position;
            dfs(graph, next);
        } else {
            if (next != graph->ancestor[position]) {
                // Handle exception
            }
        }
    }
}

int dijkstra(Graph *graph, int start, int stop, int size) {
    start--;
    stop--;
    int *dist = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        dist[i] = (i != start) ? INT_MAX : 0;
        graph->ancestor[i] = start;
    }
    
    // Priority queue implementation omitted for brevity
    // Add logic for Dijkstra's algorithm here
    
    free(dist);
    return dist[stop] == INT_MAX ? -1 : dist[stop];
}

int main() {
    // Example usage of the Graph structure and functions
    return 0;
}
