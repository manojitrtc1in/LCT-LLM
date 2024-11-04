#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_T (1000 * 1000 * 1000)
#define MODULO (1000 * 1000 * 1000 + 7)

typedef struct {
    int *values;
    int size;
    int capacity;
} SortedIdMapper;

typedef struct {
    long *sums;
    long *mins;
    int size;
} SegmentTree;

typedef struct {
    int *keys;
    int *ids;
    int size;
    int capacity;
} IdMap;

void initSortedIdMapper(SortedIdMapper *mapper) {
    mapper->size = 0;
    mapper->capacity = 10;
    mapper->values = (int *)malloc(mapper->capacity * sizeof(int));
}

void addValue(SortedIdMapper *mapper, int value) {
    if (mapper->size == mapper->capacity) {
        mapper->capacity *= 2;
        mapper->values = (int *)realloc(mapper->values, mapper->capacity * sizeof(int));
    }
    mapper->values[mapper->size++] = value;
}

void sortValues(SortedIdMapper *mapper) {
    qsort(mapper->values, mapper->size, sizeof(int), (int (*)(const void *, const void *))compare);
}

void initIdMap(IdMap *idMap) {
    idMap->size = 0;
    idMap->capacity = 10;
    idMap->keys = (int *)malloc(idMap->capacity * sizeof(int));
    idMap->ids = (int *)malloc(idMap->capacity * sizeof(int));
}

int registerId(IdMap *idMap, int key) {
    for (int i = 0; i < idMap->size; i++) {
        if (idMap->keys[i] == key) {
            return idMap->ids[i];
        }
    }
    if (idMap->size == idMap->capacity) {
        idMap->capacity *= 2;
        idMap->keys = (int *)realloc(idMap->keys, idMap->capacity * sizeof(int));
        idMap->ids = (int *)realloc(idMap->ids, idMap->capacity * sizeof(int));
    }
    idMap->keys[idMap->size] = key;
    idMap->ids[idMap->size] = idMap->size;
    return idMap->size++;
}

void initSegmentTree(SegmentTree *tree, int n) {
    tree->size = n;
    tree->sums = (long *)malloc(4 * n * sizeof(long));
    tree->mins = (long *)malloc(4 * n * sizeof(long));
}

void updateIndex(SegmentTree *tree, int index, long value) {
    // Implementation of updateIndex
}

long getInterval(SegmentTree *tree, int start, int end, long value) {
    // Implementation of getInterval
}

void solve() {
    int q;
    scanf("%d", &q);
    int queries[q][4];

    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        queries[i][0] = type;
        if (type == 1) {
            scanf("%d %d", &queries[i][1], &queries[i][2]);
        } else if (type == 2) {
            scanf("%d", &queries[i][1]);
        } else {
            scanf("%d %d %d", &queries[i][1], &queries[i][2], &queries[i][3]);
        }
    }

    SortedIdMapper mapper;
    initSortedIdMapper(&mapper);
    addValue(&mapper, 0);
    addValue(&mapper, MAX_T + 1);

    for (int i = 0; i < q; ++i) {
        addValue(&mapper, queries[i][1]);
        if (queries[i][0] == 3) {
            addValue(&mapper, queries[i][2]);
        }
    }

    sortValues(&mapper);
    IdMap ids;
    initIdMap(&ids);

    for (int i = 0; i < mapper.size; ++i) {
        registerId(&ids, mapper.values[i]);
    }

    int minTime = ids.ids[0], maxTime = ids.ids[ids.size - 1];
    // Further implementation...

    free(mapper.values);
    free(ids.keys);
    free(ids.ids);
    free(tree.sums);
    free(tree.mins);
}

int main() {
    solve();
    return 0;
}
