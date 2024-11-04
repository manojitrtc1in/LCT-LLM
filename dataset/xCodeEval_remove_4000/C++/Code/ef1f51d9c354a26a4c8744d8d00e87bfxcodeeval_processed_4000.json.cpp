


































































































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





struct Edge{
	int to,cap,rev;
	Edge(){}
	Edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};

vector<Edge> vs[1005];
bool lgl[1005];
int a[1005],b[1005];
int wrs[1005][1005];

void addEdge(int u,int v,int cap){
	wrs[u][v]=SZ(vs[u]);
	wrs[v][u]=SZ(vs[v]);
	vs[u].pb(Edge(v,cap,SZ(vs[v])));
	vs[v].pb(Edge(u,0,SZ(vs[u])-1));
}

int dfs(int bg,int en,int cap){
	if(bg==en){
		return cap;
	}
	lgl[bg]=1;
	for(int i=0;i<SZ(vs[bg]);i++){
		if(!lgl[vs[bg][i].to]&&vs[bg][i].cap>0){
			int dis=dfs(vs[bg][i].to,en,min(cap,vs[bg][i].cap));
			if(dis){
				vs[bg][i].cap-=dis;
				vs[vs[bg][i].to][vs[bg][i].rev].cap+=dis;
				return dis;
			}
		}
	}
	return 0;
}

bool isE[1005][1005];

int main(){
	int n,m;
	fio>>n>>m;
	int sum=0,sum2=0;
	for(int i=1;i<=n;i++){
		fio>>a[i];
		sum+=a[i];
		addEdge(0,i,a[i]);
	}
	for(int i=1;i<=n;i++){
		fio>>b[i];
		sum2+=b[i];
		addEdge(n+i,2*n+1,b[i]);
	}
	if(sum!=sum2){
		OVER("NO\n");
	}
	for(int i=0;i<m;i++){
		int x,y;
		fio>>x>>y;
		isE[x][y]=isE[y][x]=1;
		addEdge(x,n+y,Inf);
		addEdge(y,n+x,Inf);
	}
	for(int i=1;i<=n;i++){
		addEdge(i,n+i,Inf);
	}
	int ans=0;
	while(1){
		FILL0(lgl);
		int fff=dfs(0,2*n+1,2*Inf);
		

		if(!fff){
			break;
		}
		ans+=fff;
	}
	

	if(ans==sum){
		fio<<"YES\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&!isE[i][j]){
					

					fio<<0<<' ';
				}else{
					fio<<vs[j+n][wrs[j+n][i]].cap<<' ';
				}
			}
			fio<<endl;
		}
		return 0;
	}else{
		OVER("NO\n");
	}
}