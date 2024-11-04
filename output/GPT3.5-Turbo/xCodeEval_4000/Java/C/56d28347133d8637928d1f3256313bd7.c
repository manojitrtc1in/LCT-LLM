#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTEX_COUNT 100000
#define MAX_EDGE_COUNT 1000000

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
} IntQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntHeap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntDeque;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntVector;

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
} IntArraySet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHeap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayPriorityQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntry;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntry;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetEntryValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetKeyIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMapValueIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSetValueIterator;

typedef struct {
    int* array;
