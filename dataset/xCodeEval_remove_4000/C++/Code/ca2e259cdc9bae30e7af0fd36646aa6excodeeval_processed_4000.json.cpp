






using namespace std;
using namespace __gnu_pbds;
 




































const ld pi  = 3.141592653589793238462;
const ll mod = 1000000007;


const ll inf = 1e18;









void _print(bool t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll id4(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, id4(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

ll mul(ll a , ll b , ll m){ ll res = (a%m*b%m)%m; if(res<0) {res+=m;} return res;}
ll ceil(ll a,ll b){ if(a%b==0) {return a/b;} else {return a/b +1;} }
ll power(ll a,ll b) { ll res=1; while(b>0) { if(b&1) { res=res*a; b--; } else { a=a*a; b/=2; } } return res; }
ll mod_power(ll a , ll b , ll m){ ll res = 1; while (b > 0) { if (b & 1) {res = mul(res,a,m);} a = mul(a , a , m); b >>= 1;} return res%m; }
ll isprime(ll n) { ll flag=1; for ( ll i = 2; i <= sqrt(n); i++) { if (n % i == 0) { flag = 0; break; } } if (n <= 1) { flag = 0; } return flag; }
ll id0(ll a) { ll S=0; while(a>0) { ll t=a%10; S+=t; a/=10; } return S; }
ll gcd(ll a,ll b) { return __gcd(a,b); }
ll highestpower(ll n) { ll temp=1; for(ll i=1;1;i++) { temp=1<<i; if(temp>n) { return temp; } } } 

ll id2(ll x) { ll y=sqrt(x); return y*y==x; }
ll stoint(string s) { stringstream geek(s); ll x = 0; geek >> x; return x; }
ll fact(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) { res = res * i; } return res; }
ll nCr(ll n, ll r) { return fact(n) / (fact(r) * fact(n - r)); }
ll countDigit(ll n) { ll count = 0; while (n != 0) { n = n / 10; ++count; } return count; }
ll id3(string s) { ll t=0; ll l=sz(s); rep(i,0,l) { if(s[i]!=s[l-i-1]) t=1; } if(t) { return 0; } return 1; }
ll id7(ll num) { ll rev_num = 0; while (num > 0) { rev_num = rev_num * 10 + num % 10; num = num / 10; } return rev_num; }
void pop_front(vector<ll> &v) { if (v.size() > 0) { v.erase(v.begin()); } }



vc<ll> lis(ll a[],ll n)
{
    vector<int> dp;
    vc<ll> ans;
    rep(i,0,n)
    {
        auto it=lower_bound(dp.begin(),dp.end(),a[i]);
        
        if(it==dp.end()) dp.push_back(a[i]);
        else *it = a[i];
        ans.pb(sz(dp));
    }
    return ans;
}
 

ll lcs(string a, string b, ll m, ll n)
{

    ll dp[m+1][n+1];
    memset(dp, 0, sizeof(dp)); 


    rep(i,0,m)
    {
        rep(j,0,n)
        {
            if (a[i]==b[j])
            {
               dp[i+1][j+1]=1+dp[i][j];
            }   
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[m][n];
}

bool ispal(ll n)
{
    string s=to_string(n);

    if(id3(s))
    {
        return true;
    }
    return false;
}

static bool cmp(string a,string b)
{
    ll n1=sz(a),n2=sz(b);

    if(a[n1-1]==b[0])
        return a<b;
    if(b[n2-1]==a[0])
        return b<a;
    if(a[0]==b[0])
    {
        if(sz(a)==1)
            return a<b ;
        else
            b<a;
    }
}

void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

void DFS(int u, vector<pair<int,int>> adj[],
                    vector<bool> &visited,int &c)
{
    visited[u] = true;
    c++;
    

    for (auto x:adj[u])
    {
        if(visited[x.ff]==false && x.ss==0)
        {
            DFS(x.ff, adj, visited, c);
        }
    }
    

    

}

void primeFactors(ll n, ll & ans)
{
    

    while (n % 2 == 0)
    {
        ans+=2;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        

        while (n % i == 0)
        {
            ans+=i;
            n = n/i;
        }
    }
 
    if (n > 2)
        ans+=n;
}

ll fac[1000010], inv[1000010], finv[1000010];

ll help(ll x, ll y)
{
    if(x<0 || y>x)
        return 0;
    return fac[x]*finv[y]%mod*finv[x-y]%mod;
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.ss<b.ss;
}

bool id9(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void cheating()
{
    fac[0]=inv[0]=inv[1]=finv[0]=finv[1]=1;
    rep(i,1,1000001)
    fac[i]=fac[i-1]*i%mod;
    rep(i,2,1000001)
    inv[i]=mod-mod/i*inv[mod%i]%mod;
    rep(i,2,1000001)
    finv[i]=finv[i-1]*inv[i]%mod;
}

bool ispal(string s, int a, int b)
{
    int i=a,j=b;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int count(string &s, int a, int b)
{
    if(a==b)
        return 0;
    if(a+1==b && s[a]==s[b])
        return 0;

    if(s[a]==s[b])
        return count(s,a+1,b-1);

    int i;
    for(i=a+1;i<b;i++)
    {
        if(s[i]==s[b])
            break;
    }

    int j;
    for(j=b;j>a;j--)
    {
        if(s[j]==s[a])
            break;
    }

    if(i-a < b-j)
    {
        swap(s[i],s[a]);
        return (i-a) + count(s,a+1,b-1);
    }
    else
    {
        swap(s[j],s[b]);
        return (b-j) + count(s,a+1,b-1);
    }

}

void id1(vll a, vll c, int l, int r, int &ans)
{
    if(r-l<10)
    {
        for(int i=l;i<=r;i++)
        {
            int cnt=0;
            for(int j=l;j<=r;j++)    
            {
                if(i!=j)
                {
                    cnt+=(abs(a[i]-a[j])*c[j]);
                }
            }
            ans=min(ans,cnt);
        }
        return;
    }

    int m=(l+r)>>1;
    int c1=0;
    for(int j=l;j<=r;j++)    
    {
        if(m!=j)
        {
            c1+=(abs(a[m]-a[j])*c[j]);
        }
    }

    int c2=0;
    m--;
    for(int j=l;j<=r;j++)    
    {
        if(m!=j)
        {
            c2+=(abs(a[m]-a[j])*c[j]);
        }
    }
    ans=min(ans,min(c1,c2));

    if(c1<c2)
    {
        id1(a,c,m,r,ans);
    }
    else
    {
        id1(a,c,l,m,ans);
    }
    return;
}

int id5(vector<int> &v, int val){
    int l = 0;
    int size = v.size();
    int r = size-1;
    int id6 = size;
    

    while(l<=r){
      int mid = l + (r - l) / 2;
      if(v[mid] < val){
        l = mid + 1;
    
      }
      else{
        r = mid - 1;
        id6 = mid;
      }
    }

    

    

    

    

    

    

    

    

    

    

    

    return id6;
}

int id8(vector<int> &v, int val){
    int l = 0;
    int size = v.size();
    int r = size-1;
    int id6 = size;
    while(l<=r){
        int mid = l + (r-l) / 2;
        if(v[mid] <= val){
            l = mid +1;
        }
        else{
            r = mid -1;
            id6 = mid;
        }
    }
    return (size-id6);
}































void solve()
{
    ll count=0,res=0,cnt=0,count0=0,count1=0,flag=0,flag1=0,zero=0,odd=0,even=0,sum=0,ans=0,ans1=0,pos=0,neg=0;
    
    ll n,k,r,c;
    cin>>n>>k>>r>>c;
    r--;
    c--;

    rep(i,0,n)
    {
        rep(j,0,n)
        {
            if((i+j)%k==(r+c)%k)
                cout<<'X';
            else
                cout<<'.';
        }
        cout<<endl;
    }
    


} 
    

    


    

    


    

    

    

    

 
    

    

    

    












 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    

    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    
    
    ll t=1;
    cin>>t;

    cheating();
    

    while(t--)
    {
        solve();
    }

    

    return 0;
}



