#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <cstdio>
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
# include <deque>
# include <functional>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <emmintrin.h>
using namespace std;



# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_map>
# else
# include <tr1/unordered_map>
using namespace std::tr1;
# endif
# else
# include <unordered_map>
# endif

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)			std::cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)	std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)	std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif


double __begin;
#define DTIME(ccc) __begin = clock(); ccc; std::cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<std::endl;

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(){};triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>
template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

#define FI(n) for(int i=0;i<n;i++)
#define FJ(n) for(int j=0;j<n;j++)
#define all(a) a.begin(), a.end()



inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));return((x >> 16) | (x << 16));}
inline int sign(int x){ return x > 0;}
inline bool isPowerOfTwo(int x){return (x!=0 && (x&(x-1))==0);}
#define checkbit(n,b) ( (n >> b) & 1)



template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";cout<<endl;}

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)

inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j=0;j<m;++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0;ii < n; ii++){ scanf("%I64d", a + ii); } }
template<class T>
inline void cinarr(T &a, int n){ for (int i=0;i<n;++i) cin >> a[i];}



#define INF			1011111111
#define LLINF       1000111000111000111LL
#define EPS			(double)1e-15
#define mod			1000000007
#define PI			3.14159265358979323



typedef unsigned char uchar;

int read_int()
{
    const int BUSFIZE = 4096;
    static char inbuf[BUSFIZE + 16];
    static char *inp = inbuf;
    static char *linp = inbuf + BUSFIZE;
    if (*inp == 0)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    while (*inp && (*inp < '0' || *inp > '9')) ++inp;
    int res = 0;
    while (*inp >= '0' && *inp <= '9')
    {
        res = res * 10 + *inp - '0';
        ++inp;
        if (inp == linp)
        {
            memset(inbuf, 0, BUSFIZE);
            cin.read(inbuf, BUSFIZE);
            inp = inbuf;
        }
    }
    ++inp;
    return res;
}


uchar pack(uchar a, uchar b) {
    return a | (b << 4);
}
const uchar secondMask = (15 << 4);
const uchar firstMask = 15;
void setFirst(uchar &c, uchar val) {
    c = (c & secondMask) | val;
}
void setSecond(uchar &c, uchar val) {
    c = (c & firstMask) | (val << 4);
}
int getChar(uchar *s, int pos) {
    if (pos & 1) {
        return (s[pos / 2] & secondMask) >> 4;
    } else {
        return s[pos / 2] & firstMask;
    }
}
void memsetSse(uchar *s, uchar c, int len) {
    typedef __m128i T;
    const T v = _mm_set_epi8(c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    T* ptr = (T*) s;
    len /= sizeof(T);
    while (len--) {
        _mm_store_si128(ptr, v);




        ++ptr;
    }
}
void draw(uchar *s, int l, int r, char c) {
    if (l < 0) l = 0;
    ++r;
    if (r & 1) {
        setFirst(s[r / 2], c);
        --r;
    }
    if (l & 1) {
        setSecond(s[l / 2], c);
        ++l;
    }
    s += l / 2;
    int len = r / 2 - l / 2;
    uchar val = pack(c, c);
    if (len < 30) {
        memset(s, val, len);
        return;
    }
    
    auto ps = (size_t) s;
    auto o = ps % 16;
    if (o != 0) o = 16 - o;
    if (o > 0) {
        memset(s, val, o);
        s += o;
        len -= o;
    }
    int tlen = len / 16 * 16;
    if (tlen > 0) {
        memsetSse(s, val, tlen);
    }
    if (len > tlen) {
        memset(s + tlen, val, len - tlen);
    }
}

bool areEqualSse(const uchar *s1, const uchar *s2, int len) {
    typedef __m128i T;
    T *a = (T*) s1;
    T *b = (T*) s2;
    int d = len / sizeof(T);
    int d8 = d / 8;
    ++d8;
    while (--d8) {
        T x = _mm_loadu_si128(a + 0);
        T y = _mm_loadu_si128(b + 0);
        T orRes = _mm_xor_si128(x, y);
        
        T x1 = _mm_loadu_si128(a + 1);
        T y1 = _mm_loadu_si128(b + 1);
        T orRes1 = _mm_xor_si128(x1, y1);
        
        x = _mm_loadu_si128(a + 2);
        y = _mm_loadu_si128(b + 2);
        orRes = _mm_or_si128(orRes, _mm_xor_si128(x, y));
        
        x1 = _mm_loadu_si128(a + 3);
        y1 = _mm_loadu_si128(b + 3);
        orRes1 = _mm_or_si128(orRes1, _mm_xor_si128(x1, y1));
        
        x = _mm_loadu_si128(a + 4);
        y = _mm_loadu_si128(b + 4);
        orRes = _mm_or_si128(orRes, _mm_xor_si128(x, y));
        
        x1 = _mm_loadu_si128(a + 5);
        y1 = _mm_loadu_si128(b + 5);
        orRes1 = _mm_or_si128(orRes1, _mm_xor_si128(x1, y1));
        
        x = _mm_loadu_si128(a + 6);
        y = _mm_loadu_si128(b + 6);
        orRes = _mm_or_si128(orRes, _mm_xor_si128(x, y));
        
        x1 = _mm_loadu_si128(a + 7);
        y1 = _mm_loadu_si128(b + 7);
        orRes1 = _mm_or_si128(orRes1, _mm_xor_si128(x1, y1));
        
        orRes = _mm_or_si128(orRes, orRes1);
        
        static const __m128i zero = {0};
        if (!_mm_testc_si128(zero, orRes)) break;
        a += 8;
        b += 8;
    }
    d %= 8;
    ++d;
    while (--d) {
        const T x = _mm_loadu_si128(a);
        const T y = _mm_loadu_si128(b);
        static const __m128i zero = {0};
        const T res = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, res)) break;
        ++a; ++b;
    }
    return d8 == 0 && d == 0;
}

