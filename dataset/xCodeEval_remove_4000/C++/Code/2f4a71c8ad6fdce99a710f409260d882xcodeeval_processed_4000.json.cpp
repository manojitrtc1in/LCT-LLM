







using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<double> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


















const int MOD = (119 << 23) + 1, root = 3; 






const ll INF = 1e18;
const int MX = 200005;
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
    template<class T> void re(vector<T>& a) { id0(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id0(i,SZ) re(a[i]); }
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
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 

        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); 

    }
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

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    

    friend void pr(const modular& a) { pr(a.val); }
    friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } 

    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

namespace vecOp {
    template<class T> vector<T> rev(vector<T> v) { reverse(all(v)); return v; }
    template<class T> vector<T> shift(vector<T> v, int x) { v.insert(v.begin(),x,0); return v; }
    
    template<class T> vector<T>& operator+=(vector<T>& l, const vector<T>& r) {
        l.rsz(max(sz(l),sz(r))); id0(i,sz(r)) l[i] += r[i]; return l;
    }
    template<class T> vector<T>& operator-=(vector<T>& l, const vector<T>& r) {
        l.rsz(max(sz(l),sz(r))); id0(i,sz(r)) l[i] -= r[i]; return l;
    }
    template<class T> vector<T>& operator*=(vector<T>& l, const T& r) { trav(t,l) t *= r; return l;  }
    template<class T> vector<T>& operator/=(vector<T>& l, const T& r) { trav(t,l) t /= r; return l; }

    template<class T> vector<T> operator+(vector<T> l, const vector<T>& r) { return l += r; }
    template<class T> vector<T> operator-(vector<T> l, const vector<T>& r) { return l -= r; }
    template<class T> vector<T> operator*(vector<T> l, const T& r) { return l *= r; }
    template<class T> vector<T> operator*(const T& r, const vector<T>& l) { return l*r; }
    template<class T> vector<T> operator/(vector<T> l, const T& r) { return l /= r;  }

