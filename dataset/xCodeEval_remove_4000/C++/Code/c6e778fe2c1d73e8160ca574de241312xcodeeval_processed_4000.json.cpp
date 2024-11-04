
using namespace std;





typedef long long ll;
typedef long double ld;
const double eps = 1e-10;
const double INF=1e8;
const double PI = acos(-1.0);
int dcmp(double x) { if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }

double torad(double deg) { return deg/180 * PI; }

struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

typedef Point Vector;
typedef vector<Point> Polygon;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }

bool operator < (const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

Point read_point() {
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x, y);
};

double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Length(const Vector& A) { return sqrt(Dot(A, A)); }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
double Area2(Point A,Point B,Point C){ return Cross(B-A,C-A); }

Vector Rotate(Vector A, double rad) {
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

Vector Normal(Vector A) {

  double L = Length(A);
  return Vector(-A.y/L, A.x/L);
}

Point id2(Point P, Point v, Point Q, Point w) {
  Vector u = P-Q;
  double t = Cross(w, u) / Cross(v, w);
  return P+v*t;
}

Point id8(Point P, Point A, Point B) {

  Vector v = B-A;
  return A+v*(Dot(v, P-A) / Dot(v, v));
}

double id14(Point P, Point A, Point B) {
  Vector v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2)) / Length(v1); 

}

double id5(Point P, Point A, Point B) {
  if(A == B) return Length(P-A);
  Vector v1 = B - A, v2 = P - A, v3 = P - B;
  if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
  else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
  else return fabs(Cross(v1, v2)) / Length(v1);
}

