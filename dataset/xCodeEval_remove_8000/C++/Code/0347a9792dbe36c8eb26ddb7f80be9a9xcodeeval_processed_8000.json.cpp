

















                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    

using namespace std;









	namespace Fread{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}}namespace Fwrite{const int SIZE=1<<16;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}
    
	











using namespace __gnu_pbds;


namespace Fastio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();short f=1;while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}x*=f;return *this;}Reader&operator>>(double&x){char c=getchar();short f=1,s=0;x=0;double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(long double&x){char c=getchar();short f=1,s=0;x=0;long double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(__float128&x){char c=getchar();short f=1,s=0;x=0;__float128 t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(char&c){c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();return *this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(std::string&str){char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{typedef __int128 mxdouble;template<typename T>Writer&operator<<(T x){if(x==0)return putchar('0'),*this;if(x<0)putchar('-'),x=-x;static int sta[45];int top=0;while(x)sta[++top]=x%10,x/=10;while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(long double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(__float128 x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return *this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(std::string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}











                                                                    
                                                                    
                                                                    
                                                                    




int qp(int x,int n=p-2,int P=p){int r=1;while(n){if(n&1)r=r*x%P;x=x*x%P,n>>=1;}return r;}


int fac[maxw+100],ifac[maxw+100];
void init(int n,int P=p){fac[0]=1;for(int x=1;x<=n;x++)fac[x]=fac[x-1]*x%P;ifac[n]=qp(fac[n],P-2,P);for(int x=n;x>=1;x--)ifac[x-1]=ifac[x]*x%P;}
int C(int x,int y,int P=p){if(x<y||y<0)return 0;return fac[x]*ifac[y]%P*ifac[x-y]%P;}
int iC(int x,int y,int P=p){if(x<y||y<0)return 0;return ifac[x]*fac[y]%P*fac[x-y]%P;}
int inv(int x,int P=p){return iC(x,1,P);}


template <uint32_t mod>
struct id4 {
	using mint = id4;
	using i32 = int32_t;
	using u32 = uint32_t;
	using u64 = uint64_t;
	static constexpr u32 get_r() {
		u32 ret = mod;
		for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
		return ret;
	}
	static constexpr u32 r = get_r();
	static constexpr u32 n2 = -u64(mod) % mod;
	static_assert(r * mod == 1, "invalid, r * mod != 1");
	static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
	static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");
	u32 a;
	constexpr id4() : a(0) {}
	constexpr id4(const int64_t &b)
			: a(reduce(u64(b % mod + mod) * n2)){};
	static constexpr u32 reduce(const u64 &b) {
		return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
	}
	constexpr mint &operator+=(const mint &b) {
		if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
		return *this;
	}
	constexpr mint &operator-=(const mint &b) {
		if (i32(a -= b.a) < 0) a += 2 * mod;
		return *this;
	}
	constexpr mint &operator*=(const mint &b) {
		a = reduce(u64(a) * b.a);
		return *this;
	}
	constexpr mint &operator/=(const mint &b) {
		*this *= b.inverse();
		return *this;
	}
	constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
	constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
	constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
	constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
	constexpr bool operator==(const mint &b) const {
		return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
	}
	constexpr bool operator!=(const mint &b) const {
		return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
	}
	constexpr mint operator-() const { return mint() - mint(*this); }
	constexpr mint pow(u64 n) const {
		mint ret(1), mul(*this);
		while (n > 0) {
			if (n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}
	constexpr mint inverse() const { return pow(mod - 2); }
	friend ostream &operator<<(ostream &os, const mint &b) {
		return os << b.get();
	}
	friend istream &operator>>(istream &is, mint &b) {
		int64_t t;
		is >> t;
		b = id4<mod>(t);
		return (is);
	}
	constexpr u32 get() const {
		u32 ret = reduce(a);
		return ret >= mod ? ret - mod : ret;
	}
	static constexpr u32 get_mod() { return mod; }
    operator u32() const {return get();}
};



template<int nn,int ...ns>struct BIT;
template<int nn,int U,int ...ns>
struct BIT<nn,U,ns...>
{
    BIT<nn-1,ns...> BITT[U+10];
    void clear(){for(int x=0;x<U+10;x++)BITT[x].clear();}
    BIT(){clear();}
    template<typename T1,typename ...Tn>
    void add(const T1& n,const Tn& ...tn){for(int x=n+3;x<=U+5;x+=x&-x)BITT[x].add(tn...);}
    template<typename T1,typename ...Tn>
    int query(const T1& n,const Tn& ...tn){int r=0;for(int x=n+3;x;x-=x&-x)r+=BITT[x].query(tn...);return r;}
    template<typename T1,typename ...Tn>
    int querylr(const T1& L,const T1& R,const Tn& ...tn){int r=0;for(int x=R+3;x;x-=x&-x)r+=BITT[x].querylr(tn...);for(int x=L+2;x;x-=x&-x)r-=BITT[x].querylr(tn...);return r;}
};
template<>
struct BIT<0>
{
    int val;
    void clear(){val=0;}
    BIT(){clear();}
    void add(int u){val+=u;}
    int query(){return val;}
    int querylr(){return val;}
};
template<int nn,int ...ns>struct BITex;
template<int nn,int U,int ...ns>
struct BITex<nn,U,ns...>
{
    BITex<nn-1,ns...> BITT[U+10],BITT2[U+10];
    void clear(){for(int x=0;x<U+10;x++)BITT[x].clear(),BITT2[x].clear();}
    BITex(){clear();}
    template<typename T1,typename ...Tn>
    void add(const T1&u,const T1& L,const T1& R,const Tn& ...tn)
	{
		int l=L+3,r=R+3;
		for(int x=l;x<=U+5;x+=x&-x)BITT[x].add(u,tn...),BITT2[x].add(l*u,tn...);
		for(int x=r+1;x<=U+5;x+=x&-x)BITT[x].add(-u,tn...),BITT2[x].add(-(r+1)*u,tn...);
	}
    template<typename T1,typename ...Tn>
    int query(const T1& L,const T1& R,const Tn& ...tn)
	{
		int res=0;
		int l=L+3,r=R+3;
		int now=0;
		for(int x=r;x;x-=x&-x)now+=BITT[x].query(tn...),res-=BITT2[x].query(tn...);
		res+=(r+1)*now;
		now=0;
		for(int x=l-1;x;x-=x&-x)now+=BITT[x].query(tn...),res+=BITT2[x].query(tn...);
		res-=l*now;
		return res;
	}
};
template<>
struct BITex<0>
{
    int val;
    void clear(){val=0;}
    BITex(){clear();}
    void add(int u){val+=u;}
    int query(){return val;}
};



	void buildd(int num,int le,int ri)\
    {\
        if(le==ri){tre[num]=a[le];return;}\
        int mid=(le+ri)/2;\
        buildd(num*2,le,mid);\
        buildd(num*2+1,mid+1,ri);\
        tre[num]=tre[num*2]+tre[num*2+1];\
    }
struct id3{
    int tre[N*4],laz[N*4],a[N],n;
    builddd
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        memset(laz,0,sizeof(laz));
        buildd(1,1,n);
    }
    id3(int nn,int *A){build(nn,A);}
    void pushdown(int num,int le,int ri)
    {
    	int mid=(le+ri)/2;
        if(laz[num]!=0)tre[num*2]+=laz[num]*(mid-le+1),tre[num*2+1]+=laz[num]*(ri-mid),laz[num*2]+=laz[num],laz[num*2+1]+=laz[num],laz[num]=0;
    }
    void update(int num,int le,int ri,int x,int y,int k)
    {
        if(x<=le&&y>=ri){tre[num]+=k*(ri-le+1);laz[num]+=k;return;}
        tre[num]+=max(0ll,k*(min(ri,y)-max(le,x)+1));
        pushdown(num,le,ri);
        int mid=(le+ri)/2;
        if(x<=mid)update(num*2,le,mid,x,y,k);
        if(y>mid)update(num*2+1,mid+1,ri,x,y,k);
    }
    void update(int x,int y,int k=1){update(1,1,n,x,y,k);}
    int query(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return tre[num];
        pushdown(num,le,ri);
        int mid=(le+ri)/2;
        int ans=0;
        if(x<=mid)ans+=query(num*2,le,mid,x,y);
        if(y>mid)ans+=query(num*2+1,mid+1,ri,x,y);
        return ans;
    }
    int query(int x,int y){return query(1,1,n,x,y);}
};

    void update(int num,int le,int ri,int x,int y)\
    {\
        if(le==ri){tre[num]+=y;return;}\
        int mid=(le+ri)/2;\
        if(x<=mid)update(num*2,le,mid,x,y);\
        else update(num*2+1,mid+1,ri,x,y);\
        tre[num]=tre[num*2]+tre[num*2+1];\
    }\
    void update(int x,int k=1){update(1,1,n,x,k);}\
    int query(int num,int le,int ri,int x,int y)\
    {\
        if(x<=le&&y>=ri)return tre[num];\
        int mid=(le+ri)/2;\
        int ans=0;\
        if(x<=mid)ans+=query(num*2,le,mid,x,y);\
        if(y>mid)ans+=query(num*2+1,mid+1,ri,x,y);\
        return ans;\
    }\
    int query(int x,int y){return query(1,1,n,x,y);}
struct id0{
    int tre[N*4],a[N],n;
    builddd
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        buildd(1,1,n);
    }
    id0(int nn,int *A){build(nn,A);}
    update_querysum
};
struct id1{
    int tre[N*4],a[N],n,Max[N*4],Min[N*4];
    void buildd(int num,int le,int ri)
    {
        if(le==ri){tre[num]=Max[num]=Min[num]=a[le];return;}
        int mid=(le+ri)/2;
        buildd(num*2,le,mid);
        buildd(num*2+1,mid+1,ri);
        tre[num]=tre[num*2]+tre[num*2+1];
        Max[num]=max(Max[num*2],Max[num*2+1]);
        Min[num]=min(Min[num*2],Min[num*2+1]);
    }
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        memset(Max,0,sizeof(Max));
        memset(Min,0,sizeof(Min));
        buildd(1,1,n);
    }
    id1(int nn,int *A){build(nn,A);}
    update_querysum
    int query_max(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return Max[num];
        int mid=(le+ri)/2;
        int ans=-10000000000;
        if(x<=mid)ans=max(ans,query_max(num*2,le,mid,x,y));
        if(y>mid)ans=max(ans,query_max(num*2+1,mid+1,ri,x,y));
        return ans;
    }
    int query_max(int x,int y){return query_max(1,1,n,x,y);}
    int query_min(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return Min[num];
        int mid=(le+ri)/2;
        int ans=10000000000;
        if(x<=mid)ans=min(ans,query_min(num*2,le,mid,x,y));
        if(y>mid)ans=min(ans,query_min(num*2+1,mid+1,ri,x,y));
        return ans;
    }
    int query_min(int x,int y){return query_min(1,1,n,x,y);}
};




templ inline Type1 min(Type1 x, Type2 y) { return mymin(x,y); }
templ inline Type1 max(Type1 x, Type2 y) { return mymax(x,y); }


templ inline Type1 min(Type1 x, Type2 y, Args... args) { return min(min(x, y), args...); }
templ inline Type1 max(Type1 x, Type2 y, Args... args) { return max(max(x, y), args...); }




bitset<maxw+10>ck;
int pe[maxw+10];


struct DINIC{
	
	const int MAXN=qpqpqpqp;
    const int inf=2147483647;
	vector<long long>Stream,S2;
	int Arc[qpqpqpqp],Deep[qpqpqpqp];
	vector< pair<int,int> >Edge[qpqpqpqp];
    vector<array<int,3>>ee;
	inline bool Bfs(int Start,int End)
	{
	    queue<int>Queue;
	    memset(Deep,0,sizeof(Deep));
	    Queue.push(Start);
	    Deep[Start]=1;
	    int i;
	    while(!Queue.empty())
	    {
	        int Top;
	        Top=Queue.front();
	        Queue.pop();
	        for(i=0;i<Edge[Top].size();i++)
	        {
	            if(!Deep[Edge[Top][i].first]&&Stream[Edge[Top][i].second])
	            {
	                Deep[Edge[Top][i].first]=Deep[Top]+1;
	                Queue.push(Edge[Top][i].first);
	                if(Edge[Top][i].first==End)
	                {
	                    return true;
	                }
	            }
	        }
	    }
	    return false;
	}
	inline long long Dfs(int Now,int End,long long Min)
	{
	    if(Now==End)
	    {
	        return Min;
	    }
	    for(int &i=Arc[Now];i<Edge[Now].size();i++)
	    {
	        int U,V;
	        U=Edge[Now][i].first;
	        V=Edge[Now][i].second;
	        if(Deep[U]==Deep[Now]+1&&Stream[V])
	        {
	            int MinStream=0;
	            MinStream=min(Min,Dfs(U,End,min(Min,Stream[V])));
	            if(!MinStream)
	            {
	                continue;
	            }
	            Stream[V]-=MinStream;
	            Stream[V^1]+=MinStream;
	            return MinStream;
	        }
	    }
	    return 0;
	}
	inline long long Dinic(int Start,int End)
	{
	    memset(Arc,0,sizeof(Arc));
	    memset(Deep,0,sizeof(Deep));
	    long long Return;
	    Return=0;
	    long long Delta;
	    while(Bfs(Start,End))
	    {
	        memset(Arc,0,sizeof(Arc));
	        while(Delta=Dfs(Start,End,inf))
	        {
	            Return+=Delta;
	        }
	    }
	    return Return;
	}
	int Count=0;
    void addedge(int u,int v,int w=1)
    {
		Stream.push_back(w);
		S2.push_back(0);
        ee.push_back({u,v,w});
		Edge[u].push_back(pair<int,int>(v,Count));
		++Count;
    }
	void add_edge(int u,int v,int w=1)
	{
        addedge(u,v,w);
        addedge(v,u,0);
	}
    void init()
    {
        Stream.clear();
        S2.clear();
        memset(Arc,0,sizeof(Arc));
        memset(Deep,0,sizeof(Deep));
        for(int x=0;x<MAXN;x++)
        {
            vector<pair<int,int>>pp;
            swap(Edge[x],pp);
        }
	    Count=0;
    }
    DINIC(){init();}
    void fill(DINIC a)
    {
        Stream=a.Stream;
        S2=a.S2;
        memset(Arc,0,sizeof(Arc));
        memset(Deep,0,sizeof(Deep));
        for(int x=0;x<MAXN;x++)
        {
            Arc[x]=a.Arc[x];
            Deep[x]=a.Deep[x];
            Edge[x]=a.Edge[x];
        }
	    Count=a.Count;
    }
    
};


struct id5{
	
	const int MAXN=qpqpqpqp;
    const int inf=2147483647;
	int dis[qpqpqpqp],flow[qpqpqpqp],exist[qpqpqpqp];
	int pre[qpqpqpqp],preedge[qpqpqpqp];
	struct Edge
	{
	    int next,to,flow,dis;
	};
	vector<Edge>edge; int head[qpqpqpqp],cnt;
	void init()
	{
		memset(pre,0,sizeof(pre));
		memset(preedge,0,sizeof(preedge));
		memset(head,0,sizeof(head));
		cnt=1;
		edge.clear();
		edge.resize(2);
	}
	id5(){init();}
	void addedge(int from,int to,int flow,int dis)
	{
		edge.push_back({head[from],to,flow,dis});
		cnt++;
	    head[from]=cnt;
	}
	void add_edge(int from,int to,int flow,int dis)
	{
	    addedge(from,to,flow,dis);
	    addedge(to,from,0,-dis);
	}
	bool spfa(int s,int t)
	{
	    fill(dis,dis+MAXN,inf);
	    fill(flow,flow+MAXN,inf);
	    memset(exist,0,sizeof(exist));
	    queue<int> q;
	    pre[t]=-1; exist[s]=1; dis[s]=0; q.push(s);
	    while(!q.empty())
	    {
	        int u=q.front();q.pop();exist[u]=0;
	        for(int i=head[u];i;i=edge[i].next)
	        {
	            int v=edge[i].to;
	            if(edge[i].flow>0&&dis[v]>dis[u]+edge[i].dis)
	            {
	                dis[v]=dis[u]+edge[i].dis;
	                flow[v]=min(edge[i].flow,flow[u]);
	                pre[v]=u;
	                preedge[v]=i;
	                if(!exist[v])
	                {
	                    exist[v]=1;
	                    q.push(v);
	                }
	            }
	        }
	    }
	    return pre[t]!=-1;
	}
	pair<int,int>Mcmf(int s,int t)
	{
	    int ret=0,ans=0;
	    while(spfa(s,t))
	    {
	        ret += flow[t] * dis[t];
	        int now = t;
	        while(now!=s)
	        {
	            edge[preedge[now]].flow -= flow[t];
	            edge[preedge[now]^1].flow += flow[t];
                

                if(edge[preedge[now]].to==t)ans+=flow[t];
	            now=pre[now];
	        }
	    }
        return {ans,ret};
	}
	
};


const int gcd_maxw=maxw,gcd_sqr=sqrt(gcd_maxw);
int gcd_fac[gcd_maxw+10][3];
bool isp[gcd_maxw + 10];
int pri[gcd_maxw+10], tot;
int pre[gcd_sqr+10][gcd_sqr+10];
int gcd(int a, int b) {
  int ans = 1;
  for (int i = 0; i < 3; ++i) {
    int tmp = (gcd_fac[a][i] > gcd_sqr) ?
                (b % gcd_fac[a][i] ?
                   1
                 : gcd_fac[a][i]
                )
              : pre[gcd_fac[a][i]][b % gcd_fac[a][i]];
    b /= tmp;
    ans *= tmp;
  }
  return ans;
}


int phi[maxw+10];



template<size_t len>
struct fast_bitset
{
	typedef unsigned long long u64;
	typedef u64 u256 __attribute((vector_size(32)));
	static constexpr size_t ulen=(len-1)/64+1,vlen=(ulen-1)/4+1;
	u256 v[vlen];
	bs(){memset(v,0,sizeof v);}
	bool operator[](size_t ind){return v[ind/256][ind%256/64]>>ind%64&1;}
	void set(size_t ind){v[ind/256][ind%256/64]|=1ull<<ind%64;}
	void reset(size_t ind){v[ind/256][ind%256/64]&=~(1ull<<ind%64);}
	void flip(size_t ind){v[ind/256][ind%256/64]^=1ull<<ind%64;}
	bs&operator^=(const bs&rhs){for(size_t i=0;i<vlen;i++)v[i]^=rhs.v[i];return*this;}
	bs&operator|=(const bs&rhs){for(size_t i=0;i<vlen;i++)v[i]|=rhs.v[i];return*this;}
	bs&operator&=(const bs&rhs){for(size_t i=0;i<vlen;i++)v[i]&=rhs.v[i];return*this;}
	u64 count(){u64 s=0;for(size_t i=0;i<vlen;i++)s+=__builtin_popcountll(v[i][0])+__builtin_popcountll(v[i][1])+__builtin_popcountll(v[i][2])+__builtin_popcountll(v[i][3]);return s;}
};
template<size_t len>bs<len> operator^(const bs<len>&a,const bs<len>&b){bs<len>c;for(size_t i=0;i<a.vlen;i++) c.v[i]=a.v[i]^b.v[i];return c;}
template<size_t len>bs<len> operator|(const bs<len>&a,const bs<len>&b){bs<len>c;for(size_t i=0;i<a.vlen;i++) c.v[i]=a.v[i]|b.v[i];return c;}
template<size_t len>bs<len> operator&(const bs<len>&a,const bs<len>&b){bs<len>c;for(size_t i=0;i<a.vlen;i++) c.v[i]=a.v[i]&b.v[i];return c;}





void Init_for_all_task()
{

init(maxw+10);


ck[1]=1;
register int sum=0;
for(register int x=2;x<=maxw;x++)
{
	if(!ck[x])pe[++sum]=x;
	for(register int j=1;j<=sum&&x*pe[j]<=maxw;j++)
	{
		ck[x*pe[j]]=1;
		if(x%pe[j]==0)break;
	}
}


{
  gcd_fac[1][0] = gcd_fac[1][1] = gcd_fac[1][2] = 1;
  for (int i = 2; i <= gcd_maxw; ++i) {
    if (!isp[i]) {
      gcd_fac[i][0] = gcd_fac[i][1] = 1;
      gcd_fac[i][2] = i;
      pri[++tot] = i;
    }
    for (int j = 1; pri[j] * i <= gcd_maxw; ++j) {
      int tmp = pri[j] * i;
      isp[tmp] = true;
      gcd_fac[tmp][0] = gcd_fac[i][0] * pri[j];
      gcd_fac[tmp][1] = gcd_fac[i][1];
      gcd_fac[tmp][2] = gcd_fac[i][2];
      if (gcd_fac[tmp][0] > gcd_fac[tmp][1])swap(gcd_fac[tmp][0],gcd_fac[tmp][1]);
      if (gcd_fac[tmp][1] > gcd_fac[tmp][2])swap(gcd_fac[tmp][1],gcd_fac[tmp][2]);
      if (i % pri[j] == 0)break;
    }
  }
  for (int i = 0; i <= gcd_sqr; ++i) {
    pre[0][i] = pre[i][0] = i;
  }
  for (int i = 1; i <= gcd_sqr; ++i) {
    for (int j = 1; j <= i; ++j) {
      pre[i][j] = pre[j][i] = pre[j][i % j];
    }
  }
}


phi[1]=1;
for(int i=2;i<=maxw;++i) {
if(!ck[i])phi[i]=i-1;
for(int j=1;j<=sum&&i*pe[j]<=maxw;++j) {
	if(i%pe[j]==0){phi[i*pe[j]]=phi[i]*pe[j];break;}
	else phi[i*pe[j]]=phi[i]*phi[pe[j]];
	}
}



}






struct custom_hash{static uint64_t splitmix64(uint64_t x) {x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}size_t operator()(uint64_t x) const {static const uint64_t id2=chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+id2);}};


BIT<1,300001>sum[sl];
int a[300001];
mt19937 mt(1337);
int bas[sl],mo[sl],del[sl];



namespace nz{





void Main(){
















int n,q;
cin>>n>>q;
for(int x=0;x<sl;x++)
bas[x]=x+100000,mo[x]=mt()%bas[x]+10,del[x]=mt()%100000000000+100000;
for(int x=1;x<=n;x++)
{
    cin>>a[x];
    for(int y=0;y<sl;y++)
    sum[y].add(x,(a[x]*bas[y]+del[y])%mo[y]);
}  
while(q--)
{
    int op;
    cin>>op;
    if(op==2)
    {
        int l,r,k;
        cin>>l>>r>>k;
        for(int x=0;x<sl;x++)
        if(sum[x].querylr(l,r)%k!=0){cout<<"NO"<<endl;goto nxt;}
        cout<<"YES"<<endl;
        nxt:;
    }
    else 
    {
        int x,u;
        cin>>x>>u;
        for(int y=0;y<sl;y++)
        sum[y].add(x,-(a[x]*bas[y]+del[y])%mo[y]);
        a[x]=u;
        for(int y=0;y<sl;y++)
        sum[y].add(x,(a[x]*bas[y]+del[y])%mo[y]);
    }
}  

}
}


int32_t main()
{
    Init_for_all_task();

    int t;cin>>t;while(t--)

    nz::Main();
}



