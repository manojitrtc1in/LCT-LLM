
































































































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





namespace eto{
	INT a[107],p[107];
	int k;
	INT mii[107][107];
	INT id0;
	INT la,lb,lc;
	INT V;
	INT maxb,maxa;

	INT id2(INT x){
		INT l=0,r=1000000002;
		while(r-l>1){
			INT m=(l+r)>>1;
			if(m*m<=x){
				l=m;
			}else{
				r=m;
			}
		}
		return l;
	}

	INT id1(INT x){
		INT l=0,r=1000002;
		while(r-l>1){
			INT m=(l+r)>>1;
			if(m*m*m<=x){
				l=m;
			}else{
				r=m;
			}
		}
		return l;
	}

	void dfsb(int djg,INT tmpa,INT tmpb){
		if(tmpb>maxb){
			return;
		}
		if(djg==k){
			INT tmpc=V/tmpa/tmpb;
			if(2*(tmpa*tmpb+tmpa*tmpc+tmpb*tmpc)<id0){
				id0=2*(tmpa*tmpb+tmpa*tmpc+tmpb*tmpc);
				la=tmpa;
				lb=tmpb;
				lc=tmpc;
			}
			return;
		}
		if(p[djg]){
			p[djg]--;
			dfsb(djg,tmpa,tmpb*a[djg]);
			p[djg]++;
		}
		dfsb(djg+1,tmpa,tmpb);
	}

	void dfsa(int djg,INT tmpa){
		if(tmpa>maxa){
			return;
		}
		if(djg==k){
			maxb=sqrt(V/tmpa);
			if(2*(V/tmpa+2*tmpa*maxb)>id0){
				return;
			}
			dfsb(0,tmpa,1);
			return;
		}
		if(p[djg]){
			p[djg]--;
			dfsa(djg,tmpa*a[djg]);
			p[djg]++;
		}
		dfsa(djg+1,tmpa);
	}

	void threebody(){
		fio>>k;
		V=1;
		for(int i=0;i<k;i++){
			fio>>a[i]>>p[i];
			mii[i][0]=1;
			for(int j=1;j<=p[i];j++){
				mii[i][j]=mii[i][j-1]*a[i];
				V*=a[i];
			}
		}
		id0=INF;

		maxa=pow(V,1.0/3)+1;

		dfsa(0,1);
		fio<<id0<<' '<<la<<' '<<lb<<' '<<lc<<endl;
	}
}

int main(){
	int t;
	fio>>t;
	while(t--){
		eto::threebody();
	}
	return 0;
}


