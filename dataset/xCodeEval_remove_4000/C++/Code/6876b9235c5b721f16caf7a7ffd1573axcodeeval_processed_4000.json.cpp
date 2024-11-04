
































































































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





map<INT,pair<PII,PII> > mem;
INT k,a[107],p[107];
INT used[107];
INT V,rs,ra,rb,rc;
INT A,B,C,NN;

void dfs(INT rx,INT x,INT now,INT zl){
	if(now==k||rx<a[now]){
		if(zl){
			B=x;
			C=NN/B;
			INT s13=A*(B+C)+NN;
			if(s13<rs){
				rs=s13;
				ra=A;
				rb=B;
				rc=C;
			}
		}else{
			A=x;
			NN=V/A;
			INT BB=sqrt(NN);
			if(2*A*BB+NN<rs){
				for(int i=0;i<k;i++){
					p[i]-=used[i];
				}
				dfs(BB+1,1,0,1);
				for(int i=0;i<k;i++){
					p[i]+=used[i];
				}
			}
		}
		return;
	}
	INT fo=0,RX[64],X[64];
	while(rx>=1&&fo<=p[now]){
		RX[fo]=rx;
		X[fo]=x;
		rx/=a[now];
		x*=a[now];
		fo++;
	}
	for(int i=fo-1;i>=0;i--){
		if(!zl){
			used[now]=i;
		}
		dfs(RX[i],X[i],now+1,zl);
	}
}

int main(){
	int T;
	fio>>T;
	while(T--){
		fio>>k;
		V=1;
		for(int i=0;i<k;i++){
			fio>>a[i]>>p[i];
			for(int j=0;j<p[i];j++){
				V*=a[i];
			}
		}
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				if(a[i]>a[j]){
					swap(a[i],a[j]);
					swap(p[i],p[j]);
				}
			}
		}
		if(mem.count(V)){
			pair<PII,PII> fuck=mem[V];
			fio<<2*fuck.first.first<<' '<<fuck.first.second<<' '<<fuck.second.first<<' '<<fuck.second.second<<endl;
		}else{
			rs=INF;
			dfs(pow(V,1.0/3)+1,1,0,0);
			mem[V]=mp(mp(rs,ra),mp(rb,rc));
			fio<<2*rs<<' '<<ra<<' '<<rb<<' '<<rc<<endl;
		}
	}
	return 0;
}