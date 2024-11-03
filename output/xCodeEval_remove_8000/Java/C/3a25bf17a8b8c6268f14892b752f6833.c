#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000001

typedef struct {
    int from;
    int to;
    long sum;
    long min;
    long max;
    long* pendingVal;
} Node;

typedef struct {
    Node* heap;
    long* array;
    int size;
} SegmentTree;

void build(SegmentTree* st, long* array, int v, int from, int size);
long rsq(SegmentTree* st, int v, int from, int to);
long id9(SegmentTree* st, int v, int from, int to);
long id2(SegmentTree* st, int v, int from, int to);
void update(SegmentTree* st, int v, int from, int to, long value);
void propagate(SegmentTree* st, int v);
void change(Node* n, long value);
bool contains(int from1, int to1, int from2, int to2);
bool intersects(int from1, int to1, int from2, int to2);
void sort(int* arr, int size);
void reverseSort(int* arr, int size);
void swap(int* a, int* b);
int bsearch(int* arr, int val, int lo, int hi);
long power(long x, long y, long p);
long gcd(long a, long b);
long lcm(long a, long b);
long modInverse(long n, long p);
long modDiv(long a, long b);
long mod(long a, long m);
long hash(long key);
int logk(long n, long k);
int gcd(int a, int b);
int gcd(int* arr, int size);
int* connectedComponents(int* parentOf, int n);
int* id15(int n);
int** id19(int n, int m);
int** prod(int** mat1, int** mat2, int n);
int** matExpo(int** mat, long power, int n);
int** id26(int** table, int l, int r, int n);
int** id29(int* a, int n);
int id13(int** table, int l, int r);
int ancestor(int node, int k, int* parentOf, int id14);
int lca(int u, int v, int* parentOf, int* lvlOf, int** id39, int id14);
void binConstruct(int node, int lvl, int* parentOf, int** id39, int id14);
void parentConstruct(int current, int from, int* parentOf, int* lvlOf, int** id39, int id14, int n);
void dfsMark(int current, bool* marked, int* componentId, int color, int* adj, int* adjSize);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20, int* adjIdx21);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20, int* adjIdx21, int* adjIdx22);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20, int* adjIdx21, int* adjIdx22, int* adjIdx23);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20, int* adjIdx21, int* adjIdx22, int* adjIdx23, int* adjIdx24);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20, int* adjIdx21, int* adjIdx22, int* adjIdx23, int* adjIdx24, int* adjIdx25);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20, int* adjIdx21, int* adjIdx22, int* adjIdx23, int* adjIdx24, int* adjIdx25, int* adjIdx26);
void dfsMark(int current, bool* marked, int* componentId, int color, int** adj, int* adjSize, int* adjIdx, int* adjIdx2, int* adjIdx3, int* adjIdx4, int* adjIdx5, int* adjIdx6, int* adjIdx7, int* adjIdx8, int* adjIdx9, int* adjIdx10, int* adjIdx11, int* adjIdx12, int* adjIdx13, int* adjIdx14, int* adjIdx15, int* adjIdx16, int* adjIdx17, int* adjIdx18, int* adjIdx19, int* adjIdx20, int* adjIdx21, int* adjIdx22, int* adjIdx23, int* adjIdx24, int* adjIdx25, int* adjIdx26, int* adjIdx27);
