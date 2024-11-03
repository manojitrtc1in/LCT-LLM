















using std::endl;
using std::cin;
using std::cout;
using ll = long long;
using lint = __int128;
using std::vector;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi = vector<ll>;
using vii = vector<vi>;
using pii = std::pair<ll, ll>;
using vs = vector<int>;
using vss = vector<vs>;
using pss = std::pair<int, int>;
using vl = vector<lint>;
using vll = vector<vl>;
using pll = std::pair<lint, lint>;




constexpr ll MOD = 998244353, root = 3;










constexpr ll MAX = 1e6+10;
constexpr ll inf = (1ll << 60);
constexpr lint linf = lint(inf) * inf;



void lout(lint N, string add){
    string S;
    if(N < 0){
        S += '-';
        N = -N;
    }
    string T;
    if(N == 0) T += '0';
    while(N){
        T += N % 10 + '0';
        N /= 10;
    }
    reverse(ALL(T));
    S += T;
    cout << S << add;
}



lint lin(){
    string S; cin >> S;
    bool flag = 0;
    if(S[0] == '-') flag = 1;
    lint ret = 0;
    rep(i, flag, S.size()) ret = ret * 10 + S[i] - '0';
    if(flag) ret *= -1;
    return ret;
}



template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};



ll modpow(ll X, ll Y, ll mod){
    ll ret = 1;
    while(Y){
        if(Y & 1){
            ret *= X;
            ret %= mod;
        }
        X *= X;
        X %= mod;
        Y >>= 1;
    }
    return ret % mod;
}



template<typename T>
void id9(ll a, ll b, T &x, T &y){
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    id9(b, a%b, y, x);
    
    y -= a / b * x;
}



template<typename T>
bool id5(ll a, ll b, ll c, T &x, T &y){
    ll d = std::__gcd(a, b);
    if(c % d) return false;
    id9(a, b, x, y);
    ll e = a * b / d;
    x %= e;
    y %= e;
    x = (lint)x * (c/d) % e;
    y = (lint)y * (c/d) % e;
    return true;
}



template<typename T>
struct segment_tree{
    ll N;
    T INF;
    vector<T> node;
    segment_tree(vector<T> &X, T INF_):INF(INF_){
        N = 1;
        while(N < X.size()) N <<= 1;
        node.resize(2*N, INF);
        rep(i, 0, X.size()) node[N+i] = X[i];
        per(i, N-1, 0) node[i] = compare(node[i*2], node[i*2+1]);
    }
    T compare(T A, T B){
        return std::max(A, B);
    }
    

    

    bool is_lower(T A, T B){
        return A < B;
    }
    

    

