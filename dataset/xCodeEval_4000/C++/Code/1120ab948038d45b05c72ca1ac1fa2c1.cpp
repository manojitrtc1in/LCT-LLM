#include <bits/stdc++.h>
using namespace std;
using i64=int_fast64_t;
using pii=pair<int,int>;
template <class T> constexpr T inf=numeric_limits<T>::max() / (T)2;
template <class T> using minheap=priority_queue<T,vector<T>,greater<T>>;
#define fir first
#define sec second
#define mkp make_pair
#define mkt make_tuple
#define emb emplace_back
#define all(v) begin(v),end(v)
i64 binry(i64 ok, i64 ng, const function<bool(i64)> &f) {
    while(abs(ok-ng)>1) {
        i64 mid=(ok+ng)/2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

template <class cost_t = int_fast64_t, class cap_t = int_fast64_t>
struct Flow {
    struct edge { int to; cost_t cost; cap_t cap; edge *rev; };
    size_t V,E;
    bool neg_edge_exist;
    vector<vector<edge>> adj;

    Flow(size_t _V) : V(_V),E(),neg_edge_exist() {
        adj.resize(V);
        if(V <= 3e3) for(size_t v = 0; v != V; ++v) adj[v].reserve(V);
    }

    void add_edge(int from, int to, cost_t cost, cap_t cap) {
        adj[from].emplace_back((edge){ to, cost, cap, nullptr });
        adj[to].emplace_back((edge){ from, -cost, 0, nullptr });
        adj[from].back().rev = &(adj[to].back());
        adj[to].back().rev = &(adj[from].back());
        ++E; if(cost < 0) neg_edge_exist = true;
    }

    vector<cost_t> Dijkstra(int s) {
        vector<cost_t> dist(V,inf<cost_t>);
        priority_queue<pair<cost_t,int>,vector<pair<cost_t,int>>,greater<pair<cost_t,int>>> que;
        que.emplace(dist[s] = 0, s);
        while(!que.empty()) {
            auto p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(edge &e : adj[v]) {
                if(e.cap > 0 && dist[v] + e.cost < dist[e.to]) que.emplace(dist[e.to] = dist[v] + e.cost, e.to);
            } 
        }
        return dist;
    }

    struct Fold_Fulkerson_exe {
        Flow &F;
        vector<bool> used;

        Fold_Fulkerson_exe(Flow &_F) : F(_F) {
            used.resize(F.V);
        }

        cap_t dfs(int v, int t, cap_t f) {
            if(v == t) return f;
            used[v] = true;
            for(edge &e : F.adj[v]) {
                if(!used[e.to] && e.cap > 0) {
                    cap_t d = dfs(e.to,t,min(f,e.cap));
                    if(d > 0) {
                        e.cap -= d;
                        e.rev->cap += d;
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

    cap_t Fold_Fulkerson(int s, int t) { return Fold_Fulkerson_exe(*this).max_flow(s,t); }
    
    struct Dinic_exe {
        Flow &F;
        vector<int> level,itr;

        Dinic_exe(Flow &_F) : F(_F) {
            level.resize(F.V), itr.resize(F.V);
        }

        void bfs(int s) {
            fill(begin(level),end(level),-1);
            queue<int> que;
            level[s] = 0;
            que.emplace(s);
            while(!que.empty()) {
                int v = que.front(); que.pop();
                for(edge &e : F.adj[v]) {
                    if(e.cap > 0 && level[e.to] < 0) {
                        level[e.to] = level[v] + 1;
                        que.emplace(e.to);
                    }
                } 
            }
        }

        cap_t dfs(int v, int t, cap_t f) {
            if(v == t) return f;
            for(int &i = itr[v]; i != F.adj[v].size(); ++i) {
                edge &e = F.adj[v][i];
                if(e.cap > 0 && level[v] < level[e.to]) {
                    cap_t d = dfs(e.to, t, min(f,e.cap));
                    if(d > 0) {
                        e.cap -= d;
                        e.rev->cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        cap_t max_flow(int s, int t) {
            cap_t flow = 0,f;
            while(true) {
                bfs(s);
                if(level[t] < 0) return flow;
                fill(begin(itr),end(itr),0);
                while((f = dfs(s,t,numeric_limits<cap_t>())) > 0) flow += f;
            }
        }
    };

    cap_t Dinic(int s, int t) { return Dinic_exe(*this).max_flow(s,t); }

    struct Primal_Dual_exe {
        Flow &F;
        vector<cost_t> dist,h;
        vector<int> prev_v;
        vector<edge*> prev_e;

        Primal_Dual_exe(Flow &_F) : F(_F) {
            dist.resize(F.V), h.resize(F.V), prev_v.resize(F.V), prev_e.resize(F.V);
        }

        bool Dijkstra(int s, int t) {
            priority_queue<pair<cost_t,int>,vector<pair<cost_t,int>>,greater<pair<cost_t,int>>> que;
            fill(begin(dist),end(dist),inf<cost_t>);
            que.emplace(dist[s] = 0, s);
            while(!que.empty()) {
                cost_t cs; int v;
                tie(cs,v) = que.top();
                que.pop();
                if(cs > dist[v]) continue;
                for(edge &e : F.adj[v]) {
                    if(e.cap > 0 && dist[v] + h[v] + e.cost < dist[e.to] + h[e.to]) {
                        que.emplace(dist[e.to] = dist[v] + h[v] - h[e.to] + e.cost, e.to);
                        prev_v[e.to] = v;
                        prev_e[e.to] = &e;
                    }
                }
            } 
            if(dist[t] >= inf<cost_t>) return false;
            for(int v = 0; v < F.V; ++v) h[v] += dist[v];
            return true;
        }

        cost_t min_cost_flow(int s, int t, cap_t f) {
            cost_t res = 0;
            fill(begin(h),end(h),0);
            while(f > 0) {
                if(!Dijkstra(s,t)) return inf<cost_t>;
                cap_t d = f;
                for(int v = t; v != s; v = prev_v[v]) d = min(d, prev_e[v]->cap);
                f -= d;
                res += d * h[t];
                for(int v = t; v != s; v = prev_v[v]) {
                    prev_e[v]->cap -= d;
                    prev_e[v]->rev->cap += d;
                }
            }
            return res;
        }
    };

    cost_t Primal_Dual(int s, int t, cap_t f) {
        cost_t corr = 0;
        if(neg_edge_exist) {
            neg_edge_exist = false;
            int _s = V++;
            int _t = V++;
            add_edge(_s,s,0,f);
            add_edge(t,_t,0,f);
            s = _s, t = _t;
            for(int v = 0; v < V; ++v) {
                for(edge &e : adj[v]) {
                    if(e.cost < 0) {
                        f += e.cap;
                        add_edge(s,e.to,0,e.cap);
                        add_edge(v,t,0,e.cap);
                        corr += e.cap * e.cost;
                        e.rev->cap += e.cap;
                        e.cap = 0;
                    }
                }
            }
        }
        return Primal_Dual_exe(*this).min_cost_flow(s,t,f) + corr;
    } 
};





















































































































































    


































































































































































































































































int n,qry;
int low[55],up[55];

signed main() {
    cin>>n>>qry;
    Flow<int,int> flow(3000);
    const int s=2998;
    const int t=2999;
    for(int i=0; i<n; ++i) up[i]=n-1;
    for(int i=0; i<qry; ++i) {
        int l,r,v,typ;
        cin>>typ>>l>>r>>v;
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
    if(ans>=1e4) cout<<-1<<"\n";
    else cout<<ans<<"\n"; 
}