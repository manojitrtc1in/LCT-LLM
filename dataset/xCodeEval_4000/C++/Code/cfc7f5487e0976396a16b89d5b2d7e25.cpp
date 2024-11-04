




#define FILE_NAME "model.cpp"
#ifndef ONLINE_JUDGE
#define _LOCAL_JUDGE
#endif
#if defined(_MSC_VER)
#define _CRT_SECURE_NO_WARNINGS
#endif




#if 01


#if ((defined(__cplusplus) && (__cplusplus >= 201103L) || defined(_MSC_VER) && (_MSC_VER >= 1900)))
#define __cpp11
#endif
#if defined(__GNUC__) || defined(__GNUG__)


#endif
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#ifdef __cpp11
#include <array>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#endif
#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <memory>
#include <numeric>
#include <string>
#include <typeinfo>
#include <utility>
#ifdef __cpp11
#include <initializer_list>
#include <random>
#include <tuple>
#include <type_traits>
#endif
using namespace std;

#ifdef _LOCAL_JUDGE
#define DBG(...)     OUT(__VA_ARGS__);
#define DBG_(...)    OUT_(__VA_ARGS__);
#define _DBG(...)    _OUT(__VA_ARGS__);
#define DBGn         OUTn
#define DBGnm        OUTnm
#else
#define DBG(...)
#define DBG_(...)
#define _DBG(...)
#define DBGn(...)
#define DBGnm(...)
#define watch(...)
#endif

#ifdef _LOCAL_JUDGE
#include "G:\OnlineJudge\cplusplus_improvement_library\all.h"


#else
#define FOR(i, a, b)          for (long long i = (long long)(a); i < (long long)(b); ++i)
#define ROF(i, a, b)          for (long long i = (long long)(b) - 1; i >= (long long)(a); --i)
#define rep(i, a, b)          for (long long i = (long long)(a); i < (long long)(b); ++i)
#define per(i, a, b)          for (long long i = (long long)(b) - 1; i >= (long long)(a); --i)
#define REP(i, n)             for (long long i = 0; i < (long long)(n); ++i)
#define PER(i, n)             for (long long i = (long long)(n) - 1; i >= 0; --i)
#if                           defined(__GNUC__) || defined(__GNUG__)
#define ECH(i, c)             for (__typeof(c.begin()) i = c.begin(), e = c.end(); i != e; ++i)
#define HCE(i, c)             for (__typeof(c.rbegin()) i = c.rbegin(), e = c.rend(); i != e; ++i)
#else
#define ECH(i, c)             for (auto i = c.begin(), e = c.end(); i != e; ++i)
#define HCE(i, c)             for (auto i = c.rbegin(), e = c.rend(); i != e; ++i)
#endif
#define DO(n)                 for (int _iDO_ = int(n); _iDO_--;)
#define rush()                int _CASES_; scanf("%d\n", &_CASES_); for (int iCase = 1; iCase <= _CASES_; ++iCase)
#define cases()               int _CASES_; scanf("%d\n", &_CASES_); for (int iCase = 1; (iCase <= _CASES_ && printf("Case #%d:\n", iCase)); ++iCase)
#define sqr(x)                ((x) * (x))
#define cub(x)                ((x) * (x) * (x))
#define all(x)                (x).begin(), (x).end()
#define sortall(x)            sort((x).begin(), (x).end())
#define reverseall(x)         reverse((x).begin(), (x).end())
#define sz(x)                 ((int)(x).size())
#define eb                    emplace_back
#define pb                    push_back
#define pf                    push_front
#define ppb                   pop_back
#define ppf                   pop_front
#define mp                    make_pair
#define pbmp(a, b)            push_back(make_pair((a), (b)))
#define fi                    first
#define se                    second
#define ms(a, b)              memset((a), (b), sizeof(a))
#define cp(a, b)              memcpy((a), (b), sizeof(a))
#define IOSS0                 std::ios::sync_with_stdio(false);cin.tie(0);
#define whatis(x)             cout << #x << " = " << x << endl;
#define uniqueit(v)           (v).erase(unique((v).begin(), (v).end()), (v).end())
#define insertlb(v, a)        (v).insert(lower_bound((v).begin(), (v).end(), (a)), (a))
#define insertub(v, a)        (v).insert(upper_bound((v).begin(), (v).end(), (a)), (a))
#define PQ                    priority_queue
#define uset                  unordered_set
#define mset                  multiset
#define umap                  unordered_map
#define mmap                  multimap
typedef double                db;
typedef long double           ldb;
typedef unsigned char         uchar;
typedef unsigned short        ushort;
typedef unsigned int          uint;
typedef long long             ll;
typedef unsigned long long    ull;
typedef vector<bool>          VB;
typedef vector<VB>            VVB;
typedef vector<char>          VC;
typedef vector<VC>            VVC;
typedef vector<int>           VI;
typedef vector<VI>            VVI;
typedef vector<ll>            VLL;
typedef vector<VLL>           VVLL;
typedef vector<double>        VD;
typedef vector<VD>            VVD;
typedef vector<string>        VS;
typedef vector<VS>            VVS;
typedef pair<int, int>        PII;
typedef pair<ll, ll>          PLL;
typedef vector<PII>           VPII;
typedef vector<PLL>           VPLL;
typedef pair<int, PII>        PIPII;
typedef pair<ll, PLL>         PLPLL;
typedef pair<PII, int>        PPIII;
typedef pair<PLL, ll>         PPLLL;
typedef map<int, int>         MII;
typedef map<ll, ll>           MLL;
typedef map<db, db>           MDD;
typedef map<string, int>      MSI;
typedef map<int, string>      MIS;
typedef set<int>              SI;
typedef set<ll>               SLL;
typedef queue<int>            QI;
typedef queue<ll>             QLL;
typedef queue<PII>            QPII;
typedef deque<int>            DI;
typedef deque<ll>             DLL;
typedef deque<PII>            DPII;
const double                  eps = 1e-9;
const double                  pi = 3.14159265358979323846264338327950288419716939937510;
const int                     inf = 0x3f3f3f3f;
const int                     mod = 1000000007;
const int                     mod2 = 1000000006;
const long long               infll = 0x3f3f3f3f3f3f3f3fLL;
const int                     dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
const int                     dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };





