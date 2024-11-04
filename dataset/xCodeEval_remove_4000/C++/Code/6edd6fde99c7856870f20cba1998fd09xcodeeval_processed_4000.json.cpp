
 

using namespace std;









typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
typedef vector<pll> vpll;
typedef vector<ll> vl;










ll ceiling(ll a, ll b){return((a+b-1)/b);}
void swap(ll &a,ll &b){a^=b^=a^=b;}
 
const ll mod = 1e9+7 , mod2 = 998244353, INF = 1e18, inf = 4*mod;
const int mxN = 1e5+10;
int expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int id0(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_a(ll a,ll b){int m = mod; a %= m;b %= m;return (((a + b) % m) + m) % m;}
ll mod_m(ll a,ll b){int m = mod2; a %= m;b %= m;return (((a * b) % m) + m) % m;}
ll mod_s(ll a,ll b){int m = mod; a %= m;b %= m;return (((a - b) % m) + m) % m;}
ll mod_d(ll a,ll b){int m = mod2; a %= m;b %= m;return (mod_m(a, id0(b, m)) + m) % m;}
 
string id2(ll n){string s = bitset<64> (n).to_string();const auto loc1 = s.find('1');if(loc1 != string::npos)return s.substr(loc1);return "0";}
 

 
ll id1(ll a,ll b,ll m){ll res = 1;a%=m; b%=(m-1); while(b>0){ if(b&1)res = (res * a) % m;a = (a * a) % m;b >>= 1;}return res;}
ll lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
ll n,m,x,y,z,k,k1,k2,a,b,c,d,e,f,l,r,u,v,mid,xx,yy,sum,cnt,res,ans,mx=-1,mn=mod;
vector<ll> adj[mxN], arr(mxN), primes, arr2, arr3;
string s,t,str;
bool vis[mxN][3], found;
int dxy[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};




void solve(){
    cin>>a>>b;
    if(a<b) swap(a,b);

    if(a%2 == b%2){
        x = a-b >>1;
        y = (a+b) - x;
        ans = y-x >>1;
        cout << ++ans << endl;
        loop(i,x,y+1)
            cout << i << ' ', ++i;
    }

    else{
        x = a - (a+b+1)/2;
        y = (a+b) - x;
        cout << y - x + 1 << endl;
        loop(i,x,y+1)
            cout << i << ' ';
    }
    nl;
}   



 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    


    int tc,i=1; cin>>tc; while(tc--)
    solve();
 
    return 0;
}