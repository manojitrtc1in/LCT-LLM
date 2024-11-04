#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_BIT 17

typedef struct {
    int to;
    int index;
} Edge;

typedef struct {
    int n;
    int m;
    Edge** graph;
    Edge* edges;
} id37;

typedef struct {
    int to;
    int w;
} Edge;

typedef struct {
    int n;
    Edge** graph;
} id19;

typedef struct {
    int n;
    int** table;
    int* id89;
    int* order;
    int* tin;
    int* up;
} SparseTable;

typedef struct {
    int n;
    int** graph;
    int* h;
    int** parents;
} id64;

typedef struct {
    int n;
    int** graph;
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

typedef struct {
    int n;
    int** graph;
    int* sizes;
    int* ranks;
    int* parents;
} DSU;

id37* create_id37(int n) {
    id37* g = (id37*)malloc(sizeof(id37));
    g->n = n;
    g->m = 0;
    g->graph = (Edge**)malloc(n * sizeof(Edge*));
    for (int i = 0; i < n; i++) {
        g->graph[i] = (Edge*)malloc(sizeof(Edge));
    }
    g->edges = (Edge*)malloc(n * sizeof(Edge));
    return g;
}

void addEdge(id37* g, int from, int to) {
    Edge* id30 = &(g->edges[g->m]);
    Edge* id65 = &(g->edges[g->m + 1]);

    id30->to = to;
    id30->index = g->m;
    id65->to = from;
    id65->index = g->m + 1;

    g->graph[from][0] = *id30;
    g->graph[to][0] = *id65;

    g->m += 2;
}

void id76(id37* g, int from, int parent, int* time, int* tin, int* up, bool* used, bool* id35) {
    used[from] = true;

    up[from] = tin[from] = *time;
    (*time)++;

    for (int i = 0; i < g->n; i++) {
        Edge* e = &(g->graph[from][i]);
        int to = e->to;

        if (to == parent) continue;

        if (used[to]) {
            up[from] = fmin(up[from], tin[to]);
        } else {
            id76(g, to, from, time, tin, up, used, id35);
            up[from] = fmin(up[from], up[to]);
            if (up[to] >= tin[from] && parent != -1) {
                id35[from] = true;
            }
        }
    }

    if (parent == -1) {
        int childrenCount = 0;
        for (int i = 0; i < g->n; i++) {
            if (used[i]) childrenCount++;
        }
        if (childrenCount > 1) {
            id35[from] = true;
        }
    }
}

bool* id33(id37* g) {
    bool* id35 = (bool*)malloc(g->n * sizeof(bool));
    memset(id35, false, g->n * sizeof(bool));

    bool* used = (bool*)malloc(g->n * sizeof(bool));
    memset(used, false, g->n * sizeof(bool));

    int* tin = (int*)malloc(g->n * sizeof(int));
    int* up = (int*)malloc(g->n * sizeof(int));
    int time = 0;

    for (int i = 0; i < g->n; i++) {
        if (!used[i]) {
            id76(g, i, -1, &time, tin, up, used, id35);
        }
    }

    free(used);
    free(tin);
    free(up);

    return id35;
}

void paintEdge(id37* g, int edgeIndex, int color, int* edgeColors) {
    if (edgeColors[edgeIndex] != -1) return;

    edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
}

void id28(id37* g, int from, int color, int parent, int* edgeColors) {
    bool* used = (bool*)malloc(g->n * sizeof(bool));
    memset(used, false, g->n * sizeof(bool));

    used[from] = true;

    for (int i = 0; i < g->n; i++) {
        Edge* e = &(g->graph[from][i]);
        int to = e->to;
        if (to == parent) continue;

        if (!used[to]) {
            if (g->up[to] >= g->tin[from]) {
                int newColor = ++color;
                paintEdge(g, e->index, newColor, edgeColors);
                id28(g, to, newColor, from, edgeColors);
            } else {
                paintEdge(g, e->index, color, edgeColors);
                id28(g, to, color, from, edgeColors);
            }
        } else if (g->up[to] <= g->tin[from]) {
            paintEdge(g, e->index, color, edgeColors);
        }
    }

    free(used);
}

int* paintEdges(id37* g) {
    int* edgeColors = (int*)malloc(g->m * sizeof(int));
    memset(edgeColors, -1, g->m * sizeof(int));

    int color = -1;

    bool* used = (bool*)malloc(g->n * sizeof(bool));
    memset(used, false, g->n * sizeof(bool));

    for (int i = 0; i < g->n; i++) {
        if (!used[i]) {
            ++color;
            id28(g, i, color, -1, edgeColors);
        }
    }

    free(used);

    return edgeColors;
}

int** id60(id37* g) {
    int** id101 = (int**)malloc(g->n * sizeof(int*));
    for (int i = 0; i < g->n; i++) {
        id101[i] = (int*)malloc(g->n * sizeof(int));
        memset(id101[i], 0, g->n * sizeof(int));
    }

    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            id101[i][j] = -1;
        }
    }

    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            Edge* e = &(g->graph[i][j]);
            int edgeColor = edgeColors[e->index];
            if (edgeColor != -1) {
                id101[i][edgeColor] = 1;
            }
        }
    }

    return id101;
}

