#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#include <cassert>
#include <ctime>
#include <bitset>
#include <functional>
#include <numeric>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repd(i, n) for (int i = (n) - 1; i >= 0; --i)
#define repa(i, a, n) for (int i = (a); i < (n); ++i)
#define repad(i, a, n) for (int i = (n) - 1; i >= (a); --i)
#define trav(a, x) for (auto& a : x)
#define allsta(a, x) for (auto a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define debug(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }
template<typename T> bool has(T& s, typename T::value_type x) { return s.find(x) != s.end(); }
template<typename T> void del(T& s, typename T::value_type x) { if (has(s, x)) s.erase(s.find(x)); }
template<typename T> void add(T& s, typename T::value_type x) { s.insert(x); }

template<typename T> void uniq(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
template<typename T> int lwb(const vector<T>& a, const T& b) { return lower_bound(all(a), b) - a.begin(); }
template<typename T> int upb(const vector<T>& a, const T& b) { return upper_bound(all(a), b) - a.begin(); }

template<typename T> void make_unique(vector<T>& a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void make_unique(string& s) { string tmp = s; sort(all(tmp)); s.erase(unique(all(tmp)), s.end()); }

template<typename T> void relax(T& a, const T& b) { a = min(a, b); }
template<typename T> void tense(T& a, const T& b) { a = max(a, b); }

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T> T sqr(const T& a) { return a * a; }

template<typename T> int sign(const T& a) { return a < 0 ? -1 : (a > 0 ? 1 : 0); }

template<typename T> T bpow(T x, T n, T mod) { T res = 1; while (n) { if (n & 1) res = res * x % mod; x = x * x % mod; n >>= 1; } return res; }
template<typename T> T bpow(T x, T n) { T res = 1; while (n) { if (n & 1) res = res * x; x = x * x; n >>= 1; } return res; }

template<typename T> void read(T& x) { cin >> x; }
template<typename T> void read(vector<T>& v) { for (auto& x : v) read(x); }
template<typename T> void read(vector<vector<T>>& v) { for (auto& x : v) read(x); }
template<typename T> void write(const T& x) { cout << x; }
template<typename T> void write(const vector<T>& v) { for (auto& x : v) write(x), write(' '); }
template<typename T> void write(const vector<vector<T>>& v) { for (auto& x : v) write(x), write('\n'); }
template<typename T> void writeln(const T& x) { write(x), write('\n'); }

template<typename T> void readln(T& x) { read(x), readln(); }
template<typename T> void readln(vector<T>& v) { read(v), readln(); }
template<typename T> void readln(vector<vector<T>>& v) { read(v), readln(); }

template<typename T> void writeln(const vector<T>& v) { write(v), write('\n'); }
template<typename T> void writeln(const vector<vector<T>>& v) { write(v), write('\n'); }

template<typename T> void readln(vector<T>& v, int n) { v.resize(n); for (auto& x : v) readln(x); }
template<typename T> void readln(vector<vector<T>>& v, int n) { v.resize(n); for (auto& x : v) readln(x); }

template<typename T> void writeln(const vector<T>& v, int n) { for (int i = 0; i < n; ++i) writeln(v[i]); }

template<typename T> void readln(vector<T>& v, int n, int m) { v.resize(n); for (auto& x : v) readln(x, m); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m) { v.resize(n); for (auto& x : v) readln(x, m); }

template<typename T> void writeln(const vector<T>& v, int n, int m) { for (int i = 0; i < n; ++i) writeln(v[i], m); }

template<typename T> void readln(vector<T>& v, int n, int m, int k) { v.resize(n); for (auto& x : v) readln(x, m, k); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k) { v.resize(n); for (auto& x : v) readln(x, m, k); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k) { for (int i = 0; i < n; ++i) writeln(v[i], m, k); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l) { v.resize(n); for (auto& x : v) readln(x, m, k, l); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l) { v.resize(n); for (auto& x : v) readln(x, m, k, l); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r) { v.resize(n); for (auto& x : v) readln(x, m, k, l, r); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r) { v.resize(n); for (auto& x : v) readln(x, m, k, l, r); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x) { v.resize(n); for (auto& y : v) readln(y, m, k, l, r, x); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x) { v.resize(n); for (auto& y : v) readln(y, m, k, l, r, x); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y) { v.resize(n); for (auto& z : v) readln(z, m, k, l, r, x, y); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y) { v.resize(n); for (auto& z : v) readln(z, m, k, l, r, x, y); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z) { v.resize(n); for (auto& w : v) readln(w, m, k, l, r, x, y, z); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z) { v.resize(n); for (auto& w : v) readln(w, m, k, l, r, x, y, z); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a) { v.resize(n); for (auto& b : v) readln(b, m, k, l, r, x, y, z, a); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a) { v.resize(n); for (auto& b : v) readln(b, m, k, l, r, x, y, z, a); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b) { v.resize(n); for (auto& c : v) readln(c, m, k, l, r, x, y, z, a, b); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b) { v.resize(n); for (auto& c : v) readln(c, m, k, l, r, x, y, z, a, b); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a, b); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c) { v.resize(n); for (auto& d : v) readln(d, m, k, l, r, x, y, z, a, b, c); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c) { v.resize(n); for (auto& d : v) readln(d, m, k, l, r, x, y, z, a, b, c); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a, b, c); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d) { v.resize(n); for (auto& e : v) readln(e, m, k, l, r, x, y, z, a, b, c, d); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d) { v.resize(n); for (auto& e : v) readln(e, m, k, l, r, x, y, z, a, b, c, d); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a, b, c, d); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e) { v.resize(n); for (auto& f : v) readln(f, m, k, l, r, x, y, z, a, b, c, d, e); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e) { v.resize(n); for (auto& f : v) readln(f, m, k, l, r, x, y, z, a, b, c, d, e); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a, b, c, d, e); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f) { v.resize(n); for (auto& g : v) readln(g, m, k, l, r, x, y, z, a, b, c, d, e, f); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f) { v.resize(n); for (auto& g : v) readln(g, m, k, l, r, x, y, z, a, b, c, d, e, f); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a, b, c, d, e, f); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g) { v.resize(n); for (auto& h : v) readln(h, m, k, l, r, x, y, z, a, b, c, d, e, f, g); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g) { v.resize(n); for (auto& h : v) readln(h, m, k, l, r, x, y, z, a, b, c, d, e, f, g); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a, b, c, d, e, f, g); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h) { v.resize(n); for (auto& i : v) readln(i, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h) { v.resize(n); for (auto& i : v) readln(i, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h) { for (int i = 0; i < n; ++i) writeln(v[i], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i) { v.resize(n); for (auto& j : v) readln(j, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i) { v.resize(n); for (auto& j : v) readln(j, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i) { for (int j = 0; j < n; ++j) writeln(v[j], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) { v.resize(n); for (auto& k : v) readln(k, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) { v.resize(n); for (auto& k : v) readln(k, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) { for (int k = 0; k < n; ++k) writeln(v[k], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1) { v.resize(n); for (auto& l : v) readln(l, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1) { v.resize(n); for (auto& l : v) readln(l, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1) { for (int l = 0; l < n; ++l) writeln(v[l], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1) { v.resize(n); for (auto& m : v) readln(m, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1) { v.resize(n); for (auto& m : v) readln(m, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1) { for (int m = 0; m < n; ++m) writeln(v[m], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1) { v.resize(n); for (auto& n : v) readln(n, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1) { v.resize(n); for (auto& n : v) readln(n, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1) { for (int n = 0; n < n; ++n) writeln(v[n], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1) { v.resize(n); for (auto& o : v) readln(o, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1) { v.resize(n); for (auto& o : v) readln(o, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1) { for (int o = 0; o < n; ++o) writeln(v[o], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o) { v.resize(n); for (auto& p : v) readln(p, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o) { v.resize(n); for (auto& p : v) readln(p, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o) { for (int p = 0; p < n; ++p) writeln(v[p], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p) { v.resize(n); for (auto& q : v) readln(q, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p) { v.resize(n); for (auto& q : v) readln(q, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p) { for (int q = 0; q < n; ++q) writeln(v[q], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q) { v.resize(n); for (auto& r : v) readln(r, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q) { v.resize(n); for (auto& r : v) readln(r, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q) { for (int r = 0; r < n; ++r) writeln(v[r], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r) { v.resize(n); for (auto& s : v) readln(s, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r) { v.resize(n); for (auto& s : v) readln(s, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r) { for (int s = 0; s < n; ++s) writeln(v[s], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s) { v.resize(n); for (auto& t : v) readln(t, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s) { v.resize(n); for (auto& t : v) readln(t, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s) { for (int t = 0; t < n; ++t) writeln(v[t], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t) { v.resize(n); for (auto& u : v) readln(u, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t) { v.resize(n); for (auto& u : v) readln(u, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t) { for (int u = 0; u < n; ++u) writeln(v[u], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u) { v.resize(n); for (auto& v : v) readln(v, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u) { v.resize(n); for (auto& v : v) readln(v, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u) { for (int v = 0; v < n; ++v) writeln(v[v], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u, int v) { v.resize(n); for (auto& w : v) readln(w, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u, v); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u, int v) { v.resize(n); for (auto& w : v) readln(w, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u, v); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u, int v) { for (int w = 0; w < n; ++w) writeln(v[w], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u, v); }

template<typename T> void readln(vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u, int v, int w) { v.resize(n); for (auto& x : v) readln(x, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u, v, w); }
template<typename T> void readln(vector<vector<T>>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u, int v, int w) { v.resize(n); for (auto& x : v) readln(x, m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u, v, w); }

template<typename T> void writeln(const vector<T>& v, int n, int m, int k, int l, int r, int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k1, int l1, int m1, int n1, int o, int p, int q, int r, int s, int t, int u, int v, int w) { for (int x = 0; x < n; ++x) writeln(v[x], m, k, l, r, x, y, z, a, b, c, d, e, f, g, h, i, j, k1, l1, m1, n1, o, p, q, r, s, t, u, v, w); }

