#pragma GCC oPTimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma GCC oPTimization ("unroll-loops")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define epsi (double)(0.00000000001)
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<pii>
#define vvi vector<vi>




#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define ff(a,b,c) for(int a=b; a<=c; a++)
#define frev(a,b,c) for(int a=c; a>=b; a--)
#define REP(a,b,c) for(int a=b; a<c; a++)
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define ld long double
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define setbits(x) __builtin_popcountll(x)
#define trav(a,x) for(auto &a:x)
#define make_unique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define rev(arr) reverse(all(arr))
#define gcd(a,b) __gcd(a,b);
#define ub  upper_bound 

#define lb  lower_bound 

#define qi queue<ll>
#define fsh cout.flush()
#define si stack<ll>

const long double PI = acos(-1);



mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}


template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>;

template<class T>
using max_heap = priority_queue<T>;


template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T> istream& operator >> (istream &is, pair<T,T>& V) {
    is >> V.F >> V.S;
    return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}

#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
    return (out << "}");
}
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif

ll gcdExtended(ll a, ll b, ll *x, ll *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll m){
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
        ll res = (x%m + m) % m;
        return res;
}

ll binary_Search(vector<ll>&arr,ll key){
    ll l=0,r=arr.size()-1;
    ll ans;
    while(l<=r){
        ll mid=(l+r)/2;
        ll value=arr[mid];
        if(value>key){
            r=mid-1;
        }else if(value==key){
            return mid;
        }else{
            l=mid+1;
        }
    }
    return -1;
}
 
ll power(ll x,ll y,ll p){
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){  
        if (y & 1){
            res=(res*x)%p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}



























const ll MAX=1e18+5;
const int N=1e5+5;
vector<int> pr;










































const ll mod=1e9+7;
const ll mod1=998244353;

const int inf = 1e9;
const ll INF=1e18;

#define ii pii

void precompute(){
    
}

const int MOD=1e9+7;

struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        if(p>=MOD){
            p%=(MOD-1);
        }
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

struct my_node{
    bitset<26> mn;
    

    

    my_node(){}
    my_node(bitset<26> val){
        mn = val;
        

    }
    void merge(const my_node &l,const my_node &r){ 

        mn=l.mn|r.mn;
        

        

    }
};
 




 


 
struct my_update{
    ll v = 0; 

    bitset<26> b;
    

    

    my_update(){}
    my_update(bitset<26> val){
        b = val; 

    }
    

    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
        b=other.b;
        

    }
    

    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
        x.mn=b;
        

        

        

 
    }
};
 
template<typename node,typename update>
struct segtree{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l){
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
 
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(!lazy[v]) return;
        int32_t tm = (tl + tr) >> 1;
        apply(v<<1,tl,tm,u[v]);
        apply(v<<1|1,tm+1,tr,u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }
 
    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
        if(tl != tr){
            lazy[v] = 1;
            u[v].combine(upd,tl,tr);
        }
        upd.apply(t[v],tl,tr);
    }
 
    template<typename T>
    void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(tl == tr){
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr,v<<1,tl,tm);
        build(arr,v<<1|1,tm+1,tr);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
        if(l > tr || r < tl){
            return identity_element;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
        ans.merge(a,b);
        return ans;
    }
 
    

    void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
        if(l > tr || r < tl){
            return;
        }
        if(tl >= l && tr <= r){
            apply(v,tl,tr,upd);
            return;
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v<<1,tl,tm,l,r,upd);
        rupd(v<<1|1,tm+1,tr,l,r,upd);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }

    ll query1(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,ll ev, ll od){
        if(l > tr || r < tl){
            return 0;
        }
        if(tl >= l && tr <= r){
            
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        ll a = query1(v<<1,tl,tm,l,r,ev,od);
        ll b = query1(v<<1|1,tm+1,tr,l,r,ev,od);
        

        return a+b;
    }
 
    public:
    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const int32_t &l,const int32_t &r){
        return query(1,0,len-1,l,r);
    }

    ll query1(const int32_t &l,const int32_t &r,ll ev, ll od){
         return query1(1,0,len-1,l,r,ev,od);
    }

    void rupd(const int32_t &l,const int32_t &r,const update &upd){
        rupd(1,0,len-1,l,r,upd);
    }
};

const int N1=2*1e5+5;
struct edge{
    int u;
    int v;
    int w;
    int ind;
};
vector<vector<edge>> g(N1);
vi check;

int val[N1],val2[N1];
int ans[N1];
void dfs(int u,int p,int va=0){
    if(va!=-1){
        val[u]=setbits(va)%2;
        check.pb(u);
    }else{
        val[u]=-1;
    }
    for(auto i:g[u]){
        int v=i.v^i.u^u;
        if(v==p) continue;
        if(va==-1 || i.w==-1){
            dfs(v,u,-1);
        }else{
            dfs(v,u,va^i.w);
        }
    }
}
vector<vector<pair<int,int>>> qu(N1);
bool vis[N1];
bool ok=1;
void dfs2(int u,int p){
    vis[u]=1;
    for(auto i:qu[u]){
        if(vis[i.F]){
            if((i.S^val2[i.F])!=val2[u]){
                ok=0;
            }
        }else{
            if(val[i.F]!=-1){
                if(val[i.F]!=(i.S^val[u])){
                    ok=0;
                }
            }else{
                val[i.F]=i.S^val[u];
            }
            val2[i.F]=i.S^val2[u];
            dfs2(i.F,u);
        }
    }
}

void dfs3(int u,int p,int va=0){
    for(auto i:g[u]){
        int v=i.v^i.u^u;
        if(v==p) continue;
        if(i.w!=-1){
            dfs3(v,u,va^i.w);
            ans[i.ind]=i.w;
        }else{
            assert(val[v]!=-1);
            if(val[v]){
                i.w=1^va;
            }else{
                i.w=va;
            }
            ans[i.ind]=i.w;
            dfs3(v,u,va^i.w);
        }
    }
}

void TEST_CASE(){
    int n, m;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++){
        g[i].clear();
        vis[i]=0;
        qu[i].clear();
    }
    vii edges;
    check.clear();
    for(int i=1 ; i<n ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.pb({u,v});
        g[u].pb({u,v,w,i});
        g[v].pb({u,v,w,i});
        if(w!=-1){
            if(setbits(w)%2){
                qu[u].pb({v,1});
                qu[v].pb({u,1});
            }else{
                qu[u].pb({v,0});
                qu[v].pb({u,0});
            }
        }
    }
    dfs(1,0);
    ok=1;
    map<pair<int,int>,int> m1;
    for(int i=0 ; i<m ; i++){
        int u,v,x;
        cin >> u >> v >> x;
        qu[u].pb({v,x});
        qu[v].pb({u,x});
        pair<int,int> temp={min(u,v),max(u,v)};
        if(m1.find(temp)!=m1.end()){
            if(x!=m1[temp]){
                ok=0;
            }
        }else{
            m1[temp]=x;
        }
    }
    for(auto i:check){
        if(!vis[i]){
            val2[i]=0;
            dfs2(i,0);
        }
    }
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            val2[i]=0;
            val[i]=0;
            dfs2(i,0);
        }
    }
    if(!ok){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    dfs3(1,0);
    for(int i=1 ; i<n ; i++){
        cout << edges[i-1].F << " " << edges[i-1].S << " " << ans[i] << endl;
    }
}

signed main(){
    fast;
    

    

    int test=1,TEST=1;
    auto start = std::chrono::high_resolution_clock::now();
    precompute();
    cin >> test;
    while(test--){
        

        TEST_CASE();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    

    return 0;
}