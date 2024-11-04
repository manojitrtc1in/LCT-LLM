#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000
#define MAXM 100000
#define MOD 1000000007

typedef struct {
    int first;
    int second;
} Pair;

int l[MAXN];
Pair t[MAXM];

int check(int x, int m) {
    int now = x;
    long long c = 0;
    for (int i = 0; i < MAXN; i++) {
        c += l[i];
    }
    long long cur = 0;
    int last = 0;
    int ld[MAXM] = {0};

    for (int i = 0; i < m; i++) {
        if (t[i].first <= x) {
            ld[t[i].second] = i;
        }
    }

    for (int i = 0; i < m; i++) {
        if (ld[t[i].second] != i) {
            continue;
        }
        if (t[i].first > x) {
            break;
        }
        cur += t[i].first - last;
        int rt = cur < l[t[i].second - 1] ? cur : l[t[i].second - 1];
        cur -= rt;
        now -= rt;
        c -= rt;
        last = t[i].first;
    }
    return now >= 2 * c;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &t[i].first, &t[i].second);
    }

    // Sort the pairs
    qsort(t, m, sizeof(Pair), [](const void *a, const void *b) {
        return ((Pair *)a)->first - ((Pair *)b)->first;
    });

    int st = 1;
    int end = 2 * c;
    int ans = end;

    while (st <= end) {
        int mid = (st + end) / 2;
        if (check(mid, m)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
