#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define db double
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossonly(p1,p2,p3) (sgn((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y)))


using namespace std;
typedef long long ll;
inline void read(int &a);
const int maxn=2e5+10;
const int N =3e5+10;
const int inf=0x3f3f3f3f;
const int mnf=0x1f1f1f1f;
const db eps = 1e-6;
const db pi= acos(-1.0);
int sgn(db a){return a<-eps?-1:a>eps;}
int cmppoint(db a,db b){return sgn(a-b);}
int gcd(int a,int b) {return (b==0?a:gcd(b,a%b));}

struct ball{
    db x,y,z,r;
};
db balldis(ball a,ball b){
    db ans = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
    return ans;
}
db ar3(ball a){
    db ans=(4.0/3)*pi*a.r*a.r*a.r;
    return ans;
}
db Uball(ball a,ball b){

    db ans=0;
    db d=balldis(a,b);
    if(sgn(d-a.r-b.r)>=0){
        ans=ar3(a)+ar3(b);
    }
    else if(d<=abs(a.r-b.r)){
        ans=max(ar3(a),ar3(b));
    }
    else{
        db c = (a.r*a.r+d*d-b.r*b.r)/(2.0*d*a.r);
        db h = a.r*(1-c);
        ans+=(1.0/3)*pi*(3*a.r-h)*h*h;
        c = (b.r*b.r+d*d-a.r*a.r)/(2.0*d*b.r);
        h= b.r*(1-c);
        ans+=(1.0/3)*pi*(3*b.r-h)*h*h;

        ans=ar3(a)+ar3(b)-ans;

    }
    return ans;
}


