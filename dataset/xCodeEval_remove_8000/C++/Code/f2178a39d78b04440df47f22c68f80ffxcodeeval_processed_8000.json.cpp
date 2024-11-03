

using namespace std;






















































int dblcmp(double d)
{
    if (fabs(d)<eps)
        return 0;
    return d>eps?1:-1;
}

const int maxp=1111;



struct point
{
    double x,y;
    point()                     {                                }
    point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    void output()
    {
        printf("%.2f %.2f\n", x, y);
    }

    bool operator == (point a) const
    {
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }

    bool operator < (point a) const
    {
        return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
    }

    point operator - (point a) const
    {
        return point(x - a.x, y - a.y);
    }

    double len()
    {
        return hypot(x, y);
    }
    double len2()
    {
        return x * x + y * y;
    }
    double distance(point p)
    {
        return hypot(x - p.x, y - p.y);
    }
    point add(point p)
    {
        return point(x + p.x, y + p.y);
    }
    point sub(point p)
    {
        return point(x - p.x, y - p.y);
    }
    point mul(double b)
    {
        return point(x * b, y * b);
    }
    point div(double b)
    {
        return point(x / b, y / b);
    }
    double dot(point p)
    {
        return x * p.x + y * p.y;
    }
    double det(point p)
    {
        return x * p.y - y * p.x;
    }

    double rad(point a, point b)
    {
        point p = *this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))), a.sub(p).dot(b.sub(p))));
    }

    point trunc(double r)
    {
        double l = len();
        if(!dblcmp(l))
            return *this;
        r /= l;
        return point(x*r, y*r);
    }

    point rotleft()
    {
        return point(-y, x);
    }
    point rotright()
    {
        return point(y, -x);
    }

    point rotate(point p, double angle)
    {
        point v = this->sub(p);
        double c = cos(angle), s = sin(angle);
        return point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};



struct line
{
    point a,b;
    line()                      {                 }
    line(point _a,point _b)
    {
        a = _a;
        b = _b;
    }

    bool operator == (line v)
    {
        return (a == v.a) && (b == v.b);
    }

    line(point p, double angle)
    {
        a = p;
        if (dblcmp(angle - pi/2) == 0)
            b = a.add(point(0,1));
        else
            b = a.add(point(1, tan(angle)));
    }
    

    line(double _a,double _b,double _c)
    {
        if(dblcmp(_a) == 0)
        {
            a = point(0, -_c/_b);
            b = point(1, -_c/_b);
        }
        else if (dblcmp(_b) == 0)
        {
            a = point(-_c/_a, 0);
            b = point(-_c/_a, 1);
        }
        else
        {
            a = point(0, -_c/_b);
            b = point(1, (-_c-_a)/_b);
        }
    }

    void input()
    {
        a.input();
        b.input();
    }
    void adjust()
    {
        if(b < a)
            swap(a,b);
    }
    double length()
    {
        return a.distance(b);
    }

    double angle()
    {
        double k = atan2(b.y - a.y, b.x - a.x);
        if (dblcmp(k) < 0)
            k+=pi;
        if (dblcmp(k-pi) == 0)
            k-=pi;
        return k;
    }

    int relation(point p)
    {
        int c = dblcmp(p.sub(a).det(b.sub(a)));
        if (c < 0)
            return 1;
        if (c > 0)
            return 2;
        return 3;
    }

    bool pointonseg(point p)
    {
        return dblcmp(p.sub(a).det(b.sub(a))) == 0 && dblcmp(p.sub(a).dot(p.sub(b))) <= 0;
    }

    bool parallel(line v)
    {
        return dblcmp(b.sub(a).det(v.b.sub(v.a))) == 0;
    }

    int segcrossseg(line v)
    {
        int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3 = dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4 = dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if((d1^d2) == -2 && (d3^d4) == -2)
            return 2;
        return (d1 == 0 && dblcmp(v.a.sub(a).dot(v.a.sub(b))) <= 0 ||
                d2 == 0 && dblcmp(v.b.sub(a).dot(v.b.sub(b))) <=0 ||
                d3 == 0 && dblcmp(a.sub(v.a).dot(a.sub(v.b))) <=0 ||
                d4 == 0 && dblcmp(b.sub(v.a).dot(b.sub(v.b))) <=0);
    }

