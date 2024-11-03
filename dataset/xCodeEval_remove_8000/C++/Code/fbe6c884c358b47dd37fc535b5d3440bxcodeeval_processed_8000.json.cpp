









using namespace std;





const double INF        = 1e10;     

const double EPS        = 1e-9;    

const double PI         = acos (-1.0);
const int LEFT          = 0;        

const int RIGHT         = 1;        

const int ONLINE        = 2;        

const int CROSS         = 0;        

const int COLINE        = 1;        

const int id24      = 2;        

const int id12   = 3;        

const int INSIDE        = 1;        

const int OUTSIDE       = 2;        

const int BORDER        = 3;        

const int id5        = 1;        

const int id2        = 2;        

const int id23      = 3;        

const int id25        = 4;        

const int id0        = 5;        








struct Point {              

    double x, y;
    int z;
    double angle, dis;
    Point() {}
    Point(double x0, double y0): x(x0), y(y0) {}
    Point(double x0, double y0, int z0): x(x0), y(y0), z(z0) {}
    void scan()  { scanf ("%lf %lf", &x, &y);}
    void print() { printf ("%f %f\n", x, y);}

};
struct id22 {            

    double x, y, z;
    id22() {}
    id22(double x0, double y0, double z0): x(x0), y(y0), z(z0) {}
    void scan()  { scanf ("%lf %lf %lf", &x, &y, &z);}
    void print() { printf ("%f %f %f\n", x, y, z);}
};
struct Line {               

    Point p1, p2;
    Line() {}
    Line(Point p10, Point p20): p1(p10), p2(p20) {}
    void scan()  { p1.scan();  p2.scan();}
    void print() { p1.print();  p2.print();}
};
struct id16 {             

    id22 p1, p2;
    id16() {}
    id16(id22 p10, id22 p20): p1(p10), p2(p20) {}
    void scan()  { p1.scan();  p2.scan();}
    void print() { p1.print();  p2.print();}
};
struct Rect {              

    double w, h;
    Rect() {}
    Rect(double _w,double _h) : w(_w),h(_h) {}
    void scan()  { scanf ("%lf %lf", &w, &h);}
    void print() { printf ("%f %f\n", w, h);}
};
struct id17 {             

    double xl, yl, xh, yh;
    id17() {}
    id17(double _xl,double _yl,double _xh,double _yh) : xl(_xl),yl(_yl),xh(_xh),yh(_yh) {}
};
struct Circle {            

    Point c;
    double r;
    Circle() {}
    Circle(Point _c,double _r) :c(_c),r(_r) {}
    void scan()  { c.scan(); scanf ("%lf", &r);}
    void print() { c.print(); printf ("%f\n", r);}
};
typedef vector<Point> Polygon;      

typedef vector<Point> Points;       

typedef vector<id22> Points3D;   

typedef vector<Circle> Circles;







inline double max(double x,double y) {
    return x > y ? x : y;
}
inline double min(double x, double y) {
    return x > y ? y : x;
}
inline bool ZERO(double x) {            

    return (fabs(x) < EPS);
}
inline bool ZERO(Point p) {            

    return (ZERO(p.x) && ZERO(p.y));
}
inline bool ZERO(id22 p) {            

    return (ZERO(p.x) && ZERO(p.y) && ZERO(p.z));
}
inline bool EQ(double x, double y) {     

    return (fabs(x - y) < EPS);
}
inline bool NEQ(double x, double y) {    

    return (fabs(x - y) >= EPS);
}
inline bool LT(double x, double y) {    

    return ( NEQ(x, y) && (x < y) );
}
inline bool GT(double x, double y) {    

    return ( NEQ(x, y) && (x > y) );
}
inline bool LEQ(double x, double y) {    

    return ( EQ(x, y) || (x < y) );
}
inline bool GEQ(double x, double y) {    

    return ( EQ(x, y) || (x > y) );
}












inline double FIX(double x) {
    return (fabs(x) < EPS) ? 0 : x;
}







