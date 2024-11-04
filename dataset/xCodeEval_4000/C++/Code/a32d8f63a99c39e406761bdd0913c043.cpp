
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int ans=-1;
		for(int i=1;i<=3;i++)
		{
			int x;
			cin>>x;
			ans=max(x,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
 } 