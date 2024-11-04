
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;



















tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const ll INF = 1e18;
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id5(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } 


tcTU> T fstTrue(T lo, T hi, U f) {
    ++hi; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    --lo; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } 




inline namespace Helpers {
    

    

    

    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool id8 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id0 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id1 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id7 = !id0<T> && id8<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id7<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id7<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


    

    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.rsz(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }

    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
}

inline namespace ToString {
    tcT> constexpr bool id3 = !id1<T> && id8<T>;

    

    tcT> typename enable_if<id1<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id4(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id3<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id8<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id3<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id3<T>,vs>::type 
      id6(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id3<T>,vs>::type 
      id6(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id6<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id4(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.bk += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
    

    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, str names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void id9(const T& t) {
        cerr << "\n\n" << ts_sep(id6<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

    const clock_t beg = clock();
    
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}




struct MCMF { 
    using F = ll; using C = ll; 

    struct Edge { int to, rev; F flo, cap; C cost; };
    int N; V<C> p, dist; vpi pre; V<V<Edge>> adj;
    void init(int _N) { N = _N;
        p.rsz(N), adj.rsz(N), dist.rsz(N), pre.rsz(N); }
    void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
        adj[u].pb({v,sz(adj[v]),0,cap,cost}); 
        adj[v].pb({u,sz(adj[u])-1,0,0,-cost});
    } 

    bool path(int s, int t) { 

        const C inf = numeric_limits<C>::max(); dist.assign(N,inf);
        using T = pair<C,int>;
        priority_queue<T,V<T>,greater<T>> todo; 
        todo.push({dist[s] = 0,s}); 
        while (sz(todo)) { 

            T x = todo.top(); todo.pop(); 
            if (x.f > dist[x.s]) continue;
            each(e,adj[x.s]) { 

                if (e.flo < e.cap && ckmin(dist[e.to],
                        x.f+e.cost+p[x.s]-p[e.to]))
                    pre[e.to]={x.s,e.rev}, todo.push({dist[e.to],e.to});
            }
        } 

        

        return dist[t] != inf; 

    }
    pair<F,C> calc(int s, int t) { assert(s != t);
        id4(_,N) id4(i,N) each(e,adj[i]) 

            if (e.cap) ckmin(p[e.to],p[i]+e.cost);
        F totFlow = 0; C totCost = 0;
        while (path(s,t)) { 

            id4(i,N) p[i] += dist[i]; 

            F df = numeric_limits<F>::max();
            for (int x = t; x != s; x = pre[x].f) {
                Edge& e = adj[pre[x].f][adj[x][pre[x].s].rev]; 
                ckmin(df,e.cap-e.flo); }
            if(p[t]-p[s] >= 0) break;
            totFlow += df; totCost += (p[t]-p[s])*df;
            for (int x = t; x != s; x = pre[x].f) {
                Edge& e = adj[x][pre[x].s]; e.flo -= df;
                adj[pre[x].f][e.rev].flo += df;
            }
        } 

        return {totFlow,totCost};
    }
};



template<int SZ> struct BellmanFord {
    int n;
    vi adj[SZ];
    V<pair<pi,int>> ed;
    void ae(int u, int v, int w) { 
        adj[u].pb(v), ed.pb({{u,v},w}); }
    ll dist[SZ];
    void genBad(int x) { 
        

        

        if (dist[x] == -INF) return;
        dist[x] = -INF; 
        each(t,adj[x]) genBad(t);
    }
    void init(int _n, int s) {
        n = _n; id4(i,n) dist[i] = INF; 
        dist[s] = 0;
        id4(i,n) each(a,ed) if (dist[a.f.f] < INF)
            ckmin(dist[a.f.s],dist[a.f.f]+a.s);
        each(a,ed) if (dist[a.f.f] < INF 
                    && dist[a.f.s] > dist[a.f.f]+a.s) 
            genBad(a.f.s);
    }
};

const int mx = 100005;
int a[mx];
int u[mx];
int v[mx];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i];
    }

    MCMF id2;
    id2.init(n+5);
    for(int i = 1; i <= m; i++){
        id2.ae(u[i], v[i], MOD, 0);
    }
    for(int i = 1; i <= n; i++){
        id2.ae(n+1, i, 1, -a[i]);
        id2.ae(i, n+2, 1, +a[i]);
    }

    ll cost = id2.calc(n+1, n+2).s;

    BellmanFord<mx> bf;

    for(int i = 1; i <= n+2; i++){
        for(auto x: id2.adj[i]){
            

            if(x.flo < x.cap){
                bf.ae(i, x.to, int(x.cost));
            }
        }
    }

    bf.init(n+3, n+1);

    

    for(int i = 1; i <= n; i++){
        cout << -bf.dist[i] << " ";
    }
    cout << "\n";

    

}

