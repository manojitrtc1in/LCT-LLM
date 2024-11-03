#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <fstream>
using namespace std;




#define FF(i, a, b) for(int i = (a); i < (b); ++i)
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FED(i, b, a) for(int i = (b); i>= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)
#define CLR(A,value) memset(A,value,sizeof(A))
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)




#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()




#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RIV(n, m, k, p) scanf("%d%d%d%d", &n, &m, &k, &p)
#define RV(n, m, k, p, q) scanf("%d%d%d%d%d", &n, &m, &k, &p, &q)
#define RS(s) scanf("%s", s)




#define WI(n) printf("%d\n", n)
#define WS(n) printf("%s\n", n)






#ifndef online_judge
#define debugt(a) cout << (#a) << "=" << a << " ";
#define debugI(a) debugt(a) cout << endl
#define debugII(a, b) debugt(a) debugt(b) cout << endl
#define debugIII(a, b, c) debugt(a) debugt(b) debugt(c) cout << endl
#define debugIV(a, b, c, d) debugt(a) debugt(b) debugt(c) debugt(d) cout << endl
#else
#define debugI(v)
#define debugII(a, b)
#define debugIII(a, b, c)
#define debugIV(a, b, c, d)
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int MOD = 100000007;
const int MAXN = 1000010;
const double PI = acos(-1.0);




double torad(double deg)
{
    return deg / 180 * PI;
}
inline int dcmp(double x)
{
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point
{
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) { }
    inline void read()
    {
        scanf("%lf%lf", &x, &y);
    }
};
typedef vector<Point> Polygon;
typedef Point Vector;

inline Vector operator + (Vector A, Vector B)
{
    return Vector(A.x+B.x, A.y+B.y);
}
inline Vector operator - (Point A, Point B)
{
    return Vector(A.x-B.x, A.y-B.y);
}
inline Vector operator * (Vector A, double p)
{
    return Vector(A.x*p, A.y*p);
}
inline Vector operator / (Vector A, double p)
{
    return Vector(A.x/p, A.y/p);
}


inline bool operator < (Point a, Point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}


inline bool operator == (Point a, Point b)
{
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}


inline double Dot(Vector A, Vector B)
{
    return A.x*B.x + A.y*B.y;
}
inline double Length(Vector A)
{
    return sqrt(Dot(A, A));
}
inline double Angle(Vector A, Vector B)
{
    return acos(Dot(A, B) / Length(A) / Length(B));
}
inline double angle(Vector v)
{
    return atan2(v.y, v.x);
}
inline double Cross(Vector A, Vector B)
{
    return A.x*B.y - A.y*B.x;
}
inline Vector Unit(Vector x)
{
    return x / Length(x);   

}
inline Vector Normal(Vector x)
{
    return Point(-x.y, x.x) / Length(x);   

}
inline Vector Rotate(Vector A, double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
inline double Area2(Point A, Point B, Point C)
{
    return Cross(B-A, C-A);
}

template <class T> T sqr(T x)
{
    return x * x ;
}





Point GetLineIntersection(Point p, Vector v, Point q, Vector w)
{
    Vector u = p-q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v*t;
}




inline Point GetLineProjection(Point P, Point A, Point B)
{
    Vector v = B-A;
    return A+v*(Dot(v, P-A) / Dot(v, v));
}




inline double DistanceToLine(Point P, Point A, Point B)
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1); 

}


inline bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) <= 0;
}




inline void getLineGeneralEquation(Point p1, Point p2, double& a, double& b, double &c)
{
    a = p2.y-p1.y;
    b = p1.x-p2.x;
    c = -a*p1.x - b*p1.y;
}


double DistanceToSegment(Point p, Point a, Point b)
{
    if(a == b) return Length(p-a);
    Vector v1 = b-a, v2 = p-a, v3 = p-b;
    if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}


inline double dis_pair_seg(Point p1, Point p2, Point p3, Point p4)
{
    return min(min(DistanceToSegment(p1, p3, p4), DistanceToSegment(p2, p3, p4)),
               min(DistanceToSegment(p3, p1, p2), DistanceToSegment(p4, p1, p2)));
}


