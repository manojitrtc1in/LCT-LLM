#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAX_N 110



const long double INF        = 1e10;      

const long double EPS        = 1e-8;      

const long double PI         = acos(-1.0);

const int PINXING       = 0;         

const int XIANGJIAO     = 1;         

const int XIANGLI       = 0;         

const int GONGXIAN      = 2;         

const int CHONGDIE      = -1;        

const int INSIDE        = 1;         

const int OUTSIDE       = 0;         

const int BORDER        = 2;         




struct Point {              

    long double x, y;
    

    Point() {}
    Point(long double x0, long double y0): x(x0), y(y0) {}
    void read()
    {
        cin>>x>>y;
    }
};
struct Point3D {            

    long double x, y, z;
    Point3D() {}
    Point3D(long double x0, long double y0, long double z0): x(x0), y(y0), z(z0) {}
};
struct Line {               

    Point p1, p2;
    Line() {}
    Line(Point p10, Point p20): p1(p10), p2(p20) {}
    void read()
    {
        

    }
};
struct Line3D {             

    Point3D p1, p2;
    Line3D() {}
    Line3D(Point3D p10, Point3D p20): p1(p10), p2(p20) {}
};
struct Rect {              

    long double w, h;
    Rect() {}
    Rect(long double _w,long double _h) : w(_w),h(_h) {}
};
struct Rect_2 {             

    long double xl, yl, xh, yh;
    Rect_2() {}
    Rect_2(long double _xl,long double _yl,long double _xh,long double _yh) : xl(_xl),yl(_yl),xh(_xh),yh(_yh) {}
};
struct Circle {            

    Point c;
    long double r;
    Circle() {}
    Circle(Point _c,long double _r) :c(_c),r(_r) {}
};

typedef vector<Point> Polygon;      

typedef vector<Point> Points;       




inline long double max(long double x,long double y)
{
    return x > y ? x : y;
}
inline long double min(long double x, long double y)
{
    return x > y ? y : x;
}
inline bool ZERO(long double x)              

{
    return (fabs(x) < EPS);
}
inline bool ZERO(Point p)               

{
    return (ZERO(p.x) && ZERO(p.y));
}
inline bool ZERO(Point3D p)              

{
    return (ZERO(p.x) && ZERO(p.y) && ZERO(p.z));
}
inline bool EQ(long double x, long double y)      

{
    return (fabs(x - y) < EPS);
}
inline bool NEQ(long double x, long double y)     

{
    return (fabs(x - y) >= EPS);
}
inline bool LT(long double x, long double y)     

{
    return ( NEQ(x, y) && (x < y) );
}
inline bool GT(long double x, long double y)     

{
    return ( NEQ(x, y) && (x > y) );
}
inline bool LEQ(long double x, long double y)     

{
    return ( EQ(x, y) || (x < y) );
}
inline bool GEQ(long double x, long double y)     

{
    return ( EQ(x, y) || (x > y) );
}



inline long double FIX(long double x)
{
    return (fabs(x) < EPS) ? 0 : x;
}



bool operator==(Point p1, Point p2)
{
    return ( EQ(p1.x, p2.x) &&  EQ(p1.y, p2.y) );
}
bool operator!=(Point p1, Point p2)
{
    return ( NEQ(p1.x, p2.x) ||  NEQ(p1.y, p2.y) );
}
bool operator<(Point p1, Point p2)
{
    if (NEQ(p1.x, p2.x)) {
        return (p1.x < p2.x);
    } else {
        return (p1.y < p2.y);
    }
}
Point operator+(Point p1, Point p2)
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator-(Point p1, Point p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}
long double operator*(Point p1, Point p2) 

{
    return (p1.x * p2.y - p2.x * p1.y);
}
long double operator&(Point p1, Point p2) { 

    return (p1.x * p2.x + p1.y * p2.y);
}
long double Norm(Point p) 

{
    return sqrt(p.x * p.x + p.y * p.y);
}





long double Dis(Point p1,Point p2)
{
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}



