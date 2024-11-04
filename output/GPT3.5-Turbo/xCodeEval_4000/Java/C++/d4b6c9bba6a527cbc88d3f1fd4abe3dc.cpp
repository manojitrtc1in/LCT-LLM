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
#include <complex>
#include <climits>
#include <ctime>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define DWN(i, b, a) for (int i = (b) - 1; i >= a; --i)
#define REP_1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR_1(i, a, b) for (int i = (a); i <= (b); ++i)
#define DWN_1(i, b, a) for (int i = (b); i >= (a); --i)
#define REP_C(i, n) for (int n____ = (n), i = 0; i < n____; ++i)
#define REP_N(i, n) for (i = 0; i < (n); ++i)
#define REP_D(i, n) for (int i = (n)-1; i >= 0; --i)
#define FOR_D(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define DWN_1(i, b, a) for (int i = (b); i >= a; --i)
#define REP_1_C(i, n) for (int n____ = (n), i = 1; i <= n____; ++i)
#define FOR_1_C(i, a, b) for (int b____ = (b), i = (a); i <= b____; ++i)
#define DWN_1_C(i, b, a) for (int a____ = (a), i = (b); i >= a____; --i)
#define REP_1_N(i, n) for (i = 1; i <= (n); ++i)
#define REP_D_C(i, n) for (int n____ = (n), i = n____ - 1; i >= 0; --i)
#define REP_D_N(i, n) for (i = (n)-1; i >= 0; --i)
#define REP_D_D(i, n) for (int i = (n)-1; i >= 0; --i)
#define FOR_D_C(i, a, b) for (int b____ = (b), i = b____ - 1; i >= (a); --i)
#define FOR_D_N(i, a, b) for (int i = (b)-1, i##end = (a); i >= i##end; --i)
#define DO(n) for (int ____n__ = n; ____n__ > 0; --____n__)
#define DO_C(n) for (int ____n__ = (n); ____n__ > 0; --____n__)
#define DO_N(n) for (int ____n__ = (n); ____n__ >= 0; --____n__)
#define DO_D(n) for (int ____n__ = (n)-1; ____n__ >= 0; --____n__)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int((A).size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>
#define fi first
#define se second
#define re real()
#define im imag()

typedef long long LL;
typedef double DB;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
typedef vector<PTT> VP;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<char, int> MCI;
typedef map<int, string> MIS;
typedef map<char, string> MCS;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;
typedef pair<char, int> PCI;
typedef pair<int, string> PIS;
typedef pair<char, string> PCS;
typedef complex<double> point;

template <class T>
inline T& RD(T&);

template <class T>
inline void OT(const T&);

inline LL RD() {
  LL x;
  return RD(x);
}

inline DB& RF(DB&);

inline DB RF() {
  DB x;
  return RF(x);
}

inline char* RS(char* s);

inline char& RC(char&);

inline char RC();

inline char& RC(char& c) {
  scanf(" %c", &c);
  return c;
}

inline char RC() {
  char c;
  return RC(c);
}

template <class T>
inline T& RDD(T& x) {
  char c;
  for (c = getchar(); c < '0'; c = getchar())
    ;
  x = c - '0';
  for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x;
}

inline LL RDD() {
  LL x;
  return RDD(x);
}

template <class T0, class T1>
inline T0& RD(T0& x0, T1& x1) {
  RD(x0), RD(x1);
  return x0;
}

template <class T0, class T1, class T2>
inline T0& RD(T0& x0, T1& x1, T2& x2) {
  RD(x0), RD(x1), RD(x2);
  return x0;
}

template <class T0, class T1, class T2, class T3>
inline T0& RD(T0& x0, T1& x1, T2& x2, T3& x3) {
  RD(x0), RD(x1), RD(x2), RD(x3);
  return x0;
}

template <class T0, class T1, class T2, class T3, class T4>
inline T0& RD(T0& x0, T1& x1, T2& x2, T3& x3, T4& x4) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);
  return x0;
}

