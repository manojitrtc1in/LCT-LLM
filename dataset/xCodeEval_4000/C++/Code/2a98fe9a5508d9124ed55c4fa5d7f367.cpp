#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

typedef long long int llint;
typedef pair<int,int> para;

#define PI 3.141592653589793238462643383279502884L

class Angle { 

double a; 


void normalize(void) {
while(a<0) a+=360;
while(a>=360) a-=360;
}

public:
Angle(void) {a=0;}
Angle(double _a, bool rad=0) {
    if (rad) _a=_a/PI*180;
    a = _a;
    normalize();
    }

double toRadians(void) const {return a/180*PI;}
double toDegrees(void) const {return a;}

Angle& operator+=(const Angle& n) {(*this)=(*this)+n; return (*this);}
Angle& operator-=(const Angle& n) {(*this)=(*this)-n; return (*this);}
Angle& operator*=(double n) {(*this)=(*this)*n; return (*this);}
Angle& operator/=(double n) {(*this)=(*this)/n; return (*this);}

friend const Angle operator+(const Angle& l, const Angle& r);
friend const Angle operator-(const Angle& l, const Angle& r);


friend const Angle operator*(const Angle& l, double r);
friend const Angle operator/(const Angle& l, double r);
friend const Angle operator*(double l, const Angle& r);
friend istream& operator>>(istream& is, Angle& a);
friend ostream& operator<<(ostream& os, const Angle& a);
};

const Angle operator+(const Angle& l, const Angle& r) { return Angle(l.a+r.a); }
const Angle operator-(const Angle& l, const Angle& r) { return Angle(l.a-r.a); }
const Angle operator*(const Angle& l, double r) {
double tmp = l.toDegrees()*r;
tmp-=(((long long int)tmp)/360)*360;
return Angle(tmp);
}
const Angle operator/(const Angle& l, double r) { return Angle(l.a/r); }
const Angle operator*(double l, const Angle& r) { return r*l; }
istream& operator>>(istream& is, Angle& a) {is>>a.a; return is;}
ostream& operator<<(ostream& os, const Angle& a) {os<<a.a; return os;}

class Point { 

public:
double x;
double y;

Point(void) {x=0; y=0;}
Point(double _x, double _y) {x=_x; y=_y;}

friend istream& operator>>(istream& is, Point& p);
friend ostream& operator<<(ostream& os, const Point& p);

friend bool operator!=(const Point& l, const Point& r) {return l!=r;}

friend bool operator==(const Point& l, const Point& r);
};

bool operator==(const Point& l, const Point& r) {return l.x==r.x && l.y==r.y;}

istream& operator>>(istream& is, Point& p) {is>>p.x>>p.y; return is;}
ostream& operator<<(ostream& os, const Point& p) {os<<p.x<<' '<<p.y; return os;}

class Vector { 

public:
double x;
double y;

Vector(void) {x=0; y=0;}
Vector(double _x, double _y) {x=_x; y=_y;}
Vector(Point a, Point b) {x=b.x-a.x; y=b.y-a.y;}

double getLengthSquare(void) const {return x*x+y*y;}
double getLength(void) const {return sqrt(getLengthSquare());}

Angle getAngle(void) const { return Angle(atan2(y, x), 1); }

Vector& operator+=(const Vector& n) {(*this)=(*this)+n; return (*this);}
Vector& operator-=(const Vector& n) {(*this)=(*this)-n; return (*this);}
Vector& operator*=(double n) {(*this)=(*this)*n; return (*this);}
Vector& operator/=(double n) {(*this)=(*this)/n; return (*this);}

friend const Vector operator+(const Vector& l, const Vector& r);
friend const Vector operator-(const Vector& l, const Vector& r);
friend const Vector operator*(const Vector& l, double r);
friend const Vector operator/(const Vector& l, double r);
friend const Vector operator*(double l, const Vector& r);
friend istream& operator>>(istream& is, Vector& v);
friend ostream& operator<<(ostream& os, const Vector& v);



friend bool operator> (const Vector& l, const Vector& r) {return r<l;}
friend bool operator>=(const Vector& l, const Vector& r) {return !(l<r);}
friend bool operator<=(const Vector& l, const Vector& r) {return !(l>r);}

friend bool operator<(const Vector& l, const Vector& r);
};

