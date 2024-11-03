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
    int n;
    int** graph;
} id75;

typedef struct {
    int n;
    int** graph;
    int** parents;
    int* h;
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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

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
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

typedef struct {
    int n;
    int** graph;
    int* tin;
    int* up;
    int* parents;
    bool* used;
    bool* id35;
} id75;

id37* create_id37(int n) {
    id37* g = (id37*)malloc(sizeof(id37));
    g->n = n;
    g->m = 0;
    g->graph = (Edge**)malloc(n * sizeof(Edge*));
    g->edges = (Edge*)malloc(2 * n * sizeof(Edge));
    for (int v = 0; v < n; v++) {
        g->graph[v] = (Edge*)malloc(sizeof(Edge));
    }
    return g;
}

void add_edge(id37* g, int from, int to) {
    Edge* e1 = &(g->edges[g->m]);
    e1->to = to;
    e1->index = g->m;
    g->graph[from][0] = *e1;

    Edge* e2 = &(g->edges[g->m + 1]);
    e2->to = from;
    e2->index = g->m + 1;
    g->graph[to][0] = *e2;

    g->m += 2;
}

void dfs(id37* g, int from, int parent, int* time, int* tin, int* up, bool* used, bool* id35) {
    used[from] = true;
    up[from] = tin[from] = *time;
    (*time)++;

    for (int i = 0; i < g->n; i++) {
        Edge e = g->graph[from][i];
        int to = e.to;

        if (to == parent) {
            continue;
        }

        if (used[to]) {
            up[from] = fmin(up[from], tin[to]);
        } else {
            dfs(g, to, from, time, tin, up, used, id35);
            up[from] = fmin(up[from], up[to]);
            if (up[to] >= tin[from] && parent != -1) {
                id35[from] = true;
            }
        }
    }

    if (parent == -1) {
        int childrenCount = 0;
        for (int i = 0; i < g->n; i++) {
            if (used[i]) {
                childrenCount++;
            }
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

    dfs(g, 0, -1, &time, tin, up, used, id35);

    return id35;
}

int* paint_edges(id37* g) {
    int* edgeColors = (int*)malloc(g->m * sizeof(int));
    memset(edgeColors, -1, g->m * sizeof(int));

    int id95 = -1;

    bool* used = (bool*)malloc(g->n * sizeof(bool));
    memset(used, false, g->n * sizeof(bool));

    for (int i = 0; i < g->n; i++) {
        if (!used[i]) {
            id95++;
            id28(g, i, id95, -1);
        }
    }

    return edgeColors;
}

void id28(id37* g, int from, int color, int parent) {
    used[from] = true;

    for (int i = 0; i < g->n; i++) {
        Edge e = g->graph[from][i];
        int to = e.to;
        if (to == parent) {
            continue;
        }

        if (!used[to]) {
            if (up[to] >= tin[from]) {
                int newColor = ++id95;
                paint_edge(g, e.index, newColor);
                id28(g, to, newColor, from);
            } else {
                paint_edge(g, e.index, color);
                id28(g, to, color, from);
            }
        } else if (up[to] <= tin[from]) {
            paint_edge(g, e.index, color);
        }
    }
}

void paint_edge(id37* g, int edgeIndex, int color) {
    if (g->edgeColors[edgeIndex] != -1) {
        return;
    }

    g->edgeColors[edgeIndex] = g->edgeColors[edgeIndex ^ 1] = color;
}

int** id60(id37* g) {
    int** id101 = (int**)malloc(g->n * sizeof(int*));
    for (int v = 0; v < g->n; v++) {
        id101[v] = (int*)malloc(g->n * sizeof(int));
        for (int i = 0; i < g->n; i++) {
            id101[v][i] = -1;
        }
    }

    for (int from = 0; from < g->n; from++) {
        for (int i = 0; i < g->n; i++) {
            Edge e = g->graph[from][i];
            int to = e.to;
            if (to == parent) {
                continue;
            }
            if (!used[to]) {
                if (up[to] >= tin[from]) {
                    int newColor = ++id95;
                    paint_edge(g, e.index, newColor);
                    id28(g, to, newColor, from);
                } else {
                    paint_edge(g, e.index, color);
                    id28(g, to, color, from);
                }
            } else if (up[to] <= tin[from]) {
                paint_edge(g, e.index, color);
            }
        }
    }

    return id101;
}

id37* build(id37* g) {
    bool* id35 = id33(g);
    paint_edges(g);
    id2(g);

    return g;
}

int** to_graph(id37* g) {
    return g->componentsGraph;
}

int main() {
    int n = 5;
    id37* g = create_id37(n);

    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 0);

    build(g);

    int** graph = to_graph(g);

    return 0;
}
