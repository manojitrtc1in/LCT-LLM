














const double PI = acos(-1);

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

struct id4 {
  int x,y;
  
  id4(){
    x = 0;
    y = 0;
  }
  
  id4(int x, int y) : x(x), y(y) {}
  
  id4 operator+(const id4 b) const{
    return id4(x + b.x, y + b.y);
  }
  
  id4 operator-(const id4 b) const{
    return id4(x - b.x, y - b.y);
  }
  
  void operator=(const id4 b) {
    x = b.x;
    y = b.y;
  }
  
  double distanceTo(id4 b){
    return sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
  }
  
  int squareDistanceTo(id4 b){
    return (x - b.x)*(x - b.x) + (y - b.y)*(y - b.y);
  }
  
  bool operator<(const id4 & p) const{
    return tie(x,y) < tie(p.x, p.y);
  }
  
};

struct id2 {
  int x,y;
  
  id2(){
    x = 0;
    y = 0;
  }
  
  id2(int x, int y) : x(x), y(y) {}
  
  id2(id4 a, id4 b){
    x = b.x - a.x;
    y = b.y - a.y;
  }
  
  id2 operator+(const id2 b) const{
    return id2(x + b.x, y + b.y);
  }
  
  id2 operator-(const id2 b) const{
    return id2(x - b.x, y - b.y);
  }
  
  void operator=(const id2 b) {
    x = b.x;
    y = b.y;
  }
  
  int operator*(const id2 b) const{
    return (x*b.x + y*b.y);
  }
  
  int operator^(const id2 b) const{
		return x*b.y - y*b.x;
	}
	
	bool operator<(const id2 & v) const{
    return tie(x,y) < tie(v.x, v.y);
  }
	
	id2 scale(int n){
	  return id2(x*n, y*n);
	}
	
	double size(){
	  return sqrt(x*x + y*y);
	}
	
	int squareSize(){
	  return x*x + y*y;
	}
	
	

	id2 normalize(){
	  return id2((double)x/size(), (double)y/size());
	}
	
	id2 rotate(double ang){
	  return id2(x*cos(ang) + y*-sin(ang), x*sin(ang) + y*cos(ang));
	}
	
};

struct id0 {
  id4 p, q;
  id2 v;
  id2 normal;
  
  int a,b,c;
  
  id0() {
    p = id4();
    q = id4();
    v = id2();
    normal = id2();
    a = 0;
    b = 0;
    c = 0;
  }
  
  void operator=(const id0 l){
    a = l.a;
    b = l.b;
    c = l.c;
    p = l.p;
    q = l.q;
    v = l.v;
    normal = l.normal;
  }
  
  id0(id4 r, id4 s){
    p = r;
    q = s;
    v = id2(r, s);
    normal = id2(-v.y, v.x);
    a = -v.y;
    b = v.x;
    c = -(a*p.x + b*p.y);
  }
  
  id0(id4 r, id2 s){
    p = r;
    q = id4(p.x + s.x, p.y + s.y);
    v = s;
    normal = id2(-v.y, v.x);
    a = -v.y;
    b = v.x;
    c = -(a*p.x + b*p.y);
  }
  
  void flip_sign(){
    a = -a, b = -b, c = -c;
  }
  
  void normalize(){
    if(a < 0) flip_sign();
    else if(a == 0 && b < 0) flip_sign();
    else if(a == 0 && b == 0 && c < 0) flip_sign();
    int g = max(a, max(b,c));
    if(a != 0) g = gcd(g, a); if(b != 0) g = gcd(g,b); if(c != 0) g = gcd(g,c);
    if(g > 0) a/=g, b/=g, c/=g;
  }
  
  bool operator<(const id0 & l) const{
    return tie(a,b,c) < tie(l.a, l.b, l.c);
  }
  
};

struct Circle{
  id4 c;
  int r;
  Circle() {}
  Circle(id4 center, int radius) : c(center), r(radius) {}
  bool operator=(Circle circ){
    c = circ.c;
    r = circ.r;
  }
};

struct Geo2D {

  double distancePointLine(id4 p, id0 l){
    return (double)(1.*abs(l.a*p.x + l.b*p.y + l.c))/l.normal.size();
  }
  
