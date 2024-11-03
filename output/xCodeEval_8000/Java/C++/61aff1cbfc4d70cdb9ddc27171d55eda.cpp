#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <numeric>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <ctime>
#include <random>
#include <deque>
#include <array>
#include <chrono>
#include <climits>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
#define debug(x) cerr << #x << " = " << (x) << endl;
#define endl '\n'

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int MAXN = 1e5 + 5;

int n, m;
vector<int> g[MAXN];
vector<int> tin, low;
vector<bool> used;
vector<pair<int, int>> bridges;
int timer;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (used[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.pb({v, to});
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    tin.assign(n, -1);
    low.assign(n, -1);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    find_bridges();

    cout << sz(bridges) << endl;
    for (auto p : bridges) {
        cout << p.f + 1 << " " << p.s + 1 << endl;
    }

    return 0;
}
