
































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

template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};

template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_mapped_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};


int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gamma=0.5772156649015328606;
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
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;


namespace StandardCodeLibrary
{
namespace StringAlgorithms
{



void get_pi(const vi t,vi& pi)
{
	pi.resize(sz(t)),pi[0]=-1;
	int j=-1;
	repf(i,1,sz(t))
	{
		whl(j!=-1&&t[j+1]!=t[i]) j=pi[j];
		if (t[j+1]==t[i]) j++;
		pi[i]=j;
	}
}
void get_match(const vi& t,const vi& pi,const vi& s,vi& match)
{
	int j=-1;
	rep(i,sz(s))
	{
		whl(j!=-1&&t[j+1]!=s[i]) j=pi[j];
		if (t[j+1]==s[i]) j++;
		if (j==sz(t)-1)
		{
			match.pb(i-j);
			j=pi[j];
		}
	}
}
int KMP(const vi& t,const vi& s)
{
	vi pi;
	get_pi(t,pi);
	vi match;
	get_match(t,pi,s,match);
	if (sz(match)) rtn match.front();
	else rtn -1;
}



void get_ext(const vi& t,vi& ext)
{
	ext.resize(sz(t)),ext[0]=sz(t);
	if (sz(t)==1) rtn;
	int j=0,a=1;
	whl(1+j<sz(t)&&t[1+j]==t[j]) j++;
	ext[1]=j;
	repf(i,2,sz(t))
	{
		if (i+ext[i-a]<a+ext[a]) ext[i]=ext[i-a];
		else
		{
			j=max(a+ext[a]-i,0);
			whl(i+j<sz(t)&&t[i+j]==t[j]) j++;
			ext[a=i]=j;
		}
	}
}
void get_extend(const vi& t,const vi& ext,const vi& s,vi& extend)
{
	extend.resize(sz(s));
	int j=0,a=0;
	whl(j<sz(s)&&j<sz(t)&&s[j]==t[j]) j++;
	extend[0]=j;
	repf(i,1,sz(s))
	{
		if (i+ext[i-a]<a+extend[a]) extend[i]=ext[i-a];
		else
		{
			j=max(a+extend[a]-i,0);
			whl(i+j<sz(s)&&j<sz(t)&&s[i+j]==t[j]) j++;
			extend[a=i]=j;
		}
	}
}



void id2(const vi& str,vi& ans_str,int split=0)
{
	vi S;
	rep(i,sz(str)) S.pb(split),S.pb(str[i]);
	S.pb(split);
	vi p(sz(S));
	int ans,ansi,mid;
	ans=(p[mid=0]=1)-1;
	repf(i,1,sz(S))
	{
	    p[i]=p[mid]+mid>i?min(p[mid]+mid-i,p[mid*2-i]):1;
	    whl(i>=p[i]&&i+p[i]<sz(S)&&S[i-p[i]]==S[i+p[i]]) p[i]++;
	    if (cmax(ans,p[i]-1)) ansi=i;
	    if (p[i]+i>p[mid]+mid) mid=i;
	}
	ans_str.clear();
	ft(i,ansi-ans,ansi+ans)
		if (S[i]!=split) ans_str.pb(S[i]);
}

}
}


namespace StandardCodeLibrary
{
namespace StringAlgorithms
{
namespace AhoCorasickAlgorithm
{

const int MAXNODE=2000000;
const int id0=26;
typedef bool info;
struct struct_node{struct_node* n[id0];struct_node* f;info i;int v;};
typedef struct_node* node;
struct_node pool[MAXNODE];
node top;
int cnt;

struct Initializer{Initializer(){top=pool,clr(pool);}}initializer;

class id1
{
	node rt;
	virtual void update(info&,const info&)=0;
	virtual void calculate(const info&)=0;
public:
	id1():rt(top++){}
	void insert(vi s,const info& i)
	{
		node u=rt;
		rep(i,sz(s))
		{
			if (!u->n[s[i]]) u->n[s[i]]=top++;
			u=u->n[s[i]];
		}
		update(u->i,i);
	}
	void build()
	{
		que<node> q;
		rt->f=rt,q.push(rt);
		whl(sz(q))
		{
			node u=q.front();
			q.pop();
			rep(c,id0) if (u->n[c])
			{
				if (u==rt) u->n[c]->f=rt;
				else
				{
					node v=u->f;
					whl(v!=rt&&!v->n[c]) v=v->f;
					if (v->n[c]) v=v->n[c];
					u->n[c]->f=v;
				}
				q.push(u->n[c]);
			}
		}
	}
	void query(vi s)
	{
		cnt++;
		node u=rt;
		rep(i,sz(s))
		{
			whl(u!=rt&&!u->n[s[i]]) u=u->f;
			if (u->n[s[i]]) u=u->n[s[i]];
			node v=u;
			whl(v!=rt&&v->v!=cnt)
				calculate(v->i),v->v=cnt,v=v->f;
		}
	}
};

}
}
}

using namespace StandardCodeLibrary::StringAlgorithms;
using namespace StandardCodeLibrary::StringAlgorithms::AhoCorasickAlgorithm;

struct AC:id1
{
	void update(info&,const info&)
	{
	}
	void calculate(const info&)
	{
	}
};

void read(vi& s)
{
	str t;
	cin>>t;
	s.resize(sz(t));
	rep(i,sz(s)) s[i]=t[i]-'a';
}

int dfs(node u,const vi& pi,const vi& e,int pj,int rest)
{
	rest--;
	int ans=0;
	rep(si,id0)
		if (u->n[si])
		{
			int j=pj;
			whl(j!=-1&&e[j+1]!=si) j=pi[j];
			if (e[j+1]==si) j++;
			if (j==sz(e)-1) ans+=rest<=0,j=pi[j];
			ans+=dfs(u->n[si],pi,e,j,rest);
		}
	rtn ans;
}

int main()
{
	vi s,b,e;
	read(s),read(b),read(e);
	vi bpi,epi,mat;
	get_pi(b,bpi),get_pi(e,epi);
	get_match(b,bpi,s,mat);
	AC ac;
	rep(i,sz(mat)) ac.insert(vi(s.begin()+mat[i],s.end()),true);
	cout<<dfs(pool,epi,e,-1,sz(b))<<endl;
}