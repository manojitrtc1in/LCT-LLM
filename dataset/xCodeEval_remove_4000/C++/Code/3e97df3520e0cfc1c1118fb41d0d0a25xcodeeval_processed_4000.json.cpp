
using namespace std;
using i64=int_fast64_t;
using pii=pair<int,int>;
template <class T> constexpr T inf=numeric_limits<T>::max() / (T)2;
template <class T> using minheap=priority_queue<T,vector<T>,greater<T>>;






i64 binry(i64 ok, i64 ng, const function<bool(i64)> &f) {
    while(abs(ok-ng)>1) {
        i64 mid=(ok+ng)/2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
void id2() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}







































































































































    























































































































































































































































template <class cost_t = int_fast64_t, class cap_t = int_fast64_t>
struct Flow {
    struct edge_t { int from, to; cost_t cost; cap_t cap; size_t rev; };
    size_t V,E;
    vector<vector<size_t>> adj;
    vector<edge_t> edge;
    bool id3;

    Flow(size_t _V) : V(_V), E(), edge(), id3()
    {
        adj.resize(V);
    }

    void add_edge(int from, int to, cost_t cost, cap_t cap) {
        size_t pos = edge.size();
        size_t rpos = pos + 1;
        edge.emplace_back((edge_t){ from, to, cost, cap, rpos });
        adj[from].emplace_back(pos);
        edge.emplace_back((edge_t){ to, from, -cost, 0, pos });
        adj[to].emplace_back(rpos); 
        ++E; if(cost < 0) id3 = true;
    }

    vector<cost_t> Dijkstra(int s) {
        vector<cost_t> dist(V,inf<cost_t>);
        priority_queue<pair<cost_t,int>,vector<pair<cost_t,int>>,greater<pair<cost_t,int>>> que;
        que.emplace(dist[s] = 0, s);
        while(!que.empty()) {
            auto p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(size_t i : adj[v]) {
                edge_t &e = edge[i];
                if(e.cap > 0 && dist[v] + e.cost < dist[e.to]) que.emplace(dist[e.to] = dist[v] + e.cost, e.to);
            } 
        }
        return dist;
    }

    struct id4 {
        vector<edge_t> &edge;
        vector<vector<size_t>> &adj;  
        vector<bool> used;

        id4(Flow &_F) : edge(_F.edge), adj(_F.adj)
        {
            used.resize(_F.V);
        }

        cap_t dfs(int v, int t, cap_t f) {
            if(v == t) return f;
            used[v] = true;
            for(size_t i : adj[v]) {
                edge_t &e = edge[i];
                if(!used[e.to] && e.cap > 0) {
                    cap_t d = dfs(e.to,t,min(f,e.cap));
                    if(d > 0) {
                        e.cap -= d;
                        edge[e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        cap_t max_flow(int s, int t) {
            cap_t flow = 0,f;
            while(true) {
                fill(begin(used),end(used),false);
                if((f = dfs(s,t,numeric_limits<cap_t>::max())) > 0) flow += f;
                else break;
            }
            return flow;
        }
    };

    cap_t Fold_Fulkerson(int s, int t) { return id4(*this).max_flow(s,t); }
    
    struct id1 {
        vector<edge_t> &edge;
        vector<vector<size_t>> &adj;
        vector<int> level,itr;

        id1(Flow &_F) : edge(_F.edge), adj(_F.adj)
        {
            level.resize(_F.V), itr.resize(_F.V);
        }

        void bfs(int s) {
            fill(begin(level),end(level),-1);
            queue<int> que;
            level[s] = 0;
            que.emplace(s);
            while(!que.empty()) {
                int v = que.front(); que.pop();
                for(size_t i : adj[v]) {
                    edge_t &e = edge[i];
                    if(e.cap > 0 && level[e.to] < 0) {
                        level[e.to] = level[v] + 1;
                        que.emplace(e.to);
                    }
                } 
            }
        }

        cap_t dfs(int v, int t, cap_t f) {
            if(v == t) return f;
            for(int &i = itr[v]; i < (int)adj[v].size(); ++i) {
                edge_t &e = edge[adj[v][i]];
                if(e.cap > 0 && level[v] < level[e.to]) {
                    cap_t d = dfs(e.to, t, min(f,e.cap));
                    if(d > 0) {
                        e.cap -= d;
                        edge[e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        cap_t max_flow(int s, int t) {
            cap_t flow = 0, f;
            while(bfs(s), level[t] >= 0) {
                fill(begin(itr), end(itr), 0);
                while((f = dfs(s, t, numeric_limits<cap_t>::max())) > 0) flow += f;
            }
            return flow;
        }
    };

    cap_t Dinic(int s, int t) { return id1(*this).max_flow(s, t); }

    struct id0 {
        vector<edge_t> &edge;
        vector<vector<size_t>> &adj;
        vector<cost_t> dist, h;
        vector<int> prev_v;
        vector<edge_t*> prev_e;
        size_t V;

        id0(Flow &_F) : edge(_F.edge), adj(_F.adj), V(_F.V)
        {
            dist.resize(_F.V), h.resize(_F.V), prev_v.resize(_F.V), prev_e.resize(_F.V);
        }

        bool Dijkstra(int s, int t) {
            priority_queue<pair<cost_t,int>,vector<pair<cost_t,int>>,greater<pair<cost_t,int>>> que;
            fill(begin(dist), end(dist), inf<cost_t>);
            que.emplace(dist[s] = 0, s);
            while(!que.empty()) {
                cost_t _cost; int v;
                tie(_cost, v) = que.top();
                que.pop();
                if(_cost != dist[v]) continue;
                for(size_t i : adj[v]) {
                    edge_t &e = edge[i];
                    if(e.cap > 0 && dist[v] + h[v] + e.cost < dist[e.to] + h[e.to]) {
                        que.emplace(dist[e.to] = dist[v] + h[v] - h[e.to] + e.cost, e.to);
                        prev_v[e.to] = v;
                        prev_e[e.to] = &e;
                    }
                }
            } 
            if(dist[t] >= inf<cost_t>) return false;
            for(size_t v = 0; v < V; ++v) {
                h[v] += dist[v];
                if(h[v] > inf<cost_t>) h[v] = inf<cost_t>;
            }
            return true;
        }

        cost_t min_cost_flow(int s, int t, cap_t f) {
            cost_t res = 0;
            fill(begin(h), end(h), 0);
            while(f > 0) {
                if(!Dijkstra(s,t)) return inf<cost_t>;
                cap_t d = f;
                for(int v = t; v != s; v = prev_v[v]) d = min(d, prev_e[v]->cap);
                f -= d;
                res += d * h[t];
                for(int v = t; v != s; v = prev_v[v]) {
                    prev_e[v]->cap -= d;
                    edge[prev_e[v]->rev].cap += d;
                }
            }
            return res;
        }
    };

    cost_t Primal_Dual(int s, int t, cap_t f) {
        cost_t corr = 0;
        if(id3) {
            int _s = V++;
            int _t = V++;
            add_edge(_s, s, 0, f);
            add_edge(t, _t, 0, f);
            s = _s, t = _t;
            for(edge_t &e : edge) {
                if(e.cost <  0) {
                    f += e.cap;
                    add_edge(s, e.to, 0, e.cap);
                    add_edge(e.from, t, 0, e.cap);
                    corr += e.cap * e.cost;
                    edge[e.rev].cap += e.cap;
                    e.cap = 0;
                }
            }
            id3 = false;
        }
        return id0(*this).min_cost_flow(s, t, f) + corr;
    } 
};


int n,qry;
int low[55],up[55];

signed main() {
    

    scanf("%d%d",&n,&qry);
    Flow<int,int> flow(3000);
    const int s=2998;
    const int t=2999;
    for(int i=0; i<n; ++i) up[i]=n-1;
    for(int i=0; i<qry; ++i) {
        int l,r,v,typ;
        scanf("%d%d%d%d",&typ,&l,&r,&v);
        l--,r--,v--;
        if(typ==1) {
            for(int j=l; j<=r; ++j) {
                low[j]=max(low[j],v);
            }
        } else {
            for(int j=l; j<=r; ++j) {
                up[j]=min(up[j],v);
            }
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=low[i]; j<=up[i]; ++j) {
            for(int x=0; x<n; ++x) {
                flow.add_edge(i,n+j*n+x,0,1);
            }
        }
        flow.add_edge(s,i,0,1);
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            flow.add_edge(i*n+n+j,t,j*2+1,1);
        }
    }

    int ans=flow.Primal_Dual(s,t,n);
    if(ans>=1e4) printf("-1\n");
    else printf("%d\n",ans); 
}