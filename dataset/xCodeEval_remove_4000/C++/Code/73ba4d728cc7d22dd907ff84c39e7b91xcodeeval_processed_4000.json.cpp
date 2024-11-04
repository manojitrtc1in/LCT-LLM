

using namespace std;


int main() {

	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int m[8005]={0};
        ll check=0;
        int dp[n+1]={0};
        

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+a[i-1];
        }
        int ans=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ll temp=dp[j]-dp[i-1];
                if(temp>n)
                {
                    break;
                }
                if(m[temp]>0)
                {
                    ans+=m[temp];
                    m[temp]=0;
                }
            }
        }
        cout<<ans<<endl;
    }
	
}







































































































