#define ONLINE_JUDGE 1

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;

int N, K;
vector<int> cnt_up, cnt_down, up_mark, down_mark, traverse, t, h, first_in_traverse, xxx, p;
vector<ii> edges;
vector<vector<ii>> g;

void dfs1(const int &v, const int &parent = -1, const int &edge = -1) {
    p[v] = parent;
    first_in_traverse[v] = traverse.size();
    traverse.push_back(v);
    for(const ii &to : g[v])
        if(to.X != parent) {
            h[to.X] = h[v] + 1;
            dfs1(to.X, v, to.Y);
            traverse.push_back(v);
        }
}

void dfs2(const int &v, const int &parent = -1) {
    for(const ii &to : g[v])
        if(to.X != parent) {
            dfs2(to.X, v);
            up_mark[v] += up_mark[to.X];
            down_mark[v] += down_mark[to.X];
        }
    for(const ii &to : g[v])
        if(to.X != parent) {
            cnt_up[to.Y] = up_mark[to.X];
            cnt_down[to.Y] = down_mark[to.X];
        }
}

void build(const int &v, const int &tl, const int &tr) {
    if(tl == tr) {
        t[v] = traverse[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = (h[t[v * 2]] < h[t[v * 2 + 1]] ? t[v * 2] : t[v * 2 + 1]);
}

int get(const int &v, const int &tl, const int &tr, const int &l, const int &r) {
    if(l <= tl && tr <= r)
        return t[v];
    if(l > tr || r < tl)
        return -1;
    int tm = (tl + tr) / 2;
    int i1 = get(v * 2, tl, tm, l, r);
    int i2 = get(v * 2 + 1, tm + 1, tr, l, r);
    if(i1 == -1) return i2;
    if(i2 == -1) return i1;
    return (h[i1] < h[i2] ? i1 : i2);
}

void build_tree() {
    t.resize(4 * traverse.size());
    build(1, 0, traverse.size() - 1);
}

int lca(const int &v1, const int &v2) {
    int i1 = first_in_traverse[v1], i2 = first_in_traverse[v2];
    if(i1 > i2)
        swap(i1, i2);
    return get(1, 0, traverse.size() - 1, i1, i2);
}

void solve() {
    scanf("%d", &N);
    first_in_traverse.resize(N, -1);
    up_mark.resize(N, 0);
    down_mark.resize(N, 0);
    p.resize(N);
    h.resize(N);
    g.resize(N);
    cnt_up.resize(N - 1);
    cnt_down.resize(N - 1);
    for(int i = 0;i < N - 1;i++) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        u--;v--;
        edges.push_back(ii(u, v));
        if(x == 1)
            xxx.push_back(i);
        g[u].push_back(ii(v, i));
        g[v].push_back(ii(u, i));
    }
    h[0] = 0;
    dfs1(0);
    build_tree();
    scanf("%d", &K);
    int S1 = 1, S2;
    for(int i = 1;i <= K;i++) {
        scanf("%d", &S2);
        int v1 = S1 - 1, v2 = S2 - 1;
        int v_lca = lca(v1, v2);
        if(v_lca != v1 && v_lca != v2) {
            up_mark[v1]++;
            up_mark[v_lca]--;
            down_mark[v2]++;
            down_mark[v_lca]--;
        } else if(v_lca == v1) {
            down_mark[v1]--;
            down_mark[v2]++;
        } else if(v_lca == v2) {
            up_mark[v1]++;
            up_mark[v2]--;
        }
        S1 = S2;
    }
    up_mark[0] = 0;
    down_mark[0] = 0;
    dfs2(0);
    int MOD = 1000000007, ans = 0;
    vector<int> pow2(1000020);
    pow2[0] = 1;
    for(int i = 1;i < pow2.size();i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    for(const int &i : xxx) {
        if(p[edges[i].X] == edges[i].Y)
            ans = (ans + pow2[cnt_down[i]] - 1) % MOD;
        else
            ans = (ans + pow2[cnt_up[i]] - 1) % MOD;
    }


    printf("%d", ans);
}

int main() {
    if(ONLINE_JUDGE) { 

        ;
    } else { 

        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
