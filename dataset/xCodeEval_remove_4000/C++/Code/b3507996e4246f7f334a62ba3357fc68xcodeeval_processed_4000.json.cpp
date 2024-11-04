































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
inline bool id3(int x){ return (x != 0 && (x&(x - 1)) == 0); }
template<class T1, class T2, class T3> T1 inline clamp(T1 x, const T2& a, const T3& b) { if (x < a) return a; else if (x > b) return b; else return x; }
unsigned long long id6() {

    return 0;

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








template<class T> inline void normmod(T &x, T m) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 id1(T1 x, T1 y, T2 m) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3> inline void id5(T1 &x, T2 y, T3 m) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3> inline void id0(T1 &x, T2 y, T3 m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll r = 0; normmod(x, m); normmod(n, m); while (n) { if (n & 1) id5(r, x, m); id5(x, x, m); n /= 2; } return r; }
inline ll id9(ll x, ll n, ll m){ ll r = 0; while (n){ if (n & 1) id5(r, x, m); id5(x, x, m); n /= 2; } return r; }
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
template<class T> bool isPrime(T x) { if (x < 2) return 0; for (T i = 2; i * i <= x; ++i) if (x % i == 0) return 0; return 1; }
bool id7(long long n) {
    if (n <= 2) return n == 2;
    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) { if (a >= n) return a == n;
        long long f = id2(a, s, n); if (f == 1 || f == n - 1) continue;
        for (int i = 1; i < t; ++i) if ((f = id9(f, f, n)) == n - 1) goto nextp;
        return false; nextp:;
    } return true;
}
















int dp[606][606];
int a[202];
vector<pii> v[1731311];
vector<int> who[666];
int par[606];
int with[606];

const int MAXN = 1202;
struct edge {
    int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
            to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
        to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}
bool used[606];
void join(int x, int y) {
    with[x] = y;
    par[y] = x;
}
bool id8(int cur) {
    if (used[ cur]) return false;
    used[cur] = true;
    for (int to : g[cur]) {
        if (par[to] == -1 || id8(par[to])) {
            join(cur, to);
            return true;
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);






    int n, m, c, k;
    cin >> n >> m >> c >> k;
    FI(n) { FJ(n) {
        dp[i][j] = INF;
    }
        dp[i][i] = 0;
    }
    FI(c) {
        cin >> a[i];
        --a[i];
        who[a[i]].push_back(i);
    }
    FI(m) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        dp[x][y] = dp[y][x] = min(dp[y][x], w);
    }
    FK(n) {
        FI(n) {
            for (int j = 0; j < i; ++j) {
                dp[i][j] = dp[j][i] = min(dp[k][i] + dp[k][j], dp[i][j]);
            }
        }
    }
    vector<tri> qq;
    FI(n) {
        FJ(n) {
            if (!who[i].empty() && dp[i][j] < INF) {
                qq.push_back({dp[i][j], i, j});


            }


        }


    }






    int l = 0;
    int r = 1731312;
    while (l < r) {
        int m = (l + r) / 2;
        e.clear();
        FI(MAXN) g[i].clear();
        ::s = 0;
        ::t = 1 + n + n;
        ::n = ::t + 1;
        FI(n) {
            FJ(n) {
                if (dp[i][j] <= m) {
                    add_edge(1 + i, 1 + n + j, 1);
                }
            }
        }
        FI(n) {
            add_edge(0, 1 + i, (int)who[i].size());
        }
        FI(n) {
            add_edge(1 + n + i, ::t, 1);
        }
        if (dinic() >= k) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (l == 1731312) {
        l = -1;
    }
    cout << l << endl;
    return 0;
}


