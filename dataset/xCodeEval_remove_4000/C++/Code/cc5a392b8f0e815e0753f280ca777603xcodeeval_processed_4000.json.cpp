

































using namespace std;




























































typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef vec<pii> vpii;
typedef vec<pdd> vpdd;

using __gnu_cxx::rope;


template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};

template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_mapped_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};


int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type& b){rtn mp(a.x/b,a.y/b);}
template<typename type>inline pr<type,type>& operator-=(pr<type,type>& a,const pr<type,type>& b){rtn a=a-b;}
template<typename type>inline pr<type,type>& operator+=(pr<type,type>& a,const pr<type,type>& b){rtn a=a+b;}
template<typename type>inline pr<type,type>& operator*=(pr<type,type>& a,const type& b){rtn a=a*b;}
template<typename type>inline pr<type,type>& operator/=(pr<type,type>& a,const type& b){rtn a=a/b;}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.y-a.y*b.x;}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.x+a.y*b.y;}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type id3(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;



namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace MinCostMaxFlow
{

const lli oo=0x7f7f7f7f7f7f7f7fll;
const int MAXE=1000000;
const int MAXV=10000;
typedef lli flow_type;
typedef lli cost_type;
typedef struct struct_edge* edge;
struct struct_edge{int v;flow_type c;cost_type d;edge n,b;}pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
void build_graph(int s,int t)
{
	top=pool,clr(adj);
	S=s,T=t;

	

}
void add_edge(int u,int v,flow_type c,cost_type d)
{
	top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
	if (u==v) adj[u]->n->b=adj[u],adj[v]->b=adj[v]->n;

}
cost_type d[MAXV];
int q[MAXV];
bool inq[MAXV];
int qh,qt;
edge p[MAXV];
void id1(flow_type& flow,cost_type& cost)
{
	flow=0,cost=0;
	lp
	{
		fl(d,oo),inq[q[qh=qt=0]=S]=true,d[S]=0,p[S]=0;
		whl(qh<=qt)
		{
			int u=q[(qh++)%MAXV];
			inq[u]=false;
			for (edge i=adj[u];i;i=i->n)
				if (i->c&&cmin(d[i->v],d[u]+i->d))
				{
					p[i->v]=i;
					if (!inq[i->v]) inq[q[(++qt)%MAXV]=i->v]=true;
				}
		}
		if (d[T]==oo) break;
		else
		{
			flow_type delta=oo;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta,cost+=delta*i->d;
			flow+=delta;
		}
	}
}
int V=MAXV;
cost_type h[MAXV];
void id2(flow_type& flow,cost_type& cost,bool id0=true)
{
	flow=0,cost=0;
	if (id0)
	{
		fl(h,oo),fl(inq,false),qh=0,qt=-1;
		rep(i,V) h[i]=0,q[++qt]=i,inq[i]=true;
		whl(qh<=qt)
		{
			int u=q[(qh++)%MAXV];
			inq[u]=false;
			for (edge i=adj[u];i;i=i->n)
				if (i->c&&cmin(h[i->v],h[u]+i->d))
				{
					p[i->v]=i;
					if (!inq[i->v]) inq[q[(++qt)%MAXV]=i->v]=true;
				}
		}
	}
	else clr(h);
	lp
	{
		fl(d,oo),fl(inq,false);
		prq<pr<cost_type,int> > Q;
		d[S]=0,p[S]=0,Q.push(mp(-d[S],S));
		whl(sz(Q))
		{
			int u=Q.top().y;
			Q.pop();
			if (!inq[u])
			{
				inq[u]=true;
				for (edge i=adj[u];i;i=i->n)
				{
					if (i->c&&!inq[i->v]&&cmin(d[i->v],d[u]+i->d+h[u]-h[i->v]))
						p[i->v]=i,Q.push(mp(-d[i->v],i->v));
				}
			}
		}
		if (d[T]==oo) break;
		else
		{
			flow_type delta=oo;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta,cost+=delta*i->d;
			flow+=delta;
			rep(i,V) h[i]+=d[i];
		}
	}
}

}
}
}
using namespace StandardCodeLibrary::GraphTheory::MinCostMaxFlow;

int main()
{
	inf=1e8;
	int n;
	cin>>n;
	vpii p(n);
	rep(i,n) cin>>p[i];
	int maxy=-::oo,cnt=0;
	rep(i,n) cmax(maxy,p[i].y);
	rep(i,n) if (p[i].y==maxy) cnt++;
	if (cnt!=1) cout<<-1<<endl;
	else
	{
		build_graph(n+n,n+n+1);
		rep(i,n)
		{
			add_edge(S,i,2,0);
			rep(j,n) if (p[j].y<p[i].y) add_edge(i,n+j,1,sqrt(sqr(p[i].x-p[j].x)+sqr(p[j].y-p[i].y))*inf);
			add_edge(n+i,T,1,0);
		}
		lli flow,cost;
		

		id2(flow,cost,false);
		prt(flow);
		if (flow!=n-1) cout<<-1<<endl;
		else pdb(100,db(cost)/inf)<<endl;
	}
}
