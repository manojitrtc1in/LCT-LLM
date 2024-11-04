
using namespace std;



using namespace __gnu_cxx;
struct str_hash{
	size_t operator()(const string& str) const
	{ return __stl_hash_string(str.c_str()); }};

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
	inline bool read(int &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return false;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (sign)x=-x;
		return true;
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
        
            puts("error:can't recognize the system!");
        

	}
	inline void println2(ll x){print2(x);printf("\n");}
	inline void println2(){printf("\n");}



};
using namespace fastIO;

int i,i0,n,m,q,ans,mp[305][305],pre[305*305],v[2000005],mp0[305][305],cnt[305*305];
struct node
{
	int x,y,z,pre;
}a[2000005];
int fin(int x){return (pre[x]==x)?x:pre[x]=fin(pre[x]);}
void uni(int x,int y){if(fin(x)!=fin(y))pre[fin(y)]=fin(x);}
int has(int x,int y)
{
	return (x-1)*m+y;
}
void init()
{
	for(int i=1;i<=n*m;i++)pre[i]=i;
	for(int i=1;i<=n;i++)for(int i0=1;i0<=m;i0++)mp[i][i0]=0;
}
bool chk(int x,int y,int d)
{
    if(x<1||x>n)return 0;
    if(y<1||y>m)return 0;
    if(mp[x][y]!=d)return 0;
    return 1;
}
int main()
{
	read(n),read(m),read(q);
	for(int i=1;i<=q;i++)
	{
		read(a[i].x),read(a[i].y),read(a[i].z);
		a[i].pre=mp[a[i].x][a[i].y];
		mp[a[i].x][a[i].y]=a[i].z;
	}
	for(int i=1;i<=q;i++)
	{
		int l=i,r=i;
		while(r<=q&&a[r+1].z==a[r].z)r++;
		init();
		int tmp=0;
		for(int i0=l;i0<=r;i0++)
		{
			if(a[i0].z==a[i0].pre)
			{
				v[i0]+=tmp;
				continue;
			}
			int x=a[i0].x,y=a[i0].y,z=a[i0].z;
			mp[x][y]=z;
			int sz=0;
			if(chk(x+1,y,z))sz+=(cnt[fin(has(x+1,y))]==0),cnt[fin(has(x+1,y))]++;
			if(chk(x-1,y,z))sz+=(cnt[fin(has(x-1,y))]==0),cnt[fin(has(x-1,y))]++;
			if(chk(x,y-1,z))sz+=(cnt[fin(has(x,y-1))]==0),cnt[fin(has(x,y-1))]++;
			if(chk(x,y+1,z))sz+=(cnt[fin(has(x,y+1))]==0),cnt[fin(has(x,y+1))]++;
			if(chk(x+1,y,z))cnt[fin(has(x+1,y))]--;
			if(chk(x-1,y,z))cnt[fin(has(x-1,y))]--;
			if(chk(x,y-1,z))cnt[fin(has(x,y-1))]--;
			if(chk(x,y+1,z))cnt[fin(has(x,y+1))]--;
			if(chk(x+1,y,z))uni(has(x,y),fin(has(x+1,y)));
			if(chk(x-1,y,z))uni(has(x,y),fin(has(x-1,y)));
			if(chk(x,y-1,z))uni(has(x,y),fin(has(x,y-1)));
			if(chk(x,y+1,z))uni(has(x,y),fin(has(x,y+1)));
			tmp+=1-sz;
			v[i0]+=tmp;
			mp0[x][y]=z;
		}
		init();
		for(int i0=1;i0<=n;i0++)
		{
			for(int i1=1;i1<=m;i1++)
			{
				if(i0+1<=n&&mp0[i0][i1]==mp0[i0+1][i1])
				{
					uni(has(i0,i1),has(i0+1,i1));
				}
				if(i1+1<=m&&mp0[i0][i1]==mp0[i0][i1+1])
				{
					uni(has(i0,i1),has(i0,i1+1));
				}
			}
		}
		int sz=0;
		for(int i0=1;i0<=n;i0++)
		{
			for(int i1=1;i1<=m;i1++)
			{
				if(mp0[i0][i1]!=a[l].z)sz+=(cnt[fin(has(i0,i1))]==0),cnt[fin(has(i0,i1))]++;
				else pre[has(i0,i1)]=has(i0,i1);
			}
		}
		for(int i0=1;i0<=n;i0++)
		{
			for(int i1=1;i1<=m;i1++)
			{
				if(mp0[i0][i1]!=a[l].z)cnt[fin(has(i0,i1))]--;
			}
		}
		tmp=sz;
		for(int i0=1;i0<=n;i0++)for(int i1=1;i1<=m;i1++)mp[i0][i1]=mp0[i0][i1];
		for(int i0=r;i0>=l;i0--)
		{
			if(a[i0].z==a[i0].pre)
			{
				v[i0]+=tmp;
				continue;
			}
			int x=a[i0].x,y=a[i0].y,z=a[i0].pre;
			mp[x][y]=z;
			int sz=0;
			if(chk(x+1,y,z))sz+=(cnt[fin(has(x+1,y))]==0),cnt[fin(has(x+1,y))]++;
			if(chk(x-1,y,z))sz+=(cnt[fin(has(x-1,y))]==0),cnt[fin(has(x-1,y))]++;
			if(chk(x,y-1,z))sz+=(cnt[fin(has(x,y-1))]==0),cnt[fin(has(x,y-1))]++;
			if(chk(x,y+1,z))sz+=(cnt[fin(has(x,y+1))]==0),cnt[fin(has(x,y+1))]++;
			if(chk(x+1,y,z))cnt[fin(has(x+1,y))]--;
			if(chk(x-1,y,z))cnt[fin(has(x-1,y))]--;
			if(chk(x,y-1,z))cnt[fin(has(x,y-1))]--;
			if(chk(x,y+1,z))cnt[fin(has(x,y+1))]--;
			if(chk(x+1,y,z))uni(has(x,y),fin(has(x+1,y)));
			if(chk(x-1,y,z))uni(has(x,y),fin(has(x-1,y)));
			if(chk(x,y-1,z))uni(has(x,y),fin(has(x,y-1)));
			if(chk(x,y+1,z))uni(has(x,y),fin(has(x,y+1)));
			v[i0]+=tmp;
			tmp-=sz-1;
		}
		i=r;
	}
	for(int i=1;i<=q;i++)printf("%d\n",v[i]);
    return 0;
}                                                                                                                                                                                                                                                                                                                                                     