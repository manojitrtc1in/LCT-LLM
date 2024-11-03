
















































































































































































































































int a[10000000];
int main()
{
    int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
		int flag=1;
		for(int i=1;i<n;i++)
		if(a[i]<a[i+1])
		{
			if(a[i+1]-a[i]!=1)
			{
				flag=0;
				break;
			}
		}
		if(flag) 
		puts("Yes");
		else 
		puts("No");
	}
    return 0;
}
