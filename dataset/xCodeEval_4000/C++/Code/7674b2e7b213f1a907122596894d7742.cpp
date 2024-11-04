
 
#include <bits/stdc++.h>
using namespace std;









typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
typedef vector<pll> vpll;
typedef vector<ll> vl;
#define loop(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define debugd(x,y) cout<<#x<<" : "<<x<<"  "<<#y<<" : "<<y<<'\n'
#define debugt(x,y,z) cout<<#x<<" : "<<x<<"  "<<#y<<" : "<<y<<"  "<<#z<<" : "<<z<<'\n'
#define pb   push_back
#define pf   push_front
#define mp   make_pair




#define sz(x) ((int)(x).size())
ll ceiling(ll a, ll b){return((a+b-1)/b);}
void swap(ll &a,ll &b){a^=b^=a^=b;}
 
const ll mod = 1e9+7 , mod2 = 998244353, INF = 1e18, inf = 4*mod;
const int mxN = 1e5+10;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_a(ll a,ll b,int m = mod){a %= m;b %= m;return (((a + b) % m) + m) % m;}
ll mod_m(ll a,ll b,int m = mod){a %= m;b %= m;return (((a * b) % m) + m) % m;}
ll mod_s(ll a,ll b,int m = mod){a %= m;b %= m;return (((a - b) % m) + m) % m;}
ll mod_d(ll a,ll b,int m = mod){a %= m;b %= m;return (mod_m(a, mminvprime(b, m)) + m) % m;}
 
string converttobinary(ll n){string s = bitset<64> (n).to_string();const auto loc1 = s.find('1');if(loc1 != string::npos)return s.substr(loc1);return "0";}
 
#define ina(a,x,n) a.resize(n+x); loop(i,x,n+x)cin>>a[i];
 
ll binexpomod(ll a,ll b,ll m){ll res = 1;a%=m; b%=(m-1); while(b>0){ if(b&1)res = (res * a) % m;a = (a * a) % m;b >>= 1;}return res;}
ll lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
ll n,m,x,y,z,k,k1,k2,a,b,c,d,e,f,l,r,u,v,w,mid,xx,yy,sum,cnt,res,ans,mx=-1,mn=mod;
vector<ll> adj[mxN], arr(mxN), primes, arr2, arr3;
string s,t,str;
bool vis[mxN], found;
int dxy[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};




ll bs(){
    l = 0, r = n-1;
    while(l <= r){
        mid = l+r >>1;
        cout << "? " << l + 1 << ' ' << mid + 1 << endl; 
        cin >> sum;
        z = mid - l + 1 - sum;
        if(z >= k)
            y = mid + 1,
            r = mid - 1;
        else if(z < k)
            l = mid + 1, k -= z;
    }
    return y;
}

void solve(){
    cin >> n >> x >> k;
    ans = bs();
    cout << "! " << ans;
}


 
int main()
{
    

    

    

    
    

    solve();
 
    return 0;
}