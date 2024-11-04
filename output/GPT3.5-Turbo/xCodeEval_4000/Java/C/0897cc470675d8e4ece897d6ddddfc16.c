#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTEX_COUNT 1000
#define MAX_EDGE_COUNT 10000
#define INF 1e9

typedef struct {
    int from;
    int to;
    long long weight;
    long long capacity;
    int reverseEdge;
} Edge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int firstOutbound[MAX_VERTEX_COUNT];
    int firstInbound[MAX_VERTEX_COUNT];
    Edge edges[MAX_EDGE_COUNT];
    int nextInbound[MAX_EDGE_COUNT];
    int nextOutbound[MAX_EDGE_COUNT];
    int from[MAX_EDGE_COUNT];
    int to[MAX_EDGE_COUNT];
    long long weight[MAX_EDGE_COUNT];
    long long capacity[MAX_EDGE_COUNT];
    int reverseEdge[MAX_EDGE_COUNT];
    int flags[MAX_EDGE_COUNT];
} Graph;

typedef struct {
    long long first;
    long long second;
} Pair;

typedef struct {
    int value;
    bool valid;
} IntIterator;

typedef struct {
    int data[MAX_VERTEX_COUNT];
    int size;
} IntQueue;

void initGraph(Graph* graph, int vertexCount) {
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    memset(graph->firstOutbound, -1, sizeof(graph->firstOutbound));
    memset(graph->firstInbound, -1, sizeof(graph->firstInbound));
}

void addEdge(Graph* graph, int from, int to, long long weight, long long capacity, int reverseEdge) {
    int edgeID = graph->edgeCount++;
    graph->from[edgeID] = from;
    graph->to[edgeID] = to;
    graph->weight[edgeID] = weight;
    graph->capacity[edgeID] = capacity;
    graph->reverseEdge[edgeID] = reverseEdge;
    graph->nextOutbound[edgeID] = graph->firstOutbound[from];
    graph->firstOutbound[from] = edgeID;
    graph->nextInbound[edgeID] = graph->firstInbound[to];
    graph->firstInbound[to] = edgeID;
}

void addFlowWeightedEdge(Graph* graph, int from, int to, long long weight, long long capacity) {
    if (capacity == 0) {
        addEdge(graph, from, to, weight, 0, -1);
    } else {
        int lastEdgeCount = graph->edgeCount;
        addEdge(graph, to, from, -weight, 0, lastEdgeCount + 1);
        addEdge(graph, from, to, weight, capacity, lastEdgeCount);
    }
}

void pushFlow(Graph* graph, int id, long long flow) {
    if (flow == 0) {
        return;
    }
    if (flow > 0) {
        if (graph->capacity[id] < flow) {
            printf("Not enough capacity\n");
            exit(1);
        }
    } else {
        if (graph->capacity[graph->reverseEdge[id]] < -flow) {
            printf("Not enough capacity\n");
            exit(1);
        }
    }
    graph->capacity[id] -= flow;
    graph->capacity[graph->reverseEdge[id]] += flow;
}

void fordBellman(Graph* graph, int source, long long* phi) {
    int vertexCount = graph->vertexCount;
    memset(phi, INF, sizeof(long long) * vertexCount);
    phi[source] = 0;
    bool inQueue[vertexCount];
    memset(inQueue, false, sizeof(bool) * vertexCount);
    int queue[vertexCount + 1];
    int head = 0;
    int tail = 1;
    queue[0] = source;
    inQueue[source] = true;
    int stepCount = 0;
    while (head != tail) {
        int vertex = queue[head++];
        if (head == vertexCount + 1) {
            head = 0;
        }
        inQueue[vertex] = false;
        int edgeID = graph->firstOutbound[vertex];
        while (edgeID != -1) {
            long long total = phi[vertex] + graph->weight[edgeID];
            int destination = graph->to[edgeID];
            if (graph->capacity[edgeID] != 0 && phi[destination] > total) {
                phi[destination] = total;
                if (!inQueue[destination]) {
                    queue[tail++] = destination;
                    if (tail == vertexCount + 1) {
                        tail = 0;
                    }
                    inQueue[destination] = true;
                }
            }
            edgeID = graph->nextOutbound[edgeID];
        }
        if (++stepCount > 2 * vertexCount * vertexCount) {
            printf("Graph contains negative cycle\n");
            exit(1);
        }
    }
}

