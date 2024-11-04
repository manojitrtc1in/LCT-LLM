#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <numeric>
#include <functional>
#include <complex>
#include <random>
#include <array>
#include <chrono>
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
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define debug4(x, y, z, w) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl;
#define debugp(p) cerr << #p << " = (" << p.fi << ", " << p.se << ")" << endl;
#define debugv(v) {cerr << #v << " = "; for(auto x : v) cerr << x << ", "; cerr << endl;}
#define debugvv(vv) {cerr << #vv << " = " << endl; for(auto v : vv) {for(auto x : v) cerr << x << ", "; cerr << endl;}}
#define debuga(a, n) {cerr << #a << " = "; for(int i = 0; i < n; ++i) cerr << a[i] << ", "; cerr << endl;}
#define debugaa(a, n, m) {cerr << #a << " = " << endl; for(int i = 0; i < n; ++i) {for(int j = 0; j < m; ++j) cerr << a[i][j] << ", "; cerr << endl;}}
#define debugm(m) {cerr << #m << " = " << endl; for(auto x : m) {cerr << x.fi << ": " << x.se << endl;}}
#define debugp(p) {cerr << #p << " = (" << p.fi << ", " << p.se << ")" << endl;}
#define debug2(x, y) {cerr << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define debug3(x, y, z) {cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define debug4(x, y, z, w) {cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl;}
#define debugv(v) {cerr << #v << " = "; for(auto x : v) cerr << x << ", "; cerr << endl;}
#define debugvv(vv) {cerr << #vv << " = " << endl; for(auto v : vv) {for(auto x : v) cerr << x << ", "; cerr << endl;}}
#define debuga(a, n) {cerr << #a << " = "; for(int i = 0; i < n; ++i) cerr << a[i] << ", "; cerr << endl;}
#define debugaa(a, n, m) {cerr << #a << " = " << endl; for(int i = 0; i < n; ++i) {for(int j = 0; j < m; ++j) cerr << a[i][j] << ", "; cerr << endl;}}
#define debugm(m) {cerr << #m << " = " << endl; for(auto x : m) {cerr << x.fi << ": " << x.se << endl;}}
#define debugp(p) {cerr << #p << " = (" << p.fi << ", " << p.se << ")" << endl;}

const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll LLINF = 1e18 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    for(int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
    }

    vector<vector<int>> cmp(10, vector<int>(10, 0));
    for(int i = 0; i < m; ++i) {
        int small = min(u[i], v[i]);
        int large = max(u[i], v[i]);
        cmp[small][large] = -1;
        cmp[large][small] = 1;
    }

    auto comp = [&](char a, char b) {
        return cmp[a - '0'][b - '0'];
    };

    vector<long long> dp(1 << 10, 0);
    for(int j = 0; j < 10; ++j) {
        dp[1 << j] = 1;
    }

    vector<vector<bool>> isValid(1 << 10, vector<bool>(10, false));
    vector<vector<int>> map(1 << 10, vector<int>(10, 0));

    for(int mask = 0; mask < (1 << 10); ++mask) {
        for(int j = 0; j < 10; ++j) {
            bool ok = true;
            int next = 1 << j;
            for(int k = 0; k < 10; ++k) {
                if((1 << k & mask) == 0) {
                    continue;
                }
                if(cmp[j][k] == 0) {
                } else if(cmp[j][k] == -1) {
                    next |= 1 << k;
                } else {
                    ok = false;
                }
            }
            isValid[mask][j] = ok;
            map[mask][j] = next;
        }
    }

    for(int i = n - 2; i >= 0; --i) {
        vector<long long> next(1 << 10, 0);
        for(int mask = 0; mask < (1 << 10); ++mask) {
            for(int j = 0; j < 10; ++j) {
                if(!isValid[mask][j]) {
                    continue;
                }
                int mask2 = map[mask][j];
                long long val = (next[mask2] + dp[mask]) % MOD;
                next[mask2] = val;
            }
        }
        dp = next;
    }

    long long sum = 0;
    for(int mask = 0; mask < (1 << 10); ++mask) {
        sum += dp[mask];
    }
    sum %= MOD;

    cout << sum << "\n";

    return 0;
}
