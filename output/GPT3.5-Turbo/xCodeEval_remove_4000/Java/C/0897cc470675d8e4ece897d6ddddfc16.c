#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTEX_COUNT 100000
#define MAX_EDGE_COUNT 200000

typedef struct {
    int id;
} GraphEdge;

typedef struct {
    int vertexCount;
    int edgeCount;
    int firstOutbound[MAX_VERTEX_COUNT];
    int firstInbound[MAX_VERTEX_COUNT];
    GraphEdge edges[MAX_EDGE_COUNT];
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
    int* elements;
    int* at;
    int size;
    int capacity;
    int (*comparator)(int, int);
} Heap;

typedef struct {
    int* queue;
    int head;
    int tail;
    int size;
} IntQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntStack;

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
} IntArrayQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayStack;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDeque;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDoubleArrayArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayCharArrayArrayArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayIntArrayArrayArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayLongArrayArrayArrayArrayArrayArrayArrayArrayIntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
