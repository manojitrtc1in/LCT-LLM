


















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

class DSU
{
    public:
    int findParent(int node,vector<int>& par)
    {
        if(par[node]==node)return node;
        return par[node]=findParent(par[node],par);
    }
    void Union(int u,int v,vector<int> &size,vector<int> &par)
    {
        int pu=findParent(u,par);
        int pv=findParent(v,par);
        if(pu==pv)return;
        if(size[pu]<=size[pv])
        {
            par[pu]=pv;
            size[pv]++;
        }
        else
        {
            par[pv]=pu;
            size[pu]++;
        }
    }
    bool isConnected(int u,int v,vector<int> &par)
    {
        int pu=findParent(u,par);
        int pv=findParent(v,par);
        if(pu==pv)return 1;
        return 0;
    }
};
ll find(ll x,vi &parent)
{
    if (parent[x] != x)
    {
 
        parent[x] = find(parent[x],parent);
    }
    return parent[x];
}
void Union(ll x,ll y,vi &parent,vi &rank)
{
 
    ll xset = find(x,parent);
    ll yset = find(y,parent);
 
    if (xset == yset)
        return;
 
    if (rank[xset]< rank[yset])
    {
        parent[xset] = yset;
    }
    else if (rank[xset] > rank[yset])
    {
        parent[yset] = xset;
    }
 
    else
    {
        parent[yset] = xset;
        rank[xset] = rank[xset] + 1;
    }
}

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




void solve() {
    
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];




    }

    vector<int> temp=v;
    sort(temp.begin(),temp.end());
    if(temp==v)
    {    cout<<0;
    return;
    }


    for(int i=0;i<n/2;i++)
    {
        if(v[0]>n/2 && v[i]<=n/2)
            {
                cout<<-1;
                return;
            }
        if(v[0]<=n/2 && v[i]>n/2)
            {
                cout<<-1;
                return;
            }





    }


int arr[n]={0};
for(int i=0;i<n;i=i+2)
{
    if(abs(v[i]-v[i+1])!=1)
    {
        cout<<-1;
        return;
    }

    else
    {
        if(arr[i]==1 || arr[i+1]==1)
        {
            cout<<-1;
            return;
        }
        arr[i]=1;
        arr[i+1]=1;


    }



}

for(int i=1;i<=log2(n);i++)
{

    for(int j=0;j<n;)
    {
        int temp=v[j];
        for(int a=j+1;a<j+pow(2,i);a++)
        {
            if(abs(v[a]-temp)>=pow(2,i))
               { 
                cout<<-1;
                return;
            }
        }





        j+=pow(2,i);
    }





}


long long op=0;

for(int i=1;i<=log2(n);i++)
{
    for(int j=0;j<n;)
    {
        if(v[j]>v[j+pow(2,i-1)])
           {
            
            op++;
           }






        




        j+=pow(2,i);
    }





}


cout<<op;



    
}


int32_t main() {

    freopen("Error.txt", "w", stderr);

    fastio();
    auto start1 = high_resolution_clock::now();
    ll t=1LL;
    cin>>t;
    
    ll counter = 1ll;

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

