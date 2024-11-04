#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100005

int n, m;
int l[MAXN];
int t[MAXN][2];

int cmp(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    if (x[0] != y[0]) {
        return x[0] - y[0];
    }
    return x[1] - y[1];
}

bool check(int x) {
    int now = x;
    int c = 0;
    int cur = 0;
    int last = 0;
    int ld[MAXN] = {0};
    for (int i = 0; i < m; i++) {
        if (t[i][0] <= x) {
            ld[t[i][1]] = i;
        }
    }
    for (int i = 0; i < m; i++) {
        if (ld[t[i][1]] != i) {
            continue;
        }
        if (t[i][0] > x) {
            break;
        }
        cur += t[i][0] - last;
        int rt = (cur < l[t[i][1] - 1]) ? cur : l[t[i][1] - 1];
        cur -= rt;
        now -= rt;
        c -= rt;
        last = t[i][0];
    }
    if (now >= 2 * c) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &t[i][0], &t[i][1]);
    }
    qsort(t, m, sizeof(t[0]), cmp);
    int st = 1;
    int end = 2 * n;
    int ans = end;
    while (st <= end) {
        int mid = (st + end) / 2;
        if (check(mid) == true) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
