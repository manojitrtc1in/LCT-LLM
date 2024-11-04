








































































#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define maxn 200005
#define task ""
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int m, n, tin[maxn], tout[maxn], cnt = 0, ans[maxn], ver[maxn], spe[maxn], sz[maxn], h[maxn], num[maxn];

string s[maxn];

vector <int> ke[maxn];

vector <pii> q[maxn];

map <string, int> dd[maxn];

void Topo(int u, int par)
{
    tin[u] = ++cnt;
    ver[cnt] = u;
    sz[u] = 1;
    spe[u] = -1;
    for (auto v : ke[u])
    {
        if (v == par) continue;
        h[v] = h[u] + 1;
        Topo(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[spe[u]]) spe[u] = v;
    }
    tout[u] = cnt;
}

void Querry(int u)
{
    for (auto p : q[u])
        ans[p.S] = num[h[u]+p.F];
}

void DFS(int u, int par, int keep)
{
    if (spe[u] == -1)
    {
        if (!dd[h[u]][s[u]]) num[h[u]]++;
        dd[h[u]][s[u]]++;
        Querry(u);
        if (!keep)
        {
            dd[h[u]][s[u]]--;
            if (!dd[h[u]][s[u]]) num[h[u]]--;
        }
        return;
    }
    for (auto v : ke[u])
    {
        if (v == par || v == spe[u]) continue;
        DFS(v, u, 0);
    }
    DFS(spe[u], u, 1);
    for (auto v : ke[u])
    {
        if (v == par || v == spe[u]) continue;
        FOR(i, tin[v], tout[v])
        {
            if (!dd[h[ver[i]]][s[ver[i]]]) num[h[ver[i]]]++;
            dd[h[ver[i]]][s[ver[i]]]++;
        }
    }
    if (!dd[h[u]][s[u]]) num[h[u]]++;
    dd[h[u]][s[u]]++;
    Querry(u);
    if (!keep)
    {
        FOR(i, tin[u], tout[u])
        {
            dd[h[ver[i]]][s[ver[i]]]--;
            if (!dd[h[ver[i]]][s[ver[i]]]) num[h[ver[i]]]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    

    

    cin >> n;
    FOR(i, 1, n)
    {
        int j;
        cin >> s[i] >> j;
        ke[i].PB(j);
        ke[j].PB(i);
    }
    cin >> m;
    FOR(i, 1, m)
    {
        int u, h;
        cin >> u >> h;
        q[u].PB(MP(h, i));
    }
    h[0] = 0;
    Topo(0, -1);
    DFS(0, -1, 1);
    FOR(i, 1, m) cout << ans[i] << '\n';
    return 0;
}

















































