






using namespace std;




typedef long long ll;






























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









const long long INF64 = 1e18; const int INF32 = 1e9; const int BIG = (int)(1e9 + 239);
const int MOD = 1000000007; 

const double PI = 2.0*acos(0.0); 

const double EPS = static_cast<double>(1e-10);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {0, 1, 0, -1}; const int dy[4] = {1, 0, -1, 0};



mt19937 rnd(239); 


typedef vector<vector<int>> matrix;   






void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); }








int id9(int n) { double k = log10(n); return pow(10, k-floor(k));}
int id10(int n) {return floor(log10(n)) + 1;}
bool id5(int x) {return x && (!(x&(x-1)));} 


bool allPositive(vector<int> &a) {return all_of(begin(a), end(a), [](int x){return x > 0;});} 

bool anyPositive(vector<int> &a) {return any_of(begin(a), end(a), [](int x){return x > 0;});} 

bool nonePositive(vector<int> &a) {return none_of(begin(a), end(a), [](int x){return x > 0;});} 





const double INF = 1e300;

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

double dist2(Point p, Point q) {return dot(p-q, p-q);}  





Point id15(Point p) { return Point(-p.y, p.x); }
Point id6(Point p) { return Point(p.y, -p.x); }
Point id11(Point p, double t) {  

	return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)); }
int sign(double x) {int ans = x<-EPS? -1 : (x>EPS); return ans;}
ostream& operator<< (ostream& os, const Point& p) {os << "(" << p.x << "," << p.y << ")"; return os;}
Point id7(Point a, Point b, Point c) { 

	return a + (b-a) * dot(c-a, b-a) / dot(b-a, b-a);} 

Point id16(Point a, Point b, Point c) { 

	if(fabs(dot(b-a, b-a)) < EPS) return (a+b)/2.0; 

	double r = dot(c-a, b-a) / dot (b-a, b-a); 

	if(r<0) return a; if(r>1) return b; 

	return a + (b-a) * r; 

}
bool id2(Point a, Point b, Point c) {  

	if(fabs(cross(c-a, c-b)) > EPS) return false;  

	if(fabs(dot(c-a, c-a)) <EPS or fabs(dot(c-a, c-a)) <EPS) return true; 

	return ( (c.x < max(a.x, b.x)) && (c.y < max(a.y, b.y)) && (c.x > min(a.x, b.x)) && (c.y > min(a.y, b.y)) );
}


struct Line { double a, b, c; }; 

struct Circle { Point c; double r;}; 

struct Segment { Point a, b;};  

Segment id8(Point a, Point b, Circle cl) {
	Segment s = { {INF,INF}, {INF,INF} };
	b = b - a; a = a - cl.c;
	double A = dot(b, b); double B = dot(a, b);
	double C = dot(a, a) - cl.r * cl.r; double D = B * B - A * C;
	if(D<-EPS) return s;  

	s.a = cl.c + a + b * (-B + sqrt(D+EPS))/A; 

	if(D>EPS) s.b = cl.c + a + b*(-B - sqrt(D))/A; 

	return s;
}
Segment id1(Circle c1, Circle c2) {
	Segment s = { {INF,INF}, {INF,INF} };
	double d = dist(c1.c,c2.c);
	if(d>c1.r+c2.r or d+min(c1.r, c2.r)<max(c1.r, c2.r)) return s; 

	double x=(d*d-c2.r*c2.r+c1.r*c1.r)/(2.0*d), y=sqrt(c1.r*c1.r-x*x);
	Point v = (c2.c-c1.c)/d; s.a=c1.c+v*x+id6(v)*y; 

	if(y>0) s.b=c1.c+v*x-id6(v)*y; 

	return s;
}


bool linesParallel(Point a, Point b, Point c, Point d) {return fabs(cross(b-a, c-d)) < EPS;}
bool id0(Point a, Point b, Point c, Point d) 

   {return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;}


