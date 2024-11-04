#define  _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <cmath>
#define PI acos(-1.0) 

#define EPS 1e-9
#define INF 1e9
using namespace std;



struct point
{
    double x, y;
    point()
    {
        x = y = 0.0;
    }
    point(double _x, double _y) : x(_x), y(_y) {}
    point(const point &p) : x(p.x), y(p.y) {}
    bool operator < (point other) const    

    {
        if (fabs(x - other.x) > EPS) 

            return x < other.x; 

        return y < other.y;

    }
    bool operator > (point other) const    

    {
        if (fabs(x - other.x) > EPS) 

            return x > other.x; 

        return y > other.y;

    }
    bool operator == (point other) const
    {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    point operator+(const point &p) const
    {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p) const
    {
        return point(x - p.x, y - p.y);
    }
    point operator*(double c) const
    {
        return point(x*c, y * c);
    }
    point operator/(double c) const
    {
        return point(x / c, y / c);
    }
};
double DEG_to_RAD(double t)
{
    return t*PI/180.0;
}
double RAD_to_DEG(double t)
{
    return t*180.0/PI;
}
double dot(point p, point q)
{
    return p.x * q.x + p.y * q.y;
}
double dist2(point p, point q)
{
    return dot(p - q, p - q);
}
double cross(point p, point q)
{
    return p.x * q.y - p.y * q.x;
}


point rotate(point p, double theta)
{
    double rad = DEG_to_RAD(theta);

    point t;
    if(fabs(p.x * cos(rad) - p.y * sin(rad))<EPS)
        t.x=0.0;
    else t.x=p.x * cos(rad) - p.y * sin(rad);
    if(fabs(p.x * sin(rad) + p.y * cos(rad))<EPS)
        t.y=0.0;
    else t.y=p.x * sin(rad) + p.y * cos(rad);
    return t;
}
point rotateCCW90(point p)
{
    return point(-p.y, p.x);
}
point rotateCW90(point p)
{
    return point(p.y, -p.x);
}
double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}



struct line    

{
    double a, b, c;
};
void pointsToLine(point p1, point p2, line &l)
{
    if (fabs(p1.x - p2.x) < EPS)   

    {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x; 

    }
    else
    {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; 

        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}
void point_and_m_ToLine(point p,double m,line &l)
{
    l.a=-1*m;
    l.b=1;
    l.c=m*p.x-p.y;
}
bool areParallel(line l1, line l2)   

{
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2)   

{
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p)
{
    if (areParallel(l1, l2)) return false; 

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b); 

    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    if(fabs(p.x)<EPS)p.x=0;
    if(fabs(p.y)<EPS)p.y=0;
    return true;
}



struct vec
{
    double x, y; 

    vec() {};
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b)    

{
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s)    

{
    return vec(v.x * s, v.y * s);
} 

point translate(point p, vec v)    

{
    point t;
    if(fabs(p.x+v.x)<EPS)
        t.x=0.0;
    else t.x=p.x+v.x;
    if(fabs(p.y+v.y)<EPS)
        t.y=0.0;
    else t.y=p.y+v.y;
    return t;
}
double dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v)
{
    return v.x * v.x + v.y * v.y;
}
vec rotateCCW90(vec p)
{
    return vec(-p.y, p.x);
}
vec rotateCW90(vec p)
{
    return vec(p.y, -p.x);
}







double distToLine(point p, point a, point b, point &c)
{
    

    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); 

    return dist(p, c);
} 








double distToLineSegment(point p, point a, point b, point &c)
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = point(a.x, a.y); 

        return dist(p, a);
    } 

    if (u > 1.0)
    {
        c = point(b.x, b.y); 

        return dist(p, b);
    } 

    return distToLine(p, a, b, c);

}


