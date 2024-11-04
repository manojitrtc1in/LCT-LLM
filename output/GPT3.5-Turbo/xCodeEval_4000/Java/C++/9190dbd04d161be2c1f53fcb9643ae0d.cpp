#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <cstdio>
#include <numeric>
#include <complex>
#include <fstream>
#include <functional>
#include <random>
#include <array>
#include <chrono>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; --i)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define ALL(c) (c).begin(), (c).end()
#define MOD 998244353
#define INF 1000000007
#define INFL 1000000000000000007LL
#define EPS 1e-9
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())
#define PRINT(v) cout << (v) << endl
#define DEBUG(x) cerr << #x << ": " << (x) << endl
#define DEBUG_VEC(v) \
  cerr << #v << ":";  \
  REP(i, v.size()) cerr << " " << v[i]; \
  cerr << endl
#define DEBUG_MAT(v) \
  cerr << #v << endl; \
  REP(i, v.size()) { \
    REP(j, v[i].size()) { \
      cerr << v[i][j] << " "; \
    } \
    cerr << endl; \
  }
#define ALL_MAT(v) v.begin(), v.end()
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, -1, sizeof(a))
#define REP2(i, m, n) for (int i = (m); i < (n); ++i)
#define REP3(i, m, n, s) for (int i = (m); i < (n); i += (s))
#define REP4(i, m, n) for (int i = (m); i > (n); --i)
#define REP5(i, m, n, s) for (int i = (m); i > (n); i -= (s))
#define ALL_REV(v) (v).rbegin(), (v).rend()
#define DEBUG_PAIRS(p) \
  cerr << #p << endl; \
  REP(i, p.size()) { \
    cerr << p[i].first << " " << p[i].second << endl; \
  }
#define DEBUG_SET(s) \
  cerr << #s << endl; \
  for (auto x : s) { \
    cerr << x << " "; \
  } \
  cerr << endl;
#define DEBUG_MAP(m) \
  cerr << #m << endl; \
  for (auto x : m) { \
    cerr << x.first << ":" << x.second << endl; \
  }
#define DEBUG_TUPLE(t) \
  cerr << #t << ":" << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
