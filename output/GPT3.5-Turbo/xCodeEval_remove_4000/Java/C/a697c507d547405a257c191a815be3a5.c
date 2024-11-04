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
    int size;
    int* values;
} IdMap;

typedef struct {
    int size;
    long* sums;
    long* mins;
} SegmentTree;

int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

void updateIndex(SegmentTree* tree, int index, long value) {
    tree->sums[index] = value;
    tree->mins[index] = fmin(0, value);
}

void updateVertex(SegmentTree* tree, int v, int vLeft, int vRight) {
    tree->sums[v] = tree->sums[vLeft] + tree->sums[vRight];
    tree->mins[v] = fmin(tree->mins[vLeft], tree->sums[vLeft] + tree->mins[vRight]);
}

void id26(SegmentTree* tree, int v, int left, int right, int index, long value) {
    if (left + 1 == right) {
        updateIndex(tree, v, value);
    } else {
        int mid = (left + right) / 2;
        int vLeft = (v << 1);
        int vRight = vLeft + 1;

        if (index < mid) {
            id26(tree, vLeft, left, mid, index, value);
        } else {
            id26(tree, vRight, mid, right, index, value);
        }

        updateVertex(tree, v, vLeft, vRight);
    }
}

void getInterval(SegmentTree* tree, int v, int left, int right, int start, int end, long value, bool* found, int* foundIndex) {
    if (start <= left && right <= end) {
        if (!(*found)) {
            if (value + tree->mins[v] <= 0) {
                *found = true;
                *foundIndex = v;
            } else {
                value += tree->sums[v];
            }
        }
    } else {
        int mid = (left + right) / 2;
        int vLeft = (v << 1);
        int vRight = vLeft + 1;

        if (start < mid) {
            getInterval(tree, vLeft, left, mid, start, end, value, found, foundIndex);
        }
        if (mid < end) {
            getInterval(tree, vRight, mid, right, start, end, value, found, foundIndex);
        }
    }
}

void solve() {
    int q = readInt();
    Query* queries = (Query*)malloc(q * sizeof(Query));

    for (int i = 0; i < q; ++i) {
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

    IdMap mapper;
    mapper.size = 0;
    mapper.values = (int*)malloc((q + 2) * sizeof(int));
    mapper.values[mapper.size++] = 0;
    mapper.values[mapper.size++] = MAX_T + 1;

    for (int i = 0; i < q; ++i) {
        int type = queries[i].type;
        if (type == 1) {
            mapper.values[mapper.size++] = queries[i].arg1;
        } else if (type == 2) {
            mapper.values[mapper.size++] = queries[i].arg1;
        } else {
            mapper.values[mapper.size++] = queries[i].arg1;
            mapper.values[mapper.size++] = queries[i].arg2;
        }
    }

    int* times = (int*)malloc(mapper.size * sizeof(int));
    for (int i = 0; i < mapper.size; ++i) {
        times[i] = mapper.values[i];
    }

    int minTime = 0, maxTime = mapper.size - 1;

    int* id33 = (int*)malloc((maxTime + 1) * sizeof(int));
    id33[minTime] = 0;
    id33[maxTime] = 0;

    for (int i = 0; i < q; ++i) {
        int type = queries[i].type;
        if (type == 1) {
            queries[i].arg1 = mapper.size - 1;
        } else if (type == 2) {
            queries[i].arg1 = mapper.size - 1;
        } else {
            queries[i].arg1 = mapper.size - 1;
            queries[i].arg2 = mapper.size - 1;
        }
    }

    SegmentTree tree;
    tree.size = mapper.size;
    tree.sums = (long*)malloc((tree.size * 4) * sizeof(long));
    tree.mins = (long*)malloc((tree.size * 4) * sizeof(long));

    for (int i = 0; i < q; ++i) {
        int type = queries[i].type;
        if (type == 1) {
            int time = queries[i].arg1;
            int realTime = times[time];
            long speed = queries[i].arg2;

            int timeAfter = time + 1;
            int id10 = times[timeAfter];

            int timeBefore = time - 1;
            int id38 = times[timeBefore];
            long speedBefore = id33[timeBefore];

            updateIndex(&tree, timeBefore, speedBefore * (realTime - id38));
            updateIndex(&tree, time, speed * (id10 - realTime));

            id33[time] = speed;
        } else if (type == 2) {
            int time = queries[i].arg1;
            int realTime = times[time];

            int timeAfter = time + 1;
            int id10 = times[timeAfter];

            int timeBefore = time - 1;
            int id38 = times[timeBefore];

            long speedBefore = id33[timeBefore];

            updateIndex(&tree, timeBefore, speedBefore * (id10 - id38));
            updateIndex(&tree, time, 0);

            id33[time] = 0;
        } else {
            int start = queries[i].arg1, end = queries[i].arg2;
            long value = queries[i].arg3;

            if (value == 0) {
                printf("%d\n", times[start]);
                continue;
            }

            bool found = false;
            int foundIndex = -1;
            getInterval(&tree, 1, minTime, maxTime, start, end, value, &found, &foundIndex);
            if (foundIndex == -1) {
                printf("-1\n");
            } else {
                value = tree.sums[foundIndex];

                int time = foundIndex;
                int realTime = times[time];

                if (value == 0) {
                    printf("%d\n", realTime);
                } else {
                    long speed = id33[time];

                    int timeAfter = fmin(end, time + 1);
                    int id10 = times[timeAfter];

                    long delta = id10 - realTime;
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

    free(queries);
    free(mapper.values);
    free(times);
    free(id33);
    free(tree.sums);
    free(tree.mins);
}

int main() {
    solve();
    return 0;
}
