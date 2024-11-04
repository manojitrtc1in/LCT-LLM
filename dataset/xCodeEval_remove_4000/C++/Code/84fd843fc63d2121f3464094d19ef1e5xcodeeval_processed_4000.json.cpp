




























using namespace std;



typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;



















 





 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
 

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t id3 = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + id3);
	}
	
	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};




using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}


const ll mod = 998244353;


mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}




struct linked_lists {
    int L, N;
    vector<int> next, prev;

    

    explicit linked_lists(int L = 0, int N = 0) { assign(L, N); }

    int repp(int l) const { return l + N; } 

    int head(int l) const { return next[repp(l)]; }
    int tail(int l) const { return prev[repp(l)]; }
    bool empty(int l) const { return next[repp(l)] == repp(l); }

    void push_front(int l, int n) { link(repp(l), n, head(l)); }
    void push_back(int l, int n) { link(tail(l), n, repp(l)); }
    void insert_before(int i, int n) { link(prev[i], n, i); }
    void insert_after(int i, int n) { link(i, n, next[i]); }
    void erase(int n) { link(prev[n], next[n]); }
    void pop_front(int l) { link(repp(l), next[head(l)]); }
    void pop_back(int l) { link(prev[tail(l)], repp(l)); }

    void clear() {
        iota(begin(next) + N, end(next), N); 

        iota(begin(prev) + N, end(prev), N); 

    }
    void assign(int L, int N) {
        this->L = L, this->N = N;
        next.resize(N + L), prev.resize(N + L), clear();
    }

