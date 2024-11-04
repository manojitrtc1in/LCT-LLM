#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = (119 << 23) + 1, root = 3; 






const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); } 
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); 

    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); 

        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

    }
}

using namespace io;

int invGeneral(int a, int b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    int x = invGeneral(b,a); return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

struct mi {
    int val;
    int mod = 0;
    


    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    mi(int v = 0, int m = 0) : val(v), mod(m) { normalize(); }
    


    explicit operator int() const { return val; }
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }

    void check(mi& b) { 

        

        mi& a = *this;
        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        int mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    mi& operator+=(mi b) { check(b); val += int(b); if (val >= mod) val -= mod; return *this; }
    mi& operator-=(mi b) { check(b); val -= int(b); if (val < 0) val += mod; return *this; }
    mi& operator*=(mi b) { check(b); val = (ll)val*int(b)%mod; return *this; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator-(const mi& a) { return mi(0)-a; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi exp(mi b, ll p) {
        mi ans = mi(1,b.mod);
        for (; p; p /= 2, b *= b) if (p&1) ans *= b;
        return ans;
    }

    friend mi inv(const mi& b) {
        return {invGeneral(b.val,b.mod),b.mod};
        

    }
    mi& operator/=(mi b) { check(b); return *this *= inv(b); }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
vmi toVmi(vi v) { vmi V(sz(v)); F0R(i,sz(V)) V[i] = v[i]; return V; }
vi toVi(vmi V) { vi v(sz(V)); F0R(i,sz(v)) v[i] = int(V[i]); return v; }

namespace vecOp {
	template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
	template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
	template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
	
    template<class T> vector<T> rev(vector<T> v) { reverse(all(v)); return v; }
    template<class T> vector<T> operator+(vector<T> l, const vector<T>& r) {
        l.resz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i];
        return l;
    }
    template<class T> vector<T> operator-(vector<T> l, const vector<T>& r) {
        l.resz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i];
        return l;
    }
    template<class T> vector<T> operator*(const vector<T>& l, const vector<T>& r) {
        if (min(sz(l),sz(r)) == 0) return {};
        vector<T> x(sz(l)+sz(r)-1); F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
        return x;
    }
    template<class T> vector<T> operator*(const vector<T>& l, const T& r) { 
        vector<T> v = {r}; return l*v; 
    }
    template<class T> vector<T> operator*(const T& l, const vector<T>& r) { 
    	return r*l;
    }
    
    template<class T> vector<T> rem(vector<T> a,vector<T> b) { 
        while (sz(b) && b.back() == 0) b.pop_back();
        assert(sz(b)); b *= inv(b.back());
        while (sz(a) >= sz(b)) {
            auto k = a.back();
            F0R(i,sz(b)) a[sz(a)-sz(b)+i] -= k*b[i];
            while (sz(a) && a.back() == 0) a.pop_back();
        }
        return a;
    }
    template<class T> vector<T> interpolate(vector<pair<T,T>> v) {
        vector<T> ret;
        F0R(i,sz(v)) {
            vector<T> prod = {1};
            T todiv = 1;
            F0R(j,sz(v)) if (i != j) {
                todiv *= v[i].f-v[j].f;
                vector<T> tmp = {-v[j].f,1}; prod *= tmp;
            }
            ret += prod*(v[i].s/todiv);
        }
        return ret;
    }
}





using namespace vecOp;

namespace FFT {
    int size(int s) { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }

    template<class T> void fft(vector<T>& a, vector<T>& roots) {
        int n = sz(a);
        
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit; if (i < j) swap(a[i], a[j]);
        }
        
        for (int len = 2; len <= n; len <<= 1) 
            for (int i = 0; i < n; i += len) 
                F0R(j,len/2) {
                    auto u = a[i+j], v = a[i+j+len/2]*roots[n/len*j];
                    a[i+j] = u+v, a[i+j+len/2] = u-v;
                }
    }
    
    void genRoots(vmi& roots) {
        int n = sz(roots); mi r = exp(mi(root),(MOD-1)/n);
        roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
    }
    void genRoots(vcd& roots) {
    	int n = sz(roots); ld ang = 2*PI/n;
        F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); 

    }
    
    template<class T> vector<T> conv(vector<T> a, vector<T> b) {
        int s = sz(a)+sz(b)-1, L = size(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return a*b;
    	vector<T> roots(n); genRoots(roots);
    	
        a.resz(n), fft(a,roots); b.resz(n), fft(b,roots);
        F0R(i,n) a[i] *= b[i];
        reverse(beg(roots)+1,en(roots)); fft(a,roots); 
        
        T in = T(1)/T(n); trav(x,a) x *= in;
        a.resz(s); return a;
    } 
    
    vi convMOD(const vi& a, const vi& b) { 
    	return toVi(conv(toVmi(a),toVmi(b))); 
    }
    vl convl(const vl& a, const vl& b) { 
        vcd X = conv(vcd(all(a)),vcd(all(b)));
        vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
        return x;
    } 

    vl convMod(const vl& a, const vl& b, ll mod) { 

        int s = sz(a)+sz(b)-1, L = size(s), n = 1<<L;
        
        vcd v1(n), v2(n), r1(n), r2(n);
        F0R(i,sz(a)) v1[i] = cd(a[i] >> 15, a[i] & 32767);
        F0R(i,sz(b)) v2[i] = cd(b[i] >> 15, b[i] & 32767);
        
        vcd roots(n); genRoots(roots);
        fft(v1,roots), fft(v2,roots);
        F0R(i,n) {
            int j = (i ? (n - i) : i);
            cd ans1 = (v1[i] + conj(v1[j])) * cd(0.5, 0);
            cd ans2 = (v1[i] - conj(v1[j])) * cd(0, -0.5);
            cd ans3 = (v2[i] + conj(v2[j])) * cd(0.5, 0);
            cd ans4 = (v2[i] - conj(v2[j])) * cd(0, -0.5);
            r1[i] = (ans1 * ans3) + (ans1 * ans4) * cd(0, 1);
            r2[i] = (ans2 * ans3) + (ans2 * ans4) * cd(0, 1);
        }
        reverse(beg(roots)+1,en(roots));
        fft(r1,roots), fft(r2,roots); F0R(i,n) r1[i] /= n, r2[i] /= n;
        
        vl ret(n);
        F0R(i,n) {
            ll av = (ll)round(r1[i].real());
            ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
            ll cv = (ll)round(r2[i].imag());
            av %= mod, bv %= mod, cv %= mod;
            ret[i] = (av << 30) + (bv << 15) + cv;
            ret[i] = (ret[i]%mod+mod)%mod;
        }
        
        ret.resz(s); return ret;
    } 

}

using namespace FFT;

namespace FFTextend { 
    vmi inv(vmi v, int p) { 

        v.resize(p); if (p == 1) return {1};
        

        if (p&1) { 

            mi cur = 0; auto V = inv(v,p-1);
            F0R(i,p-1) if (p-1-i < sz(v)) cur -= V[i]*v[p-1-i];
            V.pb(cur); return V;
        }
        vmi a = inv(v,p/2);
        vmi h0 = vmi(v.begin(),v.begin()+p/2);
        vmi h1 = vmi(v.begin()+p/2,v.end());
        vmi c = conv(a,h0); c = vmi(c.begin()+p/2,c.end()); 
        

        
        vmi b = conv(mi(-1)*a,conv(h1,a)+c); b.resz(p/2); 
        a.insert(a.end(),all(b)); return a;
    }
    
    pair<vmi,vmi> divmi(vmi f, vmi g) { 

        if (sz(f) < sz(g)) return {{},f};
        vmi q = conv(inv(rev(g),sz(f)-sz(g)+1),rev(f));
        q.resz(sz(f)-sz(g)+1); q = rev(q);
        vmi r = f-conv(q,g); r.resize(sz(g)-1);
        return {q,r};
    }
    
    vmi sqrt(vmi v, int p) { 

        v.resz(p);
        if (p == 1) return {1};
        vmi S = sqrt(v,p/2);
        vmi ans = S+conv(v,inv(S,p));
        while (sz(ans) > p) ans.pop_back();
        ans *= mi(1)/2;
        return ans;
    }
    
    vmi poly[1<<19];
    
    void precompute(int ind, vmi vals) { 
        if (sz(vals) == 1) { poly[ind] = {-vals[0],1}; return; }
        int m = sz(vals)/2;
        precompute(2*ind,vmi(vals.begin(),vals.begin()+m));
        precompute(2*ind+1,vmi(vals.begin()+m,vals.end()));
        poly[ind] = conv(poly[2*ind],poly[2*ind+1]);
    }
    
    void eval(int ind, vmi p, vmi& ans) { 

        p = divmi(p,poly[ind]).s;
        if (sz(poly[ind]) == 2) { ans.pb(p[0]); return; }
        eval(2*ind,p,ans); eval(2*ind+1,p,ans);
    }
}

using namespace FFTextend;


int n,m;
vmi c(100001);



int main() {
    

    setIO(); re(n,m);
    F0R(i,n) {
        int C; re(C);
        c[C] = (int)c[C]+1;
    }
    c = vmi(1,1)-mi(4)*c;
    c = vmi(1,1)+sqrt(c,1<<17);
    c = inv(c*(mi(1)/2),1<<17);
    FOR(i,1,m+1) ps(c[i]);
    
    

}



