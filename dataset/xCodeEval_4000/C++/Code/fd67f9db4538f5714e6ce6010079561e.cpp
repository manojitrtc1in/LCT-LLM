#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")


#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")



#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>

#ifdef LOCAL
# include <opencv2/core/core.hpp>
# include <opencv2/highgui/highgui.hpp>
# include <opencv2/imgproc/imgproc.hpp>
#endif

using namespace std;



# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cerr<<#a<<"=["; printarray(a,n); cerr<<"]\n"
#define DAR(a,n,s) cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cerr<<"]\n"

#ifdef _MSC_VER
#define PREFETCH(ptr, rw, level) ((void)0)
#else
#define PREFETCH(ptr, rw, level) __builtin_prefetch(ptr, rw, level)
#endif

#ifdef LOCAL
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
#else
#define CURTIME()
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef int itn;

template<class T1, class T2, class T3>
struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
template<class T1, class T2, class T3>
bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
template<class T1, class T2, class T3>
bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>

#define FI(n) for(int i=0;i<(n);++i)
#define FJ(n) for(int j=0;j<(n);++j)
#define FK(n) for(int k=0;k<(n);++k)
#define FL(n) for(int l=0;l<(n);++l)
#define FQ(n) for(int q=0;q<(n);++q)
#define FOR(i,a,b) for(int i = (a), __e = (int) (b); i < __e; ++i)
#define all(a) std::begin(a), std::end(a)
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define pow(x, n) pow(1.0 * (x), n)

#define COMPARE(obj) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b)
#define COMPARE_BY(obj, field) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b) { return a.field < b.field; }

#define checkbit(n, b) (((n) >> (b)) & 1)
#define setbit(n, b) ((n) | (static_cast<std::decay<decltype(n)>::type>(1) << (b)))
#define removebit(n, b) ((n) & ~(static_cast<std::decay<decltype(n)>::type>(1) << (b)))
#define flipbit(n, b) ((n) ^ (static_cast<std::decay<decltype(n)>::type>(1) << (b)))
inline int countBits(uint v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int countBits(ull v){uint t=v>>32;uint p=(v & ((1ULL << 32) - 1)); return countBits(t) + countBits(p); }
inline int countBits(ll v){return countBits((ull)v); }
inline int countBits(int v){return countBits((uint)v); }
unsigned int reverseBits(uint x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T> inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
constexpr ll power(ll x, int p) { return p == 0 ? 1 : (x * power(x, p - 1)); }


unsigned long long rdtsc() { unsigned long long ret = 0;
#ifdef __clang__
    return __builtin_readcyclecounter();
#endif
#ifndef _MSC_VER
    asm volatile("rdtsc" : "=A" (ret) : :);
#endif
    return ret; }


const int __BS = 4096;
static char __bur[__BS + 16], *__er = __bur + __BS, *__ir = __er;
template<class T = int> T readInt() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    c(); while (*__ir && (*__ir < '0' || *__ir > '9') && *__ir != '-') ++__ir; c();
    bool m = false; if (*__ir == '-') ++__ir, c(), m = true;
    T r = 0; while (*__ir >= '0' && *__ir <= '9') r = r * 10 + *__ir - '0', ++__ir, c();
    ++__ir; return m ? -r : r;
}
static char __buw[__BS + 20], *__iw = __buw, *__ew = __buw + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw;
    if (endc) { *__iw++ = endc; }
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw; }
}
struct __FL__ { ~__FL__() { if (__iw != __buw) cout.write(__buw, __iw - __buw); } };
static __FL__ __flushVar__;



#define TT1 template<class T>
#define TT1T2 template<class T1, class T2>
#define TT1T2T3 template<class T1, class T2, class T3>
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p);
TT1 ostream& operator << (ostream& os, const vector<T>& v);
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, const multiset<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v);
TT1T2T3 ostream& operator << (ostream& os, const map<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const multimap<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v);
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v) {     bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v){    bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multiset<T1,T2>&v){bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const map<T1,T2,T3>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool f = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) os << ", "; f = 0; os << x; } return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
TT1T2 void printarray(const T1& a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }



TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t);
TT1T2 inline istream& operator >> (istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
TT1 inline istream& operator >> (istream& os, vector<T>& v) {
    if (v.size()) for (T& t : v) os >> t; else {
        string s; T obj; while (s.empty()) {getline(os, s); if (!os) return os;}
        stringstream ss(s); while (ss >> obj) v.push_back(obj);
    }
    return os;
}
TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }



#define PT1T2 pair<T1, T2>
TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2& operator+=(PT1T2 &p1 , const PT1T2 &p2) { p1.first += p2.first, p1.second += p2.second; return p1; }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }
TT1T2 inline PT1T2& operator-=(PT1T2 &p1 , const PT1T2 &p2) { p1.first -= p2.first, p1.second -= p2.second; return p1; }

#undef TT1
#undef TT1T2
#undef TT1T2T3

#define FREIN(FILE) freopen(FILE, "rt", stdin)
#define FREOUT(FILE) freopen(FILE, "wt", stdout)
#ifdef LOCAL
#define BEGIN_PROFILE(idx, name) int profileIdx = idx; profileName[profileIdx] = name; totalTime[profileIdx] -= rdtsc() / 1e3;
#define END_PROFILE totalTime[profileIdx] += rdtsc() / 1e3; totalCount[profileIdx]++;
#else
#define BEGIN_PROFILE(idx, name)
#define END_PROFILE
#endif

