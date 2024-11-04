




























using namespace std;
const double eps=1e-8;
const double inf=1e20;
const double pi=acos(-1.0);
const int maxp=1611;
int dblcmp(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline double sqr(double x){return x*x;}
struct point 
{
    double x,y;
    point(){}
    point(double _x,double _y):
    x(_x),y(_y){};
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    void output()
    {
        printf("%.2f %.2f\n",x,y);
    }
    bool operator==(point a)
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len()
    {
        return sqrt(len2());
    }
    double len2()
    {
        return x*x+y*y;
    }
    double distance(point p)
    {
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    }
    point add(point p)
    {
        return point(x+p.x,y+p.y);
    }
    point sub(point p)
    {
        return point(x-p.x,y-p.y);
    }
    point mul(double b)
    {
        return point(x*b,y*b);
    }
    point div(double b)
    {
        return point(x/b,y/b);
    }
    double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    double det(point p)
    {
        return x*p.y-y*p.x;
    }
    double rad(point a,point b)
    {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r)
    {
        r/=len();
        return point(x*r,y*r);
    }
    point rotleft()
    {
        return point(-y,x);
    }
    point rotright()
    {
        return point(y,-x);
    }
    point rotate(point p,double angle)

    {
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }        
};
struct line 
{
    point a,b;
    line(){}
    line(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line v)
    {
        return (a==v.a)&&(b==v.b);
    }
    

    line(point p,double angle)
    {
        a=p;
        if (dblcmp(angle-pi/2)==0)
        {
            b=a.add(point(0,1));
        }
        else 
        {
            b=a.add(point(1,tan(angle)));
        }
    }       
    line(double _a,double _b,double _c)
    {
        if (dblcmp(_a)==0)
        {
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        }
        else if (dblcmp(_b)==0)
        {
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        }
        else 
        {
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input()
    {
        a.input();
        b.input();
    }
    void adjust()
    {
        if (b<a)swap(a,b);
    }
    double length()
    {
        return a.distance(b);
    }
    

    

    

    

    int relation(point p)
    {
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p)
    {
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v)
    {
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    

    

    

    int segcrossseg(line v)
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
    int linecrossseg(line v)
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    int linecrossline(line v)
    {
        if ((*this).parallel(v))
        {
            return v.relation(a)==3;
        }
        return 2;
    }
    point crosspoint(line v)
    {
        double a1=v.b.sub(v.a).det(a.sub(v.a));
        double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p)
    {
        return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    double dispointtoseg(point p)
    {
        if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
        {
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p)
    {
        return a.add(b.sub(a).trunc(b.sub(a).dot(p.sub(a))/b.distance(a)));
    }
    point symmetrypoint(point p)
    {
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }   
};
struct polygon 
{
    int n;
    point p[maxp];
    line l[maxp];
    void input()
    {
        for (int i=0;i<n;i++)
        {
            p[i].input();
        }
    }
    void add(point q)
    {
        p[n++]=q;
    }
    void getline()
    {
        for (int i=0;i<n;i++)
        {
            l[i]=line(p[i],p[(i+1)%n]);
        }
    }
    struct cmp
    {
        point p;
        cmp(const point &p0){p=p0;}
        bool operator()(const point &aa,const point &bb)
        {
            point a=aa,b=bb;
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
        point mi=p[0];
        for (int i=1;i<n;i++)mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    void getconvex(polygon &convex)
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
            while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for (i=n-3;i>=0;i--)
        {
            while (top!=temp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
    }
    bool isconvex()
    {
        bool s[3];
        memset(s,0,sizeof(s));
        int i,j,k;
        for (i=0;i<n;i++)
        {
            j=(i+1)%n;
            k=(j+1)%n;
            s[dblcmp(p[j].sub(p[i]).det(p[k].sub(p[i])))+1]=1;
            if (s[0]&&s[2])return 0;
        }
        return 1;
    }
    

    

    

    

    int relationpoint(point q)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            if (p[i]==q)return 3;
        }
        getline();
        for (i=0;i<n;i++)
        {
            if (l[i].pointonseg(q))return 2;
        }
        int cnt=0;
        for (i=0;i<n;i++)
        {
            j=(i+1)%n;
            int k=dblcmp(q.sub(p[j]).det(p[i].sub(p[j])));
            int u=dblcmp(p[i].y-q.y);
            int v=dblcmp(p[j].y-q.y);
            if (k>0&&u<0&&v>=0)cnt++;
            if (k<0&&v<0&&u>=0)cnt--;
        }
        return cnt!=0;
    }
    

    

    

    int relationline(line u)
    {
        int i,j,k=0;
        getline();
        for (i=0;i<n;i++)
        {
            if (l[i].segcrossseg(u)==2)return 1;
            if (l[i].segcrossseg(u)==1)k=1;
        }
        if (!k)return 0;
        vector<point>vp; 
        for (i=0;i<n;i++)
        {
            if (l[i].segcrossseg(u))
            {
                if (l[i].parallel(u))
                {
                    vp.pb(u.a);
                    vp.pb(u.b);
                    vp.pb(l[i].a);
                    vp.pb(l[i].b);
                    continue;
                }
                vp.pb(l[i].crosspoint(u));
            }
        }
        sort(vp.begin(),vp.end());
        int sz=vp.size();
        for (i=0;i<sz-1;i++)
        {
            point mid=vp[i].add(vp[i+1]).div(2);
            if (relationpoint(mid)==1)return 1;
        }
        return 2;
    }
    

    

    void convexcut(line u,polygon &po)
    {
        int i,j,k;
        int &top=po.n;
        top=0;
        for (i=0;i<n;i++)
        {
            int d1=dblcmp(p[i].sub(u.a).det(u.b.sub(u.a)));
            int d2=dblcmp(p[(i+1)%n].sub(u.a).det(u.b.sub(u.a)));
            if (d1>=0)po.p[top++]=p[i];
            if (d1*d2<0)po.p[top++]=u.crosspoint(line(p[i],p[(i+1)%n]));
        }
    }
    double getcircumference()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
    double getarea()
    {
        double sum=0;
        int i;
        for (i=1;i<n-1;i++)
        {
            sum+=p[i].sub(p[0]).det(p[(i+1)%n].sub(p[0]));
        }
        if (dblcmp(sum)<0)
        {
            

            reverse(p,p+n);
        }
        return fabs(sum)/2;
    }
    point getbarycentre()
    {
        point ret(0,0);
        double area=0;
        int i;
        for (i=1;i<n-1;i++)
        {
            double tmp=p[i].sub(p[0]).det(p[i+1].sub(p[0]));
            if (dblcmp(tmp)==0)continue;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if (dblcmp(area))ret=ret.div(area);
        return ret;
    }
    double areaintersection(polygon po)
    {
    }
    double areaunion(polygon po)
    {
        return getarea()+po.getarea()-areaintersection(po);
    }
};
struct circle 
{
    point p;
    double r;
    circle(){}
    circle(point _p,double _r):
    p(_p),r(_r){};
    circle(double x,double y,double _r):
    p(point(x,y)),r(_r){};
    circle(point a,point b,point c)
    {
        p=line(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(line(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
        r=p.distance(a);
    }
    void input()
    {
        p.input();
        scanf("%lf",&r);
    }
    bool operator==(circle v)
    {
        return ((p==v.p)&&dblcmp(r-v.r)==0);
    }
    double area()
    {
        return pi*sqr(r);
    }
    double circumference()
    {
        return 2*pi*r;
    }
    

    

    

    int relation(point b)
    {
        double dst=b.distance(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int crossseg(line v)
    {
        return dblcmp(v.dispointtoseg(p)-r)<=0;
    }
    int getcircle(point a,point b,double r,circle&c1,circle&c2)
    {
        circle x(a,r),y(b,r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
        if (!t)return 0;
        c1.r=c2.r=r;
        return t;
    }
    int pointcrossline(line v,point &p1,point &p2)
    {
        if (!(*this).crossseg(v))return 0;
        point a=v.lineprog(p);
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
    

    

    

    

    

    int relationcircle(circle v)
    {
        double d=p.distance(v.p);
        if (dblcmp(d-r-v.r)>0)return 5;
        if (dblcmp(d-r-v.r)==0)return 4;
        double l=fabs(r-v.r);
        if (dblcmp(d-r-v.r)<0&&dblcmp(d-l)>0)return 3;
        if (dblcmp(d-l)==0)return 2;
        if (dblcmp(d-l)<0)return 1;
    }
    int pointcrosscircle(circle v,point &p1,point &p2)
    {
        int rel=relationcircle(v);
        if (rel==1||rel==5)return 0;
        if (rel==2||rel==4)
        {
            p1=p.add(v.p.sub(p).trunc(r));
            p2=p.add(v.p.sub(p).trunc(r));
            return 1;
        }
        double d=p.distance(v.p);
        double l=(d+(sqr(r)-sqr(v.r))/d)/2;
        double h=sqrt(sqr(r)-sqr(l));
        p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
        p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
        return 2;
    }
    void tangentline(point q,line &u,line &v)
    {
        double d=p.distance(q);
        double l=sqr(r)/d;
        double h=sqrt(sqr(r)-sqr(l));
        u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
        v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
    }
    double areacircle(circle v)
    {
        int rel=relationcircle(v); 
        if (rel>=4)return 0.0;
        if (rel<=2)return min(area(),v.area());
        double d=p.distance(v.p);
        double hf=(r+v.r+d)/2.0;
        double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
        double a1=acos((r*r+d*d-v.r*v.r)/2.0*r*d);
        a1=a1*r*r;
        double a2=acos((v.r*v.r+d*d-r*r)/2.0*v.r*d);
        a2=a2*v.r*v.r;
        return a1+a2-ss;
    }
    double areatriangle(point a,point b)
    {
        point p1,p2;
        line l(a,b);
        int t=pointcrossline(l,p1,p2);
        double angle;
        if (t<=1)
        {
            return fabs(area()*p.rad(a,b)/(2*pi));
        }
        bool b1=l.pointonseg(p1);
        bool b2=l.pointonseg(p2);
        if (b1&&b2)
        {
            return fabs(area()*p.rad(a,p1)/(2*pi)+area()*p.rad(p2,b)/(2*pi)+fabs(p1.sub(p).det(p2.sub(p)))/2.0);
        }
        if (b1)
        {
            return fabs(area()*p.rad(a,p1)/(2*pi)+fabs(p1.sub(p).det(b.sub(p))/2.0));
        }
        if (b2)
        {
            return fabs(area()*p.rad(p2,b)/(2*pi)+fabs(a.sub(p).det(p2.sub(p))/2.0));
        }
        return fabs(a.sub(p).det(b.sub(p))/2.0);
    }   
    double areapologon(polygon pl)
    {
        int i,j,k,l,m;
        double ans=0;
        for (i=0;i<pl.n;i++)
        {
            int j=(i+1)%pl.n;
            if (dblcmp(pl.p[j].sub(p).det(pl.p[i].sub(p)))>=0)
            {
                ans+=areatriangle(pl.p[i],pl.p[j]);
            }
            else 
            {
                ans-=areatriangle(pl.p[i],pl.p[j]);
            }
        }
        return fabs(ans);
    }
};
const int maxn=500;
struct circles 
{
    circle c[maxn];
    int n;
    circles(){}
    void add(circle cc)
    {
        c[n++]=cc;
    }
    void init_or()

    {
        bool v[maxn]={0};
        int i,j,k=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i==j)continue;
                if (c[i].relationcircle(c[j])==1)v[i]=1;
            }
        }
        for (i=0;i<n;i++)
        {
            if (!v[i])c[k++]=c[i];
        }
        n=k;
    }
    void init_and()

    {
        bool v[maxn]={0};
        int i,j,k=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i==j)continue;
                if (c[j].relationcircle(c[i])==1)v[i]=1;
            }
        }
        for (i=0;i<n;i++)
        {
            if (!v[i])c[k++]=c[i];
        }
        n=k;
    }               
};
struct halfplane:public line
{
    double angle;
    halfplane(){}
    halfplane(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    void calcangle()
    {
        angle=atan2(b.y-a.y,b.x-a.x);
    }
    bool operator<(const halfplane &b)const 
    {
        return angle<b.angle;
    }
};
struct halfplanes 
{
    int n;
    halfplane hp[maxp];
    point p[maxp];
    int que[maxp];
    int st,ed;
    void push(halfplane tmp)
    {
        hp[n++]=tmp;
    }
    void unique()
    {
        int m=1,i;
        for (i=1;i<n;i++)
        {
            if (dblcmp(hp[i].angle-hp[i-1].angle))hp[m++]=hp[i];
            else if (dblcmp(hp[m-1].b.sub(hp[m-1].a).det(hp[i].a.sub(hp[m-1].a))>0))hp[m-1]=hp[i];
        }
        n=m;
    }
    bool halfplaneinsert()
    {
        int i;
        for (i=0;i<n;i++)hp[i].calcangle();
        sort(hp,hp+n);
        unique();
        que[st=0]=0;
        que[ed=1]=1;
        p[1]=hp[0].crosspoint(hp[1]);
        for (i=2;i<n;i++)
        {
            while (st<ed&&dblcmp((hp[i].b.sub(hp[i].a).det(p[ed].sub(hp[i].a))))<0)ed--;
            while (st<ed&&dblcmp((hp[i].b.sub(hp[i].a).det(p[st+1].sub(hp[i].a))))<0)st++;
            que[++ed]=i;
            if (hp[i].parallel(hp[que[ed-1]]))return false;
            p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
        }
        while (st<ed&&dblcmp(hp[que[st]].b.sub(hp[que[st]].a).det(p[ed].sub(hp[que[st]].a)))<0)ed--;
        while (st<ed&&dblcmp(hp[que[ed]].b.sub(hp[que[ed]].a).det(p[st+1].sub(hp[que[ed]].a)))<0)st++;
        if (st+1>=ed)return false;
        return true;
    }
    void getconvex(polygon &con)
    {
        p[st]=hp[que[st]].crosspoint(hp[que[ed]]);
        con.n=ed-st+1;
        int j=st,i=0;
        for (;j<=ed;i++,j++)
        {
            con.p[i]=p[j];
        }
    }
};
struct point3 
{
    double x,y,z;
    point3(){}
    point3(double _x,double _y,double _z):
    x(_x),y(_y),z(_z){};
    void input()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    void output()
    {
        printf("%.2lf %.2lf %.2lf",x,y,z);
    }
    bool operator==(point3 a)
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0&&dblcmp(a.z-z)==0;
    }
    bool operator<(point3 a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)==0?dblcmp(z-a.z)<0:y<a.y:x<a.x;
    }
    double len()
    {
        return sqrt(len2());
    }
    double len2()
    {
        return x*x+y*y+z*z;
    }
    double distance(point3 p)
    {
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)+(p.z-z)*(p.z-z));
    }
    point3 add(point3 p)
    {
        return point3(x+p.x,y+p.y,z+p.z);
    }
    point3 sub(point3 p)
    {
        return point3(x-p.x,y-p.y,z-p.z);
    }
    point3 mul(double d)
    {
        return point3(x*d,y*d,z*d);
    }
    point3 div(double d)
    {
        return point3(x/d,y/d,z/d);
    }
    double dot(point3 p)
    {
        return x*p.x+y*p.y+z*p.z;
    }
    point3 det(point3 p)
    {
        return point3(y*p.z-p.y*z,p.x*z-x*p.z,x*p.y-p.x*y);
    }
    double rad(point3 a,point3 b)
    {
        point3 p=(*this);
        return acos(a.sub(p).dot(b.sub(p))/(a.distance(p)*b.distance(p)));
    }
    point3 trunc(double r)
    {
        r/=len();
        return point3(x*r,y*r,z*r);
    }
    point3 rotate(point3 o,double r)
    {
    }
};
struct line3 
{
    point3 a,b;
    line3(){}
    line3(point3 _a,point3 _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line3 v)
    {
        return (a==v.a)&&(b==v.b);
    }
    void input()
    {
        a.input();
        b.input();
    }
    double length()
    {
        return a.distance(b);
    }
    double dispointtoline(point3 p)
    {
        return b.sub(a).det(p.sub(a)).len()/a.distance(b);
    }
    point3 lineprog(point3 p)
    {
        return a.add(b.sub(a).trunc(b.sub(a).dot(p.sub(a))/b.distance(a)));
    }   
};
struct plane
{
    point3 a,b,c,o;
    plane(){}
    plane(point3 _a,point3 _b,point3 _c)
    {
        a=_a;
        b=_b;
        c=_c;
        o=pvec();
    }
    plane(double _a,double _b,double _c,double _d)
    {
        

        o=point3(_a,_b,_c);
        if (dblcmp(_a)!=0)
        {
            a=point3((-_d-_c-_b)/_a,1,1);
        }
        else if (dblcmp(_b)!=0)
        {
            a=point3(1,(-_d-_c-_a)/_b,1);
        }
        else if (dblcmp(_c)!=0)
        {
            a=point3(1,1,(-_d-_a-_b)/_c);
        }
    }
    void input()
    {
        a.input();
        b.input();
        c.input();
    }
    point3 pvec()
    {
        return b.sub(a).det(c.sub(a));
    }
    int crossline(line3 u,point3 &p)
    {
        double x=o.dot(u.b.sub(a));
        double y=o.dot(u.a.sub(a));
        double d=x-y;
        if (dblcmp(fabs(d))==0)return 0;
        p=u.a.mul(x).sub(u.b.mul(y)).div(d);
        return 1;
    }
};
int count(line u)
{


    int x=(int)ceil(u.a.x);
    int y=(int)floor(u.b.x+eps);
    

    return y-x+1;
}
halfplanes hps;
polygon pl,con;
int main()
{
    int i,j,k,n,cc=0,cas;
    cas=1;
    while (cas--)
    {
    scanf("%d",&n);
        pl.n=n;
        pl.input();
        line uu=line(pl.p[0],pl.p[1]);
        pl.getarea();
        pl.getline();
        hps.n=0;
        for (i=0;i<n;i++)
        {
            

            

            hps.push(halfplane(pl.l[i].a,pl.l[i].b));
        }
        hps.halfplaneinsert();
        hps.getconvex(pl);
        pl.getline();
    

    

    for (i=0;i<pl.n;i++)pl.l[i].adjust();
        line u=uu;
        

        

        line seg;
        int b=0;
        set<point>st;
        u.adjust();
        
        

        

        

        

        

        

        for (i=0;i<pl.n;i++)
        {
            
            if (!u.segcrossseg(pl.l[i]))continue;
            

            if (u.parallel(pl.l[i]))
            {
                if (dblcmp(u.a.sub(pl.l[i].a).det(u.a.sub(pl.l[i].b)))==0)
                {
                    b=1;
                    
                    if (u.b<pl.l[i].a)
                    {
                        puts("0");
                        return 0;
                    }
                    if (pl.l[i].b<u.a)
                    {
                        puts("0");
                        return 0;
                    }
                    if (u.a<pl.l[i].a)
                    {
                        seg.a=pl.l[i].a;
                    }
                    else 
                    {
                        seg.a=u.a;
                    }
                    if (pl.l[i].b<u.b)
                    {
                        seg.b=pl.l[i].b;
                    }
                    else 
                    {
                        seg.b=u.b;
                    }
                }
                
            }
            else 
                {
                    

                    st.insert(u.crosspoint(pl.l[i]));
                }
            
        }
        if (!b&&st.size()==0)
        {
            puts("0");
            continue;
        }
        

        if (!b)
        {
        

        set<point>::iterator ptr=st.begin();
        if (st.size()==2)
        {
            
            

            {
                seg.a=*ptr;
                ++ptr;
                seg.b=*ptr;
            }
        }
        else 
        {
            

            seg.a=*ptr;
            seg.b=*ptr;
        }
        }
        if (n==187)
        {
        

        

        }
            cout<<count(seg)<<endl;
    }
    return 0;
}
        
    