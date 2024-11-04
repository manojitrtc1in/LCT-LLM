














































using namespace std;






























[[noreturn]] __attribute__((always_inline)) inline void undefinedBehaviour() {}









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
inline bool id4(int x){ return (x != 0 && (x&(x - 1)) == 0); }
constexpr ll power(ll x, int p) { return p == 0 ? 1 : (x * power(x, p - 1)); }
template<class T>
inline bool inRange(const T& val, const T& min, const T& max) { return min <= val && val <= max; }


unsigned long long id7() { unsigned long long ret = 0;

    return __builtin_readcyclecounter();


    asm volatile("id7" : "=A" (ret) : :);

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
string readString() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    string r; c(); while (*__ir && isspace(*__ir)) ++__ir, c();
    while (!isspace(*__ir)) r.push_back(*__ir), ++__ir, c();
    ++__ir; return r;
}
char readChar() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    c(); while (*__ir && isspace(*__ir)) ++__ir, c(); return *__ir++;
}
static char id9[__BS + 20], *__iw = id9, *__ew = id9 + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(id9, __iw - id9), __iw = id9;
    if (endc) { *__iw++ = endc; }
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) cout.write(id9, __iw - id9), __iw = id9; }
}
struct __FL__ { ~__FL__() { if (__iw != id9) cout.write(id9, __iw - id9); } };
static __FL__ id2;






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















const int id10 = 1000000007;
template<class T> inline void normmod(T &x, T m = id10) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 id1(T1 x, T1 y, T2 m = id10) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3 = int> inline void id6(T1 &x, T2 y, T3 m = id10) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3 = int> inline void id0(T1 &x, T2 y, T3 m = id10) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ x %= m; n %= m; ll r = x * n - ll(ld(x)*ld(n) / ld(m)) * m; while (r < 0) r += m; while (r >= m) r -= m; return r; }
inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1) r *= x; x *= x; r %= m; x %= m; n /= 2; }return r; }
inline ll id3(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> inline T gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<class T>
T id8(T u, T v) {
    int shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
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

    FREIN("input.txt");



    
    return solve();
}
int solve() {
    int tc;
    cin >> tc;
    while (tc--) {
        array<char, 32> mapping = {};
        array<char, 32> mapped = {};
        int k;
        cin >> k;
        string s, a, b;
        cin >> s >> a >> b;
        for (char& c : s) c -= 'a' - 1;
        for (char& c : a) c -= 'a' - 1;
        for (char& c : b) c -= 'a' - 1;
        bool ok = true;
        for (int i = 0; i < s.size(); ++i) {
            if (mapping[s[i]]) {
                char c = mapping[s[i]];
                if (c < a[i] || c > b[i]) {
                    ok = false;
                    break;
                }
                if (c > a[i] && c < b[i]) {
                    ok = true;
                    break;
                }
                if (a[i] == b[i]) continue;
                if (c < b[i]) {
                    for (int j = i + 1; j < s.size(); ++j) {
                        if (mapping[s[j]]) {
                            char c = mapping[s[j]];
                            if (c != a[j]) {
                                ok = c > a[j];
                                break;
                            }
                        } else {
                            int free = 0;
                            for (int c = a[j] + 1; c <= k; ++c) {
                                if (!mapped[c]) {
                                    free = c;
                                }
                            }
                            if (free) {
                                mapping[s[j]] = free;
                                mapped[free] = true;
                                ok = true;
                                break;
                            }
                            if (mapped[a[j]]) {
                                ok = false;
                                break;
                            }
                            mapping[s[j]] = a[j];
                            mapped[a[j]] = true;
                        }
                    }
                }
                if (c > a[i]) {
                    for (int j = i + 1; j < s.size(); ++j) {
                        if (mapping[s[j]]) {
                            char c = mapping[s[j]];
                            if (c != b[j]) {
                                ok = c < b[j];
                                break;
                            }
                        } else {
                            int free = 0;
                            for (int c = 1; c < b[j]; ++c) {
                                if (!mapped[c]) {
                                    free = c;
                                }
                            }
                            if (free) {
                                mapping[s[j]] = free;
                                mapped[free] = true;
                                ok = true;
                                break;
                            }
                            if (mapped[b[j]]) {
                                ok = false;
                                break;
                            }
                            mapping[s[j]] = b[j];
                            mapped[b[j]] = true;
                        }
                    }
                }
                break;
            } else if (a[i] == b[i]) {
                if (mapped[a[i]]) {
                    ok = false;
                    break;
                }
                mapping[s[i]] = a[i];
                mapped[a[i]] = true;
            } else {
                int free = 0;
                for (int c = a[i] + 1; c < b[i]; ++c) {
                    if (!mapped[c]) {
                        free = c;
                    }
                }
                if (free) {
                    mapping[s[i]] = free;
                    mapped[free] = true;
                    ok = true;


                    break;
                }
                if (mapped[a[i]] && mapped[b[i]]) {
                    ok = false;
                    break;
                }
                ok = false;
                if (!mapped[a[i]]) {
                    auto savedMapping = mapping;
                    auto savedMapped = mapped;
                    mapping[s[i]] = a[i];
                    mapped[a[i]] = true;
                    ok = true;
                    for (int j = i + 1; j < s.size(); ++j) {
                        if (mapping[s[j]]) {
                            char c = mapping[s[j]];
                            if (c != a[j]) {
                                ok = c > a[j];
                                break;
                            }
                        } else {
                            int free = 0;
                            for (int c = a[j] + 1; c <= k; ++c) {
                                if (!mapped[c]) {
                                    free = c;
                                }
                            }
                            if (free) {
                                mapping[s[j]] = free;
                                mapped[free] = true;
                                ok = true;
                                break;
                            }
                            if (mapped[a[j]]) {
                                ok = false;
                                break;
                            }
                            mapping[s[j]] = a[j];
                            mapped[a[j]] = true;
                        }
                    }
                    if (!ok) {
                        mapping = savedMapping;
                        mapped = savedMapped;
                    }
                    if (ok) break;
                }
                if (!mapped[b[i]]) {
                    mapping[s[i]] = b[i];
                    mapped[b[i]] = true;
                    ok = true;
                    for (int j = i + 1; j < s.size(); ++j) {
                        if (mapping[s[j]]) {
                            char c = mapping[s[j]];
                            if (c != b[j]) {
                                ok = c < b[j];
                                break;
                            }
                        } else {
                            int free = 0;
                            for (int c = 1; c < b[j]; ++c) {
                                if (!mapped[c]) {
                                    free = c;
                                }
                            }
                            if (free) {
                                mapping[s[j]] = free;
                                mapped[free] = true;
                                ok = true;
                                break;
                            }
                            if (mapped[b[j]]) {
                                ok = false;
                                break;
                            }
                            mapping[s[j]] = b[j];
                            mapped[b[j]] = true;
                        }
                    }
                    if (ok) break;
                }
                break;
            }
        }
        if (ok) {


            int last = 1;
            for (int i = 1; i <= k; ++i) {
                while (mapped[last]) ++last;
                if (!mapping[i]) {
                    mapping[i] = last++;
                }
            }
            cout << "YES\n";
            char answer[30] = {};
            for (int i = 1; i <= k; ++i) {
                answer[i - 1] = mapping[i] - 1 + 'a';
            }
            answer[k] = '\n';
            cout << answer;
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}