long double Dis(Point p, Line L)
{
    return ( fabs((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) );
}



long double Dis2(Point p1,Point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}



Point SymmetryPoint(Point A,Point B)
{
    Point C;
    C.x = 2*B.x-A.x;
    C.y = 2*B.y-A.y;
    return C;
}







Point Rotate(Point p, long double angle)
{
    Point result;
    result.x = p.x * cos(angle) - p.y * sin(angle);
    result.y = p.x * sin(angle) + p.y * cos(angle);
    return result;
}



long double GetAngle(Point p)
{
    long double tmp=atan2(p.y,p.x);
    if(tmp<0) tmp=2*PI+tmp;
    return tmp;
}




long double GetAngle(Point p1,Point p2)
{
    long double tmp = GetAngle(p1) - GetAngle(p2);
    if( GT( tmp,PI) ) return -(2*PI-tmp);
    if( LEQ( tmp,-PI) ) return (tmp+2*PI);
    return tmp;
}








bool OnSeg(Point p, Line L)
{
    return ( ZERO( (L.p1 - p) * (L.p2 - p) ) &&
            LEQ((p.x - L.p1.x)*(p.x - L.p2.x), 0) &&
            LEQ((p.y - L.p1.y)*(p.y - L.p2.y), 0) );
}



bool OnLine(Point p, Line L)
{
    return ZERO( (p - L.p1) * (L.p2 - L.p1) );
}

bool OnCir(Point p,Circle cir)
{
    return EQ( (p.x-cir.c.x)*(p.x-cir.c.x)+(p.y-cir.c.y)*(p.y-cir.c.y),cir.r*cir.r );
}



long double PointToLine(Point p,Line L,Point& rep)
{
    if(L.p1==L.p2)
    {
        rep=L.p1;
        return Dis(p,L.p1);
    }
    Point a,b;
    a = L.p2-L.p1;
    b = p-L.p1;
    long double dis12 = Dis(L.p1,L.p2);
    long double dis = ( fabs(a*b) )/dis12;
    
    long double k = (a&b)/(Norm(a)*dis12) ;
    rep.x = L.p1.x + k*(L.p2.x-L.p1.x);
    rep.y = L.p1.y + k*(L.p2.y-L.p1.y);
    
    return dis;
}



long double PointToSeg(Point P, Line L,Point& rep)
{
    if(L.p1 == L.p2)
    {
        rep = L.p1;
        return Dis(rep,P);

    }
    Point result;
    long double a, b, t;
    
    a = L.p2.x - L.p1.x;
    b = L.p2.y - L.p1.y;
    t = ( (P.x - L.p1.x) * a + (P.y - L.p1.y) * b ) / (a * a + b * b);

    
    if ( GEQ(t, 0) && LEQ(t, 1) ) {
        result.x = L.p1.x + a * t;

        result.y = L.p1.y + b * t;
    } else {
        if ( Norm(P - L.p1) < Norm(P - L.p2) ) {
            result = L.p1;
        } else {
            result = L.p2;
        }
    }
    return Dis(result, P);
}




Point SymmetryPonitToLine(Point A,Line L)
{
    Point B;
    PointToLine(A, L, B);

    return SymmetryPoint(A, B);
}







long double Area(Point A, Point B, Point C)
{
    return ((B-A)*(C-A) / 2.0);
}



long double Area(long double a, long double b, long double c)
{
    long double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}



long double Area(Circle C)
{
    return PI * C.r * C.r;
}





long double Area(Polygon _poly)
{
    int nsize=_poly.size();
    long double area=0;
    for(int i=0;i<nsize;i++)
    {
        area += _poly[i]*_poly[(i+1)%nsize];
    }
    return area/2.0;
}







int LineAndLine(Line L1,Line L2,Point &p)
{
    Point px,py;
    px = L1.p1 - L1.p2;
    py = L2.p1 - L2.p2;
    if( EQ(px*py,0) )

    {
        if( ZERO( (L2.p1-L1.p1)*py ) ) 

        {
            return GONGXIAN;
        }
        return PINXING;
    }
    
    long double xa,xb,xc,ya,yb,yc;
    xa=(L1.p2.y-L1.p1.y); xb=(L1.p1.x-L1.p2.x); xc=(L1.p1.y*L1.p2.x-L1.p1.x*L1.p2.y);
    ya=(L2.p2.y-L2.p1.y); yb=(L2.p1.x-L2.p2.x); yc=(L2.p1.y*L2.p2.x-L2.p1.x*L2.p2.y);
    
    p.y = (xa*yc-xc*ya)/(xb*ya-xa*yb);
    p.x = (xb*yc-xc*yb)/(xa*yb-xb*ya);
    
    return XIANGJIAO;
}



bool SegAndSeg(Line L1,Line L2)
{
    return ( GEQ( max(L1.p1.x, L1.p2.x), min(L2.p1.x, L2.p2.x) ) &&
            GEQ( max(L2.p1.x, L2.p2.x), min(L1.p1.x, L1.p2.x) ) &&
            GEQ( max(L1.p1.y, L1.p2.y), min(L2.p1.y, L2.p2.y) ) &&
            GEQ( max(L2.p1.y, L2.p2.y), min(L1.p1.y, L1.p2.y) ) &&
            LEQ( ((L2.p1 - L1.p1) * (L1.p2 - L1.p1)) * ((L2.p2 -  L1.p1) * (L1.p2 - L1.p1)), 0 ) &&
            LEQ( ((L1.p1 - L2.p1) * (L2.p2 - L2.p1)) * ((L1.p2 -  L2.p1) * (L2.p2 - L2.p1)), 0 ) );
}








int SegAndSeg(Line L1,Line L2,Point &p)
{
    
    long double signx,signy;
    
    

    if( LEQ(signx=( ((L1.p2-L1.p1)*(L1.p1-L2.p1))*((L1.p2-L1.p1)*(L1.p1-L2.p2)) ),0) &&
       LEQ(signy=( ((L2.p2-L2.p1)*(L2.p1-L1.p1))*((L2.p2-L2.p1)*(L2.p1-L1.p2)) ),0) )
    {
        if( ZERO(signx) && ZERO(signy) )
        {
            

            signx = min( max(L1.p1.x,L1.p2.x),max(L2.p1.x,L2.p2.x) )-
            max( min(L1.p1.x,L1.p2.x),min(L2.p1.x,L2.p2.x) );
            
            signy = min( max(L1.p1.y,L1.p2.y),max(L2.p1.y,L2.p2.y) )-
            max( min(L1.p1.y,L1.p2.y),min(L2.p1.y,L2.p2.y) );
            
            if( ZERO(signx) && ZERO(signy) ) 

            {
                if(L1.p1==L2.p1||L1.p1==L2.p2) p=L1.p1;
                if(L1.p2==L2.p1||L1.p2==L2.p2) p=L1.p2;
                return XIANGJIAO;
            }
            else if( GEQ(signx, 0) && GEQ(signy, 0) )
            {
                return CHONGDIE;

            }
            else
            {
                return XIANGLI;

            }
        }
        return LineAndLine(L1, L2, p);

    }
    return  XIANGLI;

}














int InPolygon(const Polygon poly, Point p)
{
    int i, n, count;
    Line ray, side;
    
    n = poly.size();
    count = 0;
    ray.p1    = p;
    ray.p2.y  = p.y;
    ray.p2.x  = - INF;

    
    for (i = 0; i < n; i++) {
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];
        
        if( OnSeg(p, side) ) {
            return BORDER;
        }
        

        if ( EQ(side.p1.y, side.p2.y) ) {
            continue;
        }
        if (OnSeg(side.p1, ray)) {
            if ( GT(side.p1.y, side.p2.y) ) count++;
        } else if (OnSeg(side.p2, ray)) {
            if ( GT(side.p2.y, side.p1.y) ) count++;
        } else if ( SegAndSeg(ray, side) ) {
            count++;
        }
    }
    return ((count % 2 == 1) ? INSIDE : OUTSIDE);
}



