
using namespace std;








template<class T> ostream& operator<<(ostream &os,vector<T> V){
	os<<"[ ";for(auto v:V)os<<v<<" ";return os<<" ]";
}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){
	return os<<"("<<P.first<<","<<P.second<<")";
}




template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
	const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}



























ld INF = 1e100;
ld EPS = 1e-15;
inline bool eq(ld a,ld b) {return fabs(a-b)<EPS;}
inline bool lt(ld a,ld b) {return a+EPS<b;}
inline bool gt(ld a,ld b) {return a>b+EPS;}
inline bool le(ld a,ld b) {return lt(a,b)||eq(a,b);}
inline bool ge(ld a,ld b) {return gt(a,b)||eq(a,b);}
struct pt {
	ld x, y; 
	pt() {}
	pt(ld x, ld y) : x(x), y(y) {}
	pt(const pt &p) : x(p.x), y(p.y)		{}
	pt operator + (const pt &p)	
	const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt &p)	
	const { return pt(x-p.x, y-p.y); }
	pt operator * (ld c)		 
	const { return pt(x*c,	 y*c	); }
	pt operator / (ld c)		 
	const { return pt(x/c,	 y/c	); }
	bool operator < (const pt &p) 
	const {return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
	bool operator > (const pt &p) 
	const{ return p<pt(x,y);}
	bool operator <= (const pt &p) 
	const{ return !(pt(x,y)>p);}
	bool operator >= (const pt &p) 
	const{ return !(pt(x,y)<p);}
	bool operator == (const pt &p) 
	const{ return (pt(x,y)<=p)&&(pt(x,y)>=p);}
};
ld dot(pt p,pt q) {return p.x*q.x+p.y*q.y;}
ld dist2(pt p, pt q) {return dot(p-q,p-q);}
ld dist(pt p,pt q) {return sqrtl(dist2(p,q));}
ld norm2(pt p) {return dot(p,p);}
ld norm(pt p) {return sqrtl(norm2(p));}
ld cross(pt p, pt q) { return p.x*q.y-p.y*q.x;}
ostream &operator<<(ostream &os, const pt &p) {
	return os << "(" << p.x << "," << p.y << ")";}
istream& operator >> (istream &is, pt &p){
	return is >> p.x >> p.y;}


int orient(pt a,pt b,pt c)
{
	pt p=b-a,q=c-b;double cr=cross(p,q);
	if(eq(cr,0))return 0;if(lt(cr,0))return 1;return -1;}


pt id9(pt p)	 { return pt(-p.y,p.x); }
pt id16(pt p)		{ return pt(p.y,-p.x); }
pt id3(pt p, ld t) {

return pt(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); }


pt id12(pt a, pt b, pt c) {
	return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);}


pt id17(pt a, pt b, pt c) {
	ld r = dot(b-a,b-a); if (eq(r,0)) return a;

	r = dot(c-a, b-a)/r;if (lt(r,0)) return a;

	if (gt(r,1)) return b; return a + (b-a)*r;}


ld id0(pt a, pt b, pt c) {
	return sqrtl(dist2(c, id17(a, b, c)));}


ld id11(pt a, pt b, pt c) {
	return sqrtl(dist2(c, id12(a, b, c)));}


bool LinesParallel(pt a, pt b, pt c, pt d) { 
	return eq(cross(b-a, c-d),0); }
bool id18(pt a, pt b, pt c, pt d) { 
	return LinesParallel(a, b, c, d) && eq(cross(a-b, a-c),0) && eq(cross(c-d, c-a),0);}


bool SegmentsIntersect(pt a, pt b, pt c, pt d) {
	if (id18(a, b, c, d)) {
		

		if(eq(dist2(a,c),0)||eq(dist2(a,d),0)||eq(dist2(b,c),0)||eq(dist2(b,d),0)) 
			return true;
		if(gt(dot(c-a,c-b),0)&&gt(dot(d-a,d-b),0)&&gt(dot(c-b,d-b),0)) return false;
		return true;}
	if(gt(cross(d-a,b-a)*cross(c-a,b-a),0)) return false;

	if(gt(cross(a-c,d-c)*cross(b-c,d-c),0)) 
	return false;

	return true;}






pt id14(pt a,pt b,pt c,pt d){
	b=b-a;d=c-d;c=c-a;

	assert(gt(dot(b, b),0)&&gt(dot(d, d),0));
	return a + b*cross(c, d)/cross(b, d);}


bool between(pt a,pt b,pt c){
	if(!eq(cross(b-a,c-b),0))return 0;

	return le(dot(b-a,b-c),0);
}


pt id6(pt a,pt b,pt c,pt d){
	if(!SegmentsIntersect(a,b,c,d))return {INF,INF};

	

	if(id18(a,b,c,d)){if(between(a,c,b))return c;if(between(c,a,d))return a;return b;}
	return id14(a,b,c,d);
}


pt id20(pt a,pt b,pt c){
	b=(a+b)/2;c=(a+c)/2;
	return id14(b,b+id16(a-b),c,c+id16(a-c));}






