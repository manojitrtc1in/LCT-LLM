#include <bits/stdc++.h>
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
 
#define tcT template<class T
#define tcTU tcT, class U


tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
 


#define mp make_pair
#define f first
#define s second
 




#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return
 
#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
 


#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
 
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
constexpr int msk2(int x) { return p2(x)-1; }
 
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

 
#define tcTUU tcT, class ...U
 
inline namespace Helpers {
    

    

    

    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool is_iterable_v = is_iterable<T>::value;
 
    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool is_readable_v = is_readable<T>::value;
 
    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool is_printable_v = is_printable<T>::value;
}
 
inline namespace Input {
    tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 

 
    

    tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
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
    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
    #define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}
 
inline namespace ToString {
    tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;
 
    

    tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }
 
    

    template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
      ts_lev(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
      ts_lev(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = ts_lev<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        F0R(i,sz(res)) {
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
    template<int lev, class T> void dbgl_out(const T& t) {
        cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
    #ifdef LOCAL
        #define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
        #define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
    #else 

        #define dbg(...) 0
        #define dbgl(lev,x) 0
    #endif
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
const int VAL_BLOCK = sqrt(mx)*0.7;
const int POS_BLOCK = sqrt(mx)*0.4;




 
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
 
void genBigVal(){
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
 
struct SqrtBIT{
    ll trips[mx];
    ll block_sums[mx];
 
    SqrtBIT(){
        for(int i = 0; i < mx; i++){
            trips[i] = block_sums[i] = 0;
        }
    }
 
    void update(int pos, ll val){ 

        trips[pos]+=val;
        int L = (pos-1)/POS_BLOCK*POS_BLOCK+1;
        int R = L+POS_BLOCK-1;
        if(R <= n){
            block_sums[R] = 0;
            for(int i = L; i <= R; i++){
                block_sums[R]+=trips[i];
            }
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
 
SqrtBIT bt;
 
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
 
void undoCurInside(int v){
    for(const auto&u: cur_inside[v]){
        bt.update(u.f, -u.s);
    }
}
 
void redoCurInside(int v){
    for(const auto&u: cur_inside[v]){
        bt.update(u.f, u.s);
    }
}
 
void recalcCurInside(int v){
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
 


 
struct SqrtBlock{
    ll A, B, C, AB, BC, ABC;
    ll Asum;
    ll ABsum;
    ll ABCsum;
 
    SqrtBlock(){
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
 
void calcSums(const SqrtBlock& L, SqrtBlock& R){ 

    R.Asum = L.Asum+R.A;
    R.ABsum = L.ABsum+L.Asum*R.B+R.AB;
    R.ABCsum = L.ABCsum+L.ABsum*R.C+L.Asum*R.BC+R.ABC;
}
 
vector<SqrtBlock> big_blocks[mx]; 

 
void updateBigBlocks(int v, int pos){
    assert(big_val[v]);
    int bl = (pos-1)/POS_BLOCK+1;
 
    if(bl < sz(big_blocks[v])){
        big_blocks[v][bl] = SqrtBlock();
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
        calcSums(big_blocks[v][i-1], big_blocks[v][i]);
    }
}
 
SqrtBlock query_helper[mx];
 
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
 
    genBigVal(); 

 
    

 
    for(int i = 1; i <= n; i++){
        vi relevant_vals = getUnique(vi{b[a[i]], a[i], c[a[i]]});
        for(auto v: relevant_vals){
            if(!big_val[v]){
                val_poses[v].pb(i);
            }
        }
    }
 
    for(int v = 1; v <= n; v++){
        if(!big_val[v]){
            recalcCurInside(v);
            redoCurInside(v);
        }
    }
 
    

 
    for(int v = 1; v <= n; v++){
        if(big_val[v]){
            big_blocks[v] = vector<SqrtBlock>(n/POS_BLOCK+1, SqrtBlock());
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
                calcSums(big_blocks[v][i-1], big_blocks[v][i]);
            }
        }
    }
 
    

    

    

    

    

    

 
    vi all_big_vals;
    for(int v = 1; v <= n; v++){
        if(big_val[v]){
            all_big_vals.pb(v);
        }
    }
 
    for(int i = 1; i <= m; i++){
        if(typ[i] == 1){ 

            vi relevant_vals = getUnique(vi{b[a[k[i]]], a[k[i]], c[a[k[i]]], b[x[i]], x[i], c[x[i]]});
            vi relevant_vals_before = getUnique(vi{b[a[k[i]]], a[k[i]], c[a[k[i]]]});
            vi relevant_vals_after = getUnique(vi{b[x[i]], x[i], c[x[i]]});
            
 
            

 
            for(auto v: relevant_vals){ 

                if(!big_val[v]){
                    undoCurInside(v);
                }
            }
 
            for(auto v: relevant_vals_before){ 

                if(!big_val[v]){
                    vectorRemove(val_poses[v], k[i]);
                }
            }
 
            

            a[k[i]] = x[i];
            

 
            

            for(auto v: relevant_vals_after){ 

                if(!big_val[v]){
                    

                    vectorAdd(val_poses[v], k[i]);
                    

                }
            }
 
            for(auto v: relevant_vals){ 

                if(!big_val[v]){
                    recalcCurInside(v);
                    redoCurInside(v);
                }
            }
 
            for(auto v: relevant_vals){
                if(big_val[v]){
                    updateBigBlocks(v, k[i]);
                }
            }
        }
        else if(typ[i] == 2){
            ll ans = bt.query(r[i]); 

 
            int cutoff = r[i]/POS_BLOCK*POS_BLOCK;
            int bl = cutoff/POS_BLOCK;
            

 
            

            vi relevant_vals;
            for(int j = cutoff+1; j <= r[i]; j++){
                if(big_val[b[a[j]]]){
                    relevant_vals.pb(b[a[j]]);
                }
                if(big_val[a[j]]){
                    relevant_vals.pb(a[j]);
                }
                if(big_val[c[a[j]]]){
                    relevant_vals.pb(c[a[j]]);
                }
            }
            relevant_vals = getUnique(relevant_vals);
 
            for(const auto& v: relevant_vals){
                query_helper[v] = SqrtBlock();
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
 
            for(const auto& v: relevant_vals){
                

                calcSums(big_blocks[v][bl], query_helper[v]);
                

                ans+=query_helper[v].ABCsum-big_blocks[v][bl].ABCsum;
            }
 
            

 
            for(const auto& v: all_big_vals){
                ans+=big_blocks[v][bl].ABCsum;
            }
 
            ps(ans);
        }
    }
 
    dbg(VAL_BLOCK, POS_BLOCK);
    dbg(db(clock()-BEG)/db(CLOCKS_PER_SEC));
 
    

}
 
