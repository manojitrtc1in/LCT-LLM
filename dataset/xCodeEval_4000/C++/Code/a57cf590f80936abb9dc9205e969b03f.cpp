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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 400005;
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
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); } 
    

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

template<class T, int SZ> struct RMQ {
    int stor[SZ][32-__builtin_clz(SZ)];
    vector<T> x;
    
    int comb(int a, int b) {
        return x[a] < x[b] ? a : b;
    }
    
    void build(const vector<T>& _x) {
        x = _x; F0R(i,sz(x)) stor[i][0] = i;
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

struct LCP {
    string S; int N;
    vi sa, inv, lcp;
    RMQ<int,MX> R; 
    
    void suffixArray() { 

        sa.resz(N); vi classes(N);
        F0R(i,N) sa[i] = N-1-i, classes[i] = S[i];
        stable_sort(all(sa), [this](int i, int j) { return S[i] < S[j]; });
        for (int len = 1; len < N; len *= 2) { 
            vi c(classes);
            F0R(i,N) { 

                bool same = i && sa[i-1] + len < N
                              && c[sa[i]] == c[sa[i-1]]
                              && c[sa[i]+len/2] == c[sa[i-1] + len/2];
                classes[sa[i]] = same ? classes[sa[i-1]] : i;
            }
            vi nex(N), s(sa); F0R(i,N) nex[i] = i; 

            F0R(i,N) {
                int s1 = s[i]-len;
                if (s1 >= 0) sa[nex[classes[s1]]++] = s1; 

            }
        }
    }
    
    void lcpArray() { 

        int h = 0;
        inv.resz(N), lcp.resz(N); F0R(i,N) inv[sa[i]] = i; 

        F0R(i,N) if (inv[i]) {
            int pre = sa[inv[i]-1];
            while (max(i,pre)+h < N && S[i+h] == S[pre+h]) h++;
            lcp[inv[i]] = h; 

            if (h) h--; 

        }
    }
    
    void init(string _S) {
        S = _S; N = sz(S);
        suffixArray(); lcpArray();
        R.build(lcp);
    }
    
    int getLCP(int a, int b) {
        if (max(a,b) >= N) return 0;
        if (a == b) return N-a;
        int t0 = inv[a], t1 = inv[b];
        if (t0 > t1) swap(t0,t1);
        return R.query(t0+1,t1);
    }
};

LCP L;

int nex = 1, rev[MX];
vpi child[MX];

pl operator+(const pl& l, const pl& r) { return {l.f+r.f,l.s+r.s}; }
pl operator-(const pl& l, const pl& r) { return {l.f-r.f,l.s-r.s}; }
pl& operator+=(pl& l, const pl& r) { return l = l+r; }
pl& operator-=(pl& l, const pl& r) { return l = l-r; }

template <class T, int ...Ns> struct BIT {
    T val = {0,0};
    void upd(T v) { val += v; }
    T query() { return val; }
};

template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
    BIT<T,Ns...> bit[N + 1];
    template<typename... Args> void upd(int pos, Args... args) {
        for (; pos <= N; pos += (pos&-pos)) bit[pos].upd(args...);
    }
    template<typename... Args> T sum(int r, Args... args) {
        T res = {0,0}; for (; r; r -= (r&-r)) res += bit[r].query(args...); 
        return res;
    }
    template<typename... Args> T query(int l, int r, Args... args) {
        return sum(r,args...)-sum(l-1,args...);
    }
}; 



namespace treap {
    typedef struct tnode* pt;
    
    struct tnode {
        int pri, val; pt c[2]; 

        int sz; ll sum; 

        bool flip; 

    
        tnode (int _val) {
            pri = rand()+(rand()<<15); val = _val; c[0] = c[1] = NULL;
            sz = 1; sum = val;
            flip = 0;
        }
    };
    
    int getsz(pt x) { return x?x->sz:0; }
    ll getsum(pt x) { return x?x->sum:0; }
    
    pt prop(pt x) {
        if (!x || !x->flip) return x;   
        swap(x->c[0],x->c[1]);
        x->flip = 0;
        F0R(i,2) if (x->c[i]) x->c[i]->flip ^= 1;
        return x;
    }
    
    void tour(pt x, vi& v) {
        if (!x) return;
        prop(x);
        tour(x->c[0],v); v.pb(x->val); tour(x->c[1],v);
    }
    
    pt calc(pt x) {
        assert(!x->flip);
        prop(x->c[0]), prop(x->c[1]);
        x->sz = 1+getsz(x->c[0])+getsz(x->c[1]);
        x->sum = x->val+getsum(x->c[0])+getsum(x->c[1]);
        return x;
    }
    
    pair<pt,pt> split(pt t, int v) { 

        if (!t) return {t,t};
        prop(t);
        if (t->val >= v) {
            auto p = split(t->c[0], v); t->c[0] = p.s;
            return {p.f, calc(t)};
        } else {
            auto p = split(t->c[1], v); t->c[1] = p.f;
            return {calc(t), p.s};
        }
    }
    
    pair<pt,pt> splitsz(pt t, int sz) { 

        if (!t) return {t,t};
        prop(t);
        if (getsz(t->c[0]) >= sz) {
            auto p = splitsz(t->c[0], sz); t->c[0] = p.s;
            return {p.f, calc(t)};
        } else {
            auto p = splitsz(t->c[1], sz-getsz(t->c[0])-1); t->c[1] = p.f;
            return {calc(t), p.s};
        }
    }
        
    pt merge(pt l, pt r) {
        if (!l || !r) return l ? l : r;
        prop(l), prop(r);
        pt t;
        if (l->pri > r->pri) l->c[1] = merge(l->c[1],r), t = l;
        else r->c[0] = merge(l,r->c[0]), t = r;
        return calc(t);
    }
    
    pt ins(pt x, int v) { 

        auto a = split(x,v), b = split(a.s,v+1);
        return merge(a.f,merge(new tnode(v),b.s));
    }
    
    pt del(pt x, int v) { 

        auto a = split(x,v), b = splitsz(a.s,1);
        return merge(a.f,b.s);
    }
    
    ll get(pt a, ll b) {
        auto A = split(a,b);
        ll res = A.s ? A.s->sz*b-A.s->sum : 0;
        a = merge(A.f,A.s); return res;
    }
}

using namespace treap;

vpi mod1[MX], mod2[MX];

template<int SZ, bool VALUES_IN_EDGES> struct HLD { 
    int N; 
    int par[SZ], sz[SZ], depth[SZ], ad[SZ];
    int root[SZ], pos[SZ], rpos[SZ];
    pt dumb[MX];
    BIT<pl,SZ> B;

    void dfs_sz(int v = 0) {
        sz[v] = 1;
        trav(u,child[v]) {
            par[u.f] = v; depth[u.f] = depth[v]+u.s;
            dfs_sz(u.f); sz[v] += sz[u.f];
            if (sz[u.f] > sz[child[v][0].f]) swap(u, child[v][0]);
        }
    }
    
    int t = 1;
    void dfs_hld(int v = 0) {
        pos[v] = t; rpos[t] = v; t++;
        trav(u,child[v]) {
            root[u.f] = ((u == child[v][0] && v) ? root[v] : u.f);
            dfs_hld(u.f);
        }
    }
    
    void init(int _N) {
        N = _N; par[0] = depth[0] = 0; root[0] = 0; 
        dfs_sz(); dfs_hld();
    }

    template <class BinaryOperation>
    void processPath(int v, BinaryOperation op) {
        for (; root[v]; v = par[root[v]]) op(root[v],v);
    }

    
    
    void upd1(int x) {
        processPath(x,[this](int a, int b) {
            ad[a] ++; B.upd(pos[b],mp(-1,depth[b]-depth[par[a]]));
        });
    }
    
    void upd2(pi t, int z = 1) { 

        int b = t.s, a = root[b];
        ad[a] += z; 

        int d = t.f+depth[par[a]];
        if (z == 1) dumb[a] = ins(dumb[a],d); 

        else dumb[a] = del(dumb[a],d);
        

    }
    
    void upd3(pi t) { 

        int b = t.s, a = root[b];
        ad[a] ++; B.upd(pos[b],mp(-1,depth[b]-depth[par[a]]));
    }
    void upd9(int v, int x) {
        processPath(x,[&v,this](int a, int b) {
            

            mod1[v+depth[par[a]]+1].pb({v,b});
            mod2[v+depth[b]].pb({v,b});
            

            

        });
    }
    
    int fst(int l, int r, int maxDepth) {
        while (l < r) {
            int m = (l+r)/2;
            if (depth[rpos[m]] >= maxDepth) r = m;
            else l = m+1;
        }
        return l;
    }
    ll qsum1(int v, int maxDepth) { 

        ll ans = 0;
        processPath(v,[this,&maxDepth,&ans](int a, int b) {
            if (maxDepth <= depth[par[a]]) return;
            ckmin(maxDepth,depth[b]); assert(pos[a]);
            auto res = B.query(pos[a],fst(pos[a],pos[b],maxDepth)-1); res.f += ad[a]; 

            ans += res.f*(maxDepth-depth[par[a]])+res.s;
            

            

            

            

        });
        return ans;
    }
    ll qsum2(int v, int maxDepth, int r) { 

        ll ans = 0;
        processPath(v,[this,&maxDepth,&r,&ans](int a, int b) {
            if (maxDepth <= depth[par[a]]) return;
            ckmin(maxDepth,depth[b]); assert(pos[a]);
            auto res = B.query(pos[a],fst(pos[a],pos[b],maxDepth)-1); res.f += ad[a]; 

            ans += res.f*(maxDepth-depth[par[a]])+res.s;
            ans += get(dumb[a],r-(maxDepth-depth[par[a]]));
            

            

            

            

        });
        return ans;
    }
};

HLD<MX,1> H;

string s; int q, N;

int divi(int cur, int pre, int l, int r) {
    if (l == r) {
        int len = N-L.sa[l];
        if (len != pre) {
            child[cur].pb({nex,len-pre}); cur = nex++;
        }
        rev[L.sa[l]] = cur;
        return cur;
    }
    int t = L.R.query(l+1,r);
    

    if (L.lcp[t] != pre) {
        child[cur].pb({nex,L.lcp[t]-pre}); cur = nex++;
        pre = L.lcp[t];
    }
    divi(cur,pre,l,t-1); divi(cur,pre,t,r);
    return cur;
} 


void init() {
	re(s,q); N = sz(s); L.init(s); 
	divi(0,0,0,N-1);
	
} 


vector<array<int,3>> neg[MX], pos[MX]; 

ll ans[MX];

void processL() {
    

    

    H = HLD<MX,1>(); H.init(nex);
	F0R(i,N) {
	    trav(t,neg[i]) ans[t[0]] -= H.qsum1(t[1],t[2]);
	    H.upd1(rev[i]); 

	}
	
}

void processR() {
    H = HLD<MX,1>(); H.init(nex);
    F0R(i,N) H.upd9(i,rev[i]); 

    FOR(i,1,MX) {
        

        trav(t,mod1[i]) H.upd2(t,1); 

        

        trav(t,mod2[i]) H.upd2(t,-1), H.upd3(t); 

        

        trav(t,pos[i]) ans[t[0]] += H.qsum2(t[1],t[2],i);
    }
    

    

    

    

    

}

int main() {
    init();
	F0R(i,q) {
	    int l,r; re(l,r); l--,r--;
	    neg[l].pb({i,rev[l],r-l+1}); 

	    pos[r+1].pb({i,rev[l],r-l+1}); 

	}
	processL(); processR();
	F0R(i,q) ps(ans[i]);
    

} 


