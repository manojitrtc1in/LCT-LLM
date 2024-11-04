







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
#define INf 2000000000000000000
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
#define si stack<ll>

const long double PI = acos(-1);

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

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
const int N=2*1e5+5;
const int N1=5*1e3+5;










































ll mod=1e9+7;
ll mod1=998244353;

const int inf = 1e9;
const ll INF=1e18;

#define ii pii




















































































































































































































struct SuffixArray
{
    #define sentinel (char)(32)
    vector<int> pos, eq, lcp, locate;
    

    string s;
    void radix_sort(vector<pair<pair<int, int>, int>> &v, vector<int> &pos, vector<int> &eq)
    {
        int n = v.size();
        vector<int> where(n);
        for(int i=0; i<n; i++)
            where[v[i].second] = i;
 
 
        vector<int> cnt(n);
        for(int i=0; i<n; i++)
            cnt[v[i].F.F]++;
        
        vector<int> from(n);
        from[0] = 0;
        for(int i=1; i<n; i++)
            from[i] = from[i-1] + cnt[i-1];
        
        for(int i=0; i<n; i++)
        {
            pos[from[v[i].F.F]] = v[i].S; from[v[i].F.F]++;
        }
 
        eq[pos[0]] = 0;
        for(int i=1; i<n; i++)
        {
            eq[pos[i]] = eq[pos[i-1]] + (v[where[pos[i]]].F != v[where[pos[i-1]]].F);
        }
    }
    void build(string t)
    {
        s = t; 
        s += sentinel;
        int n = s.size();
        pos.resize(n);
        eq.resize(n);
        vector<pair<char, int>> x(n);
        for(int i=0; i<n; i++)
            x[i] = {s[i], i};
        
        sort(x.begin(), x.end());
        for(int i=0; i<n; i++)
        {
            pos[i] = x[i].second;
            eq[pos[i]] = ((i==0) ? 0 : eq[pos[i-1]] + (s[pos[i]]!=s[pos[i-1]]));
        }
 
        int cur = 1;
        while(cur < n && eq[n-1] != n-1)
        {
            cur *= 2;
            vector<pair<pair<int, int>, int>> v(n);
            for(int i=0; i<n; i++)
            {
                int x = (pos[i]-cur/2+n);
                if(x >= n) x -= n;
 
                v[i] = {{eq[x], eq[pos[i]]}, x};
            }
            radix_sort(v, pos, eq);
        }       
    }
    void build_lcp()
    {
        int n = s.size();
        lcp.resize(n);
        locate.resize(n);
        for(int i=0; i<n; i++)
            locate[pos[i]] = i;
 
        for(int i=0; i<n-1; i++)
        {
            int w = locate[i];
            int up = pos[w-1];
            if(i > 0)
            {
                lcp[w] = max(lcp[w], lcp[locate[i-1]]-1);
            }
            while(s[i+lcp[w]] == s[up+lcp[w]])
            {
                ++lcp[w];
            }
        }
    }
    

    

    

    

        
    

    

    

    

 
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

};

struct my_node
{
    int mn = 1e9;
    int freq = 0;
    

    

    my_node(){}
    my_node(int val){
        mn = val;
        freq = val;
    }
    void merge(const my_node &l,const my_node &r){ 

 
        mn = min(l.mn,r.mn);
        freq=l.freq+r.freq;
        

        

    }
};
 




 


 
struct my_update
{
    int v = 0; 

    

    

    my_update(){}
    my_update(int val){
        v = val; 

    }
    

    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
        v +=other.v; 

        

    }

    

    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
 
        

        x.mn+=v;
        x.freq+=v;
 
    }
};
 
template<typename node,typename update>
struct segtree
{
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
 
    public:
    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const int32_t &l,const int32_t &r){
        return query(1,0,len-1,l,r);
    }
    void rupd(const int32_t &l,const int32_t &r,const update &upd){
        rupd(1,0,len-1,l,r,upd);
    }
};

void precompute(){
    
}

const int MOD = 998244353;
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

ll query(ll l,ll r){
    cout << "? " << l << " " << r << endl;
    cout.flush();
    ll x;
    cin >> x;
    assert(x!=-1);
    return x;
}

ll n;

ll bs(ll val){
    ll l=1,r=n,mid,ans=-1;
    while(l<=r){
        mid=(l+r)/2;
        ll temp=(mid*(mid+1))/2;
        if(temp==val){
            return mid;
        }else if(temp>val){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

void TEST_CASE(){
    cin >> n;
    ll tot=query(1,n);
    ll l=1,r=n,mid,ans;
    ll i=-1,j;
    ll k,x;
    while(l<=r){
        mid=(l+r)/2;
        ll x1=query(1,mid);
        if(x1==0){
            l=mid+1;
            continue;
        }else if(x1==tot){
            ans=mid;
            r=mid-1;
            continue;
        }
        ll temp1=bs(x1);
        if(temp1==-1){
            r=mid-1;
        }else{
            if(i==-1){
                ll x2=query(1,mid-temp1);
                if(x2==0){
                    i=mid-temp1;
                }else{
                    ll x3=query(1,mid-1);
                    x1-=x3;
                    j=mid-x1;
                    x1=query(1,j-1);
                    x1=bs(x1);
                    i=j-1-x1;
                    ans=j;
                    break;
                }
                ans=mid+1;
                l=mid+1;
            }else{
                if(temp1==(mid-i)){
                    l=mid+1;
                }else{
                    ans=mid;
                    r=mid-1;
                }
            }
        }
    }
    j=ans;
    x=query(1,j-1);
    k=bs(tot-x)+j;
    

    

    cout << "! " << i << " " << j << " " << k << endl;
    cout.flush();
}


signed main(){
    fast;
    

    

    int test=1,TEST=1;
    precompute();
    cin >> test;
    while(test--){
        

        TEST_CASE();
    }
    return 0;
}