






































using namespace std;

































	

	







	rep(i,n){ \
        rep(j,m)cout<<A[i][j]<<" "; \
		cout<<endl; \
	} \
}






const int inf=~0U>>1;
const int MOD=1000000007;
const long long linf=(long long)1e18;
const double eps=1e-6,PI=atan(1.0)*4;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double DB;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<int,bool> PIB;
typedef pair<int,pair<int,int> > tri;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef vector<int>::iterator vit;
typedef set<int> SI;
typedef set<string> SS;
typedef set<ll> SL;
typedef set<double> SD;
typedef set<PII> SII;
typedef set<int>::iterator sit;
typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef map<ll,int> MLI;
typedef map<double,int> MDI;
typedef map<int,bool> MIB;
typedef map<string,bool> MSB;
typedef map<ll,bool> MLB;
typedef map<double,bool> MDB;
typedef map<int,int>::iterator mit;
typedef map<PII,int> MPIII;
typedef map<PII,bool> MPIIB;
typedef istringstream ISS;
typedef ostringstream OSS;
template<class T> string tostr(const T &x){
	OSS out;out<<x;return out.str();
}
struct debugger{
	template<typename T>
	debugger& operator ,(const T &x){
		cerr<<x<<endl;
		return *this;
	}
}dbg;
template<class T> inline void CLR(priority_queue<T,vector<T>,less<T> > &Q){
	while (!Q.empty())Q.pop();
}
template<class T> inline void CLR(priority_queue<T,vector<T>,greater<T> > &Q){
	while (!Q.empty())Q.pop();
}
template<class T> inline void CLR(T &A){A.clear();}
template<class T> inline void SRT(T &A){sort(all(A));}
void showVi(const vector<int> &A){
	for (vector<int>::const_iterator i=A.begin();i!=A.end();++i)cout<<*i<<" ";cout<<endl;
}
void showArray(int *A,int n){
	for (int i=1;i<=n;++i)cout<<A[i]<<" ";cout<<endl;
}
int **id6(int n,int m){
	int **p=new int*[n],*a=new int[n*m];
	for (int i=0;i<n;++i)p[i]=a+m*i;
	return p;
}
template <class T> T Min(const T &a,const T &b){return a<b?a:b;}
template <class T> T Max(const T &a,const T &b){return a>b?a:b;}
inline int max_fast(int x,int y){int m=(x-y)>>31;return y&m|x&~m;}
inline int min_fast(int x,int y){int m=(y-x)>>31;return y&m|x&~m;}
template<class T> inline void checkMin(T &a,const T b){if (b<a)a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a)a=b;}
template<class T,class C> inline void checkMin(T &a,const T b,C c){if (c(b,a))a=b;}
template<class T,class C> inline void checkMax(T &a,const T b,C c){if (c(a,b))a=b;}
template<class T> inline T Min(const T &a,const T &b,const T &c){return min(min(a,b),c);}
template<class T> inline T Max(const T &a,const T &b,const T &c){return max(max(a,b),c);}
template<class T> inline T Min(const T &a,const T &b,const T &c,const T &d){return min(min(a,b),min(c,d));}
template<class T> inline T Max(const T &a,const T &b,const T &c,const T &d){return max(max(a,b),max(c,d));}
template<class T> inline T sqr(const T &a){return a*a;}
template<class T> inline T cub(const T &a){return a*a*a;}
inline int Ceil(int x,int y){return (x-1)/y+1;}
inline bool _1(int x,int i){return x&1<<i;}
inline bool _1(ll x,int i){return x&1LL<<i;}
inline ll _1(int i){return 1LL<<i;}
template<class T> inline T low_bit(T x){return x&-x;}
template<class T> inline T high_bit(T x){
	T p=low_bit(x); while (p!=x)x-=p,p=low_bit(x); return p;
}
template<class T> inline T cover_bit(T x){
	T p=1; while (p<x)p<<=1;return p;
}
inline int count_bits(int x){
	x=(x&0x55555555)+((x&0xaaaaaaaa)>>1);
	x=(x&0x33333333)+((x&0xcccccccc)>>2);
	x=(x&0x0f0f0f0f)+((x&0xf0f0f0f0)>>4);
	x=(x&0x00ff00ff)+((x&0xff00ff00)>>8);
	x=(x&0x0000ffff)+((x&0xffff0000)>>16);
	return x;
}
inline int count_bits(ll x){
	x=(x&0x5555555555555555LL)+((x&0xaaaaaaaaaaaaaaaaLL)>>1);
	x=(x&0x3333333333333333LL)+((x&0xccccccccccccccccLL)>>2);
	x=(x&0x0f0f0f0f0f0f0f0fLL)+((x&0xf0f0f0f0f0f0f0f0LL)>>4);
	x=(x&0x00ff00ff00ff00ffLL)+((x&0xff00ff00ff00ff00LL)>>8);
	x=(x&0x0000ffff0000ffffLL)+((x&0xffff0000ffff0000LL)>>16);
	x=(x&0x00000000ffffffffLL)+((x&0xffffffff00000000LL)>>32);
	return x;
}
int reverse_bits(int x){
	x=((x>>1)&0x55555555)|((x<<1)&0xaaaaaaaa);
	x=((x>>2)&0x33333333)|((x<<2)&0xcccccccc);
	x=((x>>4)&0x0f0f0f0f)|((x<<4)&0xf0f0f0f0);
	x=((x>>8)&0x00ff00ff)|((x<<8)&0xff00ff00);
	x=((x>>16)&0x0000ffff)|((x<<16)&0xffff0000);
	return x;
}
ll reverse_bits(ll x){
	x=((x>>1)&0x5555555555555555LL)|((x<<1)&0xaaaaaaaaaaaaaaaaLL);
	x=((x>>2)&0x3333333333333333LL)|((x<<2)&0xccccccccccccccccLL);
	x=((x>>4)&0x0f0f0f0f0f0f0f0fLL)|((x<<4)&0xf0f0f0f0f0f0f0f0LL);
	x=((x>>8)&0x00ff00ff00ff00ffLL)|((x<<8)&0xff00ff00ff00ff00LL);
	x=((x>>16)&0x0000ffff0000ffffLL)|((x<<16)&0xffff0000ffff0000LL);
	x=((x>>32)&0x00000000ffffffffLL)|((x<<32)&0xffffffff00000000LL);
	return x;
}
ll C(int n,int m){
	if (n>m)return 0;
	ll res=1;
	for (int i=1;i<=n;++i)res=res*(m-i+1)/i;
	return res;
}
inline void INC(int &a,int b){a+=b;if (a>=MOD)a-=MOD;}
inline int SUM(int a,int b){a+=b;if (a>=MOD)a-=MOD;return a;}
inline void DEC(int &a,int b){a-=b;if (a<0)a+=MOD;}
inline int DFF(int a,int b){a-=b;if (a<0)a+=MOD;return a;}
inline void MUL(int &a,int b){a=(ll)a*b%MOD;}
inline int SUM(int a,int b,int c){return SUM(SUM(a,b),c);}
inline int SUM(int a,int b,int c,int d){return SUM(SUM(a,b),SUM(c,d));}
inline int pow(int x,int y){
	int res=1;
	for (;y;y>>=1){
		if (y&1)MUL(res,x);MUL(x,x);
	}
	return res;
}
inline ll mul32(ll x,ll y){
	ll res=0;x%=MOD;y%=MOD;
	while (y){if (y&1)res+=x;x=(x<<1)%MOD;y>>=1;}
	return res;
}
template<class T> inline T gcd(T x,T y){return !y?x:gcd(y,x%y);}
template<class T> inline T lcm(T x,T y){return x*(y/gcd(x,y));}
template<class T> inline T id1(T a,T b,T &x,T &y){
	if (!b){x=1;y=0;return a;}
	T res=id1(b,a%b,y,x);y-=x*(a/b);
	return res;
}
ll id4(ll a,ll b,ll &x,ll &y){
	if (!b){x=1;y=0;return a;}
	ll tmp=id4(b,a%b,y,x);y-=x*(a/b);
	return tmp;
}
template<class T> pair<vector<T>,int> factor(T x){
	pair<vector<T>,int> res;
	for (T i=2;i*i<=x;++i)if (x%i==0){
		int cnt=0;while (x%i==0)x/=i,++cnt;res.push(make_pair(i,cnt));
	}
	if (x>1)res.push(make_pair(x,1));
	return res;
}
template<class T> T phi(T x){
	pair<vector<T>,int> tmp=factor(x);
	for (int i=0;i<tmp.size();++i)x=x/tmp[i].first*(tmp[i].first-1);return x;
}
ll exp(ll x,ll y,ll z){  

	ll ans=1;
	while (y){
		if (y&1)ans=ans*x%z;
		x=x*x%z;y>>=1;
	}
	return ans;
}
bool witness(ll x,ll n){
	ll tmp=n-1;
	while (!(tmp&1))tmp>>=1;
	ll x0,x1=exp(x,tmp,n);
	while (tmp!=n-1){
		x0=x1;x1=x0*x0%n;
		if (x1==1&&x0!=1&&x0!=n-1)return 1;
		tmp<<=1;
	}
	if (x1!=1)return 1;
		else return 0;
}
bool Judge(ll x){
	
	if (x==1)return 0;
	for (int i=0;i<Sp;++i){
		ll tmp=((rand()<<16)+rand())%(x-1)+1;
		if (witness(tmp,x))return 0;
	}
	return 1;
}
ll inv(ll x,ll p,ll P){return exp(x,p-2,P);}
int get_prime(int p[],int n){
	int len=0,*f=new int[n+1];
	memset(f+1,0,sizeof(int)*n);
	for (int i=2;i<=n;++i){
		if (!f[i])f[i]=p[++len]=i;
		for (int j=1;j<=len&&p[j]<=f[i]&&i*p[j]<=n;++j)
			f[i*p[j]]=p[j];
	}
	delete[] f;return len;
}
inline int _rand(){static unsigned int x=31253125;x+=(x<<4)+1;x&=0x7fffffff;return x;}
inline int rand32(){return (bool(rand()&1)<<30)+(rand()<<15)+rand();}
inline int random32(int l,int r){return rand32()%(r-l+1)+l;}
inline int random(int l,int r){return rand()%(r-l+1)+l;}
template<int stack_size,class T>
void id0(T *p,int a){
	int *Stack=new int[stack_size],bak;
	__asm__ __volatile__
	(
		"mov %%esp,%0\n"
		"mov %1,%%esp\n"
		:"=g"(bak)
		:"g"(Stack+stack_size-1)
		:
	);
	(*p)(a);
	__asm__ __volatile__
	(
		"mov %0,%%esp\n"
		:
		:"g"(bak)
		:
	);
	delete[] Stack;
}
struct Timer{
	int t;
	Timer(){set();}
	void set(){t=clock();}
	int time(){return clock()-t;}
	void print(){printf("time=%d\n",time());}
};
template<int _N,int _M>
struct Edge{
	int link[_M],next[_M],son[_N],l;
	void clear(){l=0;memset(son,0,sizeof(son));}
	void addedge(int x,int y){
		link[++l]=y;next[l]=son[x];son[x]=l;
	}
};
template<int _N,int _M>
struct Edge_c{
	int link[_M*2],next[_M*2],cost[_M*2],son[_N],l;
	void clear(){l=0;memset(son,0,sizeof(son));}
	void addedge(int x,int y,int z){
		link[++l]=y;cost[l]=z;next[l]=son[x];son[x]=l;
	}
};
template<int N>
struct DisjointSet{
	int f[N],rank[N];
	void init(int n){for (int i=1;i<=n;++i)f[i]=i,rank[i]=0;}
	int find(int x){
		if (f[x]==x)return x;
		else return f[x]=find(f[x]);
	}
	void link(int x,int y){f[find(x)]=find(y);}
	void _link(int x,int y){
		int f1=find(x),f2=find(y);
		if (f1==f2)return;
		if (rank[f1]>rank[f2])f[f2]=f1;
			else if (rank[f1]<rank[f2])f[f1]=f2;
				else f[f2]=f1,++rank[f1];
	}
};
namespace Matrix{
	const ll P=1000000007LL;size_t size;
	template<size_t Size>
	struct matrix{
		ll key[Size][Size];
		void clear(){
			memset(key,0,sizeof(key));
		}
		void print(int n){
			for (int i=0;i<size;++i)
				for (int j=0;j<size;++j)
					printf("%d%c",(int)key[i][j],j+1==size?'\n':' ');
		}
		int det(){
			if (P==1)return 0;
			for (int i=0;i<size;++i)
				for (int j=0;j<size;++j)key[i][j]%=P;
			int ans=1;
			for (int i=0;i<size;++i){
				for (int j=i+1;j<size;++j)while (key[j][i]){
					int t=key[i][i]/key[j][i];
					for (int k=i;k<size;++k)
						key[i][k]=((ll)key[j][k]*-t+key[i][k])%P;
					for (int k=i;k<size;++k)
						{int tmp=key[i][k];key[i][k]=key[j][k];key[j][k]=tmp;}
					ans=-ans;
				}
				if (key[i][i]==0)return 0;
				ans=(ll)ans*key[i][i]%P;
			}
			return ((ll)ans+P)%P;
		}
	};
	template<size_t Size>
	const matrix<Size>& operator +(const matrix<Size> &a,const matrix<Size> &b){
		static matrix<Size> T;T.clear();
		for (int i=0;i<size;++i)
			for (int j=0;j<size;++j)T.key[i][j]=(a.key[i][j]+b.key[i][j])%P;
		return T;
	}
	template<size_t Size>
	const matrix<Size>& operator *(const matrix<Size> &a,const matrix<Size> &b){
		static matrix<Size> T;T.clear();
		for (int k=0;k<size;++k)
			for (int i=0;i<size;++i)
				for (int j=0;j<size;++j)
					T.key[i][j]+=a.key[i][k]*b.key[k][j];
		for (int i=0;i<size;++i)
			for (int j=0;j<size;++j)T.key[i][j]=T.key[i][j]%P;
		return T;
	}
	template<size_t Size>
	matrix<Size> pow(const matrix<Size> &x,int y){
		static matrix<Size> res,tmp;tmp=x;
		memset(res.key,0,sizeof(res.key));
		for (int i=0;i<Size;++i)res.key[i][i]=1;
		while (y){
			if (y&1)res=res*tmp;
			tmp=tmp*tmp;y>>=1;
		}
		return res;
	}
};
using Matrix::matrix;
struct point{
	static const double eps=1e-10;
	ll x,y;
	point(ll _x=0,ll _y=0):x(_x),y(_y){}
	point operator +(const point &p)const{return point(x+p.x,y+p.y);}
	point operator -(const point &p)const{return point(x-p.x,y-p.y);}
	double operator *(const point &p)const{return x*p.x+y*p.y;}  

