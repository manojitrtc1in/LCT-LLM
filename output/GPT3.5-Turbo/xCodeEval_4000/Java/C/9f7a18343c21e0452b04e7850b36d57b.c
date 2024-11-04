#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTEX_COUNT 1000
#define MAX_EDGE_COUNT 10000

typedef struct {
    int from;
    int to;
    long weight;
    long capacity;
    int reverseEdge;
} Edge;

typedef struct {
    int id;
    int firstOutbound;
} GraphEdge;

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
    long weight[MAX_EDGE_COUNT];
    long capacity[MAX_EDGE_COUNT];
    int reverseEdge[MAX_EDGE_COUNT];
    int flags[MAX_EDGE_COUNT];
} Graph;

typedef struct {
    long first;
    long second;
} Pair;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayList;

typedef struct {
    IntArrayList* list;
    int shift;
    int* index;
} Heap;

typedef struct {
    Graph* graph;
    int source;
    int destination;
    long* phi;
    long* dijkstraResult;
    int* lastEdge;
    Heap* heap;
    int vertexCount;
    int* visited;
    int visitIndex;
} MinCostFlow;

void addEdge(Graph* graph, int fromID, int toID, long weight, long capacity, int reverseEdge) {
    int edgeCount = graph->edgeCount;
    graph->edges[edgeCount].from = fromID;
    graph->edges[edgeCount].to = toID;
    graph->edges[edgeCount].weight = weight;
    graph->edges[edgeCount].capacity = capacity;
    graph->edges[edgeCount].reverseEdge = reverseEdge;
    if (graph->firstOutbound[fromID] != -1) {
        graph->nextOutbound[edgeCount] = graph->firstOutbound[fromID];
    } else {
        graph->nextOutbound[edgeCount] = -1;
    }
    graph->firstOutbound[fromID] = edgeCount;
    if (graph->firstInbound != NULL) {
        if (graph->firstInbound[toID] != -1) {
            graph->nextInbound[edgeCount] = graph->firstInbound[toID];
        } else {
            graph->nextInbound[edgeCount] = -1;
        }
        graph->firstInbound[toID] = edgeCount;
    }
    graph->edgeCount++;
}

void addFlowWeightedEdge(Graph* graph, int from, int to, long weight, long capacity) {
    if (capacity == 0) {
        addEdge(graph, from, to, weight, 0, -1);
    } else {
        int lastEdgeCount = graph->edgeCount;
        addEdge(graph, to, from, -weight, 0, lastEdgeCount + 1);
        addEdge(graph, from, to, weight, capacity, lastEdgeCount);
    }
}

GraphEdge createEdge(int id) {
    GraphEdge edge;
    edge.id = id;
    return edge;
}

Graph* createGraph(int vertexCount, int edgeCapacity) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
        graph->firstInbound[i] = -1;
    }
    return graph;
}

void ensureEdgeCapacity(Graph* graph, int size) {
    if (graph->edgeCount + size > MAX_EDGE_COUNT) {
        printf("Edge capacity exceeded");
        exit(1);
    }
}

void add(Graph* graph, int value) {
    ensureEdgeCapacity(graph, 1);
    graph->array[graph->size++] = value;
}

void addAll(Graph* graph, IntArrayList* values) {
    for (int i = 0; i < values->size; i++) {
        add(graph, values->array[i]);
    }
}

IntIterator* createIterator(IntList* list) {
    IntIterator* iterator = (IntIterator*)malloc(sizeof(IntIterator));
    iterator->list = list;
    iterator->index = 0;
    return iterator;
}

int hasNext(IntIterator* iterator) {
    return iterator->index < iterator->list->size;
}

int next(IntIterator* iterator) {
    return iterator->list->array[iterator->index++];
}

