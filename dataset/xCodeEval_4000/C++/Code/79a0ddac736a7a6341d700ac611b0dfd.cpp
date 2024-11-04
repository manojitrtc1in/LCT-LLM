

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>


using namespace std;


using ll = long long;
ll mod=1000000007;
ll *fact, *ifact;

using cd = complex<long double>;
const long double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        long double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;

    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < (int) adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};



template<typename flow_t, typename cost_t>
struct MinCostMaxFlow {
    static const flow_t FLOW_INF = numeric_limits<flow_t>::max() / 2;
    const cost_t COST_INF = numeric_limits<cost_t>::max() / 2;
    struct edge {
        int node, rev;
        flow_t capacity;
        cost_t cost;

        edge(int _node = -1, int _rev = -1, flow_t _capacity = 0, cost_t _cost = 0)
                : node(_node), rev(_rev), capacity(_capacity), cost(_cost) {}
    };

    int V = -1;
    vector<vector<edge>> adj;
    vector<cost_t> dist;
    vector<int> prev;
    vector<edge*> prev_edge;

    MinCostMaxFlow(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }

    void init(int vertices) {
        V = vertices;
        adj.assign(V, {});
        dist.resize(V);
        prev.resize(V);
        prev_edge.resize(V);
    }

    void addEdge(int u, int v, flow_t capacity, cost_t cost) {
        edge uv_edge(v, adj[v].size() + (u == v ? 1 : 0), capacity, cost);
        edge vu_edge(u, adj[u].size(), 0, -cost);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    bool bellman_ford(int source, int sink) {
        for (int i = 0; i < V; i++) {
            dist[i] = COST_INF;
            prev[i] = -1;
            prev_edge[i] = nullptr;
        }

        vector<int> last_seen(V, -1);
        vector<int> nodes(1, source);
        dist[source] = 0;

        for (int iteration = 0; iteration < V; iteration++) {
            vector<int> next_nodes;

            for (int node : nodes)
                for (edge &e : adj[node])
                    if (e.capacity > 0 && dist[node] + e.cost < dist[e.node]) {
                        dist[e.node] = dist[node] + e.cost;
                        prev[e.node] = node;
                        prev_edge[e.node] = &e;

                        if (last_seen[e.node] != iteration) {
                            last_seen[e.node] = iteration;
                            next_nodes.push_back(e.node);
                        }
                    }

            swap(nodes, next_nodes);
        }

        return prev[sink] != -1;
    }

    struct dijkstra_state {
        cost_t dist;
        int node;

        bool operator<(const dijkstra_state &other) const {
            return dist > other.dist;
        }
    };

    void dijkstra_check(int node, cost_t potential_dist, int previous, edge *previous_edge, auto &pq) {
        if (potential_dist < dist[node]) {
            dist[node] = potential_dist;
            prev[node] = previous;
            prev_edge[node] = previous_edge;
            pq.push({dist[node], node});
        }
    }

    bool dijkstra(int source, int sink) {
        dist.assign(V, COST_INF);
        prev.assign(V, -1);
        prev_edge.assign(V, nullptr);

        priority_queue<dijkstra_state> pq;
        dijkstra_check(source, 0, -1, nullptr, pq);

        while (!pq.empty()) {
            dijkstra_state top = pq.top();
            pq.pop();

            if (top.dist > dist[top.node])
                continue;

            for (edge &e : adj[top.node])
                if (e.capacity > 0)
                    dijkstra_check(e.node, top.dist + e.cost, top.node, &e, pq);
        }

        return prev[sink] != -1;
    }

    void reduce_cost() {
        for (int i = 0; i < V; i++)
            for (edge &e : adj[i])
                e.cost += dist[i] - dist[e.node];
    }

    pair<flow_t, cost_t> minCostFlow(int source, int sink, flow_t flow_goal = FLOW_INF) {
        assert(V >= 0);

        if (!bellman_ford(source, sink))
            return make_pair(0, 0);

        flow_t total_flow = 0;
        cost_t total_cost = 0;
        cost_t reduce_sum = 0;

        do {
            reduce_cost();
            reduce_sum += dist[sink];
            flow_t path_cap = flow_goal - total_flow;

            for (int node = sink; prev[node] != -1; node = prev[node])
                path_cap = min(path_cap, prev_edge[node]->capacity);

            for (int node = sink; prev[node] != -1; node = prev[node]) {
                edge *e = prev_edge[node];
                assert(e->cost == 0);
                e->capacity -= path_cap;
                reverse_edge(*e).capacity += path_cap;
            }

            total_flow += path_cap;
            total_cost += reduce_sum * path_cap;
        } while (total_flow < flow_goal && dijkstra(source, sink));

        return make_pair(total_flow, total_cost);
    }
};

ll modExp(ll base, ll exp, ll mod=::mod){
    ll ans=1;
    while(exp) {
        if (exp & 1) {
            (ans *= base) %= mod;
        }
        (base *= base) %= mod;
        exp>>=1;
    }
    return ans;
}
ll modInv(ll x, ll mod=::mod){
    return modExp(x,mod-2,mod);
}
void modFact(ll n, ll mod=::mod){
    ifact=new ll[n+1];
    fact=new ll[n+1];
    fact[0]=fact[1]=1;
    for(int i=2;i<=n;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    ifact[n]=modInv(fact[n], mod);
    for(int i=n-1;i>=0;i--){
        ifact[i]=((i+1)*ifact[i+1])%mod;
    }
}
ll ncr(ll n, ll r, ll mod=::mod){
    if(n<r || r<0)
        return 0;
    ll ans=fact[n];
    ans*=ifact[r];
    ans%=mod;
    ans*=ifact[n-r];
    ans%=mod;
    return ans;
}
ll npr(ll n, ll r, ll mod=::mod){
    if(n<r || r<0)
        return 0;
    ll ans=fact[n];
    ans*=ifact[n-r];
    return ans%mod;
}
class DSU{
public:
    int*p, *r;
    DSU(int n){
        p=new int[n+50];
        r=new int[n+50];
        for(int i=0;i<=n+10;i++){
            p[i]=i;
            r[i]=0;
        }
    }
    ~DSU(){
        delete[] p;
        delete[] r;
    }
    int find(int x){
        if(p[x]==x)
            return x;
        return p[x]=find(p[x]);
    }
    bool Unite(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b)
            return false;
        if(r[a]<r[b])
            p[a]=b;
        else
            p[b]=a;
        if(r[a]==r[b])
            r[a]++;
        return true;
    }
};

using  namespace std;

class FFT {
public:
    #define pw(x) (1LL << (x))
    typedef double dbl;
    const dbl PI = acos(-1);

    

