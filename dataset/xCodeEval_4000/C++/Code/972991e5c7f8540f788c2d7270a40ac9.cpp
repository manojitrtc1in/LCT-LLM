#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define pqueue priority_queue
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl cout<<'\n'
const ull FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
struct custom_hash 
{
    static ull splitmix64(ull x) 

    {x+=0x9e3779b97f4a7c15,x=(x^(x>>30))*0xbf58476d1ce4e5b9,x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    uint operator()(ull x)const{return splitmix64(x+FIXED_RANDOM);}
    template<typename A,typename B>
    uint operator()(pair<A,B>x)const{return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1);}
};
template<typename A,typename B>using umap=gp_hash_table<A,B,custom_hash>; 

template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<int MOD,int RT> 
struct Mint 
{
	static const int mod = MOD; int v;
	static constexpr Mint rt(){return RT;} 

	explicit operator int()const{return v;} 

	Mint():v(0){}
	Mint(ll _v){v=int((-MOD<_v && _v<MOD)?_v:_v%MOD);if(v<0)v+=MOD;}
	bool operator==(const Mint &o)const{return v==o.v;}
	friend bool operator!=(const Mint &a,const Mint &b){return!(a==b);}
	friend bool operator<(const Mint &a, const Mint &b) {return a.v<b.v;}
	Mint &operator+=(const Mint &o){if((v+=o.v)>=MOD)v-=MOD;return *this;}
	Mint &operator-=(const Mint &o){if((v-=o.v)<0)v+=MOD;return *this;}
	Mint &operator*=(const Mint &o){v=int((ll)v*o.v%MOD);return *this;}
	Mint &operator/=(const Mint &o){return(*this)*=inv(o);}
	friend Mint pow(Mint a, ll p){Mint ans=1;for(;p;p/=2,a*=a)if(p&1)ans*=a;return ans;}
	friend Mint inv(const Mint &a){assert(a.v!=0);return pow(a,MOD-2);}
	Mint operator-()const{return Mint(-v);}
	Mint &operator++(){return *this+=1;}
	Mint &operator--(){return *this-=1;}
	friend Mint operator+(Mint a,const Mint &b){return a+=b;}
	friend Mint operator-(Mint a,const Mint &b){return a-=b;}
	friend Mint operator*(Mint a,const Mint &b){return a*=b;}
	friend Mint operator/(Mint a,const Mint &b){return a/=b;}
};
struct Line 
{
    mutable ll m,c,poi;
    bool operator<(const Line& o)const{return m<o.m;}
    bool operator<(const ll &x)const{return poi<x;}
};
struct LineContainer : multiset<Line, less<>> 
{
    static const ll inf = LLONG_MAX;
    LineContainer(){}
    ll div(const ll &a,const ll &b){return a/b-((a^b)<0&&a%b);}
    bool isect(iterator x,iterator y) 
    {
        if(y==end())return x->poi=inf,0;
        if(x->m==y->m)x->poi=x->c>y->c?inf:-inf;
        else x->poi=div(y->c-x->c,x->m-y->m);
        return x->poi>=y->poi;
    }
    void add(const ll &m,const ll &c) 
    {
        auto z=insert({m,c,0}),y=z++,x=y;
        while(isect(y,z))z=erase(z);
        if(x!=begin()&&isect(--x,y))isect(x,y=erase(y));
        while((y=x)!=begin()&&(--x)->poi>=y->poi)isect(x,erase(y));
    }
    ll query(const ll &x){assert(!empty());auto l=lower_bound(x);return l->m*x+l->c;}
};
#ifdef LOCAL
#define debug(...) logger(__LINE__,#__VA_ARGS__,__VA_ARGS__)
#else
#define debug(...) 0
#endif
template<int MOD,int RT>ostream &operator<<(ostream &out,const Mint<MOD,RT>&x){out<<x.v;return out;}
template<int MOD,int RT>istream &operator>>(istream &in,Mint<MOD,RT>&x){ll v;in>>v;x=Mint<MOD,RT>(v);return in;}
template<typename T>ostream &operator<<(ostream &out,const vector<T>&v) {for(const T&x:v)out<<x<<' ';return out;}
template<typename T>istream &operator>>(istream &in,vector<T>&v){for(T &x:v)in>>x;return in;}
template<typename A,typename B>ostream &operator<<(ostream &out,const pair<A,B>&p){out<<p.first<<' '<<p.second;return out;}
template<typename A,typename B>istream &operator>>(istream &in,pair<A,B>&p){in>>p.first>>p.second;return in;}
template<typename ...Args>void logger(int line,string vars,Args&&... values) 
{cout <<"Line "<<line<<" : ("<<vars<<") = (";string delim="";(...,(cout<<delim<<values,delim=", "));cout<<")\n";}
ll cdiv(const ll &a,const ll &b){return a/b+((a^b)>0 && a%b);}
ll fdiv(const ll &a,const ll &b){return a/b-((a^b)<0 && a%b);}
template<typename T,typename F>
T first_true(T lo,T hi,const F&f){hi++;while(lo<hi){T mid=lo+(hi-lo)/2;if(f(mid))hi=mid;else lo=mid+1;}return lo;}
template<typename T,typename F> 

