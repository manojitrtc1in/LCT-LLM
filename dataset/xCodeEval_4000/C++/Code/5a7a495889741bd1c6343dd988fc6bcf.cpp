#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>


























using namespace std;




const double eps=1e-5;
const double PI=acos(-1);
struct Point
{
    double x,y;
    Point(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    Point()
    {
        x=0;
        y=0;
    }
};
typedef Point Vector;
Vector operator+(Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(Vector A,double p)
{
    return Vector(A.x/p,A.y/p);
}
Vector operator*(double p,Vector A)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(double p,Vector A)
{
    return Vector(A.x/p,A.y/p);
}
bool operator<(const Point& a,const Point& b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int dcmp(double x)
{
    if(fabs(x)<eps)
    {
        return 0;
    }
    else
    return x<0?-1:1;
}
bool operator==(const Point& a,const Point& b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Vector a,Vector b)
{
    

    return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b)
{
    

    return a.x*b.y-a.y*b.x;
}
double Length(Vector a)
{
    

    return sqrt(Dot(a,a));
}
double Angle(Vector A,Vector B)
{
    

    return acos(Dot(A,B)/Length(A)/Length(B));
}
double Area2(Point A,Point B,Point C)
{
    

    return Cross(B-A,C-A);
}
Vector Rotate(Vector a,double rad)
{
    

    

    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Vector Normal(Vector a)
{
    

    

    double l=Length(a);
    return Vector(-a.y/l,a.x/l);
}
Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    

    

    

    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}
double DistanceToLine(Point p,Point a,Point b)
{
    

    Point v1=b-a;
    Point v2=p-a;
    return fabs(Cross(v1,v2))/Length(v1);
    

}
double DistanceToSegment(Point p,Point a,Point b)
{
    

    if(a==b)
    {
        return Length(p-a);
    }
    Vector v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0)
    {
        return Length(v2);
    }
    else
    if(dcmp(Dot(v1,v3))>0)
    {
        return Length(v3);
    }
    else
    {
        return fabs(Cross(v1,v2))/Length(v1);
    }
}
Point GetLineProjection(Point p,Point a,Point b)
{
    

    

    

    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    

    double c1=Cross(a2-a1,b1-a1);
    double c2=Cross(a2-a1,b2-a1);
    double c3=Cross(b2-b1,a1-b1);
    double c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(Point p,Point a1,Point a2)
{
    

    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}
double ConvexPolygonArea(Point* p,int n)
{
    

    double area=0;
    for(int i=1;i<n-1;i++)
    {
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2;
}


struct Circle
{
    Point c;
    double r;
    Circle()
    {

    }
    Circle(Point cc,double rr)
    {
        c=cc;
        r=rr;
    }
    Point point(double a)
    {
        

        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
struct Line
{
    

    Vector v;
    Point p;
    double ang;
    Line(){}
    Line(Point pp,Vector vv)
    {
        p=pp;
        v=vv;
        ang=atan2(v.y,v.x);
    }
    Point point(double a)
    {
        return v+a*(p-v);
    }
    bool operator<(const Line& L) const
    {
        return ang<L.ang;
    }
};
bool OnLeft(Line l,Point pp)
{
    

    return Cross(l.v,pp-l.p)>0;
}
Point GetLineIntersection(Line a,Line b)
{
    

    Vector u=a.p-b.p;
    double t=Cross(b.v,u)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
int getLineCircleIntersection(Line l,Circle cc,double& t1,double& t2,vector<Point>& sol)
{
    

    

    

    

    

    

    

    

    

    

    

    double a=l.v.x;
    double b=l.p.x-cc.c.x;
    double c=l.v.y;
    double d=l.p.y-cc.c.y;
    double e=a*a+c*c;
    double f=2*(a*b+c*d);
    double g=b*b+d*d-cc.r*cc.r;
    double delta=f*f-4*e*g;

    if(dcmp(delta)<0)
    {
        return 0;

    }
    if(dcmp(delta)==0)
    {
        t1=t2=-f/(2*e);
        sol.push_back(l.point(t1));
        return 1;

    }
    t1=(-f-sqrt(delta))/(2*e);
    sol.push_back(l.point(t1));
    t2=(-f+sqrt(delta))/(2*e);
    sol.push_back(l.point(t2));
    return 2;

}
double angle(Vector v)
{
    

    return atan2(v.y,v.x);
}
int getCircleCircleIntersection(Circle c1,Circle c2,vector<Point>& sol)
{
    double d=Length(c1.c-c2.c);
    if(dcmp(d)==0)
    {
        if(dcmp(c1.r-c2.r)==0)
        return -1;

        return 0;
    }
    if(dcmp(c1.r+c2.r-d)<0)
    return 0;
    if(dcmp(fabs(c1.r-c2.r)-d)>0)
    return 0;

    double a=angle(c2.c-c1.c);

    double da=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    

    Point p1=c1.point(a-da);
    Point p2=c1.point(a+da);
    sol.push_back(p1);
    if(p1==p2)
    return 1;
    sol.push_back(p2);
    return 2;
}
int getTangents(Point p,Circle c,Vector* v)
{
    

    Vector u=c.c-p;
    double dist=Length(u);
    if(dist<c.r)
    return 0;
    else
    if(dcmp(dist-c.r)==0)
    {
        v[0]=Rotate(u,PI/2);
        return 1;
    }
    else
    {
        double ang=asin(c.r/dist);
        v[0]=Rotate(u,-ang);
        v[1]=Rotate(u,ang);
        return 2;
    }
}
int getTangents(Circle a,Circle b,Point* aa,Point* bb)
{
    

    

    int cnt=0;
    if(a.r<b.r)
    {
        swap(a,b);
        swap(aa,bb);
    }
    int d2=(a.c.x-b.c.x)*(a.c.x-b.c.x)+(a.c.y-b.c.y)*(a.c.y-b.c.y);
    int rdiff=a.r-b.r;
    int rsum=a.r+b.r;
    if(d2<rdiff*rdiff)
    {
        return 0;

    }
    double base=atan2(b.c.y-a.c.y,b.c.x-a.c.x);
    if(d2==0&&a.r==b.r)
    return -1;

    if(d2==rdiff*rdiff)
    {
        aa[cnt]=a.point(base);
        bb[cnt]=b.point(base);
        cnt++;
        return 1;

    }
    

    double ang=acos((a.r-b.r)/sqrt(d2));
    aa[cnt]=a.point(base+ang);
    bb[cnt]=b.point(base+ang);
    cnt++;
    aa[cnt]=a.point(base-ang);
    bb[cnt]=b.point(base-ang);
    cnt++;

    if(d2==rsum*rsum)
    {
        aa[cnt]=a.point(base);
        bb[cnt]=b.point(base+PI);
        cnt++;

    }
    else
    if(d2>rsum*rsum)
    {
        double ang=acos((a.r+b.r)/sqrt(d2));
        aa[cnt]=a.point(base+ang);
        bb[cnt]=b.point(PI+base+ang);
        cnt++;
        aa[cnt]=a.point(base-ang);
        bb[cnt]=b.point(PI+base-ang);
        cnt++;

    }
    return cnt;
}
Circle CircumscribedCircle(Point p1,Point p2,Point p3)
{
    

    double bx=p2.x-p1.x;
    double by=p2.y-p1.y;
    double cx=p3.x-p1.x;
    double cy=p3.y-p1.y;
    double d=2*(bx*cy-cx*by);
    double ccx=(cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+p1.x;
    double ccy=(bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+p1.y;
    Point p=Point(ccx,ccy);
    return Circle(p,Length(p1-p));
}
Circle InscribedCircle(Point p1,Point p2,Point p3)
{
    

    double a=Length(p2-p3);
    double b=Length(p3-p1);
    double c=Length(p1-p2);
    Point p=(p1*a+p1*b+p3*c)/(a+b+c);
    return Circle(p,DistanceToLine(p,p1,p2));
}
double torad(double deg)
{
    

    return deg/180*PI;
}
void get_coord(double r,double lat,double lng,double& x,double& y,double& z)
{
    

    lat=torad(lat);
    lng=torad(lng);
    x=r*cos(lat)*cos(lng);
    y=r*cos(lat)*sin(lng);
    z=r*sin(lat);
}




struct Polygon
{
    int n;
    Point p[1000];
    Polygon()
    {
        n=0;
    }
    Polygon(int nn,Point* pp)
    {
        n=nn;
        for(int q=0;q<n;q++)
        {
            p[q]=pp[q];
        }
    }
    Point operator[](int a) const
    {
        return p[a];
    }
};
int isPointInPolygon(Point p,Polygon po)
{
    

    

    int wn=0;
    int n=po.n;
    for(int i=0;i<n;i++)
    {
        if(OnSegment(p,po[i],po[(i+1)%n]))
        return -1;

        int k=dcmp(Cross(po[(i+1)%n]-po[i],p-po[i]));
        int d1=dcmp(po[i].y-p.y);
        int d2=dcmp(po[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0)
        wn++;
        if(k<0&&d2<=0&&d1>0)
        wn--;
    }
    if(wn!=0)
    return 1;

    return 0;

}




int ConvexHull(Point* p,int n,Point* ch)
{
    

    

    

    

    sort(p,p+n);
    

    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
        m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
        m--;
        ch[m++]=p[i];
    }
    if(n>1)
    m--;
    return m;
}
double diameter(Point* o,int n,Point *p)
{
    

    

    int num=ConvexHull(o,n,p);
    int mi=0;
    int ma=0;
    for(int q=0;q<num;q++)
    {
        if(p[q]<p[mi])
            mi=q;
        if(p[ma]<p[q])
            ma=q;
    }
    int v=ma;
    double ans=(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y);
    ans=max(ans,(p[num-1].x-p[ma].x)*(p[num-1].x-p[ma].x)+(p[num-1].y-p[ma].y)*(p[num-1].y-p[ma].y));
    ans=max(ans,(p[mi].x-p[ma-1].x)*(p[mi].x-p[ma-1].x)+(p[mi].y-p[ma-1].y)*(p[mi].y-p[ma-1].y));
    ans=max(ans,(p[num-1].x-p[ma-1].x)*(p[num-1].x-p[ma-1].x)+(p[num-1].y-p[ma-1].y)*(p[num-1].y-p[ma-1].y));
    for(;mi<v;mi++)
    {
        for(;;)
        {
            int a=dcmp(Cross(p[mi+1]-p[mi],p[ma+1]-p[ma]));
            if(a==0)
            {
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                ma++;
                break;
            }
            if(a>0)
            {
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ma++;
            }
            if(a<0)
            {
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                break;
            }
        }
    }
    return ans;
}
int HalfplaneIntersection(Line* l,int n,Point* poly)
{
    sort(l,l+n);
    int first,last;
    Point *p=new Point[n];
    Line *q=new Line[n];
    q[first=last=0]=l[0];
    for(int i=1;i<n;i++)
    {
        while(first<last&&!OnLeft(l[i],p[last-1]))
            last--;
        while(first<last&&!OnLeft(l[i],p[first]))
            first++;
        q[++last]=l[i];
        if(fabs(Cross(q[last].v,q[last-1].v))<eps)
        {
            last--;
            if(OnLeft(q[last],l[i].p))
                q[last]=l[i];
        }
        if(first<last)
            p[last-1]=GetLineIntersection(q[last-1],q[last]);
    }
    while(first<last&&!OnLeft(q[first],p[last-1]))
        last--;
    if(last-first<=1)
        return 0;
    p[last]=GetLineIntersection(q[last],q[first]);
    int m=0;
    for(int i=first;i<=last;i++)
        poly[m++]=p[i];
    return m;
}
void FindBorder(Point* p,int n)
{
    

    int num;
    Point ans[10005];
    Point z[205];
    double x[205];
    int a;
    int min1=0;
    for(int q=0;q<n;q++)
        if(p[q]<p[min1])
            min1=q;
    p[n]=p[0];
    ans[0]=p[min1];
    double s=-PI;
    num=1;
    for(int idx=0;;idx++)
    {
        a=0;
        for(int q=0;q<n;q++)
            if(p[q]==ans[num-1])
            {
                z[a]=p[(q+1)%n];
                x[a]=atan2(-p[q].y+z[a].y,-p[q].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
                z[a]=p[(q+n-1)%n];
                x[a]=atan2(-p[q].y+z[a].y,-p[q].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
            }
        for(int q=0;q<n;q++)
            if(OnSegment(ans[num-1],p[q],p[q+1]))
            {
                z[a]=p[(q+1)];
                x[a]=atan2(-ans[num-1].y+z[a].y,-ans[num-1].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
                z[a]=p[q];
                x[a]=atan2(-ans[num-1].y+z[a].y,-ans[num-1].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
            }
        int mi=0;
        for(int q=0;q<a;q++)
            if(x[q]<x[mi])
                mi=q;
        double ma=101000000;
        Point f=z[mi],g;
        for(int q=0;q<n;q++)
            if(SegmentProperIntersection(z[mi],ans[num-1],p[q],p[q+1]))
            {
                g=GetLineIntersection(z[mi],z[mi]-ans[num-1],p[q],p[q]-p[q+1]);
                if(Length(g-ans[num-1])<ma)
                {
                    ma=Length(g-ans[num-1]);
                    f=g;
                }
            }
        ans[num]=f;
        s=atan2(ans[num-1].y-ans[num].y,ans[num-1].x-ans[num].x);
        num++;
        if(ans[num-1]==ans[0])
            break;
    }
    printf("%d\n",num-1);
    for(int q=0;q<num-1;q++)
        printf("%.4lf %.4lf\n",ans[q].x,ans[q].y);
}
Polygon cutPolygon(Polygon& po,Point a,Point s)
{
    

    

    Point x,c;
    Polygon ans;
    int sum=0;
    for(int q=0;q<po.n;q++)
    {
        x=po[q];
        c=po[(q+1)%po.n];
        if(OnLeft(Line(a,s-a),x)||OnSegment(x,a,s))
        {
            ans.p[sum]=x;
            sum++;
        }
        if(SegmentProperIntersection(x,c,a,s))
        {
            ans.p[sum]=GetLineIntersection(x,c-x,a,s-a);
            sum++;
        }
    }
    ans.n=sum;
    return ans;
}




struct Point3
{
    double x,y,z;
    Point3()
    {
        x=0;
        y=0;
        z=0;
    }
    Point3(double xx,double yy,double zz)
    {
        x=xx;
        y=xx;
        z=zz;
    }
    bool operator==(Point3 p) const
    {
        return dcmp(x-p.x)==0&&dcmp(y-p.y)==0&&dcmp(z-p.z)==0;
    }
};
typedef Point3 Vector3;
Vector3 operator+(Vector3 a,Vector3 b)
{
    return Vector3(a.x+b.x,a.y+b.y,a.z+b.z);
}
Vector3 operator-(Vector3 a,Vector3 b)
{
    return Vector3(a.x-b.x,a.y-b.y,a.z-b.z);
}
Vector3 operator*(Vector3 a,double p)
{
    return Vector3(a.x*p,a.y*p,a.z*p);
}
Vector3 operator/(Vector3 a,double p)
{
    return Vector3(a.x/p,a.y/p,a.z/p);
}
double Dot(Vector3 a,Vector3 b)
{
    return a.x*b.x+a.y*b.y+a.z*b.y;
}
double Length(Vector3 a)
{
    return sqrt(Dot(a,a));
}
double Angle(Vector3 a,Vector3 b)
{
    return acos(Dot(a,b)/Length(a)/Length(b));
}


double DistanceToPlane(Point3 &p,Point3 &p0,Vector3 &n)
{
    

    return fabs(Dot(p-p0,n));
    

}
Point3 GetPlaneProjection(Point3 &p,Point3 &p0,Vector3 &n)
{
    

    return p-n*Dot(p-p0,n);
}
Point3 LinePlaneIntersection(Point3 p1,Point3 p2,Point3 p0,Vector3 n)
{
    

    

    Vector3 v=p2-p1;
    double t=(Dot(n,p0-p1)/Dot(n,p2-p1));

    return p1+v*t;

}
Vector3 Cross(Vector3 a,Vector3 b)
{
    return Vector3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double Area2(Point3 a,Point3 b,Point3 c)
{
    return Length(Cross(b-a,c-a));
}
bool PointInTri(Point3 p,Point3 p0,Point3 p1,Point3 p2)
{
    

    double area1=Area2(p,p0,p1);
    double area2=Area2(p,p2,p1);
    double area3=Area2(p,p0,p2);
    return dcmp(area1+area2+area3-Area2(p0,p1,p2))==0;
}
bool TriSegIntersection(Point3 p0,Point3 p1,Point3 p2,Point3 a,Point3 b,Point3 &p)
{
    

    

    Vector3 n=Cross(p1-p0,p2-p0);
    if(dcmp(Dot(n,b-a))==0)
        return false;
    else
    {
        double t=Dot(n,p0-a)/Dot(n,b-a);
        if(dcmp(t)<0||dcmp(t-1)>0)
            return false;
        p=a+(b-a)*t;

        return PointInTri(p,p0,p1,p2);

    }
}
double DistanceToLine(Point3 p,Point3 a,Point3 b)
{
    

    Vector3 v1=b-a,v2=p-a;
    return Length(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(Point3 p,Point3 a,Point3 b)
{
    

    if(a==b)
        return Length(p-a);
    Vector3 v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0)
        return Length(v2);
    else
    if(dcmp(Dot(v1,v3))>0)
        return Length(v3);
    else
        return Length(Cross(v1,v2))/Length(v1);
}
double Volume6(Point3 a,Point3 b,Point3 c,Point3 d)
{
    return Dot(d-a,Cross(b-a,c-a));
}


int n;
int a[1000005];
int z[10000005];
int idx[10000005];
int num[1000005];
int s[1000005][10];
int u[10000005];


void find(int l)
{
    if(u[l]!=u[u[l]])
    {
        find(u[l]);
        u[l]=u[u[l]];
    }
}
void unio(int a,int s)
{
    u[u[a]]=u[s];
}
void dfs(int h,long long g,long long d,int f)
{
    
    if(h==num[f])
    {
        
        if(g==d)
            return;
        long long j=(d+g)/2;
        long long k=abs(d-g)/2;
        

        

        

        int m=0;
        if((j&1)==0)
            m++;
        if((k&1)==0)
            m++;
        if((a[f]&1)==0)
            m++;
        if(m>1)
            return;
        if(j<10000005ll&&idx[j]>=0)
        {
        find(a[f]);
        find(j);
        unio(a[f],j);
        }
        if(k<10000005ll&&idx[k]>=0)
        {
        find(a[f]);
        find(k);
        unio(a[f],k);
        }
        return;
    }
    if(s[f][h]&1)
    {
        dfs(h+1,g*s[f][h]*s[f][h],d,f);
        dfs(h+1,g,d*s[f][h]*s[f][h],f);
    }
    else
    {
        int m=0;
        for(m=0;;m++)
            if((1<<m)==s[f][h])
                break;
        for(int q=1;q<m*2;q++)
        {
            dfs(h+1,g<<q,d<<(m+m-q),f);
        }
    }
}
int main()
{
    scanf("%d",&n);
    memset(z,0,sizeof z);
    

    

        

    

    for(int q=0;q<10000005;q++)
    {
        idx[q]=-1;
        u[q]=q;
        

    }
    for(int q=0;q<n;q++)
    {
        scanf("%d",&a[q]);
        idx[a[q]]=q;
        

    }
    z[1]=1;
    

    for(int q=2;q<10000005;q++)
    {
        

        if(z[q]==0)
        {
            for(int w=q;w<10000005;w+=q)
                z[w]=q;
        }
        

        if(idx[q]>=0)
        {
            int d=idx[q];
            num[d]=1;
            s[d][0]=z[q];
            int w=q/z[q];
            for(;w!=1;)
            {
                if(s[d][num[d]-1]%z[w]==0)
                {
                    s[d][num[d]-1]*=z[w];
                }
                else
                {
                    s[d][num[d]]=z[w];
                    num[d]++;
                }
                w/=z[w];
            }
        }

    }
    

    

        

        

        

    


    for(int q=0;q<n;q++)
    {
        dfs(0,1,1,q);
        

    }
    for(int q=0;q<10000005;q++)
        find(q);
    int nm=0;
    for(int q=0;q<10000005;q++)
        if(idx[q]>=0&&u[q]==q)
            nm++;
        cout<<nm<<endl;
























    return 0;
}
