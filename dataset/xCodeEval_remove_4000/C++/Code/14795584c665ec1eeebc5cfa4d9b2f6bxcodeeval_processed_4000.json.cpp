
































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
inline bool id1(int x){ return (x != 0 && (x&(x - 1)) == 0); }
template<class T1, class T2, class T3> T1 inline clamp(T1 x, const T2& a, const T3& b) { if (x < a) return a; else if (x > b) return b; else return x; }
unsigned long long id6() {
    unsigned long long ret;
    __asm__ __volatile__("id6" : "=A" (ret) : :);
    return ret;
}


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
template<class T>
void write_int(T x, char endc = '\n') {
    const int B = 4096;
    static char b[B + 20], *i = b, *e = b + B;
    if (x < 0) *i++ = '-', x = -x;
    if (x == 0) *i++ = '0';
    char* s = i;
    while (x) {
        T t = x / 10;
        char c = x - 10 * t + '0';
        *i++ = c;
        x = t;
    }
    char* f = i - 1;
    while (s < f) swap(*s, *f), ++s, --f;
    if (i > e) cout.write(b, i - b), i = b;
    *i++ = endc;
    struct F { ~F() { if (i != b) cout.write(b, i - b); } };
    static F flush;
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
inline ll id7(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int id7(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void id4(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void id4(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void id3(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void id3(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = id7(res, x, m); x = id7(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
inline ll id0(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n >>= 1; } return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
ll id2(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1;
    ll d = id2(b % a, a, y, y1);
    x = y1 - (b / a) * y;
    return d;
}
















int a[3030];

struct rib {
    int b, u, c, f;
    size_t back;
};

vector < vector<rib> > g (6030);
void id5 (int a, int b, int u, int c) {
    rib r1 = { b, u, c, 0, g[b].size() };
    rib r2 = { a, 0, -c, 0, g[a].size() };
    g[a].push_back (r1);
    g[b].push_back (r2);
}

int flow(int p)
{
    int s = 0;
    int t = 2 * p + 1;
    int k = 4;
    int n = 2 * p + 2;
    
    int flow = 0,  cost = 0;
    while (flow < k) {
        vector<int> id (n, 0);
        vector<int> d (n, INF);
        vector<int> q (n);
        vector<int> p (n);
        vector<size_t> id8 (n);
        int qh=0, qt=0;
        q[qt++] = s;
        d[s] = 0;
        while (qh != qt) {
            int v = q[qh++];
            id[v] = 2;
            if (qh == n)
                qh = 0;
            for (size_t i = 0; i < g[v].size(); ++i) {
                rib& r = g[v][i];
                if (r.f < r.u && d[v] + r.c < d[r.b]) {
                    d[r.b] = d[v] + r.c;
                    if (id[r.b] == 0) {
                        q[qt++] = r.b;
                        if (qt == n)
                            qt = 0;
                    } else if (id[r.b] == 2) {
                        if (--qh == -1)
                            qh = n - 1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    id8[r.b] = i;
                }
            }
        }


        if (d[t] == INF)  break;


        for (int v = t; v != s; v = p[v]) {


            int pv = p[v];
            size_t pr = id8[v], r = g[pv][pr].back;
            g[pv][pr].f += 1;
            g[v][r].f -= 1;
            cost += g[pv][pr].c;
        }
        ++flow;
    }
    return cost;
}
vector<int> vost[7];
vector<int> vval[101010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);






    int n;
    cin >> n;
    FI(n) {

        a[i + 1] = 1 + rand() % 100000;

        cin >> a[i + 1];

    }
    
    for (int i = n; i >= 1; --i) {
        id5(0, 2 * i - 1, 1, 0);
        id5(2 * i - 1, 2 * i, 1, -1);
        id5(2 * i, 2 * n + 1, 1, 0);
        
        int cur = 2 * i;
        for (auto& v : {vost[a[i] % 7], vval[a[i] - 1], vval[a[i] + 1]}) {


            for (int i = (int)v.size() - 1; i >= 0 && i >= (int)v.size() - 10; --i) {


                id5(cur, 2 * v[i] - 1, 1, 0);
            }
        }
        
        vost[a[i] % 7].push_back(i);
        vval[a[i]].push_back(i);


    }
    
    cout << -flow(n) << endl;
    
    
    CURTIME();
    return 0;
}


