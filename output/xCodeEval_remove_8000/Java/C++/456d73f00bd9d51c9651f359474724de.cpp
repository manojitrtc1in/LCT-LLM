#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <cassert>
#include <random>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define per(i, n) for (int i = (n)-1; i >= 0; --i)
#define per1(i, n) for (int i = (n); i >= 1; --i)
#define FOREACH(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define IN(x, y, z) ((y) <= (x) && (x) <= (z))
#define INR(x, y, z) ((y) < (x) && (x) <= (z))
#define FILL(a, b) memset(a, b, sizeof(a))
#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))
#define out(x) cout << #x << " = " << (x) << " ";
#define outln(x) cout << #x << " = " << (x) << endl;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);

const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;

template<typename T> inline void read(T &x) {
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= f;
}

template<typename T> inline void write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

template<typename T> inline void writeln(T x) {
    write(x);
    puts("");
}

template<typename T> inline void writesp(T x) {
    write(x);
    putchar(' ');
}

template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T max(T a, T b, T c) { return max(max(a, b), c); }
template<typename T> inline T min(T a, T b, T c) { return min(min(a, b), c); }
template<typename T> inline T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }
template<typename T> inline T min(T a, T b, T c, T d) { return min(min(a, b), min(c, d)); }
template<typename T> inline T max(vector<T> v) { return *max_element(all(v)); }
template<typename T> inline T min(vector<T> v) { return *min_element(all(v)); }
template<typename T> inline T sum(vector<T> v) { return accumulate(all(v), 0); }
template<typename T> inline T max(vector<vector<T>> v) { return *max_element(all(v)); }
template<typename T> inline T min(vector<vector<T>> v) { return *min_element(all(v)); }
template<typename T> inline T sum(vector<vector<T>> v) { return accumulate(all(v), 0); }
template<typename T> inline void sort(vector<T>& v) { sort(all(v)); }
template<typename T> inline void rsort(vector<T>& v) { sort(rall(v)); }
template<typename T> inline void reverse(vector<T>& v) { reverse(all(v)); }
template<typename T> inline void unique(vector<T>& v) { sort(v); v.erase(unique(all(v)), v.end()); }
template<typename T> inline int sgn(T x) { return (x > 0) - (x < 0); }
template<typename T> inline int sgn(T x, T y) { return sgn(x - y); }
template<typename T> inline int sgn(T x1, T y1, T x2, T y2) { return sgn(x1, x2) ? sgn(x1, x2) : sgn(y1, y2); }
template<typename T> inline int sgn(pii p1, pii p2) { return sgn(p1.fi, p1.se, p2.fi, p2.se); }
template<typename T> inline double dist(T x, T y) { return sqrt(x * x + y * y); }
template<typename T> inline double dist(T x1, T y1, T x2, T y2) { return dist(x1 - x2, y1 - y2); }
template<typename T> inline double dist(pii p1, pii p2) { return dist(p1.fi, p1.se, p2.fi, p2.se); }
template<typename T> inline T cross(T x1, T y1, T x2, T y2) { return x1 * y2 - x2 * y1; }
template<typename T> inline T cross(pii p1, pii p2) { return cross(p1.fi, p1.se, p2.fi, p2.se); }
template<typename T> inline T dot(T x1, T y1, T x2, T y2) { return x1 * x2 + y1 * y2; }
template<typename T> inline T dot(pii p1, pii p2) { return dot(p1.fi, p1.se, p2.fi, p2.se); }
template<typename T> inline T rad(T x) { return x * pi / 180.0; }
template<typename T> inline T deg(T x) { return x * 180.0 / pi; }
template<typename T> inline int to_int(T x) { stringstream ss; ss << x; int r; ss >> r; return r; }
template<typename T> inline string to_str(T x) { stringstream ss; ss << x; return ss.str(); }
template<typename T> inline void chmax(T& x, T y) { x = max(x, y); }
template<typename T> inline void chmin(T& x, T y) { x = min(x, y); }
template<typename T> inline void chmax(T& x, vector<T> v) { for (auto i : v) chmax(x, i); }
template<typename T> inline void chmin(T& x, vector<T> v) { for (auto i : v) chmin(x, i); }
template<typename T> inline void read(vector<T>& v) { for (auto& i : v) read(i); }
template<typename T> inline void writesp(vector<T>& v) { for (auto& i : v) writesp(i); puts(""); }
template<typename T> inline void writeln(vector<T>& v) { for (auto& i : v) writeln(i); }
template<typename T> inline void print(vector<T>& v) { for (auto& i : v) print(i); }
template<typename T> inline void print(vector<vector<T>>& v) { for (auto& i : v) print(i); }
template<typename T> inline void print(set<T>& s) { for (auto& i : s) print(i); }
template<typename T> inline void print(multiset<T>& s) { for (auto& i : s) print(i); }
template<typename T> inline void print(unordered_set<T>& s) { for (auto& i : s) print(i); }
template<typename T> inline void print(unordered_multiset<T>& s) { for (auto& i : s) print(i); }
template<typename T1, typename T2> inline void print(map<T1, T2>& m) { for (auto& i : m) print(i.fi), writesp(i.se); }
template<typename T1, typename T2> inline void print(multimap<T1, T2>& m) { for (auto& i : m) print(i.fi), writesp(i.se); }
template<typename T1, typename T2> inline void print(unordered_map<T1, T2>& m) { for (auto& i : m) print(i.fi), writesp(i.se); }
template<typename T1, typename T2> inline void print(unordered_multimap<T1, T2>& m) { for (auto& i : m) print(i.fi), writesp(i.se); }
template<typename T> inline void print(priority_queue<T>& q) { while (!q.empty()) { print(q.top()), q.pop(); } }
template<typename T> inline void print(stack<T>& s) { while (!s.empty()) { print(s.top()), s.pop(); } }
template<typename T> inline void print(queue<T>& q) { while (!q.empty()) { print(q.front()), q.pop(); } }
template<typename T> inline void print(deque<T>& q) { while (!q.empty()) { print(q.front()), q.pop_front(); } }
template<typename T> inline void print(T x) { cout << x << " "; }
template<typename T> inline void writeln(T x) { print(x); puts(""); }
template<typename T> inline void writesp(T x) { print(x); putchar(' '); }
template<typename T> inline void chmax(T& x, T y, T z) { chmax(x, max(y, z)); }
template<typename T> inline void chmin(T& x, T y, T z) { chmin(x, min(y, z)); }
template<typename T> inline void chmax(T& x, T y, T z, T w) { chmax(x, max(y, max(z, w))); }
template<typename T> inline void chmin(T& x, T y, T z, T w) { chmin(x, min(y, min(z, w))); }
template<typename T> inline void chmax(T& x, vector<T> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, vector<T> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, vector<vector<T>> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, vector<vector<T>> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, set<T> s) { chmax(x, max(s)); }
template<typename T> inline void chmin(T& x, set<T> s) { chmin(x, min(s)); }
template<typename T> inline void chmax(T& x, multiset<T> s) { chmax(x, max(s)); }
template<typename T> inline void chmin(T& x, multiset<T> s) { chmin(x, min(s)); }
template<typename T> inline void chmax(T& x, unordered_set<T> s) { chmax(x, max(s)); }
template<typename T> inline void chmin(T& x, unordered_set<T> s) { chmin(x, min(s)); }
template<typename T> inline void chmax(T& x, unordered_multiset<T> s) { chmax(x, max(s)); }
template<typename T> inline void chmin(T& x, unordered_multiset<T> s) { chmin(x, min(s)); }
template<typename T1, typename T2> inline void chmax(T1& x, T2 a, T2 b) { chmax(x, max(a, b)); }
template<typename T1, typename T2> inline void chmin(T1& x, T2 a, T2 b) { chmin(x, min(a, b)); }
template<typename T1, typename T2> inline void chmax(T1& x, T2 a, T2 b, T2 c) { chmax(x, max(a, max(b, c))); }
template<typename T1, typename T2> inline void chmin(T1& x, T2 a, T2 b, T2 c) { chmin(x, min(a, min(b, c))); }
template<typename T1, typename T2> inline void chmax(T1& x, T2 a, T2 b, T2 c, T2 d) { chmax(x, max(a, max(b, max(c, d)))); }
template<typename T1, typename T2> inline void chmin(T1& x, T2 a, T2 b, T2 c, T2 d) { chmin(x, min(a, min(b, min(c, d)))); }
template<typename T> inline void chmax(T& x, initializer_list<T> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, initializer_list<T> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, initializer_list<vector<T>> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, initializer_list<vector<T>> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, initializer_list<set<T>> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, initializer_list<set<T>> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, initializer_list<multiset<T>> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, initializer_list<multiset<T>> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_set<T>> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_set<T>> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_multiset<T>> v) { chmax(x, max(v)); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_multiset<T>> v) { chmin(x, min(v)); }
template<typename T> inline void chmax(T& x, initializer_list<T> v, T y) { chmax(x, max(v), y); }
template<typename T> inline void chmin(T& x, initializer_list<T> v, T y) { chmin(x, min(v), y); }
template<typename T> inline void chmax(T& x, initializer_list<vector<T>> v, T y) { chmax(x, max(v), y); }
template<typename T> inline void chmin(T& x, initializer_list<vector<T>> v, T y) { chmin(x, min(v), y); }
template<typename T> inline void chmax(T& x, initializer_list<set<T>> v, T y) { chmax(x, max(v), y); }
template<typename T> inline void chmin(T& x, initializer_list<set<T>> v, T y) { chmin(x, min(v), y); }
template<typename T> inline void chmax(T& x, initializer_list<multiset<T>> v, T y) { chmax(x, max(v), y); }
template<typename T> inline void chmin(T& x, initializer_list<multiset<T>> v, T y) { chmin(x, min(v), y); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_set<T>> v, T y) { chmax(x, max(v), y); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_set<T>> v, T y) { chmin(x, min(v), y); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_multiset<T>> v, T y) { chmax(x, max(v), y); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_multiset<T>> v, T y) { chmin(x, min(v), y); }
template<typename T> inline void chmax(T& x, initializer_list<T> v, T y, T z) { chmax(x, max(v), y, z); }
template<typename T> inline void chmin(T& x, initializer_list<T> v, T y, T z) { chmin(x, min(v), y, z); }
template<typename T> inline void chmax(T& x, initializer_list<vector<T>> v, T y, T z) { chmax(x, max(v), y, z); }
template<typename T> inline void chmin(T& x, initializer_list<vector<T>> v, T y, T z) { chmin(x, min(v), y, z); }
template<typename T> inline void chmax(T& x, initializer_list<set<T>> v, T y, T z) { chmax(x, max(v), y, z); }
template<typename T> inline void chmin(T& x, initializer_list<set<T>> v, T y, T z) { chmin(x, min(v), y, z); }
template<typename T> inline void chmax(T& x, initializer_list<multiset<T>> v, T y, T z) { chmax(x, max(v), y, z); }
template<typename T> inline void chmin(T& x, initializer_list<multiset<T>> v, T y, T z) { chmin(x, min(v), y, z); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_set<T>> v, T y, T z) { chmax(x, max(v), y, z); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_set<T>> v, T y, T z) { chmin(x, min(v), y, z); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_multiset<T>> v, T y, T z) { chmax(x, max(v), y, z); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_multiset<T>> v, T y, T z) { chmin(x, min(v), y, z); }
template<typename T> inline void chmax(T& x, initializer_list<T> v, T y, T z, T w) { chmax(x, max(v), y, z, w); }
template<typename T> inline void chmin(T& x, initializer_list<T> v, T y, T z, T w) { chmin(x, min(v), y, z, w); }
template<typename T> inline void chmax(T& x, initializer_list<vector<T>> v, T y, T z, T w) { chmax(x, max(v), y, z, w); }
template<typename T> inline void chmin(T& x, initializer_list<vector<T>> v, T y, T z, T w) { chmin(x, min(v), y, z, w); }
template<typename T> inline void chmax(T& x, initializer_list<set<T>> v, T y, T z, T w) { chmax(x, max(v), y, z, w); }
template<typename T> inline void chmin(T& x, initializer_list<set<T>> v, T y, T z, T w) { chmin(x, min(v), y, z, w); }
template<typename T> inline void chmax(T& x, initializer_list<multiset<T>> v, T y, T z, T w) { chmax(x, max(v), y, z, w); }
template<typename T> inline void chmin(T& x, initializer_list<multiset<T>> v, T y, T z, T w) { chmin(x, min(v), y, z, w); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_set<T>> v, T y, T z, T w) { chmax(x, max(v), y, z, w); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_set<T>> v, T y, T z, T w) { chmin(x, min(v), y, z, w); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_multiset<T>> v, T y, T z, T w) { chmax(x, max(v), y, z, w); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_multiset<T>> v, T y, T z, T w) { chmin(x, min(v), y, z, w); }
template<typename T> inline void chmax(T& x, initializer_list<T> v, T y, T z, T w, T q) { chmax(x, max(v), y, z, w, q); }
template<typename T> inline void chmin(T& x, initializer_list<T> v, T y, T z, T w, T q) { chmin(x, min(v), y, z, w, q); }
template<typename T> inline void chmax(T& x, initializer_list<vector<T>> v, T y, T z, T w, T q) { chmax(x, max(v), y, z, w, q); }
template<typename T> inline void chmin(T& x, initializer_list<vector<T>> v, T y, T z, T w, T q) { chmin(x, min(v), y, z, w, q); }
template<typename T> inline void chmax(T& x, initializer_list<set<T>> v, T y, T z, T w, T q) { chmax(x, max(v), y, z, w, q); }
template<typename T> inline void chmin(T& x, initializer_list<set<T>> v, T y, T z, T w, T q) { chmin(x, min(v), y, z, w, q); }
template<typename T> inline void chmax(T& x, initializer_list<multiset<T>> v, T y, T z, T w, T q) { chmax(x, max(v), y, z, w, q); }
template<typename T> inline void chmin(T& x, initializer_list<multiset<T>> v, T y, T z, T w, T q) { chmin(x, min(v), y, z, w, q); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_set<T>> v, T y, T z, T w, T q) { chmax(x, max(v), y, z, w, q); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_set<T>> v, T y, T z, T w, T q) { chmin(x, min(v), y, z, w, q); }
template<typename T> inline void chmax(T& x, initializer_list<unordered_multiset<T>> v, T y, T z, T w, T q) { chmax(x, max(v), y, z, w, q); }
template<typename T> inline void chmin(T& x, initializer_list<unordered_multiset<T>> v, T y, T z, T w, T q) { chmin(x, min(v), y, z, w, q); }

template<typename T> inline void chmax(T& x, T y) { x = max(x, y); }
template<typename T> inline void chmin(T& x, T y) { x = min(x, y); }

template<typename T> inline void add(T& x, T y) { x += y; if (x >= mod) x -= mod; }
