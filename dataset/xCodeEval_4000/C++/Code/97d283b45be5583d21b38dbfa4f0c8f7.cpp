









#include<bits/stdc++.h>
using namespace std;

int n,sum[1100];

main()
{
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		cout<<"? 1 "<<i<<endl;
		cin>>sum[i];
	}
	cout<<"? 2 "<<n<<endl;
	cin>>sum[1];
	cout<<"! "<<sum[n]-sum[1]<<' '<<sum[2]+sum[1]-sum[n];
	for(int i=3;i<=n;++i)
	{
		cout<<" "<<sum[i]-sum[i-1];
	}
	return 0;
}












