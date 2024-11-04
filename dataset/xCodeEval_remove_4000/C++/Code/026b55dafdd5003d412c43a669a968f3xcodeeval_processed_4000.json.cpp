

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e5+5;

const double eps = 1e-8;
const double pi = std::acos(-1.0);



class Point
{
public:
    double x, y;
    Point(){};
    Point(double x, double y):x(x),y(y){};

    static double xmult(const Point &ps, const Point &pe, const Point &po)
    {
        return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
    }
    static double wmult(const Point &ps, const Point &po, const Point &pe)
    {
        return (ps.x - po.x) * (pe.x - po.x) + (pe.y - po.y) * (ps.y - po.y);
    }

    

    

    double operator *(const Point &_Off) const
    {
        return x * _Off.y - y * _Off.x;
    }
    

    Point operator - (const Point &_Off) const
    {
        return Point(x - _Off.x, y - _Off.y);
    }
        

    Point operator + (const Point &_Off) const
    {
        return Point(x + _Off.x, y + _Off.y);
    }
    

    bool operator == (const Point &_Off) const
    {
        return std::fabs(_Off.x - x) < eps && std::fabs(_Off.y - y) < eps;
    }
    

    bool operator != (const Point &_Off) const
    {
        return ((*this) == _Off) == false;
    }
    

    double dis2(const Point &_Off) const
    {
        return (x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y);
    }
    

    double dis(const Point &_Off) const
    {
        return std::sqrt((x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y));
    }
    Point rotate(double theta) {
        

        return Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    }
    void debug() {
        printf("%.8f %.8f\n", x, y);
    }
};



class PVector
{
public:
    Point s, e;

    double a, b, c;


    PVector(){}
    PVector(const Point &s, const Point &e):s(s),e(e){}

    void debug() {
        printf("(%.8f, %.8f) -> (%.8f, %.8f)\n", s.x, s.y, e.x, e.y);
    }
    

    

    double operator *(const Point &_Off) const
    {
        return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
    }
    

    double operator *(const PVector &_Off) const
    {
        return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
    }
    

    bool pton()
    {
        a = s.y - e.y;
        b = e.x - s.x;
        c = s.x * e.y - s.y * e.x;
        return true;
    }

    

    

    

    friend bool operator<(const Point &_Off, const PVector &_Ori)
    {
        return (_Ori.e.y - _Ori.s.y) * (_Off.x - _Ori.s.x)
            < (_Off.y - _Ori.s.y) * (_Ori.e.x - _Ori.s.x);
    }

    friend bool operator>(const Point &_Off, const PVector &_Ori)
    {
        return (_Ori.e.y - _Ori.s.y) * (_Off.x - _Ori.s.x)
             > (_Off.y - _Ori.s.y) * (_Ori.e.x - _Ori.s.x);
    }

    

