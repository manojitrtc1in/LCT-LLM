















using namespace std;






int dp[9000000];
int n;
double sol(int p, int t)
{
	if (p == n*n-1)
	{
		return dp[p] = 1.0 + sol(p-1,(t+1)%2);
	}
	if (p == 0)
	{
		return dp[p] = 0.0;
	}
	if (dp[p] != 0) return dp[p];
	if (p == 1)
	{
		return dp[p] = 1.0 + sol(p-1,(t+1)%2);
	}
	else
	{
		return dp[p] = 4+sol(p-2,(t+1)%2);
	}
}
int main()
{
	cin>>n;
	vector<int> aa(n);
	
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>aa[i];
		for (int j = 0; j < i; j++)
		{
			if (aa[j] > aa[i])
			{
				p++;
			}
		}
	}
	int res = sol(p,0);
	cout<<res<<endl;
}