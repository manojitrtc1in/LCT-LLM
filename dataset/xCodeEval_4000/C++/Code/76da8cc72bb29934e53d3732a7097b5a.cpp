#include <bits\stdc++.h>
using namespace std;
#define rep(flag,a,b) for(int flag=(a);flag<=b;flag++) 
#define Rep(flag,a,b) for(int flag=(a);flag>=b;flag--) 
#define mem(flag) memset(flag,0,sizeof(flag))
#define Mem(flag) memset(flag,-1,sizeof(flag))
typedef long long ll;
typedef unsigned long long ull;
const int MAX=12;





const double PI = acos(-1.0);
const double EPS = 1e-10;

struct Point;
struct Segment;
struct Line;
struct Circle;
struct Polygon;
typedef Point Vector;
typedef Segment Rectangle;

double hypot(double lhs, double rhs)
    { return sqrt(lhs*lhs+rhs*rhs); }

inline bool lt(double lhs, double rhs) { return rhs - lhs >= EPS; }
inline bool le(double lhs, double rhs) { return rhs - lhs >= -EPS; }
inline bool gt(double lhs, double rhs) { return lhs - rhs >= EPS; }
inline bool ge(double lhs, double rhs) { return lhs - rhs >= -EPS; }
inline bool eq(double lhs, double rhs) { return fabs(rhs-lhs) < EPS; }
inline bool ne(double lhs, double rhs) { return fabs(rhs-lhs) >= EPS; }

inline bool zr(double lhs) { return fabs(lhs) < EPS; }
inline bool nz(double lhs) { return fabs(lhs) >= EPS; }
inline bool ps(double lhs) { return lhs >= EPS; }

inline bool nn(double lhs) { return lhs >= -EPS; }

inline bool ng(double lhs) { return lhs < -EPS; }
inline bool np(double lhs) { return lhs < EPS; }



double dist(const Point&, const Point&);
double dist(const Point&, const Line&);
double dist(const Line&, const Point&);
double dist(const Segment&, const Point&);
double dist(const Point&, const Segment&);
double dist(const Line&, const Segment&);
double dist(const Segment&, const Line&);



bool parallel(const Line&, const Line&);
bool cross(const Line&, const Segment&);
bool cross(const Segment&, const Line&);
bool cross(const Line&, const Circle&);
bool cross(const Circle&, const Line&);
bool cross(const Circle&, const Circle&);
bool onSegment(const Point&, const Segment&);
bool cross(const Segment&, const Segment&);
const Point intersect(const Line&, const Line&);
const vector<Point> intersect(const Line&, const Circle&);
const vector<Point> intersect(const Circle&, const Line&);
const Point pedal(const Line&, const Point&);
const Point pedal(const Point&, const Line&);
const Point mirror(const Line&, const Point&);
const Point mirror(const Point&, const Line&);
const Line perpendicular(const Point&, const Line&);
const Line bisector(const Point&, const Point&);


const Line angleBisector(const Point&, const Point&, const Point&);
const Circle circumcircle(const Point&, const Point&, const Point&);




bool Less(const Point &a,const Point &b);
void sortPolarCoor(vector<Point> &ps); 








struct Point {
    double x, y;
    int color;
    Point(double x,double y,int c):x(x), y(y), color(c) {}
    Point(double x=0, double y=0) : x(x), y(y) {}
    void get() { scanf("%lf%lf", &x, &y); }
    void put() const { printf("(%lf, %lf)", x, y); }
    operator bool() const { return nz(x) && nz(y); }
    double length() const { return hypot(x, y); }
};

Point x;



istream& operator>>(istream& is, Point& p)
    { return is >> p.x >> p.y;}
ostream& operator<<(ostream& os, const Point& p)
    { return os << "(" << p.x << ", " << p.y << ")"; }



bool operator==(const Point& lhs, const Point& rhs)
    { return eq(lhs.x, rhs.x) && eq(lhs.y, rhs.y); }
