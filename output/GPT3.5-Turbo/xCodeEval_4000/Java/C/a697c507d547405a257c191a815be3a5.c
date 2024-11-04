#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_T 1000000000
#define MODULO 1000000007

typedef struct {
    int type;
    int arg1;
    int arg2;
    int arg3;
} Query;

typedef struct {
    int value;
    int index;
} IntIndexPair;

typedef struct {
    int to;
    int w;
} Edge;

typedef struct {
    int size;
    long* sums;
    long* mins;
    int index;
    long value;
} SegmentTree;

typedef struct {
    int* values;
    int size;
} IdMap;

typedef struct {
    int* values;
    int size;
} SortedIdMapper;

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* arr, int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

void updateTreeIndex(SegmentTree* tree, int v, int left, int right) {
    if (left + 1 == right) {
        tree->sums[v] = tree->value;
        tree->mins[v] = fmin(0, tree->value);
    }
    else {
        int mid = (left + right) / 2;
        int vLeft = (v << 1), vRight = vLeft + 1;

        if (tree->index < mid)
            updateTreeIndex(tree, vLeft, left, mid);
        else
            updateTreeIndex(tree, vRight, mid, right);

        tree->sums[v] = tree->sums[vLeft] + tree->sums[vRight];
        tree->mins[v] = fmin(tree->mins[vLeft], tree->sums[vLeft] + tree->mins[vRight]);
    }
}

void updateIndex(SegmentTree* tree, int index, long value) {
    tree->index = index;
    tree->value = value;
    updateTreeIndex(tree, 1, 0, tree->size);
}

void findTreeIndex(SegmentTree* tree, int v, int left, int right) {
    if (left + 1 == right) {
        tree->foundIndex = left;
    }
    else {
        int mid = (left + right) / 2;
        int vLeft = (v << 1), vRight = vLeft + 1;

        if (tree->value + tree->mins[vLeft] <= 0)
            findTreeIndex(tree, vLeft, left, mid);
        else {
            tree->value += tree->sums[vLeft];
            findTreeIndex(tree, vRight, mid, right);
        }
    }
}

int getInterval(SegmentTree* tree, int start, int end, long value) {
    tree->start = start;
    tree->end = end;
    tree->value = value;
    tree->found = false;
    tree->foundIndex = -1;

    getTreeInterval(tree, 1, 0, tree->size);

    return tree->foundIndex;
}

void getTreeInterval(SegmentTree* tree, int v, int left, int right) {
    if (tree->start <= left && right <= tree->end) {
        if (!tree->found) {
            if (tree->value + tree->mins[v] <= 0) {
                findTreeIndex(tree, v, left, right);
                tree->found = true;
            }
            else {
                tree->value += tree->sums[v];
            }
        }
    }
    else {
        int mid = (left + right) / 2;
        int vLeft = (v << 1), vRight = vLeft + 1;

        if (tree->start < mid)
            getTreeInterval(tree, vLeft, left, mid);
        if (mid < tree->end)
            getTreeInterval(tree, vRight, mid, right);
    }
}

IdMap* createIdMap() {
    IdMap* map = (IdMap*)malloc(sizeof(IdMap));
    map->values = (int*)malloc(sizeof(int));
    map->size = 0;
    return map;
}

void addValue(IdMap* map, int value) {
    map->values = (int*)realloc(map->values, (map->size + 1) * sizeof(int));
    map->values[map->size] = value;
    map->size++;
}

int getId(IdMap* map, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->values[i] == value)
            return i;
    }
    return -1;
}

IdMap* build(SortedIdMapper* mapper) {
    qsort(mapper->values, mapper->size, sizeof(int), cmpfunc);

    IdMap* ids = createIdMap();
    int* uniqueValues = (int*)malloc(sizeof(int));

    for (int index = 0; index < mapper->size; ++index) {
        int value = mapper->values[index];
        if (index == 0 || mapper->values[index - 1] != value) {
            addValue(ids, value);
            uniqueValues = (int*)realloc(uniqueValues, (ids->size) * sizeof(int));
            uniqueValues[ids->size - 1] = value;
        }
    }

    mapper->values = uniqueValues;

    return ids;
}

