#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    long long x, y;
} pll;

typedef struct {
    pll point;
    int index;
} point_index;

int cmp(const void *a, const void *b) {
    pll *p1 = (pll *)a;
    pll *p2 = (pll *)b;
    if (p1->x != p2->x) return (p1->x > p2->x) ? 1 : -1;
    return (p1->y > p2->y) ? 1 : -1;
}

int cross_product(pll a, pll b) {
    return a.x * b.y - a.y * b.x;
}

void take(int k, point_index *perm, point_index *points, int *points_size) {
    int n = *points_size;
    for (int i = 0; i < n; ++i) {
        if (points[i].index == k) {
            points[i] = points[n - 1];
            (*points_size)--;
            break;
        }
    }
    perm[n - 1] = points[n - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    point_index *p = malloc(n * sizeof(point_index));
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &p[i].point.x, &p[i].point.y);
        p[i].index = i;
    }
    char s[n - 1];
    scanf("%s", s);
    
    point_index *perm = malloc(n * sizeof(point_index));
    int first_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (cmp(&p[i].point, &p[first_idx].point) < 0) {
            first_idx = i;
        }
    }
    take(first_idx, perm, p, &n);
    
    for (int i = 0; i < n - 2; ++i) {
        pll q = perm[n - 1].point;
        int best = 0;
        for (int j = 1; j < n; ++j) {
            if (cross_product((pll){p[best].point.x - q.x, p[best].point.y - q.y}, 
                               (pll){p[j].point.x - q.x, p[j].point.y - q.y}) > 0 == (s[i] == 'R')) {
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
    free(perm);
    return 0;
}
