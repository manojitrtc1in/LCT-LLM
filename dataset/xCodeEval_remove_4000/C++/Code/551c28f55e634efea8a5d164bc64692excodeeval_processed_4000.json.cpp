
using namespace std;









namespace fastIO
{





	static bool IOerror=0;

	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}

	inline char nc(){static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;if(p1==pend){p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);if(pend==p1){IOerror=1;return -1;}}return *p1++;}

	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T&x){bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return false;if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(sign)x=-x;return true;}
	inline bool read(unsigned long long&x){char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return false;for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';return true;}
	inline bool read(unsigned int&x){char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return false;for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';return true;}
	inline bool read(double&x){bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return false;if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(ch=='.'){double tmp=1;ch=nc();for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');}if(sign)x=-x;return true;}
	inline bool read(char*s){char ch=nc();for(;blank(ch);ch=nc());if(IOerror)return false;for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;*s=0;return true;}
	inline bool read(char&c){for(c=nc();blank(c);c=nc());if(IOerror){c=-1;return false;}return true;}
	inline bool read(std::string&s){s.clear();char ch=nc();for(;blank(ch);ch=nc());if(IOerror)return false;for(;!blank(ch)&&!IOerror;ch=nc())s+=ch;return true;}
	template<class T,class... U> bool read(T&h,U&... t){return read(h)&&read(t...);}
	struct id0
	{

		inline void out(char ch) { putchar(ch); }

		constexpr static LL Mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
		char*buf,*p1,*pend;
		id0(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
		inline void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}

		template<class T> inline void print(T x){static char s[41],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);}
		inline void print(char ch){out(ch);}
		inline void print(unsigned long long x){static char s[41],*s1;s1=s;if(!x)*s1++='0';while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);}
		inline void print(unsigned int x){static char s[41],*s1;s1=s;if(!x)*s1++='0';while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);}
		inline void print(double x,int y=DECIMAL){if(x<-1e-12)out('-'),x=-x;x*=Mul[y];LL x1=(LL)floor(x);if(x-floor(x)>=0.5)++x1;LL x2=x1/Mul[y],x3=x1-x2*Mul[y];print(x2);if(y>0){out('.');for(size_t i=1;i<y&&x3*Mul[i]<Mul[y];out('0'),++i);print(x3);}}
		inline void print(char*s){while(*s)out(*s++);}
		inline void print(const char*s){while(*s)out(*s++);}
		inline void print(std::string s){print(s.c_str());}

		inline void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~id0(){flush();}

	}Ostream;
	template<class T> inline void print(T x){Ostream.print(x);}
	template<class T> inline void println(T x){Ostream.print(x);Ostream.out('\n');}
	inline void print(double x,int y=DECIMAL){Ostream.print(x,y);}
	inline void println(double x,int y=DECIMAL){Ostream.print(x,y);Ostream.out('\n');}
	template<class T,class... U> void print(const T&h,const U&... t){print(h);Ostream.out(' ');print(t...);}
	template<class T,class... U> void println(const T&h,const U&... t){print(h);Ostream.out(' ');println(t...);}

	inline void flush(){Ostream.flush();}




}
using namespace fastIO;



const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double pi=acos(-1.0);

const int P=998244353;
namespace ModInt
{
	inline int norm(int x){if(x<0)x+=P;if(x>=P)x-=P;return x;}
	template<class T> T power(T a,ll n){T ans=1;while(n){if(n&1)ans=ans*a;a=a*a;n>>=1;}return ans;}
	struct Z
	{
		int x;
		Z(int x=0):x(norm(x)){}
		Z(ll x):x(norm(x%P)){}
		int val()const{return x;}
		operator int(){return x;}
		Z operator-()const{return Z(norm(P-x));}
		Z inv()const{assert(x!=0);return power(*this,P-2);}
		Z&operator*=(const Z&rhs){x=(ll)x*rhs.x%P;return *this;}
		Z&operator+=(const Z&rhs){x=norm(x+rhs.x);return *this;}
		Z&operator-=(const Z&rhs){x=norm(x-rhs.x);return *this;}
		Z&operator/=(const Z&rhs){return *this*=rhs.inv();}
		friend Z operator*(const Z&lhs,const Z&rhs){Z res=lhs;res*=rhs;return res;}
		friend Z operator+(const Z&lhs,const Z&rhs){Z res=lhs;res+=rhs;return res;}
		friend Z operator-(const Z&lhs,const Z&rhs){Z res=lhs;res-=rhs;return res;}
		friend Z operator/(const Z&lhs,const Z&rhs){Z res=lhs;res/=rhs;return res;}
		friend istream&operator>>(istream&is,Z&a){ll v;is>>v;a=Z(v);return is;}
		friend ostream&operator<<(ostream&os,const Z&a){return os<<a.val();}
	};
}
using namespace ModInt;



int n,m;
char str[300005];
string s[300005];
pair<int,int> id1(int x)
{
	return {x/m+(bool)(x%m),(x-1)%m+1};
}
int id2(int x,int y)
{
	return (x-1)*m+y;
}
struct Edge
{
	int to,dis;
};
vector<Edge>edge[300005];
struct city
{
	int id,dis;
	bool operator<(const city&c)const
	{
		return dis>c.dis;
	}
};
priority_queue<city>pq;
int dis[300005];
int vis[300005];

void solve()
{
	scanf("%lld%lld",&n,&m);
	int p,q;
	scanf("%lld%lld",&p,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		s[i]=" "+(string)str;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)if(s[i][j]!='
		{
			if(s[i][j]=='D'||s[i][j]=='R')if(i>1&&j>1&&s[i-1][j-1]!='
			if(s[i][j]=='D'||s[i][j]=='L')if(i>1&&j<m&&s[i-1][j+1]!='
			if(s[i][j]=='U'||s[i][j]=='R')if(i<n&&j>1&&s[i+1][j-1]!='
			if(s[i][j]=='U'||s[i][j]=='L')if(i<n&&j<m&&s[i+1][j+1]!='
			if(s[i][j]=='D')if(i>2&&s[i-2][j]!='
			if(s[i][j]=='U')if(i<n-1&&s[i+2][j]!='
			if(s[i][j]=='R')if(j>2&&s[i][j-2]!='
			if(s[i][j]=='L')if(j<m-1&&s[i][j+2]!='
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		dis[i]=INF;
		vis[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='.')
			{
				dis[id2(i,j)]=0;
				pq.push({id2(i,j),0});
			}
		}
	}
	while(!pq.empty())
	{
		auto [id,d]=pq.top();
		pq.pop();
		if(vis[id])continue;
		else vis[id]=1;
		for(auto [it,dd]:edge[id])
		{
			if(dis[it]>dis[id]+dd)
			{
				dis[it]=dis[id]+dd;
				pq.push({it,dis[it]});
			}
		}
	}
	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)if(dis[id2(i,j)]!=INF)
		{
			if(i<n&&dis[id2(i+1,j)]!=INF)ans=min(ans,dis[id2(i,j)]+dis[id2(i+1,j)]);
			if(j<m&&dis[id2(i,j+1)]!=INF)ans=min(ans,dis[id2(i,j)]+dis[id2(i,j+1)]);
		}
	}














	if(ans==INF)printf("-1\n");
	else printf("%lld\n",ans);
}



signed main()
{







	




		solve();
	return 0;
}
