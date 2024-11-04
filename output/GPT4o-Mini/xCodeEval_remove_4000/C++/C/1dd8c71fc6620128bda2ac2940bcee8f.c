#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 6000006
#define MOD 1000000007
#define EPS 1e-9
#define LLINF 180000000000000000
#define INF 900000000

int cnt[MAXN];

typedef struct {
    int *fw;
    int size;
} Fenwick;

void fenwick_init(Fenwick *fw, int n) {
    fw->size = n + 1;
    fw->fw = (int *)calloc(fw->size, sizeof(int));
}

void fenwick_update(Fenwick *fw, int i, int d) {
    while (i < fw->size) {
        if (fw->fw[i] < d) {
            fw->fw[i] = d;
        }
        i = (i | (i + 1));
    }
}

int fenwick_get(Fenwick *fw, int n) {
    int result = 0;
    while (n >= 0) {
        if (result < fw->fw[n]) {
            result = fw->fw[n];
        }
        n = (n & (n + 1)) - 1;
    }
    return result;
}

int fenwick_range_get(Fenwick *fw, int l, int r) {
    return fenwick_get(fw, r) - fenwick_get(fw, l - 1);
}

void solution(int n, int m) {
    int l[MAXN], r[MAXN];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 1; i <= n; i++) {
        int l_val, r_val;
        scanf("%d %d", &l_val, &r_val);
        cnt[l_val]++;
        cnt[r_val + 1]--;
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

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (ans < l[i] + r[i] - 1) {
            ans = l[i] + r[i] - 1;
        }
    }

    printf("%d\n", ans);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    solution(n, m);
    
    return EXIT_SUCCESS;
}
