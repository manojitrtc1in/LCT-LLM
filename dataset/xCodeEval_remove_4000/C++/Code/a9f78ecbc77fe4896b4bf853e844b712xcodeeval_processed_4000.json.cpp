

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;







using namespace std;

char s1[maxn],s2[maxn];
int main(){
	int n,l,r,i,j,ans=0;
	scanf("%d%s%s",&n,s1,s2);
	for(l=0;s1[l]==s2[l];l++){}
	for(r=n-1;s1[r]==s2[r];r--){}
	for(i=l;i<r;i++) if(s1[i]!=s2[i+1]) break;
	if(i==r) ++ans;
	for(i=l;i<r;i++) if(s1[i+1]!=s2[i]) break;
	if(i==r) ++ans;
	printf("%d\n",ans);
    return 0;
}
