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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
template<class A, class B> A operator/=(A& l, const B& r) { return l = l/r; }

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

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modInt {
    T val;
    T mod = 0;
    


    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    modInt(T v = 0, T m = 0) : val(v), mod(m) { normalize(); }
    


    explicit operator T() const { return val; }
    friend ostream& operator<<(ostream& os, const modInt& a) { return os << a.val; }
    friend bool operator==(const modInt& a, const modInt& b) { return a.val == b.val; }
    friend bool operator!=(const modInt& a, const modInt& b) { return !(a == b); }

    friend void check(modInt& a, modInt& b) { 

        

        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        T mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    friend modInt operator+(modInt a, modInt b) {
        check(a,b); a.val += (T)b;
        if (a.val >= a.mod) a.val -= a.mod;
        return a;
    }
    friend modInt operator-(modInt a, modInt b) {
        check(a,b); a.val -= (T)b; 
        if (a.val < 0) a.val += a.mod; 
        return a;
    }
    friend modInt operator-(const modInt& a) { return modInt(0)-a; }

    friend modInt operator*(modInt a, modInt b) {
        check(a,b); a.val = (ll)a.val*(T)b%a.mod; return a;
    }
    friend modInt exp(modInt a, ll p) {
        modInt ans(1,a.mod);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modInt inv(const modInt& a) {
        return {invGeneral(a.val,a.mod),a.mod};
        

    }
    friend modInt operator/(modInt a, modInt b) { 
        check(a,b); return a*inv(b); 
    }
};

typedef modInt<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

namespace vecOp {
    template<class T> vector<T> rev(vector<T> v) { reverse(all(v)); return v; }
    template<class T> vector<T> shift(vector<T> v, int x) { v.insert(v.begin(),x,0); return v; }
    
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
    template<class T> vector<T> operator*(const vector<T>& l, const T& r) { return l*vector<T>(1,r);  }
    template<class T> vector<T> operator*(const T& r, const vector<T>& l) { return l*r; }
    template<class T> vector<T> operator/(vector<T> l, const T& r) { 
        F0R(i,sz(l)) l[i] /= r; 
        return l;
    }
    
    template<class T> vector<T> rem(vector<T> a,vector<T> b) { 
        while (sz(b) && b.back() == 0) b.pop_back();
        assert(sz(b)); b /= b.back();
        while (sz(a) >= sz(b)) {
            a -= a.back()*shift(b,sz(a)-sz(b));
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

    template<class T> void fwht(vector<T>& a) {
        int n = sz(a);
        
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit; if (i < j) swap(a[i], a[j]);
        }
        
        for (int len = 2; len <= n; len <<= 1) 
            for (int i = 0; i < n; i += len) 
                F0R(j,len/2) {
                    auto u = a[i+j], v = a[i+j+len/2];
                    a[i+j] = u+v, a[i+j+len/2] = u-v;
                }
    }
    
}

using namespace FFT;

int n,k,x,y,z, tot = 0;
vpi v;

int main() {
    setIO(); re(n,k,x,y,z);
    vmi e1(1<<k), e2(1<<k), e3(1<<k);
    F0R(i,n) {
        int a,b,c; re(a,b,c);
        tot ^= a; b ^= a; c ^= a; a = 0;
        v.pb({b,c});
        e1[b] += 1; e2[c] += 1; e3[b^c] += 1;
    }
    fwht(e1); fwht(e2); fwht(e3);
    vmi res(1<<k);
    F0R(i,1<<k) {
        mi a = (mi(n)+e1[i]+e2[i]+e3[i])/4;
        mi b = (mi(n)+e1[i]-e2[i]-e3[i])/4;
        mi c = (mi(n)-e1[i]+e2[i]-e3[i])/4;
        mi d = (mi(n)-e1[i]-e2[i]+e3[i])/4;
        res[i] = exp(mi(x)+y+z,(int)a);
        res[i] *= exp(mi(x)+y-z,(int)b);
        res[i] *= exp(mi(x)-y+z,(int)c);
        res[i] *= exp(mi(x)-y-z,(int)d);
    }
    fwht(res); trav(t,res) t /= 1<<k;
    F0R(i,1<<k) pr(res[i^tot],' ');
    

    

    

    

    

}