template <class T0, class T1, class T2, class T3, class T4, class T5>
inline T0& RD(T0& x0, T1& x1, T2& x2, T3& x3, T4& x4, T5& x5) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);
  return x0;
}

template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline T0& RD(T0& x0, T1& x1, T2& x2, T3& x3, T4& x4, T5& x5, T6& x6) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);
  return x0;
}

template <class T0, class T1>
inline void OT(const T0& x0, const T1& x1) {
  OT(x0), OT(x1);
}

template <class T0, class T1, class T2>
inline void OT(const T0& x0, const T1& x1, const T2& x2) {
  OT(x0), OT(x1), OT(x2);
}

template <class T0, class T1, class T2, class T3>
inline void OT(const T0& x0, const T1& x1, const T2& x2, const T3& x3) {
  OT(x0), OT(x1), OT(x2), OT(x3);
}

template <class T0, class T1, class T2, class T3, class T4>
inline void OT(const T0& x0, const T1& x1, const T2& x2, const T3& x3,
               const T4& x4) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);
}

template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void OT(const T0& x0, const T1& x1, const T2& x2, const T3& x3,
               const T4& x4, const T5& x5) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);
}

template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void OT(const T0& x0, const T1& x1, const T2& x2, const T3& x3,
               const T4& x4, const T5& x5, const T6& x6) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);
}

inline char& RC(char& a, char& b) {
  RC(a), RC(b);
  return a;
}

inline char& RC(char& a, char& b, char& c) {
  RC(a), RC(b), RC(c);
  return a;
}

inline char& RC(char& a, char& b, char& c, char& d) {
  RC(a), RC(b), RC(c), RC(d);
  return a;
}

inline char& RC(char& a, char& b, char& c, char& d, char& e) {
  RC(a), RC(b), RC(c), RC(d), RC(e);
  return a;
}

inline char& RC(char& a, char& b, char& c, char& d, char& e, char& f) {
  RC(a), RC(b), RC(c), RC(d), RC(e), RC(f);
  return a;
}

inline char& RC(char& a, char& b, char& c, char& d, char& e, char& f, char& g) {
  RC(a), RC(b), RC(c), RC(d), RC(e), RC(f), RC(g);
  return a;
}

inline DB& RF(DB& a, DB& b) {
  RF(a), RF(b);
  return a;
}

inline DB& RF(DB& a, DB& b, DB& c) {
  RF(a), RF(b), RF(c);
  return a;
}

inline DB& RF(DB& a, DB& b, DB& c, DB& d) {
  RF(a), RF(b), RF(c), RF(d);
  return a;
}

inline DB& RF(DB& a, DB& b, DB& c, DB& d, DB& e) {
  RF(a), RF(b), RF(c), RF(d), RF(e);
  return a;
}

inline DB& RF(DB& a, DB& b, DB& c, DB& d, DB& e, DB& f) {
  RF(a), RF(b), RF(c), RF(d), RF(e), RF(f);
  return a;
}

inline DB& RF(DB& a, DB& b, DB& c, DB& d, DB& e, DB& f, DB& g) {
  RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g);
  return a;
}

inline void RS(char* s1, char* s2) {
  RS(s1), RS(s2);
}

inline void RS(char* s1, char* s2, char* s3) {
  RS(s1), RS(s2), RS(s3);
}

template <class T>
inline void RST(T& A) {
  memset(A, 0, sizeof(A));
}

template <class T0, class T1>
inline void RST(T0& A0, T1& A1) {
  RST(A0), RST(A1);
}

template <class T0, class T1, class T2>
inline void RST(T0& A0, T1& A1, T2& A2) {
  RST(A0), RST(A1), RST(A2);
}

template <class T0, class T1, class T2, class T3>
inline void RST(T0& A0, T1& A1, T2& A2, T3& A3) {
  RST(A0), RST(A1), RST(A2), RST(A3);
}

