































template<typename T>
void print(T x){}
template<>
void print<int>(int x){od(x);}
template<>
void print<const int>(const int x){od(x);}
template<>
void print<long long>(long long x){old(x);}
template<>
void print<const long long>(const long long x){old(x);}
template<>
void print<char>(char x){putchar(x);}
template<>
void print<const char>(const char x){putchar(x);}
template<>
void print<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void print(T x,qwq ...args)
{
	print(x);
	print(args...);
}

template<typename T>
void debug(T x){}
template<>
void debug<int>(int x){od(x);}
template<>
void debug<const int>(const int x){od(x);}
template<>
void debug<long long>(long long x){old(x);}
template<>
void debug<const long long>(const long long x){old(x);}
template<>
void debug<char>(char x){putchar(x);}
template<>
void debug<const char>(const char x){putchar(x);}
template<>
void debug<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	debug(x);
	debug(args...);
}



template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	
}



const int mod=998244353;





inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}



class SegTreeAl{

	int minn[1000005<<2];


	int maxn[1000005<<2];


	int sum[1000005<<2];

	int tag[1000005<<2];

	void pushdown(int o,int l,int r)

	void pushdown(int o)

	{
		int&t=tag[o];

		minn[o<<1]+=t;
		minn[o<<1|1]+=t;


		maxn[o<<1]+=t;
		maxn[o<<1|1]+=t;


		int m=l+r>>1;
		sum[o<<1]+=t*(m-l+1);
		sum[o<<1|1]+=t*(r-m);

		tag[o<<1]+=t;
		tag[o<<1|1]+=t;
		t=0;
	}
	void add(int o,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{

			maxn[o]+=v;


			minn[o]+=v;


			sum[o]+=v*(r-l+1);

			tag[o]+=v;
			return;
		}
		int m=l+r>>1;

		pushdown(o,l,r);

		pushdown(o);

		if(L<=m)add(o<<1,l,m,L,R,v);
		if(m<R)add(o<<1|1,m+1,r,L,R,v);

		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);


		minn[o]=min(minn[o<<1],minn[o<<1|1]);


		sum[o]=sum[o<<1]+sum[o<<1|1];

	}

	int qmin(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return minn[o];
		}
		int m=l+r>>1,res=inf;

		pushdown(o,l,r);

		pushdown(o);

		if(L<=m)res=min(res,qmin(o<<1,l,m,L,R));
		if(m<R)res=min(res,qmin(o<<1|1,m+1,r,L,R));

		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);


		minn[o]=min(minn[o<<1],minn[o<<1|1]);


		sum[o]=sum[o<<1]+sum[o<<1|1];

		return res;
	}



	int qmax(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return maxn[o];
		}
		int m=l+r>>1,res=-inf;

		pushdown(o,l,r);

		pushdown(o);

		if(L<=m)res=max(res,qmax(o<<1,l,m,L,R));
		if(m<R)res=max(res,qmax(o<<1|1,m+1,r,L,R));

		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);


		minn[o]=min(minn[o<<1],minn[o<<1|1]);


		sum[o]=sum[o<<1]+sum[o<<1|1];

		return res;
	}



	int qsum(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			return sum[o];
		}
		int m=l+r>>1,res=0;

		pushdown(o,l,r);

		pushdown(o);

		if(L<=m)res+=qsum(o<<1,l,m,L,R);
		if(m<R)res+=qsum(o<<1|1,m+1,r,L,R);

		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);


		minn[o]=min(minn[o<<1],minn[o<<1|1]);


		sum[o]=sum[o<<1]+sum[o<<1|1];

		return res;
	}

};

typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}\
struct node{\
	int u,d;\
	bool operator<(const node&b)const{return d>b.d;}\
};\
void dij(int s,int *d,int N)\
{\
	memset(d,0x3f,sizeof(int)*(N+3));\
	d[s]=0;std::priority_queue<node>q;q.push((node){s,0});\
	while(!q.empty())\
	{\
		int u=q.top().u,D=q.top().d;q.pop();if(D!=d[u])continue;\
		for(int i=h[u];i;i=e[i].nxt){int v=e[i].v,w=e[i].w;\
		if(d[u]+w<d[v])d[v]=d[u]+w,q.push((node){v,d[v]});\
		}\
	}\
}

inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
{\
    int fx=f(x),fy=f(y);\
    if(fx==fy)return 0;\
    if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    return 1;\
}
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int id0()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}

struct BIT{int a[1<<20|1],n;
void add(int x,int p){while(x<=n)a[x]+=p,x+=x&-x;}
int operator[](int x){int res=0;while(x)res+=a[x],x-=x&-x;return res;}
int operator()(int l,int r){return (*this)[r]-(*this)[l-1];}};

int rnv[1000005];






int fac[1000005],inv[1000005];

