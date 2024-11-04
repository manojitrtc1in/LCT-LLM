




































using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
inline double sqr(double x){return x*x;}
const int maxp=4001111;
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
    bool operator==(point a)const
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len()
    {
        return hypot(x,y);
    }
    double len2()
    {
        return x*x+y*y;
    }
    double distance(point p)
    {
        return hypot(x-p.x,y-p.y);
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
		double l=len();
		if (!dblcmp(l))return *this;
		r/=l;
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
    double angle()

	{
		double k=atan2(b.y-a.y,b.x-a.x);
		if (dblcmp(k)<0)k+=pi;
		if (dblcmp(k-pi)==0)k-=pi;
		return k;
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
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p)
    {
    	point q=lineprog(p);
    	return point(2*q.x-p.x,2*q.y-p.y);
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
    circle(point a,point b,point c,bool t)

    {
    	line u,v;
    	double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
    	u.a=a;
		u.b=u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	v.a=b;
    	m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
    	v.b=v.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	p=u.crosspoint(v);
    	r=line(a,b).dispointtoseg(p);
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
    bool operator==(circle v)
    {
    	return ((p==v.p)&&dblcmp(r-v.r)==0);
    }
    bool operator<(circle v)const
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
    

    

    

    int relation(point b)
    {
        double dst=b.distance(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationseg(line v)
    {
        double dst=v.dispointtoseg(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationline(line v)
    {
        double dst=v.dispointtoline(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    

    int getcircle(point a,point b,double r,circle&c1,circle&c2)
    {
        circle x(a,r),y(b,r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r;
        return t;
    }
    

    int getcircle(line u,point q,double r1,circle &c1,circle &c2)
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
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
		circle cc=circle(q,r1);
    	point p1,p2;
    	if (!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
    	c1=circle(p1,r1);
    	if (p1==p2)
		{
			c2=c1;return 1;
    	}
    	c2=circle(p2,r1);
    	return 2;
	}
	

    int getcircle(line u,line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4)
    {
    	if (u.parallel(v))return 0;
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
    	line v1=line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
    	line v2=line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
    	c1.r=c2.r=c3.r=c4.r=r1;
    	c1.p=u1.crosspoint(v1);
    	c2.p=u1.crosspoint(v2);
    	c3.p=u2.crosspoint(v1);
    	c4.p=u2.crosspoint(v2);
    	return 4;
	}
	

	int getcircle(circle cx,circle cy,double r1,circle&c1,circle&c2)
    {
        circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r1;
        return t;
    }
    int pointcrossline(line v,point &p1,point &p2)

    {
        if (!(*this).relationline(v))return 0;
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
    

    int tangentline(point q,line &u,line &v)
    {
    	int x=relation(q);
    	if (x==2)return 0;
    	if (x==1)
    	{
    		u=line(q,q.add(q.sub(p).rotleft()));
    		v=u;
    		return 1;
    	}
    	double d=p.distance(q);
    	double l=sqr(r)/d;
    	double h=sqrt(sqr(r)-sqr(l));
    	u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
    	v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
    	return 2;
	}
    double areacircle(circle v)
    {
    	int rel=relationcircle(v); 
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
    double areatriangle(point a,point b)
    {
        if (dblcmp(p.sub(a).det(p.sub(b))==0))return 0.0;
        point q[5];
        int len=0;
        q[len++]=a;
        line l(a,b);
        point p1,p2;
        if (pointcrossline(l,q[1],q[2])==2)
        {
            if (dblcmp(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
            if (dblcmp(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
        }
        q[len++]=b;
        if (len==4&&(dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))swap(q[1],q[2]);
        double res=0;
        int i;
        for (i=0;i<len-1;i++)
        {
            if (relation(q[i])==0||relation(q[i+1])==0)
            {
                double arg=p.rad(q[i],q[i+1]);
                res+=r*r*arg/2.0;
            }
            else 
            {
                res+=fabs(q[i].sub(p).det(q[i+1].sub(p))/2.0);
            }
        }
        return res;
    }
};
struct polygon 
{
    int n;
    point p[maxp];
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
    int getconvex(polygon &convex)
    {
        int i,j,k;
        sort(p,p+n);
        convex.n=n;
        for (i=0;i<min(n,2);i++)
        {
            convex.p[i]=p[i];
        }
        if (n<=2)return n;
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
        return top;
    }
    double getarea()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        return fabs(sum)/2;
    }
    void find(int st,point tri[],circle &c)
    {
    	if (!st)
    	{
    		c=circle(point(0,0),-2);
    	}
    	if (st==1)
    	{
    		c=circle(tri[0],0);
    	}
    	if (st==2)
    	{
    		c=circle(tri[0].add(tri[1]).div(2),tri[0].distance(tri[1])/2.0);
    	}
    	if (st==3)
    	{
    		c=circle(tri[0],tri[1],tri[2]);
    	}
    }
    void solve(int cur,int st,point tri[],circle &c)
    {
    	find(st,tri,c);
    	if (st==3)return;
    	int i;
    	for (i=0;i<cur;i++)
    	{
    		if (dblcmp(p[i].distance(c.p)-c.r)>0)
    		{
    			tri[st]=p[i];
    			solve(i,st+1,tri,c);
    		}
    	}
    }
    circle mincircle()

	{
		random_shuffle(p,p+n);
		point tri[4];
		circle c;
		solve(n,0,tri,c);
	 	return c;
	}
};
polygon pl,con;
int n;
short a[2111][2111];
bool v[2111][2111];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
int xa,ya,x2,y2;
double sc;
void dfs(int x,int y)
{
	if (x<xa||x==xa&&y<ya)
	{
		xa=x;
		ya=y;
	}
	if (x>x2||x==x2&&y>y2)
	{
		x2=x;
		y2=y;
	}	
	++sc;
	v[x][y]=1;
	pl.add(point(x,y));
	for (int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if (xx>0&&xx<=n&&yy>0&&yy<=n&&!v[xx][yy]&&a[xx][yy]==1)dfs(xx,yy);
	}
}
int main()
{
	int i,j,k;
	

	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			
		}
	}
	int rec=0,cc=0;
	for (i=0;i<n;i++)for (j=0;j<n;j++)
	{
		if (!v[i][j]&&a[i][j]==1)
		{
			pl.n=0;
			xa=x2=i;ya=y2=j;sc=0;
			dfs(i,j);
			

			double c=pl.mincircle().area();
			double d=fabs(sc-c);
			if (dblcmp(d/c-0.1)<0)++cc;
			else ++rec;
		}
	}
	printf("%d %d\n",cc,rec);
	return 0;
}
		
				
		
