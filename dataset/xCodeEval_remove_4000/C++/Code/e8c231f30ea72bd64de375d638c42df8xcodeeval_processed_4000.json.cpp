 

using namespace std;
using namespace chrono;


































template<typename F, typename S>
istream& operator >>(istream& istream, pair<F, S>& p) 
{
    cin >> p.first >> p.second;
    return istream;
}
 
template<typename T>
istream& operator >>(istream& istream, vector<T>& v) 
{
    for(auto& element : v) 
    {
        cin >> element;
    }
    return istream;
}
template<typename F, typename S>
ostream& operator <<(ostream& ostream, pair<F, S>& p) 
{
    cout << p.first << " " << p.second;
    return ostream;
}
 
template<typename T>
ostream& operator <<(ostream& ostream, vector<T>& v) 
{
    for(auto& element : v) 
    {
        cout << element << " ";
    }
    return ostream;
}
 
template<typename T>
ostream& operator <<(ostream& ostream, vector<vector<T>>& v) 
{
    for(auto& row : v) 
    {
        for(auto& cell : row) 
        {
            cout << cell << " ";
        }
        cout << "\n";
    }
    return ostream;
}


template<typename T_vector>
void output(const T_vector &v, bool add_one = false, int start = -1, int end = -1) 
{
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
} 







typedef long long ll;
typedef unsigned long long  ull;
typedef long double         ld;
typedef pair<ll, ll>        pl;
typedef pair <int,int>      pii;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<string>      vs;
typedef vector<pii>         vpii;
typedef vector<pl>          vpl;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;
typedef priority_queue<int, vector<int>, greater<int>>  min_heap32;
typedef priority_queue<ll, vector<ll>, greater<ll>>     min_heap64;
typedef priority_queue<int>                             max_heap32;
typedef priority_queue<ll>                              max_heap64;
typedef unordered_map<int, int>                         umap32;
typedef unordered_map<ll, ll>                           umap64;





using namespace __gnu_pbds;






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
template <class T> void _print(vector <T> v) {cerr << "["; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}


template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "["; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll power(ll a,ll b){ll ans=1;while(b){if(b&1){ans=(ans*a*1LL);}a=(a*a*1LL);b>>=1;}return ans;}
void id1(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} id1(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll id9(ll a, ll b) {ll arr[3]; id1(a, b, arr); return arr[0];} 
ll id3(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, id3(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

ll cmp(ll a,ll b){return a>b;}
int isPrime(int N){if(N<2 || (!(N&1) && N!=2))return 0;for(int i=3; i*i<=N; i+=2){if(!(N%i))return 0;}return 1;}
vector<ll> primeFactors(ll n){ vector<ll> factors;while (n % 2 == 0) {factors.push_back(2);n = n / 2;    }for (int i = 3; i <= sqrt(n); i = i + 2){while (n % i == 0){factors.push_back(i);n = n / i;}}if (n > 2)   factors.push_back(n);  return factors;}


vector<ll> id2(ll n){vector<ll> factors;for(int i=1;i<=sqrt(n);i++){if(n%i==0){factors.push_back(i);if(n/i!=i)factors.push_back(n/i);    }}return factors;}
long long id0(vl array,long long n){long long best = 0, sum = 0;for (long long  k = 0; k < n; k++) {sum = max(array[k],sum+array[k]);best = max(best,sum);}return  best ;}
void printBinary(int num){for(int i=10;i>=0;--i){cout<<((num>>i)&1);}cout<<endl;}
int id4(int n){if (n % 4 == 0)return n;if (n % 4 == 1)return 1;if (n % 4 == 2)return n + 1;return 0;}
template<typename T>
ll vsum(vector<T> v){
    ll s=0;
    for(int i=0;i<v.size();i++)
        s+=v[i];
    return s;
}

const int MAX_SIZE = 2800001;
vector<int>isprime(MAX_SIZE , true);
vector<int> idx(MAX_SIZE);
vector<int> prime;
vector<int>SPF(MAX_SIZE);
void id8(int N) 
{
    isprime[0] = isprime[1] = false ;
    for (int i = 2; i < N ; i++) 
    {
        if (isprime[i]) 
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) 
        {
            isprime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j] ;
        }
    }
    for (int i = 0; i < (int)prime.size(); i++) 
    {
        idx[prime[i]] = i + 1;
    }
}


vl id5(ll a) 
{
    vl p;
    ll count1 = 0;
    for (auto i : prime) {
        if (i > a)
            break;
        if (a % i == 0) {
            while (a % i == 0) {
                count1++;
                p.pb(i);
                a /= i;
            }
        }
    }
    debug(p)
return p;
}


float id6(ll a, ll b)
{
    return (float)log(a) / (float)log(b);
}


long long sum(ll n)
{
    return n*(n+1)/2;
}
vector<bool> tob(int n)
{  vector<bool> a;
   while(n)
   {
      a.pb(n%2);
      n/=2;
   }
   reverse(all(a));
   return a;
}

string tostring(ll n)
{
    string s;
    while(n)
    {
        s+=(n%10)+'0';
  n/=10;
    }
    reverse(all(s));
    return s;
}

class DSU {
public:
    ll n, components;
    vector<ll> parent, siz;

    DSU(ll n) {
        this->n = n;
        for (ll i = 0; i < n; ++i) {
            parent.push_back(i);
            siz.push_back(1);
        }
        components = n;
    }

    ll find_set(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]); 

    }

    ll getSiz(ll node) {
        return siz[find_set(node)];
    }

    set<ll> getParents() {
        set<ll> s;
        for (ll i = 0; i < n; i++) s.insert(find_set(i));
        return s;
    }

    void union_sets(ll a, ll b) 
    {
        a = find_set(a);
        b = find_set(b);

        if (a == b) return ;

        if (siz[a] > siz[b]) swap(a, b);
        parent[a] = b;
        siz[b] += siz[a];

        components--;
        return ;
    }
};


