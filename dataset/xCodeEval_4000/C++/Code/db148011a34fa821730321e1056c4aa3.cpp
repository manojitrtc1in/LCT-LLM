
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long 
using namespace std;
const int maxn=100005;
int n,m,sum,ssum,pre=1,l[maxn];
bool cmp(int a,int b)
{
	return a > b;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(register int i=1;i<=m;i++)
	{
		scanf("%lld",&l[i]);
		if(l[i]>n)
		{
			printf("-1\n");
			return 0;
		}
		sum+=l[i];
	}
	if(sum<n)
	{
		printf("-1\n");
		return 0;
	}


	ssum=sum-l[1];sum-=l[1];
	for(register int i=2;i<=m;i++)
	{
		if(pre+sum>=n)
		{


			pre++;sum-=l[i];
		}
		else
		{


			pre=n-sum+1;
			sum-=l[i];
		}
		if(pre+l[i]-1>n)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("1 ");
	pre=1;
	for(register int i=2;i<=m;i++)
	{
		if(pre+ssum>=n)
		{
			printf("%lld ",pre+1);
			pre++;ssum-=l[i];
		}
		else
		{
			printf("%lld ",n-ssum+1);
			pre=n-ssum+1;
			ssum-=l[i];
		}
	}
	return 0;
}