  double distancePointSegment(id4 p, id0 l){
    int dot1 = id2(l.p, p)*id2(l.p, l.q);
    int dot2 = id2(l.q, p)*id2(l.q, l.p);
    
    if(dot1 >= 0 && dot2 >= 0) return distancePointLine(p, l);
    else return min(p.distanceTo(l.p), p.distanceTo(l.q));
  }
  
  double distancePointRay(id4 p, id0 l){
    int dot = id2(l.p, p)*l.v;
    if(dot >= 0) return distancePointLine(p, l);
    else return p.distanceTo(l.p);
  }
  
  id4 closestPointInSegment(id4 p, id0 s){
    

    id2 u = s.v.normalize();
    id2 w(s.p, p);
    id2 res = u.scale(u*w);
    if(u*w < 0 || u*w > s.p.distanceTo(s.q)){
      if(p.distanceTo(s.p) < p.distanceTo(s.q)) return s.p;
      else return s.q;
    }
    else return id4(s.p.x + res.x, s.p.y + res.y);
  }
  
  bool intersectionSegmentSegment(id0 s1, id0 s2){
    

    if(s1.p.x > s1.q.x) swap(s1.p, s1.q);
    if(s2.p.x > s2.q.x) swap(s2.p, s2.q);
    if(abs(s1.v^s2.v) <= EPS){
		  id2 v1(s2.p, s1.p);
		  if(s1.p.x == s1.q.x && s2.p.x == s2.q.x && s1.p.x == s2.p.x){
			  id4 ansl, ansr;
			  if(s1.p.y > s1.q.y) swap(s1.p, s1.q);
			  if(s2.p.y > s2.q.y) swap(s2.p, s2.q);
			  if(s1.p.y <= s2.p.y) ansl = s2.p;
			  else ansl = s1.p;
			  if(s2.q.y <= s1.q.y) ansr = s2.q;
			  else ansr = s1.q;
			  if(ansl.x == ansr.x && ansl.y == ansr.y){
			    

			    return true;
			  }
			  else if(ansr.y < ansl.y){
			    

			    return false;
			  }
			  else {
				  if(ansl.x == ansr.x && ansl.y > ansr.y) swap(ansl, ansr);
				  

				  return true;
			  }
		  }
		  else if(abs(s1.v^v1) <= EPS){
			  id4 ansl, ansr;
			  if(s1.p.x <= s2.p.x) ansl = s2.p;
			  else ansl = s1.p;
			  if(s2.q.x <= s1.q.x) ansr = s2.q;
			  else ansr = s1.q;
			  if(ansl.x == ansr.x && ansl.y == ansr.y){
			    

			    return true;
			  }
			  else if(ansr.x < ansl.x){
			    

			    return false;
			  }
			  else {
				  if(ansl.x == ansr.x && ansl.y > ansr.y) swap(ansl, ansr);
				  

				  return true;
			  }
		  }
		  else {
		    

		    return false;
		  }
		
	  }
	  else {
		  int a1 = s1.q.y - s1.p.y;
		  int b1 = s1.p.x - s1.q.x;
		  int c1 = a1*s1.p.x + b1*s1.p.y;
		  int a2 = s2.q.y - s2.p.y;
		  int b2 = s2.p.x - s2.q.x;
		  int c2 = a2*s2.p.x + b2*s2.p.y;
		  int det = a1*b2 - a2*b1;
		  double x = (double)(b2*c1 - b1*c2)/(double)det*1.;
		  double y = (double)(a1*c2 - a2*c1)/(double)det*1.;
		  if(s1.p.x-EPS <= x && x <= s1.q.x+EPS && s2.p.x-EPS <= x && x <= s2.q.x+EPS){
		    

		    return true;
		  }
		  else {
		    

		    return false;
		  }
	  }
  }
  