template <class T>
inline void CLR(priority_queue<T, vector<T>, less<T> >& Q) {
  while (!Q.empty()) Q.pop();
}

template <class T>
inline void CLR(priority_queue<T, vector<T>, greater<T> >& Q) {
  while (!Q.empty()) Q.pop();
}

template <class T>
inline void CLR(T& A) {
  A.clear();
}

template <class T0, class T1>
inline void CLR(T0& A0, T1& A1) {
  CLR(A0), CLR(A1);
}

template <class T0, class T1, class T2>
inline void CLR(T0& A0, T1& A1, T2& A2) {
  CLR(A0), CLR(A1), CLR(A2);
}

template <class T0, class T1, class T2, class T3>
inline void CLR(T0& A0, T1& A1, T2& A2, T3& A3) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3);
}

template <class T>
inline void CLR(T& A, int n) {
  REP(i, n) CLR(A[i]);
}

template <class T>
inline bool EPT(T& a) {
  return a.empty();
}

template <class T0, class T1>
inline bool EPT(T0& a0, T1& a1) {
  return EPT(a0) && EPT(a1);
}

template <class T0, class T1, class T2>
inline bool EPT(T0& a0, T1& a1, T2& a2) {
  return EPT(a0) && EPT(a1) && EPT(a2);
}

template <class T0, class T1, class T2, class T3>
inline bool EPT(T0& a0, T1& a1, T2& a2, T3& a3) {
  return EPT(a0) && EPT(a1) && EPT(a2) && EPT(a3);
}

template <class T>
inline T& SRT(T& A) {
  sort(ALL(A));
  return A;
}

template <class T, class C>
inline T& SRT(T& A, C B) {
  sort(ALL(A), B);
  return A;
}

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB OO = 1e20;
const DB PI = acos(-1.0);  // M_PI;

template <class T>
inline void checkMin(T& a, const T b) {
  if (b < a) a = b;
}

template <class T>
inline void checkMax(T& a, const T b) {
  if (a < b) a = b;
}

template <class T, class C>
inline void checkMin(T& a, const T b, C c) {
  if (c(b, a)) a = b;
}

template <class T, class C>
inline void checkMax(T& a, const T b, C c) {
  if (c(a, b)) a = b;
}

template <class T>
inline T& checkMin(T& a, T& b, T& c) {
  checkMin(a, b), checkMin(a, c);
  return a;
}

template <class T>
inline T& checkMax(T& a, T& b, T& c) {
  checkMax(a, b), checkMax(a, c);
  return a;
}

template <class T>
inline T& checkMin(T& a, T& b, T& c, T& d) {
  checkMin(a, b), checkMin(a, c), checkMin(a, d);
  return a;
}

template <class T>
inline T& checkMax(T& a, T& b, T& c, T& d) {
  checkMax(a, b), checkMax(a, c), checkMax(a, d);
  return a;
}

template <class T>
inline T sqr(const T& a) {
  return a * a;
}

template <class T>
inline T cub(const T& a) {
  return a * a * a;
}

inline int ceil(int x, int y) { return (x - 1) / y + 1; }

inline int sgn(DB x) { return x < -EPS ? -1 : x > EPS; }

inline int sgn(DB x, DB y) { return sgn(x - y); }

inline DB cot(DB x) { return (DB)1 / tan(x); }

inline DB sec(DB x) { return (DB)1 / cos(x); }

inline DB csc(DB x) { return (DB)1 / sin(x); }

template <class T>
inline T low_bit(T x) {
  return x & -x;
}

template <class T>
inline T high_bit(T x) {
  T p = low_bit(x);
  while (p != x) x -= p, p = low_bit(x);
  return p;
}