double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d)
{
    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
double angle(point a, point o, point b)
{
    

    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(vec a, vec b)
{
    return a.x * b.y - a.y * b.x;
}




bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
}


bool collinear(point p, point q, point r)
{
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}
int ccw_(point a,point b,point c)
{
    int t=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if(t>0)
        return 1;      

    if(t<0)
        return -1;         

    else return 0;
}
bool isproper(point a,point b,point c,point d) 

{
    return (ccw_(a,b,c)*ccw_(a,b,d)<0 && ccw_(c,d,a)*ccw_(c,d,b)<0);
}
point rotate_rond_point_CCW90(point base,point p)
{
    vec v=toVec(base,p);
    vec t=rotateCCW90(v);
    return translate(base,t);
}
point rotate_rond_point_CW90(point base,point p)
{
    vec v=toVec(base,p);
    vec t=rotateCW90(v);
    return translate(base,t);
}
point get_mirror_point_line(point p,point a,point b)
{
    vec v;
    point c;
    double d=distToLine(p,a,b,c);
    v=toVec(p,c);
    return translate(c,v);
}



double fixangle(double A)
{
    return A>1?1:(A<-1?-1:A);
}


double getside_a_bAB(double b,double A,double B)
{
    return (sin(A)*b)/sin(B);
}
double getangle_A_abB(double a,double b,double B)
{
    return asin(fixangle( (a*sin(B))/b ));
}


double getangle_A_abc(double a,double b,double c)
{
    return acos(fixangle( (b*b+c*c-a*a)/(2*b*c) ));
}


double get_height(double base,double area)
{
    return (2*area)/base;
}
double Pow(double b,long p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return b;
    if (p % 2 == 1) return b*Pow(b, p-1);
    long long r = Pow(b, p / 2);
    return r*r;
}
long double Triangle_area(double a,double b,double c)
{
    long double v=0.5*(a+b+c);
    return sqrt(v*(v-a)*(v-b)*(v-c));
}



double get_arc(double r ,double teta) 

{
    return (teta*r);
}
double get_length_Chord(double r,double teta)
{
    return 2*r*sin(teta/2);
}
double Circular_sector(double r,double teta)
{
    return (r*r*teta)/2;
}
double get_Segment_of_circle(double r,double teta)
{
    return Circular_sector(r,teta)-Triangle_area(r,r,get_length_Chord(r,teta));
}
bool circle2PtsRad(point p1, point p2, double r, point &c)
{
    

    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}


double rInCircle(double a,double b,double c) 

{
    return Triangle_area(a,b,c)/((a+b+c)/2);
}
double rInCircle(point a, point b, point c)
{
    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}


double RCircumCircle(double a,double b,double c) 

{
    return (a*b*c)/(4.0*Triangle_area(a,b,c));
}
double RCircumCircle(point a, point b, point c)
{
    return RCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}








int inCircle(point p1, point p2, point p3, point &ctr, double &r)
{
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return 0; 

    line l1, l2; 

    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr); 

    return 1;
}
double get_area(double a,double b,double c,double r) 

{
    double t=0;
    double tet=getangle_A_abc(a,b,c);
    double tetar=PI-tet;
    double tetar2=tet/2;
    double side=getside_a_bAB(r,tetar,tetar2);
    double s_sector=Circular_sector(r,tetar);
    double s_T1=Triangle_area(side,r,r);
    double s=s_sector-s_T1;
    tetar=(PI-tet)/2;
    double side2=getside_a_bAB(side,tetar,tet);
    double s2=Triangle_area(side2,side2,side);
    t=s2-s;
    return t;
}
int insideCircle(point p, point c, double r)   

{
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r; 

    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;

}


point ComputeCircleCenter(point a, point b, point c)
{
    b = (a + b) / 2;
    c = (a + c) / 2;
    point inters;
    line l1,l2;
    pointsToLine(b,b+rotateCW90(a - b),l1);
    pointsToLine(c,c+rotateCW90(a - c),l2);
    bool bo=areIntersect( l1 , l2 , inters );
    return inters;
}
vector<point> CircleLineIntersection(point a, point b, point c, double r)
{
    vector<point> ret;
    b = b - a;
    a = a - c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B * B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
    if (D > EPS)
        ret.push_back(c + a + b * (-B - sqrt(D)) / A);
    return ret;
}




