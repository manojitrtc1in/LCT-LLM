





using namespace std;










































typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<int>> graph;




template<typename T> inline int checkbit(T n, T i){return ((n >> i) & T(1));}
inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<typename T> inline bool id0(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }

void bitprint(int n, int w=32){ for (int i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }
void bitprint(ll n, int w=64){ for (ll i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }


template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T id2(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=id2(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}


template <typename Collection, typename UnaryOperation> void foreach(Collection &col, UnaryOperation op){for_each(all(col), op);}
template <typename Collection, typename UnaryOperation> Collection fmap(Collection &col, UnaryOperation op){transform(all(col), col.begin(), op); return col;}
template <typename Collection, typename binop> Collection zip(Collection& fc, Collection& sc,binop op) {transform(all(fc), sc.begin(), fc.begin(), op); return fc;}
template <typename Collection, typename Condition> bool exists(Collection& col,Condition con) {auto exist = find_if(all(col), con); return exist != col.end();}
template <typename Collection, typename Predicate> Collection filterNot(Collection& col, Predicate predicate) {auto returnIterator = remove_if(all(col), predicate); col.erase(returnIterator, end(col)); return col;}



void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }
template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}
template<class T> inline void getarr(T* arr, int l, int r) { in_range(i, l, r) cin >> arr[i]; }



template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> inline void printarr(T* arr, int l, int r) { in_range(i, l, r) {cout << arr[i] << " ";}; cout << "\n"; }



template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }



template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }



template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::tensor(args...); }






























































template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };


template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }














































































































































inline void NO() {
    print("Impossible");
    exit(0);
}

const int MAXN = 2e4;
int lp[MAXN+1];
deque<int> primes;
void id1() {
    for (int i = 2; i <= MAXN; i++) {
        if (!lp[i]) { lp[i] = i; primes.pb(i); }
        for (int j = 0; j < sz(primes) && primes[j] <= lp[i] && 1LL*i*primes[j] <= MAXN; j++) {
            lp[i*primes[j]] = primes[j];
        }
    }
}

struct edge{
    int from, to;
    int next;
    int f, c;
};

int n, m;
int s, t;
int even = 0;
vector<edge> edges;
vector<int> head;
vector<int> a;
ostream& operator <<(ostream& out, const edge& e) {
    out << "[" << a[e.from] << " --> " << a[e.to] << ", " << e.f << ", " << e.c << "]";
    return out;
}

void add_edge(int a, int b, int c) {
    edges.pb({a, b, head[a], 0, c});
    edges.pb({b, a, head[b], 0, 0});
    head[a] = sz(edges)-2;
    head[b] = sz(edges)-1;
}

void read_network() {
    read(n), s = 0, t = n+1;
    if (n & 1) NO();
    head = vector<int>(n+2, -1);
    a = vector<int>(n+2);
    a[0] = -1, a[n+1] = -2;
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1) { add_edge(s, i, 2); }
        else { add_edge(i, t, 2); even++; }
    }
    if (even != n/2) NO();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i]%2 == 1 && a[j]%2 == 0 && lp[a[i]+a[j]] == a[i]+a[j]) {
                add_edge(i, j, 1);
            }
        }
    }
    n += 2, m = sz(edges);
}

vector<int> q;
vector<int> d;
vector<int> ptr;

bool bfs() {
    fill(all(d), INF);
    int qh = 0, qt = 0;
    q[qt++] = s;
    d[s] = 0;
    while (qh < qt) {
        int v = q[qh++];
        for (int i = head[v]; i != -1; i = edges[i].next) {
            edge &e = edges[i];
            if (e.f < e.c && d[e.to] > d[v]+1) {
                d[e.to] = d[v]+1;
                q[qt++] = e.to;
            }
        }
    }
    in_range(v, 0, n) ptr[v] = head[v];
    return d[t] < INF;
}

int push(int v, int flow) {
    if (v == t || !flow) return flow;
    for (int pushed; ptr[v] != -1; ptr[v] = edges[ptr[v]].next) {
        edge &e = edges[ptr[v]];
        if (d[e.to] != d[v]+1) continue;
        pushed = push(e.to, min(flow, e.c-e.f));
        if (pushed > 0) {
            e.f += pushed, edges[ptr[v]^1].f -= pushed;
            return pushed;
        }
    }
    return 0;
}

int max_flow() {
    id1();
    read_network();
    q = vector<int>(n, -1);
    ptr = vector<int>(n, -1);
    d = vector<int>(n, INF);
    int F = 0;
    while (bfs()) {
        while (int pushed = push(s, INF)) {
            F += pushed;
        }
    }
    return F;
}
inline bool inner(const edge& e) { return e.from != s && e.from != t && e.to != s && e.to != t; }
void min_cut() {
    int F = max_flow();
    if (F < 2*even) NO();


    graph G(n);
    for (int i = 0; i < m; i++) {
        edge &e = edges[i];


        if (inner(e) && (a[e.from]%2) && !(a[e.to]%2) && e.f > 0) {
            G[e.from].pb(e.to);
            G[e.to].pb(e.from);
        }
    }










    vector<int> used(n);
    vector<vector<int>> answer;
    vector<int> component;
    function<void(int)> extract_component = [&](int v){
        used[v] = 1;
        component.pb(v);
        for (auto &u : G[v]) if (!used[u])
            extract_component(u);
    };
    for (int i = 1; i <= n-2; i++) {
        if (!used[i]) {
            component.clear();
            extract_component(i);
            answer.pb(component);
        }
    }
    print(sz(answer));
    for (auto &table : answer) {
        print(sz(table), table);
    }
}
int main(){
    fastIO();




    min_cut();
    return 0;
}
