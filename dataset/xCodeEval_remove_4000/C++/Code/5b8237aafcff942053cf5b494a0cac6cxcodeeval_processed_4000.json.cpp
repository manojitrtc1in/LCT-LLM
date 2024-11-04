







































using namespace std;










using namespace tr1;




































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
inline int countBits(ll v){return countBits((ull)v); }
inline int countBits(int v){return countBits((uint)v); }
unsigned int reverseBits(uint x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T> inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool id4(int x){ return (x != 0 && (x&(x - 1)) == 0); }
constexpr ll power(ll x, int p) { return p == 0 ? 1 : (x * power(x, p - 1)); }
template<class T1, class T2, class T3> T1 inline clamp(T1 x, const T2& a, const T3& b) { if (x < a) return a; else if (x > b) return b; else return x; }
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
static char id9[__BS + 20], *__iw = id9, *__ew = id9 + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(id9, __iw - id9), __iw = id9;
    *__iw++ = endc;
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















template<class T> inline void normmod(T &x, T m) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 id1(T1 x, T1 y, T2 m) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3> inline void id6(T1 &x, T2 y, T3 m) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3> inline void id0(T1 &x, T2 y, T3 m) { x -= y; if (x < 0) x += m; }

inline ll mulmod(ll x, ll n, ll m){ ll r = 0; normmod(x, m); normmod(n, m); while (n) { if (n & 1) r += x; x += x; if (r >= m) r -= m; if (x >= m) x -= m; n /= 2; } return r; }

using int128 = __int128;
inline ll mulmod(ll x, ll n, ll m){ return __int128(x) * n % m; }

inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1)r = (r*x) % m; x = (x*x) % m; n /= 2; }return r; }
inline ll id3(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> inline T gcd(T a, T b) { while (b) { a %= b; T t = a; a = b; b = t; } return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
ll id5(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = id5(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
bool id8(long long n) {
    if (n <= 1000) return isPrime(n);
    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
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
int ap[101010];
int seed;
int rnd() {
    int res = seed;
    seed = (seed * 7LL + 13) % mod;
    return res;
}
struct Node {
    ll same;
};
Node tr[404040];
void build(int cur, int l, int r) {
    if (l == r) {
        tr[cur].same = ap[l];
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        build(dcur, l, m);
        build(dcur + 1, m + 1, r);
    }
}
void push(int cur, int l, int r) {
    if (l == r) {
        return;
    }
    if (tr[cur].same) {
        for (int to : {cur + cur, cur + cur + 1}) {
            tr[to].same = tr[cur].same;
        }
        tr[cur].same = 0;
    }
}
void assign(int cur, int l, int r, int x, int y, int val) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
        tr[cur].same = val;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        push(cur, l, r);
        assign(dcur, l, m, x, y, val);
        assign(dcur + 1, m + 1, r ,x, y, val);
    }
}
void add(int cur, int l, int r, int x, int y, int val) {
    if (x > r || y < l) return;
    if (x <= l && r <= y && tr[cur].same) {
        tr[cur].same += val;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        push(cur, l, r);
        add(dcur, l, m, x, y, val);
        add(dcur + 1, m + 1, r ,x, y, val);
    }
}
ll getAns(int cur, int l, int r, int x, int y, int t, int p) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y && tr[cur].same) {
        return powmod(tr[cur].same % p, t, p) * (r - l + 1LL) % p;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        push(cur, l, r);
        return (getAns(dcur, l, m, x, y, t, p) + getAns(dcur + 1, m + 1, r, x, y, t, p)) % p;
    }
    
}
vector<pair<ll, int>> st;
void go(int cur, int l, int r, int x, int y) {
    if (x > r || y < l) return;
    if (tr[cur].same) {
        st.push_back({tr[cur].same, min(r, y) - max(l, x) + 1});
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        push(cur, l, r);
        go(dcur, l, m, x, y);
        go(dcur + 1, m + 1, r, x, y);
    }
}


int solve() {
    int n, m, v;
    cin >> n >> m >> seed >> v;
    FI(n) {
        ap[i] = rnd() % v + 1;
    }
    build(1, 0, n - 1);
    FI(m) {
        int t = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        if (l > r) {
            swap(l, r);
        }
        int x, y = 0;
        if (t == 3) {
            x = rnd() % (r - l + 1) + 1;
        } else {
            x = rnd() % v + 1;
        }
        if (t == 4) {
            y = rnd() % v + 1;
        }
        --l; --r;
        if (t == 1) {
            add(1, 0, n - 1, l, r, x);
        } else if (t == 2) {
            assign(1, 0, n - 1, l, r, x);
        } else if (t == 3) {
            st.clear();
            go(1, 0, n - 1, l, r);
            sort(all(st));
            for (auto p : st) {
                if (x <= p.second) {
                    cout << p.first << '\n';
                    break;
                }
                x -= p.second;
            }
        } else if (t == 4) {
            auto res = getAns(1, 0, n - 1, l, r, x, y);
            cout << res << '\n';
        }
    }
    
    return 0;
}

