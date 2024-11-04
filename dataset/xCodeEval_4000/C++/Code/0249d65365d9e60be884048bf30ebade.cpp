









































































































#include <numeric>
#include <set>
#include <iomanip>
#include <algorithm> 
#include <queue>
#include <memory>
#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
using namespace std;
#define pb push_back 
#define all(v) (v).begin(),(v).end()
#define sz(v) ll(v.size())
#define watch(x) cerr << (#x) << " = " << x << '\n'
#define X first
#define Y second
typedef long long ll;
typedef double ld;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
template<typename IT>
ostream &print(IT b, IT e, string sep = " ", ostream &stream = cout){
    for(IT it = b; it != e; ++it){
        stream << *it;
        if(it+1 != e) stream << sep;
    } 
    return stream;
}
template<typename IT> istream &read(IT b, IT e, istream &stream = cin){
    for(IT it = b; it != e; ++it)
        stream >> *it; 
    return stream;
}
template<typename T> ostream &operator<<(ostream &stream, vector<T> &t){
    return print(all(t)," ",stream);
}
template<typename T> ostream &operator<<(ostream &stream, vector<T> &&t){
    return print(all(t)," ",stream);
}
template<typename T> istream &operator>>(istream &stream, vector<T> &t){
    return read(all(t),stream);
}
template<typename F, typename S> ostream &operator<<(ostream &stream, const pair<F,S> t){
    return stream << t.first << ' ' << t.second;
}
template<typename F, typename S> istream &operator>>(istream &stream, pair<F,S> &t){
    return stream >> t.first >> t.second;
}
template <typename T> 
void print(T x, string end = "\n"){
    cout << x << end;
}
template <typename t> 
void print(vector<t> arr,string sep=" "){
    if(arr.empty()){
        return;
    }
    print(arr.begin(),arr.end(),sep);
    cout << '\n';
}
template <typename T> 
void print(vector<vector<T> > arr){
    for(int i = 0; i < sz(arr); ++i){
        cout << "[" << arr[i] << "]";
        if(i+1 < sz(arr))
            cout << ", ";
    }
    cout << '\n';
}
struct DSU{
    vi par;
    int n;
    DSU(int _n):n(_n){
        par.resize(n+1);
        iota(all(par),0);
    }
    int getpar(int u){
        if(par[par[u]] == par[u])
            return par[u];
        return par[u] = getpar(par[u]);
    }
    bool unite(int u, int v){
        u = getpar(u);
        v = getpar(v);
        if(u == v)
            return false;
        par[u] = v; 
        return true;
    }
};
template<typename T>
T sum(vector<T> &arr){
    T ans = 0;
    for(auto x : arr)
        ans += x;
    return ans;
}
template<typename T>
T sum(vector<T> &&arr){
    T ans = 0;
    for(auto x : arr)
        ans += x;
    return ans;
}
template <typename COST_TYPE = ll, ll COST_INF = ll(1e18)>
struct MaxFlow{
    const ll FLOW_INF = 1e18;
    struct Edge{
        int u,v;
        ll c,rc;
        COST_TYPE cost;
        shared_ptr<ll> flow;
        Edge(int _u, int _v, ll _c, COST_TYPE _cost = 0):u(_u),v(_v),c(_c),cost(_cost){
            rc = 0;
        }
    };
    struct FlowTracker{
        shared_ptr<ll> flow;
        ll cap, rcap;
        bool dir;
        FlowTracker(ll _cap, ll _rcap, shared_ptr<ll> _flow, int _dir):cap(_cap),rcap(_rcap),flow(_flow),dir(_dir){ }
        ll rem() const {
            if(dir == 0){
                return cap-*flow;
            }
            else{
                return rcap+*flow;
            }
        }
        void add_flow(ll f){
            if(dir == 0)
                *flow += f;
            else
                *flow -= f;
            assert(*flow <= cap);
            assert(-*flow <= rcap);
        }
        operator ll() const { return rem(); }
        void operator-=(ll x){ add_flow(x); }
        void operator+=(ll x){ add_flow(-x); }
    };
    int source,sink;
    vector<vector<int> > adj;
    vector<vector<COST_TYPE> > cost;
    vector<vector<FlowTracker> > cap;
    vector<Edge> edges;
    MaxFlow(int _source, int _sink):source(_source),sink(_sink){
        assert(source != sink);
    }
    int add_edge(int u, int v, ll c, COST_TYPE cost = 0){
        edges.push_back(Edge(u,v,c,cost));
        return edges.size()-1;
    }
    vector<int> now,lvl;
    vector<COST_TYPE> pot;
    void prep(){
        vector<int> indices = {source,sink};
        for(auto &edge : edges){
            indices.push_back(edge.u);
            indices.push_back(edge.v);
        }
        sort(indices.begin(),indices.end());
        indices.erase(unique(indices.begin(),indices.end()),indices.end());
        source = lower_bound(indices.begin(),indices.end(),source)-indices.begin();
        sink = lower_bound(indices.begin(),indices.end(),sink)-indices.begin();
        adj.clear();
        cost.clear();
        cap.clear();
        now.clear();
        lvl.clear();
        pot.clear();
        int max_id = indices.size()-1;
        adj.resize(max_id+1);
        cost.resize(max_id+1);
        cap.resize(max_id+1);
        now.resize(max_id+1);
        lvl.resize(max_id+1);
        pot.resize(max_id+1);
        for(auto &edge : edges){
            edge.u = lower_bound(indices.begin(),indices.end(),edge.u)-indices.begin();
            edge.v = lower_bound(indices.begin(),indices.end(),edge.v)-indices.begin();
            auto flow = make_shared<ll>(0);
            adj[edge.u].push_back(edge.v);
            cost[edge.u].push_back(edge.cost);
            cap[edge.u].push_back(FlowTracker(edge.c,edge.rc,flow,0));
            if(edge.u != edge.v){
                adj[edge.v].push_back(edge.u);
                cost[edge.v].push_back(-edge.cost);
                cap[edge.v].push_back(FlowTracker(edge.c,edge.rc,flow,1));
            }
            assert(cap[edge.u].back() == edge.c);
            edge.flow = flow;
        }
    }
    bool dinic_bfs(){
        fill(now.begin(),now.end(),0);
        fill(lvl.begin(),lvl.end(),0);
        lvl[source] = 1;
        vector<int> bfs(1,source);
        for(int i = 0; i < bfs.size(); ++i){
            int u = bfs[i];
            for(int j = 0; j < adj[u].size(); ++j){
                int v = adj[u][j];
                if(cap[u][j] > 0 && lvl[v] == 0){
                    lvl[v] = lvl[u]+1;
                    bfs.push_back(v);
                }
            }
        }
        return lvl[sink] > 0;
    }
    ll dinic_dfs(int u, ll flow){
        if(u == sink)
            return flow;
        while(now[u] < adj[u].size()){
            int v = adj[u][now[u]];
            if(lvl[v] == lvl[u] + 1 && cap[u][now[u]] != 0){
                ll res = dinic_dfs(v,min(flow,(ll)cap[u][now[u]]));
                if(res > 0){
                    cap[u][now[u]] -= res;
                    return res;
                }
            }
            ++now[u];
        }
        return 0;
    }
    ll max_flow(){
        prep();
        ll ans = 0;
        while(dinic_bfs()){
            ll cur = 0;
            do{
                cur = dinic_dfs(source,FLOW_INF);
                ans += cur;
            }while(cur > 0);
        }
        return ans;
    }
    void bellman_ford(){
        vector<COST_TYPE> dist(adj.size(),COST_INF);
        dist[source] = 0;
        for(int times = 0; times < dist.size(); ++times)
            for(auto &edge : edges)
                dist[edge.v] = min(dist[edge.v], dist[edge.u]+edge.cost);
        pot = dist;
    }
    ll dijkstra(vector<COST_TYPE> &dist, vector<int> &last_node, vector<int> &last_index){
        dist[source] = 0;
        vector<ll> flow(dist.size());
        flow[source] = FLOW_INF;
        vector<bool> visited(dist.size());
        priority_queue<pair<COST_TYPE,int> > pq;
        pq.push({0,source});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            if(visited[u])
                continue;
            visited[u] = true;
            for(int i = 0; i < adj[u].size(); ++i){
                int v = adj[u][i];
                if(!visited[v] && cap[u][i])
                    if(dist[u]+cost[u][i]+pot[u]-pot[v] < dist[v]){
                        dist[v] = dist[u]+cost[u][i]+pot[u]-pot[v];
                        last_node[v] = u;
                        last_index[v] = i;
                        flow[v] = min(flow[u],(ll)cap[u][i]);
                        pq.push({-dist[v],v});
                    }
            }
        }
        return flow[sink];
    }
    pair<ll,COST_TYPE> min_cost_flow(){
        prep();
        bool has_negative = false;
        for(auto &edge : edges)
            if(edge.cost < 0)
                has_negative = true;
        if(has_negative)
            bellman_ford();
        ll total_flow = 0; 
        COST_TYPE total_cost = 0;
        while(true){
            vector<COST_TYPE> dist(adj.size(),COST_INF);
            vector<int> last_node(dist.size()),last_index(dist.size());
            ll flow = dijkstra(dist,last_node,last_index);
            if(flow == 0)
                break;
            for(int u = sink; u != source; u = last_node[u])
                cap[last_node[u]][last_index[u]] -= flow;
            for(int i = 0; i < adj.size(); ++i)
                pot[i] += dist[i];
            total_flow += flow;
            total_cost += pot[sink]*flow;
        }
        return {total_flow,total_cost};
    }
    ll flow_on_edge(int edge_index){
        assert(edge_index < edges.size());
        return *edges[edge_index].flow;
    }
};
template<typename T>
vector<T> filter_size(const vector<T> &arr, int l = 1, int r = int(1e9)){
    vector<T> ans;
    for(auto &cur : arr)
        if(l <= sz(cur) && sz(cur) <= r)
            ans.pb(cur);
    return ans;
}
template<typename T>
T _();
const ll INF = ll(2e18)+666;
const ll MOD = 1e9+7;
const ld EPS = 1e-12;
template<typename T>
vector<T> operator+(const vector<T> &lhs, const vector<T> &rhs){
    vector<T> ans(lhs);
    assert(ans.size() == rhs.size());
    for(int i = 0; i < rhs.size(); ++i)
        ans[i] += rhs[i];
    return ans;
}
template<typename T>
vector<T> operator+=(vector<T> &lhs, const vector<T> &rhs){
    return lhs = lhs+rhs;
}
template<typename T>
vector<T> operator-(const vector<T> lhs, const vector<T> rhs){
    vector<T> ans(all(lhs));
    assert(ans.size() == rhs.size());
    for(int i = 0; i < rhs.size(); ++i)
        ans[i] -= rhs[i];
    return ans;
}
template<typename T>
vector<T> operator-=(vector<T> &lhs, const vector<T> &rhs){
    return lhs = lhs-rhs;
}
template<typename T>
T max(const vector<T> arr){
    assert(!arr.empty());
    T ans = arr[0];
    for(auto &cur : arr)
        ans = max(ans,cur);
    return ans;
}
template<typename T>
T min(const vector<T> &arr){
    assert(!arr.empty());
    T ans = arr[0];
    for(auto &cur : arr)
        ans = min(ans,cur);
    return ans;
}
template<typename T>
T max(const set<T> &s){
    assert(!s.empty());
    return *--s.end();
}
template<typename T>
T min(const set<T> &s){
    assert(!s.empty());
    return *s.begin();
}
template<typename T, typename G>
vector<T> set_max(vector<T> &base, const vector<G> &comp){
    assert(base.size() == comp.size());
    for(int i = 0; i < (int)comp.size(); ++i)
        base[i] = max(base[i],comp[i]);
    return base;
}
template <typename T>
vector<T> unique(vector<T> &arr){
    sort(all(arr));
    arr.erase(unique(all(arr)),arr.end());
    return arr;
}
string unique(string &s){
    sort(all(s));
    s.erase(unique(all(s)),s.end());
    return s;
}
struct UGraph{
    struct Edge{
        int u,v,id;
        int nxt(int from){
            return from==u?v:u;
        }
    };
    vector<Edge> edges;
    int n,m;
    vvi conn;
    UGraph(){
        m = -1;
    }
    UGraph(int nsize) : UGraph() {
        n = nsize;
        conn.resize(n+1);
    }
    UGraph(int nsize, int _m) : UGraph(nsize){
        m = _m;
    }
    void add_edge(int u, int v, int id = -1) {
        if(id == -1)
            id = sz(edges);
        conn[u].pb(sz(edges));
        conn[v].pb(sz(edges));
        edges.pb({u,v,id});
    }
    vi bfs_dist(int u){
        vb visited(n+1);
        visited[u] = true;
        vi bfs(1,u),dist(n+1,-1);
        dist[u] = 0;
        for(int i = 0; i < bfs.size(); ++i){
            int u = bfs[i];
            for(int _v : conn[u]){
                int v = edges[_v].nxt(u);
                if(!visited[v]){
                    visited[v] = true;
                    dist[v] = dist[u]+1;
                    bfs.pb(v);
                }
            }
        }
        return dist;
    }
    void _bridges_dfs(int u, int p, int &timer, vi &tin, vi &fup, vb &used, vi &ans){
        used[u] = true;
        tin[u] = fup[u] = timer++;
        for (int i = 0; i < sz(conn[u]); ++i) {
            if (edges[conn[u][i]].id == p)  continue;
            int v = edges[conn[u][i]].nxt(u);
            if (used[v])
                fup[u] = min (fup[u], tin[v]);
            else {
                _bridges_dfs(v, edges[conn[u][i]].id,timer,tin,fup,used,ans);
                fup[u] = min (fup[u], fup[v]);
                if (fup[v] > tin[u]){
                    ans.pb(edges[conn[u][i]].id);
                }
            }
        }
    }
    vi bridges(){

        vi tin(n+1),fup(n+1);
        vb used(n+1);
        int timer = 0;
        for (int i = 1; i <= n; ++i)
            used[i] = false;
        vi ans;
        for (int i = 1; i <= n; ++i)
            if (!used[i])
                _bridges_dfs(i,-1,timer,tin,fup,used,ans);
        sort(all(ans));
        return ans;
    }
    void _sz_below(int u, int p, int &timer, vl &sz, vi &tin, vb &used, vl &weight){
        vl ans;
        used[u] = true;
        tin[u] = timer++;
        sz[u] = weight[u];
        for (int i = 0; i < sz(conn[u]); ++i) {
            if (edges[conn[u][i]].id == p) continue;
            int v = edges[conn[u][i]].nxt(u);
            if(!used[v]){
                _sz_below(v, edges[conn[u][i]].id,timer,sz,tin,used,weight);
                sz[u] += sz[v];
            }
        }
    }
    vpll bridge_sep_sizes(vl weight = vl()){

        if(weight.empty())
            weight = vl(n+1,1);
        vb used(n+1,false);
        int timer = 0;
        vl sz;
        vi tin(n+1);
        sz.resize(n+1);
        for (int i = 1; i <= n; ++i)
            if (!used[i])
                _sz_below(i,-1,timer,sz,tin,used,weight);
        vi br = bridges();
        vpll ans;
        for(auto cur : br){
            int u = edges[cur].u;
            int v = edges[cur].v;
            if(tin[u] > tin[v])
                swap(u,v);
            ans.pb({cur,sz[v]});
        }
        return ans;
    }
    vi non_bridges(){

        vi br = bridges();
        reverse(all(br));
        vi nbr;
        for(int i = 0; i < sz(edges); ++i)
            if(!br.empty() && i == br.back())
                br.pop_back();
            else
                nbr.pb(i);
        return nbr;
    }
    vvi conn_comp(){
        DSU dsu(n);
        for(auto cur : edges)
            dsu.unite(cur.u,cur.v);
        vvi comp(n+1);
        for(int i = 1; i <= n; ++i)
            comp[dsu.getpar(i)].pb(i);
        return filter_size(comp);
    }
    vvi bridge_conn_comp(){
        vi br = bridges();
        DSU dsu(n);
        for(auto cur : br)
            dsu.unite(edges[cur].u,edges[cur].v);
        vvi comp(n+1);
        for(int i = 1; i <= n; ++i)
            comp[dsu.getpar(i)].pb(i);
        return filter_size(comp);
    }
    vvi non_bridge_conn_comp(){
        vi nbr = non_bridges();
        DSU dsu(n);
        for(auto cur : nbr)
            dsu.unite(edges[cur].u,edges[cur].v);
        vvi comp(n+1);
        for(int i = 1; i <= n; ++i)
            comp[dsu.getpar(i)].pb(i);
        return filter_size(comp);
    }
    vi _cut_points_dfs(int u, int p, int &timer, vi &tin, vi &fup, vb &visited, vi &ans) {
        visited[u] = true;
        tin[u] = fup[u] = timer++;
        int children=0;
        for(int i = 0; i < sz(conn[u]); ++i){
            if (conn[u][i] == p) continue;
            int v = edges[conn[u][i]].nxt(u);
            if (visited[v]) {
                fup[u] = min(fup[u], tin[v]);
            } else {
                _cut_points_dfs(v, conn[u][i],timer,tin,fup,visited,ans);
                fup[u] = min(fup[u], fup[v]);
                if (fup[v] >= tin[u] && p!=-1)
                    ans.pb(u);
                ++children;
            }
        }
        if(p == -1 && children > 1)
            ans.pb(u);
        return ans;
    }
    vi cut_points(){
        vector<bool> visited(n+1);
        vector<int> tin(n+1,-1), fup(n+1,-1);
        int timer = 0;
        vi ans;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                _cut_points_dfs(i,-1,timer,tin,fup,visited,ans);
        }
        unique(ans);
        return ans;
    }
    void _biconn_comp_dfs(int u, int p, int &timer, vi &tin, vi &fup, vb &visited, vb &edge_visited, vi &stk, vvi &ans) {
        

        

        visited[u] = true;
        tin[u] = fup[u] = timer++;
        int children=0;
        for(int i = 0; i < sz(conn[u]); ++i){
                

            if(conn[u][i] == p)
                continue;
            int v = edges[conn[u][i]].nxt(u);
            if(!edge_visited[conn[u][i]])
                stk.pb(edges[conn[u][i]].id);
            edge_visited[conn[u][i]] = true;
            if (visited[v]) {
                fup[u] = min(fup[u], tin[v]);
            } else {
                _biconn_comp_dfs(v, conn[u][i],timer,tin,fup,visited,edge_visited,stk,ans);
                fup[u] = min(fup[u], fup[v]);
                if (fup[v] >= tin[u] && p!=-1){
                    

                    

                    

                    

                    

                    if(!stk.empty()){
                        vi cur;
                        while(!stk.empty() && edges[stk.back()].id != edges[conn[u][i]].id){
                            cur.pb(stk.back());
                            stk.pop_back();
                        }
                        cur.pb(stk.back());
                        stk.pop_back();
                        

                            

                            

                        

                        

                        

                        ans.pb(cur);
                    }
                }
                ++children;
                if(p == -1 && sz(stk)){
                    sort(all(stk));
                    ans.pb(stk);
                    stk.clear();
                }
            }
        }
        if(p == -1 && sz(stk)){
            

            sort(all(stk));
            ans.pb(stk);
            

            stk.clear();
        }
    }
    vvi biconn_comp_edges(){
        vb visited(n+1),edge_visited(sz(edges));
        

            

        vi tin(n+1,-1), fup(n+1,-1),stk;
        int timer = 0;
        vvi ans;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                _biconn_comp_dfs(i,-1,timer,tin,fup,visited,edge_visited,stk,ans);
        }
        return ans;
    }
    vi induced_sub(vi edge_ids){
        vi ans;
        for(auto cur : edge_ids){
            ans.pb(edges[cur].u);
            ans.pb(edges[cur].v);
        }
        unique(ans);
        return ans;
    }
    vvi biconn_comp(){
        vvi edges = biconn_comp_edges();
        

        vvi ans;
        for(auto cur : edges)
            ans.pb(induced_sub(cur));
        return ans;
    }
};
istream &operator>>(istream &stream, UGraph &g){
    if(g.m == -1){
        stream >> g.n >> g.m;
        g = UGraph(g.n,g.m);
    }
    for(int i = 0; i < g.m; ++i){
        int u,v;
        stream >> u >> v;
        g.add_edge(u,v);
    }
    return stream;
}
ostream &operator<<(ostream &stream, const UGraph g){
    stream << g.n << ' ' << g.m << '\n';
    for(auto cur : g.edges)
        stream << cur.u << " " << cur.v << '\n';
    return stream;
}
void _(){
	int n,m;
	cin >> n >> m;
	vpii edges;
	vi col;
	for(int i = 0; i < m; ++i){
		pii e;
		int c;
		cin >> e >> c;
		edges.pb(e);
		col.pb(c);
	}
	UGraph g(n);
	int timer = -1;
	for(auto _ : edges)
		g.add_edge(_.X,_.Y,++timer);
	vi has_col(m+1);
	vvi non_trivial;
	for(auto comp : g.biconn_comp_edges()){
		if(sz(comp) == 1)
			has_col[col[comp[0]]] = true;
		else
			non_trivial.pb(comp);
	}
	int ans = sum(has_col);
	{
		int source = -1, sink = -2;
		int k = sz(non_trivial);
		MaxFlow mf(source,sink);
		for(int i = 0; i < k; ++i){
			mf.add_edge(source,i,sz(non_trivial[i])-1);
			for(auto _ : non_trivial[i]){
				if(!has_col[col[_]]){
					mf.add_edge(i,k+col[_],1);
					

					

				}
			}
		}
		for(int i = 1; i <= m; ++i)
			if(!has_col[i])
				mf.add_edge(i+k,sink,1);
		ans += mf.max_flow();
	}
	print(ans);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(15);
    _();
}