    bool lhas(const Point &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    

    bool shas(const Point &_Off) const
    {
        return lhas(_Off)
            && _Off.x - std::min(s.x, e.x) > -eps && _Off.x - std::max(s.x, e.x) < eps
            && _Off.y - std::min(s.y, e.y) > -eps && _Off.y - std::max(s.y, e.y) < eps;
    }

    

    

    double dis(const Point &_Off, bool isSegment = false)
    {
        

        pton();

        

        double td = (a * _Off.x + b * _Off.y + c) / sqrt(a * a + b * b);

        

        if(isSegment)
        {
            double xp = (b * b * _Off.x - a * b * _Off.y - a * c) / ( a * a + b * b);
            double yp = (-a * b * _Off.x + a * a * _Off.y - b * c) / (a * a + b * b);
            double xb = std::max(s.x, e.x);
            double yb = std::max(s.y, e.y);
            double xs = s.x + e.x - xb;
            double ys = s.y + e.y - yb;
            if(xp > xb + eps || xp < xs - eps || yp > yb + eps || yp < ys - eps)
                td = std::min(_Off.dis(s), _Off.dis(e));
        }

        return fabs(td);
    }

    

    Point mirror(const Point &_Off) const
    {
        

        Point ret;
        double d = a * a + b * b;
        ret.x = (b * b * _Off.x - a * a * _Off.x - 2 * a * b * _Off.y - 2 * a * c) / d;
        ret.y = (a * a * _Off.y - b * b * _Off.y - 2 * a * b * _Off.x - 2 * b * c) / d;
        return ret;
    }
    

    static PVector ppline(const Point &_a, const Point &_b)
    {
        PVector ret;
        ret.s.x = (_a.x + _b.x) / 2;
        ret.s.y = (_a.y + _b.y) / 2;
        

        ret.a = _b.x - _a.x;
        ret.b = _b.y - _a.y;
        ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
        

        if(std::fabs(ret.a) > eps)
        {
            ret.e.y = 0.0;
            ret.e.x = - ret.c / ret.a;
            if(ret.e == ret. s)
            {
                ret.e.y = 1e10;
                ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
            }
        }
        else
        {
            ret.e.x = 0.0;
            ret.e.y = - ret.c / ret.b;
            if(ret.e == ret. s)
            {
                ret.e.x = 1e10;
                ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
            }
        }
        return ret;
    }

    

    

    bool equal(const PVector &_Off) const
    {
        return lhas(_Off.e) && lhas(_Off.s);
    }
    

    bool parallel(const PVector &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    

    Point crossLPt(PVector _Off)
    {
        

        Point ret = s;
        double t = ((s.x - _Off.s.x) * (_Off.s.y - _Off.e.y) - (s.y - _Off.s.y) * (_Off.s.x - _Off.e.x))
                / ((s.x - e.x) * (_Off.s.y - _Off.e.y) - (s.y - e.y) * (_Off.s.x - _Off.e.x));
        ret.x += (e.x - s.x) * t;
        ret.y += (e.y - s.y) * t;
        return ret;
    }

    

    

    

    bool crossSL(const PVector &_Off) const
    {
        double rs = (*this) * _Off.s;
        double re = (*this) * _Off.e;
        return rs * re < eps;
    }

    

    

    bool isCrossSS(const PVector &_Off) const
    {
        

        

        return (
            (std::max(s.x, e.x) >= std::min(_Off.s.x, _Off.e.x)) &&
            (std::max(_Off.s.x, _Off.e.x) >= std::min(s.x, e.x)) &&
            (std::max(s.y, e.y) >= std::min(_Off.s.y, _Off.e.y)) &&
            (std::max(_Off.s.y, _Off.e.y) >= std::min(s.y, e.y)) &&
            ((PVector(_Off.s, s) * _Off) * (_Off * PVector(_Off.s, e)) >= 0.0) &&
            ((PVector(s, _Off.s) * (*this)) * ((*this) * PVector(s, _Off.e)) >= 0.0)
            );
    }
};

class Polygon
{
public:
    const static long maxpn = 100010;
    Point pt[maxpn];

    int n;


    Point& operator[](int _p)
    {
        return pt[_p];
    }

    

    double area() const
    {
        double ans = 0.0;
        int i;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            ans += pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
        }
        return std::fabs(ans / 2.0);
    }
    

    Point gravity() const
    {
        Point ans;
        ans.x = ans.y = 0.0;
        int i;
        double area = 0.0;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            double tp = pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
            area += tp;
            ans.x += tp * (pt[i].x + pt[nt].x);
            ans.y += tp * (pt[i].y + pt[nt].y);
        }
        ans.x /= 3 * area;
        ans.y /= 3 * area;
        return ans;
    }
    Point centroid() const
    {
        Point ans;
        ans.x = ans.y = 0.0;
        int i;
        double area = 0.0;
        double bx = pt[0].x;
        double by = pt[0].y;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            double tp = (pt[i].x - bx) * (pt[nt].y - by) - (pt[nt].x - bx) * (pt[i].y - by);
            area += tp;
            ans.x += tp * (pt[i].x + pt[nt].x - 2 * bx);
            ans.y += tp * (pt[i].y + pt[nt].y - 2 * by);
        }
        ans.x /= 3 * area;
        ans.y /= 3 * area;
        ans.x += bx;
        ans.y += by;
        return ans;
    }
    

    bool chas(const Point &_Off) const
    {
        double tp = 0, np;
        int i;
        for(i = 0; i < n; i ++)
        {
            np = PVector(pt[i], pt[(i + 1) % n]) * _Off;
            if(tp * np < -eps)
                return false;
            tp = (std::fabs(np) > eps)?np: tp;
        }
        return true;
    }
    

    bool ahas(const Point &_Off) const
    {
        int ret = 0;
        double infv = 1e-10;

        PVector l = PVector(_Off, Point( -infv ,_Off.y));
        for(int i = 0; i < n; i ++)
        {
            PVector ln = PVector(pt[i], pt[(i + 1) % n]);
            if(fabs(ln.s.y - ln.e.y) > eps)
            {
                Point tp = (ln.s.y > ln.e.y)? ln.s: ln.e;
                if(fabs(tp.y - _Off.y) < eps && tp.x < _Off.x + eps)
                    ret ++;
            }
            else if(ln.isCrossSS(l))
                ret ++;
        }
        return (ret % 2 == 1);
    }
    

    Polygon split(PVector _Off)
    {
        

        Polygon ret;
        Point spt[2];
        double tp = 0.0, np;
        bool flag = true;
        int i, pn = 0, spn = 0;
        for(i = 0; i < n; i ++)
        {
            if(flag)
                pt[pn ++] = pt[i];
            else
                ret.pt[ret.n ++] = pt[i];
            np = _Off * pt[(i + 1) % n];
            if(tp * np < -eps)
            {
                flag = !flag;
                spt[spn ++] = _Off.crossLPt(PVector(pt[i], pt[(i + 1) % n]));
            }
            tp = (std::fabs(np) > eps)?np: tp;
        }
        ret.pt[ret.n ++] = spt[0];
        ret.pt[ret.n ++] = spt[1];
        n = pn;
        return ret;
    }

    

    

    

    static bool graham_cmp(const Point &l, const Point &r)

    {
        return l.y < r.y || (l.y == r.y && l.x < r.x);
    }
    Polygon& graham(Point _p[], int _n)
    {
        int i, len;
        std::sort(_p, _p + _n, Polygon::graham_cmp);
        n = 1;
        pt[0] = _p[0], pt[1] = _p[1];
        for(i = 2; i < _n; i ++)
        {
            while(n && Point::xmult(_p[i], pt[n], pt[n - 1]) >= 0){
                n--;
            }
            pt[++ n] = _p[i];
        }
        len = n;
        pt[++ n] = _p[_n - 2];
        for(i = _n - 3; i >= 0; i --)
        {
            while(n != len && Point::xmult(_p[i], pt[n], pt[n - 1]) >= 0)
                n --;
            pt[++ n] = _p[i];
        }
        return (*this);
    }

    

    

    double rotating_calipers()
    {
        int i = 1;
        double ret = 0.0;
        pt[n] = pt[0];
        for(int j = 0; j < n; j ++)
        {
            while(fabs(Point::xmult(pt[j], pt[j + 1], pt[i + 1])) > fabs(Point::xmult(pt[j], pt[j + 1], pt[i])) + eps)
                i = (i + 1) % n;
            

            ret = std::max(ret, std::max(pt[i].dis(pt[j]), pt[i + 1].dis(pt[j + 1])));
        }
        return ret;
    }

    

    

    double rotating_calipers(Polygon &_Off)
    {
        int i = 0;
        double ret = 1e10;

        pt[n] = pt[0];
        _Off.pt[_Off.n] = _Off.pt[0];
        

        while(_Off.pt[i + 1].y > _Off.pt[i].y)
            i = (i + 1) % _Off.n;
        for(int j = 0; j < n; j ++)
        {
            double tp;
            

            while((tp = Point::xmult(pt[j], pt[j + 1], _Off.pt[i + 1]) - Point::xmult( pt[j], pt[j + 1], _Off.pt[i])) > eps)
                i = (i + 1) % _Off.n;
            

            ret = std::min(ret, PVector(pt[j], pt[j + 1]).dis(_Off.pt[i], true));
            ret = std::min(ret, PVector(_Off.pt[i], _Off.pt[i + 1]).dis(pt[j + 1], true));
            if(tp > -eps)

            {
                ret = std::min(ret, PVector(pt[j], pt[j + 1]).dis(_Off.pt[i + 1], true));
                ret = std::min(ret, PVector(_Off.pt[i], _Off.pt[i + 1]).dis(pt[j], true));
            }
        }
        return ret;
    }

    

    

    

    

    static double hpc_pa(const PVector &_Off)
    {
        return atan2(_Off.e.y - _Off.s.y, _Off.e.x - _Off.s.x);
    }
    

    static bool hpc_cmp(const PVector &l, const PVector &r)
    {
        double lp = hpc_pa(l), rp = hpc_pa(r);
        if(fabs(lp - rp) > eps)
            return lp < rp;
        return Point::xmult(l.s, r.e, r.s) < 0.0;
    }
    

    PVector dequeue[maxpn];
    

    

    

    Polygon& halfPanelCross(PVector _Off[], int ln)
    {
        int i, tn;
        n = 0;
        std::sort(_Off, _Off + ln, hpc_cmp);
        

        for(i = tn = 1; i < ln; i ++)
            if(fabs(hpc_pa(_Off[i]) - hpc_pa(_Off[i - 1])) > eps)
                _Off[tn ++] = _Off[i];
        ln = tn;
        int bot = 0, top = 1;
        dequeue[0] = _Off[0];
        dequeue[1] = _Off[1];
        for(i = 2; i < ln; i ++)
        {
            if(dequeue[top].parallel(dequeue[top - 1]) ||
                dequeue[bot].parallel(dequeue[bot + 1]))
                return (*this);
            while(bot < top &&
                Point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), _Off[i].e, _Off[i].s) > eps)
                top --;
            while(bot < top &&
                Point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), _Off[i].e, _Off[i].s) > eps)
                bot ++;
            dequeue[++ top] = _Off[i];
        }

        while(bot < top &&
            Point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), dequeue[bot].e, dequeue[bot].s) > eps)
            top --;
        while(bot < top &&
            Point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), dequeue[top].e, dequeue[top].s) > eps)
            bot ++;
        

        if(top <= bot + 1)
            return (*this);
        for(i = bot; i < top; i ++)
            pt[n ++] = dequeue[i].crossLPt(dequeue[i + 1]);
        if(bot < top + 1)
            pt[n ++] = dequeue[bot].crossLPt(dequeue[top]);
        return (*this);
    }
};