bool id20(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

double id7(Point*p,int n)

{
	double area=0;
	for(int i=1;i<n-1;++i)
	{
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	}
	return area/2;
}

struct Line {
  Point p;    

  Vector v;   

  double ang; 

  Line() {}
  Point point(double t) {
    return p + v*t;
  }
  Line move(double d) {
    return Line(p + Normal(v)*d, v);
  }
  Line(Point p, Vector v):p(p),v(v){ ang = atan2(v.y, v.x); }
  bool operator < (const Line& L) const {
    return ang < L.ang;
  }
};

struct Triangle
{
	Point x,y,z;
	double a,b,c;
	double A,B,C;
	Triangle(Point x,Point y,Point z):x(x),y(y),z(z){
		a=Length(y-z),b=Length(x-z),c=Length(x-y);
		A=acos((b*b+c*c-a*a)/(2*b*c));
		B=acos((a*a+c*c-b*b)/(2*a*c));
		C=acos((a*a+b*b-c*c)/(2*a*b));
	}
	double perimeter()const
	{
		return a+b+c;
	}
	double area()const
	{
		double p=(a+b+c)/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
};

struct Circle {
  Point c;
  double r;
  Circle(Point c=Point(), double r=0):c(c),r(r) {}
  Point point(double a) {
    return Point(c.x + cos(a)*r, c.y + sin(a)*r);  
  }
  double arc(double thita)
  {
  	return thita*r;
  }
  double get_thita(Point p)

  {
  	Vector tmp=p-c;
  	return atan2(tmp.y,tmp.x);
  }
  double perimeter()
  {
  	return 2*PI*r;
  }
};

bool id3(const Point&p,const Circle&c)
{
	return Length(p-c.c)-c.r<-eps;
}

bool id18(const Triangle&t,const Circle&c)
{
	return id3(t.x,c)||id3(t.y,c)||id3(t.z,c);
}

bool id21(const Triangle&t,const Circle&c)
{
	return id3(t.x,c)&&id3(t.y,c)&&id3(t.z,c);
}

double id4(Circle C, Point A, Point B)
{
    Vector OA = A-C.c, OB = B-C.c;
    Vector BA = A-B, BC = C.c-B;
    Vector AB = B-A, AC = C.c-A;
    double DOA = Length(OA), DOB = Length(OB),DAB = Length(AB), r = C.r;
    if(dcmp(Cross(OA,OB)) == 0) return 0;
    if(dcmp(DOA-C.r) < 0 && dcmp(DOB-C.r) < 0) return Cross(OA,OB)*0.5;
    else if(DOB < r && DOA >= r) {
        double x = (Dot(BA,BC) + sqrt(r*r*DAB*DAB-Cross(BA,BC)*Cross(BA,BC)))/DAB;
        double TS = Cross(OA,OB)*0.5;
        return asin(TS*(1-x/DAB)*2/r/DOA)*r*r*0.5+TS*x/DAB;
    }
    else if(DOB >= r && DOA < r) {
        double y = (Dot(AB,AC)+sqrt(r*r*DAB*DAB-Cross(AB,AC)*Cross(AB,AC)))/DAB;
        double TS = Cross(OA,OB)*0.5;
        return asin(TS*(1-y/DAB)*2/r/DOB)*r*r*0.5+TS*y/DAB;
    }
    else if(fabs(Cross(OA,OB)) >= r*DAB || Dot(AB,AC) <= 0 || Dot(BA,BC) <= 0) {
        if(Dot(OA,OB) < 0){
            if(Cross(OA,OB) < 0) return (-acos(-1.0)-asin(Cross(OA,OB)/DOA/DOB))*r*r*0.5;
            else return ( acos(-1.0)-asin(Cross(OA,OB)/DOA/DOB))*r*r*0.5;
        }
        else return asin(Cross(OA,OB)/DOA/DOB)*r*r*0.5;
    }
    else {
        double x = (Dot(BA,BC)+sqrt(r*r*DAB*DAB-Cross(BA,BC)*Cross(BA,BC)))/DAB;
        double y = (Dot(AB,AC)+sqrt(r*r*DAB*DAB-Cross(AB,AC)*Cross(AB,AC)))/DAB;
        double TS = Cross(OA,OB)*0.5;
        return (asin(TS*(1-x/DAB)*2/r/DOA)+asin(TS*(1-y/DAB)*2/r/DOB))*r*r*0.5 + TS*((x+y)/DAB-1);
    }
}

int id16(Line L, Circle C, double& t1, double& t2, vector<Point>& sol){
  double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
  double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d - C.r*C.r;
  double delta = f*f - 4*e*g; 

  if(dcmp(delta) < 0) return 0; 

  if(dcmp(delta) == 0) { 

    t1 = t2 = -f / (2 * e); sol.push_back(L.point(t1));
    return 1;
  }
  

  t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
  t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
  return 2;
}

double angle(Vector v) {

  return atan2(v.y, v.x);
}

int id6(Circle C1, Circle C2, vector<Point>& sol) {
  double d = Length(C1.c - C2.c);
  if(dcmp(d) == 0) {
    if(dcmp(C1.r - C2.r) == 0) return -1; 

    return 0;
  }
  if(dcmp(C1.r + C2.r - d) < 0) return 0;
  if(dcmp(fabs(C1.r-C2.r) - d) > 0) return 0;

  double a = angle(C2.c - C1.c);
  double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
  Point p1 = C1.point(a-da), p2 = C1.point(a+da);

  sol.push_back(p1);
  if(p1 == p2) return 1;
  sol.push_back(p2);
  return 2;
}



int id1(Point p, Circle C, Vector* v) {
  Vector u = C.c - p;
  double dist = Length(u);
  if(dist < C.r) return 0;
  else if(dcmp(dist - C.r) == 0) { 

    v[0] = Rotate(u, PI/2);
    return 1;
  } else {
    double ang = asin(C.r / dist);
    v[0] = Rotate(u, -ang);
    v[1] = Rotate(u, +ang);
    return 2;
  }
}



Circle id0(Point p1, Point p2, Point p3) {
  double Bx = p2.x-p1.x, By = p2.y-p1.y;
  double Cx = p3.x-p1.x, Cy = p3.y-p1.y;
  double D = 2*(Bx*Cy-By*Cx);
  double cx = (Cy*(Bx*Bx+By*By) - By*(Cx*Cx+Cy*Cy))/D + p1.x;
  double cy = (Bx*(Cx*Cx+Cy*Cy) - Cx*(Bx*Bx+By*By))/D + p1.y;
  Point p = Point(cx, cy);
  return Circle(p, Length(p1-p));
}



Circle id11(Point p1, Point p2, Point p3) {
  double a = Length(p2-p3);
  double b = Length(p3-p1);
  double c = Length(p1-p2);
  Point p = (p1*a+p2*b+p3*c)/(a+b+c);
  return Circle(p, id14(p, p1, p2));
}



void get_coord(double R,double lat,double lng,double&x,double&y,double&z)
{
	lat=torad(lat);
	lng=torad(lng);
	x=R*cos(lat)*cos(lng);
	y=R*cos(lat)*sin(lng);
	z=R*sin(lat);
}

vector<Point> id19(vector<Point> p) {
  

  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());

  int n = p.size();
  int m = 0;
  vector<Point> ch(n+1);
  for(int i = 0; i < n; i++) {
    while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  for(int i = n-2; i >= 0; i--) {
    while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
    ch[m++] = p[i];
  }
  if(n > 1) m--;
  ch.resize(m);
  return ch;
}



double PolygonArea(vector<Point> p) {
  double area = 0;
  int n = p.size();
  for(int i = 1; i < n-1; i++)
    area += Cross(p[i]-p[0], p[i+1]-p[0]);
  return area/2;
}

int Dist2(const Point& A, const Point& B) {
  return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}



int id17(vector<Point>& points) {
  vector<Point> p = id19(points);
  int n = p.size();
  if(n == 1) return 0;
  if(n == 2) return Dist2(p[0], p[1]);
  p.push_back(p[0]); 

  int ans = 0;
  for(int u = 0, v = 1; u < n; u++) {
    

    for(;;) {
      

      

      

      

      int diff = Cross(p[u+1]-p[u], p[v+1]-p[v]);
      if(diff <= 0) {
        ans = max(ans, Dist2(p[u], p[v])); 

        if(diff == 0) ans = max(ans, Dist2(p[u], p[v+1])); 

        break;
      }
      v = (v + 1) % n;
    }
  }
  return ans;
}



bool OnLeft(const Line& L, const Point& p) {
  return Cross(L.v, p-L.p) > 0;
}



Point id2(const Line& a, const Line& b) {
  Vector u = a.p-b.p;
  double t = Cross(b.v, u) / Cross(a.v, b.v);
  return a.p+a.v*t;
}



vector<Point> id13(vector<Line> L) {
  int n = L.size();
  sort(L.begin(), L.end()); 

  
  int first, last;         

  vector<Point> p(n);      

  vector<Line> q(n);       

  vector<Point> ans;       


  q[first=last=0] = L[0];  

  for(int i = 1; i < n; i++) {
    while(first < last && !OnLeft(L[i], p[last-1])) last--;
    while(first < last && !OnLeft(L[i], p[first])) first++;
    q[++last] = L[i];
    if(fabs(Cross(q[last].v, q[last-1].v)) < eps) { 

      last--;
      if(OnLeft(q[last], L[i].p)) q[last] = L[i];
    }
    if(first < last) p[last-1] = id2(q[last-1], q[last]);
  }
  while(first < last && !OnLeft(q[first], p[last-1])) last--; 

  if(last - first <= 1) return ans; 

  p[last] = id2(q[last], q[first]); 


  

  for(int i = first; i <= last; i++) ans.push_back(p[i]);
  return ans;
}





inline void id9(const Point& p1, const Point& p2, double& a, double& b, double &c) {
  a = p2.y-p1.y;
  b = p1.x-p2.x;
  c = -a*p1.x - b*p1.y;
}

int id12(const Point& p, const vector<Point>& poly){
  int wn = 0;
  int n = poly.size();
  for(int i = 0; i < n; i++){
    const Point& p1 = poly[i];
    const Point& p2 = poly[(i+1)%n];
    if(p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1; 

    int k = dcmp(Cross(p2-p1, p-p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1; 

  return 0; 

}

bool id10(const vector<Point> ch1, const vector<Point> ch2) {
  int c1 = ch1.size();
  int c2 = ch2.size();
  for(int i = 0; i < c1; i++)
    if(id12(ch1[i], ch2) != 0) return false; 

  for(int i = 0; i < c2; i++)
    if(id12(ch2[i], ch1) != 0) return false; 

  for(int i = 0; i < c1; i++)
    for(int j = 0; j < c2; j++)
      if(id20(ch1[i], ch1[(i+1)%c1], ch2[j], ch2[(j+1)%c2])) return false;
  return true;
}

bool isDiagonal(const Polygon& poly, int a, int b) {
  int n = poly.size();
  for(int i = 0; i < n; i++)
    if(i != a && i != b && OnSegment(poly[i], poly[a], poly[b])) return false; 

  for(int i = 0; i < n; i++)
    if(id20(poly[i], poly[(i+1)%n], poly[a], poly[b])) return false; 

  Point midp = (poly[a] + poly[b]) * 0.5;
  return (id12(midp, poly) == 1); 

}

bool id15(const Polygon&poly,Point a,Point b)
{
	int n=poly.size();
	_for(t,0,n-1)
	{
		if(id20(poly[t],poly[t+1],a,b))return 1;
	}
	return 0;
}
Polygon p;
int n;
double w,v,u;

bool ch(double c)
{
	Point a={v*c,0},b={v*c+v/u*w,w};
	return id15(p,a,b);
}
int main()
{
	cin>>n>>w>>v>>u;
	double mi=1e20,ma=-1e20;
	double ans;
	_for(t,0,n)
	{
		double x,y;cin>>x>>y;
		double e=x-y*v/u;
		mi=min(mi,e);
		ma=max(ma,e);
	}
	if(mi>-eps)ans=w/u;
	else
	{
		if(ma<-eps)ans=w/u;
		else ans=ma/v+w/u;
	}
	printf("%.12lf",ans);
}
