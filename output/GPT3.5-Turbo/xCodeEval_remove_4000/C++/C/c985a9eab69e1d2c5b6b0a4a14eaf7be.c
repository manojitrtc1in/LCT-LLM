#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item {
    struct pair {
        int first;
        int second;
    } key;
    int prior;
    size_t cnt;
    struct item* l;
    struct item* r;
} item;

typedef item* pitem;

bool operator_less(struct pair a, struct pair b) {
    return (long long)a.first * b.second < (long long)a.second * b.first;
}

bool operator_greater(struct pair a, struct pair b) {
    return (long long)a.first * b.second > (long long)a.second * b.first;
}

bool operator_equal(struct pair a, struct pair b) {
    return (long long)a.first * b.second == (long long)a.second * b.first;
}

void upd(pitem t) {
    if (t == NULL)
        return;
    t->cnt = (t->l == NULL ? 0 : t->l->cnt) + (t->r == NULL ? 0 : t->r->cnt) + 1;
}

void split(pitem t, struct pair key, pitem* l, pitem* r) {
    if (!t)
        *l = *r = NULL;
    else if (operator_less(key, t->key) || (operator_equal(key, t->key) && rand() % 2))
        split(t->l, key, l, &(t->l)), *r = t;
    else
        split(t->r, key, &(t->r), r), *l = t;
    upd(*l), upd(*r);
}

void wsplit(pitem t, struct pair key, pitem* l, pitem* r) {
    if (!t)
        *l = *r = NULL;
    else if (operator_less(key, t->key) || operator_equal(key, t->key))
        wsplit(t->l, key, l, &(t->l)), *r = t;
    else
        wsplit(t->r, key, &(t->r), r), *l = t;
    upd(*l), upd(*r);
}

void insert(pitem* t, pitem it) {
    if (!*t)
        *t = it;
    else if (it->prior > (*t)->prior)
        split(*t, it->key, &(it->l), &(it->r)), *t = it;
    else
        insert(operator_less(it->key, (*t)->key) || (operator_equal(it->key, (*t)->key) && rand() % 2) ? (*t)->l : (*t)->r, it);
    upd(*t);
}

void merge(pitem* t, pitem l, pitem r) {
    if (!l || !r)
        *t = l ? l : r;
    else if (l->prior > r->prior)
        merge(&(l->r), l->r, r), *t = l;
    else
        merge(&(r->l), l, r->l), *t = r;
    upd(*t);
}

void erase(pitem* t, struct pair key) {
    if ((*t)->key.first == key.first && (*t)->key.second == key.second)
        merge(t, (*t)->l, (*t)->r);
    else
        erase(operator_less(key, (*t)->key) ? (*t)->l : (*t)->r, key);
    upd(*t);
}

long long ans(struct pair* a, size_t n) {
    pitem t = NULL;
    long long ans = 0;
    for (size_t i = 0; i < n; i++) {
        pitem l, r;
        wsplit(t, a[i].second, &l, &r);
        ans += (r == NULL ? 0 : r->cnt);
        merge(&t, l, r);
        insert(&t, &(struct item){a[i].second, rand(), 1, NULL, NULL});
    }
    return ans;
}

int main() {
    size_t n;
    int w;
    scanf("%zu %d", &n, &w);
    struct pair* b = malloc(n * sizeof(struct pair));
    for (size_t i = 0; i < n; i++) {
        int a, v;
        scanf("%d %d", &a, &v);
        b[i].first = (struct pair){abs(a), abs(v - w)};
        b[i].second = (struct pair){abs(a), abs(v + w)};
    }
    qsort(b, n, sizeof(struct pair), [](const void* a, const void* b) {
        struct pair* pa = (struct pair*)a;
        struct pair* pb = (struct pair*)b;
        if (pa->first.first < pb->first.first)
            return -1;
        if (pa->first.first > pb->first.first)
            return 1;
        if (pa->first.second < pb->first.second)
            return -1;
        if (pa->first.second > pb->first.second)
            return 1;
        if (pa->second.first < pb->second.first)
            return -1;
        if (pa->second.first > pb->second.first)
            return 1;
        if (pa->second.second < pb->second.second)
            return -1;
        if (pa->second.second > pb->second.second)
            return 1;
        return 0;
    });
    printf("%lld\n", ans(b, n));
    free(b);
    return 0;
}
