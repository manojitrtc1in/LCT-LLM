






























































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


		int m=(l+r+inf+inf>>1)-inf;
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
		int m=(l+r+inf+inf>>1)-inf;

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
		int m=(l+r+inf+inf>>1)-inf,res=inf;

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
		int m=(l+r+inf+inf>>1)-inf,res=-inf;

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
		int m=(l+r+inf+inf>>1)-inf,res=0;

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

int a[1000005],p[1000005],q[1000005],g[1000005];
int Ld,Rd;




    

    

    







    

    

    













	

    

    

    

        

        

        

    

    

    

    

    







    

    

    

    

    

    







	

	

	

	

	







	

	





int s(int l,int r)
{
	int val=q[r]-q[l-1];
	if(l&1)return val;
	return -val;
}

int solve(int pos,int n,int val,int endpos)
{
	if(endpos<pos)return 0;
	int ret=0;
	if(pos&1)
	{
		int t=val+q[pos-1]-p[n];
		

		if(endpos+pos&1);else endpos--;
		int l=pos+1>>1,r=endpos>>1,ans=l-1,s=l;
		

		while(l<=r)
		{
			int m=l+r>>1;
			int i=m*2;
			if(t+1<=q[i]-p[i])ans=m,l=m+1;
			else r=m-1;
		}
		int d=0;
		ret=ans-s+1;
		

	}
	else
	{
		int t=val-q[pos-1]-p[n];
		

		

		if(endpos+pos&1);else endpos--;
		int l=pos+1>>1,r=endpos-1>>1,ans=l-1,s=l;
		

		while(l<=r)
		{
			int m=l+r>>1;
			int i=m*2+1;
			if(t+1<=-q[i]-p[i])ans=m,l=m+1;
			else r=m-1;
		}
		ret=ans-s+1;
		int d=0;
		for(int i=pos+1;i<=endpos;i+=2)if(t<-q[i]-p[i])d=i;
		



		

		

			

			

			

			

			

		

		

	}
	

		

	return ret;
}

signed main()
{
	initprog();
	int T=read();rg(T)
	int n=read();rg(n)a[i]=read();p[i]=p[i-1]+a[i],q[i]=q[i-1]+((i&1)?a[i]:-a[i]);Rd+=a[i]*2;gr
	

	Ld=-Rd-1;
	rg(n)g[i]=q[i]-p[i];gr
	

	

	

	

	



	



	int ans=0;
	

	

	for(int i=1;i<=n;i++)if(p[i]<p[n]-p[i])ans++;
	for(int i=1;i<=n-1;i++)if(p[i]+a[n]<p[n]-p[i]-a[n])ans++;
	if(n>2&&p[n-2]+a[n]<a[n-1])ans--,odl(-1);
	

	oldl(ans%998244353);
	

	0;
	oldl(ans%998244353);
	

	for(int i=1;i+2<=n;i++)
	{
		ans+=solve(i+1,n,p[i],n);
	}
	oldl(ans%998244353);
	for(int i=1;i+2<=n;i++)
	{
		ans+=solve(i+1,n-1,p[i]+a[n],n-3);
	}
	oldl(ans%998244353);
	

	

	for(int i=1;i<=n;i++)if(p[i]>p[n]-p[i])ans++;
	oldl(ans%998244353);
	

	for(int i=2;i+2<=n;i++)
	{
		ans+=solve(i+1,n,p[i]-p[1]-p[1],n-1);
	}
	for(int i=2;i+2<=n-1;i++)
	{
		ans+=solve(i+1,n-1,p[i]-p[1]-p[1]+a[n],n-2);
	}
	oldl(ans%998244353);
	
	for(int i=2;i<n;i++)if(p[i]-p[1]<p[n]-p[i]+p[1])ans++;
	oldl(ans%998244353);	
	for(int i=2;i<n-1;i++)
		if(a[n]+p[i]-a[1]<p[n-1]-p[i]+a[1])ans++;



	oldl(ans%998244353);
	

	

	

	

	
	

	

	

	

	

	gr
	return 0;
}
