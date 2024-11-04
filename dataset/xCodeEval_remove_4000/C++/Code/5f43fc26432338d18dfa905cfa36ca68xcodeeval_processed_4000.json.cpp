
 

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
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll id0(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_a(ll a,ll b,int m = mod){a %= m;b %= m;return (((a + b) % m) + m) % m;}
ll mod_m(ll a,ll b,int m = mod){a %= m;b %= m;return (((a * b) % m) + m) % m;}
ll mod_s(ll a,ll b,int m = mod){a %= m;b %= m;return (((a - b) % m) + m) % m;}
ll mod_d(ll a,ll b,int m = mod){a %= m;b %= m;return (mod_m(a, id0(b, m)) + m) % m;}
 
string id2(ll n){string s = bitset<64> (n).to_string();const auto loc1 = s.find('1');if(loc1 != string::npos)return s.substr(loc1);return "0";}
 

 
ll id1(ll a,ll b,ll m){ll res = 1;a%=m; b%=(m-1); while(b>0){ if(b&1)res = (res * a) % m;a = (a * a) % m;b >>= 1;}return res;}
ll lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
ll n,m,x,y,z,k,k1,k2,a,b,c,d,e,f,h,l,r,u,v,w,mid,xx,yy,sum,cnt,res,ans,mx=-1,mn=mod;
vector<ll> adj[mxN], arr(mxN), primes, arr2, arr3;
string s,t,str;
bool vis[mxN], found;
int dxy[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};




bool check(ll dis){
    x = arr[0];
    cnt = 0;
    loop(i,1,n)
        if(arr[i]-x >= dis)
            ++cnt, x = arr[i];
    return cnt >= k-1;
}

ll bs(){
    l = 1, r = n;
    ans = 1;
    while(r - l >= 1){
        mid = l+r >>1;
        cout << "? " << l << ' ' << mid << endl;
        cin >> sum;
        z = mid-l+1-sum;
        if(z < k)
            k -= z, l = mid + 1;
        else if(z >= k)
            r = mid;
    }
    return r;
}

void solve(){
    cin >> n >> x >> k;
    ans = bs();
    cout << "! " << ans;
    nl;
}


 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout << fixed << setprecision(15);
    
    

    solve();
 
    return 0;
}