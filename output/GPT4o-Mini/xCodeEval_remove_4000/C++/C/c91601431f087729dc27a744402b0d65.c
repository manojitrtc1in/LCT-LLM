#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_POINTS 10101
#define MAX_USED 101010

typedef struct {
    int x, y;
} Point;

Point p[MAX_POINTS];
Point a[MAX_POINTS];
bool used[MAX_USED];

int comparePoints(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x * (long long)p2->y < p1->y * (long long)p2->x) ? -1 : 1;
}

int solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].x < p[cur].x || (p[i].x == p[cur].x && p[i].y < p[cur].y)) {
            cur = i;
        }
    }

    char s[MAX_POINTS];
    scanf("%s", s);
    strcat(s, "R");
    int ans[MAX_POINTS];
    ans[0] = cur;

    for (int i = 0; i + 1 < n; ++i) {
        used[cur] = true;
        Point zero = p[cur];
        for (int j = 0; j < n; ++j) {
            a[j].x = p[j].x - zero.x;
            a[j].y = p[j].y - zero.y;
        }

        int idx = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                if (idx == -1) idx = j;
                else {
                    if (s[i] == 'R' && comparePoints(&a[j], &a[idx]) < 0) idx = j;
                    if (s[i] == 'L' && comparePoints(&a[idx], &a[j]) < 0) idx = j;
                }
            }
        }
        cur = idx;
        ans[i + 1] = cur;
    }

    for (int j = 0; j < n; ++j) {
        printf("%d ", ans[j] + 1);
    }
    printf("\n");

    return 0;
}

int main() {
    solve();
    return 0;
}
