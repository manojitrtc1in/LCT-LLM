#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define ALIGN(x) __attribute__((aligned(x)))

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)           printf(#a "=%lld\n",(long long)(a))
#define DBN2(a,b)         printf(#a "=%lld, " #b "=%lld\n",(long long)(a),(long long)(b))
#define DBN3(a,b,c)       printf(#a "=%lld, " #b "=%lld, " #c "=%lld\n",(long long)(a),(long long)(b),(long long)(c))
#define DBN4(a,b,c,d)     printf(#a "=%lld, " #b "=%lld, " #c "=%lld, " #d "=%lld\n",(long long)(a),(long long)(b),(long long)(c),(long long)(d))
#define DBN5(a,b,c,d,e)   printf(#a "=%lld, " #b "=%lld, " #c "=%lld, " #d "=%lld, " #e "=%lld\n",(long long)(a),(long long)(b),(long long)(c),(long long)(d),(long long)(e))
#define DBN6(a,b,c,d,e,f) printf(#a "=%lld, " #b "=%lld, " #c "=%lld, " #d "=%lld, " #e "=%lld, " #f "=%lld\n",(long long)(a),(long long)(b),(long long)(c),(long long)(d),(long long)(e),(long long)(f))
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) printf(#a "=["); printarray(a,n); printf("]\n")
#define DAR(a,n,s) printf(#a "[%lld-%lld]=[" ,(long long)(s),(long long)(n-1)); printarray(a,n,s); printf("]\n")

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef int itn;

template<class T1, class T2, class T3>
struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
template<class T1, class T2, class T3>
bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
template<class T1, class T2, class T3>
bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>

#define FI(n) for(int i=0;i<n;++i)
#define FJ(n) for(int j=0;j<n;++j)
#define FK(n) for(int k=0;k<n;++k)
#define FL(n) for(int l=0;l<n;++l)
#define FQ(n) for(int q=0;q<n;++q)
#define FOR(i,a,b) for(int i = (a), __e = (int) (b); i < __e; ++i)
#define all(a) a
#define reunique(v) v

#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define pow(x, n) pow(1.0 * (x), n)

#define COMPARE(obj) [&](const std::decay<decltype(obj)>::type& a, const std::decay<decltype(obj)>::type& b)
#define COMPARE_BY(obj, field) [&](const std::decay<decltype(obj)>::type& a, const std::decay<decltype(obj)>::type& b) { return a.field < b.field; }

#define checkbit(n, b) (((n) >> (b)) & 1)
#define setbit(n, b) ((n) | (static_cast<decltype(n)>(1) << (b)))
#define removebit(n, b) (~setbit(~(n), (b)))
inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T>
inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
unsigned long long rdtsc() {
    unsigned long long ret;
    __asm__ __volatile__("rdtsc" : "=A" (ret) : :);
    return ret;
}

#define TT1 template<class T>
#define TT1T2 template<class T1, class T2>
#define TT1T2T3 template<class T1, class T2, class T3>
TT1T2 void printpair(const std::pair<T1, T2>& p);
TT1 void printvector(const std::vector<T>& v);
TT1T2 void printset(const std::set<T1, T2>&v);
TT1T2 void printmultiset(const std::multiset<T1, T2>&v);
TT1T2 void printpriority_queue(std::priority_queue<T1, T2> v);
TT1T2T3 void printmap(const std::map<T1, T2, T3>& v);
TT1T2T3 void printmultimap(const std::multimap<T1, T2, T3>& v);
TT1T2T3 void printtriple(const triple<T1, T2, T3>& t);
TT1T2 void printpair(const std::pair<T1, T2>& p){ printf("(%lld, %lld)",(long long)(p.first),(long long)(p.second)); }
TT1 void printvector(const std::vector<T>& v){ bool f=1;printf("[");for(auto& i : v) { if (!f)printf(", ");printpair(i);f=0;}printf("]"); }
TT1T2 void printset(const std::set<T1, T2>&v){ bool f=1;printf("[");for(auto& i : v) { if (!f)printf(", ");printpair(i);f=0;}printf("]"); }
TT1T2 void printmultiset(const std::multiset<T1,T2>&v){bool f=1;printf("[");for(auto& i : v) { if (!f)printf(", ");printpair(i);f=0;}printf("]"); }
TT1T2T3 void printmap(const std::map<T1,T2,T3>& v){ bool f = 1; printf("["); for (auto& ii : v) { if (!f)printf(", "); printf("(%lld -> %lld) ",(long long)(ii.first),(long long)(ii.second)); f = 0; }printf("]"); }
TT1T2T3 void printmultimap(const std::multimap<T1, T2>& v){ bool f = 1; printf("["); for (auto& ii : v) { if (!f)printf(", "); printf("(%lld -> %lld) ",(long long)(ii.first),(long long)(ii.second)); f = 0; }printf("]"); }
TT1T2 void printpriority_queue(std::priority_queue<T1, T2> v) { bool f = 1; printf("["); while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) printf(", "); f = 0; printpair(x); } printf("]"); }
TT1T2T3 void printtriple(const triple<T1, T2, T3>& t){ printf("(%lld, %lld, %lld)",(long long)(t.a),(long long)(t.b),(long long)(t.c)); }
TT1T2 void printarray(T1 a, T2 sz, T2 beg) { for (T2 i = beg; i<sz; i++) printf("%lld ",(long long)(a[i])); printf("\n"); }

