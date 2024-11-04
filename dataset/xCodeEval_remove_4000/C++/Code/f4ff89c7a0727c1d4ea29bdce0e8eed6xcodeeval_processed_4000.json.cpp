







































using namespace std;





































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















































inline int countBits(uint v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return(((v+(v>>4))&0xF0F0F0F)*0x1010101)>>24;}
inline int countBits(ull v){uint t=v>>32;uint p=(v & ((1ULL << 32) - 1)); return countBits(t) + countBits(p); }
inline int countBits(ll v){return countBits((ull)v); }
inline int countBits(int v){return countBits((uint)v); }
unsigned int reverseBits(uint x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T> inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool id4(int x){ return (x != 0 && (x&(x - 1)) == 0); }
constexpr ll power(ll x, int p) { return p == 0 ? 1 : (x * power(x, p - 1)); }
template<class T>
inline bool inRange(const T& val, const T& min, const T& max) { return min <= val && val <= max; }




















const int __BS = 4096;
static char __bur[__BS + 16], *__er = __bur + __BS, *__ir = __er;
auto c = []() { if (__ir == __er) {std::fill(__bur, __bur + __BS + 16, 0); cin.read(__bur, __BS);


    __ir = __bur; };};
template<class T = int> T readInt() {
    c(); while (*__ir && (*__ir < '0' || *__ir > '9') && *__ir != '-') ++__ir; c();
    bool m = false; if (*__ir == '-') {++__ir; c(); m = true;}
    T r = 0; while (*__ir >= '0' && *__ir <= '9') {r = r * 10 + *__ir - '0', ++__ir; c();}
    ++__ir; return m ? -r : r;
}
string readString() {
    string r; c(); while (*__ir && isspace(*__ir)) {++__ir; c();}
    while (!isspace(*__ir)) {r.push_back(*__ir); ++__ir; c();}
    ++__ir; return r;
}
char readChar() {
    c(); while (*__ir && isspace(*__ir)) {++__ir; c();} return *__ir++;
}
void flushInput() {
    __ir = __er;
    std::fill(__bur, __bur + __BS, 0);
}
static char id8[__BS + 20], *__iw = id8, *__ew = id8 + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) {swap(*s, *f); ++s; --f;}
    if (__iw > __ew) {cout.write(id8, __iw - id8); __iw = id8;}
    if (endc) { *__iw++ = endc; }
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) {cout.write(id8, __iw - id8); __iw = id8; }}
}
struct __FL__ { ~__FL__() { if (__iw != id8) cout.write(id8, __iw - id8); } };
static __FL__ id2;







TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p);
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v);
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, const Container& x);
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
TT1T2 void printarray(const T1& a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) {
    bool f = 1;
    os << "[";
    while (!v.empty()) {
        if (!f) os << ", ";
        f = 0; os << v.top();
        v.pop();
    }
    return os << "]";
}

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, const Container& x) {
    if constexpr (std::is_pointer<Container>::value) {
        if constexpr (sizeof(*x) == 1) { return os << (const char*)x; } else { return os << (ptrdiff_t)x; }
    } else {
        os << "["; bool f = 1; for(const auto& y : x) { if (!f) os << ", "; f = 0; os << y; } return os << "]";
    }
}



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















const int id9 = 1000000007;
template<class T> inline void normmod(T &x, T m = id9) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 id1(T1 x, T1 y, T2 m = id9) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3 = int> inline void id6(T1 &x, T2 y, T3 m = id9) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3 = int> inline void id0(T1 &x, T2 y, T3 m = id9) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ x %= m; n %= m; ll r = x * n - ll(ld(x)*ld(n) / ld(m)) * m; while (r < 0) r += m; while (r >= m) r -= m; return r; }
inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1) r *= x; x *= x; r %= m; x %= m; n /= 2; }return r; }
inline ll id3(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> inline T gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<class T>
T id7(T u, T v) {
    int shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}
template<class T> inline ll norm(const pair<T, T>& p) {
    return p.first * 1LL * p.first + p.second * 1LL * p.second;
}
inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
ll id5(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = id5(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}

bool isPrime(long long n) {
    if (n <= (1 << 14)) { int x = (int) n; if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
        for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
    long long s = n - 1; int t = 0; while (s % 2 == 0) { s /= 2; ++t; }
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (!(a %= n)) return true;
        long long f = id3(a, s, n); if (f == 1 || f == n - 1) continue;
        for (int i = 1; i < t; ++i) if ((f = mulmod(f, f, n)) == n - 1) goto nextp;
        return false; nextp:;
    } return true;
}



















int32_t solve();
int32_t main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);cin.tie(0);

    FREIN("Data/input.txt");



    return solve();
}

int a[303030];
struct SSet {
    int shift = 0;
    int rev = 1;
    map<int, int> s;
    void reverse() {
        rev *= -1;
        shift *= -1;
    }
    void add(int x) {
        s[(x - shift) * rev]++;
    }
    int count(int x) {
        x -= shift;
        x *= rev;
        auto it = s.find(x);
        if (it == s.end()) {
            return 0;
        } else {
            return it->second;
        }
    }
    void dropBigger(int x) {
        x -= shift;
        x *= rev;
        if (rev > 0) {
            while (!s.empty()) {
                auto it = --s.end();
                if (it->first > x) {
                    s.erase(it);
                } else {
                    break;
                }
            }
        } else {
            while (!s.empty()) {
                auto it = s.begin();
                if (it->first < x) {
                    s.erase(it);
                } else {
                    break;
                }
            }
        }
    }
};
int solve() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        SSet dp;
        ll ans = 0;
        FI(n) {
            cin >> a[i];
            dp.dropBigger(a[i]);
            dp.reverse();
            dp.add(0);
            dp.shift += a[i];
            ans += dp.count(0);
        }
        cout << ans << endl;
    }
    return 0;
}
