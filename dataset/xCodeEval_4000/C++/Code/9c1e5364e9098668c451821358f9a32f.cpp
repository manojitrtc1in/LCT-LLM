#include<bits/stdc++.h>
#define pb push_back
#define Int int64_t
using namespace std;

int64_t N,M,K;
long long h,w;
int64_t X,Y,Z;
long long B;


const int MOD=1e9+7;



const int MAXN=1e6+5;
const int NAX=1005;
vector<int> adj[MAXN];
vector<pair<int,int64_t>> G[MAXN];
vector<Int> A;

Int ceilS(Int x,Int y){
    return (x+y-1)/y;
}

Int perform(Int x){
    return (x*(x+1))/2LL;
}

vector<pair<int64_t,int64_t>> factorize(int64_t x){

    vector<pair<int64_t,int64_t>> factors;

    for(int64_t i=2;i*i<=x;++i){
        if(x % i) continue;
        int cnt=0;

        while(x % i ==0){
            x/=i;
            ++cnt;
        }
        factors.pb({i,cnt});
    }
    if(x > 1){
        factors.pb({x,1});
    }
    return factors;
}


vector<long long> fac(MAXN);
struct DSU{
    vector<int> SZ,ID;
    int n;
    int cc;

    DSU(int n){
        SZ.resize(n);
        ID.resize(n);
        cc=n;
        this->n=n;
        for(int i=0;i<n;++i){
            SZ[i]=1;
            ID[i]=i;
        }
    }

    int find(int x){
        return (ID[x]==x ? x:ID[x]=find(ID[x]));
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }

    void merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y) return;
        if(SZ[x]<SZ[y]) {
            swap(x,y);
        }

        SZ[x]+=SZ[y];
        ID[y]=x;
        --cc;
    }

};

long long ModExpo(long long x,unsigned long long y,long long M){
    Int ans=1;
    ans=(long long)ans;

    x %= M;
    if(x == 0)
        return 0;
    
    while(y>0){
        if(y&1) ans=((ans%M)*(x%M))%M;
        y>>=1LL;
        x=((x%M)*(x%M))%M;
    }
    return ans%M;
}



long long ModInv(long long x){
    return ModExpo(x,MOD-2,MOD);
}
Int madd(Int x,Int y){
    return (x+y)%MOD;
}

Int mmul(Int x,Int y){
    return ((x%MOD)*(y%MOD))%MOD;
}

Int performMod(Int x){
    return mmul(mmul(x,x+1),ModInv(2))%MOD;
}
void fill(){
    fac[0]=1;
    for(int i=1;i<MAXN;++i){
        fac[i]=mmul(fac[i-1],i)%MOD;
    }
}

long long choose(long long n,long long r){
    if(r==0||r==n) return 1;
    if(r>n) return 0;

    return mmul(mmul(fac[n],ModInv(fac[n-r])),ModInv(fac[r]))%MOD;
}

struct TrieNode{
    int value;
    TrieNode* children[2];
    TrieNode(){
        children[0] = children[1] = nullptr;
        value = 0;
    }
};

struct LCA{
    const int LN = 20;
    vector<int64_t> lev;
    vector<vector<int>> memo;
    int n;
    LCA(int n ){
        this -> n=n;
        lev.resize(n + 1);
        memo.resize(n + 1);
        for(int i=0; i <= n; ++i){
            memo[i].resize(LN+1);
        }
    }
 
 
    function<void(int,int)> dfs=[&](int u, int par){
        memo[u][0] =  par;
        for(int i =1 ; i <= LN; ++i)
            memo[u][i] = memo[memo[u][i-1]][i-1];
 
        for(auto &v : adj[u]){
            if(v != par){
                lev[v] = lev[u] + 1;
                dfs(v,u);
            }
        }
    };
 
    int lca(int u, int v){
        if(lev[u] < lev[v])
            swap(u,v);
 
        for(int i= LN ; i >=0; --i){
            if((lev[u] - (1LL << i)) >= lev[v])
                u=memo[u][i];
        }
 
        if(u==v)
            return u;
 
        for(int i= LN ; i >=0; --i){
            if(memo[u][i] != memo[v][i]){
                u=memo[u][i];
                v=memo[v][i];
            }
        }
 
        return memo[u][0];
    }
 
