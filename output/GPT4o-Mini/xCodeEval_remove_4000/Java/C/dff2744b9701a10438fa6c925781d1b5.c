#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int *data;
    int size;
} IntArray;

typedef struct {
    int *firstOutbound;
    int *nextOutbound;
    int *from;
    int *to;
    long *weight;
    long *capacity;
    int vertexCount;
    int edgeCount;
} Graph;

typedef struct {
    int *degree;
    int *weight;
    int *path;
    Graph graph;
} TaskD;

void initIntArray(IntArray *arr, int size) {
    arr->data = (int *)malloc(size * sizeof(int));
    arr->size = size;
}

void freeIntArray(IntArray *arr) {
    free(arr->data);
}

void addEdge(Graph *graph, int fromID, int toID, long weight, long capacity) {
    if (graph->edgeCount >= graph->vertexCount) {
        graph->vertexCount *= 2;
        graph->from = realloc(graph->from, graph->vertexCount * sizeof(int));
        graph->to = realloc(graph->to, graph->vertexCount * sizeof(int));
        graph->weight = realloc(graph->weight, graph->vertexCount * sizeof(long));
        graph->capacity = realloc(graph->capacity, graph->vertexCount * sizeof(long));
    }
    graph->from[graph->edgeCount] = fromID;
    graph->to[graph->edgeCount] = toID;
    graph->weight[graph->edgeCount] = weight;
    graph->capacity[graph->edgeCount] = capacity;
    graph->edgeCount++;
}

void dfs(TaskD *task, int current, int last, int *result) {
    int max = 0, second = 0;
    for (int i = 0; i < task->graph.edgeCount; i++) {
        if (task->graph.from[i] == current && task->graph.to[i] != last) {
            int next = task->graph.to[i];
            dfs(task, next, current, result);
            if (task->path[next] > max) {
                second = max;
                max = task->path[next];
            } else {
                second = (task->path[next] > second) ? task->path[next] : second;
            }
        }
    }
    if (task->weight[current] != 0) {
        task->path[current] = task->weight[current] + max;
        *result = (*result > max + second + task->weight[current]) ? *result : (max + second + task->weight[current]);
    } else {
        task->path[current] = 0;
    }
}

void solve(TaskD *task, int n, int k, int *a, int *u, int *v) {
    task->graph.vertexCount = n;
    task->graph.edgeCount = 0;
    task->graph.from = (int *)malloc((n - 1) * sizeof(int));
    task->graph.to = (int *)malloc((n - 1) * sizeof(int));
    task->graph.weight = (long *)malloc((n - 1) * sizeof(long));
    task->graph.capacity = (long *)malloc((n - 1) * sizeof(long));
    task->degree = (int *)calloc(n, sizeof(int));
    task->weight = (int *)malloc(n * sizeof(int));
    task->path = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n - 1; i++) {
        task->degree[u[i]]++;
        task->degree[v[i]]++;
        addEdge(&task->graph, u[i], v[i], 1, 1);
    }

    int left = k, right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        int threshold = a[middle - 1];
        memset(task->weight, 0, n * sizeof(int));
        for (int i = 0; i < n; i++) {
            task->weight[i] = (a[i] >= threshold) ? 1 : 0;
        }
        int result = 0;
        dfs(task, 0, -1, &result);
        if (result >= k) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    printf("%d\n", a[left - 1]);

    free(task->graph.from);
    free(task->graph.to);
    free(task->graph.weight);
    free(task->graph.capacity);
    free(task->degree);
    free(task->weight);
    free(task->path);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *a = (int *)malloc(n * sizeof(int));
    int *u = (int *)malloc((n - 1) * sizeof(int));
    int *v = (int *)malloc((n - 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    TaskD task;
    solve(&task, n, k, a, u, v);

    free(a);
    free(u);
    free(v);
    return 0;
}
