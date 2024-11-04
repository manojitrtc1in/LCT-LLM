

































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
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
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
template<typename type>inline type id6(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.erase(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;



namespace StandardCodeLibrary
{
namespace ComputationalGeometry2D
{



typedef db Number;

typedef pr<Number,Number> Point;

typedef Point Vector;

typedef pr<Point,Point> Segment;

typedef Segment Line;

typedef Segment Halfplane;

typedef vec<Point> Polygon;






using ::sgn;


using ::dbcmp;


using ::dot;
inline
Number dot(const Vector& a,const Vector& b,const Vector& c)
{
	rtn dot(b-a,c-a);
}


using ::cross;
inline
Number cross(const Vector& a,const Vector& b,const Vector& c)
{
	rtn cross(b-a,c-a);
}


inline
Number len(const Vector& v)
{
	rtn sqrt(dot(v,v));
}
inline
Number len(const Segment& s)
{
	rtn len(s.x-s.y);
}


inline
Number dis(const Point& a,const Point& b)
{
	rtn len(b-a);
}





int id4(const Point& p,const Segment& s)
{
	if (sgn(cross(p,s.x,s.y))) rtn 0;
	else rtn sgn(dot(p,s.x,s.y))<=0?1:-1;
}





int id0(const Point& p,const vec<Segment>& e)
{
	rep(i,sz(e)) if (id4(p,e[i])==1) rtn 0;
	bool in=false;
	rep(i,sz(e))
		if ((dbcmp(e[i].x.y,p.y)>0)!=(dbcmp(e[i].y.y,p.y)>0)
			&&dbcmp(p.x,(e[i].y.x-e[i].x.x)/(e[i].y.y-e[i].x.y)*(p.y-e[i].x.y)+e[i].x.x)<0)
			in=!in;
	return in?1:-1;
}





Point intersection(const Line& a,const Line& b)
{
	Vector va=a.y-a.x,vb=b.y-b.x;
	if (!sgn(cross(va,vb))) rtn Point(+inf,+inf);
	else rtn a.x+va*(cross(b.x-a.x,vb)/cross(va,vb));
}



void id1(Polygon& CH,Polygon& PO)
{
	CH.clear();
	srt(PO);
	rep(i,sz(PO))
	{
		whl(sz(CH)>=2&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();

		CH.pb(PO[i]);
	}
	for (int i=sz(PO)-2,t=sz(CH)+1;i>=0;--i)
	{
		whl(sz(CH)>=t&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();

		CH.pb(PO[i]);
	}
	CH.pop_back();
}



bool id5(const Halfplane& a,const Halfplane& b)
{
	Vector u=a.y-a.x,v=b.y-b.x;
	db du=atan2(u.y,u.x),dv=atan2(v.y,v.x);
	if (dbcmp(du,dv)) return dbcmp(du,dv)<0;
	else return sgn(cross(a.x,a.y,b.x))<0;
}
bool id3(const Halfplane& a,const Halfplane& b,const Halfplane& c)
{
	Vector u=a.y-a.x,v=b.y-b.x;
	db du=atan2(u.y,u.x),dv=atan2(v.y,v.x);
	if (dbcmp(du,dv))
	{
		if (sgn(cross(a.y-a.x,b.y-b.x)))
		{
			Point ab=intersection(a,b);
			return sgn(cross(c.x,c.y,ab))<=0;

		}
		else return false;
	}
	else return true;
}
bool id2(Polygon& CH,vec<Halfplane>& AHP,vec<Halfplane> HP)
{
	HP.pb(Halfplane(Point(-inf,-inf),Point(+inf,-inf))),
	HP.pb(Halfplane(Point(+inf,-inf),Point(+inf,+inf))),
	HP.pb(Halfplane(Point(+inf,+inf),Point(-inf,+inf))),
	HP.pb(Halfplane(Point(-inf,+inf),Point(-inf,-inf)));
	sort(all(HP),id5);
	deque<Halfplane> q;
	q.pb(HP.front());
	repf(i,1,sz(HP))
	{
		Halfplane t;
		do t=q.back(),q.pop_back();
		whl(sz(q)&&id3(q.back(),t,HP[i]));
		q.pb(t);
		do t=q.front(),q.pop_front();
		whl(sz(q)&&id3(q.front(),t,HP[i]));
		q.push_front(t);
		q.pb(HP[i]);
	}
	Halfplane t;
	do t=q.back(),q.pop_back();
	whl(sz(q)&&id3(q.back(),t,q.front()));
	q.pb(t);
	if (sz(q)<3) return false;
	else
	{
		CH.resize(sz(q)),AHP.resize(sz(q));
		rep(i,sz(q)) AHP[i]=q[i];
		for (int i=0,j=sz(AHP)-1;i<sz(AHP);j=i++)
			CH[i]=intersection(AHP[i],AHP[j]);
		return true;
	}
}

}
}
using namespace StandardCodeLibrary::ComputationalGeometry2D;

int main()
{
	int t;
	cin>>t;
	whl(t--)
	{
		db a,b;
		cin>>a>>b;
		if (!sgn(b))
		{
			pdb(8,1.0)<<endl;
			continue;
		}
		if (!sgn(a))
		{
			pdb(8,0.5)<<endl;
			continue;
		}
		Polygon CH;
		vec<Halfplane> AHP,HP;
		HP.pb(Halfplane(mp(-b,0),mp(b,0)));
		HP.pb(Halfplane(mp(b,0),mp(b,a)));
		HP.pb(Halfplane(mp(b,a),mp(-b,a)));
		HP.pb(Halfplane(mp(-b,a),mp(-b,0)));
		HP.pb(Halfplane(mp(0,0),mp(1,4)));
		id2(CH,AHP,HP);
		db s=0;
		rep(i,sz(CH)) s+=cross(CH[i],CH[i+1==sz(CH)?0:i+1])/2;
		pdb(8,s/(a*b*2))<<endl;
	}
}
