#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXQ 5010
#define MAXN 100100
#define N 200100
#define MOD 1000000007

typedef struct {
    int be, en;
    int maxv, add, sum;
} segment_node;

typedef struct {
    int l;
    segment_node tree[N * 4];
} segment_tree;

typedef struct {
    int l, r, maxv, deep;
    double p;
} query;

typedef struct {
    double first;
    int second;
} pair_double_int;

segment_tree sgt;
query que[MAXQ];
int son[MAXQ][MAXQ]; // Adjusted for maximum children
int arr[MAXN], fa[MAXQ];
pair_double_int dp[MAXQ][MAXQ]; // Adjusted for maximum size
int n, nq, be, en;

void dfs(int no, int deep) {
    // Implement getmax function here
    // que[no].maxv = getmax(que[no].l, que[no].r, 1);
    be = fmax(be, que[no].maxv);
    en = fmax(en, que[no].maxv + deep + 1);
    que[no].deep = deep;
    for (int i = 0; i < MAXQ && son[no][i] != -1; i++)
        dfs(son[no][i], deep + 1);
}

pair_double_int operator_plus(pair_double_int a, pair_double_int b) {
    return (pair_double_int){a.first + b.first, a.second};
}

void dfsdp(int no) {
    dp[no][0] = (pair_double_int){1, que[no].maxv};
    for (int i = 0; i < MAXQ && son[no][i] != -1; i++) {
        int rno = son[no][i];
        dfsdp(rno);
        pair_double_int rdp[MAXQ], rdp1[MAXQ];
        double sum1 = dp[no][0].first, sum2 = dp[rno][0].first, p = que[rno].p;

        // Merging logic for rdp and rdp1
        // Implement the merging logic here

        // Clear dp[no] and fill it with merged results
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
            son[fa[i]][i] = i; // Adjusted for maximum children
        } else {
            fa[i] = nq;
            son[nq][i] = i; // Adjusted for maximum children
        }
    }
    que[nq].l = 0; que[nq].r = n - 1;
    // Implement build function for segment tree here

    dfs(nq, 0);
    dfsdp(nq);
    double ans = 0;
    for (int i = 0; i < MAXQ && dp[nq][i].first != 0; i++) {
        ans += dp[nq][i].first * dp[nq][i].second;
    }
    printf("%.10lf\n", ans);

    return 0;
}
