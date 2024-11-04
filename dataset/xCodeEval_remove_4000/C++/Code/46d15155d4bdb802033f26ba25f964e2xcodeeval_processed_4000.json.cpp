
































































































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





INT k,x,n,m;
const char fuck[]="Happy new year!\n";
int kt[57],jw[57];
INT x12[57],x21[57],x11[57],x22[57];
INT fib[57],cx1[57],cx2[57];
map<INT,pair<pii,pii> > mb;

int main()
{
	fio>>k>>x>>n>>m;
	kt[1]=jw[1]=cx1[1]=cx2[2]=1;
	kt[2]=jw[2]=2;
	fib[1]=fib[2]=1;
	for(int i=3;i<=k;i++)
	{
		x12[i]=x12[i-1]+x12[i-2];
		x21[i]=x21[i-1]+x21[i-2];
		x11[i]=x11[i-1]+x11[i-2];
		x22[i]=x22[i-1]+x22[i-2];
		if(jw[i-2]==1&&kt[i-1]==2)x12[i]++;
		if(jw[i-2]==2&&kt[i-1]==1)x21[i]++;
		if(jw[i-2]==1&&kt[i-1]==1)x11[i]++;
		if(jw[i-2]==2&&kt[i-1]==2)x22[i]++;
		fib[i]=fib[i-1]+fib[i-2];
		cx1[i]=cx1[i-1]+cx1[i-2];
		cx2[i]=cx2[i-1]+cx2[i-2];
		kt[i]=kt[i-2];
		jw[i]=jw[i-1];
	}
	for(int f1=0;f1<4;f1++)
		for(int f2=0;f2<4;f2++)
			for(int i=0;i+__builtin_popcount(f1)<=n;i+=2)
				for(int j=0;j+__builtin_popcount(f2)<=m;j+=2)
				{
					INT ans=0;
					ans+=i/2*cx1[k];
					ans+=j/2*cx2[k];
					ans+=(f1==3)*x11[k];
					ans+=(f2==3)*x22[k];
					ans+=((f1/2)&&(f2%2))*x21[k];
					ans+=((f1%2)&&(f2/2))*x12[k];
					if(ans==x)
					{
						string str1="",str2="";
						if(f1/2)str1+="C",n--;
						if(f2/2)str2+="C",m--;
						int ii;
						for(ii=0;ii<i;ii+=2)
							str1+="AC";
						for(;ii<n;ii++)
							str1+="B";
						for(ii=0;ii<j;ii+=2)
							str2+="AC";
						for(;ii<m;ii++)
							str2+="B";
						if(f1/2)n++;
						if(f2/2)m++;
						if(f1%2)str1[n-1]='A';
						if(f2%2)str2[m-1]='A';
						cout<<str1<<endl;
						cout<<str2<<endl;


						return 0;
					}
				}
	OVER(fuck);
}