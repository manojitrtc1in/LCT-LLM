
using namespace std;
using ll=long long int;



template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
template<typename T> constexpr int bitUP(T x,int a){return (x>>a)&1;}


int dh[4]={0,1,0,-1}, dw[4]={1,0,-1,0};




long double EPS = 1e-6;
long double PI = acos(-1);
const ll INF=(1LL<<62);
const int MAX=(1<<30);
constexpr ll MOD=1000000000+7;




inline void bin101(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
}

using pii=pair<int,int>;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using psi=pair<string,int>;
using pis=pair<int,string>;
using psl=pair<string,ll>;
using pls=pair<ll,string>;
using pss=pair<string,string>;

using Graph=vector<vector<int>>;

template<typename T >
struct edge {
	int to;
	T cost;
	edge()=default;
	edge(int to, T cost) : to(to), cost(cost) {}

};
template<typename T>
using WeightGraph=vector<vector<edge<T>>>;

template<typename T>
void CinGraph(int M,WeightGraph<T> &g,bool directed=false,bool index1=true){
    while(M--){
        int s,t;
        T cost;
        cin>>s>>t>>cost;
        if(index1) s--,t--;
        g[s].emplace_back(t,cost);
        if(not directed) g[t].emplace_back(s,cost);
    }
}

void CinGraph(int M,Graph &g,bool directed=false,bool index1=true){
    while(M--){
        int s,t;
        cin>>s>>t;
        if(index1) s--,t--;
        g[s].push_back(t);
        if(not directed) g[t].push_back(s);
    }
}




template<typename T>
inline istream &operator>>(istream &is,vector<T> &v) {
    for(size_t i=0;i<v.size();i++) is>>v[i];
	return is;
}
 


template<typename T>
inline istream &operator>>(istream &is,vector<vector<T>> &v) {
    for(size_t i=0;i<v.size();i++){
        is>>v[i];
    }
    return is;
}


template<typename T>
inline ostream &operator<<(ostream &os,const vector<T> &v) {
    for(size_t i=0;i<v.size();i++){
        if(i) os<<" ";
        os<<v[i];
    }
    return os;
}


template<typename T>
inline ostream &operator<<(ostream &os,const vector<vector<T>> &v) {
    for(size_t i=0;i<v.size();i++){
        os<<v[i];
        if(i+1!=v.size()) os<<"\n";
    }
    return os;
}



template<typename T>
inline ostream &operator<<(ostream &os,const Graph &g) {
    for(size_t i=0;i<g.size();i++){
        for(int to:g[i]){
            os<<i<<"->"<<to<<" ";
        }
        os<<endl;
    }
    return os;
}



template<typename T>
inline ostream &operator<<(ostream &os,const WeightGraph<T> &g) {
    for(size_t i=0;i<g.size();i++){
        for(auto e:g[i]){
            os<<i<<"->"<<e.to<<"("<<e.cost<<") ";
        }
        os<<endl;
    }
    return os;
}




template<typename T>
inline vector<T> vmake(size_t n,T x){
	return vector<T>(n,x);
}



template<typename... Args>
auto vmake(size_t n,Args... args){
	auto v=vmake(args...);
	return vector<decltype(v)>(n,move(v));
}



template<typename T, typename U>
inline ostream &operator<<(ostream &os,const pair<T,U> &p) {
	os<<p.first<<" "<<p.second;
	return os;
}
 


template<typename T, typename U>
inline istream &operator>>(istream &is,pair<T,U> &p) {
	is>>p.first>>p.second;
	return is;
}
 


template<typename T>
inline void vsort(vector<T> &v){
    sort(v.begin(),v.end());
}
 


template<typename T>
inline void rvsort(vector<T> &v){
	sort(v.rbegin(),v.rend());
}



inline int popcount(int x){
	return __builtin_popcount(x);
}


inline int popcount(ll x){
	return __builtin_popcountll(x);
}
template<typename T>
inline void Compress(vector<T> &C){
    sort(C.begin(),C.end());
    C.erase(unique(C.begin(),C.end()),C.end());
}
template<typename T>
inline int lower_idx(const vector<T> &C,T value){
    return lower_bound(C.begin(),C.end(),value)-C.begin();
}
template<typename T>
inline int upper_idx(const vector<T> &C,T value){
    return upper_bound(C.begin(),C.end(),value)-C.begin();
}


template<typename T>
inline void rotate90(vector<vector<T>> &C){
    vector<vector<T>> D(C[0].size(),vector<T>(C.size()));
    for(int h=0;h<C.size();h++){
        for(int w=0;w<C[h].size();w++){
            D[w][C.size()-1-h]=C[h][w];
        }
    }
    C=D;
}




Graph ComplementGraph(const Graph &g){
    size_t sz=g.size();
    bool used[sz][sz];
    fill(used[0],used[sz],false);
    for(size_t i=0;i<sz;i++){
        for(int to:g[i]){
            used[i][to]=true;
        }
    }
    Graph ret(sz);
    for(size_t i=0;i<sz;i++){
        for(size_t j=0;j<sz;j++){
            if(used[i][j]) continue;
            if(i==j) continue;
            ret[i].push_back(j);
        }
    }
    return ret;
}




