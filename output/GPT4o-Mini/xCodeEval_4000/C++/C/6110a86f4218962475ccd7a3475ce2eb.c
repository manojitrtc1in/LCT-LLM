#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define N (100 * 1000 + 13)

typedef long long li;

li h;
int n, m, k;
struct {
    li x;
    int y;
} a[N];

bool read() {
    if (scanf("%lld%d%d%d", &h, &n, &m, &k) != 4)
        return false;
    for (int i = 0; i < n; i++)
        scanf("%lld%d", &a[i].x, &a[i].y);
    return true;
}

bool used[N];
li mn[N];
struct {
    int y;
    int index;
} cur[N];
int cur_size = 0;

void add(li x) {
    li new_mn[N];
    memcpy(new_mn, mn, sizeof(mn));
    for (int i = 0; i < k; i++) {
        if (mn[i] + x < new_mn[(i + x) % k]) {
            new_mn[(i + x) % k] = mn[i] + x;
        }
    }
    memcpy(mn, new_mn, sizeof(mn));
}

void recalc() {
    cur_size = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && mn[a[i].x % k] <= a[i].x) {
            cur[cur_size++] = (struct {int y; int index;}){a[i].y, -i};
        }
    }
    // Sort cur in descending order based on y
    for (int i = 0; i < cur_size - 1; i++) {
        for (int j = 0; j < cur_size - i - 1; j++) {
            if (cur[j].y < cur[j + 1].y) {
                struct {int y; int index;} temp = cur[j];
                cur[j] = cur[j + 1];
                cur[j + 1] = temp;
            }
        }
    }
}

void solve() {
    for (int i = 0; i < k; i++)
        mn[i] = h + 1;
    mn[1] = 1;
    memset(used, 0, sizeof(used));
    recalc();
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            li x;
            scanf("%lld", &x);
            add(x);
            recalc();
        } else if (t == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x;
            if (mn[a[x].x % k] <= a[x].x) {
                for (int j = 0; j < cur_size; j++) {
                    if (cur[j].index == -x) {
                        cur[j] = cur[--cur_size];
                        break;
                    }
                }
            }
            a[x].y -= y;
            if (mn[a[x].x % k] <= a[x].x) {
                cur[cur_size++] = (struct {int y; int index;}){a[x].y, -x};
            }
        } else if (cur_size > 0) {
            printf("%d\n", cur[0].y);
            used[-cur[0].index] = true;
            cur[0] = cur[--cur_size];
            recalc();
        } else {
            puts("0");
        }
    }
}

int main() {
    while (read()) {
        solve();
    }
}
