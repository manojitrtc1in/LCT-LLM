
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
constexpr int id12(int x) { return p2(x)-1; }
 
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
    tcT> constexpr bool id19 = is_iterable<T>::value;
 
    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id3 = is_readable<T>::value;
 
    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id6 = is_printable<T>::value;
}
 
inline namespace Input {
    tcT> constexpr bool id18 = !id3<T> && id19<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 

 
    

    tcT> typename enable_if<id3<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id18<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id18<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id8 = !id6<T> && id19<T>;
 
    

    tcT> typename enable_if<id6<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id11(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id8<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id19<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id8<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }
 
    

    template<int, class T> typename enable_if<!id8<T>,vs>::type 
      id13(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id8<T>,vs>::type 
      id13(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id13<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id11(i,sz(res)) {
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
    template<int lev, class T> void id20(const T& t) {
        cerr << "\n\n" << ts_sep(id13<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    
}
 
inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}
 
const int mx = 200005;
const int VAL_BLOCK = sqrt(mx);
const int POS_BLOCK = sqrt(mx);




 
int n, m;
int a[mx];
int b[mx];
int c[mx];
int typ[mx];
int k[mx];
int x[mx];
int r[mx];
 
int val_cnt[mx];
bool big_val[mx];
 
void id17(){
    for(int i = 1; i <= n; i++){
        val_cnt[a[i]]++;
        val_cnt[b[a[i]]]++;
        val_cnt[c[a[i]]]++;
    }
 
    for(int i = 1; i <= m; i++){
        val_cnt[x[i]]++;
        val_cnt[b[x[i]]]++;
        val_cnt[c[x[i]]]++;
    }
 
    for(int i = 1; i <= n; i++){
        if(val_cnt[i] > VAL_BLOCK){
            big_val[i] = 1;
        }
    }
}
 
struct id15{
    ll trips[mx];
    ll block_sums[mx];
 
    id15(){
        for(int i = 0; i < mx; i++){
            trips[i] = block_sums[i] = 0;
        }
    }
 
    void update(int pos, ll val){ 

        trips[pos]+=val;
        int L = (pos-1)/POS_BLOCK*POS_BLOCK+1;
        int R = L+POS_BLOCK-1;
        if(R <= n){
            block_sums[R]+=val;
            

            

            

            

        }
    }
 
    ll query(int pos){
        ll res = 0;
 
        int cur_ind = 0; 

 
        while(true){
            if(cur_ind+POS_BLOCK <= pos){
                cur_ind+=POS_BLOCK;
                res+=block_sums[cur_ind];
                continue;
            }
            for(int i = cur_ind+1; i <= pos; i++){
                res+=trips[i];
            }
            break;
        }
 
        return res;
    }
};
 
bool get_unique_aux[mx];
 
vi getUnique(const vi& a){
    for(const auto& u: a){
        get_unique_aux[u] = 0;
    }
    vi res;
    for(const auto& u: a){
        if(get_unique_aux[u] == 0){
            get_unique_aux[u] = 1;
            res.pb(u);
        }
    }
    return res;
}
 
id15 bt;
 
vi val_poses[mx]; 

vector<pair<int, ll>> cur_inside[mx]; 

 
void vectorRemove(vi& a, int b){
    for(int i = 0; i < sz(a); i++){
        if(a[i] == b){
            a.erase(a.begin()+i);
            return;
        }
    }
}
 
void vectorAdd(vi& a, int b){
    if(sz(a) == 0){
        a.pb(b);
    }
    else if(b < a[0]){
        a.insert(a.begin()+0, b);
    }
    else if(b > a.bk){
        a.pb(b);
    }
    else{
        for(int i = 0; i+1 < sz(a); i++){
            if(a[i] < b && b < a[i+1]){
                a.insert(a.begin()+i+1, b);
            }
        }
    }
}
 
void id5(int v){
    for(const auto&u: cur_inside[v]){
        bt.update(u.f, -u.s);
    }
}
 
void id14(int v){
    for(const auto&u: cur_inside[v]){
        bt.update(u.f, u.s);
    }
}
 
void id10(int v){
    ll A = 0;
    ll AB = 0;
    ll ABC = 0;
 
    cur_inside[v].clear();
    for(const auto& u: val_poses[v]){
        ll ABC_here = 0;
        if(c[a[u]] == v){
            ABC+=AB;
            ABC_here = AB;
        }
        if(a[u] == v){
            AB+=A;
        }
        if(b[a[u]] == v){
            A++;
        }
        
        cur_inside[v].pb(mp(u, ABC_here));
    }
}
 


 
struct id0{
    ll A, B, C, AB, BC, ABC;
    ll Asum;
    ll ABsum;
    ll ABCsum;
 
    id0(){
        A = B = C = AB = BC = ABC = Asum = ABsum = ABCsum = 0;
    }
 
    void C_update(){ 

        C++;
        BC+=B;
        ABC+=AB;
    }
 
    void B_update(){
        B++;
        AB+=A;
    }
 
    void A_update(){
        A++;
    }
};
 
void id7(const id0& L, id0& R){ 

    R.Asum = L.Asum+R.A;
    R.ABsum = L.ABsum+L.Asum*R.B+R.AB;
    R.ABCsum = L.ABCsum+L.ABsum*R.C+L.Asum*R.BC+R.ABC;
}
 
vector<id0> big_blocks[mx]; 

 
void id4(int v, int pos){
    assert(big_val[v]);
    int bl = (pos-1)/POS_BLOCK+1;
 
    if(bl < sz(big_blocks[v])){
        big_blocks[v][bl] = id0();
        for(int i = bl*POS_BLOCK-POS_BLOCK+1; i <= bl*POS_BLOCK; i++){
            if(c[a[i]] == v){
                big_blocks[v][bl].C_update();
            }
            if(a[i] == v){
                big_blocks[v][bl].B_update();
            }
            if(b[a[i]] == v){
                big_blocks[v][bl].A_update();
            }
        }
    }
 
    for(int i = 1; i < sz(big_blocks[v]); i++){
        id7(big_blocks[v][i-1], big_blocks[v][i]);
    }
}
 
id0 query_helper[mx];
 
int main() {
    setIO();
    clock_t BEG = clock();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> typ[i];
        if(typ[i] == 1){
            cin >> k[i] >> x[i];
        }
        else if(typ[i] == 2){
            cin >> r[i];
        }
    }
 
    id17(); 

 
    

 
    for(int i = 1; i <= n; i++){
        vi id16 = getUnique(vi{b[a[i]], a[i], c[a[i]]});
        for(auto v: id16){
            if(!big_val[v]){
                val_poses[v].pb(i);
            }
        }
    }
 
    for(int v = 1; v <= n; v++){
        if(!big_val[v]){
            id10(v);
            id14(v);
        }
    }
 
    

 
    for(int v = 1; v <= n; v++){
        if(big_val[v]){
            big_blocks[v] = vector<id0>(n/POS_BLOCK+1, id0());
        }
    }
 
    for(int i = 1; i <= n/POS_BLOCK*POS_BLOCK; i++){
 
        int bl = (i-1)/POS_BLOCK+1;
        

        {
            
            int v = c[a[i]];
            if(big_val[v]){
                

                big_blocks[v][bl].C_update();
            }
        }
        {
            
            int v = a[i];
            if(big_val[v]){
                

                big_blocks[v][bl].B_update();
            }
        }
        {
            
            int v = b[a[i]];
            if(big_val[v]){
                

                big_blocks[v][bl].A_update();
            }
        }
    }
 
    
 
    for(int v = 1; v <= n; v++){
        if(big_val[v]){
            for(int i = 1; i < sz(big_blocks[v]); i++){
                id7(big_blocks[v][i-1], big_blocks[v][i]);
            }
        }
    }
 
    

    

    

    

    

    

 
    vi id1;
    for(int v = 1; v <= n; v++){
        if(big_val[v]){
            id1.pb(v);
        }
    }
 
    for(int i = 1; i <= m; i++){
        if(typ[i] == 1){ 

            vi id16 = getUnique(vi{b[a[k[i]]], a[k[i]], c[a[k[i]]], b[x[i]], x[i], c[x[i]]});
            vi id9 = getUnique(vi{b[a[k[i]]], a[k[i]], c[a[k[i]]]});
            vi id2 = getUnique(vi{b[x[i]], x[i], c[x[i]]});
            
 
            

 
            for(auto v: id16){ 

                if(!big_val[v]){
                    id5(v);
                }
            }
 
            for(auto v: id9){ 

                if(!big_val[v]){
                    vectorRemove(val_poses[v], k[i]);
                }
            }
 
            

            a[k[i]] = x[i];
            

 
            

            for(auto v: id2){ 

                if(!big_val[v]){
                    

                    vectorAdd(val_poses[v], k[i]);
                    

                }
            }
 
            for(auto v: id16){ 

                if(!big_val[v]){
                    id10(v);
                    id14(v);
                }
            }
 
            for(auto v: id16){
                if(big_val[v]){
                    id4(v, k[i]);
                }
            }
        }
        else if(typ[i] == 2){
            ll ans = bt.query(r[i]); 

 
            int cutoff = r[i]/POS_BLOCK*POS_BLOCK;
            int bl = cutoff/POS_BLOCK;
            

 
            

            vi id16;
            for(int j = cutoff+1; j <= r[i]; j++){
                if(big_val[b[a[j]]]){
                    id16.pb(b[a[j]]);
                }
                if(big_val[a[j]]){
                    id16.pb(a[j]);
                }
                if(big_val[c[a[j]]]){
                    id16.pb(c[a[j]]);
                }
            }
            id16 = getUnique(id16);
 
            for(const auto& v: id16){
                query_helper[v] = id0();
            }
 
            

            for(int j = cutoff+1; j <= r[i]; j++){
                if(big_val[c[a[j]]]){
                    query_helper[c[a[j]]].C_update();
                }
                if(big_val[a[j]]){
                    query_helper[a[j]].B_update();
                }
                if(big_val[b[a[j]]]){
                    query_helper[b[a[j]]].A_update();
                }
            }
 
            for(const auto& v: id16){
                

                id7(big_blocks[v][bl], query_helper[v]);
                

                ans+=query_helper[v].ABCsum-big_blocks[v][bl].ABCsum;
            }
 
            

 
            for(const auto& v: id1){
                ans+=big_blocks[v][bl].ABCsum;
            }
 
            ps(ans);
        }
    }
 
    dbg(VAL_BLOCK, POS_BLOCK);
    dbg(db(clock()-BEG)/db(CLOCKS_PER_SEC));
 
    

}
 
