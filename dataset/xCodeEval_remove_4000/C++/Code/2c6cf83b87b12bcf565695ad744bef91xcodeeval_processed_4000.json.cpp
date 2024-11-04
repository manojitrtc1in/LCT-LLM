























using namespace std;








using namespace std::tr1;




























double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(){};triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};


template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }







inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));return((x >> 16) | (x << 16));}
inline int sign(int x){ return x > 0;}
inline bool id0(int x){return (x!=0 && (x&(x-1))==0);}




template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";cout<<endl;}








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











typedef unsigned char uchar;

int read_int()
{
    const int id3 = 4096;
    static char inbuf[id3 + 16];
    static char *inp = inbuf;
    static char *linp = inbuf + id3;
    if (*inp == 0)
    {
        memset(inbuf, 0, id3);
        cin.read(inbuf, id3);
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
            memset(inbuf, 0, id3);
            cin.read(inbuf, id3);
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
void id1(uchar *s, uchar c, int len) {
    typedef __m128i T;
    const T v = _mm_set_epi8(c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    T* ptr = (T*) s;
    len /= sizeof(T);
    
    int len8 = len / 8;
    ++len8;
    while (--len8) {
        _mm_store_si128(ptr + 0, v);
        _mm_store_si128(ptr + 1, v);
        _mm_store_si128(ptr + 2, v);
        _mm_store_si128(ptr + 3, v);
        _mm_store_si128(ptr + 4, v);
        _mm_store_si128(ptr + 5, v);
        _mm_store_si128(ptr + 6, v);
        _mm_store_si128(ptr + 7, v);
        ptr += 8;
    }
    len %= 8;
    ++len;
    while (--len) {
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
        id1(s, val, tlen);
    }
    if (len > tlen) {
        memset(s + tlen, val, len - tlen);
    }
}


bool id5(const uchar *s1, const uchar *s2, int len) {
    typedef __m128i T;
    T *a = (T*) s1;
    T *b = (T*) s2;
    int d = len / sizeof(T);
    int d8 = d / 8;
    ++d8;
    while (--d8) {
        static const __m128i zero = {0};
        T x = _mm_loadu_si128(a + 0);
        T y = _mm_loadu_si128(b + 0);
        T orRes = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, orRes)) break;
        
        x = _mm_loadu_si128(a + 1);
        y = _mm_loadu_si128(b + 1);
        orRes = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, orRes)) break;
        x = _mm_loadu_si128(a + 2);
        y = _mm_loadu_si128(b + 2);
        orRes = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, orRes)) break;
        x = _mm_loadu_si128(a + 3);
        y = _mm_loadu_si128(b + 3);
        orRes = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, orRes)) break;
        x = _mm_loadu_si128(a + 4);
        y = _mm_loadu_si128(b + 4);
        orRes = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, orRes)) break;
        x = _mm_loadu_si128(a + 5);
        y = _mm_loadu_si128(b + 5);
        orRes = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, orRes)) break;
        x = _mm_loadu_si128(a + 6);
        y = _mm_loadu_si128(b + 6);
        orRes = _mm_xor_si128(x, y);
        if (!_mm_testc_si128(zero, orRes)) break;
        x = _mm_loadu_si128(a + 7);
        y = _mm_loadu_si128(b + 7);
        orRes = _mm_xor_si128(x, y);
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


bool id6(const uchar *s1, const uchar *s2, int len) {
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
        T id2 = _mm_xor_si128(x1, y1);
        
        x = _mm_loadu_si128(a + 2);
        y = _mm_loadu_si128(b + 2);
        orRes = _mm_or_si128(orRes, _mm_xor_si128(x, y));
        
        x1 = _mm_loadu_si128(a + 3);
        y1 = _mm_loadu_si128(b + 3);
        id2 = _mm_or_si128(id2, _mm_xor_si128(x1, y1));
        
        x = _mm_loadu_si128(a + 4);
        y = _mm_loadu_si128(b + 4);
        orRes = _mm_or_si128(orRes, _mm_xor_si128(x, y));
        
        x1 = _mm_loadu_si128(a + 5);
        y1 = _mm_loadu_si128(b + 5);
        id2 = _mm_or_si128(id2, _mm_xor_si128(x1, y1));
        
        x = _mm_loadu_si128(a + 6);
        y = _mm_loadu_si128(b + 6);
        orRes = _mm_or_si128(orRes, _mm_xor_si128(x, y));
        
        x1 = _mm_loadu_si128(a + 7);
        y1 = _mm_loadu_si128(b + 7);
        id2 = _mm_or_si128(id2, _mm_xor_si128(x1, y1));
        
        orRes = _mm_or_si128(orRes, id2);
        
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
                int id4 = len / 32 * 16;
                if (id4 > 0) {
                    e &= id6(strA, strB, id4);
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