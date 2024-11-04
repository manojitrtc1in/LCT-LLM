


#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp" 
#define   ll                                long long int
#define   ull                               unsigned long long int
#define   cint                              const int
#define   fo(i,a,b)                         for(int i=a;i<b;++i)
#define   rfo(i,a,b)                        for(int i=a-1;i>=b;--i)
#define   foll(i,a,b)                       for(ll i = a; i < b; ++i)
#define   rfoll(i,a,b)                      for(ll i = a-1; i >= b; --i)
#define   sqr(x)                            (x)*(x)
#define   ii                                pair<int,int>
#define   vLL                               vector<ll>
#define   vi                                vector<int>
#define   vS                                vector<string>
#define   vstr                              vector<string>
#define   pb                                push_back
#define   ppb                               pop_back
#define   eb                                emplace_back
#define   lbd                               lower_bound
#define   ubd                               upper_bound
#define   ins                               insert
#define   setint                            set<int>
#define   setlong                           set<ll>
#define   setchar                           set<char>
#define   setstring                         set<string>
#define   multisetint                       multiset<int>
#define   multisetlong                      multiset<ll>
#define   multisetchar                      multiset<char>
#define   multisetstring                    multiset<string>
#define   vectorint                         vector<int>
#define   vectorlong                        vector<ll>
#define   vectorchar                        vector<char>
#define   vectorstring                      vector<string>
#define   vectorpair_int                    vector< ii >
#define   vectorpair_long                   vector< pair<ll, ll> >
#define   que_max                           priority_queue <int>
#define   que_min                           priority_queue <int, vi, greater<int> >
#define   umap                              unordered_map
#define   fastio                            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);
#define   decimal(k)                        fixed<<setprecision(k)
#define   PI                                3.14159265359
#define   ff                                first
#define   ss                                second
#define   all(V)                            (V).begin(),(V).end()
#define   alla(a,n)                         a, a+n
#define   sz(v)                             (ll)v.size()
#define   szz(a,n)                          sizeof(a)/(n)
#define   SORT(v)                           sort(all(v))
#define   REV                               reverse
#define   MAX(v)                            *max_element(all(v))
#define   MIN(v)                            *min_element(all(v))
#define   MAXPOS(v)                         max_element(all(v)) - (v).begin()
#define   MINPOS(v)                         min_element(all(v)) - (v).begin()
#define   LBD(v,element)                    *lower_bound(all(v),element)
#define   UBD(v,element)                    *upper_bound(all(v),element)
#define   LBDPOS(v,element)                 lower_bound(all(v),element) -(v).begin()
#define   UBDPOS(v,element)                 upper_bound(all(v),element) -(v).begin()
#define   UNIQUE(v)                         sort(all(v)); v.erase(unique(v.begin(),v.end()),v.end())
#define   mem1(a)                           memset(a,-1,sizeof(a));
#define   mem0(a)                           memset(a,0,sizeof(a));
#define   mymax                             1000000000000000100
#define   mymin                             -1000000001
#define   bitcount                          __builtin_popcount
#define   gcd                               __gcd
#define   MOD                               (ll)1000000007
#define   INF                               2147483646
#define   TEST(t)                           int tc; cin>>tc; fo(t,1,tc+1)
#define   YES                               cout << "YES\n"
#define   NO                                cout << "NO\n"
#define   Yes                               cout << "Yes\n"
#define   No                                cout << "No\n"
#define   MINUS_ONE                         cout << "-1\n"
#define   TS                                to_string
#define   len(s)                            (s).length()
#define   line                              cout << '\n';
#define   endl                              '\n'
#define   open                              {
#define   close                             }
#define   goog(tno)                         cout <<"Case #" << tno << ": "
#define   np2(S)                            ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" = "; _print(x); cout << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}


