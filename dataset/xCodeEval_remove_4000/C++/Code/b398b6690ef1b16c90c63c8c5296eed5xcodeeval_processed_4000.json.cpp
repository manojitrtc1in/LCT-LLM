
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
 
 
 
 
 


  

 

using namespace std;

long long T,n,l,r,fac[200005],ifac[200005];
long long power(long long a,long long b) {
	long long res=1;
	while(b) {
		if(b&1) res=(res*a)%mod; 


  

 
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
long long C(long long a,long long b) {
	if(a<b||a<0||b<0) return 0;
	return ((fac[a]*ifac[b])%mod*ifac[a-b])%mod; 


  

 
}
signed main() {
	cin >> T;
	fac[1]=ifac[1]=fac[0]=ifac[0]=1;
	for(long long i=2; i<=200000; i++) {
		fac[i]=(fac[i-1]*i)%mod;
		ifac[i]=power(fac[i],mod-2); 


  

 
	}
	for(int i=1;i<=T;++i) {
		cin>>n>>l>>r;
		long long queryanswer=0;
		long long k=min(1-l,r-n);
		queryanswer=(queryanswer+k*C(n,n/2)%mod)%mod;
		if(n%2==1) queryanswer=(queryanswer+k*C(n,n/2)%mod)%mod;
		for(long long i=k+1; i<=k+n-1; i++) { 


  

 
			long long id0,id1;
			if(l-1+i<0) id0=0;
			else
				id0=l-1+i;
			if(n+i-r<0) id1=0; 


  

 
			else
				id1=n+i-r;
			if(id0+id1>n||id0>(n+n%2)/2||id1>(n+n%2)/2) break;
				queryanswer=(queryanswer+C(n-id0-id1,n/2-id0)%mod)%mod; 


  

 
			if(n%2!=0) 
				queryanswer=(queryanswer+C(n-id0-id1,(n+1)/2-id0)%mod)%mod;
		}
		cout << queryanswer << endl; 


  

 
	}
	return 0; 


  

 
} 


  

 