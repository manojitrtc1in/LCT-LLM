#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

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
} HashSet;

typedef struct {
    HashSet** adj;
    int E;
} UGraph;

typedef struct {
    int* adj;
    int size;
} HashSet;

typedef struct {
    HashSet** adj;