	double operator ^(const point &p)const{return x*p.y-p.x*y;}  

	point operator *(ll d)const{return point(x*d,y*d);}
	friend point operator *(ll d,const point &x){return point(x.x*d,x.y*d);}
	point operator /(ll d)const{return point(x/d,y/d);}
	friend point operator /(ll d,const point &x){return point(x.x/d,x.y/d);}
	point operator -()const{return point(-x,-y);}
	bool operator <(const point &p)const{return x<p.x||x==p.x&&y<p.y;}
	bool operator ==(const point &p)const{return fabs(x-p.x)<eps&&fabs(y-p.y)<eps;}
	bool operator !=(const point &p)const{return !(*this==p);}
	point& operator +=(const point &p){x+=p.x;y+=p.y;return *this;}
	point& operator -=(const point &p){x-=p.x;y-=p.y;return *this;}
	point& operator *=(ll d){x*=d;y*=d;return *this;}
	point& operator /=(ll d){x/=d;y/=d;return *this;}
	double len()const{return sqrt(x*x+y*y);}
	double atan(){return atan2(y,x);}
	

		

	

	istream& operator >>(istream &in){return in>>x>>y;}
	ostream& operator <<(ostream &out){return out<<"("<<x<<","<<y<<")";}
};
template<size_t N>
void id5(int A[N],int l,int r){  

	
	
	A+=l-1;r-=l-1;l=1;
	int *B=new int[N],*s=new int[base+1],*a=A,*b=B,x=0;
	for (int i1=1;i1<=2;++i1){
		memset(s,0,sizeof(s));
		for (int i=1;i<=r;++i)++s[a[i]>>x&base];
		for (int i=1;i<=base;++i)s[i]+=s[i-1];
		for (int i=r;i>=1;--i)b[s[a[i]>>x&base]--]=a[i];
		int *tmp=a;a=b;b=tmp;x+=W;
	}
	if (a!=A)memcpy(A+1,a+1,sizeof(int)*r);
	delete[] B;delete[] s;
	
	
}
template<class T>
struct Vector{
	typedef T* it;
	it Mem,End,MemEnd;
	void Grow(){
		int s=MemEnd-Mem;it NewMem=new T[s*2];
		memcpy(NewMem,Mem,sizeof(T)*s);delete[] Mem;
		Mem=NewMem;End=Mem+s;MemEnd=Mem+s*2;
	}
	void Shrink(){
		int s=MemEnd-Mem,l=End-Mem;it NewMem=new T[s>>1];
		memcpy(NewMem,Mem,sizeof(T)*(s>>1));delete[] Mem;
		Mem=NewMem;End=Mem+l;MemEnd=Mem+(s>>1);
	}
	Vector(){Mem=new T[1];End=Mem;MemEnd=Mem+1;}
	void push_back(const T &x){
		if (End==MemEnd)Grow();*(End++)=x;
	}
	void pop_back(){
		--End;if (End-Mem<(MemEnd-Mem)>>2)Shrink();
	}
	it begin(){return Mem;}
	it end(){return End;}
	int size(){return End-Mem;}
	int capacity(){return MemEnd-Mem;}
	T& operator [](int id){return Mem[id];}
};
template<size_t N,size_t M>
struct graph{
	
	
	int link[M],cost[M],next[M],son[N],*cap,*opp,*st,l;
	void add(int x,int y,int z=0){
		link[++l]=y;cost[l]=z;next[l]=son[x];son[x]=l;
	}
	void clear(){l=0;memset(son,-1,sizeof(son));}
	void set(int _n){n=_n;clear();}
	graph():n(0),cap(NULL),opp(NULL){}
	graph(int _n):n(_n),cap(NULL),opp(NULL){clear();}
	void addedge(int x,int y){add(x,y);}
	void addedge2(int x,int y){add(x,y);add(y,x);}
	void addedge(int x,int y,int z){add(x,y,z);}
	void addedge2(int x,int y,int z){add(x,y,z);add(y,x,z);}
	void addedge_f(int x,int y,int z){
		if (!cap)cap=new int[M],opp=new int[M];
		link[++l]=y;next[l]=son[x];son[x]=l;cap[l]=z;opp[l]=l+1;
		link[++l]=x;next[l]=son[y];son[y]=l;cap[l]=0;opp[l]=l-1;
	}
	void addedge_c(int x,int y,int z,int c){
		if (!cap)cap=new int[M],opp=new int[M];if (!st)st=new int[M];
		link[++l]=y;st[l]=x;next[l]=son[x];son[x]=l;cap[l]=z;cost[l]=c;opp[l]=l+1;
		link[++l]=x;st[l]=y;next[l]=son[y];son[y]=l;cap[l]=0;cost[l]=-c;opp[l]=l-1;
	}
	int *inq,*q,*d,*f,*pre,n,S,T;
	void spfa(int S,int *d){
		int h=0,t=1;new_arr(inq);new_arr(q);
		for (int i=1;i<=n;++i)d[i]=oo;
		for (int i=1;i<=n;++i)inq[i]=0;
		d[S]=0;q[1]=S;inq[S]=1;
		while (h!=t){
			h=h<n?h+1:1;int i=q[h];inq[i]=0;
			for (int p=son[i];p!=-1;p=next[p]){
				int j=link[p];
				if (d[i]+cost[p]<d[j]){
					d[j]=d[i]+cost[p];
					if (!inq[j])t=t<n?t+1:1,q[t]=j,inq[j]=1;
				}
			}
		}
		delete[] inq;delete[] q;
	}
	struct d_node{
		int d,x;
		d_node(int _d,int _x){d=_d;x=_x;}
		bool operator <(const d_node &y)const{return d>y.d;}
	};
	void dijkstra(int S,int *dis){
		priority_queue<d_node> Q;
		bool *visit=new bool[n+5];
		for (int i=1;i<=n;++i)visit[i]=0,dis[i]=oo;
		Q.push(d_node(0,S));
		while (!Q.empty()){
			int d=Q.top().d,x=Q.top().x;visit[x]=1;dis[x]=d;
			for (int p=son[x];p!=-1;p=next[p])
				Q.push(d_node(d+cost[p],link[p]));
			while (visit[Q.top().x]&&!Q.empty())Q.pop();
		}
		delete[] visit;
	}
	int *dfn,*low,*stack,*instack,*num,top,D,now;
	void tarjan_f(int x){
		dfn[x]=low[x]=++D;stack[++top]=x;instack[x]=1;
		for (int p=son[x];p!=-1;p=next[p]){
			int j=link[p];
			if (!dfn[j]) tarjan_f(j),low[x]=min(low[x],low[j]);
			else if (instack[j]) low[x]=min(low[x],dfn[j]);
		}
		if (low[x]==dfn[x]){
			int k;++now;
			do k=stack[top--],instack[k]=0,num[k]=now; while (k!=x);
		}
	}
	void tarjan(int *_num){
		new_arr(dfn);new_arr(low);new_arr(stack);new_arr(instack);
		memset(dfn,0,sizeof(int)*(n+5));D=0;top=0;now=0;num=_num;
		for (int i=1;i<=n;++i)if (!dfn[i])tarjan(i);
		delete[] dfn;delete[] low;delete[] stack;delete[] instack;
	}
	int toposort(int *q){
		int *in;new_arr(in);
		int h=0,t=0;
		for (int i=1;i<=n;++i)in[i]=0;
		for (int i=1;i<=n;++i)
			for (int p=son[i];p!=-1;p=next[p])++in[link[p]];
		for (int i=1;i<=n;++i)if (!in[i])q[++t]=i;
		while (h<t){
			int i=q[++h];
			for (int p=son[i];p!=-1;p=next[p]){
				int j=link[p]; --in[j];
				if (!in[j])q[++t]=j;
			}
		}
		delete[] in;return t;
	}
	int find(int x){
		if (f[x]==x)return x;
		else return f[x]=find(f[x]);
	}
	struct k_edge{
		int x,y,z,id;
		bool operator <(const k_edge &y)const{return z<y.z;}
	};
	int kruskal(){
		k_edge *e=new k_edge[l+5];new_arr(f);
		int m=0,ans=0,num=0;
		for (int i=1;i<=n;++i)
			for (int p=son[i];p!=-1;p=next[p])
				e[++m].x=i,e[m].y=link[p],e[m].z=cost[p],e[m].id=m;
		std::sort(e+1,e+1+m);
		for (int i=1;i<=n;++i)f[i]=i;
		for (int i=1;i<=m;++i){
			int f1=find(e[i].x),f2=find(e[i].y);
			if (f1!=f2)f[f1]=f2,ans+=e[i].z,++num;
		}
		delete[] e;delete[] f;
		if (num==n-1)return ans;else return oo;
	}
	bool build(){
		int x,y,l=1,r=1;
		memset(d,-1,sizeof(int)*(n+5));
		q[1]=S;d[S]=0;
		while (l<=r){
			x=q[l++];
			for (int i=son[x];i!=-1;i=next[i]){
				y=link[i];
				if (cap[i]&&d[y]==-1){
					d[y]=d[x]+1;q[++r]=y;
					if (y==T)return 1;
				}
			}
		}
		return 0;
	}
	int find(int now,int flow){
		int ret,y,w=0;
		if (now==T)return flow;
		for (int i=son[now];i!=-1&&w<flow;i=next[i]){
			y=link[i];
			if (cap[i]&&d[y]==d[now]+1&&(ret=find(y,min(flow-w,cap[i]))))
				cap[i]-=ret,cap[opp[i]]+=ret,w+=ret;
		}
		if (!w)d[now]=-1;
		return w;
	}
	int maxflow(int _S,int _T){  

		int ans=0;new_arr(d);new_arr(q);S=_S;T=_T;
		while (build()) while (1){
			int flow=find(S,oo);
			if (!flow)break;
			ans+=flow;
		}
		delete[] d;delete[] q;
		return ans;
	}
	int spfa_c(){
		int h=0,t=1,i,j,p;
		for (int i=0;i<=n;++i)d[i]=oo;
		for (int i=0;i<=n;++i)inq[i]=0;
		d[S]=0;q[1]=S;inq[S]=1;
		while (h!=t){
			h=h<n?h+1:1;i=q[h];inq[i]=0;
			for (p=son[i];p!=-1;p=next[p]){
				j=link[p];
				if (d[i]+cost[p]<d[j]&&cap[p]){
					d[j]=d[i]+cost[p];pre[j]=p;
					if (!inq[j])t=t<n?t+1:1,q[t]=j,inq[j]=1;
				}
			}
		}
		return d[T]<oo?1:0;
	}
	void update(int &maxflow,int &mincost){
		int p,flow=oo;
		for (p=T;p!=S;p=st[p]){
			p=pre[p];if (cap[p]<flow)flow=cap[p];
		}
		maxflow+=flow;
		for (p=T;p!=S;p=st[p]){
			p=pre[p];mincost+=cost[p]*flow;
			cap[p]-=flow;cap[opp[p]]+=flow;
		}
	}
	pair<int,int> costflow(int _S,int _T){
		int maxflow,mincost;S=_S;T=_T;new_arr(d);new_arr(q);new_arr(inq);new_arr(pre);
		maxflow=mincost=0;while (spfa_c())update(maxflow,mincost);
		delete[] d;delete[] q;delete[] inq;delete[] pre;
		return make_pair(maxflow,mincost);
	}
	template<int _N,int _M>
	void floyd(int (&a)[_N][_M]){
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)a[i][j]=oo;
		for (int i=1;i<=n;++i)a[i][i]=0;
		for (int x=1;x<=n;++x)
			for (int p=son[x],y=link[p];p!=-1;p=next[p],y=link[p])
				a[x][y]=min(a[x][y],cost[p]);
		for (int k=1;k<=n;++k)
			for (int i=1;i<=n;++i)
				for (int j=1;j<=n;++j)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
	template<int _N,int _M>
	void Johnson(int (&a)[_N][_M]){
		if (n<1)return;
		int *_cost=new int[l];new_arr(d);spfa(1,d);
		memcpy(_cost,cost,sizeof(int)*l);
		for (int x=1;x<=n;++x)
			for (int p=son[x],y=link[p];p!=-1;p=next[p],y=link[p])
				cost[p]+=d[x]-d[y];
		for (int i=1;i<=n;++i){
			dijkstra(i,a[i]);
			for (int j=1;j<=n;++j)a[i][j]+=d[j]-d[i];
		}
		memcpy(cost,_cost,sizeof(int)*l);
		delete[] d;delete[] _cost;
	}
	
	
};
template<int S>
struct BitSet{
	
	
	
