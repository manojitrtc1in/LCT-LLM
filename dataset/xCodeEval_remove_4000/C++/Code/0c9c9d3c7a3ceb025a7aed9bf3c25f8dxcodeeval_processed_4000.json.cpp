
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
constexpr int id8(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id2 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id5 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id10 = !id2<T> && id11<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id2<T>,void>::type re(T& x) { cin >> x; } 

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
    tcT> constexpr bool id6 = !id5<T> && id11<T>;

    

    tcT> typename enable_if<id5<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id7(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id6<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id6<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id6<T>,vs>::type 
      id9(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id6<T>,vs>::type 
      id9(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id9<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id7(i,sz(res)) {
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
    template<int lev, class T> void id12(const T& t) {
        cerr << "\n\n" << ts_sep(id9<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

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
    FOR(i,1,SZ) id7(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}





tcT> void fft(V<T>& A, bool inv = 0) { 

    int n = sz(A); assert((T::mod-1)%n == 0); V<T> B(n);
    for(int b = n/2; b; b /= 2, swap(A,B)) { 

        T w = pow(T::rt(),(T::mod-1)/n*b), m = 1; 
        for(int i = 0; i < n; i += b*2, m *= w) id7(j,b) {
            T u = A[i+j], v = A[i+j+b]*m;
            B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
        }
    }
    if (inv) { reverse(1+all(A)); 
        T z = T(1)/T(n); each(t,A) t *= z; }
} 

tcT> V<T> mul(V<T> A, V<T> B) {
    if (!min(sz(A),sz(B))) return {};
    int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
    bool eq = A == B; A.rsz(n), fft(A);
    if (eq) B = A; 

    else B.rsz(n), fft(B);
    id7(i,n) A[i] *= B[i];
    fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(V<T> x, V<T> y) {
    auto con = [](const V<T>& v) {
        V<M> w(sz(v)); id7(i,sz(v)) w[i] = (int)v[i];
        return w; };
    return mul(con(x),con(y));
} 

tcT> V<T> MUL(const V<T>& A, const V<T>& B) {
    using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
    using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
    using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
    int n = sz(c0); V<T> res(n); m1 r01 = 1/m1(m0::mod); 
    m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
    id7(i,n) { 

        int a = c0[i].v, b = ((c1[i]-a)*r01).v, 
            c = (((c2[i]-a)*r02-b)*r12).v;
        res[i] = (T(c)*m1::mod+b)*m0::mod+a; 

    }
    return res;
}


const int mx = 400005;

struct Eff{

ll n, m;
int k;
ll a[mx]{};
ll csum[mx]{};

vi addZeroBef(vi A){
    vi res;
    res.pb(0);
    for(auto u: A){
        res.pb(u);
    }
    return res;
}








































mi oneSub(vi vals, ll B){ 

    vals = addZeroBef(vals);
    vi id1 = vals;
    for(int i = 1; i < sz(id1); i++){
        id1[i]+=id1[i-1];
        id1[i] %= k;
    }

    mi res = mi(0);

    vmi rems(k, mi(0));
    for(int i = 0; i < sz(id1); i++){
        int need = (-B+id1[i]+k) % k;
        res+=rems[need];
        rems[id1[i]]+=mi(1);
    }
    

    return res;
}



























vmi sufPref(){
    vmi poly1 = vmi(k, mi(0));
    for(int i = 1; i <= n; i++){
        ll pref = csum[i];
        assert(0 <= pref && pref < k);
        poly1[pref]+=mi(1);
    }

    vmi poly2 = vmi(k, mi(0));

    for(int i = 1; i <= n; i++){
        ll suf = (csum[n]-csum[i-1]+k) % k;
        assert(0 <= suf && suf < k);
        poly2[suf]+=mi(1);
    }

    

    

    


    dbg("BEGIN FFT");
    vmi res = MUL(poly1, poly2);
    dbg("END FFT");

    vmi resk = vmi(k, mi(0));
    for(int i = 0; i < sz(res); i++){
        resk[i % k]+=res[i];
    }
    return resk;
}

vector<ll> calc(ll m, ll k) {
    

    m--;
    vector<ll> res(k, 0);
    for (int i = 0; i < k; ++i) {
        ll cnt = m - i;
        if (cnt <= 0) {
            continue;
        }
        ll full_blocks = cnt / k;
        res[i] = full_blocks * (full_blocks + 1) / 2 * k;
        res[i] += (full_blocks + 1) * (cnt % k);
    }
    

    return res;
}

vmi getIJ(){
    vl RES = calc(m, k);
    assert(sz(RES) == k);
    vmi res;
    for(auto u: RES){
        res.pb(mi(u));
    }
    return res;
}






















int getPow(ll base, ll expo){
    

    ll res = 1;

    while(expo > 0){
        if(expo&1LL){
            res = (res*base) % k;
        }
        expo/=2;
        base = (base*base) % k;
    }

    

    return (int)(res % k);
}

int getInv(int base){
    return getPow(base, k-2);
}

mi array2Sol(ll B){
    


    dbg(B);
    vmi rems = sufPref();
    mi ans = mi(0);
    vmi id3 = getIJ();

    assert(sz(rems) == k && sz(id3) == k); 

    

    



    for(int i = 0; i < k; i++){ 

        int need = (int)((B-i+k) % k); 


        if(csum[n] == 0){
            if(need == 0){
                ans+=rems[i]*mi((ll(m)*ll(m-1))/2); 

            }
            else{
                ans+=mi(0);
            }
        }
        else{
            assert(k > 1);
            int diff = (int)((ll(getInv(csum[n]))*ll(need)) % k);

            ans+=rems[i]*id3[diff];
            assert(0 <= diff && diff < k);
        }
    }

    

    return ans;
}

mi getSubarrays(ll B){ 

    

    vi justOne;
    for(int i = 1; i <= n; i++){
        justOne.pb(a[i]);
    }
    mi ans1 = oneSub(justOne, B); ans1*=mi(m);

    
    mi ans2 = array2Sol(B);
    

    

    

    

    return ans1+ans2;
}

mi getPrefs(ll B){
    for(int i = 1; i <= n; i++){
        csum[i] = (csum[i-1]+a[i]) % k;
    }

    vmi rems(k, mi(0));
    for(int j = 1; j <= m; j++){ 

        rems[(csum[n]*ll(j-1)) % k]+=mi(1);
    }
    

    mi res = mi(0);
    for(int i = 1; i <= n; i++){
        int need = (B-csum[i]+k) % k;
        

        res+=rems[need];
    }
    return res;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]%=k;
    }
    for(int i = 1; i <= n; i++){
        csum[i] = (csum[i-1]+a[i]) % k;
    }

    ll tot = (ll(csum[n])*ll(m)) % k;

    mi id0 = getSubarrays(0);
    

    mi id4 = getSubarrays(tot);



    mi pref1 = getPrefs(tot);

    for(int i = 1; i <= n/2; i++){
        swap(a[i], a[n+1-i]);
    }

    mi pref2 = getPrefs(tot);

    dbg(id0, id4);
    dbg(pref1, pref2);
    mi ans = id0+id4-pref1-pref2+mi(1);



    ps(ans);
}  

};


int main() {
    setIO();
    Eff e;
    e.solve();
    

}


