

























using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;










using namespace std;









struct P
{
    double x, y;
    P(){}
    P(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    P operator - (const P p1){return P(x - p1.x, y - p1.y);}
    P operator + (const P p1){return P(x + p1.x, y + p1.y);}
    P operator / (double r){return P(x / r, y / r);}
    P operator * (double r){return P(x * r, y * r);}
    bool operator == (const P p1)const{return fabs(x-p1.x)<eps && fabs(y-p1.y)<eps;}
    bool operator != (const P p1)const{return fabs(x-p1.x)>eps || fabs(y-p1.y)>eps;}
    bool operator < (const P p1)const{return y < p1.y-eps || y < p1.y+eps && x < p1.x;}
};



double cpr(const P &a,const P &b,const P &c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
double dpr(const P &a,const P &b,const P &c){return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);}



double cpr(const P &a,const P &b){return a.x*b.y-a.y*b.x;}
double dpr(const P &a,const P &b){return a.x*b.x+a.y*b.y;}



double vlen(const P &a){return sqrt(a.x*a.x+a.y*a.y);}
double dis(const P &a, const P &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}



bool over(const P &a, const P &b, const P &c, const P &d)
{
    double p, q;
    p = cpr(a, b, c);
    q = cpr(a, b, d);
    return p>eps && q<-eps || p<-eps && q>eps;
}



bool cross(const P &a, const P &b, const P &c, const P &d)
{
    double p, q;
    p = cpr(a, b, c);
    q = cpr(a, b, d);
    if (!(p>eps && q<-eps || p<-eps && q>eps))
        return 0;
    p = cpr(c, d, a);
    q = cpr(c, d, b);
    return p>eps && q<-eps || p<-eps && q>eps;
}



P its(const P &a, const P &b, const P &c, const P &d)
{
    P ret = a;
    double t =  ((c.x - a.x)*(d.y - c.y) - (c.y - a.y)*(d.x - c.x))/
        ((b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x));
    ret.x += (b.x - a.x) * t;
    ret.y += (b.y - a.y) * t;
    return ret;
}



double angsum(P p[], int n)
{
    double ret = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        P &A = p[i], &B = p[(i+1)%n], &C = p[(i+2)%n];
        tmp = PI - acos(dpr(B, A, C) / dis(A, B) / dis(B, C));
        if (cpr(A, B, C) < 0)
            tmp = -tmp;
        ret += tmp;
    }
    return ret;
}



int id1(P p[], int n)
{
    int s[3] = {1,1,1};
    for (int i = 0; i<n && s[1]|s[2]; i++)
        s[_sign(cpr(p[i], p[(i+1)%n], p[(i+2)%n]))] = 0;
    return s[1]|s[2];
}



int id15(P p[], int n)
{
    int s[3] = {1,1,1};
    for (int i = 0; i<n && s[0] && s[1]|s[2]; i++)
        s[_sign(cpr(p[i], p[(i+1)%n], p[(i+2)%n]))] = 0;
    return s[0] && s[1]|s[2];
}



int id7(P q, P p[], int n)
{
    int s[3] = {1,1,1};
    for (int i = 0; i<n && s[1]|s[2]; i++)
        s[_sign(cpr(p[i], p[(i+1)%n],q))] = 0;
    return s[1]|s[2];
}



int id9(P q, P p[], int n)
{
    int s[3] = {1,1,1};
    for (int i = 0; i<n && s[0] && s[1]|s[2]; i++)
        s[_sign(cpr(p[i], p[(i+1)%n],q))] = 0;
    return s[0] && s[1]|s[2];
}



P id6(int n, P *p)
{
    P ret(0, 0), t;
    double t1 = 0, t2;
    for (int i = 1; i < n - 1; i++)
    {
        if (fabs(t2 = cpr(p[i+1], p[0], p[i])) > eps)
        {
            t.x = (p[0].x + p[i].x + p[i+1].x) /3.0;
            t.y = (p[0].y + p[i].y + p[i+1].y) /3.0;
            ret.x += t.x*t2;
            ret.y += t.y*t2;
            t1 += t2;
        }
    }
    if (fabs(t1) > eps)
        ret.x /= t1, ret.y /= t1;
    return ret;
}







