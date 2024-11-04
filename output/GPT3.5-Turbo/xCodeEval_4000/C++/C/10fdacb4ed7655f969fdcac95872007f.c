#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200100

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
} q;

segment_tree sgt;
q que[5010];
int son[5010][5010];
int arr[100100], fa[5010];
double dp[5010][5010];
int n, nq, be, en;

int max1(int a, int b) {
    return b < a ? a : b;
}

void build(segment_tree *sgt, int no, int l, int r, int orig, int *a) {
    if (l > r) r = l;
    if (l == r) {
        sgt->tree[no].be = sgt->tree[no].en = l;
        sgt->tree[no].add = 0;
        if (a == NULL) sgt->tree[no].maxv = orig;
        else sgt->tree[no].maxv = a[l];
        sgt->tree[no].add = 0;
        sgt->tree[no].sum = sgt->tree[no].maxv;
        return;
    }
    sgt->tree[no].be = l; sgt->tree[no].en = r;
    int mid = (l + r) / 2;
    build(sgt, no * 2, l, mid, orig, a);
    build(sgt, no * 2 + 1, mid + 1, r, orig, a);
    sgt->tree[no].sum = sgt->tree[no * 2].sum + sgt->tree[no * 2 + 1].sum;
    sgt->tree[no].add = 0;
    sgt->tree[no].maxv = max1(sgt->tree[no * 2].maxv, sgt->tree[no * 2 + 1].maxv);
}

void relax(segment_tree *sgt, int no) {
    int le = no * 2, ri = no * 2 + 1;
    sgt->tree[le].add += sgt->tree[no].add;
    sgt->tree[le].sum += sgt->tree[no].add * (sgt->tree[le].en - sgt->tree[le].be + 1);
    sgt->tree[le].maxv += sgt->tree[no].add;
    sgt->tree[ri].add += sgt->tree[no].add;
    sgt->tree[ri].sum += sgt->tree[no].add * (sgt->tree[ri].en - sgt->tree[ri].be + 1);
    sgt->tree[ri].maxv += sgt->tree[no].add;
    sgt->tree[no].add = 0;
}

void down(segment_tree *sgt, int l, int r, int no, int ranadd) {
    if (l <= sgt->tree[no].be && r >= sgt->tree[no].en) {
        sgt->tree[no].add += ranadd;
        sgt->tree[no].sum += ranadd * (sgt->tree[no].en - sgt->tree[no].be + 1);
        sgt->tree[no].maxv += ranadd;
        return;
    }
    if (sgt->tree[no].add && sgt->tree[no].be != sgt->tree[no].en) relax(sgt, no);
    int mid = (sgt->tree[no].be + sgt->tree[no].en) >> 1;
    if (r >= sgt->tree[no].be && l <= mid) down(sgt, l, r, no * 2, ranadd);
    if (r >= mid + 1 && l <= sgt->tree[no].en) down(sgt, l, r, no * 2 + 1, ranadd);
    sgt->tree[no].sum = sgt->tree[no * 2].sum + sgt->tree[no * 2 + 1].sum;
    sgt->tree[no].maxv = max1(sgt->tree[no * 2].maxv, sgt->tree[no * 2 + 1].maxv);
}

int getmax(segment_tree *sgt, int l, int r, int no) {
    if (l > r) return 0;
    if (l <= sgt->tree[no].be && r >= sgt->tree[no].en)
        return sgt->tree[no].maxv;
    if (sgt->tree[no].add && sgt->tree[no].be != sgt->tree[no].en) relax(sgt, no);
    int ans = 0;
    int mid = (sgt->tree[no].be + sgt->tree[no].en) >> 1;
    if (r >= sgt->tree[no].be && l <= mid) ans = max1(ans, getmax(sgt, l, r, no * 2));
    if (r >= mid + 1 && l <= sgt->tree[no].en) ans = max1(ans, getmax(sgt, l, r, no * 2 + 1));
    return ans;
}

void dfs(int no, int deep) {
    que[no].maxv = getmax(&sgt, que[no].l, que[no].r, 1);
    be = max1(be, que[no].maxv);
    en = max1(en, que[no].maxv + deep + 1);
    que[no].deep = deep;
    for (int i = 0; i < son[no][0]; i++)
        dfs(son[no][i], deep + 1);
}

