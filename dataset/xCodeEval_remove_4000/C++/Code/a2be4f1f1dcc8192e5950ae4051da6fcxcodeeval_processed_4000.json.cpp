











using namespace std;

typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;











const  double eps = 1e-20;
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
    Point() {}
    Point ( double _x,  double _y)
    {
        x = _x, y = _y;
    }
    void input()
    {
        scanf("%Lf%Lf", &x, &y);
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
    int linecrossseg(Line v)
    {
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        if((d1^d2)==-2) return 2;
        return (d1==0||d2==0);
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

struct polygon
{
    int n;
    Point p[maxp];
    Line l[maxp];
    void input(int _n)
    {
        n=_n;
        for(int i=0;i<n;i++) p[i].input();
    }
    void add(Point q)
    {
        p[n++]=q;
    }
    void getline()
    {
        for(int i=0;i<n;i++)
        {
            l[i]=Line(p[i],p[(i+1)%n]);
        }
    }
    void norm()
    {
        Point mi=p[0];
        for(int i=1;i<n;i++) mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    struct cmp
    {
        Point p;
        cmp(const Point &p0){p=p0;}
        bool operator()(const Point &aa,const Point &bb)
        {
            Point a=aa,b=bb;
            int d=sgn((a-p)^(b-p));
            if(d==0) return sgn(a.distance(p)-b.distance(p))<0;
            return d>0;
        }
    };

    void Graham(polygon &convex)

    {
        norm();
        int &top=convex.n;
        top=0;
        if(n==1)
        {
            top=1;
            convex.p[0]=p[0];
            return ;
        }
        if(n==2)
        {
            top=2;
            convex.p[0]=p[0];
            convex.p[1]=p[1];
            if(convex.p[0]==convex.p[1]) top--;
            return ;
        }
        convex.p[0]=p[0];
        convex.p[1]=p[1];
        top=2;
        for(int i=2;i<n;i++)
        {
            while(top>1&&sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2]))<=0) top--;
            convex.p[top++]=p[i];
        }
        if(convex.n==2&&(convex.p[0]==convex.p[1])) convex.n--;
    }
    

    void getconvex(polygon &convex)
    {
       

        sort(p,p+n);
        convex.n=n;
        for(int i=0;i<min(n,2);i++) convex.p[i]=p[i];
        if(convex.n==2&&(convex.p[0] == convex.p[1])) convex.n--;
        if(n<=2) return ;
        int &top=convex.n;
        top=1;
        for(int i=2;i<n;i++)
        {
            while(top&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<0) top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for(int i=n-3;i>=0;i--)
        {
            while(top!=temp&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<0) top--;
            convex.p[++top]=p[i];
        }
        if(convex.n==2&&(convex.p[0]==convex.p[1])) convex.n--;
    }
    

    

    

    

    int polygoncrossline(Line v)
    {
        getline();
        for(int i=0;i<n;i++)
        {
            if(v.linecrossseg(l[i])==1) return 1;
            if(v.linecrossseg(l[i])==2) return 2;
        }
        return 0;
    }
    

    double getarea()

    {
        

        double sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(p[i]^p[(i+1)%n]);
        }
        return fabs(sum)/2.0;
    }
    

    

    

    

    int relationPoint(Point q)
    {
        for(int i=0;i<n;i++) if(p[i] == q) return 3;
        getline();
        for(int i=0;i<n;i++) if(l[i].pointonseg(q)) return 2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            int k=sgn((q-p[j])^p[i]-p[j]);
            int u=sgn(p[i].y-q.y);
            int v=sgn(p[j].y-q.y);
            if(k>0&&u<0&&v>=0) cnt++;
            if(k<0&&v<0&&u>=0) cnt--;
        }
        return cnt!=0;
    }
}vex;
int main()
{
    

    

    

    int n;
    double w,v,u;
    scanf("%d%Lf%Lf%Lf",&n,&w,&v,&u);
    vex.input(n);
    vex.norm();
   

    Point O(0,0);
    Point e = O +Point(w*v/u,w);
    Line l(O,e);
    int tmp=vex.polygoncrossline(l);
   

    if(tmp!=2) return 0*printf("%.15Lf\n",w/u);
    int pos;
    for(int i=0;i<vex.n;i++)
    {
        if(sgn(vex.p[i].x-O.x)>0)
        {
            pos=i;
            break;
        }
    }
   

 

    double ans=0;
    while(pos<vex.n)
    {
        while(pos<vex.n&&vex.p[pos].x<O.x) pos++;
        if(pos==n)
        {
            ans=ans+(w-O.y)/u;
            break;
        }
        double tt = (vex.p[pos].y-O.y)*v-(vex.p[pos].x-O.x)*u;
        if(sgn(tt)<=0)
        {
            ans = ans + (vex.p[pos].x-O.x)/v;
            O=vex.p[pos];
            pos++;
        }
        else
        {
            double t=(vex.p[pos].y-O.y)/u;
            Point tmp = Point(O.x+t*v,vex.p[pos].y);
            ans = ans + t;
            O = tmp;
            pos++;
        }
    }
    printf("%.15Lf\n",ans);
    

    return 0;
}