	typedef unsigned int uint;
	uint a[get_size(S)];int size;
	void clear(){memset(a,0,sizeof(uint)*size);}
	BitSet():size(get_size(S)){clear();}
	BitSet(uint x):size(get_size(S)){clear();a[0]=x;}
	BitSet(const BitSet<S> &x):size(get_size(S)){*this=x;}
	void set(int x,int y){
		if (y<0||y>1){printf("error!\n");return;}
		int X=x>>W,Y=x&mask;
		if (y)a[X]|=1<<Y;else a[X]&=~(1<<Y);
	}
	uint find(uint x){uint X=x>>W,Y=x&mask;return (a[X]>>Y)&1u;}
	uint operator [](uint x){return find(x);}
	BitSet& operator =(const BitSet &y){
		memcpy(a,y.a,sizeof(uint)*size);
		

		

		

		return *this;
	}
	BitSet<S> operator |(const BitSet<S> &y){
		BitSet<S> res;
		for (int i=0;i<size;++i)res.a[i]=a[i]|y.a[i];
		return res;
	}
	BitSet<S> operator &(const BitSet<S> &y){
		BitSet<S> res;
		for (int i=0;i<size;++i)res.a[i]=a[i]&y.a[i];
		return res;
	}
	BitSet<S> operator ^(const BitSet<S> &y){
		BitSet<S> res;
		for (int i=0;i<size;++i)res.a[i]=a[i]^y.a[i];
		return res;
	}
	BitSet<S> operator ~(){
		return BitSet<S>(*this).flip();
		
	}
	BitSet<S>& operator =(const char *s){
		memset(a,0,sizeof(uint)*size);
		for (int i=0;i<S;++i){
			if (s[i]!='0'&&s[i]!='1')break;
			int X=i>>W,Y=i&mask;
			if (s[i]=='1')a[X]|=1<<Y;
		}
		return *this;
	}
	BitSet<S>& operator =(const int *s){
		memset(a,0,sizeof(uint)*size);
		for (int i=0;i<S;++i){
			if (s[i]!=0&&s[i]!=1)break;
			int X=i>>W,Y=i&mask;
			if (s[i]==1)a[X]|=1<<Y;
		}
		return *this;
	}
	BitSet<S> operator <<(uint x){}
	BitSet<S> operator >>(uint x){}
	BitSet<S>& operator |=(const BitSet<S> &y){
		uint *startA=a;const uint *startB=y.a,*endA=a+size;
		while (startA!=endA)*startA++|=*startB++;
		

		return *this;
	}
	BitSet<S>& operator &=(const BitSet<S> &y){
		uint *startA=a;const uint *startB=y.a,*endA=a+size;
		while (startA!=endA)*startA++&=*startB++;
		

		return *this;
	}
	BitSet<S>& operator ^=(const BitSet<S> &y){
		uint *startA=a;const uint *startB=y.a,*endA=a+size;
		while (startA!=endA)*startA++^=*startB++;
		

		return *this;
	}
	operator bool(){return count()>0;}
	BitSet<S>& flip(){
		for (uint *start=a,*end=a+size;start!=end;*start=~*start++);
		return *this;
	}
	