const Vector operator+(const Vector& l, const Vector& r) { return Vector(l.x+r.x, l.y+r.y); }
const Vector operator-(const Vector& l, const Vector& r) { return Vector(l.x-r.x, l.y-r.y); }
const Vector operator*(const Vector& l, double r) { return Vector(l.x*r, l.y*r); }
const Vector operator/(const Vector& l, double r) { return Vector(l.x/r, l.y/r); }
const Vector operator*(double l, const Vector& r) { return Vector(l*r.x, l*r.y); }

istream& operator>>(istream& is, Vector& v) {is>>v.x>>v.y; return is;}
ostream& operator<<(ostream& os, const Vector& v) {os<<v.x<<' '<<v.y; return os;}

bool operator<(const Vector& l, const Vector& r) {
return (l.x*r.y-l.y*r.x>0);
}

enum class Halfplane{Top, Bottom, Border}; 


class Line { 

double A, B, C; 


public:
Line(void) {A=0; B=0; C=0;}

Line(Point p1, Point p2) {A = p1.y-p2.y; B = p2.x-p1.x; C = p1.x*p2.y-p2.x*p1.y;}
Line(Point p, Vector v) : Line(p, Point(p.x+v.x, p.y+v.y)) {}
Line(double _A, double _B, double _C) {A=_A; B=_B; C=_C;}

double getA(void) const {return A;}
double getB(void) const {return B;}
double getC(void) const {return C;}

Vector getNormal(void) const {return Vector(A, B);}
Vector getDirection(void) const {return Vector(-B, A);}

Halfplane operator()(Point p) {
double d = A*p.x+B*p.y+C;
if (d>0) return Halfplane::Top;
if (d<0) return Halfplane::Bottom;
return Halfplane::Border;
}

friend bool operator!=(const Line& l, const Line& r) {return l!=r;}

friend bool operator==(const Line& l, const Line& r);
};

bool operator==(const Line& l, const Line& r) {
if (l.A*r.B!=l.B*r.A) return 0;
if (l.A*r.C!=l.C*r.A) return 0;
if (l.B*r.C!=l.C*r.B) return 0;
return 1;
}

class Polygon { 

vector<Point> v; 

int n; 


int getLeftofBottomIndex(void) const {
Point ans = v[0];
int ind = 0;
for(int i=0; i<n; i++) {
    Point it = v[i];
    if (it.y<ans.y || (it.y==ans.y && it.x < ans.x)) {ans=it; ind=i;}
    }
return ind;
}

public:
Polygon(void) {n=0;}
Polygon(const vector<Point>& _v) { 

v = _v;
n = v.size();

Vector v1(v[0], v[1]), v2(v[1], v[2]);
if (v1>v2) reverse(v.begin(), v.end());

int ind = getLeftofBottomIndex();
rotate(v.begin(), v.begin()+ind, v.end());
}

int getSize(void) const {
return n;
}



bool isContainPoint(Point p, bool strict=0) const { 

for(int i=0; i<(int)v.size(); i++) {
    Line l(v[i], v[(i+1)%n]);
    if (l(p)==Halfplane::Border) {
        if (strict) return 0;
        continue;
        }
    if (l(p)!=l(v[(i+2)%n])) return 0;
    }
return 1;
}

Point getLeftofBottom(void) const {
return v[0];
}

vector<Vector> asVectorArray(void) const {
vector<Vector> t;
for(int i=0; i<n; i++) {
    int i1=i, i2=i+1;
    if (i2==n) i2=0;
    t.push_back(Vector(v[i1], v[i2]));
    }
return t;
}

Polygon getInversed(void) const { 

vector<Point> ans = v;
for(auto& it: ans) {
    it.x*=-1;
    it.y*=-1;
    }
return Polygon(ans);
}

double getArea(void) const {
double ans=0;
for(int i=1; i+1<n; i++) {
    Vector v1(v[0], v[i]);
    Vector v2(v[0], v[i+1]);
    ans+=fabs(v1.x*v2.y-v1.y*v2.x);
    }
return ans/2;
}
};

