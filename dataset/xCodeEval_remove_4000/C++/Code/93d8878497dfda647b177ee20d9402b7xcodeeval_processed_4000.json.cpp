
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
constexpr int id4(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id7 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id6 = !id0<T> && id7<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id6<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id6<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id2 = !id1<T> && id7<T>;

    

    tcT> typename enable_if<id1<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id3(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id2<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id7<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id2<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id2<T>,vs>::type 
      id5(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id2<T>,vs>::type 
      id5(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id5<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id3(i,sz(res)) {
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
    template<int lev, class T> void id8(const T& t) {
        cerr << "\n\n" << ts_sep(id5<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

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



template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } 

    int v; explicit operator int() const { return v; } 

    mint():v(0) {}
    mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    bool operator==(const mint& o) const {
        return v == o.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend void re(mint& a) { ll x; re(x); a = mint(x); }
    friend str ts(mint a) { return ts(a.v); }
   
    mint& operator+=(const mint& o) { 
        if ((v += o.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& o) { 
        if ((v -= o.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& o) { 
        v = int((ll)v*o.v%MOD); return *this; }
    mint& operator/=(const mint& o) { return (*this) *= inv(o); }
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

using mi = mint<MOD,5>; 

using vmi = V<mi>;
using pmi = pair<mi,mi>;
using vpmi = V<pmi>;

V<vmi> scmb; 

void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) id3(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



tcT> struct BIT {
    int N; V<T> data;
    void init(int _N) { N = _N; data.rsz(N); }

    V<pair<int, T>> changes;

    void add(int p, T x, bool pushing = true) { if(pushing) changes.pb(mp(p, x)); for (++p;p<=N;p+=p&-p) data[p-1] += x; }

    void reset(){

        for(auto u: changes){
            add(u.f, -u.s, false);
        }
        changes.clear();

        dbg("RESET");
    }

    T sum(int l, int r) { return sum(r+1)-sum(l); }
    T sum(int r) { T s = 0; for(;r;r-=r&-r)s+=data[r-1]; return s; }
    int lower_bound(T sum) {
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1<<25; pw; pw >>= 1) {
            int npos = pos+pw;
            if (npos <= N && data[npos-1] < sum)
                pos = npos, sum -= data[pos-1];
        }
        return pos;
    }
};

const int mx = 200005;

struct Eff{ 




int a[mx];
mi sub_pre[mx];
mi sub_suf[mx];

void solveTestCase(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    map<int, int> m;
    for(int i = 1; i <= n; i++){
        m[a[i]];
    }
    int m_cur = 0;
    for(auto& u: m){
        u.s = ++m_cur;
    }

    for(int i = 1; i <= n; i++){
        a[i] = m[a[i]];
    }
        
    {
        BIT<mi> left_bt; 

        left_bt.init(n+5);

        for(int i = 1; i <= n; i++){
            sub_pre[i] = left_bt.sum(1, a[i]-1);
            sub_pre[i]+=mi(1);
            left_bt.add(a[i], sub_pre[i]);
        }
    }
    
    {
        BIT<mi> right_bt;
        right_bt.init(n+5);

        for(int i = n; i >= 1; i--){
            sub_suf[i] = right_bt.sum(a[i]+1, n);
            sub_suf[i]+=mi(1);
            right_bt.add(a[i], sub_suf[i]);
        }
    }

    vi sorted_inds; for(int i = 1; i <= n; i++) sorted_inds.pb(i);
    sort(all(sorted_inds), [&](int l, int r){
        if(a[l] != a[r]){
            return a[l] > a[r];
        }
        return l < r;
    });

    mi ans = 0;
    int rightmost = -1;
    BIT<mi> bt; bt.init(n+5);

    for(auto ind: sorted_inds){
        dbg(ind);
        if(rightmost < ind){
            rightmost = ind;
            bt.reset();
            bt.add(ind, mi(1));
        }
        else{
            mi seq_num = mi(0);
            seq_num+=bt.sum(ind+1, n);
            ans+=sub_pre[ind]*sub_suf[ind]-sub_pre[ind]*seq_num;
            dbg(ind, seq_num);
            bt.add(ind, seq_num);
        }
    }


    ps(ans);
}

void solve(){
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solveTestCase();
    }
}

}; 


int main() {
    setIO();
    Eff e; e.solve();
    

}