	void flip(int x){a[x>>W]^=1<<(x&mask);}
	uint popcount(uint x)const{
		x=(x&0x55555555)+((x>>1)&0x55555555);
		x=(x&0x33333333)+((x>>2)&0x33333333);
		x=(x&0x0F0F0F0F)+((x>>4)&0x0F0F0F0F);
		x=(x&0x00FF00FF)+((x>>8)&0x00FF00FF);
		x=(x&0x0000FFFF)+((x>>16)&0x0000FFFF);
		return x;
	}
	int count(){
		int res=0;
		if (S&mask)a[size-1]&=(1<<(S&mask))-1;
		for (int i=0;i<size;++i)res+=popcount(a[i]);
		return res;
	}
	void reset(){
		memset(a,0,sizeof(uint)*size);
		

	}
	uint to_uint(){
		if (S&mask)a[size-1]&=(1<<(S&mask))-1;
		return a[0];
	}
	void print(){
		for (int i=0;i<size;++i)
			for (int j=0;j<=mask&&(i<<W)+j+1<=S;++j)printf("%d",(a[i]>>j)&1);
		printf("\n");
	}
	
	
	
};
template<class Tkey> inline size_t id3(const Tkey &x){return x;}
template<class Tkey,class Tvalue,size_t (*gethash)(const Tkey&)=id3>
struct Hash{
	Tkey *key; Tvalue *value;
	int *v,*next,len,P,size;
	void build(int Len=9,int p=11){  

		P=p;len=0;size=Len;++Len; key=new Tkey[Len];
		v=new int[p];memset(v,0,sizeof(int)*p);
		value=new Tvalue[Len];memset(value,0,sizeof(Tvalue)*Len);
		next=new int[Len];memset(next,0,sizeof(int)*Len);
	}
	Hash(int Len=0,int p=11){if (Len==0)return;build(Len,p);}
	void clear(){len=0;memset(v,0,sizeof(int)*P);}
	void insert(const Tkey &x,const Tvalue &y=0){
		size_t x1=gethash(x)%P;
		key[++len]=x;value[len]=y;
		next[len]=v[x1];v[x1]=len;
	}
	void del(const Tkey &x){
		size_t x1=gethash(x)%P;
		for (int i=v[x1],pre=0;i;pre=i,i=next[i])
			if (key[i]==x)
				if (pre==0)v[x1]=next[i];
				else next[pre]=next[i];
	}
	Tvalue find(const Tkey &x){
		size_t x1=gethash(x)%P;
		for (int i=v[x1];i;i=next[i])
			if (key[i]==x)return value[i];
		return -1;
	}
	Tvalue& find_r(const Tkey &x){
		size_t x1=gethash(x)%P;
		for (int i=v[x1];i;i=next[i])
			if (key[i]==x)return value[i];
		Tvalue *null=NULL;return *null;
	}
	void inc(const Tkey &x,const Tvalue &y=1){
		size_t x1=gethash(x)%P;
		for (int i=v[x1];i;i=next[i])
			if (key[i]==x){value[i]+=y;return;}
	}
	Tvalue& operator [](const Tkey &x){
		Tvalue& tmp=find_r(x);
		if (&tmp==0)insert(x);return find_r(x);
	}
	Tvalue id(const Tkey &x){return find(x);}
};
class Int{
	
