


















































using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;







const double EPS = 1.0e-9;
typedef double PType;
class Point
{
public:
    PType x, y;
    Point() : x(0), y(0) {}
    Point(PType xx, PType yy) : x(xx), y(yy) {}
};

Point operator+(Point p1, Point p2)
{ return Point(p1.x + p2.x, p1.y + p2.y); }

Point operator-(Point p1, Point p2)
{ return Point(p1.x - p2.x, p1.y - p2.y); }

Point operator*(Point p1, Point p2)
{
    double x = p1.x*p2.x - p1.y*p2.y;
    double y = p1.x*p2.y + p1.y*p2.x;
    return Point(x,y);
}

bool operator<(Point p1, Point p2)
{ return p1.x < p2.x || (p1.x==p2.x && p1.y < p2.y); }

bool operator==(Point p1, Point p2)
{ return fabs(p1.x-p2.x)<=EPS && fabs(p1.y-p2.y)<=EPS; }

bool operator!=(Point p1, Point p2)
{ return !(p1==p2); }

ostream& operator<<(ostream &os, Point p) 
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

PType dot(Point p1, Point p2)
{ return p1.x * p2.x + p1.y * p2.y; }

PType det(Point p1, Point p2) 

{ return p1.x * p2.y - p1.y * p2.x; }


inline double norm2(Point p)
{ return (p.x*p.x + p.y*p.y); }

inline double norm(Point p)
{ return sqrt(norm2(p)); }

inline double dist2(Point p1, Point p2)
{ return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y); }

inline double dist(Point p1, Point p2)
{ return sqrt(dist2(p1,p2)); }





double id7(Point p1, Point p2, Point pt)
{
    Point v1 = p1-pt, v2=p2-pt;
    double area = det(v1,v2);
    return fabs(area) / dist(p1,p2);
}





bool id8(Point p1, Point p2, Point pt)
{
    double eps = EPS*10;
    bool good = (min(p1.x,p2.x)-eps <= pt.x) && (pt.x <= max(p1.x,p2.x)+eps) &&
        (min(p1.y,p2.y)-eps <= pt.y) && (pt.y <= max(p1.y,p2.y)+eps);
    return good;
}

bool collinear(Point p1, Point p2, Point p3)
{ return id7(p1,p2,p3) <= EPS; }

bool id1(Point p1, Point p2, Point pt)
{
    return id7(p1,p2,pt) <= EPS && id8(p1,p2,pt);
}






















bool lineIntersect(double A1, double B1, double C1,
    double A2, double B2, double C2, Point &pt)
{
    double det = A1*B2 - A2*B1;
    if (fabs(det) < EPS) { 
        

        return false;
    } else {
        pt.x = 1.0/det*(B2*C1-B1*C2);
        pt.y = 1.0/det*(A1*C2-A2*C1);
        return true;
    }
}



void id3(Point p1, Point p2, double &A, double &B, double &C)
{ A = (p2.y-p1.y); B = (p1.x-p2.x); C = A*p1.x+B*p1.y; }



bool segmentIntersect(Point p1, Point p2, Point p3, Point p4)
{
    double A1,B1,C1; id3(p1,p2,A1,B1,C1);
    double A2,B2,C2; id3(p3,p4,A2,B2,C2);
    Point pt;
    if (!lineIntersect(A1,B1,C1,A2,B2,C2,pt)) return false;
    return id8(p1,p2,pt) && id8(p3,p4,pt);
}









int id4(Point p1, Point p2, Point pt)
{
    Point v1 = p2-p1, v2 = pt-p1;
    double val = det(v1,v2)/(norm(v1)*norm(v2)); 

    if (fabs(val) <= EPS) return 0;
    else if (val > 0) return +1;
    else return -1;
}





bool id9(Point p1, Point p2, Point p3, Point p4)
{
    

    return (id4(p1,p2,p3)*id4(p1,p2,p4) <= 0 &&
        id4(p3,p4,p1)*id4(p3,p4,p2) <= 0);
}

