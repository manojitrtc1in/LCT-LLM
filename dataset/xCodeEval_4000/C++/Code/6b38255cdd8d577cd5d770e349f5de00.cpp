#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sz(a) (int)((a).size())
#define fuck() cout<<"--------"<<endl
#define see(x) cout<<#x<<" = "<<x<<endl
#define see2(x,y) cout<<#x<<" = "<<x<<"::"<<#y<<" = "<<y<<endl 
const double pi=3.14159265358979323846;
const int mod=1000000007;
typedef pair<int,int> pii;
const int inf=1e18;
const int N=1e5+5;
double dinf = 1e100;
double eps = 1e-7;
const double PI=3.14159265358979323846264338327950288419716939937510582097;
struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x * c, y * c); }
    PT operator / (double c) const { return PT(x / c, y / c); }
};
double dot(PT p, PT q)
{
    return p.x * q.x + p.y * q.y;
}
double dist2(PT p, PT q)
{
    return dot(p - q, p - q);
}
double dist(PT p, PT q)
{
    return sqrtl(dist2(p, q));
}
double cross(PT p, PT q)
{
    return p.x * q.y - p.y * q.x;
}
double abs2(PT a)
{
    return a.x * a.x + a.y * a.y;
}
double abs(PT a)
{
    return sqrtl(abs2(a));
}
double manhattan(PT a,PT b){
    return fabs(a.x-b.x)+fabs(a.y-b.y);
}
bool SamePoint(PT a,PT b){
    PT p=a-b;
    if(fabs(p.x)>eps or fabs(p.y)>eps)return false;
    return true;
}
ostream &operator<<(ostream &os, const PT &p) {
    return os << "(" << p.x << "," << p.y << ")";
}
void seepoint(PT &p){
    cout<< "(" << p.x << "," << p.y << ")\n";
}


PT RotateCCW90(PT p)
{ 
    return PT(-p.y, p.x); 
}
PT RotateCW90(PT p) 
{ 
    return PT(p.y, -p.x);
}
PT RotateCCW(PT p, double t) 
{
    return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
PT RotateCCWAround(PT pivot,PT pt,double angle){
    PT npt=pt-pivot;
    double nx=npt.x*cos(angle)-npt.y*sin(angle);
    double ny=npt.x*sin(angle)+npt.y*cos(angle);
    PT np={nx,ny};
    npt=np+pivot;
    return npt;
}




PT ProjectPointLine(PT a, PT b, PT c) 
{
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}


PT ProjectPointSegment(PT a, PT b, PT c) 
{
    double r = dot(b - a, b - a);
    if (fabs(r) < eps) return a;
    r = dot(c - a, b - a) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b - a ) * r;
}


double DistancePointSegment(PT a, PT b, PT c) 
{
    return sqrtl(dist2(c, ProjectPointSegment(a, b, c)));
}


double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d)
{ 
    return fabs(a * x + b * y + c * z - d) / sqrtl(a * a + b * b + c * c); 
}


bool LinesParallel(PT a, PT b, PT c, PT d)
{ 
    return fabs(cross(b - a, c - d)) < eps; 
}
bool LinesCollinear(PT a, PT b, PT c, PT d) 
{
    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < eps
            && fabs(cross(c - d, c - a)) < eps;
}




bool SegmentsIntersect(PT a, PT b, PT c, PT d) 
{
    if (LinesCollinear(a, b, c, d)) {
        if (dist2(a, c) < eps || dist2(a, d) < eps ||
                dist2(b, c) < eps || dist2(b, d) < eps) return 1;
        if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
            return 0;
        return 1;
    }
    if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
    if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
    return 1;
}








PT ComputeLineIntersection(PT a, PT b, PT c, PT d) 
{
    b = b - a; d = c - d; c = c - a;
    assert(dot(b, b) > eps && dot(d, d) > eps);
    return a + b * cross(c, d) / cross(b, d);
}


PT ComputeCircleCenter(PT a, PT b, PT c) 
{
    b = (a + b) / 2;
    c = (a + c) / 2;
    return ComputeLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
}














