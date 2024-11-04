 
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n,m;
int a[N][N];
int cnt;
int ans[N*N][10];
bool check(int i,int j,int x1,int y1,int x2,int y2)
{return (x1<=i&&i<=x2&&y1<=j&&j<=y2);}
void find3(int i,int j,int x1,int y1,int x2,int y2)
{
	if(check(i+1,j,x1,y1,x2,y2)&&a[i+1][j]&&check(i,j+1,x1,y1,x2,y2)&&a[i][j+1])
	{
		cnt++;
		a[i][j]=a[i+1][j]=a[i][j+1]=0;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j+1;
		return;
	}
	if(check(i-1,j,x1,y1,x2,y2)&&a[i-1][j]&&check(i,j+1,x1,y1,x2,y2)&&a[i][j+1])
	{
		cnt++;
		a[i][j]=a[i-1][j]=a[i][j+1]=0;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i-1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j+1;
		return;
	}
	if(check(i+1,j,x1,y1,x2,y2)&&a[i+1][j]&&check(i,j-1,x1,y1,x2,y2)&&a[i][j-1])
	{
		cnt++;
		a[i][j]=a[i+1][j]=a[i][j-1]=0;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j-1;
		return;
	}
	if(check(i-1,j,x1,y1,x2,y2)&&a[i-1][j]&&check(i,j-1,x1,y1,x2,y2)&&a[i][j-1])
	{
		cnt++;
		a[i][j]=a[i-1][j]=a[i][j-1]=0;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i-1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j-1;
		return;
	}
	return;
}
void find_2(int i,int j,int x1,int y1,int x2,int y2)
{
	
	if(check(i,j+2,x1,y1,x2,y2)&&a[i][j+2])
	{
		if(i+1<=x2)
		{
			a[i][j]=a[i][j+2]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i,ans[cnt][4]=j+1;
			ans[cnt][5]=i+1,ans[cnt][6]=j+1;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j+2;
			ans[cnt][3]=i,ans[cnt][4]=j+1;
			ans[cnt][5]=i+1,ans[cnt][6]=j+1;
			return;
		}
		else
		{
			a[i][j]=a[i][j+2]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i,ans[cnt][4]=j+1;
			ans[cnt][5]=i-1,ans[cnt][6]=j+1;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j+2;
			ans[cnt][3]=i,ans[cnt][4]=j+1;
			ans[cnt][5]=i-1,ans[cnt][6]=j+1;
			return;
		}
	}
	if(check(i+2,j,x1,y1,x2,y2)&&a[i+2][j])
	{
		if(j+1<=y2)
		{
			a[i][j]=a[i+2][j]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i+1,ans[cnt][4]=j+1;
			ans[cnt][5]=i+1,ans[cnt][6]=j;
			cnt++;
			ans[cnt][1]=i+2,ans[cnt][2]=j;
			ans[cnt][3]=i+1,ans[cnt][4]=j+1;
			ans[cnt][5]=i+1,ans[cnt][6]=j;
			return;
		}
		else
		{
			a[i][j]=a[i+2][j]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i+1,ans[cnt][4]=j-1;
			ans[cnt][5]=i+1,ans[cnt][6]=j;
			cnt++;
			ans[cnt][1]=i+2,ans[cnt][2]=j;
			ans[cnt][3]=i+1,ans[cnt][4]=j-1;
			ans[cnt][5]=i+1,ans[cnt][6]=j;
			return;
		}
	}
	if(check(i-1,j+2,x1,y1,x2,y2)&&a[i-1][j+2])
	{
		a[i][j]=a[i-1][j+2]=0;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i-1,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i-1,ans[cnt][2]=j+2;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i-1,ans[cnt][6]=j+1;
		return;
	}
	if(check(i+1,j+2,x1,y1,x2,y2)&&a[i+1][j+2])
	{
		a[i][j]=a[i+1][j+2]=0;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i+1,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i+1,ans[cnt][2]=j+2;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i+1,ans[cnt][6]=j+1;
		return;
	}
	if(check(i+2,j+1,x1,y1,x2,y2)&&a[i+2][j+1])
	{
		a[i][j]=a[i+2][j+1]=0;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i+1,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i+2,ans[cnt][2]=j+1;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i+1,ans[cnt][6]=j+1;
		return;
	}
	if(check(i+2,j-1,x1,y1,x2,y2)&&a[i+2][j-1])
	{
		a[i][j]=a[i+2][j-1]=0;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i+1,ans[cnt][6]=j-1;
		cnt++;
		ans[cnt][1]=i+2,ans[cnt][2]=j-1;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i+1,ans[cnt][6]=j-1;
		return;
	}
	return;
}
void find2(int i,int j,int x1,int y1,int x2,int y2)
{
	if(check(i,j+1,x1,y1,x2,y2)&&a[i][j+1])
	{
		if(i+1<=x2)
		{
			a[i][j]=a[i][j+1]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i+1,ans[cnt][4]=j;
			ans[cnt][5]=i+1,ans[cnt][6]=j+1;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j+1;
			ans[cnt][3]=i+1,ans[cnt][4]=j;
			ans[cnt][5]=i+1,ans[cnt][6]=j+1;
			return;
		}
		else
		{
			a[i][j]=a[i][j+1]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i-1,ans[cnt][4]=j;
			ans[cnt][5]=i-1,ans[cnt][6]=j+1;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j+1;
			ans[cnt][3]=i-1,ans[cnt][4]=j;
			ans[cnt][5]=i-1,ans[cnt][6]=j+1;
			return;
		}
	}
	if(check(i+1,j,x1,y1,x2,y2)&&a[i+1][j])
	{
		if(j+1<=y2)
		{
			a[i][j]=a[i+1][j]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i,ans[cnt][4]=j+1;
			ans[cnt][5]=i+1,ans[cnt][6]=j+1;
			cnt++;
			ans[cnt][1]=i+1,ans[cnt][2]=j;
			ans[cnt][3]=i,ans[cnt][4]=j+1;
			ans[cnt][5]=i+1,ans[cnt][6]=j+1;
			return;
		}
		else
		{
			a[i][j]=a[i+1][j]=0;
			cnt++;
			ans[cnt][1]=i,ans[cnt][2]=j;
			ans[cnt][3]=i,ans[cnt][4]=j-1;
			ans[cnt][5]=i+1,ans[cnt][6]=j-1;
			cnt++;
			ans[cnt][1]=i+1,ans[cnt][2]=j;
			ans[cnt][3]=i,ans[cnt][4]=j-1;
			ans[cnt][5]=i+1,ans[cnt][6]=j-1;
			return;
		}
	}
	if(check(i+1,j+1,x1,y1,x2,y2)&&a[i+1][j+1])
	{
		a[i][j]=a[i+1][j+1]=0;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i+1,ans[cnt][2]=j+1;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j+1;
		return;
	}
	if(check(i+1,j-1,x1,y1,x2,y2)&&a[i+1][j-1])
	{
		a[i][j]=a[i+1][j-1]=0;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j-1;
		cnt++;
		ans[cnt][1]=i+1,ans[cnt][2]=j-1;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i,ans[cnt][6]=j-1;
		return;
	}
	return;
}
void find1(int i,int j,int x1,int y1,int x2,int y2)
{
	a[i][j]=0;
	if(i+1<=x2&&j+1<=y2)
	{
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i+1,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i+1,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i+1,ans[cnt][6]=j;
	}
	else if(i+1<=x2&&j-1>=y1)
	{
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j-1;
		ans[cnt][5]=i+1,ans[cnt][6]=j-1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i+1,ans[cnt][4]=j;
		ans[cnt][5]=i+1,ans[cnt][6]=j-1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j-1;
		ans[cnt][5]=i+1,ans[cnt][6]=j;
	}
	else if(i-1>=x1&&j+1<=y2)
	{
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i-1,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i-1,ans[cnt][4]=j;
		ans[cnt][5]=i-1,ans[cnt][6]=j+1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j+1;
		ans[cnt][5]=i-1,ans[cnt][6]=j;
	}
	else
	{
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i-1,ans[cnt][4]=j;
		ans[cnt][5]=i-1,ans[cnt][6]=j-1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j-1;
		ans[cnt][5]=i-1,ans[cnt][6]=j-1;
		cnt++;
		ans[cnt][1]=i,ans[cnt][2]=j;
		ans[cnt][3]=i,ans[cnt][4]=j-1;
		ans[cnt][5]=i-1,ans[cnt][6]=j;
	}
}
void gao(int x1,int y1,int x2,int y2)
{
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			if(a[i][j]) find3(i,j,x1,y1,x2,y2);
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			if(a[i][j]) find_2(i,j,x1,y1,x2,y2);
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			if(a[i][j]) find2(i,j,x1,y1,x2,y2);
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			if(a[i][j]) find1(i,j,x1,y1,x2,y2);
} 
int main()
{
	char c;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				c=getchar();
				while(c!='0'&&c!='1') c=getchar();
				a[i][j]=c-'0';
			}
		if(n%2==0&&m%2==0)
		{
			for(int i=1;i<=n;i+=2)
				for(int j=1;j<=m;j+=2)
					gao(i,j,i+1,j+1);
		}
		else if(n%2!=0&&m%2==0)
		{
			for(int j=1;j<=m;j+=2) gao(1,j,3,j+1);
			for(int i=4;i<=n;i+=2)
				for(int j=1;j<=m;j+=2)
					gao(i,j,i+1,j+1);
		}
		else if(n%2==0&&m%2!=0)
		{
			for(int i=1;i<=n;i+=2) gao(i,1,i+1,3);
			for(int i=1;i<=n;i+=2)
				for(int j=4;j<=m;j+=2)
					gao(i,j,i+1,j+1);
		}
		else
		{
			gao(1,1,3,3);
			for(int j=4;j<=m;j+=2) gao(1,j,3,j+1);
			for(int i=4;i<=n;i+=2) gao(i,1,i+1,3);
			for(int i=4;i<=n;i+=2)
				for(int j=4;j<=m;j+=2)
					gao(i,j,i+1,j+1);
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
			printf("%d %d %d %d %d %d\n",ans[i][1],ans[i][2],ans[i][3],ans[i][4],ans[i][5],ans[i][6]);
	}	
	return 0;
}
