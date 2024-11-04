
 
using namespace std;
 




 

typedef long long ll;
typedef unsigned long long ull;
 
 





 

 







 
























 






typedef vector<int> vi;
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;
 





inline bool cmp(pll a,pll b){ if(a.ss == b.ss) return a.ff < b.ff; return a.ss < b.ss; }
 

 

int drx[8] = {-2,-2,-1,-1,1,1,2,2};
int dcy[8] = {-1,1,-2,2,-2,2,-1,1};
int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, -1, 0, 1 };
 







template <class T> inline T gcd(T a,T b){if(b == 0)return a; return gcd(b, a % b);}
template <class T> inline T lcm(T a,T b){return a * b / gcd<T>(a, b);}
template <class T> inline T power(T b,T p){ll ans = 1;while(p--) ans *= b; return ans;}



void __print(ll x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}









mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rng(0,1);


ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll id5(ll a,ll b,ll& x,ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = id5(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool isPrime(ll n){
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
bool id1(ll n) { 
   if(n==0) 
   return false; 
   return (((ll)ceil(log2(n)) == (ll)floor(log2(n)))+1); 
}
 
ll powm(ll a,ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
ll divide(ll a,ll b) {
    return (a % mod) * powm(b, mod - 2) % mod;
}
ll mul(ll a,ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
 
ll add(ll a,ll b) {
    return (a % mod + b % mod) % mod;
}
ll Totfun(ll n){
    ll z=n;
    if(n%2==0){
        while(n%2==0){
            n/=2;
        }
        z/=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        if(isPrime(i)&&n%i==0){
          while(n%i==0){
            n/=i;
          }
        z-=z/i;  
        }
    }
    if(n>1){
        z-=z/n;
    }
    return z;
}
ll fact[mx];
ll nCr(ll n,ll r){
    if(r>n||r<0) return 0;
    ll z=fact[n];
    z=mul(z,powm(fact[n-r],mod-2));
    z=mul(z,powm(fact[r],mod-2));
    return z;
}


 

 int id0(int n)
{
    

    

    

    

    

    

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        

        

        if (prime[p] == true)
        {
            

            

            

            

            

            

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int ans;
    

    for (int p = 2; p <= n; p++)
        if (prime[p]){
            ans=p;
            break;
        }
    
    return ans;
}
 
int powerof(int n , int m){
    int count=0;
    while(n%m==0){
        count++;
        n=n/m;
    }
    return count;
}
ll factorial(ll n){
    if(n==0 || n==1) return 1;
    ll ans=n*factorial(n-1);
    return ans;
}
vector<ll> id2(ll n){
    vector<ll>v;
    for(ll i=2; i<=n; i++){
        if(isPrime(i)){
            v.pb(i);
        }
    }
    return v;
}
vector<ll> primeFactors(ll n)
{
    vector<ll>v;
    
    while (n % 2 == 0)
    {
        v.pb(2);
        n = n/2;
    }
 
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        
        while (n % i == 0)
        {
            v.pb(i);
            n = n/i;
        }
    }
 
    
    if (n > 2)
        v.pb(n);

    return v;
}
int id3(int h) {
    

    ll dp[h + 1]; 
    

    dp[0] = dp[1] = 1; 
    for(int i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
    } 
    return dp[h];
}

bool ispal(string s){
    bool flag=true;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]!=s[n-1-i]) {
            flag=false;
            break;
        } 
    }
    return flag;
}



int min(vector<int> a, int b){
    int as=a.size();
    return min(as,b);
}

void addedge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}
int id4(int n, int k)
{
    

    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    

    return id4(n - 1, k - 1)
           + id4(n - 1, k);
}

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int sorted(vector<int> a,int n){
 
  for (int i = 0; i < n-1; i++) {
    if(a[i]<=a[i+1]){
      continue;
    }
    else{
      return 0;
    }
  }
  return 1;
}
const int N=1e5+5;
int a[N], b[N];
int main(){
    
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    
 
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);
   cout.tie(NULL);
   cout<<fixed<<setprecision(20);
   ll test=1;
   
   cin>>test; 
   while(test--){
      int a,b,c;
      cin>>a>>b>>c;
      if(a>b){
          int t=b;
          b=a;
          a=t;
      }
      int n=2*(b-a);
      if(c>n or n<b) one
      else{
         if(c<b-a+1){
             cout<<b-a+c;
         }
         if(c>b-a+1){
            cout<<a-b+c;
         }
         if(c==b-a+1) cout<<1;

         en
      }
   }

    printf("\nRun Time -> %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

   return 0;
}

  	 			   	  	    	  	 	   			