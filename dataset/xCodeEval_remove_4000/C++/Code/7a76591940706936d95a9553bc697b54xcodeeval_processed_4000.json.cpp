


































































































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





int nei[205][26];
int fail[205];
string s[205];
int to[205];
int cnt=1;

void add(const string& S){
	int now=0;
	string cur="";
	for(int i=0;i<SZ(S);i++){
		if(!nei[now][S[i]-'a']){
			nei[now][S[i]-'a']=cnt++;
		}
		now=nei[now][S[i]-'a'];
		cur+=S[i];
		s[now]=cur;
	}
}

void build(){
	fail[0]=0;
	queue<int> q;
	for(int i=0;i<26;i++){
		if(nei[0][i]){
			q.push(nei[0][i]);
		}
	}
	while(SZ(q)){
		int x=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(nei[x][i]){
				q.push(nei[x][i]);
				fail[nei[x][i]]=nei[fail[x]][i];
			}else{
				nei[x][i]=nei[fail[x]][i];
			}
		}
	}
}

INT pw[60][205][205],ans[205][205],c[205][205],bg[205][205];
void times(INT a[][205],INT b[][205]){
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			c[i][j]=-INF;
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			for(int k=0;k<cnt;k++){
				if(a[i][k]>=0){
					c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
				}
			}
		}
	}
}

int n;
INT m;
int ass[205];
string ss[205];

int main(){
	fio>>n>>m;
	for(int i=0;i<n;i++){
		fio>>ass[i];
	}
	for(int i=0;i<n;i++){
		fio>>ss[i];
		add(ss[i]);
	}
	build();
	for(int i=0;i<cnt;i++){
		for(int j=0;j<n;j++){
			if(SZ(s[i])>=SZ(ss[j])&&s[i].substr(SZ(s[i])-SZ(ss[j]))==ss[j]){
				to[i]+=ass[j];
			}
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			bg[i][j]=ans[i][j]=-INF;
			for(int k=0;k<26;k++){
				if(nei[i][k]==j){
					bg[i][j]=to[j];
				}
			}
		}
	}
	ans[0][0]=0;
	memcpy(pw[0],bg,sizeof(bg));
	for(int i=1;i<60;i++){
		times(pw[i-1],pw[i-1]);
		memcpy(pw[i],c,sizeof(c));
	}
	for(int i=0;i<60;i++){
		if(BIT(m,i)){
			times(ans,pw[i]);
			memcpy(ans,c,sizeof(c));
		}
	}
	INT Ans=0;
	for(int i=0;i<cnt;i++){
		Ans=max(Ans,ans[0][i]);
	}
	fio<<Ans<<endl;
	return 0;
}