






#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[1001],dp1[9][1001],dp2[1001][1<<9];
int cut(int pos, int l, int num)

{
	 l = dp1[num][pos] + l;
	 if (dp1[num][n] < l)
		 return 1000000000;
	 int ll = 1;
	 int rr = n;
	 while (ll < rr)
	 {
		 int mid = (ll + rr) >> 1;
		 if (dp1[num][mid] >= l)
			 rr = mid - 1;
		 else
			 ll = mid + 1;
	 }
	 if (dp1[num][ll] != l)
		 ll++;
	 return ll;
}
int count(int k)
{
	int ans = 0;
	for (int i = 0; i <8; i++)
	{
		if (((k>>i)&1) == 1)
			ans++;
	}
	return ans;
}
int ans = -1;
int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= 8; i++)
	for (int j = 1; j <= n; j++)
	{
		if (a[j] == i)
		{
			dp1[i][j] = dp1[i][j - 1] + 1;
		}
		else
		{
			dp1[i][j] = dp1[i][j - 1];
		}
	}
	

	for (int l = 1; l <= n/8+5; l++)
	{
		for (int i = 1; i <= n; i++)
		for (int k = 0; k <= (1 << 8) - 1; k++)
			dp2[i][k] = -1;
		dp2[1][0] = 0;
		for (int i = 1; i <= n; i++)
		for (int k = 0; k <= (1 << 8) - 1; k++)
		{
			if (dp2[i][k] == -1)
				continue;
			for (int j = 0; j <8; j++)
			{
	
				if (((k >> j) & 1) == 0)
				{
					int ll;
					if (i == 1)
					{
						ll = cut(i - 1,  l, j + 1);
					}
					else
					{
						ll = cut(i, l, j + 1);
					}
					if (ll <= n)
					{
						dp2[ll][k | (1 << j)] = max(dp2[ll][k | (1 << j)], dp2[i][k] + l);
					

						

					}
					if (i == 1)
					{
						ll = cut(i - 1, l+1, j + 1);
					}
					else
					{
						ll = cut(i, l+1, j + 1);
					}
					if (ll <= n)
					{
						dp2[ll][k | (1 << j)] = max(dp2[ll][k | (1 << j)], dp2[i][k] + l + 1);
					}
				}
			}
		}
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j < (1 << 8) - 1; j++)
			{
				if (dp2[i][j] != -1)
					ans = max(ans, count(j));
			}
			ans = max(ans, dp2[i][(1 << 8) - 1]);
		
		}
	

	}
	printf("%d\n", ans);
	
	return 0;
}