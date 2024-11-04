
































































































































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










const int MOD = 998244353;
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
    tcT> constexpr bool id11 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id3 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id10 = !id0<T> && id11<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

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
    tcT> constexpr bool id4 = !id3<T> && id11<T>;

    

    tcT> typename enable_if<id3<T>,str>::type ts(T v) {
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
    tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
        

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
    template<int lev, class T> void id13(const T& t) {
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
    FOR(i,1,SZ) id5(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



vmi invs, fac, ifac;
void genFac(int SZ) {
    invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FOR(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
    FOR(i,1,SZ) fac[i] = fac[i-1]*i, ifac[i] = ifac[i-1]*invs[i];
}
mi comb(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac[a]*ifac[b]*ifac[a-b]; }



tcT, int SZ> struct LazySeg { 
    static_assert(pct(SZ) == 1); 

    const T ID = mp(-MOD, -1); T cmb(T a, T b) { return max(a, b); }
    T seg[2*SZ];
    int lazy[2*SZ];
    LazySeg() { 
        id5(i,2*SZ){
            seg[i] = ID; 
            lazy[i] = 0;
        }
    }
    void push(int ind, int L, int R) { 

        seg[ind].f += lazy[ind]; 

        if (L != R) id5(i,2) lazy[2*ind+i] += lazy[ind]; 

        lazy[ind] = 0;
    } 

    void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
    void build() { ROF(i,1,SZ) pull(i); }
    void upd(int lo,int hi,int inc,int ind=1,int L=0, int R=SZ-1) {
        push(ind,L,R); if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) { 
            lazy[ind] = inc; push(ind,L,R); return; }
        int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
        upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
    }
    T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
        push(ind,L,R); if (lo > R || L > hi) return ID;
        if (lo <= L && R <= hi) return seg[ind];
        int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
            query(lo,hi,2*ind+1,M+1,R));
    }
};



tcT> struct BIT {
    int N; V<T> data;
    void init(int _N) { N = _N; data.rsz(N); }
    void add(int p, T x) { for (++p;p<=N;p+=p&-p) data[p-1] += x; }
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



const int mx = 600005;
const int SEG_SZ = 1048576;
BIT<int> bt;
LazySeg<pi, SEG_SZ> lseg;

bool allDistinct(vi v){
    int orig_size = sz(v);
    remDup(v);
    int end_size = sz(v);
    return orig_size == end_size;
}

mi addCase(vector<pair<int, bool>> pairs, int T){
    dbg(pairs, T);
    assert(sz(pairs));
    vector<pi> id9;
    { 

        map<int, int> id1;
        for(auto u: pairs){
            if(u.s == 0){
                id1[u.f]++;
            }
        }
        for(auto u: id1){
            id9.pb(u);
        }
        reverse(all(id9));
    }


    auto pairWorks = [&](int val, bool typ){
        int bt_sum = typ ? bt.sum(val+1, mx-2) : bt.sum(1, val-1);
        return val+bt_sum == T;
    };

    mi ans = 1;
    for(int i = 0; i < sz(pairs); i++){
        dbg(i);
        pi id2 = mp(-MOD, -1);
        pi id12 = mp(-MOD, -1);
        if(sz(id9) && pairWorks(id9.bk.f, 0)){
            id2 = mp(id9.bk.f, 0);
        }

        {
            pi id8 = lseg.query(0, SEG_SZ-1);
            if(id8.f == T){
                int val = id8.f;
                if(val == T){
                    id12 = mp(id8.s, 1);
                }
            }
        }

        if(id2.f < 0 && id12.f < 0){
            return mi(0);
        }

        dbg(id2, id12);
        int which_one = -1;
        if(id2.f < 0){
            which_one = 1;
        }
        else if(id12.f < 0){
            which_one = 0;
        }
        else{
            if(id2 > id12){
                which_one = 0;
            }
            else{
                which_one = 1;
            }
        }

        pi works = which_one ? id12 : id2;
        int val = works.f;
        int bt_sum = works.s ? bt.sum(val+1, mx-2) : bt.sum(1, val-1);
        assert(val+bt_sum == T);
        

        if(works.s){
            ans*=mi(1);
        }
        else{
            ans*=mi(id9.bk.s);
        }
        dbg("HERE", val);

        bt.add(val, -1);
        bt.add(T, +1);

        if(which_one == 0){
            id9.bk.s--;
            if(id9.bk.s == 0) id9.pop_back();
        }
        else{
            

            lseg.upd(val, val, -MOD);
        }
        dbg("END");

        

        lseg.upd(val, T-1, +1);

    }
    
    return ans;
}

mi getAns(vector<pair<int, bool>> pairs){
    if(sz(pairs) == 0) return mi(1);

    bt.init(mx);
    for(auto u: pairs){
        bt.add(u.f, +1);   
    }

    


    vi distincts;
    for(auto u: pairs){
        distincts.pb(u.f);
    }
    remDup(distincts);
    if(sz(distincts) == 1){
        return fac[sz(pairs)];
    }

    int T = MOD;
    for(auto u: pairs){
        ckmin(T, u.f);
    }
    T = (T+sz(pairs)-1);

    dbg(T);
    for(auto u: pairs){
        if(u.f > T) return mi(0);
    }

    

    {
        vi one_inds;
        for(auto u: pairs){
            if(u.f == T) continue;
            if(u.s == 1){
                one_inds.pb(u.f);
            }
        }
        if(!allDistinct(one_inds)) return mi(0);  

        vi csum(mx, 0);
        for(auto u: pairs){
            csum[u.f]++;
        }
        for(int i = 1; i < sz(csum); i++){
            csum[i]+=csum[i-1];
        }

        for(auto u: one_inds){
            lseg.seg[u+SEG_SZ] = mp(u+csum.bk-csum[u], u);
        }
        lseg.build();
    }
    

    mi ans = 1;
    {
        vector<pair<int, bool>> new_pairs;
        int id15 = 0;
        int id14 = 0;
        for(auto u: pairs){
            if(u.f == T){
                if(u.s == 0){
                    id15++;
                }
                else{
                    id14++;
                }
            }
            else{
                new_pairs.pb(u);
            }
        }

        ans*=fac[id15];
        ans*=fac[id14];
        dbg(sz(pairs), id14, id15);
        ans*=comb(sz(pairs), id14);

        swap(pairs, new_pairs);
    }

    dbg(ans);

    ans*=addCase(pairs, T);

    return ans;
}

int main() {
    setIO();
    genFac(1000005);
    int n; cin >> n;
    vector<pair<int, bool>> pairs(n);
    for(int i = 0; i < n; i++){
        cin >> pairs[i].f;
    }
    for(int i = 0; i < n; i++){
        cin >> pairs[i].s;
    }

    mi ans = getAns(pairs);
    ps(ans);

    

}


