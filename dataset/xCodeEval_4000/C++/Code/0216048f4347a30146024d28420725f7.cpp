#include<bits/stdc++.h>


#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define per(i,j,n) for(int i=(int)(j);(int)(n)<=i;i--)
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(ll)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(ll)(key)))
#define pb emplace_back
#define mp std::make_pair




using std::endl;
using std::cin;
using std::cout;
using ll=long long;
using std::vector;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=std::pair<ll,ll>;


constexpr ll MOD=1e9+7;








constexpr ll MAX=3e6;
constexpr ll inf=(1ll<<60);
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template<typename T>
struct Segment_tree{
    ll N;
    T mem;
    vector<T> node;
    Segment_tree(vector<T> &X,T m):mem(m){
        ll sz=X.size();
        N=1;
        while(N<sz) N*=2;
        node.resize(2*N-1,mem);
        rep(i,0,sz) node[N-1+i]=X[i];
        per(i,N-2,0){
            node[i]=Compare(node[i*2+1],node[i*2+2]);
        }
    }
    T Compare(T &A,T &B){
        return std::min(A,B);
    }
    void update(ll X,T val){
        X+=N-1;
        node[X]=val;
        while(X>0){
            X=(X-1)/2;
            node[X]=Compare(node[X*2+1],node[X*2+2]);
        }
    }
    T Query(ll a,ll b,ll now=0,ll l=0,ll r=-1){ 

        if(r<0) r=N;
        if(r<=a||b<=l) return mem;
        if(a<=l&&r<=b) return node[now];
        auto vl=Query(a,b,now*2+1,l,(l+r)/2),vr=Query(a,b,now*2+2,(l+r)/2,r);
        return Compare(vl,vr);
    }
    ll lower_bound(ll left,ll right,T val,ll now=0,ll l=0,ll r=-1){
        if(r<0) r=N;
        if(node[now]<val||l>=right||left>=r) return r;
        else if(now>=N-1) return l;
        ll vl=lower_bound(left,right,val,now*2+1,l,(l+r)/2);
        if(vl==(l+r)/2) return lower_bound(left,right,val,now*2+2,(l+r)/2,r);
        return vl;
    }
};
template<typename T>
struct lazy_Segment_tree{
    int N;
    vector<T> node,lazy;
    T INF;
    vector<bool> flag;
    lazy_Segment_tree(vector<T> X,T Y):INF(Y){
        N=1;
        while(X.size()>N) N*=2;
        node.resize(2*N-1,Y);
        lazy.resize(2*N-1);
        flag.resize(2*N-1);
        rep(i,0,X.size()) node[i+N-1]=X[i];
        per(i,N-2,0) node[i]=compare(node[i*2+1],node[i*2+2]);
    }
    T compare(T X,T Y){
        return std::max(X,Y);
    }
    T plus(T X,int l,int r){
        return X;
    }
    void eval(int now,int l,int r){
        if(flag[now]){
            if(r-l>1){
                flag[now*2+1]=flag[now*2+2]=1;
                lazy[now*2+1]=lazy[now*2+2]=lazy[now];
            }
            node[now]=lazy[now];
            flag[now]=0;
        }
    }
    void update(int a,int b,T add,int now=0,int l=0,int r=-1){
        if(r<0) r=N;
        eval(now,l,r);
        if(b<=l||r<=a) return;
        if(a<=l&&r<=b){
            lazy[now]=add;
            flag[now]=1;
            eval(now,l,r);
        }
        else{
            update(a,b,add,now*2+1,l,(r+l)/2);
            update(a,b,add,now*2+2,(r+l)/2,r);
            node[now]=compare(node[now*2+1],node[now*2+2]);
        }
    }
    T Query(int a,int b,int now=0,int l=0,int r=-1){
        if(r<0) r=N;
        eval(now,l,r);
        if(b<=l||r<=a) return INF;
        if(a<=l&&r<=b) return node[now];
        return compare(Query(a,b,now*2+1,l,(r+l)/2),Query(a,b,now*2+2,(r+l)/2,r));
    }
    ll lower_bound(ll left,ll right,T val,ll now=0,ll l=0,ll r=-1){
        eval(now,l,r);
        if(r<0) r=N;
        if(node[now]<val||l>=right||left>=r) return r;
        else if(now>=N-1) return l;
        ll vl=lower_bound(left,right,val,now*2+1,l,(l+r)/2);
        if(vl==(l+r)/2) return lower_bound(left,right,val,now*2+2,(l+r)/2,r);
        return vl;
    }
};
struct Binary_indexed_tree{
    int N;
    vi bit;
    Binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    void add(int x,ll a){
        x++;
        for(x;x<=N;x+=(x&-x)) bit[x]+=a;
    }
    ll sum(int x){
        x++;
        ll ret=0;
        for(x;x>0;x-=(x&-x)) ret+=bit[x];
        return ret;
    }
    ll lower_bound(ll X){
        if(sum(N)<X) return -1;
        ll ret=0,memo=1,sum=0;
        while(memo*2<=N) memo*=2;
        while(memo>0){
            if(memo+ret<=N&&sum+bit[memo+ret]<X){
                sum+=bit[memo+ret];
                ret+=memo;
            }
            memo/=2;
        }
        return ret;
    }
};
struct Union_Find{
    ll N;
    vi par;
    vi siz;
    Union_Find(int n):N(n){
        par.resize(N);
        siz.resize(N,1);
        rep(i,0,N) par[i]=i;
    }
    ll root(ll X){
        if(par[X]==X) return X;
        return par[X]=root(par[X]);
    }
    bool same(ll X,ll Y){
        return root(X)==root(Y);
    }
    void unite(ll X,ll Y){
        X=root(X);
        Y=root(Y);
        if(X==Y) return;
        if(siz[Y]<siz[X]) std::swap(X,Y);
        par[X]=Y;
        siz[Y]+=siz[X];
        siz[X]=0;
    }
    ll size(ll X){
        return siz[root(X)];
    }
};
struct Strongly_Connected_Components{
    ll N,M;
    vii edge,ver;
    vi ind;
    Strongly_Connected_Components(vii e){
        ll n=e.size();
        ll m=0;
        vii revedge(n);
        ind.resize(n);
        rep(i,0,n){
            m+=e[i].size();
            for(auto p:e[i]) revedge[p].pb(i);
        }
        vi num(n,-1),po(n);
        vector<bool> seen(n);
        ll cnt=0;
        rep(i,0,n){
            if(num[i]==-1){
                dfs(i,e,num,cnt);
            }
        }
        rep(i,0,n) po[num[i]]=i;
        per(i,n-1,0){
            ll X=po[i];
            if(!seen[X]){
                std::queue<ll> que;
                vi v;
                que.push(X);
                seen[X]=1;
                while(!que.empty()){
                    ll now=que.front(); que.pop();
                    v.pb(now);
                    ind[now]=ver.size();
                    for(auto p:revedge[now]){
                        if(!seen[p]){
                            seen[p]=1;
                            que.push(p);
                        }
                    }
                }
                ver.pb(v);
            }
        }
        N=ver.size();
        M=0;
        edge.resize(N);
        rep(i,0,n){
            for(auto p:e[i]){
                if(ind[i]==ind[p]) continue;
                M++;
                edge[ind[i]].pb(ind[p]);
            }
        }
    }
    void dfs(ll now,vii &e,vi &num,ll &cnt){
        num[now]=0;
        for(auto next:e[now]){
            if(num[next]==-1){
                dfs(next,e,num,cnt);
            }
        }
        num[now]=cnt++;
    }
};
struct Directed_Gragh{
    ll N,M;
    vii edge;
    Directed_Gragh(vii e):edge(e){
        N=edge.size();
        rep(i,0,N) M+=edge[i].size();
    }
    vi sort(){
        vi ret;
        vi cnt(N);
        rep(i,0,N){
            for(auto p:edge[i]) cnt[p]++;
        }
        std::queue<ll> que;
        rep(i,0,N){
            if(cnt[i]==0) que.push(i);
        }
        while(!que.empty()){
            ll now=que.front(); que.pop();
            ret.pb(now);
            for(auto next:edge[now]){
                cnt[next]--;
                if(cnt[next]==0) que.push(next);
            }
        }
        return ret;
    }
};
struct Tree{
    int N;
    vii dp;
    vi par;
    vi dist;
    vi subtree;
    vii edge;
    Tree(vii E):edge(E){
        N=edge.size();
        dp.resize(N);
        par.resize(N);
        dist.resize(N,-1);
        for(int i=0;i<N;i++) dp[i].resize(20);
        dist[0]=dp[0][0]=0;
        std::queue<int> que;
        que.push(0);
        while(!que.empty()){
            int now=que.front(); que.pop();
            for(int i=0;i<edge[now].size();i++){
                int next=edge[now][i];
                if(dist[next]==-1){
                    dist[next]=dist[now]+1;
                    que.push(next);
                    par[next]=now;
                    dp[next][0]=now;
                }
            }
        }
        for(int i=1;i<20;i++){
            for(int j=0;j<N;j++) dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    int LCA(int X,int Y){
        if(dist[X]<dist[Y]) std::swap(X,Y);
        {
            int Z=dist[X]-dist[Y];
            int i=0;
            while(Z){
                if(Z&1) X=dp[X][i];
                i++;
                Z>>=1;
            }
        }
        if(X==Y) return X;
        for(int i=19;i>=0;i--){
            if(dp[X][i]!=dp[Y][i]){
                X=dp[X][i];
                Y=dp[Y][i];
            }
        }
        return dp[X][0];
    }
    void Subtree(){
        subtree.resize(N,-1);
        dfs(0);
    }
    void dfs(ll now){
        subtree[now]=1;
        for(auto next:edge[now]){
            if(subtree[next]==-1){
                dfs(next);
                subtree[now]+=subtree[next];
            }
        }
    }
};
struct max_flow{
    struct Edge{
        int to,cap,rev;
    };
    int N;
    vector<vector<Edge>> edge;
    vector<int> dist,itr;
    max_flow(vii e,vii w){
        N=e.size();
        edge.resize(N);
        rep(i,0,N){
            rep(j,0,e[i].size()){
                edge[i].pb((Edge){(int)e[i][j],(int)w[i][j],(int)edge[e[i][j]].size()});
                edge[e[i][j]].pb((Edge){i,0,(int)edge[i].size()-1});
            }
        }
    }
    void add_edge(int from,int to,int cap){
        edge[from].pb((Edge){to,cap,(int)edge[to].size()});
        edge[to].pb((Edge){from,0,(int)edge[from].size()-1});
    }
    void bfs(int s){
        dist.assign(N,-1);
        std::queue<int> que;
        dist[s]=0;
        que.push(s);
        while(!que.empty()){
            int now=que.front(); que.pop();
            for(auto p:edge[now]){
                int next=p.to;
                if(p.cap>0&&dist[next]<0){
                    dist[next]=dist[now]+1;
                    que.push(next);
                }
            }
        }
    }
    int dfs(int now,int t,int f){
        if(now==t) return f;
        for(;itr[now]<edge[now].size();itr[now]++){
            Edge& p=edge[now][itr[now]];
            if(p.cap>0&&dist[now]<dist[p.to]){
                int mem=dfs(p.to,t,std::min(f,p.cap));
                if(mem>0){
                    p.cap-=mem;
                    edge[p.to][p.rev].cap+=mem;
                    return mem;
                }
            }
        }
        return 0;
    }
    int Query(int s,int t){
        int ret=0;
        while(1){
            bfs(s);
            if(dist[t]<0) break;
            itr.assign(N,0);
            while(1){
                int mem=dfs(s,t,(1<<30));
                if(mem<=0) break;
                ret+=mem;
            }
        }
        return ret;
    }
};
struct min_cost_flow{
    struct Edge{
        int to,cap,rev;
        ll cost;
    };
    int N;
    vector<vector<Edge>> edge;
    vector<ll> dist,h;
    void add_edge(int from,int to,int cap,ll cost){
        edge[from].pb((Edge){to,cap,(int)edge[to].size(),cost});
        edge[to].pb((Edge){from,0,(int)edge[from].size()-1,-cost});
    }
    min_cost_flow(vii e,vii m,vii w){
        N=e.size();
        edge.resize(N);
        rep(i,0,N){
            rep(j,0,e[i].size()){
                add_edge(i,e[i][j],m[i][j],w[i][j]);
            }
        }
    }
    void potential(){
        h.assign(N,0);
        vector<vector<int>> edge2(N);
        vii weight(N);
        vector<int> cnt(N);
        rep(i,0,N){
            for(auto e:edge[i]){
                if(e.cap>0&&e.cost<0){
                    edge2[i].pb(e.to);
                    weight[i].pb(-e.cost);
                    cnt[e.to]++;
                }
            }
        }
        std::queue<ll> que;
        rep(i,0,N){
            if(cnt[i]==0) que.push(i);
        }
        vector<int> ver;
        while(!que.empty()){
            int now=que.front(); que.pop();
            ver.pb(now);
            for(auto next:edge2[now]){
                cnt[next]--;
                if(cnt[next]==0) que.push(next);
            }
        }
        per(i,N-1,0){
            rep(j,0,edge2[ver[i]].size()){
                int next=edge2[ver[i]][j];
                h[ver[i]]=std::max(h[ver[i]],h[next]+weight[ver[i]][j]);
            }
        }
    }
    ll Query(int s,int t,int f){
        ll ret=0;
        potential();
        while(f){
            vi dist(N,inf);
            vector<int> memv(N),meme(N);
            dist[s]=0;
            prique<std::pair<ll,int>> que;
            que.push(mp(0,s));
            while(!que.empty()){
                auto now=que.top().second; 
                if(dist[now]<que.top().first){
                    que.pop();
                    continue;
                }
                que.pop();
                rep(i,0,edge[now].size()){
                    auto e=edge[now][i];
                    auto next=e.to;
                    if(e.cap>0&&dist[next]>dist[now]+h[now]-h[next]+e.cost){
                        dist[next]=dist[now]+h[now]-h[next]+e.cost;
                        memv[next]=now;
                        meme[next]=i;
                        que.push(mp(dist[next],next));
                    }
                }
            }
            if(dist[t]==inf) return -1;
            int now=t,max=f;
            while(now!=s){
                auto& e=edge[memv[now]][meme[now]];
                max=std::min(max,e.cap);
                now=memv[now];
            }
            f-=max;
            now=t;
            while(now!=s){
                auto& e=edge[memv[now]][meme[now]];
                e.cap-=max;
                auto& e2=edge[e.to][e.rev];
                e2.cap+=max;
                now=memv[now];
            }
            rep(i,0,N) h[i]+=dist[i];
            ret+=h[t]*max;
        }
        return ret;
    }
};
template<typename T>
struct tancomp{
    int place(std::pair<T,T> p){
        if(p.first<=0&&p.second<0) return 0;
        if(p.first>0&&p.second<=0) return 1;
        if(p.first==0&&p.second==0) return 2;
        if(p.first>=0&&p.second>0) return 3;
        return 4;
    }
    bool operator()(const std::pair<T,T> &l,const std::pair<T,T> &r){
        if(place(l)!=place(r)) return place(l)<place(r);
        

        return l.second*r.first<l.first*r.second;
    }
};
template<typename T>
vector<std::pair<T,T>> Declination_sort(ll N,vector<T> X,vector<T> Y){
    vector<std::pair<T,T>> ret(N);
    rep(i,0,N){
        ret[i]=(mp(X[i],Y[i]));
    }
    sort(ALL(ret),tancomp<T>());
    return ret;
}
vector<pii> Convex_Hull(vector<pii> X){
    int N=X.size();
    sort(ALL(X));
    if(N<=2) return X;
    return X;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
vi fac,finv,inv;
void COMinit() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n,ll r){
    if(n<r||n<0||r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}
void comp(vi &A){
    std::map<ll,ll> memo;
    rep(i,0,A.size()) memo[A[i]]=0;
    ll cnt=0;
    for(auto &p:memo) p.second=cnt++;
    rep(i,0,A.size()) A[i]=memo[A[i]];
}
void dec(std::map<ll,ll> &mem,ll X){
    mem[X]--;
    if(mem[X]==0) mem.erase(X);
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::random_device rnd;
    std::mt19937 mt(rnd());
    ll N; cin>>N;
    vi A(N);
    rep(i,0,N) cin>>A[i];
    ll ans=inf;
    vii B;
    B.pb(A);
    vi sum;
    sum.pb(0);
    per(i,30,0){
        vii C;
        vi D;
        rep(j,0,B.size()){
            vii mem(2);
            for(auto q:B[j]){
                int X=q&(1<<i);
                X>>=i;
                mem[X%2].pb(q);
            }
            if(mem[0].empty()||mem[1].empty()){
                C.pb(B[j]);
                D.pb(sum[j]);
                continue;
            }
            C.pb(mem[0]);
            D.pb(sum[j]+mem[1].size()-1);
            C.pb(mem[1]);
            D.pb(sum[j]+mem[0].size()-1);
        }
        sum=D;
        B=C;
    }
    for(auto p:sum) ans=std::min(ans,p);
    cout<<ans<<endl;
}
