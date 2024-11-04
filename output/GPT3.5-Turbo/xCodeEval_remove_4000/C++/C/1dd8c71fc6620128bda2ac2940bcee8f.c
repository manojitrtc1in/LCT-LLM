#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAXN 600006
#define N 500005

int cnt[MAXN];

typedef struct {
    int *fw;
} fenwick;

fenwick* create_fenwick(int n) {
    fenwick* fw = (fenwick*)malloc(sizeof(fenwick));
    fw->fw = (int*)calloc(n + 1, sizeof(int));
    return fw;
}

void update(fenwick* fw, int i, int d) {
    while (i < fw->fw_size) {
        if (d > fw->fw[i]) {
            fw->fw[i] = d;
        }
        i = (i | (i + 1));
    }
}

int get(fenwick* fw, int n) {
    int result = 0;
    while (n >= 0) {
        if (fw->fw[n] > result) {
            result = fw->fw[n];
        }
        n = (n & (n + 1)) - 1;
    }
    return result;
}

int get_range(fenwick* fw, int l, int r) {
    return get(fw, r) - get(fw, l - 1);
}

void solution(int test_case) {
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

    fenwick* fw_l = create_fenwick(100001);
    int* l = (int*)malloc((m + 1) * sizeof(int));
    for (int i = 1; i <= m; i++) {
        l[i] = get(fw_l, cnt[i]) + 1;
        update(fw_l, cnt[i], l[i]);
    }

    fenwick* fw_r = create_fenwick(100001);
    int* r = (int*)malloc((m + 1) * sizeof(int));
    for (int i = m; i >= 1; i--) {
        r[i] = get(fw_r, cnt[i]) + 1;
        update(fw_r, cnt[i], r[i]);
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
        solution(test_case);
    }

    return EXIT_SUCCESS;
}
