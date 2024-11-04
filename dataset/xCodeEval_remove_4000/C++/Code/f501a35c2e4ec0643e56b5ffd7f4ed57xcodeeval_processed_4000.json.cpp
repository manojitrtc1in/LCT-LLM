
using namespace std;
typedef long long LL;
const int N = 305;


namespace Geometry{
    
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
    struct id1{
        typec x,y;
        id1(){}
        id1(typec _x,typec _y):x(_x),y(_y){};
        void input(){
            scanf("%lf%lf",&x,&y);
        }
        void output(){
            printf("%.2f %.2f\n",x,y);
        }
        bool operator==(id1 a)const{
            return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
        }
        bool operator<(id1 a)const{
            return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
        }
        typec len(){
            return hypot(x,y);
        }
        typec len2(){
            return x*x+y*y;
        }
        id1 operator + (const id1 &A) const{
            return id1(x + A.x , y + A.y);
        }
        id1 operator - (const id1 &A) const{
            return id1(x - A.x , y - A.y);
        }
        id1 operator * (const typec _x) const{
            return id1(x * _x , y * _x);
        }
        typec operator * (const id1 &A) const{
            return x * A.x + y * A.y;
        }
        typec operator ^ (const id1 &A) const{
            return x * A.y - y * A.x;
        }
        id1 operator / (const typec _p) const{
            return id1(x / _p , y / _p);
        }
        typec distance(id1 p){
            return sqr(x-p.x) +sqr (y-p.y);
        }
        id1 add(id1 p){
            return id1(x+p.x,y+p.y);
        }
        id1 sub(id1 p){
            return id1(x-p.x,y-p.y);
        }
        id1 mul(typec b){
            return id1(x*b,y*b);
        }
        id1 div(typec b){
            return id1(x/b,y/b);
        }
        typec dot(id1 p){
            return x*p.x+y*p.y;
        }
        typec det(id1 p){
            return x*p.y-y*p.x;
        }
        typec rad(id1 a,id1 b){
            id1 p=*this;
            return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
        }
        id1 trunc(typec r){
            typec l=len();
            if (!dblcmp(l))return *this;
            r/=l;
            return id1(x*r,y*r);
        }
        id1 rotleft(){
            return id1(-y,x);
        }
        id1 rotright(){
            return id1(y,-x);
        }
        id1 rotate(id1 p,typec angle)

        {
            id1 v=this->sub(p);
            typec c=cos(angle),s=sin(angle);
            return id1(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
        }
    };

    typec cross(id1 a,id1 b,id1 c){
        return (b.sub(a)).det(c.sub(a));
    }

    struct id0{
        id1 a,b;
        double at;
        id0(){}
        id0(id1 _a,id1 _b){
            a=_a;
            b=_b;
        }
        bool operator==(id0 v){
            return (a==v.a)&&(b==v.b);
        }
        bool operator < (const id0 &t) const {
            return sgn(at-t.at)<0||
                    (sgn(at-t.at)==0&&sgn(cross(a,b,t.a))<0);
        }

        id1 operator &(id0 &A)const
        {
            id1 res = a;
            

            

            double t = ((a - A.a) ^ (A.a - A.b)) / ((a - b) ^ (A.a - A.b));
            res.x += (b.x - a.x) * t;
            res.y += (b.y - a.y) * t;
            return res;
        }
        

        id0(id1 p,double angle)
        {
            a=p;
            if (dblcmp(angle-pi/2)==0)
            {
                b=a.add(id1(0,1));
            }
            else
            {
                b=a.add(id1(1,tan(angle)));
            }
        }

        

        id1 rotate(id1 v,id1 p,double angle,double scale){
            id1 ret=p;
            v.x-=p.x,v.y-=p.y;
            p.x=scale*cos(angle);
            p.y=scale*sin(angle);
            ret.x+=v.x*p.x-v.y*p.y;
            ret.y+=v.x*p.y+v.y*p.x;
            return ret;
        }

        

