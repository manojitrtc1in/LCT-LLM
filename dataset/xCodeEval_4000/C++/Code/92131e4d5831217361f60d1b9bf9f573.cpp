

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>PLL;
typedef pair<int,int>PII;
typedef pair<double,double>PDD;
#define I_int ll
#define x first
#define y second
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define read read()
char F[200];
inline void out(I_int x) {
    if (x == 0) return (void) (putchar('0'));
    I_int tmp = x > 0 ? x : -x;
    if (x < 0) putchar('-');
    int cnt = 0;
    while (tmp > 0) {
        F[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while (cnt > 0) putchar(F[--cnt]);
    

}
ll ksm(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p;b>>=1;}return res;}
const int inf=0x3f3f3f3f;
const ll mod=998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define rep(i, a, b) for(int i=(a);i<=(b);++i)
#define dep(i, a, b) for(int i=(a);i>=(b);--i)

const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxp = 1010;


int sgn(double x){
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}


inline double sqr(double x){return x*x;}

struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x = _x;
        y = _y;
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("%.2f %.2f\n",x,y);
    }
    bool operator == (Point b)const{
        return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
    }
    bool operator < (Point b)const{
        return sgn(x-b.x)== 0?sgn(y-b.y)<0:x<b.x;
    }
    Point operator -(const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    

    double operator ^(const Point &b)const{
        return x*b.y - y*b.x;
    }
    

    double operator *(const Point &b)const{
        return x*b.x + y*b.y;
    }
    

    double len(){
        return hypot(x,y);

    }
    

    double len2(){
        return x*x + y*y;
    }
    

    double distance(Point p){
        return hypot(x-p.x,y-p.y);
    }
    Point operator +(const Point &b)const{
        return Point(x+b.x,y+b.y);
    }
    Point operator *(const double &k)const{
        return Point(x*k,y*k);
    }
    Point operator /(const double &k)const{
        return Point(x/k,y/k);
    }
    

    

    

    double rad(Point a,Point b){
        Point p = *this;
        return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
    }
    

    Point trunc(double r){
        double l = len();
        if(!sgn(l))return *this;
        r /= l;
        return Point(x*r,y*r);
    }
    

    Point rotleft(){
        return Point(-y,x);
    }
    

    Point rotright(){
        return Point(y,-x);
    }
    

    Point rotate(Point p,double angle){
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
    }
};

struct Line{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e){
        s = _s;
        e = _e;
    }
    bool operator ==(Line v){
        return (s == v.s)&&(e == v.e);
    }
    

    Line(Point p,double angle){
        s = p;
        if(sgn(angle-pi/2) == 0){
            e = (s + Point(0,1));
        }
        else{
            e = (s + Point(1,tan(angle)));
        }
    }
    

    Line(double a,double b,double c){
        if(sgn(a) == 0){
            s = Point(0,-c/b);
            e = Point(1,-c/b);
        }
        else if(sgn(b) == 0){
            s = Point(-c/a,0);
            e = Point(-c/a,1);
        }
        else{
            s = Point(0,-c/b);
            e = Point(1,(-c-a)/b);
        }
    }
    void input(){
        s.input();
        e.input();
    }
    void adjust(){
        if(e < s)swap(s,e);
    }
    

    double length(){
        return s.distance(e);
    }
    

    double angle(){
        double k = atan2(e.y-s.y,e.x-s.x);
        if(sgn(k) < 0)k += pi;
        if(sgn(k-pi) == 0)k -= pi;
        return k;
    }
    

    

    

    

    int relation(Point p){
        int c = sgn((p-s)^(e-s));
        if(c < 0)return 1;
        else if(c > 0)return 2;
        else return 3;
    }
    

    bool pointonseg(Point p){
        return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0;
    }
    

    bool parallel(Line v){
        return sgn((e-s)^(v.e-v.s)) == 0;
    }
    

    

    

    

    int segcrossseg(Line v){
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
    

    

    

    

    

    int linecrossseg(Line v){
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        if((d1^d2)==-2) return 2;
        return (d1==0||d2==0);
    }
    

    

    

    

    int linecrossline(Line v){
        if((*this).parallel(v))
            return v.relation(s)==3;
        return 2;
    }
    

    

    Point crosspoint(Line v){
        double a1 = (v.e-v.s)^(s-v.s);
        double a2 = (v.e-v.s)^(e-v.s);
        return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
    }
    

    double dispointtoline(Point p){
        return fabs((p-s)^(e-s))/length();
    }
    

    double dispointtoseg(Point p){
        if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
            return min(p.distance(s),p.distance(e));
        return dispointtoline(p);
    }
    

    

    double dissegtoseg(Line v){
        return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
    }
    

    Point lineprog(Point p){
        return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
    }
    

    Point symmetrypoint(Point p){
        Point q = lineprog(p);
        return Point(2*q.x-p.x,2*q.y-p.y);
    }
};


struct circle{
    Point p;

    double r;

    circle(){}
    circle(Point _p,double _r){
        p = _p;
        r = _r;
    }
    circle(double x,double y,double _r){
        p = Point(x,y);
        r = _r;
    }
    

    

    

    

    circle(Point a,Point b,Point c){
        Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
        Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
        p = u.crosspoint(v);
        r = p.distance(a);
    }
    

    

    

