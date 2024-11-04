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
    int id;
    int value;
} IdValue;

typedef struct {
    int size;
    IdValue *values;
} IdMap;

typedef struct {
    int size;
    long *sums;
    long *mins;
} SegmentTree;

int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

void updateIndex(SegmentTree *tree, int index, long value) {
    tree->sums[index] = value;
    tree->mins[index] = fmin(0, value);
}

void updateTreeIndex(SegmentTree *tree, int v, int left, int right, int index, long value) {
    if (left + 1 == right) {
        updateIndex(tree, v, value);
    } else {
        int mid = (left + right) / 2;
        int vLeft = v * 2;
        int vRight = vLeft + 1;

        if (index < mid) {
            updateTreeIndex(tree, vLeft, left, mid, index, value);
        } else {
            updateTreeIndex(tree, vRight, mid, right, index, value);
        }

        tree->sums[v] = tree->sums[vLeft] + tree->sums[vRight];
        tree->mins[v] = fmin(tree->mins[vLeft], tree->sums[vLeft] + tree->mins[vRight]);
    }
}

void updateVertex(SegmentTree *tree, int v, int vLeft, int vRight) {
    tree->sums[v] = tree->sums[vLeft] + tree->sums[vRight];
    tree->mins[v] = fmin(tree->mins[vLeft], tree->sums[vLeft] + tree->mins[vRight]);
}

void updateTree(SegmentTree *tree, Query *queries, int queryCount, IdMap *ids, int *times, int minTime, int maxTime) {
    for (int i = 0; i < queryCount; i++) {
        Query query = queries[i];
        int type = query.type;
        int time = query.arg1;
        int realTime = times[time];
        long speed;

        if (type == 1) {
            speed = query.arg2;

            int timeBefore = ids->values[time - 1].id;
            int realTimeBefore = times[timeBefore];
            long speedBefore = ids->values[time - 1].value;

            updateIndex(tree, timeBefore, speedBefore * (realTime - realTimeBefore));
            updateIndex(tree, time, speed * (times[time + 1] - realTime));
        } else if (type == 2) {
            int timeBefore = ids->values[time - 1].id;
            int realTimeBefore = times[timeBefore];
            long speedBefore = ids->values[time - 1].value;

            updateIndex(tree, timeBefore, speedBefore * (times[time + 1] - realTimeBefore));
            updateIndex(tree, time, 0);
        } else {
            int start = query.arg1;
            int end = query.arg2;
            long value = query.arg3;

            int foundIndex = -1;
            for (int j = start; j <= end; j++) {
                if (tree->sums[j] + tree->mins[j] <= value) {
                    foundIndex = j;
                    break;
                }
            }

            if (foundIndex == -1) {
                printf("-1\n");
            } else {
                value = tree->sums[foundIndex];

                int time = foundIndex;
                int realTime = times[time];
                long speed = ids->values[time].value;

                int timeAfter = fmin(end, ids->values[time + 1].id);
                int realTimeAfter = times[timeAfter];

                long delta = realTimeAfter - realTime;
                long total = delta * speed;

                if (value + total > 0) {
                    printf("-1\n");
                } else {
                    double badTime = realTime + (double)value / fabs(speed);
                    printf("%f\n", badTime);
                }
            }
        }
    }
}

