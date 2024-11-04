#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
#define REP(i , n) for(int i = 0 ; i < n ; i++)
#define ALL(x) x.begin() , x.end()
#define SZ(x) (int) x.size()
#define BOOST ios_base::sync_with_stdio(0)
#define REMOVE_REDUNDANT

typedef long long LL;
typedef long double LD;
typedef pair < int , int > PII;
typedef vector < int > VI;
typedef vector< VI > VVI;
typedef vector < PII > VPII;
typedef vector < VVI > VVII;

const LD kEps = 1e-9;
const LD kPi = 2.0 * acos(0);
const LD inf = (LD)(1e18);

struct Point{
	LD x , y;
	int index;
	Point(LD a = 0 , LD b = 0) : x(a) , y(b) {}
	Point(const Point &a) : x(a.x) , y(a.y) , index(a.index) {}
	void operator=(const Point &a){ x = a.x , y = a.y; }
	Point operator+(const Point &a) const { Point p(x + a.x , y + a.y); return p; }
	Point operator-(const Point &a) const { Point p(x - a.x , y - a.y); return p; }
	Point operator*(LD a) const { Point p(x * a , y * a); return p; }
	Point operator/(LD a) const { assert(a > kEps); Point p(x / a , y / a); return p; }
	Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
	Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
	Point& operator*=(LD a) { x *= a; y *= a; return *this;}
	Point& operator/=(LD a) { assert(a > kEps); x /= a; y /= a; return *this; }
	bool IsZero() const {
		return fabs(x) < kEps && fabs(y) < kEps;
	}
	bool operator==(const Point& a) const {
		return (*this - a).IsZero();
	}
	LD CrossProd(const Point &a) const{
		return x * a.y - y * a.x;
	}
	LD CrossProd(Point a, Point b){
		a -= *this;
		b -= *this;
		return a.CrossProd(b);
	}
	LD DotProd(const Point &a){
		return x * a.x + y * a.y; 
	}
	LD Norm() const{
		return sqrt(x * x + y * y);
	}
	void NormalizeSelf(){
		*this /= Norm();
	}
	Point Normalize(){
		Point res(*this);
		res.NormalizeSelf();
		return res;
	}
	LD Dist(const Point &a) const{
		return (*this - a).Norm();
	}
	LD Angle() const{
		return atan2(y, x);
	}
	void RotateSelf(LD angle){
		LD c = cos(angle);
		LD s = sin(angle);
		LD nx = x * c - y * s;
		LD ny = x * s + y * c;
		x = nx , y = ny;
	}
	Point Rotate(LD angle) const{
		Point res(*this);
		res.RotateSelf(angle);
		return res;
	}
	static bool LexCmp(const Point &a, const Point &b){
		if(fabs(a.x - b.x) > kEps) return a.x < b.x;
		return a.y < b.y;
	}
	static bool LexCmp2(const Point &a, const Point &b){
		if(fabs(a.y - b.y) > kEps) return a.y < b.y;
		return a.x < b.x;
	}
	friend ostream& operator<<(ostream& out, Point m);
};

