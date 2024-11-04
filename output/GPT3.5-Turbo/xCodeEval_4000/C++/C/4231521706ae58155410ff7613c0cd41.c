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
#define DBN1(a)           printf(#a "=%d\n", (a))
#define DBN2(a,b)         printf(#a "=%d, " #b "=%d\n", (a), (b))
#define DBN3(a,b,c)       printf(#a "=%d, " #b "=%d, " #c "=%d\n", (a), (b), (c))
#define DBN4(a,b,c,d)     printf(#a "=%d, " #b "=%d, " #c "=%d, " #d "=%d\n", (a), (b), (c), (d))
#define DBN5(a,b,c,d,e)   printf(#a "=%d, " #b "=%d, " #c "=%d, " #d "=%d, " #e "=%d\n", (a), (b), (c), (d), (e))
#define DBN6(a,b,c,d,e,f) printf(#a "=%d, " #b "=%d, " #c "=%d, " #d "=%d, " #e "=%d, " #f "=%d\n", (a), (b), (c), (d), (e), (f))
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) printf(#a "=["); printarray(a,n); printf("]\n")
#define DAR(a,n,s) printf(#a "[%d-%d]=[", s, n-1); printarray(a,n,s); printf("]\n")

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef struct { int a; int b; int c; } triple;
typedef struct { ll a; ll b; ll c; } trll;
typedef struct { int first; int second; } pii;
typedef struct { ll first; ll second; } pll;
typedef struct { int first; int second; int third; } triple_int;

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

#define COMPARE(obj) (const void* a, const void* b)
#define COMPARE_BY(obj, field) (const void* a, const void* b) { return ((obj*)a)->field - ((obj*)b)->field; }

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

#define TT1T2T3 inline void printarray(T1 a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) printf("%d ", a[i]); printf("\n"); }

TT1T2T3 inline void printarray(T1 a, T2 sz, T2 beg) {
    for (T2 i = beg; i < sz; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

TT1T2T3 inline void printarray(T1 a, T2 sz) {
    printarray(a, sz, 0);
}

int powlog2(int v) {
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    ++v;
    return v / 2;
}

void add(int* x, int y) {
    *x += y;
    if (*x >= mod) *x -= mod;
}

int solve2(int x, int y, int k, int bonus) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if ((x & (x - 1)) == 0 && (y & (y - 1)) == 0) {
        k = k < x ? k : x;
        return k * (ll)y % mod * (k + 1 + bonus * 2LL) % mod;
    }
    int ty = powlog2(y);
    int tx = powlog2(x);
    int res;
    int txk = tx < k ? tx : k;
    if (tx == ty) {
        res = txk * (ll)ty % mod * (txk + 1 + bonus * 2LL) % mod;
        add(&res, solve2(x - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(y - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(x - tx, y - tx, k, bonus));
    } else {
        res = txk * (ll)y % mod * (txk + 1 + bonus * 2LL) % mod;
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
        int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        printf("%d\n", ans * powmod(2LL, mod - 2, mod) % mod);
    }
    return 0;
}
