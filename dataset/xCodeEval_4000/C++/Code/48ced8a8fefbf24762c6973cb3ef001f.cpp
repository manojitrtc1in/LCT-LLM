
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
		int a,b,c;
		cin>>a>>b>>c;
		int maxii=max(a,max(b,c));
		int ans=2*maxii-(a+b+c);
		if(ans<=0) ans=1;
		else ans+=1;
		cout<<ans<<endl;
	}
	return 0;
}
