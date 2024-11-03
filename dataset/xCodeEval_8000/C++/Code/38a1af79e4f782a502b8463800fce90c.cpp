








#include<functional>
#include<algorithm>
#include<iostream>


#include<iomanip>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<cstddef>
#include<cstdio>
#include<memory>
#include<vector>
#include<cctype>
#include<string>
#include<cmath>
#include<queue>
#include<deque>
#include<ctime>
#include<stack>
#include<map>
#include<set>

#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef long long ll;

using namespace std;

const int MAXN=1e3+10;
const double eps=1e-8;
const double pi=acos(-1.0);
const ll INF=0x3f3f3f3f3f3f3f3f;

inline int dcmp(double x){
	if(fabs(x)<eps)	return 0;
	return (x>0? 1: -1);
}

inline double sqr(double x){ return x*x; }

struct Point{
	double x,y;
	Point(){ x=0,y=0; }
	Point(double _x,double _y):x(_x),y(_y){}
	void input(){ scanf("%lf%lf",&x,&y); }
	void output(){ printf("%.2f %.2f\n",x,y); }
	friend istream &operator >>(istream &os,Point &b){
		os>>b.x>>b.y;
		return os;
	}
	friend ostream &operator <<(ostream &os,Point &b){
		os<<b.x<<' '<<b.y;
		return os;
	}
	bool operator ==(const Point &b)const{
		return (dcmp(x-b.x)==0&&dcmp(y-b.y)==0);
	}
	bool operator !=(const Point &b)const{
		return !((dcmp(x-b.x)==0&&dcmp(y-b.y)==0));
	}
	bool operator <(const Point &b)const{
		return (dcmp(x-b.x)==0? dcmp(y-b.y)<0 : x<b.x);
	}
	double operator ^(const Point &b)const{		

		return x*b.y-y*b.x;
	}
	double operator *(const Point &b)const{		

		return x*b.x+y*b.y;
	}
	Point operator +(const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	Point operator *(double a){
		return Point(x*a,y*a);
	}
	Point operator /(double a){
		return Point(x/a,y/a);
	}
	double len2(){	

		return sqr(x)+sqr(y);
	}
	double len(){   

		return sqrt(len2());
	}
	double polar(){	

		return atan2(y,x);	 

	}
	Point change_len(double r){	

		double l=len();
		if(dcmp(l)==0)	return *this;  

		return Point(x*r/l,y*r/l);
	}
	Point rotate_left(){	

		return Point(-y,x);
	}
	Point rotate_right(){	

		return Point(y,-x);
	}
	Point rotate(Point p,double ang){	

		Point v=(*this)-p;
		double c=cos(ang),s=sin(ang);
		return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
	}
	Point normal(){		

		return Point(-y/len(),x/len());
	}
};

inline double cross(Point a,Point b){	

	return a.x*b.y-a.y*b.x;
}

inline double dot(Point a,Point b){	

	return a.x*b.x+a.y*b.y;
}

inline double dis(Point a,Point b){	

	Point p=b-a;	return p.len();
}

inline double dis2(Point a,Point b){	

	Point p=b-a;	return p.len2();
}

double rad_degree(double rad){	

	return rad/pi*180;
}

double degree_rad(double deg){	

	return deg/180*pi;
}

double rad(Point a,Point b){	

	return fabs(atan2(fabs(cross(a,b)),dot(a,b)));
}

bool is_parallel(Point a,Point b){	

	double p=rad(a,b);
	return dcmp(p)==0||dcmp(p-pi)==0;
}

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e):s(_s),e(_e){} 

	Line(Point p,double ang){	

		s=p;
		if(dcmp(ang-pi/2)==0){
			e=s+Point(0,1);
		}
		else{
			e=s+Point(1,tan(ang));
		}
	}
	Line(double a,double b,double c){	

		if(dcmp(a)==0){
			s=Point(0,-c/b);
			e=Point(1,-c/b);
		}
		else if(dcmp(b)==0){
			s=Point(-c/a,0);
			e=Point(-c/a,1);
		}
		else{
			s=Point(0,-c/b);
			e=Point(1,(-c-a)/b);
		}
	}
	void input(){
		s.input();
		e.input();
	}
	void adjust(){
		if(e<s)	swap(e,s);
	}
	double length(){	

		return dis(s,e);
	}
	double polar(){	

		return atan2(e.y-s.y,e.x-s.x);	 

	}
	double angle(){		

		double k=atan2(e.y-s.y,e.x-s.x);
		if(dcmp(k)<0)	k+=pi;
		if(dcmp(k-pi)==0)	k-=pi;
		return k;
	}
	Point operator &(const Line &b)const{	 

		Point res=s;
		double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x+=(e.x-s.x)*t;
		res.y+=(e.y-s.y)*t;
		return res;
	}
};

int relation(Point p,Line l){	

	int c=dcmp(cross(p-l.s,l.e-l.s));
	if(c<0)	return 1;
	else if(c>0)	return 2;
	else	return 3;
}

