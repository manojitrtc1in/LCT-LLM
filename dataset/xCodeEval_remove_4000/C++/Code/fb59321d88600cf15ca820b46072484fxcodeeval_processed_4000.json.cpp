


































































































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





int n,p,k;
int a[100005],b[100005];
vector<pair<pii,int> > s1,s2;
int whr1[100005],whr2[100005],whr[100005],Whr[100005];
pii qzh[100005];

bool cmp1(pair<pii,int> a,pair<pii,int> b){
	return a.first.second==b.first.second?a.first.first<b.first.first:a.first.second>b.first.second;
}

bool cmp2(pair<pii,int> a,pair<pii,int> b){
	return a.first.first==b.first.first?a.first.second>b.first.second:a.first.first>b.first.first;
}

struct{
	INT dt[100005];
	void add(int a,int x){
		a++;
		while(a<100005){
			dt[a]+=x;
			a+=a&-a;
		}
	}
	INT sum(int a){
		a++;
		INT sum=0;
		while(a){
			sum+=dt[a];
			a-=a&-a;
		}
		return sum;
	}
}bit,bit2;

int main(){
	fio>>n>>p>>k;
	for(int i=0;i<n;i++){
		fio>>a[i]>>b[i];
		s1.pb(mp(mp(a[i],b[i]),i));
		s2.pb(mp(mp(a[i],b[i]),i));
	}
	sort(ALL(s1),cmp1);
	sort(ALL(s2),cmp2);
	INT ans=0,ans2=0;
	int whrr=0;
	for(int i=0;i<n;i++){
		whr1[s1[i].second]=i;
		whr2[s2[i].second]=i;
	}
	for(int i=0;i<n;i++){
		whr[whr1[i]]=whr2[i];
	}
	for(int i=0;i<n-p+k;i++){
		bit.add(whr[i],1);
		bit2.add(whr[i],s1[i].first.first);
		int l=-1,r=100004;
		while(r-l>1){
			int m=(l+r)>>1;
			if(bit.sum(m)<=k){
				l=m;
			}else{
				r=m;
			}
		}
		INT x=bit2.sum(l);
		if(x>ans2){
			ans2=x;
			whrr=i;
		}
	}
	xqi pq;
	for(int i=0;i<=whrr;i++){
		pq.push(whr[i]);
	}
	for(int i=0;i<k;i++){
		int x=pq.top();
		pq.pop();
		fio<<s2[x].second+1<<' ';
	}
	for(int i=whrr+1,j=k;j<p;j++,i++){
		fio<<s1[i].second+1<<' ';
	}
	fio<<endl;
	return 0;
}