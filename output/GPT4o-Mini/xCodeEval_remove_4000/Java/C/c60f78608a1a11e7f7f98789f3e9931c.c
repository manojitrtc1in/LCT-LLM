#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BIG 1000000007

typedef struct Point {
    int index;
    int x;
    int y;
} Point;

typedef struct Edge {
    Point *vertex0;
    Point *vertex1;
    bool bidirectional;
} Edge;

typedef struct Set {
    Point *points;
    int size;
    int capacity;
} Set;

Set* createSet(int capacity) {
    Set *set = (Set *)malloc(sizeof(Set));
    set->points = (Point *)malloc(capacity * sizeof(Point));
    set->size = 0;
    set->capacity = capacity;
    return set;
}

void addPoint(Set *set, Point point) {
    if (set->size >= set->capacity) {
        set->capacity *= 2;
        set->points = (Point *)realloc(set->points, set->capacity * sizeof(Point));
    }
    set->points[set->size++] = point;
}

int countLines(Set *points) {
    Set *xs = createSet(points->size);
    Set *ys = createSet(points->size);
    for (int i = 0; i < points->size; i++) {
        addPoint(xs, points->points[i]);
        addPoint(ys, points->points[i]);
    }
    int result = xs->size + ys->size;
    free(xs->points);
    free(xs);
    free(ys->points);
    free(ys);
    return result;
}

long modMultiply(long a, long b) {
    return (a * b) % BIG;
}

long modAdd(long a, long b) {
    return (a + b) % BIG;
}

long modSubtract(long a, long b) {
    return (a - b + BIG) % BIG;
}

long id12(int a) {
    long result = 1;
    for (int index = 0; index < a; index++) {
        result = modMultiply(result, 2);
    }
    return result;
}

void solve() {
    int n;
    scanf("%d", &n);
    Set *points = createSet(n);
    for (int index = 0; index < n; index++) {
        Point point;
        scanf("%d %d", &point.x, &point.y);
        point.index = index;
        addPoint(points, point);
    }

    // Additional logic for edges and processing would go here...