double max3(double a, double b, double c)
{ return max(a,max(b,c)); }
double min3(double a, double b, double c)
{ return min(a,min(b,c)); }




Point id12(Point pts[])
{
    

    double x1 = pts[0].x, y1 = pts[0].y;
    double x2 = pts[1].x, y2 = pts[1].y;
    double x3 = pts[2].x, y3 = pts[2].y;

    if (collinear(pts[0],pts[1],pts[2]))
    {
        double xc = (min3(x1,x2,x3) + max3(x1,x2,x3))/2.0;
        double yc = (min3(y1,y2,y3) + max3(y1,y2,y3))/2.0;
        return Point(xc,yc);
    }
    

    double A1 = y2-y1, B1 = x1-x2; 

    double D1 = -B1, E1 = A1, F1 = D1*(x1+x2)/2.0 + E1*(y1+y2)/2.0;
    

    double A2 = y3-y2, B2 = x2-x3; 

    

    double D2 = -B2, E2 = A2, F2 = D2*(x2+x3)/2.0 + E2*(y2+y3)/2.0;

    Point pt;
    bool isinter = lineIntersect(D1,E1,F1,D2,E2,F2,pt);
    assert(isinter);
    return pt;
}



double area(const vector<Point> &pa)
{
    int n = pa.size();
    double ret = 0.0;
    for(int i=0; i < n; i++)
    {
        ret += det(pa[i], pa[(i+1)%n]);
    }
    return ret/2.0;
}

vector<Point> id13(vector<Point> pa)
{
    

    int n = pa.size();
    if (n < 2) return pa;
    vector<Point> hull(2*n); 


    sort(pa.begin(), pa.end());

    

    int k=0;
    for(int i=0; i < n; hull[k++] = pa[i++])
        while(k > 1 && det(hull[k-1]-hull[k-2], pa[i]-hull[k-2]) <= 0) k--;
    

    for(int i=n-2, t=k; i >= 0; hull[k++] = pa[i--])
        while(k > t && det(hull[k-1] - hull[k-2], pa[i]-hull[k-2]) <= 0) k--;

    k--;
    vector<Point> ret(k);
    copy(hull.begin(), hull.begin()+k, ret.begin());
    return ret;
}









int id10(const vector<Point> &pts, Point pt)
{
    

    Point ptout(INT_MAX,INT_MAX);
    

    int cnt=0, N=pts.size();
    for(int i=0; i<N; ++i)
    { 
        Point p1=pts[i], p2=pts[(i+1)%N];
        

        if (id1(p1,p2,pt)) return 0;

        if (segmentIntersect(pt,ptout,p1,p2) !=
            id9(pt,ptout,p1,p2))
        { cout << pt << " " << ptout << " " << p1 << " " << p2 << endl;
            abort(); }
        if (segmentIntersect(pt,ptout,p1,p2)) { 
        

            

            if (id1(pt,ptout,p1) && id1(pt,ptout,p2))
            {  }
            else if (id1(pt,ptout,p2))
            {
                

                

                Point p3 = pts[(i+2)%N];
                double left1, left2;
                left1 = det(p1-pt,ptout-pt);
                left2 = det(p3-pt,ptout-pt);
                if (left1*left2 < 0) cnt++;
            }
            else if (id1(pt,ptout,p1))
            {  }
            else { cnt++; }
            

        }
    }
    

    if (cnt&1) return +1;
    else return -1;
}

