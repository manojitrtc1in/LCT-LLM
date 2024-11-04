#include <stdio.h>
#include <stdlib.h>

#define MAXN 200007
#define MOD 998244353

typedef struct Set {
    int size;
    int *elements;
} Set;

typedef struct Pair {
    int first;
    int second;
} Pair;

Set* createSet(int size) {
    Set *set = (Set*)malloc(sizeof(Set));
    set->size = size;
    set->elements = (int*)malloc(size * sizeof(int));
    return set;
}

void destroySet(Set *set) {
    free(set->elements);
    free(set);
}

Set* insertElement(Set *set, int element) {
    set->elements[set->size++] = element;
    return set;
}

Set* removeElement(Set *set, int element) {
    int i, j;
    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            for (j = i; j < set->size - 1; j++) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            break;
        }
    }
    return set;
}

int containsElement(Set *set, int element) {
    int i;
    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1;
        }
    }
    return 0;
}

Pair* createPair(int first, int second) {
    Pair *pair = (Pair*)malloc(sizeof(Pair));
    pair->first = first;
    pair->second = second;
    return pair;
}

void destroyPair(Pair *pair) {
    free(pair);
}

int comparePairs(const void *a, const void *b) {
    Pair *pairA = *(Pair**)a;
    Pair *pairB = *(Pair**)b;
    return pairA->first - pairB->first;
}

int removeLeaf(Set *s[], Set *deg[], int v) {
    if (s[v]->size == 0) {
        removeElement(deg[c[v]], createPair(0, v));
        return 0;
    }
    int u = s[v]->elements[0];
    removeElement(deg[c[v]], createPair(s[v]->size, v));
    removeElement(deg[c[u]], createPair(s[u]->size, u));
    removeElement(s[u], v);
    removeElement(s[v], u);
    insertElement(deg[c[u]], createPair(s[u]->size, u));
    return 1;
}

void id5(Set *s[], Set *deg[]) {
    while (1) {
        if (deg[0]->size == 0) {
            break;
        }
        Pair *ret = deg[0]->elements[0];
        if (ret->first > 1) {
            break;
        }
        removeLeaf(s, deg, ret->second);
    }
}

int solve(Set *s[], Set *deg[], int beg) {
    int res = 0;
    id5(s, deg);
    while (1) {
        if (deg[0]->size == 0 && deg[1]->size == 0 && deg[2]->size == 0) {
            break;
        }
        if (deg[beg]->size == 0) {
            beg = 3 - beg;
            continue;
        }
        res++;
        while (1) {
            if (deg[beg]->size == 0) {
                break;
            }
            Pair *ret = deg[beg]->elements[0];
            if (ret->first > 1) {
                break;
            }
            removeLeaf(s, deg, ret->second);
            id5(s, deg);
        }
        beg = 3 - beg;
    }
    return res;
}

int main() {
    int t, n, i, j, u, v;
    int c[MAXN];
    Set *s[MAXN], *st[MAXN];
    Set *deg[3], *degt[3];

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        for (i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            s[u] = insertElement(s[u], v);
            s[v] = insertElement(s[v], u);
            st[u] = insertElement(st[u], v);
            st[v] = insertElement(st[v], u);
        }
        for (i = 1; i <= n; i++) {
            deg[c[i]] = insertElement(deg[c[i]], createPair(s[i]->size, i));
            degt[c[i]] = insertElement(degt[c[i]], createPair(st[i]->size, i));
        }
        printf("%d ", max(min(solve(s, deg, 1), solve(st, degt, 2)), 1));
        for (i = 1; i <= n; i++) {
            destroySet(s[i]);
            destroySet(st[i]);
        }
        for (i = 0; i < 3; i++) {
            destroySet(deg[i]);
            destroySet(degt[i]);
        }
        printf("\n");
    }

    return 0;
}