bool operator!=(const Point& lhs, const Point& rhs)
    { return ne(lhs.x, rhs.x) && ne(lhs.y, rhs.y); }
bool operator<(const Point& lhs, const Point& rhs)
    { return lt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && lt(lhs.y, rhs.y); }
bool operator<=(const Point& lhs, const Point& rhs)
    { return lt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && le(lhs.y, rhs.y); }
bool operator>(const Point& lhs, const Point& rhs)
    { return gt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && gt(lhs.y, rhs.y); }
bool operator>=(const Point& lhs, const Point& rhs)
    { return gt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && ge(lhs.y, rhs.y); }



const Point operator+(const Point& lhs, double rhs)
    { return Point(lhs.x+rhs, lhs.y+rhs); }
const Point operator+(double lhs, const Point& rhs)
    { return Point(lhs+rhs.x, lhs+rhs.y); }
const Point operator-(const Point& lhs, double rhs)
    { return Point(lhs.x-rhs, lhs.y-rhs); }
const Point operator-(double lhs, const Point& rhs)
    { return Point(lhs-rhs.x, lhs-rhs.y); }
const Point operator*(double lhs, const Point& rhs)
    { return Point(lhs*rhs.x, lhs*rhs.y); }
const Point operator*(const Point& lhs, double rhs)
    { return Point(lhs.x*rhs, lhs.y*rhs); }
const Point operator/(const Point& lhs, double rhs)
    { return Point(lhs.x/rhs, lhs.y/rhs); }
Point& operator+=(Point& lhs, double rhs)
    { lhs.x += rhs; lhs.y += rhs; return lhs; }
Point& operator-=(Point& lhs, double rhs)
    { lhs.x -= rhs; lhs.y -= rhs; return lhs; }
