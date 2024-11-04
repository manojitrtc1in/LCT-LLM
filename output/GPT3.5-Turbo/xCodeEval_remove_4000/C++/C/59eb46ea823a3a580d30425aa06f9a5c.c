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

int compare(const void* a, const void* b) {
    PointIndex* p1 = (PointIndex*)a;
    PointIndex* p2 = (PointIndex*)b;
    if (p1->point.x < p2->point.x) {
        return -1;
    } else if (p1->point.x > p2->point.x) {
        return 1;
    } else {
        if (p1->point.y < p2->point.y) {
            return -1;
        } else if (p1->point.y > p2->point.y) {
            return 1;
        } else {
            return 0;
        }
    }
}

void take(int k, PointIndex* perm, PointIndex* points, int* numPoints) {
    int n = *numPoints;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (points[i].index == k) {
            PointIndex temp = points[i];
            points[i] = points[n - 1];
            points[n - 1] = temp;
            break;
        }
    }
    perm[*numPoints - 1] = points[*numPoints - 1];
    (*numPoints)--;
}

int main() {
    int n;
    scanf("%d", &n);
    PointIndex* p = (PointIndex*)malloc(n * sizeof(PointIndex));
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &p[i].point.x, &p[i].point.y);
        p[i].index = i;
    }
    char* s = (char*)malloc((n - 1) * sizeof(char));
    scanf("%s", s);
    PointIndex* perm = (PointIndex*)malloc(n * sizeof(PointIndex));
    int first_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].point.x < p[first_idx].point.x || (p[i].point.x == p[first_idx].point.x && p[i].point.y < p[first_idx].point.y)) {
            first_idx = i;
        }
    }
    take(first_idx, perm, p, &n);
    for (int i = 0; i < n - 2; ++i) {
        Point q = perm[n - 2].point;
        int best = 0;
        for (int j = 1; j < n; ++j) {
            if ((((p[best].point.x - q.x) * (p[j].point.y - q.y) - (p[best].point.y - q.y) * (p[j].point.x - q.x)) > 0) == (s[i] == 'R')) {
                best = j;
            }
        }
        take(p[best].index, perm, p, &n);
    }
    take(p[0].index, perm, p, &n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", perm[i].index + 1);
    }
    printf("\n");

    free(p);
    free(s);
    free(perm);

    return 0;
}
