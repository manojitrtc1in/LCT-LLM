#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 305;
#define mp make_pair
#define pb push_back
namespace Geometry{
    #define typec double
    const typec eps=1e-8;
    const typec pi=acos(-1.0);
    const typec inf=1e20;
    const int maxp=100001;
    int dblcmp(double d){
        if (fabs(d)<eps)return 0;
        return d>eps?1:-1;
    }
    int sgn(double a) {return a<-eps?-1:a>eps;}
    inline double sqr(double x){return x*x;}
    struct Point2D{
        typec x,y;
        Point2D(){}
        Point2D(typec _x,typec _y):x(_x),y(_y){};
        void input(){
            scanf("%lf%lf",&x,&y);
        }
        void output(){
            printf("%.2f %.2f\n",x,y);
        }
        bool operator==(Point2D a)const{
            return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
        }
        bool operator<(Point2D a)const{
            return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
        }
        typec len(){
            return hypot(x,y);
        }
        typec len2(){
            return x*x+y*y;
        }
        Point2D operator + (const Point2D &A) const{
            return Point2D(x + A.x , y + A.y);
        }
        Point2D operator - (const Point2D &A) const{
            return Point2D(x - A.x , y - A.y);
        }
        Point2D operator * (const typec _x) const{
            return Point2D(x * _x , y * _x);
        }
        typec operator * (const Point2D &A) const{
            return x * A.x + y * A.y;
        }
        typec operator ^ (const Point2D &A) const{
            return x * A.y - y * A.x;
        }
        Point2D operator / (const typec _p) const{
            return Point2D(x / _p , y / _p);
        }
        typec distance(Point2D p){
            return sqr(x-p.x) +sqr (y-p.y);
        }
        Point2D add(Point2D p){
            return Point2D(x+p.x,y+p.y);
        }
        Point2D sub(Point2D p){
            return Point2D(x-p.x,y-p.y);
        }
        Point2D mul(typec b){
            return Point2D(x*b,y*b);
        }
        Point2D div(typec b){
            return Point2D(x/b,y/b);
        }
        typec dot(Point2D p){
            return x*p.x+y*p.y;
        }
        typec det(Point2D p){
            return x*p.y-y*p.x;
        }
        typec rad(Point2D a,Point2D b){
            Point2D p=*this;
            return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
        }
        Point2D trunc(typec r){
            typec l=len();
            if (!dblcmp(l))return *this;
            r/=l;
            return Point2D(x*r,y*r);
        }
        Point2D rotleft(){
            return Point2D(-y,x);
        }
        Point2D rotright(){
            return Point2D(y,-x);
        }
        Point2D rotate(Point2D p,typec angle)

        {
            Point2D v=this->sub(p);
            typec c=cos(angle),s=sin(angle);
            return Point2D(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
        }
    };

    typec cross(Point2D a,Point2D b,Point2D c){
        return (b.sub(a)).det(c.sub(a));
    }

    struct Line2D{
        Point2D a,b;
        double at;
        Line2D(){}
        Line2D(Point2D _a,Point2D _b){
            a=_a;
            b=_b;
        }
        bool operator==(Line2D v){
            return (a==v.a)&&(b==v.b);
        }
        bool operator < (const Line2D &t) const {
            return sgn(at-t.at)<0||
                    (sgn(at-t.at)==0&&sgn(cross(a,b,t.a))<0);
        }

        Point2D operator &(Line2D &A)const
        {
            Point2D res = a;
            

            

            double t = ((a - A.a) ^ (A.a - A.b)) / ((a - b) ^ (A.a - A.b));
            res.x += (b.x - a.x) * t;
            res.y += (b.y - a.y) * t;
            return res;
        }
        

        Line2D(Point2D p,double angle)
        {
            a=p;
            if (dblcmp(angle-pi/2)==0)
            {
                b=a.add(Point2D(0,1));
            }
            else
            {
                b=a.add(Point2D(1,tan(angle)));
            }
        }

        

        Point2D rotate(Point2D v,Point2D p,double angle,double scale){
            Point2D ret=p;
            v.x-=p.x,v.y-=p.y;
            p.x=scale*cos(angle);
            p.y=scale*sin(angle);
            ret.x+=v.x*p.x-v.y*p.y;
            ret.y+=v.x*p.y+v.y*p.x;
            return ret;
        }

        