bool PointInPolygon(const vector<PT> &p, PT q) 
{
    bool c = 0;
    for(int i=0;i<p.size();i++)
    {
        int j = (i + 1) % p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
                p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}


bool PointOnPolygon(const vector<PT> &p, PT q) 
{
    for(int i=0;i<p.size();i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < eps)
        return 1;
    return 0;
}




vector<PT> CLIntersection(PT a, PT b, PT c, double r) 
{
    vector<PT> ret;
    b = b - a;
    a = a - c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r * r;
    double D = B * B - A * C;
    if (D < -eps) return ret;
    ret.pb(c + a + b * (-B + sqrtl(D + eps)) / A);
    if (D > eps)
        ret.pb(c + a + b * (-B - sqrtl(D)) / A);
    return ret;
}




vector<PT> CCIntersection(PT a, PT b, double r, double R) 
{
    vector<PT> ret;
    double d = sqrtl(dist2(a, b));
    if (d > r + R || d + min(r, R) < max(r, R)) return ret;
    double x = (d * d - R * R + r * r) / (2 * d);
    double y = sqrtl(r * r - x * x);
    PT v = (b - a) / d;
    ret.pb(a + v * x + RotateCCW90(v)*y);
    if (y > 0)
        ret.pb(a + v * x - RotateCCW90(v)*y);
    return ret;
}








double ComputeSignedArea(const vector<PT> &p) 
{
    double area = 0;
    for(int i=0;i<p.size();i++) {
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area / 2.0;
}
double ComputeArea(const vector<PT> &p) 
{
    return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT> &p) 
{
    PT c(0, 0);
    double scale = 6.0 * ComputeSignedArea(p);
    for(int i=0;i<p.size();i++){
        int j = (i + 1) % p.size();
        c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
    }
    return c / scale;
}


bool IsSimple(const vector<PT> &p) 
{
    for(int i=0;i<p.size();i++) {
        for(int k=i+1;k<p.size();k++) {
            int j = (i + 1) % p.size();
            int l = (k + 1) % p.size();
            if (i == l || j == k) continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
                return 0;
        }
    }
    return 1;
}
bool RayOnPoint(PT a, PT v, PT b) 
{ 

    b = b - a;
    if (abs(b.x * v.y - b.y * v.x) < eps) { 

        if (b.x * v.x >= -eps && b.y * v.y >= -eps) 

            return 1;
        return 0;
    }
    return 0;
}
bool PointOnLine(PT a,PT v,PT b){
    if(LinesCollinear(a,v,v,b))return true;
    return false;
}
int sign(PT a, PT b, PT c) 
{
    return (cross(b - a, c - b) < 0 ? -1 : 1 );
}
double ArcArea(PT a, PT b, PT c, double r) 
{
    double cosa = dot(a - c, b - c) / (abs(a - c) * abs(b - c));
    double ang = acos(cosa);
    if (ang > 2 * PI) ang = 2 * PI - ang;
    return 0.5 * r * r * ang;
}
double TCArea(PT a1, PT a2, PT c, double r) 
{
    double ans = 0;
    double d1 = dist2(a1, c), d2 = dist2(a2, c);
    if (d1 > d2) swap(d1, d2), swap(a1, a2);
    if (d2 <= r * r) {
        ans = 0.5 * abs(cross(a1 - c, a2 - c));
    }
    else if (d1 <= r * r) {
        auto vv = CLIntersection(a1, a2, c, r);
        PT C = vv[0];
        if (vv.size() > 1 && dot(vv[1] - a1, vv[1] - a2) < 0)
            C = vv[1];
        vv = CLIntersection(a2, c, c, r);
        PT D = vv[0];
        if (vv.size() > 1 && dot(vv[1] - a2, vv[1] - c) < 0)
            D = vv[1];
        ans = ArcArea(C, D, c, r) + 0.5 * abs(cross(C - c, a1 - c));
    }
    else {
        auto vv = CLIntersection(a1, a2, c, r);
        if (vv.size() <= 1 || dot(a1 - vv[0], a2 - vv[0]) > 0) {
            ans = ArcArea(a1, a2, c, r);
        }
        else {
            if (dist2(a1, vv[1]) < dist2(a1, vv[0]))
                swap(vv[0], vv[1]);
            ans = ArcArea(a1, vv[0], c, r) + ArcArea(a2, vv[1], c, r) + 0.5 * abs(cross(vv[0] - c, vv[1] - c));
        }
    }
    return abs(ans);
}
double PolyCircArea(vector<PT> &a, PT c, double r) 
{   

    

    int n = a.size();
    if (n <= 2) return 0;
    double ans = 0;
    for(int i=0;i<n;i++)
        ans += TCArea(a[i], a[(i + 1) % n], c, r) * sign(c, a[i], a[(i + 1) % n]);
    return abs(ans);
}
struct line 
{
    double a, b, c;
    line() {}
    line(double A, double B, double C) {
        a = A, b = B, c = C;
    }
};
bool areParallel(line l1, line l2) 
{
    return fabs(l1.a - l2.a) < eps && fabs(l1.b - l2.b) < eps;
}
bool areSame(line l1, line l2) 
{
    return areParallel(l1, l2) && fabs(l1.c - l2.c) < eps;
}
struct Circle : PT {
    double r;
    Circle() {}
    Circle(PT c, double r) : PT(c.x, c.y),
        r(r) {}
    bool strictContains(PT p) {
        return dist2((*this), p) < r * r;
    }
    bool onBorder(PT p) {
        return abs(dist2((*this), p) - r * r) < eps;
    }
    bool contains(PT p) {
        return strictContains(p) || onBorder(p);
    }
};
#define sqr(x) ((x) * (x))




void tangents(PT c, double r1, double r2,vector<line> & ans) 
{
    double r = r2 - r1;
    double z = sqr(c.x) + sqr(c.y);
    double d = z - sqr(r);
    if (d < -eps) return;
    d = sqrt(fabs(d));
    line l((c.x * r + c.y * d) / z, (c.y * r - c.x * d) / z, r1);
    ans.push_back(l);
}


vector<line> tangents(Circle a, Circle b) { 

    vector<line> ans; ans.clear();
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2)
            tangents(b - a, a.r * i, b.r * j, ans);
    for (int i = 0; i < ans.size(); ++i)
        ans[i].c -= ans[i].a * a.x + ans[i].b *
                    a.y;
    vector<line> ret;
    for (int i = 0; i < (int) ans.size(); ++i) {
        bool ok = true;
        for (int j = 0; j < i; ++j)
            if (areSame(ret[j], ans[i])) {
                ok = false;
                break;
            }
        if (ok) ret.push_back(ans[i]);
    }
    return ret;
}
int isOrthogonal(PT &a, PT &b, PT &c)
{
    return fabs((b.x-a.x) * (b.x-c.x) + (b.y-a.y) * (b.y-c.y))<eps;
}



int isRectangle(PT &a, PT &b, PT &c, PT &d)
{
    return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
}



int isRectangleAnyOrder(PT &a, PT &b, PT &c, PT &d)
{
    return isRectangle(a, b, c, d) || isRectangle(b, c, a, d) | isRectangle(c, a, b, d);
}



int isSquare(PT &a, PT &b, PT &c, PT &d)
{
    return isRectangle(a, b, c, d) && fabs(dist2(a, b)-dist2(b, c))<eps;
}



int isSquareAnyOrder(PT &a, PT &b, PT &c, PT &d)
{
    return isSquare(a, b, c, d) || isSquare(b, c, a, d) | isSquare(c, a, b, d);
}
void __solve(){
    cout<<fixed<<setprecision(15);
    double n,r;
    cin>>n>>r;
    double a0=(PI/n),a1=(PI/(2*n));
    double area=r*r*tan(a0)*tan(a1);
    area/=(tan(a0)+tan(a1));
    area*=n;
    cout<<area;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int T=1;
    

    while(T--){
        __solve();
        cout<<endl;
    }
}