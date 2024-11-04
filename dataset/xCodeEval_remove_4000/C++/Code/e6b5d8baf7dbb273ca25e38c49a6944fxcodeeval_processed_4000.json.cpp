




























using namespace std;

const double eps = 1e-8;
const double inf = 10000;
const int maxP = 11111;


inline double xdet(double x1, double y1, double x2, double y2) {
        return x1 * y2 - x2 * y1;
}
inline double ddet(double x1, double y1, double x2, double y2) {
        return x1 * x2 + y1 * y2;
}
inline int dcmp(double d) {
        if ( fabs(d) < eps ) return 0;
        return d > eps ? 1 : -1;
}

struct Point {
        double x , y;
        Point() {
        }
        Point(double _x, double _y) :
        x(_x), y(_y) {
        }
        void input() {
                scanf("%lf%lf", &x, &y);
        }
        bool operator ==(Point a) {
                return ( dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0 );
        }
        bool operator<(Point a)const
    {
        return dcmp(a.x-x)==0?dcmp(y-a.y)<0:x<a.x;
    }
        double xmult(Point p) {
                return xdet(x, y, p.x, p.y);
        }
        double xmult(Point p1, Point p2) {
                return xdet(p1.x - x, p1.y - y, p2.x - x, p2.y - y);
        }
        double dmult(Point p) {
                return ddet(x, y, p.x, p.y);
        }
        double Distance(Point p) {
                return sqrt(( p.x - x ) * ( p.x - x ) + ( p.y - y ) * ( p.y - y ));
        }
        Point rotate(Point p, double angle) {
                Point vec(x - p.x, y - p.y);
                double Cos(cos(angle)) , Sin(sin(angle));
                Point ret;
                ret.x = p.x + vec.x * Cos - vec.y * Sin;
                ret.y = p.y + vec.x * Sin + vec.y * Cos;
                return ret;
        }
};

struct Line {
        Point a , b;
        Line() {
        }
        Line(Point _a, Point _b) :
        a(_a), b(_b) {
        }
        void input() {
                a.input(), b.input();
        }
        double xmult(Point p) {
                return xdet(b.x - a.x, b.y - a.y, p.x - a.x, p.y - a.y);
        }
        double dmult(Point p) {
                return ddet(p.x - a.x, p.y - a.y, p.x - b.x, p.y - b.y);
        }
        double Distance() {
                return a.Distance(b);
        }
        int SegCrossSeg(Line v) {
                Line &u = ( *this );
                int d1 = dcmp(u.xmult(v.a));
                int d2 = dcmp(u.xmult(v.b));
                int d3 = dcmp(v.xmult(a));
                int d4 = dcmp(v.xmult(b));
                if ( ( d1 ^ d2 ) == -2 && ( d3 ^ d4 ) == -2 ) return 2;
                return ( ( d1 == 0 && dcmp(u.dmult(v.a)) <= 0 ) || 
                        ( d2 == 0 && dcmp(u.dmult(v.b)) <= 0 ) || 
                        ( d3 == 0 && dcmp(v.dmult(a)) <= 0 ) || 
                        ( d4 == 0 && dcmp(v.dmult(b)) <= 0 ) );
        }
        int LineCrossSeg(Line v) {
                Line &u = ( *this );
                int d1 = dcmp(u.xmult(v.a));
                int d2 = dcmp(u.xmult(v.b));
                if ( ( d1 ^ d2 ) == -2 ) return 2;
                return ( d1 == 0 || d2 == 0 );
        }
        bool parallel(Line v) {
                return dcmp(xdet(b.x - a.x, b.y - a.y, v.b.x - v.a.x, v.b.y - v.a.y)) == 0;
        }
        int LineCrossLine(Line v) {
                if ( ( *this ).parallel(v) ) {
                        return ( dcmp(v.xmult(a)) == 0 );
                }
                return 2;
        }
        Point CrossPoint(Line v) {
                double a1 = v.xmult(a) , a2 = v.xmult(b);
                return Point((a.x * a2 - b.x * a1) / (a2 - a1) , (a.y * a2 - b.y * a1) / (a2 - a1));
        }
        double DisPointToSeg(Point p) {
                Point q(p.x + a.y - b.y, p.y + b.x - a.x);
                if ( dcmp(xmult(p) * xmult(q)) > 0 ) {
                        return min(p.Distance(a), q.Distance(b));
                }
                return fabs(xmult(p)) / a.Distance(b);
        }
        Point PointToSeg(Point p) {
                Point q(p.x + a.y - b.y, p.y + b.x - a.x);
                if ( dcmp(xmult(p) * xmult(q)) > 0 ) {
                        return p.Distance(a) < q.Distance(b) ? a : b;
                }
                return CrossPoint(Line(p, q));
        }
        double DisPointToLine(Point p) {
                return fabs(( *this ).xmult(p)) / a.Distance(b);
        }
        Point PointToLine(Point p) {
                Point q(p.x + a.y - b.y, p.y + b.x - a.x);
                return CrossPoint(Line(p, q));
        }
        void Translation(double d) {
                Point c((a.x + b.x)/2 , (a.y + b.y)/2);
                double mul = d / b.Distance(c);
                double deltaX = mul * (c.y - b.y) , deltaY = mul * (b.x - c.x);
                a.x += deltaX , a.y += deltaY;
                b.x += deltaX , b.y += deltaY;
        }
};

