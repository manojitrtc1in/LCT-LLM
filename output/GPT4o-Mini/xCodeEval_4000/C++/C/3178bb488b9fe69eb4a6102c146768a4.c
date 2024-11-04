#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_N 1000 + 44

typedef struct {
    int first;
    int second;
} pii;

int graf[MAX_N][MAX_N];
int siz[MAX_N];
int dep[MAX_N];
pii ans[MAX_N * MAX_N];
int ans_count = 0;
int ava[MAX_N];
int ava_count = 0;
int n;

void dfs1(int x, int y, int d) {
    siz[x] = 1;
    dep[x] = d;
    for (int v = 1; v <= n; v++) {
        if (graf[x][v] && v != y) {
            dfs1(v, x, d + 1);
            siz[x] += siz[v];
        }
    }
}

void dfs2(int x, int y, int d) {
    int t = ava[0];
    ava_count--;
    memmove(ava, ava + 1, ava_count * sizeof(int));
    assert(t > d);
    ans[ans_count++] = (pii){x, y};
    for (int v = 1; v <= n; v++) {
        if (graf[x][v] && v != y) {
            dfs2(v, x, t);
        }
    }
}

void dfs3(int x, int y, int d, int *seen) {
    seen[d] = 1;
    for (int i = 1; i <= n; i++) {
        if (graf2[x][i] && i != y) {
            dfs3(i, x, d + graf2[x][i], seen);
        }
    }
}

void test_ans() {
    int seen[MAX_N * MAX_N * 2 / 9] = {0};
    for (int i = 0; i < ans_count; i++) {
        graf2[ans[i].first][ans[i].second] = ans[i].second;
        graf2[ans[i].second][ans[i].first] = ans[i].first;
    }
    for (int i = 1; i <= n; i++) {
        dfs3(i, -1, 0, seen);
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

        for (int v = 1; v <= n; v++) {
            if (graf[i][v] && dep[v] == dep[i] + 1) {
                sizes[size_count++] = (pii){siz[v], v};
            } else {
                p = v;
            }
        }
        if (i != 1) sizes[size_count++] = (pii){n - siz[i], p};

        int good = 1;
        for (int j = 0; j < size_count; j++) {
            if (sizes[j].first > M) {
                good = 0;
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
            }

            assert(sum1 * sum2 >= n * n * 2 / 9);
            assert(whme != 0);
            if (whme == 2) {
                pii *temp = v1;
                v1 = v2;
                v2 = temp;
                int temp_sum = sum1;
                sum1 = sum2;
                sum2 = temp_sum;
            }

            for (int j = 1; j < sum1; j++) {
                ava[ava_count++] = j;
            }

            for (int j = 0; j < whme; j++) {
                if (v1[j].second != i) {
                    dfs2(v1[j].second, i, 0);
                }
            }
            assert(ava_count == 0);

            for (int j = 0; j < sum2; j++) {
                ava[ava_count++] = 1 + j * sum1;
            }

            for (int j = 0; j < whme; j++) {
                dfs2(v2[j].second, i, 0);
            }
            assert(ava_count == 0);

            for (int j = 0; j < ans_count; j++) {
                printf("%d %d %d\n", ans[j].first, ans[j].second);
            }
            test_ans();
            return 0;
        }
    }
    assert(0);
}
