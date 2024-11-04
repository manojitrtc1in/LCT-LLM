


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;



#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define rrepf(i,a,b) fdt(i,(a)-1,b)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define for_each(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define for_in_charset(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define ctz __builtin_ctz
#define clz __builtin_clz
#define bc __builtin_popcount
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define rev(x) reverse(all(x))
#define shf(x) random_shuffle(all(x))
#define nxtp(x) next_permutation(all(x))



#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<#x" = "<<(x)<<endl
#define asrtWA(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtTLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtMLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtOLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtRE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in)
#define output(out)
#endif



typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<lli> vl;
typedef vec<vl> vvl;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<char> vc;
typedef vec<vc> vvc;
typedef vec<str> vs;
typedef pr<int, int> pii;
typedef pr<lli, lli> pll;
typedef pr<db, db> pdd;
typedef vec<pii> vpii;
typedef vec<pll> vpll;
typedef vec<pdd> vpdd;
typedef map<int, int> mii;
typedef map<str, int> msi;
typedef map<char, int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;



int oo = (~0u) >> 1;
lli ooll = (~0ull) >> 1;
db inf = 1e+10;
db eps = 1e-10;
db gam = 0.5772156649015328606;
db pi = acos(-1.0);
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1, 0 };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1, 0 };
int MOD = 1000000007;