bool point_on_seg(Point p,Line l){	

	return dcmp(cross(p-l.s,l.e-l.s))==0&&dcmp(dot(p-l.s,p-l.e)<=0);	

}

bool is_parallel(Line a,Line b){	

	return is_parallel(a.e-a.s,b.e-b.s);
}

int seg_cross_seg(Line a,Line v){	

	int d1=dcmp(cross(a.e-a.s,v.s-a.s));
    int d2=dcmp(cross(a.e-a.s,v.e-a.s));
    int d3=dcmp(cross(v.e-v.s,a.s-v.s));
    int d4=dcmp(cross(v.e-v.s,a.e-v.s));
    if((d1^d2)==-2&&(d3^d4)==-2)    return 2;
    return (d1==0&&dcmp(dot(v.s-a.s,v.s-a.e))<=0)||
           (d2==0&&dcmp(dot(v.e-a.s,v.e-a.e))<=0)||
           (d3==0&&dcmp(dot(a.s-v.s,a.s-v.e))<=0)||
           (d4==0&&dcmp(dot(a.e-v.s,a.e-v.e))<=0);
}

int line_cross_seg(Line a,Line v){	

	int d1=dcmp(cross(a.e-a.s,v.s-a.s));
	int d2=dcmp(cross(a.e-a.s,v.e-a.s));
	if((d1^d2)==-2)	return 2;
	return (d1==0||d2==0);
}

int line_cross_line(Line a,Line v){	

	if(is_parallel(a,v))	return relation(a.e,v)==3;
	return 2;
}

Point line_intersection(Line a,Line v){	

	double a1=cross(v.e-v.s,a.s-v.s);
	double a2=cross(v.e-v.s,a.e-v.s);
	return Point((a.s.x*a2-a.e.x*a1)/(a2-a1),(a.s.y*a2-a.e.y*a1)/(a2-a1));
}

Point line_intersection(Line line,double a,double b,double c)	

{
    double u=fabs(a*line.s.x+b*line.s.y+c);
    double v=fabs(a*line.e.x+b*line.e.y+c);
    return Point((line.s.x*v+line.e.x*u)/(u+v),(line.s.y*v+line.e.y*u)/(u+v));
}

double point_to_line(Point p,Line a){	

	return fabs(cross(p-a.s,a.e-a.s)/a.length());
}

double point_to_seg(Point p,Line a){	

	if(dcmp(dot(p-a.s,a.e-a.s))<0||dcmp(dot(p-a.e,a.s-a.e))<0)
		return min(dis(p,a.e),dis(p,a.s));
	return point_to_line(p,a);
}

Point projection(Point p,Line a){		

	return a.s+(((a.e-a.s)*dot(a.e-a.s,p-a.s))/(a.e-a.s).len2());
}

Point symmetry(Point p,Line a){			

	Point q=projection(p,a);
	return Point(2*q.x-p.x,2*q.y-p.y);
}

Line vector_move_inward(Line line,double d)		

{
    double len=line.length();
    Point p((line.s.y-line.e.y)*d/len,(line.e.x-line.s.x)*d/len);
    return Line(line.s+p,line.e+p);
}

struct Circle{
	Point p;
	double r;
	Circle(){}
	Circle(Point _p,double _r):p(_p),r(_r){}
	Circle(double a,double b,double _r){
		p=Point(a,b);
		r=_r;
	}
	void input(){
		p.input();
		scanf("%lf",&r);
	}
	void output(){
		p.output();
		printf("%.2f\n",r);
	}
	bool operator ==(const Circle &a)const{
		return p==a.p&&(dcmp(r-a.r)==0);
	}
	double area(){
		return pi*r*r;
	}
	double circumference(){
		return 2*pi*r;
	}
};

int relation(Point p,Circle a){	

	double d=dis(p,a.p);
	if(dcmp(d-a.r)==0)	return 1;
	return (dcmp(d-a.r)<0? 2: 0);
}

int relation(Line a,Circle b){	

	double p=point_to_line(b.p,a);
	if(dcmp(p-b.r)==0)	return 1;
	return (dcmp(p-b.r)<0? 2: 0);
}

int relation(Circle a,Circle v){	

	double d=dis(a.p,v.p);
	if(dcmp(d-a.r-v.r)>0)	return 5;
	if(dcmp(d-a.r-v.r)==0)	return 4;
	double l=fabs(a.r-v.r);
	if(dcmp(d-l)>0)		return 3;
	if(dcmp(d-l)==0)	return 2;
	return 1;
}

Circle triangle_out_circle(Point a,Point b,Point c){	

	Line u=Line((a+b)/2,((a+b)/2)+(b-a).rotate_left());
	Line v=Line((b+c)/2,((b+c)/2)+(c-b).rotate_left());
	Point p=line_intersection(u,v);
	double r=dis(p,a);
	return Circle(p,r);
}

Circle triangle_in_circle(Point a,Point b,Point c){	

	Line u,v;
	double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
	u.s=a;
	u.e=u.s+Point(cos((n+m)/2),sin((n+m)/2));
	v.s=b;
	m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
	v.e=v.s+Point(cos((n+m)/2),sin((n+m)/2));
	Point p=line_intersection(u,v);
	double r=point_to_seg(p,Line(a,b));
	return Circle(p,r);
}

