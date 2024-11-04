


















#pragma comment(linker, "/stack:20000000")
#pragma warning(disable:4146)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS




#include <bits/stdc++.h>
#include <experimental/string_view>
#include <experimental/optional>
#include <tr2/dynamic_bitset>
#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>
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
#define rep(i,n) for (int i=0;i<(n);i++)
#define Rep(i,a,b) for (int i=(a);i<=(b);i++)
#define repit(it,a) for (__typeof(a.begin()) it=a.begin();it!=a.end();++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define RET(p,x) return p<<x<<endl,0
#define all(a) (a).begin(),(a).end()
#define reunique(v) v.erase(unique(all(v)),v.end())
#define sz(a) (int)a.size()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#define __str__(x) #x
#define sqr(x) ((x)*(x))
do_nothing(){}


#if !defined(__NOT_WANT_TO_DEBUG__)
#define Debug(...) __debug_assistant(#__VA_ARGS__,__VA_ARGS__)
template<typename T>void __debug_assistant(const char* name,T&& t){cout<<name<<" = "<<t<<endl;}
template<typename T1,typename... T>void __debug_assistant(const char* names,T1&& t1,T&&... t){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" = "<<t1<<", ";__debug_assistant(comma+1,t...);}
#else
#define Debug(...)
#endif
namespace fastioput{
	const char lu[]="0123456789ABCDEF";
	const int lv[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	template<int __RR=10> class my_ostream {
		protected:
			int __R=__RR;
			int precision=6;
			template <class T = int> inline void writeInt(T x,int output_len=-1){if(x<0)putchar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]=lu[x%__R],x/=__R;while(n<output_len)s[n++]='0';while(n--)putchar(s[n]);}
			template<class T=unsigned int> inline void writeUInt(T x,int output_len=-1){char s[24];int n=0;while(x||!n)s[n++]=lu[x%__R],x/=__R;while(n<output_len)s[n++]='0';while(n--)putchar(s[n]);}
			inline void writeWord(const char *s){while(*s)putchar(*s++);}
			template<class T=double>inline void writeDouble(T x,int output_len=-1){if(x<0)putchar('-'),x=-x;int t=(int)x;writeUInt(t),x-=t;putchar('.');for(int i=output_len-1;i>0;i--){x*=__R;t=(int)x;putchar(lu[t]),x-=t;}x*=__R;t=min(__R-1,(int)(x+__R/2));putchar(lu[t]);}
			inline void writestring(const string &x){writeWord(x.c_str());}
		public:
			my_ostream() { }
			my_ostream&change_base(int x) {__R=x;return *this;}
			my_ostream&operator<<(const int &x){writeInt<int>(x,-1);return *this;}
			my_ostream&operator<<(const long long &x){writeInt<long long>(x,-1);return *this;}
			my_ostream&operator<<(const unsigned &x){writeUInt<unsigned>(x,-1);return *this;}
			my_ostream&operator<<(const unsigned long long &x)
			{writeUInt<unsigned long long>(x,-1);return *this;}
			my_ostream&operator<<(const float &x){writeDouble<float>(x,precision);return *this;}
			my_ostream&operator<<(const double &x){writeDouble<double>(x,precision);return *this;}
			my_ostream&operator<<(const long double &x)
			{writeDouble<long double>(x,precision);return *this;}
			my_ostream&operator<<(const char &x){putchar(x);return *this;}
			my_ostream&operator<<(char *x){writeWord(x);return *this;}
			my_ostream&operator<<(const string &x){writestring(x);return *this;}
			my_ostream& setprecision(int __precision){precision=__precision;return *this;}
			my_ostream&operator<<(my_ostream &ms){return *this;}
			template<typename _I>my_ostream&print(_I a,_I b,char c=' '){while(a<b){operator<<(*a);operator<<(c);a++;}return *this;}
			template<typename T>my_ostream&writearr(T a[],int x,int y){return print(a+x,a+y);}
			template<typename T>my_ostream&operator<<(const vector<T> &x){return print(x.begin(),x.end());}
			template<typename T>my_ostream&operator<<(const deque<T> &x){return print(x.begin(),x.end());}
			template<typename T>my_ostream&operator<<(const set<T> &x){return print(x.begin(),x.end());}
			template<typename T>my_ostream&operator<<(const complex<T> &x){return operator<<(x.real)<<('+')<<(x.imag)<<'j';}
			template<typename T,typename Y>my_ostream&operator<<(const pair<T,Y> &x){return operator<<('(')<<(x.first)<<(',')<<(x.second)<<')';}
	};
	template<int __RR=10> class my_istream {
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
			my_istream() { }
			my_istream&change_base(int x) {__R=x;return *this;}
			my_istream&operator>>(int &x){x=readInt<int>();return *this;}
			my_istream&operator>>(long long &x){x=readInt<long long>();return *this;}
			my_istream&operator>>(unsigned &x){x=readUInt<unsigned>();return *this;}
			my_istream&operator>>(unsigned long long &x){x=readUInt<unsigned long long>();return *this;}
			my_istream&operator>>(float &x){x=readDouble<float>();return *this;}
			my_istream&operator>>(double &x){x=readDouble<double>();return *this;}
			my_istream&operator>>(long double &x){x=readDouble<long double>();return *this;}
			my_istream&operator>>(char &x){x=readChar();return *this;}
			my_istream&operator>>(char *x){readWord(x);return *this;}
			my_istream&operator>>(string &x){x=readstring();return *this;}
			template<typename T>my_istream&operator>>(vector<T> &x){if(x.size())input(x.begin(),x.end());else{string st;readline(st);stringstream ss(st);int k;while(ss>>k)x.push_back(k);}return *this;}
			my_istream&readline(string &s,char cc='\n'){s=readLinestring(cc);return *this;}
			my_istream&readline(char *s,char cc='\n'){readLine(s,cc);return *this;}
			template<typename T>my_istream&readarr(T a[],int x,int y){return input(a+x,a+y);}
			template<typename _I>my_istream&input(_I a,_I b){do{operator>>(*a);a++;}while(a<b);return *this;}
			my_istream&operator>>(my_istream &ms){return *this;}
	};
}
fastioput::my_ostream<10> costr;fastioput::my_istream<10> cistr;
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
const int N=1005;
int n,d,szx,szy;
pii x[2*N],y[2*N];
string dir;
pair <pii,pii> command[N];
bool blocked[2*N][2*N];
bool used[2*N][2*N];
void dfs(int i,int j) {
    if (i<0||j<0||i>=szx||j>=szy||blocked[i][j]||used[i][j]) return;
    used[i][j]=1;
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i,j+1);
}
bool solve(const int &test)
{
	cin>>n;
	int X=0,Y=0;
	x[szx++]=pii(X,1);
	y[szy++]=pii(Y,1);
	for(int i=0;i<n;i++) {
		cin>>dir>>d;
		int nX=X,nY=Y;
		if (dir=="R") nY+=d;
		if (dir=="L") nY-=d;
		if (dir=="U") nX-=d;
		if (dir=="D") nX+=d;
		if (dir=="L"||dir=="U") {
			command[i]=pair<pii,pii > (pii(nX,nY),pii(X,Y));
		} else {
			command[i]=pair<pii,pii > (pii(X,Y),pii(nX,nY));
		}
		x[szx++]=pii(nX,1);
		y[szy++]=pii(nY,1);
		X=nX;Y=nY;
	}
	x[szx++]=pii(-200000000,0);
	x[szx++]=pii(200000000,0);
	y[szy++]=pii(-200000000,0);
	y[szy++]=pii(200000000,0);
	sort(x,x+szx);
	sort(y,y+szy);
	szx=unique(x,x+szx)-x;
	szy=unique(y,y+szy)-y;
	int nszx=szx,nszy=szy;
	for(int i=0;i+1<szx;i++) {
		if (x[i+1].first-x[i].first-1>0) {
			x[nszx++]=pii(x[i].first+1,x[i+1].first-x[i].first-1);
		}
	}
	szx=nszx;
	for(int i=0;i+1<szy;i++) {
		if (y[i+1].first-y[i].first-1>0) {
			y[nszy++]=pii(y[i].first+1,y[i+1].first-y[i].first-1);
		}
	}
	szy=nszy;
	sort(x,x+szx);
	sort(y,y+szy);
	for(int i=0;i<n;i++) {
		int X1,X2,Y1,Y2;
		for(int j=0;j<szx;j++) if (x[j].first==command[i].first.first) X1=j;
		for(int j=0;j<szx;j++) if (x[j].first==command[i].second.first) X2=j;
		for(int j=0;j<szy;j++) if (y[j].first==command[i].first.second) Y1=j;
		for(int j=0;j<szy;j++) if (y[j].first==command[i].second.second) Y2=j;
		for(int j=X1;j<=X2;j++) {
			for(int k=Y1;k<=Y2;k++) {
				blocked[j][k]=1;
			}
		}
	}
	for(int i=0;i<szx;i++) {
		for(int j=0;j<szy;j++) {
			if (i==0||j==0||i+1==szx||j+1==szy) {
				dfs(i,j);
			}
		}
	}
	ll ans=0;
	for(int i=0;i<szx;i++) {
		for(int j=0;j<szy;j++) {
			if (used[i][j]) continue;
			ll tmp=1ll*x[i].second*y[j].second;
			ans+=tmp;
		}
	}
	cout<<ans<<endl;
	return false;
}
void main_init()
{
	__builtin_fprintf(stderr,"文件信息 :                   Messages of The File :\n日期 : %s           Date : %s\n运行时间 : %s          Operation Time :%s\n作者 : libra9z               author : libra9z\n",__DATE__,__DATE__,__TIME__,__TIME__);fprintf(stderr,"文件 : %s\n",__FILE__);
	#ifdef __FILE_JUDGE__
	freopen(string(string(__FILE__).substr(string(__FILE__).find_last_of('\\')+1,string(__FILE__).find_last_of('.')-string(__FILE__).find_last_of('\\'))+"in").c_str(),"r",stdin);
	freopen(string(string(__FILE__).substr(string(__FILE__).find_last_of('\\')+1,string(__FILE__).find_last_of('.')-string(__FILE__).find_last_of('\\'))+"out").c_str(),"w",stdout);
	#endif
}
signed main()
{
	main_init();
	int tests=single_test;if (!tests) __builtin_scanf("%d",&tests);
	else if (tests<0) tests=100000000;
	for (int test=1;test<=tests;++test) if (solve(test)) break;
	return 0;
}






















