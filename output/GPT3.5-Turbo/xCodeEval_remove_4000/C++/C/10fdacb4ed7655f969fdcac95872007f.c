#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5010
#define MOD -1

typedef struct {
    int be, en;
    int maxv, add, sum;
} segment_node;

typedef struct {
    int l;
    segment_node tree[N * 4];
} segment_tree;

segment_tree sgt;
int que[N][5];
int son[N][N];
int arr[N], fa[N];
double dp[N][N];

int max1(int a, int b) {
    return b < a ? a : b;
}

void build(int no, int l, int r, int orig, int *a) {
    if (l > r) r = l;
    if (l == r) {
        sgt.tree[no].be = sgt.tree[no].en = l;
        sgt.tree[no].add = 0;
        if (a == NULL) sgt.tree[no].maxv = orig;
        else sgt.tree[no].maxv = a[l];
        sgt.tree[no].add = 0;
        sgt.tree[no].sum = sgt.tree[no].maxv;
        return;
    }
    sgt.tree[no].be = l; sgt.tree[no].en = r;
    int mid = (l + r) / 2;
    build(no * 2, l, mid, orig, a);
    build(no * 2 + 1, mid + 1, r, orig, a);
    sgt.tree[no].sum = sgt.tree[no * 2].sum + sgt.tree[no * 2 + 1].sum;
    sgt.tree[no].add = 0;
    sgt.tree[no].maxv = max1(sgt.tree[no * 2].maxv, sgt.tree[no * 2 + 1].maxv);
}

void relax(int no) {
    int le = no * 2, ri = no * 2 + 1;
    sgt.tree[le].add += sgt.tree[no].add;
    sgt.tree[le].sum += sgt.tree[no].add * (sgt.tree[le].en - sgt.tree[le].be + 1);
    sgt.tree[le].maxv += sgt.tree[no].add;
    sgt.tree[ri].add += sgt.tree[no].add;
    sgt.tree[ri].sum += sgt.tree[no].add * (sgt.tree[ri].en - sgt.tree[ri].be + 1);
    sgt.tree[ri].maxv += sgt.tree[no].add;
    sgt.tree[no].add = 0;
}

void down(int l, int r, int no, int ranadd) {
    if (l <= sgt.tree[no].be && r >= sgt.tree[no].en) {
        sgt.tree[no].add += ranadd;
        sgt.tree[no].sum += ranadd * (sgt.tree[no].en - sgt.tree[no].be + 1);
        sgt.tree[no].maxv += ranadd;
        return;
    }
    if (sgt.tree[no].add && sgt.tree[no].be != sgt.tree[no].en) relax(no);
    int mid = (sgt.tree[no].be + sgt.tree[no].en) >> 1;
    if (r >= sgt.tree[no].be && l <= mid) down(l, r, no * 2, ranadd);
    if (r >= mid + 1 && l <= sgt.tree[no].en) down(l, r, no * 2 + 1, ranadd);
    sgt.tree[no].sum = sgt.tree[no * 2].sum + sgt.tree[no * 2 + 1].sum;
    sgt.tree[no].maxv = max1(sgt.tree[no * 2].maxv, sgt.tree[no * 2 + 1].maxv);
}

int getmax(int l, int r, int no) {
    if (l > r) return 0;
    if (l <= sgt.tree[no].be && r >= sgt.tree[no].en)
        return sgt.tree[no].maxv;
    if (sgt.tree[no].add && sgt.tree[no].be != sgt.tree[no].en) relax(no);
    int ans = 0;
    int mid = (sgt.tree[no].be + sgt.tree[no].en) >> 1;
    if (r >= sgt.tree[no].be && l <= mid) ans = max1(ans, getmax(l, r, no * 2));
    if (r >= mid + 1 && l <= sgt.tree[no].en) ans = max1(ans, getmax(l, r, no * 2 + 1));
    return ans;
}

void dfs(int no, int deep) {
    que[no][3] = getmax(que[no][1], que[no][2], 1);
    que[no][0] = max1(que[no][0], que[no][3]);
    que[no][4] = max1(que[no][4], que[no][3] + deep + 1);
    for (int i = 0; i < N; i++) {
        if (son[no][i] != -1) dfs(son[no][i], deep + 1);
    }
}