void solve() {
    int q = readInt();
    Query *queries = (Query *)malloc(q * sizeof(Query));

    for (int i = 0; i < q; i++) {
        int type = readInt();
        if (type == 1) {
            queries[i].type = 1;
            queries[i].arg1 = readInt();
            queries[i].arg2 = readInt();
        } else if (type == 2) {
            queries[i].type = 2;
            queries[i].arg1 = readInt();
        } else {
            queries[i].type = 3;
            queries[i].arg1 = readInt();
            queries[i].arg2 = readInt();
            queries[i].arg3 = readInt();
        }
    }

    IdMap *mapper = (IdMap *)malloc(sizeof(IdMap));
    mapper->size = 0;
    mapper->values = (IdValue *)malloc((q + 2) * sizeof(IdValue));
    mapper->values[mapper->size].id = 0;
    mapper->values[mapper->size].value = 0;
    mapper->size++;

    for (int i = 0; i < q; i++) {
        Query query = queries[i];
        if (query.type == 1) {
            mapper->values[mapper->size].id = query.arg1;
            mapper->values[mapper->size].value = 0;
            mapper->size++;
        } else if (query.type == 3) {
            mapper->values[mapper->size].id = query.arg1;
            mapper->values[mapper->size].value = 0;
            mapper->size++;
            mapper->values[mapper->size].id = query.arg2;
            mapper->values[mapper->size].value = 0;
            mapper->size++;
        }
    }

    IdMap *ids = (IdMap *)malloc(sizeof(IdMap));
    ids->size = mapper->size;
    ids->values = (IdValue *)malloc(ids->size * sizeof(IdValue));

    for (int i = 0; i < ids->size; i++) {
        ids->values[i].id = mapper->values[i].id;
        ids->values[i].value = i;
    }

    int *times = (int *)malloc(ids->size * sizeof(int));
    for (int i = 0; i < ids->size; i++) {
        times[i] = ids->values[i].id;
    }

    int minTime = ids->values[0].id;
    int maxTime = ids->values[ids->size - 1].id;

    SegmentTree *tree = (SegmentTree *)malloc(sizeof(SegmentTree));
    tree->size = ids->size;
    tree->sums = (long *)malloc((4 * tree->size) * sizeof(long));
    tree->mins = (long *)malloc((4 * tree->size) * sizeof(long));

    for (int i = 0; i < tree->size; i++) {
        tree->sums[i] = 0;
        tree->mins[i] = 0;
    }

    updateIndex(tree, 0, 0);
    updateIndex(tree, tree->size - 1, 0);

    for (int i = 0; i < q; i++) {
        Query query = queries[i];
        int type = query.type;
        if (type == 1) {
            int time = query.arg1;
            int realTime = times[time];
            long speed = query.arg2;

            int timeBefore = ids->values[time - 1].id;
            int realTimeBefore = times[timeBefore];
            long speedBefore = ids->values[time - 1].value;

            updateIndex(tree, timeBefore, speedBefore * (realTime - realTimeBefore));
            updateIndex(tree, time, speed * (times[time + 1] - realTime));
        } else if (type == 2) {
            int time = query.arg1;
            int realTime = times[time];

            int timeBefore = ids->values[time - 1].id;
            int realTimeBefore = times[timeBefore];
            long speedBefore = ids->values[time - 1].value;

            updateIndex(tree, timeBefore, speedBefore * (times[time + 1] - realTimeBefore));
            updateIndex(tree, time, 0);
        } else {
            int start = query.arg1;
            int end = query.arg2;
            long value = query.arg3;

            int foundIndex = -1;
            for (int j = start; j <= end; j++) {
                if (tree->sums[j] + tree->mins[j] <= value) {
                    foundIndex = j;
                    break;
                }
            }

            if (foundIndex == -1) {
                printf("-1\n");
            } else {
                value = tree->sums[foundIndex];

                int time = foundIndex;
                int realTime = times[time];
                long speed = ids->values[time].value;

                int timeAfter = fmin(end, ids->values[time + 1].id);
                int realTimeAfter = times[timeAfter];

                long delta = realTimeAfter - realTime;
                long total = delta * speed;

                if (value + total > 0) {
                    printf("-1\n");
                } else {
                    double badTime = realTime + (double)value / fabs(speed);
                    printf("%f\n", badTime);
                }
            }
        }
    }

    free(queries);
    free(mapper->values);
    free(mapper);
    free(ids->values);
    free(ids);
    free(times);
    free(tree->sums);
    free(tree->mins);
    free(tree);
}

int main() {
    int q = readInt();
    for (int i = 0; i < q; i++) {
        solve();
    }
    return 0;
}