Pair minCostMaxFlow(Graph* graph, int source, int destination, bool hasNegativeEdges) {
    int vertexCount = graph->vertexCount;
    long long phi[vertexCount];
    if (hasNegativeEdges) {
        fordBellman(graph, source, phi);
    }
    long long dijkstraResult[vertexCount];
    int lastEdge[vertexCount];
    memset(lastEdge, -1, sizeof(int) * vertexCount);
    IntQueue heap;
    heap.size = 0;
    int visited[vertexCount];
    memset(visited, 0, sizeof(int) * vertexCount);
    int visitIndex = 0;
    long long cost = 0;
    long long flow = 0;
    while (true) {
        memset(dijkstraResult, INF, sizeof(long long) * vertexCount);
        memset(lastEdge, -1, sizeof(int) * vertexCount);
        dijkstraResult[source] = 0;
        heap.size = 0;
        heap.data[heap.size++] = source;
        while (heap.size > 0) {
            int current = heap.data[0];
            int currentIndex = 0;
            for (int i = 1; i < heap.size; i++) {
                if (dijkstraResult[heap.data[i]] < dijkstraResult[current]) {
                    current = heap.data[i];
                    currentIndex = i;
                }
            }
            heap.data[currentIndex] = heap.data[--heap.size];
            int edgeID = graph->firstOutbound[current];
            while (edgeID != -1) {
                if (graph->capacity[edgeID] != 0) {
                    int next = graph->to[edgeID];
                    long long total = graph->weight[edgeID] - phi[next] + phi[current] + dijkstraResult[current];
                    if (dijkstraResult[next] > total) {
                        dijkstraResult[next] = total;
                        lastEdge[next] = edgeID;
                        if (visited[next] != visitIndex) {
                            visited[next] = visitIndex;
                            heap.data[heap.size++] = next;
                        }
                    }
                }
                edgeID = graph->nextOutbound[edgeID];
            }
        }
        if (lastEdge[destination] == -1) {
            return (Pair) {cost, flow};
        }
        for (int i = 0; i < vertexCount; i++) {
            if (dijkstraResult[i] != INF) {
                phi[i] += dijkstraResult[i];
            }
        }
        int vertex = destination;
        long long currentFlow = INF;
        long long currentCost = 0;
        while (vertex != source) {
            int edgeID = lastEdge[vertex];
            currentFlow = currentFlow < graph->capacity[edgeID] ? currentFlow : graph->capacity[edgeID];
            currentCost += graph->weight[edgeID];
            vertex = graph->from[edgeID];
        }
        flow += currentFlow;
        cost += currentCost * currentFlow;
        vertex = destination;
        while (vertex != source) {
            int edgeID = lastEdge[vertex];
            pushFlow(graph, edgeID, currentFlow);
            vertex = graph->from[edgeID];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    int a[n];
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[s[i] - 'a']++;
    }
    Graph g;
    initGraph(&g, n + 100);
    int source = n + 100 - 2;
    int target = source + 1;
    for (int i = 0; i * 2 < n; i++) {
        addFlowWeightedEdge(&g, i, target, 0, 2);
    }
    for (int i = 0; i < 26; i++) {
        addFlowWeightedEdge(&g, source, i + n, 0, cnt[i]);
        for (int j = 0; j * 2 < n; j++) {
            if (s[j] == s[n - j - 1]) {
                int w = 0;
                if (s[j] == i + 'a') {
                    w = -a[j] > -a[n - j - 1] ? -a[j] : -a[n - j - 1];
                }
                addFlowWeightedEdge(&g, i + n, j, w, 1);
            } else {
                int w = 0;
                if (s[j] == i + 'a') {
                    w -= a[j];
                }
                if (s[n - j - 1] == i + 'a') {
                    w -= a[n - j - 1];
                }
                addFlowWeightedEdge(&g, i + n, j, w, 1);
            }
        }
    }
    Pair result = minCostMaxFlow(&g, source, target, true);
    printf("%lld\n", -result.first);
    return 0;
}