struct point{
    db x,y;
    point() {}
    point(db _x,db _y){
        x = _x;
        y = _y;
    }
    db len2(){
        return x*x+y*y;
    }
    point operator -(const point &b)const{
        return point(x - b.x,y - b.y);
    }
    point operator + (const point &b) const {
        return point(x+b.x,y+b.y);
    }
    db operator ^(const point &b)const{

        return x*b.y - y*b.x;
    }
    db operator *(const point &b)const{

        return x*b.x + y*b.y;
    }
    point operator / (const  db &k) const{
        return point(x/k,y/k);
    }
    point operator *(const db &k) const {
        return point(x*k,y*k);
    }
    bool operator < (point p) const{
        int c=cmppoint(x,p.x);
        if(c) return c==-1;
        return cmppoint(y,p.y)==-1;
    }
    bool operator == (point o) const {
        return cmppoint(x,o.x)==0&&cmppoint(y,o.y)==0;
    }
    point rotleft(){
        return point (-y,x);
    }
    point rotright(){
        return point (y,-x);
    }
    point rotate(point p ,db angle){

        point v = (*this) -p;
        db c = cos(angle),s = sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
    db rad(point a,point b){

        point p=*this;
        return fabs(atan2(fabs((a-p)^(b-p)),(a-p)*(b-p)));
    }
    point trunc(db r){

        db l = hypot(x,y);
        if(!sgn(l)) return *this;
        r/=l;
        return point(x*r,y*r);
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
};
db dist(point a,point b){return sqrt((a-b)*(a-b));}
struct line{
    point s,e;
    line() {}
    line(point _s,point _e){
        s = _s;
        e = _e;
    }
    bool operator == (line v){
        return (s==v.s)&&(e==v.e);
    }
    line(point p,db angle){

        s=p;
        if(sgn(angle-pi/2)==0) e = (s+point(0,1));
        else e = (s+point(1,tan(angle)));
    }
    line(db a,db b,db c){

        if(sgn(a)==0){
            s = point(0,-c/b);
            e = point(1,-c/b);
        }else if(sgn(b)==0){
            s = point(-c/a,0);
            e = point(-c/a,1);
        }else{
            s = point(0,-c/b);
            e = point(1,(-c-a)/b);
        }
    }
    void input(){
        s.input();
        e.input();
    }
    void adjust(){
        if(e<s) swap(e,s);
    }
    db length(){
        return dist(e,s);
    }
    db angle(){

        db k = atan2(e.y-s.y,e.x-s.x);
        if(sgn(k)<0) k+=pi;
        if(sgn(k-pi)==0) k-=pi;
        return k;
    }
    int relation(point p){
        

        

        int c = sgn((p-s)^(e-s));
        if(c<0) return 1;
        else if(c>0) return 2;
        else return 3;
    }
    bool pointonseg(point p){
        return sgn((p-s)^(e-s))==0 && sgn((p-s)*(p-e))<=0;
    }
    int segtoseg(line v){
    

    

        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        int d3 = sgn((v.e-v.s)^(s-v.s));
        int d4 = sgn((v.e-v.s)^(e-v.s));
        if((d1^d2)==-2&&(d3^d4)==-2) return 2;
        return (d1==0&&sgn((v.s-s)*(v.s-e))<=0)||
               (d2==0&&sgn((v.e-s)*(v.e-e))<=0)||
               (d3==0&&sgn((s-v.s)*(s-v.e))<=0)||
               (d4==0&&sgn((e-v.s)*(e-v.e))<=0);}
    db dispointtoline(point p){
    

        return fabs((p-s)^(e-s))/dist(s,e);
    }
    db dispointtoseg(point p){
        

        if(sgn((p-s)*(e-s))<0||sgn((p-e)*(s-e))<0) return min(dist(p,s),dist(p,e));
        return fabs(dispointtoline(p));
    }
    db dissegtoseg(line v){
        

        return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
    }
    point lineprog(point p){
    

        return s + ( ((e-s)*((e-s)*(p-s))) / ((e-s).len2()) );
    }
    point symmetrypoint(point p){
    

        point q = lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }
    int linetoseg(line v){
    

    

    

        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        if((d1^d2)==-2) return 2;
        return (d1==0||d2==0);
    }








    bool operator <(line &l) const{
        if(e.x==l.e.x) return s.x<l.s.x;
        return e.x<l.e.x;
    }






    pair<int,point> operator &(const line &b)const{
        point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);

            else return make_pair(1,res);

        }
        db t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};
struct triangle{
    point v[3];
    db ar2(){return fabs(0.5*cross(v[0],v[1],v[2]));}
};
struct circle{
    point center;
    db r;
    circle(){}
    circle (point p,db _r){
        center=p;
        r=_r;
    }
    circle(db x,db y,db _r){
        center = point(x,y);
        r=_r;
    }
    void input(){
        center.input();
        cin>>r;
    }
    bool operator == (circle v){
        return (center==v.center) && sgn(r-v.r)==0;
    }
    bool operator < (circle v) const {
        return ((center<v.center)||((center==v.center)&&sgn(r-v.r)<0));
    }
    void outtriangle(point a,point  b,point c){

        line u = line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
        line v = line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
        pair<int,point> p = u&v;
        center = p.second;
        r = dist(center,a);
    }
    void intriangle(point a,point b,point c){

        line u,v;
        db m = atan2(b.y-a.y,b.x-a.x), n = atan2(c.y-a.y,c.x-a.x);
        u.s = a;
        u.e = u.s + point(cos((m+n)/2),sin((m+n)/2));
        v.s = b;
        v.e = v.s+ point(cos((m+n)/2),sin((m+n)/2));
        pair<int,point> p =u&v;
        center = p.second;
        r = line(a,b).dispointtoseg(center);
    }
    db area(){return pi*r*r;}
    db circumference(){return 2*pi*r;}
    

    int relationtopoint(point b){
        


        db dst = dist(b,center);
        if(sgn(dst-r)<0) return 2;
        else if(sgn(dst-r)==0) return 0;
        return 0;
    }
    int relationtoseg(line v){
        

        db dst = v.dispointtoseg(center);
        if(sgn(dst-r)<0) return 2;
        else if(sgn(dst-r)==0) return 1;
        return 0;
    }
    int relationtoline(line v){
        

        db dst = v.dispointtoline(center);
        if(sgn(dst-r)<0) return 2;
        if(sgn(dst-r)==0) return 1;
        return 0;
    }
    

    

    

    

    

    

    int relationtocircle(circle v){
        db d = dist(center,v.center);
        if(sgn(d-r-v.r)>0) return 5;
        if(sgn(d-r-v.r)==0)return 4;
        db l =fabs(r-v.r);
        if(sgn(d-r-v.r)<0&&sgn(d-l)>0) return 3;
        if(sgn(d-l)==0)return 2;
        if(sgn(d-l)<0) return 1;
    }
    

