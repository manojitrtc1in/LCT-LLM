
#include <bits/stdc++.h>


#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define rep(i, a, b) for(int i = a; i <= b; ++ i)
#define repo(i, a, b) for(int i = a; i >= b; -- i)
#define vaia vector<int> a(n + 1); rep(i, 1, n) cin >> a[i];#define Inv(x) quick_pow(x, mod - 2)
#define Polynomial vector<ll>
#define DEBUG(x, y) cout << (x) << ": " << (y) << '\n';
#define mem(a, x) memset(a, x, sizeof(a))
#define right_1_pos(x) __builtin_ffs(x)
#define left_0_num(x) __builtin_clz(x)
#define right_0_num(x) __builtin_ctz(x)
#define num_of_1(x) __builtin_popcount(x)
#define mp_(x, y) make_pair(x, y)
#define all(v) (v).begin(), (v).end()
using i16 = short;
using ll = long long;
using ull = unsigned long long;


using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
#define fi first
#define se second
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> tr;



namespace StandardIO {
    template<typename T> inline void read(T &x) {
        int mod = 19260817;
        x = 0; T f = 1;
        char c = getchar();
        for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = -1;
        for (; c >= '0' && c <= '9'; c = getchar()) x = (x * 10 % mod + c - '0') % mod;
        x = x * f % mod;
    }

    template<typename T> inline void write(T x) {
        if (x < 0) putchar('-'), x *= -1;
        if (x >= 10) write(x / 10);
        putchar(x % 10 + '0');
    }
}
using namespace StandardIO;


namespace BASIC_MATH {


    const ll mod = 1e9 + 7;
    const ld eps = 1e-6; 

    const ld pi = acos(-1.0);
    const int inf = 0x3f3f3f3f;
    const int maxp = 1000;


    ll mul(ll a, ll b) { ll z = (long double) a / mod * b; ll res = (unsigned long long) a * b - (unsigned long long) z * mod; return (res + mod) % mod; }
    

    inline ll quick_pow(ll ans, ll p, ll res = 1) {
        for(; p; p >>= 1, ans = mul(ans, ans) % mod)
            if(p & 1) res = mul(res, ans) % mod;
        return res % mod;
    }
    double gcd(double a,double b) {
        if(fabs(b) < eps) return a;
        if(fabs(a) < eps) return b;
        return gcd(b, fmod(a,b));
    }
    int gcd(int a, int b) { return __gcd(a, b); }
    ll gcd(ll a, ll b) { return __gcd(a, b); }


    ll exgcd(ll A, ll B, ll &x, ll &y) { 

        if(B == 0) {x = 1; y = 0; return A; }
        ll _gcd_ = exgcd(B, A % B, x, y);

        ll t = x;
        x = y; y = t - A / B * y;
        return _gcd_;
    }
    void call_exgcd(ll A, ll B, ll C, ll &x, ll &y) {
        ll d = exgcd(A, B, x, y);
        if(C % d != 0) cout << -1 << '\n';
        else { 

            x = C / d * x;
            y = C / d * y;
            x %= mod; while(x < 0) x += mod;
            y %= mod; while(y < 0) y += mod;
            cout << x << ' ' << y << '\n';
        }
    }


    int sgn(double x) { if(fabs(x) < eps) return 0; return x > 0? 1: -1; }
    inline double sqr(double x) { return x * x; }
    struct Point {
        double x, y;
        Point() { }
        Point(double _x,double _y): x(_x), y(_y) { }
        void input() { cin >> x >> y; }
        void output() {
            if(sgn(x) == 0) x = 0; if(sgn(y) == 0) y = 0;
            cout << fixed << setprecision(12) << x << ' ' << y << '\n';
        }
        bool operator == (Point b)const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
        bool operator < (Point b)const { return sgn(x - b.x)== 0? sgn(y - b.y) < 0: x < b.x; }
        Point operator -(const Point &b)const { return Point(x - b.x, y - b.y); }
        double operator ^(const Point &b)const { return x * b.y - y * b.x; } 

