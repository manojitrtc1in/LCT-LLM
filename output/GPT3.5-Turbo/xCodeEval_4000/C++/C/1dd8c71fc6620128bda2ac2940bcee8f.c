#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAXN 600006
#define N 500005

typedef long long ll;

ll cnt[MAXN];
ll l[MAXN], r[MAXN];

typedef struct {
    ll* fw;
    int size;
} Fenwick;

Fenwick create_fenwick(int n) {
    Fenwick fw;
    fw.fw = (ll*)malloc((n + 1) * sizeof(ll));
    memset(fw.fw, 0, (n + 1) * sizeof(ll));
    fw.size = n;
    return fw;
}

void update(Fenwick* fw, int i, ll d) {
    while (i < fw->size) {
        if (fw->fw[i] < d) {
            fw->fw[i] = d;
        }
        i |= (i + 1);
    }
}

ll get(Fenwick* fw, int n) {
    ll result = 0;
    while (n >= 0) {
        if (fw->fw[n] > result) {
            result = fw->fw[n];
        }
        n = (n & (n + 1)) - 1;
    }
    return result;
}

ll get_range(Fenwick* fw, int l, int r) {
    return get(fw, r) - get(fw, l - 1);
}

void solution() {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        cnt[l]++;
        cnt[r + 1]--;
    }

    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }

    Fenwick fw_l = create_fenwick(100001);
    for (int i = 1; i <= m; i++) {
        l[i] = get_range(&fw_l, 0, cnt[i]) + 1;
        update(&fw_l, cnt[i], l[i]);
    }

    Fenwick fw_r = create_fenwick(100001);
    for (int i = m; i >= 1; i--) {
        r[i] = get_range(&fw_r, 0, cnt[i]) + 1;
        update(&fw_r, cnt[i], r[i]);
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (l[i] + r[i] - 1 > ans) {
            ans = l[i] + r[i] - 1;
        }
    }

    printf("%d\n", ans);
}

int main() {
    srand(time(0));

    int queries = 1;

    for (int test_case = 1; test_case <= queries; test_case++) {
        solution();
    }

    return 0;
}
