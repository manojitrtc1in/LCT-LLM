
using namespace std;


int a[1000005];
int dp[1000005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		dp[a[i]]=1;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=a[i]+a[i];j<=1000000;j+=a[i])
		{
			dp[j]=max(dp[a[i]]+1,dp[j]);
		}
		ans=max(dp[a[i]],ans);
	}
	cout<<ans;
	return 0;
}
