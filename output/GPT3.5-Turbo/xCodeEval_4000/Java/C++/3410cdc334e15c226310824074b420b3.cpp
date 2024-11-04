#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <functional>
#include <numeric>
#include <climits>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define trav(a, x) for(auto& a : x)
#define mem(a, b) memset(a, b, sizeof(a))
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
#define sqr(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define runfileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);cin.tie(NULL);cout.tie(NULL);

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
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<string> vstr;
typedef vector<bool> vbool;
typedef vector<ld> vld;
typedef vector<vector<int>> matrix;

const int MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

template<typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> T add(T a, T b, T mod) { return mod(mod(a, mod) + mod(b, mod), mod); }
template<typename T> T mul(T a, T b, T mod) { return mod(mod(a, mod) * mod(b, mod), mod); }
template<typename T> T pow(T a, T b, T mod) { T res = 1; while (b > 0) { if (b & 1) res = mul(res, a, mod); a = mul(a, a, mod); b >>= 1; } return res; }
template<typename T> T inverse(T a, T mod) { return pow(a, mod - 2, mod); }

template<typename T> void print(T x) { cout << x << endl; }
template<typename T> void print(vector<T>& v) { for (auto& i : v) cout << i << " "; cout << endl; }
template<typename T> void print(vector<vector<T>>& v) { for (auto& i : v) { for (auto& j : i) cout << j << " "; cout << endl; } }
template<typename T> void print(set<T>& s) { for (auto& i : s) cout << i << " "; cout << endl; }
template<typename T> void print(multiset<T>& s) { for (auto& i : s) cout << i << " "; cout << endl; }
template<typename T1, typename T2> void print(map<T1, T2>& m) { for (auto& i : m) cout << i.fi << " " << i.se << endl; }
template<typename T1, typename T2> void print(pair<T1, T2>& p) { cout << p.fi << " " << p.se << endl; }

template<typename T> void read(T& x) { cin >> x; }
template<typename T> void read(vector<T>& v) { for (auto& i : v) cin >> i; }
template<typename T> void read(vector<vector<T>>& v) { for (auto& i : v) for (auto& j : i) cin >> j; }
template<typename T1, typename T2> void read(pair<T1, T2>& p) { cin >> p.fi >> p.se; }

template<typename T> void write(T x) { cout << x << " "; }
template<typename T> void write(vector<T>& v) { for (auto& i : v) cout << i << " "; cout << endl; }
template<typename T> void write(vector<vector<T>>& v) { for (auto& i : v) { for (auto& j : i) cout << j << " "; cout << endl; } }
template<typename T1, typename T2> void write(pair<T1, T2>& p) { cout << p.fi << " " << p.se << endl; }

template<typename T> void run(T& x) { x.run(); }

class CF1172C {
public:
    void run() {
        bool local = getenv("ONLINE_JUDGE") == nullptr;
        bool async = false;

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int inf = 1e8;
        int mod = 998244353;

        if (async) {
            thread t(run, *this);
            t.detach();
        } else {
            solve();
        }
    }

    void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), w(n);
        int fW = 0, hW = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                hW += w[i];
            } else {
                fW += w[i];
            }
        }
        vector<int> inv(2 * m + 1);
        for (int i = 0; i < 2 * m + 1; i++) {
            inv[i] = inverse(hW + fW + i - m, mod);
        }

        vector<vector<int>> f(m + 1, vector<int>(m + 1, -1));
        vector<vector<int>> h(m + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= m; i++) {
            fill(f[i].begin(), f[i].end(), -1);
            fill(h[i].begin(), h[i].end(), -1);
        }

        for (int i = 0; i <= m; i++) {
            f[i][0] = 1;
            h[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                cout << mul(w[i], f(0, m)) << endl;
            } else {
                cout << mul(w[i], h(0, m)) << endl;
            }
        }
    }

    int f(int i, int k) {
        if (f[i][k] == -1) {
            int j = (m - k) - i;
            int fixI = add(i, fW, mod);
            int fixJ = add(hW, -j, mod);
            f[i][k] = 0;
            int inv = this.inv[i - j + m];
            f[i][k] = add(f[i][k], mul(mul(add(fixI, 1, mod), inv), f(i + 1, k - 1), mod), mod);
            f[i][k] = add(f[i][k], mul(mul(fixJ, inv), f(i, k - 1), mod), mod);
        }
        return f[i][k];
    }

    int h(int i, int k) {
        if (h[i][k] == -1) {
            int j = (m - k) - i;
            int fixI = add(i, fW, mod);
            int fixJ = add(hW, -j, mod);
            h[i][k] = 0;
            int inv = this.inv[i - j + m];

            h[i][k] = add(h[i][k], mul(mul(add(fixJ, -1, mod), inv), h(i, k - 1), mod), mod);
            h[i][k] = add(h[i][k], mul(mul(fixI, inv), h(i + 1, k - 1), mod), mod);
        }
        return h[i][k];
    }
};

int main() {
    fastio;
    CF1172C task;
    task.run();
    return 0;
}
