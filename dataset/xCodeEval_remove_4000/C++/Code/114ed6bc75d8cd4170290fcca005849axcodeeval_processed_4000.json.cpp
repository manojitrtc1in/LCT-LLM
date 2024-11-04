



















using namespace std;
using namespace chrono;




































struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id1);
    }
};








typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;



void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template<typename T,typename V>
using safe_map=unordered_map<T,V,custom_hash>;



template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void cin1(vector <T>& v) {fo (1,sz(v)-1) { cin>>v[i];} }
template <class T> void cout1(vector <T>& v) {fo (1,sz(v)-1) { cout<<v[i]<<" ";} }
template <class T,class V> void amax(T& a,V b){a = a>=b ? a : b ;}
template <class T,class V> void amin(T& a,V b){a = a<b ? a : b ;}


template<typename T1, typename T2> 

istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
 
template<typename T> 

istream& operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
 
template<typename T1, typename T2> 

ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> 

ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 


template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }






ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void id2(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} id2(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll id3(ll a, ll b) {ll arr[3]; id2(a, b, arr); return arr[0];} 

ll id0(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, id0(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

vector<int> prefixSum(vector<int> &A){vector<int> res(A.size());res[0]=A[0];for(int i=1;i<A.size();i++){res[i]=A[i]+res[i-1];} return res;}

class dsu
{
    vector<int> rank,parent;
     
    public:

    int distinctcomponents;
    
    dsu(int n)
    {
        distinctcomponents = n;
        rank.resize(n+1);
        parent.resize(n+1);
        iota(begin(parent),end(parent),0);
    }
    
    bool unioner(int a,int b)
    {
        a = findparent(a);
        b = findparent(b);
        
        if(a==b)
            return 0;
        
        distinctcomponents--;
        
        if(rank[a]>=rank[b])
        {
            if(rank[a]==rank[b])
                rank[a]++;

            parent[b]=a;
        }else if(rank[a]<rank[b])
        {
            parent[a]=b;
        }
        
        return 1;
    }
    
    int findparent(int a)
    {
        if(parent[a]==a)
            return a;
        
        return parent[a] = findparent(parent[a]);
    }
    
    bool isSingle()
    {
        return distinctcomponents==1;
    }
};

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool kmp(string &a,string &b)
{
    vll pre(b.size());

    ll i=1,j=0;

    while(i<b.size())
    {
        if(b[i]==b[j])
        {
            j++;
            pre[i++] = j;
        }else
        {
            if(j!=0)
            {
                j = pre[j-1];
            }else
            {
                pre[i++] = 0;
            }
        }
    }

    i=0;
    j=0;

    while(i<a.size())
    {
        if(a[i]==b[j])
        {
            i++,j++;
        }else
        {
            if(j!=0)
            {
                j = pre[j-1];
            }else
            {
                i++;
            }
        }

        if(j==b.size())
        {
            return 1;
        }
    }

    return 0;
}

void helper(vector<ll> &v1, ll n, vector<ll> &ans_here){
      ll k = sz(v1);
      ll min_here = INF;
      ll sum_here = 0;
      for(ll i = 1; i <= k; i++){
            ll x = i - 1;
            min_here = min(min_here, v1[i - 1]);
            sum_here = sum_here + v1[i - 1];
            ll p = sum_here - min_here;
            ll r = min_here * (n - x);
            ans_here.pb(p + r);
      }
}

void solve() {
    
    
            int n;
            cin >> n;
            vector<ll> dir1;
            vector<ll> dir2;
            for(int i = 0; i < n; i++){
                  ll a;
                  cin >> a;
                  if((i+1) & 1){
                        dir1.pb(a);
                  }else{
                        dir2.pb(a);
                  }
            }
            vector<ll> ans_up;
            vector<ll> ans_down;
            helper(dir1, n, ans_up);
            helper(dir2, n, ans_down);
            ll ans = INF;
            debug(mp(dir1, dir2));
            debug(mp(ans_up, ans_down));
            for(int i = 1; i <= sz(ans_up); i++){
                  int left = i - 2;
                  int here = i - 1;
                  int right = 1e7;
                  ll ans_left = ans_up[i - 1] + (left >= 0 ? ans_down[left] : INF);
                  ll ans_right = ans_up[i - 1] + (right < sz(ans_down) ? ans_down[right] : INF);
                  ll ans_here = ans_up[i - 1] + (here < sz(ans_down) ? ans_down[here] : INF);
                  debug(ans_left);
                  debug(ans_right);
                  debug(ans_here);
                  ans = min(ans, min(ans_left, min(ans_right, ans_here)));
                  debug(ans);
            }
            cout << ans << nline;
      

    
}


int32_t main() {

    freopen("Error.txt", "w", stderr);

    fastio();
    auto start1 = high_resolution_clock::now();
    ll t=1LL;
    cin>>t;

    while(t--)
    {
        solve();
        cout<<'\n';
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

    cerr << "Time: " << duration . count() / 1000 << endl;


    return 0;   
}