int circle_intersection(Circle a,Circle v,Point &p1,Point &p2){	

    int rel=relation(a,v);									    

	if(rel==1||rel==5)	return 0;
	double d=dis(a.p,v.p);
	double l=(d*d+a.r*a.r-v.r*v.r)/(2*d);
	double h=sqrt(a.r*a.r-l*l);
	Point tmp=a.p+(v.p-a.p).change_len(l);
	p1=tmp+((v.p-a.p).rotate_left().change_len(h));
	p2=tmp+((v.p-a.p).rotate_right().change_len(h));
	if(rel==2||rel==4)	return 1;
	return 2;
}

int line_circle_intersection(Line v,Circle u,Point &p1,Point &p2){	

	if(!relation(v,u))	return 0;									

	Point a=projection(u.p,v);
	double d=point_to_line(u.p,v);
	d=sqrt(u.r*u.r-d*d);
	if(dcmp(d)==0){
		p1=a,p2=a;
		return 1;
	}
	p1=a+(v.e-v.s).change_len(d);
	p2=a-(v.e-v.s).change_len(d);
	return 2;
}

int get_circle(Point a,Point b,double r1,Circle &c1,Circle &c2){	

	Circle x(a,r1),y(b,r1);											

	int t=circle_intersection(x,y,c1.p,c2.p);
	if(!t)	return 0;
	c1.r=c2.r=r1;
	return t;
}

int get_circle(Line u,Point q,double r1,Circle &c1,Circle &c2){		

	double d=point_to_line(q,u);
	if(dcmp(d-r1*2)>0)	return 0;
	if(dcmp(d)==0){
		c1.p=q+((u.e-u.s).rotate_left().change_len(r1));
		c2.p=q+((u.e-u.s).rotate_right().change_len(r1));
		c1.r=c2.r=r1;
		return 2;
	}
	Line u1=Line(u.s+(u.e-u.s).rotate_left().change_len(r1),u.e+(u.e-u.s).rotate_left().change_len(r1));
	Line u2=Line(u.s+(u.e-u.s).rotate_right().change_len(r1),u.e+(u.e-u.s).rotate_right().change_len(r1));
	Circle cc=Circle(q,r1);
	Point p1,p2;
	if(!line_circle_intersection(u1,cc,p1,p2))	line_circle_intersection(u2,cc,p1,p2);
	c1=Circle(p1,r1);
	if(p1==p2){
		c2=c1;
		return 1;
	}
	c2=Circle(p2,r1);
	return 2;
}

int get_circle(Line u,Line v,double r1,Circle &c1,Circle &c2,Circle &c3,Circle &c4){	

	if(is_parallel(u,v))	return 0;
	Line u1=Line(u.s+(u.e-u.s).rotate_left().change_len(r1),u.e+(u.e-u.s).rotate_left().change_len(r1));
	Line u2=Line(u.s+(u.e-u.s).rotate_right().change_len(r1),u.e+(u.e-u.s).rotate_right().change_len(r1));
	Line v1=Line(v.s+(v.e-v.s).rotate_left().change_len(r1),v.e+(v.e-v.s).rotate_left().change_len(r1));
	Line v2=Line(v.s+(v.e-v.s).rotate_right().change_len(r1),v.e+(v.e-v.s).rotate_right().change_len(r1));
	c1.r=c2.r=c3.r=c4.r=r1;
	c1.p=line_intersection(u1,v1);
	c2.p=line_intersection(u1,v2);
	c3.p=line_intersection(u2,v1);
	c4.p=line_intersection(u2,v2);
	return 4;
}

int get_circle(Circle cx,Circle cy,double r1,Circle &c1,Circle &c2){	

	Circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
	int t=circle_intersection(x,y,c1.p,c2.p);
	if(!t)	return 0;
	c1.r=c2.r=r1;
	return t;
}

Circle get_circle(Point a,Point b,double k){	

	double k2=k*k;
	double d=(2*b.x-2*a.x/k2)/((1/k2)-1);
	double e=(2*b.y-2*a.y/k2)/((1/k2)-1);
	double f=(a.x*a.x/k2-b.x*b.x+a.y*a.y/k2-b.y*b.y)/((1/k2)-1);
	double cx=-d/2,cy=-e/2;
	double r=sqrt((d*d+e*e)/4-f);
	return Circle(Point(cx,cy),r);
}

bool get_circle(Point a,Point b,double r,Point &res1,Point &res2){	

	if(dcmp(dis(a,b)-2*r)>0)	return 0;
	Point mid((a.x+b.x)/2,(a.y+b.y)/2);
	double angle=atan2(b.y-a.y,b.x-a.x),d=sqrt(r*r-sqr(dis(a,b)/2));
	res1=Point(mid.x+d*sin(angle),mid.y-d*cos(angle));
	res2=Point(mid.x-d*sin(angle),mid.y+d*cos(angle));
	return 1;
}

