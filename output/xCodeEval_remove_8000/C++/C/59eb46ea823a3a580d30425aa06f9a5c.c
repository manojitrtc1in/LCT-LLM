#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long x;
    long long y;
} Point;

typedef struct {
    Point point;
    int index;
} PointIndex;

int comparePoints(const void* a, const void* b) {
    PointIndex* p1 = (PointIndex*)a;
    PointIndex* p2 = (PointIndex*)b;
    if (p1->point.x != p2->point.x) {
        return p1->point.x - p2->point.x;
    }
    return p1->point.y - p2->point.y;
}

int main() {
    int n;
    scanf("%d", &n);
    PointIndex* points = (PointIndex*)malloc(n * sizeof(PointIndex));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &points[i].point.x);
        points[i].index = i;
    }
    char* s = (char*)malloc((n - 1) * sizeof(char));
    scanf("%s", s);

    PointIndex* perm = (PointIndex*)malloc(n * sizeof(PointIndex));
    int firstIdx = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].point.x < points[firstIdx].point.x) {
            firstIdx = i;
        }
    }
    perm[0] = points[firstIdx];
    int permSize = 1;

    for (int i = 0; i < n - 2; i++) {
        Point q = perm[permSize - 1].point;
        int best = 0;
        for (int j = 1; j < n; j++) {
            if ((((points[best].point.x - q.x) * (points[j].point.y - q.y)) - ((points[best].point.y - q.y) * (points[j].point.x - q.x))) > 0 == (s[i] == 'R')) {
                best = j;
            }
        }
        perm[permSize] = points[best];
        permSize++;
        points[best] = points[n - 1 - i];
    }

    perm[permSize] = points[0];
    permSize++;
    perm[permSize] = points[1];

    qsort(perm, permSize, sizeof(PointIndex), comparePoints);

    for (int i = 0; i < permSize; i++) {
        printf("%d ", perm[i].index + 1);
    }
    printf("\n");

    free(points);
    free(s);
    free(perm);

    return 0;
}
