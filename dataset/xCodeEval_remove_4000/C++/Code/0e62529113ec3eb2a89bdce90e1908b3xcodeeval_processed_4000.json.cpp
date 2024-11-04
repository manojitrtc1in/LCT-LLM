

using namespace std;
typedef long long ll;













const int mod = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;











const double EPS =1e-22;

struct Point {
  CT x, y;
  Point() {}
  Point(CT x, CT y) : x(x), y(y) {}
  Point(const Point &p) : x(p.x), y(p.y)    {}
  Point operator + (const Point &p)  const { return Point(x+p.x, y+p.y); }
  Point operator - (const Point &p)  const { return Point(x-p.x, y-p.y); }
  Point operator * (double c)     const { return Point(x*c,   y*c  ); }
  Point operator / (double c)     const { return Point(x/c,   y/c  ); }
};

CT dot(Point p, Point q)     { return p.x*q.x+p.y*q.y; }
double dist2(Point p, Point q)   { return dot(p-q,p-q); }
CT cross(Point p, Point q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const Point &p) {
  os << "(" << p.x << "," << p.y << ")";
}

bool operator < (const Point& a, const Point& b) {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
bool operator == (const Point& a, const Point& b) {
    

    return abs(a.x-b.x)<EPS&&abs(a.y-b.y)<EPS;
    

}




Point id8(Point p)   { return Point(-p.y,p.x); }
Point id13(Point p)    { return Point(p.y,-p.x); }
Point id1(Point p, double t) {
  return Point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}





Point id11(Point a, Point b, Point c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}



Point id14(Point a, Point b, Point c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}


pair<Point,Point> id5(Point a,Point b,Point c){
  c=id11(a,b,c);


  if(a==c) a=b;

  return mp(c,c+id13(a-c));
}


double id0(Point a, Point b, Point c) {
  return sqrt(dist2(c, id14(a, b, c)));
}



double id2(double x, double y, double z,
			  double a, double b, double c, double d)
{
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}



bool LinesParallel(Point a, Point b, Point c, Point d) {
  return fabs(cross(b-a, c-d)) < EPS;
}

bool id15(Point a, Point b, Point c, Point d) {
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS;
}





bool SegmentsIntersect(Point a, Point b, Point c, Point d) {
  if (id15(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}









Point id12(Point a, Point b, Point c, Point d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}



Point id19(Point a, Point b, Point c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return id12(b, b+id13(a-b), c, c+id13(a-c));
}















bool id20(const vector<Point> &p, Point q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}



bool id7(const vector<Point> &p, Point q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(id14(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}





vector<Point> id3(Point a, Point b, Point c, double r) {
  vector<Point> ret;
  b = b-a;
  a = a-c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r*r;
  double D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS)
    ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
}





vector<Point> id9(Point a, Point b, double r, double R) {
  vector<Point> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  Point v = (b-a)/d;
  ret.push_back(a+v*x + id8(v)*y);
  if (y > 0)
    ret.push_back(a+v*x - id8(v)*y);
  return ret;
}









double id6(const vector<Point> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}

double ComputeArea(const vector<Point> &p) {
  return fabs(id6(p));
}

Point id18(const vector<Point> &p) {
  Point c(0,0);
  double scale = 6.0 * id6(p);
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
  }
  return c / scale;
}



bool IsSimple(const vector<Point> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i+1; k < p.size(); k++) {
      int j = (i+1) % p.size();
      int l = (k+1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
	return false;
    }
  }
  return true;
}
typedef vector< Point > Polygon;



CT area2(Point a, Point b, Point c) { return cross(b-a,c-a); }   


bool between(const Point &a, const Point &b, const Point &c) {        

    return abs(area2(a, b, c)) <eps && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0;
}


void id16(vector<Point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
	while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
	while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
	up.push_back(pts[i]);
	dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);


    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
	if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
	dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
	dn[0] = dn.back();
	dn.pop_back();
    }
    pts = dn;

}



bool id4(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);     

    

    if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) return false;
    while(abs(a-b) > 1) {
	c = (a+b)/2;
	if (Det(l[0], l[c], p) > 0) b = c; else a = c;
    }
    

    return Det(l[a], l[b], p) <= 0;
}





