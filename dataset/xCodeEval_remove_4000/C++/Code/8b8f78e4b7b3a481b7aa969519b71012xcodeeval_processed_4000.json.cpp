
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

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id7(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id13 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id2 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id3 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id12 = !id2<T> && id13<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id2<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id12<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id12<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id5 = !id3<T> && id13<T>;

    

    tcT> typename enable_if<id3<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id6(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id5<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id13<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id5<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id5<T>,vs>::type 
      id8(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id5<T>,vs>::type 
      id8(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id8<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id6(i,sz(res)) {
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
    template<int lev, class T> void id14(const T& t) {
        cerr << "\n\n" << ts_sep(id8<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

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



struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { 

        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};





template<int SZ> struct UnweightedMatch {
    int match[SZ], N; vi adj[SZ];
    void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
    queue<int> q;
    int par[SZ], vis[SZ], orig[SZ], aux[SZ];
    void augment(int u, int v) { 

        while (1) { 

            int pv = par[v], nv = match[pv];
            match[v] = pv; match[pv] = v;
            v = nv; if (u == pv) return;
        }
    }
    int lca(int u, int v) { 

        static int t = 0;
        for (++t;;swap(u,v)) {
            if (!u) continue;
            if (aux[u] == t) return u; 

            aux[u] = t; u = orig[par[match[u]]];
        }
    }
    void blossom(int u, int v, int a) { 

        for (; orig[u] != a; u = par[v]) { 

            par[u] = v; v = match[u]; 

            if (vis[v] == 1) vis[v] = 0, q.push(v);
            orig[u] = orig[v] = a; 

        }
    }
    bool bfs(int u) { 

        id6(i,N+1) par[i] = 0, vis[i] = -1, orig[i] = i;
        q = queue<int>(); vis[u] = 0, q.push(u);
        while (sz(q)) { 

            int v = q.ft; q.pop(); 

            each(x,adj[v]) {
                if (vis[x] == -1) { 

                    vis[x] = 1; par[x] = v;
                    if (!match[x]) return augment(u,x),1;
                    vis[match[x]] = 0, q.push(match[x]);
                } else if (vis[x] == 0 && orig[v] != orig[x]) {
                    int a = lca(orig[v],orig[x]); 

                    blossom(x,v,a), blossom(v,x,a); 
                } 

            }
        }
        return 0;
    }
    int calc(int _N) { 

        N = _N; id6(i,N+1) match[i] = aux[i] = 0; 
        int ans = 0; vi V(N); iota(all(V),1); shuffle(all(V),rng); 

        each(x,V) if (!match[x]) each(y,adj[x]) if (!match[y]) { 
            match[x] = y, match[y] = x; ++ans; break; }
        FOR(i,1,N+1) if (!match[i] && bfs(i)) ++ans;
        return ans;
    }
};

const int mx = 300005;

int n;
int a[mx];

vpi id0;
vpi tree_adj[mx];

void fillTree(int node, int p = -1){
    for(auto u: tree_adj[node]){
        if(u.f == p) continue;
        if(a[id0[u.s].f-1] == u.f){
            a[id0[u.s].f] = u.f;
        }
        else{
            assert(a[id0[u.s].s+1] == u.f);
            a[id0[u.s].s] = u.f;
        }
        fillTree(u.f, node);
    }
}

void id1(){
    set<int> eq_vals;
    for(int i = 1; i+1 <= n; i++){
        if(a[i] != 0 && a[i] == a[i+1]){
            eq_vals.insert(a[i]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            int L = i;
            int R = i;
            for(int j = i; j <= n; j++){
                if(a[j] == 0){
                    R = j;
                }
                else{
                    break;
                }
            }
            id0.pb(mp(L, R));
            i = R;
        }
    }

    for(int i = 0; i < sz(id0); i++){
        set<int> good_vals;
        if(!eq_vals.count(a[id0[i].f-1])){
            good_vals.insert(a[id0[i].f-1]);
        }
        if(!eq_vals.count(a[id0[i].s+1])){
            good_vals.insert(a[id0[i].s+1]);
        }
        assert(sz(good_vals) == 2);
    }

    int max_val = 0;
    for(auto u: id0){
        ckmax(max_val, a[u.f-1]);
        ckmax(max_val, a[u.s+1]);
    }
    assert(max_val <= 600);

    DSU dsu;
    dsu.init(max_val+5);

    vi cycle_edges;
    vb id9;
    for(int i = 0; i < sz(id0); i++){
        if((id0[i].s-id0[i].f+1) % 2 == 1){
            id9.pb(true);
        }
        else{
            id9.pb(false);
        }
    }

    for(int i = 0; i < sz(id0); i++){
        if(!id9[i]) continue;
        int v1 = a[id0[i].f-1];
        int v2 = a[id0[i].s+1];
        if(dsu.unite(v1, v2)){
            tree_adj[v1].pb(mp(v2, i));
            tree_adj[v2].pb(mp(v1, i));
        }
        else{
            cycle_edges.pb(i);
        }
    }

    vb comp_done(max_val+5, false);

    for(auto u: cycle_edges){
        int v1 = a[id0[u].f-1];
        if(comp_done[dsu.get(v1)]) continue;
        comp_done[dsu.get(v1)] = true;
        a[id0[u].f] = v1;
        fillTree(v1);
    }

    UnweightedMatch<605> um;
    map<pi, int> range_ind;

    for(int i = 0; i < sz(id0); i++){
        if(id9[i]) continue;
        int v1 = dsu.get(a[id0[i].f-1]);
        int v2 = dsu.get(a[id0[i].s+1]);

        if(v1 == v2 || comp_done[v1] || comp_done[v2]) continue;
        
        um.ae(v1, v2);
        range_ind[mp(v1, v2)] = i;
        range_ind[mp(v2, v1)] = i;
    }

    um.calc(max_val+1);

    for(int i = 1; i <= max_val; i++){
        if(um.match[i] > i){
            assert(um.match[um.match[i]] == i);
            int id4 = range_ind[mp(i, um.match[i])];
            int v1 = a[id0[id4].f-1];
            int v2 = a[id0[id4].s+1];
            a[id0[id4].f] = v1;
            a[id0[id4].s] = v2;
            comp_done[dsu.get(v1)] = true;
            comp_done[dsu.get(v2)] = true;
            fillTree(v1);
            fillTree(v2);
        }
    }

    for(int i = 1; i <= max_val; i++){
        if(dsu.get(i) == i && !comp_done[i]){
            fillTree(i);
        }
    }
}

void ERASE(set<int>& s, int v){
    if(s.count(v)) s.erase(v);
}

set<int> remain;

void fillRest(int L = 1, int R = n){
    for(int i = L; i <= R; i++){
        if(a[i] == 0){
            assert(sz(remain));
            int v = *(remain.begin());
            if(i+1 <= R && a[i+1] == 0){
                a[i] = a[i+1] = v;
                ERASE(remain, v);
            }
            else{
                a[i] = v;
                ERASE(remain, v);
            }
        }
        
    }
}

void PRINT(){
    for(int i = 1; i <= n; i++){
        

        if(a[i] == 0){
            dbg("ZERO IN ARRAY");
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}



int main() {
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        remain.insert(i);
    }
    for(int i = 1; i <= n; i++){
        ERASE(remain, a[i]);
    }

    bool all_zero = true;
    for(int i = 1; i <= n; i++){
        if(a[i] != 0){
            all_zero = false;
        }
    }

    if(all_zero){
        fillRest();
        PRINT();
        exit(0);
    }

    if(a[1] == 0){
        int last_ind = 1;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0){
                last_ind = i;
            }
            else{
                break;
            }
        }
        if(last_ind % 2 == 1){
            a[last_ind] = a[last_ind+1];
        }
        fillRest(1, last_ind);
    }

    

    if(a[n] == 0){
        int last_ind = n;
        for(int i = n; i >= 1; i--){
            if(a[i] == 0){
                last_ind = i;
            }
            else{
                break;
            }
        }
        if((n+1-last_ind) % 2 == 1){
            a[last_ind] = a[last_ind-1];
        }
        fillRest(last_ind, n);
    }
    


    vpi LR;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            int L = i;
            int R = i;
            for(int j = i; j <= n; j++){
                if(a[j] == 0){
                    R = j;
                }
                else{
                    break;
                }
            }
            LR.pb(mp(L, R));
            i = R;
        }
    }

    vb id11(sz(LR), false);
    map<int, vi> val_check;
    for(int i = 0; i < sz(LR); i++){
        val_check[a[LR[i].f-1]].pb(i);
        val_check[a[LR[i].s+1]].pb(i);
    }

    queue<int> q_check;
    set<int> eq_vals;

    auto id10 = [&](int v){
        eq_vals.insert(v);
        while(sz(val_check[v])){
            q_check.push(val_check[v].bk); val_check[v].pop_back();
        }
    };

    for(int i = 1; i+1 <= n; i++){
        if(a[i] == a[i+1] && a[i] != 0){
            id10(a[i]);
        }
    }

    for(int i = 0; i < sz(LR); i++){
        if(a[LR[i].f-1] == a[LR[i].s+1]){
            q_check.push(i);
        }
    }

    while(sz(q_check)){
        int ind = q_check.front(); q_check.pop();
        if(id11[ind]) continue;

        set<int> good_vals;
        if(!eq_vals.count(a[LR[ind].f-1])){
            good_vals.insert(a[LR[ind].f-1]);
        }
        if(!eq_vals.count(a[LR[ind].s+1])){
            good_vals.insert(a[LR[ind].s+1]);
        }

        assert(sz(good_vals) <= 1);
        

        id11[ind] = 1;
        if((LR[ind].s-LR[ind].f+1) % 2 == 0){
            fillRest(LR[ind].f, LR[ind].s);
        }
        else{
            if(eq_vals.count(a[LR[ind].f-1])){
                a[LR[ind].s] = a[LR[ind].s+1];
            }
            else{
                assert(eq_vals.count(a[LR[ind].s+1]) || a[LR[ind].f-1] == a[LR[ind].s+1]);
                a[LR[ind].f] = a[LR[ind].f-1];
            }

            fillRest(LR[ind].f, LR[ind].s);

            id10(a[LR[ind].f-1]);
            id10(a[LR[ind].s+1]);
        }
    }

    id1();

    fillRest();
    PRINT();
    

    

}