IntList* createIntList() {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->array = (int*)malloc(sizeof(int) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addToList(IntList* list, int value) {
    if (list->size == list->capacity) {
        list->array = (int*)realloc(list->array, sizeof(int) * list->capacity * 2);
        list->capacity *= 2;
    }
    list->array[list->size++] = value;
}

void ensureCapacity(IntArrayList* list, int newCapacity) {
    if (newCapacity > list->capacity) {
        list->array = (int*)realloc(list->array, sizeof(int) * newCapacity);
        list->capacity = newCapacity;
    }
}

IntArrayList* createIntArrayList() {
    IntArrayList* list = (IntArrayList*)malloc(sizeof(IntArrayList));
    list->array = (int*)malloc(sizeof(int) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addToIntArrayList(IntArrayList* list, int value) {
    if (list->size == list->capacity) {
        ensureCapacity(list, list->capacity * 2);
    }
    list->array[list->size++] = value;
}

Heap* createHeap(int vertexCount) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->list = createIntArrayList();
    heap->shift = 0;
    heap->index = (int*)malloc(sizeof(int) * vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        heap->index[i] = -1;
    }
    return heap;
}

void addToHeap(Heap* heap, int source) {
    heap->index[source] = 0;
    addToIntArrayList(heap->list, source);
}

int isEmpty(Heap* heap) {
    return heap->shift == heap->list->size;
}

int poll(Heap* heap) {
    int result = heap->list->array[heap->shift++];
    heap->index[result] = -1;
    return result;
}

int getIndex(Heap* heap, int next) {
    return heap->index[next];
}

void shiftUp(Heap* heap, int index) {
    // TODO: Implement shiftUp
}

void clearHeap(Heap* heap) {
    heap->list->size = 0;
    heap->shift = 0;
    for (int i = 0; i < heap->list->size; i++) {
        heap->index[heap->list->array[i]] = -1;
    }
}

MinCostFlow* createMinCostFlow(Graph* graph, int source, int destination, bool hasNegativeEdges) {
    MinCostFlow* minCostFlow = (MinCostFlow*)malloc(sizeof(MinCostFlow));
    minCostFlow->graph = graph;
    minCostFlow->source = source;
    minCostFlow->destination = destination;
    minCostFlow->vertexCount = graph->vertexCount;
    minCostFlow->phi = (long*)malloc(sizeof(long) * minCostFlow->vertexCount);
    minCostFlow->dijkstraResult = (long*)malloc(sizeof(long) * minCostFlow->vertexCount);
    minCostFlow->lastEdge = (int*)malloc(sizeof(int) * minCostFlow->vertexCount);
    minCostFlow->heap = createHeap(minCostFlow->vertexCount);
    minCostFlow->visited = (int*)malloc(sizeof(int) * minCostFlow->vertexCount);
    minCostFlow->visitIndex = 0;
    if (hasNegativeEdges) {
        // TODO: Implement fordBellman
    }
    return minCostFlow;
}

Pair* createPair(long first, long second) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->first = first;
    pair->second = second;
    return pair;
}

Pair* minCostMaxFlow(MinCostFlow* minCostFlow) {
    long maxFlow = LONG_MAX;
    long cost = 0;
    long flow = 0;
    while (maxFlow != 0) {
        if (minCostFlow->graph->vertexCount <= 1000) {
            // TODO: Implement dijkstraAlgorithm
        } else {
            // TODO: Implement dijkstraAlgorithmFull
        }
        if (minCostFlow->lastEdge[minCostFlow->destination] == -1) {
            return createPair(cost, flow);
        }
        for (int i = 0; i < minCostFlow->vertexCount; i++) {
            if (minCostFlow->dijkstraResult[i] != LONG_MAX) {
                minCostFlow->phi[i] += minCostFlow->dijkstraResult[i];
            }
        }
        int vertex = minCostFlow->destination;
        long currentFlow = maxFlow;
        long currentCost = 0;
        while (vertex != minCostFlow->source) {
            int edgeID = minCostFlow->lastEdge[vertex];
            currentFlow = currentFlow < minCostFlow->graph->edges[edgeID].capacity ? currentFlow : minCostFlow->graph->edges[edgeID].capacity;
            currentCost += minCostFlow->graph->edges[edgeID].weight;
            vertex = minCostFlow->graph->edges[edgeID].from;
        }
        maxFlow -= currentFlow;
        cost += currentCost * currentFlow;
        flow += currentFlow;
        vertex = minCostFlow->destination;
        while (vertex != minCostFlow->source) {
            int edgeID = minCostFlow->lastEdge[vertex];
            minCostFlow->graph->edges[edgeID].capacity -= currentFlow;
            minCostFlow->graph->edges[minCostFlow->graph->edges[edgeID].reverseEdge].capacity += currentFlow;
            vertex = minCostFlow->graph->edges[edgeID].from;
        }
    }
    return createPair(cost, flow);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int shoe = m * n / 2;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    Graph* graph = createGraph(2 * shoe + 2, 2 * shoe + 2);

    int source = 2 * shoe;
    int sink = 2 * shoe + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = i * m + j;
            if ((i + j) % 2 == 0) {
                for (int z = 0; z < 4; z++) {
                    int i1 = i + dx[z];
                    int j1 = j + dy[z];
                    if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m) {
                        continue;
                    }
                    int id1 = i1 * m + j1;
                    int wt = (a[i][j] == a[i1][j1]) ? 0 : 1;
                    addFlowWeightedEdge(graph, id, id1, wt, 1);
                }
                addFlowWeightedEdge(graph, source, id, 0, 1);
            } else {
                addFlowWeightedEdge(graph, id, sink, 0, 1);
            }
        }
    }

    MinCostFlow* mcf = createMinCostFlow(graph, source, sink, false);
    Pair* ans = minCostMaxFlow(mcf);
    printf("%ld\n", ans->first);

    return 0;
}
