#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

typedef struct {
    ll x;
    ll y;
} pll;

typedef struct {
    pll point;
    int index;
} PointIndexPair;

int comparePairs(const void* a, const void* b) {
    PointIndexPair* pairA = (PointIndexPair*)a;
    PointIndexPair* pairB = (PointIndexPair*)b;
    if (pairA->point.x < pairB->point.x) {
        return -1;
    } else if (pairA->point.x > pairB->point.x) {
        return 1;
    } else {
        if (pairA->point.y < pairB->point.y) {
            return -1;
        } else if (pairA->point.y > pairB->point.y) {
            return 1;
        } else {
            return 0;
        }
    }
}

void take(int k, PointIndexPair* perm, PointIndexPair* points, int* numPoints) {
    int n = *numPoints;
    for (int i = 0; i < n; i++) {
        if (points[i].index == k) {
            PointIndexPair temp = points[i];
            points[i] = points[n - 1];
            points[n - 1] = temp;
            (*numPoints)--;
            break;
        }
    }
    perm[*numPoints] = points[n - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    PointIndexPair* p = (PointIndexPair*)malloc(n * sizeof(PointIndexPair));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i].point.x);
        scanf("%lld", &p[i].point.y);
        p[i].index = i;
    }
    char* s = (char*)malloc((n - 1) * sizeof(char));
    scanf("%s", s);
    PointIndexPair* perm = (PointIndexPair*)malloc(n * sizeof(PointIndexPair));
    int firstIdx = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].point.x < p[firstIdx].point.x || (p[i].point.x == p[firstIdx].point.x && p[i].point.y < p[firstIdx].point.y)) {
            firstIdx = i;
        }
    }
    take(firstIdx, perm, p, &n);
    for (int i = 0; i < n - 2; i++) {
        pll q = perm[n - 1].point;
        int best = 0;
        for (int j = 1; j < n; j++) {
            if ((((p[best].point.x - q.x) * (p[j].point.y - q.y)) - ((p[best].point.y - q.y) * (p[j].point.x - q.x))) > 0 == (s[i] == 'R')) {
                best = j;
            }
        }
        take(p[best].index, perm, p, &n);
    }
    take(p[0].index, perm, p, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].index + 1);
    }
    printf("\n");
    free(p);
    free(s);
    free(perm);
    return 0;
}
