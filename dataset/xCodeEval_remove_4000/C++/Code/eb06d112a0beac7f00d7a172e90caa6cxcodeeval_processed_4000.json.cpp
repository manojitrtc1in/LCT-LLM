






















































































































































































































































                                     "<<

                                     "<<

                                     "<<

                                 "<<


 





                        out v[i]<<" ";\
                        out "\n";  


                        in v[i];






using namespace std;
using namespace __gnu_pbds;



    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }







void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}





typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<long double,long double> pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> OST;

template<class T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
ll pow(ll a,ll p,ll m)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%M;p>>=1;}
return res;}


const ldb pi=3.141592653589793238462643383;
const int MAXN = (int)((1e5) + 10);
using vi = vector<int>;
template<typename T>
istream &operator>>(istream &in, vector<T> &vec) {
    for (auto &x : vec) {
        in >> x;
    }
    return in;
}

ll divide(string s, ll x){
    vector <ll> a;
    for(int i = 0; i < s.size(); ++i){
        a.pb((ll)s[i] - '0');
    }
    ll temp = 0;
    for(int i = 0; i < a.size(); ++i){
        temp = temp *10 + a[i];
        if(temp >= x){
            temp %= x;
        }
    }
    return temp;
}

int id2(int a, int b, int m){
    int result = 1;
    while(b>0){
        if(b & 1){
            result = (result  * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}

long long multiply(long long a, long long b, long long m){
    long long result = 0;
    while(b>0){
        if(b & 1){
            result = result + a;
            result %= m;
        }
        a <<= 1;
        a %= m;
        b >>= 1;
    }
    return result;
}

long long id4(long long a, long long b, long long m){
    long long result = 1;
    while(b>0){
        if(b & 1){
            result = multiply(result, a, m);
        }
        a = multiply(a, a, m);
        b >>= 1;
    }
    return result;
}


const int P = (1 << 21) + 5;
int  a[P];
LL cnt[P];
LL dp[P];

LL call(int mask,int m){
    if(mask == 0)return 0;
    if(dp[mask] != -1)return dp[mask];
    LL ret = 0;
    for(int i = 0;i < m;i++){
        if(mask & (1 << i)){
            ret = max(ret,(1LL << i) * cnt[mask] + call(mask ^ (1 << i),m));
        }
    }
    return dp[mask] = ret;
}
ll min(ll a,ll b)
{
    return (a<=b?a:b);
}
ll max(ll a,ll b)
{
    return (a>=b?a:b);
}
ll gd(ll a,ll b)
{
    if(b==0)
    return a;
    return gd(b,a%b);
}
ll pwr(ll a,ll b)
{
    ll res=0;
    while(b)
    {
        if(b%2==1)
        {
            res*=a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
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

    Dinic(int n, int s, int t) : n(n),  t(t) {
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
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
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









int minKey(int key[], bool mstSet[])  
{  
    

    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  




void id0(int parent[], int graph[V][V])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
  






void id3(int graph[V][V])  
{  
    

    int parent[V];  
      
    

    int key[V];  
      
    

    bool mstSet[V];  
  
    

    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    

    

    key[0] = 0;  
    parent[0] = -1; 

  
    

    for (int count = 0; count < V - 1; count++) 
    {  
        

        

        int u = minKey(key, mstSet);  
  
        

        mstSet[u] = true;  
  
        

        

        

        

        for (int v = 0; v < V; v++)  
  
            

            

            

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
    

    id0(parent, graph);  
}

void id1(){
     FIO;             
    
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
}



long long int n;

int32_t main(){
    FIO;
    id1();
    w(t)
    
    {    
    	 vector<ll> s1;
        vector<ll> s2;
        for(int axy=0; axy<n; axy++){
            int abcd = 1;
            int bcde = 0;
            int teemp;
            teemp  = abcd;
            abcd = bcde; 
            bcde = teemp;
            break;
        }
        int n;
        cin>>n;
        map<ll,ll> mp;
        for(int axy=0; axy<n; axy++){
            int abcd = 1;
            int bcde = 0;
            int teemp;
            teemp  = abcd;
            abcd = bcde; 
            bcde = teemp;
            break;
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            while(true){
                int abc = 0;
                abc++;
                abc++;
                abc--;
                break;
            }
            if(mp[x]==1){
                s2.push_back(x);
            }
            else{
                mp[x]=1;
                s1.push_back(x);
            }
        }
        while(true){
            int abc = 0;
            abc++;
            abc++;
            abc--;
            break;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(auto x:s1){
            cout<<x<<" ";
        }
        for(auto x:s2){
            cout<<x<<" ";
        }
        cout<<endl;
    }




        
    
    
    return 0;
}