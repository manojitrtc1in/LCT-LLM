
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
inline int id9(vll arr, int n){ int result = arr[0]; for (int i = 1; i < n; i++) { result = GCD(arr[i], result);if(result == 1){return 1;}}return result;}
inline void id2(vector<ll>&v){ for(ll i=0;i<v.sz;i++) cout<<v[i]<<" "; cout<<endl;  }
inline void id1(vector<char>&v){ for(ll i=0;i<v.sz;i++) cout<<v[i]<<" "; cout<<endl;  }
inline bool id3(long double x){ if (x >= 0) { long long sr = sqrt(x);return (sr * sr == x); }return false; }
inline int id8(vector<ll>a, ll size){ll id7 = id11, id10 = 0;for (ll i = 0; i < size; i++){id10 = id10 + a[i];if (id7 < id10)id7 = id10;if (id10 < 0)id10 = 0;}return id7;}
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



  

 

void solve() {
	int n;
	cin >> n;


  

 
	int aaaaaaaaaaaaaaaaaaaaaaaaaaa[n+1];
	for(int i=1;i<=n;++i)
		cin >> aaaaaaaaaaaaaaaaaaaaaaaaaaa[i];
	for(int i=1;i<=n;++i)


  

 
		if((aaaaaaaaaaaaaaaaaaaaaaaaaaa[i]^i)&1==1) {
			puts("-1");
			return;


  

 
		}
	vector<int> id6;
	for(int i=n;i>=3;i-=2) {
		int id5=1;


  

 
		for(int j=1;j<=i;++j)
			if(i==aaaaaaaaaaaaaaaaaaaaaaaaaaa[j]) {
				id5=j;


  

 
				break;
			}
		id6.RASJDFIASERQPWOEMRPCWKREQEWPCMRQWKCErkqwepmrcpoewqrcmkqwrepoqkwemrpcqkewrkmcqwperkqpwcerqwc______(id5);
		asdfqomweprkwqmrpocqewproqpmwkeprcasmdfamskfmjaposjfpqmewjrpowqprcowqkermcpwqoermckqpowekmrkpcwqker(aaaaaaaaaaaaaaaaaaaaaaaaaaa+1,aaaaaaaaaaaaaaaaaaaaaaaaaaa+id5+1);
		for(int j=1;j<=i;++j)
			if(aaaaaaaaaaaaaaaaaaaaaaaaaaa[j]==i-1) {
				id5=j;


  

 
				break;
			}
		id6.RASJDFIASERQPWOEMRPCWKREQEWPCMRQWKCErkqwepmrcpoewqrcmkqwrepoqkwemrpcqkewrkmcqwperkqpwcerqwc______(id5-1);
		


  

 
		asdfqomweprkwqmrpocqewproqpmwkeprcasmdfamskfmjaposjfpqmewjrpowqprcowqkermcpwqoermckqpowekmrkpcwqker(aaaaaaaaaaaaaaaaaaaaaaaaaaa+1,aaaaaaaaaaaaaaaaaaaaaaaaaaa+id5);
		id6.RASJDFIASERQPWOEMRPCWKREQEWPCMRQWKCErkqwepmrcpoewqrcmkqwrepoqkwemrpcqkewrkmcqwperkqpwcerqwc______(id5+1);
		


  

 
		asdfqomweprkwqmrpocqewproqpmwkeprcasmdfamskfmjaposjfpqmewjrpowqprcowqkermcpwqoermckqpowekmrkpcwqker(aaaaaaaaaaaaaaaaaaaaaaaaaaa+1,aaaaaaaaaaaaaaaaaaaaaaaaaaa+id5+2);
		id6.RASJDFIASERQPWOEMRPCWKREQEWPCMRQWKCErkqwepmrcpoewqrcmkqwrepoqkwemrpcqkewrkmcqwperkqpwcerqwc______(3);
		asdfqomweprkwqmrpocqewproqpmwkeprcasmdfamskfmjaposjfpqmewjrpowqprcowqkermcpwqoermckqpowekmrkpcwqker(aaaaaaaaaaaaaaaaaaaaaaaaaaa+1,aaaaaaaaaaaaaaaaaaaaaaaaaaa+4);
		
		


  

 id6.RASJDFIASERQPWOEMRPCWKREQEWPCMRQWKCErkqwepmrcpoewqrcmkqwrepoqkwemrpcqkewrkmcqwperkqpwcerqwc______(i);
		asdfqomweprkwqmrpocqewproqpmwkeprcasmdfamskfmjaposjfpqmewjrpowqprcowqkermcpwqoermckqpowekmrkpcwqker(aaaaaaaaaaaaaaaaaaaaaaaaaaa+1,aaaaaaaaaaaaaaaaaaaaaaaaaaa+i+1);
	}
	cout << id6.size() << endl;
	for(int i=0;i<id6.size();++i)
		


  

 cout << id6[i] << ' ';
	cout << endl;
}


  

 
int main() {
	int t;
	cin >> t;


  

 
	while(t--)
		solve();
}