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
#include <cassert>
#include <ctime>
#include <climits>
#include <functional>
#include <numeric>
#include <iomanip>
#include <complex>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define DWN(i, b, a) for (int i = (b) - 1; i >= a; --i)
#define REP_1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR_1(i, a, b) for (int i = (a); i <= (b); ++i)
#define DWN_1(i, b, a) for (int i = (b); i >= (a); --i)
#define REP_C(i, n) for (int n____ = (n), i = 0; i < n____; ++i)
#define FOR_C(i, a, b) for (int b____ = (b), i = (a); i < b____; ++i)
#define DWN_C(i, b, a) for (int a____ = (a), i = (b) - 1; i >= a____; --i)
#define REP_N(i, n) for (i = 0; i < (n); ++i)
#define FOR_N(i, a, b) for (i = (a); i < (b); ++i)
#define DWN_N(i, b, a) for (i = (b) - 1; i >= a; --i)
#define REP_1_C(i, n) for (int n____ = (n), i = 1; i <= n____; ++i)
#define FOR_1_C(i, a, b) for (int b____ = (b), i = (a); i <= b____; ++i)
#define DWN_1_C(i, b, a) for (int a____ = (a), i = (b); i >= a____; --i)
#define REP_1_N(i, n) for (i = 1; i <= (n); ++i)
#define FOR_1_N(i, a, b) for (i = (a); i <= (b); ++i)
#define DWN_1_N(i, b, a) for (i = (b); i >= (a); --i)
#define REP_C_N(i, n) for (int n____ = (n), i = 0; i < n____; ++i)
#define FOR_C_N(i, a, b) for (int b____ = (b), i = (a); i < b____; ++i)
#define DWN_C_N(i, b, a) for (int a____ = (a), i = (b) - 1; i >= a____; --i)
#define REP_1_C_N(i, n) for (int n____ = (n), i = 1; i <= n____; ++i)
#define FOR_1_C_N(i, a, b) for (int b____ = (b), i = (a); i <= b____; ++i)
#define DWN_1_C_N(i, b, a) for (int a____ = (a), i = (b); i >= a____; --i)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template<typename T> inline void checkMin(T &a, const T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T &a, const T b) { if (b > a) a = b; }
template<typename T> inline T min(T a, T b, T c) { return min(min(a, b), c); }
template<typename T> inline T max(T a, T b, T c) { return max(max(a, b), c); }
template<typename T> inline T min(T a, T b, T c, T d) { return min(min(a, b), min(c, d)); }
template<typename T> inline T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline T cub(T x) { return x * x * x; }
inline int ceil(int x, int y) { return (x - 1) / y + 1; }
inline int sgn(double x) { return x < -1e-8 ? -1 : x > 1e-8; }
inline int sgn(double x, double y) { return sgn(x - y); }
template<typename T> inline void read(T &x) {
    char ch;
    while ((ch = getchar()) && !isdigit(ch) && ch != '-') ;
    bool neg = (ch == '-');
    x = neg ? 0 : ch - '0';
    while ((ch = getchar()) && isdigit(ch)) x = x * 10 + ch - '0';
    x = neg ? -x : x;
}
template<typename T, typename... Args> inline void read(T &first, Args &... args) { read(first); read(args...); }
inline bool read_str(char *s) { char ch; while ((ch = getchar()) && !isgraph(ch) && ch != EOF); if (ch == EOF) return false; s[0] = ch; int len = 1; while ((ch = getchar()) && isgraph(ch)) s[len++] = ch; s[len] = '\0'; return true; }
template<typename T> inline void write(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 10) { putchar(x + '0'); return; } write(x / 10); putchar(x % 10 + '0'); }
template<typename T, typename... Args> inline void write(T first, Args... args) { write(first); write(args...); }
inline void space() { putchar(' '); }
inline void ln() { putchar('\n'); }
inline void read() {}
template<typename T, typename... Args> inline void read(T &first, Args &... args) { read(first); read(args...); }
inline void write() {}
template<typename T, typename... Args> inline void write(T first, Args... args) { write(first); space(); write(args...); }
inline void writeln() { ln(); }
template<typename T, typename... Args> inline void writeln(T first, Args... args) { write(first); space(); writeln(args...); }
template<typename T> inline void writeln(T a[], int n) { REP(i, n) { write(a[i]); space(); } ln(); }
template<typename T> inline void writeln(vector<T> &a) { for (auto &x : a) { write(x); space(); } ln(); }
template<typename T> inline void writeln(vector<T> &a, int l, int r) { FOR(i, l, r + 1) { write(a[i]); space(); } ln(); }
template<typename T> inline void clr(T &a) { memset(a, 0, sizeof(a)); }
template<typename T> inline void clr(T &a, int n) { memset(a, 0, sizeof(a[0]) * n); }
template<typename T> inline void clr(T &a, int n, int m) { memset(a, 0, sizeof(a[0][0]) * n * m); }
template<typename T> inline void clr(T &a, int n, int m, int k) { memset(a, 0, sizeof(a[0][0][0]) * n * m * k); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l) { memset(a, 0, sizeof(a[0][0][0][0]) * n * m * k * l); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o) { memset(a, 0, sizeof(a[0][0][0][0][0]) * n * m * k * l * o); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p) { memset(a, 0, sizeof(a[0][0][0][0][0][0]) * n * m * k * l * o * p); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0]) * n * m * k * l * o * p * q); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r, int s) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r * s); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r * s * t); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r * s * t * u); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u, int v) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r * s * t * u * v); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u, int v, int w) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r * s * t * u * v * w); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r * s * t * u * v * w * x); }
template<typename T> inline void clr(T &a, int n, int m, int k, int l, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x, int y) { memset(a, 0, sizeof(a[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]) * n * m * k * l * o * p * q * r * s * t * u * v * w * x * y); }
