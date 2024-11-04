#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cassert>
#include<cfloat>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point;
typedef Point Vector;
typedef vector<Point> Polygon;
struct Circle;
struct Segment;
typedef Segment Line;
double norm(Point a);
double abs(Point a);
double dot(Vector a, Vector b);
double cross(Vector a, Vector b);
double getDistance(Point a, Point b);
double getDistanceLP(Line l, Point p);
double getDistanceSP(Segment s, Point p);
double getDistance(Segment s1, Segment s2);
bool isOrthogonal(Vector a, Vector b);
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2);
bool isOrthogonal(Segment s1, Segment s2);
bool isParallel(Vector a, Vector b);
bool isParallel(Point a1, Point a2, Point b1, Point b2);
bool isParallel(Segment s1, Segment s2);
int ccw(Point p0, Point p1, Point p2);
bool intersect(Point p1, Point p2, Point p3, Point p4);
bool intersect(Segment s1, Segment s2);
bool intersect(Circle c, Line l); 

bool intersect(Circle c1, Circle c2); 


Point project(Segment s, Point p);
Point reflect(Segment s, Point p);
Point getCrossPoint(Segment s1, Segment s2);
pair<Point,Point> getCrossPoints(Circle c, Line l);
pair<Point,Point> getCrossPoints(Circle c1, Circle c2); 

pair<Point,Point> getContactPoints(Circle c, Point p); 


double area(Polygon g); 

bool isConvex(Polygon g); 

int contains(Polygon g, Point p);

double arg(Vector p);   

Vector polar(double a, double r); 


Polygon andrewScan(Polygon g); 

double convexDiameter(Polygon g); 


struct Line2d;  

void tangents(Point p, double r1, double r2, vector<Line2d> &v);    

vector<Line2d> commonTangents(Circle c1, Circle c2);

double smallestEnclosingCircle(Polygon g);  



struct Point{
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator + (Point p){ return Point(x+p.x, y+p.y); }
    Point operator - (Point p){ return Point(x-p.x, y-p.y); }
    Point operator * (double a){ return Point(a*x, a*y); }
    Point operator / (double a){ return Point(x/a, y/a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x*x + y*y; }

    bool operator < (const Point &p) const{
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const{
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;
typedef vector<Point> Polygon;

struct Circle{
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

struct Segment{
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

typedef Segment Line;


double norm(Point a){
    return a.x * a.x + a.y * a.y;
}

double abs(Point a){
    return sqrt(norm(a));
}

double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

double getDistance(Point a, Point b){
    return abs(a - b);
}

double getDistanceLP(Line l, Point p){
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.p2-s.p1, p-s.p1) < 0.0)    return abs(p-s.p1);
    if(dot(s.p1-s.p2, p-s.p2) < 0.0)    return abs(p-s.p2);
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
    if(intersect(s1, s2))   return 0.0;
    return min({getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2), 
                getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)});
}


bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0.0);
}
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
    return isOrthogonal(a1-a2, b1-b2);
}
bool isOrthogonal(Segment s1, Segment s2){
    return equals(dot(s1.p2-s1.p1, s2.p2-s2.p1), 0.0);
}
bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0.0);
}
bool isParallel(Point a1, Point a2, Point b1, Point b2){
    return isParallel(a1-a2, b1-b2);
}
bool isParallel(Segment s1, Segment s2){
    return equals(cross(s1.p2-s1.p1, s2.p2-s2.p1), 0.0);
}


static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;   

static const int ONLINE_FRONT = -2; 

static const int ON_SEGMENT = 0;    

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS)   return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS)  return CLOCKWISE;
    if(dot(a, b) < -EPS)    return ONLINE_BACK;
    if(norm(a) < norm(b))   return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2){
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
bool intersect(Circle c, Line l){
    return getDistanceLP(l, c.c) < c.r+EPS;
}
bool intersect(Circle c1, Circle c2){
    return abs(c1.r-c2.r) <= getDistance(c1.c, c2.c) && getDistance(c1.c, c2.c) < c1.r+c2.r+EPS;
}

Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p){
    return p + (project(s, p) - p) * 2.0;
}

