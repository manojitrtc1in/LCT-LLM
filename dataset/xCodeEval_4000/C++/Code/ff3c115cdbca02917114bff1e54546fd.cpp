
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<ctime>
#include<cmath>
#include<map>
using namespace std;
#define N 100005

int n,a[N],f[N][2];

int gcd(int a,int b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	int t=a[1];
	for (int i=2;i<=n;++i) t=gcd(t,a[i]);
	if (t>1)
	{
		puts("YES");
		puts("0");
		return 0;
	}
	memset(f,127,sizeof(f));
	if (a[1]&1) f[1][1]=0;else f[1][0]=0;
	for (int i=2;i<=n;++i)
		if (a[i]&1)
		{
			f[i][0]=min(f[i-1][0]+2,f[i-1][1]+1);
			f[i][1]=min(f[i-1][0],f[i-1][1]+2);
		}
		else
		{
			f[i][0]=min(f[i-1][0],f[i-1][1]+2);
			f[i][1]=f[i-1][1]+3;
		}
	puts("YES");
	printf("%d\n",f[n][0]);
}