    int64_t dist(int u , int v){
        int p = lca(u, v);
        return lev[u] + lev[v] - 2 * lev[p];
    }
};


struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e9;
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
        adj[v].push_back(edges.size());
        edges.emplace_back(v, u, cap);
        adj[u].push_back(edges.size());
        edges.emplace_back(u, v, 0);

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

    long long dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min((long long)pushed, edges[id].cap - edges[id].flow));
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
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};


struct Fenwick{
    vector<long long> BIT;
    int n;  
        Fenwick(int n){
            BIT.resize(n);
            BIT.assign(n ,0);
            this->n=n;
        }


        void add(int x,int64_t value){
            while(x<n){
                BIT[x] +=value;
                x+=(x&(-x));
            }
        }
        long long sum(int64_t x){
            long long answer= 0;
            while(x){
                answer += BIT[x];
                x-=(x&(-x));
            }
            return answer;
        }

        void rangeAdd(int L , int R , int64_t value){
            add(L , value);
            add(R + 1, -value);
        }
        
        long long rangeSum(int L,int R){
            return sum(R)-sum(L-1);
        }
};

Int countInversions(vector<Int> arr){
    Int inv=0;
    int n=arr.size();
    Fenwick BIT(MAXN);

    for(int i=(int)arr.size()-1;i>=0;--i){
        inv+=BIT.sum(arr[i]-1);
        BIT.add(arr[i],1);
    }
    
    return inv;
}

struct segTree{
    vector<int64_t> ST;
    int n;
    vector<int64_t> arr;
    function<int64_t(int64_t , int64_t)> func;
        segTree(int n,vector<int64_t> arr, function<int64_t(int64_t, int64_t)> func){
            ST.resize(4*n);
            this->arr=arr;
            this->n=n;
            this->func = func;
        }

        void build(int l,int r,int pos){
            if(l==r){
                ST[pos]=arr[l];
                return;
            }

            int mid=(l+r)/2;
            build(l,mid,2*pos+1);
            build(mid+1,r,2*pos+2);
            ST[pos]= func(ST[2*pos+1], ST[2*pos+2]);

        }


        int64_t query(int l, int r,int x,int y,int pos){
            if(x>=l && y<=r) return ST[pos];
            if(x>r || y<l) return 0;

            int mid=(x+y)/2;
            return func(query(l,r,x,mid,2*pos+1) , query(l,r,mid+1,y,2*pos+2));
        }



        void update(int l,int r,int pos,int64_t value,int idx){
            if(idx < l || idx>r) return;
            if(l==r){
                arr[idx]=value;
                ST[pos]=value;
            }
            else{
                int mid=(l+r)/2;
                if(idx >=l && idx<=mid){
                    update(l,mid,2*pos+1,value,idx);
                }
                else update(mid+1,r,2*pos+2,value,idx);
                ST[pos]=func(ST[2*pos+1] , ST[2*pos+2]);
            }
            return;
        }
};

struct RMQ_sparse{
    vector<vector<int64_t>> RMQ;
    int n;
    int LN;
    vector<int64_t> a;
    RMQ_sparse(vector<int64_t> a,int n){
        this->n=n;
        this->a =a;
        LN = ceil(log2(n)) + 1;
        RMQ.resize(n);
        for(int i=0; i < n; ++i){
            RMQ[i].resize(LN);
            RMQ[i][0]=i;
        }
    }

    void process(){
        for(int j=1 ; (1 << j) < a.size(); ++j){
            for(int i= 0; i  +(1 << j) -1 < a.size(); ++i){
                if (a[RMQ[i][j - 1]] <= a[RMQ[i + (1 << (j - 1))][j - 1]])
                    RMQ[i][j] = RMQ[i][j - 1];
                else
                    RMQ[i][j] = RMQ[i + (1 << (j - 1))][j - 1];
            }
        }
    }


    int RMQ_index(int l, int r){
        int j=floor(log2(r - l +1));
        int start=l,end=r;
         if (a[RMQ[start][j]] <= a[RMQ[end-(1<<j)+1][j]])
            return RMQ[start][j];
         else
            return RMQ[end-(1<<j)+1][j];
    }
}; 

const Int INF=2e18+5;
using D=long double;