template<typename T> inline bool RD(T& v) { char c; bool n; while (c = getchar(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = getchar(), c >= '0' && c <= '9') v = (v << 3) + (v << 1) + c - '0'; if (n) v *= -1; return true; }
#ifdef __cpp11
template<typename A, typename ...Args> inline bool RD(A& a, Args&... rest) { return RD(a) && RD(rest...); }
#else
template<typename T> inline bool RD(T& a, T& b) { return RD(a) && RD(b); }
template<typename T> inline bool RD(T& a, T& b, T& c) { return RD(a, b) && RD(c); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d) { return RD(a, b, c) && RD(d); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e) { return RD(a, b, c, d) && RD(e); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f) { return RD(a, b, c, d, e) && RD(f); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g) { return RD(a, b, c, d, e, f) && RD(g); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h) { return RD(a, b, c, d, e, f, g) && RD(h); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i) { return RD(a, b, c, d, e, f, g, h) && RD(i); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i, T& j) { return RD(a, b, c, d, e, f, g, h, i) && RD(j); }
#endif
inline int RD() { int v; RD(v); return v; }


static char _BUF_[1 << 15], *_HEAD_ = _BUF_, *_TAIL_ = _BUF_;
inline static char getchar_buffered() { return _HEAD_ == _TAIL_ && (_TAIL_ = (_HEAD_ = _BUF_) + fread(_BUF_, 1, 1 << 15, stdin), _HEAD_ == _TAIL_) ? EOF : *_HEAD_++; }
template<typename T> inline bool RDB(T& v) { char c; bool n; while (c = getchar_buffered(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = getchar_buffered() - '0', c >= 0 && c <= 9) v = (v << 3) + (v << 1) + c; if (n) v *= -1; return true; }
#ifdef __cpp11
template<typename A, typename ...Args> inline bool RDB(A& a, Args&... rest) { return RDB(a) && RDB(rest...); }
#else
template<typename T> inline bool RDB(T& a, T& b) { return RDB(a) && RDB(b); }
template<typename T> inline bool RDB(T& a, T& b, T& c) { return RDB(a, b) && RDB(c); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d) { return RDB(a, b, c) && RDB(d); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e) { return RDB(a, b, c, d) && RDB(e); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f) { return RDB(a, b, c, d, e) && RDB(f); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g) { return RDB(a, b, c, d, e, f) && RDB(g); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h) { return RDB(a, b, c, d, e, f, g) && RDB(h); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i) { return RDB(a, b, c, d, e, f, g, h) && RDB(i); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i, T& j) { return RDB(a, b, c, d, e, f, g, h, i) && RDB(j); }
#endif
inline int RDB() { int v; RDB(v); return v; }


template<typename T> inline void _WR(T a) { if (a < 0) { putchar('-'); a *= -1; } T t = a / 10; if (t) _WR(t); putchar(a - (t << 1) - (t << 3) + '0'); }
template<typename T> inline void WR_(const T&a) { _WR(a); putchar(' '); }
template<typename T> inline void WR(const T&a) { _WR(a); putchar('\n'); }
#ifdef __cpp11
template<typename A, typename ...Args> inline void _WR(const A& a, const Args&... rest) { WR_(a); _WR(rest...); }
template<typename A, typename ...Args> inline void WR_(const A& a, const Args&... rest) { WR_(a); WR_(rest...); }
template<typename A, typename ...Args> inline void WR(const A& a, const Args&... rest) { WR_(a); WR(rest...); }
#else
template<typename T> inline void _WR(const T& a, const T& b) { WR_(a); _WR(b); }
template<typename T> inline void WR_(const T& a, const T& b) { WR_(a); WR_(b); }
template<typename T> inline void WR(const T& a, const T& b) { WR_(a); WR(b); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c) { WR_(a, b); _WR(c); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c) { WR_(a, b); WR_(c); }
template<typename T> inline void WR(const T& a, const T& b, const T& c) { WR_(a, b); WR(c); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); _WR(d); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); WR_(d); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); WR(d); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); _WR(e); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); WR_(e); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); WR(e); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); _WR(f); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); WR_(f); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); WR(f); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); _WR(g); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); WR_(g); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); WR(g); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); _WR(h); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); WR_(h); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); WR(h); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); _WR(i); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); WR_(i); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); WR(i); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); _WR(j); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); WR_(j); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); WR(j); }
#endif
#define RDn(a, l, r)          { rep(_i_, l, r) RD((a)[_i_]); }
#define RDBn(a, l, r)         { rep(_i_, l, r) RDB((a)[_i_]); }
#define WRn(a, l, r)          { rep(_i_, l, r - 1) WR_((a)[_i_]); if(r > 0) WR((a)[r - 1]); }
#define RDnm(a, b, c, d, e)   { rep(__i__, b, c) RDn(a[__i__], d, e) }
#define RDBnm(a, b, c, d, e)  { rep(__i__, b, c) RDBn(a[__i__], d, e) }
#define WRnm(a, b, c, d, e)   { rep(__i__, b, c) WRn(a[__i__], d, e) }




