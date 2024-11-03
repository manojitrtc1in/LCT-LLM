


using namespace std;
int a[8010], s[8010];
int vis[8010]; 
int main()
{
	int t;
	cin >> t;
	int n, k;
	while(t--)
	{
		
		scanf("%d", &n);
		memset(s, 0, sizeof s);
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			s[i] = s[i - 1] + a[i];
			vis[a[i]]++;
		}
		
		int ans = 0;
		int m = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
			{
				int t = s[j] - s[i - 1];
				if(t > n) continue;
				if(vis[t])
				{
					ans += vis[t];
					

					vis[t] = 0;
				}
					
			}
				
	

		cout <<ans <<endl;
	}
	
	return 0;
}

