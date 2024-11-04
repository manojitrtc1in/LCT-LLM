

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

int a[maxn],b[maxn],c[maxn];
vi v;
int main() {
	map<int,int> mp;
    int n,p,k;
    ll ans=0;
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		b[i]=(1ll*a[i]*a[i]%p*a[i]%p*a[i]%p-1ll*k*a[i]%p+p)%p;
		++mp[b[i]];
		
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		ans+=1ll*(it->S)*((it->S)-1)/2;
	}
	printf("%lld\n",ans);
    return 0;
}