
















using namespace std;




























































typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int MOD = 100000007;
const int MAXN = 10010;





























































































































































































































































































































































































































































































































































































































































const double PI = acos(-1.0);






































double torad(double deg) { return deg / 180 * PI; }
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





Point id4(Point p, Vector v, Point q, Vector w)
{
    Vector u = p-q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v*t;
}




inline Point id9(Point P, Point A, Point B)
{
    Vector v = B-A;
    return A+v*(Dot(v, P-A) / Dot(v, v));
}




inline double id15(Point P, Point A, Point B)
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1); 

}


inline bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) <= 0;
}




inline void id10(Point p1, Point p2, double& a, double& b, double &c)
{
    a = p2.y-p1.y;
    b = p1.x-p2.x;
    c = -a*p1.x - b*p1.y;
}


double id6(Point p, Point a, Point b)
{
    if(a == b) return Length(p-a);
    Vector v1 = b-a, v2 = p-a, v3 = p-b;
    if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}


inline double id17(Point p1, Point p2, Point p3, Point p4)
{
    return min(min(id6(p1, p3, p4), id6(p2, p3, p4)),
               min(id6(p3, p1, p2), id6(p4, p1, p2)));
}


inline bool id26(Point a1, Point a2, Point b1, Point b2)
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


inline Point id4(Line a, Line b)
{
    return id4(a.p, a.v, b.p, b.v);
}




inline bool OnLeft(const Line& L, const Point& p)
{
    return Cross(L.v, p-L.p) > 0;
}


















vector<Point> id14(vector<Line> L)
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
        if(first < last) p[last-1] = id4(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1])) last--; 

    if(last - first <= 1) return ans; 

    p[last] = id4(q[last], q[first]); 



    

    for(int i = first; i <= last; i++) ans.push_back(p[i]);
    return ans;
}



int id23(Point p, Polygon poly)
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


double PolygonArea(vector<Point> p)
{
    int n = p.size();
    double area = 0;
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i]-p[0], p[i+1]-p[0]);
    return area/2;
}






vector<Point> id24(vector<Point>& p)
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




double id21(vector<Point>& points)
{
    vector<Point> p = id24(points);
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


double id3(Point *ch1, Point *ch2, int n, int m)
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
        if(tmp < -eps) ans = min(ans,id6(ch2[q],ch1[p],ch1[p+1]));
        else ans = min(ans,id17(ch1[p],ch1[p+1],ch2[q],ch2[q+1]));
        p=(p+1)%n;
    }
    return ans;
}


double id16(Point* res,int n)