template<typename Ty>
bool id1(Ty &x)
{
    char ch; bool neg=false;
    for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
        if(ch=='-')
            neg=true;
        else if(ch==-1)return false;
    for(x=0;'0'<=ch&&ch<='9';ch=getchar())
        x=(x<<1)+(x<<3)+ch-'0';
    if(neg) x=-x;
    return true;
}

Polygon N,M;
int n,m;
Point p[maxn],q[maxn];
double f[4*maxn],f2[2*maxn];
int nex[2*maxn];
void id0()
{
    int i,j;
    nex[0] = j = -1;
    i = 0;
    while(i < n)
    {
        while(j!=-1&&fabs(f2[j]-f2[i])>eps)

            j = nex[j];
        nex[++i] = ++j;
    }
}
bool kmp()
{
    int i,j;
    i = j = 0;
    while(i < 2*n&&j<n)
    {
        while(j!=-1&&fabs(f[i]-f2[j])>eps)
        {
            j = nex[j];
        }
        i++;
        j++;
    }
    if(j == n)
        return 1;

    return 0;

}

int main(){
    
    freopen("D:\\in.txt","r",stdin);
    

    int i,j,a,b;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        p[i]=Point(a,b);
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        q[i]=Point(a,b);
    }
    N.graham(p,n);
    M.graham(q,m);
    n = N.n;
    m = M.n;
    if(n!=m){
        printf("NO");
        return 0;
    }
    for(i=0;i<n;i++){
        int st = (i+1)%n,ft = (i+n-1)%n;
        f[i*2]=N[i].dis2(N[st]);
        f[i*2+1]=Point::wmult(N[ft],N[i],N[st]);
        f[i*2+n*2]=f[i*2];
        f[i*2+1+n*2]=f[i*2+1];
        f2[i*2]=M[i].dis2(M[st]);
        f2[i*2+1]=Point::wmult(M[ft],M[i],M[st]);
    }
    n *= 2;

    id0();
    if(kmp())printf("Yes");
    else printf("No");
}
