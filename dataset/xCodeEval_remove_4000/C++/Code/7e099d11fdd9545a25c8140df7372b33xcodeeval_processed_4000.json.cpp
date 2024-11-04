





















































































































































































































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
	cin>>n>>m;
	int a[n+1][m+1];
	int c=1;
	int q[4]={1,0,0,1};
	int p[4]={0,1,1,0};
	
	
	if(n%4==0){
		rep(i,1,n){
			if(i%4==1 or i%4==0){
				int g=0;
				rep(j,1,m){
					a[i][j]=q[g];
					g++;g%=4;
				}
			}else{
				int g=0;
				rep(j,1,m){
					a[i][j]=p[g];
					g++;g%=4;
				}			
			}
		}		
		
	}
	
	else{

	rep(i,1,n-2){
		if(i%4==1 or i%4==0){
			int g=0;
			rep(j,1,m){
				a[i][j]=q[g];
				g++;g%=4;
			}
		}else{
			int g=0;
			rep(j,1,m){
				a[i][j]=p[g];
				g++;g%=4;
			}			
		}
	}
	
	rep(i,n-1,n){
		if(i==n-1){
			int g=0;
			rep(j,1,m){
				a[i][j]=q[g];
				g++;g%=4;
			}
		}else{
			int g=0;
			rep(j,1,m){
				a[i][j]=p[g];
				g++;g%=4;
			}			
		}
	}

	}
	rep(i,1,n){
		rep(j,1,m){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	
	



}


signed main() {
	FAST();
	tcs=1;
	cin>>tcs;
	while(tcs--)Solve();
	return 0;
}