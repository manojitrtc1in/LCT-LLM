




















































































































































































































#include<bits/stdc++.h>
using namespace std;
#define lowbit(a) a&(-a)
#define FAST() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define NO {cout<<"NO"<<endl;return;}
#define YES {cout<<"YES"<<endl;return;}
#define No {cout<<"No"<<endl;return;}
#define Yes {cout<<"Yes"<<endl;return;}
#define AW {cout<<"Alice"<<endl;return;}
#define BW {cout<<"Bob"<<endl;return;}
#define GG {cout<<-1<<endl;return;}
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define dec(i,x,y) for(int i=x;i>=y;i--)
#define inf 0x7fffffff
#define INF 1e18 
#define mp make_pair
#define mem(x,y) memset(x,y,sizeof(x))
#define random(x) rand()%(x)
#define debug(x) std::cout << #x << " " << (x) << endl
#define pb push_back
#define int ll
#define endl "\n"
#define fi first
#define se second
#define cf() fflush(stdout)
#define all(x) x.begin()+1,x.end() 
#define ALL(x) x.begin(),x.end() 
#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
#define dbug(x) std::cout<<#x<<endl;for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<x[i][j]<<" ";cout<<endl;}
#define bug(x) std::cout<<#x<<endl;for(int i=1;i<=n;i++){cout<<x[i]<<" ";}cout<<endl;
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
const int mod=998244353;
const int M=2e5+10;
const int N=1e4+10;
const double eps=1e-12;
int tcs;
bool ok;
int a[N];
int n,m,k,x,y,Q;
int ans;
int res[N];
int vis[N];

void q1(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	cf();
	rep(i,l,r){
		cin>>a[i];
	}
	cf();
}

void gg(int x){
	cout<<"! "<<x<<endl;
	cf(); 
}

void Solve(){
	map<int,int>hm;
	ans=0;
	cin>>n;
	rep(i,1,n)a[i]=0;
	int len=2;
	ans=0;
	
	int last=1;
	vi g;
	int l=1;
	int r=n;
	
	while(l<=r){
		int mid=(l+r)/2;
		q1(l,mid);
		
		int hf=0;
		rep(i,l,mid){
			if(l<=a[i] and a[i]<=mid)hf++;
		}
		
		
		if(hf&1){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
		
	}
	
	gg(ans);


}


signed main() {
	tcs=1;
	cin>>tcs;
	while(tcs--)Solve();
	return 0;
}
