

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
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

long double INF = 1e100;
long double EPS = 1e-12;
struct PT {
    long double x, y;
    PT() {}
    PT(long double x, long double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (long double c) const { return PT(x*c, y*c ); }
    PT operator / (long double c) const { return PT(x/c, y/c ); }
};


template<class T> struct Point3D {
    typedef Point3D P;
    typedef const P& R;
    T x, y, z;
    Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
    bool operator<(R p) const {
        return tie(x, y, z) < tie(p.x, p.y, p.z); }
    bool operator==(R p) const {
        return tie(x, y, z) == tie(p.x, p.y, p.z); }
    P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
    P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
    P operator*(T d) const { return P(x*d, y*d, z*d); }
    P operator/(T d) const { return P(x/d, y/d, z/d); }
    T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
    P cross(R p) const {
        return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
    }
    T dist2() const { return x*x + y*y + z*z; }
    long double dist() const { return sqrt((long double)dist2()); }
    

    long double phi() const { return atan2(y, x); }
    

    long double theta() const { return atan2(sqrt(x*x+y*y),z); }
    P unit() const { return *this/(T)dist(); } 

    

    P normal(P p) const { return cross(p).unit(); }
    

    P rotate(long double angle, P axis) const {
        long double s = sin(angle), c = cos(angle); P u = axis.unit();
        return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
    }
};



long double dot(PT p, PT q) { return p.x*q.x+p.y*q.y; }
long double dist2(PT p, PT q) { return dot(p-q,p-q); }
ll dist2(pair<ll,ll> p1,pair<ll,ll> p2){
    return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}
long double cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}



bool top(PT p) {
    return p.y < 0 || p.y == 0 && p.x < 0;
}




bool polarLess(const PT& a, const PT& b) {
    bool ta = top(a);
    bool tb = top(b);
    if (ta != tb)
        return ta;
    return cross(a, b) > 0;
}





PT RotateCCW90(PT p) { return PT(-p.y,p.x); }
PT RotateCW90(PT p) { return PT(p.y,-p.x); }
PT RotateCCW(PT p, long double t) {
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}




PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}


PT ProjectPointSegment(PT a, PT b, PT c) {
    long double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}


long double DistancePointSegment(PT a, PT b, PT c) {
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}


long double DistancePointPlane(long double x, long double y, long double z,
                          long double a, long double b, long double c, long double d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}



bool angleLess(const PT& a1, const PT& b1, const PT& a2, const PT& b2) {
    PT p1(dot(a1, b1), abs(cross(a1, b1)));
    PT p2(dot(a2, b2), abs(cross(a2, b2)));
    return cross(p1, p2) > 0;
}


bool LinesParallel(PT a, PT b, PT c, PT d) {
    return fabs(cross(b-a, c-d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
           && fabs(cross(a-b, a-c)) < EPS
           && fabs(cross(c-d, c-a)) < EPS;
}




bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (LinesCollinear(a, b, c, d)) {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
            dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
        if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
            return false;
        return true;
    }
    if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
    if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
    return true;
}








PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}


PT ComputeCircleCenter(PT a, PT b, PT c) {
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}














bool PointInPolygon(const vector<PT> &p, PT q) {
    bool c = 0;
    for (int i = 0; i < p.size(); i++){
        int j = (i+1)%p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
             p[j].y <= q.y && q.y < p[i].y) &&
            q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}


bool PointOnPolygon(const vector<PT> &p, PT q) {
    for (int i = 0; i < p.size(); i++)
        if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
            return true;
    return false;
}




vector<PT> CircleLineIntersection(PT a, PT b, PT c, long double r) {
    vector<PT> ret;
    b = b-a;
    a = a-c;
    long double A = dot(b, b);
    long double B = dot(a, b);
    long double C = dot(a, a) - r*r;
    long double D = B*B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}




