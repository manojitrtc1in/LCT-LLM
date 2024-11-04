
































































































































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










int MOD = 1e9+7; 

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
constexpr int id6(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id10 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id9 = !id0<T> && id10<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id9<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id9<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id4 = !id2<T> && id10<T>;

    

    tcT> typename enable_if<id2<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id5(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id4<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id10<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id4<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id4<T>,vs>::type 
      id7(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id4<T>,vs>::type 
      id7(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id7<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id5(i,sz(res)) {
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
    template<int lev, class T> void id11(const T& t) {
        cerr << "\n\n" << ts_sep(id7<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

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



struct mi { 

     int v; explicit operator int() const { return v; } 
    mi():v(0) {}
    mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
    if ((a.v += b.v) >= MOD) a.v -= MOD; 
    return a; }
mi& operator-=(mi& a, mi b) { 
    if ((a.v -= b.v) < 0) a.v += MOD; 
    return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, ll p) { assert(p >= 0); 

    return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

string ts(mi a){
    return to_string(a.v);
}

using vmi = V<mi>;

V<vmi> scmb; 

V<mi> fac;
void genComb(int SZ) {
    fac.pb(mi(1));
    for(int i = 1; i < SZ; i++){
        fac.pb(mi(i)*fac.bk);
    }
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) id5(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}


const int mx = 2005;

int n;
int p[mx];
mi anses[mx];
mi f[mx][mx];

int id1(vi v){
    vb vals(n+1, 0);
    for(auto u: v){
        vals[u] = true;
    }

    int D = 0;
    for(int i = 1; i+1 <= n; i++){
        if(!vals[i] && !vals[i+1]){
            D++;
        }
        else if(!vals[i+1] && v.bk == i){
            D++;
        }
    }
    return D;
}

vmi getDP(int N, int D){
    dbg(N, D);
    assert(D <= N);

    vmi ans(n+1, mi(0));
    for(int k = 0; k <= n; k++){
        if(D-k >= 0 && N-1-k >= 0){
            ans[k] = scmb[D][k]*f[D-k][N-1-k];
        }
    }
    return ans;

    

    

    

    

    

    

    

    

    

    

    

    

}

void updateAns(int N, int D, int d, int mult = 1){
    vmi ans = getDP(N, D);
    for(int i = 0; i < sz(ans); i++){
        if(i+d <= n){
            anses[i+d]+=ans[i]*mi(mult);
        }
    }
}

int placed_num = 0;
vi cur_perm = vi{-1};
int cur_d = 0;
bool val_seen[mx];
int empty_pairs = 0;

void INITIALIZE(){
    empty_pairs = n-1;
}

void placeVal(int pos, int val){
    

    placed_num++;
    assert(sz(cur_perm) == pos);
    cur_perm.pb(val);
    if(cur_perm[sz(cur_perm)-2]+1 == cur_perm[sz(cur_perm)-1]){
        cur_d++;
    }
    val_seen[cur_perm.bk] = true;
    if(1 <= cur_perm.bk-1 && !val_seen[cur_perm.bk-1]){
        empty_pairs--;
    }
    if(cur_perm.bk+1 <= n && !val_seen[cur_perm.bk+1]){
        empty_pairs--;
    }
    

}

void rollbackVals(){
    

    if(cur_perm.bk+1 <= n && !val_seen[cur_perm.bk+1]){
        empty_pairs++;
    }
    if(1 <= cur_perm.bk-1 && !val_seen[cur_perm.bk-1]){
        empty_pairs++;
    }
    val_seen[cur_perm.bk] = false;
    if(cur_perm[sz(cur_perm)-2]+1 == cur_perm[sz(cur_perm)-1]){
        cur_d--;
    }
    cur_perm.pop_back();
    placed_num--;
    

}

vi id3(){
    int N = n-placed_num+1;
    int D = empty_pairs;
    if(cur_perm.bk+1 <= n && !val_seen[cur_perm.bk+1]){
        D++;
    }
    return vi{N, D, cur_d};
}

void solve(){
    
    cin >> n >> MOD;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    genComb(mx+5);
    for(int x = 0; x < mx; x++){
        for(int y = 0; y < mx; y++){
            if(x == 0){
                f[x][y] = fac[y];
            }
            else{
                if(x-1 >= 0){
                    f[x][y]+=f[x-1][y];
                }
                if(x-1 >= 0 && y-1 >= 0){
                    f[x][y]-=f[x-1][y-1];
                }
            }
        }
    }
    INITIALIZE();

    map<vi, int> id8;

    for(int i = 0; i <= n-1; i++){
        int next_val = p[i+1];

        vb seen(n+1);
        for(int j = 1; j <= i; j++){
            seen[p[j]] = true;
        }

        for(int j = 1; j < next_val; j++){
            if(seen[j]) continue;
            placeVal(i+1, j);

            vi NDd = id3();
            id8[NDd]++;

            rollbackVals();
        }
        placeVal(i+1, p[i+1]);
    }

    for(auto u: id8){
        updateAns(u.f[0], u.f[1], u.f[2], u.s);
    }

    for(int i = n-1; i >= 0; i--){
        cout << anses[i].v;
        if(i-1 >= 0){
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    setIO();
    solve();

    

    

    

    

    

    
    

}