	public:
	typedef long long value;
	void New(size_t l){
		if (a!=NULL)delete[] a;a=new value[l];
		len=1;a[0]=0;sign=1;
	}
	Int():a(NULL),base(BASE){New(1);}
	Int(value x):a(NULL),base(BASE){New(1);*this=x;}
	Int(const Int &B):a(NULL),base(BASE){New(1);*this=B;}
	~Int(){delete[] a;}
	Int& operator =(value x){
		size_t l=1;for (value x1=max(x,-x);x1>=base;++l,x1/=base);New(l);
		if (x<0)x=-x,sign=0;else sign=1;
		len=0;while (x)a[len++]=x%base,x/=base;
		if (!len)a[len++]=0;
		return *this;
	}
	Int& operator =(const Int &A){
		New(A.len);len=A.len;memcpy(a,A.a,sizeof(value)*len);
		base=A.base;sign=A.sign;return *this;
	}
	friend Int operator -(Int A){A.sign=1-A.sign;return A;}
	bool operator !(){if (len==1&&a[0]==0)return 1;else return 0;}
	friend Int operator +(Int A,Int B){
		if (A.sign!=B.sign){B.sign=1-B.sign;return A-B;}
		if (A.base!=B.base)
			if (A.base>B.base)B.set_base(A.base);
			else A.set_base(B.base);
		Int res;res.set_base(A.base); int len=A.len>B.len?A.len:B.len;
		res.New(len+1);res.sign=A.sign;
		memset(res.a,0,(len+1)*sizeof(value));
		for (int i=0;i<len;++i){
			if (i<A.len)res.a[i]+=A.a[i];
			if (i<B.len)res.a[i]+=B.a[i];
		}
		for (int i=0;i<len;++i)
			if (res.a[i]>=res.base)++res.a[i+1],res.a[i]-=res.base;
		if (res.a[len])res.len=len+1;else res.len=len;
		return res;
	}
	friend Int operator -(Int A,Int B){
		if (A.sign!=B.sign){B.sign=1-B.sign;return A+B;}
		if (A.base!=B.base)
			if (A.base>B.base)B.set_base(A.base);
			else A.set_base(B.base);
		if (small(A,B))swap(A,B),A.sign=1-A.sign;
		Int res;res.set_base(A.base); int len=A.len>B.len?A.len:B.len;
		res.New(len);res.sign=A.sign;
		memset(res.a,0,len*sizeof(value));
		for (int i=0;i<len;++i){
			if (i>=B.len)res.a[i]+=A.a[i];
			else res.a[i]+=A.a[i]-B.a[i];
			if (res.a[i]<0)res.a[i]+=res.base,--res.a[i+1];
		}
		while (len>1&&!res.a[len-1])--len;res.len=len;
		return res;
	}
	friend Int operator *(Int A,Int B){
		if (A.base!=B.base)
			if (A.base>B.base)B.set_base(A.base);
			else A.set_base(B.base);
		Int res;res.set_base(A.base); int len=A.len+B.len;
		res.New(len);res.sign=(A.sign==B.sign);
		memset(res.a,0,len*sizeof(value));
		for (int i=0;i<A.len;++i)
			for (int j=0;j<B.len;++j){
				res.a[i+j]+=A.a[i]*B.a[j];
				res.a[i+j+1]+=res.a[i+j]/res.base;
				res.a[i+j]%=res.base;
			}
		
		while (len>1&&!res.a[len-1])--len;res.len=len;
		return res;
	}
	friend pair<Int,Int> divide(Int A,Int B){
		if (!B){puts("error:div zero!");for (;;);}
		if (A.base!=B.base)
			if (A.base>B.base)B.set_base(A.base);
			else A.set_base(B.base);
		if (small(A,B))return make_pair(Int(0),A);
		Int C,D;C.set_base(A.base);D.set_base(A.base);C.New(A.len);C.len=A.len;
		for (int i=A.len-1;i>=0;--i){
			C.a[i]=0;D=D*D.base;D.a[0]=A.a[i];
			int l=0,r=A.base-1,mid;
			while (l<r){
				mid=(l+r+1)>>1;
				if (small(B*mid,D+1))l=mid;
					else r=mid-1;
			}
			C.a[i]=l;D=D-B*l;
		}
		C.sign=(A.sign==B.sign);D.sign=A.sign;
		while (C.len>1&&!C.a[C.len-1])--C.len;
		return make_pair(C,D);
	}
	Int operator /(value x){
		if (!x){puts("error:div zero!");for (;;);}
		value d=0;Int res;res.set_base(base);res.New(len);res.len=len;
		if (x<0)x=-x,res.sign=(sign==0);
		else res.sign=(sign==1);
		for (int i=len-1;i>=0;--i)
			d=d*base+a[i],res.a[i]=d/x,d%=x;
		while (res.len>1&&!res.a[res.len-1])--res.len;
		return res;
	}
	Int operator %(value x){
		value d=0;if (x<0)x=-x;
		for (int i=len-1;i>=0;--i)d=(d*base+a[i])%x;
		return d;
	}
	friend Int abs(Int A){A.sign=1;return A;}
	friend bool small(Int A,Int B){
		if (A.base!=B.base)
			if (A.base>B.base)B.set_base(A.base);
			else A.set_base(B.base);
		if (A.len!=B.len)return A.len<B.len;
		for (int i=A.len-1;i>=0;--i)
			if (A.a[i]!=B.a[i])return A.a[i]<B.a[i];
		return 0;
	}
	friend bool operator <(Int A,Int B){
		if (A.sign!=B.sign)return A.sign<B.sign;
		return small(A,B);
	}
	friend bool operator ==(Int A,Int B){
		if (A.base!=B.base)
			if (A.base>B.base)B.set_base(A.base);
			else A.set_base(B.base);
		if (A.sign!=B.sign||A.len!=B.len)return 0;
		for (int i=0;i<A.len;++i)if (A.a[i]!=B.a[i])return 0;
		return 1;
	}
	friend bool operator !=(Int A,Int B){return !(A==B);}
	friend bool operator >(Int A,Int B){return !(A<B||A==B);}
	friend bool operator <=(Int A,Int B){return A<B||A==B;}
	friend bool operator >=(Int A,Int B){return A>B||A==B;}
	Int operator /(Int B){return divide(*this,B).first;}
	Int operator %(Int B){return divide(*this,B).second;}
	Int& operator +=(Int B){*this=*this+B;return *this;}
	Int& operator -=(Int B){*this=*this-B;return *this;}
	Int& operator *=(Int B){*this=*this*B;return *this;}
	Int& operator /=(Int B){*this=*this/B;return *this;}
	Int& operator %=(Int B){*this=*this%B;return *this;}
	Int& operator ++(){*this=*this+1;return *this;}
	Int& operator --(){*this=*this-1;return *this;}
	Int operator ++(int){Int res(*this);*this=*this+1;return res;}
	Int operator --(int){Int res(*this);*this=*this-1;return res;}
	Int operator +(value x){return *this+Int(x);}
	Int operator -(value x){return *this-Int(x);}
	Int operator *(value x){return *this*Int(x);}
	

	

