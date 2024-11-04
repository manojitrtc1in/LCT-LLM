#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item {
    struct item* l;
    struct item* r;
    int prior;
    size_t cnt;
    pair key;
} item;

typedef struct pair {
    int first;
    int second;
} pair;

bool operator_less(pair a, pair b) {
    return (long long)a.first * b.second < (long long)a.second * b.first;
}

bool operator_greater(pair a, pair b) {
    return (long long)a.first * b.second > (long long)a.second * b.first;
}

bool operator_equal(pair a, pair b) {
    return (long long)a.first * b.second == (long long)a.second * b.first;
}

void upd(item* t) {
    if (t == NULL)
        return;
    t->cnt = (t->l == NULL ? 0 : t->l->cnt) + (t->r == NULL ? 0 : t->r->cnt) + 1;
}

void split(item* t, pair key, item** l, item** r) {
    if (!t)
        *l = *r = NULL;
    else if (operator_less(key, t->key) || (operator_equal(key, t->key) && rand() % 2))
        split(t->l, key, l, &(t->l)), *r = t;
    else
        split(t->r, key, &(t->r), r), *l = t;
    upd(*l);
    upd(*r);
}

void wsplit(item* t, pair key, item** l, item** r) {
    if (!t)
        *l = *r = NULL;
    else if (operator_less(key, t->key) || operator_equal(key, t->key))
        wsplit(t->l, key, l, &(t->l)), *r = t;
    else
        wsplit(t->r, key, &(t->r), r), *l = t;
    upd(*l);
    upd(*r);
}

void insert(item** t, item* it) {
    if (!(*t))
        *t = it;
    else if (it->prior > (*t)->prior)
        split(*t, it->key, &(it->l), &(it->r)), *t = it;
    else
        insert(operator_less(it->key, (*t)->key) || (operator_equal(it->key, (*t)->key) && rand() % 2) ? (*t)->l : (*t)->r, it);
    upd(*t);
}

void merge(item** t, item* l, item* r) {
    if (!l || !r)
        *t = l ? l : r;
    else if (l->prior > r->prior)
        merge(&(l->r), l->r, r), *t = l;
    else
        merge(&(r->l), l, r->l), *t = r;
    upd(*t);
}

void erase(item** t, pair key) {
    if ((*t)->key.first == key.first && (*t)->key.second == key.second)
        merge(t, (*t)->l, (*t)->r);
    else
        erase(operator_less(key, (*t)->key) ? (*t)->l : (*t)->r, key);
    upd(*t);
}

long long ans(pair* a, size_t n) {
    item* t = NULL;
    long long ans = 0;
    for (size_t i = 0; i < n; i++) {
        item* l;
        item* r;
        wsplit(t, a[i].second, &l, &r);
        ans += (r == NULL ? 0 : r->cnt);
        merge(&t, l, r);
        insert(&t, new_item(a[i].second));
    }
    return ans;
}

int main() {
    size_t n;
    int w;
    scanf("%zu %d", &n, &w);
    pair* b = (pair*)malloc(n * sizeof(pair));
    for (size_t i = 0; i < n; i++) {
        int a, v;
        scanf("%d %d", &a, &v);
        b[i].first = abs(a);
        b[i].second = abs(v - w);
    }
    qsort(b, n, sizeof(pair), compare);
    printf("%lld\n", ans(b, n));
    free(b);
    return 0;
}
