


using namespace __gnu_pbds;
 




 

























 





 
































 


























using namespace std;
void printarr(ll a[],ll n){
    forl(i,n){
        p0(a[i]);
    }
    cout<<endl;
}
void printv(vector<ll>&v){
    forl(i,v.S){
        p0(v[i]);
    }
    cout<<endl;
}
vector<ll> res;
void factorize(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
}
vll divs;
void divisor(ll n){
        for(ll i=2;i<=sqrt(n);i++){
            if(n%i==0){
                divs.pb(i);
                if(n/i!=i){
                    divs.pb(n/i);
                }
            }
        }
        divs.pb(1);
        if(n!=1){
            divs.pb(n);
        }
}
vector<ll>prefix_function(string &s) {
    ll n = (ll)s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++) {
        ll j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
ll modexpo(ll x,ll y)  
{   ll res = 1;
    x = x%mod1; 
    if (x == 0) return 0; 
    while (y > 0)  
    {   if (y & 1)res = (res*x) % mod1;  
        y = y>>1; 
        x = (x*x) % mod1;  
    }  
    return res;  
}  






 

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};






vll g[400005];
vll gt[400005];
ll vis[400005];
vll order,component;
vll roots(400005,0);
vll root_nodes;
vll gscc[400005];
void addEdge(ll u,ll v){
    

    g[u].pb(v);
    

    gt[v].pb(u);
}


void dfs1(ll u){
    vis[u]=1;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    order.pb(u);
}


void dfs2(ll u){
    vis[u]=1;
    component.pb(u);
    for(auto v:gt[u]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}


void condense(ll n,vll &selfloop){
    for(ll i=1;i<=n;i++){
        vis[i]=0;
    }
    

    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    

    rev(all(order));
    

    for(ll i=1;i<=n;i++){
        vis[i]=0;
    }
    for (auto x : order)
            if (!vis[x]) {
                dfs2(x);
                ll root = component.front();
                for(auto u : component) 
                {
                    roots[u] = root;
                    selfloop[root] |= selfloop[u];
                }
                root_nodes.push_back(root);
                if(component.S > 1)
                    selfloop[root] = 1;
 
                component.clear();
            }
        for (ll u = 1; u <=n; u++)
            for (auto v : g[u]) {
                ll root_u = roots[u];
                ll root_v = roots[v];
                if (root_v != root_u)
                    gscc[root_v].pb(root_u);
            }
    for(ll i=1;i<=n;i++){
        vis[i]=0;
    }
}

ll dp[400005];
void dfs3(ll x,vll &selfloop)
{
    vis[x] = true;
    for(auto v : gscc[x])
    {
        if(!vis[v])
            dfs3(v,selfloop);
        dp[x] += dp[v];
        selfloop[x] |= selfloop[v];
    }
    if(!dp[x])selfloop[x] = 0;
    dp[x] = min(dp[x], 2ll);
}
 


int main(){
   FAST;
   tc{
       ll n,m;
       cin>>n>>m;
       ll a,b;
       vll selfloop(n+1);
       forl(i,m){
           cin>>a>>b;
           if(a!=b){
           addEdge(a,b);
           }
           if(a==b){
               selfloop[a]=1;
           }
       }
       condense(n,selfloop);
       

        for(auto x : root_nodes)vis[x] = 0;
        dp[roots[1]] = 1;
        for(auto x : root_nodes)
            if(!vis[x])
                dfs3(x,selfloop);
        for(ll i = 1; i <= n; i++)
        {
            int x = roots[i];
            if(selfloop[x])
                cout << "-1 ";
            else
                cout << dp[x] << " ";
        }
        cout << "\n";
       for(ll i=1;i<=n;i++){
           g[i].clear();
           gt[i].clear();
           gscc[i].clear();
           vis[i]=0;
           dp[i]=0;
           roots[i]=0;
       }
       order.clear();
       root_nodes.clear();
       component.clear();
   }
  
  
  
  
    
}































