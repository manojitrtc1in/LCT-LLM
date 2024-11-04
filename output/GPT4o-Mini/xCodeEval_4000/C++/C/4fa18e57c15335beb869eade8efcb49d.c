#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int a, b, c;
} int_abc;

typedef struct {
    int u, v;
} int_uv;

typedef struct {
    int *data;
    int size;
} vector_int;

typedef struct {
    int_abc *data;
    int size;
} vector_int_abc;

void push_back_int_uv(vector_int_uv *vec, int_uv value) {
    vec->data = realloc(vec->data, (vec->size + 1) * sizeof(int_uv));
    vec->data[vec->size++] = value;
}

void push_back_int_abc(vector_int_abc *vec, int_abc value) {
    vec->data = realloc(vec->data, (vec->size + 1) * sizeof(int_abc));
    vec->data[vec->size++] = value;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

void doit(int *a, int *b, int *path, vector_int_abc *res, int pos, int vol, int diff) {
    if (pos + 1 >= path[0]) return;
    int tgt = path[pos + 1];
    int before = min(diff, vol - a[tgt]);
    int src = path[pos];
    if (before > 0) {
        int_abc abc = {src + 1, tgt + 1, before};
        push_back_int_abc(res, abc);
    }
    doit(a, b, path, res, pos + 1, vol, diff);
    int after = diff - before;
    if (after > 0) {
        int_abc abc = {src + 1, tgt + 1, after};
        push_back_int_abc(res, abc);
    }
}

void solve() {
    int n, vol, e;
    scanf("%d %d %d", &n, &vol, &e);
    
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *ee = malloc(e * sizeof(int_uv));
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i < e; i++) scanf("%d %d", &ee[i].u, &ee[i].v);
    
    // Graph initialization and DFS invocation would go here...

    vector_int_abc res = {NULL, 0};
    
    for (int q = 0; q < n; q++) {
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                int *path = malloc(n * sizeof(int)); // Assume path is filled correctly
                // Path finding logic would go here...

                if (a[path[0]] < b[path[0]]) {
                    // Reverse the path logic would go here...
                }

                int src = path[0], tgt = path[path[0]];
                int diff = min(abs(a[src] - b[src]), abs(a[tgt] - b[tgt]));
                doit(a, b, path, &res, 0, vol, diff);
                a[src] -= diff;
                a[tgt] += diff;

                free(path);
            }
        }
    }

    printf("%d\n", res.size);
    for (int i = 0; i < res.size; i++) {
        printf("%d %d %d\n", res.data[i].a, res.data[i].b, res.data[i].c);
    }

    free(a);
    free(b);
    free(ee);
    free(res.data);
}

int main() {
    solve();
    return 0;
}