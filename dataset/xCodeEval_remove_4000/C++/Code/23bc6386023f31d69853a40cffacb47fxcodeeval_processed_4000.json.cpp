














using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;


typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef pair<ll, p64> tp;
ll MOD = 1e9 + 7;





























typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;




























  cout << item << " " << y << " " << z << " " << zz << endl;

const int N = 1e5 + 10;
template <typename T> void print(const T &t) { std::cout << t; }

template <class T> void print(vector<T> v) {
  for (T i : v) {
    printe(i);
  }
  println();
}
template <class T> void print(set<T> v) {
  for (T i : v) {
    printe(i);
  }
  println();
}

template <class T, class V> void print(map<T, V> v) {
  for (auto i : v) {
    printe(i)
  }
  println();
}
ll maxi=300000;

typedef unsigned long long ull;
typedef long double lld;

void print(ll t) { cout << t << ln; }
void print(int t) { cout << t << ln; }
void print(string t) { cout << t << ln; }
void print(char t) { cout << t << ln; }

void print(ll a, ll b) { cout << a << " " << b << ln; }
void print(int a, int b) { cout << a << " " << b << ln; }
void print(string a, string b) { cout << a << " " << b << ln; }
void print(char a, char b) { cout << a << " " << b << ln; }
void print(string a, ll b) { cout << a << " " << b << ln; }
void print(ll a, string b) { cout << a << " " << b << ln; }

void print(ll a, ll b, ll c) { cout << a << " " << b << " " << c << ln; }
void print(int a, int b, int c) { cout << a << " " << b << " " << c << ln; }
void print(string a, string b, string c) {
  cout << a << " " << b << " " << c << ln;
}
void print(char a, char b, char c) { cout << a << " " << b << " " << c << ln; }
void print(ll a, string b, ll c) { cout << a << " " << b << " " << c << ln; }
void print(ll a, string b, string c) {
  cout << a << " " << b << " " << c << ln;
}
void print(string a, ll b, ll c) { cout << a << " " << b << " " << c << ln; }
void print(string a, ll b, string c) {
  cout << a << " " << b << " " << c << ln;
}
void print(string a, string b, ll c) {
  cout << a << " " << b << " " << c << ln;
}



  cerr << 
  _print(x);                                                                   \
  cerr << ln;




void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.fi);
  cerr << ",";
  _print(p.se);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

void yes() { cout << "YES\n"; }

void no() { cout << "NO\n"; }


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


void solve()
{
  ll n;
  cin>>n;
  v64 v(n+1);
  v64 arr[n+2];
  forsn(i,1,n+1) cin>>v[i];
  v64 dp(n+2);
  for(int i=2;i<=n+1;++i) dp[i]=0;
  dp[0]=1;
  dp[1]=1;
  forsn(i,1,n+1)
  {
    if((v[i])<=(n-i)) arr[i].pb(v[i]+i);
    if(i>=(1+v[i])) arr[i-v[i]].pb(i);
  }
  forsn(i,1,n+1)
  {
    if(!dp[i]) 
    {   
        continue;
    }
    for(auto k:arr[i])
    {
        dp[k+1]=1;
    }
  }
  ll ans=dp[n+1];
  if(ans==1) yes();
  else no();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  

  ll T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}





