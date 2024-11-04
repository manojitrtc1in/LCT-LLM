





using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
ll INF = 1e9+7;
ll MOD = 998244353;
typedef pair<ll,ll> ii;























mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr;
ll rnd(ll a, ll b){return distr(rng)%(b-a+1)+a;}
template <typename T> struct Dsu{
    vector<T>par;
    int N;
    void init(int n){
        N = n+1;
        f(i,0,N){
            par.pb(i);
        }
    }
    int find_par(int x){
        if(par[x] == x){
            return x;
        }
        par[x] = find_par(par[x]);
        return par[x];
    }
    bool enose(ll x,ll y){
        ll pos1 = find_par(x);
        ll pos2 = find_par(y);
        par[pos2] = pos1;
        return pos1 != pos2;
    }
};
template <typename T> struct Matrix{
    vector<vector<T> > matrix,base,last;
    int mod = 1e9+7;
    void build(vector<vector<T> > a,vector<vector<T> >b){
        matrix = base = a;
        last = b;
    }
    void mult(vector<vector<T> > &a,vector<vector<T> > &b){
        vector<vector<T> > ans;
        vector<T> v;
        v.assign(b[0].size(),0);
        ans.assign(a.size(),v);
        f(i,0,a.size()){
            f(j,0,b[0].size()){
                f(k,0,b.size()){
                    ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        f(i,0,a.size()){
            f(j,0,b[0].size()){
                a[i][j] = ans[i][j];
            }
        }
    }
    void expo(vector<vector<T> >&a,ll x){
        if(x <= 1){
            return;
        }
        expo(a,x/2);
        mult(a,a);
        if(x % 2){
            mult(a,base);
        }
    }
};
struct Num{
    ll val;
    int mod = 1e9+7;
    ll power(ll b){
        if(b == 0){
            return 1;
        }
        if(b == 1){
            return val;
        }
        ll ans = power(b/2);
        ans *= ans;
        ans %= mod;
        if(b % 2){
            ans *= val;
            ans %= mod;
        }
        return ans;
    }
    ll inverse(void){
       val %= mod;
       return power(mod-2);
    }
};
struct Binomial{
    int N,mod = 1e9+7;
    vector<int> fact;
    void build(int n){
        N = n+5;
        fact.pb(1);
        fact.pb(1);
        f(i,2,N){
            fact.pb((fact[i-1] * 1LL * i) % mod);
        }
    }
    ll ana(ll n,ll k){
        if(k > n){
            return -1;
        }
        ll ans = fact[n];
        Num a,b;
        a.val = fact[k],b.val = fact[n-k];
        ans *= a.inverse();
        ans %= mod;
        ans *= b.inverse();
        return ans%mod;
    }
};
template <typename T> struct Bit{
    int N;
    vector<T>bit;
    void build(int n){
        N = n+5;
        f(i,0,n){
            bit.pb(0);
        }
    }
    void upd(int k,T x){
        while(k <= N){
            bit[k] += x;
            k += k & -k;
        }
    }
    T query(int k){
        T ans = 0;
        while(k >= 1){
            ans += bit[k];
            k -= k & -k;
        }
        return ans;
    }
};
template <typename T> struct Segtree{
    vector<T>seg;
    void init(ll n){
        T a;
        seg.assign(4*n+5,a);
    }
    void build(ll s,ll e,ll idx,T arr[]){
        if(s == e){
            seg[idx].val = arr[s-1];
            return;
        }
        ll mid = (s+e)/2;
        build(s,mid,idx*2);
        build(mid+1,e,idx*2+1);
        seg[idx].val = seg[idx*2].val + seg[idx*2+1].val;
    }
    void update(ll s,ll e,ll qs,ll qe,ll idx,ll k){
        if(qs <= s && qe >= e){
            seg[idx].val += k * (e-s+1);
            seg[idx].lazy += k;
            return;
        }
        if(s > qe || e < qs){
            return;
        }
        ll mid = (s+e)/2;
        seg[idx*2].lazy += seg[idx].lazy;
        seg[idx*2+1].lazy += seg[idx].lazy;
        seg[idx*2].val += seg[idx].lazy * (mid-s+1);
        seg[idx*2+1].val += seg[idx].lazy * (e-mid);
        seg[idx].lazy = 0;
        update(s,mid,qs,qe,idx*2,k);
        update(mid+1,e,qs,qe,idx*2+1,k);
        seg[idx].val = seg[idx*2].val + seg[idx*2+1].val;
    }
    T query(ll s,ll e,ll qs,ll qe,ll idx){
        if(qs <= s && qe >= e){
            return seg[idx].val;
        }
        if(s > qe || e < qs){
            return 0;
        }
        ll mid = (s+e)/2;
        seg[idx*2].lazy += seg[idx].lazy;
        seg[idx*2+1].lazy += seg[idx].lazy;
        seg[idx*2].val += seg[idx].lazy * (mid-s+1);
        seg[idx*2+1].val += seg[idx].lazy * (e-mid);
        seg[idx].lazy = 0;
        T a = query(s,mid,qs,qe,idx*2);
        T b = query(mid+1,e,qs,qe,idx*2+1);
        return a+b;
    }
};
template <typename T> struct Graph{
    vector<vector<T> >adj;
    vector<ll>dist;
    ll N,M;
    ll res = 0;
    vector<bool>vis,taken;
    void init(ll n,ll m){
        N = n,M = m;
        adj.assign(n+1,vector<T>());
    }
    void unvis(void){
        vis.assign(N+1,0);
        dist.assign(N+1,INF);
    }
    void dfs(ll s){
        vis[s] = true;
        res++;
        for(auto x:adj[s]){
            if(!vis[x]){
                dfs(x);
            }
        }
    }
    void dfsw(ll s){
        vis[s] = true;
        res++;
        for(auto x:adj[s]){
            if(!vis[x.F]){
                dfsw(x.F);
            }
        }
    }
    void bfs(ll s){
        queue<ll>q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()){
            ll f = q.front();
            q.pop();
            for(auto x:adj[f]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }
    void bfs01(ll s){
        deque<ll>q;
        dist[s] = 0;
        q.push_back(s);
        while(!q.empty()){
            ll v = q.front();
            q.pop_front();
            for(auto x:adj[v]){
                if(dist[x.F] > dist[v] + x.S){
                    dist[x.F] = dist[v] + x.S;
                    if(x.S == 0){
                        q.push_front(x.F);
                    }
                    else{
                        q.push_back(x.F);
                    }
                }
            }
        }
    }
    void dijkstra(ll s){
        priority_queue<ii,vector<ii>, greater<ii> >pq;
        pq.push(ii(0,s));
        dist[s] = 0;
        while(!pq.empty()){
            ii f = pq.top();
            pq.pop();
            ll w = f.F;
            ll u = f.S;
            if(w > dist[u]){
                continue;
            }
            for(auto v:adj[u]){
                if(dist[u] + v.S < dist[v.F]){
                    dist[v.F] = dist[u] + v.S;
                    pq.push(ii(dist[v.F],v.F));
                }
            }
        }
    }
    ll mst_prim(ll s){
        taken.assign(N+1,0);
        priority_queue<ii,vector<ii>, greater<ii> >pq;
        taken[s] = 1;
        for(auto v:adj[s]){
            if(!taken[v.F]){
                pq.push(ii(v.S,v.F));
            }
        }
        ll cost = 0;
        while(!pq.empty()){
            ii f = pq.top();
            pq.pop();
            ll w = f.F;
            ll u = f.S;
            if(!taken[u])
                cost += w;
            taken[u] = 1;
            for(auto v:adj[u]){
                if(!taken[v.F]){
                    pq.push(ii(v.S,v.F));
                }
            }
        }
        return cost;
    }
    ll mst_kruskal(void){
        ll ans = 0;
        vector<iii>edges;
        f(i,0,N+1){
            for(auto x:adj[i]){
                edges.pb(iii(x.S,ii(x.F,i)));
            }
        }
        sort(all(edges));
        Dsu<ll>exo;
        exo.init(N);
        for(auto x:edges){
            if(exo.find_par(x.S.F) != exo.find_par(x.S.S)){
                ans = max(ans,x.F);
                exo.enose(x.S.F,x.S.S);
            }
        }
        return ans;
    }
};
template <typename T> struct Tree{
    vector<vector<T> >adj;
    ll N;
    vector<ll>an[35];
    vector<ll>depth;
    void init(ll n){
        N = n;
        adj.assign(n+1,vector<T>());
        depth.assign(n+1,0);
        f(i,0,35){
            an[i].assign(n+1,0);
        }
    }
    void dfs(ll s,ll p){
        for(auto x:adj[s]){
            if(x != p){
                depth[x] = depth[s] + 1;
                dfs(x,s);
            }
        }
    }
    void dfsw(ll s,ll p){
        for(auto x:adj[s]){
            if(x.F != p){
                depth[x.F] = depth[s] + 1;
                dfs(x.F,s);
            }
        }
    }
    void build(ll s,ll p){
        an[s][0] = p;
        f(i,1,35){
            an[s][i] = an[an[s][i-1]][i-1];
        }
        for(auto x:adj[s]){
            if(x != p){
                depth[x] = depth[s] + 1;
                build(x,s);
            }
        }
    }
    ll kth(ll x,ll k){
        ll ans = x;
        if(depth[x] < k){
            return -1;
        }
        ll pos = 0;
        while(k > 0){
            if(k % 2){
                ans = an[ans][pos];
            }
            pos++;
            k /= 2;
        }
        return ans;
    }
    ll lca(ll a,ll b){
        if(depth[a] > depth[b]){
            swap(a,b);
        }
        b = kth(b,abs(depth[a] - depth[b]));
        if(a == b){
            return a;
        }
        for(ll i = 34;i >= 0;i--){
            if(an[a][i] == an[b][i]){
                continue;
            }
            a = an[a][i];
            b = an[b][i];
        }
        return an[a][0];
    }
};
template <typename T> struct Trie{
    vector<T>trie;
    ll c = 1;
    void init(ll n){
        T a;
        c = 1;
        trie.assign(n+1,a);
    }
    void add(string s,ll n){
        ll cur = 1,next;
        f(i,0,n){
            next = trie[cur].child[s[i]-'a'];
            if(next == 0){
                c++;
                trie[cur].child[s[i]-'a'] = c;
                cur = c;
            }
            else{
                cur = next;
            }
            trie[cur].pre++;
        }
    }
    ll prefix(string s,ll n){
        ll cur = 1;
        f(i,0,n){
            cur = trie[cur].child[s[i]-'a'];
            if(cur == 0){
                return 0;
            }
        }
        return trie[cur].pre;
    }
};
struct Hash{
    string s;
    vector<ll>pre[3],suf[3];
    vector<ull>pref,suff;
    vector<ll>powe[3];
    vector<ull>power;
    ll base = 256;
    ll mod[3];
    void build(void){
        mod[0] = 1e9+7;
        mod[1] = 1e9+9;
        mod[2] = 998244353;
        ll num[3];
        f(j,0,3){
            pre[j].pb(0);
            suf[j].pb(0);
            num[j] = 1;
        }
        pref.pb(0);
        ull numi = 1;
        suff.pb(0);
        rf(i,s.size()-1,0){
            f(j,0,3){
                suf[j].pb((suf[j].back() + (num[j] * (ll)(s[i] -'0')) % mod[j]) % mod[j]);
                powe[j].pb(num[j]);
                num[j] = (num[j] * base) % mod[j];
            }
            suff.pb(suff.back() + numi * (ll)(s[i]-'0'));
            power.pb(numi);
            numi *= base;
        }
        f(i,0,s.size()){
            f(j,0,3){
                pre[j].pb(((pre[j].back() * base) % mod[j] + (ll)(s[i] -'0')) % mod[j]);
            }
            pref.pb((pref.back() * base) + (ll)(s[i]-'0'));
        }
    }
    ll timi(ll l,ll r,ll pos){
        if(pos <= 2){
            ll ans = (pre[pos][r+1] + (mod[pos] - ((pre[pos][l] * powe[pos][r-l+1]) % mod[pos]))) % mod[pos];
            return ans;
        }
        else{
            ull ans = pref[r+1] - (pref[l] * power[r-l+1]);
            return ans;
        }
    }
};
template <typename T> struct opset{
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> s;
    ll pos(ll e){
        return s.order_of_key(e);
    }
    ll atpos(ll e){
        return s.find_by_order(e);
    }
    void Erase(ll e){
        s.erase(s.find_by_order(s.order_of_key(e)));
    }
};
template <typename T> struct opmap{
    gp_hash_table<T,ll> mp;
};
void YESNO(ll a){if(!!a){pl("YES");}else{pl("NO");}}
void filesin(void){freopen("input.in","r",stdin);}
void filesout(void){freopen("output.out","w",stdout);}












int main(void){
    fastio;
    Hash a;
    cin>>a.s;
    ll n = a.s.size();
    a.base = 10;
    a.build();
    f(i,2,n){
        if(a.s[i] == '0' && i != n-1){
            continue;
        }
        f(len,max(1LL,(n-i)-1),(n-i)+2){
            bool ok = 1;
            if(len > i-1){
                continue;
            }
            f(j,0,3){
                if((a.s[len] == '0' && i-1 != len) || a.timi(i,n-1,j) != (a.timi(0,len-1,j) + a.timi(len,i-1,j)) % a.mod[j]){
                    ok = 0;
                }
            }
            if(ok){
                f(j,0,n){
                    if(j == i){
                        p('=');
                    }
                    p(a.s[j]);
                    if(j == len-1){
                        p('+');
                    }
                }
                return 0;
            }
        }
        f(len,max(1LL,(n-i)-1),(n-i)+2){
            if(i-len-1 < 0){
                continue;
            }
            bool ok = 1;
            f(j,0,3){
                if((a.s[i-len] == '0' && i-1 != i-len) || a.timi(i,n-1,j) != (a.timi(0,i-len-1,j) + a.timi(i-len,i-1,j)) % a.mod[j]){
                    ok = 0;
                }
            }
            if(ok){
                f(j,0,n){
                    if(j == i){
                        p('=');
                    }
                    p(a.s[j]);
                    if(j == i-len-1){
                        p('+');
                    }
                }
                return 0;
            }
        }
    }
}

