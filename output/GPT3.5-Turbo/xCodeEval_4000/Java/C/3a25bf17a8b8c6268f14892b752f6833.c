#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define gigamod 1000000007

typedef struct {
    long long x;
    long long y;
    long long z;
    long long id;
} Point;

typedef struct {
    int from;
    int to;
    long long weight;
    int id;
} Edge;

typedef struct {
    int* parentOf;
    int maxJmpPow;
    int** binAncestorOf;
    int n;
    int* lvlOf;
} BinaryLift;

typedef struct {
    int* adj;
    int size;
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

typedef struct {
    int* adj;
    int size;
} Stack;

typedef struct {
    long long* array;
    int size;
} FenwickTree;

typedef struct {
    long long** heap;
    long long* array;
    int size;
} SegmentTree;

typedef struct {
    long long sum;
    long long min;
    long long max;
    long long* pendingVal;
    int from;
    int to;
} Node;

typedef struct {
    long long x;
    long long y;
} DioGCDResult;

typedef struct {
    long long* x0;
    long long* y0;
} DiophantineResult;

typedef struct {
    long long** mat;
    int size;
} Matrix;

typedef struct {
    int* parent;
    int* size;
    int count;
} UnionFind;

typedef struct {
    int* levelOf;
    int* first;
    int* segtree;
    int* euler;
    bool* visited;
    int n;
} LCA;

typedef struct {
    int* arr;
    int length;
} CountMap;

int main() {
    // Your code here
    return 0;
}
