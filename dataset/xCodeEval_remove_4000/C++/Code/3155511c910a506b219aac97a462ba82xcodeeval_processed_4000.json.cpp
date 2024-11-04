



































































































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





char s[1000005];
INT MOD=1926081777;
INT ha[1000005],ha2[1000005];
INT mii[1000005],mii2[1000005];

int main(){
	fio>>(s+1);
	int n=strlen(s+1);
	mii[0]=mii2[0]=1;
	for(int i=1;i<=n;i++){
		ha[i]=ha[i-1]*10+s[i]-'0';
		ha2[i]=(ha2[i-1]*10+s[i]-'0')%MOD;
		mii[i]=mii[i-1]*10;
		mii2[i]=mii2[i-1]*10%MOD;
	}
	for(int i=1;i<=n/2;i++){
		if(i<=(n-i)/2){
			int j=(n-i)/2+i;
			if(i==j||j==n){
				continue;
			}
			INT ans1=ha[i]+(ha[j]-ha[i]*mii[j-i]);
			INT ans2=(ha2[i]+(ha2[j]-ha2[i]*mii2[j-i]%MOD+MOD)%MOD)%MOD;
			

			if((i==1||s[1]!='0')&&(j==i+1||s[i+1]!='0')&&(n==j+1||s[j+1]!='0')&&ans1==ha[n]-ha[j]*mii[n-j]&&ans2==(ha2[n]-ha2[j]*mii2[n-j]%MOD+MOD)%MOD){
				for(int f=1;f<=n;f++){
					fio<<s[f];
					if(f==i){
						fio<<'+';
					}
					if(f==j){
						fio<<'=';
					}
				}
				return 0;
			}
			j=(n-i)/2+i-1;
			if(i==j||j==n){
				continue;
			}
			ans1=ha[i]+(ha[j]-ha[i]*mii[j-i]);
			ans2=(ha2[i]+(ha2[j]-ha2[i]*mii2[j-i]%MOD+MOD)%MOD)%MOD;
			

			if((i==1||s[1]!='0')&&(j==i+1||s[i+1]!='0')&&(n==j+1||s[j+1]!='0')&&ans1==ha[n]-ha[j]*mii[n-j]&&ans2==(ha2[n]-ha2[j]*mii2[n-j]%MOD+MOD)%MOD){
				for(int f=1;f<=n;f++){
					fio<<s[f];
					if(f==i){
						fio<<'+';
					}
					if(f==j){
						fio<<'=';
					}
				}
				return 0;
			}
		}else{
			int j=n-i;
			if(i==j){
				continue;
			}
			INT ans1=ha[i]+(ha[j]-ha[i]*mii[j-i]);
			INT ans2=(ha2[i]+(ha2[j]-ha2[i]*mii2[j-i]%MOD+MOD)%MOD)%MOD;
			if((i==1||s[1]!='0')&&(j==i+1||s[i+1]!='0')&&(n==j+1||s[j+1]!='0')&&ans1==ha[n]-ha[j]*mii[n-j]&&ans2==(ha2[n]-ha2[j]*mii2[n-j]%MOD+MOD)%MOD){
				for(int f=1;f<=n;f++){
					fio<<s[f];
					if(f==i){
						fio<<'+';
					}
					if(f==j){
						fio<<'=';
					}
				}
				return 0;
			}
			j=n-i-1;
			if(i==j){
				continue;
			}
			ans1=ha[i]+(ha[j]-ha[i]*mii[j-i]);
			ans2=(ha2[i]+(ha2[j]-ha2[i]*mii2[j-i]%MOD+MOD)%MOD)%MOD;
			if((i==1||s[1]!='0')&&(j==i+1||s[i+1]!='0')&&(n==j+1||s[j+1]!='0')&&ans1==ha[n]-ha[j]*mii[n-j]&&ans2==(ha2[n]-ha2[j]*mii2[n-j]%MOD+MOD)%MOD){
				for(int f=1;f<=n;f++){
					fio<<s[f];
					if(f==i){
						fio<<'+';
					}
					if(f==j){
						fio<<'=';
					}
				}
				return 0;
			}
		}
	}
	return 0;
}