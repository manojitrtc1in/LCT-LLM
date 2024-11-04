#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <utility>  
#include <cmath>  
#include <queue>  
#include <set>  
#include <map>  
#include <climits>  
#include <functional>  
#include <deque>  
#include <ctime>  
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
double eps=1e-8;
const int MAXN = 201000;
const double inf=1e12;
int n,m,cCnt,curCnt;






struct vec{
	int x,y;
	int index;
	vec(){
		x=y=0;
	}
	vec(double _x,double _y){
		x=_x;
		y=_y;
	}
	vec operator +(vec v){
		return vec(x+v.x,y+v.y);
	}
	vec operator -(vec v){
		return vec(x-v.x,y-v.y);
	}
	vec operator *(double v){
		return vec(x*v,y*v);
	}
	vec operator /(double v){
		return vec(x/v,y/v);
	}
	double operator *(vec v){
		return x*v.x+y*v.y;
	}
	double len(){
		return sqrt(x*x+y*y);
	}
	long long len_sqr(){
		return 1LL*x*x+1LL*y*y;
	} 
	vec rotate(double c){
		return vec(x*cos(c)-y*sin(c),x*sin(c)+y*cos(c));
	}
	vec turnc(double l){
		return (*this)*l/len();
	}
	vec rot90(){
		return vec(-y,x);
	}
	void read_cpp(){
		cin>>x>>y;
	}
	void read_c(){
		scanf("%lf%lf",&x,&y);
	}
};
struct Segment{
	vec b;
	vec v;
	double angle;
	Segment(){};
	Segment(vec _b,vec _v){
		b=_b;
		v=_v;
	}
	void get_angle(){angle=atan2(v.y,v.x);}
	friend bool operator < (Segment a,Segment b)
    {
        return a.angle<b.angle;
    }
}seg[MAXN];
int sgn(double x){
	if(x<-eps) return -1;
	if(x>eps) return 1;
	return 0;
}
vec lerp(vec a,vec b,double t){
	return a*(1-t)+b*t;
}
double cross(vec a,vec b){
	return a.x*b.y-a.y*b.x;
}
double dist(vec a,vec b){
	return (a-b).len();
}
double cross(vec a,vec b,vec c){
	return (a.x-b.x)*(a.y-c.y)-(a.y-b.y)*(a.x-c.x);
}
double get_angle(vec a,vec b){
	return fabs(atan2(fabs(cross(a,b)),a*b));
}
double dot(vec v1,vec v2){
    return v1.x * v2.x + v1.y * v2.y;
}
bool Quadratic(double A,double B,double C,double* t0,double* t1){
	double Delta=B*B-4.0*A*C;
	if(Delta<0.0) return false;
	double rootDelta=sqrt(Delta);
	double q;
	if(B<0) q=-0.5*(B-rootDelta);
	else    q=-0,5*(B+rootDelta);
	*t0=q/A;
	*t1=C/q;
	if(*t0>*t1) swap(*t0,*t1);
	return true;
}
bool point_on_segment(vec p,vec a,vec b){
	return sgn(cross(b-a,p-a))==0&&sgn((p-a)*(p-b))<=0;
}
bool setment_intersection_line(vec a,vec b,vec p,vec q){
	if(sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0) return 0;
	return sgn(cross(a-p,b-p))*(sgn(cross(a-q,b-q)))<=0;
} 
int line_intersection(vec a,vec b,vec p,vec q,vec &o,double *t=0){
	double U=cross(p-a,q-p);
	double D=cross(b-a,q-p);
	if(sgn(D)==0) return sgn(D)==0?2:0;
	o=a+(b-a)*(U/D);
	if(t) *t=U/D;
	return 1;
}
double point_to_segment(vec p,vec a,vec b){ 
	if(sgn(vec(a-b).len())==0) return vec(a-p).len();
	if(sgn(dot(vec(a-p),vec(a-b)))==-1) return vec(a-p).len();
	if(sgn(dot(vec(b-p),vec(b-a)))==-1) return vec(b-p).len();
	return fabs(cross(p,a,b)/vec(a-b).len());
}
bool cmpXY(vec a,vec b){
	if(sgn(a.x-b.x)) return a.x<b.x;
	return a.y<b.y;
}
bool point_in_polygon(vec *v,int n,vec c){
	double s=0;
	for(int i=0;i<n;i++)
	{
		if(point_on_segment(c,v[i],v[(i+1)%n])) return 1;
		vec a=v[i]-c,b=v[(i+1)%n]-c;
		double ang=acos(a*b/(a.len()*b.len()));
		s+=cross(a,b)<0?ang:-ang;
	}
	return sgn(s)!=0;
}
int convex_hull(vec *v,int n,vec *z){
	sort(v,v+n,cmpXY);
	int m=0;
	for(int i=0;i<n;i++)
	{
		while(m>1&&cross(z[m-1]-z[m-2],v[i]-z[m-2])<0) --m;
		z[m++]=v[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--)
	{
		while(m>k&&cross(z[m-1]-z[m-2],v[i]-z[m-2])<0) --m;
		z[m++]=v[i];
	}
	if(n>1) --m;
	return m;
}
double get_convex_area(vec *z,int n){
	double area=0;
	for(int i=1;i<n-1;i++)
	area+=cross(z[0]-z[i],z[0]-z[i+1]);
	return area/2;
}
int has_intersection(vec a,vec b,vec p,vec q){
	int d1=sgn(cross(b-a,p-a)),d2=sgn(cross(b-a,q-a));
	int d3=sgn(cross(q-p,a-p)),d4=sgn(cross(q-p,b-p));
	if(d1*d2<0&&d3*d4<0) return 1;
	if((d1==0&&point_on_segment(p,a,b))||
	   (d2==0&&point_on_segment(q,a,b))||
	   (d3==0&&point_on_segment(a,p,q))||
	   (d4==0&&point_on_segment(b,p,q)))
	    return -1;

	return 0;
}
void clockwise(vec* p,int n){
	for(int i=0;i<n-1;i++){
		double tmp=cross(vec(p[i+1]-p[i]),vec(p[i+2]-p[i]));
		if(sgn(tmp)==1) return;
		else if(sgn(tmp)==-1){
			reverse(p,p+n);
			return;
		}
	}
}
double min_dist_of_segments(vec a, vec b, vec c, vec d){
	double dist1=min(point_to_segment(c,a,b),point_to_segment(d,a,b));
	double dist2=min(point_to_segment(a,c,d),point_to_segment(b,c,d));
	return min(dist1,dist2);
}






bool OnLeft(Segment L,vec p){
    return cross(L.v,p-L.b)>0;

}
vec GetIntersection(Segment a,Segment b){
    vec u=a.b-b.b;
    double t=cross(b.v,u)/cross(a.v,b.v);
    return a.b+a.v*t;
}
int HalfplaneIntersection(Segment *L,int n,vec *poly){
    sort(L,L+n);
    int first,last;
    vec *p=new vec[n];
	Segment *q=new Segment[n];
    q[first=last=0]=L[0];
    for (int i=1 ;i<n ;i++)
    {
        while (first<last && !OnLeft(L[i],p[last-1])) last--;
        while (first<last && !OnLeft(L[i],p[first])) first++;
        q[++last]=L[i];
        if (sgn(cross(q[last].v,q[last-1].v))==0)
        {
            last--;
            if (OnLeft(q[last] , L[i].b)) q[last]=L[i];
        }
        if (first<last) p[last-1]=GetIntersection(q[last-1],q[last]);
    }
    while (first<last && !OnLeft(q[first],p[last-1])) last--;
    if (last-first<=1) return 0;
    p[last]=GetIntersection(q[last],q[first]);
    int m=0;
    for (int i=first ;i<=last ;i++) poly[m++]=p[i];
    return m;
}
int HalfPlane(double r,vec* p,vec* z){
	

    for(int i = 0; i < n; ++i){
        vec ta, tb, tt;
        tt.x = p[(i+1)%n].y - p[i].y;
        tt.y = p[i].x - p[(i+1)%n].x;
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        ta.x = p[i].x - tt.x;
        ta.y = p[i].y - tt.y;
        tb.x = p[(i+1)%n].x - tt.x;
        tb.y = p[(i+1)%n].y - tt.y;
        seg[i].b=ta;
        seg[i].v=tb-ta;
        seg[i].get_angle();
    }
    int k=HalfplaneIntersection(seg,n,z);
    

    return k;
}






double min_dist_of_convexs(vec* P,vec *Q,int n,int m){
	int yminP=0;
	int ymaxQ=0;
	for(int i=0;i<n;i++){
		if(P[i].y<P[yminP].y) yminP=i;
	} 
	for(int i=0;i<m;i++){
		if(Q[i].y>Q[ymaxQ].y) ymaxQ=i;
	}
	P[n]=P[0];
	Q[m]=Q[0];
	double tmp;
	double ans=inf;
	for(int i=0;i<n;i++)  
    {  
        while(tmp=cross(P[yminP+1],Q[ymaxQ+1],P[yminP])-cross(P[yminP+1],Q[ymaxQ],P[yminP])>eps)  
            ymaxQ=(ymaxQ+1)%m;  
        if(tmp<-eps) ans=min(ans,point_to_segment(P[yminP],P[yminP+1],Q[ymaxQ]));  
        else         ans=min(ans,min_dist_of_segments(P[yminP],P[yminP+1],Q[ymaxQ],Q[ymaxQ+1]));  
        yminP=(yminP+1)%n;  
    }  
    return ans; 
} 
double diameter_of_convex(vec *p,int n){
	int cnt=0;
	double mmax=0;
	for(int i=0;i<n;i++){
		while(cnt<n-1&&vec(p[i]-p[cnt]).len_sqr()<=vec(p[i]-p[cnt+1]).len_sqr()) cnt++;
			if(vec(p[i]-p[cnt]).len()>=mmax){
			mmax=vec(p[i]-p[cnt]).len();
		}
	}
	return mmax;
}
double width_of_convex(vec *p,int n){
	int cnt=0;
	double mmin=inf;
	for(int i=0;i<n;i++){
		while(cnt<n-1&&vec(p[i]-p[cnt]).len()<=vec(p[i]-p[cnt+1]).len()) cnt++;
		if(i==cnt) continue;
		mmin=min(vec(p[i]-p[cnt]).len(),mmin);
		mmin=min(point_to_segment(p[cnt],p[i],p[i+1]),mmin);
	}
	return mmin;
}




struct circle{
	vec c;
	double r;
	circle(){c=vec(0,0);r=0;}
	circle(vec _c,double _r){
		c=_c;
		r=_r;
	}
}; 


bool circle_line_intersection(circle c,vec a,vec b,double *t0,double *t1){
	vec d=b-a;
	double A=d*d;
	double B=d*(a-c.c)*2.0;
	double C=(a-c.c).len_sqr()-c.r*c.r;
	return Quadratic(A,B,C,t0,t1);
}
bool circle_circle_intersection(circle a,circle b,vec &p1,vec &p2){
	double d=(a.c-b.c).len();
	if(d>a.r+b.r||d<fabs(a.r-b.r)) return false;
	double l=((a.c-b.c).len_sqr()+a.r*a.r-b.r*b.r)/(2*d);
	double h=sqrt(a.r*a.r-l*l);
	vec vl=(b.c-a.c).turnc(l),vh=vl.rot90().turnc(h);
	p1=a.c+vl+vh;
	p2=a.c+vl-vh;
	return true;
}


double circle_triangle_intersection_area(circle c,vec a,vec b){
	if(sgn(cross(a-c.c,b-c.c))==0) return 0;
	vec q[5];
	int len=0;
	double t0,t1;
	q[len++]=a;
	if(circle_line_intersection(c,a,b,&t0,&t1)){
		if(0<=t0&&t1<=1) q[len++]=lerp(a,b,t0);
		if(0<=t1&&t1<=1) q[len++]=lerp(a,b,t1);
	}
	q[len++]=b;
	double s=0;
	for(int i=1;i<len;i++){
		vec z=(q[i-1]+q[i])/2;
		if((z-c.c).len_sqr()<=c.r*c.r)
			s+=fabs(cross(q[i-1]-c.c,q[i]-c.c))/2;
		else{
			s+=c.r*c.r*get_angle(q[i-1]-c.c,q[i]-c.c)/2;
		}
	}
	return s;
}
double circle_polygon_intersection_area(circle c,vec *v,int n){
	double s=0;
	for(int i=0;i<n;i++){
		s+=circle_triangle_intersection_area(c,v[i],v[(i+1)%n])*sgn(cross(v[i]-c.c,v[(i+1)%n]-c.c));
	}
	return s;
}




namespace kd_tree{
struct qnode {
    vec p;
    double dis;
    qnode() {}
    qnode(vec _p, double _dis) {
        p = _p;
        dis = _dis;
    }
    bool operator <(const qnode &b)const {
        if (dis != b.dis)return dis < b.dis;
        else return p.index < b.p.index;
    }
};
priority_queue<qnode>q;
inline bool cmpX(const vec &a, const vec &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.index < b.index);
}
inline bool cmpY(const vec &a, const vec &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x) || (a.y == b.y && a.x == b.x && a.index < b.index);
}
bool cmp(const vec &a, const vec &b, bool div) {
    return div ? cmpY(a, b) : cmpX(a, b);
}
struct Node{
	vec e;
	Node *lc,*rc;
	bool div;
}pool[MAXN],*tail,*root;
void init(){
	tail=pool;
}
Node *build(vec *a,int l,int r,bool div){
	if(l>=r) return NULL;
	Node *p=tail++;
	p->div=div;
	int mid=(l+r)>>1;
	nth_element(a+l,a+mid,a+r,div?cmpY:cmpX);
	p->e=a[mid];
	p->lc=build(a,l,mid,!div);
	p->rc=build(a,mid+1,r,!div);
	return p;
}
void search(vec p,Node *x,bool div,int m){
	if(x==NULL) return;
	if(cmp(p,x->e,div)){
		search(p,x->lc,!div,m);
		if(q.size()<m){
			q.push(qnode(x->e,(p-x->e).len_sqr()));
			search(p,x->rc,!div,m);
		}
		else{
			if((p-x->e).len_sqr()<=q.top().dis){
				q.push(qnode(x->e, (p-x->e).len_sqr()));
                q.pop();
			}
			if(!div){
				if ((x->e.x - p.x)*(x->e.x - p.x) <= q.top().dis)
                    search(p, x->rc, !div, m);
			}
			else{
				if ((x->e.y - p.y)*(x->e.y- p.y) <= q.top().dis)
                    search(p, x->rc, !div, m);
			}
		}
	}
	else{
		search(p,x->rc,!div,m);
		if(q.size()<m){
			q.push(qnode(x->e,(p-x->e).len_sqr()));
			search(p,x->lc,!div,m);
		}
		else{
			if((p-x->e).len_sqr()<=q.top().dis){
				q.push(qnode(x->e, (p-x->e).len_sqr()));
                q.pop();
			}
			if(!div){
				if ((x->e.x - p.x)*(x->e.x - p.x) <= q.top().dis)
                    search(p, x->lc, !div, m);
			}
			else{
				if ((x->e.y - p.y)*(x->e.y- p.y) <= q.top().dis)
                    search(p, x->lc, !div, m);
			}
		}
	}
}
void search(vec p,int m){
	while(!q.empty()) q.pop();
	search(p,root,0,m);
}
};



vec p[1005];
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
struct L{
	int up;
	int down;
	long long len;
	L(){};
	L(int _up,int _down,long long _len){
		up=_up;
		down=_down;
		len=_len;
	}
}line[2005*2005];
bool Cmp(L a,L b){
	if(a.up!=b.up) return a.up<b.up;
	if(a.down!=b.down) return a.down<b.down;
	return a.len<b.len;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) p[i].read_cpp();
	int cnt=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			vec d=vec(p[i]-p[j]);
			if(sgn(d.y)==0){
				line[++cnt]=L(fabs(d.x),d.y,d.len_sqr());
				continue;
			}
			if(sgn(d.y)<0) d=d*(-1);
			int m=gcd(fabs(d.x),d.y);
			line[++cnt]=L(d.x/m,d.y/m,d.len_sqr());
		}
	}
	sort(line+1,line+1+cnt,Cmp);
	int num=1;
	long long ans=0;
	for(int i=1;i<=cnt;i++){
		

		if(i==cnt||line[i].up!=line[i+1].up||line[i].down!=line[i+1].down||line[i].len!=line[i+1].len){
			ans+=num*(num-1)/2;
			num=1;
		}
		else num++;
	}
	cout<<ans/2<<endl;
    return 0;
}