inline bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1),
           c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}


struct Line
{
    Point p;    

    Vector v;   

    double ang; 

    Line() {}
    Line(Point P, Vector v):p(P),v(v)
    {
        ang = atan2(v.y, v.x);
    }
    inline bool operator < (const Line& L) const
    {
        return ang < L.ang;
    }
    inline Point point(double t)
    {
        return p + v * t;
    }
    inline Line move(double d)
    {
        return Line(p + Normal(v) * d, v);
    }
    inline void read()
    {
        Point q;
        p.read(), q.read();
        v = q - p;
        ang = atan2(v.y, v.x);
    }
};


inline Point GetLineIntersection(Line a, Line b)
{
    return GetLineIntersection(a.p, a.v, b.p, b.v);
}




inline bool OnLeft(const Line& L, const Point& p)
{
    return Cross(L.v, p-L.p) > 0;
}


















vector<Point> HalfplaneIntersection(vector<Line> L)
{
    int n = L.size();
    sort(L.begin(), L.end()); 



    int first, last;         

    vector<Point> p(n);      

    vector<Line> q(n);       

    vector<Point> ans;       



    q[first=last=0] = L[0];  

    for(int i = 1; i < n; i++)
    {
        while(first < last && !OnLeft(L[i], p[last-1])) last--;
        while(first < last && !OnLeft(L[i], p[first])) first++;
        q[++last] = L[i];
        if(fabs(Cross(q[last].v, q[last-1].v)) < eps)   

        {
            last--;
            if(OnLeft(q[last], L[i].p)) q[last] = L[i];
        }
        if(first < last) p[last-1] = GetLineIntersection(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1])) last--; 

    if(last - first <= 1) return ans; 

    p[last] = GetLineIntersection(q[last], q[first]); 



    

    for(int i = first; i <= last; i++) ans.push_back(p[i]);
    return ans;
}



double PolygonArea(vector<Point> p) {
  int n = p.size();
  double area = 0;
  for(int i = 1; i < n-1; i++)
    area += Cross(p[i]-p[0], p[i+1]-p[0]);
  return area/2;
}



int isPointInPolygon(Point p, Polygon poly)
{
    int wn = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++)
    {
        if (OnSegment(p, poly[i], poly[(i + 1) % n])) return -1;    

        int k = dcmp(Cross(poly[(i + 1) % n] - poly[i], p - poly[i]));
        int d1 = dcmp(poly[i].y - p.y);
        int d2 = dcmp(poly[(i + 1) % n].y - p.y);
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1;  

    return 0;   

}




Point PolyGravity(Point *p, int n) {
    Point tmp, g = Point(0, 0);
    double sumArea = 0, area;
    for (int i=2; i<n; ++i) {
        area = Cross(p[i-1]-p[0], p[i]-p[0]);
        sumArea += area;
        tmp.x = p[0].x + p[i-1].x + p[i].x;
        tmp.y = p[0].y + p[i-1].y + p[i].y;
        g.x += tmp.x * area;
        g.y += tmp.y * area;
    }
    g.x /= (sumArea * 3.0); g.y /= (sumArea * 3.0);
    return g;
}




Point bcenter(vector<Point> pnt)
{
    int n = pnt.size();
    Point p, s;
    double tp, area = 0, tpx = 0, tpy = 0;
    p.x = pnt[0].x;
    p.y = pnt[0].y;
    FE(i, 1, n)
    {
        s.x = pnt[(i == n) ? 0 : i].x;
        s.y = pnt[(i == n) ? 0 : i].y;
        tp = (p.x * s.y - s.x * p.y);
        area += tp / 2;
        tpx += (p.x + s.x) * tp;
        tpy += (p.y + s.y) * tp;
        p.x = s.x;
        p.y = s.y;
    }
    s.x = tpx / (6 * area);
    s.y = tpy / (6 * area);
    return s;
}