T last_true(T lo,T hi,const F&f){lo--;while(lo<hi){T mid=lo+(hi-lo+1)/2;if(f(mid))lo=mid;else hi=mid-1;}return lo;}
template<typename T>
vector<pair<T,int>>rle(const vector<T>&a){if(!a.size())return vector<pair<T,int>>();vector<pair<T,int>>res(1,{a[0],0});for(const T&x:a)if(x==res.back().first)res.back().second++;else res.push_back({x,1});return res;}
bool is_prime(const ll &x){if(x<2)return false;for(ll d=2;d*d<=x;d++)if(x%d==0)return false;return true;}
vector<pair<ll,ll>> pfactor(ll x){vector<pair<ll,ll>>res;for(ll d=2,cnt;d*d<=x;d++){cnt=0;while(x%d==0)cnt++,x/=d;if(cnt)res.push_back({d,cnt});}if(x>1)res.push_back({x,1});return res;}
ll gcd(const ll &x, const ll &y){return(y==0?x:gcd(y,x%y));}
ll lcm(const ll &x, const ll &y){return x/gcd(x,y)*y;}
ll gcd(const ll &a,const ll &b,ll&x,ll&y){if(b==0){x=1,y=0;return a;}ll x1,y1;ll d=gcd(b,a%b,x1,y1);x=y1,y=x1-y1*(a/b);return d;}
uint bitcount(const ull &x){return __builtin_popcountll(x);}
ull lsb(const ull &x){return x&(~x+1);}
ull msb(const ull &x){if(x==0)return 0;return(1ULL<<(63-__builtin_clzll(x)));}
ull sq(const ll &x){return x*x;}
uint log2(const ull &x){return (63-__builtin_clzll(x));}
int sqrt(const int &y){return last_true(0,y,[&](const int &x)->bool{return x*x<=y;});}
ll sqrt(const ll &y){return last_true(0LL,y,[&](const ll &x)->bool{return x*x<=y;});}
ll binpow(ll a,ull n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ull n,const ll &mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
const int dx[8]={1,0,-1,0,1,1,-1,-1},dy[8]={0,1,0,-1,1,-1,1,-1}; 
const ll mod = 1000000007;


using mint = Mint<mod, 5>; 

bool TESTCASES = 1;
 
int n, m, a[200000], idx[200000];
int rmq[200000][20];
 
int query(int l, int r)
{
    if (r < l)
        return -1;
    int j = (int) log2((ull)(r - l + 1));
    if (a[rmq[l][j]] >= a[rmq[r - (1 << j) + 1][j]])
        return rmq[l][j];
    return rmq[r - (1 << j) + 1][j];
}
 
pair<int,int> ranges[200000];
queue<int> order;
int L[200000], R[200000];
void find_ranges(int l, int r, int i)
{
    if (r < l)
        return;
    if (l == r)
    {
        ranges[l] = {l, r};
        order.push(i);
        return;
    }
 
    ranges[i] = {l, r};
    L[i] = query(l, i - 1);
    R[i] = query(i + 1, r);
 
    find_ranges(l, i - 1, L[i]);
    find_ranges(i + 1, r, R[i]);

    order.push(i);
}
 
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        rmq[i][0] = i;
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
            if (a[rmq[i][j-1]] >= a[rmq[i + (1 << (j - 1))][j-1]])
                rmq[i][j] = rmq[i][j-1];
            else
                rmq[i][j] = rmq[i + (1 << (j - 1))][j-1];
 
    find_ranges(0, n - 1, query(0, n - 1));
    vector<vector<ll>> dp(n, vector<ll> (m + 1, 1));
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    while (!order.empty())
    {
        int i = order.front();
        order.pop();
        if (ranges[i].first == ranges[i].second)
        {
            for (int x = 1; x <= m; x++)
                dp[i][x] = x;
        }
        else if (ranges[i].first == i)
        {
            for (int x = 1; x <= m; x++)
            {
                dp[i][x] = dp[i][x - 1] + dp[R[i]][x];
                dp[i][x] %= mod;
            }
        }
        else if (ranges[i].second == i)
        {
            for (int x = 1; x <= m; x++)
            {
                dp[i][x] = dp[i][x - 1] + dp[L[i]][x - 1];
                dp[i][x] %= mod;
            }
        }
        else
        {
            for (int x = 1; x <= m; x++)
            {
                dp[i][x] = dp[i][x - 1] + dp[L[i]][x - 1] * dp[R[i]][x] % mod;
                dp[i][x] %= mod;
            }
        }
    }
 
    cout << dp[order.back()][m] << '\n';
 
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int _t=1;
    if(TESTCASES)cin>>_t;
    while(_t--)solve();
    return 0;
}


