





















































































































































































































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
	if(n<m)return 0;
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
bool cmp(int a,int b) {
	return a>b;
}


	

	

	

	



	

	

		

		

		

	

	

		

			

			

			

		

	


const int MOD=1e9+7;
const int mod=998244353;
const int M=2e5+10;
const int N=2e5+10;
const double eps=1e-12;
int tcs;
bool ok;


int n,m,k,x,y,Q;
int ans;



void Solve(){
	map<int,int>hm;
	ans=0;
	cin>>n;
	vector<int>b(n+1);rep(i,1,n)cin>>b[i];
	vi a(n+1);
	vii g[n+1];
	priority_queue<pii,vii,greater<pii>>q;
	rep(i,1,n){
		int l,r;
		if(b[i]==0){
			l=i+1;
			r=n;
		}else{
			l=i/(b[i]+1)+1;
			r=i/b[i];
		}
		if(l>r){
			swap(l,r);
		}
		g[l].pb(mp(r,i));
	}

	rep(i,1,n){
		for(pii p:g[i]){
			q.push(p);
		}
		auto u=q.top();q.pop();
		a[u.second]=i;
	}
	
	
	
	rep(i,1,n){
		cout<<a[i]<<" ";
	}
	cout<<endl;


}


signed main() {
	tcs=1;
	cin>>tcs;
	while(tcs--)Solve();
	return 0;
}