


































































































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





bool lesseq(double a,double b){
	return a<b+1e-15;
}

struct ConvexHull{
	vector<pair<double,double> > lns;

	void init(){
		lns.clear();
	}
	bool fuck(int a,int b,int c){
		return lesseq((lns[c].second-lns[a].second)*(lns[a].first-lns[b].first),(lns[b].second-lns[a].second)*(lns[a].first-lns[c].first));
	}
	void ins(double a,double b){
		lns.pb(mp(a,b));
		while(SZ(lns)>=3&&fuck(SZ(lns)-3,SZ(lns)-2,SZ(lns)-1)){
			lns[SZ(lns)-2]=lns[SZ(lns)-1];
			lns.pob();
		}
	}
	double get(int whr,double x){
		return lns[whr].first*x+lns[whr].second;
	}
	double find(double num){
		int l=0,r=SZ(lns)-1;
		while(r>l){
			int m=(l+r)>>1;
			

			if(lesseq(get(m+1,num),get(m,num))){
				l=m+1;
			}else{
				r=m;
			}
		}
		return get(l,num);
	}
}cvx;

double dp[55][200005];
INT t[200005],sum[200005];
double fsum[200005],pre[200005];
int n,k;

int main(){
	fio>>n>>k;
	for(int i=1;i<=n;i++){
		fio>>t[i];
		sum[i]=sum[i-1]+t[i];
		fsum[i]=fsum[i-1]+1.0/t[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+sum[i]*1.00/t[i];
		

	}
	for(int i=1;i<=n;i++){
		dp[0][i]=INF;
	}
	for(int i=1;i<=k;i++){
		cvx.init();
		cvx.ins(0,0);
		for(int j=1;j<=n;j++){
			dp[i][j]=cvx.find(fsum[j])+pre[j];
			

			cvx.ins(-sum[j],dp[i-1][j]-pre[j]+sum[j]*fsum[j]);
		}
	}
	fio<<dp[k][n]<<endl;
	return 0;
}