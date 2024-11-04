#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef long long li;
typedef struct {
    li x;
    int y;
} pt;

#define N (100 * 1000 + 13)
#define INF (int)(1e9)
#define INF64 (li)(1e18)
#define MOD (INF + 7)
#define EPS (1e-9)
#define PI (acos(-1.0))

int n, m, k;
li h;
pt a[N];

bool read() {
    if (scanf("%lld%d%d%d", &h, &n, &m, &k) != 4)
        return false;
    for (int i = 0; i < n; i++)
        scanf("%lld%d", &a[i].x, &a[i].y);
    return true;
}

bool used[N];
li mn[N];
pt cur[N];
int cur_size = 0;

void add(li x) {
    int q[N], front = 0, back = 0;
    for (int i = 0; i < k; i++) q[back++] = i;
    while (front < back) {
        int v = q[front++];
        if (mn[v] + x < mn[(v + x) % k]) {
            mn[(v + x) % k] = mn[v] + x;
            q[back++] = (v + x) % k;
        }
    }
}

void recalc() {
    cur_size = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && mn[a[i].x % k] <= a[i].x) {
            cur[cur_size++] = (pt){a[i].y, -i};
        }
    }
    // Sort cur in descending order based on y
    for (int i = 0; i < cur_size - 1; i++) {
        for (int j = i + 1; j < cur_size; j++) {
            if (cur[i].y < cur[j].y) {
                pt temp = cur[i];
                cur[i] = cur[j];
                cur[j] = temp;
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
                    if (cur[j].y == -x) {
                        cur[j] = cur[--cur_size];
                        break;
                    }
                }
            }
            a[x].y -= y;
            if (mn[a[x].x % k] <= a[x].x) {
                cur[cur_size++] = (pt){a[x].y, -x};
            }
        } else if (cur_size > 0) {
            printf("%d\n", cur[0].y);
            used[-cur[0].y] = true;
            cur[0] = cur[--cur_size];
        } else {
            puts("0");
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int tt = clock();
    while (read()) {
        solve();
        fprintf(stderr, "TIME = %d\n", clock() - tt);
        tt = clock();
    }
    return 0;
}