void dfsdp(int no) {
    dp[no][0] = 1;
    for (int i = 0; i < son[no][0]; i++) {
        int rno = son[no][i];
        dfsdp(rno);
        double sum1 = dp[no][0], sum2 = dp[rno][0], p = que[rno].p;
        for (int link1 = 0, link2 = 0; link1 < dp[no][0] || link2 < dp[rno][0]; ) {
            dp[no][link1 + link2] = sum1 * sum2 * (1 - p);
            if (link1 == dp[no][0] - 1) {
                link2++;
                if (link2 == dp[rno][0]) break;
                sum2 += dp[rno][link2];
            } else if (link2 == dp[rno][0] - 1) {
                link1++;
                sum1 += dp[no][link1];
            } else if (dp[no][link1 + 1] > dp[rno][link2 + 1]) {
                link2++;
                sum2 += dp[rno][link2];
            } else {
                link1++;
                sum1 += dp[no][link1];
            }
        }
        for (int i = dp[no][0]; i > 0; i--)
            dp[no][i] -= dp[no][i - 1];
        int rsz = 1;
        for (int i = 1; i < dp[no][0]; i++) {
            if (dp[no][i] == dp[no][i - 1])
                dp[no][rsz - 1] += dp[no][i];
            else dp[no][rsz++] = dp[no][i];
        }
        dp[no][0] = rsz;
        sum1 = dp[no][0], sum2 = dp[rno][0];
        for (int link1 = 0, link2 = 0; link1 < dp[no][0] || link2 < dp[rno][0]; ) {
            if (sum1 * sum2 > 1e-10)
                dp[no][link1 + link2] = sum1 * sum2 * p;
            if (link1 == dp[no][0] - 1) {
                link2++;
                if (link2 == dp[rno][0]) break;
                sum2 += dp[rno][link2];
            } else if (link2 == dp[rno][0] - 1) {
                link1++;
                sum1 += dp[no][link1];
            } else if (dp[no][link1 + 1] > dp[rno][link2 + 1]) {
                link2++;
                sum2 += dp[rno][link2];
            } else {
                link1++;
                sum1 += dp[no][link1];
            }
        }
        for (int i = dp[no][0]; i > 0; i--)
            dp[no][i] -= dp[no][i - 1];
        rsz = 1;
        for (int i = 1; i < dp[no][0]; i++) {
            if (dp[no][i] == dp[no][i - 1])
                dp[no][rsz - 1] += dp[no][i];
            else dp[no][rsz++] = dp[no][i];
        }
        dp[no][0] = rsz;
        int rsz = 1;
        for (int link1 = 0, link2 = 0; link1 < dp[no][0] || link2 < dp[rno][0]; ) {
            if (link2 == dp[rno][0]) {
                dp[no][rsz++] = dp[no][link1++];
            } else if (link1 == dp[no][0]) {
                dp[no][rsz++] = dp[rno][link2++];
            } else if (dp[no][link1] > dp[rno][link2]) {
                dp[no][rsz++] = dp[rno][link2++];
            } else if (dp[no][link1] == dp[rno][link2]) {
                dp[no][rsz++] = dp[no][link1++] + dp[rno][link2++];
            } else if (dp[no][link1] < dp[rno][link2]) {
                dp[no][rsz++] = dp[no][link1++];
            }
        }
        dp[no][0] = rsz;
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
        for (int j = 0; j < i; j++) {
            if (j != i && que[j].r - que[j].l == que[i].r - que[i].l && que[j].r == que[i].r)
                fa[i] = j;
        }
        if (fa[i] != -1) continue;
        for (int j = 0; j < nq; j++) {
            if (j != i && que[j].r - que[j].l == que[i].r - que[i].l)
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
        if (fa[i] != -1) son[fa[i]][son[fa[i]][0]++] = i;
        else {
            fa[i] = nq;
            son[nq][son[nq][0]++] = i;
        }
    }
    que[nq].l = 0; que[nq].r = n - 1;
    build(&sgt, 1, 0, n - 1, 0, arr);

    dfs(nq, 0);
    dfsdp(nq);
    double ans = 0;
    for (int i = 0; i < dp[nq][0]; i++) {
        ans += dp[nq][i] * dp[nq][i];
    }
    printf("%.10lf\n", ans);

    return 0;
}
