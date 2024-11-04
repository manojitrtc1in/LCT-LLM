



















using namespace std;
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;
const dl EPS = 1e-6;


struct wor {
    ll x = 0, y = 0;
};


dl dist(wor a, wor b) {
    dl answer = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return answer;
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















































































































































































bool by_x(wor a,wor b){
    return a.x<b.x;
}
bool by_y(wor a ,wor b){
    return a.y<b.y;
}
const ll M = 1e9+100;
int main() {




    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;

    wor s;
    cin>>s.x>>s.y;
    vector<wor> arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>arr[i].x>>arr[i].y;
    }










    vector<vector<wor>> d(4,vector<wor>());

    for(int i = 0 ; i < n ; i ++){
        if(arr[i].x <s.x){
            d[0].push_back(arr[i]);
        }
        if(arr[i].x> s.x){
            d[2].push_back(arr[i]);
        }
        if(arr[i].y> s.y){
            d[1].push_back(arr[i]);
        }
        if(arr[i].y<s.y){
            d[3].push_back(arr[i]);
        }
    }
    ll answer =0 ;
    wor res;
    sort(d[0].rbegin(),d[0].rend(),by_x);
    sort(d[2].begin(),d[2].end(),by_x);
    sort(d[1].begin(),d[1].end(),by_y);
    sort(d[3].rbegin(),d[3].rend(),by_y);
    if(d[0].size() > answer){
        answer = d[0].size();
        res.y = s.y;
        res.x = d[0][0].x;
    }
    if(d[1].size() > answer){
        answer = d[1].size();
        res.x = s.x;
        res.y = d[1][0].y;
    }
    if(d[2].size() > answer){
        answer = d[2].size();
        res.y = s.y;
        res.x = d[2][0].x;
    }
    if(d[3].size() > answer){
        answer = d[3].size();
        res.x = s.x;
        res.y = d[3][0].y;
    }
    cout<<answer<<"\n";
    cout<<res.x<<" "<<res.y;;












































































































































































    return 0;
}