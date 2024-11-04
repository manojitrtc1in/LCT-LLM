#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef long long int int64;
typedef unsigned long long int uint64;

#define DOUBLE_INF INFINITY
#define DOUBLE_NAN NAN

#define STR(a) #a

#define ASSERT(expr, msg) \
    if (!( expr )) { \
        fprintf(stderr, "%s:%d - %s\n", __FILE__, __LINE__, msg); \
        exit(EXIT_FAILURE); \
    }

typedef struct ScopeTimer {
    clock_t tic;
    const char* msg;
} ScopeTimer;

void ScopeTimer_init(ScopeTimer* timer, const char* msg) {
    timer->tic = clock();
    timer->msg = msg;
}

void ScopeTimer_destroy(ScopeTimer* timer) {
    const clock_t toc = clock();
    const uint64 dt = 1000L * (toc - timer->tic) / CLOCKS_PER_SEC;

    const uint64 mil = dt % 1000L;
    const uint64 sec = (dt / 1000L) % 60L;
    const uint64 min = (dt / 60000L) % 60L;
    const uint64 hrs = (dt / 3600000L);

    printf("\n%s\n\telapsed time: ", timer->msg);

    if (hrs) printf("%llu hrs, ", hrs);
    if (min) printf("%llu min, ", min);
    if (sec) printf("%llu sec, ", sec);
    printf("%llu mil-sec\n", mil);
}

typedef struct xyPoint {
    double x, y;
} xyPoint;

typedef struct xyCircle {
    xyPoint center;
    double radius;
} xyCircle;

void xyPoint_print(xyPoint* p) {
    printf("(%lf, %lf)", p->x, p->y);
}

void xyCircle_print(xyCircle* o) {
    printf("{(%lf, %lf) %lf}", o->center.x, o->center.y, o->radius);
}

double cartesian_dist(xyPoint* a, xyPoint* b) {
    const double d = a->x - b->x;
    const double e = a->y - b->y;
    return sqrt(d * d + e * e);
}

typedef struct xyLine {
    double slope, intercept, normfac;
    bool vertical;
    double xcross;
} xyLine;

void xyLine_init(xyLine* line, xyPoint* a, xyPoint* b) {
    if (a->x == b->x) {
        line->vertical = true;
        line->xcross = a->x;

        line->intercept = DOUBLE_NAN;
        line->slope = DOUBLE_INF;
        line->normfac = DOUBLE_NAN;
    } else {
        line->vertical = false;
        line->xcross = DOUBLE_NAN;

        line->slope = (b->y - a->y) / (b->x - a->x);
        line->intercept = a->y - line->slope * a->x;
        line->normfac = sqrt(line->slope * line->slope + 1.0);
    }
}

double xyLine_orth_dist(xyLine* line, xyPoint* o) {
    if (line->vertical) {
        return o->x - line->xcross;
    } else {
        return (line->slope * o->x - o->y + line->intercept) / line->normfac;
    }
}

double triangle_area(xyPoint* a, xyPoint* b, xyPoint* c) {
    xyLine l;
    xyLine_init(&l, a, b);
    const double h = fabs(xyLine_orth_dist(&l, c));
    const double e = cartesian_dist(a, b);
    return h * e;
}

typedef struct BigInteger {
    // implementation details
} BigInteger;

typedef struct HopcroftKarp {
    // implementation details
} HopcroftKarp;

void HopcroftKarp_init(HopcroftKarp* hk, const std::vector<std::list<size_t>>* adj, const std::vector<bool>* tag) {
    // implementation details
}

size_t HopcroftKarp_get_npair(HopcroftKarp* hk) {
    // implementation details
}

std::map<size_t, size_t> HopcroftKarp_get_map(HopcroftKarp* hk) {
    // implementation details
}

typedef struct All_Pairs_Tree_Shortest_Path {
    // implementation details
} All_Pairs_Tree_Shortest_Path;

void All_Pairs_Tree_Shortest_Path_init(All_Pairs_Tree_Shortest_Path* ap, const std::vector<std::list<size_t>>* adj) {
    // implementation details
}

size_t All_Pairs_Tree_Shortest_Path_get_distance(All_Pairs_Tree_Shortest_Path* ap, size_t u, size_t v) {
    // implementation details
}

typedef struct Heap {
    // implementation details
} Heap;

void Heap_init(Heap* heap) {
    // implementation details
}

void Heap_init_with_values(Heap* heap, const std::vector<int>* values) {
    // implementation details
}

void Heap_push(Heap* heap, int value) {
    // implementation details
}

int Heap_pop(Heap* heap) {
    // implementation details
}

int Heap_top(Heap* heap) {
    // implementation details
}

bool Heap_empty(Heap* heap) {
    // implementation details
}

size_t Heap_size(Heap* heap) {
    // implementation details
}

typedef struct UnionFind {
    // implementation details
} UnionFind;

void UnionFind_init(UnionFind* uf, size_t n) {
    // implementation details
}

size_t UnionFind_find(UnionFind* uf, size_t s) {
    // implementation details
}

void UnionFind_lazy_union(UnionFind* uf, size_t i, size_t j) {
    // implementation details
}

int main(int argc, char* argv[]) {
    // implementation details
    return EXIT_SUCCESS;
}