    int segcrossseg_inside(line v)
    {
        if(v.pointonseg(a) || v.pointonseg(b) || pointonseg(v.a) || pointonseg(v.b))
            return 0;
        int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3 = dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4 = dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if((d1^d2) == -2 && (d3^d4) == -2)
            return 1;
        return (d1 == 0 && dblcmp(v.a.sub(a).dot(v.a.sub(b))) <= 0 ||
                d2 == 0 && dblcmp(v.b.sub(a).dot(v.b.sub(b))) <= 0 ||
                d3 == 0 && dblcmp(a.sub(v.a).dot(a.sub(v.b))) <= 0 ||
                d4 == 0 && dblcmp(b.sub(v.a).dot(b.sub(v.b))) <= 0);
    }

    int linecrossseg(line v)    

    {
        int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
        if((d1^d2) == -2)
            return 2;
        return (d1 == 0 || d2 == 0);
    }

    int linecrossline(line v)
    {
        if ((*this).parallel(v))
            return v.relation(a) == 3;
        return 2;
    }

    point crosspoint(line v)
    {
        double a1 = v.b.sub(v.a).det(a.sub(v.a));
        double a2 = v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x * a2 - b.x * a1) / (a2 - a1), (a.y * a2 - b.y * a1)/(a2 - a1));
    }

    double dispointtoline(point p)
    {
        return fabs(p.sub(a).det(b.sub(a))) / length();
    }

    double dispointtoseg(point p)
    {
        if (dblcmp(p.sub(b).dot(a.sub(b))) < 0 || dblcmp(p.sub(a).dot(b.sub(a))) < 0)
            return min(p.distance(a), p.distance(b));
        return dispointtoline(p);
    }

    point lineprog(point p)
    {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a)) / b.sub(a).len2()));
    }

    point symmetrypoint(point p)
    {
        point q = lineprog(p);
        return point(2*q.x - p.x, 2*q.y - p.y);
    }
};



struct circle
{
    point p;
    double r;
    circle() {}
    circle(point _p,double _r): p(_p),r(_r) {};
    circle(double x,double y,double _r):p(point(x,y)),r(_r) {};

