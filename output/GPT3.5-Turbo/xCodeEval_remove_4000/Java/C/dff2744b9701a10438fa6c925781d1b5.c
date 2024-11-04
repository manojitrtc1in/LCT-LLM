#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
} GraphEdge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int* firstOutbound;
    int* firstInbound;
    GraphEdge* edges;
    int* nextInbound;
    int* nextOutbound;
    int* from;
    int* to;
    long* weight;
    long* capacity;
    int* reverseEdge;
    int* flags;
} Graph;

Graph* createGraph(int vertexCount) {
    return createGraphWithCapacity(vertexCount, vertexCount);
}

Graph* createGraphWithCapacity(int vertexCount, int edgeCapacity) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    graph->firstOutbound = (int*)malloc(vertexCount * sizeof(int));
    for (int i = 0; i < vertexCount; i++) {
        graph->firstOutbound[i] = -1;
    }
    graph->firstInbound = NULL;
    graph->edges = (GraphEdge*)malloc(edgeCapacity * sizeof(GraphEdge));
    graph->nextInbound = NULL;
    graph->nextOutbound = (int*)malloc(edgeCapacity * sizeof(int));
    graph->from = (int*)malloc(edgeCapacity * sizeof(int));
    graph->to = (int*)malloc(edgeCapacity * sizeof(int));
    graph->weight = NULL;
    graph->capacity = NULL;
    graph->reverseEdge = NULL;
    graph->flags = (int*)malloc(edgeCapacity * sizeof(int));
    return graph;
}

int addEdge(Graph* graph, int fromID, int toID, long weight, long capacity, int reverseEdge) {
    int id = graph->edgeCount;
    if (graph->firstOutbound[fromID] != -1) {
        graph->nextOutbound[id] = graph->firstOutbound[fromID];
    } else {
        graph->nextOutbound[id] = -1;
    }
    graph->firstOutbound[fromID] = id;
    if (graph->firstInbound != NULL) {
        if (graph->firstInbound[toID] != -1) {
            graph->nextInbound[id] = graph->firstInbound[toID];
        } else {
            graph->nextInbound[id] = -1;
        }
        graph->firstInbound[toID] = id;
    }
    graph->from[id] = fromID;
    graph->to[id] = toID;
    if (capacity != 0) {
        if (graph->capacity == NULL) {
            graph->capacity = (long*)malloc(edgeCapacity * sizeof(long));
        }
        graph->capacity[id] = capacity;
    }
    if (weight != 0) {
        if (graph->weight == NULL) {
            graph->weight = (long*)malloc(edgeCapacity * sizeof(long));
        }
        graph->weight[id] = weight;
    }
    if (reverseEdge != -1) {
        if (graph->reverseEdge == NULL) {
            graph->reverseEdge = (int*)malloc(edgeCapacity * sizeof(int));
            for (int i = 0; i < id; i++) {
                graph->reverseEdge[i] = -1;
            }
        }
        graph->reverseEdge[id] = reverseEdge;
    }
    graph->flags[id] = 0;
    graph->edgeCount++;
    return id;
}

int createGraphEdge(Graph* graph, int id) {
    GraphEdge* edge = (GraphEdge*)malloc(sizeof(GraphEdge));
    edge->id = id;
    return edge;
}

int firstOutbound(Graph* graph, int vertex) {
    int id = graph->firstOutbound[vertex];
    while (id != -1 && isRemoved(graph, id)) {
        id = graph->nextOutbound[id];
    }
    return id;
}

int nextOutbound(Graph* graph, int id) {
    id = graph->nextOutbound[id];
    while (id != -1 && isRemoved(graph, id)) {
        id = graph->nextOutbound[id];
    }
    return id;
}

int destination(Graph* graph, int id) {
    return graph->to[id];
}

bool flag(Graph* graph, int id, int bit) {
    return (graph->flags[id] >> bit) & 1;
}

bool isRemoved(Graph* graph, int id) {
    return flag(graph, id, 0);
}

void removeFlag(Graph* graph, int id, int bit) {
    graph->flags[id] &= ~(1 << bit);
}

void addFlag(Graph* graph, int id, int bit) {
    graph->flags[id] |= 1 << bit;
}

void removeEdge(Graph* graph, int id) {
    removeFlag(graph, id, 0);
    removeFlag(graph, id ^ 1, 0);
}

void addReverseEdge(Graph* graph, int id) {
    int reverseEdgeID = id ^ 1;
    if (graph->reverseEdge == NULL) {
        graph->reverseEdge = (int*)malloc(graph->edgeCount * sizeof(int));
        for (int i = 0; i < graph->edgeCount; i++) {
            graph->reverseEdge[i] = -1;
        }
    }
    graph->reverseEdge[id] = reverseEdgeID;
    graph->reverseEdge[reverseEdgeID] = id;
}

