#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 1044

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int x;
    long long p, q, r, s;
} yda;

int graf[MAX_N][MAX_N];
int siz[MAX_N];
int dep[MAX_N];
pii ans[MAX_N * MAX_N];
int ava[MAX_N];
int ava_size = 0;
int n;
pii graf2[MAX_N][MAX_N];
int seen[MAX_N];

void dfs1(int x, int y, int d) {
    siz[x] = 1;
    dep[x] = d;
    for (int v = 0; v < MAX_N; v++) {
        if (graf[x][v] && v != y) {
            dfs1(v, x, d + 1);
            siz[x] += siz[v];
        }
    }
}

void dfs2(int x, int y, int d) {
    int t = ava[0];
    ava_size--;
    memmove(ava, ava + 1, ava_size * sizeof(int));
    assert(t > d);
    ans[ava_size].first = (pii){x, y};
    ans[ava_size].second = t - d;
    for (int v = 0; v < MAX_N; v++) {
        if (graf[x][v] && v != y) {
            dfs2(v, x, t);
        }
    }
}

void dfs3(int x, int y, int d) {
    seen[d] = 1;
    for (int i = 0; i < MAX_N; i++) {
        if (graf2[x][i].first != y) {
            dfs3(graf2[x][i].first, x, d + graf2[x][i].second);
        }
    }
}

void test_ans() {
    for (int i = 0; i < ava_size; i++) {
        graf2[ans[i].first.first][i].first = ans[i].first.second;
        graf2[ans[i].first.second][i].first = ans[i].first.first;
    }
    for (int i = 1; i <= n; i++) {
        dfs3(i, -1, 0);
    }
    for (int i = 1; i <= n * n * 2 / 9; i++) {
        assert(seen[i]);
    }
}

int main() {
    scanf("%d", &n);
    if (n == 1) return 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graf[a][b] = 1;
        graf[b][a] = 1;
    }

    dfs1(1, -1, 0);
    int M = n * 2 / 3;

    for (int i = 1; i <= n; i++) {
        pii sizes[MAX_N];
        sizes[0] = (pii){1, i};
        int p = -1;
        int size_count = 1;

        for (int v = 0; v < MAX_N; v++) {
            if (graf[i][v] && dep[v] == dep[i] + 1) {
                sizes[size_count++] = (pii){siz[v], v};
            } else {
                p = v;
            }
        }
        if (i != 1) sizes[size_count++] = (pii){n - siz[i], p};

        bool good = true;
        for (int j = 0; j < size_count; j++) {
            if (sizes[j].first > M) {
                good = false;
            }
        }
        if (good) {
            pii v1[MAX_N], v2[MAX_N];
            int sum1 = 0, sum2 = 0;
            int whme = 0;

            for (int j = 0; j < size_count; j++) {
                if (sum1 + sizes[j].first > M) {
                    v2[whme++] = sizes[j];
                    sum2 += sizes[j].first;
                    if (sizes[j].second == i) whme = 2;
                } else {
                    v1[whme++] = sizes[j];
                    sum1 += sizes[j].first;
                    if (sizes[j].second == i) whme = 1;
                }
                assert(sum1 <= M && sum2 <= M);
            }
            assert(sum1 * sum2 >= n * n * 2 / 9);
            assert(whme != 0);
            if (whme == 2) {
                // swap
                for (int j = 0; j < whme; j++) {
                    pii temp = v1[j];
                    v1[j] = v2[j];
                    v2[j] = temp;
                }
                int temp_sum = sum1;
                sum1 = sum2;
                sum2 = temp_sum;
            }
            for (int j = 1; j < sum1 - 1; j++) {
                ava[ava_size++] = j;
            }
            for (int j = 0; j < whme; j++) {
                if (v1[j].second != i) {
                    dfs2(v1[j].second, i, 0);
                }
            }
            assert(ava_size == 0);
            for (int j = 0; j < sum2; j++) {
                ava[ava_size++] = 1 + j * sum1;
            }
            for (int j = 0; j < whme; j++) {
                dfs2(v2[j].second, i, 0);
            }
            assert(ava_size == 0);
            for (int j = 0; j < ava_size; j++) {
                printf("%d %d %d\n", ans[j].first.first, ans[j].first.second, ans[j].second);
            }
            test_ans();
            return 0;
        } else {
            // debug("err");
        }
    }
    assert(false);
}