inline void INC(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

inline int sum(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline void DEC(int& a, int b) {
  a -= b;
  if (a < 0) a += MOD;
}

inline int dff(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

inline void MUL(int& a, int b) { a = (LL)a * b % MOD; }

inline int pdt(int a, int b) { return (LL)a * b % MOD; }

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

inline void ADD(LL& a, LL b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

inline void ADD(LL& a, LL b, LL c) {
  a += b;
  if (a >= c) a -= c;
}

inline void SUB(LL& a, LL b) {
  a -= b;
  if (a < 0) a += MOD;
}

inline void SUB(LL& a, LL b, LL c) {
  a -= b;
  if (a < c) a += c;
}

inline void MUL(LL& a, LL b) { a = (a * b) % MOD; }

inline LL pdt(LL a, LL b) { return (a * b) % MOD; }

inline LL pow(LL a, LL b) {
  LL c(1);
  while (b) {
    if (b & 1) MUL(c, a);
    MUL(a, a);
    b >>= 1;
  }
  return c;
}

template <class T>
inline int count_bit(T n) {
  return n == 0 ? 0 : 1 + count_bit(n & (n - 1));
}

inline int count_bit(int x) {
  x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
  x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
  x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
  return x;
}

inline int count_bit(LL x) {
  x = (x & 0x5555555555555555LL) + ((x >> 1) & 0x5555555555555555LL);
  x = (x & 0x3333333333333333LL) + ((x >> 2) & 0x3333333333333333LL);
  x = (x & 0x0f0f0f0f0f0f0f0fLL) + ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL);
  x = (x & 0x00ff00ff00ff00ffLL) + ((x >> 8) & 0x00ff00ff00ff00ffLL);
  x = (x & 0x0000ffff0000ffffLL) + ((x >> 16) & 0x0000ffff0000ffffLL);
  x = (x & 0x00000000ffffffffLL) + ((x >> 32) & 0x00000000ffffffffLL);
  return x;
}

inline void get_min(LL& a, LL b) {
  if (b < a) a = b;
}

inline void get_max(LL& a, LL b) {
  if (a < b) a = b;
}

inline void get_min(int& a, int b) {
  if (b < a) a = b;
}

inline void get_max(int& a, int b) {
  if (a < b) a = b;
}

inline void get_min(DB& a, DB b) {
  if (b < a) a = b;
}

inline void get_max(DB& a, DB b) {
  if (a < b) a = b;
}

inline void check_min(LL& a, LL b) {
  if (b < a) a = b;
}

inline void check_max(LL& a, LL b) {
  if (a < b) a = b;
}

inline void check_min(int& a, int b) {
  if (b < a) a = b;
}

inline void check_max(int& a, int b) {
  if (a < b) a = b;
}

inline void check_min(DB& a, DB b) {
  if (b < a) a = b;
}

inline void check_max(DB& a, DB b) {
  if (a < b) a = b;
}

inline int random_int() { return rand() << 15 | rand(); }

inline int random_int(int n) { return random_int() % n; }

inline int random_int(int a, int b) { return random_int(b - a) + a; }

inline DB random_real() { return (DB)rand() / RAND_MAX; }

inline DB random_real(DB a, DB b) { return random_real() * (b - a) + a; }

template <class T>
inline void RD(T& t) {
  cin >> t;
}

template <class T0, class T1>
inline void RD(T0& t0, T1& t1) {
  cin >> t0 >> t1;
}

template <class T0, class T1, class T2>
inline void RD(T0& t0, T1& t1, T2& t2) {
  cin >> t0 >> t1 >> t2;
}

template <class T0, class T1, class T2, class T3>
inline void RD(T0& t0, T1& t1, T2& t2, T3& t3) {
  cin >> t0 >> t1 >> t2 >> t3;
}

template <class T>
inline void OT(const T& t) {
  cout << t << endl;
}

template <class T0, class T1>
inline void OT(const T0& t0, const T1& t1) {
  cout << t0 << ' ' << t1 << endl;
}

template <class T0, class T1, class T2>
inline void OT(const T0& t0, const T1& t1, const T2& t2) {
  cout << t0 << ' ' << t1 << ' ' << t2 << endl;
}

template <class T0, class T1, class T2, class T3>
inline void OT(const T0& t0, const T1& t1, const T2& t2, const T3& t3) {
  cout << t0 << ' ' << t1 << ' ' << t2 << ' ' << t3 << endl;
}

template <class T>
inline void OT(const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); ++i)
    cout << v[i] << ((i == (int)v.size() - 1) ? '\n' : ' ');
}

template <class T>
inline void OT(const vector<vector<T> >& v) {
  for (int i = 0; i < (int)v.size(); ++i) OT(v[i]);
}

inline void OT() { cout << endl; }

template <class T>
inline void setMin(T& a, const T& b) {
  if (b < a) a = b;
}

template <class T>
inline void setMax(T& a, const T& b) {
  if (a < b) a = b;
}

template <class T>
inline T min(const T& a, const T& b, const T& c) {
  return min(min(a, b), c);
}

template <class T>
inline T max(const T& a, const T& b, const T& c) {
  return max(max(a, b), c);
}

template <class T>
inline T min(const T& a, const T& b, const T& c, const T& d) {
  return min(min(a, b), min(c, d));
}

template <class T>
inline T max(const T& a, const T& b, const T& c, const T& d) {
  return max(max(a, b), max(c, d));
}

template <class T>
inline T sqr(const T& x) {
  return x * x;
}

template <class T>
inline T cub(const T& x) {
  return x * x * x;
}

template <class T>
inline int sign(const T& x) {
  return x < 0 ? -1 : x > 0;
}

inline void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

inline void sub(int& a, int b) {
  a -= b;
  if (a < 0) a += MOD;
}

inline void mul(int& a, int b) { a = (LL)a * b % MOD; }

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

inline int mul(int a, int b) { return (LL)a * b % MOD; }

inline int pow(int a, int b) {
  int c(1);
  while (b) {
    if (b & 1) mul(c, a);
    mul(a, a);
    b >>= 1;
  }
  return c;
}

inline int pow(int a, int b, int c) {
  int d(1);
  while (b) {
    if (b & 1) mul(d, a, c);
    mul(a, a, c);
    b >>= 1;
  }
  return d;
}

inline int _I(int b) {
  int a = MOD, x1 = 0, x2 = 1, q;
  while (true) {
    q = a / b, a %= b;
    if (!a) return (x2 + MOD) % MOD;
    sub(x1, mul(q, x2));

    q = b / a, b %= a;
    if (!b) return (x1 + MOD) % MOD;
    sub(x2, mul(q, x1));
  }
}

inline void DIV(int& a, int b) { mul(a, _I(b)); }

inline int sum(int a, int b, int c) { return add(add(a, b), c); }

inline int sum(int a, int b, int c, int d) { return add(add(a, b), sum(c, d)); }

inline int sum(int a, int b, int c, int d, int e) {
  return add(add(a, b), sum(c, d, e));
}

inline int sum(int a, int b, int c, int d, int e, int f) {
  return add(add(a, b), sum(c, d, e, f));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g) {
  return add(add(a, b), sum(c, d, e, f, g));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h) {
  return add(add(a, b), sum(c, d, e, f, g, h));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
  return add(add(a, b), sum(c, d, e, f, g, h, i));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F, int G) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F, int G, int H) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F, int G, int H, int I) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F, int G, int H, int I, int J) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F, int G, int H, int I, int J,
               int K) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F, int G, int H, int I, int J,
               int K, int L) {
  return add(add(a, b), sum(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L));
}

inline int sum(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j, int k, int l, int m, int n, int o, int p, int q, int r,
               int s, int t, int u, int v, int w, int x, int y, int z, int A,
               int B, int C, int D, int E, int F, int G, int H, int I, int J,
               int K, int L, int M) {
