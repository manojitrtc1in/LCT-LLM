




















using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=std::pair<ll,ll>;




constexpr ll MOD=998244353;






constexpr ll MAX=3e6;
constexpr ll inf=(1ll<<62);
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
struct id0{
    int N;
    vector<T> node,lazy;
    T INF;
    vector<bool> flag;
    id0(vector<T> X,T Y):INF(Y){
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
struct id2{
    int N;
    vi bit;
    id2(int n):N(n){
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
struct id4{
    ll N,M;
    vii edge,ver;
    vi ind;
    id4(vii e){
        ll n=e.size();
        ll m=0;
        vii id1(n);
        ind.resize(n);
        rep(i,0,n){
            m+=e[i].size();
            for(auto p:e[i]) id1[p].pb(i);
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
                    for(auto p:id1[now]){
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
struct lowlink{
    ll N;
    vii edge;
    vi ord,low,aps;
    vector<bool> used;
    vector<pii> bridges;
    lowlink(vii e):edge(e){
        N=edge.size();
        used.resize(N);
        ord.resize(N);
        low.resize(N);
        ll cnt=0;
        rep(i,0,N){
            if(!used[i]) dfs(i,cnt,-1);
        }
    }
    void dfs(ll now,ll &cnt,ll from){
        used[now]=1;
        ord[now]=cnt++;
        low[now]=ord[now];
        bool flag=0;
        for(auto next:edge[now]){
            if(!used[now]){
                dfs(next,cnt,now);
                low[now]=std::min(low[now],low[next]);
                if(from!=-1&&ord[now]<=low[next]) flag=1;
                if(ord[now]<low[next]) bridges.pb(mp(now,next));
            }
            else if(next!=from) low[now]=std::min(low[now],ord[next]);
        }
        if(from==-1&&edge[now].size()>=2) flag=1;
        if(flag) aps.pb(now);
    }
};
struct id5{
    ll N,M;
    vii edge;
    id5(vii e):edge(e){
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
        for(int i=0;i<N;i++) dp[i].resize(30);
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
        for(int i=1;i<30;i++){
            for(int j=0;j<N;j++) dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    int LCA(int X,int Y){
        if(dist[X]<dist[Y]) std::swap(X,Y);
        {
            int Z=dist[X]-dist[Y];
            for(int i=0;i<30;i++){
                if(Z&(1<<i)){
                    X=dp[X][i];
                }
            }
        }
        if(X==Y) return X;
        for(int i=29;i>=0;i--){
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
vector<std::pair<T,T>> id3(ll N,vector<T> X,vector<T> Y){
    vector<std::pair<T,T>> ret(N);
    rep(i,0,N){
        ret[i]=(mp(X[i],Y[i]));
    }
    sort(ALL(ret),tancomp<T>());
    return ret;
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
    ll N,M; cin>>N>>M;
    vii edge(N),id1(N);
    rep(i,0,M){
        ll X,Y; cin>>X>>Y;
        edge[X-1].pb(Y-1);
        id1[Y-1].pb(X-1);
    }
    ll K=60;
    {
        vector<vector<pii>> dist(N,vector<pii>(2,mp(inf,inf)));
        dist[0][0]=mp(0,0);
        prique<std::pair<pii,pii>> que;
        que.push(mp(mp(0,0),mp(0,0)));
        while(!que.empty()){
            auto now=que.top().second;
            que.pop();
            for(auto next:edge[now.first]){
                auto p=dist[now.first][now.second];
                p.second++;
                if(p.first%2) break;
                if(p<dist[next][now.second]){
                    dist[next][now.second]=p;
                    que.push(mp(p,mp(next,now.second)));
                }
            }
            for(auto next:id1[now.first]){
                auto p=dist[now.first][now.second];
                p.second++;
                if(!(p.first%2)) break;
                if(p<dist[next][now.second]){
                    dist[next][now.second]=p;
                    que.push(mp(p,mp(next,now.second)));
                }
            }
            auto p=dist[now.first][now.second];
            p.first++;
            if(p<dist[now.first][1-now.second]){
                dist[now.first][1-now.second]=p;
                que.push(mp(p,mp(now.first,1-now.second)));
            }
        }
        auto p=std::min(dist[N-1][0],dist[N-1][1]);
        if(p.first>K){
            ll ans=p.first;
            ans=modpow(2,ans,MOD)-1+p.second;
            ans%=MOD;
            if(ans<0) ans+=MOD;
            cout<<ans<<endl;
            return 0;
        }
    }
    vii dist(N,vi(K+1,inf));
    prique<std::pair<ll,pii>> que;
    dist[0][0]=0;
    que.push(mp(0,mp(0,0)));
    while(!que.empty()){
        auto now=que.top().second;
        que.pop();
        for(auto next:edge[now.first]){
            auto p=now.second;
            ll sum=dist[now.first][p]+1;
            if(p%2) break;
            if(p<=K&&sum<dist[next][p]){
                dist[next][p]=sum;
                que.push(mp(sum,mp(next,p)));
            }
        }
        for(auto next:id1[now.first]){
            auto p=now.second;
            ll sum=dist[now.first][p]+1;
            if(!(p%2)) break;
            if(p<=K&&sum<dist[next][p]){
                dist[next][p]=sum;
                que.push(mp(sum,mp(next,p)));
            }
        }
        auto p=dist[now.first][now.second];
        if(now.second<K&&dist[now.first][now.second+1]>p){
            dist[now.first][now.second+1]=p;
            que.push(mp(p,mp(now.first,now.second+1)));
        }
    }
    ll ans=inf;
    REP(i,0,K) ans=std::min(ans,dist[N-1][i]+(1ll<<i)-1);
    ans%=MOD;
    cout<<ans<<endl;
}
