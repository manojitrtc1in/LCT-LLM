#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

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

#define FOR(i, a, b)                 for (long long i = (long long)(a); i < (long long)(b); ++i)
#define ROF(i, a, b)                 for (long long i = (long long)(b) - 1; i >= (long long)(a); --i)
#define rep(i, a, b)                 for (long long i = (long long)(a); i < (long long)(b); ++i)
#define per(i, a, b)                 for (long long i = (long long)(b) - 1; i >= (long long)(a); --i)
#define REP(i, n)                    for (long long i = 0; i < (long long)(n); ++i)
#define PER(i, n)                    for (long long i = (long long)(n) - 1; i >= 0; --i)
#if                                  defined(__GNUC__) || defined(__GNUG__)
#define ECH(i, c)                    for (__typeof(c.begin()) i = c.begin(), e = c.end(); i != e; ++i)
#define HCE(i, c)                    for (__typeof(c.rbegin()) i = c.rbegin(), e = c.rend(); i != e; ++i)
#else
#define ECH(i, c)                    for (auto i = c.begin(), e = c.end(); i != e; ++i)
#define HCE(i, c)                    for (auto i = c.rbegin(), e = c.rend(); i != e; ++i)
#endif
#define DO(n)                        for (int _iDO_ = int(n); _iDO_--;)
#define rush()                       int _CASES_; scanf("%d\n", &_CASES_); for (int iCase = 1; iCase <= _CASES_; ++iCase)
#define cases()                      int _CASES_; scanf("%d\n", &_CASES_); for (int iCase = 1; (iCase <= _CASES_ && printf("Case #%d:\n", iCase)); ++iCase)
#define sqr(x)                       ((x) * (x))
#define cub(x)                       ((x) * (x) * (x))
#define all(x)                       (x).begin(), (x).end()
#define sortall(x)                   sort((x).begin(), (x).end())
#define reverseall(x)                reverse((x).begin(), (x).end())
#define sz(x)                        ((int)(x).size())
#define eb                           emplace_back
#define pb                           push_back
#define pf                           push_front
#define ppb                          pop_back
#define ppf                          pop_front
#define mp                           make_pair
#define pbmp(a, b)                   push_back(make_pair((a), (b)))
#define fi                           first
#define se                           second
#define ms(a, b)                     memset((a), (b), sizeof(a))
#define cp(a, b)                     memcpy((a), (b), sizeof(a))
#define IOSS0                        std::ios::sync_with_stdio(false);cin.tie(0);
#define whatis(x)                    cout << #x << " = " << x << endl;
#define uniqueit(v)                  (v).erase(unique((v).begin(), (v).end()), (v).end())
#define insertlb(v, a)               (v).insert(lower_bound((v).begin(), (v).end(), (a)), (a))
#define insertub(v, a)               (v).insert(upper_bound((v).begin(), (v).end(), (a)), (a))
#define PQ                           priority_queue
#define uset                         unordered_set
#define mset                         multiset
#define umap                         unordered_map
#define mmap                         multimap
typedef double                       db;
typedef long double                  ldb;
typedef unsigned char                uchar;
typedef unsigned short               ushort;
typedef unsigned int                 uint;
typedef long long                    ll;
typedef unsigned long long           ull;
typedef std::vector<bool>            VB;
typedef std::vector<VB>              VVB;
typedef std::vector<char>            VC;
typedef std::vector<VC>              VVC;
typedef std::vector<int>             VI;
typedef std::vector<VI>              VVI;
typedef std::vector<ll>              VLL;
typedef std::vector<VLL>             VVLL;
typedef std::vector<double>          VD;
typedef std::vector<VD>              VVD;
typedef std::vector<std::string>     VS;
typedef std::vector<VS>              VVS;
typedef std::pair<int, int>          PII;
typedef std::pair<ll, ll>            PLL;
typedef std::vector<PII>             VPII;
typedef std::vector<PLL>             VPLL;
typedef std::pair<int, PII>          PIPII;
typedef std::pair<ll, PLL>           PLPLL;
typedef std::pair<PII, int>          PPIII;
typedef std::pair<PLL, ll>           PPLLL;
typedef std::map<int, int>           MII;
typedef std::map<ll, ll>             MLL;
typedef std::map<db, db>             MDD;
typedef std::map<std::string, int>   MSI;
typedef std::map<int, std::string>   MIS;
typedef std::set<int>                SI;
typedef std::set<ll>                 SLL;
typedef std::queue<int>              QI;
typedef std::queue<ll>               QLL;
typedef std::queue<PII>              QPII;
typedef std::deque<int>              DI;
typedef std::deque<ll>               DLL;
typedef std::deque<PII>              DPII;
const double                         eps = 1e-9;
const double                         pi = 3.14159265358979323846264338327950288419716939937510;
const int                            inf = 0x3f3f3f3f;
const int                            mod = 1000000007;
const int                            mod2 = 1000000006;
const long long                      infll = 0x3f3f3f3f3f3f3f3fLL;
const int                            dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
const int                            dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };







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