vector<Point> ConvexHull(vector<Point>& p)
{
    

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());


    int n = p.size();
    int m = 0;
    vector<Point> ch(n+1);
    for(int i = 0; i < n; i++)
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--)
    {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    ch.resize(m);
    return ch;
}


inline double Dist2(Point a, Point b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}




double diameter2(vector<Point>& points)
{
    vector<Point> p = ConvexHull(points);
    int n = p.size();
    if(n == 1) return 0;
    if(n == 2) return Dist2(p[0], p[1]);
    p.push_back(p[0]); 

    double ans = 0;
    for(int u = 0, v = 1; u < n; u++)
    {
        

        for(;;)
        {
            

            

            

            

            int diff = Cross(p[u+1]-p[u], p[v+1]-p[v]);
            if(diff <= 0)
            {
                ans = max(ans, Dist2(p[u], p[v])); 

                if(diff == 0)
                    ans = max(ans, Dist2(p[u], p[v+1])); 

                break;
            }
            v = (v + 1) % n;
        }
    }
    return ans;
}



double RC_Distance(Point *ch1, Point *ch2, int n, int m)
{
    int q=0, p=0;
    REP(i, n) if(ch1[i].y-ch1[p].y < -eps) p=i;
    REP(i, m) if(ch2[i].y-ch2[q].y > eps) q=i;
    ch1[n]=ch1[0];
    ch2[m]=ch2[0];


    double tmp, ans=1e100;
    REP(i, n)
    {
        while((tmp = Cross(ch1[p+1]-ch1[p], ch2[q+1]-ch1[p]) - Cross(ch1[p+1]-ch1[p], ch2[q]- ch1[p])) > eps)
            q=(q+1)%m;
        if(tmp < -eps) ans = min(ans,DistanceToSegment(ch2[q],ch1[p],ch1[p+1]));
        else ans = min(ans,dis_pair_seg(ch1[p],ch1[p+1],ch2[q],ch2[q+1]));
        p=(p+1)%n;
    }
    return ans;
}





double RC_Distance(vector<Point> ch1, vector<Point> ch2)
{
    int q = 0, p = 0, n = ch1.size(), m = ch2.size();
    REP(i, n) if(ch1[i].y-ch1[p].y < -eps) p=i;
    REP(i, m) if(ch2[i].y-ch2[q].y > eps) q=i;
    ch1.push_back(ch1[0]), ch2.push_back(ch2[0]);


    double tmp, ans=1e100;
    REP(i, n)
    {
        while((tmp = Cross(ch1[p+1]-ch1[p], ch2[q+1]-ch1[p]) - Cross(ch1[p+1]-ch1[p], ch2[q]- ch1[p])) > eps)
            q=(q+1)%m;
        if(tmp < -eps) ans = min(ans,DistanceToSegment(ch2[q],ch1[p],ch1[p+1]));
        else ans = min(ans,dis_pair_seg(ch1[p],ch1[p+1],ch2[q],ch2[q+1]));
        p=(p+1)%n;
    }
    return ans;
}



double RC_Triangle(Point* res,int n)
{
    if(n < 3)    return 0;
    double ans = 0, tmp;
    res[n] = res[0];
    int j, k;
    REP(i, n)
    {
        j = (i+1)%n;
        k = (j+1)%n;
        while((j != k) && (k != i))
        {
            while(Cross(res[j] - res[i], res[k+1] - res[i]) > Cross(res[j] - res[i], res[k] - res[i])) k= (k+1)%n;
            tmp = Cross(res[j] - res[i], res[k] - res[i]);
            if(tmp > ans) ans = tmp;
            j = (j+1)%n;
        }
    }
    return ans;
}



double RC_Triangle(vector<Point> res, Point& a, Point& b, Point& c)
{
    int n = res.size();
    if(n < 3)    return 0;
    double ans=0, tmp;
    res.push_back(res[0]);
    int j, k;
    REP(i, n)
    {
        j = (i+1)%n;
        k = (j+1)%n;
        while((j != k) && (k != i))
        {
            while(Cross(res[j] - res[i], res[k+1] - res[i]) > Cross(res[j] - res[i], res[k] - res[i])) k= (k+1)%n;
            tmp = Cross(res[j] - res[i], res[k] - res[i]);
            if(tmp > ans)
            {
                a = res[i], b = res[j], c = res[k];
                ans = tmp;
            }
            j = (j+1)%n;
        }
    }
    return ans;
}




