


































































































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





int m,k,n,s;
int a[500005],cnt[500005],ans[500005];
vector<int> pos[500005];
int anssz;

void findans(int l,int r){
	int prvl=(l-1)/k*k+1;
	int len1=r-prvl+1;
	if(len1>k){
		len1-=k;
	}else{
		len1=0;
	}
	int todel=len1;
	vector<int> ans;
	for(int i=l;i<=r&&todel;i++){
		if(!cnt[a[i]]){
			ans.pb(i);
			todel--;
		}else{
			cnt[a[i]]--;
		}
	}
	for(int i=0;i<todel;i++){
		ans.pb(l-1-i);
	}
	fio<<SZ(ans)<<endl;
	for(int i=0;i<SZ(ans);i++){
		fio<<ans[i]<<' ';
	}
	fio<<endl;
}

int main(){
	fio>>m>>k>>n>>s;
	for(int i=1;i<=m;i++){
		fio>>a[i];
	}
	for(int i=1;i<=s;i++){
		int x;
		fio>>x;
		cnt[x]++;
		if(cnt[x]==1){
			anssz++;
		}
	}
	multiset<int,greater<int> > S;
	for(int i=m;i>=0;i--){
		if(cnt[a[i]]){
			pos[a[i]].pb(i);
			if(ans[a[i]]){
				S.erase(S.find(ans[a[i]]));
			}
			if(SZ(pos[a[i]])>=cnt[a[i]]){
				ans[a[i]]=pos[a[i]][SZ(pos[a[i]])-cnt[a[i]]];
				S.insert(ans[a[i]]);
			}
			if(SZ(S)==anssz){
				int curans=0;
				int prvl=(i-1)/k*k+1;
				int len1=*S.begin()-prvl+1;
				if(len1>k){
					curans=len1-k;
				}
				if(m-curans>=n*k){
					findans(i,*S.begin());
					return 0;
				}
			}
		}
	}
	OVER("-1\n");
}