    circle(point a,point b,point c)
    {
        p = line(a.add(b).div(2), a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(line(c.add(b).div(2), c.add(b).div(2).add(b.sub(c).rotleft())));
        r = p.distance(a);
    }

    circle(point a,point b,point c, bool t)
    {
        line u,v;
        double m = atan2(b.y - a.y,b.x - a.x), n = atan2(c.y - a.y,c.x - a.x);
        u.a = a;
        u.b = u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
        v.a = b;
        m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
        v.b = v.a.add(point(cos((n+m)/2), sin((n+m)/2)));
        p = u.crosspoint(v);
        r = line(a,b).dispointtoseg(p);
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

    bool operator == (circle v)
    {
        return ((p == v.p) && dblcmp(r - v.r) == 0);
    }

    bool operator < (circle v) const
    {
        return ((p < v.p) || (p == v.p) && dblcmp(r - v.r) < 0);
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
        double dst = b.distance(p);
        if (dblcmp(dst-r) <  0)
            return 2;
        if (dblcmp(dst-r) == 0)
            return 1;
        return 0;
    }

    int relationseg(line v)
    {
        double dst = v.dispointtoseg(p);
        if (dblcmp(dst-r) <  0)
            return 2;
        if (dblcmp(dst-r) == 0)
            return 1;
        return 0;
    }

    int relationline(line v)
    {
        double dst = v.dispointtoline(p);
        if (dblcmp(dst-r) <  0)
            return 2;
        if (dblcmp(dst-r) == 0)
            return 1;
        return 0;
    }

    int getcircle(point a, point b, double r, circle &c1, circle &c2)
    {
        circle x(a,r), y(b,r);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if(!t)
            return 0;
        c1.r = c2.r = r;
        return t;
    }

    int getcircle(line u, point q, double r1, circle &c1, circle &c2)
    {
        double dis = u.dispointtoline(q);
        if (dblcmp(dis - r1*2) > 0)
            return 0;
        if (dblcmp(dis) == 0)
        {
            c1.p = q.add(u.b.sub(u.a).rotleft().trunc(r1));
            c2.p = q.add(u.b.sub(u.a).rotright().trunc(r1));
            c1.r = c2.r = r1;
            return 2;
        }
        line u1 = line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
        line u2 = line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
        circle cc = circle(q,r1);
        point p1,p2;

        if (!cc.pointcrossline(u1,p1,p2))
            cc.pointcrossline(u2,p1,p2);

        c1=circle(p1,r1);
        if (p1==p2)
        {
            c2=c1;
            return 1;
        }

        c2 = circle(p2,r1);
        return 2;
    }

    int getcircle(line u, line v, double r1, circle &c1, circle &c2, circle &c3, circle &c4)
    {
        if(u.parallel(v))
            return 0;
        line u1 = line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)), u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
        line u2 = line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)), u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
        line v1 = line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)), v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
        line v2 = line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)), v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
        c1.r = c2.r = c3.r = c4.r = r1;
        c1.p = u1.crosspoint(v1);
        c2.p = u1.crosspoint(v2);
        c3.p = u2.crosspoint(v1);
        c4.p = u2.crosspoint(v2);
        return 4;
    }

    int getcircle(circle cx, circle cy, double r1, circle &c1, circle &c2)
    {
        circle x(cx.p, r1+cx.r), y(cy.p, r1+cy.r);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if(!t)
            return 0;
        c1.r = c2.r = r1;
        return t;
    }

    int pointcrossline(line v,point &p1,point &p2)
    {
        if(!(*this).relationline(v))
            return 0;
        point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r*r-d*d);
        if(dblcmp(d) == 0)
        {
            p1 = p2 = a;
            return 1;
        }
        p1 = a.sub(v.b.sub(v.a).trunc(d));
        p2 = a.add(v.b.sub(v.a).trunc(d));
        return 2;
    }

    
    int relationcircle(circle v)
    {
        double d = p.distance(v.p);
        if (dblcmp(d-r-v.r) >  0)
            return 5;
        if (dblcmp(d-r-v.r) == 0)
            return 4;
        double l = fabs(r-v.r);
        if (dblcmp(d-r-v.r) < 0 && dblcmp(d-l) > 0)
            return 3;
        if (dblcmp(d-l) == 0)
            return 2;
        if (dblcmp(d-l) < 0)
            return 1;
    }

    int pointcrosscircle(circle v, point &p1, point &p2)
    {
        int rel = relationcircle(v);
        if (rel == 1 || rel == 5)
            return 0;
        double d = p.distance(v.p);
        double l = (d + (sqr(r) - sqr(v.r)) / d) / 2;
        double h = sqrt(sqr(r) - sqr(l));
        p1 = p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
        p2 = p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
        if (rel == 2 || rel == 4)
            return 1;
        return 2;
    }

    int tangentline(point q, line &u, line &v)
    {
        int x = relation(q);
        if (x == 2)
            return 0;
        if (x == 1)
        {
            u = line(q,q.add(q.sub(p).rotleft()));
            v = u;
            return 1;
        }
        double d = p.distance(q);
        double l = sqr(r)/d;
        double h = sqrt(sqr(r) - sqr(l));
        u = line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
        v = line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
        return 2;
    }
    long double f(long double r, long double theta) {
    return r * r * theta / 2 - r * r * sin(theta) / 2;
    }
    long double areacircle(circle v)
    {
        if((*this)==v) return pi*r*r;
        long double dx = p.x - v.p.x;
        long double dy = p.y - v.p.y;
        long double d = sqrt(dx * dx + dy * dy);
        if (d + min(r, v.r) < max(r, v.r) + eps)
        {
            return min(r, v.r) * min(r, v.r) * pi;
        }
        if (d > r+v.r)
        {
            return 0;
        }
        long double a = (r*r- v.r * v.r) / 2 / d + d / 2;
        long double theta1 = 2 * acos(a / r);
        long double theta2 = 2 * acos((d - a) / v.r);
        return (f(r, theta1) + f(v.r, theta2));
    }

    double areatriangle(point a,point b)
    {
        if(dblcmp(p.sub(a).det(p.sub(b)) == 0))
            return 0.0;
        point q[5];
        int len = 0;
        q[len++] = a;
        line l(a, b);
        point p1, p2;
        if (pointcrossline(l, q[1], q[2]) == 2)
        {
            if(dblcmp(a.sub(q[1]).dot(b.sub(q[1])))<0)
                q[len++]=q[1];
            if(dblcmp(a.sub(q[2]).dot(b.sub(q[2])))<0)
                q[len++]=q[2];
        }
        q[len++] = b;
        if (len == 4 && (dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1]))) > 0))
            swap(q[1],q[2]);
        double res = 0;
        For(i,len-1)
        {
            if(relation(q[i]) == 0 || relation(q[i+1]) == 0)
            {
                double arg = p.rad(q[i],q[i+1]);
                res += r*r*arg/2.0;
            }
            else
                res += fabs(q[i].sub(p).det(q[i+1].sub(p)) / 2.0);
        }
        return res;
    }
};


