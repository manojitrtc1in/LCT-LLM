#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_COUNT 1000
#define MAX_EDGE_COUNT 10000
#define INF 1000000000

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
    int* array;
    int size;
    int capacity;
} IntList;

typedef struct {
    IntList list;
    int shift;
    int* index;
} Heap;

Graph createGraph(int vertexCount) {
    Graph graph;
    graph.vertexCount = vertexCount;
    graph.edgeCount = 0;
    for (int i = 0; i < vertexCount; ++i) {
        graph.firstOutbound[i] = -1;
        graph.firstInbound[i] = -1;
    }
    return graph;
}

void addEdge(Graph* graph, int from, int to, long long weight, long long capacity, int reverseEdge) {
    int id = graph->edgeCount;
    graph->edges[id].from = from;
    graph->edges[id].to = to;
    graph->edges[id].weight = weight;
    graph->edges[id].capacity = capacity;
    graph->edges[id].reverseEdge = reverseEdge;
    if (graph->firstOutbound[from] != -1) {
        graph->nextOutbound[id] = graph->firstOutbound[from];
    } else {
        graph->nextOutbound[id] = -1;
    }
    graph->firstOutbound[from] = id;
    if (graph->firstInbound != NULL) {
        if (graph->firstInbound[to] != -1) {
            graph->nextInbound[id] = graph->firstInbound[to];
        } else {
            graph->nextInbound[id] = -1;
        }
        graph->firstInbound[to] = id;
    }
    graph->from[id] = from;
    graph->to[id] = to;
    if (capacity != 0) {
        graph->capacity[id] = capacity;
    }
    if (weight != 0) {
        graph->weight[id] = weight;
    }
    if (reverseEdge != -1) {
        graph->reverseEdge[id] = reverseEdge;
    }
    if (graph->edges != NULL) {
        graph->edges[id] = graph->edges[id];
    }
    graph->edgeCount++;
}

void addDirectedEdge(Graph* graph, int from, int to, long long capacity) {
    addEdge(graph, from, to, 0, capacity, -1);
}

void addFlowEdge(Graph* graph, int from, int to, long long capacity) {
    int id1 = addEdge(graph, from, to, 0, capacity, -1);
    int id2 = addEdge(graph, to, from, 0, 0, id1);
    graph->edges[id1].reverseEdge = id2;
    graph->edges[id2].reverseEdge = id1;
}

void addBidirectionalEdge(Graph* graph, int from, int to, long long capacity) {
    addDirectedEdge(graph, from, to, capacity);
    addDirectedEdge(graph, to, from, capacity);
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
        if (graph->flow[id] < -flow) {
            printf("Not enough capacity\n");
            exit(1);
        }
    }
    graph->capacity[id] -= flow;
    graph->capacity[graph->reverseEdge[id]] += flow;
}

bool flag(Graph* graph, int id, int bit) {
    return (graph->flags[id] >> bit & 1) != 0;
}

bool isRemoved(Graph* graph, int id) {
    return flag(graph, id, 0);
}

void ensureCapacity(Graph* graph, int size) {
    if (graph->edgeCount < size) {
        int newSize = size > 1 ? size : 2;
        graph->edges = (Edge*)realloc(graph->edges, newSize * sizeof(Edge));
        graph->from = (int*)realloc(graph->from, newSize * sizeof(int));
        graph->to = (int*)realloc(graph->to, newSize * sizeof(int));
        graph->nextOutbound = (int*)realloc(graph->nextOutbound, newSize * sizeof(int));
        graph->flags = (int*)realloc(graph->flags, newSize * sizeof(int));
    }
}

void clear(Graph* graph) {
    graph->vertexCount = 0;
    graph->edgeCount = 0;
    for (int i = 0; i < graph->vertexCount; ++i) {
        graph->firstOutbound[i] = -1;
        graph->firstInbound[i] = -1;
    }
}