Point getCrossPoint(Segment s1, Segment s2){
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1-s2.p1));
    double d2 = abs(cross(base, s1.p2-s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

pair<Point,Point> getCrossPoints(Circle c, Line l){
    assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(fabs(c.r * c.r - norm(pr - c.c)));
    return make_pair(pr + e*base, pr - e*base);
}

pair<Point,Point> getCrossPoints(Circle c1, Circle c2){
    assert(intersect(c1, c2));
    double d = abs(c1.c - c2.c);
    double a = acos( (c1.r*c1.r + d*d - c2.r*c2.r)/(2*c1.r*d) );
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t+a), c1.c + polar(c1.r, t-a));
}

pair<Point,Point> getContactPoints(Circle c, Point p){
    assert(c.r < getDistance(c.c, p));
    double d = getDistance(c.c, p);
    return getCrossPoints(c, Circle(p, sqrt(d*d-c.r*c.r)));
}

double area(Polygon g){
    if(g.size() < 3)    return 0;
    int n = g.size();
    Point o(0.0, 0.0);
    double s = 0.0;
    for(int i = 0; i < n; i++)  s += cross(g[i]-o, g[(i+1)%n]-o);
    return abs(s) / 2.0;
}

bool isConvex(Polygon g){
    bool ret = true;
    int n = g.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(cross(g[i]-g[(i+n-1)%n], g[j]-g[(i+n-1)%n]) < -EPS || cross(g[(i+1)%n]-g[i], g[j]-g[i]) < -EPS){
                ret = false;
            }
        }
    }
    return ret;
}

static const int IN = 2;
static const int ON = 1;
static const int OUT = 0;
int contains(Polygon g, Point p){
    int n = g.size();
    bool x = false;
    for(int i = 0; i < n; i++){
        Point a = g[i] - p, b = g[(i+1)%n] - p;
        if(abs(cross(a, b)) < EPS && dot(a, b) < EPS)   return ON;
        if(a.y > b.y)   swap(a, b);
        if(a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
    }
    return x ? IN : OUT;
}


double arg(Vector p){
    return atan2(p.y, p.x);
}

Vector polar(double a, double r){
    return Point(a * cos(r), a * sin(r));
}


Polygon andrewScan(Polygon g){
    Polygon u, l;
    if(g.size() < 3)    return g;
    

    u.push_back(g[0]);
    u.push_back(g[1]);
    l.push_back(g[g.size()-1]);
    l.push_back(g[g.size()-2]);

    

    for(int i = 2; i < g.size(); i++){
        for(int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], g[i]) != CLOCKWISE; n--){
            u.pop_back();
        }
        u.push_back(g[i]);
    }

    

    for(int i = g.size()-3; i >= 0; i--){
        for(int n = l.size(); n >= 2 && ccw(l[n-2], l[n-1], g[i]) != CLOCKWISE; n--){
            l.pop_back();
        }
        l.push_back(g[i]);
    }

    reverse(l.begin(), l.end());
    for(int i = u.size()-2; i >= 1; i--)    l.push_back(u[i]);

    return l;
}

double convexDiameter(Polygon g){
    double d = 0.0;
    int n = g.size();
    int is = 0, js = 0;
    for(int i = 1; i < n; i++){
        if(g[i].y > g[is].y)    is = i;
        if(g[i].y < g[js].y)    js = i;
    }
    d = getDistance(g[is], g[js]);

    int i = is, j = js, maxi = is, maxj = js;
    do{
        if(cross(g[(i+1)%n]-g[i], g[(j+1)%n]-g[j]) >= 0.0)  j = (j+1)%n;
        else    i = (i+1)%n;
        if(getDistance(g[i], g[j]) > d){
            d = getDistance(g[i], g[j]);
            maxi = i, maxj = j;
        }
    }while(i != is || j != js);

    return d; 

}