bool areEqual(const uchar *s1, const uchar *s2, int len) {
    typedef ll T;
    
    T *a = (T*)s1;
    T *b = (T*)s2;
    int d = len / sizeof(T);
    const int P = 8;
    int d8 = d / P;
    ++d8;
    while (--d8) {
        if (*a != *b) break;
        ++a; ++b;
        if (*a != *b) break;
        ++a; ++b;
        if (*a != *b) break;
        ++a; ++b;
        if (*a != *b) break;
        ++a; ++b;
        if (*a != *b) break;
        ++a; ++b;
        if (*a != *b) break;
        ++a; ++b;
        if (*a != *b) break;
        ++a; ++b;
        if (*a != *b) break;
        ++a; ++b;
    }
    d %= P;
    ++d;
    while (--d) {
        if (*a != *b) break;
        ++a; ++b;
    }
    return d == 0 && d8 == 0;
}
char ALIGN(16) s[100100];
int main() {
    

    uchar ALIGN(16) s1[50100];
    uchar ALIGN(16) s2[50100];
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    cin >> s;
    FI(n) {
        s[i] -= '0' - 1;
    }
    FI((n + 1) / 2) {
        s1[i] = pack(s[i + i], s[i + i + 1]);
    }
    FI(n / 2) {
        s2[i] = pack(s[i + i + 1], s[i + i + 2]);
    }
    FI(m + k) {
        int t;
        int l, r, c;
        t = read_int();
        l = read_int();
        r = read_int();
        c = read_int();
        --l; --r;
        if (t == 1) {
            draw(s1, l, r, c + 1);
            draw(s2, l - 1, r - 1, c + 1);
        } else {
            bool e = true;
            if (r - l + 1 > c) {
                uchar *strA = l & 1 ? s2 + l / 2 : s1 + l / 2;
                uchar *strB = (l + c) & 1 ? s2 + (l + c) / 2 : s1 + (l + c) / 2;
                int len = (r - l + 1 - c);
                int sseLen = len / 32 * 16;
                if (sseLen > 0) {
                    e &= areEqualSse(strA, strB, sseLen);
                }
                l += len / 32 * 32;
                len %= 32;
                for (int i = 0; i < len; ++i) {
                    e &= getChar(s1, l + i) == getChar(s1, l + c + i);
                }
            }
            puts(e ? "YES" : "NO");
        }
    }
    
    return 0;
}