void add(IntList* list, int value) {
    if (list->size == list->capacity) {
        list->capacity = list->capacity * 2;
        list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = value;
}

void addAll(IntList* list, IntList* values) {
    for (int i = 0; i < values->size; ++i) {
        add(list, values->array[i]);
    }
}

IntList createIntList() {
    IntList list;
    list.array = (int*)malloc(10 * sizeof(int));
    list.size = 0;
    list.capacity = 10;
    return list;
}

void addHeap(Heap* heap, int source) {
    heap->index[source] = 0;
    add(&heap->list, source);
}

bool isEmpty(Heap* heap) {
    return heap->shift == heap->list.size;
}

int poll(Heap* heap) {
    int result = heap->list.array[heap->shift++];
    heap->index[result] = -1;
    return result;
}

int getIndex(Heap* heap, int next) {
    return heap->index[next];
}

void shiftUp(Heap* heap, int index) {

}

void clearHeap(Heap* heap) {
    heap->list = createIntList();
    heap->shift = 0;
    for (int i = 0; i < heap->list.size; ++i) {
        heap->index[heap->list.array[i]] = -1;
    }
}

Graph readGraph() {
    int vertexCount;
    scanf("%d", &vertexCount);
    Graph graph = createGraph(vertexCount);
    int edgeCount;
    scanf("%d", &edgeCount);
    for (int i = 0; i < edgeCount; ++i) {
        int from, to;
        long long weight, capacity;
        scanf("%d%d%lld%lld", &from, &to, &weight, &capacity);
        addFlowEdge(&graph, from - 1, to - 1, capacity);
    }
    return graph;
}

Pair minCostFlow(Graph* graph, int source, int destination, bool id11) {
    int vertexCount = graph->vertexCount;
    long long phi[vertexCount];
    if (id11) {
        for (int i = 0; i < vertexCount; ++i) {
            phi[i] = INF;
        }
        phi[source] = 0;
        bool inQueue[vertexCount];
        int queue[vertexCount + 1];
        int head = 0;
        int tail = 1;
        queue[0] = source;
        inQueue[source] = true;
        int stepCount = 0;
        int maxSteps = 2 * vertexCount * vertexCount;
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
            if (++stepCount > maxSteps) {
                printf("Graph contains negative cycle\n");
                exit(1);
            }
        }
    }
    long long id13[vertexCount];
    int lastEdge[vertexCount];
    Heap heap;
    heap.list = createIntList();
    heap.shift = 0;
    heap.index = (int*)malloc(vertexCount * sizeof(int));
    if (graph->isSparse) {
        for (int i = 0; i < vertexCount; ++i) {
            id13[i] = INF;
            lastEdge[i] = -1;
            heap.index[i] = -1;
        }
        id13[source] = 0;
        addHeap(&heap, source);
        while (!isEmpty(&heap)) {
            int current = poll(&heap);
            int edgeID = graph->firstOutbound[current];
            while (edgeID != -1) {
                if (graph->capacity[edgeID] != 0) {
                    int next = graph->to[edgeID];
                    long long total = graph->weight[edgeID] - phi[next] + phi[current] + id13[current];
                    if (id13[next] > total) {
                        id13[next] = total;
                        if (getIndex(&heap, next) == -1) {
                            addHeap(&heap, next);
                        } else {
                            shiftUp(&heap, getIndex(&heap, next));
                        }
                        lastEdge[next] = edgeID;
                    }
                }
                edgeID = graph->nextOutbound[edgeID];
            }
        }
    } else {
        int visited[vertexCount];
        for (int i = 0; i < vertexCount; ++i) {
            id13[i] = INF;
            lastEdge[i] = -1;
            visited[i] = 0;
            heap.index[i] = -1;
        }
        id13[source] = 0;
        for (int i = 0; i < vertexCount; ++i) {
            int index = -1;
            long long length = INF;
            for (int j = 0; j < vertexCount; ++j) {
                if (visited[j] != 1 && id13[j] < length) {
                    length = id13[j];
                    index = j;
                }
            }
            if (index == -1) {
                break;
            }
            visited[index] = 1;
            int edgeID = graph->firstOutbound[index];
            while (edgeID != -1) {
                if (graph->capacity[edgeID] != 0) {
                    int next = graph->to[edgeID];
                    if (visited[next] != 1) {
                        long long total = graph->weight[edgeID] - phi[next] + phi[index] + length;
                        if (id13[next] > total) {
                            id13[next] = total;
                            lastEdge[next] = edgeID;
                        }
                    }
                }
                edgeID = graph->nextOutbound[edgeID];
            }
        }
    }
    long long cost = 0;
    long long flow = 0;
    while (true) {
        if (lastEdge[destination] == -1) {
            break;
        }
        for (int i = 0; i < vertexCount; ++i) {
            if (id13[i] != INF) {
                phi[i] += id13[i];
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
    Pair result;
    result.first = cost;
    result.second = flow;
    return result;
}

int main() {
    int vertexCount, edgeCount;
    scanf("%d%d", &vertexCount, &edgeCount);
    Graph graph = createGraph(vertexCount);
    for (int i = 0; i < edgeCount; ++i) {
        int from, to;
        long long weight, capacity;
        scanf("%d%d%lld%lld", &from, &to, &weight, &capacity);
        addFlowEdge(&graph, from - 1, to - 1, capacity);
    }
    Pair result = minCostFlow(&graph, 0, vertexCount - 1, false);
    printf("%lld\n", result.first);
    return 0;
}
