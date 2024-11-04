

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>


using namespace std;


using ll = long long;
ll mod=1000000007;
ll *fact, *ifact;

using cd = complex<long double>;
const long double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
struct MinCostMaxFlow {
    static const flow_t FLOW_INF = numeric_limits<flow_t>::max() / 2;
    const cost_t COST_INF = numeric_limits<cost_t>::max() / 2;
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

template <typename T>
void coordinateCompress(vector<T> &v, T start = 1){
    vector<T> cpy = v;
    sort(cpy.begin(), cpy.end());
    map<T,T> mp;
    for(T x:cpy){
        mp[x]=start++;
    }
    for(T &x:v){
        x=mp[x];
    }
}
using namespace std;


class BIT{
public:
	vector<ll> tree;
	int n;
	BIT(int n):n(n),tree(n+10){};
	void add(int index, ll value){
		for(;index<=n+5;index+=index&-index){
			(tree[index]+=value)%=mod;
		}
	}
	ll sum(int index){
		ll ans = 0;
		for(;index>0;index-=index&-index){
			(ans+=tree[index])%=mod;
		}
		return ans;
	}
};
struct state{
	int len, link;bool clone;map<char, int> next;bool str0,str1,str2;
};
const ll MAXLEN = 1000005;state st[MAXLEN * 2];
ll sz,last;ll endpos[2*MAXLEN][3];

class EThreeStrings {
	void sa_init() {
		sz=0;
		last=0;
		

		memset(endpos,0, sizeof(endpos));
		st[0].len = 0;st[0].link = -1;sz++;last = 0;
	}
	void sa_extend(char c, int str){
		ll cur = sz++;st[cur].len = st[last].len + 1;
		st[cur].clone = false;
		if(str==0)st[cur].str0=true;
		else if(str==1)st[cur].str1=true;
		else if(str==2)st[cur].str2=true;

		ll p = last;
		while (p != -1 && !st[p].next.count(c)){
			st[p].next[c] = cur;p = st[p].link;
		}
		if (p == -1) {
			st[cur].link = 0;
		} else {
			ll q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) {
				st[cur].link = q;
			} else {
				ll clone = sz++;st[clone].len = st[p].len + 1;
				st[clone].next = st[q].next;st[clone].link = st[q].link;
				st[clone].clone = true;
				st[clone].str0=st[clone].str1=st[clone].str2=false;
				while (p != -1 && st[p].next[c] == q) {
					st[p].next[c] = clone;p = st[p].link;
				}
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
public:
	void solve(std::istream& cin, std::ostream& cout) {

		sa_init();
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		string s=s1+"A"+s2+"B"+s3;
		for(int i=0;i<s.length();i++)
			if(i<s1.length())
				sa_extend(s[i],0);
			else if(i==s1.length())
				sa_extend(s[i], -1);
			else if(i<s1.length()+s2.length()+1)
				sa_extend(s[i], 1);
			else if(i==s1.length()+s2.length()+1)
				sa_extend(s[i], -1);
			else
				sa_extend(s[i], 2);

		vector<ll> vt;
		for(ll i=0 ; i<sz ; i++)vt.push_back(i);
		sort(vt.begin(), vt.end(), [&](ll i, ll j){
			return st[i].len > st[j].len;
		});

		for(ll i=0 ; i<sz ; i++){
			ll idx = vt[i];
			if(st[idx].clone == false && idx != 0)
			{
				if(st[idx].str0)
					endpos[idx][0]++;
				if(st[idx].str1)
					endpos[idx][1]++;
				if(st[idx].str2)
					endpos[idx][2]++;
			}
			if(idx!=0) {
				endpos[st[idx].link][0] += endpos[idx][0];
				endpos[st[idx].link][1] += endpos[idx][1];
				endpos[st[idx].link][2] += endpos[idx][2];
			}
		}
		for(ll i=0;i<sz;i++){
			ll idx=vt[i];
			if(idx!=0){
				st[st[idx].link].str0 = st[st[idx].link].str0 || st[idx].str0;
				st[st[idx].link].str1 = st[st[idx].link].str1 || st[idx].str1;
				st[st[idx].link].str2 = st[st[idx].link].str2 || st[idx].str2;
			}
		}

		BIT bit(300000);
		for(int i=1;i<sz;i++){
			if(st[i].str0 && st[i].str1 && st[i].str2){
				int l2=st[i].len;
				int l1=st[st[i].link].len+1;
				ll val = endpos[i][0]*endpos[i][1];
				val%=mod;
				val*=endpos[i][2];
				val%=mod;
				bit.add(l1, val);
				bit.add(l2+1, mod-val);
			}
		}
		for(int i=1;i<=min({s1.length(), s2.length(), s3.length()});i++){
			cout<<bit.sum(i)<<" ";

		}
		cout<<endl;
	}
};


int main() {
	EThreeStrings solver;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
