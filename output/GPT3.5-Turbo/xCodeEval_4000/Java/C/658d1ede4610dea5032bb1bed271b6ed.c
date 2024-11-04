#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTEX_COUNT 100000
#define MAX_EDGE_COUNT 200000

typedef struct {
    int from;
    int to;
    long long weight;
    long long capacity;
    int reverseEdge;
} Edge;

typedef struct {
    int id;
    int next;
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
    int id;
    long long value;
} HeapNode;

typedef struct {
    HeapNode* array;
    int size;
    int capacity;
    int* position;
} Heap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntStack;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntTripleArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntTripleHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntTripleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongPairArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongPairHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongPairHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongTripleArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongTripleHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongTripleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongPairArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongPairHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongPairHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongTripleArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongTripleHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongTripleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongPairArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongPairHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongPairHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongTripleArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongTripleHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongTripleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongPairArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongPairHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongPairHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongTripleArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongTripleHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongTripleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongPairArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongPairHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongPairHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongTripleArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongTripleHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongTripleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongLongPairArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongLongPairHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongLongPairHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongLongTripleArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongLongTripleHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntLongLongLongLongLongLongTripleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