class Segment { 

public:
Point p1, p2; 


Segment(void) {}
Segment(Point _p1, Point _p2) {p1=_p1; p2=_p2;}

Point getMiddle(void) const {return Point((p1.x+p2.x)/2, (p1.y+p2.y)/2);}
};

class Circle { 

Point c;
double r; 


public:
Circle(void) {}
Circle(Point _c, double _r) {c=_c; r=_r;}
Circle(Point p1, Point p2, Point p3) { 

double Ax=p1.x, Ay=p1.y, Bx=p2.x, By=p2.y, Cx=p3.x, Cy=p3.y;
double D, Ux, Uy;
D = 2*( Ax*( By-Cy ) +Bx*( Cy-Ay ) +Cx*( Ay-By ) );
Ux =(( Ax*Ax+Ay*Ay ) *( By-Cy ) +( Bx*Bx+By*By ) *( Cy-Ay ) +( Cx*Cx+Cy*Cy ) *( Ay-By ) )/D;
Uy =(( Ax*Ax+Ay*Ay ) *( Cx-Bx ) +( Bx*Bx+By*By ) *( Ax-Cx ) +( Cx*Cx+Cy*Cy ) *( Bx-Ax ) )/D;
c = Point(Ux, Uy);
r = Vector(c, p1).getLength();
}

Point getCenter(void) const {return c;}
double getRadius(void) const {return r;}
bool isInCircle(Point p, bool strict=0) const {
double x = p.x-c.x, y = p.y-c.y;
double d = x*x+y*y;
return d<r*r || (d==r*r && !strict);
}

friend bool operator!=(const Circle& l, const Circle& r) {return l!=r;}

friend bool operator==(const Circle& l, const Circle& r);
};

bool operator==(const Circle& l, const Circle& r) {return l.c==r.c && l.r==r.r;}

enum class FigureType {
Nothing, Point, Segment, Line, Circle, TwoPoints
};

class SomeFigure { 

public:
FigureType type;
Point point;
Segment segment;
Line line;
Circle circle;
Point secondPoint;

SomeFigure(void) {type=FigureType::Nothing;}
SomeFigure(Point p) {type=FigureType::Point; point=p;}
SomeFigure(Segment s) {type=FigureType::Segment; segment=s;}
SomeFigure(Line l) {type=FigureType::Line; line=l;}
SomeFigure(Circle c) {type=FigureType::Circle; circle=c;}
SomeFigure(Point p1, Point p2) {type=FigureType::TwoPoints; point=p1; secondPoint=p2;}
};

Angle minForm(Angle a) {
if (a.toDegrees()<=180) return a;
return 360-a;
}

Angle getAngle(Vector v1, Vector v2) { 

return v2.getAngle()-v1.getAngle();
}

Vector makeVector(double r, Angle a) {
return Vector(r*cos(a.toRadians()), r*sin(a.toRadians()));
}

double pointToLineDistance(Point p, Line l) {
double a=l.getA(), b=l.getB(), c=l.getC();
return fabs(a*p.x+b*p.y+c)/sqrt(a*a+b*b);
}

Point pointOnLineProjection(Point p, Line l) {
double a=l.getA(), b=l.getB(), c=l.getC();
double x = (b*(b*p.x-a*p.y)-a*c)/(a*a+b*b);
double y = (a*(-b*p.x+a*p.y)-b*c)/(a*a+b*b);
return {x, y};
}

Line middlePerpendicular(Segment s) {
Point p = s.getMiddle();
Vector v = Line(s.p1, s.p2).getNormal();
return Line(p, v);
}

SomeFigure lineIntersection(Line l1, Line l2) {
if (l1==l2) return l1;
double A1 = l1.getA(), A2 = l2.getA();
double B1 = l1.getB(), B2 = l2.getB();
double C1 = l1.getC(), C2 = l2.getC();
double tmp = A1*B2-B1*A2;
if (tmp==0) return SomeFigure();
return Point(-(C1*B2-C2*B1)/tmp, -(A1*C2-A2*C1)/tmp);
}

