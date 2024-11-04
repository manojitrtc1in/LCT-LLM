


































































































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





struct BIT{
	int dt[50005];
	void plus(int a,int x){
		while(a<50005){
			dt[a]+=x;
			a+=a&-a;
		}
	}
	int sum(int a){
		int ans=0;
		while(a){
			ans+=dt[a];
			a-=a&-a;
		}
		return ans;
	}
};

struct segtree{
	int dt[800005],wp[800005];
	void plus(int now,int nl,int nr,int l,int r,int wht){
		if(wp[now]){
			dt[now<<1]+=wp[now];
			dt[now<<1|1]+=wp[now];
			wp[now<<1]+=wp[now];
			wp[now<<1|1]+=wp[now];
			wp[now]=0;
		}
		if(nl>=l&&nr<=r){
			dt[now]+=wht;
			wp[now]+=wht;
			return;
		}
		if(nr<l||nl>r){
			return;
		}
		int m=(nl+nr)>>1;
		plus(now<<1,nl,m,l,r,wht);
		plus(now<<1|1,m+1,nr,l,r,wht);
		dt[now]=min(dt[now<<1],dt[now<<1|1]);
	}
	int qmin(int now,int nl,int nr,int l,int r){
		if(wp[now]){
			dt[now<<1]+=wp[now];
			dt[now<<1|1]+=wp[now];
			wp[now<<1]+=wp[now];
			wp[now<<1|1]+=wp[now];
			wp[now]=0;
		}
		if(nl>=l&&nr<=r){
			return dt[now];
		}
		if(nr<l||nl>r){
			return Inf;
		}
		int m=(nl+nr)>>1;
		return min(qmin(now<<1,nl,m,l,r),qmin(now<<1|1,m+1,nr,l,r));
	}
}seg;

char s[50005];
int n;
VPII fs;

int main(){
	fio>>s;
	n=strlen(s);
	INT ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			seg.plus(1,0,n-1,i,n-1,1);
		}else if(s[i]==')'){
			seg.plus(1,0,n-1,i,n-1,-1);
		}else{
			s[i]='(';
			int a,b;
			fio>>a>>b;
			seg.plus(1,0,n-1,i,n-1,1);
			fs.pb(mp(b-a,i));
			ans+=a;
		}
	}
	sort(ALL(fs));
	for(int i=0;i<SZ(fs);i++){
		if(seg.qmin(1,0,n-1,fs[i].second,n-1)>=2){
			seg.plus(1,0,n-1,fs[i].second,n-1,-2);
			ans+=fs[i].first;
			s[fs[i].second]=')';
		}
	}
	if(seg.dt[1]<0){
		OVER("-1\n");
	}
	if(seg.qmin(1,0,n-1,n-1,n-1)){
		OVER("-1\n");
	}
	fio<<ans<<endl;
	fio<<s<<endl;
	return 0;
}