class PointInPolygon
{ 
public: 
    string testPoint(vector <string> ver, int testX, int testY) 
    { 
        string in="INTERIOR", out="EXTERIOR", bound="BOUNDARY";
        int N = ver.size(); Point pt(testX,testY);
        vector<Point> pts;
        for(int i=0; i<N; ++i)
        {
            istringstream ss(ver[i]);
            int x,y; ss >> x >> y; pts.push_back(Point(x,y));
        }
        switch(id10(pts,pt))
        {
        case +1: return in;
        case -1: return out;
        case  0: return bound;
        }
        return out;
    } 
    


	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) id0(); if ((Case == -1) || (Case == 2)) id17(); if ((Case == -1) || (Case == 3)) id14(); if ((Case == -1) || (Case == 4)) id5(); if ((Case == -1) || (Case == 5)) id16(); if ((Case == -1) || (Case == 6)) id6(); if ((Case == -1) || (Case == 7)) id2(); if ((Case == -1) || (Case == 8)) id15(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case 
	void test_case_0() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 5; string Arg3 = "INTERIOR"; verify_case(0, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id0() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; string Arg3 = "EXTERIOR"; verify_case(1, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id17() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 10; string Arg3 = "BOUNDARY"; verify_case(2, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id14() { string Arr0[] = {"-100 -90", "-100 100","100 100", "100 -100",
 "-120 -100","-120 100","-130 100","-130 -110",
 "110 -110", "110 110", "-110 110","-110 -90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "EXTERIOR"; verify_case(3, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id5() { string Arr0[] = {"0 0","0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 500; string Arg3 = "INTERIOR"; verify_case(4, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id16() { string Arr0[] = {"0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 322; int Arg2 = 333; string Arg3 = "EXTERIOR"; verify_case(5, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id6() { string Arr0[] = {"500 0","500 100","400 100","400 200","300 200",
 "300 300","200 300","200 400","100 400","100 500",
 "0 500","0 400","-100 400","-100 300","-200 300",
  "-200 200","-300 200","-300 100","-400 100","-400 0",
  "-500 0","-500 -100","-400 -100","-400 -200","-300 -200",
  "-300 -300","-200 -300","-200 -400","-100 -400","-100 -500",
  "0 -500","0 -400","100 -400","100 -300","200 -300",
  "200 -200","300 -200","300 -100","400 -100","400 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; int Arg2 = 200; string Arg3 = "INTERIOR"; verify_case(6, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id2() { string Arr0[] = {"1 0","2 0","2 1","3 1","3 0","4 0","4 -1","5 -1","5 0",
 "6 0","6 2","0 2","0 3","-1 3","-1 4","0 4","0 6","1 6",
 "1 7","0 7","0 8","-2 8","-2 2","-8 2","-8 0","-7 0",
 "-7 -1","-6 -1","-6 0","-4 0","-4 1","-3 1","-3 0",
 "-2 0","-2 -6","0 -6","0 -5","1 -5","1 -4","0 -4",
 "0 -3","-1 -3","-1 -2","0 -2","0 -1","1 -1"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "INTERIOR"; verify_case(7, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void id15() { string Arr0[] = { "0 0", "3 0", "3 4", "-2 4", "-2 0", "-1 0", "-1 3", "2 3", "2 1", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; string Arg3 = "EXTERIOR"; verify_case(8, Arg3, testPoint(Arg0, Arg1, Arg2)); }



 
}; 

class id11
{
public:
    double x, y, z;
    id11() { x=y=z=0.0; }
    id11(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
};

id11 operator-(id11 p1, id11 p2) { return id11(p1.x-p2.x, p1.y-p2.y, p1.z-p2.z); }
ostream& operator<<(ostream &os, id11 p)
{ return os << "(" << p.x << "," << p.y << "," << p.z << ")"; }

bool operator==(id11 p1, id11 p2)
{ return (fabs(p1.x-p2.x)<=EPS && fabs(p1.y-p2.y)<=EPS && fabs(p1.z-p2.z)<=EPS); }
bool operator!=(id11 p1, id11 p2)
{ return !(p1==p2); }

double sqr(double x) { return x*x; }

double norm2(id11 p) { return sqr(p.x)+sqr(p.y)+sqr(p.z); }
double norm(id11 p) { return sqrt(norm2(p)); }

double dist2(id11 p1, id11 p2)
{ return (sqr(p1.x-p2.x) + sqr(p1.y-p2.y) + sqr(p1.z-p2.z)); }
double dist(id11 p1, id11 p2)
{ return sqrt(dist2(p1,p2)); }



double balldist(double lat1, double lng1, double lat2, double lng2, double R)
{
    double dlat = lat2-lat1, dlng = lng2-lng1;
    double a = sqr(sin(dlat/2))+cos(lat1)*cos(lat2)*sqr(sin(dlng/2));
    double c = 2*atan2(sqrt(a), sqrt(1-a));
    return R*c;
}

double dot(id11 p1, id11 p2)
{ return p1.x*p2.x + p1.y*p2.y + p1.z*p2.z; }

id11 cross(id11 p1, id11 p2)
{ 
    double x = p1.y*p2.z - p1.z*p2.y;
    double y = -(p1.x*p2.z - p1.z*p2.x);
    double z = p1.x*p2.y - p2.x*p1.y;
    return id11(x,y,z);
}



double ptLineDist(id11 p1, id11 p2, id11 pt)
{
    double area = norm(cross(p1-pt,p2-pt));
    if (p1==p2) return dist(p1,pt);
    else return area/dist(p1,p2);
}



void XYZconvert(double lat, double lng, double alt, id11 &pt)
{
    const double PI = acos(-1.0);
    pt.x = cos(lng/180*PI)*cos(lat/180*PI)*alt;
    pt.y = sin(lng/180*PI)*cos(lat/180*PI)*alt;
    pt.z = sin(lat/180*PI)*alt;
}





double balldist(id11 p1, id11 p2, double R)
{
    double ang = acos(dot(p1,p2)/(norm(p1)*norm(p2)));
    return ang*R;
}





double balldist2(double lat1, double lng1, double lat2, double lng2, double R)
{
    double dlat = lat2-lat1, dlng = lng2-lng1;
    double a = sqr(sin(dlat/2))+cos(lat1)*cos(lat2)*sqr(sin(dlng/2));
    double c = 2*atan2(sqrt(a), sqrt(1-a));
    return R*c;
}

void solve()
{
    Point start, end; cin >> start.x >> start.y >> end.x >> end.y;
    int n; cin >> n;
    vector<Point> vp(n);
    for(int i=0; i<n; ++i) cin >> vp[i].x >> vp[i].y;

    int cnt=0, x[2];
    Point pts[2];
    for(int i=0; i<n; ++i)
    {
        int next = (i+1)%n;
        if (segmentIntersect(vp[i],vp[next],start,end))
        {
            double A1,B1,C1,A2,B2,C2;
            id3(vp[i],vp[next],A1,B1,C1);
            id3(start,end,A2,B2,C2);
            lineIntersect(A1,B1,C1,A2,B2,C2,pts[cnt]);
            if (cnt==0) { x[cnt++]=i; } 

            else if (cnt==1) { 

                if (pts[0] == pts[1]) {  }
                else { x[cnt++]=i; break; }
            }
        }
    }
    

    

    double res;
    if (cnt == 2)
    {
        double d1 = min(dist(start,pts[0]), dist(start,pts[1]));
        double d2 = min(dist(end,pts[0]), dist(end, pts[1]));
        double plen = 0.0;
        for(int i=0; i<n; ++i) { plen += dist(vp[i],vp[(i+1)%n]); }
        double d3 = 0;
        for(int i=(x[0]+1)%n; i!=x[1]; i=(i+1)%n) d3+=dist(vp[i],vp[(i+1)%n]);
        d3 += dist(pts[0],vp[(x[0]+1)%n]) + dist(vp[x[1]],pts[1]);
        res = d1+d2+min3(d3,plen-d3,2*dist(pts[0],pts[1]));
    }
    else { res = dist(start,end); }
    cout << fixed << setprecision(7) << res << endl;
}

int main()
{
    solve();
}