struct Line2d{
    double a, b, c;
    double eval(double x){
        

        return (-a*x-c)/b;   
    }
};

void tangents(Point p, double r1, double r2, vector<Line2d> &v){
    double r = r2-r1;
    double z = p.x*p.x + p.y*p.y;
    double d = z - r*r;
    if(d < -EPS)    return; 

    d = sqrt(d);
    Line2d l;
    l.a = (p.x*r + p.y*d) / z;
    l.b = (p.y*r - p.x*d) / z;
    l.c = r1;
    v.push_back(l);
}

vector<Line2d> commonTangents(Circle c1, Circle c2){
    if(c1.r > c2.r) swap(c1, c2);
    vector<Line2d> ans;
    if(c1.c == c2.c && c1.r == c2.r)            return ans;
    if(getDistance(c1.c, c2.c) < c2.r-c1.r)     return ans;
    for(int i : {-1, 1}){
        for(int j : {-1, 1}){
            tangents(c2.c-c1.c, c1.r*i, c2.r*j, ans);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        ans[i].c -= ans[i].a*c1.c.x + ans[i].b*c1.c.y;
    }
    return ans;
}

double smallestEnclosingCircle(Polygon g){
    double ret = DBL_MAX;
    int n = g.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double mx = (g[i].x+g[j].x)/2.0, my = (g[i].y+g[j].y)/2.0;
            double r = sqrt(pow(g[i].x-mx, 2.0)+pow(g[i].y-my, 2.0));
            bool valid = true;
            vector<bool> in(n, 0);
            for(int k = 0; k < n; k++){
                in[k] = sqrt(pow(g[k].x-mx,2.0)+pow(g[k].y-my,2.0)) <= r+EPS;
                valid &= in[k];
            }
            if(valid)   ret = min(ret, r);
            for(int k = 0; k < n; k++){
                if(in[k])   continue;
                double a = g[j].x-g[i].x;
                double b = g[k].x-g[j].x;
                double c = g[j].y-g[i].y;
                double d = g[k].y-g[j].y;
                double X = -(g[i].x*g[i].x-g[j].x*g[j].x+g[i].y*g[i].y-g[j].y*g[j].y);
                double Y = -(g[j].x*g[j].x-g[k].x*g[k].x+g[j].y*g[j].y-g[k].y*g[k].y);
                double cy = X/2*b - Y/2*a;
                cy /= (b*c-a*d);
                double cx = (X/2-c*cy)/a;
                double radius = sqrt(pow(g[k].x-cx,2.0)+pow(g[k].y-cy,2.0));
                if(radius > r){
                    r = radius;
                    mx = cx;
                    my = cy;
                }
            }
            valid = true;
            for(int k = 0; k < n; k++){
                valid &= sqrt(pow(g[k].x-mx,2.0)+pow(g[k].y-my,2.0)) <= r+EPS;
            }
            if(valid)   ret = min(ret, r);
        }
    }
    

    return ret;
}






int main(){
    int n;
    scanf("%d", &n);
    Polygon g;
    g.push_back({0, 0});
    double sum = 0;
    for(int i = 0; i < n; i++){
        int y;
        scanf("%d", &y);
        sum += y;
        g.push_back({(double)(i+1), sum});
    }
    Polygon ch = andrewScan(g);
    vector<double> ret(n+1, 0);
    for(int i = 0; i+1 < ch.size(); i++){
        int from = (int)ch[i].x, to = (int)ch[i+1].x;
        if(from > to)   break;
        double sub = ch[i+1].y-ch[i].y;
        for(int j = from; j <= to; j++){
            ret[j] = ch[i].y+sub/(to-from)*(j-from);
        }
    }
    for(int i = 1; i <= n; i++) printf("%.12f\n", ret[i]-ret[i-1]);
    return 0;
}