void initprog()
{

	fac[0]=inv[0]=inv[1]=1;
	rg(1000000)fac[i]=fac[i-1]*i%mod;gr
	rg(1000000)if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
	rg(1000000)rnv[i]=inv[i];gr
	rg(1000000)inv[i]=inv[i]*inv[i-1]%mod;gr

}

int C(int n,int m)
{
	if(n==m||m==0)return 1;
	if(n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

inline int qp(int a,int b){int c=1;while(b){if(b&1)c=c*a%mod;a=a*a%mod;b>>=1;}return c;}
inline int mae(int &a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int mde(int &a,int b){a+=mod-b;if(a>=mod)a-=mod;return a;}
inline int mle(int &a,int b){a=a*b%mod;return a;}
inline int mve(int &a,int b){a=a*qp(b,mod-2)%mod;return a;}
inline int mxe(int &a,int b){return a=a>b?a:b;}
inline int mne(int &a,int b){return a=a<b?a:b;}
inline int ae(int a,int b){int c=a+b;return c>=mod?c-mod:c;}
inline int de(int a,int b){return ae(a,mod-b);}
inline int me(int a,int b){return a*b%mod;}
inline int mive(int &a,int b){a=a*rnv[b]%mod;return a;}
inline int ive(int a,int b){return a*rnv[b]%mod;}
inline int ve(int a,int b){return a*qp(b,mod-2)%mod;}

struct STmin{
	int a[21][1000005],n;
	void init(int N,int *b)
	{
		n=N;
		rg(n)a[0][i]=b[i];gr
		rg(20)rg_(j,n-(1<<i)+1)a[i][j]=min(a[i-1][j],a[i-1][j+(1<<i-1)]);gr gr
	}
	int q(int l,int r)
	{
		int d=std::__lg(r-l+1);
		return min(a[d][l],a[d][r-(1<<d)+1]);
	}
};
struct STmax{
	int a[21][1000005],n;
	void init(int N,int *b)
	{
		n=N;
		rg(n)a[0][i]=b[i];gr
		rg(20)rg_(j,n-(1<<i)+1)a[i][j]=max(a[i-1][j],a[i-1][j+(1<<i-1)]);gr gr
	}
	int q(int l,int r)
	{
		int d=std::__lg(r-l+1);
		return max(a[d][l],a[d][r-(1<<d)+1]);
	}
};


struct SAM{
	int ch[1000005][26],lnk[1000005],len[1000005],lst=1,cc=1;
	int sz[1000005];
	void insert(int c)
	{
		len[++cc]=len[lst]+1;sz[cc]=1;
		int p=lst;lst=cc;
		while(p&&ch[p][c]==0)ch[p][c]=cc,p=lnk[p];
		if(p==0)lnk[cc]=1;
		else
		{
			int x=ch[p][c];
			if(len[p]+1==len[x])lnk[cc]=x;
			else
			{
				int q=cc;++cc;
				lnk[cc]=lnk[x];
				lnk[x]=lnk[q]=cc;
				len[cc]=len[p]+1;
				memcpy(ch[cc],ch[x],sizeof(ch[cc]));
				while(p&&ch[p][c]==x)ch[p][c]=cc,p=lnk[p];
			}
		}
	}
	newe(1000005);
	long long ans;
	void build()
	{
		rg(cc)addedge(lnk[i],i,0);gr
	}
	void dfs(int u)
	{
		fe(u)dfs(v),sz[u]+=sz[v];gr
		if(sz[u]>1)ans=max(ans,1ll*sz[u]*len[u]);
	}
}t;

int l[1000005],r[1000005];
int L[1000005],R[1000005];
int seg(int x){return sqrt(x);}
signed main()
{
	initprog();
	int n=read();
	rg(n)l[i]=read(),r[i]=l[i];gr
	int ans=inf;
	int p=r[n];
	for(int s=1;s<=p;s++)
	{
		int m=1;L[1]=l[1],R[1]=r[1];
		for(int i=2;i<=n;i++)if(l[i]-R[m]>s)L[++m]=l[i],R[m]=r[i];else R[m]=r[i];
		n=m;rg(n)l[i]=L[i],r[i]=R[i];gr
		if(r[1]>s*s+s)continue;
		int Ls=max(l[1],s*s),Rs=s*s+s;
		int ok=1;
		int dl=Ls-l[1],dr=Rs-r[1];
		int mn=inf,mx=0;
		rg(n)
		int minl=l[i]+dl,maxl=l[i]+dr,
		minr=r[i]+dl,maxr=r[i]+dr;
		if(seg(maxl)<seg(minr))ok=0;
		else
		{
			int s=seg(maxl);
			int sl=minl,sr=minr;
			int dl=max(0,s*s-sl);
			int dr=s*s+s-sr;
			mne(mn,dr);
			mxe(mx,dl);
			

		}
		gr
		if(mn>=mx&&ok)ans=min(ans,mx+dl);
	}
	oldl(ans);
	return 0;
}