    circle(Point a,Point b,Point c,bool t){
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
    

    void input(){
        p.input();
        scanf("%lf",&r);
    }
    

    void output(){
        printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
    }
    bool operator == (circle v){
        return (p==v.p) && sgn(r-v.r)==0;
    }
    bool operator < (circle v)const{
        return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0));
    }
    

    double area(){
        return pi*r*r;
    }
    

    double circumference(){
        return 2*pi*r;
    }
    

    

    

    

    int relation(Point b){
        double dst = b.distance(p);
        if(sgn(dst-r) < 0)return 2;
        else if(sgn(dst-r)==0)return 1;
        return 0;
    }
    

    

    int relationseg(Line v){
        double dst = v.dispointtoseg(p);
        if(sgn(dst-r) < 0)return 2;
        else if(sgn(dst-r) == 0)return 1;
        return 0;
    }
    

    

    int relationline(Line v){
        double dst = v.dispointtoline(p);
        if(sgn(dst-r) < 0)return 2;
        else if(sgn(dst-r) == 0)return 1;
        return 0;
    }
    

    

    

    

    

    

    

    

    int relationcircle(circle v){
        double d = p.distance(v.p);
        if(sgn(d-r-v.r) > 0)return 5;
        if(sgn(d-r-v.r) == 0)return 4;
        double l = fabs(r-v.r);
        if(sgn(d-r-v.r)<0 && sgn(d-l)>0)return 3;
        if(sgn(d-l)==0)return 2;
        if(sgn(d-l)<0)return 1;
        return 0;
    }
    

    

    

    int pointcrosscircle(circle v,Point &p1,Point &p2){
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
    

    int pointcrossline(Line v,Point &p1,Point &p2){
        if(!(*this).relationline(v))return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r*r-d*d);
        if(sgn(d) == 0){
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e-v.s).trunc(d);
        p2 = a - (v.e-v.s).trunc(d);
        return 2;
    }
    

    int gercircle(Point a,Point b,double r1,circle &c1,circle &c2){
        circle x(a,r1),y(b,r1);
        int t = x.pointcrosscircle(y,c1.p,c2.p);
        if(!t)return 0;
        c1.r = c2.r = r1;
        return t;
    }
    

    

    int getcircle(Line u,Point q,double r1,circle &c1,circle &c2){
        double dis = u.dispointtoline(q);
        if(sgn(dis-r1*2)>0)return 0;
        if(sgn(dis) == 0){
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
        if(p1 == p2){
            c2 = c1;
            return 1;
        }
        c2 = circle(p2,r1);
        return 2;
    }
    

    

    int getcircle(Line u,Line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4){
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
    

    

    int getcircle(circle cx,circle cy,double r1,circle &c1,circle &c2){
        circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
        int t = x.pointcrosscircle(y,c1.p,c2.p);
        if(!t)return 0;
        c1.r = c2.r = r1;
        return t;
    }
 
    

    

    int tangentline(Point q,Line &u,Line &v){
        int x = relation(q);
        if(x == 2)return 0;
        if(x == 1){
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
    

    double areacircle(circle v){
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
    

    double areacircle2(circle v)
    {
        double a=hypot(p.x-v.p.x,p.y-v.p.y),b=r,c=v.r;
        double s1=pi*r*r,s2=pi*v.r*v.r;
        if(sgn(a-b-c)>=0)
            return 0;
        if(sgn(a+min(b,c)-max(b,c))<=0)
            return min(s1,s2);
        else
        {
            double cta1=2*acos((a*a+b*b-c*c)/(2*a*b));
            double cta2=2*acos((a*a+c*c-b*b)/(2*a*c));
            return cta1/(2*pi)*s1-0.5*sin(cta1)*b*b+cta2/(2*pi)*s2-0.5*sin(cta2)*c*c;
        }
    }
    

    

    double areatriangle(Point a,Point b){
        if(sgn((p-a)^(p-b)) == 0)return 0.0;
        Point q[5];
        int len = 0;
        q[len++] = a;
        Line l(a,b);
        Point p1,p2;
        if(pointcrossline(l,q[1],q[2])==2){
            if(sgn((a-q[1])*(b-q[1]))<0)q[len++] = q[1];
            if(sgn((a-q[2])*(b-q[2]))<0)q[len++] = q[2];
        }
        q[len++] = b;
        if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q[2]);
        double res = 0;
        for(int i = 0;i < len-1;i++){
            if(relation(q[i])==0||relation(q[i+1])==0){
                double arg = p.rad(q[i],q[i+1]);
                res += r*r*arg/2.0;
            }
            else{
                res += fabs((q[i]-p)^(q[i+1]-p))/2.0;
            }
        }
        return res;
    }
};


const int maxn = 3e5 + 10;



int a[maxn],b[maxn],n,p[maxn],d[maxn],ns[maxn];
int minn;

void init(){
	memset(p,-1,sizeof p);
	memset(d,0x3f,sizeof d);
	memset(ns,0,sizeof ns);
}

int bb(){
	queue<int>q;
	init();
	q.push(n);
	d[n]=0;
	minn=n;
	while(!q.empty()){
		int t=q.front();q.pop();
		if(t==0) return d[t];
		for(int x=a[t];x;x--){
			int ow=t-x,tmp=0;
			if(ow>=minn) break;
			if(ow>0) tmp=ow,ow=ow+b[t-x];
			else ow=0;
			if(d[ow]>d[t]+1){
				d[ow]=d[t]+1;
				p[ow]=t;
				ns[ow]=tmp;
				q.push(ow);
			}
		}
		minn=min(minn,t-a[t]);
	}
	return -1;
}

void solve(){
	n=read;
    rep(i,1,n) a[i]=read;
    rep(i,1,n) b[i]=read;
}

void output(){
	stack<int>stk;
		int x=0;
		while(p[x]!=-1){
			stk.push(x);
			x=p[x];
		}   	
		while(!stk.empty()){
			int now=stk.top();
			printf("%d ",ns[now]);
			stk.pop();
		}
		puts("");
}

bool check(){
	int ans=0;
	for(int i=1;i<=99;i++)
		ans++;
	return 1;
}

int main() {
	check();
    solve();
	cout<<bb()<<"\n"; 
	output();
	return 0;
}
