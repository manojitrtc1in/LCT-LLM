



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9
#define MAX 1e6
#define forr(i, x, y) for(ll i = x; i <= y; i++)
#define forn(i, x, y) for(ll i = x; i >= y; i--)


using db = long double; 

using str = string; 

 


using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first


 
#define tcT template<class T
#define tcTU tcT, class U


tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
 




#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz res
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
 
#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }
 


#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);


mt19937 rng(0);
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 




constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } 

 
tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { 

	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } 

 
#define tcTUU tcT, class ...U
ll gcd(ll a,ll b)
{
    

  if(b==0)
  return a;
  else
  return gcd(b,a%b);
}
bool isprime(ll n)
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


 void  is(vector<ll>&v,ll n)
 {
  set<ll>s;
  

  ll maxi=0,temp=1;
  ll i;
  for( i=1;i*i<=n;i++)
  {
   

     

      if(n%i==0&&s.find(i)==s.end())
      {
        

         s.insert(i);
        

        

        

        

        

        

        

        

       v.push_back(i);
 

      }
    }
    maxi=0;
    for( i=sqrt(n);i>=1;i--)
  {
   

     

    if(n%i==0)
    { 
      if(s.find(n/i)==s.end())
     {
       

        s.insert(n/i);
        

        

        

        

        

        

        

        

       

        v.push_back(n/i);
   

    }
}
}








 






















}


bool ispalindrome(string s)
{
  string s1=s;
  reverse(s.begin(),s.end());
  return (s1==s);
}


ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
ll ans=0;
void dfs(ll i,vector<ll>adj[],vector<bool>&visited)
{
  visited[i]=true;
  

  for(auto j:adj[i])
  {
    if(!visited[j])
    {
      

      dfs(j,adj,visited);
     

    }
  }
  

}
ll binomialCoeff(ll n, ll k)
{
    ll res = 1;
    ll mod=1e9+7;
 
    

    if (k > n - k)
        k = n - k;
 
    

    

    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res%=mod;
        res /= (i + 1);
        res%=mod;
    }
 
    return res;
}
bool static issort(pair<ll,pair<ll,ll>>a,pair<ll,pair<ll,ll>>b)
{
 if(a.first==b.first)
 {
   return a.second.first<b.second.first;
 }
 return a.first>b.first;
}
 
 


string decimalToBinary(ll n)
{
    

    

    string s = bitset<64> (n).to_string();
    
    

    

    const auto loc1 = s.find('1');
    
    if(loc1 != string::npos)
        return s.substr(loc1);
    
    return "0";
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    

    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}


ll power(ll x,unsigned ll y)
{
  ll ans=1;
 

  while(y>0)
  {
    if(y&1)
    ans=(ans*x);
    x*=x;
    

    y=y>>1;
  

  }
  return ans;
}
bool isPower(ll x, ll y)
{
    

    ll res1 = log(y) / log(x);
    double res2 = log(y) / log(x); 

 
    

    return (res1 == res2);
}
ll check(string &s,string &t)
{
  ll ans=0,i;
  for(i=0;i<s.length();i++)
  {
    if(s[i]!=t[i])
    ans++;
  }
  return ans;
}
ll countOdd1(ll L, ll R){
 
    ll N = (R - L) / 2;
 
    

    if (R % 2 != 0 || L % 2 != 0)
        N += 1;
 
    return N;
}


ll palindromic(string &s,ll i,ll j,char c,ll &ans)
{
 while(i<j)
 {
   if(s[i]==s[j])
   {
     i++;
     j--;
   }
   else
   {
     if(s[i]!=c&&s[j]!=c)
     return INF;
     else
     {
       if(s[i]==c)
       return 1+palindromic(s,i+1,j,c,ans);
       else
       return 1+palindromic(s,i,j-1,c,ans);
     }
   }
 }
 return 0;
 

}


ll check2(ll a[],ll n,ll i,bool pos,vector<vector<ll>>&dp1)
{
  if(i==n)
  return 0;
  if(dp1[i][pos])
  return dp1[i][pos];
  ll inc ,exc;
  if(a[i]>0&&pos)
  {
    pos=false;
    inc= 1+check2(a,n,i+1,pos,dp1);
  }
  else if(a[i]<0&&!pos)
  {
    pos=true;
    exc=1+check2(a,n,i+1,pos,dp1);
  }
  exc=check2(a,n,i+1,pos,dp1);
  dp1[i][pos]=max(exc,inc);
}