bool ConvexPolygonDisjoint(const vector<Point> ch1, const vector<Point> ch2)
{
    int c1 = ch1.size();
    int c2 = ch2.size();
    for(int i = 0; i < c1; i++)
        if(isPointInPolygon(ch1[i], ch2) != 0)
            return false; 

    for(int i = 0; i < c2; i++)
        if(isPointInPolygon(ch2[i], ch1) != 0)
            return false; 

    for(int i = 0; i < c1; i++)
        for(int j = 0; j < c2; j++)
            if(SegmentProperIntersection(ch1[i], ch1[(i+1)%c1], ch2[j], ch2[(j+1)%c2]))
                return false;
    return true;
}

inline double dist(Point a, Point b)
{
    return Length(a - b);
}



double fermat_point(Point *pt, int n, Point& ptres)
{
    Point u, v;
    double step = 0.0, curlen, explen, minlen;
    int i, j, k;
    bool flag;
    u.x = u.y = v.x = v.y = 0.0;
    REP(i, n)
    {
        step += fabs(pt[i].x) + fabs(pt[i].y);
        u.x += pt[i].x;
        u.y += pt[i].y;
    }
    u.x /= n;
    u.y /= n;
    flag = 0;
    while(step > eps)
    {
        for(k = 0; k < 10; step /= 2, ++k)
            for(i = -1; i <= 1; ++i)
                for(j = -1; j <= 1; ++j)
                {
                    v.x = u.x + step*i;
                    v.y = u.y + step*j;
                    curlen = explen = 0.0;
                    REP(idx, n)
                    {
                        curlen += dist(u, pt[idx]);
                        explen += dist(v, pt[idx]);
                    }
                    if(curlen > explen)
                    {
                        u = v;
                        minlen = explen;
                        flag = 1;
                    }
                }
    }
    ptres = u;
    return flag ? minlen : curlen;
}





Point Fermat(int np, Point* p)
{
    double nowx = 0, nowy = 0;
    double nextx = 0, nexty = 0;
    REP(i, np)
    {
        nowx += p[i].x;
        nowy += p[i].y;
    }
    for (nowx /= np, nowy /= np;; nowx = nextx, nowy = nexty)
    {
        double topx = 0, topy = 0, bot = 0;
        REP(i, np)
        {
            double d = sqrt(sqr(nowx - p[i].x) + sqr(nowy - p[i].y));
            topx += p[i].x / d;
            topy += p[i].y / d;
            bot += 1 / d;
        }
        nextx = topx / bot;
        nexty = topy / bot;
        if (dcmp(nextx - nowx) == 0 && dcmp(nexty - nowy) == 0)
            break;
    }
    Point fp;
    fp.x = nowx;
    fp.y = nowy;
    return fp;
}






