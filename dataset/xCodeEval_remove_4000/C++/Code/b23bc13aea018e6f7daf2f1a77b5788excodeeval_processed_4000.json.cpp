
































using namespace std;










using namespace tr1;




































double __begin;



typedef long long ll;
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
unsigned int reverseBits(uint x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T> inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool id3(int x){ return (x != 0 && (x&(x - 1)) == 0); }
template<class T1, class T2, class T3> T1 inline clamp(T1 x, const T2& a, const T3& b) { if (x < a) return a; else if (x > b) return b; else return x; }
unsigned long long id6() { unsigned long long ret = 0;

__asm__ __volatile__("id6" : "=A" (ret) : :);

return ret; }


template<class T = int> T read_int() {
    const int B = 4096;
    static char b[B + 16], *e = b + B, *i = e;
    auto c = [&]() { if (i == e) memset(b, 0, B), cin.read(b, B), i = b; };
    c();
    while (*i && (*i < '0' || *i > '9') && *i != '-') ++i;
    c();
    bool m = false;
    if (*i == '-') ++i, c(), m = true;
    T r = 0;
    while (*i >= '0' && *i <= '9') r = r * 10 + *i - '0', ++i, c();
    ++i;
    return m ? -r : r;
}
const int __BS = 4096;
static char __bu[__BS + 20], *__iw = __bu, *__e = __bu + __BS;
template<class T>
void write_int(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x;
    if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) {
        T t = x / 10;
        char c = x - 10 * t + '0';
        *__iw++ = c;
        x = t;
    }
    char* f = __iw - 1;
    while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __e) cout.write(__bu, __iw - __bu), __iw = __bu;
    *__iw++ = endc;
}
struct F { ~F() { if (__iw != __bu) cout.write(__bu, __iw - __bu); } };
static F flush;






TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p);
TT1 ostream& operator << (ostream& os, const vector<T>& v);
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, const multiset<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v);
TT1T2T3 ostream& operator << (ostream& os, const map<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const multimap<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
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








template<class T> inline void normmod(T &x, T m) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 id1(T1 x, T1 y, T2 m) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3> inline void id5(T1 &x, T2 y, T3 m) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3> inline void id0(T1 &x, T2 y, T3 m) { x -= y; if (x < 0) x += m; }

inline ll mulmod(ll x, ll n, ll m){ ll r = 0; normmod(x, m); normmod(n, m); while (n) { if (n & 1) id5(r, x, m); id5(x, x, m); n /= 2; } return r; }

inline ll mulmod(ll x, ll n, ll m){ return __int128(x) * n % m; }

inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1)r = (r*x) % m; x = (x*x) % m; n /= 2; }return r; }
inline ll id2(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> inline T gcd(T a, T b) { while (b) { a %= b; T t = a; a = b; b = t; } return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
ll id4(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = id4(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 4; i * i <= x; i += 2) if (x % i == 0) return 0; return 1; }
bool id7(long long n) {
    if (n <= 1000) return isPrime(n);
    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (!(a %= n)) return true;
        long long f = id2(a, s, n); if (f == 1 || f == n - 1) continue;
        for (int i = 1; i < t; ++i) if ((f = mulmod(f, f, n)) == n - 1) goto nextp;
        return false; nextp:;
    } return true;
}
















int32_t solve();
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    FREIN("input.txt");



    return solve();
}
const int N = 1000101;
const int K = 2;
const int p[K] = {37, 41};
int mods[K] = {};
int revp[N + 5][K];
int powp[N + 5][K];
struct Hash {
    int vals[K];
    Hash() {
        FI(K) vals[i] = 0;
    }
    void add(int c) {
        FI(K) {
            vals[i] = (vals[i] * (ll) p[i] + c) % mods[i];
        }
    }
    void remove(int c) {
        FI(K) {
            vals[i] = (vals[i] + mods[i] - c) * (ll) revp[1][i] % mods[i];
        }
    }
    Hash del(int c, int len) {
        Hash cp;
        FI(K) {
            cp.vals[i] = (vals[i] - c * (ll)powp[len - 1][i]) % mods[i];
            if (cp.vals[i] < 0) cp.vals[i] += mods[i];
        }
        return cp;
    }
    bool operator<(const Hash& h) const {
        FI(K) {
            if (this->vals[i] != h.vals[i]) {
                return this->vals[i] < h.vals[i];
            }
        }
        return false;
    }
};
ostream& operator<<(ostream& os, const Hash& he) {
    os << "(";
    FI(K) {
        cout << he.vals[i] << (i == K - 1 ? "" : ",");
    }
    os << ")";
    return os;
}
string s[N];
vector<int> v[N];
Hash he[N];
int32_t solve() {
    srand(time(0));
    int ps = 0;
    for (int i = INF; ps < 2; ++i) {
        if (rand() % 10 == 0 && id7(i)) {
            mods[ps++] = i;
        }
    }
    FI(K) {
        powp[0][i] = 1;
        for (int j = 1; j <= N; ++j) {
            powp[j][i] = powp[j - 1][i] * (ll)p[i] % mods[i];
        }
        revp[N][i] = powmod(powp[N][i], mods[i] - 2, mods[i]);
        for (int j = N - 1; j >= 0; --j) {
            revp[j][i] = revp[j + 1][i] * (ll)p[i] % mods[i];
        }
    }


    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int maxLen = 0;
        set<Hash> se;
        FI(n) {
            cin >> s[i];
            v[s[i].length()].push_back(i);
            maxLen = max(maxLen, (int)s[i].size());
            he[i] = Hash();
            for (char c : s[i]) {
                he[i].add(c);
            }
        }
        int ans = 0;
        for (int i = maxLen; i >= 0; --i) {
            for (auto id : v[i]) {




                auto p = se.insert(he[id]);
                if (p.second) {
                    ++ans;






                    se.insert(he[id].del(s[id][0], (int)s[id].size()));
                }
                he[id].remove(s[id].back());
                s[id].pop_back();
                if (i > 1) {
                    v[i - 1].push_back(id);
                }


            }
            v[i].clear();
        }
        cout << ans << endl;
    }


    return 0;
}