






























































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;





INT dt[1600007];
int n;
INT wp[1600007];
char inp[107];


void pls(int djg,int l,int r,int nl,int nr,int num)
{
	

	wp[djg*2]+=wp[djg];
	wp[djg*2+1]+=wp[djg];
	dt[djg*2]+=wp[djg];
	dt[djg*2+1]+=wp[djg];
	wp[djg]=0;
	if(nl>=l&&nr<=r)
	{
		

		dt[djg]+=num;
		wp[djg]+=num;
		return;
	}
	if(nr<=l||nl>=r)return;

	pls(djg*2,l,r,nl,(nl+nr)/2,num);
	pls(djg*2+1,l,r,(nl+nr)/2,nr,num);
	dt[djg]=min(dt[djg*2],dt[djg*2+1]);
}

INT find(int djg,int l,int r,int nl,int nr)
{
	

	wp[djg*2]+=wp[djg];
	wp[djg*2+1]+=wp[djg];
	dt[djg*2]+=wp[djg];
	dt[djg*2+1]+=wp[djg];
	wp[djg]=0;
	

	if(nl>=l&&nr<=r)return dt[djg];

	if(nr<=l||nl>=r)return INF;
	return min(find(djg*2,l,r,nl,(nl+nr)/2),find(djg*2+1,l,r,(nl+nr)/2,nr));
}

void INC(int a,int b,int c)
{
	if(a<=b)pls(1,a,b+1,0,n,c);
	else
	{
		pls(1,0,b+1,0,n,c);
		pls(1,a,n,0,n,c);
	}
}

INT RMQ(int a,int b)
{
	if(a<=b)return find(1,a,b+1,0,n);
	else return min(find(1,0,b+1,0,n),find(1,a,n,0,n));
}

int main()
{
	scanf("%d",&n);
	FILLBIG(dt);
	for(int i=0;i<n;i++)
	{
		int xx;
		scanf("%d",&xx);
		int l=0,r=n,m,mm=1;
		if(r-l==1)dt[mm]=xx;
		while(r-l>1)
		{
			m=(l+r)/2;
			if(m>i)r=m,mm=mm*2;
			else if(m<=i)l=m,mm=mm*2+1;
			if(r-l==1)dt[mm]=xx;
		}
		while(mm>1)
		{
			mm/=2;
			dt[mm]=min(dt[mm*2],dt[mm*2+1]);
		}
	}
	

	int q;
	scanf("%d",&q);
	gets(inp);
	while(q--)
	{
		gets(inp);
		int x,y,z;
		if(sscanf(inp,"%d%d%d",&x,&y,&z)==3)
			INC(x,y,z);
		else
		{
			sscanf(inp,"%d%d",&x,&y);
			printf("%I64d\n",RMQ(x,y));
		}
	}
	return 0;
}