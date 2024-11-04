




using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double lld;
typedef complex<lld> cd;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<lld,lld> pd;
typedef vector<int> vi;
typedef vector<lld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>>  vvvl;          
typedef vector<cd> vcd;
typedef vector<cd> vcd;

const ll MOD = 1000000007;














template<class T,class V> void _print(pair<T,V> p);
template<class T>void _print(set<T> v);
template<class T>void _print(multiset<T> v) ;
template<class T,class V>void _print(map<T, V> v);
template<class T>void _print(vector<T> v);
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod=MOD) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void id1(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} id1(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll id2(ll a, ll b) {ll arr[3]; id1(a, b, arr); return arr[0];} 

ll id0(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case 
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, id0(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

void precision(int a) {cout << setprecision(a) << fixed;}


void solve()
{
    int i,j;
    int m=-1;
    unordered_map<int,int> val;
    set<int> s;
    int n;
    cin>>n;
    vi a(n);
    fi(i,0,n){
        cin>>a[i];
        m=max(a[i],m);
    }
    vvi g(m+2,{0});
    vi sol(10000,0);
    val[0]=0;
    sol[0]=1;
    int cnt=1;
    fi(i,0,n){
        trav(e,g[a[i]]){
            int k=e^a[i];
            if(sol[k]==0){
                fi(j,a[i]+1,m+2){
                    g[j].push_back(k);
                }
                sol[k]=1;
                cnt++;
                val[k]=a[i]+1;
            }
            else{
                fi(j,a[i]+1,val[k]){
                    g[j].push_back(k);
                }
                val[k]=min(val[k],a[i]+1);
            }
        }
        g[a[i]]={};
    }
    cout<<cnt<<nl;
    fi(i,0,10000){
        if(sol[i]==1){
            cout<<i<<sp;
        }
    }
    cout<<nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precision(9);
    int t=1;
    

    while (t--)
    {     
        solve();
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
    return 0;
}


























































































































































































































































































































































































































































































































































































