void removeReverseEdge(Graph* graph, int id) {
    int reverseEdgeID = id ^ 1;
    graph->reverseEdge[id] = -1;
    graph->reverseEdge[reverseEdgeID] = -1;
}

bool hasReverseEdge(Graph* graph, int id) {
    return graph->reverseEdge != NULL && graph->reverseEdge[id] != -1;
}

int reverseEdge(Graph* graph, int id) {
    return graph->reverseEdge[id];
}

void removeEdge(Graph* graph, int id, bool removeReverseEdge) {
    removeEdge(graph, id);
    if (removeReverseEdge && hasReverseEdge(graph, id)) {
        removeEdge(graph, reverseEdge(graph, id));
    }
}

void removeAllEdges(Graph* graph) {
    for (int i = 0; i < graph->edgeCount; i++) {
        removeEdge(graph, i);
    }
}

void removeVertex(Graph* graph, int id) {
    int edgeID = firstOutbound(graph, id);
    while (edgeID != -1) {
        removeEdge(graph, edgeID, true);
        edgeID = nextOutbound(graph, edgeID);
    }
    edgeID = firstInbound(graph, id);
    while (edgeID != -1) {
        removeEdge(graph, edgeID, true);
        edgeID = nextInbound(graph, edgeID);
    }
}

int* range(int from, int to) {
    int size = abs(from - to);
    int* result = (int*)malloc(size * sizeof(int));
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            result[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            result[i] = current--;
        }
    }
    return result;
}

int* createOrder(int size) {
    return range(0, size);
}

void reverse(int* array, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntIterator;

IntIterator* createIntIterator(IntArray* intArray) {
    IntIterator* intIterator = (IntIterator*)malloc(sizeof(IntIterator));
    intIterator->at = 0;
    intIterator->removed = false;
    intIterator->intArray = intArray;
    return intIterator;
}

int value(IntIterator* intIterator) {
    if (intIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intIterator->intArray, intIterator->at);
}

bool advance(IntIterator* intIterator) {
    intIterator->at++;
    intIterator->removed = false;
    return isValid(intIterator);
}

bool isValid(IntIterator* intIterator) {
    return !intIterator->removed && intIterator->at < size(intIterator->intArray);
}

void remove(IntIterator* intIterator) {
    removeAt(intIterator->intArray, intIterator->at);
    intIterator->at--;
    intIterator->removed = true;
}

typedef IntIterator IntStream;

IntIterator* intIterator(IntArray* intArray) {
    return createIntIterator(intArray);
}

typedef struct {
    int at;
    bool removed;
    IntArray* intArray;
} IntListIterator;

IntListIterator* createIntListIterator(IntArray* intArray) {
    IntListIterator* intListIterator = (IntListIterator*)malloc(sizeof(IntListIterator));
    intListIterator->at = 0;
    intListIterator->removed = false;
    intListIterator->intArray = intArray;
    return intListIterator;
}

int value(IntListIterator* intListIterator) {
    if (intListIterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return get(intListIterator->intArray, intListIterator->at);
}

bool advance(IntListIterator* intListIterator) {
    intListIterator->at++;
    intListIterator->removed = false;
    return isValid(intListIterator);
}

bool isValid(IntListIterator* intListIterator) {
    return !intListIterator->removed && intListIterator->at < size(intListIterator->intArray);
}

void remove(IntListIterator* intListIterator) {
    removeAt(intListIterator->intArray, intListIterator->at);
    intListIterator->at--;
    intListIterator->removed = true;
}

typedef IntListIterator IntListStream;

IntListIterator* intListIterator(IntArray* intArray) {
    return createIntListIterator(intArray);
}

typedef struct {
    int* data;
    int size;
    int position;
} IntArray;

IntArray* createIntArray(int* arr, int size) {
    IntArray* intArray = (IntArray*)malloc(sizeof(IntArray));
    intArray->data = arr;
    intArray->size = size;
    intArray->position = 0;
    return intArray;
}

int size(IntArray* intArray) {
    return intArray->size;
}

int get(IntArray* intArray, int at) {
    return intArray->data[at];
}

void set(IntArray* intArray, int index, int value) {
    intArray->data[index] = value;
}

void addAt(IntArray* intArray, int index, int value) {
    // Not supported
}

void removeAt(IntArray* intArray, int index) {
    // Not supported
}

typedef IntArray IntList;