vl id7(ll n)
{
   vl t;
   while(n)
   {
    t.pb(n%2);
    n=n/2;
   }
   ll s=t.size();
   for(int i=s;i<32;i++)
   {
    t.pb(0);
   }
   reverse(all(t));
   

   return t;
}
void presum(vl &a)
{
    ll n=a.size();
    for(int i=1;i<n;i++)
    {
      a[i]+=a[i-1];
    }
}
void presolve()
{
  

}




ll n;
bool dfs(int c,vector<pair<ll,ll>> g[],vi &vis,vi &pvis)
{
    bool x=0;
    vis[c]=1;
    pvis[c]=1;
    

    for(auto child:g[c])
    {
        if(pvis[child.ff]) {return 1;}
        if(!vis[child.ff])
        {
            x|=dfs(child.ff,g,vis,pvis);
        }
    }
    pvis[c]=0;
    

    

    return x;
}
bool cycle(vector<pair<ll,ll>> g[],vi &vis,vi &pvis)
{
    bool x=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,g,vis,pvis))
                return 1;
        }
    }
    return 0;
}
ll hell(int c,vpl g[],vl &ans)
{
    if(ans[c]!=-1) return ans[c];
    for(auto i:g[c])
    {
        ans[c]=max(ans[c],i.ss+max(0LL,hell(i.ff,g,ans)));
    }
    return ans[c];
}
void solve()
{
  cin>>n;

  int N=n+20;
  vi vis(N,0),pvis(N,0);
  vl dp(N,-1);
  vector<pair<ll,ll>> g[n+1];
  ll ans=0;
  for(int i=0;i<n;i++)
  {
    ll t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        ll x;
        cin>>x;
        if(x>i+1)
        {
            g[i+1].pb({x,1});
        }
        else
        {
            g[i+1].pb({x,0});
        }
    }
    

  }
  if(cycle(g,vis,pvis))
  {
    cout<<-1<<nl;
    return;
  }
  for(int i=1;i<=n;i++)
  {
    

    ans=max(ans,hell(i,g,dp));
  }
  cout<<ans+1<<nl;
  


}

       
int main()  
{
    fastio();
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    
    auto start1 = high_resolution_clock::now();
    int tc=1;
    cin>>tc;    
    

    for(int i=1;i<=tc;i++)
    { 
        

        solve();
    }   

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    
    cerr << "Time: " << duration.count() / 1000 << endl;
    
    return 0;
}



   
