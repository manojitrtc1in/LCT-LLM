
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








































inline string id0(ll a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}

inline ll id1(string a)
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

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);

}

unsigned long long gcd(unsigned long long a,unsigned long long b){
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
int id3(ll n){
    ll i=1,ans=0;
    while(n>=i) {ans++;i=i*10;}
    return ans;
}
int id5(ll n){
    ll i,ans=0,nod;
    nod=id3(n);
    

    i=pow(10,nod-1);
    while(i>0) {
        ans+=(n/i);
        n=n-(n/i)*i;
        

        i=i/10;
    }
    

    return ans;
}

long long binMultiply(long long a, long long b){
    long long ans =0;
    while(b){
        if(b&1){
            ans= (ans +a)%MOD;
        }
        a= (a+a)%MOD;
        b >>=1;
    }
    return ans;
}

long long  id7(long long a,long long  b){
    long long  ans=1;
    a= a%MOD;
    while(b){
        if(b&1){
            ans=(binMultiply(ans,a))%MOD;
        }
        a=(binMultiply(a,a))%MOD;
        b>>=1;
    }
    return ans;
}

string id10(ll n){
    string s="";
    while(n!=0){
            if(n%2==0) s=s+"0";
            else s=s+"1";
            n=n/2;}
    return s;
}
ll id9(vl &v){
    ll gc=v[0];
    FOR(i,0,v.size()){
        gc=__gcd(gc,v[i]);
    }
    return gc;
}
bool id11(const pair<ll,ll> &a,
                   const pair<ll,ll> &b)
{
     

     

    

    

    

    

    

       return a.fi>b.fi;
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
void id2(vl &v){
    for(int i=0;i<v.size();i+=2){
        swap(v[i],v[i+1]);
    }
}
void id8(vl &v){
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
void id6(int arr[], int N)
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




void id13(ll n, vl& fac)
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
void id12(ll n, vl& fac)
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
ll  id4(ll  n)
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

ll nsum(ll n){
    return (n*(n+1))/2;
}

int mod = 1e9 + 7;
ll mex(vl &v){
    FOR(i,0,v.size()){
        if(i!=v[i]){
            return ll(i);
        }
    }
    

    return ll(v.size());
}

bool sortva(const vector<ll> &a,
                   const vector<ll> &b)
{
	ll suma = 0;
	FOR(i,0,5){ if(i!=0)suma += a[i];}
	ll sumb = 0;
	FOR(i,0,5){ if(i!=0)sumb += b[i];}
	ll difa =  a[0] - suma;
	ll difb =  b[0] - sumb;
	

		

	

	return difa>difb;

	

	

	

 

}
bool sortvb(const vector<ll> &a,
                   const vector<ll> &b)
{	
	ll suma = 0;
	FOR(i,0,5){if(i!=1) suma += a[i];}
	ll sumb = 0;
	FOR(i,0,5){if(i!=1) sumb += b[i];}
	ll difa =  a[1] - suma;
	ll difb =  b[1] - sumb;
	

		

	

	return difa>difb;
}
bool sortvc(const vector<ll> &a,
                   const vector<ll> &b)
{
	ll suma = 0;
	FOR(i,0,5){if(i!=2) suma += a[i];}
	ll sumb = 0;
	FOR(i,0,5){if(i!=2) sumb += b[i];}
	ll difa =  a[2] - suma;
	ll difb =  b[2] - sumb;
	

		

	

	return difa>difb;
}
bool sortvd(const vector<ll> &a,
                   const vector<ll> &b)
{
	ll suma = 0;
	FOR(i,0,5){if(i!=3) suma += a[i];}
	ll sumb = 0;
	FOR(i,0,5){if(i!=3) sumb += b[i];}
	ll difa =  a[3] - suma;
	ll difb =  b[3] - sumb;
	

		

	

	return difa>difb;
}
bool sortve(const vector<ll> &a,
                   const vector<ll> &b)
{
	ll suma = 0;
	FOR(i,0,5){if(i!=4) suma += a[i];}
	ll sumb = 0;
	FOR(i,0,5){if(i!=4) sumb += b[i];}
	ll difa =  a[4] - suma;
	ll difb =  b[4] - sumb;
	

		

	

	return difa>difb;
}
void solve(){
    ll n,m,q,ans=0,flag=0,k=0,total=0,flag1=0,x,y;
    cin>>n;
    vector <vector<ll> > v(n,vector<ll> (5,0));
    vl tot(5,0);
    FOR(i,0,n){
    	string s;
    	cin>>s;
    	FOR(j,0,s.length()){
    		v[i][s[j]-'a']++;
    		tot[s[j]-'a']++;
    	}
    }
    

    

    

    

    

    

    FOR(i,0,5){
    	if(i==0) sort(All(v),sortva); if(i==1) sort(All(v),sortvb); if(i==2) sort(All(v),sortvc); if(i==3) sort(All(v),sortvd); if(i==4) sort(All(v),sortve);
    	

    	ll mx = 0,scr =0;
    	FOR(j,0,n){
    		ll sum = 0;
    		FOR(k,0,5){
    			if( i != k ){
    				sum += v[j][k];
    			}
    		}
    		if( (scr + (v[j][i]-sum) )> 0){
    			scr += (v[j][i]-sum);
    			

    			mx++;
    		}
    	}
    	ans = max(ans,mx);
    }
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