template<typename type> inline bool cmax(type& a, const type& b) {
	rtn a < b ? a = b, true : false;
}
template<typename type> inline bool cmin(type& a, const type& b) {
	rtn b < a ? a = b, true : false;
}
template<typename type> inline type sqr(const type& x) {
	rtn x * x;
}
template<typename type> inline type mod(const type& x) {
	rtn x % MOD;
}
inline int sgn(const db& x) {
	rtn (x > +eps) - (x < -eps);
}
inline int dbcmp(const db& a, const db& b) {
	rtn sgn(a - b);
}
template<typename type> inline pr<type, type> operator-(
		const pr<type, type>& x) {
	rtn mp(-x.x, -x.y);
}
template<typename type> inline pr<type, type> operator+(const pr<type, type>& a,
		const pr<type, type>& b) {
	rtn mp(a.x + b.x, a.y + b.y);
}
template<typename type> inline pr<type, type> operator-(const pr<type, type>& a,
		const pr<type, type>& b) {
	rtn mp(a.x - b.x, a.y - b.y);
}
template<typename type> inline pr<type, type> operator*(const pr<type, type>& a,
		const type& b) {
	rtn mp(a.x * b, a.y * b);
}
template<typename type> inline pr<type, type> operator/(const pr<type, type>& a,
		const type& b) {
	rtn mp(a.x / b, a.y / b);
}
template<typename type> inline pr<type, type>& operator-=(pr<type, type>& a,
		const pr<type, type>& b) {
	rtn a = a - b;
}
template<typename type> inline pr<type, type>& operator+=(pr<type, type>& a,
		const pr<type, type>& b) {
	rtn a = a + b;
}
template<typename type> inline pr<type, type>& operator*=(pr<type, type>& a,
		const type& b) {
	rtn a = a * b;
}
template<typename type> inline pr<type, type>& operator/=(pr<type, type>& a,
		const type& b) {
	rtn a = a / b;
}
template<typename type> inline type cross(const pr<type, type>& a,
		const pr<type, type>& b) {
	rtn a.x * b.y - a.y * b.x;
}
template<typename type> inline type dot(const pr<type, type>& a,
		const pr<type, type>& b) {
	rtn a.x * b.x + a.y * b.y;
}
template<typename type> inline type gcd(type a, type b) {
	if (b)
		whl((a %= b) && (b %= a))
					;
			rtn a + b;
		}
		template<typename type> inline type lcm(type a, type b) {
			rtn a * b / gcd(a, b);
		}
		inline lli bin_pow(lli x, lli y) {
			lli z = 1;
			whl(y) {
						if (y & 1)
							z = mod(z * x);
						x = mod(sqr(x)), y >>= 1;
					}
					rtn z;
				}
				template<typename istream, typename first_type,
						typename second_type> inline istream& operator>>(
						istream& cin, pr<first_type, second_type>& x) {
					rtn cin >> x.x >> x.y;
				}
				template<typename ostream, typename first_type,
						typename second_type> inline ostream& operator<<(
						ostream& cout, const pr<first_type, second_type>& x) {
					rtn cout << x.x << " " << x.y;
				}
				template<typename istream, typename type> inline istream& operator>>(
						istream& cin, vec<type>& x) {
					rep(i,sz(x))
						cin >> x[i];
					rtn cin;
				}
				template<typename ostream, typename type> inline ostream& operator<<(
						ostream& cout, const vec<type>& x) {
					rep(i,sz(x))
						cout << x[i] << (i + 1 == sz(x) ? "" : " ");
					rtn cout;
				}
				inline ostream& pdb(int prcs, db x) {
					rtn cout << setprecision(prcs) << fixed
							<< (sgn(x) ? (x) : 0);
				}
				template<typename type> inline void bit_inc(vec<type>& st,
						int x, type inc) {
					whl(x < sz(st))
								st[x] += inc, x |= x + 1;
						}
						template<typename type> inline type bit_sum(
								const vec<type>& st, int x) {
							type s = 0;
							whl(x >= 0)
										s += st[x], x = (x & (x + 1)) - 1;
									rtn s;
								}
								template<typename type> inline type bit_kth(
										const vec<type>& st, int k) {
									int x = 0, y = 0, z = 0;
									whl((1 << (++y)) <= sz(st))
												;
											rrep(i,y)
											{
												if ((x += 1 << i) > sz(st)
														|| z + st[x - 1] > k)
													x -= 1 << i;
												else
													z += st[x - 1];
											}
											rtn x;
										}
										inline void make_set(vi& st) {
											rep(i,sz(st))
												st[i] = i;
										}
										inline int find_set(vi& st, int x) {
											int y = x, z;
											whl(y != st[y])
														y = st[y];
													whl(x != st[x])
																z = st[x], st[x] =
																y, x = z;
															rtn y;
														}
														inline bool union_set(
																vi& st, int a,
																int b) {
															a = find_set(st, a), b =
																	find_set(st,
																			b);
															rtn a != b ?
																	st[a] = b, true :
																	false;
														}
														inline void make_set(
																vpii& st) {
															rep(i,sz(st))
																st[i] = mp(i,
																		1);
														}
														inline int find_set(
																vpii& st,
																int x) {
															int y = x, z;
															whl(y != st[y].x)
																		y =
																				st[y].x;
																	whl(x
																					!= st[x].x)
																				z =
																						st[x].x, st[x].x =
																						y, x =
																						z;
																			rtn y;
																		}
																		inline bool union_set(
																				vpii& st,
																				int a,
																				int b) {
																			a =
																					find_set(
																							st,
																							a), b =
																					find_set(
																							st,
																							b);
																			rtn a
																					!= b ?
																					(st[a].y
																							> st[b].y ?
																							st[a].x =
																									b, st[a].y +=
																									st[b].y :
																							st[b].x =
																									a, st[b].y +=
																							st[a].y), true :
																					false;
																		}
																		template<
																				typename type> inline void merge(
																				type& a,
																				type& b) {
																			if (sz(
																					a)<sz(b))
																				swap(
																						a,
																						b);
																																										whl(sz(b))a.ins(*b.begin()),
																					b.ers(b.begin());}



																					struct Initializer{
#ifndef DEBUG
																					Initializer() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
																					~Initializer() {runtime();}
#endif
																					}initializer;