Point& operator*=(Point& lhs, double rhs)
    { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
Point& operator/=(Point& lhs, double rhs)
    { lhs.x /= rhs; lhs.y /= rhs; return lhs; }



const Point operator+(const Point& lhs, const Point& rhs)
    { return Point(lhs.x+rhs.x, lhs.y+rhs.y); }
const Point operator-(const Point& lhs, const Point& rhs)
    { return Point(lhs.x-rhs.x, lhs.y-rhs.y); }
const Point operator~(const Point& lhs)
    { return Point(-lhs.y, lhs.x); }
double operator^(const Point& lhs, const Point& rhs)
    { return lhs.x*rhs.y - lhs.y*rhs.x; }
double operator*(const Point& lhs, const Point& rhs)
    { return lhs.x*rhs.x + lhs.y*rhs.y; }
Point& operator+=(Point& lhs, const Point& rhs)
    { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
Point& operator-=(Point& lhs, const Point& rhs)
    { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }








struct Segment {
    Point a, b;
    Segment() : a(), b() {}
    Segment(Point a, Point b) : a(a), b(b) {}
};








struct Line {
    double A, B, C;
    Line() : A(0), B(0), C(0) {}
    Line(double A, double B, double C) : A(A), B(B), C(C) {}
    Line(const Point& lhs, const Point& rhs) :
        A(rhs.y - lhs.y), B(lhs.x - rhs.x), C(-(lhs.x*A+lhs.y*B)) {}
    Line(double slope, const Point& p) :
        A(slope), B(-1.0), C(p.y-slope*p.x ) {}
    Line(const Point& p, double slope) :
        A(slope), B(-1.0), C(p.y-slope*p.x ) {}
    Line(const Segment& s) { *this = Line(s.a, s.b); }
    double eval(const Point& p) const { return A*p.x+B*p.y+C; }
     void put() {printf("%lf %lf %lf\n",A,B,C);}
};








struct Circle {
    Point c;
    double r;
    Circle() {}
    Circle(Point c, double r) : c(c), r(r) {}
    Circle(double r, Point c) : c(c), r(r) {}
};








struct Polygon : public vector<Point> {
    Polygon() : vector<Point>(0) {}
    Polygon(const Polygon& P) : vector<Point>(P) {}
    Polygon(const vector<Point>& V) : vector<Point>(V) {}
    template<class Iter> Polygon(Iter begin, Iter end) :
        vector<Point>(begin, end) {}
    double area() const;
    double perimeter() const;
    const Point center() const;
    int within(const Point& p) const;
};








bool parallel(const Line& a, const Line& b)
    { return eq(a.A * b.B, a.B * b.A); }
bool cross(const Line& l, const Segment& s) {

    double a = l.eval(s.a), b = l.eval(s.b);

    return zr(a) || zr(b) || ps(a)^ps(b);
}
bool cross(const Segment& s, const Line& l)
    { return cross(l, s); }
bool cross(const Line& l, const Circle& c)
    { return le(dist(c.c, l), c.r);  }
bool cross(const Circle& c, const Line& l)
    { return le(dist(c.c, l), c.r);  }
bool cross(const Circle& c1, const Circle& c2) {
    double d = dist(c1.c, c2.c);
    return le(d, c1.r+c2.r) && ge(d, fabs(c1.r-c2.r));
}
bool onSegment(const Point& p, const Segment& s)

    { return zr((p-s.a)^(p-s.b)) && np((p-s.a)*(p-s.b)); }
bool cross(const Segment& v, const Segment& w) {
    if(onSegment(v.a, w) ||
        onSegment(v.b, w) ||
        onSegment(w.a, v) ||
        onSegment(w.b, v))
        return true;

    return ( ps((v.a-w.a)^(w.b-w.a)) ^ ps((v.b-w.a)^(w.b-w.a)) )
        && ( ps((w.a-v.a)^(v.b-v.a)) ^ ps((w.b-v.a)^(v.b-v.a)) );
}
const Point intersect(const Line& a, const Line& b) {
    return Point( (a.B*b.C-b.B*a.C)/(b.B*a.A-a.B*b.A),
                  (a.A*b.C-b.A*a.C)/(b.A*a.B-a.A*b.B) );
}
const vector<Point> intersect(const Line& l, const Circle& c) {
    vector<Point> ans;
    if(cross(l, c)) {
        Point p = pedal(c.c, l);
        double d = dist(p, c.c);
        double len = sqrt(fabs(c.r*c.r-d*d));
        Vector a(-l.B, l.A);
        if(zr(len)) ans.push_back(p);
        else {
            ans.push_back(p+a*len/a.length());
            ans.push_back(p-a*len/a.length());
        }
    }
    return ans;
}
const vector<Point> intersect(const Circle& c, const Line& l)
    { return intersect(l, c); }
const vector<Point> intersect(const Circle& c1, const Circle& c2) {
    if(cross(c1, c2)) {
        double d = dist(c1.c, c2.c);
        double t = ((c1.r*c1.r-c2.r*c2.r)/d/d+1)*0.5;
        Point o = c1.c+(c2.c-c1.c)*t;
        return intersect(c1, Line(o, o+~(c1.c-c2.c)));
    }
    else return vector<Point>(0);
}





bool Less(const Point &a,const Point &b) {
	Point hor(1,0),va=a-x,vb=b-x;
	if((va^hor)==0) {
		if(va.x>0&&!((vb^hor)==0&&vb.x>0)) return 1;
		if(va.x<0&&(vb^hor)>0) return 1;
		return 0;
	} else if((va^hor)<0) {
		if((vb^hor)==0&&vb.x<0) return 1;
		if((vb^hor)<0&&(vb^va)<0) return 1;
		if((vb^hor)>0) return 1;
		return 0;
	} else {
		if((vb^va)<0&&(vb^hor)>0) return 1;
		return 0;
	}
}
void sortPolarCoor(vector<Point> &ps) {
	sort(ps.begin(),ps.end(),Less);
}

const Point pedal(const Line& l, const Point& p ) {

    double k = l.eval(p)/(l.A*l.A+l.B*l.B);
    return Point(p.x-l.A*k, p.y-l.B*k);
}
const Point pedal(const Point& p, const Line& l)
    { return pedal(l, p); }
const Point mirror(const Line& l, const Point& p)

    { return pedal(l, p) * 2.0 - p; }
const Point mirror(const Point& p, const Line& l)
    { return pedal(l, p) * 2.0 - p; }
const Line perpendicular(const Point& p, const Line& l)

    { return Line(p, pedal(p, l)); }
const Line bisector(const Point& a, const Point& b)

    { return Line((a+b)/2.0, (a+b)/2.0+~(a-b)); }


const Line angleBisector(const Point& A, const Point& B, const Point& C) {
    Point v = (B - A) / (B - A).length();

    Point w = (C - A) / (C - A).length();
    Point O = (A + v + A + w) / 2.0;
    return Line(A, O);
}
const Circle circumcircle(const Point& a, const Point& b, const Point& c) {
    Point p = intersect(bisector(a, b), bisector(b, c));
    return Circle(p, dist(a, p));
}








double dist(const Point& lhs, const Point& rhs)
    { return (lhs-rhs).length(); }
double dist(const Point& p, const Line& l)
    { return fabs(l.eval(p))/hypot(l.A, l.B); }

                                                

double dist(const Line& l, const Point& p)
    { return fabs(l.eval(p))/hypot(l.A, l.B); }
double dist(const Segment& s, const Point& p) {
    if(ps((s.a-p)*(s.a-s.b))^ps((s.b-p)*(s.b-s.a)))

        return min(dist(s.a, p), dist(s.b, p));

    return dist(p, Line(s.a, s.b));
}
double dist(const Point& p, const Segment& s)
    { return dist(s, p); }
double dist(const Line& l, const Segment& s) {
    if(cross(l, s)) return 0.0;
    return min(dist(s.a, l), dist(s.b, l));
}
double dist(const Segment& s, const Line& l)
    { return dist(l, s); }

















double areaSSA(double a, double b, double C)
    { return 0.5*a*b*sin(C); }
double areaSSS(double a, double b, double c)
    { double s=(a+b+c)*0.5; return sqrt(s*(s-a)*(s-b)*(s-c)); }
double areaSAA(double a, double B, double C)
    { return a*a*0.5/(1.0/tan(B)+1.0/tan(C)); }
double area(const Point& pA, const Point& pB, const Point& pC)

    { return fabs((pB-pA)^(pC-pA))*0.5; }
double area(const Vector& v, const Vector& w)

    { return fabs(v^w)*0.5; }
double side_c(double a, double b, double C = PI/2.0) {
    double ans = a*a + b*b - 2.0*a*b*cos(C);
    return nn(ans) ? sqrt(fabs(ans)) : -1.0;
}


const Point gravityCenter(const Point& A, const Point& B, const Point& C)
    { return (A + B + C) / 3.0; }
const Point outterCenter(const Point& A, const Point& B, const Point& C)
    { return intersect(bisector(A, B), bisector(A, C)); }
const Point innerCenter(const Point& A, const Point& B, const Point& C)
    { return intersect(angleBisector(A, B, C), angleBisector(C, B, A)); }
const Point orthoCenter(const Point& A, const Point& B, const Point& C)
    { return intersect(perpendicular(A, Line(B, C)), perpendicular(B, Line(A, C))); }







double Polygon::area() const {
    double ans = 0.0;
    for(int i=0; i<size(); ++i)
        ans += (at(i) ^ at((i+1)%size()));
    return fabs(ans)*0.5;
}

double Polygon::perimeter() const {
    double ans = 0.0;
    for(int i=0; i<size(); ++i)
        ans += dist(at(i), at((i+1)%size()));
    return ans;
}

const Point Polygon::center() const {
    Point ans(0, 0), p;
    double W = 0.0, w;
    for(int i=0; i<size(); ++i) {
        W += (w = (at(i) ^ at((i+1)%size())));
        p = (at(i) + at((i+1)%size())) / 3.0 * w;
        ans += p;
    }
    return ans / W;
}

int quadrant(const Point& p) {
    if(zr(p.x) && zr(p.y))  return -1;

    if(p.x > 0 && p.y >= 0) return 0;
    if(p.x <= 0 && p.y > 0) return 1;
    if(p.x < 0 && p.y <= 0) return 2;
    if(p.x >= 0 && p.y < 0) return 3;
}



int Polygon::within(const Point& p) const {
    int n = 0, qa, qb;
    Point a, b = back() - p;
    for(int i=0; i<size(); ++i) {
        qa = quadrant(a=b);
        qb = quadrant(b=at(i)-p);
        if(qa==-1 || qb==-1) return -1;
        else if(qa==qb) continue;
        else if(qa==(qb+3)%4) ++n;
        else if(qa==(qb+1)%4) --n;
        else if(zr(a^b)) return -1;
        else n += ps(a^b) ? 2 : -2;
    }
    return n ? 1 : 0;
}

Point refP, ctrP;
double xmult(Point lhs, Point rhs, Point ref) {
    return (lhs - ref) ^ (rhs - ref);
}

bool acmp(const Point& lhs, const Point& rhs) {
    return  ng(xmult(lhs, rhs, refP)) ||
            zr(xmult(lhs, rhs, refP)) &&
            ng(xmult(lhs, rhs, ctrP));
}
const Polygon ConvexHull(Polygon P) {
    int i, k = 0;
    for(refP = ctrP = P[0], i = 1; i < P.size(); ++i ) {
        ctrP = ctrP + P[i];
        if(gt(refP.y, P[i].y) || eq(refP.y, P[i].y) &&
            gt(refP.x, P[i].x))  refP = P[k=i];
    }
    ctrP.x /= P.size();
    ctrP.y /= P.size();
    swap(P[k], P[0]);
    sort(P.begin() + 1, P.end(), acmp);
    if( P.size() < 3 )  return  P;
    Polygon CH(P.begin(), P.begin() + 3);
    for(i = k = 3; i < P.size(); ++i, ++k) {
        while(k > 2 && np(xmult(CH[k-2], P[i], CH[k-1])))
            {CH.pop_back(); k--;}
        CH.push_back( P[i] );
    }
    return CH;
}

bool Less2(const Point &a,const Point &b) {
	return a.x<b.x;
}

int n,m;
vector<Point> ps1; 
int main() {
	#ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases=2;
	while(cases--) {
	#endif
		int count=0;
		scanf("%d %d",&n,&m);
		rep(i,0,n-1) {
			double a,b;
			scanf("%lf%lf",&a,&b);
			ps1.push_back(Point(a,b,0));
		}
		rep(i,0,m-1) {
			double a,b;
			scanf("%lf%lf",&a,&b);
			ps1.push_back(Point(a,b,1));
		}
		sort(ps1.begin(),ps1.end(),Less2);
		rep(i,0,(int)ps1.size()-1) {
			if(ps1[i].color==0) {
				x=ps1[i];
				sort(ps1.begin(),ps1.begin()+i,Less);
				
				rep(j,0,i-1) {
					if(ps1[j].color==0) {
						int idx=-1;
						rep(k,j+1,i-1) {							
							if(ps1[k].color==1) {
								if(idx==-1) idx=k;
								else {
									Vector v1=ps1[idx]-ps1[j];
									Vector v2=ps1[k]-ps1[j];
									if((v2^v1)<0) idx=k;
								}
							} else {
								if(idx==-1) count++;
								else {
									Vector v1=ps1[k]-ps1[j];
									Vector v2=ps1[idx]-ps1[j];
								
									if((v1^v2)<=0) count++;
								}
							}
						}
					}
				}	
			
			}
		}
		printf("%d\n",count);
	#ifdef DEBUG	
	}
	#endif
	return 0; 
}
