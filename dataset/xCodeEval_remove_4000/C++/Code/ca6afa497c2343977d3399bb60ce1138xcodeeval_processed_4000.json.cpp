



























































































































using namespace std;





typedef double ld;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
template <typename T>
T _();
const ll INF = ll(2e18) + 666;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-12;
template <typename T>
vector<T> unique(vector<T>& arr){
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
    return arr;
}
string unique(string& s){
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    return s;
}
template <typename IT>
ostream& print(IT b, IT e, string sep = " ", ostream& stream = cout){
    for(IT it = b; it != e; ++it){
        stream << *it;
        if(it + 1 != e)
            stream << sep;
    }
    return stream;
}
template <typename IT>
istream& read(IT b, IT e, istream& stream = cin){
    for(IT it = b; it != e; ++it)
        stream >> *it;
    return stream;
}
template <typename T>
ostream& operator<<(ostream& stream, vector<T>& t){
    return print(all(t), " ", stream);
}
template <typename T>
ostream& operator<<(ostream& stream, vector<T>&& t){
    return print(all(t), " ", stream);
}
template <typename T>
istream& operator>>(istream& stream, vector<T>& t){
    return read(all(t), stream);
}
template <typename F, typename S>
ostream& operator<<(ostream& stream, const pair<F, S> t){
    return stream << t.first << ' ' << t.second;
}
template <typename F, typename S>
istream& operator>>(istream& stream, pair<F, S>& t){
    return stream >> t.first >> t.second;
}
template <typename T>
void print(T x, string end = "\n"){
    cout << x << end;
}
template <typename t>
void print(vector<t> arr, string sep = " "){
    if(arr.empty()){
        return;
    }
    print(arr.begin(), arr.end(), sep);
    cout << '\n';
}
template <typename T>
void print(vector<vector<T>> arr){
    for(int i = 0; i < sz(arr); ++i){
        cout << "[" << arr[i] << "]";
        if(i + 1 < sz(arr))
            cout << ", ";
    }
    cout << '\n';
}
template <typename COST_TYPE = ll>
struct MaxFlow{
    const COST_TYPE COST_INF = numeric_limits<COST_TYPE>::max();
    const ll FLOW_INF = 1e18;
    bool id0;
    struct FlowTracker{
        ll *cap, *rcap;
        shared_ptr<ll> flow;
        bool dir;
        FlowTracker(){
            

            

        }
        FlowTracker(ll *_cap, ll *_rcap, shared_ptr<ll> _flow, int _dir)
            :cap(_cap), rcap(_rcap), flow(_flow), dir(_dir){
        }
        ll rem()const{
            if(dir == 0){
                return *cap - *flow;
            }else{
                return *rcap + *flow;
            }
        }
        void add_flow(ll f){
            if(dir == 0)
                *flow += f;
            else
                *flow -= f;
            assert(*flow <= *cap);
            assert(-*flow <= *rcap);
        }
        operator ll()const{
            return rem();
        }
        void operator-=(ll x){
            add_flow(x);
        }
        void operator+=(ll x){
            add_flow(-x);
        }
    };
    struct Edge{
        int u, v;
        ll c, rc;
        COST_TYPE cost;
        FlowTracker flow;
        Edge(){}
        Edge(int _u, int _v, ll _c, COST_TYPE _cost = 0)
            :u(_u), v(_v), c(_c), cost(_cost){
            rc = 0;
        }
        void change_cap(ll _c, ll _rc = 0){
            c = _c;
            rc = _rc;
        }
    };
    int source, sink, rt_source, rt_sink;
    MaxFlow(int _source = numeric_limits<int>::min(), int _sink = numeric_limits<int>::min() + 1):source(_source), sink(_sink){
        id0 = true;
    }
    vector<vector<int>> adj;
    vector<vector<COST_TYPE>> cost;
    vector<vector<FlowTracker>> cap;
    vector<Edge> edges;
    int add_edge(int u, int v, ll c, COST_TYPE cost = 0){
        id0 = true;
        edges.push_back(Edge(u, v, c, cost));
        return sz(edges) - 1;
    }
    vector<int> now, lvl;
    vector<COST_TYPE> pot;
    vi indices;
    void prep(){
        if(!id0)
            return;
        id0 = false;
        indices = vi{source,sink};
        for(auto& edge : edges){
            indices.push_back(edge.u);
            indices.push_back(edge.v);
        }
        sort(indices.begin(), indices.end());
        indices.erase(unique(indices.begin(), indices.end()), indices.end());
        rt_source = lower_bound(indices.begin(), indices.end(), source) - indices.begin();
        rt_sink = lower_bound(indices.begin(), indices.end(), sink) - indices.begin();
        adj.clear();
        cost.clear();
        cap.clear();
        now.clear();
        lvl.clear();
        pot.clear();
        int max_id = sz(indices) - 1;
        adj.resize(max_id + 1);
        cost.resize(max_id + 1);
        cap.resize(max_id + 1);
        now.resize(max_id + 1);
        lvl.resize(max_id + 1);
        pot.resize(max_id + 1);
        for(auto& edge : edges){
            int u = lower_bound(indices.begin(), indices.end(), edge.u) - indices.begin();
            int v = lower_bound(indices.begin(), indices.end(), edge.v) - indices.begin();
            auto flow = make_shared<ll>(0);
            adj[u].push_back(v);
            cost[u].push_back(edge.cost);
            cap[u].push_back(FlowTracker(&edge.c, &edge.rc, flow, 0));
            if(u != v){
                adj[v].push_back(u);
                cost[v].push_back(-edge.cost);
                cap[v].push_back(FlowTracker(&edge.c, &edge.rc, flow, 1));
            }
            assert(cap[u].back() == edge.c);
            edge.flow = cap[v].back();
        }
    }
    int get_name(int x){
        auto it = lower_bound(all(indices),x);
        if(it == indices.end() || *it != x){
            indices.pb(x);
            unique(indices);
            id0 = true;
            it = lower_bound(all(indices),x);
        }
        assert(*it == x);
        return it-indices.begin();
    }
    void set_source(int _source){
        if(source == _source) return;
        source = _source;
        rt_source = get_name(source);
    }
    void set_sink(int _sink){
        if(sink == _sink) return;
        sink = _sink;
        rt_sink = get_name(sink);
    }
    bool dinic_bfs(){
        fill(now.begin(), now.end(), 0);
        fill(lvl.begin(), lvl.end(), 0);
        lvl[rt_source] = 1;
        vector<int> bfs(1, rt_source);
        for(int i = 0; i < sz(bfs); ++i){
            int u = bfs[i];
            for(int j = 0; j < sz(adj[u]); ++j){
                int v = adj[u][j];
                if(cap[u][j] > 0 && lvl[v] == 0){
                    lvl[v] = lvl[u] + 1;
                    bfs.push_back(v);
                }
            }
        }
        return lvl[rt_sink] > 0;
    }
    ll dinic_dfs(int u, ll flow){
        if(u == rt_sink)
            return flow;
        while(now[u] < sz(adj[u])){
            int v = adj[u][now[u]];
            if(lvl[v] == lvl[u] + 1 && cap[u][now[u]] != 0){
                ll res = dinic_dfs(v, min(flow, (ll)cap[u][now[u]]));
                if(res > 0){
                    cap[u][now[u]] -= res;
                    return res;
                }
            }
            ++now[u];
        }
        return 0;
    }
    ll max_flow(int _source, int _sink){
        set_source(_source);
        set_sink(_sink);
        prep();
        ll ans = 0;
        while(dinic_bfs()){
            ll cur = 0;
            do{
                cur = dinic_dfs(rt_source, FLOW_INF);
                ans += cur;
            }while(cur > 0);
        }
        return ans;
    }
    ll max_flow(){
        return max_flow(source, sink);
    }
    void bellman_ford(){
        vector<COST_TYPE> dist(sz(adj), COST_INF);
        dist[rt_source] = 0;
        for(int times = 0; times < sz(dist); ++times){
            for(int u = 0; u < sz(adj); ++u)
                for(int i = 0; i < sz(adj[u]); ++i){
                    int v = adj[u][i];
                    if(dist[u] != COST_INF && cap[u][i])
                        dist[v] = min<COST_TYPE>(dist[v], dist[u] + cost[u][i]);
                }
        }
        pot = dist;
    }
    ll dijkstra(vector<COST_TYPE>& dist, vector<int>& last_node, vector<int>& last_index){
        dist[rt_source] = 0;
        vector<ll> flow(sz(dist));
        flow[rt_source] = FLOW_INF;
        vector<bool> visited(sz(dist));
        priority_queue<pair<COST_TYPE, int>> pq;
        pq.push({0, rt_source});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            if(visited[u])
                continue;
            visited[u] = true;
            assert(dist[u] != COST_INF);
            for(int i = 0; i < sz(adj[u]); ++i){
                int v = adj[u][i];
                if(!visited[v] && cap[u][i])
                    if(dist[u] + cost[u][i] + pot[u] - pot[v] < dist[v]){
                        dist[v] = dist[u] + cost[u][i] + pot[u] - pot[v];
                        last_node[v] = u;
                        last_index[v] = i;
                        flow[v] = min(flow[u], (ll)cap[u][i]);
                        pq.push({-dist[v], v});
                    }
            }
        }
        return flow[rt_sink];
    }
    pair<ll, COST_TYPE> min_cost_flow(int _source, int _sink){
        set_source(_source);
        set_sink(_sink);
        prep();
        bool has_negative = false;
        for(auto& edge : edges)
            if(edge.cost < 0)
                has_negative = true;
        if(has_negative)
            bellman_ford();
        ll total_flow = 0;
        COST_TYPE total_cost = 0;
        while(true){
            vector<COST_TYPE> dist(sz(adj), COST_INF);
            vector<int> last_node(sz(dist)), last_index(sz(dist));
            ll flow = dijkstra(dist, last_node, last_index);
            if(flow == 0)
                break;
            for(int u = rt_sink; u != rt_source; u = last_node[u])
                cap[last_node[u]][last_index[u]] -= flow;
            for(int i = 0; i < sz(adj); ++i)
                pot[i] = pot[i] + dist[i];
            total_flow += flow;
            total_cost += pot[rt_sink] * flow;
        }
        return {total_flow, total_cost};
    }
    pair<ll, COST_TYPE> min_cost_flow(){
        return min_cost_flow(source, sink);
    }
    ll flow_on_edge(int edge_index){
        assert(edge_index < sz(edges));
        return edges[edge_index].flow;
    }
};
template <typename T>
vector<T> operator+(const vector<T>& lhs, const vector<T>& rhs){
    vector<T> ans(lhs);
    assert(sz(ans) == sz(rhs));
    for(int i = 0; i < sz(rhs); ++i)
        ans[i] += rhs[i];
    return ans;
}
template <typename T>
vector<T> operator+=(vector<T>& lhs, const vector<T>& rhs){
    return lhs = lhs + rhs;
}
template <typename T>
vector<T> operator-(const vector<T> lhs, const vector<T> rhs){
    vector<T> ans(all(lhs));
    assert(sz(ans) == sz(rhs));
    for(int i = 0; i < sz(rhs); ++i)
        ans[i] -= rhs[i];
    return ans;
}
template <typename T>
vector<T> operator-=(vector<T>& lhs, const vector<T>& rhs){
    return lhs = lhs - rhs;
}
template <typename T>
T max(const vector<T> arr){
    assert(!arr.empty());
    T ans = arr[0];
    for(auto& cur : arr)
        ans = max(ans, cur);
    return ans;
}
template <typename T>
T min(const vector<T>& arr){
    assert(!arr.empty());
    T ans = arr[0];
    for(auto& cur : arr)
        ans = min(ans, cur);
    return ans;
}
template <typename T>
T max(const set<T>& s){
    assert(!s.empty());
    return *--s.end();
}
template <typename T>
T min(const set<T>& s){
    assert(!s.empty());
    return *s.begin();
}
template <typename T, typename G>
vector<T> set_max(vector<T>& base, const vector<G>& comp){
    assert(sz(base) == sz(comp));
    for(int i = 0; i < sz(comp); ++i)
        base[i] = max(base[i], comp[i]);
    return base;
}
void _(){
    int n1,n2,m;
    cin >> n1 >> n2 >> m;
    vi deg1(n1),deg2(n2);
    vpii edges(m);
    cin >> edges;
    for(auto &_ : edges){
        --_.X;
        --_.Y;
        deg1[_.X]++;
        deg2[_.Y]++;
    }
    int min_deg = min(min(deg1),min(deg2));
    MaxFlow<short> mf;
    for(auto _ : edges)
        mf.add_edge(_.X,_.Y+n1,1);
    for(int i = 0; i < n1; ++i) mf.add_edge(mf.source,i,0);
    for(int i = 0; i < n2; ++i) mf.add_edge(i+n1,mf.sink,0);
    for(int k = 0; k <= min_deg; ++k){
        for(int i = m; i < m+n1+n2; ++i)
            mf.edges[i].change_cap(k);
        mf.max_flow();
        vi deg1(n1+1),deg2(n2+2);
        vi ans;
        for(int i = 0; i < m; ++i)
            if(mf.flow_on_edge(i)){
                deg1[edges[i].X]++;
                deg2[edges[i].Y]++;
                ans.pb(i+1);
            }
        for(int i = 0; i < m; ++i){
            if(mf.edges[i].flow)
                continue;
            if(deg1[edges[i].X] < k){
                ans.pb(i+1);
                deg1[edges[i].X]++;
            }
            if(deg2[edges[i].Y] < k){
                ans.pb(i+1);
                deg2[edges[i].Y]++;
            }
        }
        if(sz(ans) == 0)
            print(0);
        else{
            cout << sz(ans) << ' ';
            print(ans);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    _();
}