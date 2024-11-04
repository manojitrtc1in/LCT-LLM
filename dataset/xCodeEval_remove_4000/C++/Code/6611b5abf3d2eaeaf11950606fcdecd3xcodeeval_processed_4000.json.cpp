
































































































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
struct fastIO
{
	inline fastIO operator>>(int& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(INT& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(float& num)
	{
		scanf("%f",&num);
		return *this;
	}
	inline fastIO operator>>(double& num)
	{
		scanf("%lf",&num);
		return *this;
	}
	inline fastIO operator>>(long double& num)
	{
		scanf("%Lf",&num);
		return *this;
	}
	inline fastIO operator>>(char& num)
	{
		num=getchar();
		while(num==' '||num=='\n')num=getchar();
		return *this;
	}
	inline fastIO operator>>(char* num)
	{
		int cnt=0;
		char c=getchar();
		while(c==' '||c=='\n')c=getchar();
		while(c!=' '&&c!='\n')
		{
			num[cnt++]=c;
			c=getchar();
		}
		num[cnt]=0;
		return *this;
	}
	inline fastIO operator>>(string& num)
	{
		cin>>num;
		return *this;
	}
	inline void printInt(const int& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printInt(num/10);
		putchar((num%10)+'0');
	}
	inline void printINT(const INT& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printINT(num/10);
		putchar((num%10)+'0');
	}
	inline fastIO operator<<(const int& num)
	{
		if(num<0)putchar('-'),printInt(-num);
		else printInt(num);
		return *this;
	}
	inline fastIO operator<<(const INT& num)
	{
		if(num<0)putchar('-'),printINT(-num);
		else printINT(num);
		return *this;
	}
	inline fastIO operator<<(const float& num)
	{
		printf("%.10f",num);
		return *this;
	}
	inline fastIO operator<<(const double& num)
	{
		printf("%.16lf",num);
		return *this;
	}
	inline fastIO operator<<(const long double& num)
	{
		printf("%.20Lf",num);
		return *this;
	}
	inline fastIO operator<<(const char& num)
	{
		putchar(num);
		return *this;
	}
	inline fastIO operator<<(const char* num)
	{
		for(int i=0;num[i];i++)
			putchar(num[i]);
		return *this;
	}
	inline fastIO operator<<(const string& num)
	{
		cout<<num;
		return *this;
	}
}fio;





int n,q;
struct FUCK_YOUR_FAMILY
{
	INT dt[2000007];
	int mx[2000007];
	void change(int now,int nl,int nr,int to,int num)
	{
		if(nl>to||nr<to)return;
		if(nl==to&&nr==to)
		{
			dt[now]=num;
			mx[now]=num;
			return;
		}
		int m=(nl+nr)>>1;
		change(now<<1,nl,m,to,num);
		change(now<<1|1,m+1,nr,to,num);
		dt[now]=dt[now<<1]+dt[now<<1|1];
		mx[now]=max(mx[now<<1],mx[now<<1|1]);
	}
	int qmax(int now,int nl,int nr,int l,int r,INT num)
	{
		if(nl>r||nr<l)return n;
		if(mx[now]<num)return n;
		if(nl<l||nr>r)
		{
			int m=(nl+nr)>>1;
			int QMAX=qmax(now<<1,nl,m,l,r,num);
			if(QMAX!=n)return QMAX;
			return qmax(now<<1|1,m+1,nr,l,r,num);
		}
		if(nl==nr)return nl;
		int m=(nl+nr)>>1;
		if(mx[now<<1]>=num)return qmax(now<<1,nl,m,l,r,num);
		else return qmax(now<<1|1,m+1,nr,l,r,num);
	}
	INT qsum(int now,int nl,int nr,int l,int r)
	{
		if(nl>r||nr<l)return 0;
		if(nl>=l&&nr<=r)return dt[now];
		int m=(nl+nr)>>1;
		return qsum(now<<1,nl,m,l,r)+qsum(now<<1|1,m+1,nr,l,r);
	}
}seg;

int a[200007];

int main()
{
	fio>>n>>q;
	for(int i=0;i<n;i++)
	{
		fio>>a[i];
		seg.change(1,0,n,i,a[i]);
	}
	while(q--)
	{
		int x,y;
		fio>>x>>y;
		seg.change(1,0,n,x-1,y);
		INT id0=seg.qsum(1,0,n,0,0),nowl=0;
		if(id0==0)
		{
			fio<<1<<endl;
			continue;
		}
		while(nowl<n)
		{
			int r=seg.qmax(1,0,n,nowl+1,n,id0);
			if(r==n)
			{
				fio<<-1<<endl;
				break;
			}
			if(seg.qsum(1,0,n,0,r-1)==seg.qsum(1,0,n,r,r))
			{
				fio<<r+1<<endl;
				break;
			}
			id0=seg.qsum(1,0,n,0,r);
			nowl=r;
		}
	}
	return 0;
}