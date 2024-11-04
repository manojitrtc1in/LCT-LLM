















using namespace std;






static const double PI = acos(-1);

class Point{
    public:
    double x, y;
    
    Point ( double x = 0, double y = 0): x(x), y(y){}
    
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
    Point operator * ( double a ){ return Point(x*a, y*a); }
    Point operator / ( double a ){ return Point(x/a, y/a); }
    Point operator / ( Point p ) { return Point((x*p.x+y*p.y)/(p.x*p.x+p.y*p.y), (y*p.x-x*p.y)/(p.x*p.x+p.y*p.y)); }

    double abs() { return sqrt(norm());}
    double norm() { return x*x + y*y; }

    bool operator < ( const Point &p ) const {
	return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == ( const Point &p ) const {
	return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;

class Segment{
    public:
    Point p1, p2;
  Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}

};

typedef Segment Line;

static const int id10 = 0;
static const int id8 = 1;
static const int id11 = 2;
static const int id5 = 3;

class Circle{
    public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r){}
};

typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }
double arg(Vector p){ return atan2(p.y, p.x); }

Point project( Segment s, Point p ){
    Vector base = s.p2 - s.p1;
    double t = dot(p - s.p1, base)/norm(base);
    return s.p1 + base*t;
}

Point reflect( Segment s, Point p ){
    return p + (project(s, p) - p)*2.0;
}

bool id4( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}

bool id13( Vector a, Vector b ){
     return equals( dot(a, b), 0.0 );
}

bool id13( Point a1, Point a2, Point b1, Point b2 ){
    return id13( a1 - a2, b1 - b2 );
}

bool id13( Segment s1, Segment s2 ){
    return equals( dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0 );
}

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
}

bool isParallel( Point a1, Point a2, Point b1, Point b2){
    return isParallel( a1 - a2, b1 - b2 );
}

bool isParallel( Segment s1, Segment s2 ){
    return equals( cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0 );
}

static const int id3 = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int id15 = 0;





int ccw( Point p0, Point p1, Point p2 ){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > EPS ) return id3;
    if ( cross(a, b) < -EPS ) return CLOCKWISE;
    if ( dot(a, b) < -EPS ) return ONLINE_BACK;
    if ( norm(a) < norm(b) ) return ONLINE_FRONT;
    return id15;
}



bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}





bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}



Point id1(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1/(d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1)*t;
}

Point id0( Line s1, Line s2){
    Vector a = s1.p2 - s1.p1;
    Vector base = s2.p2 - s2.p1;
    return s1.p1 + a * cross(base, s2.p1 - s1.p1)/cross(base, a);
}



double id2(Point p){
    double polar = atan2(p.y, p.x);
    double rad = (dle(0, polar))? polar : 2*PI+polar;
    return rad*180.0/acos(-1);
}


double getAngle(Point p){
    double polar = atan2(p.y, p.x);
    return (dle(0, polar))? polar : 2*PI+polar;
}





double getAngle(Point a, Point b, Point c){
    return arg((a-b)/(c-b));
}

int isIntersect(Circle c1, Circle c2){
    double d = abs(c1.c - c2.c);
    if ( c1.r + c2.r < d ) return id10; 

    if ( d + c2.r < c1.r ) return id11;  

    if ( d + c1.r < c2.r ) return id8;  

    return id5;
}

double id17(Line s, Point p){ 
    return abs(cross(s.p2 - s.p1, p - s.p1)/abs(s.p2 - s.p1));
}



double getDistance(Segment s, Point p){
    if ( dot(s.p2 - s.p1, p - s.p1) < 0.0 ) return abs(p - s.p1);
    if ( dot(s.p1 - s.p2, p - s.p2) < 0.0 ) return abs(p - s.p2);
    return abs(cross(s.p2 - s.p1, p - s.p1)/abs(s.p2 - s.p1));
}
double getDistance(Segment s1, Segment s2){
    if ( isIntersect(s1, s2) ) return 0.0;
    return min( min(getDistance(s1, s2.p1), getDistance(s1, s2.p2)),
		min(getDistance(s2, s1.p1), getDistance(s2, s1.p2)));
}

pair<Point, Point> id12(Circle c1, Circle c2){
  assert( !(c1.c == c2.c) );
    assert( isIntersect( c1, c2 ) );
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a));
}

bool isIntersect( Circle c1, Line l ){
    double d = id17(l, c1.c);
    return ( equals(d, c1.r) || d < c1.r );
}

pair<Point, Point> id12(Circle c, Line l ){
    assert( isIntersect( c, l ) );
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1)/abs(l.p2 - l.p1);
    double base = sqrt(c.r*c.r - norm(pr-c.c));
    return make_pair(pr + e*base, pr - e*base);
}

Polygon cutPolygon( Polygon P, Line l ){
    Polygon u;
    for ( int i = 0; i < P.size(); i++ ){
	Point a = P[i], b = P[(i+1)%P.size()];
	if ( ccw(l.p1, l.p2, a) != CLOCKWISE ) u.push_back(a);
	if ( ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) == -1 ){
	    u.push_back(id0(Segment(a, b), l));
	}
    }
    return u;
}

