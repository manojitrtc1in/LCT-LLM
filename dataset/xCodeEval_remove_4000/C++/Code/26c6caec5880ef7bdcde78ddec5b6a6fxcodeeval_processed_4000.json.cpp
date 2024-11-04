
 

using namespace std;









typedef unsigned long long int ull;
typedef long long int ll;










ll ceiling(ll a, ll b){return((a+b-1)/b);}
void swap(ll &a,ll &b){a^=b^=a^=b;}
 
const ll mod = 1e9+7 , mod2 = 998244353;
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
bool vis[mxN], found;
int dxy[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};





void solve(){
    char c;
    cin>>n>>c>>str;
    cnt = 0;
    loop(i,0,n)cnt+=str[i]!=c;
    if(!cnt){
        cout<<0<<endl;
        return;
    }
    x = -1;
    for(int i=n-1;i>=0;--i)
        if(str[i]==c){x=i+1;break;}
    if(x==-1)
        cout<<2<<endl<<n<<' '<<n-1<<endl;
    else{
        if(x*2>n)
            cout<<1<<endl<<x<<endl;
        else
            cout<<2<<endl<<n<<' '<<n-1<<endl;
    }
}   



 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int tc,i=1; cin>>tc; while(tc--)
    solve();
 
    return 0;
}