#include<bits/stdc++.h>

#define inr int
#define rpt(n) for(register inr ttxyc=0;ttxyc<n;++ttxyc)

using namespace std;
inline int read()

{
	register int x=0,t=0;register char c=getchar();
	for(;c<'0'||c>'9';t|=c=='-',c=getchar());
	for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=getchar());
	return t?-x:x;
}
int n,a[1000];

































































































































































main()
{
	n=read();rpt(n)a[ttxyc]=read();
	
	sort(a,a+n);
	
	rpt(n/2)printf("%d %d ",a[ttxyc],a[n-ttxyc-1]);
	
	if(n&1)printf("%d",a[n/2]);
	
}