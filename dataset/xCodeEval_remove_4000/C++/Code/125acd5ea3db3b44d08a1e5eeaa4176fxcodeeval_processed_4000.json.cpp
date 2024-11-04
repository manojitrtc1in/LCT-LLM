


































































































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





int n,k;
char s[1000005];
INT ha1[1000005];
INT ha2[1000005];
int ch1=19260817,ch2=23456789,mo2=1887415157;
INT mii1[1000005],mii2[1000005];
int ans[1000005];

bool check(int x,int y,int z){
	INT f1=ha1[x+z]-ha1[x]*mii1[z];
	INT f2=ha1[y+z]-ha1[y]*mii1[z];
	if(f1!=f2){
		return 0;
	}
	f1=(ha2[x+z]-ha2[x]*mii2[z]%mo2+mo2)%mo2;
	f2=(ha2[y+z]-ha2[y]*mii2[z]%mo2+mo2)%mo2;
	if(f1!=f2){
		return 0;
	}
	return 1;
}

int main(){
	fio>>n>>k>>(s+1);
	mii1[0]=mii2[0]=1;
	for(int i=1;i<=n;i++){
		mii1[i]=mii1[i-1]*ch1;
		mii2[i]=(mii2[i-1]*ch2)%mo2;
		ha1[i]=ha1[i-1]*ch1+s[i];
		ha2[i]=(ha2[i-1]*ch2+s[i])%mo2;
	}
	for(int i=1;i<=n/k;i++){
		int l=0,r=n+1;
		while(r-l>1){
			int m=(l+r)>>1;
			if(m+i<=n&&check(0,i,m)){
				l=m;
			}else{
				r=m;
			}
		}
		int L=i*k;
		int R=min(L+i,l+i);
		if(L<=R){
			ans[L]++;
			ans[R+1]--;
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
		fio<<min(1,ans[i]);
	}
	fio<<endl;
	return 0;
}