


































































































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





struct node{
	pii mn;
	node(){
		mn.first=Inf;
		mn.second=Inf;
	}
	node(int a,int b){
		mn=mp(a,b);
	}
};

node tmp,brk;

node qmax(node l,node r){
	tmp.mn=min(l.mn,r.mn);
	return tmp;
}

struct Segtree{
	node dt[2000005];
	void init(int l,int r,int now=1){
		if(l==r){
			dt[now]=node(Inf,l);
			return;
		}
		int m=(l+r)>>1;
		init(l,m,now<<1);
		init(m+1,r,now<<1|1);
		dt[now]=qmax(dt[now<<1],dt[now<<1|1]);
	}
	void upd(int whr,int val,int l,int r,int now=1){
		if(l>whr||r<whr){
			return;
		}
		if(l==whr&&r==whr){
			dt[now].mn=mp(val,l);
			return;
		}
		int m=(l+r)>>1;
		upd(whr,val,l,m,now<<1);
		upd(whr,val,m+1,r,now<<1|1);
		dt[now]=qmax(dt[now<<1],dt[now<<1|1]);
	}
	node qry(int L,int R,int l,int r,int now=1){
		if(l>R||r<L){
			return brk;
		}
		if(L<=l&&r<=R){
			return dt[now];
		}
		int m=(l+r)>>1;
		return qmax(qry(L,R,l,m,now<<1),qry(L,R,m+1,r,now<<1|1));
	}
}seg;

int n,a[500005];
int prv[500005],aa[500005];
int ans[500005];
vpii li[500005];

int main(){
	fio>>n;
	for(int i=0;i<n;i++){
		fio>>a[i];
		aa[a[i]]=-1;
	}
	for(int i=0;i<n;i++){
		prv[i]=aa[a[i]];
		aa[a[i]]=i;
	}
	int q;
	fio>>q;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		l--;r--;
		li[r].pb(mp(l,i));
	}
	seg.init(0,n-1);
	for(int i=0;i<n;i++){
		seg.upd(i,prv[i],0,n-1);
		if(prv[i]!=-1){
			seg.upd(prv[i],Inf,0,n-1);
		}
		for(pii it:li[i]){
			pii p=seg.qry(it.first,i,0,n-1).mn;
			if(p.first<it.first){
				ans[it.second]=a[p.second];
			}
		}
	}
	for(int i=0;i<q;i++){
		fio<<ans[i]<<endl;
	}
	return 0;
}