SortedIdMapper* createSortedIdMapper() {
    SortedIdMapper* mapper = (SortedIdMapper*)malloc(sizeof(SortedIdMapper));
    mapper->values = (int*)malloc(sizeof(int));
    mapper->size = 0;
    return mapper;
}

void addValueToSortedIdMapper(SortedIdMapper* mapper, int value) {
    mapper->values = (int*)realloc(mapper->values, (mapper->size + 1) * sizeof(int));
    mapper->values[mapper->size] = value;
    mapper->size++;
}

void solve() {
    int q;
    scanf("%d", &q);
    Query* queries = (Query*)malloc(q * sizeof(Query));

    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            queries[i].type = 1;
            scanf("%d %d", &queries[i].arg1, &queries[i].arg2);
        }
        else if (type == 2) {
            queries[i].type = 2;
            scanf("%d", &queries[i].arg1);
        }
        else {
            queries[i].type = 3;
            scanf("%d %d %d", &queries[i].arg1, &queries[i].arg2, &queries[i].arg3);
        }
    }

    SortedIdMapper* mapper = createSortedIdMapper();
    addValueToSortedIdMapper(mapper, 0);
    addValueToSortedIdMapper(mapper, MAX_T + 1);

    for (int i = 0; i < q; ++i) {
        int type = queries[i].type;
        if (type == 1) {
            addValueToSortedIdMapper(mapper, queries[i].arg1);
            if (type == 3)
                addValueToSortedIdMapper(mapper, queries[i].arg2);
        }
    }

    IdMap* ids = build(mapper);
    int* times = (int*)malloc(ids->size * sizeof(int));
    for (int i = 0; i < ids->size; i++) {
        times[i] = ids->values[i];
    }

    int minTime = getId(ids, 0);
    int maxTime = getId(ids, MAX_T + 1);

    int* timeSpeeds = (int*)malloc(ids->size * sizeof(int));
    timeSpeeds[minTime] = 0;
    timeSpeeds[maxTime] = 0;

    for (int i = 0; i < q; ++i) {
        int type = queries[i].type;
        if (type == 1) {
            int time = getId(ids, queries[i].arg1);
            int realTime = times[time];
            long speed = queries[i].arg2;

            int timeAfter = timeSpeeds[time + 1];
            int realTimeAfter = times[timeAfter];

            int timeBefore = timeSpeeds[time - 1];
            int realTimeBefore = times[timeBefore];
            long speedBefore = timeSpeeds[time - 1];

            updateIndex(timeSpeeds, timeBefore, speedBefore * (realTime - realTimeBefore));
            updateIndex(timeSpeeds, time, speed * (realTimeAfter - realTime));

            timeSpeeds[time] = speed;
        }
        else if (type == 2) {
            int time = getId(ids, queries[i].arg1);
            int realTime = times[time];

            int timeAfter = timeSpeeds[time + 1];
            int realTimeAfter = times[timeAfter];

            int timeBefore = timeSpeeds[time - 1];
            int realTimeBefore = times[timeBefore];

            long speedBefore = timeSpeeds[time - 1];

            updateIndex(timeSpeeds, timeBefore, speedBefore * (realTimeAfter - realTimeBefore));
            updateIndex(timeSpeeds, time, 0);

            timeSpeeds[time] = 0;
        }
        else {
            int start = getId(ids, queries[i].arg1);
            int end = getId(ids, queries[i].arg2);
            long value = queries[i].arg3;

            if (value == 0) {
                printf("%d\n", times[start]);
                continue;
            }

            int foundIndex = getInterval(timeSpeeds, start, end, value);
            if (foundIndex == -1) {
                printf("-1\n");
            }
            else {
                value = timeSpeeds[foundIndex];

                int time = foundIndex;
                int realTime = times[time];

                if (value == 0) {
                    printf("%d\n", realTime);
                }
                else {
                    long speed = timeSpeeds[time];

                    int timeAfter = fmin(end, timeSpeeds[time + 1]);
                    int realTimeAfter = times[timeAfter];

                    long delta = realTimeAfter - realTime;
                    long total = delta * speed;

                    if (value + total > 0) {
                        printf("-1\n");
                    }
                    else {
                        double badTime = realTime + (double)value / fabs(speed);
                        printf("%f\n", badTime);
                    }
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
