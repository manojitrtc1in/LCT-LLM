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
    int* values;
    int size;
} IdMap;

typedef struct {
    int* sums;
    int* mins;
    int size;
    int index;
    int value;
} SegmentTree;

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

void updateIndex(SegmentTree* tree, int index, int value) {
    tree->index = index;
    tree->value = value;
    id26(tree, 1, 0, tree->size);
}

void id26(SegmentTree* tree, int v, int left, int right) {
    if (left + 1 == right) {
        tree->sums[v] = tree->value;
        tree->mins[v] = fmin(0, tree->value);
    } else {
        int mid = (left + right) / 2;
        int vLeft = v * 2;
        int vRight = vLeft + 1;

        if (tree->index < mid) {
            id26(tree, vLeft, left, mid);
        } else {
            id26(tree, vRight, mid, right);
        }

        updateVertex(tree, v, vLeft, vRight);
    }
}

void updateVertex(SegmentTree* tree, int v, int vLeft, int vRight) {
    tree->sums[v] = tree->sums[vLeft] + tree->sums[vRight];
    tree->mins[v] = fmin(tree->mins[vLeft], tree->sums[vLeft] + tree->mins[vRight]);
}

int getInterval(SegmentTree* tree, int start, int end, int value) {
    tree->start = start;
    tree->end = end;
    tree->value = value;
    tree->found = false;
    tree->foundIndex = -1;

    id12(tree, 1, 0, tree->size);

    return tree->foundIndex;
}

void id12(SegmentTree* tree, int v, int left, int right) {
    if (tree->start <= left && right <= tree->end) {
        if (!tree->found) {
            if (tree->value + tree->mins[v] <= 0) {
                id19(tree, v, left, right);
                tree->found = true;
            } else {
                tree->value += tree->sums[v];
            }
        }
    } else {
        int mid = (left + right) / 2;
        int vLeft = v * 2;
        int vRight = vLeft + 1;

        if (tree->start < mid) {
            id12(tree, vLeft, left, mid);
        }
        if (mid < tree->end) {
            id12(tree, vRight, mid, right);
        }
    }
}

void id19(SegmentTree* tree, int v, int left, int right) {
    if (left + 1 == right) {
        tree->foundIndex = left;
    } else {
        int mid = (left + right) / 2;
        int vLeft = v * 2;
        int vRight = vLeft + 1;

        if (tree->value + tree->mins[vLeft] <= 0) {
            id19(tree, vLeft, left, mid);
        } else {
            tree->value += tree->sums[vLeft];
            id19(tree, vRight, mid, right);
        }
    }
}

IdMap* createIdMap() {
    IdMap* map = malloc(sizeof(IdMap));
    map->values = malloc(sizeof(int));
    map->size = 0;
    return map;
}

void addValue(IdMap* map, int value) {
    map->values = realloc(map->values, (map->size + 1) * sizeof(int));
    map->values[map->size] = value;
    map->size++;
}

int getId(IdMap* map, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->values[i] == value) {
            return i;
        }
    }
    return -1;
}

IdMap* build(IdMap* map) {
    for (int i = 0; i < map->size; i++) {
        for (int j = i + 1; j < map->size; j++) {
            if (map->values[i] > map->values[j]) {
                int temp = map->values[i];
                map->values[i] = map->values[j];
                map->values[j] = temp;
            }
        }
    }
    return map;
}

SegmentTree* createSegmentTree(int n) {
    SegmentTree* tree = malloc(sizeof(SegmentTree));
    tree->sums = malloc(4 * n * sizeof(int));
    tree->mins = malloc(4 * n * sizeof(int));
    tree->size = n;
    return tree;
}

void solve() {
    int MAX_T = 1000000000;

    int q = readInt();
    Query* queries = malloc(q * sizeof(Query));
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

    IdMap* mapper = createIdMap();
    addValue(mapper, 0);
    addValue(mapper, MAX_T + 1);

    for (int i = 0; i < q; i++) {
        Query query = queries[i];
        addValue(mapper, query.arg1);
        if (query.type == 3) {
            addValue(mapper, query.arg2);
        }
    }

    mapper = build(mapper);
    int* times = mapper->values;
    int minTime = getId(mapper, 0);
    int maxTime = getId(mapper, MAX_T + 1);

    int* id33 = malloc((maxTime + 1) * sizeof(int));
    id33[minTime] = 0;
    id33[maxTime] = 0;

    for (int i = 0; i < q; i++) {
        Query query = queries[i];
        query.arg1 = getId(mapper, query.arg1);
        if (query.type == 3) {
            query.arg2 = getId(mapper, query.arg2);
        }
    }

    SegmentTree* tree = createSegmentTree(mapper->size);

    for (int i = 0; i < q; i++) {
        Query query = queries[i];
        int type = query.type;
        if (type == 1) {
            int time = query.arg1;
            int realTime = times[time];
            int speed = query.arg2;

            int timeAfter = times[id33[time + 1]];
            int timeBefore = times[id33[time - 1]];
            int speedBefore = id33[time - 1];

            updateIndex(tree, timeBefore, speedBefore * (realTime - timeBefore));
            updateIndex(tree, time, speed * (timeAfter - realTime));

            id33[time] = speed;
        } else if (type == 2) {
            int time = query.arg1;
            int realTime = times[time];

            int timeAfter = times[id33[time + 1]];
            int timeBefore = times[id33[time - 1]];
            int speedBefore = id33[time - 1];

            updateIndex(tree, timeBefore, speedBefore * (timeAfter - timeBefore));
            updateIndex(tree, time, 0);

            id33[time] = 0;
        } else {
            int start = query.arg1;
            int end = query.arg2;
            int value = query.arg3;

            int foundIndex = getInterval(tree, start, end, value);
            if (foundIndex == -1) {
                printf("-1\n");
            } else {
                value = tree->value;

                int time = foundIndex;
                int realTime = times[time];

                if (value == 0) {
                    printf("%d\n", realTime);
                } else {
                    int speed = id33[time];

                    int timeAfter = fmin(end, id33[time + 1]);
                    int delta = timeAfter - realTime;
                    int total = delta * speed;

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
}

int main() {
    solve();
    return 0;
}