        double operator *(const Point &b)const { return x * b.x + y * b.y; } 

        double len() { return hypot(x, y); }
        double len2() { return x * x + y * y; }
        double distance(Point p) { return hypot(x - p.x, y - p.y); }
        Point operator +(const Point &b)const { return Point(x + b.x, y + b.y); }
        Point operator *(const double &k)const { return Point(x * k, y * k); }
        Point operator /(const double &k)const { return Point(x / k, y / k); }
        

        double rad(Point a,Point b) { Point p = *this; return fabs(atan2( fabs((a - p) ^ (b - p)), (a - p) * (b - p) )); }
        

        Point trunc(double r) { double l = len(); if(!sgn(l))return *this; r /= l; return Point(x * r, y * r); }
        

        Point rotleft() { return Point(-y, x); }
        

        Point rotright() { return Point(y, -x); }
        

        Point rotate(Point p, double angle) {
            Point v = (*this) - p; double c = cos(angle), s = sin(angle);
            return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
        }
    };
    struct Line {
        Point s, e;
        Line() { }
        Line(Point _s, Point _e): s(_s), e(_e) { }
        bool operator ==(Line v) { return (s == v.s) && (e == v.e); }
        

        Line(Point p,double angle) {
            s = p;
            if(sgn(angle-pi/2) == 0) e = (s + Point(0, 1));
            else e = (s + Point(1, tan(angle)));
        }
        

        Line(double a,double b,double c) {
            if(sgn(a) == 0) {
                s = Point(0, -c / b);
                e = Point(1, -c / b);
            } else if(sgn(b) == 0) {
                s = Point(-c / a, 0);
                e = Point(-c / a, 1);
            } else {
                s = Point(0, -c / b);
                e = Point(1, (-c - a) / b);
            }
        }
        void input() { s.input(); e.input(); }
        void adjust() { if(e < s) swap(s,e); }
        double length() { return s.distance(e); }
        

        double angle() {
            double k = atan2(e.y - s.y, e.x - s.x);
            if(sgn(k) < 0)k += pi;
            if(sgn(k - pi) == 0) k -= pi;
            return k;
        }
        

        int relation(Point p) {
            int c = sgn((p - s) ^ (e - s));
            if(c < 0) return 1;
            else if(c > 0) return 2;
            else return 3;
        }
        

        bool pointonseg(Point p) { return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0; }
        

        bool parallel(Line v) { return sgn((e - s) ^ (v.e - v.s)) == 0; }
        

        int segcrossseg(Line v) {
            int d1 = sgn((e-s)^(v.s-s));
            int d2 = sgn((e-s)^(v.e-s));
            int d3 = sgn((v.e-v.s)^(s-v.s));
            int d4 = sgn((v.e-v.s)^(e-v.s));
            if( (d1^d2)==-2 && (d3^d4)==-2 )return 2;
            return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
                   (d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
                   (d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
                   (d4==0 && sgn((e-v.s)*(e-v.e))<=0);
        }
        

        int linecrossseg(Line v) {
            int d1 = sgn((e - s) ^ (v.s - s));
            int d2 = sgn((e - s) ^ (v.e - s));
            if((d1 ^ d2) == -2) return 2;
            return (d1 == 0 || d2 == 0);
        }
        

        int linecrossline(Line v) {
            if((*this).parallel(v))
                return v.relation(s)==3;
            return 2;
        }
        

        Point crosspoint(Line v) {
            double a1 = (v.e-v.s)^(s-v.s);
            double a2 = (v.e-v.s)^(e-v.s);
            return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
        }
        

        double dispointtoline(Point p) { return fabs((p-s)^(e-s))/length(); }
        

        double dispointtoseg(Point p) {
            if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
                return min(p.distance(s),p.distance(e));
            return dispointtoline(p);
        }
        

        double dissegtoseg(Line v) {
            return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
        }
        

        Point lineprog(Point p) { return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) ); }
        