TT1T2T3 inline void readtriple(triple<T1, T2, T3>& t);
TT1T2 inline void readpair(std::pair<T1, T2>& p) { scanf("%lld %lld",(long long*)(&(p.first)),(long long*)(&(p.second))); }
TT1 inline void readvector(std::vector<T>& v) {
    if (v.size()) for (T& t : v) scanf("%lld",(long long*)(&t)); else {
        char s[1000000]; T obj; while (1) { fgets(s, sizeof(s), stdin); if (!feof(stdin)) break; }
        char* cur = s; while (*cur != '\n' && *cur != '\0') {
            if (!isspace(*cur)) {
                sscanf(cur, "%lld",(long long*)(&obj)); v.push_back(obj); while (!isspace(*cur) && *cur != '\0') cur++;
            } else cur++;
        }
    }
}
TT1T2T3 inline void readtriple(triple<T1, T2, T3>& t) { scanf("%lld %lld %lld",(long long*)(&(t.a)),(long long*)(&(t.b)),(long long*)(&(t.c))); }

#define PT1T2 pair<T1, T2>
TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }

#undef TT1
#undef TT1T2
#undef TT1T2T3

#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlajrewqwe
#define rank        wahayawehasdakw

void add(ll* x, ll y) {
    *x += y;
    if (*x >= mod) *x -= mod;
}
void sub(ll* x, ll y) {
    *x -= y;
    if (*x < 0) *x += mod;
}
ll solve2(ll x, ll y, ll k, ll bonus) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        ll temp = x;
        x = y;
        y = temp;
    }
    ll ty = 1;
    while (ty * 2 <= y) {
        ty *= 2;
    }
    ll tx = 1;
    while (tx * 2 <= x) {
        tx *= 2;
    }
    ll res;
    ll txk = tx < k ? tx : k;
    if (tx == ty) {
        res = txk * (txk + 1) % mod * ty + bonus * txk * 2 % mod * ty;
        res %= mod;
        add(&res, solve2(x - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(y - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(x - tx, y - tx, k, bonus));
    } else {
        res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y;
        res %= mod;
        add(&res, solve2(x - tx, y, k - tx, bonus + tx));
    }
    return res;
}
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        ll ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        printf("%lld\n", ans * powmod(2LL, mod - 2, mod) % mod);
    }
    return 0;
}
