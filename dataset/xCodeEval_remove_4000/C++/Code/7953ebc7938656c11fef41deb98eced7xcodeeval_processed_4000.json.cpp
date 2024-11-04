
































































































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





INT V;
INT p[107],a[107],afuck[107];
int n;

INT SQRT(INT x){
	INT y=sqrt(x)+1;
	while(y*y>x){
		y--;
	}
	return y;
}

INT CBRT(INT x){
	INT y=cbrt(x)+1;
	while(y*y*y>x){
		y--;
	}
	return y;
}

vector<INT> fs;

INT id0(INT num,INT now=1,int djg=n){
	if(now<=num){
		if(!djg){
			return now;
		}
		INT ans=0,fo=1;
		djg--;
		for(int i=0;i<=a[djg];i++){
			ans=max(ans,id0(num,now*fo,djg));
			fo*=p[djg];
		}
		return ans;
	}
	return 0;
}

void id1(INT num,INT now=1,int djg=n){
	if(now<=num){
		if(!djg){
			fs.pb(now);
			return;
		}
		INT fo=1;
		djg--;
		for(int i=0;i<=a[djg];i++){
			id1(num,now*fo,djg);
			fo*=p[djg];
		}
	}
}

INT calc(INT a,INT b,INT c){
	return a*(b+c)+b*c;
}

int main(){
	int t;
	fio>>t;
	while(t--){
		fio>>n;
		V=1;
		for(int i=0;i<n;i++){
			fio>>p[i]>>a[i];
			for(int j=0;j<a[i];j++){
				V*=p[i];
			}
		}
		fs.clear();
		id1(CBRT(V));
		sort(fs.rbegin(),fs.rend());
		pair<PII,PII> ans=mp(mp(calc(V,1,1),V),mp(1,1));
		for(INT f:fs){
			INT rem=V/f;
			INT remt=SQRT(rem);
			INT cremt=rem/remt;
			if(calc(f,remt,cremt)>=ans.first.first){
				continue;
			}
			INT fuck=f;
			for(int i=0;i<n;i++){
				afuck[i]=a[i];
			}
			for(int i=0;i<n;i++){
				while(fuck%p[i]==0){
					a[i]--;
					fuck/=p[i];
				}
			}
			INT x=id0(remt);
			INT cx=rem/x;
			ans=min(ans,mp(mp(calc(f,x,cx),f),mp(x,cx)));
			for(int i=0;i<n;i++){
				a[i]=afuck[i];
			}
		}
		fio<<2*ans.first.first<<' '<<ans.first.second<<' '<<ans.second.first<<' '<<ans.second.second<<endl;
	}
	return 0;
}