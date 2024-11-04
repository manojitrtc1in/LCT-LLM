#include<bits/stdc++.h>
using namespace std;
const int MAXN=100015;
int stk[MAXN],top;
struct tree
{
	int fa,ch[2],rev;
	int val;
	int arr[22];
	int ans[22];
	int ansnum;
	int num;
}t[MAXN];
void init(int n)
{
	memset(t,0,sizeof(tree)*(n+10));
}
void pushdown(int root)
{
	if(t[root].rev)
	{
		t[root].rev=0;
		swap(t[root].ch[0],t[root].ch[1]);
		t[t[root].ch[0]].rev^=1;
		t[t[root].ch[1]].rev^=1;
	}
	return;
}

int join(int *a,int *b,int na,int nb)
{
	int maxTo=min(na+nb,11);
	int ia=0;
	int ib=0;
	int temp[22];
	for(int i=0;i<maxTo;i++)
	{
		if(ia < na && ib < nb)
		{
			if(a[ia]<b[ib])
			{
				temp[i]=a[ia];
				ia++;
			}
			else
			{
				temp[i]=b[ib];
				ib++;
			}
		}
		else if(ia<na)
		{
			temp[i]=a[ia];
			ia++;
		}
		else
		{
			temp[i]=b[ib];
			ib++;
		}
	}
	for(int i=0;i<maxTo;i++)
	{
		a[i]=temp[i];
	}
	return maxTo;
}

void update(int root)
{
	t[root].ansnum=t[root].num;
	memcpy(t[root].ans,t[root].arr,sizeof(t[root].arr));

	
	if(t[root].ch[0])
	{
		

		pushdown(t[root].ch[0]);
		t[root].ansnum=join(t[root].ans,t[t[root].ch[0]].ans,t[root].ansnum,t[t[root].ch[0]].ansnum);
	}
	if(t[root].ch[1])
	{
		

		pushdown(t[root].ch[1]);
		t[root].ansnum=join(t[root].ans,t[t[root].ch[1]].ans,t[root].ansnum,t[t[root].ch[1]].ansnum);
	}

	
	return;
}


bool isroot(int root)
{
	return t[t[root].fa].ch[0]!=root&&t[t[root].fa].ch[1]!=root;
}
void rot(int root)
{
	int fa=t[root].fa;
	int gfa=t[fa].fa;
	int t1=(root!=t[fa].ch[0]);
	int t2=(fa!=t[gfa].ch[0]);
	int ch=t[root].ch[1^t1];
	if(!isroot(fa))t[gfa].ch[0^t2]=root;
	t[ch].fa=fa;
	t[root].fa=gfa;
	t[root].ch[1^t1]=fa;
	t[fa].fa=root;
	t[fa].ch[0^t1]=ch;
	update(fa);
	return;
}


#include<bits/stdc++.h>
using namespace std;
namespace fastIO{
#define BUF_SIZE 100000
#define OUT_SIZE 100000
#define ll long long
	

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
#ifdef _WIN32
		scanf("%I64d",&x);
#else
		#ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
#endif
	}
	inline void read2(double &x){scanf("%lf",&x);}
	inline void read2(char *s){scanf("%s",s);}
	inline void read2(char &c){scanf(" %c",&c);}
	inline void readln2(char *s){gets(s);}
	

	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
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
		~Ostream_fwrite(){flush();}
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
#ifdef _WIN32
		printf("%I64d",x);
#else
		#ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
#endif
	}
	inline void println2(ll x){print2(x);printf("\n");}
	inline void println2(){printf("\n");}
#undef ll
#undef OUT_SIZE
#undef BUF_SIZE
};
using namespace fastIO;


#include<bits/stdc++.h>
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
#include <ext/hash_set>
using namespace __gnu_cxx;
struct str_hash{
	size_t operator()(const string& str) const
	{ return __stl_hash_string(str.c_str()); }};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>

using namespace __gnu_pbds;


void splay(int root)
{
	stk[++top]=root;
	for(int i=root; !isroot(i); i=t[i].fa)
	{
		stk[++top]=t[i].fa;
	}
	while(top)
	{
		pushdown(stk[top--]);
	}
	while(!isroot(root))
	{
		int fa=t[root].fa;
		int gfa=t[fa].fa;
		if(!isroot(fa))
			root==t[fa].ch[0]^fa==t[gfa].ch[0]?rot(root):rot(fa);
		rot(root);
	}
	update(root);
	return;
}
int access(int root)
{
	int temp=0;
	while(root)
	{
		splay(root);
		t[root].ch[1]=temp;
		temp=root;
		root=t[root].fa;
	}
	return temp;
}
void makeroot(int root)
{
	access(root);
	splay(root);
	t[root].rev^=1;
}
void link(int root1,int root2)
{
	makeroot(root1);
	t[root1].fa=root2;
}
void cut(int root1,int root2)
{
	makeroot(root1);
	access(root2);
	splay(root2);
	t[root2].ch[0]=t[root1].fa=0;
}
int lca(int root1,int root2,int root=0)
{
	if(root)makeroot(root);
	access(root1);
	return access(root2);
}
int findroot(int root)
{
	access(root);
	splay(root);
	int temp=root;
	while(t[temp].ch[0])temp=t[temp].ch[0];
	return temp;
}
vector<pair<int,int> >v;

int main()
{
	
	int n,m,q;
	while(read(n))
	{
		read(m);
		read(q);
		

		v.clear();
		for(int i=0; i<n-1; i++)
		{
			int l, r;
			read(l);
			read(r);
			v.push_back(make_pair(l, r));
		}
		for(int i=1; i<=m; i++)
		{
			int pos;
			read(pos);
			if(t[pos].num<11)
			{
				t[pos].arr[t[pos].num]=i;
				t[pos].num++;
			}
		}
		for(int i=0; i<n-1; i++)
		{
			link(v[i].first, v[i].second);
		}
		while(q--)
		{
			int x, y, v;
			read(x); read(y); read(v);
			makeroot(x);
			access(y);
			splay(y);
			

			

			printf("%d", min(t[y].ansnum, v));
			

			for(int i=0; i<min(t[y].ansnum, v); i++)
			{
				printf(" %d", t[y].ans[i]);
			}
			putchar('\n');
			

		}
	}
	return 0;
}
