#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <functional>
#include <numeric>
#include <random>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) for(int i=0;i<(n);++i)
#define rep1(i, n) for(int i=1;i<=(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define per1(i, n) for(int i=(n);i>=1;--i)
#define each(x, y) for(auto &(x): (y))
#define rng(i, l, r) for(int i=(l);i<(r);++i)
#define maxs(x, y) (x=max(x, (y)))
#define mins(x, y) (x=min(x, (y)))
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) (((x)>>(n)) & 1LL)
#define debug(x) cout<<#x<<": "<<x<<endl
#define debug2(x, y) cout<<#x<<": "<<x<<", "<<#y<<": "<<y<<endl
#define debug3(x, y, z) cout<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<endl
#define lbidx(x, y) (lower_bound(all(x), (y))-x.begin())
#define ubidx(x, y) (upper_bound(all(x), (y))-x.begin())
#define lbpos(x, y) ((int)(lower_bound(all(x), (y))-x.begin()))
#define ubpos(x, y) ((int)(upper_bound(all(x), (y))-x.begin()))
#define isquare(x) ((ll)(x)*(x))
#define decimal(x) fixed<<setprecision(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T>T lcm(T a, T b) { return a/gcd(a, b)*b; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> tin(n), tout(n);
    vector<vector<int>> up(n, vector<int>(20));
    int timer = 0;

    function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 20; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int u : graph[v]) {
            if (u != p) {
                dfs(u, v);
            }
        }
        tout[v] = ++timer;
    };

    dfs(0, 0);

    auto is_ancestor = [&](int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    auto lca = [&](int u, int v) {
        if (is_ancestor(u, v)) {
            return u;
        }
        if (is_ancestor(v, u)) {
            return v;
        }
        for (int i = 19; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    };

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int l = lca(u, v);
        cout << l + 1 << '\n';
    }

    return 0;
}