int LineToCir(Line L,Circle R,Point p[2])
{
    if(L.p1 == L.p2)

    {
        if( EQ( Dis(L.p1, R.c),R.r ) )
        {
            p[0]=L.p1;
            return 1;
        }
        else return 0;

    }
    Point tp;

    long double dis=PointToLine(R.c, L,tp );
    if( LT(R.r, dis) )

    {
        return 0;
    }
    if( EQ(dis,R.r) )

    {
        p[0]=tp;
        return 1;
    }
    long double len=sqrt(R.r*R.r-dis*dis);
    Point onep=L.p2-L.p1;
    long double _t  = len/Norm(onep);
    
    p[0].x =tp.x + onep.x*_t;
    p[0].y =tp.y + onep.y*_t;
    
    onep=L.p1-L.p2;
    p[1].x =tp.x + onep.x*_t;
    p[1].y =tp.y + onep.y*_t;
    
    return 2;
}





Circle OutCircle(Point A,Point B,Point C)
{
    Circle tmp;
    long double a, b, c, c1, c2;
    long double xA, yA, xB, yB, xC, yC;
    a = Dis(A, B);
    b = Dis(B, C);
    c = Dis(C, A);
    

    tmp.r = (a*b*c)/( fabs(Area(A,B,C)) *4.0);
    xA = A.x;
    yA = A.y;
    xB = B.x;
    yB = B.y;
    xC = C.x;
    yC = C.y;
    c1 = (xA*xA+yA*yA - xB*xB-yB*yB) / 2;
    c2 = (xA*xA+yA*yA - xC*xC-yC*yC) / 2;
    tmp.c.x = (c1*(yA - yC)-c2*(yA - yB)) / ((xA - xB)*(yA - yC)-(xA - xC)*(yA - yB));
    tmp.c.y = (c1*(xA - xC)-c2*(xA - xB)) / ((yA - yB)*(xA - xC)-(yA - yC)*(xA - xB));
    return tmp;
}