void dfsdp(int no) {
    dp[no][0] = 1;
    for (int i = 0; i < N; i++) {
        if (son[no][i] != -1) {
            dfsdp(son[no][i]);
            double rdp[N], id1[N];
            double sum1 = dp[no][0], sum2 = dp[son[no][i]][0], p = que[son[no][i]][4];
            for (int link1 = 0, link2 = 0; link1 < N || link2 < N; ) {
                rdp[i] = sum1 * sum2 * (1 - p);
                if (link1 == N - 1) {
                    link2++;
                    if (link2 == N) break;
                    sum2 += dp[son[no][i]][link2];
                } else if (link2 == N - 1) {
                    link1++;
                    sum1 += dp[no][link1];
                } else if (dp[no][link1 + 1] > dp[son[no][i]][link2 + 1]) {
                    link2++;
                    sum2 += dp[son[no][i]][link2];
                } else {
                    link1++;
                    sum1 += dp[no][link1];
                }
            }
            for (int i = N - 1; i > 0; i--) {
                rdp[i] -= rdp[i - 1];
            }
            int rsz = 1;
            for (int i = 1; i < N; i++) {
                if (rdp[i] == rdp[i - 1]) {
                    rdp[rsz - 1] += rdp[i];
                } else {
                    rdp[rsz++] = rdp[i];
                }
            }
            rdp = realloc(rdp, rsz * sizeof(double));
            sum1 = dp[no][0], sum2 = dp[son[no][i]][0];
            for (int link1 = 0, link2 = 0; link1 < N || link2 < N; ) {
                if (sum1 * sum2 > 1e-10) {
                    id1[i] = sum1 * sum2 * p;
                }
                if (link1 == N - 1) {
                    link2++;
                    if (link2 == N) break;
                    sum2 += dp[son[no][i]][link2];
                } else if (link2 == N - 1) {
                    link1++;
                    sum1 += dp[no][link1];
                } else if (dp[no][link1 + 1] > dp[son[no][i]][link2 + 1]) {
                    link2++;
                    sum2 += dp[son[no][i]][link2];
                } else {
                    link1++;
                    sum1 += dp[no][link1];
                }
            }
            for (int i = N - 1; i > 0; i--) {
                id1[i] -= id1[i - 1];
            }
            rsz = 1;
            for (int i = 1; i < N; i++) {
                if (id1[i] == id1[i - 1]) {
                    id1[rsz - 1] += id1[i];
                } else {
                    id1[rsz++] = id1[i];
                }
            }
            id1 = realloc(id1, rsz * sizeof(double));
            dp[no] = realloc(dp[no], (rsz + N) * sizeof(double));
            for (int link1 = 0, link2 = 0; link1 < rsz || link2 < N; ) {
                if (link2 == N) {
                    dp[no][link1] = rdp[link1];
                    link1++;
                } else if (link1 == rsz) {
                    dp[no][link1] = id1[link2];
                    link2++;
                } else if (rdp[link1] > id1[link2]) {
                    dp[no][link1] = id1[link2];
                    link2++;
                } else if (rdp[link1] == id1[link2]) {
                    dp[no][link1] = rdp[link1] + id1[link2];
                    link2++; link1++;
                } else if (rdp[link1] < id1[link2]) {
                    dp[no][link1] = rdp[link1];
                    link1++;
                }
            }
        }
    }
}

int main() {
    int n, nq;
    scanf("%d%d", &n, &nq);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < nq; i++) {
        scanf("%d%d%lf", &que[i][1], &que[i][2], &que[i][4]);
        que[i][1]--;
        que[i][2]--;
    }
    memset(fa, -1, sizeof(fa));
    for (int i = 0; i < nq; i++) {
        for (int j = 0; j < i; j++) {
            if (j != i && que[j][2] - que[j][1] == que[i][2] - que[i][1] && que[j][2] == que[i][2]) {
                fa[i] = j;
            }
        }
        if (fa[i] != -1) continue;
        for (int j = 0; j < nq; j++) {
            if (j != i && que[j][2] - que[j][1] == que[i][2] - que[i][1]) {
                continue;
            }
            if (que[j][1] <= que[i][1] && que[j][2] >= que[i][2]) {
                if (fa[i] == -1) {
                    fa[i] = j;
                    continue;
                }
                if (que[j][2] - que[j][1] <= que[fa[i]][2] - que[fa[i]][1]) {
                    fa[i] = j;
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < nq; i++) {
        if (fa[i] != -1) son[fa[i]][i] = 1;
        else {
            fa[i] = nq;
            son[nq][i] = 1;
        }
    }
    que[nq][1] = 0; que[nq][2] = n - 1;
    build(1, 0, n - 1, 0, arr);
    dfs(nq, 0);
    dfsdp(nq);
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp[nq][i] * i;
    }
    printf("%.10lf\n", ans);
    return 0;
}
