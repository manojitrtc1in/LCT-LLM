



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
#define DO(n)                 for (int _iDO_ = int(n); _iDO_--;)
#define rush()                int _CASES_; scanf("%d", &_CASES_); for (; _CASES_--;)
#define cases()               int _CASES_; scanf("%d", &_CASES_); for (int iCase = 1; (iCase <= _CASES_ && printf("Case #%d:\n", iCase)); ++iCase)
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
#define IOSS0                 std::ios::sync_with_stdio(false);cin.tie(false);
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
inline long long cpow(long long& x, long long k, const long long mod = 1000000007) { x %= mod; long long ret = 1; while (k > 0) { if (k & 1) ret = ret * x % mod; x = x * x % mod; k >>= 1; } return x = ret; }


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


inline int _1(int i) { assert(i < 32); return 1 << i; }
inline int _7(int i) { assert(i < 32); return (1 << i) - 1; }
inline long long _1L(int i) { assert(i < 64); return 1LL << i; }
inline long long _7L(int i) { assert(i < 64); return (1LL << i) - 1; }



template<typename T> inline int i_1(T x) {
	assert((x & x - 1) == 0);
	int ret = 0;
	for (int i = sizeof(T) << 2; i; i >>= 1) if (x >> i) { ret += i; x >>= i; }
	return ret;
}

template<typename T> inline T lowbit(T x) { return x & -x; }
template<typename T> inline bool testbit(T x, int i) { return (bool)(x & (T(1) << i)); }
template<typename T> inline bool setbit(T& x, int i) { return (x & (T(1) << i)) ? false : (x |= (T(1) << i), true); }
template<typename T> inline bool resetbit(T& x, int i) { return (x & (T(1) << i)) ? (x &= ~(T(1) << i), true) : false; }

template<typename T>
inline int cntbit(T x) {
	int len = sizeof(T) << 3;
	x = ((x & 0xaaaaaaaaaaaaaaaa) >> 1) + (x & 0x5555555555555555);
	x = ((x & 0xcccccccccccccccc) >> 2) + (x & 0x3333333333333333);
	x = ((x & 0xf0f0f0f0f0f0f0f0) >> 4) + (x & 0x0f0f0f0f0f0f0f0f);
	if (len >= 16) x = ((x & 0xff00ff00ff00ff00) >> 8) + (x & 0x00ff00ff00ff00ff);
	if (len >= 32) x = ((x & 0xffff0000ffff0000) >> 16) + (x & 0x0000ffff0000ffff);
	if (len >= 64) x = ((x & 0xffffffff00000000) >> 32) + (x & 0x00000000ffffffff);
	return x;
}

template<typename T>
inline T reversebit(T x) {
	int len = sizeof(T) << 3;
	x = ((x & 0xaaaaaaaaaaaaaaaa) >> 1) | ((x & 0x5555555555555555) << 1);
	x = ((x & 0xcccccccccccccccc) >> 2) | ((x & 0x3333333333333333) << 2);
	x = ((x & 0xf0f0f0f0f0f0f0f0) >> 4) | ((x & 0x0f0f0f0f0f0f0f0f) << 4);
	if (len >= 16) x = ((x & 0xff00ff00ff00ff00) >> 8) | ((x & 0x00ff00ff00ff00ff) << 8);
	if (len >= 32) x = ((x & 0xffff0000ffff0000) >> 16) | ((x & 0x0000ffff0000ffff) << 16);
	if (len >= 64) x = ((x & 0xffffffff00000000) >> 32) | ((x & 0x00000000ffffffff) << 32);
	return x;
}




inline int cntbit(int x) {
	x = ((x & 0xaaaaaaaa) >> 1) + (x & 0x55555555);
	x = ((x & 0xcccccccc) >> 2) + (x & 0x33333333);
	x = ((x & 0xf0f0f0f0) >> 4) + (x & 0x0f0f0f0f);
	x = ((x & 0xff00ff00) >> 8) + (x & 0x00ff00ff);
	x = ((x & 0xffff0000) >> 16) + (x & 0x0000ffff);
	return x;
}
inline int cntbit(long long x) {
	x = ((x & 0xaaaaaaaaaaaaaaaa) >> 1) + (x & 0x5555555555555555);
	x = ((x & 0xcccccccccccccccc) >> 2) + (x & 0x3333333333333333);
	x = ((x & 0xf0f0f0f0f0f0f0f0) >> 4) + (x & 0x0f0f0f0f0f0f0f0f);
	x = ((x & 0xff00ff00ff00ff00) >> 8) + (x & 0x00ff00ff00ff00ff);
	x = ((x & 0xffff0000ffff0000) >> 16) + (x & 0x0000ffff0000ffff);
	x = ((x & 0xffffffff00000000) >> 32) + (x & 0x00000000ffffffff);
	return int(x);
}
inline int reversebit(int x) {
	x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
	x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
	x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
	x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
	x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
	return x;
}
inline long long reversebit(long long x) {
	x = ((x & 0xaaaaaaaaaaaaaaaa) >> 1) | ((x & 0x5555555555555555) << 1);
	x = ((x & 0xcccccccccccccccc) >> 2) | ((x & 0x3333333333333333) << 2);
	x = ((x & 0xf0f0f0f0f0f0f0f0) >> 4) | ((x & 0x0f0f0f0f0f0f0f0f) << 4);
	x = ((x & 0xff00ff00ff00ff00) >> 8) | ((x & 0x00ff00ff00ff00ff) << 8);
	x = ((x & 0xffff0000ffff0000) >> 16) | ((x & 0x0000ffff0000ffff) << 16);
	x = ((x & 0xffffffff00000000) >> 32) | ((x & 0x00000000ffffffff) << 32);
	return x;
}


