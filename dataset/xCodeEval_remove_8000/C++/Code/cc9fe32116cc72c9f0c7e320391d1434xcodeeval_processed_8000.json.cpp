
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 























const int MOD = 998244353; 

const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } 

int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } 

int fstTrue(function<bool(int)> f, int lo, int hi) {
    hi ++; assert(lo <= hi); 

    while (lo < hi) { 

        int mid = (lo+hi)/2; 
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}



template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }




str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
    stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
    str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; F0R(i,SZ) res += char('0'+b[i]);
    return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { 

    bool fst = 1; str res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += ts(x);
    }
    res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
    return "("+ts(p.f)+", "+ts(p.s)+")"; }



template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
    pr(h); pr(t...); }
void ps() { pr("\n"); } 

template<class H, class... T> void ps(const H& h, const T&... t) { 
    pr(h); if (sizeof...(t)) pr(" "); ps(t...); }



void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << ts(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }









void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void id6() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
    id6();
    

    

    

    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

}




struct mi {
    typedef decay<decltype(MOD)>::type T; 
     

    T v; explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) { 
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) { 
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { 
        return a.v < b.v; }
    friend void re(mi& a) { ll x; re(x); a = mi(x); }
    friend str ts(mi a) { return ts(a.v); }
   
    mi& operator+=(const mi& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mi& operator-=(const mi& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mi& operator*=(const mi& m) { 
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; 

void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) F0R(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



vi invs, fac, ifac;
void genFac(int SZ) {
    invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
    FOR(i,1,SZ) {
        fac[i] = (ll)fac[i-1]*i%MOD;
        ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
    }
}

ll comb(int a, int b) {
    if (a < b || b < 0) return 0;
    return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}





typedef mi T; using poly = vector<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { p.insert(begin(p),x,0); return p; }
poly RSZ(poly p, int x) { p.rsz(x); return p; }
T eval(const poly& p, T x) { 

    T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
    return res; }
poly dif(const poly& p) { 

    poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
    return res; }
poly integ(const poly& p) { 

    poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/T(i+1);
    return res; }

poly& operator+=(poly& l, const poly& r) {
    l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
    return l; }
poly& operator-=(poly& l, const poly& r) {
    l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
    return l; }
poly& operator*=(poly& l, const T& r) { trav(t,l) t *= r; 
    return l;     }
poly& operator/=(poly& l, const T& r) { trav(t,l) t /= r; 
    return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { trav(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;     }
poly operator*(const poly& l, const poly& r) {
    if (!min(sz(l),sz(r))) return {};
    poly x(sz(l)+sz(r)-1); 
    F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
    return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRem(poly a, poly b) { 
    remz(a); remz(b); assert(sz(b));
    T lst = b.bk, B = T(1)/lst; trav(t,a) t *= B; 
    trav(t,b) t *= B;
    poly q(max(sz(a)-sz(b)+1,0));
    for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
        q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
    trav(t,a) t *= lst;
    return {q,a}; 

}

T resultant(poly a, poly b) { 

    

    

    

    

    

    int ad = sz(a)-1, bd = sz(b)-1; 
    if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
    int pw = ad; a = quoRem(a,b).s; pw -= (ad = sz(a)-1);
    return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}







const int root = 3; 





void genRoots(vmi& roots) { 

    int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
    roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r; }
typedef complex<db> cd; typedef vector<cd> vcd;
void genRoots(vcd& roots) { 

    int n = sz(roots); db ang = 2*PI/n;
    

    F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); }

int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
template<class T> void fft(vector<T>& a, 
  const vector<T>& rts, bool inv = 0) {
    int n = sz(a);
    for (int i = 1, j = 0; i < n; i++) { 
        int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
        j ^= bit; if (i < j) swap(a[i],a[j]);
    } 

    for (int len = 1; len < n; len *= 2)
        for (int i = 0; i < n; i += 2*len) F0R(j,len) {
            T u = a[i+j], v = a[i+j+len]*rts[n/2/len*j];
            a[i+j] = u+v, a[i+j+len] = u-v;
        }
    if (inv) {
        reverse(1+all(a));
        T i = T(1)/T(n); trav(x,a) x *= i; 
    }
}
template<class T> vector<T> mul(vector<T> a, vector<T> b) {
    if (!min(sz(a),sz(b))) return {};
    int s = sz(a)+sz(b)-1, n = 1<<size(s);
    vector<T> roots(n); genRoots(roots);
    a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
    F0R(i,n) a[i] *= b[i];
    fft(a,roots,1); a.rsz(s); return a;
}




bool small(const poly& a, const poly& b) { 

    return (ll)sz(a)*sz(b) <= 10000; } 
vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
vl smart(const vl& a, const vl& b) {
    auto X = mul(vcd(all(a)),vcd(all(b)));
    vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
    return x; }
poly conv(const poly& a, const poly& b) {
    return small(a,b) ? a*b : smart(a,b); } 





poly inv(poly A, int n) { 

    poly B{1/A[0]};
    while (sz(B) < n) { int x = 2*sz(B);
        B = RSZ(2*B-conv(RSZ(A,x),conv(B,B)),x); }
    return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  

    assert(A[0] == 1); poly B{1};
    while (sz(B) < n) { int x = 2*sz(B);
        B = T(1)/T(2)*RSZ(B+mul(RSZ(A,x),inv(B,x)),x); }
    return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { 
    if (sz(f) < sz(g)) return {{},f};
    auto q = mul(inv(rev(g),sz(f)-sz(g)+1),rev(f));
    q = rev(RSZ(q,sz(f)-sz(g)+1));
    auto r = RSZ(f-mul(q,g),sz(g)-1); return {q,r};
}
poly log(poly A, int n) { assert(A[0] == 1); 

    return RSZ(integ(conv(dif(A),inv(A,n))),n); }
poly exp(poly A, int n) { 

    assert(A[0] == 0); poly B = {1};
    while (sz(B) < n) { int x = 2*sz(B);
        B = RSZ(B+conv(B,RSZ(A,x)-log(B,x)),x); }
    return RSZ(B,n);
}

void segProd(vector<poly>& stor, poly& v, int ind, int l, int r) { 

    if (l == r) { stor[ind] = {-v[l],1}; return; }
    int m = (l+r)/2; segProd(stor,v,2*ind,l,m); segProd(stor,v,2*ind+1,m+1,r);
    stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
}
void evalAll(vector<poly>& stor, vmi& res, poly v, int ind = 1) {
    v = divi(v,stor[ind]).s;
    if (sz(stor[ind]) == 2) { res.pb(sz(v)?v[0]:0); return; }
    evalAll(stor,res,v,2*ind); evalAll(stor,res,v,2*ind+1);
}
poly multiEval(poly v, poly p) {
    vector<poly> stor(4*sz(p)); segProd(stor,p,1,0,sz(p)-1);
    poly res; evalAll(stor,res,v); return res; }

poly combAll(vector<poly>& stor, poly& dems, int ind, int l, int r) {
    if (l == r) return {dems[l]};
    int m = (l+r)/2;
    poly a = combAll(stor,dems,2*ind,l,m), b = combAll(stor,dems,2*ind+1,m+1,r);
    return conv(a,stor[2*ind+1])+conv(b,stor[2*ind]);
}
poly interpolate(vector<pair<T,T>> v) {
    poly x; trav(t,v) x.pb(t.f);
    int n = sz(v);
    vector<poly> stor(4*n); segProd(stor,x,1,0,n-1);
    poly dems; evalAll(stor,dems,dif(stor[1]));
    F0R(i,n) dems[i] = v[i].s/dems[i];
    return combAll(stor,dems,1,0,n-1);
}

clock_t beg;

int n;
int m;

poly id4(poly a, int p){
    a.rsz(m);
    assert(a[0] == mi(0));
    for(int i = 0; i+1 < sz(a); i++){
        a[i] = a[i+1]; 

    }
    a = log(a, m);
    a*=mi(p);
    a = exp(a, m);
    return a;
}

poly ConstructE(poly P){
    P.rsz(m);
    poly E(m, 0);
    for(int i = 0; i <= n; i++){
        E[i] += P[n-i]*ifac[i];
    }
    return E;
}

poly CDsolve(poly C, poly D, poly Cneg){
    

    C.rsz(m);
    D.rsz(m);
    poly id10(4, 0);
    for(int i = 1; i <= 2; i++){
        id10[i+1] = mi(-i)*Cneg[i];
    }
    poly P1 = conv(dif(C), D);
    poly id12(4, 0);
    

    for(int i = 1; i <= 3; i++){
        for(int j = 0; j < m; j++){
            mi val = id10[i]*D[j];
            int ind = j-i;
            if(ind < 0){
                id12[-ind]+=val;
            }
            else{
                P1[ind]+=val;
            }
        }
    }
    

    

    for(int i = m-1; i >= 1; i--){
        P1[i] = P1[i-1];
    }
    P1[0] = id12[1];
    for(int i = 1; i <= 2; i++){
        id12[i] = id12[i+1];
    }
    

    poly P2 = conv(C, D);
    poly id1(3, 0);
    

    for(int i = 1; i <= 2; i++){
        for(int j = 0; j < m; j++){
            mi val = Cneg[i]*D[j];
            int ind = j-i;
            if(ind < 0){
                id1[-ind]+=val;
            }
            else{
                P2[ind]+=val;
            }
        }
    }
    

    

    for(int i = m-1; i >= 1; i--){
        P2[i] = P2[i-1];
    }
    P2[0] = id1[1];
    for(int i = 1; i <= 2; i++){
        id1[i] = id1[i+1];
    }
    

    poly E1 = ConstructE(P1);
    poly E2 = ConstructE(P2);
    for(int i = sz(E2)-1; i > 0; i--){
        E2[i] = E2[i-1];
    }
    E2[0] = 0;
    

    poly F(m, 0);
    for(int i = 0; i < m; i++){
        F[i] = mi(ifac[i]);
    }

    


    poly EF = conv(E1+E2, F);
    for(int i = 0; i <= n; i++){
        EF[i]*=mi(fac[i]);
    }
    poly sum(n+1, 0);
    for(int i = 0; i <= n; i++){
        sum[i]+=EF[i];
    }
    
    for(int i = 0; i <= n; i++){
        sum[i]*=mi(invs[n]);
    }
    

    return sum;
}

poly Zsolve(){
    poly C1, D1, C2, D2, id7, id8;
    poly id3 = {mi(1), mi(1)};

    id7 = poly(m, 0);
    id8 = poly(m, 0);
    for(int i = 1; i < m; i++){
        id7[i] = mi(invs[i]);
        if(i % 2 == 0){
            id7[i]*=mi(-1);
        }
    }
    for(int i = 1; i < m; i++){
        id8[i] = 1;
        if(i % 2 == 0){
            id8[i]*=mi(-1);
        }
    }
    


    poly id9 = poly{mi(1)}-(poly{1, 1})*(poly{mi(1)}-id7);
    poly id2 = conv(poly{mi(1)}-id8, poly{mi(1)}-conv(exp(id8, m), poly{mi(1)}-id8)); 


    id9.rsz(m);
    id2.rsz(m);
    

    assert(id9[0] == 0);
    assert(id9[1] == 0);
    assert(id9[2] != 0);
    assert(id2[0] == 0);
    assert(id2[1] == 0);
    assert(id2[2] != 0);

    for(int i = 0; i+2 < m; i++){
        id9[i] = id9[i+2];
        id2[i] = id2[i+2];
    }
    poly id11(3, 0), id0(3, 0);
    

    C1 = -poly{1, 1}*inv(id9, m); 

    

    D1 = id4(id7, -n);
    

    C2 = inv(id2, m); 

    D2 = poly(m, 0);

    for(int i = 0; i <= n; i++){
        D2[i] = mi(comb(n, i));
    }
    

    id11[2] = C1[0];
    id11[1] = C1[1];
    id0[2] = C2[0];
    id0[1] = C2[1];

    for(int i = 0; i+2 < m; i++){
        C1[i] = C1[i+2];
        C2[i] = C2[i+2];
    }

    

    poly Z1 = CDsolve(C1, D1, id11);
    poly Z2 = CDsolve(C2, D2, id0);

    

    poly Zcomb = Z1+Z2;
    Zcomb.rsz(m);
    return Zcomb;
}

poly solve(){

    poly ans = Zsolve();
    
    poly id5(m, 0);

    for(int i = 0; i <= n+2; i++){
        id5[i] = mi(comb(n+2, i));
        if(i % 2 == 1){
            id5[i]*=-1;
        }
    }
    ans = conv(ans, id5);
    ans.rsz(n+1);

    for(int i = 1; i <= n; i++){
        ans[i]*=mi(fac[n]);
    }
    return ans;
}

int main() {
    setIO();
    cin >> n;
    

    

    

    m = n+100; 

    genFac(2*m+5);

    poly FinalAnswer = solve();
    for(int i = 1; i <= n; i++){
        cout << FinalAnswer[i].v << " ";
    }
    cout << "\n";
    

    

    

}