        Line2D(typec _a,typec _b,typec _c){
            if (dblcmp(_a)==0)
            {
                a=Point2D(0,-_c/_b);
                b=Point2D(1,-_c/_b);
            }
            else if (dblcmp(_b)==0)
            {
                a=Point2D(-_c/_a,0);
                b=Point2D(-_c/_a,1);
            }
            else
            {
                a=Point2D(0,-_c/_b);
                b=Point2D(1,(-_c-_a)/_b);
            }
        }
        void input()
        {
            a.input();
            b.input();
            angle();
        }
        void adjust()
        {
            if (b<a)swap(a,b);
        }
        double length()
        {
            return a.distance(b);
        }
        double angle()

        {
            double k=atan2(b.y-a.y,b.x-a.x);
            if (dblcmp(k)<0)k+=pi;
            if (dblcmp(k-pi)==0)k-=pi;
            at = k;
            return k;
        }
        

        

        

        

        int relation(Point2D p)
        {
            int c=dblcmp(p.sub(a).det(b.sub(a)));
            if (c<0)return 1;
            if (c>0)return 2;
            return 3;
        }
        bool pointonseg(Point2D p)
        {
            return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
        }
        bool parallel(Line2D v)
        {
            return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
        }
        

        

        

        int segcrossseg(Line2D v)
        {
            int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
            int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
            int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
            int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
            if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
            return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
                    d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
                    d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
                    d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
        }
    

        int linecrossseg(Line2D v)
        {
            int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
            int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
            if ((d1^d2)==-2)return 2;
            return (d1==0||d2==0);
        }
        

        

        