bool id21(const vector<pt> &p,pt q){
	int n=p.size(),id15=0;
	for(int i=0;i<n;++i){
		if(eq(dist2(q,p[i]),0)) return 1;

		int j=(i+1)%n;
		if(eq(p[i].y,q.y)&&eq(p[j].y,q.y)) {

			if(le(min(p[i].x,p[j].x),q.x)&&le(q.x,max(p[i].x, p[j].x))) return 1;}

		else {
			bool below=lt(p[i].y,q.y);
			if(below!=lt(p[j].y,q.y)) {
				auto orientation=orient(q,p[j],p[i]);
				if(orientation==0) return 1;

				if(below==(orientation>0)) id15+=below?1:-1;}}}
	return id15==0?0:1;
}


bool id8(const vector<pt> &p,pt q) {
	for (int i = 0; i < p.size(); i++)
		if (eq(dist2(id17(p[i],p[(i+1)%p.size()],q),q),0)) return true;
	return false;}




ld id7(const vector<pt> &p) {
	ld ans=0;
	for(int i = 0; i < p.size(); i++) {
		int j = (i+1) % p.size();
		ans+=cross(p[i],p[j]);
	} return ans / 2.0;}
ld ComputeArea(const vector<pt> &p) {
	return fabs(id7(p));
}




vector<pt> id4(pt a, pt b, pt c, ld r) {
	vector<pt> ret;
	b = b-a;a = a-c;
	ld A = dot(b, b),B = dot(a, b),C = dot(a, a) - r*r,D = B*B - A*C;
	if (lt(D,0)) return ret;	

	ret.push_back(c+a+b*(-B+sqrtl(D+EPS))/A);
	if (gt(D,0)) ret.push_back(c+a+b*(-B-sqrtl(D))/A);
	return ret;}





vector<pt> id10(pt a, pt b, ld r, ld R) {
	vector<pt> ret;
	ld d = sqrtl(dist2(a, b)),d1=dist2(a,b);
	pt inf(INF,INF);
	if(eq(d1,0)&&eq(r,R)){ret.pb(inf);return ret;}

	if(gt(d,r+R) || lt(d+min(r, R),max(r, R)) ) return ret;	
	ld x = (d*d-R*R+r*r)/(2*d),y = sqrtl(r*r-x*x);
	pt v = (b-a)/d;
	ret.push_back(a+v*x + id9(v)*y);
	if (gt(y,0)) ret.push_back(a+v*x - id9(v)*y);
	return ret;}




pt id19(const vector<pt> &p) {
	pt c(0,0),inf(INF,INF);
	ld scale = 6.0 * id7(p);
	if(p.empty())return inf;

	if(eq(scale,0))return inf;

	for (int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		c = c + (p[i]+p[j])*cross(p[i],p[j]);}
	return c / scale;}


bool IsSimple(const vector<pt> &p) {
	for (int i = 0; i < p.size(); i++) {
		for (int k = i+1; k < p.size(); k++) {
			int j = (i+1) % p.size();
			int l = (k+1) % p.size();
			if (i == l || j == k) continue;
			if (SegmentsIntersect(p[i], p[j], p[k], p[l])) 
				return false;}}
	return true;}

bool id1(vector<pt> poly,pt point, int top) {
	if (point < poly[0] || point > poly[top]) return 0;

	auto orientation = orient(point, poly[top], poly[0]);
	if (orientation == 0) {
		if (point == poly[0] || point == poly[top]) return 1;
		return top == 1 || top + 1 == poly.size() ? 1 : 1;

		

	} else if (orientation < 0) {
		auto itRight = lower_bound(poly.begin() + 1, poly.begin() + top, point);
		return orient(itRight[0], point, itRight[-1])<=0;
		} else {
		auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
		return (orient(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]))<=0;
		}
}

ld id2(vector<pt> poly) {
	int n = poly.size();
	ld res=0;
	for (int i = 0, j = n < 2 ? 0 : 1; i < j; ++i)
		for (;; j = j+1 %n) {
				res = max(res, dist2(poly[i], poly[j]));
			if (gt(cross(poly[j+1 % n] - poly[j],poly[i+1] - poly[i]),0)) break;
	}
	return res;
}








ld id5(ld x,ld y,ld z,ld a,ld b,ld c,ld d)
{ return fabs(a*x+b*y+c*z-d)/sqrtl(a*a+b*b+c*c);}
ld id13(pt c1,ld r1,pt c2,ld r2)
{
	if(lt(r1,r2))swap(c1,c2),swap(r1,r2);
	ld d=dist2(c1,c2),d1=dist(c1,c2);
	if(le(r1+r2,d1))return 0;
	if(ge(r1-r2,d1))return PI*r2*r2;
	ld alfa=acos((d+r1*r1-r2*r2)/(2*d1*r1));
	ld beta=acos((d+r2*r2-r1*r1)/(2*d1*r2));
	return alfa*r1*r1+beta*r2*r2-sin(2*alfa)*r1*r1/2-sin(2*beta)*r2*r2/2;

	

 

 

 

 

 

 

 

 

 

 

 

}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll x1,y1,x2,y2,r1,r2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	pt c1(x1,y1),c2(x2,y2);
	

	cout<<id13(c1,r1,c2,r2)<<endl;
}