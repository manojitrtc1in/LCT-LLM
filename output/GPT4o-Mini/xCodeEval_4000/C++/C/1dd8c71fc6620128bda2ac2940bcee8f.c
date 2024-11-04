#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 6000006
#define MOD 1000000007
#define INF 9000000000

long long cnt[MAXN];

typedef struct {
    long long *fw;
    int size;
} Fenwick;

void fenwick_init(Fenwick *f, int n) {
    f->size = n + 1;
    f->fw = (long long *)calloc(f->size, sizeof(long long));
}

void fenwick_update(Fenwick *f, int i, long long d) {
    while (i < f->size) {
        if (f->fw[i] < d) f->fw[i] = d;
        i = (i | (i + 1));
    }
}

long long fenwick_get(Fenwick *f, int n) {
    long long result = 0;
    while (n >= 0) {
        if (result < f->fw[n]) result = f->fw[n];
        n = (n & (n + 1)) - 1;
    }
    return result;
}

long long fenwick_get_range(Fenwick *f, int l, int r) {
    return fenwick_get(f, r) - fenwick_get(f, l - 1);
}

void solution(int n, int m) {
    long long l[MAXN], r[MAXN];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 1; i <= n; i++) {
        int left, right;
        scanf("%d %d", &left, &right);
        cnt[left]++;
        cnt[right + 1]--;
    }

    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }

    Fenwick fw_l, fw_r;
    fenwick_init(&fw_l, 100001);
    for (int i = 1; i <= m; i++) {
        l[i] = fenwick_get(&fw_l, cnt[i]) + 1;
        fenwick_update(&fw_l, cnt[i], l[i]);
    }

    fenwick_init(&fw_r, 100001);
    for (int i = m; i >= 1; i--) {
        r[i] = fenwick_get(&fw_r, cnt[i]) + 1;
        fenwick_update(&fw_r, cnt[i], r[i]);
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        if (ans < l[i] + r[i] - 1) ans = l[i] + r[i] - 1;
    }

    printf("%lld\n", ans);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    solution(n, m);
    return 0;
}
