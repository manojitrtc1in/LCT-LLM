







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


struct Dinic {

    struct FlowEdge {
        int v, u;
        long long cap, flow = 0;

        FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
    };

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

    void add_edge(int v, int u, long long cap, long long rcap=0) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, rcap);
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
struct id0 {
    static const flow_t FLOW_INF = numeric_limits<flow_t>::max() / 2;
    const cost_t id1 = numeric_limits<cost_t>::max() / 2;
    struct edge {
        int node, rev;
        flow_t capacity, flow;
        cost_t cost;

        edge(int _node = -1, int _rev = -1, flow_t _capacity = 0, cost_t _cost = 0)
                : node(_node), rev(_rev), capacity(_capacity), cost(_cost), flow(0) {}
    };

    int V = -1;
    vector<vector<edge>> adj;
    vector<cost_t> dist;
    vector<int> prev;
    vector<edge*> prev_edge;

    id0(int vertices = -1) {
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
            dist[i] = id1;
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
        dist.assign(V, id1);
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
                e->flow += path_cap;
                reverse_edge(*e).capacity += path_cap;
                reverse_edge(*e).flow -= path_cap;
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


using namespace std;

struct TwoSat {
    int N;
    vector<vector<int>> gr;
    vector<int> values; 

    vector<int> fixed;

    TwoSat(int n = 0) : N(n), gr(2*n), fixed(2*n) {}

    int add_var() { 

        gr.emplace_back();
        gr.emplace_back();
        fixed.emplace_back();
        fixed.emplace_back();
        return N++;
    }
    void addOr(int f, int j) {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        gr[f].push_back(j^1);
        gr[j].push_back(f^1);
    }
    void addImplication(int f, int j){
        addOr(~f, j);
    }
    void setTrue(int x) {
        addOr(x, x);
        fixed[max(2*x, -1-2*x)]=1;
    }

    void atMostOneTrue(const vector<int>& li) { 

        if ((li.size()) <= 1) return;
        int cur = ~li[0];
        for(int i=2;i<li.size();i++) {
            int next = add_var();
            addOr(cur, ~li[i]);
            addOr(cur, next);
            addOr(~li[i], next);
            cur = ~next;
        }
        addOr(cur, ~li[1]);
    }

    vector<int> val, comp, z; int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        for(auto e:gr[i]) if (!comp[e])
            low = min(low, val[e] ?: dfs(e));
        if (low == val[i]){
            bool ans=false;
            for(auto x=z.end()-1;(*x)!=i;x--){
                int v=((*x)>>1)<<1;
                if(fixed[v]||fixed[v^1]){
                    ans=true;
                    break;
                }
            }
            do {
                x = z.back(); z.pop_back();
                comp[x] = low;
                if (values[x>>1] == -1)
                    values[x>>1] = (x&1)^ans;
            } while (x != i);
        }
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2*N, 0); comp = val;
        for(int i=0;i<2*N;i++) if (!comp[i]) dfs(i);
        for(int i=0;i<N;i++)
            if (comp[2*i] == comp[2*i+1])
                return 0;
        return 1;
    }
};


using namespace std;

class CNationalProperty {
public:
    void addConstraints(vector<int> &cur, vector<vector<int>> &words, TwoSat &twoSat, int index){

        if(cur.size()==0)
            return;

        map<int,vector<int>> mp;

        vector<int> values;

        for(int id:cur){
            values.push_back(words[id][index]);
            if(words[id].size()>index+1)
                mp[words[id][index]].push_back(id);
        }

        for(int i=1;i<values.size();i++){
            if(values[i]<values[i-1]){
                twoSat.setTrue(values[i-1]);
                twoSat.setTrue(~values[i]);
            }else if(values[i]>values[i-1]){
                twoSat.addOr(values[i - 1], ~values[i]);
            }
        }
        cur.clear();
        values.clear();
        for(auto it : mp){
            addConstraints(it.second, words, twoSat, index+1);
        }
    }
	void solve(std::istream& cin, std::ostream& cout) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> words(n);

        for(int i=0;i<n;i++){
            vector<int> &word=words[i];
            int l;
            cin>>l;
            word=vector<int>(l);
            for(int j=0;j<l;j++)
                cin>>word[j];
        }

        vector<int> cur(n);
        for(int i=0;i<n;i++)
            cur[i]=i;
        TwoSat twoSat(m+1);
        addConstraints(cur, words, twoSat, 0);
        if(twoSat.solve()){
            for(auto &word:words){
                for(auto &c:word)
                    if(twoSat.values[c])
                        c-=m;

            }
            auto words2=words;
            sort(words2.begin(),words2.end());
            if(words!=words2){
                cout<<"No\n";
                return;
            }
            cout<<"Yes"<<endl;
            int k=0;
            for(int i=1;i<=m;i++)
                k+=(twoSat.values[i]);
            cout<<k<<endl;
            for(int i=1;i<=m;i++)
                if(twoSat.values[i])
                    cout<<i<<" ";
            cout<<endl;
        }else{
            cout<<"No"<<endl;
        }

	}
};


int main() {
	CNationalProperty solver;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