bool operator==(Point p1, Point p2) {
    return ( EQ(p1.x, p2.x) &&  EQ(p1.y, p2.y) );
}
bool operator!=(Point p1, Point p2) {
    return ( NEQ(p1.x, p2.x) ||  NEQ(p1.y, p2.y) );
}
bool operator<(Point p1, Point p2) {
    if (NEQ(p1.x, p2.x)) {
        return (p1.x < p2.x);
    }
    else {
        return (p1.y < p2.y);
    }
}
Point operator+(Point p1, Point p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator-(Point p1, Point p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}
Point operator*(Point p1, double x) {
    return Point(p1.x * x, p1.y * x);
}
Point operator/(Point p1, double x) {
    return Point(p1.x / x, p1.y / x);
}
double operator*(Point p1, Point p2) {

    return (p1.x * p2.y - p2.x * p1.y);
}
double operator&(Point p1, Point p2) { 

    return (p1.x * p2.x + p1.y * p2.y);
}
double Norm(Point p) {

    return sqrt(p.x * p.x + p.y * p.y);
}






Point Rotate(Point p, double angle) {
    Point result;
    result.x = p.x * cos(angle) - p.y * sin(angle);
    result.y = p.x * sin(angle) + p.y * cos(angle);
    return result;
}







bool operator==(id22 p1, id22 p2) {
    return ( EQ(p1.x, p2.x) && EQ(p1.y, p2.y) && EQ(p1.z, p2.z) );
}
bool operator<(id22 p1, id22 p2) {
    if (NEQ(p1.x, p2.x)) {
        return (p1.x < p2.x);
    }
    else if (NEQ(p1.y, p2.y)) {
        return (p1.y < p2.y);
    }
    else {
        return (p1.z < p2.z);
    }
}
id22 operator+(id22 p1, id22 p2) {
    return id22(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}
id22 operator-(id22 p1, id22 p2) {
    return id22(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}
id22 operator*(id22 p1, id22 p2) {

    return id22(p1.y * p2.z - p1.z * p2.y,
                    p1.z * p2.x - p1.x * p2.z,
                    p1.x * p2.y - p1.y * p2.x );
}
double operator&(id22 p1, id22 p2) { 

    return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}
double Norm(id22 p) {

    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}














double Area(Point A, Point B, Point C) {

    return ((B-A)*(C-A) / 2.0);
}


double Area(double a, double b, double c) {

    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
double Area(const Circle & C) {
    return PI * C.r * C.r;
}




double Area(const Polygon& poly) {

    double res = 0;
    int n = poly.size();
    if (n < 3) return 0;
    for(int i = 0; i < n; i++) {
        res += poly[i].x * poly[(i+1)%n].y;
        res -= poly[i].y * poly[(i+1)%n].x;
    }
    return (res / 2.0);
}









double Distance(Point p1, Point p2) {

    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double Distance(id22 p1, id22 p2) {

    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y-p2.y)
             + (p1.z - p2.z) * (p1.z - p2.z));
}
double Distance(Point p, Line L) {

    return ( fabs((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) );
}
double Distance(id22 p, id16 L) {

    return ( Norm((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) );
}
bool OnLine(Point p, Line L) {

    return ZERO( (p - L.p1) * (L.p2 - L.p1) );
}
bool OnLine(id22 p, id16 L) {

    return ZERO( (p - L.p1) * (L.p2 - L.p1) );
}
int Relation(Point p, Line L) {

    double res = (L.p2 - L.p1) * (p - L.p1);
    if (EQ(res, 0)) {
        return ONLINE;
    }
    else if (res > 0) {
        return LEFT;
    }
    else {
        return RIGHT;
    }
}
bool SameSide(Point p1, Point p2, Line L) {

    double m1 = (p1 - L.p1) * (L.p2 - L.p1);
    double m2 = (p2 - L.p1) * (L.p2 - L.p1);
    return GT(m1 * m2, 0);
}
bool id15(Point p, Line L) {

    return ( ZERO( (L.p1 - p) * (L.p2 - p) ) &&
        LEQ((p.x - L.p1.x)*(p.x - L.p2.x), 0) &&
        LEQ((p.y - L.p1.y)*(p.y - L.p2.y), 0) );
}
bool id15(id22 p, id16 L) {

    return ( ZERO((L.p1 - p) * (L.p2 - p)) &&
        EQ( Norm(p - L.p1) + Norm(p - L.p2), Norm(L.p2 - L.p1)) );
}
Point SymPoint(Point p, Line L) {

    Point result;
    double a = L.p2.x - L.p1.x;
    double b = L.p2.y - L.p1.y;
    double t = ( (p.x - L.p1.x) * a + (p.y - L.p1.y) * b ) / (a*a + b*b);
    result.x = 2 * L.p1.x + 2 * a * t - p.x;
    result.y = 2 * L.p1.y + 2 * b * t - p.y;
    return result;
}
bool id13(Points3D points) {

    int i;
    id22 p;
    if (points.size() < 4) return true;
    p = (points[2] - points[0]) * (points[1] - points[0]);
    for (i = 3; i < points.size(); i++) {
        if (! ZERO(p & points[i]) ) return false;
    }
    return true;
}
bool LineIntersect(Line L1, Line L2) {

    return (! ZERO((L1.p1 - L1.p2)*(L2.p1 - L2.p2)) );  

}
bool LineIntersect(id16 L1, id16 L2) {

    id22 p1 = L1.p1 - L1.p2;
    id22 p2 = L2.p1 - L2.p2;
    id22 p  = p1 * p2;
    if (ZERO(p)) return false;      

    p = (L2.p1 - L1.p2) * (L1.p1 - L1.p2);
    return ZERO(p & L2.p2);         

}
bool id20(Line L1, Line L2) {

    return ( GEQ( max(L1.p1.x, L1.p2.x), min(L2.p1.x, L2.p2.x) ) &&
        GEQ( max(L2.p1.x, L2.p2.x), min(L1.p1.x, L1.p2.x) ) &&
        GEQ( max(L1.p1.y, L1.p2.y), min(L2.p1.y, L2.p2.y) ) &&
        GEQ( max(L2.p1.y, L2.p2.y), min(L1.p1.y, L1.p2.y) ) &&
        LEQ( ((L2.p1 - L1.p1) * (L1.p2 - L1.p1)) * ((L2.p2 -  L1.p1) * (L1.p2 - L1.p1)), 0 ) &&
        LEQ( ((L1.p1 - L2.p1) * (L2.p2 - L2.p1)) * ((L1.p2 -  L2.p1) * (L2.p2 - L2.p1)), 0 ) );
}
bool id20(id16 L1, id16 L2) {

    

    return true;
}




int id1(Line L1, Line L2, Point& P) {
    double A1, B1, C1, A2, B2, C2;

    A1 = L1.p2.y - L1.p1.y;
    B1 = L1.p1.x - L1.p2.x;
    C1 = L1.p2.x * L1.p1.y - L1.p1.x * L1.p2.y;

    A2 = L2.p2.y - L2.p1.y;
    B2 = L2.p1.x - L2.p2.x;
    C2 = L2.p2.x * L2.p1.y - L2.p1.x * L2.p2.y;

    if (EQ(A1 * B2, B1 * A2))    {
        if (EQ( (A1 + B1) * C2, (A2 + B2) * C1 )) {
            return COLINE;
        }
        else {
            return id24;
        }
    }
    else {
        P.x = (B2 * C1 - B1 * C2) / (A2 * B1 - A1 * B2);
        P.y = (A1 * C2 - A2 * C1) / (A2 * B1 - A1 * B2);
        return CROSS;
    }
}




int id1(id16 L1, id16 L2, id22& P) {
    

    return 0;
}


Point id26(Point P, Line L) {
    Point result;
    double a, b, t;

    a = L.p2.x - L.p1.x;
    b = L.p2.y - L.p1.y;
    t = ( (P.x - L.p1.x) * a + (P.y - L.p1.y) * b ) / (a * a + b * b);

    result.x = L.p1.x + a * t;
    result.y = L.p1.y + b * t;
    return result;
}


Point id4(Point P, Line L) {
    Point result;
    double a, b, t;

    a = L.p2.x - L.p1.x;
    b = L.p2.y - L.p1.y;
    t = ( (P.x - L.p1.x) * a + (P.y - L.p1.y) * b ) / (a * a + b * b);

    if ( GEQ(t, 0) && LEQ(t, 1) ) {
        result.x = L.p1.x + a * t;
        result.y = L.p1.y + b * t;
    }
    else {
        if ( Norm(P - L.p1) < Norm(P - L.p2) ) {
            result = L.p1;
        }
        else {
            result = L.p2;
        }
    }
    return result;
}


double MinDistance(Line L1, Line L2) {
    double d1, d2, d3, d4;

    if (id20(L1, L2)) {
        return 0;
    } else {
        d1 = Norm( id4(L1.p1, L2) - L1.p1 );
        d2 = Norm( id4(L1.p2, L2) - L1.p2 );
        d3 = Norm( id4(L2.p1, L1) - L2.p1 );
        d4 = Norm( id4(L2.p2, L1) - L2.p2 );

        return min( min(d1, d2), min(d3, d4) );
    }
}




double Inclination(Line L1, Line L2) {
    Point u = L1.p2 - L1.p1;
    Point v = L2.p2 - L2.p1;
    return acos( (u & v) / (Norm(u)*Norm(v)) );
}




double Inclination(id16 L1, id16 L2) {
    id22 u = L1.p2 - L1.p1;
    id22 v = L2.p2 - L2.p1;
    return acos( (u & v) / (Norm(u)*Norm(v)) );
}
Point id10(Point a, Point b) {

    Point m = (a + b) / 2, c, d;
    double x = a.x - m.x, y = a.y - m.y;
    c.x = -y + m.x;  c.y = x + m.y;
    d.x = y + m.x;  d.y = -x + m.y;
    return c - d;
}





















int id8(Point p, const Polygon& poly) {

    Point q(0, 0);
    Line side;
    int i, n = poly.size();

    for (i = 0; i < n; i++) {
        q.x += poly[i].x;
        q.y += poly[i].y;
    }
    q.x /= n;
    q.y /= n;
    for (i = 0; i < n; i++) {
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];
        if (id15(p, side)) {
            return BORDER;
        } else if (!SameSide(p, q, side)) {
            return OUTSIDE;
        }
    }
    return INSIDE;
}



bool id14(const Polygon& poly) {

    int i, n, rel;
    Line side;

    n = poly.size();
    if (n < 3) return false;
    side.p1 = poly[0];
    side.p2 = poly[1];
    rel = Relation(poly[2], side);
    for (i = 1; i < n; i++) {
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];
        if (Relation(poly[(i+2)%n], side) != rel) return false;
    }
    return true;
}












int InsidePolygon(const Polygon& poly, Point p) {

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

        if( id15(p, side) ) {
            return BORDER;
        }
        

        if ( EQ(side.p1.y, side.p2.y) ) {
            continue;
        }
        if (id15(side.p1, ray)) {
            if (GT(side.p1.y, side.p2.y)) count++;
        } else if (id15(side.p2, ray)) {
            if ( GT(side.p2.y, side.p1.y)) count++;
        } else if (id20(ray, side)) {
            count++;
        }
    }
    return ((count % 2 == 1) ? INSIDE : OUTSIDE);
}




bool InsidePolygon(const Polygon& poly, Line L) {

    bool result;
    int n, i;
    Points points;
    Point p;
    Line side;

    result = ( (InsidePolygon(poly, L.p1) != OUTSIDE) &&
        (InsidePolygon(poly, L.p2) != OUTSIDE) );

    if (!result) return false;

    n = poly.size();
    for (i = 0; i < n; i++) {
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];

        if ( id15(L.p1, side) ) {
            points.push_back(L.p1);
        } else if ( id15(L.p2, side) ) {
            points.push_back(L.p2);
        } else if ( id15(side.p1, L) ) {
            points.push_back(side.p1);
        } else if ( id15(side.p2, L) ) {
            points.push_back(side.p2);
        } else if( id20(side, L) ) {
            return false;
        }
    }
    

    sort(points.begin(), points.end());

    for (i = 1; i < points.size(); i++) {
        if (points[i-1] != points[i]) {
            p.x = (points[i-1].x + points[i].x) / 2.0;
            p.y = (points[i-1].y + points[i].y) / 2.0;
            if ( InsidePolygon(poly, p) == OUTSIDE ) {
                return false;
            }
        }
    }
    return true;
}




bool id7(const Point& left, const Point& right) {
    if (EQ(left.angle, right.angle)) {
        return (left.dis < right.dis);
    } else {
        return (left.angle < right.angle);
    }
}

bool id27(Points points, Polygon& result) {
    int i, k, n;
    Point p;

    n = points.size();
    result.clear();

    if (n < 3) return  false;

    

    

    k = 0;
    for (i = 1; i < n; i++ ) {
        if (EQ(points[i].y, points[k].y)) {
            if (points[i].x <= points[k].x) k = i;
        } else if (points[i].y < points[k].y) {
            k = i;
        }
    }
    swap(points[0], points[k]);

    

    

    for (i = 1; i < n; i++) {
        points[i].angle = atan2(points[i].y - points[0].y, points[i].x - points[0].x);
        points[i].dis   = Norm(points[i] - points[0]);
    }

    

    

    sort(points.begin() + 1, points.end(), id7);

    

    result.push_back(points[0]);
    for (i = 1; i < n; i++) {
        

        if ((i + 1 < n) && EQ(points[i].angle, points[i+1].angle)) continue;
        if (result.size() >= 3) {
            p = result[result.size() - 2];
            while ( GEQ((points[i] - p)*(result.back() - p), 0) )
            {
                result.pop_back();
                p = result[result.size() - 2];
            }
        }
        result.push_back( points[i] );
    }
    return true;
}
















double id21(const Polygon& poly, const Line& line, Polygon result[3]) {
    vector<Point> points;
    Line side;
    Point p;
    int i,n, cur, pre;

    result[LEFT].clear();
    result[RIGHT].clear();
    result[ONLINE].clear();
    n = poly.size();
    if (n == 0) return 0;
    pre = cur = Relation(poly[0], line);

    for (i = 0; i < n; i++) {
        cur = Relation(poly[(i+1)%n], line);
        if (cur == pre) {
            result[cur].push_back(poly[(i+1)%n]);
        } else {
            side.p1 = poly[i];
            side.p2 = poly[(i+1)%n];
            id1(side, line, p);
            points.push_back(p);
            result[pre].push_back(p);
            result[cur].push_back(p);
            result[cur].push_back(poly[(i+1)%n]);
            pre = cur;
        }
    }

    sort(points.begin(), points.end());

    if (points.size() < 2) {
        return 0;
    } else {
        return Norm(points.front() - points.back());
    }
}




Point id3(const Polygon& p) {

    double area = 0;
    int n = p.size();
    double cen_x = 0, cen_y = 0, tm;
    for(int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        tm = p[i] * p[j];
        area += tm;

        cen_x += (p[i].x + p[j].x) * tm;

        cen_y += (p[i].y + p[j].y) * tm;

    }
    area /= 2.0;
    cen_x /= 6.0 * area;
    cen_y /= 6.0 * area;
    return Point (cen_x, cen_y);








































}





bool Intersect(id17 r1, id17 r2) {
    return ( max(r1.xl, r2.xl) < min(r1.xh, r2.xh) &&
             max(r1.yl, r2.yl) < min(r1.yh, r2.yh) );
}








bool IsContain(Rect r1, Rect r2) {     

     if(r1.w >r2.w && r1.h > r2.h) return true;
     else
     {
        double r = sqrt(r2.w*r2.w + r2.h*r2.h) / 2.0;
        double alpha = atan2(r2.h,r2.w);
        double sita = asin((r1.h/2.0)/r);
        double x = r * cos(sita - 2*alpha);
        double y = r * sin(sita - 2*alpha);
        if(x < r1.w/2.0 && y < r1.h/2.0 && x > 0 && y > -r1.h/2.0) return true;
        else return false;
     }
}








double CommonArea(Circle A, Circle B) {

    double area = 0.0;
    Circle M = (A.r > B.r) ? A : B;
    Circle N = (A.r > B.r) ? B : A;
    double D = Distance(M.c, N.c);
    if ((D < M.r + N.r) && (D > M.r - N.r))
    {
        double cosM = (M.r * M.r + D * D - N.r * N.r) / (2.0 * M.r * D);
        double cosN = (N.r * N.r + D * D - M.r * M.r) / (2.0 * N.r * D);
        double alpha = 2.0 * acos(cosM);
        double beta  = 2.0 * acos(cosN);
        double TM = 0.5 * M.r * M.r * sin(alpha);
        double TN = 0.5 * N.r * N.r * sin(beta);
        double FM = (alpha / PI / 2) * Area(M);
        double FN = (beta / PI / 2) * Area(N);
        area = FM + FN - TM - TN;
    }
    else if (D <= M.r - N.r)
    {
        area = Area(N);
    }
    return area;
}

bool id19(const Circle & C, const id17 & rect) {

    return (GT(C.c.x - C.r, rect.xl)
  &&  LT(C.c.x + C.r, rect.xh)
  &&  GT(C.c.y - C.r, rect.yl)
  &&  LT(C.c.y + C.r, rect.yh));
}















int CirCir(const Circle &c1, const Circle &c2) {

    double dis = Distance(c1.c,c2.c);
    if(LT(dis,fabs(c1.r-c2.r))) return id5;
    if(EQ(dis,fabs(c1.r-c2.r))) return id2;
    if(LT(dis,c1.r+c2.r) && GT(dis,fabs(c1.r-c2.r))) return id23;
    if(EQ(dis,c1.r+c2.r)) return id25;
    return id0;
}




void id6 (Circle cir, Point p, Point& p1, Point& p2) {
    double theta = acos (cir.r / Distance (cir.c, p));
    p1 = cir.c + Rotate (p - cir.c, theta) / Distance (p, cir.c) * cir.r;
    p2 = cir.c + Rotate (p - cir.c, -theta) / Distance (p, cir.c) * cir.r;
}


void id9 (Circle cir1, Circle cir2, Point& p1, Point& p2, Point& p3, Point& p4) {
    double theta = acos ((cir1.r - cir2.r) / Distance (cir1.c, cir2.c));
    Point p = Rotate (cir2.c - cir1.c, - theta);
    p1 = cir1.c + p / Norm (p) * cir1.r;
    p2 = cir2.c + p / Norm (p) * cir2.r;
    p = Rotate (cir2.c - cir1.c, theta);
    p3 = cir1.c + p / Norm (p) * cir1.r;
    p4 = cir2.c + p / Norm (p) * cir2.r;
}





double id11(Points p, Point& id18) {
    Point u, v;
    double step = 0.0, curlen, explen, minlen;
    int i, j, k, idx, n = p.size();
    bool flag;
    

    for(i = 0; i < n; i++) {
        step += fabs(p[i].x) + fabs(p[i].y);
        u.x += p[i].x;
        u.y += p[i].y;
    }
    u.x /= n;
    u.y /= n;
    flag = 0;
    while(step > 1e-10) {
        for(k = 0; k < 10; step /= 2, k++)
            for(i = -1; i <= 1; i++)
                for(j = -1; j <= 1; j++) {
                    v.x = u.x + step * i;
                    v.y = u.y + step * j;
                    curlen = explen = 0.0;
                    for(idx = 0; idx < n; idx++) {
                        curlen += Distance(u, p[idx]);
                        explen += Distance(v, p[idx]);
                    }
                    if(curlen > explen) {
                        u = v;
                        minlen = explen;
                        flag = 1;
                    }
                }
    }
    id18 = u;
    return flag ? minlen : curlen;
}


Points red, blue;
int sum[MAXN][MAXN];

bool cmp (Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool ju (int i, int j, int k) {
    if (blue[k].x < red[i].x || blue[k].x >= red[j].x)  return false;
    if ((red[j] - red[i]) * (blue[k] - red[i]) < 0)  return false;
    return true;
}

int main()
{
    int n, m, x, y, i, j, k, ans = 0;
    scanf ("%d %d", &n, &m);
    if (n < 3)  {
        printf("0\n");
        return 0;
    }
    for (i = 1; i <= n; i ++) {
        scanf ("%d %d", &x, &y);
        red.pb (Point (x, y));
    }
    for (i = 1; i <= m; i ++) {
        scanf ("%d %d", &x, &y);
        blue.pb (Point (x, y));
    }
    sort (red.begin(), red.end(), cmp);
    for (i = 0; i < n; i ++)
        for (j = i + 1; j < n; j ++) {
            for (k = 0; k < m; k ++) {
                if (ju (i, j, k))  sum[i][j] ++;
            }
        }
    for (i = 0; i < n; i ++)
        for (j = i + 1; j < n; j ++)
            for (k = j + 1; k < n; k ++) {
                if (sum[i][j] + sum[j][k] - sum[i][k] == 0)  ans ++;
            }
    printf("%d\n", ans);
    return 0;
}
