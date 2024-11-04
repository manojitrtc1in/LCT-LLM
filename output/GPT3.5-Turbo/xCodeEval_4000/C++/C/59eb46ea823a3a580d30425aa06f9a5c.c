#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        return (p1->point.x < p2->point.x) ? -1 : 1;
    }
    return (p1->point.y < p2->point.y) ? -1 : 1;
}

bool isRightTurn(Point p1, Point p2, Point p3) {
    long long crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return crossProduct > 0;
}

void take(int k, PointIndex** perm, PointIndex** points, int* permSize, int* pointsSize) {
    int n = *pointsSize;
    for (int i = 0; i < n; i++) {
        if (points[i]->index == k) {
            PointIndex* temp = points[i];
            points[i] = points[n - 1];
            points[n - 1] = temp;
            break;
        }
    }
    (*perm)[*permSize] = *points[n - 1];
    (*permSize)++;
    (*pointsSize)--;
}

int main() {
    int n;
    scanf("%d", &n);
    PointIndex* p = (PointIndex*)malloc(n * sizeof(PointIndex));
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &(p[i].point.x), &(p[i].point.y));
        p[i].index = i;
    }
    char s[n - 1];
    scanf("%s", s);
    PointIndex* perm = (PointIndex*)malloc(n * sizeof(PointIndex));
    int permSize = 0;
    int firstIdx = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].point.x < p[firstIdx].point.x || (p[i].point.x == p[firstIdx].point.x && p[i].point.y < p[firstIdx].point.y)) {
            firstIdx = i;
        }
    }
    take(firstIdx, &perm, &p, &permSize, &n);
    for (int i = 0; i < n - 2; i++) {
        Point q = perm[permSize - 1].point;
        int best = 0;
        for (int j = 1; j < n; j++) {
            if (isRightTurn(p[best].point, q, p[j].point) == (s[i] == 'R')) {
                best = j;
            }
        }
        take(p[best].index, &perm, &p, &permSize, &n);
    }
    take(p[0].index, &perm, &p, &permSize, &n);
    for (int i = 0; i < permSize; i++) {
        printf("%d ", perm[i].index + 1);
    }
    printf("\n");
    free(p);
    free(perm);
    return 0;
}
