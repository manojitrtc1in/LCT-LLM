
























using namespace std;


















































typedef     long long ll;
typedef     unsigned long long ull;
typedef     pair<int, int>      pii;
typedef     pair<ll, ll>        pll;

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;






































const long double INF = 1e100;
const long double EPS = 1e-9;

int EQ(long double x)
{
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

struct PT
{
    long double x, y;
    PT() {}
    PT(long double x, long double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (long double c) const
    {
        return PT(x*c, y*c);
    }
    PT operator / (long double c) const
    {
        return PT(x/c, y/c);
    }

    bool operator<(const PT & p)const
    {
        if(x==p.x) return y<p.y;
        return x<p.x;
    }
};

long double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
long double id13(PT p, PT q)
{
    return dot(p-q, p-q);
}
long double id16(PT p, PT q)
{
    return sqrt(dot(p-q, p-q));
}
long double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}




PT id10(PT p)
{
    return PT(-p.y,p.x);
}

PT id15(PT p)
{
    return PT(p.y,-p.x);
}

PT id5(PT p, long double theta)
{
    return PT(p.x*cos(theta)-p.y*sin(theta), p.x*sin(theta)+p.y*cos(theta));
}
PT RotateCW(PT p, long double theta)
{
    return PT(p.x*cos(theta)+p.y*sin(theta), -p.x*sin(theta)+p.y*cos(theta));
}




PT id1(PT a, PT b, long double d)
{
    return a+(((b-a)/sqrt(dot(b-a,b-a)))*d);
}




PT id25(PT a, PT b, PT c)
{
    return a+(b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}




PT id22(PT a, PT b, PT c)
{
    long double r=dot(b-a,b-a);

    if(fabs(r)<EPS) return a;

    r=dot(c-a, b-a)/r;

    if(r<0) return a;
    if(r>1) return b;

    return a+(b-a)*r;
}




long double id3(PT a, PT b, PT c)
{
    return id16(c, id22(a, b, c));
}




long double id17(PT p, PT A, PT B)
{
    long double scale=dot(p-A,B-A)/dot(B-A,B-A);

    PT c;
    c.x=A.x+scale*(B.x-A.x);
    c.y=A.y+scale*(B.y-A.y);

    return id16(p, c);
}




long double id2(PT p, PT A, PT B)
{
    PT c;
    if(dot(B-A,p-A)<EPS) return id16(p, A);
    if(dot(A-B,p-B)<EPS) return id16(p, B);

    return id17(p, A, B);
}




bool id9(PT p, PT a, PT b)
{
    if(fabs(cross(p-b,a-b))<EPS)
    {
        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
        return true;
    }

    return false;
}




bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return fabs(cross(b-a, c-d))<EPS;
}




bool id18(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c))<EPS && fabs(cross(c-d, c-a))<EPS;
}






bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
    if(id18(a, b, c, d))
    {
        if(id13(a, c)<EPS || id13(a, d)<EPS || id13(b, c)<EPS || id13(b, d)<EPS) return true;
        if(dot(c-a, c-b)>0 && dot(d-a, d-b)>0 && dot(c-b, d-b)>0) return false;
        return true;
    }

    if(cross(d-a, b-a)*cross(c-a, b-a)>0) return false;
    if(cross(a-c, d-c)*cross(b-c, d-c)>0) return false;

    return true;
}




PT id14(PT a, PT b, PT c, PT d)
{
    long double a1=a.y-b.y;
    long double b1=b.x-a.x;
    long double c1=cross(a, b);
    long double a2=c.y-d.y;
    long double b2=d.x-c.x;
    long double c2=cross(c, d);
    long double D=a1*b2-a2*b1;

    return PT((b1*c2-b2*c1)/D, (c1*a2-c2*a1)/D);
}




PT id20(PT a, PT b, PT c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    return id14(b, b+id15(a-b), c, c+id15(a-c));
}




bool id12(const vector<PT>p, PT q)
{
    int s=p.size();
    for(int i=0, j=s-1; i<s; j=i++)
    {
        if(id9(q, p[j], p[i])) return true;
    }

    return false;
}







bool id24(const vector<PT>p, PT q)
{
    bool c=0;
    int s=p.size();

    for(int i=0,j=s-1; i<s; j=i++)
    {
        if(((p[i].y>q.y)!=(p[j].y>q.y))&&(q.x<p[i].x+(p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y))) c=!c;
    }

    return c;
}




vector<PT> id7(PT a, PT b, PT c, long double r)
{
    vector<PT>ret;
    b=b-a;
    a=a-c;

    long double A=dot(b, b);
    long double B=dot(a, b);
    long double C=dot(a, a)-r*r;
    long double D=B*B-A*C;

    if(D<-EPS) return ret;

    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);

    if(D>EPS) ret.push_back(c+a+b*(-B-sqrt(D))/A);

    return ret;
}