        id0(typec _a,typec _b,typec _c){
            if (dblcmp(_a)==0)
            {
                a=id1(0,-_c/_b);
                b=id1(1,-_c/_b);
            }
            else if (dblcmp(_b)==0)
            {
                a=id1(-_c/_a,0);
                b=id1(-_c/_a,1);
            }
            else
            {
                a=id1(0,-_c/_b);
                b=id1(1,(-_c-_a)/_b);
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
        

        

        

        

        int relation(id1 p)
        {
            int c=dblcmp(p.sub(a).det(b.sub(a)));
            if (c<0)return 1;
            if (c>0)return 2;
            return 3;
        }
        bool pointonseg(id1 p)
        {
            return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
        }
        bool parallel(id0 v)
        {
            return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
        }
        

        

        

        int segcrossseg(id0 v)
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
    

        int linecrossseg(id0 v)
        {
            int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
            int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
            if ((d1^d2)==-2)return 2;
            return (d1==0||d2==0);
        }
        

        

        

        int linecrossline(id0 v)
        {
            if ((*this).parallel(v))
            {
                return v.relation(a)==3;
            }
            return 2;
        }
        id1 crosspoint(id0 v)
        {
            double a1=v.b.sub(v.a).det(a.sub(v.a));
            double a2=v.b.sub(v.a).det(b.sub(v.a));
            return id1((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
        }
        double dispointtoline(id1 p)
        {
            return fabs(p.sub(a).det(b.sub(a)))/length();
        }
        double dispointtoseg(id1 p)
        {
            if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
            {
                return min(p.distance(a),p.distance(b));
            }
            return dispointtoline(p);
        }
        id1 lineprog(id1 p)
        {
            return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
        }
        id1 symmetrypoint(id1 p)    

        {
            id1 q=lineprog(p);
            return id1(2*q.x-p.x,2*q.y-p.y);
        }
    };
    struct Circle{
        id1 p;
        typec r;
        Circle(){}
        Circle(id1 _p,typec _r):
        p(_p),r(_r){};
        Circle(typec x,typec y,typec _r):p(id1(x,y)),r(_r){};
        Circle(id1 a,id1 b,id1 c){

            p=id0(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(id0(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
            r=p.distance(a);
        }
        Circle(id1 a,id1 b,id1 c,bool t)

        {
            id0 u,v;
            double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
            u.a=a;
            u.b=u.a.add(id1(cos((n+m)/2),sin((n+m)/2)));
            v.a=b;
            m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
            v.b=v.a.add(id1(cos((n+m)/2),sin((n+m)/2)));
            p=u.crosspoint(v);
            r=id0(a,b).dispointtoseg(p);
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
        

        

        

        int relation(id1 b)
        {
            double dst=b.distance(p);
            if (dblcmp(dst-r)<0)return 2;
            if (dblcmp(dst-r)==0)return 1;
            return 0;
        }
        int relationseg(id0 v)
        {
            double dst=v.dispointtoseg(p);
            if (dblcmp(dst-r)<0)return 2;
            if (dblcmp(dst-r)==0)return 1;
            return 0;
        }
        int relationline(id0 v)
        {
            double dst=v.dispointtoline(p);
            if (dblcmp(dst-r)<0)return 2;
            if (dblcmp(dst-r)==0)return 1;
            return 0;
        }
        

        int getCircle(id1 a,id1 b,double r,Circle&c1,Circle&c2)
        {
            Circle x(a,r),y(b,r);
            int t=x.pointcrossCircle(y,c1.p,c2.p);
            if (!t)return 0;
            c1.r=c2.r=r;
            return t;
        }
        

        int getCircle(id0 u,id1 q,double r1,Circle &c1,Circle &c2)
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
            id0 u1=id0(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
            id0 u2=id0(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
            Circle cc=Circle(q,r1);
            id1 p1,p2;
            if (!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
            c1=Circle(p1,r1);
            if (p1==p2)
            {
                c2=c1;return 1;
            }
            c2=Circle(p2,r1);
            return 2;
        }
        

        int getCircle(id0 u,id0 v,typec r1,Circle &c1,Circle &c2,Circle &c3,Circle &c4)
        {
            if (u.parallel(v))return 0;
            id0 u1=id0(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
            id0 u2=id0(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
            id0 v1=id0(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
            id0 v2=id0(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
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
        int pointcrossline(id0 v,id1 &p1,id1 &p2)

        {
            if (!(*this).relationline(v))return 0;
            id1 a=v.lineprog(p);
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
        int pointcrossCircle(Circle v,id1 &p1,id1 &p2)
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
        

        int tangentline(id1 q,id0 &u,id0 &v){
            int x=relation(q);
            if (x==2)return 0;
            if (x==1)
            {
                u=id0(q,q.add(q.sub(p).rotleft()));
                v=u;
                return 1;
            }
            double d=p.distance(q);
            double l=sqr(r)/d;
            double h=sqrt(sqr(r)-sqr(l));
            u=id0(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
            v=id0(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
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
        double areatriangle(id1 a,id1 b){
            if (dblcmp(p.sub(a).det(p.sub(b))==0))return 0.0;
            id1 q[5];
            int len=0;
            q[len++]=a;
            id0 l(a,b);
            id1 p1,p2;
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
        id1 p[maxp];
        id0 l[maxp];
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
        void add(id1 q)
        {
            p[n++]=q;
        }
        void getline()
        {
            for (int i=0;i<n;i++)
            {
                l[i]=id0(p[i],p[(i+1)%n]);
            }
        }
        struct cmp
        {
            id1 p;
            cmp(const id1 &p0){p=p0;}
            bool operator()(const id1 &aa,const id1 &bb)
            {
                id1 a=aa,b=bb;
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
            id1 mi=p[0];
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

    freopen ("input.txt" , "r" , stdin);
    


    scanf ("%d %d" , &n , &r);
    m = 0;
    poly.add (id1 (-r , 0));
    poly.add (id1 (r , 0));
    for (int i = -r + 1 ; i < r ; i ++) {
        int up = -r , down = r;
        for (int j = -r ; j <= r ; j ++) {
            if (i * i + j * j <= r * r) {
                up = max (up , j);
                down = min (down , j);
            }
        }
        poly.add (id1 (i , up));
        poly.add (id1 (i , down));
    }
    poly.add (id1 (0 , 0));
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