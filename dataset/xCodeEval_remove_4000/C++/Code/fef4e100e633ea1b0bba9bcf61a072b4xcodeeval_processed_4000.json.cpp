






using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
typedef pair<pii,pii > piiii;
const int INF=1e9+7;
const int hash1=20041123;
const int hash2=20050208; 
typedef long long ll;
const int MOD=1e9+7;
using namespace std;
const int Maxn=200005;
const int arg1=0x3a5a9;
const int arg2=1000007;
const int mod1=1000000007,mod2=998244353; 
int n,m;
char str[Maxn];
ll pw1[Maxn],pw2[Maxn];
pair <ll,ll> H[26][Maxn];

pair <ll,ll> Get(pair <ll,ll> H[],int l,int r)
{
	pair <ll,ll> ans=H[r];
	if (--l>=0) ans=make_pair((ans.first-H[l].first*pw1[r-l]%mod1+mod1)%mod1,(ans.second-H[l].second*pw2[r-l]%mod2+mod2)%mod2);
	return ans;
}
int main()
{
	pw1[0]=pw2[0]=1;
	for (int i=1;i<Maxn;i++)
	{
		pw1[i]=pw1[i-1]*arg1%mod1;
		pw2[i]=pw2[i-1]*arg2%mod2;
	}
	scanf("%d %d",&n,&m);
	scanf("%s",str+1);
	for (int i=1;i<=n;i++)
	for (int j=0;j<26;j++)
	{
		H[j][i].first=(H[j][i-1].first*arg1+1+('a'+j==str[i]))%mod1;
		H[j][i].second=(H[j][i-1].second*arg2+1+('a'+j==str[i]))%mod2;
	}
	while (m--)
	{
		int x,y,len;
		scanf("%d %d %d",&x,&y,&len);
		multiset <pair <ll,ll> > A,B;
		for (int i=0;i<26;i++)
		{
			A.insert(Get(H[i],x,x+len-1));
			B.insert(Get(H[i],y,y+len-1));
		}
		printf("%s\n",A==B?"YES":"NO");
	}
	return 0;
}