bool cmp(const Point &a, const Point &b) {
        return a.y < b.y || ( dcmp(a.y - b.y) == 0 && a.x < b.x );
}
struct Polygon {
        int n;
        Point p[maxP];
        Line l[maxP];
        void input() {
                for ( int i = 0 ; i < n ; i ++ )
                        p[i].input();
        }
        void getLine() {
                l[0] = Line(p[n - 1], p[0]);
                for ( int i = 1 ; i < n ; i ++ ) {
                        l[i] = Line(p[i - 1], p[i]);
                }
        }
        void getConvex(Polygon &convex) {
                sort(p, p + n, cmp);
                convex.n = n;
                if ( n == 0 ) return;
                convex.p[0] = p[0];
                if ( n == 1 ) return;
                convex.p[1] = p[1];
                if ( n == 2 ) return;
                int &top = convex.n;
                top = 1;
                for ( int i = 2 ; i < n ; i ++ ) {
                        while ( top && p[i].xmult(convex.p[top], convex.p[top - 1]) <= 0 )
                                top --;
                        convex.p[++ top] = p[i];
                }
                int temp = top;
                convex.p[++ top] = p[n - 2];
                for ( int i = n - 3 ; i >= 0 ; i -- ) {
                        while ( top != temp && p[i].xmult(convex.p[top], convex.p[top - 1]) <= 0 )
                                top --;
                        convex.p[++ top] = p[i];
                }
        }
        bool isConvex() {
                bool s[3] = { false , false , false };
                p[n] = p[0], p[n + 1] = p[1];
                for ( int i = 0 ; i < n ; i ++ ) {
                        s[dcmp(p[i].xmult(p[i + 1], p[i + 2])) + 1] = true;
                        if ( s[0] && s[2] ) return false;
                }
                return true;
        }
        

        

        

        

        int PointInsert(Point P) {

                for ( int i = 0 ; i < n ; i ++ ) {
                        if ( dcmp(l[i].xmult(P)) == 0 && dcmp(l[i].dmult(P)) <= 0 ) {
                                if ( l[i].a == P || l[i].b == P ) return 3;
                                return 2;
                        }
                }
                int cnt = 0;
                p[n] = p[0];
                for ( int i = 0 ; i < n ; i ++ ) {
                        int k = dcmp(p[i + 1].xmult(P, p[i]));
                        int u = dcmp(p[i].y - P.y);
                        int v = dcmp(p[i + 1].y - P.y);
                        if ( k > 0 && u < 0 && v >= 0 ) cnt ++;
                        if ( k < 0 && v < 0 && u >= 0 ) cnt --;
                }
                return ( cnt != 0 );
        }

        double CalcCircumference() {
                double sum = 0;
                p[n] = p[0];
                for ( int i = 0 ; i < n ; i ++ )
                        sum += p[i].Distance(p[i + 1]);
                return sum;
        }
        double CalcArea() {
                double sum = 0;
                for ( int i = 1 ; i < n - 1 ; i ++ )
                        sum += p[0].xmult(p[i], p[i + 1]);
                return sum / 2;
        }
        Point CalcBaryc() {
                Point ret(0, 0);
                double area = 0;
                for ( int i = 1 ; i < n - 1 ; i ++ ) {
                        double temp = p[0].xmult(p[i], p[i + 1]);
                        if ( dcmp(temp) == 0 ) continue;
                        area += temp;
                        ret.x += ( p[0].x + p[i].x + p[i + 1].x ) / 3 * temp;
                        ret.y += ( p[0].y + p[i].y + p[i + 1].y ) / 3 * temp;
                }
                if ( dcmp(area) ) ret.x /= area, ret.y /= area;
                return ret;
        }
};


struct HalfPlane:public Line{
        double angle;
        HalfPlane() {
        }
        HalfPlane( Point _a, Point _b ) {
                a = _a , b = _b;
        }
        void CalcAngle() {
                angle = atan2(b.y - a.y , b.x - a.x);
        }
        bool operator < (const HalfPlane &b) const{
                return angle < b.angle;
        }
};


struct HalfPlanes {
        int n;
        HalfPlane hp[maxP];

