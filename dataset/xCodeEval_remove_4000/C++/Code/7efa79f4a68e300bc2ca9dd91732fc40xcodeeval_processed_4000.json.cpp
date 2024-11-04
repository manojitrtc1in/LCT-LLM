
































































































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





int n,len,h;
int b[150007],a[150007],sh[150007];

struct FUCK_YOUR_FAMILY
{
	int dt[1500007],wp[1500007];
	void jia(int now,int nl,int nr,int l,int r,int num)
	{
		if(l>r)return;
		if(wp[now])
		{
			dt[now<<1]+=wp[now];
			dt[now<<1|1]+=wp[now];
			wp[now<<1]+=wp[now];
			wp[now<<1|1]+=wp[now];
			wp[now]=0;
		}
		if(nl>r||nr<l)return;
		if(nl>=l&&nr<=r)
		{
			dt[now]+=num;
			wp[now]+=num;
			return;
		}
		int m=(nl+nr)>>1;
		jia(now<<1,nl,m,l,r,num);
		jia(now<<1|1,m+1,nr,l,r,num);
		dt[now]=min(dt[now<<1],dt[now<<1|1]);
	}
}seg;

int cnt=0;

int main()
{
	fio>>n>>len>>h;
	for(int i=1;i<=len;i++)
	{
		fio>>b[i];
		b[i]=h-b[i];
	}
	sort(b+1,b+1+len);
	for(int i=1;i<=n;i++)
		fio>>a[i];
	for(int i=1;i<=n;i++)
		sh[i]=upper_bound(b+1,b+1+len,a[i])-b;
	for(int i=1;i<=len;i++)
		seg.jia(1,0,len+1,1,i,-1);
	for(int i=1;i<=len;i++)
		seg.jia(1,0,len+1,1,sh[i]-1,1);
	if(seg.dt[1]>=0)cnt++;
	for(int i=1,j=len+1;j<=n;i++,j++)
	{
		seg.jia(1,0,len+1,1,sh[i]-1,-1);
		seg.jia(1,0,len+1,1,sh[j]-1,1);
		if(seg.dt[1]>=0)cnt++;
	}
	fio<<cnt<<endl;
	return 0;
}