
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 


using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;





tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;



























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

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
    hi ++; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); 

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
    tcT> constexpr bool id11 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id1 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id10 = !id1<T> && id11<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id10<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id10<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id3 = !id2<T> && id11<T>;

    

    tcT> typename enable_if<id2<T>,str>::type ts(T v) {
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
    tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
        

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
    

    void ps() { cout << endl; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
    

    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, str names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void id13(const T& t) {
        cerr << "\n\n" << ts_sep(id6<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}

int N;
vi adj[MX];
int par[MX], depth[MX];
int dp_sub[MX], op_query_sub[MX];
int dp_without[MX], op_query_without[MX];

void dfs(int x) { 

    dp_sub[x] = 1; op_query_sub[x] = x;
    depth[x] = depth[par[x]]+1;
    vpi child_dp;
    each(y,adj[x]) if (y != par[x]) {
        par[y] = x;
        dfs(y);
        child_dp.pb({dp_sub[y],y});
    }
    sort(rall(child_dp));
    id4(i,sz(child_dp)) {
        ckmax(dp_sub[x],child_dp[i].f+i);
        if (i == 0) op_query_sub[x] = op_query_sub[child_dp[i].s];
    }
}

int id12(int x, int p) {
    assert(x && p);
    if (par[x] == p) {
        assert(op_query_sub[x]);
        return op_query_sub[x];
    } else {
        assert(par[p] == x);
        assert(op_query_without[p]);
        return op_query_without[p];
    }
}

void dfs2(int x) {
    dbg("DFS2",x);
    vpi child_dp;
    each(y,adj[x]) {
        if (y == par[x]) child_dp.pb({dp_without[x],y});
        else child_dp.pb({dp_sub[y],y});
    }
    sort(rall(child_dp));
    each(t,child_dp) assert(t.f);
    

    vi pref(sz(child_dp)+1);
    vi suf(sz(child_dp)+1);
    id4(i,sz(child_dp)) {
        pref[i+1] = max(pref[i],child_dp[i].f+i);
    }
    id7(i,sz(child_dp)) {
        suf[i] = max(suf[i+1],child_dp[i].f+i-1);
    }
    id4(i,sz(child_dp)) {
        int y = child_dp[i].s;
        if (y != par[x]) {
            dp_without[y] = max(pref[i],suf[i+1]);
            if (dp_without[y] == 0) {
                assert(x == 1 && sz(adj[x]) == 1);
                

                dp_without[y] = 1;
                op_query_without[y] = x;
            } else {
                if (i) op_query_without[y] = id12(child_dp[0].s,x);
                else {
                    assert(i+1 < sz(child_dp));
                    op_query_without[y] = id12(child_dp[1].s,x);
                }
            }
            

            assert(dp_without[y]);
            dfs2(y);
        }
    }
}

int queries_left;

int query(int i) {
    assert(queries_left);
    --queries_left;
    ps("?",i);
    ints(x); 
    rtn x;
}

void finish(int ans) {
    ps("!",ans);
    exit(0);
}

vpi id8(int x) {
    vpi adj_dp;
    each(y,adj[x]) {
        if (y == par[x]) adj_dp.pb({dp_without[x],y});
        else adj_dp.pb({dp_sub[y],y});
    }
    sort(rall(adj_dp));
    return adj_dp;
}

vpi id0(int x) { 

    vpi adj_dp;
    each(y,adj[x]) {
        if (y == par[x]) adj_dp.pb({dp_without[x],y});
        else adj_dp.pb({dp_sub[y],y});
    }
    sort(rall(adj_dp));
    each(t,adj_dp) {
        swap(t.s,t.f);
        t.s = id12(t.f,x);
    }
    return adj_dp;
}

vi endpoints;

vb marked;














vi path_to(int a, int b) {
    vi st, en;
    while (a != b) {
        if (depth[a] > depth[b]) {
            st.pb(a);
            a = par[a];
        } else {
            en.pb(b);
            b = par[b];
        }
    }
    st.pb(b);
    reverse(all(en));
    st.ins(end(st),all(en));
    return st;
}

void id9(int x, int p) {
    assert(marked.at(p));
    auto deal_path = [&](int y, int z) {
        

        vi path = path_to(y,x);
        int ind = 0;
        while (path.at(ind) != z) ++ind;
        x = path.at(ind);
        if (ind) marked[path.at(ind-1)] = 1;
        if (ind+1 < sz(path)) marked[path.at(ind+1)] = 1;
    };
    {
        int y = id12(x,p);
        int z = query(y); if (z == p) return;
        deal_path(y,z);
    }
    while (1) {
        assert(!marked.at(x));
        vpi cands;
        {
            vpi queries = id0(x);
            each(t,queries) if (!marked.at(t.f)) cands.pb(t);
        }
        dbg("FOUND",x,cands);
        bool found = 0;
        each(t,cands) {
            int y = t.s; int z = query(y);
            if (z == x) continue;
            deal_path(y,z);
            found = 1;
            break;
        }
        if (found) continue;
        endpoints.pb(x); return;
    }
}

void solve(int f) {
    vpi v = id8(f);
    each(t,v) {
        id9(t.s,f);
        if (sz(endpoints) == 2) break;
    }
    while (sz(endpoints) < 2) endpoints.pb(f);
    ps("!",endpoints[0],endpoints[1]);
}

int main() {
    re(N);
    rep(N-1) {
        ints(u,v);
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(1);
    dfs2(1);
    int ans = 0;
    FOR(x,1,N+1) {
        vpi adj_dp = id8(x);
        id4(i,sz(adj_dp)) {
            ckmax(ans,adj_dp[i].f+i);
            if (i > 0) ckmax(ans,adj_dp[i].f+i+adj_dp[0].f-1);
        }
    }
    

    ps(ans);
    ints(f);
    marked = vb(N+1);
    marked.at(f) = 1;
    queries_left = ans;
    solve(f);
    

}


