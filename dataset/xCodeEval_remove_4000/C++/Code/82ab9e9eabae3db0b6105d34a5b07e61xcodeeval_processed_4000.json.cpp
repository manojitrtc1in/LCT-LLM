



































using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
typedef string str;
typedef long double dbl;
struct LL {

    static ll m; 

    long long int val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static void setMod(ll m) { assert(m); LL::m = m; }

    static long long int reduce(ll x, ll md = m) {
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
ll LL::m = mod;

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



bool witness(LL a, ll d, ll m) {
    LL x = LL::exp(a,m);
    if (x==LL(1)) return 1;
    F0(r,d) {
        if (x==LL(-1)) return 1;
        x = x*x;
    }
    return 0;
}



bool isPrime(ll x) {
    if (x < T6) {
        int j = 2;
        while (j*j <= x) {
            if (x%j==0) return 0;
            ++j;
        }
        return 1;
    }
    ll d = 0;
    ll m = 0;
    ll y = x;
    ll cur = LL::m;
    LL::m = x;
    bool ret = 1;
    while (y>>=1) {
        ++d; if (y&1) break;
    }
    m = y;
    if (x < 1e12) {
        ret = witness(2,d,m)
            && witness(13,d,m)
            && witness(23,d,m)
            && witness(1662803,d,m);
    } else {
        ret = witness(2,d,m)
            && witness(3,d,m)
            && witness(5,d,m)
            && witness(7,d,m)
            && witness(11,d,m)
            && witness(13,d,m)
            && witness(17,d,m)
            && witness(19,d,m)
            && witness(23,d,m)
            && witness(29,d,m)
            && witness(31,d,m)
            && witness(37,d,m)
            && witness(41,d,m);
    }
    LL::m = cur;
    return ret;
}




ll gcd(ll a, ll b) {
    return b?gcd(b, a % b):a;
}

void precalc() {
}

void reset() {
}

bool cmp(pii a, pii b) {
    return 1;
}

pii pl(pii a, pii b) {
    return {a.f+b.f,a.s+b.s};
}
bool inrange(pii a) {
    return (a.f>=0)&&(a.f<N)&&(a.s>=0)&&(a.s<M);
}

int query(int k) {
    cout << "? " << k << endl; fl();
    return rd();
}

bool debug = 0;
struct Cheese {

    ll F(ll a, ll b) {
        return a+b;
    }

    int sz;
    vector<ll> ST;
    vector<ll> lazy;
    void start(int n) {
        sz = n;
        for (int i = 0; i < 4*n; i++) { ST.pb(0); lazy.pb(0); }
    }

    void build(ll * A, int idx, int b, int e) {
        lazy[idx]=0;
        if(b == e) {
            ST[idx] = A[b];
        } else {
            int mid = (b + e) / 2;
            build(A, 2*idx, b, mid);
            build(A, 2*idx+1, mid+1, e);
            ST[idx] = F(ST[2*idx],ST[2*idx+1]);
        }
    }
    void build(ll * A) { build(A, 1, 0, sz-1); }

    void update(int idx, int b, int e, int l, int r, ll val) {
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if(b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if ((b > e) || (b > r) || (e < l)) return;
        if ((b >= l) && (e <= r)) {
            ST[idx] += val;
            if (b != e) {
                lazy[idx*2] += val;
                lazy[idx*2+1] += val;
            }
            return;
        }
        int mid = (b + e) / 2;
        update(idx*2, b, mid, l, r, val);
        update(idx*2 + 1, mid + 1, e, l, r, val);
        ST[idx] = F(ST[idx*2],ST[idx*2+1]);
    }
    void update(int l, int r, ll val) { update(1,0,sz-1,l,r,val); }

    ll query(int idx, int b, int e, int l, int r) {
        if ((b > e) || (b > r) || (e < l)) return 0;
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if (b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(b >= l and e <= r) return ST[idx];
        int mid = (b + e) / 2;
        ll p1 = query(idx*2, b, mid, l, r);
        ll p2 = query(idx*2 + 1, mid + 1, e, l, r);
        return F(p1,p2);
    }
    ll query(int l, int r) { return query(1,0,sz-1,l,r); }
    ll query(int l) { return query(l,l); }

} ST;

ll A[H],pfx[H],pgx[H],phx[H],S;

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

int type(pii x) {
    int ret = !(x.f&1);
    if (x.s&1) ret = 3-ret;
    return ret;
}

void read() {
    N=rd();
    ll S = 0;
    map<pii,int> hsh;
    vector<pair<pii,ll>> tents;
    F0(i,N) {
        int a = rd(); int b = rd(); ll c = rd();
        hsh[{a,b}]=i+5;
        tents.pb({{a,b},c});
        S+=c;
        if(debug)cout << type({a,b}) << endl;
    }
    Dinic ANS;
    FE(x,tents) FE(y,tents) {
        if (type(x.f)+1==type(y.f)) {
            if (abs(x.f.f-y.f.f)<=1 && abs(x.f.s-y.f.s)<=1) {
            ANS.addEdge(hsh[x.f]+T3,hsh[y.f],INF);
            if(debug)ds(x.f); if(debug)ds(y.f); if(debug)cout << endl;
            if(debug)cout << hsh[x.f]+T3 << " " << hsh[y.f] << endl;
            }
        }
    }
    FE(x,tents) {
        ANS.addEdge(hsh[x.f],hsh[x.f]+T3,x.s);
            if(debug)ds(x.f); if(debug)cout << endl;
            if(debug)cout << hsh[x.f] << " " << hsh[x.f]+T3 << endl;
    }
    FE(x,tents) if (type(x.f)==0) {
        ANS.addEdge(1,hsh[x.f],INF);
        if(debug)cout << 1 << " " << hsh[x.f] << endl;
    }
    FE(x,tents) if (type(x.f)==3) {
        ANS.addEdge(hsh[x.f]+T3,2,INF);
        if(debug)cout << hsh[x.f]+T3 << " " << 2 << endl;
    }
    ds(S-ANS.flowIt(1,2));
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

}
