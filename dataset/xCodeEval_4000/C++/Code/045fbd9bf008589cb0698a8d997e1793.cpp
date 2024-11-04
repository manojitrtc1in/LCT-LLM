#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
const int MOD=998244353;
int t,ang;

int uc(int a,int b)
{
	while (b>0)
	{
		int r=a%b;
		a=b;b=r;
	}
	return a;
}

int main()
{
	IOS;
	cin>>t;
	while (t-->0) 
	{
		cin>>ang;
		int r=uc(180,ang),n=180/r;
		ang/=r;
		if (n-1==ang) n*=2;
		cout<<n<<"\n";
	}
}

