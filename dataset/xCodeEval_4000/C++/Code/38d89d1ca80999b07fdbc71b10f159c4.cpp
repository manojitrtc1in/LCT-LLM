#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long int ull;
typedef vector<ull> vul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef unordered_set <ll> usl;
typedef unordered_set <int> usi;
double EPS = 1e-9;
long long int INF = 1000000005;
long long INFF = 1000000000000000005ll;
double PI = acos(-1);
long long int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
long long int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif
#define sz(x) (int)((x).size())
#define mem0(a) memset(a,0,sizeof(a))
#define mem_1(a) memset(a,-1,sizeof(a))
#define mem1(a) memset(a,1,sizeof(a))

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define All(v) v.begin(), v.end()
#define AllA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(All(v))
#define REVERSE(v) reverse(All(v))
#define SORTA(arr, sz) sort(AllA(arr, sz))
#define REVERSEA(arr, sz) reverse(AllA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

inline string IntToString(ll a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}

inline ll StringToInt(string a)
{
    char x[100];
    ll res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

inline string GetString(void)
{
    char x[1000005];
    scanf("%s", x);
    string s = x;
    return s;
}

inline string uppercase(string s)
{
    long long int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'a' && s[i] <= 'z')
        s[i] = s[i] - 'a' + 'A';
    return s;
}

inline string lowercase(string s)
{
    long long int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    return s;
}

inline void OPEN(string s)
{
#ifndef TESTING
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

int gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(ll a,ll b){
    

    return ((a*b)/gcd(a,b));
}
bool isPrime(ll n)
{
    

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
int No_of_digits_in_int(ll n){
    ll i=1,ans=0;
    while(n>=i) {ans++;i=i*10;}
    return ans;
}
int sum_of_digits_in_int(ll n){
    ll i,ans=0,nod;
    nod=No_of_digits_in_int(n);
    

    i=pow(10,nod-1);
    while(i>0) {
        ans+=(n/i);
        n=n-(n/i)*i;
        

        i=i/10;
    }
    

    return ans;
}
int power(long long x, unsigned int y, int p)
{
    int res = 1;     
 
    x = x % p; 
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
     
        if (y & 1)
            res = (res*x) % p;
 
       
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
string DectoBinary(ll n){
    string s="";
    while(n!=0){
            if(n%2==0) s=s+"0";
            else s=s+"1";
            n=n/2;}
    return s;
}
ll gcd_v(vl &v){
    ll gc=v[0];
    FOR(i,0,v.size()){
        gc=__gcd(gc,v[i]);
    }
    return gc;
}
bool sortbysecdesc(const pair<ll,ll> &a,
                   const pair<ll,ll> &b)
{
    

    

    

    return a.second <= b.second;
       

}
void input(vl &v,ll n){
    FOR(i,0,n){
        ll temp;
        cin>>temp;
        v.pb(temp);
    }
}
void print(vl &v){
    FOR(i,0,v.size()){
        cout<<v[i]<<" ";
    }
}
void swap_neigh_ele(vl &v){
    for(int i=0;i<v.size();i+=2){
        swap(v[i],v[i+1]);
    }
}
void swap_half_vec(vl &v){
    int n=v.size()/2;
    vl temp;
    temp=v;
    FOR(i,0,n){
        v[i]=temp[i+n];
    }
    FOR(i,0,n){
         v[i+n]=temp[i];
    }
}
int binarySearch(vl &arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        

        

        if (arr[mid] == x)
            return mid;
 
        

        

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        

        

        return binarySearch(arr, mid + 1, r, x);
    }
 
    

    

    return -1;
}
void rearrangeArray(int arr[], int N)
{
     
    

    

    map<int, int>mp, visited;
     
    for(int i = 0; i < N; i++)
    {
        mp[arr[i]]++;
    }
     
    priority_queue<pair<int, int>>pq;
     
    

    

    for(int i = 0; i < N ; i++)
    {
        int val = arr[i];
         
        if (mp[val] > 0 and visited[val] != 1)
        {
            pq.push({mp[val], val});
        }
        visited[val] = 1;
    }
     
    

    vector<int>result(N);
     
    

    

    

    pair<int, int>prev = { -1, -1 };
    int l = 0;
     
    

    while (pq.size() != 0)
    {
         
        

        

        pair<int,int>k = pq.top();
        pq.pop();
        result[l] = k.second;
         
        

        

        

        if (prev.first > 0)
        {
            pq.push(prev);
        }
         
        

        

        k.first--;
        prev = k;
        l++;
    }
     
    for(auto it : result)
    {
        if (it == 0)
        {
             
            

            

            cout << "NO" << endl;
            return;
        }
    }
     cout << "YES" << endl;

    for(auto it : result)
    {
        cout << it << " ";
    }
}
ull fact(ull n){
    if( n==1 || n==0) return 1;
    return n*fact(n-1);
}
bool isprime(int x)
{
   
    

    

    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
 ll dp[100000];
ll lis(vl &v, ll i){
    if(dp[i]!=-1) return dp[i];
    ll ans =1;
    for(ll j =0;j<i; j++){
        if(v[i]>=v[j]){
            ans= max(ans,lis(v,j)+1);
        }
    }
    return dp[i]=ans;
} 
void ot(ll n){
    cout<<n<<" ";
}




void printDivisors(ll n, vl& fac)
{
    

    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            

            if (n/i == i)
                fac.pb(i);
                

 
            else {

                            fac.pb(i);
                        fac.pb(n/i);}
                

        }
    }
}
void primeDivisors(ll n, vl& fac)
{
    

    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            

            if (n/i == i && isPrime(i))
                fac.pb(i);
                

 
            else {

                if(isPrime(i)  )
                            fac.pb(i);
                if(isPrime(n/i)  )
                        fac.pb(n/i);}
                

        }
    }
}
ll lcs(string X, string Y)
{
    ll m = X.length(),n=Y.length();
ll L[m+1][n+1];
ll i, j;
 

for (i=0; i<=m; i++)
{
    for (j=0; j<=n; j++)
    {
    if (i == 0 || j == 0)
        L[i][j] = 0;
 
    else if (X[i-1] == Y[j-1])
        L[i][j] = L[i-1][j-1] + 1;
 
    else
        L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
}
     

return L[m][n];
}
ll  sumofFactors(ll  n)
{
    ll  res = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
 
         
        ll  curr_sum = 1;
        ll curr_term = 1;
        while (n % i == 0) {
            n = n / i;
 
            curr_term *= i;
            curr_sum += curr_term;
        }
 
        res *= curr_sum;
    }
    if (n >= 2)
        res *= (1 + n);
 
    return res;
}
struct hashFunction
{
  size_t operator()(const pair<ll , 
                    ll> &x) const
  {
    return x.first ^ x.second;
  }
};




