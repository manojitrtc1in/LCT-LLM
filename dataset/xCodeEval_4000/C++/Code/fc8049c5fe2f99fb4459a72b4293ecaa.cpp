















































#include <bits/stdc++.h>
using namespace std;
long long int pow(long long int a,long long int b)
{
	long long int res=1;
	while(b--)
	{
		res*=a;
	}
	return res;
}
int main()
{	
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n,a,b;
		cin >> n >> a >> b ;
		long long int k=max(a,b);
		std::vector<long long int> v;
		if((a+b+2)<=n && abs(a-b)<=1)
		{
			for(int i=1;i<=n;i++)
			{
				v.push_back(i);
			}
			if(a>b)
			{
				long long int i=n-1;
				while(a--)
				{
					swap(v[i],v[i-1]);
					i-=2;
				}
			}
			else if(a<b)
			{
				long long int i=0;
				while(b--)
				{
					swap(v[i],v[i+1]);
					i+=2;
				}
			}
			else if(a==b)
			{
				long long int i=1;
				while(a--)
				{
					swap(v[i],v[i+1]);
					i+=2;
				}
			}
			for(int i=0;i<n;i++)
			{
				cout << v[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
}