struct polygon
{
    int n;
    point p[maxp];
    line l[maxp];
    void input(int _n)
    {
        n = _n;
        For(i,n)   p[i].input();
    }
    void add(point q)
    {
        p[n++]=q;
    }
    void getline()
    {
        For(i,n)
        l[i] = line(p[i], p[(i+1)%n]);
    }
    struct cmp
    {
        point p;
        cmp(const point &p0)
        {
            p=p0;
        }
        bool operator() (const point &aa, const point &bb)
        {
            point a = aa, b = bb;
            int d = dblcmp(a.sub(p).det(b.sub(p)));
            if (d == 0)
                return dblcmp(a.distance(p) - b.distance(p)) < 0;
            return d > 0;
        }
    };

    void norm()
    {
        point mi = p[0];
        Fre(i,1,n) mi = min(mi,p[i]);
        sort(p, p+n, cmp(mi));
    }

    void makeConvexPolygonFromN_Points(int N,int M)
    {
        if(M == 3)
        {
            if(N == 3)
            {
                cout << 0 << ' ' << 0 << "\n";
                cout << 0 << ' ' << 1 << "\n";
                cout << 1 << ' ' << 0 << "\n";
                return;
            }

            if(N == 4)
            {
                cout << 0 << ' ' << 0 << "\n";
                cout << 0 << ' ' << 10 << "\n";
                cout << 10 << ' ' << 0 << "\n";
                cout << 1 << ' ' << 1 << "\n";
                return;
            }

            if(N >= 5)
            {
                cout << -1 << "\n";
                return;
            }
        }

        int X = 10000000;
        for(int i=0;i<M;i++) cout << i << ' ' << X+i*i << "\n";
        for(int i=0;i<N-M;i++) cout << i << ' ' << -X-i*i << "\n";
    }

