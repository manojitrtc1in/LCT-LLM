
using namespace std;







 
using namespace std;





 

























using namespace std;
int tc = 1;

  
  
  
  
  
 
  
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
inline int id7(vll arr, int n){ int result = arr[0]; for (int i = 1; i < n; i++) { result = GCD(arr[i], result);if(result == 1){return 1;}}return result;}
inline void id2(vector<ll>&v){ for(ll i=0;i<v.sz;i++) cout<<v[i]<<" "; cout<<endl;  }
inline void id1(vector<char>&v){ for(ll i=0;i<v.sz;i++) cout<<v[i]<<" "; cout<<endl;  }
inline bool id3(long double x){ if (x >= 0) { long long sr = sqrt(x);return (sr * sr == x); }return false; }
inline int id6(vector<ll>a, ll size){ll id5 = id9, id8 = 0;for (ll i = 0; i < size; i++){id8 = id8 + a[i];if (id5 < id8)id5 = id8;if (id8 < 0)id8 = 0;}return id5;}
inline void ipvll(vector<ll>&v,ll n){ rep(i,0,n){ cin>>v[i];} }
inline void id0(vector<ll>&v,ll cid){ if(cid==v.size()-1){id2(v); return; }for(ll i=cid;i<v.size();i++){swap(v[i],v[cid]);id0(v,cid+1);swap(v[i],v[cid]); }}
inline ll popcount(ll n){ll bits=log2(n)+1;ll c=0;for(ll i=0;i<bits;i++){if(getBit(n,i)==1){c++;}}return c;}
inline bool allsame(vector<ll>&v){ll n=v.sz;for(ll i=0;i<n;i++){if(v[i]!=v[0]){return false;}}return true;}
double id4(ll x1,ll y1,ll x2,ll y2)
{
    double a=(x2-x1)*(x2-x1);
    double b=(y2-y1)*(y2-y1);
    double c=(double)sqrt(a+b);
    return c;
}





  

 

using namespace std;
vector<int> a[100001];
int answer[100001],tanswer[100001],father[100001],n,k;



  

 
bool vis[100001],fatherget;
int power(int b,int m) {
	long long answer=1;
	while(m!=0) {
		if(m%2!=0)



  

 
			answer=answer*b%998244353;
		b=(long long)b*b%998244353;
		m/=2;
	}
	return answer;
}
void dfs(int x) {



  

 
	if(vis[x]) {
		fatherget=true;
		return;
	}
	vis[x]=true;
	for(unsigned int i=0;i<a[x].size();++i) {
		dfs(a[x][i]);
		if(fatherget) {



  

 
			father[x]=i;
			fatherget=false;
		}
	}
	if(x==1) return;
	if(tanswer[x]%k==0)



  

 
		tanswer[a[x][father[x]]]++;
	else
		tanswer[x]++;
}
int calc(int x) {
	k=x;
	for(int i=1;i<=n;++i) {
		vis[i]=false;



  

 
		tanswer[i]=0;
	}
	dfs(1);
	for(int i=1;i<=n;++i)
		if(tanswer[i]%x!=0)
			return 0;
	return 1;



  

 
}
void solve() {
	int s=0;
	cin >> n;
	for(int i=1;i<=n;++i) {
		a[i].clear();
		answer[i]=0;
	}
	for(int i=1;i<n;++i) {
		int u,v;



  

 
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=2;i<=n-1;++i)
		if((n-1)%i!=0)
			answer[i]=0;
		else 
			answer[i]=calc(i);
	for(int i=n-1;i>=2;--i) 



  

 
		for(int j=2*i;j<=n-1;j+=i) {
			answer[i]-=answer[j];
	  	answer[i]=(answer[i]%998244353+998244353)%998244353;
		}
	for(int i=2;i<=n-1;++i)
		s+=answer[i];



  

 
	answer[1]=(power(2,n-1)-s+998244353)%998244353;
	for(int i=1;i<=n;++i)
		cout << answer[i] << ' ';
	cout << endl;
}
int main() {
	int t;
	cin >> t;



  

 
	while(t--) 
		solve();
}