    const int maxBase=19;       


    



    

    struct num
    {
        dbl x, y;
        num(){}
        num(dbl xx, dbl yy): x(xx), y(yy) {}
        num(dbl alp): x(cos(alp)), y(sin(alp)) {}
        inline num operator + (num b) { return num(x + b.x, y + b.y); }
        inline num operator - (num b) { return num(x - b.x, y - b.y); }
        inline num operator * (num b) { return num(x * b.x - y * b.y, x * b.y + y * b.x); }

    };
    inline num conj(num a) { return num(a.x, -a.y); }

    



    
    bool rootsPrepared=false;
    int base, N;
    int lastRevN = -1;
    num* root=NULL;
    int *rev=NULL;
    

    
    void prepRoots()
    {
        if (rootsPrepared) return;
        rootsPrepared = true;
        root=new num[pw(maxBase)];
        root[1] = num(1, 0);
        for (int k = 1; k < maxBase; ++k)
        {
            num x(2 * PI / pw(k + 1));
            for (int i = pw(k - 1); i < pw(k); ++i)
            {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * x;
            }
        }
    }


    void prepRev()
    {
        if (lastRevN == N) return;
        lastRevN = N;
        if(rev!=NULL)
            delete[] rev;
        rev=new int[pw(base)];
        rev[0]=0;
        for(int i=0; i<N; i++)
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
    }

