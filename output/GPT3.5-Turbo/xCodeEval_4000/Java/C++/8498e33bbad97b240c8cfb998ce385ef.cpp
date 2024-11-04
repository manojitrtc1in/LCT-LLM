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
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
#include <functional>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORIT(i, a) for (auto i = (a).begin(); i != (a).end(); ++i)
#define REPD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define SIZE(c) (int) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define LL long long
#define ULL unsigned long long
#define LD long double
#define VI vector<int>
#define PII pair<int, int>
#define VVI vector<VI >
#define PLL pair<LL, LL>
#define VLL vector<LL>
#define VPLL vector<PLL >
#define VVLL vector<VLL >
#define VB vector<bool>
#define VS vector<string>
#define VVB vector<VB >
#define VVS vector<VS >
#define VLD vector<LD>
#define VVLD vector<VLD >
#define VPII vector<PII >
#define VVPII vector<VPII >
#define VPLL vector<PLL >
#define VVPLL vector<VPLL >

const int INF = 1000000000;
const LL LLINF = 1000000000000000000LL;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template<class T>
inline string toStr(const T& x) {
    stringstream s;
    s << x;
    return s.str();
}

template<class T>
inline T fromStr(const string& s) {
    stringstream sstr(s);
    T ret;
    sstr >> ret;
    return ret;
}

template<class T>
inline void mini(T& a, const T& b) {
    if (b < a)
        a = b;
}

template<class T>
inline void maxi(T& a, const T& b) {
    if (b > a)
        a = b;
}

template<class T>
inline T sqr(const T& x) {
    return x * x;
}