#define CHMIN(a, b) a = min((a), (b))
#define CHMAX(a, b) a = max((a), (b))
#define SQ(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define IS_ODD(x) ((x) % 2 != 0)
#define IS_EVEN(x) ((x) % 2 == 0)
#define CEIL(a, b) (((a) + (b) - 1) / (b))
#define ROUNDUP(a, b) (CEIL(a, b) * (b))
#define ROUNDDOWN(a, b) (((a) / (b)) * (b))
#define TO_RADIAN(degree) ((degree) * M_PI / 180.0)
#define TO_DEGREE(radian) ((radian) * 180.0 / M_PI)
#define BIT(n, k) (((n) >> (k)) & 1)
#define BITSET(n, k) ((n) |= (1ULL << (k)))
#define BITCLEAR(n, k) ((n) &= ~(1ULL << (k)))
#define BITFLIP(n, k) ((n) ^= (1ULL << (k)))
#define BITMASK(h, l) (((1ULL << ((h) - (l) + 1)) - 1) << (l))
#define BITMASK_CLEAR(n, h, l) ((n) &= ~BITMASK(h, l))
#define BITMASK_SET(n, h, l, v) ((n) = ((n) & ~BITMASK(h, l)) | ((v) << (l)))
#define BITMASK_GET(n, h, l) (((n) & BITMASK(h, l)) >> (l))
#define BITMASK_FLIP(n, h, l) ((n) ^= BITMASK(h, l))
#define BITMASK_SHIFT(n, h, l, d) ((n) = ((n) & ~BITMASK(h, l)) | (((n) & BITMASK(h, l)) << (d)))
#define BITMASK_ROTATE(n, h, l, r) ((n) = ((n) & ~BITMASK(h, l)) | (((n) & BITMASK(h, l)) >> (r)))
#define BITMASK_ROTATE_LEFT(n, h, l, r) ((n) = ((n) & ~BITMASK(h, l)) | (((n) & BITMASK(h, l)) << (r)))
#define BITMASK_ROTATE_RIGHT(n, h, l, r) ((n) = ((n) & ~BITMASK(h, l)) | (((n) & BITMASK(h, l)) >> (r)))
#define BITMASK_COUNT(n) __builtin_popcountll(n)
#define BITMASK_COUNTLZ(n) __builtin_clzll(n)
#define BITMASK_COUNTRZ(n) __builtin_ctzll(n)
#define BITMASK_COUNTTZ(n) BITMASK_COUNTRZ(n)
#define BITMASK_PARITY(n) __builtin_parityll(n)
#define BITMASK_PARITYODD(n) (BITMASK_PARITY(n) == 1)
#define BITMASK_PARITYEVEN(n) (BITMASK_PARITY(n) == 0)
#define BITMASK_NEXT(n) (n & -n)
#define BITMASK_RESET(n) (n = 0)
#define BITMASK_ISSET(n, k) (((n) & (1ULL << (k))) != 0)
#define BITMASK_ISCLEAR(n, k) (((n) & (1ULL << (k))) == 0)
#define BITMASK_ISFLIP(n, k) (((n) & (1ULL << (k))) != 0)
#define BITMASK_ISRESET(n) ((n) == 0)
#define BITMASK_ISEMPTY(n) ((n) == 0)
#define BITMASK_ISFULL(n, h, l) (((n) & BITMASK(h, l)) == BITMASK(h, l))
#define BITMASK_ISVALID(n, h, l) (((n) & ~BITMASK(h, l)) == 0)
#define BITMASK_ISINVALID(n, h, l) (((n) & ~BITMASK(h, l)) != 0)
#define BITMASK_ISINRANGE(n, h, l) (((n) & ~BITMASK(h, l)) == 0)
#define BITMASK_ISOUTOFRANGE(n, h, l) (((n) & ~BITMASK(h, l)) != 0)
#define BITMASK_ISOVERLAP(n, h, l) (((n) & BITMASK(h, l)) != 0)
#define BITMASK_ISDISJOINT(n, h, l) (((n) & BITMASK(h, l)) == 0)
#define BITMASK_ISCONTAINED(n, h, l, m) (((n) & ~BITMASK(h, l)) == ((m) & ~BITMASK(h, l)))
#define BITMASK_ISCONTAINS(n, h, l, m) (((n) & ~BITMASK(h, l)) == ((m) & ~BITMASK(h, l)))
#define BITMASK_ISINSIDE(n, h, l, m) (((n) & ~BITMASK(h, l)) == ((m) & ~BITMASK(h, l)))
#define BITMASK_ISEQUAL(n, h, l, m) (((n) & BITMASK(h, l)) == ((m) & BITMASK(h, l)))
#define BITMASK_ISNOTEQUAL(n, h, l, m) (((n) & BITMASK(h, l)) != ((m) & BITMASK(h, l)))
#define BITMASK_ISGREATER(n, h, l, m) (((n) & BITMASK(h, l)) > ((m) & BITMASK(h, l)))
#define BITMASK_ISGREATEROREQUAL(n, h, l, m) (((n) & BITMASK(h, l)) >= ((m) & BITMASK(h, l)))
#define BITMASK_ISLESS(n, h, l, m) (((n) & BITMASK(h, l)) < ((m) & BITMASK(h, l)))
#define BITMASK_ISLESSOREQUAL(n, h, l, m) (((n) & BITMASK(h, l)) <= ((m) & BITMASK(h, l)))
#define BITMASK_ISINCREASE(n, h, l) (((n) & BITMASK(h, l)) == BITMASK(h, l))
#define BITMASK_ISDECREASE(n, h, l) (((n) & BITMASK(h, l)) == 0)
#define BITMASK_ISPOSITIVE(n, h, l) (((n) & BITMASK(h, l)) > 0)
#define BITMASK_ISNEGATIVE(n, h, l) (((n) & BITMASK(h, l)) < 0)
#define BITMASK_ISZERO(n, h, l) (((n) & BITMASK(h, l)) == 0)
#define BITMASK_ISODD(n, h, l) (BITMASK_ISODD(n & BITMASK(h, l)))
#define BITMASK_ISEVEN(n, h, l) (BITMASK_ISEVEN(n & BITMASK(h, l)))
#define BITMASK_ISPRIME(n, h, l) (BITMASK_ISPRIME(n & BITMASK(h, l)))
#define BITMASK_ISPALINDROME(n, h, l) (BITMASK_ISPALINDROME(n & BITMASK(h, l)))
#define BITMASK_ISPERFECT(n, h, l) (BITMASK_ISPERFECT(n & BITMASK(h, l)))
#define BITMASK_ISPOWEROF2(n, h, l) (BITMASK_ISPOWEROF2(n & BITMASK(h, l)))
#define BITMASK_ISPOWEROF10(n, h, l) (BITMASK_ISPOWEROF10(n & BITMASK(h, l)))
#define BITMASK_ISPOWEROFN(n, h, l, m) (BITMASK_ISPOWEROFN(n & BITMASK(h, l), m))
#define BITMASK_ISPOWEROFM(n, h, l, m) (BITMASK_ISPOWEROFM(n & BITMASK(h, l), m))
#define BITMASK_ISPOWEROFK(n, h, l, k) (BITMASK_ISPOWEROFK(n & BITMASK(h, l), k))
#define BITMASK_ISPOWEROF2P(n) (BITMASK_ISPOWEROF2P(n))
#define BITMASK_ISPOWEROF10P(n) (BITMASK_ISPOWEROF10P(n))
#define BITMASK_ISPOWEROFNP(n, m) (BITMASK_ISPOWEROFNP(n, m))
#define BITMASK_ISPOWEROFMP(n, m) (BITMASK_ISPOWEROFMP(n, m))
#define BITMASK_ISPOWEROFKP(n, k) (BITMASK_ISPOWEROFKP(n, k))
#define BITMASK_ISPOWEROF2M(n, m) (BITMASK_ISPOWEROF2M(n, m))
#define BITMASK_ISPOWEROF2K(n, k) (BITMASK_ISPOWEROF2K(n, k))
#define BITMASK_ISPOWEROF10M(n, m) (BITMASK_ISPOWEROF10M(n, m))
#define BITMASK_ISPOWEROF10K(n, k) (BITMASK_ISPOWEROF10K(n, k))
#define BITMASK_ISPOWEROFNM(n, m, k) (BITMASK_ISPOWEROFNM(n, m, k))
#define BITMASK_ISPOWEROFMK(n, m, k) (BITMASK_ISPOWEROFMK(n, m, k))
#define BITMASK_ISPOWEROFKM(n, k, m) (BITMASK_ISPOWEROFKM(n, k, m))
#define BITMASK_ISPOWEROF2MK(n, m, k) (BITMASK_ISPOWEROF2MK(n, m, k))
#define BITMASK_ISPOWEROF2KM(n, k, m) (BITMASK_ISPOWEROF2KM(n, k, m))
#define BITMASK_ISPOWEROF10MK(n, m, k) (BITMASK_ISPOWEROF10MK(n, m, k))
#define BITMASK_ISPOWEROF10KM(n, k, m) (BITMASK_ISPOWEROF10KM(n, k, m))
#define BITMASK_ISPOWEROFNMK(n, m, k, l) (BITMASK_ISPOWEROFNMK(n, m, k, l))
#define BITMASK_ISPOWEROFMKN(n, m, k, l) (BITMASK_ISPOWEROFMKN(n, m, k, l))
#define BITMASK_ISPOWEROFKMN(n, k, m, l) (BITMASK_ISPOWEROFKMN(n, k, m, l))
#define BITMASK_ISPOWEROF2MKN(n, m, k, l) (BITMASK_ISPOWEROF2MKN(n, m, k, l))
#define BITMASK_ISPOWEROF2KMN(n, k, m, l) (BITMASK_ISPOWEROF2KMN(n, k, m, l))
#define BITMASK_ISPOWEROF10MKN(n, m, k, l) (BITMASK_ISPOWEROF10MKN(n, m, k, l))
#define BITMASK_ISPOWEROF10KMN(n, k, m, l) (BITMASK_ISPOWEROF10KMN(n, k, m, l))
#define BITMASK_ISPOWEROFNMKL(n, m, k, l, r) (BITMASK_ISPOWEROFNMKL(n, m, k, l, r))
#define BITMASK_ISPOWEROFMKLN(n, m, k, l, r) (BITMASK_ISPOWEROFMKLN(n, m, k, l, r))
#define BITMASK_ISPOWEROFKMLN(n, k, m, l, r) (BITMASK_ISPOWEROFKMLN(n, k, m, l, r))
#define BITMASK_ISPOWEROF2MKLN(n, m, k, l, r) (BITMASK_ISPOWEROF2MKLN(n, m, k, l, r))
#define BITMASK_ISPOWEROF2KMLN(n, k, m, l, r) (BITMASK_ISPOWEROF2KMLN(n, k, m, l, r))
#define BITMASK_ISPOWEROF10MKLN(n, m, k, l, r) (BITMASK_ISPOWEROF10MKLN(n, m, k, l, r))
#define BITMASK_ISPOWEROF10KMLN(n, k, m, l, r) (BITMASK_ISPOWEROF10KMLN(n, k, m, l, r))
#define BITMASK_ISPOWEROFNMKLR(n, m, k, l, r) (BITMASK_ISPOWEROFNMKLR(n, m, k, l, r))
#define BITMASK_ISPOWEROFMKNLR(n, m, k, l, r) (BITMASK_ISPOWEROFMKNLR(n, m, k, l, r))
#define BITMASK_ISPOWEROFKMNLR(n, k, m, l, r) (BITMASK_ISPOWEROFKMNLR(n, k, m, l, r))
#define BITMASK_ISPOWEROF2MKNLR(n, m, k, l, r) (BITMASK_ISPOWEROF2MKNLR(n, m, k, l, r))
#define BITMASK_ISPOWEROF2KMNLR(n, k, m, l, r) (BITMASK_ISPOWEROF2KMNLR(n, k, m, l, r))
#define BITMASK_ISPOWEROF10MKNLR(n, m, k, l, r) (BITMASK_ISPOWEROF10MKNLR(n, m, k, l, r))
#define BITMASK_ISPOWEROF10KMNLR(n, k, m, l, r) (BITMASK_ISPOWEROF10KMNLR(n, k, m, l, r))
#define BITMASK_ISPOWEROFNMKLRS(n, m, k, l, r, s) (BITMASK_ISPOWEROFNMKLRS(n, m, k, l, r, s))
#define BITMASK_ISPOWEROFMKLNRS(n, m, k, l, r, s) (BITMASK_ISPOWEROFMKLNRS(n, m, k, l, r, s))
#define BITMASK_ISPOWEROFKMLNRS(n, k, m, l, r, s) (BITMASK_ISPOWEROFKMLNRS(n, k, m, l, r, s))
#define BITMASK_ISPOWEROF2MKLNRS(n, m, k, l, r, s) (BITMASK_ISPOWEROF2MKLNRS(n, m, k, l, r, s))
#define BITMASK_ISPOWEROF2KMLNRS(n, k, m, l, r, s) (BITMASK_ISPOWEROF2KMLNRS(n, k, m, l, r, s))
#define BITMASK_ISPOWEROF10MKLNRS(n, m, k, l, r, s) (BITMASK_ISPOWEROF10MKLNRS(n, m, k, l, r, s))
#define BITMASK_ISPOWEROF10KMLNRS(n, k, m, l, r, s) (BITMASK_ISPOWEROF10KMLNRS(n, k, m, l, r, s))
#define BITMASK_ISPOWEROFNMKLRST(n, m, k, l, r, s, t) (BITMASK_ISPOWEROFNMKLRST(n, m, k, l, r, s, t))
#define BITMASK_ISPOWEROFMKNLRST(n, m, k, l, r, s, t) (BITMASK_ISPOWEROFMKNLRST(n, m, k, l, r, s, t))
#define BITMASK_ISPOWEROFKMNLRST(n, k, m, l, r, s, t) (BITMASK_ISPOWEROFKMNLRST(n, k, m, l, r, s, t))
#define BITMASK_ISPOWEROF2MKNLRST(n, m, k, l, r, s, t) (BITMASK_ISPOWEROF2MKNLRST(n, m, k, l, r, s, t))
#define BITMASK_ISPOWEROF2KMNLRST(n, k, m, l, r, s, t) (BITMASK_ISPOWEROF2KMNLRST(n, k, m, l, r, s, t))
#define BITMASK_ISPOWEROF10MKNLRST(n, m, k, l, r, s, t) (BITMASK_ISPOWEROF10MKNLRST(n, m, k, l, r, s, t))
#define BITMASK_ISPOWEROF10KMNLRST(n, k, m, l, r, s, t) (BITMASK_ISPOWEROF10KMNLRST(n, k, m, l, r, s, t))
#define BITMASK_ISPOWEROFNMKLRSU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROFNMKLRSU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROFMKLNRSU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROFMKLNRSU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROFKMLNRSU(n, k, m, l, r, s, t, u) (BITMASK_ISPOWEROFKMLNRSU(n, k, m, l, r, s, t, u))
#define BITMASK_ISPOWEROF2MKLNRSU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROF2MKLNRSU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROF2KMLNRSU(n, k, m, l, r, s, t, u) (BITMASK_ISPOWEROF2KMLNRSU(n, k, m, l, r, s, t, u))
#define BITMASK_ISPOWEROF10MKLNRSU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROF10MKLNRSU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROF10KMLNRSU(n, k, m, l, r, s, t, u) (BITMASK_ISPOWEROF10KMLNRSU(n, k, m, l, r, s, t, u))
#define BITMASK_ISPOWEROFNMKLRSTU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROFNMKLRSTU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROFMKNLRSTU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROFMKNLRSTU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROFKMNLRSTU(n, k, m, l, r, s, t, u) (BITMASK_ISPOWEROFKMNLRSTU(n, k, m, l, r, s, t, u))
#define BITMASK_ISPOWEROF2MKNLRSTU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROF2MKNLRSTU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROF2KMNLRSTU(n, k, m, l, r, s, t, u) (BITMASK_ISPOWEROF2KMNLRSTU(n, k, m, l, r, s, t, u))
#define BITMASK_ISPOWEROF10MKNLRSTU(n, m, k, l, r, s, t, u) (BITMASK_ISPOWEROF10MKNLRSTU(n, m, k, l, r, s, t, u))
#define BITMASK_ISPOWEROF10KMNLRSTU(n, k, m, l, r, s, t, u) (BITMASK_ISPOWEROF10KMNLRSTU(n, k, m, l, r, s, t, u))
#define BITMASK_ISPOWEROFNMKLRSUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROFNMKLRSUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROFMKLNRSUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROFMKLNRSUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROFKMLNRSUV(n, k, m, l, r, s, t, u, v) (BITMASK_ISPOWEROFKMLNRSUV(n, k, m, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF2MKLNRSUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROF2MKLNRSUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF2KMLNRSUV(n, k, m, l, r, s, t, u, v) (BITMASK_ISPOWEROF2KMLNRSUV(n, k, m, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF10MKLNRSUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROF10MKLNRSUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF10KMLNRSUV(n, k, m, l, r, s, t, u, v) (BITMASK_ISPOWEROF10KMLNRSUV(n, k, m, l, r, s, t, u, v))
#define BITMASK_ISPOWEROFNMKLRSTUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROFNMKLRSTUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROFMKNLRSTUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROFMKNLRSTUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROFKMNLRSTUV(n, k, m, l, r, s, t, u, v) (BITMASK_ISPOWEROFKMNLRSTUV(n, k, m, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF2MKNLRSTUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROF2MKNLRSTUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF2KMNLRSTUV(n, k, m, l, r, s, t, u, v) (BITMASK_ISPOWEROF2KMNLRSTUV(n, k, m, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF10MKNLRSTUV(n, m, k, l, r, s, t, u, v) (BITMASK_ISPOWEROF10MKNLRSTUV(n, m, k, l, r, s, t, u, v))
#define BITMASK_ISPOWEROF10KMNLRSTUV(n, k, m, l, r, s, t, u, v) (BITMASK_ISPOWEROF10KMNLRSTUV(n, k, m, l, r, s, t, u, v))
#define BITMASK_ISPOWEROFNMKLRSUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROFNMKLRSUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROFMKLNRSUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROFMKLNRSUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROFKMLNRSUVW(n, k, m, l, r, s, t, u, v, w) (BITMASK_ISPOWEROFKMLNRSUVW(n, k, m, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF2MKLNRSUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF2MKLNRSUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF2KMLNRSUVW(n, k, m, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF2KMLNRSUVW(n, k, m, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF10MKLNRSUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF10MKLNRSUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF10KMLNRSUVW(n, k, m, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF10KMLNRSUVW(n, k, m, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROFNMKLRSTUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROFNMKLRSTUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROFMKNLRSTUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROFMKNLRSTUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROFKMNLRSTUVW(n, k, m, l, r, s, t, u, v, w) (BITMASK_ISPOWEROFKMNLRSTUVW(n, k, m, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF2MKNLRSTUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF2MKNLRSTUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF2KMNLRSTUVW(n, k, m, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF2KMNLRSTUVW(n, k, m, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF10MKNLRSTUVW(n, m, k, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF10MKNLRSTUVW(n, m, k, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROF10KMNLRSTUVW(n, k, m, l, r, s, t, u, v, w) (BITMASK_ISPOWEROF10KMNLRSTUVW(n, k, m, l, r, s, t, u, v, w))
#define BITMASK_ISPOWEROFNMKLRSUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROFNMKLRSUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROFMKLNRSUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROFMKLNRSUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROFKMLNRSUVWX(n, k, m, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROFKMLNRSUVWX(n, k, m, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF2MKLNRSUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF2MKLNRSUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF2KMLNRSUVWX(n, k, m, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF2KMLNRSUVWX(n, k, m, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF10MKLNRSUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF10MKLNRSUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF10KMLNRSUVWX(n, k, m, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF10KMLNRSUVWX(n, k, m, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROFNMKLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROFNMKLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROFMKNLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROFMKNLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROFKMNLRSTUVWX(n, k, m, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROFKMNLRSTUVWX(n, k, m, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF2MKNLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF2MKNLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF2KMNLRSTUVWX(n, k, m, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF2KMNLRSTUVWX(n, k, m, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF10MKNLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF10MKNLRSTUVWX(n, m, k, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROF10KMNLRSTUVWX(n, k, m, l, r, s, t, u, v, w, x) (BITMASK_ISPOWEROF10KMNLRSTUVWX(n, k, m, l, r, s, t, u, v, w, x))
#define BITMASK_ISPOWEROFNMKLRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROFNMKLRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROFMKLNRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROFMKLNRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROFKMLNRSUVWXY(n, k, m, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROFKMLNRSUVWXY(n, k, m, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF2MKLNRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF2MKLNRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF2KMLNRSUVWXY(n, k, m, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF2KMLNRSUVWXY(n, k, m, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF10MKLNRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF10MKLNRSUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF10KMLNRSUVWXY(n, k, m, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF10KMLNRSUVWXY(n, k, m, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROFNMKLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROFNMKLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROFMKNLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROFMKNLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROFKMNLRSTUVWXY(n, k, m, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROFKMNLRSTUVWXY(n, k, m, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF2MKNLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF2MKNLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF2KMNLRSTUVWXY(n, k, m, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF2KMNLRSTUVWXY(n, k, m, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF10MKNLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF10MKNLRSTUVWXY(n, m, k, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROF10KMNLRSTUVWXY(n, k, m, l, r, s, t, u, v, w, x, y) (BITMASK_ISPOWEROF10KMNLRSTUVWXY(n, k, m, l, r, s, t, u, v, w, x, y))
#define BITMASK_ISPOWEROFNMKLRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z) (BITMASK_ISPOWEROFNMKLRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z))
#define BITMASK_ISPOWEROFMKLNRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z) (BITMASK_ISPOWEROFMKLNRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z))
#define BITMASK_ISPOWEROFKMLNRSUVWXYZ(n, k, m, l, r, s, t, u, v, w, x, y, z) (BITMASK_ISPOWEROFKMLNRSUVWXYZ(n, k, m, l, r, s, t, u, v, w, x, y, z))
#define BITMASK_ISPOWEROF2MKLNRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z) (BITMASK_ISPOWEROF2MKLNRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z))
#define BITMASK_ISPOWEROF2KMLNRSUVWXYZ(n, k, m, l, r, s, t, u, v, w, x, y, z) (BITMASK_ISPOWEROF2KMLNRSUVWXYZ(n, k, m, l, r, s, t, u, v, w, x, y, z))
#define BITMASK_ISPOWEROF10MKLNRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z) (BITMASK_ISPOWEROF10MKLNRSUVWXYZ(n, m, k, l, r, s, t, u, v, w, x, y, z))
#define BITMASK_ISPOWEROF10KMLNRSUVWXYZ(n, k, m, l, r, s, t, u, v, w, x, y, z) (BITMASK_ISPOWEROF10KMLNRSUVWXYZ(n, k, m, l, r, s, t, u, v, w, x, y, z))
#define BITMASK_ISPOWEROFNMKLRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a) (BITMASK_ISPOWEROFNMKLRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a))
#define BITMASK_ISPOWEROFMKLNRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a) (BITMASK_ISPOWEROFMKLNRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a))
#define BITMASK_ISPOWEROFKMLNRSUVWXYZA(n, k, m, l, r, s, t, u, v, w, x, y, z, a) (BITMASK_ISPOWEROFKMLNRSUVWXYZA(n, k, m, l, r, s, t, u, v, w, x, y, z, a))
#define BITMASK_ISPOWEROF2MKLNRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a) (BITMASK_ISPOWEROF2MKLNRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a))
#define BITMASK_ISPOWEROF2KMLNRSUVWXYZA(n, k, m, l, r, s, t, u, v, w, x, y, z, a) (BITMASK_ISPOWEROF2KMLNRSUVWXYZA(n, k, m, l, r, s, t, u, v, w, x, y, z, a))
#define BITMASK_ISPOWEROF10MKLNRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a) (BITMASK_ISPOWEROF10MKLNRSUVWXYZA(n, m, k, l, r, s, t, u, v, w, x, y, z, a))
#define BITMASK_ISPOWEROF10KMLNRSUVWXYZA(n, k, m, l, r, s, t, u, v, w, x, y, z, a) (BITMASK_ISPOWEROF10KMLNRSUVWXYZA(n, k, m, l, r, s, t, u, v, w, x, y, z, a))
#define BITMASK_ISPOWEROFNMKLRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b) (BITMASK_ISPOWEROFNMKLRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b))
#define BITMASK_ISPOWEROFMKLNRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b) (BITMASK_ISPOWEROFMKLNRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b))
#define BITMASK_ISPOWEROFKMLNRSUVWXYZAB(n, k, m, l, r, s, t, u, v, w, x, y, z, a, b) (BITMASK_ISPOWEROFKMLNRSUVWXYZAB(n, k, m, l, r, s, t, u, v, w, x, y, z, a, b))
#define BITMASK_ISPOWEROF2MKLNRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b) (BITMASK_ISPOWEROF2MKLNRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b))
#define BITMASK_ISPOWEROF2KMLNRSUVWXYZAB(n, k, m, l, r, s, t, u, v, w, x, y, z, a, b) (BITMASK_ISPOWEROF2KMLNRSUVWXYZAB(n, k, m, l, r, s, t, u, v, w, x, y, z, a, b))
#define BITMASK_ISPOWEROF10MKLNRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b) (BITMASK_ISPOWEROF10MKLNRSUVWXYZAB(n, m, k, l, r, s, t, u, v, w, x, y, z, a, b))
#define BITMASK_ISPOWEROF10KMLNRSUVWXYZAB(n, k, m, l, r, s, t, u, v, w, x, y, z, a, b) (BITMASK_ISPOWEROF10KMLNRSUVWXYZAB(n, k, m, l, r, s, t, u, v, w, x, y, z, a, b))