int** toGraph(id37* g) {
    int** componentsGraph = (int**)malloc(g->n * sizeof(int*));
    for (int i = 0; i < g->n; i++) {
        componentsGraph[i] = (int*)malloc(g->n * sizeof(int));
        memset(componentsGraph[i], 0, g->n * sizeof(int));
    }

    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            componentsGraph[i][j] = 0;
        }
    }

    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            Edge* e = &(g->graph[i][j]);
            int edgeColor = edgeColors[e->index];
            if (edgeColor != -1) {
                componentsGraph[i][edgeColor] = 1;
            }
        }
    }

    return componentsGraph;
}

id37* build(id37* g) {
    id33(g);
    paintEdges(g);
    return g;
}

SparseTable* create_SparseTable(int n, int* array) {
    SparseTable* st = (SparseTable*)malloc(sizeof(SparseTable));
    st->n = n;
    st->table = (int**)malloc(MAX_BIT * sizeof(int*));
    for (int i = 0; i < MAX_BIT; i++) {
        st->table[i] = (int*)malloc(n * sizeof(int));
    }
    st->id89 = (int*)malloc((n + 1) * sizeof(int));
    st->order = (int*)malloc((n + n) * sizeof(int));
    st->tin = (int*)malloc(n * sizeof(int));
    st->up = (int*)malloc(n * sizeof(int));
    st->id89[0] = 0;
    for (int i = 1; i <= n; i++) {
        st->id89[i] = st->id89[i - 1];
        int length = (1 << st->id89[i]);
        if (length + length <= i) st->id89[i]++;
    }
    st->order = order(n);
    for (int bit = 0; bit < MAX_BIT - 1; bit++) {
        for (int i = 0, j = (1 << bit); j < n; i++, j++) {
            st->table[bit + 1][i] = (array[st->order[bit]] <= array[st->order[j]]) ? st->order[bit] : st->order[j];
        }
    }
    return st;
}

int id6(SparseTable* st, int left, int right, int* order) {
    int length = (right - left + 1);

    int bit = st->id89[length];
    int segmentLength = (1 << bit);

    int orderIndex = order[left] <= order[right - segmentLength + 1] ? order[left] : order[right - segmentLength + 1];
    return orderIndex;
}

int getMin(SparseTable* st, int left, int right, int* array, int* order) {
    return array[id6(st, left, right, order)];
}

id64* create_id64(int n, int** graph) {
    id64* lca = (id64*)malloc(sizeof(id64));
    lca->n = n;
    lca->graph = graph;
    lca->h = (int*)malloc(n * sizeof(int));
    lca->parents = (int**)malloc(MAX_BIT * sizeof(int*));
    for (int i = 0; i < MAX_BIT; i++) {
        lca->parents[i] = (int*)malloc(n * sizeof(int));
    }
    return lca;
}

id64* build(id64* lca, int root) {
    bool* used = (bool*)malloc(lca->n * sizeof(bool));
    memset(used, false, lca->n * sizeof(bool));

    lca->h[root] = 0;
    lca->parents[0][root] = root;

    for (int i = 1; i < MAX_BIT; i++) {
        for (int v = 0; v < lca->n; v++) {
            lca->parents[i][v] = lca->parents[i - 1][lca->parents[i - 1][v]];
        }
    }

    free(used);

    return lca;
}

