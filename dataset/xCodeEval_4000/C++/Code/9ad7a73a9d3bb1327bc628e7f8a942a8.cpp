#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<queue>
using namespace std;
int t;
long long x[5],y[5];
int vzt[5][5][5][5];
int dy[5];
int jdg(int n1,int n2,int n3,int n4)
{
	int r[5];
	r[1]=0;
	r[2]=0;
	r[3]=0;
	r[4]=0;
	r[n1]++;
	r[n2]++;
	r[n3]++;
	r[n4]++;
	if(r[1]==1&&r[2]==1&&r[3]==1&&r[4]==1)
		return 0;
	return 1;	
}
long long cal(int n1,int n2,int n3,int n4)
{
	long long anss=1000000000000ll;
	x[0]=0;
	y[0]=0;
	dy[0]=0;
	long long a,b,l;
	for(int ia=0;ia<=4;ia++)
		for(int ib=0;ib<=4;ib++)
			for(int il=0;il<=4;il++)
			{
				a=x[ia];
				b=y[ib];
				l=abs(x[il]-a);
				anss=min(anss,abs(x[dy[1]]-a)+abs(y[dy[1]]-b)+abs(x[dy[2]]-a)+abs(y[dy[2]]-b-l)+abs(x[dy[3]]-a-l)+abs(y[dy[3]]-b)+abs(x[dy[4]]-a-l)+abs(y[dy[4]]-b-l));
				l=-l;
				anss=min(anss,abs(x[dy[1]]-a)+abs(y[dy[1]]-b)+abs(x[dy[2]]-a)+abs(y[dy[2]]-b-l)+abs(x[dy[3]]-a-l)+abs(y[dy[3]]-b)+abs(x[dy[4]]-a-l)+abs(y[dy[4]]-b-l));
				a=x[ia];
				b=y[ib];
				l=abs(y[il]-b);
				anss=min(anss,abs(x[dy[1]]-a)+abs(y[dy[1]]-b)+abs(x[dy[2]]-a)+abs(y[dy[2]]-b-l)+abs(x[dy[3]]-a-l)+abs(y[dy[3]]-b)+abs(x[dy[4]]-a-l)+abs(y[dy[4]]-b-l));
				l=-l;
				anss=min(anss,abs(x[dy[1]]-a)+abs(y[dy[1]]-b)+abs(x[dy[2]]-a)+abs(y[dy[2]]-b-l)+abs(x[dy[3]]-a-l)+abs(y[dy[3]]-b)+abs(x[dy[4]]-a-l)+abs(y[dy[4]]-b-l));
				
			}
	

	

	
	return anss;
}
int main()
{
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++)
	{
		for(int i=1;i<=4;i++)
			scanf("%lld%lld",&x[i],&y[i]); 
		long long ans=100000000000ll;
		for(int i1=1;i1<=4;i1++)
			for(int i2=1;i2<=4;i2++)
				for(int i3=1;i3<=4;i3++)
					for(int i4=1;i4<=4;i4++)
						vzt[i1][i2][i3][i4]=0;
		for(int i1=1;i1<=4;i1++)
			for(int i2=1;i2<=4;i2++)
				for(int i3=1;i3<=4;i3++)
					for(int i4=1;i4<=4;i4++)
						if(vzt[i1][i2][i3][i4]==0&&jdg(i1,i2,i3,i4)==0) 
						{
							dy[i1]=1;
							dy[i2]=2;
							dy[i3]=3;
							dy[i4]=4;
							ans=min(ans,cal(i1,i2,i3,i4));
						}
		printf("%lld\n",ans);
	}
	return 0;
}


