#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define id32 1000000007

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
    int id14;
    int** id38;
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
    int* parent;
    int* size;
    int count;
} UnionFind;

typedef struct {
    int* height;
    int* first;
    int* id31;
    int* visited;
    int n;
} LCA;

typedef struct {
    long* array;
    int size;
} id39;

typedef struct {
    Node* heap;
    long* array;
    int size;
} SegmentTree;

typedef struct {
    long sum;
    long min;
    long max;
    long pendingVal;
    int from;
    int to;
} Node;

typedef struct {
    int* arr;
    int length;
} CountMap;

UGraph* createUGraph(int V) {
    UGraph* graph = (UGraph*)malloc(sizeof(UGraph));
    graph->adj = (HashSet**)malloc(V * sizeof(HashSet*));
    graph->E = 0;
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (HashSet*)malloc(sizeof(HashSet));
        graph->adj[i]->size = 0;
    }
    return graph;
}

void addEdge(UGraph* graph, int from, int to) {
    for (int i = 0; i < graph->adj[from]->size; i++) {
        if (graph->adj[from]->adj[i] == to) {
            return;
        }
    }
    graph->E++;
    graph->adj[from]->adj[graph->adj[from]->size] = to;
    graph->adj[from]->size++;
    graph->adj[to]->adj[graph->adj[to]->size] = from;
    graph->adj[to]->size++;
}

HashSet* createHashSet(int size) {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    set->adj = (int*)malloc(size * sizeof(int));
    set->size = 0;
    return set;
}

void dfsMark(int current, bool* marked, UGraph* g) {
    if (marked[current]) {
        return;
    }
    marked[current] = true;
    for (int i = 0; i < g->adj[current]->size; i++) {
        dfsMark(g->adj[current]->adj[i], marked, g);
    }
}

void dfsMarkWithDist(int current, int from, long* distTo, bool* marked, UGraph* g, int* endPoints, int* endPointSize) {
    if (marked[current]) {
        return;
    }
    marked[current] = true;
    if (from != -1) {
        distTo[current] = distTo[from] + 1;
    }
    int id35 = 0;
    for (int i = 0; i < g->adj[current]->size; i++) {
        if (marked[g->adj[current]->adj[i]]) {
            id35++;
        }
        dfsMarkWithDist(g->adj[current]->adj[i], current, distTo, marked, g, endPoints, endPointSize);
    }
    if (id35 == g->adj[current]->size) {
        endPoints[*endPointSize] = current;
        (*endPointSize)++;
    }
}

void dfsMarkWithColor(int current, int* colorIds, int color, UGraph* g) {
    if (colorIds[current] != -1) {
        return;
    }
    colorIds[current] = color;
    for (int i = 0; i < g->adj[current]->size; i++) {
        dfsMarkWithColor(g->adj[current]->adj[i], colorIds, color, g);
    }
}

int* connectedComponents(UGraph* g) {
    int n = g->V;
    int* componentId = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        componentId[i] = -1;
    }
    int colorCtr = 0;
    for (int i = 0; i < n; i++) {
        if (componentId[i] != -1) {
            continue;
        }
        dfsMarkWithColor(i, componentId, colorCtr, g);
        colorCtr++;
    }
    return componentId;
}

bool hasCycle(UGraph* ug) {
    int n = ug->V;
    bool* marked = (bool*)malloc(n * sizeof(bool));
    bool id29 = false;
    for (int i = 0; i < n; i++) {
        if (marked[i]) {
            continue;
        }
        id20(i, ug, marked, &id29, -1);
    }
    return id29;
}

void id20(int current, UGraph* ug, bool* marked, bool* id29, int parent) {
    if (marked[current]) {
        return;
    }
    if (*id29) {
        return;
    }
    marked[current] = true;
    for (int i = 0; i < ug->adj[current]->size; i++) {
        if (marked[ug->adj[current]->adj[i]] && ug->adj[current]->adj[i] != parent && parent != -1) {
            *id29 = true;
            return;
        }
        id20(ug->adj[current]->adj[i], ug, marked, id29, current);
    }
}

int* id17(Digraph* dg) {
    int* id = (int*)malloc(dg->V * sizeof(int));
    for (int i = 0; i < dg->V; i++) {
        id[i] = -1;
    }
    Digraph* reversed = createDigraph(dg->V);
    for (int i = 0; i < dg->V; i++) {
        for (int j = 0; j < dg->adj[i]->size; j++) {
            addEdge(reversed, dg->adj[i]->adj[j], i);
        }
    }
    Stack* revStack = id16(reversed);
    int idCtr = -1;
    bool* marked = (bool*)malloc(dg->V * sizeof(bool));
    while (revStack->size > 0) {
        int vertex = revStack->adj[revStack->size - 1];
        revStack->size--;
        if (marked[vertex]) {
            continue;
        }
        id19(dg, vertex, marked, ++idCtr, id);
    }
    return id;
}

void id19(Digraph* dg, int source, bool* marked, int idCtr, int* id) {
    marked[source] = true;
    id[source] = idCtr;
    for (int i = 0; i < dg->adj[source]->size; i++) {
        if (!marked[dg->adj[source]->adj[i]]) {
            id19(dg, dg->adj[source]->adj[i], marked, idCtr, id);
        }
    }
}

Stack* id16(Digraph* dg) {
    Stack* id4 = createStack(dg->V);
    bool* marked = (bool*)malloc(dg->V * sizeof(bool));
    for (int i = 0; i < dg->V; i++) {
        marked[i] = false;
    }
    for (int i = 0; i < dg->V; i++) {
        if (marked[i]) {
            continue;
        }
        id1(dg, id4, marked, i);
    }
    return id4;
}

void id1(Digraph* dg, Stack* id4, bool* marked, int source) {
    marked[source] = true;
    for (int i = 0; i < dg->adj[source]->size; i++) {
        if (!marked[dg->adj[source]->adj[i]]) {
            id1(dg, id4, marked, dg->adj[source]->adj[i]);
        }
    }
    push(id4, source);
}

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->adj = (int*)malloc(size * sizeof(int));
    stack->size = 0;
    return stack;
}

void push(Stack* stack, int value) {
    stack->adj[stack->size] = value;
    stack->size++;
}

int pop(Stack* stack) {
    stack->size--;
    return stack->adj[stack->size];
}

Digraph* createDigraph(int V) {
    Digraph* graph = (Digraph*)malloc(sizeof(Digraph));
    graph->adj = (HashSet**)malloc(V * sizeof(HashSet*));
    graph->E = 0;
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (HashSet*)malloc(sizeof(HashSet));
        graph->adj[i]->size = 0;
    }
    return graph;
}

void addEdge(Digraph* graph, int from, int to) {
    for (int i = 0; i < graph->adj[from]->size; i++) {
        if (graph->adj[from]->adj[i] == to) {
            return;
        }
    }
    graph->E++;
    graph->adj[from]->adj[graph->adj[from]->size] = to;
    graph->adj[from]->size++;
}

int* id15(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = id15(n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
