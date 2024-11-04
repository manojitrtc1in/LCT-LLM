#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 202020

typedef struct {
    int a, b, c;
} triple;

typedef struct {
    int first, second;
} pii;

typedef struct {
    int *data;
    int size;
    int capacity;
} vector;

typedef struct {
    int *data;
    int size;
} set;

set g[MAXN];
int ct;
vector c;
int sz[MAXN];
bool used[MAXN];
int n;
vector ans;

void init_vector(vector *v) {
    v->size = 0;
    v->capacity = 10;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

void push_back(vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void go(int cur, int iter) {
    sz[cur] = 1;
    used[cur] = iter;
    int t = 0;
    for (int i = 0; i < g[cur].size; i++) {
        int to = g[cur].data[i];
        if (!used[to]) {
            go(to, iter);
            sz[cur] += sz[to];
            t = (t > sz[to]) ? t : sz[to];
        }
    }
    t = (t > (n - sz[cur])) ? t : (n - sz[cur]);
    if (t * 2 <= n) {
        ct = cur;
        push_back(&c, cur);
    }
}

vector st;

void dfs2(int cur, int p) {
    used[cur] = true;
    for (int i = 0; i < g[cur].size; i++) {
        int to = g[cur].data[i];
        if (!used[to]) {
            dfs2(to, cur);
        }
    }
    push_back(&st, cur);
}

void solve(int cur) {
    st.size = 0;
    dfs2(cur, -1);
    st.size--; // pop last
    int last = cur;
    for (int i = 0; i < st.size; i++) {
        int v = st.data[i];
        int par = (i > 0) ? st.data[i - 1] : -1;
        if (par != cur) {
            push_back(&ans, (triple){ct, last, v});
            push_back(&ans, (triple){v, par, cur});
            last = v;
        }
    }
    if (last != cur) {
        push_back(&ans, (triple){ct, last, cur});
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        push_back(&g[x], y);
        push_back(&g[y], x);
    }
    init_vector(&c);
    go(1, 1);
    memset(used, 0, sizeof(used));
    for (int i = 0; i < c.size; i++) {
        used[c.data[i]] = true;
    }
    for (int i = 0; i < c.size; i++) {
        ct = c.data[i];
        for (int j = 0; j < g[ct].size; j++) {
            int to = g[ct].data[j];
            if (!used[to]) {
                solve(to);
            }
        }
    }
    printf("%d\n", ans.size);
    for (int i = 0; i < ans.size; i++) {
        printf("%d %d %d\n", ans.data[i].a, ans.data[i].b, ans.data[i].c);
    }
    return 0;
}