void id3(P &a, P &b, P pol[], int &polcnt, P exch[])
{
    int i, p2 = 0;
    bool now, last = cpr(a, b, pol[polcnt-1]) > -eps;
    for (i = 0; i < polcnt; i++)
    {
        now = cpr(a, b, pol[i]) > -eps;
        if (now ^ last)
            exch[p2++] = its(a, b, pol[i], pol[(i+polcnt-1)%polcnt]);               
        if (now)
            exch[p2++] = pol[i];
        last = now;
    }
    polcnt = p2;
    for (i = 0; i < p2; i++)
        pol[i] = exch[i];
}




P ptoline(P p, P a, P b)
{
    P t = p;
    t.x += a.y - b.y;
    t.y += b.x - a.x;
    return its(p, t, a, b);
}



double id8(const P &p, const P &a, const P &b)
{
    return fabs(cpr(p, a, b)) / dis(a, b);
}



P id4(P p, P a, P b)
{
    P t = p;
    t.x += a.y - b.y;
    t.y += b.x - a.x;
    if (cpr(p,a,t) * cpr(p,b,t) > eps)
        return dis(p,a) < dis(p,b) ? a : b;
    return its(p, t, a, b);
}



double id13(P p, P a, P b)
{
    P t = p;
    t.x += a.y - b.y;
    t.y += b.x - a.x;
    if (cpr(p,a,t) * cpr(p,b,t) > eps)
        return min(dis(p,a), dis(p,b));
    return fabs(cpr(b,p,a)) / dis(a,b);
}



P rotate(P v, P p, double angle, double scale)
{
    P ret = p;
    v.x -= p.x;
    v.y -= p.y;
    p.x = scale * cos(angle);
    p.y = scale * sin(angle);
    ret.x += v.x * p.x - v.y * p.y;
    ret.y += v.x * p.y + v.y * p.x;
    return ret;
}



P id12(P a, P b, P c)
{
    P u1, u2, v1, v2;
    u1.x = (a.x+b.x)/2;
    u1.y = (a.y+b.y)/2;
    u2.x = u1.x-a.y+b.y;
    u2.y = u1.y+a.x-b.x;
    v1.x = (a.x+c.x)/2;
    v1.y = (a.y+c.y)/2;
    v2.x = v1.x-a.y+c.y;
    v2.y = v1.y+a.x-c.x;
    return its(u1, u2, v1, v2);
}



P incenter(P a, P b, P c)
{
    P u1, u2, v1, v2;
    double m, n;
    u1 = a;
    m = atan2(b.y-a.y, b.x-a.x);
    n = atan2(c.y-a.y, c.x-a.x);
    u2.x = u1.x + cos((m+n)/2);
    u2.y = u1.y + sin((m+n)/2);
    v1 = b;
    m = atan2(a.y-b.y, a.x-b.x);
    n = atan2(c.y-b.y, c.x-b.x);
    v2.x = v1.x + cos((m+n)/2);
    v2.y = v1.y + sin((m+n)/2);
    return its(u1, u2, v1, v2);
}



P id11(P a, P b, P c)
{
    P u1, u2, v1, v2;
    u1 = c;
    u2.x = u1.x-a.y+b.y;
    u2.y = u1.y+a.x-b.x;
    v1 = b;
    v2.x = v1.x-a.y+c.y;
    v2.y = v1.y+a.x-c.x;
    return its(u1, u2, v1, v2);
}







P id6(P a, P b, P c)
{
    P ret;
    ret.x = (a.x + b.x + c.x) / 3;
    ret.y = (a.y + b.y + c.y) / 3;
    return ret;
}





P id5(P a, P b, P c)
{
    P u, v;
    double step = fabs(a.x)+fabs(a.y)+fabs(b.x)+fabs(b.y)+fabs(c.x)+fabs(c.y);
    int i, j, k;
    u.x = (a.x+b.x+c.x)/3;
    u.y = (a.y+b.y+c.y)/3;
    while (step > 1e-10)
    {
        for (k = 0; k < 10; step/=2, k++)
            for (i = -1; i <= 1; i++)
                for (j = -1; j <= 1; j++)
                {
                    v.x = u.x + step*i;
                    v.y = u.y + step*j;
                    if (dis(u,a) + dis(u,b) + dis(u,c) > dis(v,a) + dis(v,b) + dis(v,c))
                        u = v;
                }
    }
    return u;
}





