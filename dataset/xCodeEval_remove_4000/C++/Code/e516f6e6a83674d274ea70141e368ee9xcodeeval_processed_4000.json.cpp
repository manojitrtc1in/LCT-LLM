


































































































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
int dx[][5]={{2,1,0,0,0},{1,0,0,0,-1},{0,0,0,-1,-2},{1,0,0,0,-1}};
int dy[][5]={{0,0,-1,0,1},{0,0,1,2,0},{-1,0,1,0,0},{0,-2,-1,0,0}};
char brd[9][9];
int ans=-1;
char ansbrd[9][9];

bool place(int x,int y,int dir,char wht){
	for(int i=0;i<5;i++){
		int X=x+dx[dir][i],Y=y+dy[dir][i];
		if(X<0||X>=n||Y<0||Y>=m){
			return 0;
		}
		if(!(wht=='.'||brd[X][Y]=='.')){
			return 0;
		}
	}
	for(int i=0;i<5;i++){
		int X=x+dx[dir][i],Y=y+dy[dir][i];
		brd[X][Y]=wht;
	}
	return 1;
}

void dfs(int x,int y,char djg){
	if(x==n){
		if(djg-'A'>ans){
			ans=djg-'A';
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					ansbrd[i][j]=brd[i][j];
				}
			}
		}
		return;
	}
	if((n-x)*m/5+djg-'A'<=ans){
		return;
	}
	if(y==m){
		dfs(x+1,0,djg);
		return;
	}
	for(int i=0;i<4;i++){
		if(place(x,y,i,djg)){
			dfs(x,y+1,djg+1);
			place(x,y,i,'.');
		}
	}
	dfs(x,y+1,djg);
}

int main(){
	fio>>n>>m;
	FILL(brd,'.');
	dfs(0,0,'A');
	printf("%d\n",ans);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%c",ansbrd[i][j]);
		}
		printf("\n");
	}
	return 0;
}