SomeFigure segmentIntersection(Segment s1, Segment s2) {
Line l1(s1.p1, s1.p2), l2(s2.p1, s2.p2);

if (l1(s2.p1)==Halfplane::Border && l1(s2.p2)==Halfplane::Border) { 

    Line lp(s1.p1, l1.getNormal());

    Point p[3] = {s1.p2, s2.p1, s2.p2};
    double d[3];
    for(int i=0; i<3; i++) {
        Vector v(s1.p1, p[i]);
        d[i]=v.getLengthSquare();
        if (lp(p[i])!=lp(s1.p2)) d[i]*=-1;
        }

    if (d[1]<=0 && d[2]<=0) {
        if (d[1]==0 || d[2]==0) return s1.p1;
        return SomeFigure();
        }

    if (d[1]<=0 || d[2]<=0) {
        Point to_ans = p[0];
        if (d[1]>0 && d[1]<d[0]) to_ans = p[1];
        if (d[2]>0 && d[2]<d[0]) to_ans = p[2];
        return Segment(s1.p1, to_ans);
        }

    if (d[1]<=d[0] && d[2]<=d[0]) {
        return Segment(p[1], p[2]);
        }

    if (d[1]<=d[0] || d[2]<=d[0]) {
        if (d[1]==d[0] || d[1]==d[2]) return s1.p2;
        if (d[1]<d[2]) return Segment(p[1], s1.p2);
        return Segment(p[2], s1.p2);
        }

    return SomeFigure();
    }

if (l1(s2.p1)==Halfplane::Border || l1(s2.p2)==Halfplane::Border) { 

    Point p;
    if (l1(s2.p1)==Halfplane::Border) p=s2.p1; else p=s2.p2;
    Line lp(p, l1.getNormal());
    if (lp(s1.p1)!=lp(s1.p2)) return p;
    return SomeFigure();
    }

if (l2(s1.p1)==Halfplane::Border || l2(s1.p2)==Halfplane::Border) { 

    Point p;
    if (l2(s1.p1)==Halfplane::Border) p=s1.p1; else p=s1.p2;
    Line lp(p, l2.getNormal());
    if (lp(s2.p1)!=lp(s2.p2)) return p;
    return SomeFigure();
    }



if (l1(s2.p1)==l1(s2.p2)) return SomeFigure();
if (l2(s1.p1)==l2(s1.p2)) return SomeFigure();
return lineIntersection(l1, l2);
}

SomeFigure lineAndCircleIntersection(Line l, Circle cir) {
double a = l.getA(), b = l.getB(), c = l.getC();
double r = cir.getRadius();
Point p = cir.getCenter();
c = c + a*p.x + b*p.y;
double z = a*a+b*b;
double t = c*c - r*r*z;
if (t>0) return SomeFigure();
double x0 = -a*c/z, y0 = -b*c/z;
if (t==0) return Point(x0, y0);
double d = r*r - c*c/z;
double m = sqrt(d/z);
Point p1(x0+b*m+p.x, y0-a*m+p.y);
Point p2(x0-b*m+p.x, y0+a*m+p.y);
return SomeFigure(p1, p2);
}

SomeFigure circleAndCircleIntersection(Circle c1, Circle c2) {
Point p1 = c1.getCenter();
Point p2 = c2.getCenter();
double r1 = c1.getRadius();
double r2 = c2.getRadius();
if (p1==p2) {
    if (r1==r2) return c1;
    return SomeFigure();
    }

double x2 = p2.x-p1.x;
double y2 = p2.y-p1.y;

double a = -2*x2;
double b = -2*y2;
double c = x2*x2+y2*y2+r1*r1-r2*r2;
SomeFigure sf = lineAndCircleIntersection(Line(a, b, c), Circle(Point(0, 0), r1));
if (sf.type==FigureType::Point || sf.type==FigureType::TwoPoints) {
    Point p = sf.point;
    sf.point = Point(p.x+p1.x, p.y+p1.y);
    }
if (sf.type==FigureType::TwoPoints) {
    Point p = sf.secondPoint;
    sf.secondPoint = Point(p.x+p1.x, p.y+p1.y);
    }
return sf;
}

