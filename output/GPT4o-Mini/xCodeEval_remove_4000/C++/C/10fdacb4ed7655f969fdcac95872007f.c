#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 100100
#define MOD 1000000007
#define MAXQ 5010

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef struct {
    int first, second;
} pii;
typedef struct {
    double first;
    int second;
} pdd;

typedef struct {
    int be, en;
    int maxv, add, sum;
} segment_node;

typedef struct {
    int l;
    segment_node tree[N * 4];
} segment_tree;

segment_tree sgt;
struct q {
    int l, r, maxv, deep;
    double p;
} que[MAXQ];

int son[MAXQ][MAXQ]; // Adjacency list for children
int arr[N], fa[MAXQ];
pdd dp[MAXQ][MAXQ]; // Dynamic programming array
int n, nq, be, en;

void dfs(int no, int deep) {
    que[no].maxv = sgt.tree[1].maxv; // Placeholder for max value retrieval
    be = fmax(be, que[no].maxv);
    en = fmax(en, que[no].maxv + deep + 1);
    que[no].deep = deep;
    for (int i = 0; i < MAXQ && son[no][i] != 0; i++)
        dfs(son[no][i], deep + 1);
}

pdd operator_plus(pdd a, pdd b) {
    return (pdd){a.first + b.first, a.second + b.second};
}

void dfsdp(int no) {
    dp[no][0] = (pdd){1, que[no].maxv};
    for (int i = 0; i < MAXQ && son[no][i] != 0; i++) {
        int rno = son[no][i];
        dfsdp(rno);
        pdd rdp[MAXQ], id1[MAXQ];
        double sum1 = dp[no][0].first, sum2 = dp[rno][0].first, p = que[rno].p;
        int link1 = 0, link2 = 0, rsz = 0;

        while (link1 < MAXQ || link2 < MAXQ) {
            rdp[rsz++] = (pdd){sum1 * sum2 * (1 - p), fmax(dp[no][link1].second, dp[rno][link2].second)};
            if (link1 == MAXQ - 1) {
                link2++;
                if (link2 == MAXQ) break;
                sum2 += dp[rno][link2].first;
            } else if (link2 == MAXQ - 1) {
                link1++;
                sum1 += dp[no][link1].first;
            } else if (dp[no][link1 + 1].second > dp[rno][link2 + 1].second) {
                link2++;
                sum2 += dp[rno][link2].first;
            } else {
                link1++;
                sum1 += dp[no][link1].first;
            }
        }

        // Further processing of rdp and id1 would go here...

        // Clear dp[no] and merge rdp and id1 into dp[no]
        memset(dp[no], 0, sizeof(dp[no]));
        for (int link1 = 0, link2 = 0; link1 < MAXQ || link2 < MAXQ;) {
            if (link2 == MAXQ) {
                dp[no][link1++] = rdp[link1];
            } else if (link1 == MAXQ) {
                dp[no][link2++] = id1[link2];
            } else if (rdp[link1].second > id1[link2].second) {
                dp[no][link2++] = id1[link2];
            } else if (rdp[link1].second == id1[link2].second) {
                dp[no][link2++] = operator_plus(rdp[link1], id1[link2]);
                link1++;
            } else {
                dp[no][link1++] = rdp[link1];
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &nq);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < nq; i++) {
        scanf("%d%d%lf", &que[i].l, &que[i].r, &que[i].p);
        que[i].l--;
        que[i].r--;
    }
    memset(fa, -1, sizeof(fa));
    for (int i = 0; i < nq; i++) {
        for (int j = 0; j < i; j++) if (j != i) {
            if (que[j].r - que[j].l == que[i].r - que[i].l && que[j].r == que[i].r)
                fa[i] = j;
        }
        if (fa[i] != -1) continue;
        for (int j = 0; j < nq; j++) if (j != i) {
            if (que[j].r - que[j].l == que[i].r - que[i].l)
                continue;
            if (que[j].l <= que[i].l && que[j].r >= que[i].r) {
                if (fa[i] == -1) {
                    fa[i] = j;
                    continue;
                }
                if (que[j].r - que[j].l <= que[fa[i]].r - que[fa[i]].l) {
                    fa[i] = j;
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < nq; i++) {
        if (fa[i] != -1) {
            son[fa[i]][0] = i; // Placeholder for adding child
        } else {
            fa[i] = nq;
            son[nq][0] = i; // Placeholder for adding child
        }
    }
    que[nq].l = 0; que[nq].r = n - 1;

    // Build segment tree here...

    dfs(nq, 0);
    dfsdp(nq);
    double ans = 0;
    for (int i = 0; i < MAXQ; i++) {
        ans += dp[nq][i].first * dp[nq][i].second;
    }
    printf("%.10lf\n", ans);

    return 0;
}