        Point symmetrypoint(Point p) { Point q = lineprog(p); return Point(2*q.x-p.x,2*q.y-p.y); }
    };
    struct circle {
        Point p; double r;
        circle() { }
        circle(Point _p, double _r): p(_p), r(_r) { }
        circle(double x, double y, double _r) { p = Point(x,y); r = _r; }
        

        circle(Point a, Point b, Point c) {
            Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
            Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
            p = u.crosspoint(v);
            r = p.distance(a);
        }
        

        circle(Point a, Point b, Point c, bool t) {
            Line u,v;
            double m = atan2(b.y-a.y,b.x-a.x), n = atan2(c.y-a.y,c.x-a.x);
            u.s = a;
            u.e = u.s + Point(cos((n+m)/2),sin((n+m)/2));
            v.s = b;
            m = atan2(a.y-b.y,a.x-b.x) , n = atan2(c.y-b.y,c.x-b.x);
            v.e = v.s + Point(cos((n+m)/2),sin((n+m)/2));
            p = u.crosspoint(v);
            r = Line(a,b).dispointtoseg(p);
        }
        void input() { p.input(); cin >> r; }
        void output() { cout << fixed << setprecision(9) << "x:" << p.x << ", y:" << p.y << ", r:" << r << '\n'; }
        bool operator == (circle v) { return (p == v.p) && sgn(r - v.r) == 0; }
        bool operator < (circle v)const { return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0)); }
        double area() { return pi * r * r; }
        double circumference() { return 2 * pi * r; }
        

        int relation(Point b) {
            double dst = b.distance(p);
            if(sgn(dst-r) < 0)return 2;
            else if(sgn(dst-r)==0)return 1;
            return 0;
        }
        

        int relationseg(Line v) {
            double dst = v.dispointtoseg(p);
            if(sgn(dst-r) < 0)return 2;
            else if(sgn(dst-r) == 0)return 1;
            return 0;
        }
        

        int relationline(Line v) {
            double dst = v.dispointtoline(p);
            if(sgn(dst-r) < 0)return 2;
            else if(sgn(dst-r) == 0)return 1;
            return 0;
        }
        

        int relationcircle(circle v) {
            double d = p.distance(v.p);
            if(sgn(d-r-v.r) > 0)return 5;
            if(sgn(d-r-v.r) == 0)return 4;
            double l = fabs(r-v.r);
            if(sgn(d-r-v.r)<0 && sgn(d-l)>0)return 3;
            if(sgn(d-l)==0)return 2;
            if(sgn(d-l)<0)return 1;
        }
        

        int pointcrosscircle(circle v,Point &p1,Point &p2) {
            int rel = relationcircle(v);
            if(rel == 1 || rel == 5)return 0;
            double d = p.distance(v.p);
            double l = (d*d+r*r-v.r*v.r)/(2*d);
            double h = sqrt(r*r-l*l);
            Point tmp = p + (v.p-p).trunc(l);
            p1 = tmp + ((v.p-p).rotleft().trunc(h));
            p2 = tmp + ((v.p-p).rotright().trunc(h));
            if(rel == 2 || rel == 4)
                return 1;
            return 2;
        }
        

        int pointcrossline(Line v,Point &p1,Point &p2) {
            if(!(*this).relationline(v))return 0;
            Point a = v.lineprog(p);
            double d = v.dispointtoline(p);
            d = sqrt(r*r-d*d);
            if(sgn(d) == 0) {
                p1 = a;
                p2 = a;
                return 1;
            }
            p1 = a + (v.e-v.s).trunc(d);
            p2 = a - (v.e-v.s).trunc(d);
            return 2;
        }
        

        int gercircle(Point a,Point b,double r1,circle &c1,circle &c2) {
            circle x(a,r1),y(b,r1);
            int t = x.pointcrosscircle(y,c1.p,c2.p);
            if(!t)return 0;
            c1.r = c2.r = r1;
            return t;
        }
        

        int getcircle(Line u,Point q,double r1,circle &c1,circle &c2) {
            double dis = u.dispointtoline(q);
            if(sgn(dis-r1*2)>0)return 0;
            if(sgn(dis) == 0) {
                c1.p = q + ((u.e-u.s).rotleft().trunc(r1));
                c2.p = q + ((u.e-u.s).rotright().trunc(r1));
                c1.r = c2.r = r1;
                return 2;
            }
            Line u1 = Line((u.s + (u.e-u.s).rotleft().trunc(r1)),(u.e + (u.e-u.s).rotleft().trunc(r1)));
            Line u2 = Line((u.s + (u.e-u.s).rotright().trunc(r1)),(u.e + (u.e-u.s).rotright().trunc(r1)));
            circle cc = circle(q,r1);
            Point p1,p2;
            if(!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
            c1 = circle(p1,r1);
            if(p1 == p2) {
                c2 = c1;
                return 1;
            }
            c2 = circle(p2,r1);
            return 2;
        }
        

        int getcircle(Line u,Line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4) {
            if(u.parallel(v))return 0;

            Line u1 = Line(u.s + (u.e-u.s).rotleft().trunc(r1),u.e + (u.e-u.s).rotleft().trunc(r1));
            Line u2 = Line(u.s + (u.e-u.s).rotright().trunc(r1),u.e + (u.e-u.s).rotright().trunc(r1));
            Line v1 = Line(v.s + (v.e-v.s).rotleft().trunc(r1),v.e + (v.e-v.s).rotleft().trunc(r1));
            Line v2 = Line(v.s + (v.e-v.s).rotright().trunc(r1),v.e + (v.e-v.s).rotright().trunc(r1));
            c1.r = c2.r = c3.r = c4.r = r1;
            c1.p = u1.crosspoint(v1);
            c2.p = u1.crosspoint(v2);
            c3.p = u2.crosspoint(v1);
            c4.p = u2.crosspoint(v2);
            return 4;
        }
        

        int getcircle(circle cx,circle cy,double r1,circle &c1,circle &c2) {
            circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
            int t = x.pointcrosscircle(y,c1.p,c2.p);
            if(!t)return 0;
            c1.r = c2.r = r1;
            return t;
        }
        

        int tangentline(Point q,Line &u,Line &v) {
            int x = relation(q);
            if(x == 2)return 0;
            if(x == 1) {
                u = Line(q,q + (q-p).rotleft());
                v = u;
                return 1;
            }
            double d = p.distance(q);
            double l = r*r/d;
            double h = sqrt(r*r-l*l);
            u = Line(q,p + ((q-p).trunc(l) + (q-p).rotleft().trunc(h)));
            v = Line(q,p + ((q-p).trunc(l) + (q-p).rotright().trunc(h)));
            return 2;
        }
        

        double areacircle(circle v) {
            int rel = relationcircle(v);
            if(rel >= 4)return 0.0;
            if(rel <= 2)return min(area(),v.area());
            double d = p.distance(v.p);
            double hf = (r+v.r+d)/2.0;
            double ss = 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
            double a1 = acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
            a1 = a1*r*r;
            double a2 = acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
            a2 = a2*v.r*v.r;
            return a1+a2-ss;
        }
        

        double areacircle2(circle v) {
            double a=hypot(p.x-v.p.x,p.y-v.p.y),b=r,c=v.r;
            double s1=pi*r*r,s2=pi*v.r*v.r;
            if(sgn(a-b-c)>=0)
                return 0;
            if(sgn(a+min(b,c)-max(b,c))<=0)
                return min(s1,s2);
            else {
                double cta1=2*acos((a*a+b*b-c*c)/(2*a*b));
                double cta2=2*acos((a*a+c*c-b*b)/(2*a*c));
                return cta1/(2*pi)*s1-0.5*sin(cta1)*b*b+cta2/(2*pi)*s2-0.5*sin(cta2)*c*c;
            }
        }
        

        double areatriangle(Point a,Point b) {
            if(sgn((p-a)^(p-b)) == 0)return 0.0;
            Point q[5]; int len = 0;
            q[len++] = a;
            Line l(a,b); Point p1,p2;
            if(pointcrossline(l,q[1],q[2])==2) {
                if(sgn((a-q[1])*(b-q[1]))<0)q[len++] = q[1];
                if(sgn((a-q[2])*(b-q[2]))<0)q[len++] = q[2];
            }
            q[len++] = b;
            if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q[2]);
            double res = 0; for(int i = 0; i < len-1; i++) {
                if(relation(q[i])==0||relation(q[i+1])==0) {
                    double arg = p.rad(q[i],q[i+1]);
                    res += r*r*arg/2.0;
                } else {
                    res += fabs((q[i]-p)^(q[i+1]-p))/2.0;
                }
            }
            return res;
        }
    };
    struct polygon {
        int n; Point p[maxp]; Line l[maxp];
        void input(int _n) { n = _n; for(int i = 0; i < n; i++) p[i].input(); }
        void add(Point q) { p[n++] = q; }
        void getline() { for(int i = 0; i < n; i++) l[i] = Line(p[i],p[(i + 1) % n]); }
        struct cmp {
            Point p;
            cmp(const Point &p0) { p = p0; }
            bool operator()(const Point &aa,const Point &bb) {
                Point a = aa, b = bb;
                int d = sgn((a-p)^(b-p));
                if(d == 0) {
                    return sgn(a.distance(p)-b.distance(p)) < 0;
                }
                return d > 0;
            }
        };
        

        void norm() { Point mi = p[0]; for(int i = 1; i < n; i++)mi = min(mi,p[i]); sort(p,p+n,cmp(mi)); }
        

        void getconvex(polygon &convex) {
            sort(p,p + n); convex.n = n;
            for(int i = 0; i < min(n,2); i++) convex.p[i] = p[i];
            if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;

            if(n <= 2)return; int &top = convex.n; top = 1;
            for(int i = 2; i < n; i++) {
                while(top && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i])) <= 0) top--;
                convex.p[++top] = p[i];
            }
            int temp = top; convex.p[++top] = p[n-2];
            for(int i = n-3; i >= 0; i--) {
                while(top != temp && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i])) <= 0) top--;
                convex.p[++top] = p[i];
            }
            if(convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--; convex.norm();

        }
        

        void Graham(polygon &convex) {
            norm();
            int &top = convex.n; top = 0;
            if(n == 1) { top = 1; convex.p[0] = p[0]; return; }
            if(n == 2) {
                top = 2;
                convex.p[0] = p[0];
                convex.p[1] = p[1];
                if(convex.p[0] == convex.p[1])top--;
                return;
            }
            convex.p[0] = p[0]; convex.p[1] = p[1];
            top = 2;
            for(int i = 2; i < n; i++) {
                while( top > 1 && sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2])) <= 0 )
                    top--;
                convex.p[top++] = p[i];
            }
            if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;

        }
        

        bool isconvex() {
            bool s[3];
            memset(s,false,sizeof(s));
            for(int i = 0; i < n; i++) {
                int j = (i+1)%n;
                int k = (j+1)%n;
                s[sgn((p[j]-p[i])^(p[k]-p[i]))+1] = true;
                if(s[0] && s[2])return false;
            }
            return true;
        }
        

        

        int relationpoint(Point q) {
            for(int i = 0; i < n; i++) {
                if(p[i] == q)return 3;
            }
            getline();
            for(int i = 0; i < n; i++) {
                if(l[i].pointonseg(q))return 2;
            }
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                int j = (i+1)%n;
                int k = sgn((q-p[j])^(p[i]-p[j]));
                int u = sgn(p[i].y-q.y);
                int v = sgn(p[j].y-q.y);
                if(k > 0 && u < 0 && v >= 0)cnt++;
                if(k < 0 && v < 0 && u >= 0)cnt--;
            }
            return cnt != 0;
        }
        

        

        void convexcut(Line u,polygon &po) {
            int &top = po.n;

            top = 0;
            for(int i = 0; i < n; i++) {
                int d1 = sgn((u.e-u.s)^(p[i]-u.s));
                int d2 = sgn((u.e-u.s)^(p[(i+1)%n]-u.s));
                if(d1 >= 0)po.p[top++] = p[i];
                if(d1*d2 < 0)po.p[top++] = u.crosspoint(Line(p[i],p[(i+1)%n]));
            }
        }
        

        double getcircumference() {
            double sum = 0;
            for(int i = 0; i < n; i++) {
                sum += p[i].distance(p[(i+1)%n]);
            }
            return sum;
        }
        

        double getarea() {
            double sum = 0;
            for(int i = 0; i < n; i++) {
                sum += (p[i]^p[(i+1)%n]);
            }
            return fabs(sum)/2;
        }
        

        bool getdir() {
            double sum = 0;
            for(int i = 0; i < n; i++)
                sum += (p[i]^p[(i+1)%n]);
            if(sgn(sum) > 0)return 1;
            return 0;
        }
        

        Point getbarycentre() {
            Point ret(0,0);
            double area = 0;
            for(int i = 1; i < n-1; i++) {
                double tmp = (p[i]-p[0])^(p[i+1]-p[0]);
                if(sgn(tmp) == 0)continue;
                area += tmp;
                ret.x += (p[0].x+p[i].x+p[i+1].x)/3*tmp;
                ret.y += (p[0].y+p[i].y+p[i+1].y)/3*tmp;
            }
            if(sgn(area)) ret = ret/area;
            return ret;
        }
        

        double areacircle(circle c) {
            double ans = 0;
            for(int i = 0; i < n; i++) {
                int j = (i+1)%n;
                if(sgn( (p[j]-c.p)^(p[i]-c.p) ) >= 0)
                    ans += c.areatriangle(p[i],p[j]);
                else ans -= c.areatriangle(p[i],p[j]);
            }
            return fabs(ans);
        }
        

        int relationcircle(circle c) {
            getline();
            int x = 2;
            if(relationpoint(c.p) != 1)return 0;

            for(int i = 0; i < n; i++) {
                if(c.relationseg(l[i])==2)return 0;
                if(c.relationseg(l[i])==1)x = 1;
            }
            return x;
        }
    };
    

    double dot(Point A,Point B,Point C) {
        return (B-A)*(C-A);
    }
    double cross(Point A,Point B,Point C) {
        return (B-A)^(C-A);
    }
    

    double minRectangleCover(polygon A) {
        

        if(A.n < 3)return 0.0;
        A.p[A.n] = A.p[0];
        double ans = -1;
        int r = 1, p = 1, q;
        for(int i = 0; i < A.n; i++) {
            

            while( sgn( cross(A.p[i],A.p[i+1],A.p[r+1]) - cross(A.p[i],A.p[i+1],A.p[r]) ) >= 0 )
                r = (r+1)%A.n;
            

            while(sgn( dot(A.p[i],A.p[i+1],A.p[p+1]) - dot(A.p[i],A.p[i+1],A.p[p]) ) >= 0 )
                p = (p+1)%A.n;
            if(i == 0)q = p;
            

            while(sgn(dot(A.p[i],A.p[i+1],A.p[q+1]) - dot(A.p[i],A.p[i+1],A.p[q])) <= 0)
                q = (q+1)%A.n;
            double d = (A.p[i] - A.p[i+1]).len2();
            double tmp = cross(A.p[i],A.p[i+1],A.p[r]) *
                         (dot(A.p[i],A.p[i+1],A.p[p]) - dot(A.p[i],A.p[i+1],A.p[q]))/d;
            if(ans < 0 || ans > tmp)ans = tmp;
        }
        return ans;
    }
    circle minCircleCover(int n, Point p[], Point P = Point(0, 0)) {
        random_shuffle(p, p + n); double r2 = 0;
        for(int i = 0; i < n; ++ i) {
            if((p[i] - P).len2() > r2) {
                P = p[i], r2 = 0;
                for(int j = 0; j < i; ++ j) {
                    if((p[j]-P).len2() > r2) {
                        P = (p[i]+p[j])/2, r2 = (p[j]-P).len2();
                        for(int k = 0; k < j; ++ k) {
                            if((p[k]-P).len2() > r2) {
                                P = circle(p[i], p[j], p[k]).p, r2 = (p[k] - P).len2();
                            }
                        }
                    }
                }
            }
        }
        return circle(P, sqrt(r2));
    }
}
using namespace BASIC_MATH;
namespace MODINT {
    template<unsigned M_> struct ModInt {
        static constexpr unsigned M = M_;
        unsigned x;
        constexpr ModInt() : x(0U) {}
        constexpr ModInt(unsigned x_) : x(x_ % M) {}
        constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
        constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
        constexpr ModInt(long long x_) : x(
                ((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
        ModInt &operator+=(const ModInt &a) {
            x = ((x += a.x) >= M) ? (x - M) : x;
            return *this;
        }
        ModInt &operator-=(const ModInt &a) {
            x = ((x -= a.x) >= M) ? (x + M) : x;
            return *this;
        }
        ModInt &operator*=(const ModInt &a) {
            x = (static_cast<unsigned long long>(x) * a.x) % M;
            return *this;
        }
        ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
        ModInt quick_pow(long long e) const {
            if (e < 0) return inv().quick_pow(-e);
            ModInt a = *this, b = 1U;
            for (; e; e >>= 1) {
                if (e & 1) b *= a;
                a *= a;
            }
            return b;
        }
        ModInt inv() const {
            unsigned a = M, b = x;
            int y = 0, z = 1;
            for (; b;) {
                const unsigned q = a / b;
                const unsigned c = a - q * b;
                a = b; b = c;
                const int w = y - static_cast<int>(q) * z;
                y = z; z = w;
            }
            assert(a == 1U);
            return ModInt(y);
        }
        ModInt operator+() const { return *this; }
        ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
        ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
        ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
        ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
        ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
        template<class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
        template<class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
        template<class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
        template<class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
        explicit operator bool() const { return x; }
        bool operator==(const ModInt &a) const { return (x == a.x); }
        bool operator!=(const ModInt &a) const { return (x != a.x); }
        friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
    };


    constexpr unsigned MO = 998244353;
    using Mint = ModInt<MO>;
}
using namespace MODINT;

struct Node {
    int a, b;
    bool operator<(const Node h) const {
        if(a == h.a) return b < h.b;
        return a > h.a;
    }
};

void solve() {
    int o = 1, cases = 0, if_cases = 0; cin >> o;
    while(o --) {
        if(if_cases) cout << "Case " << ++cases << ": ";
        string s; cin >> s;
        bool fina = true;
        int pos = -1, pos2 = -1;
        for(int i = 0; i < s.size() - 1; ++ i) {
            if(s.substr(i, 2) == "11") {
                pos = i;
                break;
            }
        }
        for(int i = 0; i < s.size() - 1; ++ i) {
            if(s.substr(i, 2) == "00") {
                pos2 = i;
            }
        }
        if(pos != -1 && pos2 != -1 && pos < pos2) fina = false;
        cout << (fina? "YES": "NO") << '\n';
    }

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef ACM_LOCAL
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    signed test_index_for_debug = 1;
    char acm_local_for_debug = 0;
    do {
        if (acm_local_for_debug == '$') exit(0);
        if (test_index_for_debug > 20)
            throw runtime_error("Check the stdin!!!");
        auto start_clock_for_debug = clock();
        solve();
        auto end_clock_for_debug = clock();
        cout << "\nTest " << test_index_for_debug << " successful!" << endl;
        cerr << "Test " << test_index_for_debug++ << " Run Time: "
             << double(end_clock_for_debug - start_clock_for_debug) / CLOCKS_PER_SEC << "s" << endl;
        cout << "--------------------------------------------------" << endl;
    } while (cin >> acm_local_for_debug && cin.putback(acm_local_for_debug));
#else
    solve();
#endif
    return 0;
}