        Point p[maxP];
        int que[maxP];
        int st , ed;
        void push(HalfPlane temp) {
                hp[n++] = temp;
        }
        void unique() {
                int m = 1;
                for (int i = 1 ; i < n; i ++) 
                        if ( dcmp(hp[i].angle - hp[i-1].angle) ) hp[m++] = hp[i];
                        else if ( dcmp(hp[m-1].xmult(hp[i].a) > 0) ) hp[m-1] = hp[i];
                n = m;
        }
        bool HalfPlaneInsert() {
                for (int i = 0 ; i < n ; i ++) hp[i].CalcAngle();
                sort(hp , hp + n);
                unique();
                que[st = 0] = 0 , que[ed = 1] = 1;
                p[1] = hp[0].CrossPoint(hp[1]);
                for (int i = 2 ; i < n ; i ++) {
                        while (st < ed && dcmp(hp[i].xmult(p[ ed ])) < 0) ed --;
                        while (st < ed && dcmp(hp[i].xmult(p[ st + 1 ])) < 0) st ++;
                        que[ ++ed ] = i;
                        if (hp[i].parallel(hp[ que[ed-1] ])) return false;

                        p[ed] = hp[i].CrossPoint(hp[ que[ed-1] ]);
                }
                while (st < ed && dcmp(hp[ que[st] ].xmult(p[ ed ])) < 0) ed --;
                while (st < ed && dcmp(hp[ que[ed] ].xmult(p[ st + 1 ])) < 0) st ++;
                if (st + 1 >= ed) return false;
                return true;
        }
        void getConvex(Polygon &convex) {
                p[st] = hp[ que[st] ].CrossPoint(hp[ que[ed] ]);
                convex.n = ed - st + 1;
                for (int j = st , i = 0 ; j <= ed ; i ++ , j ++) {
                        convex.p[i] = p[j];
                }
        }
};
Polygon pl;
Point s,t;
int n;
set<Point>st;
vector<Point>p;
double g[120][120];
int main()
{
        int i,j,k;
        s.input();
        t.input();
        scanf("%d",&n);
        pl.n=n;
        pl.input();
        pl.getLine();
        Line ln=Line(s,t);
        for (i=0;i<n;i++)
        {
            if (ln.parallel(pl.l[i]))continue;
                if (ln.SegCrossSeg(pl.l[i]))
                {
                        Point pp=ln.CrossPoint(pl.l[i]);
                        if (st.find(pp)!=st.end())continue;
                        p.pb(pp);
                        st.insert(pp);
                        

                }
        }
        int sz=p.size();
        if (sz<2)
        {
                printf("%lf\n",s.Distance(t));
                return 0;
        }
        for (i=0;i<120;i++)
        {
                for (j=0;j<120;j++)
                {
                        g[i][j]=1e50;
                        if (i==j)g[i][j]=0;
                }
        }
        for (i=0;i<n;i++)
        {
                for (j=0;j<n;j++)
                {
                        g[i][j]=pl.p[i].Distance(pl.p[j])*2;
                }
        }
        for (i=0;i<n;i++)
        {
                g[i][(i+1)%n]=g[(i+1)%n][i]=pl.p[i].Distance(pl.p[(i+1)%n]);
        }
        g[n+1][n]=g[n][n+1]=p[0].Distance(p[1])*2;
        Line l1(s,p[0]);
        
        double ds1=s.Distance(p[0]);
        double ds2=s.Distance(p[1]);
        if (ds1<ds2)
        {
            g[n][n+2]=g[n][n+2]=s.Distance(p[0]);
                g[n+1][n+3]=g[n+3][n+1]=t.Distance(p[1]);
        }
        else 
        {
            g[n+2][n+1]=g[n+1][n+2]=s.Distance(p[1]);
                        g[n][n+3]=g[n+3][n]=t.Distance(p[0]);
        }
        int cnt=0;
        st.clear();
        for (i=0;i<n;i++)
        {
            if (ln.parallel(pl.l[i]))continue;
                if (ln.SegCrossSeg(pl.l[i]))
                {
                        Point pp=ln.CrossPoint(pl.l[i]);
                        

                        if (st.find(pp)!=st.end())continue;
                        st.insert(pp);
                        if (cnt==0)
                        {
                                if (i==0)
                                {
                                        g[n][n-1]=g[n-1][n]=p[0].Distance(pl.p[n-1]);
                                        g[n][0]=g[0][n]=p[0].Distance(pl.p[0]);
                                }
                                else 
                                {
                                        g[n][i-1]=g[i-1][n]=p[0].Distance(pl.p[i-1]);
                                        g[n][i]=g[i][n]=p[0].Distance(pl.p[i]);
                                }
                                cnt++;
                        }
                        else 
                        {
                                if (i==0)
                                {
                                        g[n+1][n-1]=g[n-1][n+1]=p[1].Distance(pl.p[n-1]);
                                        g[n+1][0]=g[0][n+1]=p[1].Distance(pl.p[0]);
                                }
                                else 
                                {
                                        g[n+1][i-1]=g[i-1][n+1]=p[1].Distance(pl.p[i-1]);
                                        g[n+1][i]=g[i][n+1]=p[1].Distance(pl.p[i]);
                                }
                                cnt++;
                        }
                }
        }
        n+=4;
        for (k=0;k<n;k++)
        {
                for (i=0;i<n;i++)
                {
                        for (j=0;j<n;j++)
                        {
                                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                        }
                }
        }
        printf("%lf\n",g[n-1][n-2]);
        return 0;
}
