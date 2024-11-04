


























using namespace std;




























const int inf=~0U>>1;
const long long linf=(long long)1e18;
const double eps=1e-6;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef vector<int>::iterator eit;
typedef pair<int,int> pi;
typedef pair<int,pair<int,int> > tri;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef set<int>::iterator sit;
typedef map<int,int> mii;
typedef map<int,int>::iterator mit;
typedef istringstream ISS;
typedef ostringstream OSS;
template<class T> string tostr(T a){
	OSS out;out<<a;return out.str();
}
struct debugger{
	template<typename T> debugger& operator ,(const T &x)
	{
		cerr<<x<<endl;
		return *this;
	}
}dbg;
namespace fastIO{
	
	
	
	

	bool IOerror=0;
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if (p1==pend){
			p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if (pend==p1){IOerror=1;return -1;}
			

		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	inline void read(int &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (sign)x=-x;
	}
	inline void read(ll &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (sign)x=-x;
	}
	inline void read(double &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (ch=='.'){
			double tmp=1; ch=nc();
			for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if (sign)x=-x;
	}
	inline void read(char *s){
		char ch=nc();
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
	}
	inline void read(char &c){
		for (c=nc();blank(c);c=nc());
		if (IOerror){c=-1;return;}
	}
	

	inline void read1(int &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (bo)x=-x;
	}
	inline void read1(ll &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (bo)x=-x;
	}
	inline void read1(double &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (ch=='.'){
			double tmp=1;
			for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
		}
		if (bo)x=-x;
	}
	inline void read1(char *s){
		char ch=getchar();
		for (;blank(ch);ch=getchar());
		for (;!blank(ch);ch=getchar())*s++=ch;
		*s=0;
	}
	inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
	

	inline void read2(int &x){scanf("%d",&x);}
	inline void read2(ll &x){
		
			scanf("%I64d",&x);
		
		
			scanf("%lld",&x);
		
			puts("error:can't recognize the system!");
		
		
	}
	inline void read2(double &x){scanf("%lf",&x);}
	inline void read2(char *s){scanf("%s",s);}
	inline void read2(char &c){scanf(" %c",&c);}
	inline void id1(char *s){gets(s);}
	

	struct id0{
		char *buf,*p1,*pend;
		id0(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
		void out(char ch){
			if (p1==pend){
				fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
			}
			*p1++=ch;
		}
		void print(int x){
			static char s[15],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void println(int x){
			static char s[15],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1); out('\n');
		}
		void print(ll x){
			static char s[25],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void println(ll x){
			static char s[25],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1); out('\n');
		}
		void print(double x,int y){
			static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
			if (x<-1e-7)out('-'),x=-x;x*=mul[y];
			ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; ll x2=x1/mul[y];
			print(x2);if (y>0){out('.');print(x1-x2*mul[y]);}
		}
		void println(double x,int y){print(x,y);out('\n');}
		void print(char *s){while (*s)out(*s++);}
		void println(char *s){while (*s)out(*s++);out('\n');}
		void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~id0(){flush();}
	}Ostream;
	inline void print(int x){Ostream.print(x);}
	inline void println(int x){Ostream.println(x);}
	inline void print(char x){Ostream.out(x);}
	inline void println(char x){Ostream.out(x);Ostream.out('\n');}
	inline void print(ll x){Ostream.print(x);}
	inline void println(ll x){Ostream.println(x);}
	inline void print(double x,int y){Ostream.print(x,y);}
	inline void println(double x,int y){Ostream.println(x,y);}
	inline void print(char *s){Ostream.print(s);}
	inline void println(char *s){Ostream.println(s);}
	inline void println(){Ostream.out('\n');}
	inline void flush(){Ostream.flush();}
	

	char Out[OUT_SIZE],*o=Out;
	inline void print1(int x){
		static char buf[15];
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
		while(x)*p1++=x%10+'0',x/=10;
		while(p1--!=buf)*o++=*p1;
	}
	inline void println1(int x){print1(x);*o++='\n';}
	inline void print1(ll x){
		static char buf[25];
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
		while(x)*p1++=x%10+'0',x/=10;
		while(p1--!=buf)*o++=*p1;
	}
	inline void println1(ll x){print1(x);*o++='\n';}
	inline void print1(char c){*o++=c;}
	inline void println1(char c){*o++=c;*o++='\n';}
	inline void print1(char *s){while (*s)*o++=*s++; }
	inline void println1(char *s){print(s);*o++='\n';}
	inline void println1(){*o++='\n';}
	inline void flush1(){if (o!=Out&&*(o-1)=='\n')*--o=0;puts(Out);}
	struct puts_write{
		~puts_write(){flush1();}
	};
	inline void print2(int x){printf("%d",x);}
	inline void println2(int x){printf("%d\n",x);}
	inline void print2(char x){printf("%c",x);}
	inline void println2(char x){printf("%c\n",x);}
	inline void print2(ll x){
		
			printf("%I64d",x);
		
		
			printf("%lld",x);
		
			puts("error:can't recognize the system!");
		
		
	}
	inline void println2(ll x){print2(x);printf("\n");}
	inline void println2(){printf("\n");}
	
	
	
};
using namespace fastIO;
string name="", in=".in", out=".out";

const double ZERO = 1e-12;
inline double getabs(double x)
{
    return (x >= 0) ? x : -x;
}
inline double det(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}
inline bool line(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return getabs(det(x1 - x2, y1 - y2, x2 - x3, y2 - y3)) < ZERO;
}
inline bool check(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a1 = y1 - y2, b1 = y2 - y3, c1 = 2 * x2 - (x1 + 2 * x2 + x3) / 2;
    double a2 = x2 - x1, b2 = x3 - x2, c2 = 2 * y2 - (y1 + 2 * y2 + y3) / 2;
    double u = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    double px2 = (x1 + x2) / 2 + u * (y1 - y2), py2 = (y1 + y2) / 2 + u * (x2 - x1);
    double px1 = 2 * x1 - px2, py1 = 2 * y1 - py2;
    double px3 = 2 * x2 - px2, py3 = 2 * y2 - py2;
    double px4 = 2 * x3 - px3, py4 = 2 * y3 - py3;
    if (line(px1, py1, px2, py2, px3, py3)) return false;
    if (line(px1, py1, px2, py2, px4, py4)) return false;
    if (line(px1, py1, px3, py3, px4, py4)) return false;
    if (line(px2, py2, px3, py3, px4, py4)) return false;
    bool p1 = det(px2 - px1, py2 - py1, px3 - px2, py3 - py2) > 0;
    bool p2 = det(px3 - px2, py3 - py2, px4 - px3, py4 - py3) > 0;
    bool p3 = det(px4 - px3, py4 - py3, px1 - px4, py1 - py4) > 0;
    bool p4 = det(px1 - px4, py1 - py4, px2 - px1, py2 - py1) > 0;
    if (p1 == p2 && p2 == p3 && p3 == p4)
    {
        puts("YES");
        printf("%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n", px1, py1, px2, py2, px3, py3, px4, py4);
        return true;
    }
    return false;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
    int T;scanf("%d",&T);
    while (T--)
    {
        double x1, y1, x2, y2, x3, y3;
        read(x1),read(y1),read(x2),read(y2),read(x3),read(y3);
        if (line(x1, y1, x2, y2, x3, y3))
        {
            puts("NO\n");
            continue;
        }
        if (check(x1, y1, x2, y2, x3, y3)||check(x1, y1, x3, y3, x2, y2)||check(x2, y2, x1, y1, x3, y3)||
	        check(x2, y2, x3, y3, x1, y1)||check(x3, y3, x1, y1, x2, y2)||check(x3, y3, x2, y2, x1, y1));
        else puts("NO\n");
    }
    //system("pause");
    return 0;
}