    int circle_inter(circle v,point &p1,point &p2){
        int rel = relationtocircle(v);
        if(rel==1||rel==5) return 0;
        db d = dist(center,v.center);
        db l = (d*d+r*r-v.r*v.r)/(2*d);
        db h = sqrt(r*r-l*l);
        point tmp = center + (v.center-center).trunc(l);
        p1 = tmp + ((v.center-center).rotleft().trunc(h));
        p2 = tmp + ((v.center-center).rotright().trunc(h));
        if(rel==2||rel==4) return 1;
        return 2;
    }
    

    int circle_line(line v,point &p1,point &p2){
        if(!(*this).relationtoline(v)) return 0;
        point a = v.lineprog(center);
        db d = v.dispointtoline(center);
        d = sqrt(r*r-d*d);
        if(sgn(d)==0){
            p1=a;
            p2=a;
            return 1;
        }
        p1 = a + (v.e-v.s).trunc(d);
        p2 = a - (v.e-v.s).trunc(d);
        return 2;
    }
    

    int getcircle(point a,point b,db r1,circle &c1,circle &c2){
        circle x(a,r1),y(b,r1);
        int t = x.circle_inter(y,c1.center,c2.center);
        if(!t) return 0;
        c1.r=c2.r=r1;
        

        return t;
    }
    

    int getcircle(line u,point q,db r1,circle &c1,circle &c2){
        db dis = u.dispointtoline(q);
        if(sgn(dis-2*r1)>0) return 0;
        if(sgn(dis)==0){
            c1.center = q + ((u.e-u.s).rotleft().trunc(r1));
            c2.center = q + ((u.e-u.s).rotright().trunc(r1));
            c1.r=c2.r=r1;
            return 2;
        }
        line u1 = line((u.s + (u.e-u.s).rotleft().trunc(r1)),(u.e + (u.e-u.s).rotleft().trunc(r1)));
        line u2 = line((u.s + (u.e-u.s).rotright().trunc(r1)),(u.e + (u.e-u.s).rotright().trunc(r1)));
        circle cc = circle(q,r1);
        point p1,p2;
        if(!cc.circle_line(u1,p1,p2)) cc.circle_line(u2,p1,p2);
        c1 = circle(p1,r1);
        if(p1==p2){
            c2=c1;
            return 1;
        }
        c2 = circle(p2,r1);
        return 2;
    }
    

    int getcircle(line u,line v,db r1,circle &c1,circle &c2,circle &c3,circle &c4){
        pair<int ,point> pp = u&v;
        if(pp.first<2) return 0;
        line u1 = line (u.s + (u.e-u.s).rotleft().trunc(r1),u.e + (u.e-u.s).rotleft().trunc(r1));
        line u2 = line (u.s + (u.e-u.s).rotright().trunc(r1),u.e + (u.e-u.s).rotright().trunc(r1));
        line v1 = line (v.s + (v.e-v.s).rotleft().trunc(r1),v.e + (v.e-v.s).rotleft().trunc(r1));
        line v2 = line (v.s + (v.e-v.s).rotright().trunc(r1),v.e + (v.e-v.s).rotright().trunc(r1));
        c1.r=c2.r=c3.r=c4.r=r1;
        pp = u1&v1;c1.center = pp.second;
        pp = u1&v2;c2.center = pp.second;
        pp = u2&v1;c3.center = pp.second;
        pp = u2&v2;c4.center = pp.second;
        return 4;
    }
    

    int get(circle cx,circle cy,db r1,circle &c1,circle &c2){
        circle x(cx.center,r1+cx.r),y(cy.center,cy.r+r1);
        int t = x.circle_inter(y,c1.center,c2.center);
        if(!t) return 0;
        c1.r=c2.r=r1;
        return t;
    }
    

