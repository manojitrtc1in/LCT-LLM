






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








int id12(int n) { double k = log10(n); return pow(10, k-floor(k));}
int id13(int n) {return floor(log10(n)) + 1;}
bool id8(int x) {return x && (!(x&(x-1)));} 


bool allPositive(vector<int> &a) {return all_of(begin(a), end(a), [](int x){return x > 0;});} 

bool anyPositive(vector<int> &a) {return any_of(begin(a), end(a), [](int x){return x > 0;});} 

bool nonePositive(vector<int> &a) {return none_of(begin(a), end(a), [](int x){return x > 0;});} 











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



Point id18(Point p) { return Point(-p.y, p.x); }
Point id9(Point p) { return Point(p.y, -p.x); }
Point id15(Point p, double t) {  

	return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)); }
int sign(double x) {int ans = x<-EPS? -1 : (x>EPS); return ans;}
ostream& operator<< (ostream& os, const Point& p) {os << "(" << p.x << "," << p.y << ")"; return os;}
Point id10(Point a, Point b, Point c) { 

	return a + (b-a) * dot(c-a, b-a) / dot(b-a, b-a);} 

Point id19(Point a, Point b, Point c) { 

	if(fabs(dot(b-a, b-a)) < EPS) return (a+b)/2.0; 

	double r = dot(c-a, b-a) / dot (b-a, b-a); 

	if(r<0) return a; if(r>1) return b; 

	return a + (b-a) * r; 

}
bool id3(Point a, Point b, Point c) {  

	if(fabs(cross(c-a, c-b)) > EPS) return false;  

	if(fabs(dot(c-a, c-a)) <EPS or fabs(dot(c-a, c-a)) <EPS) return true; 

	return ( (c.x < max(a.x, b.x)) && (c.y < max(a.y, b.y)) && (c.x > min(a.x, b.x)) && (c.y > min(a.y, b.y)) );
}


struct Line { double a, b, c; }; 

struct Circle { Point c; double r;}; 

struct Segment { Point a, b;};  

Segment id11(Point a, Point b, Circle cl) {
	Segment s = { {INF,INF}, {INF,INF} };
	b = b - a; a = a - cl.c;
	double A = dot(b, b); double B = dot(a, b);
	double C = dot(a, a) - cl.r * cl.r; double D = B * B - A * C;
	if(D<-EPS) return s;  

	s.a = cl.c + a + b * (-B + sqrt(D+EPS))/A; 

	if(D>EPS) s.b = cl.c + a + b*(-B - sqrt(D))/A; 

	return s;
}
Segment id2(Circle c1, Circle c2) {
	Segment s = { {INF,INF}, {INF,INF} };
	double d = dist(c1.c,c2.c);
	if(d>c1.r+c2.r or d+min(c1.r, c2.r)<max(c1.r, c2.r)) return s; 

	double x=(d*d-c2.r*c2.r+c1.r*c1.r)/(2.0*d), y=sqrt(c1.r*c1.r-x*x);
	Point v = (c2.c-c1.c)/d; s.a=c1.c+v*x+id9(v)*y; 

	if(y>0) s.b=c1.c+v*x-id9(v)*y; 

	return s;
}


bool linesParallel(Point a, Point b, Point c, Point d) {return fabs(cross(b-a, c-d)) < EPS;}
bool id0(Point a, Point b, Point c, Point d) 

   {return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;}