    void update(ll index, T val, bool isAdd){
        index += N;
        if(isAdd) node[index] += val;
        else node[index] = val;
        while(index > 0){
            index >>= 1;
            node[index] = compare(node[index*2], node[index*2+1]);
        }
    }
    T calc(ll left, ll right){
        T ret = INF;
        left += N;
        right += N;
        while(left < right){
            if(left & 1) ret = compare(node[left++], ret);
            if(right & 1) ret = compare(node[--right], ret);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }
    

    ll min_left(ll left, T val, ll now = 1, ll l = 0, ll r = -1){
        if(r < 0) r = N;
        if(is_lower(node[now], val) || r<=left) return r;
        if(N <= now) return l;
        ll vl = min_left(left, val, now*2, l, (l+r)/2);
        if(vl == (l+r)/2) return min_left(left, val, now*2+1, (l+r)/2, r);
        return vl;
    }
    

    

    ll max_right(ll right, T val, ll now = 1, ll l = 0, ll r = -1){
        if(r < 0) r = N, right++;
        if(is_lower(node[now], val) || right<=l) return l-1;
        if(N <= now) return l;
        ll vr = max_right(right, val, now*2+1, (l+r)/2, r);
        if(vr == (l+r)/2-1) return max_right(right, val, now*2, l, (l+r)/2);
        return vr;
    }
};



template<typename T>
struct id11{
    int N, height;
    vector<T> node, lazy;
    T valINF, lazyINF;
    id11(vector<T> X, T id13, T id6) : valINF(id13), lazyINF(id6){
        N = 1, height = 0;
        while(N < X.size()) N <<= 1, height++;
        node.resize(2*N, valINF);
        lazy.resize(2*N, lazyINF);
        rep(i, 0, X.size()) node[i+N] = X[i];
        per(i, N-1, 0) node[i] = compare(node[i*2], node[i*2+1]);
    }
    void add(ll left, ll right, T val){
        ll l = left+N, r = right+N;
        ll L = l, R = r;
        per(i, height, 0){
            eval(l >> i);
            eval(r >> i);
        }
        while(l < r){
            if(l & 1){
                addition(lazy[l], val);
                l++;
            }
            if(r & 1){
                r--;
                addition(lazy[r], val);
            }
            l >>= 1;
            r >>= 1;
        }
        while(L){
            if(lazy[L]==lazyINF && L<N){
                eval(L*2);
                eval(L*2+1);
                node[L] = compare(node[L*2], node[L*2+1]);
            }
            if(lazy[R]==lazyINF && R<N){
                eval(R*2);
                eval(R*2+1);
                node[R] = compare(node[R*2], node[R*2+1]);
            }
            L >>= 1;
            R >>= 1;
        }
    }
    T calc(ll left, ll right){
        ll l = left+N, r = right+N;
        per(i, height, 0){
            eval(l >> i);
            eval(r >> i);
        }
        T ret = valINF;
        while(l < r){
            if(l & 1){
                eval(l);
                ret = compare(node[l], ret);
                l++;
            }
            if(r & 1){
                r--;
                eval(r);
                ret = compare(node[r], ret);
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
    

    ll min_left(ll left, T val, ll now = 1, ll l = 0, ll r = -1){
        if(r < 0) r = N;
        eval(now);
        if(is_lower(node[now], val) || r<=left) return r;
        if(N <= now) return l;
        ll vl = min_left(left, val, now*2, l, (l+r)/2);
        if(vl == (l+r)/2) return min_left(left, val, now*2+1, (l+r)/2, r);
        return vl;
    }
    

    

    ll max_right(ll right, T val, ll now = 1, ll l = 0, ll r = -1){
        if(r < 0) r = N, right++;
        eval(now);
        if(is_lower(node[now], val) || right<=l) return l-1;
        if(N <= now) return l;
        ll vr = max_right(right, val, now*2+1, (l+r)/2, r);
        if(vr == (l+r)/2-1) return max_right(right, val, now*2, l, (l+r)/2);
        return vr;
    }

    private:

    T compare(T A, T B){
        return std::max(A, B);
    }
    

    

    bool is_lower(T A, T B){
        return A < B;
    }
    void addition(T &A, T B){
        

        A += B;
        

    }
    void eval(int now){
        if(lazy[now] == lazyINF) return;
        if(now < N){
            addition(lazy[now*2], lazy[now]);
            addition(lazy[now*2+1], lazy[now]);
        }
        addition(node[now], lazy[now]);
        lazy[now] = lazyINF;
    }
};



struct union_find{
    ll N;
    vi par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        rep(i,0,N) par[i] = i;
    }
    ll root(ll X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(ll X, ll Y){
        return root(X) == root(Y);
    }
    void unite(ll X, ll Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
    ll size(ll X){
        return siz[root(X)];
    }
};



template<typename T>
struct id2{
    int N;
    vector<T> bit;
    id2(int n):N(n){
        bit.resize(N+1,0);
    }
    T addition(T a, T b){
        return a+b;
    }
    void add(int x,T a){
        x++;
        for(x; x<=N; x+=(x&-x)) bit[x] = addition(bit[x], a);
    }
    T sum(int x){
        x++;
        T ret=0;
        for(x; x>0; x-=(x&-x)) ret = addition(ret, bit[x]);
        return ret;
    }
    ll lower_bound(T X){
        if(sum(N)<X) return -1;
        ll ret=0, memo=1;
        T sum=0;
        while(memo*2 <= N) memo *= 2;
        while(0 < memo){
            if(memo+ret<=N && addition(sum, bit[memo+ret])<X){
                sum = addition(sum, bit[memo+ret]);
                ret+=memo;
            }
            memo/=2;
        }
        return ret;
    }
};



struct id3{
    ll N, M;
    vii edge;
    id3(vii e) : edge(e){
        N = edge.size();
        rep(i,0,N) M += edge[i].size();
    }
    vi sort(){
        vi ret, cnt(N);
        rep(i,0,N){
            for(auto p:edge[i]) cnt[p]++;
        }
        std::queue<ll> que;
        rep(i,0,N){
            if(cnt[i] == 0) que.push(i);
        }
        while(!que.empty()){
            ll now = que.front(); que.pop();
            ret.pb(now);
            for(auto next:edge[now]){
                cnt[next]--;
                if(cnt[next] == 0) que.push(next);
            }
        }
        return ret;
    }
    vii SCC(){
        vii id4(N), ver;
        vi ind(N);
        rep(i,0,N){
            for(auto p:edge[i]) id4[p].pb(i);
        }
        vi num(N, -1), po(N);
        vector<bool> seen(N);
        ll cnt = 0;
        rep(i,0,N){
            if(num[i] == -1){
                dfs(i, num, cnt);
            }
        }
        rep(i,0,N) po[num[i]] = i;
        per(i,N-1,0){
            ll X = po[i];
            if(!seen[X]){
                std::queue<ll> que;
                vi v;
                que.push(X);
                seen[X] = 1;
                while(!que.empty()){
                    ll now = que.front(); que.pop();
                    v.pb(now);
                    ind[now] = ver.size();
                    for(auto p:id4[now]){
                        if(!seen[p]){
                            seen[p] = 1;
                            que.push(p);
                        }
                    }
                }
                ver.pb(v);
            }
        }
        return ver;
    }
    void dfs(ll now, vi &num, ll &cnt){
        num[now] = 0;
        for(auto next:edge[now]){
            if(num[next] == -1){
                dfs(next, num, cnt);
            }
        }
        num[now] = cnt++;
    }
};



template<typename T>
struct id0{
    ll  N;
    T INF;
    vector<T> A;
    vi mem;
    vector<vector<T>> table;
    std::function<T (T, T)> compare;
    id0(vector<T> X, T INF_, std::function<T (T, T)> compare_) : A(X), INF(INF_), compare(compare_){
        N = A.size();
        mem.resize(N+1, -1);
        int height = 0;
        while((1<<height) <= N+1){
            mem[1<<height] = height;
            height++;
        }
        table.resize(N, vector<T>(height, INF));
        rep(i,0,N) table[i][0] = A[i];
        rep(j,1,height){
            rep(i,0,N){
                table[i][j] = compare(table[i][j-1], table[std::min(N-1, i+(1ll<<(j-1)))][j-1]);
            }
        }
        REP(i,1,N){
            mem[i] = std::max(mem[i-1], mem[i]);
        }
    }
    

    T calc(ll l, ll r){
        ll width = r-l;
        return compare(table[l][mem[width]], table[r-(1<<mem[width])][mem[width]]);
    }
};



struct tree{
    int N, root;
    vii dp;
    vi par;
    vi dist;
    vi subtree;
    vii edge;
    tree(vii E, ll root_) : edge(E), root(root_){
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



template<typename T>
struct max_flow{
    struct Edge{
        int to;
        T cap;
        int rev;
    };
    int N;
    vector<vector<Edge>> edge;
    vector<int> dist,itr;
    max_flow(vii e,vii w){
        N=e.size();
        edge.resize(N);
        rep(i,0,N){
            rep(j,0,e[i].size()){
                edge[i].pb((Edge){(int)e[i][j],(T)w[i][j],(int)edge[e[i][j]].size()});
                edge[e[i][j]].pb((Edge){i,0,(int)edge[i].size()-1});
            }
        }
    }
    void add_edge(int from,int to,T cap){
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
    T dfs(int now,int t,T f){
        if(now==t) return f;
        for(;itr[now]<edge[now].size();itr[now]++){
            Edge& p=edge[now][itr[now]];
            if(p.cap>0&&dist[now]<dist[p.to]){
                T mem=dfs(p.to,t,std::min(f,p.cap));
                if(mem>0){
                    p.cap-=mem;
                    edge[p.to][p.rev].cap+=mem;
                    return mem;
                }
            }
        }
        return 0;
    }
    T Query(int s,int t){
        T ret=0;
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



struct id12{
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
    id12(vii e,vii m,vii w){
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



struct Fast_Fourier_Transform{
    void dft(vector<std::complex<double>> &func,int inverse){
        int siz=func.size();
        if(siz==1) return;
        vector<std::complex<double>> left,right;
        rep(i,0,siz/2){
            left.pb(func[i*2]);
            right.pb(func[i*2+1]);
        }
        dft(left,inverse);
        dft(right,inverse);
        std::complex<double> now=1,zeta=std::polar(1.0,inverse*2.0*acos(-1)/siz);
        rep(i,0,siz){
            func[i]=left[i%(siz/2)]+now*right[i%(siz/2)];
            now*=zeta;
        }
    }
    template<typename T>
    vector<double> multiply(vector<T> f,vector<T> g){
        vector<std::complex<double>> nf,ng;
        int siz=1;
        while(siz<f.size()+g.size()) siz<<=1;
        nf.resize(siz);
        ng.resize(siz);
        rep(i,0,f.size()) nf[i]=f[i];
        rep(i,0,g.size()) ng[i]=g[i];
        dft(nf,1);
        dft(ng,1);
        rep(i,0,siz) nf[i]*=ng[i];
        dft(nf,-1);
        vector<double> ret(siz);
        rep(i,0,siz) ret[i]=nf[i].real()/siz;
        return ret;
    }
};



struct id8{
    vii mem;
    id8(void){
        mem.resize(25,vi(2));
        rep(i,0,25){
            mem[i][1]=modpow(root,MOD-1-(MOD-1)/(1<<i),MOD);
            mem[i][0]=modpow(root,(MOD-1)/(1<<i),MOD);
        }
    }
    void dft(vi &func,bool inverse,ll cnt){
        int siz=func.size();
        if(siz==1) return;
        vi left,right;
        rep(i,0,siz/2){
            left.pb(func[i*2]);
            right.pb(func[i*2+1]);
        }
        dft(left,inverse,cnt-1);
        dft(right,inverse,cnt-1);
        ll now=1;
        ll zeta=mem[cnt][inverse];
        rep(i,0,siz){
            func[i]=(left[i%(siz/2)]+now*right[i%(siz/2)])%MOD;
            now*=zeta;
            now%=MOD;
        }
    }
    vi multiply(vi f,vi g){
        ll cnt=0;
        vi nf,ng;
        int siz=1;
        while(siz<f.size()+g.size()){
            cnt++;
            siz<<=1;
        }
        nf.resize(siz);
        ng.resize(siz);
        rep(i,0,f.size()) nf[i]=f[i];
        rep(i,0,g.size()) ng[i]=g[i];
        dft(nf,0,cnt);
        dft(ng,0,cnt);
        rep(i,0,siz){
            nf[i]*=ng[i];
            nf[i]%=MOD;
        }
        dft(nf,1,cnt);
        vi ret(siz);
        ll div=modpow(siz,MOD-2,MOD);
        rep(i,0,siz) ret[i]=nf[i]*div%MOD;
        return ret;
    }
};



struct Trie{
    int let;
    char lower;
    vector<int> cnt;
    vector<vector<int>> next;
    Trie(int element,char low):let(element),lower(low){
        cnt.resize(1);
        next.pb(vector<int>(let,-1));
    }
    void insert(string S){
        int now=0;
        for(auto s:S){
            int X=s-lower;
            if(next[now][X]==-1){
                next[now][X]=cnt.size();
                cnt.pb(0);
                next.pb(vector<int>(lower,-1));
            }
            now=next[now][X];
        }
        cnt[now]++;
    }
    int get(string S){
        int now=0;
        for(auto s:S){
            int X=s-lower;
            if(next[now][X]==-1) return 0;
            now=next[now][X];
        }
        return cnt[now];
    }
};



template<typename T>
struct point{
    T x,y;
    void operator+=(const point &other){
        x += other.x;
        y += other.y;
    }
    void operator-=(const point &other){
        x -= other.x;
        y -= other.y;
    }
    bool operator<(const point &other){
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
    bool operator==(const point &other){
        return x==other.x && y==other.y;
    }
};



template<typename T>
struct tancomp{
    int place(point<T> p){
        if(p.x<=0&&p.y<0) return 0;
        if(p.x>0&&p.y<=0) return 1;
        if(p.x==0&&p.y==0) return 2;
        if(p.x>=0&&p.y>0) return 3;
        return 4;
    }
    bool operator()(const point<T> &l,const point<T> &r){
        if(place(l)!=place(r)) return place(l)<place(r);
        

        return l.y*r.x < l.x*r.y;
    }
};



vi id1(vi A,ll max_digit){
    int now=0;
    int N=A.size();
    per(i,max_digit,0){
        rep(j,now,N){
            if(A[j]&(1ll<<i)){
                std::swap(A[j],A[now]);
                break;
            }
        }
        if(now<N&&A[now]&(1ll<<i)){
            rep(j,0,N){
                if(j!=now&&A[j]&(1ll<<i)) A[j]^=A[now];
            }
            now++;
        }
    }
    vi bases;
    rep(i,0,now) bases.pb(A[i]);
    return bases;
}



template<typename T>
vi id10(vector<point<T>> A){
    ll N = A.size();
    vector<std::pair<point<T>,ll>> data(N);
    rep(i,0,N) data[i] = mp(A[i],i);
    sort(ALL(data),[](std::pair<point<T>,ll> l,std::pair<point<T>,ll> r){
        if(l.first == r.first) return l.second < r.second;
        return l.first < r.first;
    });
    vi ret;
    ret.pb(0);
    

    rep(i,1,data.size()){
        while(ret.size() > 1){
            ll n = ret.size();
            point<T> A = data[ret[n-2]].first;
            point<T> B = data[ret[n-1]].first;
            point<T> C = data[i].first;
            B -= A;
            C -= A;
            if(B.x*C.y-B.y*C.x < 0) ret.pop_back();
            else break;
        }
        ret.pb(i);
    }
    

    per(i,int(data.size())-2,0){
        while(ret.size() > 1){
            ll n = ret.size();
            point<T> A = data[ret[n-2]].first;
            point<T> B = data[ret[n-1]].first;
            point<T> C = data[i].first;
            B -= A;
            C -= A;
            if(B.x*C.y-B.y*C.x < 0) ret.pop_back();
            else break;
        }
        ret.pb(i);
    }
    ret.pop_back();
    for(auto &p:ret) p = data[p].second;
    return ret;
}



vi fac,finv,inv;
void id7() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, MAX){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
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
    std::cout.tie(nullptr);
    std::random_device rnd;
    std::mt19937 mt(rnd());
    ll N,M; cin >> N >> M;
    vector<std::map<ll,ll>> que(2);
    vii dp(N+1,vi(2,-1));
    rep(j,0,2) dp[0][j] = 0;
    vi K(N+1);
    REP(i,1,N){
        cin >> K[i];
        vi L(2),R(2);
        rep(j,0,2) cin >> L[j] >> R[j];
        rep(j,0,2){
            while(!que[j].empty()){
                auto p = *que[j].begin();
                if(p.first < L[1-j]) que[j].erase(p.first);
                else break;
            }
            while(!que[j].empty()){
                auto p = *que[j].rbegin();
                if(R[1-j] < p.first) que[j].erase(p.first);
                else break;
            }
            if(L[1-j]<=K[i-1] && K[i-1]<=R[1-j] && dp[i-1][1-j]!=-1){
                dp[i][j] = i-1;
                que[j][K[i-1]] = i-1;
            }
            else if(!que[j].empty()) dp[i][j] = (*que[j].begin()).second;
            if(L[j]<=K[i] && K[i]<=R[j]) continue;
            que[j].clear();
            dp[i][j] = -1;
        }
    }
    rep(i,0,2){
        if(dp[N][i] == -1) continue;
        cout << "Yes" << ln;
        vi ans;
        ll now = i;
        ll now2 = N;
        while(now2 >= 1){
            per(j,now2,dp[now2][now]+1){
                ans.pb(now);
            }
            now2 = dp[now2][now];
            now = 1-now;
        }
        reverse(ALL(ans));
        for(auto p:ans) cout << p << " ";
        cout << ln;
        return 0;
    }
    cout << "No" << ln;
}

