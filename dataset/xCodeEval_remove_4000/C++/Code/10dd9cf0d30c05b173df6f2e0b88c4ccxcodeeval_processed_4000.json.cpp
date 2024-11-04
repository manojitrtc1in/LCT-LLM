


































































































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





int dp[255][255][255];
int vcl[100005][30];
int n,q;
char s[100005];
int a[255],b[255],c[255];
int lena,lenb,lenc;

void upd(int A,int B,int C){
	if(!A&&!B&&!C){
		return;
	}
	dp[A][B][C]=n+1;
	if(A){
		dp[A][B][C]=min(dp[A][B][C],vcl[dp[A-1][B][C]+1][a[A]]);
	}
	if(B){
		dp[A][B][C]=min(dp[A][B][C],vcl[dp[A][B-1][C]+1][b[B]]);
	}
	if(C){
		dp[A][B][C]=min(dp[A][B][C],vcl[dp[A][B][C-1]+1][c[C]]);
	}
}

int main(){
	fio>>n>>q>>(s+1);
	for(int i=0;i<26;i++){
		vcl[n+1][i]=n+1;
		vcl[n+2][i]=n+1;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<26;j++){
			vcl[i][j]=vcl[i+1][j];
		}
		vcl[i][s[i]-'a']=i;
	}
	for(int i=0;i<q;i++){
		char mode;
		int whr;
		fio>>mode>>whr;
		if(mode=='+'){
			char ch;
			fio>>ch;
			if(whr==1){
				a[++lena]=ch-'a';
			}else if(whr==2){
				b[++lenb]=ch-'a';
			}else{
				c[++lenc]=ch-'a';
			}
		}else{
			if(whr==1){
				lena--;
			}else if(whr==2){
				lenb--;
			}else{
				lenc--;
			}
		}
		if(whr==1){
			for(int i=0;i<=lenb;i++){
				for(int j=0;j<=lenc;j++){
					upd(lena,i,j);
				}
			}
		}else if(whr==2){
			for(int i=0;i<=lena;i++){
				for(int j=0;j<=lenc;j++){
					upd(i,lenb,j);
				}
			}
		}else{
			for(int i=0;i<=lena;i++){
				for(int j=0;j<=lenb;j++){
					upd(i,j,lenc);
				}
			}
		}
		if(dp[lena][lenb][lenc]==n+1){
			fio<<"no\n";
		}else{
			fio<<"yes\n";
		}
	}
	return 0;
}