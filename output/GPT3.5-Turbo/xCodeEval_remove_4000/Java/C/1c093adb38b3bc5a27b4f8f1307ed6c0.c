#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTEX_COUNT 100000
#define MAX_EDGE_COUNT 200000

typedef struct {
    int id;
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
    long weight[MAX_EDGE_COUNT];
    long capacity[MAX_EDGE_COUNT];
    int reverseEdge[MAX_EDGE_COUNT];
    int flags[MAX_EDGE_COUNT];
} Graph;

typedef struct {
    int vertex;
    long distance;
} HeapNode;

typedef struct {
    HeapNode* array;
    int size;
    int capacity;
    int* index;
} Heap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntList;

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
} IntSet;

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
} IntDeque;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntDequeIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntIterator;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPair;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairPair;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairTriple;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairQuad;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairQuint;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairSext;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairSept;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairOct;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairNon;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairDec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairUndec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairDodec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairTridec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairTetradec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairPentadec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairHexadec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairHeptadec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairOctadec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairNonadec;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcos;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxl;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxli;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxlii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxliii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxliv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxlv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxlvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxlvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxlviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxlix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosl;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosli;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosliii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosliv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoslxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxci;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxcii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxciii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxciv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxcv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxcvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxcvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxcviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosxcix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosci;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosciii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosciv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscl;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscli;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscliii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscliv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscci;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscciii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscciv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxl;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxli;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxliii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxliv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscl;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscli;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscliii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscliv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscci;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscciii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscciv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxl;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxli;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxliii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxliv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxlix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscl;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscli;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscliii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscliv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosclxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscc;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscci;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscciii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcoscciv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxx;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxiii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxiv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxv;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxvi;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxvii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxviii;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxxxix;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPairIcosccxl;

typedef struct {
    int* array;