    void getconvex(polygon &convex)
    {
        sort(p, p+n);
        convex.n = n;
        For(i,min(n,2)) convex.p[i] = p[i];
        if (n <= 2)
            return;
        int &top = convex.n;
        top = 1;
        Fre(i,2,n)
        {
            while(top && convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        int temp = top;
        convex.p[++top] = p[n-2];
        for(int i = n-3; i>=0; i--)
        {
            while (top != temp && convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i])) <= 0)
                top--;
            convex.p[++top]=p[i];
        }
    }

    bool isconvex()
    {
        bool s[3];
        memset(s,0,sizeof(s));
        For(i,n)
        {
            int j = (i+1)%n;
            int k = (j+1)%n;
            s[dblcmp(p[j].sub(p[i]).det(p[k].sub(p[i])))+1] = 1;
            if (s[0] && s[2])
                return 0;
        }
        return 1;
    }

    int relationpoint(point q)
    {
        For(i,n)
        if(p[i] == q)
            return 3;

        getline();

        For(i,n)
        if(l[i].pointonseg(q))
            return 2;

        int cnt=0;
        For(i,n)
        {
            int j = (i+1)%n;
            int k = dblcmp(q.sub(p[j]).det(p[i].sub(p[j])));
            int u = dblcmp(p[i].y - q.y);
            int v = dblcmp(p[j].y - q.y);
            if (k > 0 && u < 0 && v >= 0)
                cnt++;
            if (k < 0 && v < 0 && u >= 0)
                cnt--;
        }
        return cnt!=0;
    }

    int relationline(line u)
    {
        int k=0;
        getline();
        For(i,n)
        {
            if (l[i].segcrossseg(u) == 2)
                return 1;
            if (l[i].segcrossseg(u) == 1)
                k=1;
        }
        if(!k)
            return 0;

        vector<point>vp;
        For(i,n)
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
        sort(all(vp));
        int szz=vp.sz;
        For(i,szz-1)
        {
            point mid = vp[i].add(vp[i+1]).div(2);
            if(relationpoint(mid)==1)
                return 1;
        }
        return 2;
    }

    void convexcut(line u, polygon &po)
    {
        int &top = po.n;
        top = 0;
        For(i,n)
        {
            int d1 = dblcmp(p[i].sub(u.a).det(u.b.sub(u.a)));
            int d2 = dblcmp(p[(i+1)%n].sub(u.a).det(u.b.sub(u.a)));
            if (d1 >= 0)
                po.p[top++] = p[i];
            if (d1*d2 < 0)
                po.p[top++] = u.crosspoint(line(p[i], p[(i+1)%n]));
        }
    }

    double getcircumference()
    {
        double sum = 0;
        For(i,n)
        sum += p[i].distance(p[(i+1)%n]);
        return sum;
    }

    double getarea()
    {
        double sum=0;
        For(i,n)
        sum+=p[i].det(p[(i+1)%n]);
        return fabs(sum)/2;
    }

    bool getdir()
    {
        double sum=0;
        For(i,n)
        sum += p[i].det(p[(i+1)%n]);
        if (dblcmp(sum) > 0)
            return 1;
        return 0;
    }

    point getbarycentre()
    {
        point ret(0,0);
        double area = 0;
        Fre(i,1,n)
        {
            double tmp = p[i].sub(p[0]).det(p[i+1].sub(p[0]));
            if(dblcmp(tmp) == 0)
                continue;
            area += tmp;
            ret.x += (p[0].x + p[i].x + p[i+1].x)/3*tmp;
            ret.y += (p[0].y + p[i].y + p[i+1].y)/3*tmp;
        }
        if(dblcmp(area))
            ret = ret.div(area);
        return ret;
    }

    double areaintersection(polygon po) {                     }
    double areaunion(polygon po)
    {
        return getarea() + po.getarea() - areaintersection(po);
    }

    double areacircle(circle c)
    {
        double ans=0;
        For(i,n)
        {
            int j=(i+1)%n;
            if (dblcmp(p[j].sub(c.p).det(p[i].sub(c.p)))>=0)
                ans+=c.areatriangle(p[i],p[j]);
            else
                ans-=c.areatriangle(p[i],p[j]);
        }
        return fabs(ans);
    }

    
    int relationcircle(circle c)
    {
        getline();
        int x=2;
        if(relationpoint(c.p) != 1)
            return 0;
        For(i,n)
        {
            if (c.relationseg(l[i]) == 2)
                return 0;
            if (c.relationseg(l[i]) == 1)
                x=1;
        }
        return x;
    }

    void find(int st, point tri[], circle &c)
    {
        if (!st)
            c = circle(point(0,0),-2);
        if (st==1)
            c = circle(tri[0],0);
        if (st==2)
            c = circle(tri[0].add(tri[1]).div(2),tri[0].distance(tri[1])/2.0);
        if (st==3)
            c = circle(tri[0],tri[1],tri[2]);
    }

    void solve(int cur, int st, point tri[], circle &c)
    {
        find(st,tri,c);
        if (st==3)
            return;
        For(i,cur)
        {
            if (dblcmp(p[i].distance(c.p) - c.r) > 0)
            {
                tri[st] = p[i];
                solve(i,st+1,tri,c);
            }
        }
    }

    circle mincircle()
    {
        random_shuffle(p, p+n);
        point tri[4];
        circle c;
        solve(n,0,tri,c);
        return c;
    }

    int circlecover(double r)
    {
        int ans = 0;
        vector<pair<double,int> >v;
        For(i,n)
        {
            v.clr;
            For(j,n)
            if (i!=j)
            {
                point q = p[i].sub(p[j]);
                double d = q.len();
                if (dblcmp(d-2*r) <= 0)
                {
                    double arg = atan2(q.y,q.x);
                    if (dblcmp(arg) < 0)
                        arg += 2*pi;
                    double t = acos(d/(2*r));
                    v.pb(mp(arg-t+2*pi,-1));
                    v.pb(mp(arg+t+2*pi,1));
                }
            }
            sort(all(v));
            int cur = 0;
            For(j,v.sz)
            {
                if (v[j].second == -1)
                    ++cur;
                else --cur;
                ans = max(ans,cur);
            }
        }
        return ans+1;
    }

    int pointinpolygon(point q)
    {
        if (getdir())
            reverse(p, p+n);
        if (dblcmp(q.sub(p[0]).det(p[n-1].sub(p[0]))) == 0)
        {
            if (line(p[n-1],p[0]).pointonseg(q))
                return n-1;
            return -1;
        }
        int low = 1,high = n-2, mid;
        while(low<=high)
        {
            mid = (low+high)>>1;
            if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0]))) >= 0 && dblcmp(q.sub(p[0]).det(p[mid+1].sub(p[0]))) < 0)
            {
                polygon c;
                c.p[0] = p[mid];
                c.p[1] = p[mid+1];
                c.p[2] = p[0];
                c.n = 3;
                if (c.relationpoint(q))
                    return mid;
                return -1;
            }
            if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0]))) > 0)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }

    double xmult(point a, point b, point c)
    {
        return (b - a).det(c - a);
    }

    int inside_polygon(point q, int on_edge=1)
    {
        point q2;
        int i = 0, cnt;
        while(i<n)
        {
            for(cnt = i = 0, q2.x = rand()+10000, q2.y = rand() + 10000; i<n; i++)
                if( dblcmp(xmult(q,p[i],p[(i+1)%n])) == 0 &&
                        (p[i].x-q.x)*(p[(i+1)%n].x-q.x) < eps &&
                        (p[i].y-q.y)*(p[(i+1)%n].y-q.y) < eps )
                    return on_edge;
                else if( dblcmp(xmult(q,q2,p[i]))==0 )
                    break;
                else if( xmult(q,p[i],q2) * xmult(q,p[(i+1)%n],q2) < -eps &&
                         xmult(p[i],q,p[(i+1)%n]) * xmult(p[i],q2,p[(i+1)%n]) < -eps )
                    cnt++;
        }
        return cnt&1;
    }

    int isdiagonal(int a, int b)
    {

        if(a == b || (a + 1)%n == b || (b + 1)%n == a)
            return 0;
        getline();
        line x(p[a], p[b]);
        For(i,n)
        if(a != i && b != i)
            if(x.pointonseg(p[i]))
                return 0;
        For(i,n)
        if(l[i].segcrossseg_inside(x))
            return 0;
        point y = p[a].add(p[b]).div(2.);
        if(inside_polygon(y, 0) == 0)
            return 0;
        return 1;
    }
};



