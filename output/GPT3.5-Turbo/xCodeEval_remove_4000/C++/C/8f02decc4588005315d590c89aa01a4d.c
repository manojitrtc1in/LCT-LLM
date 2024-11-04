#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back

#define mark_stack(...)
#define print_stack()
#define exit(...)
#define matr(...)
#define imie(...)
#define siz(...)
#define FOR(...)
#define EB(...)
#define ROS(...)
#define ckx(...)
#define avc(...)
#define pcg(...)
#define syd(...)
#define MII(...)
#define FOR(...)
#define REP(...)
#define mark_stack(...)
#define print_stack(...)
#define exit(...)
#define matr(...)
#define imie(...)
#define siz(...)
#define FOR(...)
#define EB(...)
#define ROS(...)
#define ckx(...)
#define avc(...)
#define pcg(...)
#define syd(...)
#define MII(...)

typedef long long LL;
typedef long double LD;
typedef int VI;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef map<int, int> MII;
typedef pair<PII, int> TII;
typedef pair<PII, PII> QII;
typedef unsigned long long ULL;
typedef bitset<8 * sizeof(T)> SLL;
typedef vector<int> VLL;
typedef vector<unsigned int> VULL;
typedef vector<SI> VSI;
typedef vector<TII> VTII;
typedef vector<TLL> VTLL;
typedef vector<TLD> VTLD;
typedef vector<QII> VQII;
typedef vector<QLL> VQLL;
typedef vector<QLD> VQLD;
typedef vector<QULL> VQULL;
typedef vector<TULL> VTULL;
typedef vector<ULL> VULL;
typedef vector<SULL> VSULL;

const int MOD = 1e9 + 7;
const int MN = 1e6 + 44;
const bool local = false;

typedef long long LL;
typedef long double LD;
typedef int VI;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef map<int, int> MII;

template <typename T, typename N>
bool mini(T& o, N h) {
  if (o > h) {
    o = h;
    return true;
  }
  return false;
}

template <typename T, typename N>
bool maxi(T& o, N h) {
  if (o < h) {
    o = h;
    return true;
  }
  return false;
}

int mpow(int b, int e) {
  int o = 1;
  while (e) {
    if (e & 1) o = o * 1ll * b % MOD;
    b = b * 1ll * b % MOD;
    e /= 2;
  }
  return o;
}

void dor() {
  cerr << dec << "\033[0m" << endl;
}

template <class T, class... N>
void dor(T x, N... y) {
  cerr << boolalpha << x << "; ";
  dor(y...);
}

const bool deb = false;

template <typename T>
string bte(T u) {
  stringstream o;
  o << u;
  return o.str();
}

template <typename T>
string ema(pair<T, T> u) {
  return "<" + ema(u.first) + ", " + ema(u.second) + ">";
}

template <typename T>
string bte(pair<T, T> o) {
  return "(" + bte(o.first) + ", " + bte(o.second) + ")";
}

