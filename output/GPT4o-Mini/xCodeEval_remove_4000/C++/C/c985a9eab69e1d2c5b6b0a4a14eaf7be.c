#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef unsigned int index;

typedef struct item {
    int key[2];
    int prior;
    size_t cnt;
    struct item *l, *r;
} item;

typedef item* pitem;

void upd(pitem t) {
    if (t == NULL)
        return;
    t->cnt = (t->l == NULL ? 0 : t->l->cnt) + (t->r == NULL ? 0 : t->r->cnt) + 1;
}

void split(pitem t, int key[2], pitem *l, pitem *r) {
    if (!t) {
        *l = *r = NULL;
    } else if ((long long)key[0] * t->key[1] < (long long)t->key[0] * key[1] || (key[0] == t->key[0] && rand() % 2)) {
        split(t->l, key, l, &t->l);
        *r = t;
    } else {
        split(t->r, key, &t->r, r);
        *l = t;
    }
    upd(*l);
    upd(*r);
}

void wsplit(pitem t, int key[2], pitem *l, pitem *r) {
    if (!t) {
        *l = *r = NULL;
    } else if ((long long)key[0] * t->key[1] < (long long)t->key[0] * key[1] || key[0] == t->key[0]) {
        wsplit(t->l, key, l, &t->l);
        *r = t;
    } else {
        wsplit(t->r, key, &t->r, r);
        *l = t;
    }
    upd(*l);
    upd(*r);
}

void insert(pitem *t, pitem it) {
    if (!*t) {
        *t = it;
    } else if (it->prior > (*t)->prior) {
        split(*t, it->key, &it->l, &it->r);
        *t = it;
    } else {
        insert(it->key[0] < (*t)->key[0] || (it->key[0] == (*t)->key[0] && rand() % 2) ? &(*t)->l : &(*t)->r, it);
    }
    upd(*t);
}

void merge(pitem *t, pitem l, pitem r) {
    if (!l || !r) {
        *t = l ? l : r;
    } else if (l->prior > r->prior) {
        merge(&l->r, l->r, r);
        *t = l;
    } else {
        merge(&r->l, l, r->l);
        *t = r;
    }
    upd(*t);
}

void erase(pitem *t, int key[2]) {
    if ((*t)->key[0] == key[0] && (*t)->key[1] == key[1]) {
        merge(t, (*t)->l, (*t)->r);
    } else {
        erase(key[0] < (*t)->key[0] ? &(*t)->l : &(*t)->r, key);
    }
    upd(*t);
}

long long ans(int a[][4], size_t n) {
    pitem t = NULL;
    long long result = 0;
    for (size_t i = 0; i < n; i++) {
        pitem l, r;
        wsplit(t, a[i][1], &l, &r);
        result += (r == NULL ? 0 : r->cnt);
        merge(&t, l, r);
        pitem new_item = (pitem)malloc(sizeof(item));
        new_item->key[0] = a[i][1][0];
        new_item->key[1] = a[i][1][1];
        new_item->prior = rand();
        new_item->cnt = 1;
        new_item->l = NULL;
        new_item->r = NULL;
        insert(&t, new_item);
    }
    return result;
}

int main() {
    assert(freopen("a.in", "r", stdin));
    assert(freopen("a.out", "w", stdout));

    size_t n;
    int w;
    scanf("%zu %d", &n, &w);
    int b[n][4];
    for (index i = 0; i < n; i++) {
        int a, v;
        scanf("%d %d", &a, &v);
        b[i][0] = abs(a);
        b[i][1] = abs(v - w);
        b[i][2] = abs(a);
        b[i][3] = abs(v + w);
    }
    qsort(b, n, sizeof(b[0]), [](const void *a, const void *b) {
        int *x = (int *)a;
        int *y = (int *)b;
        return (x[0] < y[0]) ? -1 : (x[0] > y[0]) ? 1 : (x[1] > y[1]) ? -1 : 1;
    });
    printf("%lld\n", ans(b, n));
}
