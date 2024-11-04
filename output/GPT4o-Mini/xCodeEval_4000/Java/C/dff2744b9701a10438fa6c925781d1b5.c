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
    int edgeCount;
    int vertexCount;
} Graph;

typedef struct {
    int *weight;
    int *path;
    Graph *graph;
} TaskD;

void readIntArray(IntArray *arr, int size) {
    arr->data = (int *)malloc(size * sizeof(int));
    arr->size = size;
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr->data[i]);
    }
}

void createGraph(Graph *graph, int vertexCount, int edgeCapacity) {
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    graph->firstOutbound = (int *)malloc(vertexCount * sizeof(int));
    graph->nextOutbound = (int *)malloc(edgeCapacity * sizeof(int));
    graph->from = (int *)malloc(edgeCapacity * sizeof(int));
    graph->to = (int *)malloc(edgeCapacity * sizeof(int));
    memset(graph->firstOutbound, -1, vertexCount * sizeof(int));
}

void addEdge(Graph *graph, int fromID, int toID) {
    graph->from[graph->edgeCount] = fromID;
    graph->to[graph->edgeCount] = toID;
    graph->nextOutbound[graph->edgeCount] = graph->firstOutbound[fromID];
    graph->firstOutbound[fromID] = graph->edgeCount++;
}

int dfs(TaskD *task, int current, int last) {
    int result = 0;
    int max = 0;
    int second = 0;
    for (int i = task->graph->firstOutbound[current]; i != -1; i = task->graph->nextOutbound[i]) {
        int next = task->graph->to[i];
        if (next == last) continue;
        result = dfs(task, next, current);
        if (task->path[next] > max) {
            second = max;
            max = task->path[next];
        } else {
            second = (task->path[next] > second) ? task->path[next] : second;
        }
    }
    if (task->weight[current] != 0) {
        task->path[current] = task->weight[current] + max;
        result = (result > max + second + task->weight[current]) ? result : (max + second + task->weight[current]);
    } else {
        task->path[current] = 0;
    }
    return result;
}

void solve(TaskD *task, int n, int k, IntArray *a, IntArray *u, IntArray *v) {
    task->graph = (Graph *)malloc(sizeof(Graph));
    createGraph(task->graph, n, n - 1);
    for (int i = 0; i < n - 1; i++) {
        addEdge(task->graph, u->data[i], v->data[i]);
    }
    task->weight = (int *)calloc(n, sizeof(int));
    task->path = (int *)calloc(n, sizeof(int));
    int left = k, right = n;

    while (left < right) {
        int middle = (left + right) >> 1;
        int threshold = a->data[middle - 1];
        memset(task->weight, 0, n * sizeof(int));
        for (int i = 0; i < n; i++) {
            task->weight[i] = (a->data[i] >= threshold) ? 1 : 0;
        }
        int result = dfs(task, 0, -1);
        if (result >= k) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    printf("%d\n", a->data[left - 1]);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    IntArray a, u, v;
    readIntArray(&a, n);
    u.size = n - 1;
    u.data = (int *)malloc(u.size * sizeof(int));
    v.size = n - 1;
    v.data = (int *)malloc(v.size * sizeof(int));
    readIntArray(&u, u.size);
    readIntArray(&v, v.size);

    TaskD task;
    solve(&task, n, k, &a, &u, &v);

    free(a.data);
    free(u.data);
    free(v.data);
    free(task.weight);
    free(task.path);
    free(task.graph->firstOutbound);
    free(task.graph->nextOutbound);
    free(task.graph->from);
    free(task.graph->to);
    free(task.graph);
    return 0;
}