vector<long long> parSum;
vector<int> lev;
void level_assign(int u,int par,int lvl){
    lev[u]=lvl;
    for(int child:adj[u]){
        if(child!=par){
            level_assign(child,u,lvl+1);
        }
    }
}

struct minqueue{
    deque<int64_t> q;
    int64_t getMin(){
        if(q.empty())
            return -1;
        return q.front();
    }

    void add(int64_t x){
        while(!q.empty() and q.back() > x)
            q.pop_back();
        q.pb(x);
    }


    void remove(int64_t x){
        if(q.size() and q.front() == x)
            q.pop_front();
    }
};

const D pi =3.1415926535897932385;


struct FordFulkerson{
    vector<vector<long long>> rGraph;
    vector<vector<int>> graph;

    int source , sink , n;
    FordFulkerson(int n, int s , int t){
        this-> n = n;
        rGraph.resize(n);
        graph.resize(n);
        for(int i = 0 ; i < n ; ++i){
            rGraph[i].resize(n);
            graph[i].resize(n);
        }
        source = s ;
        sink = t;
    }

    void add_edge(int u , int v , long long cap){
        rGraph[u][v] = cap;
        graph[u][v] = cap;
    }

    bool bfs(vector<int> &parent){
        queue<int> q;
        q.push(source);

        vector<bool> visited(n);
        visited[source] = true;
        parent[source] = -1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int i = 0; i < n ; ++i)
                if(!visited[i] and rGraph[u][i] > 0){
                    q.push(i);
                    parent[i] = u;
                    visited[i] = true;
                }
        }
        return visited[sink] == true;
    }

    void dfs(int u , vector<bool> &visited){
        visited[u] = true;
        for(int v = 0 ; v < n ; ++v){
            if(!visited[v] and rGraph[u][v] > 0)
                dfs(v , visited);
        }
    }

    long long flow(){
        long long flow = 0;
        vector<int> parent(n);
        while(bfs(parent)){
            long long augmenting_flow = 1e16;
            for(int v = sink ; v != source ; v = parent[v]){
                augmenting_flow = min(augmenting_flow , rGraph[parent[v]][v]);
            }
            flow += augmenting_flow;
            for(int v = sink ; v != source ; v = parent[v]){
                int u = parent[v];
                rGraph[u][v] -= augmenting_flow;
                rGraph[v][u] += augmenting_flow;
            }
        }
        return flow;
    }

    pair<vector<pair<int, int>> , long long> min_cut(){
        long long f = flow();
        vector<bool> visited(n);

        dfs(source , visited);
        vector<pair<int, int>> edges;

        for(int u = 0 ; u < n ; ++u){
            for(int v = 0 ; v < n ; ++v){
                if(visited[u] and !visited[v] and graph[u][v])
                    edges.emplace_back(u , v);
            }
        }
        
        return {edges , f};
    }

};

void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len-1];
                continue;
            }
        }
    }
}

int KMP(string pattern,string text){
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);
    
    lps_func(pattern,Lps); 
    
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} 
        if (j == m) { 
            return i - m; 
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {
            if (j == 0)          
                i++;
            else
                j = Lps[j - 1];
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        string S ; cin >> S;
        cin >> K;
        
        int hours = 10 * (S[0] -'0') + (S[1]-'0') , minutes = 10 * (S[3] - '0') + (S[4] - '0');
        int time_now = hours * 60 + minutes;
        int curr = time_now;
        
        auto convert=[&](int x)->string{
            int hours = (x / 60) % 24;
            int minutes = x % 60;
            string answer;
            if(hours <= 9){
                answer += '0';
            }
            answer += to_string(hours);
            answer += ':';
            if(minutes <= 9){
                answer += '0';
            }
            answer += to_string(minutes);
            return answer;
        };
       
        auto isPal=[&](string a)->bool{
            string b = a;
            reverse(b.begin() , b.end());
            return b == a;
        };
        
        int time_elapsed = 0, answer = 0;
        set<string> s;
        int iter = 0 ;
        while(iter <= 1440){
            if(isPal(convert(curr)))
                s.insert(convert(curr));
            curr += K;
            time_elapsed += K;
            ++iter;
        }
        
        cout << s.size() <<'\n';
    }
}