#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100000
#define MAXM 200000

typedef struct {
    int id;
} Edge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int firstOutbound[MAXN];
    int firstInbound[MAXN];
    Edge edges[2 * MAXM];
    int nextInbound[2 * MAXM];
    int nextOutbound[2 * MAXM];
    int from[2 * MAXM];
    int to[2 * MAXM];
    long long weight[2 * MAXM];
    long long capacity[2 * MAXM];
    int reverseEdge[2 * MAXM];
    int flags[2 * MAXM];
} Graph;

typedef struct {
    int at;
    bool removed;
} IntIterator;

void graphInit(Graph *graph, int vertexCount) {
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
        graph->firstInbound[i] = -1;
    }
}

int graphAddEdge(Graph *graph, int from, int to, long long weight, long long capacity, int reverseEdge) {
    int lastEdgeCount = graph->edgeCount;
    graph->edges[lastEdgeCount].id = lastEdgeCount;
    if (graph->firstOutbound[from] != -1) {
        graph->nextOutbound[lastEdgeCount] = graph->firstOutbound[from];
    } else {
        graph->nextOutbound[lastEdgeCount] = -1;
    }
    graph->firstOutbound[from] = lastEdgeCount;
    if (graph->firstInbound[to] != -1) {
        graph->nextInbound[lastEdgeCount] = graph->firstInbound[to];
    } else {
        graph->nextInbound[lastEdgeCount] = -1;
    }
    graph->firstInbound[to] = lastEdgeCount;
    graph->from[lastEdgeCount] = from;
    graph->to[lastEdgeCount] = to;
    if (capacity != 0) {
        graph->capacity[lastEdgeCount] = capacity;
    }
    if (weight != 0) {
        graph->weight[lastEdgeCount] = weight;
    }
    if (reverseEdge != -1) {
        graph->reverseEdge[lastEdgeCount] = reverseEdge;
    }
    graph->flags[lastEdgeCount] = 0;
    graph->edgeCount++;
    return lastEdgeCount;
}

void graphEnsureEdgeCapacity(Graph *graph, int size) {
    if (size > 2 * MAXM) {
        fprintf(stderr, "Graph has more than 2 * MAXM edges\n");
        exit(1);
    }
}

int graphFirstOutbound(Graph *graph, int vertex) {
    int id = graph->firstOutbound[vertex];
    while (id != -1 && graph->flags[id] & 1) {
        id = graph->nextOutbound[id];
    }
    return id;
}

int graphNextOutbound(Graph *graph, int id) {
    id = graph->nextOutbound[id];
    while (id != -1 && graph->flags[id] & 1) {
        id = graph->nextOutbound[id];
    }
    return id;
}

int graphDestination(Graph *graph, int id) {
    return graph->to[id];
}

bool graphFlag(Graph *graph, int id, int bit) {
    return (graph->flags[id] >> bit) & 1;
}

bool graphIsRemoved(Graph *graph, int id) {
    return graphFlag(graph, id, 0);
}

void graphAddFlowWeightedEdge(Graph *graph, int from, int to, long long weight, long long capacity) {
    if (capacity == 0) {
        graphAddEdge(graph, from, to, weight, 0, -1);
    } else {
        int lastEdgeCount = graph->edgeCount;
        graphAddEdge(graph, to, from, -weight, 0, lastEdgeCount + 1);
        graphAddEdge(graph, from, to, weight, capacity, lastEdgeCount);
    }
}

void graphAddWeightedEdge(Graph *graph, int from, int to, long long weight) {
    graphAddFlowWeightedEdge(graph, from, to, weight, 0);
}

void graphAddSimpleEdge(Graph *graph, int from, int to) {
    graphAddWeightedEdge(graph, from, to, 0);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    Graph graph;
    graphInit(&graph, n);

    int a[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int u[MAXN - 1], v[MAXN - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        graphAddSimpleEdge(&graph, u[i] - 1, v[i] - 1);
        graphAddSimpleEdge(&graph, v[i] - 1, u[i] - 1);
    }

    int order[MAXN];
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[order[i]] < a[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    int left = k;
    int right = n;
    int weight[MAXN];
    int degree[MAXN];
    for (int i = 0; i < n - 1; i++) {
        degree[u[i] - 1]++;
        degree[v[i] - 1]++;
    }
    int remaining[MAXN];
    int queue[MAXN];
    int path[MAXN];
    while (left < right) {
        int middle = (left + right) >> 1;
        int threshold = a[order[middle - 1]];
        for (int i = 0; i < n; i++) {
            weight[i] = a[i] >= threshold ? 1 : 0;
        }
        for (int i = 0; i < n; i++) {
            remaining[i] = degree[i];
        }
        int size = 0;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 && weight[i] > 0) {
                queue[size++] = i;
            }
        }
        for (int i = 0; i < size; i++) {
            int current = queue[i];
            for (int j = graphFirstOutbound(&graph, current); j != -1; j = graphNextOutbound(&graph, j)) {
                int next = graphDestination(&graph, j);
                if (weight[next] != 0) {
                    weight[next] += weight[current];
                    weight[current] = 0;
                    remaining[next]--;
                    if (remaining[next] == 1) {
                        queue[size++] = next;
                    }
                }
            }
        }
        int result = dfs(&graph, 0, -1, weight, path);
        if (result >= k) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    printf("%d\n", a[order[left - 1]]);

    return 0;
}

int dfs(Graph *graph, int current, int last, int *weight, int *path) {
    int result = 0;
    int max = 0;
    int second = 0;
    for (int id = graphFirstOutbound(graph, current); id != -1; id = graphNextOutbound(graph, id)) {
        int next = graphDestination(graph, id);
        if (next == last) {
            continue;
        }
        result = max(result, dfs(graph, next, current, weight, path));
        if (path[next] > max) {
            second = max;
            max = path[next];
        } else {
            second = max(second, path[next]);
        }
    }
    if (weight[current] != 0) {
        path[current] = weight[current] + max;
        result = max(result, max + second + weight[current]);
    } else {
        path[current] = 0;
    }
    return result;
}

int max(int a, int b) {
    return a > b ? a : b;
}
