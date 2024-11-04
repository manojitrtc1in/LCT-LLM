


































































































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
int usd[15];
int t[15][15];
int cur;
int ans;
int ax[15],ay[15],ar[15];
int cx[15],cy[15],cr[15];
char grf[15][15];
const int shitnum=28000000;
int shit;

inline bool chk(int x,int y,int wht){
	return ((usd[x]>>y)&t[wht][0])==0&&((usd[x+1]>>y)&t[wht][1])==0&&((usd[x+2]>>y)&t[wht][2])==0;
}

inline void solve(int x,int y){
	if(x+3>n){
		if(cur>ans){
			ans=cur;
			memcpy(ax,cx,sizeof(cx));
			memcpy(ay,cy,sizeof(cy));
			memcpy(ar,cr,sizeof(cr));
		}
		return;
	}
	if(y+3>m){
		solve(x+1,0);
		return;
	}
	if((n-x+1)*m/5+cur<=ans){
		return;
	}
	if(shit>=shitnum){
		return;
	}
	shit++;
	for(int i=0;i<4;i++){
		if(chk(x,y,i)){
			for(int j=x;j<x+3;j++){
				usd[j]|=(t[i][j-x]<<y);
			}
			cx[cur]=x;
			cy[cur]=y;
			cr[cur++]=i;
			solve(x,y+1);
			cur--;
			for(int j=x;j<x+3;j++){
				usd[j]^=(t[i][j-x]<<y);
			}
		}
	}
	solve(x,y+1);
}

int main(){
	fio>>n>>m;
	t[0][0]=7;
	t[0][1]=2;
	t[0][2]=2;
	t[1][0]=4;
	t[1][1]=7;
	t[1][2]=4;
	t[2][0]=2;
	t[2][1]=2;
	t[2][2]=7;
	t[3][0]=1;
	t[3][1]=7;
	t[3][2]=1;
	solve(0,0);
	fio<<ans<<endl;
	FILL(grf,'.');
	for(int i=0;i<ans;i++){
		int x=ax[i],y=ay[i],r=ar[i];
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(BIT(t[r][j],k)){
					grf[x+j][y+k]='A'+i;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			fio<<grf[i][j];
		}
		fio<<endl;
	}
	return 0;
}