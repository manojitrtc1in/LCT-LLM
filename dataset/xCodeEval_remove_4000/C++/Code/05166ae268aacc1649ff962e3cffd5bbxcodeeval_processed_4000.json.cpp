


































































































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





int lst[2005][2005],nxt[2005][2005];
int n,m,k;

int main(){
	fio>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m+1;j++){
			lst[i][j]=j;
			nxt[i][j]=j;
		}
	}
	while(k--){
		int x,y;
		fio>>x>>y;
		int ansnum=Inf,ansx=Inf,ansy;
		for(int i=0;i<n&&i<=ansnum;i++){
			int I=x-i;
			if(I>=1){
				int J=lst[I][y];
				if(J>=1&&(abs(J-y)+abs(I-x)<ansnum||(abs(J-y)+abs(I-x)==ansnum&&I<ansx))){
					ansnum=abs(J-y)+abs(I-x);
					ansx=I;
					ansy=J;
				}
				J=nxt[I][y];
				if(J<=m&&(abs(J-y)+abs(I-x)<ansnum||(abs(J-y)+abs(I-x)==ansnum&&I<ansx))){
					ansnum=abs(J-y)+abs(I-x);
					ansx=I;
					ansy=J;
				}
			}
			I=x+i;
			if(I<=n){
				int J=lst[I][y];
				if(J>=1&&(abs(J-y)+abs(I-x)<ansnum||(abs(J-y)+abs(I-x)==ansnum&&I<ansx))){
					ansnum=abs(J-y)+abs(I-x);
					ansx=I;
					ansy=J;
				}
				J=nxt[I][y];
				if(J<=m&&(abs(J-y)+abs(I-x)<ansnum||(abs(J-y)+abs(I-x)==ansnum&&I<ansx))){
					ansnum=abs(J-y)+abs(I-x);
					ansx=I;
					ansy=J;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(lst[ansx][i]==ansy){
				lst[ansx][i]=lst[ansx][ansy-1];
			}
			if(nxt[ansx][i]==ansy){
				nxt[ansx][i]=nxt[ansx][ansy+1];
			}
		}
		fio<<ansx<<' '<<ansy<<endl;
	}
	return 0;
}