























































using namespace std;







typedef long long ll;




























int a[222222];
int c[222222];
int b[444444];
int gc[222222];
ll ans;
int mx[222222];
int n;

inline id0(int a,int b)
{
	if(a%b==0)
	{
		return b;
	}
	return id0(b,a%b);
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	
	for(int i=1;i<n;i++)
	{
		gc[i]=id0(i,n);
	}
	
	for(int k=1;k<n;k++)
	{
		if(n%k) continue;
		
		for(int i=1;i<n;i++)
		{
			c[i]=c[i-1]+(gc[i]==k);
		}
		
		for(int i=0;i<k;i++)
		{
			mx[i]=-1;
		}
		
		for(int i=0;i<n;i++)
		{
			mx[i%k]=max(mx[i%k],a[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			if(a[i]==mx[i%k])
			{
				b[i]=1;
			}
			else
			{
				b[i]=0;
			}
			
			b[i+n]=b[i];
		}
		
		for(int i=2*n-2;i>=0;i--)
		{
			if(b[i])
			{
				b[i]+=b[i+1];
			}
		}
		
		for(int i=0;i<n;i++)
		{
			ans+=c[min(n-1,b[i])];
		}
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}