{
    if(n<3)    return 0;
    double ans=0, tmp;
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
inline double dist(Point a, Point b)
{
    return Length(a - b);
}


double id18(Point *pt, int n, Point& ptres)
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


Point point[100];
int tmpt[100];
inline bool cmpxy(const Point& a, const Point& b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
inline bool cmpy(const int& a, const int& b)
{
    return point[a].y < point[b].y;
}
double id2(int left, int right)
{
    double d = INF;
    if(left==right)
        return d;
    if(left + 1 == right)
        return dist(left, right);
    int mid = (left+right)>>1;
    double d1 = id2(left,mid);
    double d2 = id2(mid+1,right);
    d = min(d1,d2);
    int i,j,k=0;
    

    for(i = left; i <= right; i++)
    {
        if(fabs(point[mid].x-point[i].x) <= d)
            tmpt[k++] = i;
    }
    sort(tmpt,tmpt+k,cmpy);
    

    for(i = 0; i < k; i++)
    {
        for(j = i+1; j < k && point[tmpt[j]].y-point[tmpt[i]].y<d; j++)
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


int id19(Line L, Circle C, double& t1, double& t2, vector<Point>& sol)
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


int id8(Circle C1, Circle C2, vector<Point>& sol)
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




Circle id0(Point p1, Point p2, Point p3)
{
    double Bx = p2.x-p1.x, By = p2.y-p1.y;
    double Cx = p3.x-p1.x, Cy = p3.y-p1.y;
    double D = 2*(Bx*Cy-By*Cx);
    double cx = (Cy*(Bx*Bx+By*By) - By*(Cx*Cx+Cy*Cy))/D + p1.x;
    double cy = (Bx*(Cx*Cx+Cy*Cy) - Cx*(Bx*Bx+By*By))/D + p1.y;
    Point p = Point(cx, cy);
    return Circle(p, Length(p1-p));
}




Circle id12(Point p1, Point p2, Point p3)
{
    double a = Length(p2-p3);
    double b = Length(p3-p1);
    double c = Length(p1-p2);
    Point p = (p1*a+p2*b+p3*c)/(a+b+c);
    return Circle(p, id15(p, p1, p2));
}




int id1(Point p, Circle C, Vector* v)
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




vector<Point> id20(Point p, Line L, double r)
{
    vector<Point> ans;
    double t1, t2;
    id19(L.move(-r), Circle(p, r), t1, t2, ans);
    id19(L.move(r), Circle(p, r), t1, t2, ans);
    return ans;
}




vector<Point> id7(Line a, Line b, double r)
{
    vector<Point> ans;
    Line L1 = a.move(-r), L2 = a.move(r);
    Line L3 = b.move(-r), L4 = b.move(r);
    ans.push_back(id4(L1, L3));
    ans.push_back(id4(L1, L4));
    ans.push_back(id4(L2, L3));
    ans.push_back(id4(L2, L4));
    return ans;
}




vector<Point> id13(Circle c1, Circle c2, double r)
{
    vector<Point> ans;
    Vector v = c2.c - c1.c;
    double dist = Length(v);
    int d = dcmp(dist - c1.r -c2.r - r*2);
    if(d > 0) return ans;
    id8(Circle(c1.c, c1.r+r), Circle(c2.c, c2.r+r), ans);
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
    return dcmp(sqr(c.r) - sqr(Length(c.c - x))) >= 0;
}
inline bool OnCircle(Point x, Circle c)
{
    return dcmp(sqr(c.r) - sqr(Length(c.c - x))) == 0;
}


int id22(Line L, Circle C, Point* sol)
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
double id27(Circle C, Point a, Point b) 

{
    double a1 = angle(a - C.c);
    double a2 = angle(b - C.c);
    double da = fabs(a1 - a2);
    if (da > PI) da = PI * 2.0 - da;
    return dcmp(Cross(b - C.c, a - C.c)) * da * sqr(C.r) / 2.0;
}


double id5(Circle C, Point *p, int n)

{
    double ret = 0.0;
    Point sol[2];
    p[n] = p[0];
    REP(i, n)
    {
        

        int cnt = id22(Line(p[i], p[i+1]-p[i]), C, sol);
        if (cnt == 0)
        {
            if (!InCircle(p[i], C) || !InCircle(p[i+1], C)) ret += id27(C, p[i], p[i+1]);
            else ret += Cross(p[i+1] - C.c, p[i] - C.c) / 2.0;
        }
        if (cnt == 1)
        {
            if (InCircle(p[i], C) && !InCircle(p[i+1], C)) ret += Cross(sol[0] - C.c, p[i] - C.c) / 2.0, ret += id27(C, sol[0], p[i+1]);
            else ret += id27(C, p[i], sol[0]), ret += Cross(p[i+1] - C.c, sol[0] - C.c) / 2.0;
        }
        if (cnt == 2)
        {
            if ((p[i] < p[i + 1]) ^ (sol[0] < sol[1])) swap(sol[0], sol[1]);
            ret += id27(C, p[i], sol[0]);
            ret += Cross(sol[1] - C.c, sol[0] - C.c) / 2.0;
            ret += id27(C, sol[1], p[i+1]);
        }
    }
    return fabs(ret);
}
inline double PointDis(Point a, Point b)
{
    return Length(a - b);
}
double id25( Point a, Point b, Circle c )  

{
    Point o = c.c;
    double A = sqrt( PointDis( o, a ) );
    double B = sqrt( PointDis( o, b ) );
    double C = sqrt( PointDis( a, b ) );
    double alpha = acos( ( A*A + B*B - C*C ) / ( 2.0*A*B ) );
    if ( dcmp( Cross( o-a, o-b ) ) < 0 ) return alpha * c.r;
    else return ( 2.0*PI - alpha ) * c.r;
}

Circle C[100];

double D(Point a,Point b,int id)  

{
    double ang1,ang2;
    Vector v1,v2;
    v1=a-Point(C[id].c.x, C[id].c.y);
    v2=b-Point(C[id].c.x, C[id].c.y);
    ang1=atan2(v1.y,v1.x);
    ang2=atan2(v2.y,v2.x);
    if(ang2<ang1) ang2+=2*PI;
    return C[id].r*(ang2-ang1);
}

bool id11(const vector<Point> ch1, const vector<Point> ch2) {
    int c1 = ch1.size();
    int c2 = ch2.size();
    for(int i = 0; i < c1; i++)
        if(id23(ch1[i], ch2) != 0)
            return false; 

    for(int i = 0; i < c2; i++)
        if(id23(ch2[i], ch1) != 0)
            return false; 

    for(int i = 0; i < c1; i++)
        for(int j = 0; j < c2; j++)
            if(id26(ch1[i], ch1[(i+1)%c1], ch2[j], ch2[(j+1)%c2]))
                return false;
    return true;
}





















const int N = 600010;

int n, m;
int s[N], ans[N];

inline int lowbit(int x) { return x & -x; }

void modify(int x, int v) {
  while (x <= n) {
    s[x] += v;
    x += lowbit(x);
  }
}

int findsum(int x) {
  int v = 0;
  while (x > 0) {
    v += s[x];
    x -= lowbit(x);
  }
  return v;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) s[i] = 0;
  for (int i = 1; i <= n; i++) modify(i, 1);
  for (int i = 1; i <= n; i++) ans[i] = 0;
  while (m--) {
    int from, to, win;
    scanf("%d %d %d", &from, &to, &win);
    int dec = findsum(from - 1);
    int add = findsum(to);
    while (add > dec) {
      int ll = from, rr = to;
      while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (findsum(mid) == dec) ll = mid + 1;
        else rr = mid;
      }
      ans[ll] = win;
      modify(ll, -1);
      add--;
    }
    ans[win] = 0;
    modify(win, 1);
  }
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}