const int USUAL_MOD = 1000000007;
template<class T> inline void normmod(T &x, T m = USUAL_MOD) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 summodfast(T1 x, T1 y, T2 m = USUAL_MOD) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3 = int> inline void addmodfast(T1 &x, T2 y, T3 m = USUAL_MOD) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3 = int> inline void submodfast(T1 &x, T2 y, T3 m = USUAL_MOD) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ x %= m; n %= m; ll r = x * n - ll(ld(x)*ld(n) / ld(m)) * m; while (r < 0) r += m; while (r >= m) r -= m; return r; }
inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1) r *= x; x *= x; r %= m; x %= m; n /= 2; }return r; }
inline ll powmulmod(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> inline T gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<class T>
T fast_gcd(T u, T v) {
    int shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}

inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
ll gcdex(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = gcdex(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
bool millerRabin(long long n) {
    if (n <= 1000) return isPrime(n);
    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (!(a %= n)) return true;
        long long f = powmulmod(a, s, n); if (f == 1 || f == n - 1) continue;
        for (int i = 1; i < t; ++i) if ((f = mulmod(f, f, n)) == n - 1) goto nextp;
        return false; nextp:;
    } return true;
}






#define T9          1000000000
#define T18         1000000000000000000LL
#define INF         1011111111
#define LLINF       1000111000111000111LL
#define mod         1000000007
#define fftmod      998244353
#define EPS         (double)1e-10
#define PI          3.14159265358979323846264
#define link        asaxlajrewqwe
#define rank        wahayawehasdakw



#define sz(a) (int(a.size()))
struct cd {
    double x, y;
    cd operator*(const cd& other) {
        return {x * other.x - y * other.y, x * other.y + y * other.x};
    }
    cd operator+(const cd& other) {
        return {x + other.x, y + other.y};
    }
    cd operator-(const cd& other) {
        return {x - other.x, y - other.y};
    }
    double real() { return x; }
    double imag() { return y; }
};
inline cd conj(const cd& x) {
    return {x.x, -x.y};
}
cd polar(double x, double y) {
    auto p = std::polar(x, y);
    return {p.real(), p.imag()};
}

constexpr int T = 5;
constexpr int RADIX = power(10, T);
const int N = 1 << 19;

const double LOG_RADIX = log(RADIX);
const double LOG_3 = log(3.0);

istream& operator >> (istream& in, vi& r) {
    string s;
    in >> s;
    reverse(all(s));
    while (s.size() % T) s += '0';
    r.resize(s.size() / T);
    FI(r.size()) FJ(T) r[i] = r[i] * 10 + s[i * T + T - 1 - j] - '0';
    return in;
}

cd W[N];






































































template <bool Inv>
void fft(cd* p, int n) {
    n /= 2;
    for (int i = 0, j = n; i < n; ++i, ++j) {
        cd x = p[i], y = p[j];
        p[i] = (x + y);
        p[j] = (x - y) * (Inv ? W[j] : conj(W[j]));
    }
    if (n > 1) {
        fft<Inv>(p, n);
        fft<Inv>(p + n, n);
    }
}
template <bool Inv, int n2>
void fft(cd* p) {
    constexpr int n = n2 / 2;
    for (int i = 0, j = n; i < n; ++i, ++j) {
        cd x = p[i], y = p[j];
        p[i] = (x + y);
        p[j] = (x - y) * (Inv ? W[j] : conj(W[j]));
    }
    if (n > 1) {
        fft<Inv, n>(p);
        fft<Inv, n>(p + n);
    }
}

template <int n, class X>
void bitrev(X* a) {
    for (int i = 0, j = 0, k; i < n; ++i) {
        if (i < j) swap(a[i], a[j]);
        for (k = n; j & (k /= 2); );
        j += 3 * k - n;
    }
}

cd af[N + N];
template<int n>
int Sqr(int* a, int as) {
    FI(as) af[i] = {(double)a[i], 0.0};
    memset(af + as, 0, (n - as) * sizeof(cd));
    fft<0>(af, n);
    bitrev<n>(af);
    FI(n) af[i] = af[i] * af[i];
    fft<1>(af, n);
    bitrev<n>(af);
    constexpr double invN = 1.0 / n;
    as = n;
    ll carry = 0;
    FI(n) {
        carry += (ll)(af[i].real() * invN + 0.5);
        a[i] = carry % RADIX;
        carry /= RADIX;
    }
    if (carry) a[as++] = (int)carry;
    while (as != 0 && a[as - 1] == 0) --as;
    return as;
}

template<int b>
int mul(int* a, int as) {
    int carry = 0;
    for (int i = 0; i < as; ++i) {
        auto& x = a[i];
        carry += x * b;
        x = carry % RADIX;
        carry /= RADIX;
    }
    if (carry) a[as++] = carry;
    return as;
}

template<int b>
void div(vi& a) {
    int x = 0;
    for (int i = (int)a.size(); i --> 0; ) {
        x = x * RADIX + a[i];
        a[i] = x / b;
        x %= b;
    }
    if (x) ++a[0];
    while ((int)a.size() && a.back() == 0) a.pop_back();
}

int cmp(int* a, int as, const vi& b) {
    if (as != sz(b)) return as - sz(b);
    for (int i = as; i --> 0; )
        if (a[i] != b[i])
            return a[i] - b[i];
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE


#endif
    

    FI(N / 2) W[i + N / 2] = polar(1.0, (2 * PI / N) * i);
    for (int i = N / 2; i --> 0; W[i] = W[2 * i]);
    vi a;
    cin >> a;
    int n = sz(a);
    if (n == 1 && a[0] < 4) {
        cout << a[0] << endl;
        return 0;
    }
    int res = -1u/2;
    for (int i = 0; i <= 2; ++i) {
        if (i) div<2>(a);
        double logA = n > 1 ? log(a[n - 1] * (double)RADIX + a[n - 2]) + LOG_RADIX * (n - 2) : log(a[n - 1]);
        logA = logA / LOG_3 - 1e-9;
        int powerOf3 = max(logA + 1, 0.0);
        double c = logA - int(logA);
        if (c < 0.999) {
            res = min(res, 3 * powerOf3 + i * 2);
            continue;
        }
        static int x[1 << 19] = {1};
        int xs = 1;
        for (int i = 26; i >= 0; --i) {
            int n = 2 * (int)xs - 1;
            for (; n & n - 1; n = (n | n - 1) + 1);
            n = max(n, 1 << 8);
            switch (n) {
#define CASE(z) case (z): xs = Sqr<z>(x, xs); break;
                    CASE(1 << 8);
                    CASE(1 << 9);
                    CASE(1 << 10);
                    CASE(1 << 11);
                    CASE(1 << 12);
                    CASE(1 << 13);
                    CASE(1 << 14);
                    CASE(1 << 15);
                    CASE(1 << 16);
                    CASE(1 << 17);
                    CASE(1 << 18);
                    CASE(1 << 19);
            }


            if (powerOf3 & 1 << i) xs = mul<3>(x, xs);
        }
        if (cmp(x, xs, a) < 0) ++powerOf3;
        res = min(res, 3 * powerOf3 + i * 2);
    }
    cout << res << endl;
    CURTIME();
    return 0;
}