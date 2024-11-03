#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288419716939937510

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int u;
    int v;
} Edge;

typedef struct {
    int index;
    double angle;
} AngleIndex;

int compare(const void* a, const void* b) {
    AngleIndex* angleIndexA = (AngleIndex*)a;
    AngleIndex* angleIndexB = (AngleIndex*)b;
    if (angleIndexA->angle < angleIndexB->angle) {
        return -1;
    } else if (angleIndexA->angle > angleIndexB->angle) {
        return 1;
    } else {
        return 0;
    }
}

double getAngle(Point p1, Point p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}

void solve(int n, Edge* edges, Point* points) {
    int* subtreeSizes = (int*)malloc(n * sizeof(int));
    int* xyMapping = (int*)malloc(n * sizeof(int));
    AngleIndex* angleIndices = (AngleIndex*)malloc(n * sizeof(AngleIndex));

    // Calculate subtree sizes
    for (int i = 0; i < n; i++) {
        subtreeSizes[i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        subtreeSizes[u] += subtreeSizes[v];
    }

    // Sort points by angle
    for (int i = 0; i < n; i++) {
        angleIndices[i].index = i;
        angleIndices[i].angle = getAngle(points[i], points[0]);
    }
    qsort(angleIndices, n, sizeof(AngleIndex), compare);

    // Solve recursively
    int l = 0;
    int r = n - 1;
    int root = angleIndices[r].index;
    int parent = -1;
    xyMapping[root] = 1;
    while (l <= r) {
        int currXY = angleIndices[r].index;
        xyMapping[currXY] = root;
        qsort(angleIndices + l, r - l + 1, sizeof(AngleIndex), compare);
        int curL = l;
        for (int i = 0; i < n - 1; i++) {
            int currIndex = angleIndices[curL].index;
            int nextIndex = angleIndices[curL + subtreeSizes[currIndex] - 1].index;
            solve(subtreeSizes[currIndex], edges, points);
            curL += subtreeSizes[currIndex];
        }
        l = r + 1;
    }

    // Print xyMapping
    for (int i = 0; i < n; i++) {
        printf("%d ", xyMapping[i]);
    }
    printf("\n");

    free(subtreeSizes);
    free(xyMapping);
    free(angleIndices);
}

int main() {
    int n;
    scanf("%d", &n);

    Edge* edges = (Edge*)malloc((n - 1) * sizeof(Edge));
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    Point* points = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    solve(n, edges, points);

    free(edges);
    free(points);

    return 0;
}
