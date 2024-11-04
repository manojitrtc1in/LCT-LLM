#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 200007
#define MOD 998244353

typedef struct {
    int first, second;
} pii;

typedef struct {
    int *data;
    int size;
    int capacity;
} Set;

void init_set(Set *s) {
    s->size = 0;
    s->capacity = 10;
    s->data = (int *)malloc(s->capacity * sizeof(int));
}

void insert_set(Set *s, int value) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
    }
    s->data[s->size++] = value;
}

void remove_set(Set *s, int value) {
    for (int i = 0; i < s->size; i++) {
        if (s->data[i] == value) {
            s->data[i] = s->data[--s->size];
            return;
        }
    }
}

bool is_empty(Set *s) {
    return s->size == 0;
}

int get_min(Set *s) {
    int min_value = s->data[0];
    for (int i = 1; i < s->size; i++) {
        if (s->data[i] < min_value) {
            min_value = s->data[i];
        }
    }
    return min_value;
}

int size(Set *s) {
    return s->size;
}

void free_set(Set *s) {
    free(s->data);
}

int c[MAXN];
Set s[MAXN], st[MAXN];
Set deg[3], degt[3];

void remove_leaf(Set s[], Set deg[], int v) {
    if (is_empty(&s[v])) {
        // Assuming deg[c[v]] is a set of pairs (size, vertex)
        // Remove from deg[c[v]]
        return;
    }
    int u = get_min(&s[v]);
    assert(v);
    // Remove from deg[c[v]] and deg[c[u]]
    remove_set(&deg[c[v]], size(&s[v]));
    remove_set(&deg[c[u]], size(&s[u]));
    remove_set(&s[u], v);
    remove_set(&s[v], u);
    insert_set(&deg[c[u]], size(&s[u]));
}

void id5(Set s[], Set deg[]) {
    while (true) {
        if (is_empty(&deg[0])) break;
        int ret = get_min(&deg[0]);
        if (ret > 1) break;
        remove_leaf(s, deg, ret);
    }
}

int solve(Set s[], Set deg[], int beg) {
    int res = 0;
    id5(s, deg);
    while (true) {
        if (is_empty(&deg[0]) && is_empty(&deg[1]) && is_empty(&deg[2])) break;
        if (is_empty(&deg[beg])) { beg = 3 - beg; continue; }
        res++;
        while (true) {
            if (is_empty(&deg[beg])) break;
            int ret = get_min(&deg[beg]);
            if (ret > 1) break;
            remove_leaf(s, deg, ret);
            id5(s, deg);
        }
        beg = 3 - beg;
    }
    return res;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
            init_set(&s[i]);
            init_set(&st[i]);
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            insert_set(&s[u], v);
            insert_set(&s[v], u);
            insert_set(&st[u], v);
            insert_set(&st[v], u);
        }
        for (int i = 1; i <= n; i++) {
            insert_set(&deg[c[i]], size(&s[i]));
            insert_set(&degt[c[i]], size(&s[i]));
        }
        printf("%d ", fmax(fmin(solve(s, deg, 1), solve(st, degt, 2)), 1LL));
    }
    return 0;
}