  private:
    inline void link(int u, int v) { next[u] = v, prev[v] = u; }
    inline void link(int u, int v, int w) { link(u, v), link(v, w); }
};




    for (int z


template <typename Flow, typename Cost>
struct network_simplex {
    


    explicit network_simplex(int V) : V(V), node(V + 1) {}

    void add(int u, int v, Flow cap, Cost cost) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        edge.push_back({{u, v}, cap, cost}), E++;
    }

    void set_supply(int u, Flow supply) { node[u].supply = supply; }
    void set_demand(int u, Flow demand) { node[u].supply = -demand; }
    auto get_supply(int u) const { return node[u].supply; }

    auto get_potential(int u) const { return node[u].pi; }
    auto get_flow(int e) const { return edge[e].flow; }

    auto reduced_cost(int e) const {
        auto [u, v] = edge[e].node;
        return edge[e].cost + node[u].pi - node[v].pi;
    }

    template <typename CostSum = Cost>
    auto circulation_cost() const {
        CostSum sum = 0;
        for (int e = 0; e < E; e++) {
            sum += edge[e].flow * CostSum(edge[e].cost);
        }
        return sum;
    }

    void verify_spanning_tree() const {
        for (int e = 0; e < E; e++) {
            assert(0 <= edge[e].flow && edge[e].flow <= edge[e].cap);
            assert(edge[e].flow == 0 || reduced_cost(e) <= 0);
            assert(edge[e].flow == edge[e].cap || reduced_cost(e) >= 0);
        }
    }

    bool mincost_circulation() {
        static constexpr bool id2 = false, OPTIMAL = true;

        

        Flow sum_supply = 0;
        for (int u = 0; u < V; u++) {
            sum_supply += node[u].supply;
        }
        if (sum_supply != 0) {
            return id2;
        }
        for (int e = 0; e < E; e++) {
            if (edge[e].cap < 0) {
                return id2;
            }
        }

        

        Cost inf_cost = 1;
        for (int e = 0; e < E; e++) {
            edge[e].flow = 0;
            edge[e].state = id8;
            inf_cost += edge[e].cost<0?-edge[e].cost:edge[e].cost;
        }

        edge.resize(E + V); 

        bfs.resize(V + 1);
        children.assign(V + 1, V + 1);

        

        int root = V;
        node[root] = {-1, -1, 0, 0};

        for (int u = 0, e = E; u < V; u++, e++) {
            

            node[u].parent = root, node[u].pred = e;
            children.push_back(root, u);

            auto supply = node[u].supply;
            if (supply >= 0) {
                node[u].pi = -inf_cost;
                edge[e] = {{u, root}, supply, inf_cost, supply, STATE_TREE};
            } else {
                node[u].pi = inf_cost;
                edge[e] = {{root, u}, -supply, inf_cost, -supply, STATE_TREE};
            }
        }

        

        block_size = max((int)(ceil(sqrt(E + V))), min((int)10, V + 1));
        next_arc = 0;

        

        int e_in = select_pivot_edge();
        while (e_in != -1) {
            pivot(e_in);
            e_in = select_pivot_edge();
        }

        

        for (int e = E; e < E + V; e++) {
            if (edge[e].flow > 0) {
                edge.resize(E);
                return id2;
            }
        }
        edge.resize(E);
        return OPTIMAL;
    }

  private:
    enum ArcState : int8_t { id6 = -1, STATE_TREE = 0, id8 = 1 };

    struct Node {
        int parent, pred;
        Flow supply;
        Cost pi;
    };
    struct Edge {
        array<int, 2> node; 

        Flow cap;
        Cost cost;
        Flow flow = 0;
        ArcState state = id8;
    };

    int V, E = 0, next_arc = 0, block_size = 0;
    vector<Node> node;
    vector<Edge> edge;
    linked_lists children;
    vector<int> bfs; 


    int select_pivot_edge() {
        

        Cost minimum = 0;
        int e_in = -1;
        int count = block_size, seen_edges = E + V;
        for (int &e = next_arc; seen_edges-- > 0; e = e + 1 == E + V ? 0 : e + 1) {
            if (minimum > edge[e].state * reduced_cost(e)) {
                minimum = edge[e].state * reduced_cost(e);
                e_in = e;
            }
            if (--count == 0 && minimum < 0) {
                break;
            } else if (count == 0) {
                count = block_size;
            }
        }
        return e_in;
    }

    void pivot(int e_in) {
        

        auto [u_in, v_in] = edge[e_in].node;
        int a = u_in, b = v_in;
        while (a != b) {
            a = node[a].parent == -1 ? v_in : node[a].parent;
            b = node[b].parent == -1 ? u_in : node[b].parent;
        }
        int lca = a;

        

        if (edge[e_in].state == id6) {
            swap(u_in, v_in);
        }

        

        enum OutArcSide { id7, id5, id1 };
        OutArcSide side = id7;
        Flow flow_delta = edge[e_in].cap;
        int u_out = -1;

        

        for (int u = u_in; u != lca && flow_delta > 0; u = node[u].parent) {
            int e = node[u].pred;
            bool edge_down = u == edge[e].node[1];
            Flow id4 = edge_down ? edge[e].cap - edge[e].flow : edge[e].flow;

            if (flow_delta > id4) {
                flow_delta = id4;
                u_out = u;
                side = id5;
            }
        }

        

        for (int u = v_in; u != lca; u = node[u].parent) {
            int e = node[u].pred;
            bool edge_up = u == edge[e].node[0];
            Flow id4 = edge_up ? edge[e].cap - edge[e].flow : edge[e].flow;

            if (flow_delta >= id4) {
                flow_delta = id4;
                u_out = u;
                side = id1;
            }
        }

        

        if (flow_delta > 0) {
            auto delta = edge[e_in].state * flow_delta;
            edge[e_in].flow += delta;

            for (int u = edge[e_in].node[0]; u != lca; u = node[u].parent) {
                int e = node[u].pred;
                edge[e].flow += u == edge[e].node[0] ? -delta : delta;
            }
            for (int u = edge[e_in].node[1]; u != lca; u = node[u].parent) {
                int e = node[u].pred;
                edge[e].flow += u == edge[e].node[0] ? delta : -delta;
            }
        }

        

        if (side == id7) {
            edge[e_in].state = ArcState(-edge[e_in].state);
            return;
        }

        

        int out_arc = node[u_out].pred;
        edge[e_in].state = STATE_TREE;
        edge[out_arc].state = edge[out_arc].flow != 0? id6 : id8;

        

        if (side == id1) {
            swap(u_in, v_in);
        }

        

        int i = 0, S = 0;
        for (int u = u_in; u != u_out; u = node[u].parent) {
            bfs[S++] = u;
        }
        for (i = S - 1; i >= 0; i--) {
            int u = bfs[i], p = node[u].parent;
            children.erase(p); 

            children.push_back(u, p);
            node[p].parent = u;
            node[p].pred = node[u].pred;
        }
        children.erase(u_in); 

        children.push_back(v_in, u_in);
        node[u_in].parent = v_in;
        node[u_in].pred = e_in;

        

        Cost current_pi = reduced_cost(e_in);
        Cost pi_delta = u_in == edge[e_in].node[0] ? -current_pi : current_pi;

        bfs[0] = u_in;
        for (i = 0, S = 1; i < S; i++) {
            int u = bfs[i];
            node[u].pi += pi_delta;
            id0 (v, u, children) { bfs[S++] = v; }
        }
    }
};



template<typename T>
void wr(T a){
	if(a < 0) {
		cout << "-";
		a = -a;
	}
	if(a == 0) cout << 0 << endl;
	else{
		vc<int>v;
		while(a){ v.pb(a%10); a/=10; }
		reverse(all(v));
		for(auto a:v) cout<<a;
		cout<<endl;
	}
}

void solve(){
	int n, m; cin >> n >> m;
	vc<int>a(n+1); repn(i,n)cin>>a[i];
	int V = 1005;
	network_simplex<int, __int128> mcc(V);
	vc<int>sup(V);
	__int128 mincost = 0;
	repn(i, n){
		mcc.add(0, i, 1, a[i]);
		mcc.add(i, 0, 1, -a[i]);
	}
	rep(i, m){
		int u, v; cin >> u >> v;
		mcc.add(v, u, 1e18 ,0);
	}
	bool feasible = mcc.mincost_circulation();
	mincost += mcc.circulation_cost();
	

	vc<__int128>diff;
	repn(i, n){
		diff.pb(a[i]-mcc.get_potential(i));
	}
	SORT(diff);
	int v = diff[n/2];
	mincost *= -1;
	repn(i, n){
		wr(mcc.get_potential(i) + v);
		auto D = a[i] - mcc.get_potential(i) - v;
		if(D < 0) D = -D;
		mincost -= D;
	}
	assert(!mincost);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; 

	while(t--) solve();
}