bool yxCmp( const Point &p1, const Point &p2 ) {
    return (p1.y == p2.y) ? p1.x < p2.x : p1.y < p2.y;
}

class id16{
    public:
    Point o;
    id16( Point o): o(o){}
    bool operator()( const Point &p1,  const Point &p2) const {
	Vector a = Vector(p1.x-o.x, p1.y-o.y); 

	Vector b = Vector(p2.x-o.x, p2.y-o.y); 

	double c = cross(a, b);
	if ( fabs(c) < EPS ) return abs(a) < abs(b);
	return c > 0;
    }
};



Polygon id7( Polygon s ){
 if ( s.size() < 3 ) return s;
    Polygon h;
    Point lm = *min_element(s.begin(), s.end(), yxCmp);
    sort(s.begin(), s.end(), id16(lm));

    for ( int i = 0; i <= 2; i++ ) h.push_back(s[i]);
    for ( int i = 3; i < s.size(); i++ ){
	while( h.size() >= 2 && ccw(h[h.size()-2], h.back(), s[i]) != id3 )
	    h.pop_back();
	h.push_back(s[i]);
    }
    return h;
}


Polygon id14( Polygon s ){
    Polygon u, l;
    if ( s.size() < 3 ) return s;
    sort(s.begin(), s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);
    int n;
    for ( int i = 2; i < s.size(); i++ ){
	for ( int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], s[i]) != CLOCKWISE; n--){
	    u.pop_back();
	}
	u.push_back(s[i]);
    }

    for ( int i = s.size()-3; i >= 0; i-- ){
	for ( int n = l.size(); n >= 2 && ccw(l[n-2], l[n-1], s[i]) != CLOCKWISE; n--){
	    l.pop_back();
	}
	l.push_back(s[i]);
    }
    reverse(l.begin(), l.end());
    for ( int i = u.size()-2; i >= 1; i-- ) l.push_back(u[i]);
    return l;
}


double getArea(Point p1, Point p2, Point p3){
  return abs(0.5 * ((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x)));
}

double getArea(Polygon p){
    double sum = 0.0;
    for(int i = 0; i < p.size(); i++){
	sum += cross(p[i], p[(i+1)%p.size()]);
    }
    return abs(sum/2);
}




Segment shift(Segment s, double d ){
    Vector v = polar(d, arg(s.p2 - s.p1)+PI/2 );
    Segment m = Segment(s.p1 + v, s.p2 + v );
    return m;
}



bool isInside(Polygon g, Point p){
  int n = g.size();
  double a = 0.0;
  for ( int i = 0; i < n; i++ ){
    if ( id4(g[i], g[(i+1)%n], p) ) return true;
    a += getAngle(g[i], p, g[(i+1)%g.size()]);
  }
  return equals(fabs(a), 2*PI);
}


int contains(Polygon g, Point p){
  int n = g.size();
  bool x = false;
  for ( int i = 0; i < n; i++ ){
    Point a = g[i] - p, b = g[(i+1)%n] - p;
    if ( a.y > b.y ) swap(a, b);
    if ( a.y < EPS && EPS < b.y && cross(a, b) > EPS ) x = !x;
    if ( abs(cross(a, b)) < EPS && dot(a, b) < EPS ) return 1;
  }
  return (x?2:0);
}

void check( int a ){
  assert( -10000 <= a && a <= 10000);
}







class EndPoint{
public:
  Point p;
  int seg;
  int st;
  EndPoint(){}
  EndPoint(Point p, int seg, int st):p(p), seg(seg), st(st){}

  bool operator < ( const EndPoint &ep ) const{
    if ( p.y == ep.p.y ){
      return st < ep.st;
    } else return p.y < ep.p.y;
  }
};

int id6(Circle c1, Circle c2){
  Point base = c2.c - c1.c;
  double l = abs(base);
  int cnt = 0;
  if ( abs(c1.r - c2.r) < l  ){
    cnt += 2;
    if ( c1.r + c2.r < l ){
      cnt += 2;
    }
  }
  if ( (equals(l, abs(c1.r - c2.r)) || equals(c1.r + c2.r, l) ) && !equals(l, 0) ) {
    cnt++;
  }
  return cnt;
}

double id9(Circle c2, Circle c1){
  int numc = id6(c1, c2);
  

  

  

  

  

  if ( numc == 4 || numc == 3 ) return 0;
  if ( numc == 1 || numc == 0) return min(acos(-1)*c1.r*c1.r, acos(-1)*c2.r*c2.r);


  double ans = 0;
  double d = abs(c1.c - c2.c);
  for ( int i = 0; i < 2; i++ ){
    {
      double th = abs( acosl((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d)));
      if ( th < acos(-1)/2 ){
	ans += c1.r*c1.r*th - abs(sinl(2*th)*c1.r* c1.r/2);
      } else {
	ans += c1.r*c1.r*th + abs(sinl(2*th)*c1.r* c1.r/2);
      }
    }
    swap(c1, c2);
  }

  return ans;
}

int main(){
  double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double ans = id9(Circle(Point(x1, y1), r1), Circle(Point(x2, y2), r2));
  printf("%.12Lf\n", ans);
					  
  return 0;
}