Circle get_circle(Point p1,Point p2,Point p3){	

	if(dcmp(cross(p2-p1,p3-p1))==0){
		if(p2<p1)	swap(p1,p2);
		if(p3<p1)	swap(p1,p3);
		if(p3<p2)	swap(p2,p3);
		return Circle((p1+p3)/2,dis(p1,p3)/2);
	}
	double x1=p1.x,x2=p2.x,x3=p3.x;
	double y1=p1.y,y2=p2.y,y3=p3.y;
	double a=x1-x2,b=y1-y2,c=x1-x3,d=y1-y3;
	double e=((x1*x1-x2*x2)+(y1*y1-y2*y2))/2;
	double f=((x1*x1-x3*x3)+(y1*y1-y3*y3))/2;
	double delta=b*c-a*d;
	Point pc=Point(-(d*e-b*f)/delta,-(a*f-c*e)/delta);
	return Circle(pc,dis(pc,p1));
}

int tan_line(Point q,Circle a,Line &u,Line &v){	

	int x=relation(q,a);
	if(x==2)	return 0;
	if(x==1){
		u=Line(q,q+(q-a.p).rotate_left());
		v=u;
		return 1;
	}
	double d=dis(a.p,q);
	double l=a.r*a.r/d;
	double h=sqrt(a.r*a.r-l*l);
	u=Line(q,a.p+(q-a.p).change_len(l)+(q-a.p).rotate_left().change_len(h));
	v=Line(q,a.p+(q-a.p).change_len(l)+(q-a.p).rotate_right().change_len(h));
	return 2;
}

double area_circle(Circle a,Circle v){	

	int rel=relation(a,v);
	if(rel>=4)	return 0;
	if(rel<=2)	return min(a.area(),v.area());
	double d=dis(a.p,v.p);
	double hf=(a.r+v.r+d)/2;
	double ss=2*sqrt(hf*(hf-a.r)*(hf-v.r)*(hf-d));
	double a1=acos((a.r*a.r+d*d-v.r*v.r)/(2*a.r*d));
	a1=a1*a.r*a.r;
	double a2=acos((v.r*v.r+d*d-a.r*a.r)/(2*v.r*d));
	a2=a2*v.r*v.r;
	return a1+a2-ss;
}

double circle_traingle_area(Point a,Point b,Circle c){	

	Point p=c.p;
	double r=c.r;
	if(dcmp(cross(p-a,p-b))==0)	return 0;
	Point q[5];
	int len=0;
	q[len++]=a;
	Line l(a,b);
	Point p1,p2;
	if(line_circle_intersection(l,c,q[1],q[2])==2){
		if(dcmp(dot(a-q[1],b-q[1]))<0)	q[len++]=q[1];
		if(dcmp(dot(a-q[2],b-q[2]))<0)	q[len++]=q[2];
	}
	q[len++]=b;
	if(len==4&&dcmp(dot(q[0]-q[1],q[2]-q[1]))>0)	swap(q[1],q[2]);
	double res=0;
	for(int i=0;i<len-1;i++){
		if(relation(q[i],c)==0||relation(q[i+1],c)==0){
			double arg=rad(q[i]-p,q[i+1]-p);
			res+=r*r*arg/2;
		}
		else	res+=fabs(cross(q[i]-p,q[i+1]-p))/2;
	}
	return res;
}

int circle_cover_point(Point *p,int n,double r){		

	int ans=1;		pair<double,int>angle[MAXN];
	for(int i=0;i<n;i++){
		int m=0;	double d;
		for(int j=0;j<n;j++)
			if(dcmp((d=dis(p[i],p[j]))-2*r)<=0&&i!=j){
				double delta=acos(d/(2*r)),polar=(p[j]-p[i]).polar();
				angle[m++]=make_pair(polar-delta,1);
				angle[m++]=make_pair(polar+delta,-1);
			}
		sort(angle,angle+m);
		for(int j=0,sum=1;j<m;j++){
			sum+=angle[j].se;
			ans=max(ans,sum);
		}
	}
	return ans;
}

Circle circle_min_conver(Point *p,int n){	

	Point center=p[0];	double r=0;
	random_shuffle(p,p+n);
	for(int i=1;i<n;i++){
		if(dcmp(dis(center,p[i])-r)>0){
			center=p[i],r=0;
			for(int j=0;j<i;j++){
				if(dcmp(dis(center,p[j])-r)>0){
					center=(p[i]+p[j])/2,r=dis(center,p[j]);
					for(int k=0;k<j;k++){
						if(dcmp(dis(center,p[k])-r)>0){
							center=get_circle(p[i],p[j],p[k]).p;
							r=dis(center,p[i]);
						}
					}
				}
			}
		}
	}
	return Circle(center,r);
}

bool counter_wise(Point *p,int n){			

	for(int i=1;i<n-1;i++)
		if(dcmp(cross(p[i]-p[i-1],p[i+1]-p[i-1]))>0)	return 0;
		else if(dcmp(cross(p[i]-p[i-1],p[i+1]-p[i-1]))<0){
			reverse(p,p+n);
			return 1;
		}
	return 1;
}

