#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MODULO 1000000007
#define MAX_T 1000000000

typedef struct {
    int *values;
    int size;
    int capacity;
} IdMap;

typedef struct {
    long *sums;
    long *mins;
    int size;
} SegmentTree;

IdMap* createIdMap() {
    IdMap *map = (IdMap *)malloc(sizeof(IdMap));
    map->size = 0;
    map->capacity = 10;
    map->values = (int *)malloc(map->capacity * sizeof(int));
    return map;
}

void addValue(IdMap *map, int value) {
    if (map->size >= map->capacity) {
        map->capacity *= 2;
        map->values = (int *)realloc(map->values, map->capacity * sizeof(int));
    }
    map->values[map->size++] = value;
}

int getId(IdMap *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->values[i] == key) {
            return i;
        }
    }
    return -1;
}

SegmentTree* createSegmentTree(int n) {
    SegmentTree *tree = (SegmentTree *)malloc(sizeof(SegmentTree));
    tree->size = n;
    tree->sums = (long *)malloc(4 * n * sizeof(long));
    tree->mins = (long *)malloc(4 * n * sizeof(long));
    return tree;
}

void updateIndex(SegmentTree *tree, int index, long value) {
    // Implementation of updateIndex
}

int getInterval(SegmentTree *tree, int start, int end, long value) {
    // Implementation of getInterval
    return -1; // Placeholder
}

void solve() {
    int q;
    scanf("%d", &q);
    int **queries = (int **)malloc(q * sizeof(int *));
    for (int i = 0; i < q; ++i) {
        queries[i] = (int *)malloc(4 * sizeof(int));
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

    IdMap *mapper = createIdMap();
    addValue(mapper, 0);
    addValue(mapper, MAX_T + 1);

    for (int i = 0; i < q; ++i) {
        addValue(mapper, queries[i][1]);
        if (queries[i][0] == 3) {
            addValue(mapper, queries[i][2]);
        }
    }

    int *times = (int *)malloc(mapper->size * sizeof(int));
    for (int i = 0; i < mapper->size; i++) {
        times[i] = mapper->values[i];
    }

    int minTime = getId(mapper, 0);
    int maxTime = getId(mapper, MAX_T + 1);

    // TreeMap equivalent in C
    // Implement the logic for id33

    SegmentTree *tree = createSegmentTree(mapper->size);

    for (int i = 0; i < q; ++i) {
        int type = queries[i][0];
        if (type == 1) {
            // Handle type 1 query
        } else if (type == 2) {
            // Handle type 2 query
        } else {
            // Handle type 3 query
        }
    }

    // Free allocated memory
    for (int i = 0; i < q; ++i) {
        free(queries[i]);
    }
    free(queries);
    free(mapper->values);
    free(mapper);
    free(times);
    free(tree->sums);
    free(tree->mins);
    free(tree);
}

int main() {
    solve();
    return 0;
}