vector<point> CircleCircleIntersection(point a, point b, double r, double R)
{
    vector<point> ret;
    double d = sqrt(dist2(a, b));
    if (d > r + R || d + min(r, R) < max(r, R)) return ret;
    double x = (d * d - R * R + r * r) / (2 * d);
    double y = sqrt(r * r - x * x);
    point v = (b - a) / d;
    ret.push_back(a + v * x + rotateCCW90(v) * y);
    if (y > 0)
        ret.push_back(a + v * x - rotateCCW90(v) * y);
    return ret;
}










double perimeter(const vector<point> &P)
{
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++) 

        result += dist(P[i], P[i+1]);
    return result;
}
double area_polygon(const vector<point> &p)
{
    double area = 0;
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(area) / 2.0;
}
bool isConvex(const vector<point> &P)
{
    

    int sz = (int)P.size(); 

    if (sz <= 3) return false; 

    bool isLeft = ccw(P[0], P[1], P[2]); 

    

    for (int i = 1; i < sz-1; i++) 

        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft) 

            return false; 

    return true;

}
double ComputeSignedArea(const vector<point> &p) 

{
    double area = 0;
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area / 2.0;
}
point ComputeCentroid(const vector<point> &p)
{
    point c(0, 0);
    double scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i + 1) % p.size();
        c = c + (p[i] + p[j])*(p[i].x * p[j].y - p[j].x * p[i].y);
    }
    return c / scale;
}














bool PointInPolygon(const vector<point> &p, point q)
{
    bool c = 0;
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i + 1) % p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
                p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}




point ProjectPointLine(point a, point b, point c)
{
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}


point ProjectPointSegment(point a, point b, point c)
{
    double r = dot(b - a, b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b - a) * r;
}


bool PointOnPolygon(const vector<point> &p, point q)
{
    for (int i = 0; i < p.size(); i++)
        if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
            return true;
    return false;
}


bool IsSimple(const vector<point> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        for (int k = i + 1; k < p.size(); k++)
        {
            int j = (i + 1) % p.size();
            int l = (k + 1) % p.size();
            if (i == l || j == k) continue;
            line l1,l2;
            point t;
            pointsToLine(p[i], p[j], l1);
            pointsToLine(p[k], p[l], l2);
            if (areIntersect(l1,l2, t))
                return false;
        }
    }
    return true;
}
bool issquere(point a,point b,point c,point d)
{
    if(a==b || a==c || a==d || b==c || b==d || c==d)
        return 0;
    double x[7];
    x[0]=hypot(a.x-b.x,a.y-b.y);
    x[1]=hypot(a.x-c.x,a.y-c.y);
    x[2]=hypot(a.x-d.x,a.y-d.y);
    x[3]=hypot(b.x-c.x,b.y-c.y);
    x[4]=hypot(b.x-d.x,b.y-d.y);
    x[5]=hypot(c.x-d.x,c.y-d.y);
    int t=1,k=1;
    double m=-1;
    for(int j=1; j<=5; j++)
        if(x[0]==x[j])
            t++;
        else
        {
            if(m==-1)
                m=x[j];
            else if(m==x[j])k++;
        }
    if((t==4 && k==2) ||(t==2 && k==4))
        return 1;
    return 0;
}
bool isrectangle(point a,point b,point c,point d)
{
    if(a==b || a==c || a==d || b==c || b==d || c==d)
        return 0;
    double x[7];
    x[0]=hypot(a.x-b.x,a.y-b.y);
    x[1]=hypot(a.x-c.x,a.y-c.y);
    x[2]=hypot(a.x-d.x,a.y-d.y);
    x[3]=hypot(b.x-c.x,b.y-c.y);
    x[4]=hypot(b.x-d.x,b.y-d.y);
    x[5]=hypot(c.x-d.x,c.y-d.y);
    if((ccw_(a,b,c)==1 && ccw_(a,b,d)==-1) || (ccw_(a,b,c)==-1 && ccw_(a,b,d)==1) )
    {
        if(fabs(x[2]-x[3])<EPS && fabs(x[1]-x[4])<EPS && fabs(angle(a,c,b)-PI/2)<EPS && fabs(angle(a,d,b)-PI/2)<EPS)
            return 1;
    }
    else if((ccw_(a,c,b)==1 && ccw_(a,c,d)==-1) ||(ccw_(a,c,b)==-1 && ccw_(a,c,d)==1))
    {
        if(fabs(x[0]-x[5])<EPS && fabs(x[2]-x[3])<EPS && fabs(angle(a,b,c)-PI/2)<EPS && fabs(angle(a,d,c)-PI/2)<EPS)
            return 1;
    }
    else if((ccw_(a,d,b)==1 && ccw_(a,d,c)==-1) ||(ccw_(a,d,b)==-1 && ccw_(a,d,c)==1))
    {
        if(fabs(x[0]-x[5])<EPS && fabs(x[1]-x[4])<EPS && fabs(angle(a,b,d)-PI/2)<EPS && fabs(angle(a,c,d)-PI/2)<EPS)
            return 1;
    }
    return 0;
}
double area_polygon_side_4(double a,double b,double c,double d)
{
    double s=(a+b+c+d)/2;
    return sqrt((s-a)*(s-b)*(s-c)*(s-d));
}