    int tangentline(point q,line &u,line &v){
        int x = relationtopoint(q);
        if(x==2) return 0;
        if(x==1){
            u = line(q,q + (q-center).rotleft());
            v = u;
            return 1;
        }
        db d = dist(q,center);
        db l = r*r/d;
        db h = sqrt(r*r-l*l);
        u = line(q,center + ((q-center).trunc(l) + (q-center).rotleft().trunc(h)));
        v = line(q,center + ((q-center).trunc(l) + (q-center).rotright().trunc(h)));
        return 2;
    }
    

    db area_circle(circle v){
        int rel = relationtocircle(v);
        if(rel>=4) return 0.0;
        if(rel<=2) return min(area(),v.area());
        db d = dist(center,v.center);
        db hf= (r+v.r+d)/2.0;
        db ss= 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
        db a1= acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
        a1 = a1*r*r;
        db a2= acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
        a2 = a2*r*r;
        return a1+a2-ss;
    }
    

    db area_triangle(point a,point b){
        if(sgn((center-a)^(center-b))==0) return 0.0;
        point q[5];
        int len = 0;
        q[len++] = a;
        line l(a,b);
        point p1,p2;
        if(circle_line(l,q[1],q[2])==2){
            if(sgn((a-q[1])*(b-q[1])<0)) q[len++] = q[1];
            if(sgn((a-q[2])*(b-q[2])<0)) q[len++] = q[2];
        }
        q[len++] = b;
        if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0) swap(q[1],q[2]);
        db res = 0;
        for(int i=0;i<len-1;i++){
            if(relationtopoint(q[i])==0||relationtopoint(q[i+1])==0){
                db arg = center.rad(q[i],q[i+1]);
                res+=r*r*arg/2.0;
            }
            else res+=fabs((q[i]-center)^(q[i+1]-center))/2.0;
        }
        return res;
    }
};

struct polygon{
    int n;
    point p[maxn];
    line l[maxn];
    void input(int _n){
        n=_n;
        for(int i=0;i<n;i++) p[i].input();
    }
    void add(point q){p[n++]=q;}
    void getline(){
        for(int i=0;i<n;i++) l[i] = line(p[i],p[(i+1)%n]);
    }
    struct cmp{
        point p;
        cmp (const point &p0){p=p0;}
        bool operator () (const point &aa,const point &bb){
            point a = aa,b = bb;
            int d = sgn((a-p)^(b-p));
            if(d==0) return sgn(dist(a,p)-dist(b,p)) < 0;
            return 0;
        }
    };
    void norm(){

        point mi = p[0];
        for(int i=1;i<n;i++) mi = min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    void getconvex(polygon &convex){
        sort(p,p+n);
        convex.n=n;
        for(int i=0;i<min(n,2);i++) convex.p[i] = p[i];
        if(convex.n==2&&(convex.p[0]==convex.p[1])) convex.n--;
            if(n<=2) return ;
        int &top = convex.n;
        top = 1;
        for(int i=2;i<n;i++){
            while(top&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<=0) top--;
            convex.p[++top] = p[i];
        }
        if(convex.n==2&&(convex.p[0]==convex.p[1])) convex.n--;
        convex.norm();

    }
    bool isconvex(){

        bool s[2];
        memset(s,false,sizeof(s));
        for(int i=0;i<n;i++){
            int j = (i+1)%n;
            int k = (j+1)%n;
            s[sgn((p[j]-p[i])^(p[k]-p[i]))+1] = true;
            if(s[0]==s[2]) return false;
        }
        return true;
    }
    

    

    int relationpoint(point q){
        for(int i=0;i<n;i++)
            if(p[i]==q) return 3;
        getline();
        for(int i=0;i<n;i++)
            if(l[i].pointonseg(q)) return 2;
        int cnt = 0;
        for(int i=0;i<n;i++){
            int j = (i+1)%n;
            int k = sgn((q-p[j])^(p[i]-p[j]));
            int u = sgn(p[i].y-q.y);
            int v = sgn(p[j].y-q.y);
            if(k>0 && u<0 && v>=0) cnt++;
            if(k<0 && u<0 && v>=0) cnt--;
        }
        return cnt!=0;
    }
    

    void convexcut(line u,polygon &po){
        int &top = po.n;
        top = 0;
        for(int i=0;i<n;i++){
            int d1 = sgn((u.e-u.s)^(p[i]-u.s));
            int d2 = sgn((u.e-u.s)^(p[(i+1)%n]-u.s));
            if(d1>=0)po.p[top++] = p[i];
            pair <int ,point> pr = u&line(p[i],p[(i+1)%n]);
            if(d1*d2<0) po.p[top++] = pr.second;
        }
    }
    

    db getcircumference(){
        db sum = 0;
        for(int i=0;i<n;i++) sum+=dist(p[i],p[(i+1)%n]);
        return sum;
    }
    

    db getarea(){
        db sum = 0;
        for(int i=0;i<n;i++) sum+=(p[i]^p[(i+1)%n]);
        return fabs(sum)/2.0;
    }
    

    bool getdir(){
        db sum = 0;
        for(int i=0;i<n;i++) sum+=(p[i]^p[(i+1)%n]);
        if(sgn(sum)>0) return 1;
        return 0;
    }
    

    point getbarycenter(){
        point ret(0,0);
        db area = 0;
        for(int i=1;i<n-1;i++){
            db tmp = (p[i]-p[0])^(p[i+1]-p[0]);
            if(sgn(tmp)==0) continue ;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if(sgn(area)) ret = ret/area;
        return ret;
    }
    

    db area_circle(circle c){
        db ans = 0;
        for(int i=0;i<n;i++){
            int j =(i+1)%n;
            if(sgn((p[j]-c.center)^(p[i]-c.center))>=0) ans+=c.area_triangle(p[i],p[j]);
            else ans-=c.area_triangle(p[i],p[j]);
        }
        return fabs(ans);
    }
    

    

    int relationcircle(circle c){
        getline();
        int x = 2;
        if(relationpoint(c.center)!=1) return 0;
        for(int i=0;i<n;i++){
            if(c.relationtoseg(l[i])==2) return 0;
            if(c.relationtoseg(l[i])==1) x=1;
        }
        return x;
    }
};
bool OnSeg(point P,line L);

circle CroCircle(int n);

pair<ball,ball> lineToBall(ball par,ball bp,ball sp);

ball CroBall(int n);





int cmpgra(point a,point b);

int graham(int n);






point p[maxn],s[maxn];

ball bl[maxn];


int prime[maxn];
void isprime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=maxn;i++){
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

struct sox{
    long long x,y;
    int t;
}aa[maxn];












int cmp21(sox a,sox b){
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);






    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>aa[i].x>>aa[i].y;
        aa[i].t=i;
    }








