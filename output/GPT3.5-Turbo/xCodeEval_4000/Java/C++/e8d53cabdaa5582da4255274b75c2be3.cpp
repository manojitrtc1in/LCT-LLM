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
#include <cctype>
#include <array>
#include <tuple>
#include <regex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define debug(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<double> VD;
typedef vector<string> VS;

template <typename T>
void printV(const vector<T>& vec) {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
}

template <typename T>
void printVV(const vector<vector<T>>& vvec) {
    int n = vvec.size();
    rep(i, n) {
        printV(vvec[i]);
    }
}

template <typename T>
void printP(const pair<T, T>& p) {
    cout << p.fi << " " << p.se << endl;
}

template <typename T>
void printVP(const vector<pair<T, T>>& vp) {
    int n = vp.size();
    rep(i, n) {
        printP(vp[i]);
    }
}

template <typename T>
void print(const T& x) {
    cout << x << endl;
}

template <typename T>
void print(const vector<T>& vec) {
    int n = vec.size();
    rep(i, n) {
        print(vec[i]);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec) {
    int n = vvec.size();
    rep(i, n) {
        print(vvec[i]);
    }
}

template <typename T>
void print(const pair<T, T>& p) {
    printP(p);
}

template <typename T>
void print(const vector<pair<T, T>>& vp) {
    printVP(vp);
}

template <typename T>
void print(const set<T>& s) {
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

template <typename T>
void print(const multiset<T>& s) {
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

template <typename T>
void print(const unordered_set<T>& s) {
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

template <typename T>
void print(const unordered_multiset<T>& s) {
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

template <typename T, typename U>
void print(const map<T, U>& m) {
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << ": " << itr->second << endl;
    }
}

template <typename T, typename U>
void print(const unordered_map<T, U>& m) {
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << ": " << itr->second << endl;
    }
}

template <typename T>
void print(const complex<T>& c) {
    cout << c.real() << " " << c.imag() << endl;
}

template <typename T>
void print(const vector<complex<T>>& v) {
    int n = v.size();
    rep(i, n) {
        print(v[i]);
    }
}

template <typename T>
void print(const T* a, int n) {
    rep(i, n) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
}

template <typename T>
void print(const T* a, int n, int m) {
    rep(i, n) {
        print(a[i], m);
    }
}

template <typename T>
void print(const vector<T>& vec, int n) {
    rep(i, n) {
        cout << vec[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n) {
    rep(i, n) {
        print(vvec[i]);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m) {
    rep(i, n) {
        print(vec[i], m);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m) {
    rep(i, n) {
        print(vvec[i], m);
    }
}

template <typename T>
void print(const T& x, int n) {
    rep(i, n) {
        print(x);
    }
}

template <typename T>
void print(const T& x, int n, int m) {
    rep(i, n) {
        print(x, m);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep) {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i != n - 1) cout << sep;
    }
    cout << endl;
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep) {
    int n = vvec.size();
    rep(i, n) {
        print(vvec[i], sep);
    }
}

template <typename T>
void print(const T& x, const string& sep) {
    cout << x << sep;
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n) {
    rep(i, n) {
        cout << vec[i];
        if (i != n - 1) cout << sep;
    }
    cout << endl;
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n) {
    rep(i, n) {
        print(vvec[i], sep);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m) {
    rep(i, n) {
        print(x, sep, m);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(x, sep, m, k);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m) {
    rep(i, n) {
        print(vec[i], sep, m);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m) {
    rep(i, n) {
        print(vvec[i], sep, m);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(vec[i], sep, m, k);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(vvec[i], sep, m, k);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep) {
    rep(i, n) {
        cout << a[i];
        if (i != n - 1) cout << sep;
    }
    cout << endl;
}

template <typename T>
void print(const T* a, int n, int m, const string& sep) {
    rep(i, n) {
        print(a[i], m, sep);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep) {
    rep(i, n) {
        cout << vec[i];
        if (i != n - 1) cout << sep;
    }
    cout << endl;
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep) {
    rep(i, n) {
        print(vvec[i], sep);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep) {
    rep(i, n) {
        print(vec[i], m, sep);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep) {
    rep(i, n) {
        print(vvec[i], sep);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(vec[i], sep, m, k);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(vvec[i], sep, m, k);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(x, sep, m, k);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(x, sep, m, k, l);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(vec[i], sep, m, k);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k) {
    rep(i, n) {
        print(vvec[i], sep, m, k);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(vec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m) {
    rep(i, n) {
        print(a[i], sep, m);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k) {
    rep(i, n) {
        print(a[i], m, sep, k);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m) {
    rep(i, n) {
        print(vec[i], sep, m);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m) {
    rep(i, n) {
        print(vvec[i], sep, m);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k) {
    rep(i, n) {
        print(vec[i], m, sep, k);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k) {
    rep(i, n) {
        print(vvec[i], sep, m, k);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(vec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(x, sep, m, k, l);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(x, sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(vec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k) {
    rep(i, n) {
        print(a[i], sep, m, k);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l) {
    rep(i, n) {
        print(a[i], m, sep, k, l);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k) {
    rep(i, n) {
        print(vec[i], sep, m, k);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k) {
    rep(i, n) {
        print(vvec[i], sep, m, k);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k, int l) {
    rep(i, n) {
        print(vec[i], m, sep, k, l);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k, int l) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(x, sep, m, k, l, o);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k, int l) {
    rep(i, n) {
        print(a[i], sep, m, k, l);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l, int o) {
    rep(i, n) {
        print(a[i], m, sep, k, l, o);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k, int l) {
    rep(i, n) {
        print(vec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k, int l) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k, int l, int o) {
    rep(i, n) {
        print(vec[i], m, sep, k, l, o);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k, int l, int o) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k, int l, int o) {
    rep(i, n) {
        print(a[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l, int o, int p) {
    rep(i, n) {
        print(a[i], m, sep, k, l, o, p);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k, int l, int o) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k, int l, int o) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k, int l, int o, int p) {
    rep(i, n) {
        print(vec[i], m, sep, k, l, o, p);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k, int l, int o, int p) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(a[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(a[i], m, sep, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k, int l, int o, int p) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vec[i], m, sep, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(a[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(a[i], m, sep, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k, int l, int o, int p, int q) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vec[i], m, sep, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(a[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(a[i], m, sep, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vec[i], m, sep, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const T& x, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u) {
    rep(i, n) {
        print(x, sep, m, k, l, o, p, q, r, s, t, u);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s, t, u);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s, t, u);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(a[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(a[i], m, sep, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vec[i], m, sep, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const vector<T>& vec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s, t, u);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, const string& sep, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s, t, u);
    }
}

template <typename T>
void print(const T* a, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r, int s, int t) {
    rep(i, n) {
        print(a[i], sep, m, k, l, o, p, q, r, s, t);
    }
}

template <typename T>
void print(const T* a, int n, int m, const string& sep, int k, int l, int o, int p, int q, int r, int s, int t, int u) {
    rep(i, n) {
        print(a[i], m, sep, k, l, o, p, q, r, s, t, u);
    }
}

template <typename T>
void print(const vector<T>& vec, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
void print(const vector<vector<T>>& vvec, int n, const string& sep, int m, int k, int l, int o, int p, int q, int r, int s) {
    rep(i, n) {
        print(vvec[i], sep, m, k, l, o, p, q, r, s);
    }
}

template <typename T>