int lca(id64* lca, int a, int b) {
    if (lca->h[a] < lca->h[b]) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int delta = lca->h[a] - lca->h[b];
    for (int bit = MAX_BIT - 1; bit >= 0; bit--) {
        if (delta >= (1 << bit)) {
            delta -= (1 << bit);
            a = lca->parents[bit][a];
        }
    }

    if (a == b) return a;

    for (int bit = MAX_BIT - 1; bit >= 0; bit--) {
        int nextA = lca->parents[bit][a], nextB = lca->parents[bit][b];
        if (nextA != nextB) {
            a = nextA;
            b = nextB;
        }
    }

    return lca->parents[0][a];
}

id75* create_id75(int n, int** graph) {
    id75* lca = (id75*)malloc(sizeof(id75));
    lca->n = n;
    lca->graph = graph;
    lca->tin = (int*)malloc(n * sizeof(int));
    lca->up = (int*)malloc(n * sizeof(int));
    lca->parents = (int*)malloc(n * sizeof(int));
    lca->used = (bool*)malloc(n * sizeof(bool));
    lca->id35 = (bool*)malloc(n * sizeof(bool));
    return lca;
}

id75* build(id75* lca, int root) {
    memset(lca->used, false, lca->n * sizeof(bool));
    memset(lca->parents, -1, lca->n * sizeof(int));
    memset(lca->tin, 0, lca->n * sizeof(int));
    memset(lca->up, 0, lca->n * sizeof(int));

    lca->time = 0;

    id76(lca, root, -1);

    return lca;
}

int height(id75* lca, int v) {
    return lca->up[v];
}

int** id60(id75* lca) {
    int** id101 = (int**)malloc(lca->n * sizeof(int*));
    for (int i = 0; i < lca->n; i++) {
        id101[i] = (int*)malloc(lca->n * sizeof(int));
        memset(id101[i], 0, lca->n * sizeof(int));
    }

    for (int i = 0; i < lca->n; i++) {
        for (int j = 0; j < lca->n; j++) {
            id101[i][j] = -1;
        }
    }

    for (int i = 0; i < lca->n; i++) {
        for (int j = 0; j < lca->n; j++) {
            id101[i][j] = -1;
        }
    }

    for (int i = 0; i < lca->n; i++) {
        for (int j = 0; j < lca->n; j++) {
            if (lca->up[i] <= lca->tin[j]) {
                id101[i][j] = 1;
            }
        }
    }

    return id101;
}

int** toGraph(id75* lca) {
    int** componentsGraph = (int**)malloc(lca->n * sizeof(int*));
    for (int i = 0; i < lca->n; i++) {
        componentsGraph[i] = (int*)malloc(lca->n * sizeof(int));
        memset(componentsGraph[i], 0, lca->n * sizeof(int));
    }

    for (int i = 0; i < lca->n; i++) {
        for (int j = 0; j < lca->n; j++) {
            componentsGraph[i][j] = 0;
        }
    }

    for (int i = 0; i < lca->n; i++) {
        for (int j = 0; j < lca->n; j++) {
            if (lca->up[i] <= lca->tin[j]) {
                componentsGraph[i][j] = 1;
            }
        }
    }

    return componentsGraph;
}

DSU* create_DSU(int n, int* sizes) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->n = n;
    dsu->sizes = sizes;
    dsu->ranks = (int*)malloc(n * sizeof(int));
    dsu->parents = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dsu->ranks[i] = 1;
        dsu->parents[i] = i;
    }
    return dsu;
}

int get(DSU* dsu, int v) {
    if (v == dsu->parents[v]) return v;
    return dsu->parents[v] = get(dsu, dsu->parents[v]);
}

bool union_DSU(DSU* dsu, int a, int b) {
    a = get(dsu, a);
    b = get(dsu, b);

    if (a == b) return false;

    if (dsu->ranks[a] < dsu->ranks[b]) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    dsu->parents[b] = a;
    dsu->sizes[a] += dsu->sizes[b];

    if (dsu->ranks[a] == dsu->ranks[b]) dsu->ranks[a]++;

    return true;
}

id75* id75_build(id75* lca, int root) {
    build(lca, root);
    paintEdges(lca);
    id2(lca);
    return lca;
}

id37* id37_build(id37* g) {
    id33(g);
    paintEdges(g);
    id2(g);
    return g;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    id37* g = create_id37(n);

    for (int i = 0; i < m; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(g, from, to);
    }

    build(g);

    int** componentsGraph = toGraph(g);

    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", componentsGraph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