bool clock_wise(Point *p,int n){			

	for(int i=1;i<n-1;i++)
		if(dcmp(cross(p[i]-p[i-1],p[i+1]-p[i-1]))<0)	return 0;
		else if(dcmp(cross(p[i]-p[i-1],p[i+1]-p[i-1]))>0){
			reverse(p,p+n);
			return 1;
		}
	return 1;
}

bool is_convex(Point *p,int n){	

	for(int i=0;i<n;i++){
		int j=(i+1)%n;
		int k=(j+1)%n;
		if(dcmp(cross(p[j]-p[i],p[k]-p[j]))==-1)	return 0;
	}
	return 1;
}

double polygon_area(Point *p,int n){	

	double area=0;
	for(int i=1;i<n-1;i++)	area+=cross(p[i]-p[0],p[i+1]-p[0]);
	return fabs(area/2);
}

double polygon_area(vector<Point> p){    

    int n=p.size(); double area=0;
    for(int i=1;i<n-1;i++)  area+=cross(p[i]-p[0],p[i+1]-p[0]);
    return fabs(area/2);
}

double convex_polygon_intersection_area(Point *a,Point *b,int na,int nb){	

	Point p[MAXN],tmp[MAXN];
    int tn,sflag,eflag;
    a[na]=a[0],b[nb]=b[0];
    for(int i=0;i<=nb;i++)	p[i]=b[i];
    for(int i=0;i<na&&nb>2;i++){
        sflag=dcmp(cross(a[i+1]-a[i],p[0]-a[i]));
        for(int j=tn=0;j<nb;j++,sflag=eflag){
            if(sflag>=0)	tmp[tn++]=p[j];
            eflag=dcmp(cross(a[i+1]-a[i],p[j+1]-a[i]));
            if((sflag^eflag)==-2)	tmp[tn++]=line_intersection(Line(a[i],a[i+1]),Line(p[j],p[j+1]));
        }
        for(int j=0;j<tn;j++)	p[j]=tmp[j];
        nb=tn,p[nb]=p[0];
    }
    if(nb<3)	return 0;
    return polygon_area(p,nb);
}

double simple_polygon_intersection_area(Point *a,Point *b,int na,int nb){	

    Point t1[4],t2[4];
    double res=0; 	int num1,num2;
    a[na]=t1[0]=a[0],b[nb]=t2[0]=b[0];
    for(int i=2;i<na;i++){
        t1[1]=a[i-1],t1[2]=a[i];
        num1=dcmp(cross(t1[1]-t1[0],t1[2]-t1[0]));
        if(num1<0)	swap(t1[1],t1[2]);
        for(int j=2;j<nb;j++){
            t2[1]=b[j-1],t2[2]=b[j];
            num2=dcmp(cross(t2[1]-t2[0],t2[2]-t2[0]));
            if(num2<0)	swap(t2[1],t2[2]);
            res+=convex_polygon_intersection_area(t1,t2,3,3)*num1*num2;
        }
    }
    return res;
}

double convex_diameter(Point *p,int n){		

	if(n==1)	return 0;
	if(n==2)	return dis(p[0],p[1]);
	if(n==3)	return max(dis(p[0],p[1]),max(dis(p[1],p[2]),dis(p[2],p[0])));
	counter_wise(p,n);
	double ans=0;	p[n]=p[0];
	for(int i=0,j=2;i<n;i++){
		while(dcmp(cross(p[i+1]-p[i],p[j]-p[i])-cross(p[i+1]-p[i],p[j+1]-p[i]))<0)	j=(j+1)%n;
		ans=max(ans,max(dis(p[i],p[j]),dis(p[i+1],p[j])));
	}
	return ans;
}

double convex_min_distance(Point *a,int n,Point *b,int m){		

	int u=0,v=0,tmp;	double ans=INF;
	counter_wise(a,n);	a[n]=a[0];
	counter_wise(b,m);	b[m]=b[0];
	for(int i=0;i<n;i++)
		if(dcmp(a[u].y-a[i].y)>0)
			u=i;
	for(int i=0;i<m;i++)
		if(dcmp(b[v].y-b[i].y)<0)
			v=i;
	for(int i=0;i<n;i++){
		while((tmp=dcmp(cross(a[u+1]-a[u],b[v]-a[u])-cross(a[u+1]-a[u],b[v+1]-a[u])))<0)	v=(v+1)%m;
		if(tmp==1)	ans=min(ans,point_to_seg(b[v],Line(a[u],a[u+1])));
		else	ans=min(ans,min(min(point_to_seg(a[u],Line(b[v],b[v+1])),point_to_seg(a[u+1],Line(b[v],b[v+1]))),min(point_to_seg(b[v],Line(a[u],a[u+1])),point_to_seg(b[v+1],Line(a[u],a[u+1])))));
		u=(u+1)%n;
	}
	return ans;
}