    void prepAB(long long *x, long long *y, int n1, int n2)
    {
        base = 1;
        N = 2;
        while (N < n1 + n2) base++, N <<= 1;
        prepRoots();
        prepRev();

        

        if(A!=NULL){
            delete[] A;
            delete[] B;
            delete[] C;
        }

        A=new long long[N];
        B=new long long[N];
        C=new long long[N];

        for(int i=0;i<n1;i++)
            A[i]=x[i];

        for(int i=0;i<n2;i++)
            B[i]=y[i];

        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;
    }
    void prepAB(vector<long long> &x, vector<long long> &y)
    {
        int n1=x.size();
        int n2=y.size();
        base = 1;
        N = 2;
        while (N < n1 + n2) base++, N <<= 1;
        prepRoots();
        prepRev();

        

        if(A!=NULL){
            delete[] A;
            delete[] B;
            delete[] C;
        }

        A=new long long[N];
        B=new long long[N];
        C=new long long[N];

        for(int i=0;i<n1;i++)
            A[i]=x[i];

        for(int i=0;i<n2;i++)
            B[i]=y[i];

        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;
    }
    void prepAB(vector<long long> &x, vector<long long> &y, int n1, int n2)
    {
        n1=min(n1, (int)x.size());
        n2=min(n2, (int)y.size());
        base = 1;
        N = 2;
        while (N < n1 + n2) base++, N <<= 1;
        prepRoots();
        prepRev();

        

        if(A!=NULL){
            delete[] A;
            delete[] B;
            delete[] C;
        }

        A=new long long[N];
        B=new long long[N];
        C=new long long[N];

        for(int i=0;i<n1;i++)
            A[i]=x[i];

        for(int i=0;i<n2;i++)
            B[i]=y[i];

        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;
    }
    

    

    

    void fft(num *a, num *f)
    {
        

        for(int i=0;i<N;i++)
            f[i] = a[rev[i]];

        

        for (int k = 1; k < N; k <<= 1)
            for (int i = 0; i < N; i += 2 * k)
                for(int j=0;j<k;j++)
                {
                    num z = f[i + j + k] * root[j + k];
                    f[i + j + k] = f[i + j] - z;
                    f[i + j] = f[i + j] + z;
                }

    }

    

    
    num *a=NULL, *b=NULL, *f=NULL, *g=NULL;
    long long *A=NULL, *B=NULL, *C=NULL;

    void _multMod(int mod, bool eq)
    {
        a=new num[N];
        b=new num[N];
        f=new num[N];
        g=new num[N];
        for(int i=0;i<N;i++)
        {
            int x = A[i] % mod;
            a[i] = num(x & (pw(15) - 1), x >> 15);
        }

        for(int i=0;i<N;i++)
        {
            int x = B[i] % mod;
            b[i] = num(x & (pw(15) - 1), x >> 15);
        }

        fft(a, f);

        if (!eq) {
            fft(b, g);
        } else {
            for (int i = 0; i < N; i++) g[i] = f[i];
        }

        for(int i=0;i<N;i++)
        {
            int j = (N - i) & (N - 1);
            num a1 = (f[i] + conj(f[j])) * num(0.5, 0);
            num a2 = (f[i] - conj(f[j])) * num(0, -0.5);
            num b1 = (g[i] + conj(g[j])) * num(0.5 / N, 0);
            num b2 = (g[i] - conj(g[j])) * num(0, -0.5 / N);
            a[j] = a1 * b1 + a2 * b2 * num(0, 1);
            b[j] = a1 * b2 + a2 * b1;
        }

        fft(a, f);
        fft(b, g);

        for(int i=0;i<N;i++)
        {
            long long aa = f[i].x + 0.5;
            long long bb = g[i].x + 0.5;
            long long cc = f[i].y + 0.5;
            C[i] = (aa + bb % mod * pw(15) + cc % mod * pw(30)) % mod;
        }
        delete[] a;
        delete[] b;
        delete[] f;
        delete[] g;
    }

