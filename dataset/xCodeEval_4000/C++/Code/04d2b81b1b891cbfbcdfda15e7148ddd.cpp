
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define REP(i,n) for(int i=0;i<n;i++)

#ifdef Priyansh31dec
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; 


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
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 


ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} 

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

 
ll per(string s,ll n,char c)
{   if(n==1)
{
    return s[0]!=c;
}

    ll m=n/2;
    ll cntl=n/2-count(s.begin(),s.begin()+m,c);
    cntl+=per(s.substr(m,n-m),n/2,c+1);
    ll cntr=n/2-count(s.begin()+m,s.end(),c);
    cntr+=per(s.substr(0,m),n/2,c+1);
    return min(cntl,cntr);
}
ll occ(string temp,string res,ll n,ll m)
{    ll ans=0;
    for(int i=0;i<n-m+1;i++)
    {   ll k=0;
        for(int j=i;j<n;j++)
        {
            if(temp[j]==res[k])k++;
            else break;
            if(k==m){ans++;break;}
        }
    }
    return ans;
}




#include <bits/stdc++.h>
#define ll long long
const int N = 1000001;
using namespace std;



ll factorialNumInverse[N + 1];



ll naturalNumInverse[N + 1];



ll fact[N + 1];



void InverseofNumber(ll p)
{
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (int i = 2; i <= N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}


void InverseofFactorial(ll p)
{
	factorialNumInverse[0] = factorialNumInverse[1] = 1;

	

	for (int i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}



void factorial(ll p)
{
	fact[0] = 1;

	

	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}



ll Binomial(ll N, ll R, ll p)
{
	

	ll ans = ((fact[N] * factorialNumInverse[R])
			% p * factorialNumInverse[N - R])
			% p;
	return ans;
}



void solve(){
    	ll p = 1000000007;
	InverseofNumber(p);
	InverseofFactorial(p);
	factorial(p);
    ll n;
    cin>>n;
    vector<int> a(n);
    REP(i,n)cin>>a[i];
    map<int,int> m;
    REP(i,n)m[a[i]]++;
    for(int i=1;i<=70;i++)
    {
        for(int j=1;j<=70;j++)
        {
            
        }
    }
    
    
    
}






#include <iostream>
using namespace std;





int firstPos(string str, int start, int end)
{
	int firstChar = -1;

	

	

	for (int i = start; i <= end; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			firstChar = i;
			break;
		}
	}

	return firstChar;
}





int lastPos(string str, int start, int end)
{
	int lastChar = -1;

	

	

	for (int i = start; i >= end; i--) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			lastChar = i;
			break;
		}
	}

	return lastChar;
}







bool isPalindrome(string str)
{
	int firstChar = 0, lastChar = str.length() - 1;
	bool ch = true;

	for (int i = 0; i < str.length(); i++) {
		firstChar = firstPos(str, firstChar, lastChar);
		lastChar = lastPos(str, lastChar, firstChar);

		

		if (lastChar < 0 || firstChar < 0)
			break;
		if (str[firstChar] == str[lastChar]) {
			firstChar++;
			lastChar--;
			continue;
		}

		

		ch = false;
		break;
	}

	return (ch);
}


#include <bits/stdc++.h>
using namespace std;





string LongestPalindromicPrefix(string str)
{

	

	string temp = str;

	

	reverse(str.begin(), str.end());

	

	temp += str;

	

	int n = temp.length();

	

	int lps[n];

	

	fill(lps, lps + n, 0);

	

	for (int i = 1; i < n; i++) {

		

		

		int len = lps[i - 1];

		

		while (len > 0
			&& temp[len] != temp[i]) {
			len = lps[len - 1];
		}

		

		

		

		if (temp[i] == temp[len]) {
			len++;
		}

		

		

		lps[i] = len;
	}

	

	

	return "k";
}
ll int LCM(ll x,ll y){
	return x/gcd(x,y)*y;
}




#include <bits/stdc++.h>
using namespace std;












vector<string> perm;
void permute(string a, int l, int r)
{
	

	if (l == r)
		perm.pb(a);
	else
	{
		

		for (int i = l; i <= r; i++)
		{

			

			swap(a[l], a[i]);

			

			permute(a, l+1, r);

			

			swap(a[l], a[i]);
		}
	}
}
bool compare1(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.first<b.first)
    return true;
    else if(a.first==b.first)
    {
        if(a.second<b.second)return true;
        return false;
    }
    return false;
}
vector<int> v[100001];
vector<int> a(100001);
ll cnt=0,xo=0;
bool vis[100001];



