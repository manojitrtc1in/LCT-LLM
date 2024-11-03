#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 1000000

typedef struct {
    int y;
    int x;
} Point;

typedef struct {
    long long val;
    int id;
} IDval;

typedef struct {
    int id;
    long long val;
} IDvalC;

typedef struct {
    int size;
    int *parent;
    int *rank;
} DisjointSet;

typedef struct {
    int n;
    long long *original;
    long long *bottomUp;
    long long *topDown;
} FenwickMin;

typedef struct {
    int n;
    long long *d;
} FenwickSum;

typedef struct {
    int N;
    long long *p;
} SegmentTree;

typedef struct {
    int *elements;
    int *counts;
    int size;
} ElementCounter;

typedef struct {
    char **elements;
    int *counts;
    int size;
} StringCounter;

typedef struct {
    int N;
    int Z;
    int nextFreeId;
    int **pointers;
    bool *end;
} Trie;

typedef struct {
    double logP;
} Prob;

typedef struct {
    bool *d;
    int first;
    int length;
} Binary;

typedef struct {
    int *nodes;
    int *depths;
    int *entries;
    int pointer;
    FenwickMin *fenwick;
} LCAFinder;

typedef struct {
    int *forw;
    int *bacw;
} StronglyConnectedComponents;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} Dijkstra;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BellmanFord;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} SPFA;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} FloydWarshall;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} Johnson;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} Kruskal;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} Prim;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} TopologicalSort;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} EulerianPath;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} HamiltonianPath;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} TravelingSalesman;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} ChinesePostman;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatching;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlow;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCost;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation2;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation3;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation4;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation5;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation6;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation7;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation8;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation9;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation10;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow2;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow3;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow4;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow5;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow6;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow7;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow8;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow9;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow10;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow11;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow12;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow13;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow14;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow15;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow16;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow17;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow18;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow19;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow20;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost2;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost3;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost4;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost5;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost6;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost7;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost8;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost9;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost10;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost11;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost12;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost13;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost14;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost15;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost16;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost17;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost18;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost19;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost20;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation2;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation3;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation4;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation5;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation6;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation7;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation8;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation9;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation10;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow2;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow3;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow4;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow5;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow6;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow7;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow8;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow9;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow10;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow11;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow12;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow13;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow14;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow15;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow16;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow17;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow18;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow19;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MinCostMaxFlow20;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost2;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost3;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost4;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost5;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost6;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost7;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost8;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost9;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost10;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost11;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost12;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost13;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost14;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost15;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost16;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost17;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost18;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost19;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} BipartiteMatchingMinCost20;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation2;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation3;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation4;

typedef struct {
    int *edges;
    int *first;
    int *next;
    int *last;
    int *dist;
    int *prev;
    int *heapIndex;
    int heapSize;
} MaxFlowMinCostCirculation5;

typedef struct {
