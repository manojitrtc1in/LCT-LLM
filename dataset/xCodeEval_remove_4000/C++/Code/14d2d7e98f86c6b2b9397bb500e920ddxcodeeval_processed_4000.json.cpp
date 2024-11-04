

using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;









using namespace std;


struct MAT{
	int x,y;
	ll a[5][5];
	MAT(){x=0;y=0;memset(a,0,sizeof(a));}
	inline MAT operator *(MAT &m){
		assert(y==m.x);
		MAT ans;
		ans.x=x;
		ans.y=m.y;
		for(int i=0;i<ans.x;i++){
			for(int j=0;j<ans.y;j++){
				for(int k=0;k<y;k++){
					ans.a[i][j]=(ans.a[i][j]+a[i][k]*m.a[k][j]%_mod)%_mod;
				}
			}
		}
		return ans;
	}
};
inline ll mi(ll x,ll p){
	if(p==0) return 1;
	if(p==1) return x%mod;
	ll t=mi(x,p>>1);
	if(p&1) return t*t%mod*x%mod;
	return t*t%mod;
}
inline MAT mi(MAT &x,ll p){
	if(p==1) return x;
	MAT t=mi(x,p>>1);
	if(p&1) return t*t*x;
	return t*t;
}
int main(){
    ll n,k1,k2,k3,c,ans=1;
    scanf("%lld%lld%lld%lld%lld",&n,&k1,&k2,&k3,&c);
    MAT m1,mc,mk,mr,mt1;
    m1.x=3;m1.y=3;
    m1.a[0][0]=1;
    m1.a[0][1]=1;
    m1.a[2][0]=1;
    m1.a[1][0]=1;
    m1.a[1][2]=1;
    mt1=mi(m1,n-3);
    mk.x=1;mk.y=3;
    mk.a[0][0]=1;
    mk.a[0][1]=0;
    mk.a[0][2]=0;
    mr=mk*mt1;
    

    ans=ans*mi(k3,mr.a[0][0])%mod;
    mk.a[0][0]=0;
    mk.a[0][1]=1;
    mr=mk*mt1;
    

    ans=ans*mi(k2,mr.a[0][0])%mod;
    mk.a[0][1]=0;
    mk.a[0][2]=1;
    mr=mk*mt1;
    

    ans=ans*mi(k1,mr.a[0][0])%mod;
    mc.x=5;mc.y=5;
    mc.a[0][0]=1;
    mc.a[0][1]=1;
    mc.a[1][0]=1;
    mc.a[1][2]=1;
    mc.a[2][0]=1;
	mc.a[3][0]=1;
	mc.a[3][3]=1;
	mc.a[4][3]=1;
	mc.a[4][4]=1;
	mk.y=5;
	mk.a[0][2]=0;
	mk.a[0][3]=2;
	mk.a[0][4]=2;
	mt1=mi(mc,n-3);
	mr=mk*mt1;
	

	ans=ans*mi(c,mr.a[0][0])%mod;
    printf("%lld\n",ans);
    return 0;
}