double convex_rectangle_area(Point *p,int n){		

	if(n<=2)	return 0;
	counter_wise(p,n);
	p[n]=p[0];
	int l,r=1,t=1;	double ans=INF;
	for(int i=0;i<n;i++){
		while(dcmp(cross(p[i+1]-p[i],p[t]-p[i])-cross(p[i+1]-p[i],p[t+1]-p[i]))<0)	t=(t+1)%n;
		while(dcmp(dot(p[i+1]-p[i],p[r]-p[i])-dot(p[i+1]-p[i],p[r+1]-p[i]))<0)	r=(r+1)%n;
		if(!i)	l=r;
		while(dcmp(dot(p[i+1]-p[i],p[l]-p[i])-dot(p[i+1]-p[i],p[l+1]-p[i]))>=0)	l=(l+1)%n;
		double d=dis(p[i+1],p[i]);
		ans=min(ans,cross(p[i+1]-p[i],p[t]-p[i])*(dot(p[i+1]-p[i],p[r]-p[i])-dot(p[i+1]-p[i],p[l]-p[i]))/d/d);
	}
	return ans;
}

int relation(Point *p,int n,Point a){	

	int w=0;	p[n]=p[0];				

	for(int i=0;i<n;i++){					

		if(a==p[i]||a==p[i+1])	return 3;   

		if(point_on_seg(a,Line(p[i+1],p[i])))	return 2;
		int k=dcmp(cross(p[i+1]-p[i],a-p[i]));
		int d1=dcmp(p[i].y-a.y);
		int d2=dcmp(p[i+1].y-a.y);
		if(k>0&&d1<=0&&d2>0)	w++;
		if(k<0&&d2<=0&&d1>0)	w--;
	}
	if(w!=0)	return 1;
	return 0;
}

bool point_in_convex(Point *p,int n,Point t){		

	if(dcmp(cross(t-p[0],p[1]-p[0]))>0||dcmp(cross(p[n-1]-p[0],t-p[0]))>0)	return 0;	

	int k=lower_bound(p+1,p+n,t,[&](Point x,Point y){ return dcmp(cross(x-p[0],y-p[0]))>0; })-(p+1);
	return dcmp(cross(p[(k+1)%n]-p[k],t-p[k]))>=0;
}

void polygon_cut(Point *p,int &n,Line u){	

	int top=0;	Point tmp[MAXN];	p[n]=p[0];
	for(int i=0;i<n;i++){
		int d1=dcmp(cross(u.e-u.s,p[i]-u.s));
		int d2=dcmp(cross(u.e-u.s,p[i+1]-u.s));
		if(d1>=0)	tmp[top++]=p[i];
		if(d1*d2<0)	tmp[top++]=line_intersection(u,Line(p[i],p[i+1]));
	}
	for(int i=0;i<top;i++)	p[i]=tmp[i];
	n=top;
}

void polygon_cut(Point *p,int &n,double a,double b,double c){	

	int top=0;	Point tmp[MAXN];
	p[n]=p[0],p[n+1]=p[1];
	for(int i=1;i<=n;i++){
		if(a*p[i].x+b*p[i].y+c>-eps)	tmp[top++]=p[i];
		else{
			if(a*p[i-1].x+b*p[i-1].y+c>eps)
				tmp[top++]=line_intersection(Line(p[i-1],p[i]),Line(a,b,c));
			if(a*p[i+1].x+b*p[i+1].y+c>eps)
				tmp[top++]=line_intersection(Line(p[i],p[i+1]),Line(a,b,c));
		}
	}
	for(int i=0;i<top;i++)		p[i]=tmp[i];
	n=top;
}

double polygon_circumference(Point *p,int n){	

	double ans=0;	p[n]=p[0];
	for(int i=0;i<n;i++)	ans+=dis(p[i],p[i+1]);
	return ans;
}

double area_polygon_circle(Circle c,Point *p,int n){	

	double ans=0;
	for(int i=0;i<n;i++){
		int j=(i+1)%n;
		if(dcmp(cross(p[j]-c.p,p[i]-c.p))>=0)	ans+=circle_traingle_area(p[i],p[j],c);
		else	ans-=circle_traingle_area(p[i],p[j],c);
	}
	return fabs(ans);
}

Point centre_of_polygon(Point *p,int n){	

	double sum=0,sumx=0,sumy=0;
	Point p1=p[0],p2=p[1],p3;
	for(int i=2;i<n;i++){
		p3=p[i];
		double area=cross(p2-p1,p3-p2)/2;
		sum+=area;
		sumx+=(p1.x+p2.x+p3.x)*area;
		sumy+=(p1.y+p2.y+p3.y)*area;
		p2=p3;
	}
	return Point(sumx/(3*sum),sumy/(3*sum));
}

int convex_hull(Point *p,int n,Point *ch){	

	int m=0;
	Point tmp[MAXN];
	sort(p,p+n);
	for(int i=0;i<n;i++){
		while(m>1&&dcmp(cross(tmp[m-1]-tmp[m-2],p[i]-tmp[m-1]))<=0)	m--;
		tmp[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k&&dcmp(cross(tmp[m-1]-tmp[m-2],p[i]-tmp[m-1]))<=0)	m--;
		tmp[m++]=p[i];
	}
	if(n>1)	m--;
	for(int i=0;i<m;i++)	ch[i]=tmp[i];
	return m;
}

