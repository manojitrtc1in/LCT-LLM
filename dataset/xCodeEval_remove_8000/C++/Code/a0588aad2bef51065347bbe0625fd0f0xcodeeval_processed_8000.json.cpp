



















using namespace std;
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;
const dl EPS = 1e-10;


struct wor {
    dl x = 0, y = 0;
};


dl dist(wor a, wor b) {
    dl answer = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return answer;
}
istream& operator >> (istream & is,vector<ll> &arr){
    for(auto &e : arr){
        is>>e;
    }
    return is;
}

























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































pair<vector<dl>,vector<ll>> id0(ll from ,ll n , vector<vector<pair<dl,ll>>> &adj){
    vector<bool> used(n);
    vector<dl> d (n,1e15);
    vector<ll> f(n);
    d[from ] =0;
    f[from]= from;
    for(int i = 0 ; i <n ; i ++){
        ll mi =-1;
        for(int i =0 ; i < n ; i ++){
            if(!used[i]){
                mi = i;
                break;
            }
        }
        for(int j = 0 ; j < n ; j ++){
            if(!used[j] && d[j] < d[mi]){
                mi = j;
            }
        }
        used[mi] = true;
        for(auto e :adj[mi]){
            if(!used[e.second] && d[mi] + e.first < d[e.second] ){
                d[e.second] = d[mi] + e.first;
                f[e.second] = mi;
            }
        }
    }
    return {d,f};
}








































































































































struct Kun{
    ll n;
    vector<vector<ll>> adj;
    vector<ll> used;
    vector<bool> is_l;
    vector<ll> mt;
    Kun(ll n ){
        this-> n = n;
        adj.resize(n);
        used.resize(n);
        mt.resize(n);
        is_l.resize(n);
    }
    void add_edge(ll u ,ll v){
        adj[u]. push_back(v);
        adj[v]. push_back(u);
    }
    void make_left(ll v){
        is_l[v] = true;
    }
    bool try_kun(ll v, ll cur){
        if(used[v] == cur)return false;
        used[v] = cur;
        for(auto e : adj[v]){
            if(mt[ e] == -1 || try_kun(mt[e],cur)){
                mt[e] = v;
                return true;
            }
        }
        return false;
    }
    ll max_matching(){
        vector<bool> usel(n);
        for(int i = 0 ; i < n; i ++){
            if(!is_l[i])mt[i] = -1;
        }
        ll answer =0;
        for(int i = 0 ; i < n; i ++){
            if(is_l[i]){
                for(auto e : adj[i]){
                    if(mt[e] ==-1){
                        mt[e]=i;
                        answer++;
                        usel[i]=true;
                        break;
                    }
                }
            }
        }
        ll z =1;
        for(int i = 0 ; i < n ; i ++){
            if(is_l[i] && !usel[i] && try_kun(i,z++))answer++;
        }
        return answer;
    }

};


struct id1{
    struct edge{
        ll from ,to , cap , flow ,cost;
    };
    vector<edge> edges;
    vector<vector<ll>> adj;
    vector<ll> p;
    vector<ll> d;
    vector<ll> state;
    const ll lenin_inf = 2e9;
    ll n,s,t;

    id1(ll _n , ll _s,ll _t){
        n = _n;
        s = _s;
        t = _t;
        p.resize(n);
        d.resize(n);
        state.resize(n);
        adj.resize(n);
    }
    void add_edge(ll from , ll to ,ll cap, ll cost){
        edge e1= {from,to,cap,0,cost};
        edge e2 = {to,from,0,0,-cost};
        adj[from].push_back(edges.size());
        edges.push_back(e1);
        adj[to].push_back(edges.size());
        edges.push_back(e2);
    }
    deque<ll> q;
    void relax(ll v, ll dist ,ll from){
        if(d[v]<=dist)return;
        d[v] = dist;
        p[v] = from;
        if(state[v] == 0 ||(!q.empty() && d[v]<d[q.front()])){
            q.push_front(v);
            state[v] =1;
        }else if (state[v] ==2){
            q.push_back(v);
            state[v] =1;
        }
    }

    bool lenin(){
        fill(p.begin(),p.end(),-1);
        fill(d.begin(),d.end(), lenin_inf);
        fill(state.begin(),state.end(),0);
        relax(s,0,0);
        while(!q.empty()){
            ll v = q.front();
            q.pop_front();
            state[v] =2;
            for(auto e : adj[v]){
                if(edges[e].cap - edges[e].flow == 0)continue;
                relax(edges[e].to,d[v]+ edges[e].cost,e);
            }
        }
        return d[t] < lenin_inf;
    }
    pair<ll,ll> max_flow(){
        ll cost = 0 ;
        ll flow = 0;
        while(lenin()){
            ll ed = p[t];
            ll ma = edges[ed].cap - edges[ed].flow;
            while(edges[ed].from != s){
                ma = min(ma,edges[ed].cap - edges[ed].flow);
                ed = p[edges[ed].from];
            }
            ma = min(ma,edges[ed].cap - edges[ed].flow);
            flow +=ma;
            ed = p[t];
            while(edges[ed].from != s){
                edges[ed].flow+=ma;
                edges[ed^1].flow-= ma;
                cost += ma*edges[ed].cost;
                ed = p[edges[ed].from];
            }
            edges[ed].flow+=ma;
            edges[ed^1].flow-= ma;
            cost += ma*edges[ed].cost;
        }
        return {cost,flow};
    }
};
struct Dinic {
    struct edge{
        ll from, to, cap, flow;
    };
    vector<edge> edges;
    vector<ll> ptr;
    vector<vector<ll>> adj;
    vector<ll> level;
    ll n,s,t;
    Dinic(ll _n , ll _s , ll _t){
        n = _n ;
        s = _s;
        t = _t;
        ptr.resize(n);
        adj.resize(n);
        level.resize(n);
    }
    void add_edge(ll from , ll to ,ll cap , ll flow){
        edge e1 = {from,to,cap,flow};
        edge e2 = {to,from, 0 , -flow};
        adj[from].push_back(edges.size());
        edges.push_back(e1);
        adj[to].push_back(edges.size());
        edges.push_back(e2);
    }
    bool bfs(){
        queue<ll> q;
        fill(level.begin(),level.end(),-1);
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            ll v = q.front();
            q.pop();
            for(auto e : adj[v]){
                if(edges[e].cap - edges[e].flow == 0 )continue;
                if(level[edges[e].to] == -1){
                    level[edges[e].to] = level[v]+1;
                    q.push(edges[e].to);
                }
            }
        }

