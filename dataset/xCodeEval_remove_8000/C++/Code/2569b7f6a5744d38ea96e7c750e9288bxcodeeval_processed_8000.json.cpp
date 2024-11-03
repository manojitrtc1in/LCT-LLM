



















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

























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































pair<vector<dl>,vector<ll>> id1(ll from ,ll n , vector<vector<pair<dl,ll>>> &adj){
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














































































struct Kun1{
    ll n;
    vector<vector<ll>> adj;
    vector<ll> used;
    vector<bool> is_l;
    vector<ll> mt;
    Kun1(ll n ){
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






























































































































































struct id2{
    struct edge{
        ll from,to,flow,cap,cost;
    };
    vector<edge> edges;
    vector<vector<ll>> adj;
    vector<ll> d;
    vector<ll> p;
    deque<ll> q;


    vector<ll> state;
    const ll levit_inf = 2e9;
    ll n,s,t;
    id2(ll _n, ll _s,ll _t){
        n = _n;
        s=_s;
        t=_t;
        adj.resize(n);
        d.resize(n);
        p.resize(n);


        state.resize(n);
    }
    void add_edge(ll from , ll to , ll cap, ll cost){
        edge e1 ={from,to,0,cap,cost};
        edge e2 ={to,from,0,0,-cost};
        adj[from].push_back(edges.size());
        edges.push_back(e1);
        adj[to].push_back(edges.size());
        edges.push_back(e2);

    }


    void relax(ll v,ll dist,ll from){
        if(d[v] <=dist){
            return;
        }
        d[v] = dist;
        p[v]= from;

        if(state[v] == 0 ||(!q.empty() && d[q.front()] > d[v])){
            q.push_front(v);
            state[v] = 1;
        }else if(state[v] == 2 ){
            q.push_back(v);
            state[v] =1;
        }

    }
    bool levit(){

        fill(d.begin(),d.end(),levit_inf);
        fill(p.begin(),p.end(),-1);


        relax(s,0,0);
        while(!q.empty()){
            ll v = q.front();
            q.pop_front();
            state[v] = 2;


            for(auto i = 0 ; i< adj[v].size(); i++){
                auto e = adj[v][i];
                if(edges[e].flow < edges[e].cap){
                    relax(edges[e].to,d[v] + edges[e].cost,e);
                }
            }
        }

        return d[t]<levit_inf;
    }
    pair<ll,ll> max_flow(){
        ll flow=0;
        ll cost = 0;

        while(levit()){









            ll ed = p[t];
            ll mi_fl=edges[ed].cap-edges[ed].flow;
            while(edges[ed].from!=s){
                mi_fl = min(mi_fl,edges[ed].cap-edges[ed].flow);
                ed = p[edges[ed].from];
                

            }


            mi_fl = min(mi_fl,edges[ed].cap-edges[ed].flow);


            ed = p[t];
            while(edges[ed].from!=s){
                edges[ed].flow+=mi_fl;
                edges[ed^1].flow-=mi_fl;
                cost += edges[ed].cost*mi_fl;
                ed = p[edges[ed].from];
            }
            edges[ed].flow+=mi_fl;
            edges[ed^1].flow-=mi_fl;
            cost += edges[ed].cost*mi_fl;
            flow+=mi_fl;



        }
        return {cost,flow};
    }

};






































































































int main() {




    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t;
    cin>>t;
    ll n;
    cin>>n;
    vector<pair<string,ll>> arr(n);
    vector<vector<ll>> num(n);
    ll sum =0 ;
    ll z = n+1;
    for(int i = 0; i < n ; i ++){
        cin>>arr[i].first>>arr[i].second;
        for(int j = 0 ; j < arr[i].first.length();j++){
            num[i].push_back(z++);
        }
        sum+=arr[i].first.length();
    }

    id2 id0(2 + t.length() + n+sum,0,2 + t.length() + n+sum-1);
    for(int i = 0 ; i < n; i ++){
        id0.add_edge(0,i+1,arr[i].second,0);
    }
    for(int i = 1; i <=n ; i ++){
        for(auto e : num[i-1]){
            id0.add_edge(i,e,1,0);
        }
    }
    vector<ll> tn;
    for(int i = 0 ; i < t.length() ; i ++){
        tn.push_back(z++);
    }
    for(int i =1; i<=n ; i ++){
        for(int j= 0 ; j < arr[i-1].first.length() ; j++){
            for(int z = 0 ; z < t.length() ; z++){
                if(t[z] == arr[i-1].first[j]){
                    id0.add_edge(num[i-1][j],tn[z],1,i);
                }
            }
        }
    }
    for(auto e : tn){
        id0.add_edge(e,2 + t.length() + n+sum-1,1,0);
    }
    auto e = id0.max_flow();
    if(e.second !=t.length()){
        cout<<-1;
    }else{
        cout<<e.first;
    }
    return 0;

}