void visit( vector <vl> &v, ll n, vl &vi){
    FOR(i,0,v[n].size()){
        if(vi[v[n][i]]==0){
            vi[v[n][i]]=1;
            visit(v,v[n][i],vi);
        }
    }
    return;
}
void visi(vector <vl> &v,ll n,usl &u){
    ll s=v[n-1].size();
    u.insert(n);
    

    FOR(i,0,s){
        if(u.find(v[n-1][i])==u.end())
            visi(v,v[n-1][i],u);
    }
    return;
}
void visi1(vvl &m, ll n,vll &node,unordered_set <ll> &u){

    

    u.insert(n);
    node[n].se=1;
    FOR(i,0,m[n].size()){
        if(node[m[n][i]].se==0){
            visi1(m,m[n][i],node,u);
        }
    }   

}
void solve(){
    ll n,flag=0,k,m,ans=0;
    

    

    

    string s;
    cin>>s;
    vl v,an;
    n=s.length();
    ll temp=0;
    char z='0',o='1';
    flag=-1;
    ll cnt=0,l=0,in;
    FOR(i,0,n){
        if(flag==-1){
            

            if(s[i]==z) {
                flag=0; 
                in=i;
                if(i>0 && s[i-1]=='?' && l==0){
                    

                    an.pb(cnt);
                    l+=cnt;
                    cnt=0;
                }
                l++; 
                cnt=0;
            }
            else if(s[i]==o) {
                

                flag=1; 

                in=i;
                if(i>0 && s[i-1]=='?' && l==0){
                    

                    an.pb(cnt);
                    l+=cnt;
                    
                }
                l++;
                cnt=0;
            }
            else {
                while(i<n && s[i]=='?'){
                    cnt++;
                    l++;
                    i++;
                }
                if(cnt>0) i--;
            }
        }
        else if(flag==0){
            if(s[i]==z){
                if((i-in)%2==0){
                    l++;
                    in=i;
                    flag=0;
                    cnt=0;
                }
                else{
                    v.pb(l);
                    flag=-1;
                    l=0;
                    i--;
                }
            }
            else if(s[i]==o){
                if((i-in)%2!=0){
                    l++;
                    in=i;
                    flag=1;
                    cnt=0;
                }
                else{
                    v.pb(l);
                    flag=-1;
                    l=0;
                    i--;
                }
            }
            else if(s[i]=='?'){
                while(i<n && s[i]=='?'){
                    cnt++;
                    l++;
                    i++;
                }

                if(cnt>0) i--;
            }
        }
        else if(flag==1){
            if(s[i]==o){
                if((i-in)%2==0){
                    l++;
                    in=i;
                    flag=1;
                    cnt=0;
                }
                else{
                    

                    v.pb(l);
                    flag=-1;
                    l=0;
                    i--;
                }
            }
            else if(s[i]==z){
                if((i-in)%2!=0){
                    l++;
                    in=i;
                    flag=0;
                    cnt=0;
                }
                else{
                    v.pb(l);
                    flag=-1;
                    l=0;
                    i--;
                    

                }
            }
            else if(s[i]=='?'){
                while(i<n && s[i]=='?'){
                    cnt++;
                    l++;
                    i++;
                }
                
                if(cnt>0) i--;
            }
        }
        if(i==n-1) v.pb(l);
    }
    

    FOR(i,0,v.size()){
        k=v[i];
        ans+=(((k)*(k+1))/2);
    }
    ll d=0;
    FOR(i,0,an.size()){
        k=an[i];
        d+=(((k)*(k+1))/2);
    }
    ans-=d;
    

    cout<<ans;

}
int main(){ 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    ll t=1;
    cin>>t;
    

    TC(t){
        solve();
        cout<<"\n";
    }
    return 0;
}