





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
template<typename T> inline T id1(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=id1(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
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














































































































































struct Edge {
    int from, to;
    int f;
    int c;
};

int main(){






    int n, q;
    read(n, q);
    vector<int> vals(n+1);
    for (int i = 1; i <= n; i++)
        read(vals[i]);

    auto good = tensor<int>(n+1, n+1);
    while (q--) {
        int i, j;
        read(i, j);
        if (i % 2 == 0) swap(i, j);
        good[i][j] = 1;
    }

    auto factorize = [](int x) {
        vector<pii> f;
        for (int i = 2; 1LL*i*i <= x; i++) {
            if (x % i == 0) {
                int alpha = 0;
                while (x % i == 0) {
                    x /= i;
                    alpha++;
                }
                f.emplace_back(i, alpha);
            }
        }
        if (x != 1)
            f.emplace_back(x, 1);
        return f;
    };

    vector<Edge> edges;
    graph G(100001);
    auto add_edge = [&](int a, int b, int c) {
        G[a].push_back(sz(edges));
        edges.push_back({a, b, 0, c});
        G[b].push_back(sz(edges));
        edges.push_back({b, a, 0, 0});
    };

    int cnt = 1;
    vector<pii> data;
    data.emplace_back(-1, -1);

    for (int i = 1; i <= n; i+=2) {
        auto f = factorize(vals[i]);
        for (auto p : f) {
            add_edge(0, cnt++, p.scd);
            data.emplace_back(i, p.fst);
        }
    }

    for (int i = 2; i <= n; i+=2) {
        auto f = factorize(vals[i]);
        for (auto p : f) {
            add_edge(cnt++, 10000, p.scd);
            data.emplace_back(i, p.fst);
        }
    }

    int s = 0, t = 10000;
    n = t+1;
    vector<int> d(1<<20, -1);
    vector<int> ptr(1<<20);
    auto bfs = [&](){
        vector<int> Q(1<<20);
        fill(all(d), -1);
        int qh = 0, qt = 0;
        Q[qt++] = s;
        d[s] = 0;
        while (qh < qt && d[t] == -1) {
            int v = Q[qh++];
            for (auto u : G[v]) {
                int to = edges[u].to;


                if (d[to] == -1 && edges[u].f < edges[u].c) {
                    Q[qt++] = to;
                    d[to] = d[v]+1;
                }
            }
        }
        return d[t] != -1;
    };
    function<int(int, int)> push = [&](int v, int flow) {
        if (!flow || v == t) return flow;
        for (; ptr[v] < sz(G[v]); ++ptr[v]) {
            int id = G[v][ptr[v]];
            int to = edges[id].to;
            if (d[to] != d[v]+1) continue;
            int pushed = push(to, min(flow, edges[id].c-edges[id].f));
            if (pushed) {
                edges[id].f += pushed;
                edges[id^1].f -= pushed;
                return pushed;
            }
        }
        return 0;
    };
    auto dinic = [&](){
        int flow = 0;
        while (bfs()) {


            while (int pushed = push(s, INF))
                flow += pushed;
            fill(all(ptr), 0);
        }
        return flow;
    };
    for (int i = 1; i < cnt; i++) {
        for (int j = 1; j < cnt; j++) {
            if (good[data[i].fst][data[j].fst] &&
                data[i].scd == data[j].scd) {
                    add_edge(i, j, 10000);


            }
        }
    }
    print(dinic());
    return 0;
}