    void mult()
    {
        a=new num[N];
        f=new num[N];
        for(int i=0;i<N;i++) a[i] = num(A[i], B[i]);
        fft(a, f);
        for(int i=0;i<N;i++)
        {
            int j = (N - i)  & (N - 1);
            a[i] = (f[j] * f[j] - conj(f[i] * f[i])) * num(0, -0.25 / N);
        }
        fft(a, f);
        for(int i=0;i<N;i++) C[i] = (long long)round(f[i].x);
        delete[] a;
        delete[] f;
    }
    

    

public:

    
    long long* multiply(long long *x, long long *y, int n1, int n2, long long mod){
        prepAB(x,y, n1, n2);
        _multMod(mod, false);
        return C;
    }
    vector<long long> multiply(vector<long long> &x, vector<long long> &y,long long mod){
        prepAB(x,y);
        _multMod(mod, false);

        vector<long long> ret(x.size()+y.size()-1);
        for(int i=0;i<ret.size();i++)
            ret[i]=C[i];

        return ret;
    }
    vector<long long> multiply(vector<long long> &x, vector<long long> &y, int n1, int n2, long long mod){
        prepAB(x,y, n1, n2);
        _multMod(mod, false);

        vector<long long> ret(n1+n2-1);
        for(int i=0;i<ret.size();i++)
            ret[i]=C[i];

        return ret;
    }
    

    long long* multiply(long long *x, long long *y, int n1, int n2){
        prepAB(x,y,n1,n2);
        mult();
        return C;
    }

    vector<long long> multiply(vector<long long> &x, vector<long long> &y){
        prepAB(x,y);
        mult();

        vector<long long> ret(x.size()+y.size()-1);
        for(int i=0;i<ret.size();i++)
            ret[i]=C[i];

        return ret;
    }


    
    long long* multiplyLL(long long *x, long long *y, int n1, int n2){
        prepAB(x,y,n1,n2);
        int mod1=1.5e9;
        int mod2=mod1+1;
        _multMod(mod1, false);
        long long *D=new long long[N];

        for(int i=0;i<N;i++)
            D[i]=C[i];

        _multMod(mod2, false);

        for(int i=0;i<N;i++){
            C[i] = D[i] + (C[i] - D[i] + (long long)mod2) * (long long)mod1 % mod2 * mod1;
        }
        delete[] D;
        return C;
    }

    vector<long long> multiplyLL(vector<long long> &x, vector<long long> &y){
        prepAB(x,y);
        int mod1=1.5e9;
        int mod2=mod1+1;




        _multMod(mod1, false);
        long long *D=new long long[N];

        for(int i=0;i<N;i++)
            D[i]=C[i];

        _multMod(mod2, false);

        for(int i=0;i<N;i++){
            C[i] = D[i] + (C[i] - D[i] + (long long)mod2) * (long long)mod1 % mod2 * mod1;
        }
        delete[] D;
        vector<long long> ret(x.size()+y.size()-1);
        for(int i=0;i<ret.size();i++)
            ret[i]=C[i];
        return ret;
    }


    ~FFT(){
        if(rev!=NULL)
            delete[] rev;
        if(A!=NULL)
            delete[] A;
        if(B!=NULL)
            delete[] B;
        if(C!=NULL)
            delete[] C;
        if(root!=NULL)
            delete[] root;
    }


};


using namespace std;
ll ans[4000000];
class FRedWhiteFence {
    FFT fft;
    vector<ll> multiply(vector<vector<ll>> &v, int st, int en){
        if(st>en)return {1};
        if(st==en)return v[st];
        int mid=(st+en)>>1;
        vector<ll> left=multiply(v,st,mid);
        vector<ll> right=multiply(v, mid+1, en);
        return fft.multiply(left,right, mod);
    }
public:

	void solve(std::istream& cin, std::ostream& cout) {
        int n,k;

        cin>>n>>k;

        map<int,int> a;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]++;
        }

        vector<int> b(k);
        for(int i=0;i<k;i++)cin>>b[i];
        sort(b.begin(), b.end());
        memset(ans,0,sizeof(ans));
        mod=998244353;
        vector<ll> v={1};
        int last=0;
        vector<vector<ll>> p;
        for(auto r:b){
            p.clear();
            for(auto it:a){
                if(it.first>=r)break;
                if(it.first<last)continue;
                if(it.second==1)p.push_back({1,2});
                else p.push_back({1,2,1});
            }
            last=r;
            vector<ll> pv=multiply(p,0, ((int)p.size())-1);
            v=fft.multiply(v,pv,mod);
            for(int i=0;i<v.size();i++){
                (ans[2*(i+1)+2*r]+=v[i])%=mod;
            }
        }
        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            cout<<ans[x]<<'\n';
        }


	}
};


int main() {
	FRedWhiteFence solver;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
