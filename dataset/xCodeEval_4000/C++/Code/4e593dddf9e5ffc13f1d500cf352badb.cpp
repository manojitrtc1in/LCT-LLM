    
    #include<bits/stdc++.h>
    using namespace std;
    using namespace chrono;
    #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define MOD1 998244353
    #define MOD 1000000007
    #define PI 3.141592653589793238462
    #define INF 1e18

    #define nline "\n"
    #define py cout<<"Yes\n";
    #define pn cout<<"No\n";
    #define pyy cout<<"YES\n";
    #define pnn cout<<"NO\n";

    #define pb push_back
    #define ppb pop_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define all(x) x.begin(), x.end()
    #define fr(i,a,n) for(int i=a;i<n;i++)
    #define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
    #define fs(x) fixed<<setprecision(x)
    #define set_bits __builtin_popcount
    #define sz(x) (int)(x.size())
    #define mid(l,r)        (l+(r-l)/2)
    #define clr(x) memset(x, 0, sizeof(x))

    #define gc getchar_unlocked

    #define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)


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

    #ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x<<" "; _print(x); cerr << "\n";
    #else
    #define debug(x);
    #endif

    typedef long long ll;
    typedef unsigned long long  ull;
    typedef long double         ld;
    typedef pair<ll, ll>        pl;
    typedef pair <int,int>      pii;
    typedef vector<int>         vi;
    typedef vector<ll>          vl;
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



    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    #define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
    


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

    ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
    ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
    ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
    ll power(ll a,ll b){ll ans=1;while(b){if(b&1){ans=(ans*a*1LL);}a=(a*a*1LL);b>>=1;}return ans;}
    void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

    ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} 
    ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
    ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
    vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

    ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

    ll cmp(ll a,ll b){return a>b;}
    

    vector<ll> primeFactors(ll n){ vector<ll> factors;while (n % 2 == 0) {factors.push_back(2);n = n / 2;    }for (int i = 3; i <= sqrt(n); i = i + 2){while (n % i == 0){factors.push_back(i);n = n / i;}}if (n > 2)   factors.push_back(n);  return factors;}


    vector<ll> allFactors(ll n){vector<ll> factors;for(int i=1;i<=sqrt(n);i++){if(n%i==0){factors.push_back(i);if(n/i!=i)factors.push_back(n/i);    }}return factors;}
    long long maxsubarraysum(long long *array,long long n){long long best = 0, sum = 0;for (long long  k = 0; k < n; k++) {sum = max(array[k],sum+array[k]);best = max(best,sum);}return  best ;}
    void printBinary(int num){for(int i=10;i>=0;--i){cout<<((num>>i)&1);}cout<<endl;}
    int computeXOR(int n){if (n % 4 == 0)return n;if (n % 4 == 1)return 1;if (n % 4 == 2)return n + 1;return 0;}
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
    void manipulated_seive(int N) 
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


    vl primeFactors_sieve(ll a) 
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


    float log_a_to_base_b(ll a, ll b)
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
    ll gdcsum(ll n)
    {
        ll sum=0;
        ll n1=n;
        while(n1)
        {
            sum+=n1%10;
            n1/=10;
        }
        return gcd(sum,n);
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


    const int N=2e5+10;
    vector<int> dfs_vector;
    vector<bool> vis(N,0);
    void dfs(vector<int> graph[],int vertex)
    {  
        

        vis[vertex]=1;
        for(int child:graph[vertex])
        {   if(vis[child]==0)
            {
            
            dfs(graph,child);
            }
        }
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

        bool union_sets(ll a, ll b) {
            a = find_set(a);
            b = find_set(b);

            if (a == b) return false;

            if (siz[a] > siz[b]) swap(a, b);
            parent[a] = b;
            siz[b] += siz[a];

            components--;
            return true;
        }
    };
     


    vl tobinary(ll n)
    {
       vl t;
       while(n)
       {
        t.pb(n%2);
        n=n/2;
       }
       ll s=t.size();
       for(int i=s;i<30;i++)
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


    void PreSolve()
    {  
           

           

            ll n,q;
        cin>>n>>q;
        vl a(n);
        cin>>a;
        map<ll,ll>m;
        ll ans=0;
        for(int i=0;i<n;i++)
            m[i+1]=a[i];
        ans=vsum(a);
        ll flag=0;
        ll last=0;
        debug(q)
        while(q--)
        {
            ll t;
            cin>>t;
            
            if(t==1)
            {
                ll index,val;
                cin>>index>>val;
                

                

                

                

                

                

                

                {
                    ans-=(m[index]==0)?(last):m[index];
                    m[index]=val;
                    ans+=val;
                }
            }
 
            else
            {
                

                ll val;
                cin>>val;
                ans=val*n;
                last=val;
                m.clear();
            }
            cout<<ans<<nline;
        }
 
       
    }
 
 

    
    void solve()
    {
      
    }
    


    
           
    int main()  
    {
        fastio();
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
        #endif
        auto start1 = high_resolution_clock::now();
        ll tc=1;
        

        PreSolve();
     
        for(int i=1;i<=tc;i++)
        { 
            

          
          

          solve();
        }
      
        auto stop1 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop1 - start1);
        #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration.count() / 1000 << endl;
        #endif
        return 0;
    }



       

    