    sort(aa,aa+n,cmp21);






    int ans=0;
    for(int i=2;i<n;i++){
        if(sgn((aa[i].y-aa[0].y)*(aa[i].x-aa[1].x)-(aa[i].y-aa[1].y)*(aa[i].x-aa[0].x))==0) continue ;
        ans = aa[i].t;break;
    }
    cout<<aa[0].t+1<<" "<<aa[1].t+1<<" "<<ans+1<<'\n';
    return 0;
}
inline void read(int &a){
static char c;
bool flag=false;
while (((c=getchar())<'0'||c>'9'))flag=1;a=c-'0';
while ((c=getchar())>='0'&&c<='9') a=(a<<3)+(a<<1)+c-'0';if(flag)a=-a;}
bool OnSeg(point P,line L){
    return
        sgn((L.s-P)^(L.e-P)) == 0 &&
        sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
        sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

circle CroCircle(int n){
    random_shuffle(p+1,p+n+1);
    circle tep;
    tep.center=p[1];
    tep.r=0;
    for(int i=2;i<=n;i++){
        if(dist(p[i],tep.center)>tep.r+eps){
            tep.center=p[i];
            tep.r=0;
            for(int j=1;j<i;j++){
                if(dist(p[j],tep.center)>tep.r+eps){
                    tep.center.x=(p[i].x+p[j].x)/2;
                    tep.center.y=(p[i].y+p[j].y)/2;
                    tep.r=dist(p[i],p[j])/2;
                    for(int k=1;k<j;k++){
                        if(dist(p[k],tep.center)>tep.r+eps){
                            triangle t;
                            t.v[0]=p[i];
                            t.v[1]=p[j];
                            t.v[2]=p[k];
                            tep.outtriangle(t.v[0],t.v[1],t.v[2]);}}}}}}
    return tep;
}
ball CroBall(int n){
    db step=100,mt;
    int s=0;
    ball z;
    z.x=z.y=z.z=0;
    z.r=1e30;
    while(step>eps){
        for(int i=1;i<=n;i++)
            if(balldis(z,bl[s])<balldis(z,bl[i])) s=i;
        mt=balldis(z,bl[s]);
        z.r=min(z.r,mt);
        z.x+=(bl[s].x-z.x)/mt*step;
        z.y+=(bl[s].y-z.y)/mt*step;
        z.z+=(bl[s].z-z.z)/mt*step;
        step*=0.98;
    }
    return z;
}
pair<ball,ball> lineToBall(ball par,ball bp,ball sp){
    ball ans1,ans2;
    if(bp.x!=sp.x){
        db k_xy=(sp.y-bp.y)/(sp.x-bp.x);
        db b_xy=bp.y-k_xy*bp.x;
        db k_zx=(sp.z-bp.z)/(sp.x-bp.x);
        db b_zx=bp.z-k_zx*bp.x;
        db A = 1+k_xy*k_xy+k_zx*k_zx;
        db B = 2*k_xy*(b_xy-par.y)+2*k_zx*(b_zx-par.z)-2*par.x;
        db C = par.x*par.x+(b_xy-par.y)*(b_xy-par.y)+(b_zx-par.z)*(b_zx-par.z)-par.r*par.r;
        ans1.x=(-B+sqrt(B*B-4*A*C))/(2*A);
        ans1.y=k_xy*ans1.x+b_xy;
        ans1.z=k_zx*ans1.x+b_zx;
        ans2.x=(-B-sqrt(B*B-4*A*C))/(2*A);
        ans2.y=k_xy*ans2.x+b_xy;
        ans2.z=k_zx*ans2.x+b_zx;
    }else{

        if(bp.y!=sp.y){
            db k_zy=(sp.z-bp.z)/(sp.y-bp.y);
            db b_zy=sp.z-k_zy*sp.y;
            db A = 1+k_zy*k_zy;
            db B = 2*k_zy*(b_zy-par.z)-2*par.y;
            db C = par.y*par.y+(b_zy-par.z)*(b_zy-par.z)-(bp.x-par.x)*(bp.x-par.x)-par.r*par.r;
            ans1.x=bp.x;
            ans1.y=(-B+sqrt(B*B-4*A*C))/(2*A);
            ans1.z=k_zy*ans1.y+b_zy;
            ans2.x=bp.x;
            ans2.y=(-B-sqrt(B*B-4*A*C))/(2*A);
            ans2.z=k_zy*ans1.y+b_zy;
        }else{

            if(bp.z!=sp.z){
                ans1.x=bp.x;
                ans1.y=bp.y;
                ans1.z=par.z+sqrt(par.r*par.r-(bp.x-par.x)*(bp.x-par.x)-(bp.y-par.y)*(bp.y*par.y));
                ans2.x=bp.x;
                ans2.y=bp.y;
                ans2.z=par.z-sqrt(par.r*par.r-(bp.x-par.x)*(bp.x-par.x)-(bp.y-par.y)*(bp.y*par.y));
            }
            else{
                ans1.x=ans2.x=bp.x;
                ans1.y=ans2.y=bp.y;
                ans1.z=ans2.z=bp.z;
            }
        }
    }
    return make_pair(ans1,ans2);
}

int cmpgra(point a,point b){
    db x = cross(p[1],a,b);
    if(x>0) return 1;

    if(x==0&&dist(a,p[1])<dist(b,p[1])) return 1;

    return 0;
}
int graham(int n){












    int k=1;
    for(int i=2;i<=n;i++)
        if(p[i].y<p[k].y||(p[i].y==p[k].y&&p[i].x<p[k].x))k=i;
    swap(p[1],p[k]);

    sort(p+2,p+1+n,cmpgra);
    s[1]=p[1];s[2]=p[2];
    int t=2;
    for(int i=3;i<=n;i++){

        while(t>=2&&cross(s[t-1],s[t],p[i])<=0) t--;
        s[++t]=p[i];
    }
    return t;
}
