#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000005
#define MAXM 1000005
#define gigamod 1000000007

typedef struct {
    int from;
    int to;
    long long weight;
    int id;
} Edge;

typedef struct {
    long long x;
    long long y;
    long long z;
    long long id;
} Point;

typedef struct {
    int* parentOf;
    int maxJmpPow;
    int** binAncestorOf;
    int n;
    int* lvlOf;
} BinaryLift;

typedef struct {
    int* parent;
    int* size;
    int count;
} UnionFind;

typedef struct {
    int* adj[MAXM];
    int E;
} UGraph;

typedef struct {
    int* adj[MAXM];
    int E;
} Digraph;

typedef struct {
    int* array;
    int size;
} FenwickTree;

typedef struct {
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
    int* height;
    int* first;
    int* segtree;
    int* euler;
    bool* visited;
    int n;
} LCA;

typedef struct {
    int* arr;
    int len;
} CountMap;

// Function Declarations
int main();
void fastReader();
void solve();
void printArr(int* arr, int len);
void printArrLL(long long* arr, int len);
void printArrChar(char* arr, int len);
void printArr2D(int** arr, int rows, int cols);
void printArr2DLL(long long** arr, int rows, int cols);
void printArr2DChar(char** arr, int rows, int cols);
void sort(int* arr, int len);
void sortLL(long long* arr, int len);
void sortChar(char* arr, int len);
void reverse(int* arr, int len);
void reverseLL(long long* arr, int len);
void reverseChar(char* arr, int len);
void shuffleArray(long long* arr, int startPos, int endPos);
void shuffleArrayInt(int* arr, int startPos, int endPos);
void shuffleArrayChar(char* arr, int startPos, int endPos);
bool isPrime(long long n);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
long long power(long long x, long long y, long long p);
long long modInverse(long long n, long long p);
long long modDiv(long long a, long long b);
long long mod(long long a, long long m);
int logk(long long n, long long k);
int bsearch(int* arr, int val, int lo, int hi);
int bsearchLL(long long* arr, long long val, int lo, int hi);
int bsearchChar(char* arr, char val, int lo, int hi);
long long nCr(long long n, long long r, long long* fac);
long long** matExpo(long long** mat, long long power);
long long** prod(long long** mat1, long long** mat2);
void coprimeGenerator(int m, int n, Point* coprimes, int limit, int numCoprimes);
void primeGenerator(int upto, bool* isPrime, int* smallestFactorOf);
CountMap* smolNumPrimeFactorization(int num, bool* isPrime, int* smallestFactorOf);
CountMap* primeFactorization(long long num);
void dfsMark(int current, bool* marked, UGraph* g);
void dfsMark2(int current, int from, long long* distTo, bool* marked, UGraph* g, int* endPoints, int* endPointCtr);
void dfsMark3(int current, int* colorIds, int color, UGraph* g);
int* connectedComponents(UGraph* g);
bool hasCycle(UGraph* ug);
void hcDfsMark(int current, UGraph* ug, bool* marked, bool* hasCycleFirst, int parent);
void build(int v, int from, int size, Node* heap, long long* array);
long long rsq(int v, int from, int to, Node* heap);
long long rMinQ(int v, int from, int to, Node* heap);
long long rMaxQ(int v, int from, int to, Node* heap);
void update(int v, int from, int to, long long value, Node* heap, long long* array);
bool contains(int from1, int to1, int from2, int to2);
bool intersects(int from1, int to1, int from2, int to2);
void propagate(int v, Node* heap);
void change(Node* n, long long value);
void dfs(int current, int from, bool* marked, UGraph* ug);
void treeCalc(int current, int from, bool* marked, UGraph* ug);
int query(int node, int b, int e, int L, int R, int* segtree, int* levelOf);
int lca(int u, int v, int* levelOf, int** binAncestorOf, int maxJmpPow);
int ancestor(int node, int k, int* binAncestorOf, int maxJmpPow);
void binConstruct(int node, int lvl, int* binAncestorOf, int* parentOf, int maxJmpPow);
void parentConstruct(int current, int from, UGraph* tree, int depth, int* parentOf, int* lvlOf);
void unionInit(UnionFind* uf, int n);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionUnion(UnionFind* uf, int p, int q);
int unionNumConnectedTo(UnionFind* uf, int node);
void unionUnion(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
void unionUnion(UnionFind* uf, int p, int q);
int unionFind(UnionFind* uf, int p);
bool unionConnected(UnionFind* uf, int p, int q);
void unionInit(UnionFind* uf, int n);