  double distanceSegmentSegment(id0 l1, id0 l2){
    if((l1.v^l2.v) != 0){
    
      id0 r1(l1.p, l1.q);
      id0 r2(l1.q, l1.p);
      id0 r3(l2.p, l2.q);
      id0 r4(l2.q, l2.p);
      
      int cross1 = (id2(r3.p, r1.p)^r3.v);
      int cross2 = (id2(r3.p, r1.q)^r3.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok1 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r1.p, r3) > distancePointLine(r1.q, r3));
      
      cross1 = (id2(r1.p, r3.p)^r1.v);
      cross2 = (id2(r1.p, r3.q)^r1.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok2 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r3.p, r1) > distancePointLine(r3.q, r1));
      
      cross1 = (id2(r3.p, r2.p)^r3.v);
      cross2 = (id2(r3.p, r2.q)^r3.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok3 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r2.p, r3) > distancePointLine(r2.q, r3));
      
      cross1 = (id2(r2.p, r3.p)^r2.v);
      cross2 = (id2(r2.p, r3.q)^r2.v);
      if(cross2 < cross1) swap(cross1, cross2);
     
      bool ok4 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r3.p, r2) > distancePointLine(r3.q, r2));
      
      cross1 = (id2(r4.p, r1.p)^r4.v);
      cross2 = (id2(r4.p, r1.q)^r4.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok5 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r1.p, r4) > distancePointLine(r1.q, r4));
      
      cross1 = (id2(r1.p, r4.p)^r1.v);
      cross2 = (id2(r1.p, r4.q)^r1.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok6 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r4.p, r1) > distancePointLine(r4.q, r1));
      
      cross1 = (id2(r4.p, r2.p)^r4.v);
      cross2 = (id2(r4.p, r2.q)^r4.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok7 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r2.p, r4) > distancePointLine(r2.q, r4));
      
      cross1 = (id2(r2.p, r4.p)^r2.v);
      cross2 = (id2(r2.p, r4.q)^r2.v);
      if(cross2 < cross1) swap(cross1, cross2);
     
      bool ok8 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r4.p, r2) > distancePointLine(r4.q, r2));
      
      if(ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8) return 0;
      
    }
    
    double ans = distancePointSegment(l1.p, l2);
    ans = min(ans, distancePointSegment(l1.q, l2));
    ans = min(ans, distancePointSegment(l2.p, l1));
    ans = min(ans, distancePointSegment(l2.q, l1));
    return ans;
  }
  
  double distanceSegmentRay(id0 s, id0 r){
    if((s.v^r.v) != 0){
      id0 r1(s.p, s.q);
      id0 r2(s.q, s.p);
      
      int cross1 = (id2(r.p, r1.p)^r.v);
      int cross2 = (id2(r.p, r1.q)^r.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok1 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r1.p, r) > distancePointLine(r1.q, r));
      
      cross1 = (id2(r1.p, r.p)^r1.v);
      cross2 = (id2(r1.p, r.q)^r1.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok2 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r.p, r1) > distancePointLine(r.q, r1));
      
      cross1 = (id2(r.p, r2.p)^r.v);
      cross2 = (id2(r.p, r2.q)^r.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok3 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r2.p, r) > distancePointLine(r2.q, r));
      
      cross1 = (id2(r2.p, r.p)^r2.v);
      cross2 = (id2(r2.p, r.q)^r2.v);
      if(cross2 < cross1) swap(cross1, cross2);
     
      bool ok4 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r.p, r2) > distancePointLine(r.q, r2));
      
      if(ok1 && ok2 && ok3 && ok4) return 0;
    }
      
    
    double ans = INF;
    int dot = id2(s.p, r.p)*id2(r.p, s.q);
    if(dot >= 0) ans = min(ans, distancePointLine(r.p, s));
    else ans = min(ans, min(r.p.distanceTo(s.p), r.p.distanceTo(s.q)));
    
    dot = id2(r.p, s.p)*r.v;
    if(dot >= 0) ans = min(ans, distancePointLine(s.p, r));
    else ans = min(ans, r.p.distanceTo(s.p));
    
    dot = id2(r.p, s.q)*r.v;
    if(dot >= 0) ans = min(ans, distancePointLine(s.q, r));
    else ans = min(ans, r.p.distanceTo(s.q));
    
    return ans;
      
  }
  
  double distanceSegmentLine(id0 s, id0 l){
    if((s.v^l.v) == 0){
      return distancePointLine(s.p, l);
    }
    
    int cross1 = (id2(l.p, s.p)^l.v);
    int cross2 = (id2(l.p, s.q)^l.v);
    if(cross2 < cross1) swap(cross1, cross2);
	  if(cross1 <= 0 && cross2 >= 0) return 0;
	  else return min(distancePointLine(s.p, l), distancePointLine(s.q,l)); 
    
  }
  
  double distanceLineRay(id0 l, id0 r){
    if((l.v^r.v) == 0){
      return distancePointLine(r.p, l);
    }
    
    int cross1 = (id2(l.p, r.p)^l.v);
    int cross2 = (id2(l.p, r.q)^l.v);
    if(cross2 < cross1) swap(cross1, cross2);
	  if((cross1 <= 0 && cross2 >= 0) || (distancePointLine(r.p, l) > distancePointLine(r.q, l))) return 0;
	  return distancePointLine(r.p, l);
  }
  
  double distanceLineLine(id0 l1, id0 l2){
    if((l1.v^l2.v) == 0){
      return distancePointLine(l1.p, l2);
    }
    else return 0;
  }
  
  double distanceRayRay(id0 r1, id0 r2){
    if((r1.v^r2.v) != 0){
      
      int cross1 = (id2(r1.p, r2.p)^r1.v);
      int cross2 = (id2(r1.p, r2.q)^r1.v);
      if(cross2 < cross1) swap(cross1, cross2);
      bool ok1 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r2.p, r1) > distancePointLine(r2.q, r1));
      
      cross1 = (id2(r2.p, r1.p)^r2.v);
      cross2 = (id2(r2.p, r1.q)^r2.v);
      if(cross2 < cross1) swap(cross1, cross2);
      
      bool ok2 = (cross1 <= 0 && cross2 >= 0) || (distancePointLine(r1.p, r2) > distancePointLine(r1.q, r2));
      
      if(ok1 && ok2) return 0;
      
    }
    
    double ans = INF;
    int dot = id2(r2.p, r1.p)*r2.v;
    if(dot >= 0) ans = min(ans, distancePointLine(r1.p, r2));
    else ans = min(ans, r2.p.distanceTo(r1.p));
    
    dot = id2(r1.p, r2.p)*r1.v;
    if(dot >= 0) ans = min(ans, distancePointLine(r2.p, r1));
    else ans = min(ans, r1.p.distanceTo(r2.p));
    
    return ans;
    
  }
  
  double circleCircleIntersection(Circle c1, Circle c2){
  
    if((c1.r+c2.r)*(c1.r+c2.r) <= (c2.c.x-c1.c.x)*(c2.c.x-c1.c.x) + (c2.c.y-c1.c.y)*(c2.c.y-c1.c.y)){
      return 0;
    }
    if((c1.r-c2.r)*(c1.r-c2.r) >= (c2.c.x-c1.c.x)*(c2.c.x-c1.c.x) + (c2.c.y-c1.c.y)*(c2.c.y-c1.c.y)){
      return PI*min(c1.r, c2.r)*min(c1.r, c2.r);
    }
    double x1 = c1.c.x, x2 = c2.c.x, y1 = c1.c.y, y2 = c2.c.y, r1 = c1.r, r2 = c2.r;
    double d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    const double id3 = c1.r*c1.r;
    const double id1 = c2.r*c2.r;
    const double dsqr = d*d;
    
    const double alpha1 = acos(((c1.r + c2.r)*(c1.r - c2.r) + dsqr)/(2.*d*r1));
    const double alpha2 = acos(((c2.r + c1.r)*(c2.r - c1.r) + dsqr)/(2.*d*r2));
    double area1 = id3*(alpha1 - 0.5*sin(2*alpha1));
    double area2 = id1*(alpha2 - 0.5*sin(2*alpha2));
    
    return area1 + area2;
    
  }
  
} id5;

int32_t main() {
  int x1,y1,r1,x2,y2,r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  cout << fixed << setprecision(15);
  
  Circle c1(id4(x1, y1), r1);
  Circle c2(id4(x2, y2), r2);
  
  cout << id5.circleCircleIntersection(c1, c2) << endl;
}