vector<line> id17(Point a,Point b,CT r1,CT r2){
  vector<line> Q;
  if(dist2(a,b)<=sqr(r1-r2)) return Q;
  int f=0;
  if(r2>r1) swap(a,b),swap(r1,r2),f=1;
  if(abs(r2-r1)<=EPS){
    line m=id5(a,b,a),n=id5(a,b,b);
    

    vector<Point> l1=id3(m.X,m.Y,a,r1),l2=id3(n.X,n.Y,b,r2);
    assert(l1.size()==2&&l2.size()==2);
    if(cross(b-a,l1[0]-b)*cross(b-a,l2[0]-b)<0) swap(l2[0],l2[1]);
    Q.pb(mp(l1[0],l2[0])); Q.pb(mp(l1[1],l2[1]));
  }else{
    Point out=(b*r1-a*r2)/(r1-r2);
  

    assert(dist2(out,a)>=r1&&dist2(out,b)>=r2);
    vector<Point> l1=id9(a,out,r1,sqrt(dist2(out,a)-sqr(r1))),l2=id9(b,out,r2,sqrt(dist2(out,b)-sqr(r2)));
    assert(l1.size()==2&&l2.size()==2);
    if(cross(b-a,l1[0]-b)*cross(b-a,l2[0]-b)<0) swap(l2[0],l2[1]);
    Q.pb(mp(l1[0],l2[0])); Q.pb(mp(l1[1],l2[1]));
  }


  if(dist2(a,b)>sqr(r1+r2)+EPS){
    Point out=(b*r1+a*r2)/(r1+r2);
  

    assert(dist2(out,a)>=r1&&dist2(out,b)>=r2);
    vector<Point> l1=id9(a,out,r1,sqrt(dist2(out,a)-sqr(r1))),l2=id9(b,out,r2,sqrt(dist2(out,b)-sqr(r2)));
    assert(l1.size()==2&&l2.size()==2);
    if(cross(b-a,l1[0]-b)*cross(b-a,l2[0]-b)>0) swap(l2[0],l2[1]);
    Q.pb(mp(l1[0],l2[0])); Q.pb(mp(l1[1],l2[1]));
  }else if(abs(sqr(r1+r2)-dist2(a,b))<EPS){
    
      Point out=(b*r1+a*r2)/(r1+r2);
    

      Q.pb(id5(a,b,out));
    
  }
  if(f==1){
    REP(i,Q.size()) swap(Q[i].X,Q[i].Y);
  }
  return Q;
}
double error = 1e-8;
Point rect;
vector<pair<Point,double> > circ;

bool inpoly(vector<Point> &a,Point b){
  int n=a.size();
  REP(i,a.size()){
    if(id0(a[i],a[(i+1)%n],b)<error) return 1;
  }
  return id4(a,b);
}
bool outcircle(Point cen,double rad,Point a){
  if(dist2(cen,a)>rad*rad-error) return 1;
  return 0;
}
Point bottom;
bool cmp(Point a,Point b){
    double val=cross(a-bottom,b-a);
    if(fabs(val)<EPS){
	return dist2(bottom,b)>dist2(bottom,a);
    }
    return val>EPS;
}
int id10(vector< Point > &pts){
  sort(all(pts));
  pts.resize(unique(pts.begin(),pts.end())-pts.begin());
  bottom=pts[0];
    sort(pts.begin()+1,pts.end(),cmp);
    vector <Point >hull;
    hull.clear();
    REP(i,pts.size()){
      while(hull.size()>=2&&cross(hull[hull.size()-2]-hull[hull.size()-1],pts[i]-hull[hull.size()-1])>=EPS){
		hull.pop_back();
      }
      hull.push_back(pts[i]);

    }

    pts.clear();
    REP(i,hull.size()){
      pts.pb(hull[i]);
    }
    
    return 0;
}

vector <Point >v;
vector <int > vq;
map< pii, int >idx;
vector<vi> vec(223445);
int main(){
	

	int n,c=0;
	int x,y;
	cin>>n;
  int counter=0;
	REP(i,n){
		scanf("%d%d",&x,&y);
    if(idx.find(mp((int)x,(int)y))==idx.end())
		  idx[mp((int)x,(int)y)]=counter++;
    vec[idx[mp((int)x,(int)y)]].pb(i+1);
		v.pb(Point(1.0/x,1.0/y));
	}		
	id10(v);
	REP(i,v.size()){
		if(-v[i].y+v[i+1].y>-1*EPS){
			vq.pb(idx[mp((int)round(1.0/v[i].x),(int)round(1.0/v[i].y))]);
			break;
		}
		else{
			vq.pb(idx[mp((int)round(1.0/v[i].x),(int)round(1.0/v[i].y))]);
		}
		

	}
	

  vi haha;
	REP(i,vq.size()){
    REP(j,vec[vq[i]].size())
      haha.pb(vec[vq[i]][j]);
		

	}
  sort(all(haha));
  REP(i,haha.size()){
    printf("%d ",haha[i]);
  }

}