        return level[t]!=-1;
    }
    ll dfs(ll node , ll flow = 1e17){
        if(node == t){
            return flow;
        }

        for(ll &cid = ptr[node] ; cid < adj[node].size() ; cid ++){
            ll id = adj[node][cid];
            ll to = edges[id].to;
            if(level[node] + 1 != level[to] || edges[id].cap - edges[id].flow == 0)continue;

            ll added = dfs(to,min(flow,edges[id].cap - edges[id].flow));
            if(added){
                edges[id].flow +=added;
                edges[id^1]. flow -=added;
                return added;
            }
        }

        return 0;
    }
    ll flow(){
        ll answer =0 ;
        while(bfs()){
            fill(ptr.begin(),ptr.end(),0);
            while(ll added = dfs(s)){
                answer+=added;
            }
        }
        return answer;
    }
};
void dfs(ll node ,vector<vector<ll>> &adj,vector<bool> &used){
    used[node] = true;
    for(auto e : adj[node]){
        if(!used[e]){
            dfs(e,adj,used);
        }
    }
}




























bool vosh(vector<ll> &arr){
    ll mi = arr[0];
    for(int i = 1; i < arr.size() ; i ++){
        if(arr[i] <= mi){
            mi = arr[i];
        }else{
            return true;
        }
    }
    return false;
}
struct ev{
    ll x,y1,y2,type,id;
};
bool comp(ev a, ev b){
    if(a.x ==  b.x)return a.type<b.type;
    return a.x<b.x;
}
void preob(vector<pair<ll,ll>> &a){
    set<ll> s;
    for(auto e : a){
        s.insert(e.second);
        s.insert(e.first);
    }
    vector<ll> arr(s.size());
    ll z =0;
    for(auto e : s){
        arr[z] = e;
        z++;
    }
    for(auto &e : a){
        e.first = lower_bound(all(arr),e.first) -arr.begin();
        e.second = lower_bound(all(arr),e.second) - arr.begin();
    }
}
const ll INF = 5e5;
ll t[4*INF];
ll d[4*INF];
void push(ll v){
    if(d[v] !=0){
        t[v] +=d[v];
        d[2*v+1]+=d[v];
        d[2*v+2]+=d[v];
        d[v] =0;
    }
}
void add(ll v,ll vl, ll vr, ll l,ll r, ll val){
    push(v);
    if(vr < l || vl > r){
        return;
    }
    if(l <= vl && vr <= r){
        d[v] +=val;
        push(v);
        return ;
    }
    ll m = vl + (vr-vl)/2;
    add(2*v+1,vl,m,l,r,val);
    add(2*v+2,m+1,vr,l,r,val);
    t[v] = max(t[2*v+1],t[2*v+2]);
}
ll ma(ll v, ll vl ,ll vr, ll l ,ll r){
    push(v);
    if(vr < l || vl > r){
        return -1e17;
    }
    if(l <= vl && vr <= r){
        return t[v];
    }
    ll m = vl + (vr-vl)/2;
    return max(ma(2*v+1,vl,m,l,r),ma(2*v+2,m+1,vr,l,r));
}
bool func(vector<pair<ll,ll>> &a,vector<pair<ll,ll>> &b){
    ll am = 0;
    vector<ev> events;
    for(int i = 0 ; i < a.size() ; i ++){
        events.push_back({a[i].first,b[i].first,b[i].second,1,i});
        events.push_back({a[i].second,b[i].first,b[i].second,2,i});
    }
    sort(all(events),comp);
    for(int i =0 ; i < events.size() ; i ++){
        if(events[i].type == 1){

            ll z = ma(0,0,INF-1, events[i].y1,events[i].y2);
            if(z!=am)return false;
            add(0,0,INF-1, events[i].y1,events[i].y2,1);
            am++;
        }else{
            am--;
            add(0,0,INF-1, events[i].y1,events[i].y2,-1);
        }
    }
    return true;
}
int main() {




    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    vector<pair<ll,ll>> b(n);
    for(int i = 0; i < n ; i ++){
        cin>>a[i].first>>a[i].second>>b[i].first>>b[i].second;
    }
    preob(a);
    preob(b);
    auto f = func(a,b);
    auto z = func(b,a);
    if(f && z){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;

}