    template<class T> vector<T> operator*(const vector<T>& l, const vector<T>& r) {
        if (min(sz(l),sz(r)) == 0) return {};
        vector<T> x(sz(l)+sz(r)-1); id0(i,sz(l)) id0(j,sz(r)) x[i+j] += l[i]*r[j];
        return x;
    }
    template<class T> vector<T>& operator*=(vector<T>& l, const vector<T>& r) { return l = l*r; }
    
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
        id0(i,sz(v)) {
            vector<T> prod = {1};
            T todiv = 1;
            id0(j,sz(v)) if (i != j) {
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
    constexpr int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
    template<class T> bool small(const vector<T>& a, const vector<T>& b) { 
        return (ll)sz(a)*sz(b) <= 500000; 

    } 

    void genRoots(vmi& roots) { 

        int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
        roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
    }
    void genRoots(vcd& roots) { 

        int n = sz(roots); double ang = 2*PI/n;
        id0(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); 

    }
    template<class T> void fft(vector<T>& a, const vector<T>& roots, bool inv = 0) {
        int n = sz(a);
        for (int i = 1, j = 0; i < n; i++) { 

            int bit = n >> 1;
            for (; j&bit; bit >>= 1) j ^= bit;
            j ^= bit; if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) 
            for (int i = 0; i < n; i += len) 
                id0(j,len/2) {
                    int ind = n/len*j; if (inv && ind) ind = n-ind;
                    auto u = a[i+j], v = a[i+j+len/2]*roots[ind];
                    a[i+j] = u+v, a[i+j+len/2] = u-v;
                }
        if (inv) { T i = T(1)/T(n); trav(x,a) x *= i; }
    }

    template<class T> vector<T> mult(vector<T> a, vector<T> b) {
        int s = sz(a)+sz(b)-1, n = 1<<size(s);
        vector<T> roots(n); genRoots(roots);
        a.rsz(n), fft(a,roots); 
        b.rsz(n), fft(b,roots);
        id0(i,n) a[i] *= b[i];
        fft(a,roots,1); return a;
    }
    vcd smart(const vcd& a, const vcd& b) { return mult(a,b); }
    vd smart(const vd& a, const vd& b) {
        auto X = smart(vcd(all(a)),vcd(all(b)));
        vd x(sz(X)); id0(i,sz(X)) x[i] = X[i].real();
        return x;
    }
    vmi smart(const vmi& a, const vmi& b) { return mult(a,b); }
    vmi smart2(const vmi& a, const vmi& b) { 

        const int BIT = 15; 
        int s = sz(a)+sz(b)-1, n = 1<<size(s);
        vcd roots(n); genRoots(roots);
        
        vcd ax(n), bx(n);
        id0(i,sz(a)) {
            int A = (int)a[i];
            ax[i] = cd(A>>BIT, A&((1<<BIT)-1)); 

        }
        id0(i,sz(b)) {
            int B = (int)b[i];
            bx[i] = cd(B>>BIT, B&((1<<BIT)-1)); 

        }
        fft(ax,roots), fft(bx,roots);
        
        vcd v1(n), v0(n);
        id0(i,n) {
            int j = (i ? (n-i) : i);
            cd a1 = (ax[i]+conj(ax[j]))*cd(0.5, 0);  

            cd a0 = (ax[i]-conj(ax[j]))*cd(0, -0.5); 
            cd b1 = (bx[i]+conj(bx[j]))*cd(0.5, 0);  
            cd b0 = (bx[i]-conj(bx[j]))*cd(0, -0.5);
            v1[i] = a1*(b1+b0*cd(0,1));
            v0[i] = a0*(b1+b0*cd(0,1));
        }
        fft(v1,roots,1), fft(v0,roots,1);
        
        vmi ret(n);
        id0(i,n) {
            ll V2 = (ll)round(v1[i].real()); 

            ll V1 = (ll)round(v1[i].imag())+(ll)round(v0[i].real()); 

            ll V0 = (ll)round(v0[i].imag()); 

            ret[i] = ((((((V2%MOD)<<BIT)+V1)%MOD)<<BIT)+V0)%MOD;
        }
        ret.rsz(s); return ret;
    } 

    template<class T> vector<T> conv(const vector<T>& a, const vector<T>& b) {
        if (small(a,b)) return a*b;
        return smart(a,b);
    } 
}

using namespace FFT;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,t,x,dist[51];
int a[100],b[100],c[100];
vd tmp[100], p[100], pp[100];
vpi radj[51];
vi adj[51];
vd ans[51];

void divi(int L, int R) {
	if (L == R) {
		

		FOR(i,1,n) {
			double ret = INF;
			trav(t,adj[i]) ckmin(ret,c[t]+tmp[t][L]+pp[t][L+1]*(dist[b[t]]+x));
			ans[i].pb(ret);
		}
		ans[n].pb(0);
		return;
	}
	int M = (L+R)/2;
	divi(L,M);
	id0(i,m) {
		vd P(begin(p[i]),begin(p[i])+R-L+1);
		vd ANS(begin(ans[b[i]])+L,begin(ans[b[i]])+M+1);
		auto z = conv(P,ANS);
		FOR(j,M+1,R+1) tmp[i][j] += z[j-L];
	}
	

	divi(M+1,R);
}

int main() {
    setIO(); re(n,m,t,x);
    id0(i,m) {
    	re(a[i],b[i],c[i]);
    	radj[b[i]].pb({a[i],c[i]}); adj[a[i]].pb(i);
    	p[i].rsz(t+1); tmp[i].rsz(t+1);
    	FOR(j,1,t+1) {
    		re(p[i][j]);
    		p[i][j] /= 100000;
    	}
    	pp[i] = p[i]; pp[i].pb(0); F0Rd(j,t+1) pp[i][j] += pp[i][j+1];
    }
    priority_queue<pi,vpi,greater<pi>> pq; 
    FOR(i,1,n+1) dist[i] = MOD;
    pq.push({dist[n] = 0,n});
    while (sz(pq)) {
    	auto p = pq.top(); pq.pop(); if (p.f != dist[p.s]) continue;
    	trav(q,radj[p.s]) if (p.f+q.s < dist[q.f]) 
    		pq.push({dist[q.f] = p.f+q.s, q.f});
    }
    divi(0,t);
    cout << fixed << setprecision(9);
    ps(ans[1][t]);
    

}

