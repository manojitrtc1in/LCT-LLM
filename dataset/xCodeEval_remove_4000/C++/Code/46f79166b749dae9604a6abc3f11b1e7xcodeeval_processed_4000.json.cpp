


































































































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





int n,k,l;
int X[10005],A[10005];
int st[25],cntst;
int dis[25][10005];
int dp[MASK(21)];

bool inrange(int x){
	return 0<=x&&x<=n;
}

void id0(int x,int djg){
	FILLBIG(dis[djg]);
	queue<int> q;
	queue<int> bs;
	dis[djg][x]=0;
	q.push(x);
	bs.push(0);
	while(SZ(q)){
		int qq=q.front();
		q.pop();
		int bb=bs.front();
		bs.pop();
		for(int i=0;i<l;i++){
			int L=A[i];
			if(inrange(qq+L)&&dis[djg][qq+L]==Inf){
				q.push(qq+L);
				bs.push(bb+1);
				dis[djg][qq+L]=bb+1;
			}
			L=-A[i];
			if(inrange(qq+L)&&dis[djg][qq+L]==Inf){
				q.push(qq+L);
				bs.push(bb+1);
				dis[djg][qq+L]=bb+1;
			}
		}
	}
}

int main(){
	fio>>n>>k>>l;
	for(int i=0;i<k;i++){
		fio>>X[i];
		X[i]--;
		

		if(cntst&&st[cntst-1]==X[i]){
			cntst--;
		}else{
			st[cntst++]=X[i];
		}
		

		st[cntst++]=X[i]+1;
		

	}
	for(int i=0;i<cntst;i++){
		X[i]=st[i];
	}
	k=cntst;
	for(int i=0;i<l;i++){
		fio>>A[i];
	}
	for(int i=0;i<k;i++){
		id0(X[i],i);
	}
	FILLBIG(dp);
	dp[0]=0;
	for(int i=0;i<MASK(k);i++){
		for(int j=0;j<k;j++){
			if(BIT(i,j)){
				for(int K=j+1;K<k;K++){
					if(BIT(i,K)&&dis[j][X[K]]!=Inf){
						dp[i]=min(dp[i],dp[i^MASK(j)^MASK(K)]+dis[j][X[K]]);
						

					}
				}
			}
		}
	}
	if(dp[MASK(k)-1]>=Inf){
		OVER("-1\n");
	}else{
		OVER("%d\n",dp[MASK(k)-1]);
	}
}