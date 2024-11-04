












ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0)










using namespace std;






int spf[MAXN];


typedef unsigned long long ull;
typedef long double lld;










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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}






const vector<pair<ll,ll>> coords{{1,0},{0,1},{0,-1},{-1,0}};
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
            }
        }
    }
    ll lis(vector<ll> const& a) {
        ll n = a.size();

        vector<ll> d(n+1, INF);
        d[0] = -INF;

        for (ll i = 0; i < n; i++) {
            ll j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
            if (d[j-1] <= a[i] && a[i] <= d[j])
                d[j] = a[i];
        }

        ll ans = 0;
        for (ll i = 0; i <= n; i++) {
            if (d[i] < INF)
                ans = i;
        }
        return ans;
    }
    vector<ll> getFact(ll v,vector<ll>&pr)
    {
        vector<ll> ret;
        ll r = v;
        for(auto x:pr){
            if(x*x>v) break;
            while(r%x==0){ 
                ret.pb(x);
                r/=x;
            }
        }
        

        if(r>1) ret.pb(r);
        return ret;
    }
    ll gcd(ll a, ll b)
    {
        if (b > a)
        {
            return gcd(b, a);
        }
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    ll expo(ll a, ll b, ll mod)
    {
        ll res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }
    void id0(ll a, ll b, ll *v)
    {
        if (b == 0)
        {
            v[0] = 1;
            v[1] = 0;
            v[2] = a;
            return;
        }
        id0(b, a % b, v);
        ll x = v[1];
        v[1] = v[0] - v[1] * (a / b);
        v[0] = x;
        return;
} 

ll id7(ll a, ll b)
{
    ll arr[3];
    id0(a, b, arr);
    return arr[0];
} 

ll id2(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case 
vector<ll> sieve(ll n)
{
    ll *arr = new ll[n + 1]();
    vector<ll> vect;
    for (ll i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (ll j = (i * i); j <= n; j += i)
                arr[j] = 1;
        }
        return vect;
    }
    set<ll> sieves(ll n)
    {
        ll *arr = new ll[n + 1]();
        set<ll> s;
        for (ll i = 2; i <= n; i++)
            if (arr[i] == 0)
            {
                s.insert(i);
                for (ll j = (i * i); j <= n; j += i)
                    arr[j] = 1;
            }
            return s;
        }
        ll mod_add(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (((a + b) % m) + m) % m;
        }
        ll mod_mul(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (((a * b) % m) + m) % m;
        }
        ll mod_sub(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (((a - b) % m) + m) % m;
        }
        ll mod_div(ll a, ll b, ll m)
        {
            a = a % m;
            b = b % m;
            return (mod_mul(a, id2(b, m), m) + m) % m;
} 

ll mod_inv(ll a, ll mod){
    return expo(a,mod-2,mod);
} 
ll id5(ll n) {
    ll ans = 0;
    if (n == 1) {
      return 1;
  }
  ans += 1 + n;
  for (ll i = 2; i * i <= n; i++) {
      if (i != n / i) {
        ans += (i + n / i);
    } else {
        ans += i;
    }
    ll l = (n / i) + 1;
    ll h = (n / (i - 1)) - 1;
    if (l <= h) {
        ans += (h-l+1)*(i-1);
    }

}
return ans;
}
ll id4(ll x,ll y) {
    ll ans = 0,n=x;
    if (n == 1) {
      return 1;
  }
  ans += 1;
  for (ll i = 2; i * i <= n; i++) {
      if (i != n / i) {
        if(i>=2 && i<=y+1) ans += i;
        if(n/i>=2 && n/i<=y+1) ans+= n/i;
    } else {
        if(i>=2 && i<=y+1) ans += i;
    }
    ll l = (n / i) + 1;
    ll h = (n / (i - 1)) - 1;
    if (l <= h) {
        ans += (h-l+1)*(i-1);
    }

}
return ans;
}

ll id8(ll n, ll r,ll fact[], ll mod){


    if(n<r) return 0;


    if(r==0) return 1;
















    return (fact[n]*((mod_inv(fact[n-r],mod)*mod_inv(fact[r],mod))%mod))%mod;
}
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} 

void precision(int a) { cout << setprecision(a) << fixed; }
vector<ll> id1(ll n){
    ll chk = n*n;
    unordered_set<ll> s;
    vector<ll> res;
    for(ll i=1;i<n;i++){
        s.insert(i*i);
        if(s.find(chk-i*i)!=s.end()){
            res.pb(sqrt(chk-i*i));
            res.pb(i);
            return res;
        }
    }
    return res;
}
bool nc(string a,string b){
    if(a.length()==b.length()) return (a.compare(b)>=0);
    return a.length()>b.length();
}
string maxnum(string a, string b){
    vector<ll> v;
    for(ll i=0;i<a.length();i++) v.pb(a[i]-'0');
        for(ll i=0;i<b.length();i++) v.pb(b[i]-'0');
            sort(v.rbegin(),v.rend());
        string res="";
        for(ll i=0;i<v.size();i++) res+=(v[i]+'0');
            return res;
    }


    char retrand(char a, char b){
        if(a==b) return (a=='z')?'y':(char)a+1;
        else if(a==b+1){
            return (a=='z')?'x':(char)a+1;
        }else if(b==a+1) return (b=='z')?'x':(char)b+1;
        else return (char)((a+b)/2);
    }
ll mod =1e9+7;
ll modp=998244353;
    ll getqb(ll n){
        ll f=0,c=0;
        while(n>0){
            f+=((n&1)*expo(10,c,mod));
            n>>=1;
            ++c;
        }
        return f;
    }


    ll po2(ll n){
        ll c=0;
        while(n>1){
            n>>=1;
            ++c;
        }
        return c;
    }
    ll ncr(ll n, ll r, ll m){
        r=min(n-r,r);
        if(r==0) return 1;
        return mod_div(mod_mul(n-r+1,ncr(n,r-1,m),m),r,m);
    }
    ll get(vector<ll>&p,ll a){
        return p[a]=((p[a]==a)?a:get(p,p[a]));
    }
    pair<ll,ll> getpar(pair<ll,ll> a, vector<vector<pair<ll,ll>>>&par){
        return par[a.ff][a.ss]=(par[a.ff][a.ss]==a)?a:getpar(par[a.ff][a.ss],par);
    }
    void unio(pair<ll,ll> a, pair<ll,ll> b, vector<vector<pair<ll,ll>>>&par, vector<vector<ll>>&rank){
        a=getpar(a,par);
        b=getpar(b,par);
        if(rank[a.ff][a.ss]==rank[b.ff][b.ss]) ++rank[a.ff][a.ss];
        if(rank[a.ff][a.ss]>rank[b.ff][b.ss]) par[a.ff][a.ss]=b;
        else par[b.ff][b.ss]=a;
    }
void id6(ll i, set<ll> adj[], vector<ll>&vis, stack<ll>&st){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]) id6(x,adj,vis,st);
    }
    st.push(i);
}
void id3(ll i, set<ll> adj[] ,vector<ll>&vis, set<ll>&s){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]) id3(x,adj,vis,s);
    }
    s.insert(i);
}