template <typename A> inline istream &IN(A& a) { return std::cin >> a; }
#ifdef __cpp11
template <typename A, typename ...Args> inline istream &IN(A& a, Args&... rest) { std::cin >> a; return IN(rest...); }
#else
template <typename A, typename B> inline istream &IN(A& a, B& b) { return std::cin >> a >> b; }
template <typename A, typename B, typename C> inline istream &IN(A& a, B& b, C& c) { return std::cin >> a >> b >> c; }
template <typename A, typename B, typename C, typename D> inline istream &IN(A& a, B& b, C& c, D& d) { return std::cin >> a >> b >> c >> d; }
template <typename A, typename B, typename C, typename D, typename E> inline istream &IN(A& a, B& b, C& c, D& d, E& e) { return std::cin >> a >> b >> c >> d >> e; }
template <typename A, typename B, typename C, typename D, typename E, typename F> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f) { return std::cin >> a >> b >> c >> d >> e >> f; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g) { return std::cin >> a >> b >> c >> d >> e >> f >> g; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h, I& i) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h, I& i, J& j) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j; }
#endif
inline std::ostream& OUT() { return std::cout << std::endl; }
#ifdef __cpp11
template <typename A> inline ostream& _OUT(const A &a) { return std::cout << a; }
template <typename A, typename...Args> inline ostream& _OUT(const A &a, const Args&... rest) { std::cout << a << " "; return _OUT(rest...); }
template <typename...Args> inline ostream& OUT_(const Args&... args) { _OUT(args...); return std::cout << " "; }
template <typename...Args> inline ostream& OUT(const Args&... args) { _OUT(args...); return std::cout << std::endl; }
#else
template<typename T> inline ostream& _OUT(const T&a) { return std::cout << a; }
template<typename T> inline ostream& OUT_(const T&a) { return std::cout << a << ' '; }
template<typename T> inline ostream& OUT(const T&a) { return std::cout << a << std::endl; }
template<typename T, typename U> inline ostream& _OUT(const T&a, const U&b) { return std::cout << a << " " << b; }
template<typename T, typename U> inline ostream& OUT_(const T&a, const U&b) { return std::cout << a << " " << b << " "; }
template<typename T, typename U> inline ostream& OUT(const T&a, const U&b) { return std::cout << a << " " << b << std::endl; }
template<typename T, typename U, typename V> inline ostream& _OUT(const T&a, const U&b, const V&c) { OUT_(a, b); return _OUT(c); }
template<typename T, typename U, typename V> inline ostream& OUT_(const T&a, const U&b, const V&c) { OUT_(a, b); return OUT_(c); }
template<typename T, typename U, typename V> inline ostream& OUT(const T&a, const U&b, const V&c) { OUT_(a, b); return OUT(c); }
template<typename T, typename U, typename V, typename W> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return _OUT(d); }
template<typename T, typename U, typename V, typename W> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return OUT_(d); }
template<typename T, typename U, typename V, typename W> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return OUT(d); }
template<typename T, typename U, typename V, typename W, typename X> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return _OUT(e); }
template<typename T, typename U, typename V, typename W, typename X> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return OUT_(e); }
template<typename T, typename U, typename V, typename W, typename X> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return OUT(e); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return _OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return OUT_(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return _OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return OUT_(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return _OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return OUT_(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return _OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return OUT_(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return _OUT(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return OUT_(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return OUT(j); }
#endif
#define INn(a, b, c)          { rep(_i_, b, c) IN(a[_i_]); }
#define INnm(a, b, c, d, e)   { rep(__i__, b, c) INn(a[__i__], d, e) }
#define OUTn(a, l, r)         { rep(_i_, l, r - 1) OUT_((a)[_i_]); if(r > 0) OUT((a)[r - 1]); }
#define OUTnm(a, b, c, d, e)  { rep(__i__, b, c) OUTn(a[__i__], d, e) }



template<typename A> inline void clr(A& a) { a.clear(); }
#ifdef __cpp11
template<typename A, typename...Args> inline void clr(A& a, Args&... args) { a.clear(); clr(args...); }
#else
template<typename A, typename B> inline void clr(A &a, B &b) { a.clear(); b.clear(); }
template<typename A, typename B, typename C> inline void clr(A &a, B &b, C &c) { a.clear(); b.clear(); c.clear(); }
template<typename A, typename B, typename C, typename D> inline void clr(A &a, B &b, C &c, D &d) { a.clear(); b.clear(); c.clear(); d.clear(); }
template<typename A, typename B, typename C, typename D, typename E> inline void clr(A &a, B &b, C &c, D &d, E &e) { a.clear(); b.clear(); c.clear(); d.clear(); e.clear(); }
template<typename A, typename B, typename C, typename D, typename E, typename F> inline void clr(A &a, B &b, C &c, D &d, E &e, F &f) { a.clear(); b.clear(); c.clear(); d.clear(); e.clear(); f.clear(); }
#endif



inline long long madd(long long a, long long b, const long long mod = 1000000007) { long long ret = (a + b) % mod; if (ret < 0) ret += mod; return ret; }
inline long long msub(long long a, long long b, const long long mod = 1000000007) { long long ret = (a - b) % mod; if (ret < 0) ret += mod; return ret; }
inline long long mmul(long long a, long long b, const long long mod = 1000000007) { return a * b % mod; }
inline long long mpow(long long x, long long k, const long long mod = 1000000007) { x %= mod; long long ret = 1; while (k > 0) { if (k & 1) ret = ret * x % mod; x = x * x % mod; k >>= 1; } return ret; }


template<typename T, typename U> inline bool cmax(T& a, const U& b) { return a < b ? a = b, true : false; }
template<typename T, typename U> inline bool cmin(T& a, const U& b) { return a > b ? a = b, true : false; }


template<typename T, typename U> inline T cadd(T& a, const U& b, const int mod = 1000000007) { a = (a * 1LL + b) % mod; if (a < 0) a += mod; return a; }
template<typename T, typename U> inline T csub(T& a, const U& b, const int mod = 1000000007) { a = (a * 1LL - b) % mod; if (a < 0) a += mod; return a; }
template<typename T, typename U> inline T cmul(T& a, const U& b, const int mod = 1000000007) { return a = (a * 1LL * b) % mod; }


template<typename T> inline T clow(T& a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T cup(T& a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T cboth(T& a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }


template<typename T> inline T vlow(T a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T vup(T a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T vboth(T a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }



template<typename T> inline T max(const T& a, const T& b, const T& c) { return std::max(std::max(a, b), c); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d) { return std::max(max(a, b, c), d); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e) { return std::max(max(a, b, c, d), e); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { return std::max(max(a, b, c, d, e), f); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { return std::max(max(a, b, c, d, e, f), g); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { return std::max(max(a, b, c, d, e, f, g), h); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { return std::max(max(a, b, c, d, e, f, g, h), i); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { return std::max(max(a, b, c, d, e, f, g, h, i), j); }
template<typename T> inline T min(const T& a, const T& b, const T& c) { return std::min(std::min(a, b), c); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d) { return std::min(min(a, b, c), d); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e) { return std::min(min(a, b, c, d), e); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { return std::min(min(a, b, c, d, e), f); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { return std::min(min(a, b, c, d, e, f), g); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { return std::min(min(a, b, c, d, e, f, g), h); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { return std::min(min(a, b, c, d, e, f, g, h), i); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { return std::min(min(a, b, c, d, e, f, g, h, i), j); }

inline double run_time() { return 1.0 * clock() / CLOCKS_PER_SEC; }




template<typename T>
struct point {
	T x, y;
	point() {}
	point(T xx, T yy) : x(xx), y(yy) {}
	point(const point& B) : x(B.x), y(B.y) {}
	double radius() const { return sqrt(x * x + y *y); }
	double angle() const { return atan2(y, x); }
	double angle_degree() const { return atan2(y, x) * 180 / 3.14159265358979323846264338327950288419716939937510; }
	bool operator == (const point& B) const { return x == B.x && y == B.y; }
	bool operator != (const point& B) const { return x != B.x || y != B.y; }
	bool operator < (const point& B) const { return x < B.x || x == B.x && y < B.y; }
	bool operator > (const point& B) const { return x > B.x || x == B.x && y > B.y; }
	bool operator <= (const point& B) const { return x < B.x || x == B.x && y <= B.y; }
	bool operator >= (const point& B) const { return x > B.x || x == B.x && y >= B.y; }
	point& operator = (const point& B) { x = B.x; y = B.y; return *this; }
	point operator + (const point& B) const { return point(x + B.x, y + B.y); }
	point operator - (const point& B) const { return point(x - B.x, y - B.y); }
	point& operator += (const point& B) { x += B.x; y += B.y; return *this; }
	point& operator -= (const point& B) { x -= B.x; y -= B.y; return *this; }
	T operator * (const point& B) const { return x * B.x + y * B.y; }
	T operator ^ (const point& B) const { return x * B.y - y * B.x; }
};
template<typename T> std::ostream& operator<< (std::ostream& os, const point<T>& p) {
	return os << "(" << p.x << ", " << p.y << ")" << std::flush;
}

template<typename T> double distance(const point<T>& A, const point<T>& B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
template<typename T> double distance(T x1, T y1, T x2, T y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}











#ifndef __cpp11
template<typename PointType>
struct __CompareHelperForGraham {
	PointType o;
	__CompareHelperForGraham(PointType p) : o(p) {}
	bool operator() (const PointType& a, const PointType& b) const {
		return (a - o).angle() < (b - o).angle();
	}
};
#endif
template<typename RandomAccessIterator, typename OutputIterator>
OutputIterator Graham(RandomAccessIterator first, RandomAccessIterator last, OutputIterator output) {
	if (first == last) return output;
	RandomAccessIterator it = first;
	for (++it; it != last; ++it) if (*it < *first) swap(*first, *it);
	typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
#ifdef __cpp11
	auto cmp = [&](const value_type& a, const value_type& b) {
		return (a - *first).angle() < (b - *first).angle();
	};
#else
	__CompareHelperForGraham<value_type> cmp(*first);
#endif
	std::sort(first + 1, last, cmp);
	it = first;
	OutputIterator prev = output;
	*output = *it++;
	int cnt = 1;
	while (it != last) {
		while (cnt >= 2 && ((*output - *prev) ^ (*it - *output)) <= 0) {
			--output;
			if (--cnt != 1) --prev;
		}
		*++output = *it++;
		if (++cnt != 2) ++prev;
	}
	return ++output;
}





template<typename RandomAccessIterator, typename RandomAccessOutputIterator>
RandomAccessOutputIterator Graham2(RandomAccessIterator first, RandomAccessIterator last, RandomAccessOutputIterator output) {
	std::sort(first, last);
	int cnt = 0;
	RandomAccessIterator it = first;
	output[cnt++] = *it++;
	while (it != last) {
		while (cnt >= 2 && ((output[cnt - 1] - output[cnt - 2]) ^ (*it - output[cnt - 1])) <= 0) --cnt;
		output[cnt++] = *it++;
	}
	it -= 2;
	while (it != first) {
		while (cnt >= 2 && ((output[cnt - 1] - output[cnt - 2]) ^ (*it - output[cnt - 1])) <= 0) --cnt;
		output[cnt++] = *it--;
	}
	while (cnt >= 2 && ((output[cnt - 1] - output[cnt - 2]) ^ (*it - output[cnt - 1])) <= 0) --cnt;
	return output + cnt;
}

template<typename RandomAccessIterator>
std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type>
Graham(RandomAccessIterator first, RandomAccessIterator last) {
	std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> ret(last - first);
	ret.erase(Graham(first, last, ret.begin()), ret.end());
	return ret;
}
template<typename Container>
Container Graham(Container& c) {
	Container ret(c.size());
	ret.erase(Graham(c.begin(), c.end(), ret.begin()), ret.end());
	return ret;
}



































#endif




const int _  = (int)(2e5 + 10);
const int __ = (int)(1e6 + 10);
const int LOG = 20;


ll n, p, q;
ll a[_], b[_];
ldb f(ldb x) {
	ldb y = 1;
	REP(i, n) cmin(y, ldb(1 - x * b[i]) / a[i]);
	return p * y + x * q;
}
ldb solve1() {
	ldb l = 0, r = ldb(1) / ldb(*max_element(b, b + n));
	while (1) {
		ldb ml = (l + l + r) / 3;
		ldb mr = (l + r + r) / 3;
		ldb fl = f(ml);
		ldb fr = f(mr);
		if (run_time() > 1.9) {
			return (fl + fr) / 2;			
		}
		if (fl < fr) l = ml;
		else r = mr;
	}
}
ldb solve2() {
	ldb l = 0, r = ldb(1) / ldb(*max_element(b, b + n));
	DO (200) {
		ldb ml = (l + l + r) / 3;
		ldb mr = (l + r + r) / 3;
		ldb fl = f(ml);
		ldb fr = f(mr);
		if (fl < fr) l = ml;
		else r = mr;
	}
	return f((l + r) / 2);
}
ldb solve3() {
	ldb l = 0, r = ldb(1) / ldb(*max_element(b, b + n));
	while (1) {
		

		if (abs(r - l) < 1e-15) break;
		ldb ml = (l + l + r) / 3;
		ldb mr = (l + r + r) / 3;
		ldb fl = f(ml);
		ldb fr = f(mr);
		if (fl < fr) l = ml;
		else r = mr;
	}
	return f((l + r) / 2);
}

ldb solve4() {
	ldb ret = LDBL_MAX;
	REP(i, n) cmin(ret, max(ldb(p) / a[i], ldb(q) / b[i]));
	typedef point<ldb> Point;
	vector<Point> ps, hs;
	ps.push_back(Point(0, 0));
	REP(i, n) ps.push_back(Point(a[i], b[i]));
	hs = Graham(ps);
	
	

	Point T(p, q);

	FOR(i, 1, sz(hs) - 1) {
		ldb d1 = T ^ hs[i];
		ldb d2 = T ^ hs[i + 1];

		if (d1 * d2 > 0) continue;

		Point& p1 = hs[i];
		Point& p2 = hs[i + 1];


		Point k = p2 - p1;

		ldb x = p * (p1 ^ k) / (T ^ k);
		ldb y = q * x / p;

		ldb tmp = sqrt(p*p + q*q) / sqrt(x * x + y * y);
		

		cmin(ret, tmp);
		break;

	}


	return ret;
}

ldb solve5() {
	ldb ret = LDBL_MAX;

	typedef point<ldb> Point;
	vector<Point> ps, hs;
	ps.push_back(Point(0, 0));
	ps.push_back(Point(*max_element(a, a + n), 0));
	ps.push_back(Point(0, *max_element(b, b + n)));
	REP(i, n) ps.push_back(Point(a[i], b[i]));
	hs = Graham(ps);

	

	Point T(p, q);

	FOR(i, 1, sz(hs) - 1) {
		ldb d1 = T ^ hs[i];
		ldb d2 = T ^ hs[i + 1];

		if (d1 * d2 > 0) continue;

		Point& p1 = hs[i];
		Point& p2 = hs[i + 1];


		Point k = p2 - p1;

		ldb x = p * (p1 ^ k) / (T ^ k);
		ldb y = q * x / p;

		ldb tmp = sqrt(p*p + q*q) / sqrt(x * x + y * y);

		ret = tmp;
		break;

	}

	return ret;
}
inline void _main() {
	RDB(n, p, q);
	REP(i, n) RDB(a[i], b[i]);

	cout << fixed << setprecision(10);
	

	

	cout << solve5() << endl;


}





void generate_test_case() {
#ifdef _LOCAL_JUDGE
	srand(time(0));
	uniform_int_distribution<ll> u(-ll(1e9), ll(1e9));
	default_random_engine e(time(0));
	auto random = [&]() { return u(e); };
	ll n = 1000;
	ll m = 1000;
	WR(n, m);
	DO(n) WR(random(), random());
	DO(m) WR(random());
#endif
	exit(0);
}
int main() {
	#ifdef _LOCAL_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
		freopen("err.txt", "w", stderr);
	#endif
	#if 01
		_main();
	#else
		generate_test_case();
	#endif
	#ifdef _LOCAL_JUDGE
		OUT("Time elapsed:", run_time(), "s.");
		OUT(my_time());
		#if 1
			FILE *fp = fopen(FILE_NAME, "r+");
			fprintf(fp, "//Latest run time : %s\n", my_time());
			fclose(fp);
		#endif
	#endif
	return 0;
}
#endif