void id10(P c, double r, P l1, P l2, P &p1, P &p2)
{
    P p = c;
    p.x += l1.y - l2.y;
    p.y += l2.x - l1.x;
    p = its(p, c, l1, l2);
    double d = dis(p,c), t = sqrt(r*r - d*d) / dis(l1,l2);
    p2.x = p.x + (l2.x-l1.x)*t;
    p2.y = p.y + (l2.y-l1.y)*t;
    p1.x = p.x - (l2.x-l1.x)*t;
    p1.y = p.y - (l2.y-l1.y)*t;
}




void id0(P c1, double r1, P c2, double r2, P &p1, P &p2)
{
    P u, v;
    double t = (1+(r1*r1-r2*r2)/dis(c1,c2)/dis(c1,c2))/2;
    u.x = c1.x + (c2.x-c1.x)*t;
    u.y = c1.y + (c2.y-c1.y)*t;
    v.x = u.x + c1.y - c2.y;
    v.y = u.y - c1.x + c2.x;
    id10(c1, r1, u, v, p1, p2);
}







void find_tp(double a, double b, double c, double &ang1, double &ang2)
{
    double v1, v2;
    v1 = fabs(c) > eps ? atan2(b*c, a*c) : atan2(b, a);
    v2 = acos(fabs(c)/sqrt(a*a+b*b));
    ang1 = v1 - v2;
    ang2 = v1 + v2;
}



void id2(P c1, double r1, P c2, double r2, double &t1, double &t2)
{
    find_tp(c2.x-c1.x, c2.y-c1.y, r1-r2, t1, t2);
}



void id14(P c1, double r1, P c2, double r2, double &t1, double &t2)
{
    find_tp(c2.x-c1.x, c2.y-c1.y, r1+r2, t1, t2);
} 





void make_ch(P *p, P *f, int n, int &top)
{
    top = 0;
    sort(p, p + n);
    for (int i = 0; i < 2*n-1; i++)
    {
        int j = (i < n) ? i : 2*(n-1)-i;
        while (top > 1 && cpr(f[top-2], f[top-1], p[j]) < -eps)
            top--;
        f[top++] = p[j];
    }
    top--;
}





void make_ch(P *p, int *s, int n, int &top)
{
    top = 0;
    sort(p, p + n);
    for (int i = 0; i < 2*n-1; i++)
    {
        int j = (i < n) ? i : 2*(n-1)-i;
        while (top > 1 && cpr(p[s[top-2]], p[s[top-1]], p[j]) < -eps)
            top--;
        s[top++] = j;
    }
    top--;
}










int main() {

    int n;
    double mi = 1e60;
    double mil = 1e60;
    double mal = 1e0;

    

    while(cin>>n) {
        vector<P> v;
        double apf = 2*PI / n;
        double x = 0.0;
        const double TT = 800;
        for(int i=0;i<n;i++) {
            P p;
            p.x = TT*cos(x);
            p.y = TT*sin(x);
            x += apf;
            v.push_back(p);
        }
        const double T = 50;
        vector<P> vp;
        for(int i=0;i<n;i++) {
            P mid = (v[i]+v[(i+1)%n])/2.0;
            mid = mid/vlen(mid);
            P p1 = v[i] + mid*i/T;
            P p2 = v[(i+1)%n] + mid*i/T;
            mid = (v[(i+1)%n] + v[(i+2)%n])/2.0;
            mid = mid/vlen(mid);
            P p3 = v[(i+1)%n] + mid*((i+1)%n)/T;
            P p4 = v[(i+2)%n] + mid*((i+1)%n)/T;
            vp.push_back(its(p1, p2, p3, p4));
        }

        
        bool suc = true;

        for(int i=0;i<sz(vp);i++) {
            double len1 = dis(vp[i], vp[(i+1)%n]);
            mil = min(mil, len1);
            mal = max(mal, len1);
            for(int j=0;j<i;j++){
                double len2 = dis(vp[j], vp[j+1]);
                if(zero(len1-len2)) suc = false;
                mi = min(mi, fabs(len1-len2));
            }
        }
        

        if(suc) {
            for(int i=0;i<n;i++) printf("%.10lf %.10lf\n", vp[i].x, vp[i].y);
        } else {
            puts("No solution");
            

        }
        
    }
    

}