template<typename T>
inline T gcd(T a, T b) {
	while (b != 0) {
		T tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
#ifdef __cpp11
template<typename T, typename ...Args>
inline T gcd(T a, T b, Args... rest) {
	return gcd(gcd(a, b), rest...);
}
#endif



template<typename T>
inline T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}
#ifdef __cpp11
template<typename T, typename ...Args>
inline T lcm(T a, T b, Args... rest) {
	return lcm(lcm(a, b), rest...);
}
#endif
#endif


inline ll minv(ll x, const ll mod = 1000000007) { return mpow(x, mod - 2, mod); }



const int _  = (int)(1e3 + 10);
const int __ = (int)(1e6 + 10);
const int LOG = 18;

int n, k;
struct Point {
	int x, y;
	void read() { RDB(x, y); }
};
Point stones[7];
Point monsters[_];
bool vis[_];

VPLL* shoot[7][_];
int shoot_order[7][_];

map<PII, VPLL> lines[7];

bool dfs(VI mids, int used, int rest) {
	if (mids.empty()) return true;
	if (mids.size() > rest) return false;

	for (int mid : mids) {
		vis[mid] = true;
		REP(i, k) if (!testbit(used, i)) {
			int order = shoot_order[i][mid];
			SI s(all(mids));
			s.erase(mid);
			REP(j, order) {
				int t = (*shoot[i][mid])[j].second;
				if (vis[t]) continue;
				s.insert(t);
			}
			if (dfs(VI(all(s)), used | _1(i), rest - 1)) return true;
		}
		vis[mid] = false;
	}
	return false;
}

bool is_first_shoot[_];
inline void _main() {
	RDB(k, n);
	REP(i, k) stones[i].read();
	REP(i, n) monsters[i].read();
	REP(i, k) {
		REP(j, n) {
			int dx = monsters[j].x - stones[i].x;
			int dy = monsters[j].y - stones[i].y;
			ll d = 1LL * dx * dx + 1LL * dy * dy;

			int g = gcd(abs(dx), abs(dy));
			dx /= g, dy /= g;

			lines[i][mp(dx, dy)].pb(mp(d, j));
		}
		

		for (auto &x : lines[i]) {
			VPLL& shoot_sequence = x.second;
			sortall(shoot_sequence);
			is_first_shoot[shoot_sequence[0].second] = true;
			FOR (j, 0, sz(shoot_sequence)) {
				int m = shoot_sequence[j].second;
				shoot[i][m] = &shoot_sequence;
				shoot_order[i][m] = j;
			}
		}
	}
	
	


	int ret = 0;
	REP(i, n) {
		if (is_first_shoot[i]) {
			++ret;
			continue;
		}
		ms(vis, 0);
		if (dfs(VI{ int(i) }, 0, k)) ++ret;
	}
	WR(ret);
}




void generate_test_case() {
#ifdef _LOCAL_JUDGE
	srand(time(0));
	uniform_int_distribution<int> u(-100, 120);
	default_random_engine e(time(0));
	auto random = [&]() { return u(e); };
	

	int k = 7;
	int n = 1000;
	

	set<PII> s;
	WR(k, n);
	int cnt = 0;
	int x, y;
	while (1) {
		x = random(); y = random();
		if (s.count(mp(x, y))) continue;
		WR(x, y);
		s.insert(mp(x, y));
		if (++cnt >= k) break;
	}
	cnt = 0;
	while (1) {
		x = random(); y = random();
		if (s.count(mp(x, y))) continue;
		WR(x, y);
		s.insert(mp(x, y));
		if (++cnt >= n) break;
	}
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
