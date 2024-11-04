#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

struct Point {
    int x, y;
};

struct Point p[10101];
struct Point a[10101];
bool used[101010];

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
    char s[10101];
    scanf("%s", s);
    int len = strlen(s);
    s[len] = 'R';
    s[len + 1] = '\0';
    int ans[10101];
    int ans_idx = 0;
    ans[ans_idx++] = cur;
    for (int i = 0; i + 1 < n; ++i) {
        used[cur] = true;
        struct Point zero = p[cur];
        for (int j = 0; j < n; ++j) {
            a[j].x = p[j].x - zero.x;
            a[j].y = p[j].y - zero.y;
        }
        int idx = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                if (idx == -1) idx = j;
                else {
                    if (s[i] == 'R' && a[j].x * (ll)a[idx].y < a[idx].x * (ll)a[j].y) idx = j;
                    if (s[i] == 'L' && a[idx].x * (ll)a[j].y < a[j].x * (ll)a[idx].y) idx = j;
                }
            }
        }
        cur = idx;
        ans[ans_idx++] = cur;
    }
    for (int i = 0; i < ans_idx; ++i) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");

    return 0;
}

int main() {
    return solve();
}
