#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_POINTS 10101

typedef struct {
    int x, y;
} Point;

Point p[MAX_POINTS];
Point a[MAX_POINTS];
bool used[MAX_POINTS];

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
    s[n] = 'R'; // Append 'R' to the string
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
                if (idx == -1) {
                    idx = j;
                } else {
                    if (s[i] == 'R' && (a[j].x * (long long)a[idx].y < a[idx].x * (long long)a[j].y)) {
                        idx = j;
                    }
                    if (s[i] == 'L' && (a[idx].x * (long long)a[j].y < a[j].x * (long long)a[idx].y)) {
                        idx = j;
                    }
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
    return solve();
}
