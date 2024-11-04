


































































































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





int n,m;
vector<int> nei[100005];
vector<pair<pii,pii> > req;
int bg[100005],en[100005],cur;
int cnt[100005],ccnt[100005];
int col[100005],col2[100005];
int ans[100005];

void dfs(int now,int lst){
	bg[now]=++cur;
	for(int i=0;i<SZ(nei[now]);i++){
		if(nei[now][i]!=lst){
			dfs(nei[now][i],now);
		}
	}
	en[now]=cur;
}

int main(){
	fio>>n>>m;
	for(int i=1;i<=n;i++){
		fio>>col2[i];
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		fio>>a>>b;
		nei[a].pb(b);
		nei[b].pb(a);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		col[bg[i]]=col2[i];
	}
	for(int i=0;i<m;i++){
		int a,b;
		fio>>a>>b;
		req.pb(mp(mp(bg[a],en[a]),mp(b,i)));
	}
	sort(ALL(req));
	int nowl=1,nowr=0;
	for(int i=0;i<m;i++){
		int a=req[i].first.first,b=req[i].first.second;
		while(nowr<b){
			nowr++;
			cnt[col[nowr]]++;
			ccnt[cnt[col[nowr]]]++;
		}
		while(nowl>a){
			nowl--;
			cnt[col[nowl]]++;
			ccnt[cnt[col[nowl]]]++;
		}
		while(nowr>b){
			ccnt[cnt[col[nowr]]]--;
			cnt[col[nowr]]--;
			nowr--;
		}
		while(nowl<a){
			ccnt[cnt[col[nowl]]]--;
			cnt[col[nowl]]--;
			nowl++;
		}
		ans[req[i].second.second]=ccnt[req[i].second.first];
	}
	for(int i=0;i<m;i++){
		fio<<ans[i]<<endl;
	}
	return 0;
}