Point point[MAXN];
int tmpt[MAXN];
inline double dist(int x, int y)
{
    Point& a = point[x];
    Point& b = point[y];
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
inline bool cmpxy(Point a, Point b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
inline bool cmpy(int a, int b)
{
    return point[a].y < point[b].y;
}
double Closest_Pair(int left, int right)
{
    double d = INF;
    if(left==right)
        return d;
    if(left + 1 == right)
        return dist(left, right);
    int mid = (left+right)>>1;
    double d1 = Closest_Pair(left,mid);
    double d2 = Closest_Pair(mid+1,right);
    d = min(d1,d2);
    int k=0;
    

    FE(i, left, right)
    {
        if(fabs(point[mid].x-point[i].x) <= d)
            tmpt[k++] = i;
    }
    sort(tmpt,tmpt+k,cmpy);
    

    REP(i, k)
    {
        for(int j = i+1; j < k && point[tmpt[j]].y-point[tmpt[i]].y<d; j++)
        {
            double d3 = dist(tmpt[i],tmpt[j]);
            if(d > d3)
                d = d3;
        }
    }
    return d;
}



struct Circle
{
    Point c;
    double r;
    Circle() {}
    Circle(Point c, double r):c(c), r(r) {}
    inline Point point(double a) 

    {
        return Point(c.x+cos(a)*r, c.y+sin(a)*r);
    }
    inline void read()
    {
        scanf("%lf%lf%lf", &c.x, &c.y, &r);
    }
};



double DisOnCircle(Point a, Point b, Circle C)
{
    double ang1 = angle(a - C.c);
    double ang2 = angle(b - C.c);
    if (ang2 < ang1) ang2 += 2 * PI;
    return C.r * (ang2 - ang1);
}



int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol)
{
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
    double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d - C.r*C.r;
    double delta = f*f - 4*e*g; 

    if(dcmp(delta) < 0) return 0; 

    if(dcmp(delta) == 0)
    {
        

        t1 = t2 = -f / (2 * e);
        sol.push_back(L.point(t1));
        return 1;
    }
    

    t1 = (-f - sqrt(delta)) / (2 * e);
    sol.push_back(L.point(t1));
    t2 = (-f + sqrt(delta)) / (2 * e);
    sol.push_back(L.point(t2));
    return 2;
}



int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol)
{
    double d = Length(C1.c - C2.c);
    if(dcmp(d) == 0)
    {
        if(dcmp(C1.r - C2.r) == 0) return -1; 

        return 0;
    }
    if(dcmp(C1.r + C2.r - d) < 0) return 0;
    if(dcmp(fabs(C1.r-C2.r) - d) > 0) return 0;


    double a = angle(C2.c - C1.c);
    double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
    Point p1 = C1.point(a-da), p2 = C1.point(a+da);


    sol.push_back(p1);
    if(p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}



int getTangents(Point p, Circle C, Vector* v)
{
    Vector u = C.c - p;
    double dist = Length(u);
    if(dist < C.r) return 0;
    else if(dcmp(dist - C.r) == 0)   

    {
        v[0] = Rotate(u, PI/2);
        return 1;
    }
    else
    {
        double ang = asin(C.r / dist);
        v[0] = Rotate(u, -ang);
        v[1] = Rotate(u, +ang);
        return 2;
    }
}








int getTangents(Circle A, Circle B, Point* a, Point* b)
{
    int cnt = 0;
    if (A.r < B.r) swap(A, B), swap(a, b);
    

    int d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y - B.c.y);
    int rdiff = A.r - B.r;
    int rsum = A.r + B.r;
    if (d2 < rdiff * rdiff) return 0;   


    

    double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
    if (d2 == 0 && A.r == B.r) return -1;    

    if (d2 == rdiff * rdiff)    

    {
        

        a[cnt] = A.point(base); b[cnt] = B.point(base); cnt++;
        return 1;
    }
    

    double ang = acos((A.r - B.r) / sqrt(d2 * 1.0));
    a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
    a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
    if (d2 == rsum * rsum)  

    {
        a[cnt] = A.point(base); b[cnt] = B.point(PI + base); cnt++;
    }
    else if (d2 > rsum * rsum)  

    {
        double ang = acos((A.r + B.r) / sqrt(d2 * 1.0));
        a[cnt] = A.point(base + ang); b[cnt] = B.point(PI + base + ang); cnt++;
        a[cnt] = A.point(base - ang); b[cnt] = B.point(PI + base - ang); cnt++;
    }
    return cnt;
}




int getTangentPoints(Point p, Circle C, vector<Point>& v)
{
    Vector u = C.c - p;
    double dist = Length(u);
    if(dist < C.r) return 0;
    else if(dcmp(dist - C.r) == 0)   

    {
        v.push_back(p);
        return 1;
    }
    else
    {
        double ang = asin(C.r / dist);
        double d = sqrt(dist * dist - C.r * C.r);
        v.push_back(p + Unit(Rotate(u, -ang)) * d);
        v.push_back(p + Unit(Rotate(u, +ang)) * d);
        return 2;
    }
}



