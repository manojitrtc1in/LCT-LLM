















































using namespace std;
const double PI=acos(-1);
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
        
            puts("error:can‘t recognize the system!");
        
        
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
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
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
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        
            printf("%I64d",x);
        
        
            printf("%lld",x);
        
            puts("error:can‘t recognize the system!");
        
        
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    
    
    
};
using namespace fastIO;

const int N=5e5+10;
int n,m,k,x,sum[N],top,ha=206158430209,rev[N],w[N];
long double eps=1e-6;
vector<int> poly[200010];
priority_queue<pair<int,int> >q;

inline int add(int x){return x>=ha?x-ha:x;}
inline int sub(int x){return x<0?x+ha:x;}

inline int Mul(int a,int b){return sub(a*b-(int)((long double)a/ha*b+eps)*ha);}
inline int qpow(int a,int b)
{
	int ans=1;
	while(b){if(b&1)ans=Mul(ans,a);a=Mul(a,a);b>>=1;}
	return ans;
}
inline void getrev(int x)
{
	for(int i=0;i<(1<<x);i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(x-1));
}

namespace DU {
  int rev[N];

  struct Comp {
    double x, y;
    inline Comp operator + (const Comp &a) {
      return (Comp) { x + a.x, y + a.y };
    }
    inline Comp operator - (const Comp &a) {
      return (Comp) { x - a.x, y - a.y };
    }
    inline Comp operator * (const Comp &a) {
      return (Comp) { x * a.x - y * a.y, x * a.y + y * a.x };
    }
  } A[N];

  void Fft(Comp *a, int le, int ty) {
    for (int i = 0; i < le; ++i)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 1; i < le; i <<= 1) {
      Comp wn = (Comp) { cos(PI / i), ty * sin(PI / i) };
      for (int j = 0; j < le; j += i << 1) {
        Comp w = (Comp) { 1, 0 }, x, y;
        for (int k = 0; k < i; ++k, w = w * wn) {
          x = a[j + k]; y = a[j + i + k] * w;
          a[j + k] = x + y; a[j + i + k] = x - y;
        }
      }
    }
  }
  void Multiply(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n = (int)a.size(), m = (int)b.size();
    c.resize(n + m - 1);
    static int L;
    for (L = 1; L < n + m - 1; L <<= 1);
    for (int i = 0; i < L; ++i)
      rev[i] = (rev[i >> 1] >> 1) | (i & 1? L >> 1 : 0);
    for (int i = 0; i < L; ++i) A[i] = (Comp) { 0, 0 };
    for (int i = 0; i < n; ++i) A[i].x = (int)a[i];
    for (int i = 0; i < m; ++i) A[i].y = (int)b[i];
    Fft(A, L, 1);
    for (int i = 0; i < L; ++i) A[i] = A[i] * A[i];
    Fft(A, L, -1);
    for (int i = 0; i < n + m - 1; ++i) c[i] = (int)(A[i].y / L / 2 + 0.3)%1009;
  }
}


inline void fft(vector<int> &a,int len,int x)
{
	if(x)reverse(++a.begin(),a.end());
	for(int i=0;i<len;i++)if(rev[i]>i)swap(a[i],a[rev[i]]);
	for(int i=1;i<len;i<<=1)
	{
		w[0]=1,w[1]=qpow(22,(ha-1)/(i<<1));
		for(int j=2;j<i;j++)w[j]=Mul(w[j-1],w[1]);
		for(int j=0;j<len;j+=(i<<1))
			for(int k=j;k<i+j;k++)
			{
				int x=a[k],y=Mul(a[k+i],w[k-j]);
				a[k]=add(x+y),a[k+i]=sub(x-y);
			}
	}
	if(x){int inv=qpow(len,ha-2);for(int i=0;i<len;i++)a[i]=Mul(a[i],inv);}
}
inline vector<int> operator *(vector<int> &a,vector<int> &b)
{
	int len=1,bit=0,la=a.size(),lb=b.size();
	for(;len<la+lb;len<<=1,bit++);getrev(bit);
	for(int i=la;i<len;i++)a.push_back(0);
	for(int i=lb;i<len;i++)b.push_back(0);
	fft(a,len,0);fft(b,len,0);
	for(int i=0;i<len;i++)a[i]=Mul(a[i],b[i]);
	fft(a,len,1);for(int i=0;i<len;i++)a[i]%=1009;
	if(a.size()>k+1)a.resize(k+1);
	return a;
}
signed main()
{
	read(n),read(m),read(k);
	for(int i=0;i<n;i++)read(x),sum[x]++;
	sort(sum+1,sum+1+m);
	reverse(sum+1,sum+1+m);
	for(int i=1;i<=m;i++)
	if(sum[i])
	{
		top++;q.push(make_pair(-(sum[i]+1),top));
		for(int j=0;j<=sum[i];j++)poly[top].push_back(1);
		
	}
	while(q.size()>1)
	{
		pair<int,int> tmp1,tmp2;
		tmp1=q.top(),q.pop();
		tmp2=q.top(),q.pop();
		DU::Multiply(poly[tmp1.second],poly[tmp2.second],poly[tmp1.second]);
		q.push(make_pair(-((int)poly[tmp1.second].size()),tmp1.second));
	}
	if(poly[q.top().second].size()>k)printf("%lld",poly[q.top().second][k]%1009);else puts("0");
	return 0;
}