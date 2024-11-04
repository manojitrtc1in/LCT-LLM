
using namespace std;
const int N=2e3+5;
int T,n,m,ans,cnt;
int maxn[N],a[N][N],b[N][N],c[N][N],d[N*N],bb[N];
struct number{int x,id;}num[N];

inline bool cmp(number a,number b)
{
	return a.x>b.x;	
}
inline int max(int a,int b){return a>b?a:b;}

inline void solve()
{
	scanf("%d%d",&n,&m);
	cnt=0;
	for (register int j=1; j<=m; ++j) maxn[j]=0; 
	for (register int i=1; i<=n; ++i)
	{
		for (register int j=1; j<=m; ++j) 
		{
			scanf("%d",&a[i][j]);
			maxn[j]=max(maxn[j],a[i][j]);  

			d[++cnt]=a[i][j];
		}
	}
	for (register int i=1; i<=m; ++i)
	{
		num[i].x=maxn[i];
		num[i].id=i;
	}
	sort(num+1,num+m+1,cmp);
	m=min(m,n);
	for (register int i=1; i<=m; ++i)
	{
		for (register int j=1; j<=n; ++j) b[j][i]=a[j][num[i].id];
	}
	
	sort(d+1,d+cnt+1);
	reverse(d+1,d+cnt+1);
	int hh=0;
	for (register int i=1; i<=n; ++i) hh+=d[i];

	ans=0;	
	int hhh=0;
	for (register int j=1; j<=m; ++j)
	{
		int maxx=0,id;
		for (register int i=1; i<=n; ++i) 
		{
			bb[i]=b[i][j];
			if (bb[i]>maxx) maxx=bb[i],id=i;
		}
		hhh+=maxx;
	}
	ans=max(ans,hhh);
	if (ans==hh) return;
	
	if (m==1)
	{
		for (register int i1=1; i1<=n; ++i1)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==2)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==3)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		for (register int i3=1; i3<=n; ++i3) 
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==4)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		for (register int i3=1; i3<=n; ++i3) 
		for (register int i4=1; i4<=n; ++i4)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==5)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		for (register int i3=1; i3<=n; ++i3) 
		for (register int i4=1; i4<=n; ++i4)
		for (register int i5=1; i5<=n; ++i5)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==6)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		for (register int i3=1; i3<=n; ++i3)
		for (register int i4=1; i4<=n; ++i4)
		for (register int i5=1; i5<=n; ++i5)
		for (register int i6=1; i6<=n; ++i6)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==7)
	{
		for (register int t=1; t<=100000; ++t)
		{
			int i1,i2,i3,i4,i5,i6,i7;
			i1=rand()%n+1;
			i2=rand()%n+1;
			i3=rand()%n+1;
			i4=rand()%n+1;
			i5=rand()%n+1;
			i6=rand()%n+1;
			i7=rand()%n+1;
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}		
	}
	if (m==7)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		for (register int i3=1; i3<=n; ++i3)
		for (register int i4=1; i4<=n; ++i4)
		for (register int i5=1; i5<=n; ++i5)
		for (register int i6=1; i6<=n; ++i6)
		for (register int i7=1; i7<=n; ++i7)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==8)
	{
		for (register int t=1; t<=100000; ++t)
		{
			int i1,i2,i3,i4,i5,i6,i7,i8;
			i1=rand()%n+1;
			i2=rand()%n+1;
			i3=rand()%n+1;
			i4=rand()%n+1;
			i5=rand()%n+1;
			i6=rand()%n+1;
			i7=rand()%n+1;
			i8=rand()%n+1;
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}		
	}
	if (m==8)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		for (register int i3=1; i3<=n; ++i3)
		for (register int i4=1; i4<=n; ++i4)
		for (register int i5=1; i5<=n; ++i5)
		for (register int i6=1; i6<=n; ++i6)
		for (register int i7=1; i7<=n; ++i7)
		for (register int i8=1; i8<=n; ++i8)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==9)
	{
		for (register int t=1; t<=100000; ++t)
		{
			int i1,i2,i3,i4,i5,i6,i7,i8,i9;
			i1=rand()%n+1;
			i2=rand()%n+1;
			i3=rand()%n+1;
			i4=rand()%n+1;
			i5=rand()%n+1;
			i6=rand()%n+1;
			i7=rand()%n+1;
			i8=rand()%n+1;
			i9=rand()%n+1;
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			for (register int i=i9; i<=n; ++i) c[i-i9+1][9]=b[i][9];
			for (register int i=1; i<i9; ++i) c[n-i9+1+i][9]=b[i][9];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}		
	}
	if (m==10)
	{
		for (register int t=1; t<=100000; ++t)
		{
			int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
			i1=rand()%n+1;
			i2=rand()%n+1;
			i3=rand()%n+1;
			i4=rand()%n+1;
			i5=rand()%n+1;
			i6=rand()%n+1;
			i7=rand()%n+1;
			i8=rand()%n+1;
			i9=rand()%n+1;
			i10=rand()%n+1;
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			for (register int i=i9; i<=n; ++i) c[i-i9+1][9]=b[i][9];
			for (register int i=1; i<i9; ++i) c[n-i9+1+i][9]=b[i][9];
			for (register int i=i10; i<=n; ++i) c[i-i10+1][10]=b[i][10];
			for (register int i=1; i<i10; ++i) c[n-i10+1+i][10]=b[i][10];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==11)
	{
		for (register int t=1; t<=100000; ++t)
		{
			int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
			i1=rand()%n+1;
			i2=rand()%n+1;
			i3=rand()%n+1;
			i4=rand()%n+1;
			i5=rand()%n+1;
			i6=rand()%n+1;
			i7=rand()%n+1;
			i8=rand()%n+1;
			i9=rand()%n+1;
			i10=rand()%n+1;
			i11=rand()%n+1;
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			for (register int i=i9; i<=n; ++i) c[i-i9+1][9]=b[i][9];
			for (register int i=1; i<i9; ++i) c[n-i9+1+i][9]=b[i][9];
			for (register int i=i10; i<=n; ++i) c[i-i10+1][10]=b[i][10];
			for (register int i=1; i<i10; ++i) c[n-i10+1+i][10]=b[i][10];
			for (register int i=i11; i<=n; ++i) c[i-i11+1][11]=b[i][11];
			for (register int i=1; i<i11; ++i) c[n-i11+1+i][11]=b[i][11];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==12)
	{
		for (register int t=1; t<=100000; ++t)
		{
			int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
			i1=rand()%n+1;
			i2=rand()%n+1;
			i3=rand()%n+1;
			i4=rand()%n+1;
			i5=rand()%n+1;
			i6=rand()%n+1;
			i7=rand()%n+1;
			i8=rand()%n+1;
			i9=rand()%n+1;
			i10=rand()%n+1;
			i11=rand()%n+1;
			i12=rand()%n+1;
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			for (register int i=i9; i<=n; ++i) c[i-i9+1][9]=b[i][9];
			for (register int i=1; i<i9; ++i) c[n-i9+1+i][9]=b[i][9];
			for (register int i=i10; i<=n; ++i) c[i-i10+1][10]=b[i][10];
			for (register int i=1; i<i10; ++i) c[n-i10+1+i][10]=b[i][10];
			for (register int i=i11; i<=n; ++i) c[i-i11+1][11]=b[i][11];
			for (register int i=1; i<i11; ++i) c[n-i11+1+i][11]=b[i][11];
			for (register int i=i12; i<=n; ++i) c[i-i12+1][12]=b[i][12];
			for (register int i=1; i<i12; ++i) c[n-i12+1+i][12]=b[i][12];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
	if (m==13)
	{
		for (register int t=1; t<=100000; ++t)
		{
			int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13;
			i1=rand()%n+1;
			i2=rand()%n+1;
			i3=rand()%n+1;
			i4=rand()%n+1;
			i5=rand()%n+1;
			i6=rand()%n+1;
			i7=rand()%n+1;
			i8=rand()%n+1;
			i9=rand()%n+1;
			i10=rand()%n+1;
			i11=rand()%n+1;
			i12=rand()%n+1;
			i13=rand()%n+1;
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			for (register int i=i9; i<=n; ++i) c[i-i9+1][9]=b[i][9];
			for (register int i=1; i<i9; ++i) c[n-i9+1+i][9]=b[i][9];
			for (register int i=i10; i<=n; ++i) c[i-i10+1][10]=b[i][10];
			for (register int i=1; i<i10; ++i) c[n-i10+1+i][10]=b[i][10];
			for (register int i=i11; i<=n; ++i) c[i-i11+1][11]=b[i][11];
			for (register int i=1; i<i11; ++i) c[n-i11+1+i][11]=b[i][11];
			for (register int i=i12; i<=n; ++i) c[i-i12+1][12]=b[i][12];
			for (register int i=1; i<i12; ++i) c[n-i12+1+i][12]=b[i][12];
			for (register int i=i13; i<=n; ++i) c[i-i13+1][13]=b[i][13];
			for (register int i=1; i<i13; ++i) c[n-i13+1+i][13]=b[i][13];
			
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
		
	if (m==9)
	{
		for (register int i1=1; i1<=n; ++i1)
		for (register int i2=1; i2<=n; ++i2)
		for (register int i3=1; i3<=n; ++i3)
		for (register int i4=1; i4<=n; ++i4)
		for (register int i5=1; i5<=n; ++i5)
		for (register int i6=1; i6<=n; ++i6)
		for (register int i7=1; i7<=n; ++i7)
		for (register int i8=1; i8<=n; ++i8)
		for (register int i9=1; i9<=n; ++i9)
		{
			for (register int i=i1; i<=n; ++i) c[i-i1+1][1]=b[i][1];
			for (register int i=1; i<i1; ++i) c[n-i1+1+i][1]=b[i][1];
			for (register int i=i2; i<=n; ++i) c[i-i2+1][2]=b[i][2];
			for (register int i=1; i<i2; ++i) c[n-i2+1+i][2]=b[i][2];
			for (register int i=i3; i<=n; ++i) c[i-i3+1][3]=b[i][3];
			for (register int i=1; i<i3; ++i) c[n-i3+1+i][3]=b[i][3];
			for (register int i=i4; i<=n; ++i) c[i-i4+1][4]=b[i][4];
			for (register int i=1; i<i4; ++i) c[n-i4+1+i][4]=b[i][4];
			for (register int i=i5; i<=n; ++i) c[i-i5+1][5]=b[i][5];
			for (register int i=1; i<i5; ++i) c[n-i5+1+i][5]=b[i][5];
			for (register int i=i6; i<=n; ++i) c[i-i6+1][6]=b[i][6];
			for (register int i=1; i<i6; ++i) c[n-i6+1+i][6]=b[i][6];
			for (register int i=i7; i<=n; ++i) c[i-i7+1][7]=b[i][7];
			for (register int i=1; i<i7; ++i) c[n-i7+1+i][7]=b[i][7];
			for (register int i=i8; i<=n; ++i) c[i-i8+1][8]=b[i][8];
			for (register int i=1; i<i8; ++i) c[n-i8+1+i][8]=b[i][8];
			for (register int i=i9; i<=n; ++i) c[i-i9+1][9]=b[i][9];
			for (register int i=1; i<i9; ++i) c[n-i9+1+i][9]=b[i][9];
			int sum=0;
			for (register int i=1; i<=n; ++i)
			{
				int now=0;
				for (register int j=1; j<=m; ++j) now=max(now,c[i][j]);
				sum+=now;
			}
			ans=max(ans,sum);
			if (ans==hh) return;
		}
	}
}

int main(){




	

	

	srand(time(0));
	scanf("%d",&T);
	while (T--)
	{
		solve();
		printf("%d\n",ans);
	}
return 0;	
}