































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






















inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T>
inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }
unsigned long long id4() {
    unsigned long long ret;
    __asm__ __volatile__("id4" : "=A" (ret) : :);
    return ret;
}






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
TT1T2 void printarray(T1 a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }



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
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }








template<class T> bool isPrime(T x) { if (x < 2) return 0; for (T i = 2; i * i <= x; ++i) if (x % i == 0) return 0; return 1; }
inline void normmod(ll &x, ll m) { x %= m; if (x < 0) x += m; }
inline ll id5(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int id5(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void id3(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void id3(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void id2(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void id2(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = id5(res, x, m); x = id5(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
ll id1(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1;
    ll d = id1(b % a, a, y, y1);
    x = y1 - (b / a) * y;
    return d;
}
















void add(ll& x, ll y) {
    x += y;
    if (x >= mod) x -= mod;
}
void sub(ll& x, ll y) {
    x -= y;
    if (x < 0) x += mod;
}
ll pow2(ll v) {
    return 1LL << (63 - __builtin_clzll(v));
}
ll solve2(ll x, ll y, ll k, ll bonus = 0) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) swap(x, y);
    ll ty = pow2(y);
    ll tx = pow2(x);
    ll res;
    ll txk = min(tx, k);
    if (tx == ty) {
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod;
        add(res, solve2(x - tx, tx, k - tx, bonus + tx));
        add(res, solve2(y - tx, tx, k - tx, bonus + tx));
        add(res, solve2(x - tx, y - tx, k, bonus));
    } else {
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod;
        add(res, solve2(x - tx, y, k - tx, bonus + tx));
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    FREIN("input.txt");



    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        ll ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        cout << ans * powmod(2LL, mod - 2, mod) % mod << endl;
    }
    CURTIME();
    return 0;
}