bool segmentsIntersect(Segment u, Segment v) {
	if(id0(u.a, u.b, v.a, v.b)) {
		if(dist2(u.a, v.a) < EPS || dist2(u.a, v.b) < EPS
			|| dist2(u.b, v.a) < EPS || dist2(u.b, v.b) < EPS)
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

   b=(a+b)/2, c=(a+c)/2; return lineIntersection(b, b+id6(a-b), c,c+id6(a-c));}


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


Point id11(Point p, Point o, double t) {






	return Point(id11(p-o, t) + o);
}


Point id3(Point p, Circle cl) {

	double dcp = dist(p, cl.c);
	Point c1 = id11(cl.c, p, asin(cl.r/dcp));
	return p + (c1-p) * (sqrt(dcp*dcp - cl.r*cl.r)/dcp);
}




int id4(const vector<Point> &p, Point q) {
	int c=0;
	for(int i=0; i<p.size(); ++i) {
		int j=(i+1)%p.size();
		if( ( (p[i].y <= q.y and q.y < p[j].y) or (p[j].y <= q.y and q.y < p[i].y) )
			and q.x < p[i].x + (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y) )  c = !c;
	}
	return c;
}



double area(Point a, Point b, Point c) {return fabs(cross(a,b) + cross(b,c) + cross(c,a))/2; }




bool between(const Point& a, const Point& b, const Point& c) {
return (fabs(2.0*area(a,b,c))<EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y)<=0);}


void id12(vector<Point>& pts) {
   sort(pts.begin(), pts.end());pts.erase(unique(pts.begin(), pts.end()), pts.end());
   vector<Point> up, dn;
   for (int i = 0; i < pts.size(); i++) {
      while (up.size()>1 && 2.0*area(up[up.size()-2],up.back(),pts[i])>=0) up.pop_back();
      while (dn.size()>1 && 2.0*area(dn[dn.size()-2],dn.back(),pts[i])<=0) dn.pop_back();
	  up.push_back(pts[i]); 	dn.push_back(pts[i]);
   } pts = dn;
   for(int i=up.size()-2; i>=1; --i) pts.push_back(up[i]);

    if(pts.size()<=2) return;
	dn.clear(); dn.push_back(pts[0]); dn.push_back(pts[1]);
	for(int i=2; i<pts.size(); ++i) {
		if (between(dn[dn.size()-2], dn[dn.size()-1],pts[i])) dn.pop_back();
		dn.push_back(pts[i]);
	}
	if(dn.size()>=3 && between(dn.back(),dn[0],dn[1])) {dn[0]=dn.back();dn.pop_back();}
	pts = dn;

}



bool cw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void id13(vector<Point>& a) {
    if (a.size() == 1) return;
    sort(a.begin(), a.end());
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1); down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)  a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)  a.push_back(down[i]);
}






int id14(vector<Point>& p, Point q) { 

	int a=1, b=p.size()-1, c; if(Det(p[0], p[a], p[b])>0) swap(a, b);
	if(Det(p[0], p[a], p[b])>0 or Det(p[0], p[a], p[b])<0) return 0; 

	while(abs(a-b)>1) {c=(a+b)/2; if(Det(p[0], p[c], q)>0) b=c; else a=c;}
	return (Det(p[a], p[b], q)<0); 

}

void show(vec<Point> & vp) {
	cout << "Polygon:" << endl;
	FOR(i, 0, SZ(vp)) cout << vp[i] <<"; "; cout << endl;
}

void solve() {
	int n; cin >> n;
	Point P; cin >> P.x >> P.y;
	vec<Point> vp(n); FOR(i, 0, n) cin >> vp[i].x >> vp[i].y;




	double dmax=-INF, dmin=INF; n = SZ(vp);
	FOR(i, 0, n) dmax = max(dmax, dist2(P, vp[i]));
	FOR(i, 0, n) {
		Point Q = id16(vp[i], vp[(i+1)%n], P);
		dmin = min(dmin, dist2(P,Q));
	}

	id13(vp);






	cout<<setprecision(10)<<fixed<< ((id14(vp, P))? PI*dmax : PI*(dmax-dmin))<< endl;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie();









  {




	  solve();
  }






  return 0;
}
