





using namespace std; 












 



 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;


 




 
typedef vector<ll> vi;
typedef set<ll> si;
typedef pair<ll, ll> pi;
typedef vector<vi> vvi;
typedef vector<pi> vp;
typedef set<pi> sp;
 





 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
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
 
 
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void id1(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} id1(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll id14(ll a, ll b) {ll arr[3]; id1(a, b, arr); return arr[0];} 

ll id3(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case 
vector<ll> sieve(ll n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, id3(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 








 










 
    






    








 
















bool isPalindrome(string S)
{
    

    

    string P = S;
 
    

    reverse(P.begin(), P.end());
 
    

    if (S == P) {
        

        return 1;
    }
    

    else {
        

        return 0;
    }
}
int id10(int n, int k)
{
    

    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    

    return id10(n - 1, k - 1)
           + id10(n - 1, k);
}
bool isPrime(long long n)
{
    

    if (n <= 1)
        return false;
  
    

    for (long long i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
bool id11(long long n)
{
    ll flag=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        return false;
    else
        return true;
} 
vector<long long> primes;
vector<char> id5(long long L, long long R) {
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
 
    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
const long long MAX_SIZE = 1000001;
 










vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
 
vector<ll> evenbit(vector<ll>v)
{
  vector<ll>a;
  for(ll i=0;a.size()<1000;i++)
  {
    

    if(__builtin_popcountll(i) & 1)
      continue;
    else
    a.pb(i);
  }
  return a;
}
void invertBits(int num)
{
    

    

    int x = log2(num) + 1;
 
    

    for (int i = 0; i < x; i++)
       num = (num ^ (1 << i));
  
    cout << num;
}
bool id8(vector<ll> v)
{
  ll n=v.size();
  ll cnt=0;
  for(ll i=0;i<n-1;i++)
  {
    if(v[i]>v[i+1])
      cnt++;
  }
  if(cnt>1)
    return false;
  else
    return true;
}
int id0(ll N, ll K, ll M)
{
 
 
 
    ll firstM;
 
    double y = (double)K * log10(N * 1.0);
 
 
    y = y - (ll)y;
 
    double temp = pow(10.0, y);
 
 
    firstM = temp * (1LL) * pow(10, M - 1);
    return firstM;
  }
int id7(int x)
{
    int i = 0;
    while (x) {
        x /= 10;
        i++;
    }
    return i;
}
ll modPower(ll a, ll b, ll M)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}  
ll id2(ll left, ll right)
{
    

    

    ll min_count =INT_MAX , num;
    for (int i = left; i <= right; ++i) {
        int temp = i, cnt = 0;
 
        

        

        while (temp) {
            if (temp & 1)
                ++cnt;
            temp >>= 1;
        }
 
        

        

        if (cnt < min_count) {
            min_count = cnt;
            num = i;
        }
    }
    return num;
}
int id6(int n)
{
   
  

  if (n % 4 == 0)
    return n;
 
  

  if (n % 4 == 1)
    return 1;
 
  

  if (n % 4 == 2)
    return n + 1;
 
  

  return 0;
}
 
int find(int x,ll a[],ll n)
{
    int ans=0;
    int d=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=x)
            d+=(x-a[i]);
        ans+=abs(d);
        x^=1;
    }
    return ans;
}
ll powerLL(ll x, ll n)
{
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}
 






ll powerStrings(string sa, string sb)
{
    

 
    ll a = 0, b = 0;
 
    

    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;
 
    

    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (sb[i] - '0')) % (MOD - 1);
 
    

    

    return powerLL(a, b);
}
 
 
bool id4(long long  n)
{
    for (long long  i = 1; i * i <= n; i++) {
 
        

        if ((n % i == 0) && (n / i == i)) {
            return true;
        }
    }
    return false;
}
bool id13(const pair<int,int> &a,
              const pair<int,int> &b)
{
        if(a.first < b.first) return true; 
        if(a.first == b.first) return a.second < b.second; 
        return false; 
    
}
bool id15(const pair<int,int> &a,
              const pair<int,int> &b)
{
        if(a.second < b.second) return true; 
        if(a.second == b.second) return a.first < b.first; 
        return false; 
    
}
 






















        

int lcs( string X, string Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}








int id9(string p)
{
 
    

    int bal = 0;
    int ans = 0;
 
    for (int i = 0; i < p.length(); ++i) {
 
        bal += p[i] == '<' ? 1 : -1;
 
        

        if (bal == -1) {
            ans += 1;
            bal += 1;
        }
    }
 
    return bal + ans;
}
bool ispossible(ll k,vector<long long>&v,long long n,long long h)
{
    for(ll i=0;i<n-1;i++)
    {
      h-=min(v[i+1]-v[i],k);
      if(h<=0)
        return true;
    }
    h-=k;
    return h<=0;
}
ll f(ll x)
{
    x++;
    while(x%10==0)x/=10;
    return x;
}
bool isdone(ll mid,ll a[],ll n,ll m)
{

ll sum=0;
    for(ll i=1;i<n;i++)
    {
       if(sum>=m)
       {
        return true;
       }
       sum+=min(mid,a[i]-a[i-1]);
    }
    sum+=mid;
    if(sum>=m)
        return true;
    else
        return false;
}
void id12(){ 
  ll n;
  cin>>n;
  ll a[n];
  map<ll,ll>m;
  set<ll>s;
  for(ll i=0;i<n;i++)
    cin>>a[i],m[a[i]]++,s.insert(a[i]);
  if(n==1)
  {
    if(a[0]==1)
    {
    cout<<"YES"<<endl;
    return;
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }
    
  }

  

  


  

  

    
  

  if(m[1]!=1)
  {
    cout<<"NO"<<endl;
    return;
  }

  for(ll i=0;i<n;i++)
  {
        ll diff=(a[(i+1)%n]-a[i]);
        if(diff>1)
        {
            cout<<"NO"<<endl;
            return;
        }

  }
  cout<<"YES"<<endl;
  
}

int main() {

  freopen("Error.txt", "w", stderr);

ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int t = 1;
  

  cin >> t;
  for (int i = 1; i <= t; i++) {
     

    id12();
  }
    
 return 0;
}
 