	Int& operator *=(value x){*this=*this*x;return *this;}
	Int& operator +=(value x){*this=*this+x;return *this;}
	Int& operator -=(value x){*this=*this-x;return *this;}
	Int& operator /=(value x){*this=*this/x;return *this;}
	Int& operator %=(value x){*this=*this%x;return *this;}
	bool operator ==(value x){return *this==Int(x);}
	bool operator !=(value x){return *this!=Int(x);}
	bool operator <=(value x){return *this<=Int(x);}
	bool operator >=(value x){return *this>=Int(x);}
	bool operator <(value x){return *this<Int(x);}
	bool operator >(value x){return *this>Int(x);}
	void to_arr(char *c){
		char *c1=c;
		for (int i=0;i<len-1;++i)
			for (value x=a[i],b=base/10;b>=1;b/=10)*c1++='0'+x%10,x/=10;
		for (value x=a[len-1];x>0;x/=10)*c1++='0'+x%10;
		if (len==1&&a[len]==0)*c1++='0';
		if (sign==0)*c1++='-';*c1=0;reverse(c,c1);
	}
	void from_arr(char *c){
		size_t base_l=get_basel(),b=1;int cl=strlen(c);value x=0;
		New((cl+base_l-1)/base_l);len=0;
		if (*c=='-')sign=0,++c,--cl;else sign=1;
		while (--cl>=0){
			x+=(c[cl]-'0')*b;b*=10;if (b==base)a[len++]=x,x=0,b=1;
		}
		if (!len||x)a[len++]=x;
		while (len>1&&!a[len-1])--len;
	}
	void set_base(int _base){
		if (base==_base)return;
		char *c=new char[len*get_basel()];
		to_arr(c);base=_base;from_arr(c);
		delete[] c;
	}
	void set_basel(int _l){
		size_t _base=1;while (_l--)_base*=10;set_base(_base);
	}
	void read(){
		vector<char> s;char ch;
		scanf(" %c",&ch);if (ch=='-')s.push_back('-'),ch=getchar();
		for (;ch>='0'&&ch<='9';ch=getchar())s.push_back(ch);
		char *c=new char[s.size()+1];
		for (int i=0;i<s.size();++i)c[i]=s[i];c[s.size()]=0;
		from_arr(c);delete[] c;
	}
	void print(){
		if (!sign)putchar('-');
		printf("%d",int(a[len-1]));
		for (int i=len-2;i>=0;--i){
			for (int j=base/10;j>=10;j/=10)
				if (a[i]<j)putchar('0');
					else break;
			printf("%d",(int)a[i]);
		}
	}
	void println(){print();putchar('\n');}
	private:
	value *a,base;int len;bool sign;  