template <typename T>
string bte(vector<T> u) {
  stringstream o;
  o << "{";
  for (auto e : u) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

template <typename T>
string bte(vector<T> o) {
  stringstream o;
  o << "{";
  for (auto e : o) o << ", " + 2 * !c++ << e;
  return o.str() + "}";
}

typedef unsigned int UI;
typedef pair<UI, UI> PUI;
typedef vector<UI> VUI;
typedef vector<PUI> VPUI;
typedef vector<VUI> VVUI;

typedef long long LL;
typedef long double LD;
typedef int VI;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef map<int, int> MII;
typedef pair<PII, int> TII;
typedef pair<PII, PII> QII;
typedef unsigned long long ULL;
typedef bitset<8 * sizeof(T)> SLL;
typedef vector<int> VLL;
typedef vector<unsigned int> VULL;
typedef vector<SI> VSI;
typedef vector<TII> VTII;
typedef vector<TLL> VTLL;
typedef vector<TLD> VTLD;
typedef vector<QII> VQII;
typedef vector<QLL> VQLL;
typedef vector<QLD> VQLD;
typedef vector<QULL> VQULL;
typedef vector<TULL> VTULL;
typedef vector<ULL> VULL;
typedef vector<SULL> VSULL;

typedef pair<LL, LL> PLL;
typedef vector<LL> VLL;
typedef vector<PLL> VPLL;
typedef vector<VLL> VVLL;

typedef long double LD;
typedef vector<LD> VLD;
typedef vector<VLD> VVLD;

typedef unsigned long long ULL;
typedef vector<ULL> VULL;
typedef vector<VULL> VVULL;

typedef set<int> SI;
typedef vector<SI> VSI;
typedef vector<VSI> VVSI;

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

typedef pair<LL, LL> PLL;
typedef vector<PLL> VPLL;
typedef vector<VPLL> VVPLL;

typedef pair<LD, LD> PLD;
typedef vector<PLD> VPLD;
typedef vector<VPLD> VVPLD;

typedef pair<ULL, ULL> PULL;
typedef vector<PULL> VPULL;
typedef vector<VPULL> VVPULL;

typedef pair<SI, SI> PSI;
typedef vector<PSI> VPSI;
typedef vector<VPSI> VVPSI;

typedef pair<TII, TII> PTII;
typedef vector<PTII> VPTII;
typedef vector<VPTII> VVPTII;

typedef pair<TLL, TLL> PTLL;
typedef vector<PTLL> VPTLL;
typedef vector<VPTLL> VVPTLL;

typedef pair<TLD, TLD> PTLD;
typedef vector<PTLD> VPTLD;
typedef vector<VPTLD> VVPTLD;

typedef pair<QII, QII> PQII;
typedef vector<PQII> VPQII;
typedef vector<VPQII> VVPQII;

typedef pair<QLL, QLL> PQLL;
typedef vector<PQLL> VPQLL;
typedef vector<VPQLL> VVPQLL;

typedef pair<QLD, QLD> PQLD;
typedef vector<PQLD> VPQLD;
typedef vector<VPQLD> VVPQLD;

typedef pair<QULL, QULL> PQULL;
typedef vector<PQULL> VPQULL;
typedef vector<VPQULL> VVPQULL;

typedef pair<TULL, TULL> PTULL;
typedef vector<PTULL> VPTULL;
typedef vector<VPTULL> VVPTULL;

typedef pair<SULL, SULL> PSULL;
typedef vector<PSULL> VPSULL;
typedef vector<VPSULL> VVPSULL;

typedef pair<SI, int> PSI;
typedef vector<PSI> VPSI;
typedef vector<VPSI> VVPSI;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
typedef vector<PSITULL> VPSITULL;
typedef vector<VPSITULL> VVPSITULL;

typedef pair<SI, SULL> PSISULL;
typedef vector<PSISULL> VPSISULL;
typedef vector<VPSISULL> VVPSISULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, int> PSIINT;
typedef vector<PSIINT> VPSIINT;
typedef vector<VPSIINT> VVPSIINT;

typedef pair<SI, LL> PSILL;
typedef vector<PSILL> VPSILL;
typedef vector<VPSILL> VVPSILL;

typedef pair<SI, LD> PSILD;
typedef vector<PSILD> VPSILD;
typedef vector<VPSILD> VVPSILD;

typedef pair<SI, ULL> PSIULL;
typedef vector<PSIULL> VPSIULL;
typedef vector<VPSIULL> VVPSIULL;

typedef pair<SI, SI> PSISI;
typedef vector<PSISI> VPSISI;
typedef vector<VPSISI> VVPSISI;

typedef pair<SI, TII> PSITII;
typedef vector<PSITII> VPSITII;
typedef vector<VPSITII> VVPSITII;

typedef pair<SI, TLL> PSITLL;
typedef vector<PSITLL> VPSITLL;
typedef vector<VPSITLL> VVPSITLL;

typedef pair<SI, TLD> PSITLD;
typedef vector<PSITLD> VPSITLD;
typedef vector<VPSITLD> VVPSITLD;

typedef pair<SI, QII> PSIQII;
typedef vector<PSIQII> VPSIQII;
typedef vector<VPSIQII> VVPSIQII;

typedef pair<SI, QLL> PSIQLL;
typedef vector<PSIQLL> VPSIQLL;
typedef vector<VPSIQLL> VVPSIQLL;

typedef pair<SI, QLD> PSIQLD;
typedef vector<PSIQLD> VPSIQLD;
typedef vector<VPSIQLD> VVPSIQLD;

typedef pair<SI, QULL> PSIQULL;
typedef vector<PSIQULL> VPSIQULL;
typedef vector<VPSIQULL> VVPSIQULL;

typedef pair<SI, TULL> PSITULL;
