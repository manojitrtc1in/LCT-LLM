




























































































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
inline int read()
{
	int num=0;
	char c=getchar();
	if(c=='-')return -read();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}
inline INT READ()
{
	INT num=0;
	char c=getchar();
	if(c=='-')return -READ();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}





struct prob
{
	long long ss,sl,ts,tl;
	long double ps,psl,ptl;
	void input()
	{
		cin>>ss>>sl>>ts>>tl>>ps;
		ps=1-ps;
		psl=sl*ps;
		ptl=tl*ps;
	}
};

int n,t;
prob pr[1007];

inline bool cmp(const prob& a,const prob& b)
{
	return a.tl*(1-a.ps)/a.ps<b.tl*(1-b.ps)/b.ps;
}
inline bool eq(const long double& a,const long double& b)
{
	return a-b>-1e-16&&a-b<1e-16;
}
inline bool sm(const long double& a,const long double& b)
{
	return a-b<-1e-16;
}
inline bool bg(const long double& a,const long double& b)
{
	return a-b>1e-16;
}

long double dps[1007][1607],dpt[1007][1607];

int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		pr[i].input();
	sort(pr+1,pr+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=t;j++)
			dps[i][j]=-INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=t;j++)
			dpt[i][j]=INF;
	long double ansa=-INF,ansb=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=t;j++)
		{
			

			if(sm(dps[i][j],dps[i][j-1])||(eq(dps[i][j],dps[i][j-1])&&bg(dpt[i][j],dpt[i][j-1])))
			{
				dps[i][j]=dps[i][j-1];
				dpt[i][j]=dpt[i][j-1];
			}
			

			if(j>=pr[i].ts+pr[i].tl)
			{
				long double wls=dps[i-1][j-pr[i].ts-pr[i].tl]+pr[i].ss+pr[i].psl;
				long double wlt=(1-pr[i].ps)*(dpt[i-1][j-pr[i].ts-pr[i].tl]+pr[i].ts)+pr[i].ps*j;
				if(sm(dps[i][j],wls)||(eq(dps[i][j],wls)&&bg(dpt[i][j],wlt)))
				{
					dps[i][j]=wls;
					dpt[i][j]=wlt;
				}
			}
			

			if(j>=pr[i].ts)
			{
				long double wls=dps[i-1][j-pr[i].ts]+pr[i].ss;
				long double wlt=dpt[i-1][j-pr[i].ts]+pr[i].ts;
				if(sm(dps[i][j],wls)||(eq(dps[i][j],wls)&&bg(dpt[i][j],wlt)))
				{
					dps[i][j]=wls;
					dpt[i][j]=wlt;
				}
			}
			

			if(sm(dps[i][j],dps[i-1][j])||(eq(dps[i][j],dps[i-1][j])&&bg(dpt[i][j],dpt[i-1][j])))
			{
				dps[i][j]=dps[i-1][j];
				dpt[i][j]=dpt[i-1][j];
			}
			if(sm(ansa,dps[i][j])||(eq(ansa,dps[i][j])&&bg(ansb,dpt[i][j])))
			{
				ansa=dps[i][j];
				ansb=dpt[i][j];
			}
		}
	OVER("%.15Lf %.15Lf\n",ansa,ansb);
}
