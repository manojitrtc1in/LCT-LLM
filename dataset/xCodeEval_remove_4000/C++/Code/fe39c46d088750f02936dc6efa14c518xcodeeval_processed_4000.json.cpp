
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










const int MOD = 998244353;
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
constexpr int id7(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id15 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id4 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id13 = !id1<T> && id15<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id13<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id13<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id5 = !id4<T> && id15<T>;

    

    tcT> typename enable_if<id4<T>,str>::type ts(T v) {
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
    tcT> typename enable_if<id15<T>,str>::type ts_sep(T v, str sep) {
        

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
      id9(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id5<T>,vs>::type 
      id9(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id9<lev-1>(t);
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
    template<int lev, class T> void id16(const T& t) {
        cerr << "\n\n" << ts_sep(id9<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}

const int mx = 105;


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





template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } 

    int v; explicit operator int() const { return v; } 

    mint() { v = 0; }
    mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend void re(mint& a) { ll x; re(x); a = mint(x); }
    friend str ts(mint a) { return ts(a.v); }
   
    mint& operator+=(const mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& m) { 
        v = int((ll)v*m.v%MOD); return *this; }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mint inv(const mint& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; 

typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; 

void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) id6(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



vmi invs, fac, ifac; 

void genFac(int SZ) {
    invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FOR(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
    FOR(i,1,SZ) {
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1]*invs[i];
    }
}
mi comb(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac[a]*ifac[b]*ifac[a-b];
}

typedef bitset<mx> B;

const B B_ZERO;
B B_FULL;

void id14(vector<B>& v){
    vector<B> new_v;
    for(auto b: v){
        bool already_in = 0;
        for(auto in: new_v){
            if(b == in) already_in = 1;
        }

        if(!already_in) new_v.pb(b);
    }

    v = new_v;
}

int n, m;
vector<B> friends;

DSU dsu;
vi comp_adj[mx];
vi comp_nodes[mx];




B comp_P[mx];
int par[mx]; 

vi children[mx]; 


bool isAncestor(int C, int D){ 

    assert(C != D);
    if((comp_P[D]&comp_P[C]) == comp_P[D]){
        if(comp_P[D] == comp_P[C]){
            if(sz(comp_nodes[C]) == 1) return true;
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}

bool visited[mx];
vi order;
void buildOrder(int node){
    visited[node] = 1;
    order.pb(node);
    for(auto u: comp_adj[node]){
        if(visited[u]) continue;
        buildOrder(u);
    }
}

bool id8(vi a){
    assert(sz(a));
    for(int i = 0; i+1 < sz(a); i++){
        if(a[i]+1 != a[i+1]) return false;
    }
    return true;
}

int main() {
    setIO();
    
    genFac(100005);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        B_FULL[i] = 1;
    }

    for(int i = 1; i <= m; i++){
        B b;
        int qi;
        cin >> qi;
        for(int j = 1; j <= qi; j++){
            int s;
            cin >> s;
            b[s] = 1;
        }
        friends.pb(b);
    }
    B full; for(int i = 1; i <= n; i++) full[i] = 1;
    friends.pb(full);
    id14(friends);
    m = sz(friends);

    dbg(m, friends);

    dsu.init(m);
    vpi edges;
    vpi tree_edges;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            B isect = friends[i]&friends[j];
            if(isect != B_ZERO && isect != friends[i] && isect != friends[j]){
                

                edges.pb(mp(i, j));
                if(dsu.unite(i, j)){
                    tree_edges.pb(mp(i, j));
                }
            }
        }
    }

    for(auto u: edges){
        comp_adj[u.f].pb(u.s);
        comp_adj[u.s].pb(u.f);
    }
    

    

    

    

    

    


    for(int i = 0; i < m; i++){
        comp_nodes[dsu.get(i)].pb(i);
        comp_P[dsu.get(i)]|=friends[i];
    }

    for(int i = 0; i < m; i++){
        dbg(i, comp_nodes[i], comp_P[i]);
    }

    int R = -1;
    for(int i = 0; i < m; i++){
        if(dsu.get(i) != i) continue;
        

        par[i] = -1;
        for(int j = 0; j < m; j++){
            if(dsu.get(j) != j) continue;
            if(j == i) continue;
            if(!isAncestor(j, i)) continue;
            if(par[i] != -1 && isAncestor(j, par[i])) continue;

            par[i] = j;
        }

        if(par[i] == -1){
            assert(R == -1);
            R = i;
        }
    }

    assert(R != -1);

    for(int i = 0; i < m; i++){
        if(dsu.get(i) != i) continue;
        if(i == R) continue;
        children[par[i]].pb(i);
    }

    mi ans = mi(1);

    for(int i = 0; i < m; i++){
        if(dsu.get(i) != i) continue;
        dbg("COMPONENT", i);
        order.clear();
        buildOrder(i);

        assert(sz(order));

        vector<B> Z(2); 

        Z[1] = friends[order[0]];

        dbg(order);
        for(int j = 1; j < sz(order); j++){
            int k = sz(Z)-1;
            B S = friends[order[j]];
            vi I;
            vi id0;

            B Z0 = S;
            for(int w = 1; w <= k; w++){
                Z0 = (Z0&(B_FULL^Z[w]));
            }

            dbg(Z, S);
            dbg(Z0);


            for(int w = 1; w <= k; w++){
                B id12 = Z[w]&S;
                B id2 = Z[w]^id12;
                if(id12 != B_ZERO){
                    id0.pb(w);
                    if(id2 != B_ZERO){
                        I.pb(w);
                    }
                }
            }
            assert(sz(id0));

            

            


            if(!id8(id0)){
                ps(0);
                dbg("CASE1");
                exit(0);
            }

            if(sz(I) == 0){
                

                if(Z0 != B_ZERO){
                    if(id0[0] == 1){ 

                        assert(id0.bk != k);
                        vector<B> new_Z(1);
                        new_Z.pb(Z0);
                        for(int i = 1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else if(id0.bk == k){ 

                        Z.pb(Z0);
                    }
                    else{
                        ps(0);
                        dbg("CASE2");
                        exit(0);
                    }
                }
                else{
                    

                }
            }
            else if(sz(I) >= 3){
                ps(0);
                dbg("CASE3");
                exit(0);
            }
            else if(sz(I) == 2){
                if(Z0 != B_ZERO){
                    ps(0);
                    dbg("CASE4");
                    exit(0);
                }
                if(id0[0] == I[0] && id0.bk == I[1]){
                    int l = I[0];
                    int r = I[1];
                    B Zlp = Z[l]&S;
                    B id11 = Z[l]^Zlp;
                    B Zrp = Z[r]&S;
                    B id10 = Z[r]^Zrp;

                    vector<B> new_Z(1);
                    for(int i = 1; i <= l-1; i++){
                        new_Z.pb(Z[i]);
                    }
                    new_Z.pb(id11); new_Z.pb(Zlp);
                    for(int i = l+1; i <= r-1; i++){
                        new_Z.pb(Z[i]);
                    }
                    new_Z.pb(Zrp); new_Z.pb(id10);
                    for(int i = r+1; i <= k; i++){
                        new_Z.pb(Z[i]);
                    }
                    Z = new_Z;
                }
                else{
                    ps(0);
                    dbg("CASE5");
                    exit(0);
                }
            }
            else if(sz(I) == 1){
                if(Z0 != B_ZERO){
                    

                    int t = I[0];
                    if(id0.bk == t && id0[0] == 1){
                        vector<B> new_Z(1);
                        B Ztp = Z[t]&S;
                        B id3 = Z[t]^Ztp;

                        new_Z.pb(Z0);
                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Ztp); new_Z.pb(id3);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else if(id0[0] == t && id0.bk == k){
                        vector<B> new_Z(1);
                        B Ztp = Z[t]&S;
                        B id3 = Z[t]^Ztp;

                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(id3); new_Z.pb(Ztp);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Z0);
                        Z = new_Z;
                    }
                    else{
                        ps(0);
                        dbg("CASE6");
                        exit(0);
                    }
                }
                else{
                    

                    int t = I[0];
                    B Ztp = Z[t]&S;
                    B id3 = Z[t]^Ztp;
                    assert(id0[0] < t || id0.bk > t);

                    if(id0[0] < t && id0.bk == t){
                        vector<B> new_Z(1);

                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Ztp); new_Z.pb(id3);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else if(id0.bk > t && id0[0] == t){
                        vector<B> new_Z(1);

                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(id3); new_Z.pb(Ztp);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else{
                        ps(0);
                        exit(0);
                    }
                }
            }
        }

        


        

        if(sz(order) == 1){
            ans*=mi(1);
        }
        else{
            ans*=mi(2);
        }

        

        for(int w = 1; w < sz(Z); w++){
            B E = Z[w];
            int fact_num = E.count();
            for(auto D: children[i]){
                if((comp_P[D]&E) == comp_P[D]){
                    fact_num-=(comp_P[D].count()-1);
                }
            }
            assert(fact_num >= 0);
            

            ans*=fac[fact_num];
        }
    }

    ps(ans);

    

}


