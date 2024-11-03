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
    double xDist = p2.x - p1.x;
    double yDist = p2.y - p1.y;
    return atan2(yDist, xDist);
}

void solve(int n, int *tree, Point *points, int *mapping) {
    int *subtreeSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subtreeSizes[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        int u = tree[i * 2 - 2];
        int v = tree[i * 2 - 1];
        subtreeSizes[u] += subtreeSizes[v];
    }

    AngleIndex *angleIndices = (AngleIndex *)malloc(n * sizeof(AngleIndex));
    for (int i = 0; i < n; i++) {
        angleIndices[i].index = i;
        angleIndices[i].angle = getAngle(points[i], points[0]);
    }

    qsort(angleIndices, n, sizeof(AngleIndex), compare);

    int currentIndex = 0;
    for (int i = 0; i < n; i++) {
        int currentPoint = angleIndices[i].index;
        mapping[currentPoint] = currentIndex;
        currentIndex++;

        int start = i + 1;
        while (start < n && angleIndices[start].angle < angleIndices[i].angle + PI) {
            angleIndices[start].angle += 2 * PI;
            start++;
        }

        qsort(angleIndices + i + 1, start - i - 1, sizeof(AngleIndex), compare);
        i = start - 1;
    }

    free(subtreeSizes);
    free(angleIndices);
}

int main() {
    int n;
    scanf("%d", &n);

    int *tree = (int *)malloc((n - 1) * 2 * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &tree[i * 2], &tree[i * 2 + 1]);
    }

    Point *points = (Point *)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    int *mapping = (int *)malloc(n * sizeof(int));

    solve(n, tree, points, mapping);

    for (int i = 0; i < n; i++) {
        printf("%d ", mapping[i] + 1);
    }
    printf("\n");

    free(tree);
    free(points);
    free(mapping);

    return 0;
}