pair<vector<Graph>,vector<pair<int,int>>> id1(const Graph &g){
    vector<pair<int,int>> id(g.size(),pair<int,int>(-1,-1));
    vector<Graph> ret;
    vector<int> now;
    for(size_t i=0;i<g.size();i++){
        if(id[i].first!=-1) continue;
        id[i].first=ret.size();
        id[i].second=0;
        now.push_back(i);
        for(size_t j=0;j<now.size();j++){
            for(int to:g[now[j]]){
                if(id[to].first==-1){
                    id[to].first=ret.size();
                    id[to].second=now.size();
                    now.push_back(to);
                }
            }
        }
        Graph r(now.size());
        for(size_t j=0;j<now.size();j++){
            r[j]=g[now[j]];
            for(int &to:r[j]){
                to=id[to].second;
            }
        }
        ret.push_back(r);
        now.clear();
    }
    return make_pair(ret,id);
}


bool OutGrid(ll h,ll w,ll H,ll W){
    return (h>=H or w>=W or h<0 or w<0);
}

void NO(){
    cout<<"NO"<<"\n";
}
void YES(){
    cout<<"YES"<<"\n";
}
void No(){
    cout<<"No"<<"\n";
}
void Yes(){
    cout<<"Yes"<<"\n";
}
namespace overflow{
    template<typename T>
    T max(){
        return numeric_limits<T>::max();
    }
    template<typename T>
    T ADD(T a,T b){
        T res;
        return __builtin_add_overflow(a,b,&res)?max<T>():res;
    }
    template<typename T>
    T MUL(T a,T b){
        T res;
        return __builtin_mul_overflow(a,b,&res)?max<T>():res;
    }
};
using namespace overflow;
struct ModInt{
    using u64=uint_fast64_t;
    u64 a;
    constexpr ModInt() :a(0){}
    constexpr ModInt(ll x) :a((x>=0)?(x%MOD):(x%MOD+MOD) ) {}

    inline constexpr ModInt operator+(const ModInt rhs)const noexcept{
        return ModInt(*this)+=rhs;
    }
    inline constexpr ModInt operator-(const ModInt rhs)const noexcept{
        return ModInt(*this)-=rhs;
    }
    inline constexpr ModInt operator*(const ModInt rhs)const noexcept{
        return ModInt(*this)*=rhs;
    }
    inline constexpr ModInt operator/(const ModInt rhs)const noexcept{
        return ModInt(*this)/=rhs;
    }
    inline constexpr ModInt operator+(const ll rhs) const noexcept{
        return ModInt(*this)+=ModInt(rhs);
    }
    inline constexpr ModInt operator-(const ll rhs)const noexcept{
        return ModInt(*this)-=ModInt(rhs);
    }
    inline constexpr ModInt operator*(const ll rhs)const noexcept{
        return ModInt(*this)*=ModInt(rhs);
    }
    inline constexpr ModInt operator/(const ll rhs)const noexcept{
        return ModInt(*this)/=ModInt(rhs);
    }

    inline constexpr ModInt &operator+=(const ModInt rhs)noexcept{
        a+=rhs.a;
        if(a>=MOD) a-=MOD;
        return *this;
    }
    inline constexpr ModInt &operator-=(const ModInt rhs)noexcept{
        if(rhs.a>a) a+=MOD;
        a-=rhs.a;
        return *this;
    }
    inline constexpr ModInt &operator*=(const ModInt rhs)noexcept{
        a=(a*rhs.a)%MOD;
        return *this;
    }
    inline constexpr ModInt &operator/=(ModInt rhs)noexcept{
        a=(a*rhs.inverse().a)%MOD;
        return *this;
    }
    inline constexpr ModInt &operator+=(const ll rhs)noexcept{
        return *this+=ModInt(rhs);
    }
    inline constexpr ModInt &operator-=(const ll rhs)noexcept{
        return *this-=ModInt(rhs);
    }
    inline constexpr ModInt &operator*=(const ll rhs)noexcept{
        return *this*=ModInt(rhs);
    }
    inline constexpr ModInt &operator/=(const ll rhs)noexcept{
        return *this/=ModInt(rhs);
    }

    inline constexpr ModInt operator=(const ll x)noexcept{
        a=(x>=0)?(x%MOD):(x%MOD+MOD);
        return *this;
    }

    inline constexpr bool operator==(const ModInt p)const noexcept{
        return a==p.a;
    }

    inline constexpr bool operator!=(const ModInt p)const noexcept{
        return a!=p.a;
    }

