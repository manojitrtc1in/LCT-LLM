#include<bits/stdc++.h>
#define REP(i,first,last) for(register int i=(first);i<=(last);++i)
#define DOW(i,first,last) for(register int i=(first);(last)<=i;--i)
#define LL long long
#define UI unsigned int
#define ULL unsigned long long
#define PII pair<int,int>
#define PIL pair<int,long long>
#define PLI pair<long long,int>
#define PLL pair<long long,long long>
#define MPR(a,b) make_pair(a,b)
#define CLEAN(a) memset(a,0,sizeof(a))
#define COVER(a,v) memset(a,v,sizeof(a))
#define SURVEILLANCE(type_name) IO::DeBugln("On line ",__LINE__," "#type_name"=",type_name)
#ifndef ONLINE_JUDGE
#define GAP IO::DeBugln("Gap on line ",__LINE__);fwrite(pbuf,1,pp-pbuf,stdout);IO::pp=IO::pbuf;fclose(stdout);freopen("data.out","w",stdout);
#define STOP IO::DeBugln("Stop on line ",__LINE__);fwrite(pbuf,1,pp-pbuf,stdout);fclose(stdout);exit(0);
#else
#define GAP
#define STOP
#endif
namespace IO
{
	int double_len(6);
	bool spacebar_can_see(1);
	const char NUMBER_TO_CHAR[36]={48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
	const int CHAR_TO_NUMBER[128]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0};
	template<class T>class Number
	{
	public:
		unsigned int len;
		int hex;
		T number;
		inline Number(const T number=0,const int hex=10,const int len=0):number(number),hex(hex),len(len)
		{

		}
		inline operator T()const
		{
			return number;
		}
		inline Number<T>& operator =(const T &a)
		{
			number=a;
			return *this;
		}
	};
	inline bool CanSee(const char ch)
	{
		return spacebar_can_see?(31<ch&&ch<127):(32<ch&&ch<127);
	}
	inline bool IsNumber(const char ch)
	{
		return (47<ch&&ch<58);
	}
	inline bool IsNumber_(const int hex,const char ch)
	{
		return (47<ch&&ch<48+hex)||(64<ch&&ch<55+hex)||(96<ch&&ch<87+hex);
	}
	const int IN_BUF=1<<23,OUT_BUF=1<<23;
	char buf[IN_BUF],*ps=buf,*pt=buf,pbuf[OUT_BUF],*pp=pbuf;
	inline char GetChar()
	{


		if(ps==pt)
		{
			ps=buf;
			pt=buf+fread(buf,1,IN_BUF,stdin);
		}
		return ps==pt?EOF:*ps++;
	}
	inline void PutChar(const char ch)
	{


		if(pp==pbuf+OUT_BUF)
		{
			fwrite(pbuf,1,OUT_BUF,stdout);
			pp=pbuf;
		}
		*pp++=ch;
	}
	char read_ch(10);
	template<class T>
	inline T ReadInt()
	{
		register T x(0);
		register bool f(1);
		while(!IsNumber(read_ch)&&(~read_ch))
		{
			if(read_ch==45)
			{
				f=0;
			}
			read_ch=GetChar();
		}
		while(IsNumber(read_ch)&&(~read_ch))
		{
			x=(x<<1)+(x<<3)+(read_ch^48);
			read_ch=GetChar();
		}
		return f?x:-x;
	}
	template<class T>
	inline T ReadUInt()
	{
		register T x(0);
		while(!IsNumber(read_ch)&&(~read_ch))
		{
			read_ch=GetChar();
		}
		while(IsNumber(read_ch)&&(~read_ch))
		{
			x=(x<<1)+(x<<3)+(read_ch^48);
			read_ch=GetChar();
		}
		return x;
	}
	template<class T>
	inline T ReadKInt(const int hex)
	{
		register T x(0);
		register bool f(1);
		while(!IsNumber_(hex,read_ch)&&(~read_ch))
		{
			if(read_ch==45)
			{
				f=0;
			}
			read_ch=GetChar();
		}
		while(IsNumber_(hex,read_ch)&&(~read_ch))
		{
			x=x*hex+CHAR_TO_NUMBER[read_ch];
			read_ch=GetChar();
		}
		return f?x:-x;
	}
	template<class T>
	inline T ReadUKInt(const int hex)
	{
		register T x(0);
		while(!IsNumber_(hex,read_ch)&&(~read_ch))
		{
			read_ch=GetChar();
		}
		while(IsNumber_(hex,read_ch)&&(~read_ch))
		{
			x=x*hex+CHAR_TO_NUMBER[read_ch];
			read_ch=GetChar();
		}
		return x;
	}
	inline double ReadDouble()
	{
		register long long int_num(ReadInt<long long>());
		if(read_ch==46)
		{
			register double pow10(1.0),result(0);
			read_ch=GetChar();
			while(IsNumber(read_ch)&&(~read_ch))
			{
				pow10/=10.0;
				result+=pow10*(read_ch^48);
				read_ch=GetChar();
			}
			return int_num+(int_num<0?-result:result);
		}
		else
		{
			return (double)int_num;
		}
	}
	inline void ReadT(int &x)
	{
		x=ReadInt<int>();
	}
	inline void ReadT(long long &x)
	{
		x=ReadInt<long long>();
	}
	inline void ReadT(bool &x)
	{
		x=ReadUInt<bool>();
	}
	inline void ReadT(unsigned int &x)
	{
		x=ReadUInt<unsigned int>();
	}
	inline void ReadT(unsigned long long &x)
	{
		x=ReadUInt<unsigned long long>();
	}
	inline void ReadT(double &x)
	{
		x=ReadDouble();
	}
	inline void ReadT(char &ch)
	{
		for(;!CanSee(read_ch)&&(~read_ch);read_ch=GetChar());
		ch=read_ch;
		read_ch=10;
	}
	inline void ReadT(Number<int> &x)
	{
		x.number=ReadKInt<int>(x.hex);
	}
	inline void ReadT(Number<long long> &x)
	{
		x.number=ReadKInt<long long>(x.hex);
	}
	inline void ReadT(Number<unsigned int> &x)
	{
		x.number=ReadUKInt<unsigned int>(x.hex);
	}
	inline void ReadT(Number<unsigned long long> &x)
	{
		x.number=ReadUKInt<unsigned long long>(x.hex);
	}
	inline void ReadT(char *s)
	{
		register int len(0);
		for(;!CanSee(read_ch)&&(~read_ch);read_ch=GetChar());
		for(;CanSee(read_ch)&&(~read_ch);read_ch=GetChar())
		{
			s[len++]=read_ch;
		}
		s[len]=0;
		read_ch=10;
	}
	template<class T>
	inline void Read(T &t)
	{
		ReadT(t);
	}
	template<class T,class ...Args>
	void Read(T &t,Args &...args)
	{
		ReadT(t);
		Read(args...);
	}
	template<class T>
	inline void WriteUInt(T x)
	{
		static char out_number[25];
		static int cnt;
		out_number[cnt=1]=x%10^48;
		while(x/=10)
		{
			out_number[++cnt]=x%10^48;
		}
		while(cnt)
		{
			PutChar(out_number[cnt--]);
		}
	}
	template<class T>
	inline void WriteInt(const T x)
	{
		if(x<0)
		{
			PutChar(45);
			WriteUInt(-x);
			return;
		}
		WriteUInt(x);
	}
	template<class T>
	inline void WriteUKInt(T x,const int hex,int len)
	{
		static char out_number[25];
		static int cnt;
		out_number[cnt=1]=NUMBER_TO_CHAR[x%hex];
		while(x/=hex)
		{
			out_number[++cnt]=NUMBER_TO_CHAR[x%hex];
		}
		len-=cnt;
		while(0<len--)
		{
			PutChar(48);
		}
		while(cnt)
		{
			PutChar(out_number[cnt--]);
		}
	}
	template<class T>
	inline void WriteKInt(const T x,const int hex,const int len)
	{
		if(x<0)
		{
			PutChar(45);
			WriteUKInt(-x,hex,len-1);
			return;
		}
		WriteUKInt(x,hex,len);
	}
	inline void WriteDouble(double x,int len)
	{
		if(x<0)
		{
			PutChar(45);
			x=-x;
		}
		WriteUInt<unsigned long long>((unsigned long long)x);
		if(len)
		{
			x-=(int)x;
			PutChar(46);
			while(len--)
			{
				x*=10;
				if(!(unsigned long long)x)
				{
					PutChar(48);
				}
			}
			if((unsigned long long)x)
			{
				WriteUInt<unsigned long long>((unsigned long long)x);
			}
		}
	}
	inline void WriteT(const int x)
	{
		WriteInt<int>(x);
	}
	inline void WriteT(const long long x)
	{
		WriteInt<long long>(x);
	}
	inline void WriteT(const bool x)
	{
		PutChar(x|48);
	}
	inline void WriteT(const unsigned int x)
	{
		WriteUInt<unsigned int>(x);
	}
	inline void WriteT(const unsigned long long x)
	{
		WriteUInt<unsigned long long>(x);
	}
	inline void WriteT(const double x)
	{
		WriteDouble(x,double_len);
	}
	inline void WriteT(const char *s)
	{
		while(*s)
		{
			PutChar(*s++);
		}
	}
	inline void WriteT(const char x)
	{
		PutChar(x);
	}
	inline void WriteT(const Number<int> x)
	{
		WriteKInt(x.number,x.hex,x.len);
	}
	inline void WriteT(const Number<long long> x)
	{
		WriteKInt(x.number,x.hex,x.len);
	}
	inline void WriteT(const Number<unsigned int> x)
	{
		WriteUKInt(x.number,x.hex,x.len);
	}
	inline void WriteT(const Number<unsigned long long> x)
	{
		WriteUKInt(x.number,x.hex,x.len);
	}
	template<class T>
	inline void Write(const T t)
	{
		WriteT(t);
	}
	template<class T,class ...Args>
	void Write(const T t,const Args ...args)
	{
		WriteT(t);
		Write(args...);
	}
	inline void Writeln()
	{
		PutChar(10);
	}
	template<class T>
	inline void Writeln(const T t)
	{
		WriteT(t);
		PutChar(10);
	}
	template<class ...Args>
	inline void Writeln(const Args ...args)
	{
		Write(args...);
		PutChar(10);
	}
	template<class ...Args>
	inline void WriteExit(const Args ...args)
	{
		Write(args...);
		PutChar(10);
		exit(0);
	}
	#ifndef ONLINE_JUDGE
		template<class ...Args>
		inline void DeBug(const Args ...args)
		{
			Write(args...);
		}
		template<class ...Args>
		inline void DeBugln(const Args ...args)
		{
			Writeln(args...);
		}
		inline void DeBugln()
		{
			Writeln();
		}
	#else
		template<class ...Args>
		inline void DeBug(const Args ...args)
		{

		}
		template<class ...Args>
		inline void DeBugln(const Args ...args)
		{

		}
		inline void DeBugln()
		{

		}
	#endif
	class CodeToDo
	{
	public:
		inline CodeToDo()
		{
			#ifndef ONLINE_JUDGE
				freopen("data.in","r",stdin);
				freopen("data.out","w",stdout);
			#endif
			srand(time(0));
		}
		inline ~CodeToDo()
		{
			double_len=3;
			DeBugln("\nTime=",(double)clock()/CLOCKS_PER_SEC,"s");
			fwrite(pbuf,1,pp-pbuf,stdout);
			#ifndef ONLINE_JUDGE
				fclose(stdin);
				fclose(stdout);
			#endif
		}
	}code_to_do;
}
using namespace IO;
using namespace std;
template<typename T>
inline T Max(const T a,const T b)
{
	return a<b?b:a;
}
template<typename T,typename ...Args>
T Max(const T a,const Args ...args)
{
	return Max(a,Max(args...));
}
template<typename T>
inline T Min(const T a,const T b)
{
	return a<b?a:b;
}
template<typename T,typename ...Args>
T Min(const T a,const Args ...args)
{
	return Min(a,Min(args...));
}
template<typename T>
inline void Swap(T &a,T &b)
{
	register T temp=a;
	a=b;
	b=temp;
}
const int MAXN=5e5+5;
namespace LCA
{
	struct Edge
	{
		int to,next;
	}edge[MAXN<<1];
	int edge_head[MAXN];
	int edge_cnt=0;
	#define FOR(now) for(int edge_i=edge_head[now];edge_i;edge_i=edge[edge_i].next)
	#define TO edge[edge_i].to
	inline void AddEdge(int from,int to)
	{
		edge[++edge_cnt].to=to;
		edge[edge_cnt].next=edge_head[from];
		edge_head[from]=edge_cnt;
	}
	void Swap(int &a,int &b)
	{
		a^=b^=a^=b;
	}
	int father[MAXN][21];
	int deep[MAXN];
	void DFS(int now)
	{
		REP(i,1,20)
		{
			father[now][i]=father[father[now][i-1]][i-1];
		}
		FOR(now)
		{
			if(TO^father[now][0])
			{
				deep[TO]=deep[now]+1;
				father[TO][0]=now;
				DFS(TO);
			}
		}
	}
	inline void Init(int n,int root)
	{
		memset(father,0,sizeof(father));
		deep[root]=1;
		DFS(root);
	}
	inline int Calc(int a,int b)
	{
		if(deep[a]<deep[b])
		{
			Swap(a,b);
		}
		DOW(i,20,0)
		{
			if(deep[b]<=deep[father[a][i]])
			{
				a=father[a][i];
			}
		}
		if(a==b)
		{
			return b;
		}
		DOW(i,20,0)
		{
			if(father[a][i]^father[b][i])
			{
				a=father[a][i];
				b=father[b][i];
			}
		}
		return father[a][0];
	}
	inline int Kth(int now,int deep)
	{
		DOW(i,20,0)
		{
			if((1<<i)<=deep)
			{
				now=father[now][i];
				deep-=1<<i;
			}
		}
		return now;
	}
	#undef FOR
	#undef TO
}
template<int MAXN,int MAXM>class Edge
{
public:
	inline void AddEdge(const int from,const int to)
	{
		edge[++edge_cnt].to=to;
		edge[edge_cnt].next=edge_head[from];
		edge_head[from]=edge_cnt;
	}
private:
	class Ref
	{
	private:
		int from;
		Edge *id;
	public:
		inline Ref(Edge* id,const int from):id(id),from(from)
		{

		}
		inline Ref& operator +=(const int to)
		{
			id->AddEdge(from,to);
			return *this;
		}
		inline Ref& operator +=(const Ref&to)
		{
			id->AddEdge(from,to.from);
			return *this;
		}
	};
public:
	class Link
	{
	public:
		int next,to;
	}edge[MAXM+1];
	int edge_head[MAXN+1];
	int edge_cnt=0;
	inline void operator()(const int from,const int to)
	{
		edge[++edge_cnt].to=to;
		edge[edge_cnt].next=edge_head[from];
		edge_head[from]=edge_cnt;
	}
	inline Ref operator [](const int from)
	{
		return Ref(this,from);
	}
	inline void Clean(const int n=MAXN,const int m=MAXM)
	{
		REP(i,1,n)
		{
			edge_head[i]=0;
		}
		edge_cnt=0;
	}
	#define FOR(now_edge,now) for(register int edge_##now_edge##_i=now_edge.edge_head[now];edge_##now_edge##_i;edge_##now_edge##_i=now_edge.edge[edge_##now_edge##_i].next)
	#define TO(now_edge) now_edge.edge[edge_##now_edge##_i].to
};
int n,m;
Edge<MAXN,MAXN<<1>e;
inline LL Calc(const LL x)
{
	return x*(x-1)/2;
}
LL f1[MAXN];
LL f2[MAXN];
LL f3[MAXN];
void DFS(const int now,const int father)
{
	FOR(e,now)
	{
		if(TO(e)^father)
		{
			DFS(TO(e),now);
			f1[now]+=f1[TO(e)];
			f2[now]+=f2[TO(e)];
			f3[now]+=f3[TO(e)];
		}
	}
}
vector<PII>q[MAXN];
int main()
{
	Read(n);
	int u,v;
	REP(i,1,n-1)
	{
		Read(u,v);
		e[u]+=e[v]+=u;
		LCA::AddEdge(u,v);
		LCA::AddEdge(v,u);
	}
	LCA::Init(n,1);
	Read(m);
	REP(i,1,m)
	{
		Read(u,v);
		int lca=LCA::Calc(u,v);
		int flca=LCA::father[lca][0];
		int du=LCA::deep[u];
		int dv=LCA::deep[v];
		int dlca=LCA::deep[lca];
		++f1[u];
		++f1[v];
		--f1[lca];
		--f1[flca];
		++f2[u];
		++f2[v];
		f2[lca]-=2;
		if(dlca+2<=du)
		{
			++f3[u];
			--f3[u=LCA::Kth(u,du-dlca-1)];
		}
		if(dlca+2<=dv)
		{
			++f3[v];
			--f3[v=LCA::Kth(v,dv-dlca-1)];
		}
		du=LCA::deep[u];
		dv=LCA::deep[v];
		if(dlca<Min(du,dv))
		{
			if(u<v)
			{
				Swap(u,v);
			}
			q[lca].push_back(MPR(u,v));
		}
	}
	DFS(1,0);
	LL answer(0);
	REP(i,1,n)
	{
		answer+=Calc(f1[i])-Calc(f2[i]);
		FOR(e,i)
		{
			if(TO(e)^LCA::father[i][0])
			{
				answer+=Calc(f3[TO(e)])-Calc(f2[TO(e)]);
			}
		}
		if(q[i].size())
		{
			sort(q[i].begin(),q[i].end());
			int cnt=1;
			REP(j,1,q[i].size()-1)
			{
				if(q[i][j-1]==q[i][j])
				{
					++cnt;
				}
				else
				{
					answer+=Calc(cnt);
					cnt=1;
				}
			}
			answer+=Calc(cnt);
		}
	}
	Writeln(answer);
	return 0;
}