        int linecrossline(Line2D v)
        {
            if ((*this).parallel(v))
            {
                return v.relation(a)==3;
            }
            return 2;
        }
        Point2D crosspoint(Line2D v)
        {
            double a1=v.b.sub(v.a).det(a.sub(v.a));
            double a2=v.b.sub(v.a).det(b.sub(v.a));
            return Point2D((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
        }
        double dispointtoline(Point2D p)
        {
            return fabs(p.sub(a).det(b.sub(a)))/length();
        }
        double dispointtoseg(Point2D p)
        {
            if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
            {
                return min(p.distance(a),p.distance(b));
            }
            return dispointtoline(p);
        }
        Point2D lineprog(Point2D p)
        {
            return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
        }
        Point2D symmetrypoint(Point2D p)    

        {
            Point2D q=lineprog(p);
            return Point2D(2*q.x-p.x,2*q.y-p.y);
        }
    };
    struct Circle{
        Point2D p;
        typec r;
        Circle(){}
        Circle(Point2D _p,typec _r):
        p(_p),r(_r){};
        Circle(typec x,typec y,typec _r):p(Point2D(x,y)),r(_r){};
        Circle(Point2D a,Point2D b,Point2D c){

            p=Line2D(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(Line2D(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
            r=p.distance(a);
        }
        Circle(Point2D a,Point2D b,Point2D c,bool t)

        {
            Line2D u,v;
            double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
            u.a=a;
            u.b=u.a.add(Point2D(cos((n+m)/2),sin((n+m)/2)));
            v.a=b;
            m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
            v.b=v.a.add(Point2D(cos((n+m)/2),sin((n+m)/2)));
            p=u.crosspoint(v);
            r=Line2D(a,b).dispointtoseg(p);
        }
        void input()
        {
            p.input();
            scanf("%lf",&r);
        }
        void output()
        {
            printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
        }
        bool operator==(Circle v)
        {
            return ((p==v.p)&&dblcmp(r-v.r)==0);
        }
        bool operator<(Circle v)const
        {
            return ((p<v.p)||(p==v.p)&&dblcmp(r-v.r)<0);
        }
        double area()
        {
            return pi*sqr(r);
        }
        double circumference()
        {
            return 2*pi*r;
        }
        

        

        

        int relation(Point2D b)
        {
            double dst=b.distance(p);
            if (dblcmp(dst-r)<0)return 2;
            if (dblcmp(dst-r)==0)return 1;
            return 0;
        }
        int relationseg(Line2D v)
        {
            double dst=v.dispointtoseg(p);
            if (dblcmp(dst-r)<0)return 2;
            if (dblcmp(dst-r)==0)return 1;
            return 0;
        }
        int relationline(Line2D v)
        {
            double dst=v.dispointtoline(p);
            if (dblcmp(dst-r)<0)return 2;
            if (dblcmp(dst-r)==0)return 1;
            return 0;
        }
        

        int getCircle(Point2D a,Point2D b,double r,Circle&c1,Circle&c2)
        {
            Circle x(a,r),y(b,r);
            int t=x.pointcrossCircle(y,c1.p,c2.p);
            if (!t)return 0;
            c1.r=c2.r=r;
            return t;
        }
        

        int getCircle(Line2D u,Point2D q,double r1,Circle &c1,Circle &c2)
        {
            double dis=u.dispointtoline(q);
            if (dblcmp(dis-r1*2)>0)return 0;
            if (dblcmp(dis)==0)
            {
                c1.p=q.add(u.b.sub(u.a).rotleft().trunc(r1));
                c2.p=q.add(u.b.sub(u.a).rotright().trunc(r1));
                c1.r=c2.r=r1;
                return 2;
            }
            Line2D u1=Line2D(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
            Line2D u2=Line2D(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
            Circle cc=Circle(q,r1);
            Point2D p1,p2;
            if (!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
            c1=Circle(p1,r1);
            if (p1==p2)
            {
                c2=c1;return 1;
            }
            c2=Circle(p2,r1);
            return 2;
        }
        

        int getCircle(Line2D u,Line2D v,typec r1,Circle &c1,Circle &c2,Circle &c3,Circle &c4)
        {
            if (u.parallel(v))return 0;
            Line2D u1=Line2D(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
            Line2D u2=Line2D(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
            Line2D v1=Line2D(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
            Line2D v2=Line2D(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
            c1.r=c2.r=c3.r=c4.r=r1;
            c1.p=u1.crosspoint(v1);
            c2.p=u1.crosspoint(v2);
            c3.p=u2.crosspoint(v1);
            c4.p=u2.crosspoint(v2);
            return 4;
        }
        

        int getCircle(Circle cx,Circle cy,double r1,Circle&c1,Circle&c2)
        {
            Circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
            int t=x.pointcrossCircle(y,c1.p,c2.p);
            if (!t)return 0;
            c1.r=c2.r=r1;
            return t;
        }
        int pointcrossline(Line2D v,Point2D &p1,Point2D &p2)

        {
            if (!(*this).relationline(v))return 0;
            Point2D a=v.lineprog(p);
            double d=v.dispointtoline(p);
            d=sqrt(r*r-d*d);
            if (dblcmp(d)==0)
            {
                p1=a;
                p2=a;
                return 1;
            }
            p1=a.sub(v.b.sub(v.a).trunc(d));
            p2=a.add(v.b.sub(v.a).trunc(d));
            return 2;
        }
        

        

        

        

        

        int relationCircle(Circle v)
        {
            double d=p.distance(v.p);
            if (dblcmp(d-r-v.r)>0)return 5;
            if (dblcmp(d-r-v.r)==0)return 4;
            double l=fabs(r-v.r);
            if (dblcmp(d-r-v.r)<0&&dblcmp(d-l)>0)return 3;
            if (dblcmp(d-l)==0)return 2;
            if (dblcmp(d-l)<0)return 1;
        }
        int pointcrossCircle(Circle v,Point2D &p1,Point2D &p2)
        {
            int rel=relationCircle(v);
            if (rel==1||rel==5)return 0;
            double d=p.distance(v.p);
            double l=(d+(sqr(r)-sqr(v.r))/d)/2;
            double h=sqrt(sqr(r)-sqr(l));
            p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
            p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
            if (rel==2||rel==4)
            {
                return 1;
            }
            return 2;
        }
        

        int tangentline(Point2D q,Line2D &u,Line2D &v){
            int x=relation(q);
            if (x==2)return 0;
            if (x==1)
            {
                u=Line2D(q,q.add(q.sub(p).rotleft()));
                v=u;
                return 1;
            }
            double d=p.distance(q);
            double l=sqr(r)/d;
            double h=sqrt(sqr(r)-sqr(l));
            u=Line2D(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
            v=Line2D(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
            return 2;
        }
        double areaCircle(Circle v){
            int rel=relationCircle(v);
            if (rel>=4)return 0.0;
            if (rel<=2)return min(area(),v.area());
            double d=p.distance(v.p);
            double hf=(r+v.r+d)/2.0;
            double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
            double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
            a1=a1*r*r;
            double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
            a2=a2*v.r*v.r;
            return a1+a2-ss;
        }
        double areatriangle(Point2D a,Point2D b){
            if (dblcmp(p.sub(a).det(p.sub(b))==0))return 0.0;
            Point2D q[5];
            int len=0;
            q[len++]=a;
            Line2D l(a,b);
            Point2D p1,p2;
            if (pointcrossline(l,q[1],q[2])==2){
                if (dblcmp(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
                if (dblcmp(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
            }
            q[len++]=b;
            if (len==4&&(dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))swap(q[1],q[2]);
            double res=0;
            int i;
            for (i=0;i<len-1;i++){
                if (relation(q[i])==0||relation(q[i+1])==0){
                    double arg=p.rad(q[i],q[i+1]);
                    res+=r*r*arg/2.0;
                }
                else{
                    res+=fabs(q[i].sub(p).det(q[i+1].sub(p))/2.0);
                }
            }
            return res;
        }
    };
    struct Polygon2D{
        int n;
        Point2D p[maxp];
        Line2D l[maxp];
        void copy(Polygon2D & A){
            A.n=n;
            for (int i=0;i<n;++i){
                A.p[i]=p[i];
                A.l[i]=l[i];
            }
        }
        void input()
        {
            for (int i=0;i<n;i++)
            {
                p[i].input();
            }
        }
        void add(Point2D q)
        {
            p[n++]=q;
        }
        void getline()
        {
            for (int i=0;i<n;i++)
            {
                l[i]=Line2D(p[i],p[(i+1)%n]);
            }
        }
        struct cmp
        {
            Point2D p;
            cmp(const Point2D &p0){p=p0;}
            bool operator()(const Point2D &aa,const Point2D &bb)
            {
                Point2D a=aa,b=bb;
                int d=dblcmp(a.sub(p).det(b.sub(p)));
                if (d==0)
                {
                    return dblcmp(a.distance(p)-b.distance(p))<0;
                }
                return d>0;
            }
        };
        void norm()
        {
            Point2D mi=p[0];
            for (int i=1;i<n;i++)mi=min(mi,p[i]);
            sort(p,p+n,cmp(mi));
        }
        void getconvex(Polygon2D &convex)
        {
            int i,j,k;
            sort(p,p+n);
            convex.n=n;
            for (i=0;i<min(n,2);i++)
            {
                convex.p[i]=p[i];
            }
            if (n<=2)return;
            int &top=convex.n;
            top=1;
            for (i=2;i<n;i++)
            {
                while (top&&dblcmp(convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i])))<=0)
                    top--;
                convex.p[++top]=p[i];
            }
            int temp=top;
            convex.p[++top]=p[n-2];
            for (i=n-3;i>=0;i--)
            {
                while (top!=temp&& dblcmp(convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i])))<=0)
                    top--;
                convex.p[++top]=p[i];
            }
        }
    };

} using namespace Geometry;

Polygon2D poly , convex;
int n , r , m , ans , dist[N][N];
int a[N] , b[N];
void dfs (int idx , int cnt , int tot) {
    if (cnt == n) {
        if (tot > ans) {
            for (int i = 0 ; i < n ; i ++)
                b[i] = a[i];
            ans = tot;
        }
        return ;
    }
    if (idx == convex.n) {
        return ;
    }
    

    dfs (idx + 1 , cnt , tot);
    for (int i = 0 ; i < cnt ; i ++) {
        tot += dist[a[i]][idx];
    }
    a[cnt] = idx;
    dfs (idx , cnt + 1 , tot);
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    

#endif
    scanf ("%d %d" , &n , &r);
    m = 0;
    poly.add (Point2D (-r , 0));
    poly.add (Point2D (r , 0));
    for (int i = -r + 1 ; i < r ; i ++) {
        int up = -r , down = r;
        for (int j = -r ; j <= r ; j ++) {
            if (i * i + j * j <= r * r) {
                up = max (up , j);
                down = min (down , j);
            }
        }
        poly.add (Point2D (i , up));
        poly.add (Point2D (i , down));
    }
    poly.add (Point2D (0 , 0));
    poly.getconvex (convex);
    for (int i = 0 ; i < convex.n ; i ++)
        for (int j = 0 ; j < convex.n ; j ++)
            dist[i][j] = convex.p[i].distance (convex.p[j]);
    ans = 0;
    dfs (0 , 0 , 0);
    printf ("%d\n" , ans);
    for (int i = 0 ; i < n ; i ++) {
        printf ("%.0f %.0f\n" , convex.p[b[i]].x , convex.p[b[i]].y);
    }
    return 0;
}