bool segmentsIntersect(Segment u, Segment v) {
	if(id0(u.a, u.b, v.a, v.b)) {
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

   b=(a+b)/2, c=(a+c)/2; return lineIntersection(b, b+id9(a-b), c,c+id9(a-c));}


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


Point id15(Point p, Point o, double t) {






	return Point(id15(p-o, t) + o);
}


Point id4(Point p, Circle cl) {

	double dcp = dist(p, cl.c);
	Point c1 = id15(cl.c, p, asin(cl.r/dcp));
	return p + (c1-p) * (sqrt(dcp*dcp - cl.r*cl.r)/dcp);
}




int id6(const vector<Point> &p, Point q) {
	int c=0;
	for(int i=0; i<p.size(); ++i) {
		int j=(i+1)%p.size();
		if( ( (p[i].y <= q.y and q.y < p[j].y) or (p[j].y <= q.y and q.y < p[i].y) )
			and q.x < p[i].x + (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y) )  c = !c;
	}
	return c;
}



int id17(vector<Point>& p, Point q) { 

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





bool between(const Point& a, const Point& b, const Point& c) {
return (fabs(2.0*area(a,b,c))<EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y)<=0);}

void id16(vector<Point>& pts) {
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


struct id14 {
	double x, y, z;
	id14() : x(0), y(0), z(0) {}
	id14(double x, double y, double z) : x(x), y(y), z(z) {}
	bool operator == (const id14 & p) const {return make_pair(x,y) == make_pair(p.x, p.y) && z==p.z;}
    id14 operator = (const id14 & p) { x = p.x, y = p.y, z = p.z;  return *this; }
    id14 operator + (const id14 & p) const { return id14(x+p.x, y+p.y, z+p.z);}
    id14 operator - (const id14 & p) const { return id14(x-p.x, y-p.y, z-p.z);}
    id14 operator * (double c) const { return id14(x*c, y*c, z*c);}
    id14 operator / (double c) const { return id14(x/c, y/c, z/c);}
};
double id5(id14 p, id14 q) {return p.x*q.x + p.y*q.y + p.z*q.z;}


double id20(id14 p, id14 q) {return sqrt(id5(p-q, p-q));}
double id1(id14 p, id14 q) {return id5(p-q, p-q);}



double id7(id14 p, double a, double b, double c, double d) {
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

int area2(Point a, Point b, Point c) { return fabs(cross(b-a, c-a)); }





tuple<int, int, int> calcLine(ii P, ii Q) {
	int a = P.S - Q.S, b = Q.F - P.F, c = -a*P.F - b*P.S;
	int g = __gcd(abs(a), abs(b)); g = __gcd(g, abs(c));
	a /= g, b /= g, c /= g;
	if(a<0 or (a==0 and b<0)) a=-a, b=-b, c=-c;
	tuple<int, int, int> L = {a, b, c};
	return L;
}

const int h = 400003, del = 20001;

vvi gA;

ll hashLine(ii P, ii Q) {
	int a = P.S - Q.S, b = Q.F - P.F, c = -a*P.F - b*P.S; 

	int g;
	if(c==0) g = gA[abs(a)][abs(b)]; 

	else {
		if(a==0 or b==0) g = gA[max(abs(a),abs(b))][abs(c)]; 

		else {g = gA[abs(a)][abs(b)];	g = gA[g][abs(c)];} 

	}
	a /= g, b /= g, c /= g;
	if(a<0 or (a==0 and b<0)) a=-a, b=-b, c=-c;
	a += del, b+= del, c += del;
	return a*h*h + b*h +c;
}












void solve() {
	int n; cin >> n;
	vii vp(n); FOR(i, 0, n) cin >> vp[i].F >> vp[i].S;
	map<ll, int> mp;
	const int gN = 201, gC=gN*101; 


	gA.assign(gN, vi(gC, 1));
	FOR(i, 1, gN) FOR(j, 1, gC) {	int g = __gcd(i, j); 	gA[i][j] = g; 	}
	FOR(i, 1, gN) gA[i][0] = i, gA[0][i] = i;

	FOR(i, 0, n) {


		FOR(j, 0, n) {
			if(i==j) continue;
			ii P = vp[i], Q = vp[j];



















































			ll L = hashLine(P, Q);








				mp[L] += 2;
		}
	}


	ll C3[2002]; C3[2]=0; C3[3]=1; FOR(i, 4, n+1) C3[i] = C3[i-1] * i / (i-3);
	map<int, int> mp2; FOR(i, 1, 2002) mp2[i*i-i] = i; 




	int sum = 0;
	for(auto x : mp) {
		int k = mp2[x.S/2]; 

		sum += C3[k];
	}
	cout << C3[n] - sum << endl; 

















}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie();









  {




	  solve();
  }






  return 0;
}