point lineIntersectSeg(point p, point q, point A, point B)
{
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}




vector<point> cutPolygon(point a, point b, const vector<point> &Q)
{
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++)
    {
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
        if (left1 > -EPS) P.push_back(Q[i]); 

        if (left1 * left2 < -EPS) 

            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front()); 

    return P;
}
point pivot(0, 0);
bool angleCmp(point a, point b)   

{
    if (collinear(pivot, a, b)) 

        return dist(pivot, a) < dist(pivot, b); 

    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
} 

vector<point> CH(vector<point> P)   

{
    int i, j, n = (int)P.size();
    if (n <= 3)
    {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); 

        return P;
    } 

    

    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp; 

    

    pivot = P[0]; 

    sort(++P.begin(), P.end(), angleCmp); 

    

    

    

    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]); 

    i = 2; 

    while (i < n)   

    {
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); 

        else S.pop_back();
    } 

    return S;
} 

struct line2
{
    double m, c;
}; 

int pointsToLine2(point p1, point p2, line2 &l)
{
    if (p1.x == p2.x)   

    {
        l.m = INF; 

        l.c = p1.x; 

        return 0; 

    }
    else
    {
        l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
        l.c = p1.y - l.m * p1.x;
        return 1; 

    }
}

int main()
{
    int n;
    point a[10000];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);
    }
    double m=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            double u=0,v=0;
            bool e=0,r=0;
            for(int k=0; k<n; k++)
            {
                if(k==i||k==j)continue;
                int x=ccw_(a[i],a[j],a[k]);
                if(x==1)
                {
                    e=1;
                    double s=((a[i].x*a[j].y)-(a[i].y*a[j].x))+((a[j].x*a[k].y)-(a[j].y*a[k].x))+((a[k].x*a[i].y)-(a[k].y*a[i].x));
                    u=max(u,abs(s));
                }
                else if(x==-1)
                {
                    r=1;
                    double s=((a[i].x*a[j].y)-(a[i].y*a[j].x))+((a[j].x*a[k].y)-(a[j].y*a[k].x))+((a[k].x*a[i].y)-(a[k].y*a[i].x));
                    v=max(v,abs(s));
                }
            }
            if(e && r)
                m=max(m,u+v);
        }
    }
    printf("%.6lf",m/2.0);
    return 0;
}
