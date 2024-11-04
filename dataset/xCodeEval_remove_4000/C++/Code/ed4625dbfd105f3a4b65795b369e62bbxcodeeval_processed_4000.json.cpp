































































































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





INT n,m;
map<string,INT> dy;
INT cntdy;
string yd[300005];
PII lx[300005];
vector<INT> nei[300005];
INT llk[300005];
INT ini[300005];
INT lgl[300005];
INT tmc[300005],djg,cmt[300005];
vector<INT> stk;


INT id0;
INT blst[300005];

void dfs(INT now){
	stk.pb(now);
	tmc[now]=llk[now]=++djg;
	cmt[djg]=now;
	lgl[now]=1;
	for(INT i=0;i<SZ(nei[now]);i++){
		if(lgl[nei[now][i]]==2){
			continue;
		}
		if(!lgl[nei[now][i]]){
			dfs(nei[now][i]);
		}
		llk[now]=min(llk[now],llk[nei[now][i]]);
	}
	if(tmc[now]==llk[now]){
		id0++;
		while(SZ(stk)){
			INT x=stk.back();
			stk.pob();
			lgl[x]=2;
			blst[x]=id0;
			

			if(x==now){
				break;
			}
		}
	}
}

PII getlx(const string &s){
	PII x=mp(0,SZ(s));
	for(INT i=0;i<SZ(s);i++){
		if(s[i]=='r'){
			x.first++;
		}
	}
	return x;
}

INT get(const string& s){
	if(!dy.count(s)){
		yd[cntdy]=s;
		dy[s]=cntdy;
		lx[cntdy++]=getlx(s);
	}
	return dy[s];
}

PII minlx[300005];
INT mindjg[300005];
vector<INT> nei2[300005];
set<INT> hv[300005];
PII dp[300005];
bool lgl2[300005];

PII dfs2(INT now){
	if(dp[now]!=mp(INF,INF)){
		return dp[now];
	}
	PII &x=dp[now];
	x=minlx[now];
	

	lgl2[now]=1;
	for(INT i=0;i<SZ(nei2[now]);i++){
		x=min(x,dfs2(nei2[now][i]));
	}
	return x;
}

int main(){
	fio>>n;
	for(INT i=0;i<n;i++){
		string s;
		fio>>s;
		for(INT j=0;j<SZ(s);j++){
			s[j]=tolower(s[j]);
		}
		ini[i]=get(s);
	}
	fio>>m;
	for(INT i=0;i<m;i++){
		string a,b;
		fio>>a>>b;
		for(INT j=0;j<SZ(a);j++){
			a[j]=tolower(a[j]);
		}
		for(INT j=0;j<SZ(b);j++){
			b[j]=tolower(b[j]);
		}
		nei[get(a)].pb(get(b));
		

	}
	for(INT i=0;i<cntdy;i++){
		if(!lgl[i]){
			dfs(i);
		}
	}
	for(INT i=1;i<=id0;i++){
		minlx[i]=mp(INF,INF);
	}
	for(INT i=0;i<cntdy;i++){
		if(lx[i]<minlx[blst[i]]){
			minlx[blst[i]]=lx[i];
			mindjg[blst[i]]=i;
		}
	}
	for(INT i=0;i<cntdy;i++){
		for(INT j=0;j<SZ(nei[i]);j++){
			if(blst[i]!=blst[nei[i][j]]&&!hv[blst[i]].count(blst[nei[i][j]])){
				nei2[blst[i]].pb(blst[nei[i][j]]);
				hv[blst[i]].insert(blst[nei[i][j]]);
				

			}
		}
	}
	for(INT i=1;i<=id0;i++){
		dp[i]=mp(INF,INF);
	}
	for(INT i=1;i<=id0;i++){
		if(!lgl2[i]){
			dfs2(i);
		}
	}
	PII ans=mp(0,0);
	for(INT i=0;i<n;i++){
		PII gt=dp[blst[ini[i]]];
		ans.first+=gt.first;
		ans.second+=gt.second;
		

	}
	fio<<ans.first<<' '<<ans.second<<endl;
	return 0;
}