




#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;



#define int long long
typedef long long ll;


#define vec vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<ii>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)


#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),(x))-c.begin())
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define RESET(X, y) memset(X, y, sizeof(X))
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define max3(a, b, c) max({a, b, c})
#define min3(a, b, c) min({a, b, c})



void __print(int x) {cout << x;}
void __print(long x) {cout << x;}


void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif




const long long INF64 = 1e18; const int INF32 = 1e9; const int BIG = (int)(1e9 + 239);
const int MOD = 1000000007; 

const double PI = 2.0*acos(0.0); 

const double EPS = static_cast<double>(1e-10);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {0, 1, 0, -1}; const int dy[4] = {1, 0, -1, 0};



mt19937 rnd(239); 


typedef vector<vector<int>> matrix;   






void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); }





#define odd(x) ((x) & 1)
#define even(x) !((x) & 1)

int mostSignDigit(int n) { double k = log10(n); return pow(10, k-floor(k));}
int numOfDigits(int n) {return floor(log10(n)) + 1;}
bool isPowerOfTwo(int x) {return x && (!(x&(x-1)));} 


bool allPositive(vector<int> &a) {return all_of(begin(a), end(a), [](int x){return x > 0;});} 

bool anyPositive(vector<int> &a) {return any_of(begin(a), end(a), [](int x){return x > 0;});} 

bool nonePositive(vector<int> &a) {return none_of(begin(a), end(a), [](int x){return x > 0;});} 







#define double double 



const double INF = 1e100; 


struct Point {
	double x, y;
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
	Point(const Point & p) : x(p.x), y(p.y) {}
	bool operator< (const Point & p) const {return make_pair(x,y) < make_pair(p.x, p.y);}
	bool operator == (const Point & p) const {return make_pair(x,y) == make_pair(p.x, p.y);}
	bool operator != (const Point & p) const {return ! (*this == p); }
    Point operator = (const Point & p) { x = p.x, y = p.y;  return *this; }
    Point operator + (const Point & p) const { return Point(x+p.x, y+p.y);}
    Point operator - (const Point & p) const { return Point(x-p.x, y-p.y);}
    Point operator * (double c) const { return Point(x*c, y*c);}
    Point operator / (double c) const { return Point(x/c, y/c);}  

};
double cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
double dot(Point p, Point q) {return p.x*q.x + p.y*q.y;}
double Det(Point a, Point b, Point c) {return cross(b-a, c-a);}
double dist(Point p, Point q) {return sqrt(dot(p-q, p-q));}  

double distSquare(Point p, Point q) {return dot(p-q, p-q);}  

double area(Point a, Point b, Point c) {return fabs(cross(b-a, c-a)/2.0); } 



Point rotateCCW90(Point p) { return Point(-p.y, p.x); }
Point rotateCW90(Point p) { return Point(p.y, -p.x); }
Point rotateCCW(Point p, double t) {  

	return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)); }
int sign(double x) {int ans = x<-EPS? -1 : (x>EPS); return ans;}
ostream& operator<< (ostream& os, const Point& p) {os << "(" << p.x << "," << p.y << ")"; return os;}
Point projectPointLine(Point a, Point b, Point c) { 

	return a + (b-a) * dot(c-a, b-a) / dot(b-a, b-a);} 

Point projectPointSegment(Point a, Point b, Point c) { 

	if(fabs(dot(b-a, b-a)) < EPS) return (a+b)/2.0; 

	double r = dot(c-a, b-a) / dot (b-a, b-a); 

	if(r<0) return a; if(r>1) return b; 

	return a + (b-a) * r; 

}
bool pointOnSegment(Point a, Point b, Point c) {  

	if(fabs(cross(c-a, c-b)) > EPS) return false;  

	if(fabs(dot(c-a, c-a)) <EPS or fabs(dot(c-a, c-a)) <EPS) return true; 

	return ( (c.x < max(a.x, b.x)) && (c.y < max(a.y, b.y)) && (c.x > min(a.x, b.x)) && (c.y > min(a.y, b.y)) );
}


struct Line { double a, b, c; }; 

struct Circle { Point c; double r;}; 

struct Segment { Point a, b;};  

