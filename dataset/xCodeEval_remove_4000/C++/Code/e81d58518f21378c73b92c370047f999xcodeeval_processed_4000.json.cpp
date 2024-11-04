


































































































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





const int MAXN=5005;

struct bit2d{
	int dt[MAXN][MAXN];
	void add1line(int x,int y,int a){
		while(y<MAXN){
			dt[x][y]+=a;
			y+=(y&-y);
		}
	}
	int sum1line(int x,int y){
		int sum=0;
		while(y){
			sum+=dt[x][y];
			y-=(y&-y);
		}
		return sum;
	}
	void add(int x,int y,int a){
		

		while(x<MAXN){
			add1line(x,y,a);
			x+=(x&-x);
		}
	}
	int sum(int x,int y){
		int sum=0;
		while(x){
			sum+=sum1line(x,y);
			x-=(x&-x);
		}
		return sum;
	}
	int sum(int x1,int x2,int y1,int y2){
		x1--;
		y1--;
		x1=max(x1,0);
		y1=max(y1,0);
		x2=max(x2,0);
		y2=max(y2,0);
		x1=min(x1,MAXN-1);
		y1=min(y1,MAXN-1);
		x2=min(x2,MAXN-1);
		y2=min(y2,MAXN-1);
		

		return sum(x2,y2)-sum(x2,y1)-sum(x1,y2)+sum(x1,y1);
	}
}bit;

int n,m,k;

pii change(int x,int y){
	return mp(x+y,x-y+m);
}

pii changeback(int x,int y){
	return mp((x+y-m)/2,(x-y+m)/2);
}

pii changeback(pii xy){
	return changeback(xy.first,xy.second);
}

pii id0(int y,int x1,int x2){
	if(!bit.sum(x1,x2,y,y)){
		return mp(Inf,Inf);
	}
	x1=max(x1,0);
	x2=min(x2,MAXN-1);
	int l=x1-1,r=x2;
	while(r-l>1){
		int m=(l+r)>>1;
		if(bit.sum(x1,m,y,y)){
			r=m;
		}else{
			l=m;
		}
	}
	

	return changeback(r,y);
}

pii id1(int x,int y1,int y2){
	

	if(!bit.sum(x,x,y1,y2)){
		return mp(Inf,Inf);
	}
	y1=max(y1,0);
	y2=min(y2,MAXN-1);
	int l=y1-1,r=y2;
	while(r-l>1){
		int m=(l+r)>>1;
		if(bit.sum(x,x,y1,m)){
			r=m;
		}else{
			l=m;
		}
	}
	

	return changeback(x,r);
}

int main(){
	fio>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pii chg=change(i,j);
			bit.add(chg.first,chg.second,1);
		}
	}
	while(k--){
		int x,y;
		fio>>x>>y;
		pii chg=change(x,y);
		x=chg.first;
		y=chg.second;
		

		int l=-1,r=n+m;
		while(r-l>1){
			int m=(l+r)>>1;
			if(bit.sum(x-m,x+m,y-m,y+m)){
				r=m;
			}else{
				l=m;
			}
		}
		l=r;
		

		pii ans=min(min((id0(y-l,x-l,x+l)),(id0(y+l,x-l,x+l))),min((id1(x-l,y-l,y+l)),(id1(x+l,y-l,y+l))));
		

		int minx=ans.first,miny=ans.second;
		

		fio<<minx<<' '<<miny<<endl;
		chg=change(minx,miny);
		

		

		bit.add(chg.first,chg.second,-1);
	}
	return 0;
}