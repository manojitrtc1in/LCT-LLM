#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FILE_NAME "model.c"
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

#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

template<typename T> inline bool RD(T* v) {
    char c;
    bool n;
    while (c = getchar(), c != '-' && (c < '0' || c > '9'))
        if (c == EOF)
            return false;
    if (c == '-') {
        n = true;
        *v = 0;
    }
    else {
        n = false;
        *v = c - '0';
    }
    while (c = getchar(), c >= '0' && c <= '9')
        *v = (*v << 3) + (*v << 1) + c - '0';
    if (n)
        *v *= -1;
    return true;
}

template<typename T> inline bool RD(T& a, T& b) { return RD(&a) && RD(&b); }
template<typename T> inline bool RD(T& a, T& b, T& c) { return RD(&a) && RD(&b) && RD(&c); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d) { return RD(&a) && RD(&b) && RD(&c) && RD(&d); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e) { return RD(&a) && RD(&b) && RD(&c) && RD(&d) && RD(&e); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f) { return RD(&a) && RD(&b) && RD(&c) && RD(&d) && RD(&e) && RD(&f); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g) { return RD(&a) && RD(&b) && RD(&c) && RD(&d) && RD(&e) && RD(&f) && RD(&g); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h) { return RD(&a) && RD(&b) && RD(&c) && RD(&d) && RD(&e) && RD(&f) && RD(&g) && RD(&h); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i) { return RD(&a) && RD(&b) && RD(&c) && RD(&d) && RD(&e) && RD(&f) && RD(&g) && RD(&h) && RD(&i); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i, T& j) { return RD(&a) && RD(&b) && RD(&c) && RD(&d) && RD(&e) && RD(&f) && RD(&g) && RD(&h) && RD(&i) && RD(&j); }

inline int RD() { int v; RD(&v); return v; }

static char _BUF_[1 << 15], *_HEAD_ = _BUF_, *_TAIL_ = _BUF_;
inline static char getchar_buffered() { return _HEAD_ == _TAIL_ && (_TAIL_ = (_HEAD_ = _BUF_) + fread(_BUF_, 1, 1 << 15, stdin), _HEAD_ == _TAIL_) ? EOF : *_HEAD_++; }
template<typename T> inline bool RDB(T* v) {
    char c;
    bool n;
    while (c = getchar_buffered(), c != '-' && (c < '0' || c > '9'))
        if (c == EOF)
            return false;
    if (c == '-') {
        n = true;
        *v = 0;
    }
    else {
        n = false;
        *v = c - '0';
    }
    while (c = getchar_buffered() - '0', c >= 0 && c <= 9)
        *v = (*v << 3) + (*v << 1) + c;
    if (n)
        *v *= -1;
    return true;
}

template<typename T> inline bool RDB(T& a, T& b) { return RDB(&a) && RDB(&b); }
template<typename T> inline bool RDB(T& a, T& b, T& c) { return RDB(&a) && RDB(&b) && RDB(&c); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d) { return RDB(&a) && RDB(&b) && RDB(&c) && RDB(&d); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e) { return RDB(&a) && RDB(&b) && RDB(&c) && RDB(&d) && RDB(&e); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f) { return RDB(&a) && RDB(&b) && RDB(&c) && RDB(&d) && RDB(&e) && RDB(&f); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g) { return RDB(&a) && RDB(&b) && RDB(&c) && RDB(&d) && RDB(&e) && RDB(&f) && RDB(&g); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h) { return RDB(&a) && RDB(&b) && RDB(&c) && RDB(&d) && RDB(&e) && RDB(&f) && RDB(&g) && RDB(&h); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i) { return RDB(&a) && RDB(&b) && RDB(&c) && RDB(&d) && RDB(&e) && RDB(&f) && RDB(&g) && RDB(&h) && RDB(&i); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i, T& j) { return RDB(&a) && RDB(&b) && RDB(&c) && RDB(&d) && RDB(&e) && RDB(&f) && RDB(&g) && RDB(&h) && RDB(&i) && RDB(&j); }

inline int RDB() { int v; RDB(&v); return v; }

template<typename T> inline void _WR(T a) {
    if (a < 0) {
        putchar('-');
        a *= -1;
    }
    T t = a / 10;
    if (t)
        _WR(t);
    putchar(a - (t << 1) - (t << 3) + '0');
}
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
