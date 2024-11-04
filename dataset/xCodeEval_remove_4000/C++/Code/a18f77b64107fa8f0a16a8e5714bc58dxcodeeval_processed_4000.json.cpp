





















































































































































































































using namespace std;





























typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vii;


int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
bool MI(int x){ 
	return x>0 and  (x&(x-1))==0;
}
int AA(int n,int m) {
	int tmp=1;
	for(int i=n-m+1; i<=n; i++) {
		tmp*=i;
	}
	return tmp;
}
int CC(int n,int m) {
	m=min(m,n-m);
	int res=1;
	for(int i=n; i>=(n-m+1);i--)res*= i;
	for(int i=2; i<=m;i++)res/= i;
	return res;
}
long long ksm(long long b, long long p) {
	long long res = 1;
	while(p != 0) {
		if((p & 1)!= 0) {
			res = res * b;
		}
		b =b*b;
		p >>= 1;
	}
	return res;
}
long long ksmm (long long b, long long p, long long k) {
	b %= k;
	long long res = 1;
	while (p > 0) {
		if (p & 1)
			res = res * b % k;
		b = b * b % k;
		p >>= 1;
	}
	return res;
}
bool isPrime( ll num ) {
	if(num==1)return 0;
	if(num ==2|| num==3 )
		return 1 ;
	if(num %6!= 1&&num %6!= 5)
		return 0 ;
	ll tmp =sqrt( num);
	for(ll i= 5; i <=tmp; i+=6 )
		if(num %i== 0||num %(i+ 2)==0 )
			return 0 ;
	return 1 ;
}
int Inv(int x,int mod){

	return ksmm(x,mod-2,mod);
} 
int gcd(int x,int y) {
	if(y==0)return x;
	else return gcd(y,x%y);
}
int lcm(int x,int y) {
	return x/gcd(x,y)*y;
}
struct Edge {
	int to,next,val;
};
struct node{
	int x,y;
};
bool cmp(int a,int b) {
	return a>b;
}


	

	

	

	



	

	

		

		

		

	

	

		

			

			

			

		

	


const int MOD=1e9+7;
const int mod=1e9+7;
const int M=2e5+10;
const int N=5e5+10;
const double eps=1e-12;
int tcs;
bool ok;
int a[N];
int n,m,k,x,y,Q;
int ans;
int fact[N];
int infact[N];

ll qmi(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}
void init() {
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = fact[i - 1] * i % mod;
	infact[N - 1] = qmi(fact[N - 1], mod - 2);
	for (int i = N - 2; i >= 1; i--)
		infact[i] = (ll)(i + 1) * infact[i + 1] % mod;
}
ll C(ll n, ll m) {
	if (n < m)
		return 0;
	return fact[n] * infact[m] % mod * infact[n - m] % mod;
}

void Solve(){
	map<int,int>hm;
	ans=0;
	cin>>n;
	rep(i,0,n)cin>>a[i];
	init();
	rep(i,0,n){
		ans+=C(a[i]+i,i+1);
		ans%=mod;
	}
	
	
	

	cout<<ans%mod<<endl;
}


signed main() {
	FAST();
	tcs=1;
	

	while(tcs--)Solve();
	return 0;
}