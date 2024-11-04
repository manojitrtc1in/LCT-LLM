#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 1000000

typedef struct {
    long *elements;
    int size;
} HashSet;

typedef struct {
    int *elements;
    int size;
} List;

typedef struct {
    int *parent;
    int *size;
    int componentCount;
} DisjointSet;

typedef struct {
    long *hashes;
    long *modifiers;
} HashedString;

typedef struct {
    long P;
    long M;
} StringHasher;

void initHashSet(HashSet *set) {
    set->elements = (long *)malloc(MAX_N * sizeof(long));
    set->size = 0;
}

void addToHashSet(HashSet *set, long value) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == value) return;
    }
    set->elements[set->size++] = value;
}

bool containsInHashSet(HashSet *set, long value) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == value) return true;
    }
    return false;
}

void freeHashSet(HashSet *set) {
    free(set->elements);
}

void initList(List *list, int size) {
    list->elements = (int *)malloc(size * sizeof(int));
    list->size = 0;
}

void addToList(List *list, int value) {
    list->elements[list->size++] = value;
}

void freeList(List *list) {
    free(list->elements);
}

void initDisjointSet(DisjointSet *ds, int n) {
    ds->parent = (int *)malloc(n * sizeof(int));
    ds->size = (int *)malloc(n * sizeof(int));
    ds->componentCount = n;
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->size[i] = 1;
    }
}

int find(DisjointSet *ds, int a) {
    if (ds->parent[a] != a) {
        ds->parent[a] = find(ds, ds->parent[a]);
    }
    return ds->parent[a];
}

void join(DisjointSet *ds, int a, int b) {
    int rootA = find(ds, a);
    int rootB = find(ds, b);
    if (rootA != rootB) {
        if (ds->size[rootA] > ds->size[rootB]) {
            ds->size[rootA] += ds->size[rootB];
            ds->parent[rootB] = rootA;
        } else {
            ds->size[rootB] += ds->size[rootA];
            ds->parent[rootA] = rootB;
        }
        ds->componentCount--;
    }
}

void freeDisjointSet(DisjointSet *ds) {
    free(ds->parent);
    free(ds->size);
}

void initStringHasher(StringHasher *hasher) {
    hasher->P = 353873237; // Example prime
    hasher->M = 452940277; // Example modulus
}

HashedString hashString(StringHasher *hasher, const char *s) {
    int n = strlen(s);
    long *hashes = (long *)malloc(n * sizeof(long));
    long *modifiers = (long *)malloc(n * sizeof(long));
    hashes[0] = s[0];
    modifiers[0] = 1;
    for (int i = 1; i < n; i++) {
        hashes[i] = (hashes[i - 1] * hasher->P + s[i]) % hasher->M;
        modifiers[i] = (modifiers[i - 1] * hasher->P) % hasher->M;
    }
    HashedString result = {hashes, modifiers};
    return result;
}

long getHash(HashedString *hashedString, int startIndex, int endIndex, long M) {
    long result = hashedString->hashes[endIndex];
    if (startIndex > 0) {
        result -= (hashedString->hashes[startIndex - 1] * hashedString->modifiers[endIndex - startIndex + 1]) % M;
    }
    if (result < 0) result += M;
    return result;
}

void freeHashedString(HashedString *hashedString) {
    free(hashedString->hashes);
    free(hashedString->modifiers);
}

int main() {
    int n;
    scanf("%d", &n);

    int endOfBrute = fmin(n, 30);
    HashSet prev;
    initHashSet(&prev);
    addToHashSet(&prev, 0);

    for (int i = 0; i < endOfBrute; i++) {
        HashSet next;
        initHashSet(&next);
        for (int j = 0; j < prev.size; j++) {
            long v = prev.elements[j];
            addToHashSet(&next, v + 1);
            addToHashSet(&next, v + 5);
            addToHashSet(&next, v + 10);
            addToHashSet(&next, v + 50);
        }
        freeHashSet(&prev);
        prev = next;
    }

    if (n > endOfBrute) {
        int diff = n - endOfBrute;
        printf("%ld\n", prev.size + diff * 49L);
    } else {
        printf("%d\n", prev.size);
    }

    freeHashSet(&prev);
    return 0;
}