inline char getchar_buffered() { static char _BUF_[1 << 15], *_HEAD_ = _BUF_, *_TAIL_ = _BUF_; return _HEAD_ == _TAIL_ && (_TAIL_ = (_HEAD_ = _BUF_) + fread(_BUF_, 1, 1 << 15, stdin), _HEAD_ == _TAIL_) ? EOF : *_HEAD_++; }
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
template<typename A, typename ...Args> inline void WR (const A& a, const Args&... rest) { WR_(a); WR(rest...); }
#else
template<typename T> inline void _WR(const T& a, const T& b) { WR_(a); _WR(b); }
template<typename T> inline void WR_(const T& a, const T& b) { WR_(a); WR_(b); }
template<typename T> inline void WR (const T& a, const T& b) { WR_(a); WR(b); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c) { WR_(a, b); _WR(c); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c) { WR_(a, b); WR_(c); }
template<typename T> inline void WR (const T& a, const T& b, const T& c) { WR_(a, b); WR(c); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); _WR(d); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); WR_(d); }
template<typename T> inline void WR (const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); WR(d); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); _WR(e); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); WR_(e); }
template<typename T> inline void WR (const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); WR(e); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); _WR(f); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); WR_(f); }
template<typename T> inline void WR (const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); WR(f); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); _WR(g); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); WR_(g); }
template<typename T> inline void WR (const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); WR(g); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); _WR(h); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); WR_(h); }
template<typename T> inline void WR (const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); WR(h); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); _WR(i); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); WR_(i); }
template<typename T> inline void WR (const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); WR(i); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); _WR(j); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); WR_(j); }
template<typename T> inline void WR (const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); WR(j); }
#endif
#define RDn(a, l, r)          { rep(_i_, l, r) RD((a)[_i_]); }
#define RDBn(a, l, r)         { rep(_i_, l, r) RDB((a)[_i_]); }
#define WRn(a, l, r)          { rep(_i_, l, r - 1) WR_((a)[_i_]); if(r > 0) WR((a)[r - 1]); }
#define RDnm(a, b, c, d, e)   { rep(__i__, b, c) RDn(a[__i__], d, e) }
#define RDBnm(a, b, c, d, e)  { rep(__i__, b, c) RDBn(a[__i__], d, e) }
#define WRnm(a, b, c, d, e)   { rep(__i__, b, c) WRn(a[__i__], d, e) }