ll dfs(ll node)
{   vis[node]=1;
   ll val=a[node];
    for(auto i:v[node])
    {  
        if(!vis[i])
        {
            val^=dfs(i);
        }
    }
    if(val==xo)
    {
        cnt++;val=0;
    }
    

    return val;
    
}
void solve4()
{
    
    ll n,d,cur;
    cin>>n>>d;
    vector<int> a(n);
    REP(i,n)cin>>a[i];
    ll ans=-1e9;
    for(int i=0;i<n;i++)
    { 
       ll j=i,pos=-1,cnt=0;
       while(j!=i){
           
           if(a[j]==1)pos=cur;
          cnt++;
           a[j]=0;j+=d;j%=n;
           
       }
       if(pos==-1)
       {
           cout<<-1<<endl;return;
       }
       ans=max(ans,pos);
       
       
       
    }
    cout<<ans<<endl;
    
}
void solve5()
{ll n;
cin>>n;
ll ans=0,mn=1e9;
if(n==1)
{
    cout<<"Bob"<<endl;return;
}
for(ll i=2;i<=n;i++)
{
    if(n%i==0)
    {
        while(n%i==0)
        {
            ans+=(i-1);n/=i;
        }
        mn=min(mn,(ll)i);
    }
}

if(n>1)
{
    ans+=(n-1);
    mn=min(mn,(ll)n);
    
}
ans-=(mn-1);
if(ans%2==0)
{
    cout<<"Bob"<<endl;
}
else cout<<"Alice"<<endl;
}
void solve6()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;s+=(s[n-1]^'-'^'+');
    vector<ll> a;
    int cx=0,cy=0;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='+'){cy=0;cx++;}
        else {cy++;cx=0;}
        
        
            if(s[i]!=s[i+1]&&(cx&1||cy&1))
            {   if(a.empty())
               {
                a.pb(i);
                }
                else if(a.back()<n&&s[a.back()]==s[i])
                {
                    a.pop_back();
                }
                else 
                {
                    a.pb(i);
                }
            
            }
    }
    

    
    
    while(q--)
    {
        ll l,r;cin>>l>>r;l--;r--;
        ll l1=lower_bound(all(a),l)-a.begin();
        ll u1=upper_bound(all(a),r)-a.begin();
        if(u1>0)
        u1--;
        if(l1>=a.size())l1=a.size()-1;
        int cnt=u1-l1+1;
        
        if((a[l1]-l)&1)
        {
            if(a[l1]<n&&s[l]==s[a[l1]])cnt--;
            else cnt++;
        }
        if((r-a[u1])&1)
        {
          if(a[u1]<n&&s[r]==s[a[u1]])cnt--;
          else cnt++;
        }
        if(cnt==0)
        {
            cout<<0<<endl;
        }
        else if(cnt&1)
        {
            cout<<1<<endl;
          

            
        }
        else 
        {
            cout<<2<<endl;
           

        }
        
    }
    
}
void solve7()
{
    ll n;
    cin>>n;
   vector<ll> a(n);
   REP(i,n)cin>>a[i];
   map<ll,ll>  m;
   set<int> s;
   for(int i=1;i<=n;i++)
   s.insert(i);
   vector<int> ans(n+1,0);
   for(int i=0;i<n;i++)
   {
       if(s.find(a[i])!=s.end())
       {
           m[a[i]]=i;
           ans[i]=a[i];
           s.erase(a[i]);
       }
   }cout<<n-s.size()<<endl;
   for(int i=0;i<n;i++)
   {
       if(ans[i]==0)
       {
           if(*s.begin()==i+1)
           {
               ans[m[a[i]]]=*s.begin();
               m[a[i]]=i;
               ans[i]=a[i];
           }
           else
           {
               ans[i]=*s.begin();
           }
           s.erase(s.begin());
       }
   }
   
   for(int i=0;i<n;i++)cout<<ans[i]<<" ";cout<<endl;
}
int main() {
int t;
cin>>t;


while(t--)
{
    solve7();
}
}