void getTangentPoints(Circle A, Circle B, vector<Point>& a)
{
    if (A.r < B.r) swap(A, B);
    

    int d2 = sqr(A.c.x - B.c.x) + sqr(A.c.y - B.c.y);
    int rdiff = A.r - B.r, rsum = A.r + B.r;
    if (d2 < rdiff * rdiff) return;   


    

    double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
    if (d2 == 0 && A.r == B.r) return;    

    if (d2 == rdiff * rdiff)    

    {
        

        a.push_back(A.point(base));
        a.push_back(B.point(base));
        return;
    }
    

    double ang = acos((A.r - B.r) / sqrt(d2 * 1.0));
    a.push_back(A.point(base + ang)); a.push_back(B.point(base + ang));
    a.push_back(A.point(base - ang)); a.push_back(B.point(base - ang));
    if (d2 == rsum * rsum)  

    {
        a.push_back(A.point(base));
        a.push_back(B.point(PI + base));
    }
    else if (d2 > rsum * rsum)  

    {
        double ang = acos((A.r + B.r) / sqrt(d2 * 1.0));
        a.push_back(A.point(base + ang));
        a.push_back(B.point(PI + base + ang));
        a.push_back(A.point(base - ang));
        a.push_back(B.point(PI + base - ang));
    }
}




Circle CircumscribedCircle(Point p1, Point p2, Point p3)
{
    double Bx = p2.x-p1.x, By = p2.y-p1.y;
    double Cx = p3.x-p1.x, Cy = p3.y-p1.y;
    double D = 2*(Bx*Cy-By*Cx);
    double cx = (Cy*(Bx*Bx+By*By) - By*(Cx*Cx+Cy*Cy))/D + p1.x;
    double cy = (Bx*(Cx*Cx+Cy*Cy) - Cx*(Bx*Bx+By*By))/D + p1.y;
    Point p = Point(cx, cy);
    return Circle(p, Length(p1-p));
}




Circle InscribedCircle(Point p1, Point p2, Point p3)
{
    double a = Length(p2-p3);
    double b = Length(p3-p1);
    double c = Length(p1-p2);
    Point p = (p1*a+p2*b+p3*c)/(a+b+c);
    return Circle(p, DistanceToLine(p, p1, p2));
}




vector<Point> CircleThroughPointTangentToLineGivenRadius(Point p, Line L, double r)
{
    vector<Point> ans;
    double t1, t2;
    getLineCircleIntersection(L.move(-r), Circle(p, r), t1, t2, ans);
    getLineCircleIntersection(L.move(r), Circle(p, r), t1, t2, ans);
    return ans;
}




vector<Point> CircleTangentToLinesGivenRadius(Line a, Line b, double r)
{
    vector<Point> ans;
    Line L1 = a.move(-r), L2 = a.move(r);
    Line L3 = b.move(-r), L4 = b.move(r);
    ans.push_back(GetLineIntersection(L1, L3));
    ans.push_back(GetLineIntersection(L1, L4));
    ans.push_back(GetLineIntersection(L2, L3));
    ans.push_back(GetLineIntersection(L2, L4));
    return ans;
}




vector<Point> CircleTangentToTwoDisjointCirclesWithRadius(Circle c1, Circle c2, double r)
{
    vector<Point> ans;
    Vector v = c2.c - c1.c;
    double dist = Length(v);
    int d = dcmp(dist - c1.r -c2.r - r*2);
    if(d > 0) return ans;
    getCircleCircleIntersection(Circle(c1.c, c1.r+r), Circle(c2.c, c2.r+r), ans);
    return ans;
}




Point GetIntersection(Line a, Line b) 

{
    Vector u = a.p-b.p;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.p + a.v*t;
}


inline bool InCircle(Point x, Circle c)
{
    return dcmp(c.r - Length(c.c - x)) >= 0;
}

inline bool OnCircle(Point x, Circle c)
{
    return dcmp(c.r - Length(c.c - x)) == 0;
}