template <typename A> inline std::istream &IN(A& a) { return std::cin >> a; }
#ifdef __cpp11
template <typename A, typename ...Args> inline std::istream& IN(A& a, Args&... rest) { std::cin >> a; return IN(rest...); }
#else
template <typename A, typename B> inline std::istream& IN(A& a, B& b) { return std::cin >> a >> b; }
template <typename A, typename B, typename C> inline std::istream& IN(A& a, B& b, C& c) { return std::cin >> a >> b >> c; }
template <typename A, typename B, typename C, typename D> inline std::istream& IN(A& a, B& b, C& c, D& d) { return std::cin >> a >> b >> c >> d; }
template <typename A, typename B, typename C, typename D, typename E> inline std::istream& IN(A& a, B& b, C& c, D& d, E& e) { return std::cin >> a >> b >> c >> d >> e; }
template <typename A, typename B, typename C, typename D, typename E, typename F> inline std::istream& IN(A& a, B& b, C& c, D& d, E& e, F& f) { return std::cin >> a >> b >> c >> d >> e >> f; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G> inline std::istream& IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g) { return std::cin >> a >> b >> c >> d >> e >> f >> g; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H> inline std::istream& IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I> inline std::istream& IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h, I& i) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J> inline std::istream& IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h, I& i, J& j) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j; }
#endif
inline std::ostream& OUT() { return std::cout << std::endl; }
#ifdef __cpp11
template <typename A> inline std::ostream& _OUT(const A &a) { return std::cout << a; }
template <typename A, typename...Args> inline std::ostream& _OUT(const A &a, const Args&... rest) { std::cout << a << " "; return _OUT(rest...); }
template <typename...Args> inline std::ostream& OUT_(const Args&... args) { _OUT(args...); return std::cout << " "; }
template <typename...Args> inline std::ostream& OUT(const Args&... args) { _OUT(args...); return std::cout << std::endl; }
#else
template<typename T> inline std::ostream& _OUT(const T&a) { return std::cout << a; }
template<typename T> inline std::ostream& OUT_(const T&a) { return std::cout << a << ' '; }
template<typename T> inline std::ostream& OUT(const T&a) { return std::cout << a << std::endl; }
template<typename T, typename U> inline std::ostream& _OUT(const T&a, const U&b) { return std::cout << a << " " << b; }
template<typename T, typename U> inline std::ostream& OUT_(const T&a, const U&b) { return std::cout << a << " " << b << " "; }
template<typename T, typename U> inline std::ostream& OUT(const T&a, const U&b) { return std::cout << a << " " << b << std::endl; }
template<typename T, typename U, typename V> inline std::ostream& _OUT(const T&a, const U&b, const V&c) { OUT_(a, b); return _OUT(c); }
template<typename T, typename U, typename V> inline std::ostream& OUT_(const T&a, const U&b, const V&c) { OUT_(a, b); return OUT_(c); }
template<typename T, typename U, typename V> inline std::ostream& OUT(const T&a, const U&b, const V&c) { OUT_(a, b); return OUT(c); }
template<typename T, typename U, typename V, typename W> inline std::ostream& _OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return _OUT(d); }
template<typename T, typename U, typename V, typename W> inline std::ostream& OUT_(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return OUT_(d); }
template<typename T, typename U, typename V, typename W> inline std::ostream& OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return OUT(d); }
template<typename T, typename U, typename V, typename W, typename X> inline std::ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return _OUT(e); }
template<typename T, typename U, typename V, typename W, typename X> inline std::ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return OUT_(e); }
template<typename T, typename U, typename V, typename W, typename X> inline std::ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return OUT(e); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline std::ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return _OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline std::ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return OUT_(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline std::ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline std::ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return _OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline std::ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return OUT_(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline std::ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline std::ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return _OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline std::ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return OUT_(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline std::ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline std::ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return _OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline std::ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return OUT_(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline std::ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline std::ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return _OUT(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline std::ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return OUT_(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline std::ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return OUT(j); }
#endif
#define INn(a, b, c)          { rep(_i_, b, c) IN(a[_i_]); }
#define INnm(a, b, c, d, e)   { rep(__i__, b, c) INn(a[__i__], d, e) }
#define OUTn(a, l, r)         { rep(_i_, l, r - 1) OUT_((a)[_i_]); if(r > 0) OUT((a)[r - 1]); }
#define OUTnm(a, b, c, d, e)  { rep(__i__, b, c) OUTn(a[__i__], d, e) }


const int _ = 100000 + 10;
int n, m;
vector<vector<int>> e;

int main() {
    scanf("%d %d", &n, &m);
    int cnt = 0;
    if (m < n - 1) goto output;
    e.resize(n + 1);
    e[1].push_back(0);
    FOR(i, 1, n + 1) {
        for (int j: e[i]) {
            FOR(k, 1, n + 1) {
                int t = j + i * k;
                if (t <= i) continue;
                if (t > n) break;
                e[t].push_back(i);
                ++cnt;
                if (cnt >= m) goto output;
            }
        }
    }
    output:;
    if (cnt < m) {
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    FOR(i, 2, n + 1) {
        for (int j: e[i]) {
            WR(int(i), j);
        }
    }

    return 0;
}