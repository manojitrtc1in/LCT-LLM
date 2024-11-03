
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;

int V, E, DFSTime = 0, N;
vector<vector<int>> g;
vector<int> cnt, tin, fup, height, traverse, trav_1, t;
vector<bool> vis;
vector<ii> bridges;

void dfs(const int &v, const int &p) {
    vis[v] = true;
    trav_1[v] = traverse.size();
    traverse.push_back(v);
    fup[v] = tin[v] = DFSTime;
    DFSTime++;
    for(const int &to : g[v]) {
        if(!vis[to]) { 

            dfs(to, v);
            traverse.push_back(v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to] > tin[v]) {
                bridges.push_back(ii(v, to));
                bridges.push_back(ii(to, v));
            }
        } else if(to != p) { 

            fup[v] = min(fup[v], tin[to]);
        }
    }
}

void dfs1(const int &v) {
    vis[v] = true;
    for(const int &to : g[v]) {
        if(!vis[to]) { 

            cnt[to] = cnt[v] + binary_search(all(bridges), ii(v, to));
            height[to] = height[v] + 1;
            dfs1(to);
        }
    }
}

void build_tree(const int &v, const int &tl, const int &tr) {
    if(tl == tr) {
        t[v] = traverse[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build_tree(v * 2, tl, tm);
    build_tree(v * 2 + 1, tm + 1, tr);
    t[v] = (height[t[v * 2]] < height[t[v * 2 + 1]] ? t[v * 2] : t[v * 2 + 1]);
}

int get(const int &v, const int &tl, const int &tr, const int &l, const int &r) {
    if(l <= tl && tr <= r)
        return t[v];
    if(l > tr || r < tl)
        return INT_MAX;
    int tm = (tl + tr) / 2;
    int lr = get(v * 2, tl, tm, l, r);
    int rr = get(v * 2 + 1, tm + 1, tr, l, r);
    if(max(lr, rr) == INT_MAX)
        return min(lr, rr);
    return (height[lr] < height[rr] ? lr : rr);
}

int lca(const int &u, const int &v) {
    int i1 = trav_1[u], i2 = trav_1[v];
    if(i2 < i1)
        swap(i1, i2);
    return get(1, 0, N - 1, i1, i2);
}

void solve() {
    scanf("%d %d", &V, &E);
    g.resize(V);
    height.resize(V);
    vis.resize(V, false);
    cnt.resize(V);
    tin.resize(V);
    fup.resize(V);
    trav_1.resize(V);
    while(E--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    vis.assign(V, false);
    sort(all(bridges));
    cnt[0] = 0;
    height[0] = 0;
    dfs1(0);
    N = traverse.size();
    t.resize(4 * N);
    build_tree(1, 0, N - 1);
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;v--;

        int LCA = lca(u, v);
        if(LCA == u)
            printf("%d\n", cnt[v] - cnt[u]);
        else if(LCA == v)
            printf("%d\n", cnt[u] - cnt[v]);
        else
            printf("%d\n", cnt[u] + cnt[v] - 2 * cnt[LCA]);
    }
}

int main() {








    solve();
    return 0;
}