vector<PT> id11(PT c1, PT c2, long double r1, long double r2)
{
    vector<PT>ret;

    long double d=id16(c1, c2);
    if(d>r1+r2 || d+min(r1, r2)<max(r1, r2)) return ret;

    long double x=(d*d-r2*r2+r1*r1)/(2.0*d);
    long double y=sqrt(r1*r1-x*x);

    PT v=(c2-c1)/d;

    ret.push_back(c1+v*x+id10(v)*y);
    if(y>0) ret.push_back(c1+v*x-id10(v)*y);

    return ret;
}




long double id8(const vector<PT>p)
{
    long double area=0.0;
    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }

    return area/2.0;
}

long double ComputeArea(const vector<PT>p)
{
    return fabs(id8(p));
}




PT id21(const vector<PT>p)
{
    PT c=PT(0.0,0.0);
    long double scale=6.0*id8(p);

    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%p.size();
        c=c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
    }

    return c/scale;
}




bool IsSimple(const vector<PT>p)
{
    for(int i=0; i<p.size(); i++)
    {
        for(int k=i+1; k<p.size(); k++)
        {
            int j=(i+1)%p.size();
            int l=(k+1)%p.size();

            if(i==l || j==k) continue;

            if(SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
        }
    }

    return true;
}





pair<PT,PT> id4(PT a, PT b, long double d)
{
    return make_pair(id1(a, id10(b-a)+a, d), id1(b, id15(a-b)+b, d));
}




pair<PT,PT> id23(PT a, PT b, PT c)
{
    return make_pair(id10(a-c)+c,id10(b-c)+c);
}

vector<PT>id0(vector<PT>poly, pair<PT,PT>ln)
{
    vector<PT>ret;
    int s=poly.size();
    for(int i=0; i<s; i++)
    {
        long double c1=cross(ln.second-ln.first, poly[i]-ln.first);
        long double c2=cross(ln.second-ln.first, poly[(i+1)%s]-ln.first);

        if(EQ(c1)>=0) ret.push_back(poly[i]);
        if(EQ(c1*c2)<0)
        {
            if(!LinesParallel(poly[i], poly[(i+1)%s], ln.first, ln.second))
            {
                ret.push_back(id14(poly[i], poly[(i+1)%s], ln.first, ln.second));
            }
        }
    }

    return ret;
}





long double id6(long double x, long double y, long double z, long double a, long double b, long double c, long double d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

int orientation(PT p, PT q, PT r)
{
    long double val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if (val==0.0) return 0;
    else if (val>0.0 ) return 1;
    else return -1;
}

vector<PT> id19(vector<PT>vec)
{
    sort(full(vec));

    PT p1, p2;
    stack<PT>low;
    stack<PT>up;

    for(int i=0; i<sz(vec); i++)
    {
        while(sz(low)>=2)
        {
            p2=low.top();
            low.pop();
            p1=low.top();
            if(orientation(p1, p2, vec[i] )<0)
            {
                low.push(p2);
                break;
            }
        }
        low.push(vec[i]);
    }

    for(int i=sz(vec)-1; i>=0; i--)
    {
        while(sz(up)>=2)
        {
            p2=up.top();
            up.pop();
            p1=up.top();
            if(orientation(p1, p2, vec[i])<0)
            {
                up.push(p2);
                break;
            }
        }
        up.push(vec[i]);
    }
    low.pop();
    up.pop();

    vector<PT>ret;

    while(!up.empty())
    {
        ret.pb(up.top());
        up.pop();
    }
    while(!low.empty())
    {
        ret.pb(low.top());
        low.pop();
    }
    reverse(full(ret));

    return ret;
}

int main()
{
    PT p, v;
    long double a, b, c, d;

    while(cin>>p.x>>p.y>>v.x>>v.y>>a>>b>>c>>d)
    {
        PT ans[10];

        ans[1] = id1(p, p+v, b);

        pair< PT, PT > ln = id23(p, p+v, p);

        ans[2] = id1(ln.first, ln.second, a/2.0);
        ans[7] = id1(ln.first, ln.second, -a/2.0);
        ans[3] = id1(ln.first, ln.second, c/2.0);
        ans[6] = id1(ln.first, ln.second, -c/2.0);

        PT temp = id1(p, p+v, -d);

        pair< PT, PT > ln2 = id23(temp, p, temp);

        ans[4] = id1(ln2.first, ln2.second, c/2.0);
        ans[5] = id1(ln2.first, ln2.second, -c/2.0);


        for(int i=1; i<=7; i++) cout<<fixed<<setprecision(15)<<ans[i].x<<" "<<ans[i].y<<endl;
    }

    return 0;
}


