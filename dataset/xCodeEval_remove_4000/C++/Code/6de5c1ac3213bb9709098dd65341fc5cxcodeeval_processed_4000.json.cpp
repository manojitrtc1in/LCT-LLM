





































template <class X,class C=std::less<X>,class Y=__gnu_pbds::null_type>
using ordered_map=__gnu_pbds::tree<X,Y,C,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template <class X,class C=std::greater<X>>
using heap=__gnu_pbds::priority_queue<X, C>;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ull hash_type;
typedef complex<double> Complex;
template<typename ...T> using void_t=void;














id0(){}




template<typename T>void id3(const char* name,T&& t){cout<<name<<" = "<<t<<endl;}
template<typename T1,typename... T>void id3(const char* names,T1&& t1,T&&... t){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" = "<<t1<<", ";id3(comma+1,t...);}



namespace fastioput{
	const char lu[]="0123456789ABCDEF";
	const int lv[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	template<int __RR=10> class id1 {
		protected:
			int __R=__RR;
			int precision=6;
			template <class T = int> inline void writeInt(T x,int output_len=-1){if(x<0)putchar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]=lu[x%__R],x/=__R;while(n<output_len)s[n++]='0';while(n--)putchar(s[n]);}
			template<class T=unsigned int> inline void writeUInt(T x,int output_len=-1){char s[24];int n=0;while(x||!n)s[n++]=lu[x%__R],x/=__R;while(n<output_len)s[n++]='0';while(n--)putchar(s[n]);}
			inline void writeWord(const char *s){while(*s)putchar(*s++);}
			template<class T=double>inline void writeDouble(T x,int output_len=-1){if(x<0)putchar('-'),x=-x;int t=(int)x;writeUInt(t),x-=t;putchar('.');for(int i=output_len-1;i>0;i--){x*=__R;t=(int)x;putchar(lu[t]),x-=t;}x*=__R;t=min(__R-1,(int)(x+__R/2));putchar(lu[t]);}
			inline void writestring(const string &x){writeWord(x.c_str());}
		public:
			id1() { }
			id1&change_base(int x) {__R=x;return *this;}
			id1&operator<<(const int &x){writeInt<int>(x,-1);return *this;}
			id1&operator<<(const long long &x){writeInt<long long>(x,-1);return *this;}
			id1&operator<<(const unsigned &x){writeUInt<unsigned>(x,-1);return *this;}
			id1&operator<<(const unsigned long long &x)
			{writeUInt<unsigned long long>(x,-1);return *this;}
			id1&operator<<(const float &x){writeDouble<float>(x,precision);return *this;}
			id1&operator<<(const double &x){writeDouble<double>(x,precision);return *this;}
			id1&operator<<(const long double &x)
			{writeDouble<long double>(x,precision);return *this;}
			id1&operator<<(const char &x){putchar(x);return *this;}
			id1&operator<<(char *x){writeWord(x);return *this;}
			id1&operator<<(const string &x){writestring(x);return *this;}
			id1& setprecision(int __precision){precision=__precision;return *this;}
			id1&operator<<(id1 &ms){return *this;}
			template<typename _I>id1&print(_I a,_I b,char c=' '){while(a<b){operator<<(*a);operator<<(c);a++;}return *this;}
			template<typename T>id1&writearr(T a[],int x,int y){return print(a+x,a+y);}
			template<typename T>id1&operator<<(const vector<T> &x){return print(x.begin(),x.end());}
			template<typename T>id1&operator<<(const deque<T> &x){return print(x.begin(),x.end());}
			template<typename T>id1&operator<<(const set<T> &x){return print(x.begin(),x.end());}
			template<typename T>id1&operator<<(const complex<T> &x){return operator<<(x.real)<<('+')<<(x.imag)<<'j';}
			template<typename T,typename Y>id1&operator<<(const pair<T,Y> &x){return operator<<('(')<<(x.first)<<(',')<<(x.second)<<')';}
	};
	template<int __RR=10> class id2 {
		protected:
			int __R=__RR;
			int precision=6;
			inline char getChar(){int c=getchar();if(islower(c))c=toupper(c);return c;}
			inline int readChar(){int c=getchar();while(c!=-1&&c<=32)c=getChar();return c;}
			template<class T=unsigned int>inline T readUInt(){int c=readChar();T x=0;while('0'<=c&&c<=lu[__R-1])x=x*__R+lv[c],c=getChar();return x;}
			template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();if(islower(c))c=toupper(c);while('0'<=c&&c<=lu[__R-1])x=x*__R+lv[c],c=getChar();return s==1?x:-x;}
			template<class T=double>inline T readDouble(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<=lu[__R-1])x=x*__R+lv[c],c=getChar();if(c=='.'){c=getChar();long double coef=1.0/__R;while('0'<=c&&c<=lu[__R-1]){x+=lv[c]*(coef);coef*=1.0/__R;c=getChar();}}return s==1?x:-x;}
			inline void readWord(char *s){int c=readChar();while(c>32)*s++=(char)c,c=getChar();*s=0;}
			inline bool readLine(char *s,char cc='\n'){int c=getChar();while(c!=cc&&c!=-1)*s++=(char)c,c=getChar();*s=0;return c!=-1;}
			inline string readstring(){char s[1000005];readWord(s);return string(s);}
			inline string readLinestring(char cc='\n'){char s[1000005];readLine(s,cc);return string(s);}
		public:
			id2() { }
			id2&change_base(int x) {__R=x;return *this;}
			id2&operator>>(int &x){x=readInt<int>();return *this;}
			id2&operator>>(long long &x){x=readInt<long long>();return *this;}
			id2&operator>>(unsigned &x){x=readUInt<unsigned>();return *this;}
			id2&operator>>(unsigned long long &x){x=readUInt<unsigned long long>();return *this;}
			id2&operator>>(float &x){x=readDouble<float>();return *this;}
			id2&operator>>(double &x){x=readDouble<double>();return *this;}
			id2&operator>>(long double &x){x=readDouble<long double>();return *this;}
			id2&operator>>(char &x){x=readChar();return *this;}
			id2&operator>>(char *x){readWord(x);return *this;}
			id2&operator>>(string &x){x=readstring();return *this;}
			template<typename T>id2&operator>>(vector<T> &x){if(x.size())input(x.begin(),x.end());else{string st;readline(st);stringstream ss(st);int k;while(ss>>k)x.push_back(k);}return *this;}
			id2&readline(string &s,char cc='\n'){s=readLinestring(cc);return *this;}
			id2&readline(char *s,char cc='\n'){readLine(s,cc);return *this;}
			template<typename T>id2&readarr(T a[],int x,int y){return input(a+x,a+y);}
			template<typename _I>id2&input(_I a,_I b){do{operator>>(*a);a++;}while(a<b);return *this;}
			id2&operator>>(id2 &ms){return *this;}
	};
}
fastioput::id1<10> costr;fastioput::id2<10> cistr;
template<typename T>T compare(const char *s,...){va_list a;va_start(a,s);string t=s,o=t.substr(0,3);T res;if(o=="max")res=numeric_limits<T>::min();else if(o=="min")res=numeric_limits<T>::max();else if(o=="sum")res=T(0);else{__builtin_fprintf(stderr,"You Type is awful!");__builtin_abort();exit(3);}int x=stoi(t.substr(4));while(x--){T p=va_arg(a,T);if(o=="max")res=max(res,p);else if(o=="min")res=min(res,p);else res+=p;}va_end(a);return res;}
vector<string> splitstring(const string&s,const string&c){vector<string> v;string::size_type pos1,pos2;pos2=s.find(c);pos1=0;while(string::npos!=pos2){v.push_back(s.substr(pos1,pos2-pos1));pos1=pos2+c.size();pos2=s.find(c,pos1);}if(pos1!=s.length())v.push_back(s.substr(pos1));}
namespace numbers
{
	ll gcd(ll a,ll b){while(b)b^=a^=b^=a%=b;return a;}
	ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
	inline ll fastpow(ll a,ll b,ll mod){ll c=1;while(b){if(b&1)c=c*a%mod;a=a*a%mod;b>>=1;}return c;}
	inline ll fastpow(ll a,ll b){ll c=1;while(b){if(b&1)c*=a;a*=a;b>>=1;}return c;}
	inline bool isprime(const ll &x){if(x<=4||x%2==0||x%3==0){return x==2||x==3;}for(int i=5;i*i<=x;i+=6){if(x%i==0||x%(i+2)==0){return false;}}return true;}
	inline int reverse_bits(int x){x=((x>>1)&0x55555555)|((x<<1)&0xaaaaaaaa);x=((x>>2)&0x33333333)|((x<<2)&0xcccccccc);x=((x>>4)&0x0f0f0f0f)|((x<<4)&0xf0f0f0f0);x=((x>>8)&0x00ff00ff)|((x<<8)&0xff00ff00);x=((x>>16)&0x0000ffff)|((x<<16)&0xffff0000);return x;}
	inline ll reverse_bits(ll x){x=((x>>1)&0x5555555555555555ll)|((x<<1)&0xaaaaaaaaaaaaaaaall);x=((x>>2)&0x3333333333333333ll)|((x<<2)&0xccccccccccccccccll);x=((x>>4)&0x0f0f0f0f0f0f0f0fll)|((x<<4)&0xf0f0f0f0f0f0f0f0ll);x=((x>>8)&0x00ff00ff00ff00ffll)|((x<<8)&0xff00ff00ff00ff00ll);x=((x>>16)&0x0000ffff0000ffffll)|((x<<16)&0xffff0000ffff0000ll);x=((x>>32)&0x00000000ffffffffll)|((x<<32)&0xffffffff00000000ll);return x;}
	template<class T>inline bool odd(T x){return x&1;}
	template<class T>inline bool even(T x){return !odd(x);}
	template<class T>inline T lowbit(T x){return x&-x;}
	template<class T>inline T highbit(T x){T p=lowbit(x);while(p!=x)x-=p,p=lowbit(x);return p;}
	template<class T>inline T coverbit(T x){T p=1;while(p<x)p<<=1;return p;}
	template<class T>inline int coveridx(T x){int p=0;while((1<<p)<x)++p;return p;}
	inline int clz(int x){return __builtin_clz(x);}
	inline int clz(ll x){return __builtin_clzll(x);}
	inline int ctz(int x){return __builtin_ctz(x);}
	inline int ctz(ll x){return __builtin_ctzll(x);}
	inline int lg2(int x){return !x?-1:31-clz(x);}
	inline int lg2(ll x){return !x?-1:63-clz(x);}
	inline int lowidx(int x){return !x?-1:ctz(x);}
	inline int lowidx(ll x){return !x?-1:ctz(x);}
	inline int highidx(int x){return lg2(x);}
	inline int highidx(ll x){return lg2(x);}
	inline int parity(int x){return __builtin_parity(x);}
	inline int parity(ll x){return __builtin_parityll(x);}
	inline int count_bits(int x){return __builtin_popcount(x);}
	inline int count_bits(ll x){return __builtin_popcountll(x);}
}


