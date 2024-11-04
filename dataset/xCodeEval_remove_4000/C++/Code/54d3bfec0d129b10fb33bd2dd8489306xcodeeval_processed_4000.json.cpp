






























































































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





int dt[800007],gt[800007];
int a[100007];
int n,m;

void cccp()
{
	for(int i=0;i<800007;i++)
	{
		dt[i]=0;
		gt[i]=-1;
	}
}

void ypa(int now,int nl,int nr,int tt,int ji)
{
	if(nl==tt)dt[now]=ji;
	if(nl==tt&&nr==tt)return;
	int m=(nl+nr)/2;
	if(m>=tt)ypa(now*2,nl,m,tt,ji);
	else ypa(now*2+1,m+1,nr,tt,ji);
}

void cobet(int now,int nl,int nr,int l,int r,int frm)
{
	int m=(nl+nr)/2;
	if(gt[now]!=-1)
	{
		dt[now]=a[gt[now]];
		gt[now*2]=gt[now];
		gt[now*2+1]=gt[now]+m+1-nl;
		gt[now]=-1;
	}
	if(nr<l||nl>r)return;
	if(nl>=l)dt[now]=a[frm+nl-l];
	if(nl>=l&&nr<=r)
	{
		gt[now]=frm+nl-l;
		return;
	}
	cobet(now*2,nl,m,l,r,frm);
	cobet(now*2+1,m+1,nr,l,r,frm);
	dt[now]=dt[now*2];
}

int id0(int now,int nl,int nr,int tt)
{
	int m=(nl+nr)/2;
	if(gt[now]!=-1)
	{
		dt[now]=a[gt[now]];
		gt[now*2]=gt[now];
		gt[now*2+1]=gt[now]+m+1-nl;
		gt[now]=-1;
	}
	if(nl==tt)return dt[now];
	if(m>=tt)return id0(now*2,nl,m,tt);
	else return id0(now*2+1,m+1,nr,tt);
}

int main()
{
	scanf("%d%d",&n,&m);
	cccp();
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		ypa(1,0,n-1,i,num);
	}
	for(int i=0;i<m;i++)
	{
		int md;
		scanf("%d",&md);
		if(md==1)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--;b--;
			cobet(1,0,n-1,b,b+c-1,a);
		}
		else
		{
			int xx;
			scanf("%d",&xx);
			xx--;
			printf("%d\n",id0(1,0,n-1,xx));
		}
	}
	return 0;
}