bool isvowel(char c)
{
  return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
void build(ll ind,ll low,ll high,ll seg[],ll a[])
{
  if(low==high)
  {
    seg[ind]=a[low];
    return;
  }
  ll mid=low+(high-low)/2;
  build(2*ind+1,low,mid,seg,a);
  build(2*ind+2,mid+1,high,seg,a);
  seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
ll query(ll ind,ll low,ll high,ll l,ll r,ll seg[])
{
  if(low>=l&&high<=r)
  return seg[ind];
  if(high<l||low>r)
  return 0;
  ll mid=low+(high-low)/2;
  ll left=query(2*ind+1,low,mid,l,r,seg);
  ll right=query(2*ind+2,mid+1,high,l,r,seg);
  return left+right;
}
void update(ll ind,ll low,ll high,ll pos,ll val,ll seg[],ll a[])
{
  if(low==high)
  {
    a[low]=val;
    seg[ind]=val;
    return;
  }
  ll mid=low+(high-low)/2;
  if(pos>=low&&pos<=mid)
  update(2*ind+1,low,mid,pos,val,seg,a);
  else
  update(2*ind+2,mid+1,high,pos,val,seg,a);
  seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}


 ll dp[200005];
ll dfs1(ll parent,ll child,vector<ll>adj[],ll dist)
{
  

  ll count=0;
  for(auto j:adj[child])
  {
    if(j!=parent)
    {
      count+=dfs1(child,j,adj,dist+1);
    }
  }
  dp[child]=dist-count;
  return count+1;
}
vector<vector<ll>>prefixbits(2e5+5,vector<ll>(21,0));
void helper()
{
  ll i,j,temp,count;
    for(j=1;j<=2e5;j++)
    {
      count=0;
      for(i=0;i<=20;i++)
      {
        temp=(j&(1<<i));
      if(temp>0)
      {
        prefixbits[j][i]=1;
      }
      prefixbits[j][i]+=prefixbits[j-1][i];
    }
    }
}
vector<ll>v10(MAX,0);
void buildtree(ll a[],ll n,ll start,ll end,ll level)
{
  if(start>end)
  return;
 ll maxi=INT_MIN;
 ll idx=INT_MAX;
 for(ll i=start;i<=end;i++)
 {
   if(a[i]>maxi)
   {
     maxi=a[i];
     idx=i;
   }
 }
 v10[idx]=level;
  

  

  buildtree(a,n,start,idx-1,level+1);
  buildtree(a,n,idx+1,end,level+1);
}


ll dx2[8]={1,2,2,1,-1,-2,-2,-1};
ll dy2[8]={2,1,-1,-2,-2,-1,1,2};




 
bool checkpossibledivisor(string &s,ll k)
{
  for(ll i=0;i<s.length();i++)
  {
    if(s[i]!=s[i%k])
    return false;
  }
  return true;
}
ll ans4=INT_MAX;
ll kadane(vector<ll>&v)
{
  ll maxi=INT_MIN;
  ll sum=0,i;
  for(i=0;i<v.size();i++)
  {
    sum+=v[i];
    maxi=max(maxi,sum);
    if(sum<0)
    sum=0;
  }
  return maxi;
}
ll lcm(vector<ll>&v)
{
  ll first=v[0];
  for(ll i=1;i<v.size();i++)
  first=(first/__gcd(first,v[i]))*v[i];
  return first;
}
bool subsequence(string &s,string &t)
{
  ll j=t.length()-1,i;
  for(i=s.length()-1;i>=0;i--)
  {
    if(s[i]==t[j])
    j--;
  }
  return j<0;
}
bool checkcycle(ll src,vector<ll>adj[],vector<bool>&visited,vector<bool>&rec)
{
  visited[src]=true;
  rec[src]=true;
  for(auto j:adj[src])
  {
    if(!visited[j]&&checkcycle(j,adj,visited,rec))
    return true;
    else if(rec[j])
    return true;
  }
  rec[src]=false;
  return false;
}
ll productofdig(string &s)
{
  ll prod=1;
  for(ll i=0;i<s.length();i++)
  prod*=(s[i]-'0');
  return prod;
}




ll palindromecnt(ll n)
{
  ll count=0;
  for(ll i=1;i<=n;i++)
  {
    string s1=to_string(i);
    if(ispalindrome(s1))
    count++;
  }
  return count;
}
void dm2(bool seive[2000005])
{
  ll maxi=2e6;
  seive[0]=true;
  seive[1]=true;
  for(ll i=2;i<=maxi;i++)
 {
   if(!seive[i])
   {
     for(ll j=i;j*j<=maxi;j+=i)
     seive[j]=true;
   }
 }
}
void nthPalindrome(int n, int k)
{
    

    int temp = (k & 1) ? (k / 2) : (k/2 - 1);
    int palindrome = (int)pow(10, temp);
    palindrome += n - 1;
 
    

    printf("%d", palindrome);
 
    

    if (k & 1)
        palindrome /= 10;
 
    

    while (palindrome)
    {
        printf("%d", palindrome % 10);
        palindrome /= 10;
    }
    printf("\n");
}
bool issort1(pair<ll,pair<ll,ll>>a,pair<ll,pair<ll,ll>>b)
{return a.first>b.first;
}
ll mod=998244353;
ll factorial1(ll n)
{
  ll fact=1,i;
  for(i=1;i<=n;i++)
  {
    fact*=i;
    fact%=mod;
  }
  return fact;
}
void solve()
{
  ll n;
  cin>>n;
  ll a[n+1],i,maxi=0;
  map<ll,ll>mp;
  for(i=0;i<n;i++)
 { cin>>a[i];
  mp[a[i]]++;
}
  if(n==1)
  {
    cout<<"YES"<<endl;
    return;
  }
  if(mp[1]!=1)
  {
    cout<<"NO"<<endl;
    return;
  }
  if(a[0]>a[n-1]+1)
  {
    cout<<"NO"<<endl;
    return;
  }
  maxi=*max_element(a,a+n);
  for(i=0;i<n-1;i++)
  {
    if(a[i+1]-a[i]>1)
    {
      cout<<"NO"<<endl;
      return;
    }
  }
   for(i=0;i<n;i++)
  {
    if(a[i]==n)
    {
     if(i+1<n&&a[i+1]!=1)
     {
       cout<<"NO"<<endl;
       return;
     }
     else
     {
       cout<<"YES"<<endl;
       return;
     }
    }
  }
  cout<<"YES"<<endl;
}
    



int main()
{
   ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
    ll t;
    t=1;
    

    ll j=1;
    cin>>t;
    while(t--)
    {
     

      

      solve();
    }
  return 0;
}