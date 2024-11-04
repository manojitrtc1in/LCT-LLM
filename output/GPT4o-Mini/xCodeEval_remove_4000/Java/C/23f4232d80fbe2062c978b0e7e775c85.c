#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int *first;
    int *second;
} Pair;

typedef struct {
    int **base;
    int *used;
    int quantity;
    int *ancestor;
} Graph;

void readInt(int *num) {
    scanf("%d", num);
}

void readArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void writeInt(int number) {
    printf("%d\n", number);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void createDivision(int dividend, int divider, int *result) {
    int g = gcd(dividend, divider);
    result[0] = dividend / g;
    result[1] = divider / g;
}

void dfs(Graph *graph, int position) {
    graph->used[position] = 1;
    graph->quantity++;
    for (int index = 0; index < graph->base[position][0]; index++) {
        int next = graph->base[position][index + 1];
        if (!graph->used[next]) {
            graph->ancestor[next] = position;
            dfs(graph, next);
        } else if (next != graph->ancestor[position]) {
            // Handle cycle
            exit(1);
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

    // Priority queue implementation can be added here

    free(dist);
    return (dist[stop] == INT_MAX) ? -1 : dist[stop];
}

int main() {
    int i1;
    readInt(&i1);
    for (int i2 = 0; i2 < i1; i2++) {
        int quantity[3];
        readArray(quantity, 3);
        int *base = (int *)malloc(quantity[0] * sizeof(int));
        readArray(base, quantity[0]);

        int *countValue = (int *)calloc(quantity[0], sizeof(int));
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i]]++;
        }
        int min = 0; // Initialize min

        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]]]--;
            countValue[base[i]]++;
            // Update min
        }
        writeInt(min);
        free(base);
        free(countValue);
    }
    return 0;
}