    inline constexpr ModInt pow(ll N) const noexcept{
        ModInt ans(1LL),p(a);
        while(N>0){
            if(bitUP(N,0)){
                ans*=p;
            }
            p*=p;
            N>>=1;
        }
        return ans;
    }
    inline constexpr ModInt inverse() const noexcept{
        return pow(MOD-2);
    }

};
inline constexpr ModInt operator+(const ll &a,const ModInt &b)noexcept{
    return ModInt(a)+=b;
}
inline constexpr ModInt operator-(const ll &a,const ModInt &b)noexcept{
    return ModInt(a)-=b;
}
inline constexpr ModInt operator*(const ll &a,const ModInt &b)noexcept{
    return ModInt(a)*=b;
}
inline constexpr ModInt operator/(const ll &a,const ModInt &b)noexcept{
    return ModInt(a)/=b;
}


inline ostream &operator<<(ostream &os,const ModInt &p) {
    return os<<p.a;
}



inline istream &operator>>(istream &is,ModInt &p) {
    ll t;
    is>>t;
    p=t;
    return is;
}

struct id0{
    vector<ModInt> fac,finv,inv; 

    int sz;
    id0(int n=10) :sz(1){
        if(n<=0) n=10;
        init(n);
    }
    inline void init(int n){
        fac.resize(n+1,1);
        finv.resize(n+1,1);
        inv.resize(n+1,1);
        for(int i=sz+1;i<=n;i++){
            fac[i]=fac[i-1]*i;
            inv[i]=MOD-inv[MOD%i]*(MOD/i);
            finv[i]=finv[i-1]*inv[i];
        }
        sz=n;
    }
    

    inline ModInt com(int n,int k){
        if(n<k) return ModInt(0);
        if(n<0 || k<0) return ModInt(0);
        if(n>sz) init(n);
        return fac[n]*finv[k]*finv[n-k];
    }
    

    inline ModInt rcom(ll n,int k){
        if(n<0 || k<0 || n<k) return ModInt(0);
        if(k>sz) init(k);
        ModInt ret(1);
        for(int i=0;i<k;i++){
            ret*=n-i;
        }
        ret*=finv[k];
        return ret;
    }

    

    

    inline ModInt h(int n,int k){
        return com(n+k-1,k);
    }
};
vector<int> Subset(int S,bool zero=false,bool full=false){
    vector<int> ret;
    int now=(S-1)&S;
    if(full and S){
        ret.push_back(S);
    }
    do{
        ret.push_back(now);
        now=(now-1)&S;
    }while(now!=0);
    if(zero){
        ret.push_back(0);
    }
    return ret;
}

template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  Dinic(int V,flow_t INF) : INF(INF), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

struct LCA{
    Graph g;
    vector<int> sz,head,par,in,dep;
    LCA(Graph &g):g(g),sz(g.size(),1),head(g.size()),par(g.size()),in(g.size()),dep(g.size()){}

    void dfs_sz(int idx,int p,int d){
        par[idx]=p;
        dep[idx]=d;
        if(g[idx].size() && g[idx][0]==p) swap(g[idx][0],g[idx].back());
        for(int &next:g[idx]){
            if(next==p) continue;
            dfs_sz(next,idx,d+1);
            sz[idx]+=sz[next];
            if(sz[g[idx][0]]<sz[next]) swap(g[idx][0],next);
        }
    }

    void dfs_hld(int idx,int p,int &times){
        in[idx]=times++;
        for(int next:g[idx]){
            if(next==p) continue;
            head[next]=(next==g[idx][0] ? head[idx]:next);
            dfs_hld(next,idx,times);
        }
    }
    

    void build(int root){
        dfs_sz(root,-1,1);
        int times=0;
        head[root]=root;
        dfs_hld(root,-1,times);
    }

    int lca(int u,int v){
        while(true){
            if(in[u]>in[v]) swap(u,v); 

            if(head[u]==head[v]) return u;
            v=par[head[v]];
        }
    }
    

    int dis(int u,int v){
        int p=lca(u,v);
        return dep[u]+dep[v]-dep[p]*2;

    }
};
Graph g;

void solve(){
    int N;
    cin>>N;
    g.resize(N);
    CinGraph(N-1,g);
    vector<LCA> lca;
    vector<ModInt> pow2(2*N+1);
    id0 B;
    pow2[0]=1;
    for(int i=1;i<=2*N;i++){
        pow2[i]=pow2[i-1]/2;
    }
    auto dp=vmake(N+1,N+1,ModInt());
    dp[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int d=0;d<j;d++){
                dp[i][j]+=pow2[i+d]*B.com(i-1+d,i-1);
            }
        }
    }
    for(int i=0;i<N;i++){
        lca.emplace_back(g);
        lca[i].build(i);
    }
    ModInt ans;
    ModInt one=ModInt(1)/N;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            

            for(int k=0;k<N;k++){
                int par=lca[k].lca(i,j);
                if(par==i){
                    ans+=one;
                }else if(par==j){
                    continue;
                }else{
                    int di=lca[k].dis(i,par);
                    int dj=lca[k].dis(j,par);
                    ans+=one*dp[di][dj];
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    bin101();
    int T=1;
    

    while(T--) solve();
}

