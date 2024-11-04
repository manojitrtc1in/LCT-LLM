#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<bitset>
#include<stack>
#include<set>
#include<vector>
#include <time.h>
#include<string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 4e3+5;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

const  double eps = 1e-12;
const  double inf = 1e20;
const  double pi = acos(-1.0);
const int maxp = 1e5+10;
int sgn( double x)
{
    if (fabs(x) <eps) return 0;
    if(x <0) return -1;
    return 1;
}
inline  double sqr( double x)
{
    return x * x;
}

struct Point
{
    double x, y;
    int id;
    Point() {}
    Point ( double _x,  double _y)
    {
        x = _x, y = _y;
    }
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    void output()
    {
        cout <<"x= "<<x << " y= " << y << endl;
    }
    bool operator == (Point b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator < (Point b) const
    {
        return sgn(y - b.y) == 0 ? sgn(x - b.x) < 0 : y < b.y;
    }
    Point operator - (const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    

    double  operator ^ (const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    

    double  operator * (const Point & b) const
    {
        return x * b.x + y * b.y;
    }
    

    double  len()
    {
        return hypot(x, y);
    }
    

    double  len2()
    {
        return x * x + y * y;
    }
    

    double  distance(Point p)
    {
        return hypot(x - p.x, y - p.y);
    }
    

    Point operator + (const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }
    

    Point operator * (const double  &k) const
    {
        return Point(x * k, y * k);
    }
    

    Point operator / (const double  &k) const
    {
        return Point (x / k, y / k);
    }
    

    double  rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2( fabs((a - p) ^ (b - p)), (a - p) * (b - p) ));
    }
    

    Point trunc(double  r)
    {
        double  l = len();
        if (!sgn(l)) return *this;
        r /= l;
        return Point(x * r, y * r);
    }
    

    Point rotat(Point p,double angle)
    {
        Point v=(*this)-p;
        double c=cos(angle),s=sin(angle);
        return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};

struct Line
{
    Point s, e;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s, e = _e;
    }
    

    bool operator == (Line v)
    {
        return (s == v.s) && (e == v.e);
    }
    

    Line (Point p, double  angle)
    {
        s = p;
        if (sgn(angle - pi / 2) == 0)
            e = (s + Point (0, 1));
        else
            e = (s + Point (1, tan(angle)));
    }
    

    Line(double  a, double  b, double  c)
    {
        if (sgn(a) == 0)
        {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        }
        else if (sgn(b) == 0)
        {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        }
        else
        {
            s = Point(0, -c / b);
            e = Point(1, (-c-a) / b);
        }
    }
    

    Point getV()
    {
        return e-s;
    }
    void input()
    {
        s.input();
        e.input();
    }
    void adjust()
    {
        if (e < s) swap(s, e);
    }
    

    double  length()
    {
        return s.distance(e);
    }
    

    double  angle()
    {
        double  k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k -= pi;
        return k;
    }
    

    

    

    

    int relation(Point p)
    {
        int c = sgn( (p - s) ^ (e - s) );
        if (c < 0) return 1;
        else if (c > 0) return 2;
        return 3;
    }
    

    bool pointonseg(Point p)
    {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    

    bool parallel(Line v)
    {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    

    

    

    

    int segcrossseg(Line v)
    {
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        int d3 = sgn((v.e-v.s)^(s-v.s));
        int d4 = sgn((v.e-v.s)^(e-v.s));
        if((d1^d2)==-2&&(d3^d4)==-2) return 2;
        return ((d1==0&&sgn((v.s-s)*(v.s-e))<=0)||(d2==0&&sgn((v.e-s)*(v.e-e))<=0)||(d3==0&&sgn((s-v.s)*(s-v.e))<=0)||(d4==0&&sgn((e-v.s)*(e-v.e))<=0));
    }
    Point lineprog(Point p)
    {
        return s + ( ((e - s) * ((e - s) * (p - s))) / ((e - s).len2()) );
    }
    Point symmetrypoint(Point p)
    {
        Point q = lineprog(p);
        return Point(2.0 * q.x - p.x, 2.0 * q.y - p.y);
    }
    double  dispointtoline(Point p)
    {
        return fabs((p - s) ^ (e - s)) / length();
    }
    double  dispointtoseg(Point p)
    {
        if (sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }
    

    

    

    

    int linecrossline(Line v)
    {
        if((*this).parallel(v)) return v.relation(s)==3;
        return 2;
    }
    Point crosspoint(Line v)
    {
        double a1=(v.e-v.s)^(s-v.s);
        double a2=(v.e-v.s)^(e-v.s);
        return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
    }
};

struct circle
{
    Point p;
    double  r;
    circle() {}
    circle(Point _p, double  _r)
    {
        p = _p, r = _r;
    }
    circle (double  x, double  y, double  _r)
    {
        p = Point(x, y), r = _r;
    }
    void input()
    {
        scanf ("%lf", &r);
        p.input();
    }
    void output()
    {
        printf ("%.2Lf %.2Lf %.2Lf", p.x, p.y, r);
    }
    bool operator == (circle v)
    {
        return p == v.p && sgn(r - v.r) == 0;
    }
    bool operator < (circle v) const
    {
        return ((p < v.p) || ((p == v.p) && sgn(r - v.r) < 0));
    }
    double area()
    {
        return r*r*PI;
    }
    int relation(Point b)
    {
        double dst = b.distance(p);
        if(sgn(dst-r)<0) return 2;
        else if(sgn(dst-r)==0) return 1;
        return 0;
    }
    int relationseg(Line v)
    {
        double  dst = v.dispointtoseg(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        return 0;
    }
    int relationline(Line v)
    {
        double  dst = v.dispointtoline(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        return 0;
    }
    

    int pointcrossline(Line v, Point &p1, Point &p2)
    {
        if (!(*this).relationline(v)) return 0;
        Point a = v.lineprog(p);
        double  d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0)
        {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }
    

    

    

    

    

    

    int relationcircle(circle v)
    {
        double d = p.distance(v.p);
        if(sgn(d-r-v.r)>0) return 5;
        if(sgn(d-r-v.r)==0) return 4;
        double l = fabs(r-v.r);
        if(sgn(d-r-v.r)<0&&sgn(d-l)>0) return 3;
        if(sgn(d-l)==0) return 2;
        if(sgn(d-l)<0) return 1;
    }
    

    long double areacircle(circle v)
    {
        int rel = relationcircle(v);
        if(rel>=4) return 0.0;
        if(rel<=2) return min(area(),v.area());
        long double d = p.distance(v.p);
        long double alpha=acos((r*r+d*d-v.r*v.r)/2/r/d);
        long double beta=acos((v.r*v.r+d*d-r*r)/2/v.r/d);
        long double ans=(alpha*r*r-0.5*r*r*sin(alpha*2))+(beta*v.r*v.r-0.5*v.r*v.r*sin(beta*2));
        return ans;
    }
};
int n_m, cnt, range;
int head[maxn], depth[maxn], f[maxn][65];
ll dist[maxn];
Point p[maxn];
circle O[maxn];
int ou[maxn];
struct edge
{
    int v, nxt;
    ll length;
} Edge[2 * maxn];

void init()
{
    for(int i = 0; i <= n_m; i++) head[i] = -1;
    cnt = 0;
    range = (int)log(n_m) / log(2) + 1;
    memset(depth, 0, sizeof(depth));
    memset(f, 0, sizeof(f));
}

void addedge(int u, int v)
{
    Edge[cnt].v = v;
    Edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void bfs()
{
    queue <pii> que;
    depth[1] = 1;
    que.push(pii(1, -1));
    while(!que.empty())
    {
        pii u = que.front();
        que.pop();
        for(int i = head[u.first]; i != -1; i = Edge[i].nxt)
        {
            int v = Edge[i].v;
            if(depth[v])        continue;
            if(v == u.second)   continue;
            depth[v] = depth[u.first] + 1;
            f[v][0] = u.first;
            for(int j = 1; j <= range; j++) f[v][j] = f[f[v][j - 1]][j - 1];
            que.push(pii(v, u.first));
        }
    }
}

int lca(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    for(int i = range; i >= 0; i--)
        if(depth[f[a][i]] >= depth[b])    a = f[a][i];
    if(a == b)  return a;
    for(int i = range; i >= 0; i--)
    {
        if(f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}

int main()
{
    

    

    

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) p[i].input();
    for(int i=1;i<=m;i++) O[i].input();
    m++;
    O[m].p=Point(0,0);
    O[m].r=1e10;
    n_m=n+m;
    init();
    

    for(int i=1;i<=m-1;i++)
    {
        double minn=inf;
        int pos;
        for(int j=1;j<=m;j++)
        {
            if(i==j) continue;
            if(O[j].relationcircle(O[i])<2&&sgn(O[j].r-O[i].r)>0)
            {
                if(O[j].r<minn)
                {
                    minn=O[j].r;
                    pos=j;
                }
            }
        }
        addedge(pos,i);
        addedge(i,pos);
    }
     

    for(int i=1;i<=n;i++)
    {
        double minn=inf;
        int pos;
        for(int j=1;j<=m;j++)
        {
            if(O[j].relation(p[i])==2)
            {
                if(O[j].r<minn)
                {
                    minn=O[j].r;
                    pos=j;
                }
            }
        }
        addedge(pos,m+i);
        addedge(m+i,pos);
    }

    bfs();
    while(k--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int poa=m+a;
        int pob=m+b;
        int LCA=lca(poa,pob);
        int dis=depth[poa]+depth[pob]-2*depth[LCA];
        printf("%d\n",max(0,dis-2));
    }
    

    return 0;
}

