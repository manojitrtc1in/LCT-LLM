











































using namespace std;










using namespace tr1;



































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























inline int countBits(uint v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int countBits(ull v){uint t=v>>32;uint p=(v & ((1ULL << 32) - 1)); return countBits(t) + countBits(p); }
inline int countBits(ll v){return countBits((ull)v); }
inline int countBits(int v){return countBits((uint)v); }
unsigned int reverseBits(uint x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T> inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool id5(int x){ return (x != 0 && (x&(x - 1)) == 0); }
constexpr ll power(ll x, int p) { return p == 0 ? 1 : (x * power(x, p - 1)); }


unsigned long long id9() { unsigned long long ret = 0;

    return __builtin_readcyclecounter();


    asm volatile("id9" : "=A" (ret) : :);

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
static char id13[__BS + 20], *__iw = id13, *__ew = id13 + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(id13, __iw - id13), __iw = id13;
    if (endc) { *__iw++ = endc; }
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) cout.write(id13, __iw - id13), __iw = id13; }
}
struct __FL__ { ~__FL__() { if (__iw != id13) cout.write(id13, __iw - id13); } };
static __FL__ id3;






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




TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2& operator+=(PT1T2 &p1 , const PT1T2 &p2) { p1.first += p2.first, p1.second += p2.second; return p1; }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }
TT1T2 inline PT1T2& operator-=(PT1T2 &p1 , const PT1T2 &p2) { p1.first -= p2.first, p1.second -= p2.second; return p1; }