vector<PT> CircleCircleIntersection(PT a, PT b, long double r, long double R) {
    vector<PT> ret;
    long double d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    long double x = (d*d-R*R+r*r)/(2*d);
    long double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back(a+v*x + RotateCCW90(v)*y);
    if (y > 0)
        ret.push_back(a+v*x - RotateCCW90(v)*y);
    return ret;
}








long double ComputeSignedArea(const vector<PT> &p) {
    long double area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}
long double ComputeArea(const vector<PT> &p) {
    return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT> &p) {
    PT c(0,0);
    long double scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++){
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}


bool IsSimple(const vector<PT> &p) {
    for (int i = 0; i < p.size(); i++) {
        for (int k = i+1; k < p.size(); k++) {
            int j = (i+1) % p.size();
            int l = (k+1) % p.size();
            if (i == l || j == k) continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
                return false;
        }
    }
    return true;
}
pair<pair<ll,ll>, pair<ll,ll>> closestPointPair(vector<pair<ll,ll>> v) {
    set<pair<ll,ll>> S;
    sort(v.begin(), v.end(), [](pair<ll,ll> a, pair<ll,ll> b) { return a.second < b.second; });
    pair<ll, pair<pair<ll,ll>, pair<ll,ll>>> ret{LLONG_MAX, {pair<ll,ll>(), pair<ll,ll>()}};
    int j = 0;
    for(pair<ll,ll> p:v){
        pair<ll,ll> d{1 + (ll)sqrt(ret.first), 0};
        while (v[j].second <= p.second - d.first) S.erase(v[j++]);
        auto lo = S.lower_bound({p.first-d.first, p.second-d.second}), hi = S.upper_bound({p.first+d.first, p.second+d.second});
        for (; lo != hi; ++lo)
            ret = min(ret, {dist2(*lo,p), {*lo, p}});
        S.insert(p);
    }
    return ret.second;
}


using namespace std;

class CHarryPotterAndTheGoldenSnitch {
public:
	void solve(std::istream& cin, std::ostream& cout) {
        using PT=Point3D<long double>;
        int n;
        cin>>n;
        vector<PT> v(n+1);
        for(int i=0;i<=n;i++){
            long double x,y,z;
            cin>>x>>y>>z;
            v[i]={x,y,z};
        }
        PT p;
        long double xx,yy,zz;
        long double vh,vs;
        cin>>vh>>vs;
        cin>>xx>>yy>>zz;
        p={xx,yy,zz};
        long double dist=0;
        for(int i=1;i<=n;i++){
            dist+=(v[i]-v[i-1]).dist();
        }
        long double lo=0,hi=dist/vs,ans=INFINITY;
        for(int j=0;j<300;j++){
            long double mid=(lo+hi)/2;
            long double time=mid;
            PT position;
            for(int i=1;i<=n;i++){
                long double tt=(v[i]-v[i-1]).dist()/vs;
                if(tt<time)
                    time-=tt;
                else{
                    position=v[i-1]+(v[i]-v[i-1]).unit()*vs*time;
                    break;
                }
            }
            if((position-p).dist()<=vh*mid || (position-p).dist()-vh*mid<=EPS){
                ans=mid;
                hi=mid;
            }else{
                lo=mid;
            }
        }
        if(ans==INFINITY){
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        cout<<fixed<<setprecision(10)<<ans<<endl;
        PT pos;
        long double time=ans;
        for(int i=1;i<=n;i++){
            long double tt=(v[i]-v[i-1]).dist()/vs;
            if(tt<time)
                time-=tt;
            else{
                pos=v[i-1]+(v[i]-v[i-1]).unit()*vs*time;
                break;
            }
        }
        cout<<fixed<<setprecision(10)<<pos.x<<" "<<fixed<<setprecision(10)<<pos.y<<" "<<fixed<<setprecision(10)<<pos.z<<endl;

	}
};


int main() {
	CHarryPotterAndTheGoldenSnitch solver;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
