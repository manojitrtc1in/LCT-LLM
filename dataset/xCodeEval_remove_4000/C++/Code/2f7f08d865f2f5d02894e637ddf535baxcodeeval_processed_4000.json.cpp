

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;









using namespace std;

char s[maxn];
ii ans[maxn];
int main(){
	int T,n,k,f,l,cnt=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,s);
		f=n/2-k+1;l=n-(k-1)*2;cnt=0;
		for(int i=0;i<n;++i){
			if(i<f||i>=l&&i%2==0){
				for(int j=i;j<n;++j){
					if(s[j]=='('){
						ans[++cnt]=ii(i+1,j+1);
						reverse(s+i,s+j+1);
						break;
					}
				}
			}else{
				for(int j=i;j<n;++j){
					if(s[j]==')'){
						ans[++cnt]=ii(i+1,j+1);
						reverse(s+i,s+j+1);
						break;
					}
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i){
			printf("%d %d\n",ans[i].F,ans[i].S);
		}
	}
    return 0;
}