


using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;








ll ceiling(ll a, ll b){return((a+b-1)/b);}

const ll mod = 1e9+7 , mod2 = 998244353;
const int mxN = 1e5+10;
int expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int id0(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_a(ll a,ll b){int m = mod; a %= m;b %= m;return (((a + b) % m) + m) % m;}
ll mod_m(ll a,ll b){int m = mod; a %= m;b %= m;return (((a * b) % m) + m) % m;}
ll mod_s(ll a,ll b){int m = mod; a %= m;b %= m;return (((a - b) % m) + m) % m;}
ll mod_d(ll a,ll b){int m = mod; a %= m;b %= m;return (mod_m(a, id0(b, m)) + m) % m;}

string id1(ll n){string s = bitset<64> (n).to_string();const auto loc1 = s.find('1');if(loc1 != string::npos)return s.substr(loc1);return "0";}



ll gcd(ll a, ll b) {return b ? gcd (b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll n,m,k,x,y,z,l,r,cnt,mx,a,b,c,d,ans,mid,sum,k1,k2,w,q,u,v;
vector<ll> adj[mxN], arr(mxN), primes(mxN), arr2(mxN);
string s,t,str;

void solve()
{
    cin>>n>>m>>k;
    x = n*(n-1);x/=2;
    if(m>x or m<n-1){cout<<"NO\n";return;}
    else if(k<=1){cout<<"NO\n";return;}
    else if(k==2 and n>1){cout<<"NO\n";return;}
    else if(k==3 and m<x){cout<<"NO\n";return;}
    else cout<<"YES\n";
} 





 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    

    


    

    

    

    

    

    


    int t;

    cin>>t; while(t--)

    solve();

    return 0;
}