class Histogram{
public:
    vector<ll> hist;
  vector<int> nextSmallerElements(vector<int>&a, int&n){
        vector<int>  nse(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                if(a[i]>=a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]<a[st.top()]){
                        nse[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return nse;
    }
       vector<int> previousSmallerElements(vector<int>&a, int&n){
        vector<int>  pse(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push(i);
            else{
                if(a[i]>=a[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty()&&a[i]<a[st.top()]){
                        pse[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return pse;
    }
    int maxAreaHistogram(vector<int>&a, int&n){
        vector<int> nse(n), pse(n);
        nse = nextSmallerElements(a,n);
        pse = previousSmallerElements(a,n);
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea, (nse[i]-pse[i]-1)*a[i]);
        }
        return maxArea;
    }
};
ll dp[501][501][21];
ll recur(ll i , ll j , ll k , vector<vector<ll>> &a , vector<vector<ll>> &b , ll &n , ll &m){
    debug(i) debug(j)
    if(i < 1 || i > n || j < 1 || j > m)
        return INF;
    if(k==0)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    ll ans = INF;
    for(auto &x : coords){
        ll r = x.ff + i , c = x.ss + j;
        if(r < 1 || r > n || c < 1 || c > m)
            continue;
        if(x.ff == 0){
            ans = min(ans , a[max(r , i)][max(c , j)] + recur(r , c , k - 1 , a , b , n , m));
        }else
            ans = min(ans , b[max(r , i)][max(c , j)] + recur(r , c , k - 1 , a , b , n , m));
    }
    return dp[i][j][k] = ans;
}
int main()
{
        



    freopen("input.txt", "r", stdin);


freopen("Error.txt", "w", stderr);


    freopen("output.txt", "w", stdout);
 


    FAST;



























ll n , m , k;
cin >> n >> m >> k;


vector<vector<ll>> a(n + 1 , vector<ll>(m + 1 , INF)) , b(n + 1 , vector<ll>(m + 1 , INF));
for(ll i = 1 ; i <= n ; i++){
    for(ll j = 1 ; j < m ; j++){
        ll x;
        cin >> x;
        a[i][j + 1] = x;
    }
}
debug(a)
for(ll i = 1 ; i < n ; i++){
    for(ll j = 1 ; j <= m ; j++){
        ll x;
        cin >> x;
        b[i + 1][j] = x;
    }
}
debug(a)


if(k & 1){
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < m ; j++)
            cout << -1 << " ";
        cout << endl;
    }
    return 0;
}
memset(dp , -1 , sizeof(dp));


for(ll i = 1 ; i <= n ; i++){
    for(ll j = 1 ; j <= m ; j++){
        if(dp[i][j][k / 2] == -1)
            recur(i , j , k / 2 , a , b , n , m);
        cout << 2*dp[i][j][k / 2] << " ";
    }
    cout << endl;
}

 

 

 

 

 

 

 

 

 

 

}