#include <ext/rope>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
																					typedef __gnu_cxx::rope<char> rope; template<typename key,
																					typename value>class ext_map:public __gnu_pbds::tree<key,
																					value,
																					less<
																							key>,
																					__gnu_pbds::rb_tree_tag,
																					__gnu_pbds::tree_order_statistics_node_update> {};

																					



																					namespace StandardCodeLibrary { namespace ComputationalGeometry2D {

																					

																					typedef db Number;

																					typedef pr<Number,
																					Number> Point;

																					typedef Point Vector;

																					typedef pr<Point,
																					Point> Segment;	

																					typedef Segment Line;

																					typedef Segment Halfplane;

																					typedef vec<Point> Polygon;


																					

																					

																					using ::sgn;
																					

																					using ::dbcmp;
																					

																					using ::dot; inline Number dot(const Vector& a,const Vector& b,const Vector& c) { rtn dot(b-a,c-a); }
																					

																					using ::cross; inline Number cross(const Vector& a,const Vector& b,const Vector& c) { rtn cross(b-a,c-a); }
																					

																					inline Number len(const Vector& v) { rtn sqrt(dot(v,v)); } inline Number len(const Segment& s) { rtn len(s.x-s.y); }
																					

																					inline Number dis(const Point& a,const Point& b) { rtn len(b-a); }

																					

																					

																					int point_on_line(const Point& p,const Line& l) { if (sgn(cross(p,l.x,l.y))) rtn 0; else rtn 1; }
																					

																					

																					int point_on_segment(const Point& p,const Segment& s) { if (point_on_line(p,s)) rtn sgn(dot(p,s.x,s.y))<=0?1:-1; else rtn 0; }

																					

																					

																					int point_in_polygon(const Point& p,const vec<Segment>& e) { rep(i,sz(e)) if (point_on_segment(p,e[i])==1) rtn -1; bool in=false; rep(i,sz(e)) if ((dbcmp(e[i].x.y,p.y)>0)!=(dbcmp(e[i].y.y,p.y)>0) &&dbcmp(p.x,(e[i].y.x-e[i].x.x)/(e[i].y.y-e[i].x.y)*(p.y-e[i].x.y)+e[i].x.x)<0) in=!in; rtn in?1:0; }

																					

																					

																					int line_intersect(const Line& a,const Line& b) { Vector va=a.y-a.x,
																					vb=b.y-b.x; if (sgn(cross(va,vb))) rtn 1; else { if (sgn(cross(a.x,a.y,b.x))) rtn 0; else rtn -1; } }

																					

																					

																					

																					

																					int segment_intersect(const Segment& a,const Segment& b) { int ab=sgn(cross(a.x,a.y,b.x))*sgn(cross(a.x,a.y,b.y)),
																					ba=sgn(cross(b.x,b.y,a.x))*sgn(cross(b.x,b.y,a.y)); if (ab>0||ba>0) rtn 0; else { Vector va=a.y-a.x,
																					vb=b.y-b.x; if (sgn(cross(va,vb))) rtn 1; else { if (sgn(dot(b.x,a.x,a.y))<=0 ||sgn(dot(b.y,a.x,a.y))<=0 ||sgn(dot(a.x,b.x,b.y))<=0 ||sgn(dot(a.y,b.x,b.y))<=0) rtn -1; else rtn 0; } } }

																					

																					

																					Point line_intersection(const Line& a,const Line& b) { Vector va=a.y-a.x,
																					vb=b.y-b.x; rtn a.x+va*(cross(b.x-a.x,vb)/cross(va,vb)); }

																					

																					void convex_hull(Polygon& CH,Polygon& PO) { CH.clear(); uniq(PO); rep(i,sz(PO)) { whl(sz(CH)>=2&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();	

																					CH.pb(PO[i]); } for (int i=sz(PO)-2,t=sz(CH)+1;i>=0;--i) { whl(sz(CH)>=t&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();

																					CH.pb(PO[i]); } CH.pop_back(); }

																					

																					bool halfplane_intersection_compare(const Halfplane& a,const Halfplane& b) { Vector u=a.y-a.x,
																					v=b.y-b.x; db du=atan2(u.y,u.x),
																					dv=atan2(v.y,v.x); if (dbcmp(du,dv)) rtn dbcmp(du,dv)<0; else rtn sgn(cross(a.x,a.y,b.x))<0; } bool halfplane_intersection_judge(const Halfplane& a,const Halfplane& b,const Halfplane& c) { Vector u=a.y-a.x,
																					v=b.y-b.x; db du=atan2(u.y,u.x),
																					dv=atan2(v.y,v.x); if (dbcmp(du,dv)) { if (sgn(cross(a.y-a.x,b.y-b.x))) { Point ab=line_intersection(a,b); rtn sgn(cross(c.x,c.y,ab))<=0;

																					} else rtn false; } else rtn true; } bool halfplane_intersection(Polygon& CH,vec<Halfplane>& AHP,vec<Halfplane> HP) { HP.pb(Halfplane(Point(-inf,-inf),Point(+inf,-inf))),
HP.pb(Halfplane(Point(+inf,-inf),Point(+inf,+inf))),
HP.pb(Halfplane(Point(+inf,+inf),Point(-inf,+inf))),
HP.pb(Halfplane(Point(-inf,+inf),Point(-inf,-inf)));
sort(all(HP),halfplane_intersection_compare);
deque<Halfplane> q;
q.pb(HP.front());
repf(i,1,sz(HP))
{
	Halfplane t;
	do t=q.back(),q.pop_back();
	whl(sz(q)&&halfplane_intersection_judge(q.back(),t,HP[i]));
	q.pb(t);
	do t=q.front(),q.pop_front();
	whl(sz(q)&&halfplane_intersection_judge(q.front(),t,HP[i]));
	q.push_front(t);
	q.pb(HP[i]);
}
Halfplane t;
do t=q.back(),q.pop_back();
whl(sz(q)&&halfplane_intersection_judge(q.back(),t,q.front()));
q.pb(t);
if (sz(q)<3) rtn false;
else
{
	CH.resize(sz(q)),AHP.resize(sz(q));
	rep(i,sz(q)) AHP[i]=q[i];
	for (int i=0,j=sz(AHP)-1;i<sz(AHP);j=i++)
	CH[i]=line_intersection(AHP[i],AHP[j]);
	rtn true;
}
}

									

const int MAXV=3;
const int MAXE=3*MAXV-6;
struct Vertex:Point
{
int id;
Vertex() {}
Vertex(Number x,Number y):Point(x,y) {}
};
														

														

														

														

														

typedef struct QuadEdge* Edge;
struct QuadEdge
{
int idx;
Edge n;
Vertex v;


inline Edge Rot() {rtn idx<3?this+1:this-3;}
inline Edge InvRot() {rtn idx>0?this-1:this+3;}
inline Edge Sym() {rtn idx<2?this+2:this-2;}
inline Edge Onext() {rtn n;}
inline Edge Oprev() {rtn Rot()->Onext()->Rot();}
inline Edge Dnext() {rtn Sym()->Onext()->Sym();}
inline Edge Dprev() {rtn InvRot()->Onext()->InvRot();}
inline Edge Lnext() {rtn InvRot()->Onext()->Rot();}
inline Edge Lprev() {rtn Onext()->Sym();}
inline Edge Rnext() {rtn Rot()->Onext()->InvRot();}
inline Edge Rprev() {rtn Sym()->Onext();}
inline Vertex& Org() {rtn v;}
inline Vertex& Dest() {rtn Sym()->v;}




}pool[MAXE][4];
Edge stk[MAXE];
int stks;
int n;
Vertex v[MAXV];

inline bool Equal(const Vertex& A,const Vertex& B) {rtn sgn(dis(A,B))==0;}
inline bool CCW(const Vertex& A,const Vertex& B,const Vertex& C) {rtn sgn(cross(A,B,C))>0;}
inline bool RightOf(const Vertex& X,Edge e) {rtn CCW(X,e->Dest(),e->Org());}
inline bool LeftOf(const Vertex& X,Edge e) {rtn CCW(X,e->Org(),e->Dest());}
inline bool Valid(Edge e,Edge basel) {rtn RightOf(e->Dest(),basel);}
inline bool InCircle(const Vertex& A,const Vertex& B,const Vertex& C,const Vertex& D)
{
rtn sgn(dot(A,A)*cross(B,C,D)-
		dot(B,B)*cross(A,C,D)+
		dot(C,C)*cross(A,B,D)-
		dot(D,D)*cross(A,B,C))>0;
}
inline bool On(const Vertex& X,Edge e) {rtn point_on_segment(X,mp(e->Org(),e->Dest()))==1;}

Edge MakeEdge()
{
Edge e=stk[stks++];
rep(i,4) e[i].idx=i,e[i].n=e+(i?4-i:0);
rtn e;
}
void Splice(Edge a, Edge b)
{
Edge alpha=a->Onext()->Rot(),beta=b->Onext()->Rot();
Edge t1=b->Onext(),t2=a->Onext();
Edge t3=beta->Onext(),t4=alpha->Onext();
a->n=t1,b->n=t2;
alpha->n=t3,beta->n=t4;
}
Edge Connect(Edge a,Edge b)
{
Edge e=MakeEdge();
e->Org()=a->Dest(),e->Dest()=b->Org();
Splice(e,a->Lnext()),Splice(e->Sym(),b);
rtn e;
}
void DeleteEdge(Edge e)
{
Splice(e,e->Oprev());
Splice(e->Sym(),e->Sym()->Oprev());
stk[--stks]=e-e->idx;
}
void Swap(Edge e)
{
Edge a=e->Oprev(),b=e->Sym()->Oprev();
Splice(e,a),Splice(e->Sym(),b);
Splice(e,a->Lnext()),Splice(e->Sym(),b->Lnext());
e->Org()=a->Dest(),e->Dest()=b->Dest();
}
Edge Locate(const Vertex& X)
{
Edge e=stk[rand()%stks];
lp
{
	if (Equal(X,e->Org())||Equal(X,e->Dest())) rtn e;
	else if (RightOf(X,e)) e=e->Sym();
	else if (!RightOf(X,e->Onext())) e=e->Onext();
	else if (!RightOf(X,e->Dprev())) e=e->Dprev();
	else rtn e;
}
}

void InitializeDelaunay()
{
stks=0;
rep(i,MAXE) stk[i]=pool[i];
sort(v,v+n);
}
pr<Edge,Edge> Delaunay(int l,int r)
{
if (r-l==2)
{
	Vertex s1=v[l],s2=v[l+1];
	Edge a=MakeEdge();
	a->Org()=s1,a->Dest()=s2;
	rtn mp(a,a->Sym());
}
else if (r-l==3)
{
	Vertex s1=v[l],s2=v[l+1],s3=v[l+2];
	Edge a=MakeEdge(),b=MakeEdge();
	Splice(a->Sym(),b),a->Org()=s1,a->Dest()=b->Org()=s2,b->Dest()=s3;
	if (CCW(s1,s2,s3))
	{
		Edge c=Connect(b,a);
		rtn mp(a,b->Sym());
	}
	else if (CCW(s1,s3,s2))
	{
		Edge c=Connect(b,a);
		rtn mp(c->Sym(),c);
	}
	else rtn mp(a,b->Sym());
}
else
{
	pr<Edge,Edge> ld=Delaunay(l,(l+r)/2),rd=Delaunay((l+r)/2,r);
	Edge ldo=ld.x,ldi=ld.y,rdi=rd.x,rdo=rd.y;
	lp
	{
		if (LeftOf(rdi->Org(),ldi)) ldi=ldi->Lnext();
		else if (RightOf(ldi->Org(),rdi)) rdi=rdi->Rprev();
		else break;
	}
	Edge basel=Connect(rdi->Sym(),ldi);
	if (Equal(ldi->Org(),ldo->Org())) ldo=basel->Sym();
	if (Equal(rdi->Org(),rdo->Org())) rdo=basel;
	lp
	{
		Edge lcand=basel->Sym()->Onext();
		if (Valid(lcand,basel))
		whl(InCircle(basel->Dest(),basel->Org(),lcand->Dest(),lcand->Onext()->Dest()))
		{
			Edge t=lcand->Onext();
			DeleteEdge(lcand),lcand=t;
		}
		Edge rcand=basel->Oprev();
		if (Valid(rcand,basel))
		whl(InCircle(basel->Dest(),basel->Org(),rcand->Dest(),rcand->Oprev()->Dest()))
		{
			Edge t=rcand->Oprev();
			DeleteEdge(rcand),rcand=t;
		}
		if (!Valid(lcand,basel)&&!Valid(rcand,basel)) break;
		if (!Valid(lcand,basel)||(Valid(rcand,basel)&&InCircle(lcand->Dest(),lcand->Org(),rcand->Org(),rcand->Dest())))
		basel=Connect(rcand,basel->Sym());
		else
		basel=Connect(basel->Sym(),lcand->Sym());
	}
	rtn mp(ldo,rdo);
}
}
void InitializeInsertSite()
{
stks=0;
rep(i,MAXE) stk[i]=pool[i];
Vertex s1(-inf,-inf),s2(0,+inf),s3(+inf,0);
s1.id=s2.id=s3.id=-1;
Edge a=MakeEdge(),b=MakeEdge();
Splice(a->Sym(),b),a->Org()=s1,a->Dest()=b->Org()=s2,b->Dest()=s3;
Connect(b,a);
}
void InsertSite(const Vertex& X)
{
Edge e=Locate(X);
if (Equal(X,e->Org())||Equal(X,e->Dest())) rtn;
else if (On(X,e))
{
	Edge t=e->Oprev();
	DeleteEdge(e),e=t;
}
Edge base=MakeEdge();
Vertex first=e->Org();
base->Org()=first,base->Dest()=X,Splice(base,e);
do base=Connect(e,base->Sym()),e=base->Oprev();
whl(!Equal(e->Dest(),first));
e=base->Oprev();
lp
{
	Edge t=e->Oprev();
	if (RightOf(t->Dest(),e)&&InCircle(e->Org(),t->Dest(),e->Dest(),X))
	Swap(e),e=e->Oprev();
	else if (Equal(e->Org(),first)) rtn;
	else e=e->Onext()->Lprev();
}
}

}
}


db m[1002][1002],d[1002],p[1002];int vis[1002];
int main() {
	using namespace StandardCodeLibrary::ComputationalGeometry2D;
	int n;scanf("%d",&n);rep(i,n)rep(j,n)scanf("%lf",&m[i][j]),m[i][j]/=100;




	d[n-1]=0;
	rep(i,n) p[i]=1;
	vis[n-1]=true;
	rep(i,n){
		if (!vis[i]){
			db nd=d[i]+p[i]*m[i][n-1]*d[n-1];
			db np=p[i]*(1-m[i][n-1]);
			if ((d[i]+1)/(1-p[i])>(nd+1)/(1-np)){
				d[i]=nd;p[i]=np;
			}
		}
	}
	rep(i,n-1){
		db best=inf;int bi=-1;
		for (int i=0;i<n;i++){
			if (!vis[i]){
				if (cmin(best,(d[i]+1)/(1-p[i]))){
					bi=i;
				}
			}
		}
		if (bi==-1) break;
		d[bi]=(d[bi]+1)/(1-p[bi]);
		vis[bi]=true;
		prt(bi),prt(d[bi]);
		rep(i,n){
			if (!vis[i]){
				db nd=d[i]+p[i]*m[i][bi]*d[bi];
				db np=p[i]*(1-m[i][bi]);
				if ((d[i]+1)/(1-p[i])>(nd+1)/(1-np)){
					d[i]=nd;p[i]=np;
				}
			}
		}
	}
	db ans=d[0];
	pdb(10,ans)<<endl;
}

