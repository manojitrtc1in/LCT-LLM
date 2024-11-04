


































































































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





int ha1[1000005],mii1[1000005];
INT ha2[1000005],mii2[1000005];
int n;

inline int id0(int l,int r){
	int ans1=ha1[r];
	int ans2=1LL*ha1[l]*mii1[r-l]%Mod;
	return (ans1-ans2+Mod)%Mod;
}

inline INT id1(int l,int r){
	INT ans1=ha2[r];
	INT ans2=ha2[l]*mii2[r-l];
	return ans1-ans2;
}

inline bool test1(int l,int r){
	

	return (id0(0,l)+id0(l,r))%Mod==id0(r,n);
}

inline bool test2(int l,int r){
	

	return (id1(0,l)+id1(l,r))==id1(r,n);
}

bool testcalc(const string &a,const string &b,const string &c){
	int now1=SZ(a)-1,now2=SZ(b)-1,now3=SZ(c)-1;
	int num=0;
	while(now3>=0){
		if(now1>=0){
			num+=a[now1]-'0';
			now1--;
		}
		if(now2>=0){
			num+=b[now2]-'0';
			now2--;
		}
		if(num%10!=c[now3]-'0'){
			return 0;
		}
		num/=10;
		now3--;
	}
	return 1;
}

inline void test(const string &s,int l,int r){
	if(l>1&&s[0]=='0'){
		return;
	}
	if(r>l+1&&s[l]=='0'){
		return;
	}
	if(n>r+1&&s[r]=='0'){
		return;
	}
	if(test1(l,r)&&test2(l,r)&&testcalc(s.substr(0,l),s.substr(l,r-l),s.substr(r,n-r))){
		cout<<s.substr(0,l)<<'+'<<s.substr(l,r-l)<<'='<<s.substr(r,n-r)<<endl;
		exit(0);
	}
}

int main(){
	string s;
	cin>>s;
	n=SZ(s);
	mii1[0]=mii2[0]=1;
	for(int i=1;i<=n;i++){
		mii1[i]=mii1[i-1]*10LL%Mod;
		mii2[i]=mii2[i-1]*10;
		ha1[i]=(ha1[i-1]*10LL+s[i-1]-'0')%Mod;
		ha2[i]=(ha2[i-1]*10+s[i-1]-'0');
	}
	for(int i=n-1;i>=0;i--){
		for(int j=max(1,n-i-2);j<=min(i-1,n-i+2);j++){
			test(s,j,i);
		}
		for(int j=max(1,i+i-n-2);j<=min(i-1,i+i-n+2);j++){
			test(s,j,i);
		}
	}
	return 0;
}