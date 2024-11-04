#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <cassert>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <iterator>
#include <functional>
#include <numeric>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define per(i, n) for(int i = (n)-1; i >= 0; --i)
#define per1(i, n) for(int i = (n); i >= 1; --i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for(int i = (b); i >= (a); --i)
#define FORE(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline T gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T m) { return (a % m + m) % m; }
template<typename T> inline T pow(T a, T n, T m) { T ret = 1; while (n) { if (n & 1) ret = ret * a % m; a = a * a % m; n >>= 1; } return ret; }
template<typename T> inline T modinv(T a, T m) { return pow(a, m - 2, m); }
template<typename T> inline vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> inline auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }
template<typename T, typename V> inline typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) { t = v; }
template<typename T, typename V> inline typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) { for (auto& e : t) fill_v(e, v); }
template<typename T> inline void in(T& x) { cin >> x; }
template<typename T> inline void out(T x) { cout << x; }
template<typename T> inline void outln(T x) { cout << x << endl; }
template<typename T> inline void outsp(T x) { cout << x << " "; }
template<typename T> inline void outlnsp(T x) { cout << x << " " << endl; }
template<typename T> inline void in(vector<T>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<T>& v) { for (int i = 0; i < sz(v); ++i) { outsp(v[i]); } outln(""); }
template<typename T> inline void outln(vector<T>& v) { for (int i = 0; i < sz(v); ++i) { outlnsp(v[i]); } outln(""); }
template<typename T> inline void out(vector<T>& v, int n) { for (int i = 0; i < n; ++i) { outsp(v[i]); } outln(""); }
template<typename T> inline void outln(vector<T>& v, int n) { for (int i = 0; i < n; ++i) { outlnsp(v[i]); } outln(""); }
template<typename T> inline void in(vector<vector<T>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<vector<T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<vector<T>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<vector<T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<vector<T>>& v, int n) { for (int i = 0; i < n; ++i) { outln(v[i]); } }
template<typename T> inline void in(set<T>& s) { for (auto& e : s) in(e); }
template<typename T> inline void out(set<T>& s) { for (auto& e : s) outsp(e); outln(""); }
template<typename T> inline void outln(set<T>& s) { for (auto& e : s) outlnsp(e); outln(""); }
template<typename T> inline void in(multiset<T>& s) { for (auto& e : s) in(e); }
template<typename T> inline void out(multiset<T>& s) { for (auto& e : s) outsp(e); outln(""); }
template<typename T> inline void outln(multiset<T>& s) { for (auto& e : s) outlnsp(e); outln(""); }
template<typename T> inline void in(map<T, T>& m) { for (auto& e : m) in(e.fi), in(e.se); }
template<typename T> inline void out(map<T, T>& m) { for (auto& e : m) outsp(e.fi), outln(e.se); }
template<typename T> inline void outln(map<T, T>& m) { for (auto& e : m) outlnsp(e.fi), outln(e.se); }
template<typename T> inline void in(multimap<T, T>& m) { for (auto& e : m) in(e.fi), in(e.se); }
template<typename T> inline void out(multimap<T, T>& m) { for (auto& e : m) outsp(e.fi), outln(e.se); }
template<typename T> inline void outln(multimap<T, T>& m) { for (auto& e : m) outlnsp(e.fi), outln(e.se); }
template<typename T> inline void in(vector<pair<T, T>>& v) { for (auto& e : v) in(e.fi), in(e.se); }
template<typename T> inline void out(vector<pair<T, T>>& v) { for (int i = 0; i < sz(v); ++i) { outsp(v[i].fi), outln(v[i].se); } }
template<typename T> inline void outln(vector<pair<T, T>>& v) { for (int i = 0; i < sz(v); ++i) { outlnsp(v[i].fi), outln(v[i].se); } }
template<typename T> inline void out(vector<pair<T, T>>& v, int n) { for (int i = 0; i < n; ++i) { outsp(v[i].fi), outln(v[i].se); } }
template<typename T> inline void outln(vector<pair<T, T>>& v, int n) { for (int i = 0; i < n; ++i) { outlnsp(v[i].fi), outln(v[i].se); } }
template<typename T> inline void in(set<pair<T, T>>& s) { for (auto& e : s) in(e.fi), in(e.se); }
template<typename T> inline void out(set<pair<T, T>>& s) { for (auto& e : s) outsp(e.fi), outln(e.se); }
template<typename T> inline void outln(set<pair<T, T>>& s) { for (auto& e : s) outlnsp(e.fi), outln(e.se); }
template<typename T> inline void in(multiset<pair<T, T>>& s) { for (auto& e : s) in(e.fi), in(e.se); }
template<typename T> inline void out(multiset<pair<T, T>>& s) { for (auto& e : s) outsp(e.fi), outln(e.se); }
template<typename T> inline void outln(multiset<pair<T, T>>& s) { for (auto& e : s) outlnsp(e.fi), outln(e.se); }
template<typename T> inline void in(map<pair<T, T>, T>& m) { for (auto& e : m) in(e.fi.fi), in(e.fi.se), in(e.se); }
template<typename T> inline void out(map<pair<T, T>, T>& m) { for (auto& e : m) outsp(e.fi.fi), outsp(e.fi.se), outln(e.se); }
template<typename T> inline void outln(map<pair<T, T>, T>& m) { for (auto& e : m) outlnsp(e.fi.fi), outlnsp(e.fi.se), outln(e.se); }
template<typename T> inline void in(multimap<pair<T, T>, T>& m) { for (auto& e : m) in(e.fi.fi), in(e.fi.se), in(e.se); }
template<typename T> inline void out(multimap<pair<T, T>, T>& m) { for (auto& e : m) outsp(e.fi.fi), outsp(e.fi.se), outln(e.se); }
template<typename T> inline void outln(multimap<pair<T, T>, T>& m) { for (auto& e : m) outlnsp(e.fi.fi), outlnsp(e.fi.se), outln(e.se); }
template<typename T> inline void in(vector<set<T>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<set<T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<set<T>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<set<T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<set<T>>& v, int n) { for (int i = 0; i < n; ++i) { outln(v[i]); } }
template<typename T> inline void in(vector<multiset<T>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<multiset<T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<multiset<T>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<multiset<T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<multiset<T>>& v, int n) { for (int i = 0; i < n; ++i) { outln(v[i]); } }
template<typename T> inline void in(vector<map<T, T>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<map<T, T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<T, T>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<map<T, T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<T, T>>& v, int n) { for (int i = 0; i < n; ++i) { outln(v[i]); } }
template<typename T> inline void in(vector<multimap<T, T>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<multimap<T, T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<multimap<T, T>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<multimap<T, T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<multimap<T, T>>& v, int n) { for (int i = 0; i < n; ++i) { outln(v[i]); } }
template<typename T> inline void in(vector<vector<pair<T, T>>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<vector<pair<T, T>>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<vector<pair<T, T>>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<vector<pair<T, T>>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<vector<pair<T, T>>>& v, int n) { for (int i = 0; i < n; ++i) { outln(v[i]); } }
template<typename T> inline void in(set<vector<T>>& s) { for (auto& e : s) in(e); }
template<typename T> inline void out(set<vector<T>>& s) { for (auto& e : s) out(e); }
template<typename T> inline void outln(set<vector<T>>& s) { for (auto& e : s) outln(e); }
template<typename T> inline void in(multiset<vector<T>>& s) { for (auto& e : s) in(e); }
template<typename T> inline void out(multiset<vector<T>>& s) { for (auto& e : s) out(e); }
template<typename T> inline void outln(multiset<vector<T>>& s) { for (auto& e : s) outln(e); }
template<typename T> inline void in(vector<map<pair<T, T>, T>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<map<pair<T, T>, T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<map<pair<T, T>, T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>& v, int n) { for (int i = 0; i < n; ++i) { outln(v[i]); } }
template<typename T> inline void in(vector<set<pair<T, T>>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<set<pair<T, T>>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<set<pair<T, T>>>& v) { for (int i = 0; i < sz(v); ++i) { outln(v[i]); } }
template<typename T> inline void out(vector<set<pair<T, T>>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<set<pair<T, T>>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void in(vector<multiset<pair<T, T>>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<multiset<pair<T, T>>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<multiset<pair<T, T>>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void out(vector<multiset<pair<T, T>>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<multiset<pair<T, T>>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void in(vector<map<pair<T, T>, T>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<map<pair<T, T>, T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void out(vector<map<pair<T, T>, T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void in(set<vector<pair<T, T>>>>& s) { for (auto& e : s) in(e); }
template<typename T> inline void out(set<vector<pair<T, T>>>>& s) { for (auto& e : s) out(e); }
template<typename T> inline void outln(set<vector<pair<T, T>>>>& s) { for (auto& e : s) outln(e); }
template<typename T> inline void in(multiset<vector<pair<T, T>>>>& s) { for (auto& e : s) in(e); }
template<typename T> inline void out(multiset<vector<pair<T, T>>>>& s) { for (auto& e : s) out(e); }
template<typename T> inline void outln(multiset<vector<pair<T, T>>>>& s) { for (auto& e : s) outln(e); }
template<typename T> inline void in(vector<map<pair<T, T>, T>>>& v) { for (auto& e : v) in(e); }
template<typename T> inline void out(vector<map<pair<T, T>, T>>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>>& v) { for (int i = 0; i < sz(v); ++i) { out(v[i]); } }
template<typename T> inline void out(vector<map<pair<T, T>, T>>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>>& v, int n) { for (int i = 0; i < n; ++i) { out(v[i]); } }
template<typename T> inline void out(set<vector<pair<T, T>>>& s, int n) { int i = 0; for (auto& e : s) { out(e); ++i; if (i == n) break; } }
template<typename T> inline void outln(set<vector<pair<T, T>>>& s, int n) { int i = 0; for (auto& e : s) { outln(e); ++i; if (i == n) break; } }
template<typename T> inline void out(multiset<vector<pair<T, T>>>& s, int n) { int i = 0; for (auto& e : s) { out(e); ++i; if (i == n) break; } }
template<typename T> inline void outln(multiset<vector<pair<T, T>>>& s, int n) { int i = 0; for (auto& e : s) { outln(e); ++i; if (i == n) break; } }
template<typename T> inline void out(vector<map<pair<T, T>, T>>& v, int n) { int i = 0; for (auto& e : v) { out(e); ++i; if (i == n) break; } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>& v, int n) { int i = 0; for (auto& e : v) { outln(e); ++i; if (i == n) break; } }
template<typename T> inline void out(set<vector<pair<T, T>>>>& s, int n) { int i = 0; for (auto& e : s) { out(e); ++i; if (i == n) break; } }
template<typename T> inline void outln(set<vector<pair<T, T>>>>& s, int n) { int i = 0; for (auto& e : s) { outln(e); ++i; if (i == n) break; } }
template<typename T> inline void out(multiset<vector<pair<T, T>>>>& s, int n) { int i = 0; for (auto& e : s) { out(e); ++i; if (i == n) break; } }
template<typename T> inline void outln(multiset<vector<pair<T, T>>>>& s, int n) { int i = 0; for (auto& e : s) { outln(e); ++i; if (i == n) break; } }
template<typename T> inline void out(vector<map<pair<T, T>, T>>>& v, int n) { int i = 0; for (auto& e : v) { out(e); ++i; if (i == n) break; } }
template<typename T> inline void outln(vector<map<pair<T, T>, T>>>& v, int n) { int i = 0; for (auto& e : v) { outln(e); ++i; if (i == n) break; } }

ll pow(ll x, ll p, ll mod) {
    if (p <= 0) {
        return 1;
    }
    ll th = pow(x, p / 2, mod);
    th *= th;
    th %= mod;
    if (p % 2 == 1) {
        th *= x;
    }
    return th;
}

class Fraction {
public:
    ll x;
    ll y;

    Fraction(ll x, ll y) {
        this->x = x;
        this->y = y;
    }

    void norm() {
        ll gcd = __gcd(x, y);
        x /= gcd;
        y /= gcd;
    }

    bool operator<(const Fraction& o) const {
        if (x > o.x) {
            return false;
        }
        if (x < o.x) {
            return true;
        }
        if (y > o.y) {
            return false;
        }
        if (y < o.y) {
            return true;
        }
        return false;
    }
};

Fraction sum(Fraction a, Fraction b) {
    Fraction c = Fraction(a.x * b.y + a.y * b.x, a.y * b.y);
    c.norm();
    return c;
}

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    if (x == 0) {
        return y;
    }
    return gcd(y, x % y);
}

class Pair {
public:
    int x;
    int y;

    Pair(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Pair clone() {
        return Pair(x, y);
    }

    bool operator<(const Pair& o) const {
        if (x > o.x) {
            return false;
        }
        if (x < o.x) {
            return true;
        }
        if (y > o.y) {
            return false;
        }
        if (y < o.y) {
            return true;
        }
        return false;
    }
};

ll mod = 1000000007;

vector<ll> mult1(vector<ll>& a, vector<ll>& b) {
    int n = a.size();
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            c[i] += a[i ^ k] * b[k];
            c[i] %= mod;
        }
    }
    return c;
}

vector<vector<ll>> mult(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    int n = a.size();
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> pow(vector<vector<ll>>& x, ll p) {
    if (p == 0) {
        vector<vector<ll>> e(x.size(), vector<ll>(x.size()));
        for (int i = 0; i < e.size(); i++) {
            e[i][i] = 1;
        }
        return e;
    }
    vector<vector<ll>> ans = pow(x, p / 2);
    ans = mult(ans, ans);
    if (p % 2 == 1) {
        ans = mult(ans, x);
    }
    return ans;
}

vector<ll> mult(vector<ll>& a, vector<ll>& b) {
    int n = a.size();
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            c[i] += a[k] * b[k ^ i];
            c[i] %= mod;
        }
    }
    return c;
}

vector<ll> pow(vector<ll>& x, ll p) {
    if (p == 0) {
        vector<ll> e(x.size());
        e[0] = 1;
        return e;
    }
    vector<ll> ans = pow(x, p / 2);
    ans = mult(ans, ans);
    if (p % 2 == 1) {
        ans = mult(ans, x);
    }
    return ans;
}

ll pow(ll x, ll p) {
    if (p <= 0) {
        return 1;
    }
    ll ans = pow(x, p / 2);
    ans = (ans * ans) % mod;
    if (p % 2 == 1) {
        ans = (ans * x) % mod;
    }
    return ans;
}

ll modInv(ll x) {
    return pow(x, mod - 2);
}

Random random = new Random(566);
vector<vector<int>> to;

class Factorizator {
public:
    vector<int> div;
    vector<int> primes;

    Factorizator(int max) {
        div = vector<int>(max + 1);
        for (int i = 2; i < div.size(); i++) {
            if (div[i] == 0) {
                div[i] = i;
                primes.push_back(i);
            }
            for (int j : primes) {
                if (i * j > max) {
                    break;
                }
                div[i * j] = j;
            }
        }
    }

    vector<int> factorization(int x) {
        vector<int> ans;
        while (div[x] > 0) {
            ans.push_back(div[x]);
            x /= div[x];
        }
        return ans;
    }

    vector<int> all_divisors(int x) {
        vector<int> div = factorization(x);
        int len = div.size();
        set<int> set;
        for (int mask = 0; mask < (1 << len); mask++) {
            int th = 1;
            for (int i = 0; i < len; i++) {
                if ((mask & (1 << i)) > 0) {
                    th *= div[i];
                }
            }
            set.insert(th);
        }
        vector<int> ans(set.size());
        int iter = 0;
        for (int i : set) {
            ans[iter++] = i;
        }
        return ans;
    }

    vector<int> divisors(int x) {
        vector<int> div = factorization(x);
        int pr = 0;
        for (int i = 0; i < div.size(); i++) {
            if (i == 0 || div[i] != div[i - 1]) {
                pr++;
            }
        }
        vector<int> primes(pr);
        vector<int> sz(pr);
        pr = -1;
        for (int i = 0; i < div.size(); i++) {
            if (i == 0 || div[i] != div[i - 1]) {
                pr++;
                primes[pr] = div[i];
                sz[pr] = 1;
            } else {
                sz[pr]++;
            }
        }
        pr++;
        vector<vector<int>> pow(pr);
        for (int i = 0; i < pow.size(); i++) {
            pow[i] = vector<int>(sz[i] + 1);
            pow[i][0] = 1;
            for (int j = 1; j < pow[i].size(); j++) {
                pow[i][j] = pow[i][j - 1] * primes[i];
            }
        }
        vector<int> th(pr);
        set<int> ans;
        do {
            int z = 1;
            for (int i = 0; i < th.size(); i++) {
                z *= pow[i][th[i]];
            }
            ans.insert(z);
        } while (next(th, sz));
        vector<int> answer(ans.size());
        int iter = 0;
        for (int i : ans) {
            answer[iter++] = i;
        }
        return answer;
    }

    bool next(vector<int>& th, vector<int>& max) {
        for (int i = th.size() - 1; i >= 0; i--) {
            if (th[i] != max[i]) {
                th[i]++;
                for (int j = i + 1; j < max.size(); j++) {
                    th[j] = 0;
                }
                return true;
            }
        }
        return false;
    }

    string factorizationToString(int x) {
        if (x == 1) {
            return "1 = 1";
        }
        vector<int> list = factorization(x);
        string ans = to_string(x) + " = ";
        for (int i = 0; i < list.size(); i++) {
            ans += to_string(list[i]);
            if (i < list.size() - 1) {
                ans += " * ";
            }
        }
        return ans;
    }
};

class Rect {
public:
    int x1;
    int y1;
    int x2;
    int y2;

    Rect(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    string toString() {
        return to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
    }

    bool equals(Rect r) {
        return x1 == r.x1 && y1 == r.y1 && x2 == r.x2 && y2 == r.y2;
    }

    int inside(int x, int y) {
        int inx = in(x1, x2, x);
        int iny = in(y1, y2, y);
        return inx * iny;
    }

    int additional(Rect r) {
        if (equals(r)) {
            return 0;
        }
        if (inside(r.x1, r.y1) == 4 || inside(r.x2, r.y2) == 4 || inside(r.x1, r.y2) == 4
                || inside(r.x2, r.y1) == 4) {
            return 1;
        }
        if (inside(r.x1, r.y1) == 1 || inside(r.x2, r.y2) == 1) {
            return 1;
        }
        return 2;
    }
};

int in(int min, int max, int x) {
    if (x == min || x == max) {
        return 1;
    }
    if (x > min && x < max) {
        return 2;
    }
    return 0;
}

int sum(int x, int y) {
    if (x + y >= mod) {
        return x + y - mod;
    }
    return x + y;
}

ll mult(ll x, ll y) {
    return x * y % mod;
}

ll div(ll x, ll y) {
    return x * modInv(y) % mod;
}

int mod = 1000000007;

class Fenvik {
public:
    vector<ll> sum;

    Fenvik(int n) {
        sum = vector<ll>(n);
    }

    void add(int x, ll d) {
        for (int i = x; i < sum.size(); i = (i | (i + 1))) {
            sum[i] += d;
        }
    }

    ll sum(int r) {
        ll ans = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
            ans += sum[i];
        }
        return ans;
    }

    ll sum(int l, int r) {
        if (l > r) {
            return 0;
        }
        return sum(r) - sum(l - 1);
    }
};

class SegmentTreeAdd {
public:
    int pow;
    vector<ll> max;
    vector<ll> delta;
    vector<bool> flag;

    SegmentTreeAdd(vector<ll>& a) {
        pow = 1;
        while (pow < a.size()) {
            pow *= 2;
        }
        flag = vector<bool>(2 * pow);
        max = vector<ll>(2 * pow);
        delta = vector<ll>(2 * pow);
        for (int i = 0; i < max.size(); i++) {
            max[i] = LLONG_MIN / 2;
        }
        for (int i = 0; i < a.size(); i++) {
            max[pow + i] = a[i];
        }
        for (int i = pow - 1; i > 0; i--) {
            max[i] = f(max[2 * i], max[2 * i + 1]);
        }
    }

    SegmentTreeAdd(int n) {
        pow = 1;
        while (pow < n) {
            pow *= 2;
        }
        flag = vector<bool>(2 * pow);
        max = vector<ll>(2 * pow);
        delta = vector<ll>(2 * pow);
    }

    ll get(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) {
            return LLONG_MIN / 2;
        }
        if (l == tl && r == tr) {
            return max[v];
        }
        int tm = (tl + tr) / 2;
        return f(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void set(int v, int tl, int tr, int l, int r, ll x) {
        push(v, tl, tr);
        if (l > tr || r < tl) {
            return;
        }
        if (l <= tl && r >= tr) {
            delta[v] += x;
            flag[v] = true;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        set(2 * v, tl, tm, l, r, x);
        set(2 * v + 1, tm + 1, tr, l, r, x);
        max[v] = f(max[2 * v], max[2 * v + 1]);
    }

    void push(int v, int tl, int tr) {
        if (flag[v]) {
            if (v < pow) {
                flag[2 * v] = true;
                flag[2 * v + 1] = true;
                delta[2 * v] += delta[v];
                delta[2 * v + 1] += delta[v];
            }
            flag[v] = false;
            max[v] += delta[v];
            delta[v] = 0;
        }
    }

    ll f(ll a, ll b) {
        return max(a, b);
    }
};

class Circle {
public:
    int x;
    int y;
    int r;

    Circle(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }

    Circle clone() {
        return Circle(x, y, r);
    }

    bool operator<(const Circle& o) const {
        if (r != o.r) {
            return r < o.r;
        }
        if (x != o.x) {
            return x < o.x;
        }
        return y < o.y;
    }
};

bool inside(Circle small, Circle big) {
    return (small.x - big.x) * (small.x - big.x) + (small.y - big.y) * (small.y - big.y) <= (big.r - small.r)
            * (big.r - small.r);
}

vector<double> tangent(Circle c1, Circle c2) {
    Circle a = c1.clone();
    Circle b = c2.clone();
    int minr = min(a.r, b.r);
    a.r -= minr;
    b.r -= minr;
    b.x -= a.x;
    b.y -= a.y;
    double a0 = atan2(b.y, b.x);
    double len = sqrt(b.x * b.x + b.y * b.y);
    double da = 0;
    if (a.r == 0) {
        da = asin(b.r / len) + PI / 2;
    } else {
        da = acos(a.r / len);
    }
    vector<double> ans = { a0 - da, a0 + da };
    return ans;
}

vector<double> norm(vector<double>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        while (ans[i] < 0) {
            ans[i] += 2 * PI;
        }
        while (ans[i] > 2 * PI) {
            ans[i] -= 2 * PI;
        }
    }
    if (ans[0] > ans[1]) {
        vector<double> answer = { 0, ans[1], ans[0], 2 * PI };
        return answer;
    }
    return ans;
}

bool mergeSort(string s, vector<int>& a, int l, int r) {
    if (r - l <= 1) {
        return true;
    }
    int m = (l + r) >> 1;
    if (!mergeSort(s, a, l, m)) {
        return false;
    }
    if (!mergeSort(s, a, m, r)) {
        return false;
    }
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (x == s.length()) {
            return false;
        }
        if (s[x++] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i < m) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int p = l; p < r; p++) {
        a[p] = b[p];
    }
    return true;
}

vector<int> rev(vector<int>& a) {
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); ++i) {
        res[a[i]] = i;
    }
    return res;
}

void solve() {
    string s;
    in(s);
    int l = 0;
    int r = 100001;
    while (true) {
        int sz = (l + r) >> 1;
        vector<int> a(sz);
        for (int i = 0; i < a.size(); i++) {
            a[i] = i;
        }
        x = 0;
        b = vector<int>(sz);
        if (!mergeSort(s, a, 0, sz)) {
            r = sz;
            continue;
        }
        if (x < s.length()) {
            l = sz;
            continue;
        }
        a = rev(a);
        outln(sz);
        for (int i = 0; i < a.size(); i++) {
            outsp(a[i] + 1);
        }
        return;
    }
}

int main() {
    fastIO();
    solve();
    return 0;
}