Circle InCircle(Point A,Point B,Point C)
{
    Circle rec;
    long double a=Dis(B,C);
    long double b=Dis(A,C);
    long double c=Dis(A,B);
    rec.c.x = (a*A.x+b*B.x+c*C.x)/(a+b+c);
    rec.c.y = (a*A.y+b*B.y+c*C.y)/(a+b+c);
    rec.r = 2*fabs( Area(A,B,C) )/(a+b+c);
    return rec;
}



long double CirArea(Circle _c1,Circle _c2)
{
    if(_c2.r<_c1.r) swap(_c1,_c2); 

    long double d12 = Dis(_c1.c,_c2.c);
    if( LEQ(_c1.r+_c2.r,d12) )

    {
        return 0;
    }
    if( LEQ(d12+_c1.r, _c2.r) )

    {
        return Area(_c1);
    }
    

    long double _area=0;
    _area -= 2.0*Area(_c1.r,_c2.r,d12);
    long double ang1 = acos( (d12*d12+_c1.r*_c1.r-_c2.r*_c2.r) / (2*d12*_c1.r) );
    long double ang2 = acos( (d12*d12+_c2.r*_c2.r-_c1.r*_c1.r) / (2*d12*_c2.r) );
    _area += ang1*_c1.r*_c1.r+ang2*_c2.r*_c2.r;
    return _area;
}





int CirAndCir(Circle _c1,Circle _c2,Point p[2])
{
    if(_c2.r < _c1.r) swap(_c1,_c2); 

    long double d12 = Dis(_c1.c,_c2.c);
    if( LT(_c1.r+_c2.r,d12) )

    {
        return 0;
    }
    if( LT(d12+_c1.r, _c2.r) )

    {
        return 0;
    }
    if(_c1.c == _c2.c)

    {
        return -1;
    }
    Point u,v;
    long double t;
    long double r1=_c1.r,r2=_c2.r;
    
    t=( 1+(r1*r1-r2*r2)/(Dis(_c1.c,_c2.c)*Dis(_c1.c,_c2.c)) ) /2;
    u.x = _c1.c.x + (_c2.c.x-_c1.c.x)*t;
    u.y = _c1.c.y + (_c2.c.y-_c1.c.y)*t;
    
    v.x = u.x + _c1.c.y - _c2.c.y;
    v.y = u.y - _c1.c.x + _c2.c.x;
    
    Line _l(u,v);
    return LineToCir(_l,_c1,p);
}



Point ps[100100];

int main()
{
    int n;
    cin>>n;
    Point p;
    p.read();
    long double r,R;
    for(int i=0;i<n;i++)
    {
        ps[i].read();
    }
    R=Dis(p,ps[0]);
    for(int i=1;i<n;i++)
        R=max(R,Dis(p,ps[i]));
    r = R;
    for(int i=0;i<n;i++)
    {
        Line l;
        l.p1 = ps[i];
        l.p2 = ps[ (i+1)%n ];
        Point tp;
        double tmp = PointToSeg(p, l, tp);
        r = min( r,tmp);
    }
    
    printf("%.20Lf",PI*(R*R-r*r) );
    return 0;
}