const int id14 = 1000000007;
template<class T> inline void normmod(T &x, T m = id14) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 id2(T1 x, T1 y, T2 m = id14) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3 = int> inline void id8(T1 &x, T2 y, T3 m = id14) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3 = int> inline void id1(T1 &x, T2 y, T3 m = id14) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ x %= m; n %= m; ll r = x * n - ll(ld(x)*ld(n) / ld(m)) * m; while (r < 0) r += m; while (r >= m) r -= m; return r; }
inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1) r *= x; x *= x; r %= m; x %= m; n /= 2; }return r; }
inline ll id4(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> inline T gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<class T>
T id12(T u, T v) {
    int shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}

inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
ll id6(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = id6(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
bool id11(long long n) {
    if (n <= 1000) return isPrime(n);
    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (!(a %= n)) return true;
        long long f = id4(a, s, n); if (f == 1 || f == n - 1) continue;
        for (int i = 1; i < t; ++i) if ((f = mulmod(f, f, n)) == n - 1) goto nextp;
        return false; nextp:;
    } return true;
}



















struct cd {
    double x, y;
    inline cd operator*(const cd& other) {
        return {x * other.x - y * other.y, x * other.y + y * other.x};
    }
    inline cd operator+(const cd& other) {
        return {x + other.x, y + other.y};
    }
    inline cd operator-(const cd& other) {
        return {x - other.x, y - other.y};
    }
    double real() { return x; }
    double imag() { return y; }
    static inline cd polar(double rho, double theta) {
        double x = rho * cos(theta);
        double y = rho * sin(theta);
        return {x, y};
    }
};
inline cd conj(cd x) {
    return {x.x, -x.y};
}

constexpr int T = 5;
constexpr int RADIX = power(10, T);
const int N = 1 << 19;

const double id7 = log(RADIX);
const double id10 = log(3.0);

istream& operator >> (istream& in, vi& r) {
    char s[1 << 21];
    int first = 5;
    cin.read(s + first, 3 << 19);
    int last = first; while (s[last] != '\n') ++last;
    int len = last - first;
    while (len % T) s[--first] = '0', ++len;
    r.resize(len / T);
    FI(r.size()) FJ(T) r[i] = r[i] * 10 + s[first + len - 1 - (i * T + T - 1 - j)] - '0';
    return in;
}

cd W[N];
template<int n2>
inline void fft0(cd* p) {
    constexpr int n = n2 / 2;
    for (int i = 0, j = n; i < n; ++i, ++j) {
        cd x = p[i], y = p[j];
        p[i] = (x + y);
        p[j] = (x - y) * conj(W[j]);
    }
    if (n > 1) {
        fft0<n>(p);
        fft0<n>(p + n);
    }
}
template<int n2>
inline void fft1(cd* p) {
    constexpr int n = n2 / 2;
    if (n > 1) {
        fft1<n>(p);
        fft1<n>(p + n);
    }
    for (int i = 0, j = n; i < n; ++i, ++j) {
        cd x = p[i], y = p[j] * W[j];
        p[i] = x + y;
        p[j] = x - y;
    }
}

void fft0(cd* p, int n2) {
    int n = n2 / 2;
    if (n == 4) {

        F(0, 4, 4);
        F(1, 5, 5);
        F(2, 6, 6);
        F(3, 7, 7);
        
        F(0, 2, 2);
        F(1, 3, 3);
        
        F(0, 1, 1);
        
        F(2, 3, 1);
        
        F(4, 6, 2);
        F(5, 7, 3);
        
        F(4, 5, 1);
        
        F(6, 7, 1);
        return;
    }
    for (int i = 0, j = n; i < n; ++i, ++j) {
        cd x = p[i], y = p[j];
        p[i] = (x + y);
        p[j] = (x - y) * conj(W[j]);
    }
    if (n > 1) {
        fft0(p, n);
        fft0(p + n, n);
    }
}

void fft1(cd* p, int n2) {








    int n = n2 / 2;
    if (n == 4) {

        F(0, 1, 1);
        
        F(2, 3, 1);
        
        F(0, 2, 2);
        F(1, 3, 3);
        
        
        F(4, 5, 1);
        
        F(6, 7, 1);
        
        F(4, 6, 2);
        F(5, 7, 3);
        
        F(0, 4, 4);
        F(1, 5, 5);
        F(2, 6, 6);
        F(3, 7, 7);

        return;
    }
    if (n > 1) {
        fft1(p, n);
        fft1(p + n, n);
    }
    for (int i = 0, j = n; i < n; ++i, ++j) {
        cd x = p[i], y = p[j] * W[j];
        p[i] = x + y;
        p[j] = x - y;
    }
}
cd af[N];
template<int n>
int Sqr(int* a) {
    FI(n) af[i] = {(double)a[i], 0.0};
    fft0(af, n);
    FI(n) af[i] = af[i] * af[i];
    fft1(af, n);
    constexpr double invN = 1.0 / n;
    ull carry = 0;
    FI(n) {
        carry += (ull)(af[i].real() * invN + 0.5);
        a[i] = carry % RADIX;
        carry /= RADIX;
    }
    int as = n;
    while (a[as - 1] == 0) --as;
    return as;
}

template<int b>
int mul(int* a, int as) {
    int carry = 0;
    for (int i = 0; i < as; ++i) {
        auto& x = a[i];
        carry += x * b;
        int nc = carry / RADIX;
        x = carry - nc * RADIX;
        carry = nc;
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
    int bs = (int) b.size();
    if (as != bs) return as - bs;
    for (int i = as; i --> 0; )
        if (a[i] != b[i])
            return a[i] - b[i];
    return 0;
}

int main() {
    ios::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);

    FI(N / 2) W[i + N / 2] = cd::polar(1.0, (2 * PI / N) * i);
    for (int i = N / 2; i --> 0; W[i] = W[2 * i]);
    vi a;
    cin >> a;
    int n = (int)a.size();
    if (n == 1 && a[0] < 4) {
        cout << a[0] << endl;
        return 0;
    }
    int res = -1u/2;
    for (int i = 0; i <= 2; ++i) {
        if (i) div<2>(a);
        double logA = n > 1 ? log(a[n - 1] * (double)RADIX + a[n - 2]) + id7 * (n - 2) : log(a[n - 1]);
        logA = logA / id10 - 1e-9;
        int id0 = logA + 1;
        double c = logA - int(logA);
        DBN(c);
        if (c < 0.9) {
            res = min(res, 3 * id0 + i * 2);
            continue;
        }
        static int x[N] = {1};
        int xs = 1;
        for (int i = 26; i >= 0; --i) {
            int n = max(2 * (int)xs - 1, 1 << 8);
            while (n & n - 1) n = (n | n - 1) + 1;
            switch (n) {

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
            if (id0 & 1 << i) xs = mul<3>(x, xs);
        }
        if (cmp(x, xs, a) < 0) ++id0;
        res = min(res, 3 * id0 + i * 2);
    }
    cout << res << endl;
    CURTIME();
    return 0;
}