ostream& operator<<(ostream& out, Point p){
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

struct Circle{
	Point center;
	LD r;
	Circle(LD x, LD y, LD rad){
		center = Point(x, y);
		r = rad;
	}
	Circle(const Point &a, LD rad) : center(a), r(rad) {}
	LD Area() const{
		return kPi * r * r;
	}
	LD Permieter() const{
		return 2 * kPi * r;
	}
	LD Diameter() const{
		return 2 * r;
	}
	Point RotateRightMost(LD angle) const{
		Point right_most(r, 0);
		Point res = right_most.Rotate(angle);
		return res + center;
	}
	bool operator==(const Circle &c) const{
		return center == c.center and fabs(r - c.r) < kEps;
	}
};

struct Line{
	Point p[2];
	bool is_seg;
	Line(Point a, Point b, bool _is_seg = false){
		p[0] = a;
		p[1] = b;
		is_seg = _is_seg;
	}
	Line() {}
	Point& operator[](int a){
		return p[a];
	}
	static bool VectorsInOneHalfPlaneCmp(Line a, Line b){
		return (a[1] - a[0]).CrossProd(b[1] - b[0]) > 0; 

	}
	Point NormalVector(){
		Point perp = p[1] - p[0];
		perp.RotateSelf(kPi/2);
		perp.NormalizeSelf();
		return perp;
	}
	vector<LD> LineEqNormLD(){ 

		LD A = p[1].y - p[0].y;
		LD B = p[0].x - p[1].x;
		LD C = -(A * p[0].x + B * p[0].y);
		assert(fabs(A * p[1].x + B * p[1].y + C) < kEps);
		LD norm = sqrt(A * A + B * B);
		vector<LD> res{A, B, C};
		for(LD &x : res) x /= norm;
		if(A < -kEps || (fabs(A) < kEps && B < -kEps)) {
			for(LD &x : res) x *= -1;
		}
		return res;
	}
	

	VI LineEqNormInt(){
		int A = round(p[1].y - p[0].y);
		int B = round(p[0].x - p[1].x);
		int C = -(A * p[0].x + B * p[0].y);
		int gcd = abs(__gcd(A , __gcd(B, C)));
		VI res{A, B, C};
		for(int &x : res) x /= gcd;
		if(A < 0 || (A == 0 && B < 0)){
			for(int &x : res) x *= -1;
		}
		return res;
	}
	void ParllelShiftSelf(LD dist){
		Point perp = p[1] - p[0];
		perp.NormalizeSelf();
		perp.RotateSelf(kPi/2);
		perp *= dist;
		p[1] += perp;
		p[0] += perp;
	}
};


struct Utils{
	static LD AreaTriangle(Point a , Point b , Point c){
		return a.CrossProd(b) + b.CrossProd(c) + c.CrossProd(a);
	}
	static vector<Point> InterCircleCircle(Circle &a, Circle &b){
		Circle *c = &a;
		Circle *d = &b;
		if(a.r + kEps < b.r) {
			swap(c, d);
		}
		if(a == b){
			return vector<Point>{a.RotateRightMost(0), a.RotateRightMost(2*kPi/3), a.RotateRightMost(4*kPi/3)};
		}
		Point diff = c->center - d->center;
		LD dis = diff.Norm();
		LD ang = diff.Angle();
		LD longest = max(max(c->r, d->r), dis);
		if(2 * longest > c->r + d->r + dis + kEps){
			return vector<Point>();
		}
		if(fabs(2 * longest - c->r - d->r - dis) < 2 * kEps){
			return vector<Point>{c->RotateRightMost(ang)};
		}
		LD proj_diff = (c->r * c->r - d->r * d->r) / dis;
		LD r1_proj = (dis + proj_diff) / 2;
		LD ang_deviation = acos(r1_proj / c->r);
		LD ang1 = ang + ang_deviation;
		LD ang2 = ang - ang_deviation;
		return vector<Point>{c->RotateRightMost(ang1), c->RotateRightMost(ang2)};
	}
	static Point InterLineLine(Line &a , Line &b){
		Point va = a[1] - a[0];
		Point vb1 = b[1] - a[0];
		Point vb0 = b[0] - a[0];
		LD tr_area = vb1.CrossProd(vb0);
		LD quad_area = vb1.CrossProd(va) + va.CrossProd(vb0);






		return Point(a[0] + va * (tr_area / quad_area));
	}
	static Point ProjPointToLine(Point p, Line l) { 

		l[0] -= p;
		l[1] -= p;
		Point normal = l.NormalVector();
		normal *= normal.DotProd(l[0]);
		return normal + p;	
	}
	static Point ReflectPtWRTLine(Point p, Line l) {
		Point proj = ProjPointToLine(p, l);
		return proj * 2 - p;
	}
	static vector<Point> InterCircleLine(Circle c, Line l){
		Point proj = ProjPointToLine(c.center, l);
		LD dis_proj = c.center.Dist(proj);
		if(dis_proj > c.r + kEps) return vector<Point>();
		LD a = sqrt(c.r * c.r - dis_proj * dis_proj);
		Point dir = l[1] - l[0];
		dir.NormalizeSelf();
		if(a < 2 * kEps) return vector<Point>{proj};
		return vector<Point>{proj + dir * a , proj - dir * a};
	}
	static bool PtBelongToLine(Line l, Point p){
		return fabs(l[0].CrossProd(l[1], p)) < kEps;
	}
	static bool PtBelongToSeg(Line l, Point p){
		return fabs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < kEps;
	}
	static bool PtInCircle(Point p, Circle c){
		return c.center.Dist(p) < -kEps + c.r;
	}
	static vector<Point> TangencyPtsToCircle(Circle c, Point p){
		assert(c.center.Dist(p) > c.r + kEps); 

		Point mid = (c.center + p)/2;
		Circle aux_circle = Circle(mid, c.center.Dist(p) / 2);
		return InterCircleCircle(aux_circle, c);
	}
	static bool AreParllel(Line l1, Line l2){
		return fabs((l1[1] - l1[0]).CrossProd(l2[1] - l2[0])) < kEps;
	}
	static LD Angle(Point P, Point Q, Point R){

		LD ang1 = (R - Q).Angle();
		LD ang2 = (P - Q).Angle();
		LD ans = ang1 - ang2;
		if(ans < kEps){
			ans += 2 * kPi; 

		}
		return ans;
	}
	static LD Angle(Line &l1 , Line &l2){
		Point p1 = l1[1] - l1[0];
		Point p2 = l2[1] - l2[0];
		p1.NormalizeSelf();
		p2.NormalizeSelf();
		return acos(fabs(p1.DotProd(p2)));
	}
	static LD sign(Point p1, Point p2, Point p3){
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
	}
	static bool PointInTriangle(Point p1 , Point p2 , Point p3 , Point p){
		bool b1, b2, b3;
		b1 = (sign(p, p1, p2) < -kEps);
		b2 = (sign(p, p2, p3) < -kEps);
		b3 = (sign(p, p3, p1) < -kEps);
		return ((b1 == b2) && (b2 == b3));
	}
	static bool between(const Point &a, const Point &b, const Point &c){
		return (fabs(Utils::AreaTriangle(a , b , c)) < kEps && (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
	}
};

struct Polygon{
	vector<Point> pts;
	Polygon(vector<Point> _pts) : pts(_pts) {}
	Polygon() : Polygon(vector<Point>()) {}
	void Add(Point p){
		pts.PB(p);
	}
	double Area(){
		double area = 0;
		REP(i, SZ(pts)){
			area += pts[i].CrossProd(pts[(i+1) % SZ(pts)]);
		}
		area /= 2;
		return area;
	}
	void OrientCounterclockwise(){
		if(Area() < 0) reverse(ALL(pts));
	}
	int next(int a){
		return (a + 1 < SZ(pts) ? a + 1 : 0);
	}
	PII FurthestPair(){

	}
	void MakeConvexHull(){ 

		

		sort(ALL(pts) , Point::LexCmp);
		pts.erase(unique(pts.begin(), pts.end()), pts.end());
		vector < Point > up, dn;
		REP(i , SZ(pts)){
			while (up.size() > 1 && Utils::AreaTriangle(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
			while (dn.size() > 1 && Utils::AreaTriangle(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
			up.PB(pts[i]);
			dn.PB(pts[i]);
		}
		pts = dn;
		FORD(i , SZ(up) - 2 , 1) pts.PB(up[i]);

#ifdef REMOVE_REDUNDANT
		if (pts.size() <= 2) return;
		dn.clear();
		dn.PB(pts[0]);
		dn.PB(pts[1]);
		FOR(i , 2 , SZ(pts) - 1){
			if (Utils::between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
			dn.PB(pts[i]);
		}
		if(dn.size() >= 3 && Utils::between(dn.back(), dn[0], dn[1])) {
			dn[0] = dn.back();
			dn.pop_back();
		}
		pts = dn;
#endif
	}
	void Prepare(){

		sort(ALL(pts) , Point::LexCmp);
	}
	LD ClosestPair(){
		Prepare();
		return FindCP(0 , SZ(pts) - 1);
	}
	LD FindCP(int l , int r){
		if(l >= r) return inf;
		int mid = (l + r) >> 1;
		LD ll = FindCP(l , mid);
		LD rr = FindCP(mid + 1 , r);
		LD ans = min(ll , rr);
		LD dis = ans;
		vector < Point > lft , rgt;
		LD xmid = (pts[mid].x + pts[mid + 1].x)/2;
		FOR(i , l , mid){
			if(xmid - pts[i].x <= ans + kEps) lft.PB(pts[i]);
		}
		FOR(i , mid + 1 , r){
			if(pts[i].x - xmid <= ans + kEps) rgt.PB(pts[i]);	
		}
		sort(ALL(lft) , Point::LexCmp2);
		sort(ALL(rgt) , Point::LexCmp2);
		int dwn = 0 , up = 0;
		REP(i , SZ(lft)){
			while(up + 1 < SZ(rgt) && rgt[up + 1].y - lft[i].y <= dis){
				up++;
			}
			while (dwn < SZ(rgt) && lft[i].y - rgt[dwn].y > dis) dwn++;
			FOR(j , dwn , up){
				ans = min(ans , lft[i].Dist(rgt[j]));
			}
		}
		return ans;
	}
};

const int N = 1e5 + 5;
int n;
LD arr[N];
int main(){
	BOOST;
	cin >> n;
	Polygon pol;
	FOR(i , 1 , n){
		cin >> arr[i];
	}
	FOR(i , 1 , n){
		arr[i] += arr[i - 1];
		Point x;
		x.x = i;
		x.y = arr[i];
		pol.Add(x);
	}
	LL ans = (LL) round(pow(pol.ClosestPair() , 2));
	cout << ans << endl;
}	