#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        

    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif


ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll power(ll a,ll b,ll m){            

    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll power(ll a,ll b){            

    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll mod_inverse(ll x,ll m){
    return power(x,m-2,m);
}

ll fact(ll n){
    ll f = 1;
    for(ll i = n+1;--i;)
    {
        f = f*i;
    }
    return f;
}

ll factmod(ll n, ll m)
{
    ll f = 1;
    for(ll i = n+1;--i;)
    {
        f = ((f%m)*(i%m))%m;
    }
    return f;
}

ll ncr(ll n, ll r) {
    if(r > n - r) r = n - r;
    ll ans = 1;
    ll i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int isPal(string &s){
    int len=s.size();
    int flag=1;
    for(int i=0;i<len;++i){
        if(s[i]!=s[len-i-1]){
            flag=0;
            break;
        }
    }
    return flag;
}

ll isPrime(ll n)
{
    if(n < 2)
        return 0;
    for(ll i = 2; i*i <= n; i++)
        if(n%i == 0)
            return 0;
    return 1;
}

ll sumD(ll n)
{
    if(n == 0)
        return 0;
    return (n%10) + sumD(n/10);
}

vLL pfactor(ll n)
{
    vLL v;
    while (n % 2 == 0)
    {
        v.pb(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
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

void arrinp(int *a, int n)
{
    fo(i,0,n)
        cin >> a[i];
}

void arrinp(ll *a, int n)
{
    fo(i,0,n)
        cin >> a[i];
}

ll asum(int *a, int st, int ed)
{
    ll sum = 0;
    fo(i,st,ed)
        sum += a[i];
    return sum;
}

ll vsum(vi &a, int st, int ed)
{
    ll sum = 0;
    fo(i,st,ed)
        sum += a[i];
    return sum;
}

int agcd(int *arr, int st, int ed)
{
    int result = arr[st];
    for (int i = st+1; i <ed; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

ll alcm(int *arr, int st, int ed)
{
    ll ans = arr[st];


    for (int i = st+1; i <ed; i++)
        ans = (((arr[i] * ans)) /
                (gcd((ll)arr[i], ans)));

    return ans;
}
int vgcd(vi &arr, int st, int ed)
{
    int result = arr[st];
    for (int i = st+1; i <ed; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

ll vlcm(vLL &arr, int st, int ed)
{
    ll ans = arr[st];


    for (int i = st+1; i <ed; i++)
        ans = (((arr[i] * ans)) /
                (gcd((ll)arr[i], ans)));

    return ans;
}

double median(int a[], int n)
{
    if (n % 2 != 0)
        return (double)a[n / 2];
 
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

vLL divisor(ll n)
{
    vLL v;
    for (int i = 1; i*i < n; i++) {
        if (n % i == 0)
            v.pb(i);
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0)
            v.pb(n / i);
    }
    return v;

}

vLL divpair(ll n)
{
    vLL v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                v.pb(i);

            else
                v.pb(i), v.pb(n/i);
        }
    }
    return v;
}

ll countDivisor(ll n)
{
     ll i,ans=0;

    for (i=1; i*i<=n; i++)
    {
        if (n % i == 0)
        {
            if (i*i == n)
                ++ans;
            else
                ans += 2;
        }
    }

    return ans;
}

int mostfreq(int *arr, int n)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    int max_count = 0, res = -1;
    for (auto &i : hash) {
        if (max_count <= i.second) {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}

ll mostfreq(vLL &arr)
{
    int n = sz(arr);
    unordered_map<ll, ll> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    ll max_count = 0, res = -1;
    for (auto &i : hash) {
        if (max_count <= i.second) {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}

ll kadane(int *a, int n)
{
    ll ans=0,curr=0;
    for(int i=0;i<n;i++)
    {
        curr= curr+a[i];
        curr = max(0LL,curr);
        ans=max(ans,curr);
    }
    return ans;
}

vLL arrayIntersection(int *arr1, int *arr2, int m, int n)
{
    vLL v;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            v.pb(arr2[j]);
            i++;
            j++;
        }
    }
    return v;
}

void leftRotate(int *arr, int d, int n)
{
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        int temp = arr[i];
        int j = i;

        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

vi z_algo(string &s)
{
    int n=s.size();
    vi z(n);
    for(int i=1,l=0,r=0;i<n;i++)
    {
        if(i<=r)
            z[i]=min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            z[i]++;
        if(i+z[i]-1>r)
            l=i, r=i+z[i]-1;
    }
    return z;
}

int phi(int n)
{
    int res = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            res/=i;
            res *= (i-1);
            while(n%i == 0)
                n/=i;
        }
    }
    if(n>1)
        res/=n, res *= (n-1);
    return res;
}

vi dectobin(int n)
{
    int l = floor(log2(n))+1;
    vi bin(l);
    rfo(i,l,0)
        bin[i] = (!!(n & (1 << i)));
    reverse(all(bin));
    return bin;
}

int rrr(int a, int b) { return a + rand() % (b - a + 1); }
bool ispow2(ll n){ return !(n & (n-1)); }
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
bool notgate(ll n) { return not (n); }
string fileName(string s1,string s2) { return s1+=s2; }
ll binaryLength(ll n)
{
    return (ll)log2(n)+1;
}

int getSum(int *BITree, int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int *BITree, int n, int index, int val)
{
    while (index <= n)
    {
    BITree[index] += val;

    index += index & (-index);
    }
}

void convert(int *arr, int n)
{
    int temp[n];
    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
    for (int i=0; i<n; i++)
    {
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}

int inversion(int *arr, int n)
{
    int invcount = 0;

    convert(arr, n);
    int BIT[n+1];
    for (int i=1; i<=n; i++)
        BIT[i] = 0;
    for (int i=n-1; i>=0; i--)
    {
        invcount += getSum(BIT, arr[i]-1);
        updateBIT(BIT, n, arr[i], 1);
    }

    return invcount;
}

vectorstring split(string &s, string del = " ")
{
    int start = 0;
    int end = s.find(del);
    vectorstring vs;
    while (end != -1) {
        vs.pb(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    vs.pb(s.substr(start, end - start));
    return vs;
}

ull highestPowerof2(ull x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}

map<ll,ll> FIBO;
ll fastfibo(ll n){
    FIBO[0] = FIBO[1] = 1;
    if(FIBO.count(n)){
        return FIBO[n];
    }
    ll k=n/2;
    if (n%2==0) { 

        return FIBO[n] = (fastfibo(k)*fastfibo(k) + fastfibo(k-1)*fastfibo(k-1)) % MOD;
    } else { 

        return FIBO[n] = (fastfibo(k)*fastfibo(k+1) + fastfibo(k-1)*fastfibo(k)) % MOD;
    }

}






        



bool hasTestCase = 1;
void solve_(int tcc = 1)
{
	ll n,m;
    cin>>n>>m;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<((i%4<=1)!=(j%4<=1))<<" ";
        }
        line;
    }












    
    





}


bool fileIO = 1;
int32_t main()
{
    fastio;

    if(fileIO){
        #ifndef ONLINE_JUDGE
            string directory = "/home/bibhash/Desktop/in-out/";
            string inputfile = "input.txt";
            string outputfile = "output.txt";
            freopen(fileName(directory,inputfile).c_str(), "r", stdin);
            freopen(fileName(directory,outputfile).c_str(),"w", stdout);
        #endif
    }

    






    if(hasTestCase)
    {
        TEST(tcc)
        {
            solve_(tcc);
        }
    }
    else
    {
        solve_();
    }
    cerr << "[Run Time " << tick() << "s]" << "\n\n";
    return 0;


}



