#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288419716939937510

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int index;
    double angle;
} AngleIndex;

int compare(const void *a, const void *b) {
    AngleIndex *angleIndexA = (AngleIndex *)a;
    AngleIndex *angleIndexB = (AngleIndex *)b;
    if (angleIndexA->angle < angleIndexB->angle) {
        return -1;
    } else if (angleIndexA->angle > angleIndexB->angle) {
        return 1;
    } else {
        return 0;
    }
}

double getAngle(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return atan2(dy, dx);
}

void solve(int n, int *tree, Point *points) {
    int *subtreeSizes = (int *)malloc(n * sizeof(int));
    int *xyMapping = (int *)malloc(n * sizeof(int));
    AngleIndex *angleIndices = (AngleIndex *)malloc(n * sizeof(AngleIndex));

    for (int i = 0; i < n; i++) {
        subtreeSizes[i] = 0;
        xyMapping[i] = 0;
        angleIndices[i].index = i;
        angleIndices[i].angle = 0.0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        tree[u]++;
        tree[v]++;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    int root = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i] > tree[root]) {
            root = i;
        }
    }

    int *stack = (int *)malloc(n * sizeof(int));
    int stackSize = 0;
    stack[stackSize++] = root;

    while (stackSize > 0) {
        int node = stack[--stackSize];
        subtreeSizes[node] = 1;

        for (int i = 0; i < n; i++) {
            if (tree[i] == 1 && xyMapping[i] == 0) {
                angleIndices[i].angle = getAngle(points[node], points[i]);
                stack[stackSize++] = i;
            }
        }

        qsort(angleIndices, n, sizeof(AngleIndex), compare);

        int current = 0;
        for (int i = 0; i < n; i++) {
            if (tree[i] == 1 && xyMapping[i] == 0) {
                xyMapping[i] = angleIndices[current++].index + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", xyMapping[i]);
    }
    printf("\n");

    free(subtreeSizes);
    free(xyMapping);
    free(angleIndices);
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);

    int *tree = (int *)malloc(n * sizeof(int));
    Point *points = (Point *)malloc(n * sizeof(Point));

    for (int i = 0; i < n; i++) {
        tree[i] = 0;
    }

    solve(n, tree, points);

    free(tree);
    free(points);

    return 0;
}
