#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define F first
#define S second
#define all(C) (C).begin(), (C).end()
#define fio ios_base::sync_with_stdio(0), cin.tie(0)
 #include<bits/stdc++.h>
using namespace std;


#define ss second
#define ff first
#define pb push_back
 #include<bits/stdc++.h>






#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define si set<int>


#define s second
#define all(v) v.begin(),v.end()
#define set_bits __builtin_popcount
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ninf LLONG_MIN
#define inf LLONG_MAX
#define sz size()
#define endl '\n'
#define nln cout<<endl;
using namespace std;
int tc = 1;
#include <bits/stdc++.h>
  #include <bits/stdc++.h>
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <chrono>
 
  #include <bits/stdc++.h>
using namespace std;








using ll= long long;
using lld= long double;
using ull= unsigned long long;


const lld pi= 3.141592653589793238;
const ll INF= 1e18;
const ll mod=1e9+7;


typedef pair<ll, ll> pll;


typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define vr(v) v.begin(),v.end():
#define rv(v) v.end(),v.begin()
#include <complex>
#define endl "\n"
#define ll long long
#define lli long long int
#define vi vector<int>
#define vs vector<string>
#define vll vector<ll>
#define vvi vector < vi >
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define mii map<int,int>
#define pll pair<ll, ll>
#define PI 3.141592653589793238462
#define mod 998244353
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define ppb pop_back
#define pf  push_front
#define ppf pop_front
#define go(i,n) for(ll i=0;i<n;i++)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define dep(i,a,b) for(ll i=a; i>=b; i--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define dne cout<<-1<<endl
using namespace std;
 
 
 
inline void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
inline int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM(int a, int b) { return a * b / GCD(a, b); }
inline int ceil(int a, int b){  return ((a%b==0) ? a/b : a/b +1);}
inline double logb(int base,int num){ return (double)log(num)/(double)log(base);}
inline ll power(ll x, ll n){ ll res = 1;while (n!=0) {if (n & 1)res = (res * x)%mod;x = (x * x)%mod;n = n >> 1;}return res;}
inline bool getBit(int num, int i){return ((num & (1 << i)) != 0);}
inline int setBit(ll num, ll i){return num | (1LL << i);}
inline int clearBit(int num, int i){ int mask = ~(1 << i);return num & mask;}
inline int findGCDofArray(vll arr, int n){ int result = arr[0]; for (int i = 1; i < n; i++) { result = GCD(arr[i], result);if(result == 1){return 1;}}return result;}
inline void printvll(vector<ll>&v){ for(ll i=0;i<v.sz;i++) cout<<v[i]<<" "; cout<<endl;  }
inline void printVchar(vector<char>&v){ for(ll i=0;i<v.sz;i++) cout<<v[i]<<" "; cout<<endl;  }
inline bool isPerfectSquare(long double x){ if (x >= 0) { long long sr = sqrt(x);return (sr * sr == x); }return false; }
inline int maxSubArraySum(vector<ll>a, ll size){ll max_so_far = LLONG_MIN, max_ending_here = 0;for (ll i = 0; i < size; i++){max_ending_here = max_ending_here + a[i];if (max_so_far < max_ending_here)max_so_far = max_ending_here;if (max_ending_here < 0)max_ending_here = 0;}return max_so_far;}
inline void ipvll(vector<ll>&v,ll n){ rep(i,0,n){ cin>>v[i];} }
inline void printpermutation(vector<ll>&v,ll cid){ if(cid==v.size()-1){printvll(v); return; }for(ll i=cid;i<v.size();i++){swap(v[i],v[cid]);printpermutation(v,cid+1);swap(v[i],v[cid]); }}
inline ll popcount(ll n){ll bits=log2(n)+1;ll c=0;for(ll i=0;i<bits;i++){if(getBit(n,i)==1){c++;}}return c;}
inline bool allsame(vector<ll>&v){ll n=v.sz;for(ll i=0;i<n;i++){if(v[i]!=v[0]){return false;}}return true;}
double euclidean_distance(ll x1,ll y1,ll x2,ll y2)
{
    double a=(x2-x1)*(x2-x1);
    double b=(y2-y1)*(y2-y1);
    double c=(double)sqrt(a+b);
    return c;
}





  

 
#include<bits/stdc++.h>
using namespace std;
int a[2001],dp[2001][2001];
int main() {


  

 
	int t;
	cin >> t;
	while(t--) {
		int n,k;


  

 
		cin >> n >> k;
		for(int i=1;i<=n;++i)
			cin >> a[i];


  

 
		for(int i=1;i<=n;++i)
			for(int j=0;j<=i;++j)
				if(j==0)


  

 
					dp[i][j]=dp[i-1][j]+(a[i]==i-j);
				else
					dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]+(a[i]==i-j));
		int flag=-1;


  

 
		for(int i=0;i<=n+1;++i)
			if(dp[n][i]>=k) {
				flag=i;


  

 
				break;
			}


  

 
		cout << flag << endl;
	}
}


  

 

