#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    long *elements;
    int size;
    int capacity;
} HashMap;

typedef struct {
    long *array;
    int size;
    int capacity;
} LongList;

typedef struct {
    int *array;
    int size;
    int capacity;
} IntList;

typedef struct {
    int id;
    long val;
} IDval;

typedef struct {
    int *parent;
    int *size;
    int componentCount;
} UnionFind;

typedef struct {
    long *hashes;
    long *modifiers;
} HashResult;

typedef struct {
    long P;
    long M;
} StringHasher;

void initHashMap(HashMap *map, int capacity) {
    map->elements = (long *)malloc(capacity * sizeof(long));
    map->size = 0;
    map->capacity = capacity;
}

void addToHashMap(HashMap *map, long element) {
    if (map->size >= map->capacity) {
        map->capacity *= 2;
        map->elements = (long *)realloc(map->elements, map->capacity * sizeof(long));
    }
    map->elements[map->size++] = element;
}

void initLongList(LongList *list, int capacity) {
    list->array = (long *)malloc(capacity * sizeof(long));
    list->size = 0;
    list->capacity = capacity;
}

void addToLongList(LongList *list, long value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (long *)realloc(list->array, list->capacity * sizeof(long));
    }
    list->array[list->size++] = value;
}

void initIntList(IntList *list, int capacity) {
    list->array = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
}

void addToIntList(IntList *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = value;
}

void initUnionFind(UnionFind *uf, int n) {
    uf->parent = (int *)malloc(n * sizeof(int));
    uf->size = (int *)malloc(n * sizeof(int));
    uf->componentCount = n;
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->size[i] = 1;
    }
}

int find(UnionFind *uf, int a) {
    if (uf->parent[a] != a) {
        uf->parent[a] = find(uf, uf->parent[a]);
    }
    return uf->parent[a];
}

void join(UnionFind *uf, int a, int b) {
    int rootA = find(uf, a);
    int rootB = find(uf, b);
    if (rootA != rootB) {
        if (uf->size[rootA] > uf->size[rootB]) {
            uf->size[rootA] += uf->size[rootB];
            uf->parent[rootB] = rootA;
        } else {
            uf->size[rootB] += uf->size[rootA];
            uf->parent[rootA] = rootB;
        }
        uf->componentCount--;
    }
}

void initStringHasher(StringHasher *hasher) {
    hasher->P = 353875897; // Example prime
    hasher->M = 452940277; // Example modulus
}

HashResult hashString(StringHasher *hasher, const char *s) {
    int n = strlen(s);
    HashResult result;
    result.hashes = (long *)malloc(n * sizeof(long));
    result.modifiers = (long *)malloc(n * sizeof(long));
    result.hashes[0] = s[0];
    result.modifiers[0] = 1;
    for (int i = 1; i < n; i++) {
        result.hashes[i] = (result.hashes[i - 1] * hasher->P + s[i]) % hasher->M;
        result.modifiers[i] = (result.modifiers[i - 1] * hasher->P) % hasher->M;
    }
    return result;
}

long getHash(HashResult *hashedString, int startIndex, int endIndex, long M) {
    long result = hashedString->hashes[endIndex];
    if (startIndex > 0) {
        result -= (hashedString->hashes[startIndex - 1] * hashedString->modifiers[endIndex - startIndex + 1]) % M;
    }
    if (result < 0) result += M;
    return result;
}

void freeHashResult(HashResult *result) {
    free(result->hashes);
    free(result->modifiers);
}

int main() {
    // Example usage
    UnionFind uf;
    initUnionFind(&uf, 10);
    join(&uf, 1, 2);
    printf("Component Count: %d\n", uf.componentCount);

    StringHasher hasher;
    initStringHasher(&hasher);
    HashResult result = hashString(&hasher, "example");
    printf("Hash of 'example': %ld\n", getHash(&result, 0, 6, hasher.M));

    freeHashResult(&result);
    free(uf.parent);
    free(uf.size);
    return 0;
}
