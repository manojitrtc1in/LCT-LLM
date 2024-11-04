
 
#include <bits/stdc++.h>
#define all(n) (n).begin(), (n).end()
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define sqr(n) (n)*(n)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ll, int> PLI;
typedef vector<int> VI;
typedef double db;

template<class T1, class T2> bool umin(T1& a, T2 b) { return a > b ? (a = b, true) : false; }
template<class T1, class T2> bool umax(T1& a, T2 b) { return a < b ? (a = b, true) : false; }
template<class T> void clear(T& a) { T().swap(a); }

const int N = 2e5 + 5;

int n, m, _, k;

int main() {
    IOS; cin >> n >> m >> k; vector<PII> ed;
    vector<vector<PII>> h(n + 1); vector<PII> e;
    rep (i, 1, m) {
        int u, v, c; cin >> u >> v >> c;
        e.pb({u, v}); h[u].pb({v, c}); h[v].pb({u, c});
    }

    rep (i, 1, k) {
        int u, v; cin >> u >> v;
        ed.pb({u, v});
    }

    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, 1ll << 60));
    rep (s, 1, n) {
        priority_queue<PII> q; d[s][s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            PII p = q.top(); q.pop();
            if (d[s][p.se] != -p.fi) continue;
            for (auto &y : h[p.se]) {
                int w = d[s][p.se] + y.se;
                if (w >= d[s][y.fi]) continue;
                d[s][y.fi] = w; q.push({ -w, y.fi});
            }
        }
    }

    ll ans = 1ll << 62;
    for (auto g : e) {
        ll tmp = 0;
        for (auto gg : ed) tmp += min({d[gg.fi][gg.se], d[gg.fi][g.fi] + d[g.se][gg.se], d[gg.fi][g.se] + d[g.fi][gg.se]});
        umin(ans, tmp);
    }
    cout << ans;
    return 0;
}