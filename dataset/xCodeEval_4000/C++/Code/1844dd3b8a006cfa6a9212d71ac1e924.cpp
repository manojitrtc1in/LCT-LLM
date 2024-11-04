

































#include <bits/stdc++.h>
using namespace std;



int num[10005];
int dp1[10005];
int prime1[]={2,3,5,7,11,13,17,19,23,29,31};
int prime2[]={37,41,43,47,53,59,61,67};
int cnt[10005];
int dp2[10005];
int j;
int mod=1e9+7;





int main()
{
	int n;
	cin>>n;
	dp2[0]=1;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		for(j=0;j<8;j++)
		{
			if(t==prime2[j])
				break;
		}
		if(j<8)
		{
			cnt[j]++;
			continue;
		}
		int mask=0;
		for(j=0;j<11;j++)
		{
			int c=0;
			while(t%prime1[j]==0)
			{
				c++;
				t/=prime1[j];
			}
			if(c%2)
			{
				mask|=(1<<j);
			}
		}
		for(j=0;j<(1<<11);j++)
		{
			dp1[j]=(dp2[j]+dp2[j^mask])%mod;
		}
		for(j=0;j<(1<<11);j++)
		{
			dp2[j]=dp1[j];
		}
	}
	int ans=dp2[0];
	for(int i=0;i<8;i++)
	{
		for(int j=1;j<=cnt[i]-1;j++)
		{
			ans=(ans*2)%mod;
		}
	}
	cout<<(ans-1)%mod;
	return 0;
}