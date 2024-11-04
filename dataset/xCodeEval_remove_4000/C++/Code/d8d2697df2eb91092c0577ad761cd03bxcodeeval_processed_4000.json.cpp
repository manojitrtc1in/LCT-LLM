






















































using namespace std;







typedef long long ll;




























ll A[5];
ll B[5];
ll n;

inline int query(ll a[])
{
	cout<<"? "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
	cout<<endl;
	
	fflush(stdout);
	
	int res;
	
	cin>>res;
	
	return res;
}


void fix(ll a[],int k)
{
	ll ki=a[0],ka=a[2];
	if(k%2) ki=a[1],ka=a[3];
	
	while(ki<=ka)
	{
		ll mid=(ki+ka)>>1;
		
		ll b[5];
		
		for(int i=0;i<4;i++)
		{
			b[i]=a[i];
		}
		b[k]=mid;
		
		if(query(b))
		{
			if(k>1) ka=mid-1;
			else ki=mid+1;
		}
		else
		{
			if(k>1) ki=mid+1;
			else ka=mid-1;
		}
	}
	
	if(k>=2) a[k]=ki;
	else a[k]=ka;
}

void f1(ll a[])
{
	fix(a,3);
	fix(a,2);
	fix(a,0);
	fix(a,1);
}

void f2(ll a[])
{
	fix(a,1);
	fix(a,0);
	fix(a,2);
	fix(a,3);
}

int main()
{
	cin>>n;
	
	A[0]=A[1]=1;
	A[2]=A[3]=n;
	
	B[0]=B[1]=1;
	B[2]=B[3]=n;
	
	f1(A);
	f2(B);
	
	cout<<"! ";
	for(int k=0;k<4;k++)
	{
		cout<<A[k]<<' ';
	}
	
	for(int k=0;k<4;k++)
	{
		cout<<B[k]<<' ';
	}
	cout<<endl;
	
	fflush(stdout);
	
	return 0;
}
