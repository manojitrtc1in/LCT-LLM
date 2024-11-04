#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
#include <bitset>
#include <functional>
#include <numeric>
#include <complex>
#include <array>
#include <chrono>
#include <random>
#include <unordered_set>
#include <unordered_map>

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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for (int i = (b) - 1; i >= (a); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define MEMSET(v, a) memset(v, a, sizeof(v))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define PB push_back
#define MP make_pair
#define X first
#define Y second

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL << 60;
const int MOD = 1000000007;

template <typename T>
void chmin(T& a, const T& b) {
    a = min(a, b);
}

template <typename T>
void chmax(T& a, const T& b) {
    a = max(a, b);
}

template <typename T>
void printv(const vector<T>& v) {
    REP(i, SZ(v)) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printvv(const vector<vector<T>>& vv) {
    REP(i, SZ(vv)) {
        REP(j, SZ(vv[i])) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void printset(const set<T>& s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template <typename T>
void printmap(const map<T, T>& m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

template <typename T>
void printpq(T& pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

template <typename T>
void printstack(T& st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

template <typename T>
void printbitset(T x, int len) {
    string s = bitset<64>(x).to_string();
    cout << s.substr(64 - len, len) << endl;
}

template <typename T>
void printarray(T* arr, int len) {
    REP(i, len) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printmatrix(T** mat, int rows, int cols) {
    REP(i, rows) {
        REP(j, cols) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void printcoord(T x, T y) {
    cout << "(" << x << ", " << y << ")" << endl;
}

template <typename T>
void printcoord3(T x, T y, T z) {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

template <typename T>
void printcoord4(T x, T y, T z, T w) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ")" << endl;
}

template <typename T>
void printcoord5(T x, T y, T z, T w, T u) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ")" << endl;
}

template <typename T>
void printcoord6(T x, T y, T z, T w, T u, T v) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ")" << endl;
}

template <typename T>
void printcoord7(T x, T y, T z, T w, T u, T v, T t) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ")" << endl;
}

template <typename T>
void printcoord8(T x, T y, T z, T w, T u, T v, T t, T s) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ")" << endl;
}

template <typename T>
void printcoord9(T x, T y, T z, T w, T u, T v, T t, T s, T r) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ")" << endl;
}

template <typename T>
void printcoord10(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ")" << endl;
}

template <typename T>
void printcoord11(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ")" << endl;
}

template <typename T>
void printcoord12(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ")" << endl;
}

template <typename T>
void printcoord13(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ")" << endl;
}

template <typename T>
void printcoord14(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ")" << endl;
}

template <typename T>
void printcoord15(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ")" << endl;
}

template <typename T>
void printcoord16(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ")" << endl;
}

template <typename T>
void printcoord17(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ")" << endl;
}

template <typename T>
void printcoord18(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ")" << endl;
}

template <typename T>
void printcoord19(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ")" << endl;
}

template <typename T>
void printcoord20(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ")" << endl;
}

template <typename T>
void printcoord21(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ")" << endl;
}

template <typename T>
void printcoord22(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ")" << endl;
}

template <typename T>
void printcoord23(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ")" << endl;
}

template <typename T>
void printcoord24(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ")" << endl;
}

template <typename T>
void printcoord25(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ")" << endl;
}

template <typename T>
void printcoord26(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ")" << endl;
}

template <typename T>
void printcoord27(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ")" << endl;
}

template <typename T>
void printcoord28(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ")" << endl;
}

template <typename T>
void printcoord29(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ")" << endl;
}

template <typename T>
void printcoord30(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ")" << endl;
}

template <typename T>
void printcoord31(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ")" << endl;
}

template <typename T>
void printcoord32(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ")" << endl;
}

template <typename T>
void printcoord33(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ")" << endl;
}

template <typename T>
void printcoord34(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ")" << endl;
}

template <typename T>
void printcoord35(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ")" << endl;
}

template <typename T>
void printcoord36(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ")" << endl;
}

template <typename T>
void printcoord37(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj, T kk) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ", " << kk << ")" << endl;
}

template <typename T>
void printcoord38(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj, T kk, T ll) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ", " << kk << ", " << ll << ")" << endl;
}

template <typename T>
void printcoord39(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj, T kk, T ll, T mm) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ", " << kk << ", " << ll << ", " << mm << ")" << endl;
}

template <typename T>
void printcoord40(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj, T kk, T ll, T mm, T nn) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ", " << kk << ", " << ll << ", " << mm << ", " << nn << ")" << endl;
}

template <typename T>
void printcoord41(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj, T kk, T ll, T mm, T nn, T oo) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ", " << kk << ", " << ll << ", " << mm << ", " << nn << ", " << oo << ")" << endl;
}

template <typename T>
void printcoord42(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj, T kk, T ll, T mm, T nn, T oo, T pp) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ", " << kk << ", " << ll << ", " << mm << ", " << nn << ", " << oo << ", " << pp << ")" << endl;
}

template <typename T>
void printcoord43(T x, T y, T z, T w, T u, T v, T t, T s, T r, T q, T p, T o, T n, T m, T l, T k, T j, T i, T h, T g, T f, T e, T d, T c, T b, T a, T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii, T jj, T kk, T ll, T mm, T nn, T oo, T pp, T qq) {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ", " << u << ", " << v << ", " << t << ", " << s << ", " << r << ", " << q << ", " << p << ", " << o << ", " << n << ", " << m << ", " << l << ", " << k << ", " << j << ", " << i << ", " << h << ", " << g << ", " << f << ", " << e << ", " << d << ", " << c << ", " << b << ", " << a << ", " << aa << ", " << bb << ", " << cc << ", " << dd << ", " << ee << ", " << ff << ", " << gg << ", " << hh << ", " << ii << ", " << jj << ", " << kk << ", " << ll << ", " << mm << ", " << nn << ", " << oo << ", " << pp << ", " << qq << ")" << endl;
}

template <typename T>