Polygon sumMinkowski(const Polygon& l, const Polygon& r) {
vector<Vector> vl, vr;
vl = l.asVectorArray();
vr = r.asVectorArray();

Point pl, pr;
pl = l.getLeftofBottom();
pr = r.getLeftofBottom();
Point t(pl.x+pr.x, pl.y+pr.y);

int ln = l.getSize(), rn = r.getSize();

vector<Vector> vt;
int i1=0, i2=0;
while(i1<ln || i2<rn) {
    bool fromFirst;
    if (i1==ln) fromFirst=0; else
    if (i2==rn) fromFirst=1; else fromFirst=(vl[i1]<vr[i2]);

    if (fromFirst) {vt.push_back(vl[i1]); i1++;}
    else {vt.push_back(vr[i2]); i2++;}
    }

vector<Point> ans;
Vector v(0, 0);
for(int i=0; i<ln+rn; i++) {
    if (i==0 || vt[i]<v || vt[i]>v) {t.x+=v.x; t.y+=v.y; ans.push_back(t); v=Vector(0, 0);}
    v+=vt[i];
    }

return Polygon(ans);
}

bool arePolygonsIntersects(const Polygon& l, const Polygon& r) { 

Polygon t = sumMinkowski(l, r.getInversed());
return t.isContainPoint(Point(0, 0));
}

bool comparePointsByX(const Point& l, const Point& r) {
if (l.x<r.x) return 1;
if (l.x>r.x) return 0;
return l.y<r.y;
}

enum class ExtraFigureType { 

Nothing, Point, Segment, Polygon
};

class ExtraSomeFigure {
public:
ExtraFigureType type;
Point point;
Segment segment;
Polygon polygon;

ExtraSomeFigure(void) {type=ExtraFigureType::Nothing;}
ExtraSomeFigure(Point p) {type=ExtraFigureType::Point; point=p;}
ExtraSomeFigure(Segment s) {type=ExtraFigureType::Segment; segment=s;}
ExtraSomeFigure(Polygon p) {type=ExtraFigureType::Polygon; polygon=p;}
};

ExtraSomeFigure buildConvexHull(vector<Point> v) { 

if (v.size()==1) {return v[0];}
sort(v.begin(), v.end(), comparePointsByX);
Point p1=v[0], p2=v[v.size()-1];

vector<Point> u, d;

for(int i=0; i<(int)v.size(); i++) {
    Vector v1(p1, v[i]), v2(v[i], p2);
    if (i==0 || i==((int)v.size())-1 || v1<v2) {
        while(true) {
            if (u.size()<2) break;
            Vector v3(u[u.size()-2], u[u.size()-1]);
            Vector v4(u[u.size()-1], v[i]);
            if (v3<v4) break;
            u.pop_back();
            }
        u.push_back(v[i]);
        }
    if (i==0 || i==((int)v.size())-1 || v1>v2) { 

        while(true) {
            if (d.size()<2) break;
            Vector v3(d[d.size()-2], d[d.size()-1]);
            Vector v4(d[d.size()-1], v[i]);
            if (v3>v4) break;
            d.pop_back();
            }
        d.push_back(v[i]);
        }
    }

vector<Point> ans=d;
reverse(u.begin(), u.end());
for(int i=1; i+1<(int)u.size(); i++) ans.push_back(u[i]);

if (ans.size()==2) return Segment(ans[0], ans[1]);
return Polygon(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    int n,d;
    cin >> n >> d;
    Point p1(d,0),p2(n,n-d),p3(n-d,n),p4(0,d);
    vector<Point> v = {p4,p1,p3,p2};
    Polygon p=buildConvexHull(v).polygon;
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> p1;
        if (p.isContainPoint(p1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