Segment circleLineIntersection(Point a, Point b, Circle cl) {
	Segment s = { {INF,INF}, {INF,INF} };
	b = b - a; a = a - cl.c;
	double A = dot(b, b); double B = dot(a, b);
	double C = dot(a, a) - cl.r * cl.r; double D = B * B - A * C;
	if(D<-EPS) return s;  

	s.a = cl.c + a + b * (-B + sqrt(D+EPS))/A; 

	if(D>EPS) s.b = cl.c + a + b*(-B - sqrt(D))/A; 

	return s;
}
Segment circleCircleIntersection(Circle c1, Circle c2) {
	Segment s = { {INF,INF}, {INF,INF} };
	double d = dist(c1.c,c2.c);
	if(d>c1.r+c2.r or d+min(c1.r, c2.r)<max(c1.r, c2.r)) return s; 

	double x=(d*d-c2.r*c2.r+c1.r*c1.r)/(2.0*d), y=sqrt(c1.r*c1.r-x*x);
	Point v = (c2.c-c1.c)/d; s.a=c1.c+v*x+rotateCW90(v)*y; 

	if(y>0) s.b=c1.c+v*x-rotateCW90(v)*y; 

	return s;
}


bool linesParallel(Point a, Point b, Point c, Point d) {return fabs(cross(b-a, c-d)) < EPS;}
bool linesCollinear(Point a, Point b, Point c, Point d) 

   {return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;}


bool segmentsIntersect(Segment u, Segment v) {
	if(linesCollinear(u.a, u.b, v.a, v.b)) {
		if(distSquare(u.a, v.a) < EPS || distSquare(u.a, v.b) < EPS
			|| distSquare(u.b, v.a) < EPS || distSquare(u.b, v.b) < EPS)
			return true;
		if(dot(v.a-u.a, v.a-u.b) > 0 && dot(v.b-u.a, v.b-u.b) > 0
				&& dot(v.a-u.b, v.b-u.b) > 0 )
			return false;
		return true;
	}
	if(cross(v.b-u.a, u.b-u.a) * cross(v.a-u.a, u.b-u.a) > 0) return false;
	if(cross(u.a-v.a, v.b-v.a) * cross(u.b-v.a, v.b-v.a) > 0) return false;
	return true;
}




Point lineIntersection(Point a, Point b, Point c, Point d) {
	b = b - a; d = c - d; c = c - a;
	return a + b * cross(c,d)/cross(b,d);
}
Point circleCenter(Point a, Point b, Point c) {

   b=(a+b)/2, c=(a+c)/2; return lineIntersection(b, b+rotateCW90(a-b), c,c+rotateCW90(a-c));}


int orientation(Point a, Point b, Point c) {
	double cr = cross(b-a, c-a);
	if(fabs(cr) <= EPS) return 0; 

	if(cr > EPS ) return 1; 

	return -1;  

}






Point shortest(Point p, Circle cl) {
	Point v = p - cl.c;
	double len = dist(p, cl.c);
	return cl.c + (v/len)*cl.r;
}


Point rotateCCW(Point p, Point o, double t) {






	return Point(rotateCCW(p-o, t) + o);
}


Point tangentCCW(Point p, Circle cl) {

	double dcp = dist(p, cl.c);
	Point c1 = rotateCCW(cl.c, p, asin(cl.r/dcp));
	return p + (c1-p) * (sqrt(dcp*dcp - cl.r*cl.r)/dcp);
}




int pointInPolygonSlow(const vector<Point> &p, Point q) {
	int c=0;
	for(int i=0; i<p.size(); ++i) {
		int j=(i+1)%p.size();
		if( ( (p[i].y <= q.y and q.y < p[j].y) or (p[j].y <= q.y and q.y < p[i].y) )
			and q.x < p[i].x + (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y) )  c = !c;
	}
	return c;
}


#define Det(a,b,c) ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))
int pointInPolygon(vector<Point>& p, Point q) { 

	int a=1, b=p.size()-1, c; if(Det(p[0], p[a], p[b])>0) swap(a, b);
	if(Det(p[0], p[a], p[b])>=0 or Det(p[0], p[a], p[b])<=0) return 0; 

	while(abs(a-b)>1) {c=(a+b)/2; if(Det(p[0], p[c], q)>0) b=c; else a=c;}
	return (Det(p[a], p[b], q)<0); 

}




double signedArea(const vector<Point>& p) {
	double area=0;
	for(int i=0; i<p.size(); ++i) {int j=(i+1)%p.size(); area+=p[i].x*p[j].y-p[j].x*p[i].y;}
	return area/2.0;
}
Point centroid(const vector<Point>& p) {
	Point c(0,0); double scale=6.0*signedArea(p);
	for(int i=0; i<p.size(); ++i) {int j=(i+1)%p.size(); c=c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);}
	return c/scale;
}
int isSimple(const vector<Point> &p) { 

	for(int i=0; i<p.size(); ++i) for(int k=i+1; k<p.size(); ++k) {
		int j=(i+1)%p.size(), l=(k+1)%p.size();
		if(i==l or j==k) continue;
		Segment a = {p[i], p[j]}, b = {p[k], p[l]};
		if(segmentsIntersect(a, b)) return 0;
	}
	return 1;
}