bool polar_cmp(Line a,Line b){		

	double x=a.polar(),y=b.polar();
	if(dcmp(x-y)==0)	return dcmp(cross(a.e-a.s,b.e-a.s))<0;
	return dcmp(x-y)<0;
}

int half_plane_intersection(Line *line,int n,Point *ch){	

	Line L[MAXN],que[MAXN];
	int head=0,tail=1,cnt=1,num=0;
	for(int i=0;i<n;i++)	L[i]=line[i];
	sort(L,L+n,polar_cmp);
	for(int i=1;i<n;i++)
		if(dcmp(L[i].polar()-L[cnt-1].polar())!=0)
			L[cnt++]=L[i];
	que[0]=L[0],que[1]=L[1];
	for(int i=2;i<cnt;i++){
		while(tail>head&&relation(que[tail]&que[tail-1],L[i])==2)	tail--;
		while(tail>head&&relation(que[head]&que[head+1],L[i])==2)	head++;
		que[++tail]=L[i];
	}
	while(tail>head&&relation(que[tail]&que[tail-1],que[head])==2)	tail--;
	while(tail>head&&relation(que[head]&que[head+1],que[tail])==2)	head++;
	if(tail-head<=1) return -1;
	for(int i=head;i<=tail;i++){
		int j=(i==tail? head: i+1);
		ch[num++]=que[i]&que[j];
	}
	return num;
}

double polygon_fermat_point(Point *p,int n,Point &res){		

    double T=1e10,ans=INF,delta=0.999;    Point before(-1,-1);
    while(T>eps){
        double k=2.0*pi*(rand()*1.0/RAND_MAX),sum1=0,sum2=0;
        Point cur(before.x+T*cos(k),before.y+T*sin(k));
        for(int i=0;i<n;i++)    sum1+=dis(p[i],before);
        for(int i=0;i<n;i++)    sum2+=dis(p[i],cur);
        if(dcmp(ans-sum1)>=0)    ans=sum1,res=before;
        if(dcmp(ans-sum2)>=0)    ans=sum2,res=cur;
        if(dcmp(sum1-sum2)>=0||exp((sum1-sum2)/T)>=(rand()*1.0/RAND_MAX))    before=cur;
        T*=delta;
    }
    return ans;
}

double sphere_distance(double r,double x1,double y1,double x2,double y2){	

	return r*acos(sin(y1)*sin(y2)+cos(y1)*cos(y2)*cos(x1-x2));
}

double f(double x){ return x*x+x; }	

double cal(double l,double r){ return (r-l)*(f(l)+f(r)+4*f((l+r)/2))/6; }	

double simpson(double l,double r,double ans){	

	double mid=(l+r)/2,ans1=cal(l,mid),ans2=cal(mid,r);
	if(fabs(ans1+ans2-ans)<=eps)	return ans1+ans2+(ans-ans1-ans2)/15;
	return simpson(l,mid,ans1)+simpson(mid,r,ans2);
}

bool merge_cmp(Point a,Point b){
    if(dcmp(a.y-b.y)==0)    return dcmp(a.x-b.x)<0;
    return dcmp(a.y-b.y)<0;
}
double point_merge(Point *p,int n){				

    if(n<=1)    return INF;
    int mid=n/2;	double x=p[mid].x;
    double d=min(point_merge(p,mid),point_merge(p+mid,n-mid));	

    inplace_merge(p,p+mid,p+n,merge_cmp);		

    vector<Point>b;	   

    for(int i=0;i<n;i++){						

        if(dcmp(fabs(p[i].x-x)-d)>=0)   continue;
        for(int j=0;j<b.size();j++){
            double dx=p[i].x-b[b.size()-j-1].x;
            double dy=p[i].y-b[b.size()-j-1].y;
            if(dcmp(dy-d)>=0)   break;
            d=min(d,sqrt(sqr(dx)+sqr(dy)));
        }
        b.pb(p[i]);
    }
    b.clear();
    return d;
}
double closest_pair(Point *p,int n){	

    sort(p,p+n);
    return point_merge(p,n);
}

int get_Minkowski(Point *a,int n,Point *b,int m,Point *p){	

	a[n]=a[0],b[m]=b[0];									

	Point s1[MAXN],s2[MAXN];
	for(int i=0;i<n;i++)	s1[i]=a[i+1]-a[i];
	for(int i=0;i<m;i++)	s2[i]=b[i+1]-b[i];
	p[0]=a[0]+b[0];
	int l=0,r=0,cnt=1;
	while(l<n&&r<m)	 p[cnt]=p[cnt-1]+(dcmp(cross(s1[l],s2[r]))>=0? s1[l++]: s2[r++]),cnt++;
	while(l<n)	p[cnt]=p[cnt-1]+s1[l++],cnt++;
	while(r<m)	p[cnt]=p[cnt-1]+s2[r++],cnt++;
	return cnt;
}