template<class T>
inline int sign(const T& x) {
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

template<class T>
inline bool uin(const T& x, const T& y, const T& z) {
    return x <= y && y <= z;
}

template<class T>
inline bool uax(const T& x, const T& y, const T& z) {
    return x >= y && y >= z;
}

template<class T>
inline void uniq(vector<T>& x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
}

template<class T>
inline T next(vector<T>& x, const T& y) {
    auto it = upper_bound(x.begin(), x.end(), y);
    if (it == x.end())
        return -1;
    return *it;
}

template<class T>
inline T prev(vector<T>& x, const T& y) {
    auto it = lower_bound(x.begin(), x.end(), y) - 1;
    if (it < x.begin())
        return -1;
    return *it;
}

template<class T>
inline int lwb(const vector<T>& x, const T& y) {
    return lower_bound(x.begin(), x.end(), y) - x.begin();
}

template<class T>
inline int upb(const vector<T>& x, const T& y) {
    return upper_bound(x.begin(), x.end(), y) - x.begin();
}

template<class T>
inline void reverse(vector<T>& x) {
    reverse(x.begin(), x.end());
}

template<class T>
inline void sort(vector<T>& x) {
    sort(x.begin(), x.end());
}

template<class T>
inline void reverseSort(vector<T>& x) {
    sort(x.rbegin(), x.rend());
}

template<class T>
inline void sort(vector<T>& x, function<bool(const T&, const T&)> cmp) {
    sort(x.begin(), x.end(), cmp);
}

template<class T>
inline void reverseSort(vector<T>& x, function<bool(const T&, const T&)> cmp) {
    sort(x.rbegin(), x.rend(), cmp);
}

template<class T>
inline void readVector(vector<T>& x, int n) {
    x.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
}

template<class T>
inline void writeVector(const vector<T>& x) {
    for (int i = 0; i < SIZE(x); ++i)
        cout << x[i] << " ";
    cout << endl;
}

template<class T>
inline void readArray(T* x, int n) {
    for (int i = 0; i < n; ++i)
        cin >> x[i];
}

template<class T>
inline void writeArray(const T* x, int n) {
    for (int i = 0; i < n; ++i)
        cout << x[i] << " ";
    cout << endl;
}

template<class T>
inline void print(const T& x) {
    cout << x << endl;
}

template<class T>
inline void print(const vector<T>& x) {
    writeVector(x);
}

template<class T>
inline void print(const set<T>& x) {
    for (auto it = x.begin(); it != x.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

template<class T>
inline void print(const multiset<T>& x) {
    for (auto it = x.begin(); it != x.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

template<class T1, class T2>
inline void print(const map<T1, T2>& x) {
    for (auto it = x.begin(); it != x.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}

template<class T1, class T2>
inline void print(const unordered_map<T1, T2>& x) {
    for (auto it = x.begin(); it != x.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}

template<class T>
inline void print(const vector<vector<T>>& x) {
    for (int i = 0; i < SIZE(x); ++i)
        writeVector(x[i]);
}

template<class T>
inline void print(const T& x, int n) {
    for (int i = 0; i < n; ++i)
        cout << x << " ";
    cout << endl;
}

template<class T>
inline void print(const T& x, int r, int c) {
    for (int i = 0; i < r; ++i)
        writeVector(x, c);
}

template<class T>
inline void print(const vector<vector<T>>& x, int r, int c) {
    for (int i = 0; i < r; ++i)
        writeVector(x[i], c);
}

template<class T>
inline void print(const T& x, int a, int b, int c) {
    for (int i = 0; i < a; ++i)
        print(x, b, c);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c) {
    for (int i = 0; i < a; ++i)
        print(x, b, c);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e, f);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e, f);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e, f, g);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e, f, g);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e, f, g, h);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h) {
    for (int i = 0; i < a; ++i)
        print(x, b, c, d, e, f, g, h);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    for (int j = 0; j < a; ++j)
        print(x, b, c, d, e, f, g, h, i);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    for (int j = 0; j < a; ++j)
        print(x, b, c, d, e, f, g, h, i);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    for (int k = 0; k < a; ++k)
        print(x, b, c, d, e, f, g, h, i, j);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    for (int k = 0; k < a; ++k)
        print(x, b, c, d, e, f, g, h, i, j);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
    for (int l = 0; l < a; ++l)
        print(x, b, c, d, e, f, g, h, i, j, k);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
    for (int l = 0; l < a; ++l)
        print(x, b, c, d, e, f, g, h, i, j, k);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    for (int m = 0; m < a; ++m)
        print(x, b, c, d, e, f, g, h, i, j, k, l);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    for (int m = 0; m < a; ++m)
        print(x, b, c, d, e, f, g, h, i, j, k, l);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
    for (int n = 0; n < a; ++n)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
    for (int n = 0; n < a; ++n)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    for (int o = 0; o < a; ++o)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    for (int o = 0; o < a; ++o)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
    for (int p = 0; p < a; ++p)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
    for (int p = 0; p < a; ++p)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
    for (int q = 0; q < a; ++q)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
    for (int q = 0; q < a; ++q)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q) {
    for (int r = 0; r < a; ++r)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q) {
    for (int r = 0; r < a; ++r)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r) {
    for (int s = 0; s < a; ++s)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r) {
    for (int s = 0; s < a; ++s)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s) {
    for (int t = 0; t < a; ++t)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s) {
    for (int t = 0; t < a; ++t)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t) {
    for (int u = 0; u < a; ++u)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t) {
    for (int u = 0; u < a; ++u)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u) {
    for (int v = 0; v < a; ++v)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u) {
    for (int v = 0; v < a; ++v)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v) {
    for (int w = 0; w < a; ++w)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v) {
    for (int w = 0; w < a; ++w)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w) {
    for (int x = 0; x < a; ++x)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w) {
    for (int x = 0; x < a; ++x)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x) {
    for (int y = 0; y < a; ++y)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x) {
    for (int y = 0; y < a; ++y)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x);
}

template<class T>
inline void print(const T& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x, int y) {
    for (int z = 0; z < a; ++z)
        print(x, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y);
}

template<class T>
inline void print(const vector<vector<T>>& x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x, int y) {
    for (int z = 0; z < a; ++z)