int getSegCircleIntersection(Line L, Circle C, Point* sol)
{
    Vector nor = Normal(L.v);
    Line pl = Line(C.c, nor);
    Point ip = GetIntersection(pl, L);
    double dis = Length(ip - C.c);
    if (dcmp(dis - C.r) > 0) return 0;
    Point dxy = Unit(L.v) * sqrt(sqr(C.r) - sqr(dis));
    int ret = 0;
    sol[ret] = ip + dxy;
    if (OnSegment(sol[ret], L.p, L.point(1))) ret++;
    sol[ret] = ip - dxy;
    if (OnSegment(sol[ret], L.p, L.point(1))) ret++;
    return ret;
}



double SegCircleArea(Circle C, Point a, Point b)
{
    double a1 = angle(a - C.c);
    double a2 = angle(b - C.c);
    double da = fabs(a1 - a2);
    if (da > PI) da = PI * 2.0 - da;
    return dcmp(Cross(b - C.c, a - C.c)) * da * sqr(C.r) / 2.0;
}



double PolyCiclrArea(Circle C, Point *p, int n)
{
    double ret = 0.0;
    Point sol[2];
    p[n] = p[0];
    REP(i, n)
    {
        

        int cnt = getSegCircleIntersection(Line(p[i], p[i+1]-p[i]), C, sol);
        if (cnt == 0)
        {
            if (!InCircle(p[i], C) || !InCircle(p[i+1], C)) ret += SegCircleArea(C, p[i], p[i+1]);
            else ret += Cross(p[i+1] - C.c, p[i] - C.c) / 2.0;
        }
        if (cnt == 1)
        {
            if (InCircle(p[i], C) && !InCircle(p[i+1], C)) ret += Cross(sol[0] - C.c, p[i] - C.c) / 2.0, ret += SegCircleArea(C, sol[0], p[i+1]);
            else ret += SegCircleArea(C, p[i], sol[0]), ret += Cross(p[i+1] - C.c, sol[0] - C.c) / 2.0;
        }
        if (cnt == 2)
        {
            if ((p[i] < p[i + 1]) ^ (sol[0] < sol[1])) swap(sol[0], sol[1]);
            ret += SegCircleArea(C, p[i], sol[0]);
            ret += Cross(sol[1] - C.c, sol[0] - C.c) / 2.0;
            ret += SegCircleArea(C, sol[1], p[i+1]);
        }
    }
    return fabs(ret);
}

int n;
int x[3005],y[3005];
int ok(int i,int j,int k)
{
	if (x[i]==x[k] && y[i]==y[k]) return 0;
	if (x[j]==x[k] && y[j]==y[k]) return 0;
	return 1;	
}

int main()
{
    while (cin>>n)
	{
		double ans=9999999999;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
			x[i+n]=x[i+n+n]=x[i];
			y[i+n]=y[i+n+n]=y[i];
		}
		for (int i=n+1;i<=n+n;i++)
		for (int j=n+1;j<=n+n;j++)
		if (i!=j && i!=j+1 && i!=j-1)
		{
			double dis;
			Point d1,d2,d3;
			d1.x=x[i]; d1.y=y[i];
			d2.x=x[j]; d2.y=y[j];
			
			d3.x=x[i-1]; d3.y=y[i-1];
			dis=DistanceToLine(d3,d1,d2);
			if (ok(i,j,i-1))
			ans=min(ans,dis/2);


			
			d3.x=x[j-1]; d3.y=y[j-1];
			dis=DistanceToLine(d3,d1,d2);
			if (ok(i,j,j-1))
			ans=min(ans,dis/2);


			
			d3.x=x[i+1]; d3.y=y[i+1];
			dis=DistanceToLine(d3,d1,d2);
			if (ok(i,j,i+1))
			ans=min(ans,dis/2);


			
			d3.x=x[j+1]; d3.y=y[j+1];
			dis=DistanceToLine(d3,d1,d2);
			if (ok(i,j,j+1))
			ans=min(ans,dis/2);


		}
		printf("%.10lf\n",ans);
	}
    return 0;
}