	size_t get_basel(){
		size_t res=0;for (int b=base/10;b>=1;b/=10,++res);
		return res;
	}
	
};
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
	inline void id7(char *s){gets(s);}
	

	struct id2{
		char *buf,*p1,*pend;
		id2(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
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
			if (y>0){out('.'); for (int i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
		}
		void println(double x,int y){print(x,y);out('\n');}
		void print(char *s){while (*s)out(*s++);}
		void println(char *s){while (*s)out(*s++);out('\n');}
		void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~id2(){flush();}
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
template<class Tkey,class Tvalue>
struct hash{
	Tkey *key; Tvalue *value;
	int *v,*next,len,P,size;
	void build(int Len=9,int p=11)  

	{
		P=p;len=0;size=Len;++Len;
		v=new int[p];memset(v,0,sizeof(int)*p);
		value=new Tvalue[Len];memset(value,0,sizeof(Tvalue)*Len);
		next=new int[Len];memset(next,0,sizeof(int)*Len);
		key=new Tkey[Len];memset(key,0,sizeof(Tkey)*Len);
	}
	hash(int Len=0,int p=11){
		if (Len==0)return;build(Len,p);
	}
	void clear(){len=0;memset(v,0,sizeof(int)*P);}
	size_t gethash(const Tkey &x){return x%P;}
	void insert(Tkey x,Tvalue y=0){
		Tkey x1=gethash(x);
		key[++len]=x;value[len]=y;
		next[len]=v[x1];v[x1]=len;
	}
	void del(Tkey x){
		Tkey x1=gethash(x);int i=v[x1],pre=0;
		while(i){
			if (key[i]==x){
				if (pre==0)v[x1]=next[i];
					else next[pre]=next[i];
			}
			pre=i;i=next[i];
		}
	}
	bool find(const Tkey &x){
		size_t x1=gethash(x);int i=v[x1];
		while(i){
			if (key[i]==x)return 1;
			i=next[i];
		}
		return 0;
	}
	void inc(Tkey x,Tvalue y=1){
		Tkey x1=gethash(x);int i=v[x1];
		while(i){
			if (key[i]==x){value[i]+=y;return;}
			i=next[i];
		}
	}
	int operator [](Tkey x){return find(x);}
};

string name="", in=".in", out=".out";

point a[N];
int ans[N],ans1;
size_t G(const pair<ll,ll> &x){return (x.first<<16)+x.second;}
inline size_t G1(int x,int y){return (x<<8)+(x>>4)+y;}
hash<size_t,int> init(300005,1000005);
Hash<pair<ll,ll>,bool,G> S(100000,100000);
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int n,k;read(n);read(k);
	for (int i=1;i<=n;++i)read(a[i].x),read(a[i].y),init.insert(G1((ll)a[i].x,(ll)a[i].y));
	sort(a+1,a+1+n);
	for (int i=1;i<=k+1&&i<=n;++i)
		for (int j=n;n-j<=k&&j>=1;--j){
			point mid=a[i]+a[j];ll midx=mid.x,midy=mid.y;int cnt=0;
			for (int i1=1;i1<=n;++i1)
				//printf("calc %I64d %I64d %I64d %I64d\n",(ll)(mid.x-a[i1].x),(ll)(mid.y-a[i1].y),(ll)a[i1].x,(ll)a[i1].y);
				if (!init.find(G1(midx-a[i1].x,midy-a[i1].y)))++cnt;
				/*{
					++cnt;if (cnt>k)break;
				}*/
			//printf("cnt=%d %.2lf %.2lf\n",cnt,0.5*mid.x,0.5*mid.y);
			if (cnt<=k)S[make_pair((ll)(mid.x),(ll)(mid.y))];
		}
	{
		point mid=point(123454,654677);int cnt=0;
		for (int i1=1;i1<=n;++i1){
			//printf("calc %I64d %I64d %I64d %I64d\n",(ll)(mid.x-a[i1].x),(ll)(mid.y-a[i1].y),(ll)a[i1].x,(ll)a[i1].y);
			if (!init.find(G1((ll)(mid.x-a[i1].x),(ll)(mid.y-a[i1].y))))++cnt;
			if (cnt>k)break;
		}
		//printf("cnt=%d %.2lf %.2lf\n",cnt,0.5*mid.x,0.5*mid.y);
		if (cnt<=k){puts("-1");return 0;}
	}
	printf("%d\n",S.len);
	for (int i=0;i<S.P;++i)
		for (int j=S.v[i];j;j=S.next[j])
		printf("%.8lf %.8lf\n",0.5*S.key[j].first,0.5*S.key[j].second);
	/*printf("%d\n",S.size());
	for (set<pair<ll,ll> >::iterator zzy=S.begin();zzy!=S.end();++zzy)
		printf("%.8lf %.8lf\n",0.5*zzy->first,0.5*zzy->second);*/
	//system("pause");for (;;);
	return 0;
}


