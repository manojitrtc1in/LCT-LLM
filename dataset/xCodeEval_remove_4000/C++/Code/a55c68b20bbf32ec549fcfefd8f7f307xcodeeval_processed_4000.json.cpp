





















































































































































































































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
	vector<int>a(n+1);rep(i,1,n)cin>>a[i];
	vi pos(n+1);
	rep(i,1,n)pos[a[i]]=i;
	
	int st[n+1][30];
	int st2[n+1][30];
	mem(st,0);
	mem(st2,0);
	
	function<int(int, int)> querymax = [&](int l,int r){
		int k=log2(r-l+1); 
		return max(st[l][k],st[r-(1<<k)+1][k]);
	};
	function<int(int, int)> querymin = [&](int l,int r){
		int k=log2(r-l+1); 
		return min(st2[l][k],st2[r-(1<<k)+1][k]);
	};
	
    for(int i=1;i<=n;i++)st[i][0]=a[i];
    for(int i=1;i<=n;i++)st2[i][0]=st[i][0];

    
    for(int j=1;j<=30;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
    	}
	}	
	
	function<int(int,int)> dfs = [&] (int L,int R){
	    if (L >= R)return 0LL;
	    if (L + 1 == R)return 1LL;
	    
	    int L_id = pos[querymin(L, R)];
	    int R_id = pos[querymax(L, R)];
	    if (L_id > R_id)swap(L_id, R_id);
	    
	    return dfs(L, L_id) + 1 + dfs(R_id, R);		
	};
	
	cout << dfs(1,n)<< endl;


}


signed main() {
	FAST();
	tcs=1;
	cin>>tcs;
	while(tcs--)Solve();
	return 0;
}
