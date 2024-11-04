





































using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
typedef string str;
typedef long double dbl;
struct LL {

    static ll m; 

    ll val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static void setMod(ll m) { assert(m); LL::m = m; }

    static ll reduce(ll x, ll md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator!=(const LL& b) { return val!=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const ll& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const ll& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const ll& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const ll& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const ll& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const ll& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const ll& y){
        ll z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(ll y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const ll& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const ll& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
ll LL::m = MOD;

typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<dbl,dbl> pdd;
using namespace std;






























ll cases,N,M,Q,K,X,Y;





ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
tc(T) void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
tc(T) void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
    if (E == -18852946) E = sz-1;
    adj.clear();
    F0(i,sz+1) adj.pb(vector<T>());
    F0(i,E) {
        T a = rd(); T b = rd();
        adj[a].pb(b); adj[b].pb(a);
    }
}
tcc(S,T) void rdv(vector<S>& vec, T* sz, bool flag = 1) {
    if (flag) *sz = rd();
    F0(i,*sz) vec.pb(rd());
}

void fl() {cout.flush();}
void ds(int v) { cout << v << " "; }
void ds(ll v) { cout << v << " "; }
void ds(LL v) { cout << v << " "; }
void ds(dbl v) { cout << v << " "; }
void ds(char v) { cout << v << " "; }
void ds(str v) { cout << v << " "; }
void ds(char* v) { cout << v << " "; }
tc(T) void ds(T* v, int t) {
    auto x = v;
    F0(i,t) ds(*(x++)); cout << endl;
}
tcc(S,T) void ds(pair<S,T> v) {cout << "( "; ds(v.f); cout << ", "; ds(v.s); cout << ") ";}
tc(T) void ds(vector<T> v) { FE(x,v) ds(x); cout << endl; }
tc(T) void panic(T out) { ds(out); exit(0); }

tcc(S,T) bool updmin(S &a, T b) {
    S B = (S)b;
    if (B < a) {a = B; return 1;}
    return 0;
}

tcc(S,T) bool updmax(S &a, T b) {
    S B = (S)b;
    if (B > a) {a = B; return 1;}
    return 0;
}

tcc(S,T) S min(S a, T b) {
    S c = a; updmin(c, b); return c;
}

tcc(S,T) S max(S a, T b) {
    S c = a; updmax(c, b); return c;
}

ll mulmod(ll a, ll b, ll m) {
    ll ret = 0;
    

    while (b > 0) {
        if (b % 2 == 1) ret += a;
        ret = ret%m;
        b /= 2;
        a += a;
        a = a%m;
    

    }
    

    return ret;
}

ll power(ll a, ll n, ll m) {
    ll cur = a;
    ll result = 1ll;
        

    while (n > 0) {
        if (n % 2 == 1) result = mulmod(result,cur,m);
        cur = mulmod(cur,cur,m);
        n /= 2;
        

    }
    

    return result;
}

bool witness(ll n, ll s, ll d, ll a) {
    

    ll x = power(a, d, n);
    

    if (x==1 || x==n-1) return true;
    F0(i,s-1) {
        x = power(x,x,n);
        

        if (x == n-1) return true;
    }
    return false;
}

bool isPrime(ll n) {
    if (((!(n % 2 == 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3ll)
        return true;

    ll d = n / 2;
    ll s = 1;
    while (d % 2 == 0) {
        d /= 2;
        ++s;
    }
    


    if (n < 1373653ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 3ll);
    if (n < 9080191ll)
        return witness(n, s, d, 31ll) && witness(n, s, d, 73ll);
    if (n < 4759123141ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 7ll) && witness(n, s, d, 61ll);
    if (n < 1122004669633ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 13ll) && witness(n, s, d, 23ll) && witness(n, s, d, 1662803ll);
    if (n < 2152302898747ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 3ll) && witness(n, s, d, 5ll) && witness(n, s, d, 7ll) && witness(n, s, d, 11ll);
    if (n < 3474749660383ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 3ll) && witness(n, s, d, 5ll) && witness(n, s, d, 7ll) && witness(n, s, d, 11ll) && witness(n, s, d, 13ll);
    return witness(n, s, d, 2ll) && witness(n, s, d, 3ll) && witness(n, s, d, 5ll) && witness(n, s, d, 7ll) && witness(n, s, d, 11ll) && witness(n, s, d, 13ll) && witness(n, s, d, 17ll)
     && witness(n, s, d, 19ll) && witness(n, s, d, 23ll) && witness(n, s, d, 29ll) && witness(n, s, d, 31ll) && witness(n, s, d, 37ll);
}

ll gcd(ll a, ll b) {
    return b?gcd(b, a%b):a;
}

ll id0(ll n, ll attempt = 7) {
    if (attempt == 0) return n;
    if (n==1) return n;
    if (n % 2 == 0) return 2;
    ll x = (mr()%(n-2))+2;
    ll y = x;
    ll c = (mr()%(n-1))+1;
    ll d = 1;
    int failure = 40000; 

    while (d==1) {
        if (failure == 0) return n;
        failure--;
        x = (power(x, 2, n) + c + n)%n;
        y = (power(y, 2, n) + c + n)%n;
        y = (power(y, 2, n) + c + n)%n;
        d = gcd(abs(x-y), n);
        if (d==n) return id0(n,attempt-1);
    }
    return d;
}

map<ll,int> pf;

void factorize(ll n) {
    if (n==1) return;
    else if (isPrime(n)) pf[n]++;
    else if (n < 1e12) {
        for (ll i = 2; i*i<=n; i++) {
            if (n%i==0) {
                pf[i]++;
                factorize(n/i);
                return;
            }
        }
        pf[n]++;
    } else {
        ll d = id0(n);
        if (d==n) {
            pf[d]++;
            return;
        }
        factorize(d);
        factorize(n/d);
    }
}











pii pl(pii a, pii b) {
    return {a.f+b.f,a.s+b.s};
}
bool inrange(pii a, int K) {
    return (a.f>=0)&&(a.f<=K)&&(a.s>=0)&&(a.s<=K);
}

int query(int k) {
    cout << "? " << k << endl; fl();
    return rd();
}

bool debug = 0;

void precalc() {
    debug=0;
}

struct WIP {

struct Splay {

    int val;
    Splay *L,*R,*P,*PP;

    Splay() { L=R=P=PP=nullptr; }
    Splay(int _val) : val(_val) { L=R=P=PP=nullptr; }

    bool isR() {
        return P->R==this;
    }

    void setL(Splay* const C) {
        if (C!=nullptr) C->P=this;
        L=C;
    }

    void setR(Splay* const C) {
        if (C!=nullptr) C->P=this;
        R=C;
    }

	void rotate() {
		const auto p = P;
		const bool i = isR();

		if (p->P != nullptr) {
			if (p->isR()) p->P->setR(this);
			else p->P->setL(this);
		} else P = nullptr;

		if (i) {
            p->setR(L);
            setL(p);
		} else {
		    p->setL(R);
		    setR(p);
		}

		PP=p->PP;
	}

	void yeet() {
	    for (;P!=nullptr;rotate()) {
            if (P->P!=nullptr) {
                if (isR() == P->isR()) P->rotate();
                else this->rotate();
            }
            if(debug) {this->print(); cout << endl;}
	    }
	}

	void print() {
	    cout << val << "[";
	    if (L) cout << L->val; cout << ",";
	    if (R) cout << R->val; cout << "]" << endl;
	    if (L) L->print();
	    if (R) R->print();
	}

};

Splay* access(Splay* V) {
    V->yeet();
    if (V->R != nullptr){
        V->R->PP = V;
        V->R->P = nullptr;
    }
    V->R = nullptr;
    Splay* P = V;
    while (V->PP != nullptr) {
        P = V->PP;
        P->yeet();
        if (P->R != nullptr){
            P->R->PP = P;
            P->R->P = nullptr;
        }
        P->setR(V);
        V->PP = nullptr;
        V->yeet();
    }
    return P;
}

Splay* root(Splay* V) {
    access(V);
    for (;V->L != nullptr; V=V->L);
    access(V);
    return V;
}

void cut(Splay* V) {
    access(V);
    if (V->L == nullptr) return;
    V->L->P=nullptr;
    V->L=nullptr;
}

Splay* lca(Splay* U, Splay* V) {
    if (root(U) != root(V)) return nullptr;
    access(U);
    return access(V);
}

void link(Splay* U, Splay* V) {
    if (lca(U,V)==V) link(V,U);
    else {
        access(V);
        access(U);
        V->setL(U);
    }
}

void cut(Splay* U, Splay* V) {
    if (lca(U,V)==U) cut(V);
    else cut(U);
}

bool conn(Splay* U, Splay* V) {
    return (root(U) == root(V));
}

};


struct Edge{
    long long v, flow, C, rev;
};
struct Dinic {
    long long level [2050], start [2050], cache [2050];
    vector<Edge> adj [2050];
    void addEdge(int u, int v, long long C){
        Edge a{v, 0, C, (long long)adj[v].size()};
        Edge b{u, 0, 0, (long long)adj[u].size()};
        adj[u].pb(a); adj[v].pb(b);
    }
    bool BFS(int s, int t){
        for(int i = 0; i < 2050; i++) level[i] = -1;
        queue<int> q; level[s] = 0; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto e: adj[u])
                if(level[e.v] < 0  && e.flow < e.C){
                    level[e.v] = level[u]+1;
                    q.push(e.v);
                }
        }
        return level[t] != -1;
    }
    long long sendFlow(int u, long long flow, int t){
        if(u == t) return flow;
        for(  ; start[u] < adj[u].size(); start[u] ++){
            Edge &e = adj[u][start[u]];
            if(level[e.v] == level[u]+1 && e.flow < e.C){
                long long curr_flow = min(flow, e.C-e.flow);
                long long temp_flow = sendFlow(e.v, curr_flow, t);
                if(temp_flow > 0){
                    e.flow += temp_flow;
                    adj[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }
    long long flowIt(int s, int t){
        if(s == t) return -1;
        long long total = 0;
        while(BFS(s, t)){
            for(int i = 0; i < 2050; i++) start[i] = 0;
            while (long long flow = sendFlow(s, INF, t)) total += flow;
        }
        return total;
    }
};


pair<pll,ll> F(pair<pll,ll> a, pair<pll,ll> b) {
    return {{max(a.f.f,b.f.f),max(a.f.s,b.f.s)},max(max(a.s,b.s),a.f.f+b.f.s)};
}
ll F(ll a, ll b) {
    return max(a,b);
}

template<typename T>
struct ST {

	int sz;
	vector<T> st;
	T def; 


	ST(int n, T def) {
	    st = vector<T>();
	    this->def = def;
	    start(n);
    }
	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++)
            st.pb(def);
    }

	void lift(int idx) {
	    st[idx] = F(st[2*idx],st[2*idx+1]);
    }

	void update(int idx, T x) {
		idx += sz;
		st[idx] = x;
		idx >>= 1;
		while (idx) {
            lift(idx); idx >>= 1;
		}
	}

	T query(int lp, int rp) {
		T a = def;
		T b = def;
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F(a,st[lp++]);
			if (rp&1) b = F(st[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F(a,b);
	}

};

vector<ll> pfx,pgx,phx;
vector<pll> qs[5*H5];
void read() {
    N = rd(); Q = rd();
    pfx.pb(0); F0(i,N) pfx.pb(pfx[i]+rd());
    pgx.pb(0); F0(i,N) pgx.pb(pgx[i]+rd());
    phx.pb(0); F0(i,N) phx.pb(phx[i]+rd());
    F0(i,Q) {
        ll L = rd(); ll R = rd();
        qs[R].pb({L,rd()});
    }
    F1(i,N) srt(qs[i]);
    ST<ll> A(N+5,-LNF);
    ST<ll> B(N+5,-LNF);
    ST<pair<pll,ll>> C(N+5,{{-LNF,-LNF},-LNF});
    ST<pair<pll,ll>> D(N+5,{{-LNF,-LNF},-LNF});
    F1(i,N) A.update(i,pfx[i]-pgx[i-1]);
    F1(i,N) {
        FE(x,qs[i]) {
            ll v = B.query(i,i);
            updmax(v,B.query(x.f-1,i-1)-x.s);
            updmax(v,A.query(x.f,i)-x.s);
            B.update(i,v);
        }
    }
    F1(i,N) C.update(i,{{B.query(i,i),pgx[i]-phx[i-1]},B.query(i,i)+pgx[i]-phx[i-1]});
    F1(i,N) D.update(i,{{A.query(i,i),pgx[i]-phx[i-1]},A.query(i,i)+pgx[i]-phx[i-1]});
    ll ans = -LNF;
    F1(i,N) FE(x,qs[i]) {
        updmax(ans,C.query(x.f-1,i).s-x.s);
        updmax(ans,D.query(x.f,i).s-x.s);
    }
    cout << ans + phx[N] << endl;
}

int main() {

    precalc();

    bool trials = 0;
    bool interactive = 0;

    if (!interactive) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {
        read();
    }

    return 0;
}