double angle(Point a) { 

	if(a.x==0) if(a.y>0) return PI/2.0; else return 3.0*PI/2.0;
	if(a.y==0) if(a.x>0) return 0; else return PI;
	double res=atan(a.y/a.x); if(a.x<0) return res+PI; if(a.y<0) return res+2.0*PI;
	return res;
}


#define REMOVE_REDUNDANT 

#ifdef REMOVE_REDUNDANT
bool between(const Point& a, const Point& b, const Point& c) {
return (fabs(2.0*area(a,b,c))<EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y)<=0);}
#endif
void ConvexHull(vector<Point>& pts) {
   sort(pts.begin(), pts.end());pts.erase(unique(pts.begin(), pts.end()), pts.end());
   vector<Point> up, dn;
   for (int i = 0; i < pts.size(); i++) {
      while (up.size()>1 && 2.0*area(up[up.size()-2],up.back(),pts[i])>=0) up.pop_back();
      while (dn.size()>1 && 2.0*area(dn[dn.size()-2],dn.back(),pts[i])<=0) dn.pop_back();
	up.push_back(pts[i]); 	dn.push_back(pts[i]);
   } pts = dn;
   for(int i=up.size()-2; i>=1; --i) pts.push_back(up[i]);
#ifdef REMOVE_REDUNDANT
    if(pts.size()<=2) return;
	dn.clear(); dn.push_back(pts[0]); dn.push_back(pts[1]);
	for(int i=2; i<pts.size(); ++i) {
		if (between(dn[dn.size()-2], dn[dn.size()-1],pts[i])) dn.pop_back();
		dn.push_back(pts[i]);
	}
	if(dn.size()>=3 && between(dn.back(),dn[0],dn[1])) {dn[0]=dn.back();dn.pop_back();}
	pts = dn;
   #endif
}


struct Point3D {
	double x, y, z;
	Point3D() : x(0), y(0), z(0) {}
	Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
	bool operator == (const Point3D & p) const {return make_pair(x,y) == make_pair(p.x, p.y) && z==p.z;}
    Point3D operator = (const Point3D & p) { x = p.x, y = p.y, z = p.z;  return *this; }
    Point3D operator + (const Point3D & p) const { return Point3D(x+p.x, y+p.y, z+p.z);}
    Point3D operator - (const Point3D & p) const { return Point3D(x-p.x, y-p.y, z-p.z);}
    Point3D operator * (double c) const { return Point3D(x*c, y*c, z*c);}
    Point3D operator / (double c) const { return Point3D(x/c, y/c, z/c);}
};
double dot3D(Point3D p, Point3D q) {return p.x*q.x + p.y*q.y + p.z*q.z;}


double dist3D(Point3D p, Point3D q) {return sqrt(dot3D(p-q, p-q));}
double dist3DSquare(Point3D p, Point3D q) {return dot3D(p-q, p-q);}



double distPointPlane(Point3D p, double a, double b, double c, double d) {
	return fabs(a*p.x + b*p.y + c*p.z - d) / sqrt(a*a + b*b + c*c);}




bool in(Point A, Point B, Point C, Point D) { 

	double S= area(A, B, C), SC = area(A, B, D), SB = area(A, C, D), SA = area(B, C, D);
	if(SC==0 or SA==0 or SB==0) return false;
	return S == SA + SB + SC;
}

bool isBetween(Point A, Point B, Point C) {

	if(A.x==B.x and A.x==C.x and C.y < max(A.y, B.y) and C.y > min(A.y, B.y)) return true;
	if(A.y==B.y and A.y==C.y and C.x < max(A.x, B.x) and C.x > min(A.x, B.x)) return true;
	if(C.x < max(A.x, B.x) and C.x > min(A.x, B.x) and
			C.y < max(A.y, B.y) and C.y > min(A.y, B.y)) return true;
	return false;
}

int area2(Point a, Point b, Point c) {return fabs(cross(b-a, c-a)); }

void solve() {
	int n; cin >> n;
	vec<Point> vp(n); FOR(i, 0, n) cin >> vp[i].x >> vp[i].y;
	int id0=0, id1=1; Point A = vp[id0], B = vp[id1];
	FOR(i, 2, n) {  

		Point C = vp[i];




		if(area2(A, B, C) != 0) continue;  





		if ( isBetween(A, B, C) )	{ id1=i; B = vp[id1];




			}

	}




	A=vp[id0], B=vp[id1];
	int idx, mn = LLONG_MAX;
	FOR(i, 0, n) {
		if(i==id0 or i==id1) continue;
		int S = area2(A, B, vp[i]);




		if(S==0) continue;
		if(S < mn) {mn = S; idx = i;}




	}
	cout << id0+1 << " " << id1+1 << " " << idx+1 << endl;










}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie();









  {




	  solve();
  }






  return 0;
}