const short single_test=1;
const int inf=1e9;
const long long lnf=1e18;
const long long h1=239017,h2=731604233;
const long long mod=1000000007,mod2=1000000009;
const long double pi=3.141592653589793238462643383279;
const long double EPS=1e-9;
struct rectangle
{
	int x1,x2;
	int y1,y2;
	rectangle(int x1,int y1,int x2,int y2) : x1(x1),y1(y1),x2(x2),y2(y2) { }
};
vector <rectangle> v;
int n,x,y,X,Y;
int xm[2005],ym[2005];
bool obs[2005][2005],a[2005][2005];
map <int,int> mx,my;
void dfs(int x,int y)
{
	if (x<0 || x>=X || y<0 || y>=Y || obs[x][y] || a[x][y]) return;
	a[x][y]=true;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
bool solve(const int &test)
{
	cin>>n;
	rep(i,n)
	{
		char dir;
		int d;
		cin>>dir>>d;
		if (dir=='L')
		{
			rectangle r={x-d,y,x+1,y+1};
			v.push_back(r);
			x-=d;
		}
		if (dir=='R')
		{
			rectangle r={x,y,x+d+1,y+1};
			v.push_back(r);
			x+=d;
		}
		if (dir=='U')
		{
			rectangle r={x,y,x+1,y+d+1};
			v.push_back(r);
			y+=d;
		}
		if (dir=='D')
		{
			rectangle r={x,y-d,x+1,y+1};
			v.push_back(r);
			y-=d;
		}
	}
	rep(i,n)
	{
		mx[v[i].x1]=mx[v[i].x2]=0;
		my[v[i].y1]=my[v[i].y2]=0;
	}
	for (auto &it:mx)
	{
		it.second=X;
		xm[X++]=it.first;
	}
	for (auto &it:my)
	{
		it.second=Y;
		ym[Y++]=it.first;
	}
	--X,--Y;
	rep(i,n)
	{
		int x1=mx[v[i].x1],x2=mx[v[i].x2],y1=my[v[i].y1],y2=my[v[i].y2];
		for (int j=x1;j<x2;++j) for (int k=y1;k<y2;++k) obs[j][k]=true;
	}
	rep(i,X)rep(j,Y) if (!i || i==X-1 || !j || j==Y-1) dfs(i,j);
	long long ans=0;
	rep(i,X)rep(j,Y) if (!a[i][j])
	{
		long long dx=xm[i+1]-xm[i],dy=ym[j+1]-ym[j];
		ans+=dx*dy;
	}
	cout<<ans<<endl;
	return false;
}
void main_init()
{
	__builtin_fprintf(stderr,"文件信息 :                   Messages of The File :\n日期 : %s           Date : %s\n运行时间 : %s          Operation Time :%s\n作者 : libra9z               author : libra9z\n",__DATE__,__DATE__,__TIME__,__TIME__);fprintf(stderr,"文件 : %s\n",__FILE__);
	
	freopen(string(string(__FILE__).substr(string(__FILE__).find_last_of('\\')+1,string(__FILE__).find_last_of('.')-string(__FILE__).find_last_of('\\'))+"in").c_str(),"r",stdin);
	freopen(string(string(__FILE__).substr(string(__FILE__).find_last_of('\\')+1,string(__FILE__).find_last_of('.')-string(__FILE__).find_last_of('\\'))+"out").c_str(),"w",stdout);
	
}
signed main()
{
	main_init();
	int tests=single_test;if (!tests) __builtin_scanf("%d",&tests);
	else if (tests<0) tests=100000000;
	for (int test=1;test<=tests;++test) if (solve(test)) break;
	return 0;
}






