struct polygons
{
    vector<polygon>p;
    polygons()
    {
        p.clear();
    }
    void clear()
    {
        p.clear();
    }
    void push(polygon q)
    {
        if (dblcmp(q.getarea()))
            p.pb(q);
    }

    vector<pair<double,int> >e;
    void ins(point s, point t, point X, int i)
    {
        double r = fabs(t.x-s.x) > eps ? (X.x-s.x)/(t.x-s.x) : (X.y-s.y)/(t.y-s.y);
        r = min(r,1.0);
        r = max(r,0.0);
        e.pb(mp(r,i));
    }

    double polyareaunion()
    {
        double ans = 0.0;
        For(i,p.sz)
        if (p[i].getdir()==0)
            reverse(p[i].p, p[i].p+p[i].n);
        For(i,p.sz)
        {
            For(k,p[i].n)
            {
                point &s = p[i].p[k], &t = p[i].p[(k+1)%p[i].n];
                if(!dblcmp(s.det(t)))
                    continue;
                e.clr;
                e.pb(mp(0.0,1));
                e.pb(mp(1.0,-1));
                For(j,p.sz)
                {
                    if (i!=j)
                    {
                        For(w,p[j].n)
                        {
                            point a = p[j].p[w], b = p[j].p[(w+1)%p[j].n], c = p[j].p[(w-1+p[j].n)%p[j].n];
                            int c0 = dblcmp(t.sub(s).det(c.sub(s)));
                            int c1 = dblcmp(t.sub(s).det(a.sub(s)));
                            int c2 = dblcmp(t.sub(s).det(b.sub(s)));
                            if(c1*c2 < 0)
                                ins(s,t,line(s,t).crosspoint(line(a,b)),-c2);
                            else if(!c1 && c0*c2 < 0)
                                ins(s,t,a,-c2);
                            else if(!c1 && !c2)
                            {
                                int c3 = dblcmp(t.sub(s).det(p[j].p[(w+2)%p[j].n].sub(s)));
                                int dp = dblcmp(t.sub(s).dot(b.sub(a)));
                                if(dp && c0)
                                    ins(s,t,a,dp>0 ? c0*((j>i)^(c0<0)) : -(c0<0));
                                if(dp && c3)
                                    ins(s,t,b,dp>0 ? -c3*((j>i)^(c3<0)) : c3<0);
                            }
                        }
                    }
                }
                sort(all(e));
                int ct=0;
                double tot=0.0,last;
                For(j,e.sz)
                {
                    if(ct==2)
                        tot += e[j].first - last;
                    ct += e[j].second;
                    last = e[j].first;
                }
                ans += s.det(t)*tot;
            }
        }
        return fabs(ans)*0.5;
    }
};
int main()
{
    polygon p;
    int n,m;
    cin >> n >> m;
    p.makeConvexPolygonFromN_Points(n,m);
    return 0;
}