struct PSLG{    

    struct Edge{
        int from,to;
        double ang;
        Edge(){ ang=from=to=0; }
        Edge(int s,int t,double a){ from=s,to=t,ang=a; }
    };
    int n,m,face_cnt;   

    double area[MAXN];  

    Point point[MAXN];  

    vector<Edge>edge;
    vector<int>G[MAXN];
    vector<vector<Point> >face;
    int vis[2*MAXN],left[2*MAXN],pre[2*MAXN];   

    void Init(){
        face.clear();
        edge.clear();
        for(int i=0;i<n;i++)    G[i].clear();
        n=m=0;
    }
    PSLG(){ Init(); }
    void AddEdge(int from, int to){             

       edge.pb(Edge(from,to,(point[to]-point[from]).polar()));
       edge.pb(Edge(to,from,(point[from]-point[to]).polar()));
       m=edge.size();
       G[from].pb(m-2);
       G[to].pb(m-1);
    }
    void Build(){
        for(int u=0;u<n;u++){
            int d=G[u].size();
            for(int i=0;i<d;i++)
                for(int j=i+1;j<d;j++)
                    if(edge[G[u][i]].ang>edge[G[u][j]].ang)
                        swap(G[u][i],G[u][j]);
            for(int i=0;i<d;i++)    pre[G[u][(i+1)%d]]=G[u][i]; 

        }
        face_cnt=0; memset(vis,0,sizeof(vis));
        for(int u=0;u<n;u++){
            for(int i=0;i<G[u].size();i++){
                int e=G[u][i];
                if(!vis[e]){
                    face_cnt++;
                    vector<Point> polygon;
                    while(1){
                        vis[e]=1;
                        left[e]=face_cnt;
                        int from=edge[e].from;
                        polygon.pb(point[from]);
                        e=pre[e^1];         

                        if(e==G[u][i])  break;
                    }
                    face.pb(polygon);
               }
            }
        }
        for(int i=0;i<face_cnt;i++)  area[i]=polygon_area(face[i]);
    }
	vector<pair<double,int> >tmp[MAXN];
	void Insert(Line *line,int m){
		for(int i=0;i<m;i++){
	        for(int j=i+1;j<m;j++){
	            if(!is_parallel(line[i],line[j])){
	                Point inter=line[i]&line[j];
	                point[n++]=inter;
	                tmp[i].pb({dot(inter-line[i].s,line[i].e-line[i].s),n-1});
	                tmp[j].pb({dot(inter-line[j].s,line[j].e-line[j].s),n-1});
	            }
	        }
	        sort(tmp[i].begin(),tmp[i].end());
	        for(int j=1;j<tmp[i].size();j++)  AddEdge(tmp[i][j-1].se,tmp[i][j].se);
	    }
	    Build();
	}
};

struct Dynamic_convex_hull{
    typedef pair<double,double> PD;
    typedef set<PD>::iterator iter;
    set<PD>up,down;
    inline bool Inside(set<PD> &st,Point p){
        if(!st.size())  return 0;
        if(dcmp(p.x-st.begin()->fi)<0||dcmp(st.rbegin()->fi-p.x)<0) return 0;
        iter r=st.lower_bound(MP(p.x-eps,-INF));
        if(r!=st.end()&&dcmp(p.x-r->fi)==0)   return  dcmp(p.y-r->se)>=0;
        iter l=r;   l--;
        Point s(l->fi,l->se),t(r->fi,r->se);
        return dcmp(cross(t-s,p-s))>=0;
    }
    inline void Update(set<PD> &st,Point p){
        if(Inside(st,p))    return ;
        iter cur=st.lower_bound(MP(p.x-eps,-INF)),i,j;
        if(cur!=st.end()&&dcmp(p.x-cur->fi)==0)  st.erase(cur);
        st.insert(PD(p.x,p.y)); cur=st.lower_bound(MP(p.x-eps,p.y-eps));
        for(i=cur,i--,j=i,j--;i!=st.begin()&&cur!=st.begin();i=j,j--){
            Point s(j->fi,j->se),t(i->fi,i->se);
            if(dcmp(cross(t-s,p-s))<=0) st.erase(i);
            else    break;
        }
        for(i=cur,i++,j=i,j++;i!=st.end()&&j!=st.end();i=j,j++){
            Point s(j->fi,j->se),t(i->fi,i->se);
            if(dcmp(cross(t-s,p-s))>=0) st.erase(i);
            else    break;
        }
    }
    void Add(Point p){ Update(up,Point(p.x,-p.y)),Update(down,p); }
    bool Is_Inside(Point p){ return Inside(up,Point(p.x,-p.y))&Inside(down,p); }
}DC;


















int main(void){
    

    

    

    int n;  scanf("%d",&n);
    for(int i=0;i<n;i++){
        int op; scanf("%d",&op);
        Point p;    p.input();
        if(op==1)   DC.Add(p);
        else{
            if(DC.Is_Inside(p)) puts("YES");
            else    puts("NO");
        }
    }
	return 0;
}