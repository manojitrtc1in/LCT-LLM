#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=5e4+7;
const int maxp=5e4+7;
const double inf=1e100;
const double eps=1e-8;
const double pi =acos(-1.0);
int sgn(double x){
	if(fabs(x)<eps)return 0;
	return x>0?1:-1;
}


struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	bool operator ==(const Point& b){return !sgn(x-b.x)&&!sgn(y-b.y);}
	bool operator  <(const Point& b)const{return !sgn(x-b.x)?y<b.y:x<b.x;}
	double operator^(const Point& b){return x*b.y-y*b.x;}

	double operator*(const Point& b){return x*b.x+y*b.y;}

	Point operator +(const Point &b){return Point(x+b.x,y+b.y);}
	Point operator -(const Point& b){return Point(x-b.x,y-b.y);}
	Point operator *(const double &k){return Point(x*k,y*k);}
	Point operator /(const double &k){return Point(x/k,y/k);}
	double len(){return hypot(x,y);}
	double len2(){return x*x+y*y;}
	double rad(Point a,Point b){Point p=*this;return fabs(atan2(fabs((a-p)^(b-p)),(a-p)*(b-p)));}

	double angle(){return atan2(y,x);}

	double angle(Point B){

		Point A=(*this);
		return acos(A*B/A.len()/B.len());
	}
	double distance(Point b){return hypot(x-b.x,y-b.y);}
	Point trunc(double r){

		double l=len();
		if(!sgn(l))return *this;
		r/=l;return Point(x*r,y*r);
	}
	Point rotleft(){return Point(-y,x);}

	Point rotright(){return Point(y,-x);}

	Point rotate(double rad){

		Point A=(*this);
		double c=cos(rad),s=sin(rad);
		return Point(A.x*c-A.y*s,A.x*s+A.y*c);
	}
	Point rotate(Point p,double angle){

		Point v=((*this)-p).rotate(angle);
		return Point(p.x+v.x,p.y+v.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void show(){printf("(%.2lf %.2lf)\n",x,y);}
	void zero(){
		if(!sgn(x))x=0.0;
		if(!sgn(y))y=0.0;
	}
};
double cross(Point A,Point B,Point C){return (B-A)^(C-A);}

double dot(Point A,Point B,Point C){return (B-A)*(C-A);}

struct Line{
	Point s,e;
	Line(){};
	Line(Point s,Point e):s(s),e(e){};
	Line(Point p,double angle){

		s=p;
		if(sgn(angle-pi/2)==0)e=(s+Point(0,1));
		else e=(s+Point(1,tan(angle)));
	}
	Line(double a,double b,double c){

		if(!sgn(a))s=Point(0,-c/b),e=Point(1,-c/b);
		else if(!sgn(b))s=Point(-c/a,0),e=Point(-c/a,1);
		else s=Point(0,-c/b),e=Point(1,(-c-a)/b);
	}
	void adjust(){swap(s,e);}
	int relation(Point p){

		int c=sgn((p-s)^(e-s));
		if(c<0)return 1;
		if(c>0)return 2;
		return 3;
	}
	bool pointonseg(Point p){

		return !sgn((p-s)^(e-s))&&sgn((p-s)*(p-e))<=0;
	}
	bool parallel(Line v){

		return !sgn((e-s)^(v.e-v.s));
	}
	int linecrossline(Line v){

		if((*this).parallel(v))return v.relation(s)==3;
		return 2;
	}
	int linecrossseg(Line v){

		int d1=sgn((e-s)^(v.s-s));
		int d2=sgn((e-s)^(v.e-s));
		if((d1^d2)==-2)return 2;
		return !d1||!d2;
	}
	int segcrossseg(Line v){

		int d1=sgn((e-s)^(v.s-s));
		int d2=sgn((e-s)^(v.e-s));
		int d3=sgn((v.e-v.s)^(s-v.s));
		int d4=sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2)return 2;
		return (d1==0&&sgn((v.s-s)*(v.s-e))<=0)||(d2==0&&sgn((v.e-s)*(v.e-e))<=0)
		||(d3==0&&sgn((s-v.s)*(s-v.e))<=0)||(d4==0&&sgn((e-v.s)*(e-v.e))<=0);
	}
	double len(){return s.distance(e);}
	double angle(){

		double k=atan2(e.y-s.y,e.x-s.x);
		if(sgn(k)<0)k+=pi;
		if(!sgn(k-pi))k-=pi;
		return k;
	}
	Point crosspoint(Line v){

		double a1=(v.e-v.s)^(s-v.s);
		double a2=(v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
	double dispointtoline(Point p){return fabs((p-s)^(e-s))/len();}

	double dispointtoseg(Point p){

		if(sgn((p-s)*(e-s))<0||sgn((p-e)*(s-e))<0)return min(p.distance(s),p.distance(e));
		return dispointtoline(p);
	}
	double dissegtoseg(Line v){

		return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
	}
	Point lineprog(Point p){return s+(((e-s)*((e-s)*(p-s)))/((e-s).len2()));}

	Point symmetrypoint(Point p){

		Point q = lineprog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}
	void input(){s.input(),e.input();}
	void show(){s.show(),e.show();}
};
struct circle{
	Point p;

	double r;

	circle(){}
	circle(Point p,double r):p(p),r(r){}
	circle(Point a,Point b,Point c){

		Line u=Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
		Line v=Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
		p=u.crosspoint(v),r=p.distance(a);
	}
	circle(Point a,Point b,Point c,bool t){

		Line u,v;
		double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
		u.s=a,u.e=u.s+Point(cos((n+m)/2),sin((n+m)/2)),v.s=b;
		m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
		v.e=v.s+Point(cos((n+m)/2),sin((n+m)/2));
		p=u.crosspoint(v),r=Line(a,b).dispointtoseg(p);
	}
	Point point(double a){return Point(p.x+cos(a)*r,p.y+sin(a)*r);}

	void input(){p.input();scanf("%lf",&r);}
	void show(){printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);}
	bool operator==(circle v){return (p==v.p)&&!sgn(r-v.r);}
	bool operator <(circle v){return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0));}
	double area(){return pi*r*r;}
	double circumference(){return 2*pi*r;}

	int relation(Point b){

		double dst=b.distance(p);
		if(sgn(dst-r)<0)return 2;
		else if(!sgn(dst-r))return 1;
		return 0;
	}
	int relationseg(Line v){

		double dst=v.dispointtoseg(p);
		if(sgn(dst-r)<0)return 2;
		else if(!sgn(dst-r))return 1;
		return 0;
	}

	int relationline(Line v){

		double dst=v.dispointtoline(p);
		if(sgn(dst-r)<0)return 2;
		else if(!sgn(dst-r))return 1;
		return 0;
	}
	int relationcircle(circle v){

		double d=p.distance(v.p);
		if(sgn(d-r-v.r)>0)return 5;
		if(!sgn(d-r-v.r))return 4;
		double l=fabs(r-v.r);
		if(sgn(d-r-v.r)<0&&sgn(d-l)>0)return 3;
		if(!sgn(d-l))return 2;
		if(sgn(d-l)<0)return 1;
	}

	int pointcrosscircle(circle v,Point &p1,Point &p2){

		int rel=relationcircle(v);
		if(rel==1||rel==5)return 0;
		double d=p.distance(v.p);
		double l=(d*d+r*r-v.r*v.r)/(2*d);
		double h=sqrt(r*r-l*l);
		Point tmp=p+(v.p-p).trunc(l);
		p1=tmp+((v.p-p).rotleft().trunc(h));
		p2=tmp+((v.p-p).rotright().trunc(h));
		if(rel==2||rel==4)return 1;
		return 2;
	}
	int pointcrossline(Line v,Point &p1,Point &p2){

		if(!(*this).relationline(v))return 0;
		Point a=v.lineprog(p);
		double d=v.dispointtoline(p);
		d=sqrt(r*r-d*d);
		if(!sgn(d)){p1=p2=a;return 1;}
		p1=a+(v.e-v.s).trunc(d);
		p2=a-(v.e-v.s).trunc(d);
		return 2;
	}
	Point pointtocircle(Point sp){

		Point u,v;
		double len=sp.distance(p);
		if(len<eps)return p;
		u.x=p.x+r*fabs(p.x-sp.x)/len;
		u.y=p.y+r*fabs(p.y-sp.y)/len*((p.x-sp.x)*(p.y-sp.y)<0?-1:1);
		v.x=p.x-r*fabs(p.x-sp.x)/len;
		v.y=p.y-r*fabs(p.y-sp.y)/len*((p.x-sp.x)*(p.y-sp.y)<0?-1:1);
		return sp.distance(u)<sp.distance(v)?u:v;
	}
	int gercircle(Point a,Point b,double r1,circle &c1,circle &c2){

		circle x(a,r1),y(b,r1);
		int t=x.pointcrosscircle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r=c2.r=r;
		return t;
	}
	int getcircle(Line u,Point q,double r1,circle &c1,circle &c2){

		double dis=u.dispointtoline(q);
		if(sgn(dis-r1*2)>0)return 0;
		if(!sgn(dis)){
			c1.p=q+((u.e-u.s).rotleft().trunc(r1));
			c2.p=q+((u.e-u.s).rotright().trunc(r1));
			c1.r=c2.r=r1;return 2;
		}
		Line u1=Line((u.s+(u.e-u.s).rotleft().trunc(r1)),(u.e+(u.e-u.s).rotleft().trunc(r1)));
		Line u2=Line((u.s+(u.e-u.s).rotright().trunc(r1)),(u.e+(u.e-u.s).rotright().trunc(r1)));
		circle cc=circle(q,r1);
		Point p1,p2;
		if(!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
		c1=circle(p1,r1);
		if(p1==p2){c2=c1;return 1;}
		c2=circle(p2,r1);return 2;
	}
	int getcircle(Line u,Line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4){

		if(u.parallel(v))return 0;

		Line u1=Line(u.s+(u.e-u.s).rotleft().trunc(r1),u.e+(u.e-u.s).rotleft().trunc(r1));
		Line u2=Line(u.s+(u.e-u.s).rotright().trunc(r1),u.e+(u.e-u.s).rotright().trunc(r1));
		Line v1=Line(v.s+(v.e-v.s).rotleft().trunc(r1),v.e+(v.e-v.s).rotleft().trunc(r1));
		Line v2=Line(v.s+(v.e-v.s).rotright().trunc(r1),v.e+(v.e-v.s).rotright().trunc(r1));
		c1.r=c2.r=c3.r=c4.r=r1;
		c1.p=u1.crosspoint(v1);c2.p=u1.crosspoint(v2);
		c3.p=u2.crosspoint(v1);c4.p=u2.crosspoint(v2);
		return 4;
	}
	int getcircle(circle cx,circle cy,double r1,circle &c1,circle &c2){

		circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
		int t=x.pointcrosscircle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r=c2.r=r1;return t;
	}
	int tangentline(Point q,Line &u,Line &v){

		int x=relation(q);
		if(x==2)return 0;
		if(x==1){u=Line(q,q+(q-p).rotleft());v=u;return 1;}
		double d=p.distance(q),l=r*r/d;
		double h=sqrt(r*r-l*l);
		u=Line(q,p+((q-p).trunc(l)+(q-p).rotleft().trunc(h)));
		v=Line(q,p+((q-p).trunc(l)+(q-p).rotright().trunc(h)));
		return 2;
	}
	double areacircle(circle v){

		int rel=relationcircle(v);
		if(rel>=4)return 0.0;
		if(rel<=2)return min(area(),v.area());
		double d=p.distance(v.p);
		double hf=(r+v.r+d)/2.0;
		double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
		double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
		a1*=r*r;
		double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
		a2*=v.r*v.r;
		return a1+a2-ss;
	}
	double areatriangle(Point a,Point b){

		if(!sgn((p-a)^(p-b)))return 0.0;
		Point q[5],p1,p2;
		int len=0;
		q[len++]=a;
		Line l(a,b);
		if(pointcrossline(l,q[1],q[2])==2){
			if(sgn((a-q[1])*(b-q[1]))<0)q[len++]=q[1];
			if(sgn((a-q[2])*(b-q[2]))<0)q[len++]=q[2];
		}q[len++]=b;
		if(len==4&&sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q[2]);
		double res=0;
		for(int i=0;i<len-1;++i){
			if(!relation(q[i])||!relation(q[i+1]))res+=r*r*p.rad(q[i],q[i+1])/2.0;
			else res+=fabs((q[i]-p)^(q[i+1]-p))/2.0;
		}return res;
	}
	int cutpoint(Point sp,Point &rp1,Point &rp2){

		Point p2;
		p2.x=(p.x+sp.x)/2.0;
		p2.y=(p.y+sp.y)/2.0;
		double dx2,dy2,r2;
		dx2=p2.x-p.x;
		dy2=p2.y-p.y;
		r2=sqrt(dx2*dx2+dy2*dy2);
		return pointcrosscircle(circle(p2,r2),rp1,rp2);
	}
	int getTangents(circle B,Point* a,Point* b){

		int cnt=0;

		circle A=(*this);
		if(A.r<B.r){swap(A,B);swap(a,b);}
		double d=(B.p-A.p).len();
		double rdiff=A.r-B.r;
		double rsum=A.r+B.r;
		if(sgn(d-rdiff)==-1)return 0;

		double base=(B.p-A.p).angle();
		if(!sgn(d)&&!sgn(A.r-B.r))return -1;

		if(!sgn(d-rdiff)){

			a[cnt]=A.point(base);
			b[cnt]=B.point(base);
			++cnt;
			return 1;
		}

		double ang=acos((A.r-B.r)/d);
		a[cnt]=A.point(base+ang);b[cnt]=B.point(base+ang);++cnt;
		a[cnt]=A.point(base-ang);b[cnt]=B.point(base-ang);++cnt;
		if(!sgn(d-rsum)){

			a[cnt]=A.point(base);
			b[cnt]=B.point(base+pi);
			++cnt;
		}
		else if(sgn(d-rsum)>0){

			ang=acos((A.r+B.r)/d);
			a[cnt]=A.point(base+ang);b[cnt]=B.point(base+ang+pi);++cnt;
			a[cnt]=A.point(base-ang);b[cnt]=B.point(base-ang+pi);++cnt;
		}
		return cnt;
	}
};
struct polygon{
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n){n=_n;for(int i=0;i<n;++i)p[i].input();}
	void add(Point q){p[n++]=q;}
	void getline(){for(int i=0;i<n;++i)l[i]=Line(p[i],p[(i+1)%n]);}
	struct cmp{
		Point p;
		cmp(const Point &p0){p=p0;}
		bool operator()(const Point &aa,const Point &bb){
			Point a=aa,b=bb;
			int d=sgn((a-p)^(b-p));
			if(!d)return sgn(a.distance(p)-b.distance(p))<0;
			return d>0;
		}
	};

	void norm(){
		Point mi=p[0];
		for(int i=1;i<n;++i)mi=min(mi,p[i]);
		sort(p,p+n,cmp(mi));
	}

	void getconvex(polygon &convex){

		sort(p,p+n),convex.n=n;
		for(int i=0;i<min(n,2);++i)convex.p[i]=p[i];
		if(convex.n==2&&(convex.p[0]==convex.p[1]))--convex.n;

		if(n<=2)return;
		int &top=convex.n;top=1;
		for(int i=2;i<n;++i){
			while(top&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<=0)--top;
			convex.p[++top]=p[i];
		}int temp=top;
		convex.p[++top]=p[n-2];
		for(int i=n-3;i>=0;--i){
			while(top^temp&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<=0)--top;
			convex.p[++top]=p[i];
		}if(convex.n==2&&(convex.p[0]==convex.p[1]))--convex.n;

		convex.norm();

	}

	void Graham(polygon &convex){
		norm();
		int &top=convex.n;top=0;
		if(n==1){top=1,convex.p[0]=p[0];return;}
		if(n==2){
			top=2,convex.p[0]=p[0],convex.p[1]=p[1];
			if(convex.p[0]==convex.p[1])--top;
			return;
		}convex.p[0]=p[0],convex.p[1]=p[1],top=2;
		for(int i=2;i<n;++i){
			while(top>1&&sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2]))<=0)--top;
			convex.p[top++]=p[i];
		}if(convex.n==2&&(convex.p[0]==convex.p[1]))--convex.n;

	}
	bool isconvex(){

		bool s[3]={false,false,false};
		for(int i=0;i<n;++i){
			int j=(i+1)%n,k=(j+1)%n;
			s[sgn((p[j]-p[i])^(p[k]-p[i]))+1]=true;
			

			if(s[0]&&s[2])return false;
		}return true;
	}
	int relationpoint(Point q){

		for(int i=0;i<n;++i)if(p[i]==q)return 3;
		getline();
		for(int i=0;i<n;++i)if(l[i].pointonseg(q))return 2;
		int cnt=0;
		for(int i=0;i<n;++i){
			int j=(i+1)%n;
			int k=sgn((q-p[j])^(p[i]-p[j]));
			int u=sgn(p[i].y-q.y);
			int v=sgn(p[j].y-q.y);
			if(k>0&&u<0&&v>=0)++cnt;
			if(k<0&&v<0&&u>=0)--cnt;
		}return cnt!=0;
	}
	void convexcut(Line u,polygon &po){

		int &top=po.n;

		top=0;
		for(int i=0;i<n;++i){
			int d1=sgn((u.e-u.s)^(p[i]-u.s));
			int d2=sgn((u.e-u.s)^(p[(i+1)%n]-u.s));
			if(d1>=0)po.p[top++]=p[i];
			if(d1*d2<0)po.p[top++]=u.crosspoint(Line(p[i],p[(i+1)%n]));
		}
	}
	double getcircumference(){

		double sum=0;
		for(int i=0;i<n;++i)sum+=p[i].distance(p[(i+1)%n]);
		return sum;
	}
	double getarea(){

		double sum=0;
		for(int i=0;i<n;++i)sum+=(p[i]^p[(i+1)%n]);
		return fabs(sum)/2;
	}
	bool getdir(){

		double sum=0;
		for(int i=0;i<n;++i)sum+=(p[i]^p[(i+1)%n]);
		if(sgn(sum)>0)return 1;
		return 0;
	}
	void adjust(){reverse(p,p+n);}
	Point getbarycentre(){

		Point ret(0,0);
		double area=0;
		for(int i=1;i<n-1;++i){
			double tmp=(p[i]-p[0])^(p[i+1]-p[0]);
			if(!sgn(tmp))continue;
			area+=tmp;
			ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
			ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
		}if(sgn(area))ret=ret/area;
		return ret;
	}
	double areacircle(circle c){

		double ans=0;
		for(int i=0;i<n;++i){
			int j=(i+1)%n;
			if(sgn((p[j]-c.p)^(p[i]-c.p))>=0)ans+=c.areatriangle(p[i],p[j]);
			else ans-=c.areatriangle(p[i],p[j]);
		}return fabs(ans);
	}
	int relationcircle(circle c){

		getline();
		int x=2;
		if(relationpoint(c.p)!=1)return 0;

		for(int i=0;i<n;++i){
			if(c.relationseg(l[i])==2)return 0;
			if(c.relationseg(l[i])==1)x=1;
		}return x;
	}
	double CPIA(Point a[],Point b[],int na,int nb){

		Point tmp[20];           

		int tn,sflag,eflag;           

		a[na]=a[0],b[nb]=b[0];     

		memcpy(p,b,sizeof(Point)*(nb + 1));         

		for(int i=0;i<na&&nb>2;++i){                

			sflag=sgn(cross(a[i],a[i+1],p[0]));    

			for(int j=tn=0;j<nb;++j,sflag=eflag){   

				if(sflag>=0)tmp[tn++]=p[j];         

				eflag=sgn(cross(a[i],a[i+1],p[j+1]));

				if((sflag^eflag)==-2)               

					tmp[tn++]=Line(p[j],p[j+1]).crosspoint(Line(a[i],a[i+1]));

			}
			memcpy(p,tmp,sizeof(Point)*tn);     

			nb=tn, p[nb]=p[0];

		}n=nb;
		if(nb<3)return 0.0;      

		return getarea();

	}
	double SPIA(Point a[],Point b[],int na,int nb){

		int i,j;                            

		Point t1[4],t2[4];                  

		double res=0,num1,num2;             

		a[na]=t1[0]=a[0],b[nb]=t2[0]=b[0];  

		for(i=2;i<na;++i){                  

			t1[1]=a[i-1],t1[2]=a[i];        

			num1=sgn(cross(t1[0],t1[1],t1[2]));

			if(num1<0)swap(t1[1],t1[2]);    

			for(j=2;j<nb;++j){              

				t2[1]=b[j-1],t2[2]=b[j];    

				num2=sgn(cross(t2[0],t2[1],t2[2]));

				if(num2<0)swap(t2[1],t2[2]);

				res+=CPIA(t1,t2,3,3)*num1*num2;       

			}
		}return res;

	}
	double RotatingCalipers(){

		int i,k=1;
		double t1,t2,ans=0.0,dif;
		p[n]=p[0];
		for(i=0;i<n;++i){

			Point v=p[i+1]-p[i];
			while(sgn((v^(p[k+1]-p[i]))-(v^(p[k]-p[i])))>0)k=(k+1)%n;
			dif=sgn((v^(p[k+1]-p[i]))-(v^(p[k]-p[i])));
			if(dif==0){

				t1=(p[i]-p[k]).len2();
				t2=(p[i+1]-p[k+1]).len2();
				if(t1>ans)ans=t1;
				if(t2>ans)ans=t2;
			}else if(dif<0.0){

				t1=(p[i]-p[k]).len2();
				if(t1>ans)ans=t1;
			}
		}
		return ans;
	}
	double RotatingCalipers(bool t){

		int i,k=1;
		double ans=inf;
		p[n]=p[0];
		for(i=0;i<n;++i){

			Point v=p[i+1]-p[i];
			while(sgn((v^(p[k+1]-p[i]))-(v^(p[k]-p[i])))>0)k=(k+1)%n;
			ans=min(ans,Line(p[i+1],p[i]).dispointtoline(p[k]));
		}
		return ans;
	}
	double RotatingCalipers(polygon B){

		int yminP=0,ymaxQ=0,m=B.n;
		for(int i=0;i<n;++i)if(p[i].y<p[yminP].y)yminP=i;	

		for(int i=0;i<m;++i)if(B.p[i].y>B.p[ymaxQ].y)ymaxQ=i; 	

		p[n]=p[0],B.p[m]=B.p[0];
		double ans=inf;
		for(int i=0;i<n;++i){
			Point v=p[yminP+1]-p[yminP];
			while((v^(B.p[ymaxQ+1]-p[yminP]))-(v^(B.p[ymaxQ]-p[yminP]))>0)ymaxQ=(ymaxQ+1)%m;
			Line a=Line(p[yminP],p[yminP+1]),b=Line(B.p[ymaxQ],B.p[ymaxQ+1]);
			ans=min(ans,a.dissegtoseg(b));
			yminP=(yminP+1)%n;
		}
		return ans;
	}
	double RotatingCalipers_triangle(){

		if(n<3)return 0.00;
		int i,j,k=1;
		double ans=0.0;
		p[n]=p[0];
		for(i=0;i<n;++i){
			j=(i+1)%n,k=(j+1)%n;
			while(j^k&&k^i){
				while(sgn(cross(p[k+1],p[i],p[j])-cross(p[k],p[i],p[j]))>0)k=(k+1)%n;
				ans=max(ans,cross(p[k],p[i],p[j]));
				j=(j+1)%n;
			}
		}return ans/2.0;
	}
	double minRectangleCover(Point A[]){

		if(n<3)return 0.0;

		p[n]=p[0];
		double ans=-1;
		int r=1,k=1,q;
		for(int i=0;i<n;++i){

			while(sgn(cross(p[i],p[i+1],p[r+1])-cross(p[i],p[i+1],p[r]))>=0)r=(r+1)%n;
			

			while(sgn(dot(p[i],p[i+1],p[k+1])-dot(p[i],p[i+1],p[k]))>=0)k=(k+1)%n;
			if(i==0)q=k;

			while(sgn(dot(p[i],p[i+1],p[q+1])-dot(p[i],p[i+1],p[q]))<=0)q=(q+1)%n;
			double d=(p[i]-p[i+1]).len2();
			double tmp=cross(p[i],p[i+1],p[r])*(dot(p[i],p[i+1],p[k])-dot(p[i],p[i+1],p[q]))/d;
			if(ans<0||ans>tmp){
				ans=tmp;
				Point f=(p[i]-p[i+1]).rotright();
				Line a=Line(p[i],p[i+1]),b=Line(p[k],f.angle());
				A[0]=a.crosspoint(b);
				A[1]=A[0]+(f.trunc(a.dispointtoline(p[r])));
				f=(p[i]-p[i+1]);
				double L=Line(A[0],A[1]).dispointtoline(p[q]);
				A[2]=A[1]+f.trunc(L);
				A[3]=A[0]+f.trunc(L);
				A[0].zero(),A[1].zero(),A[2].zero(),A[3].zero();
			}
		}return ans;
	}
	void pointtangentpoly(Point P,Point &rp,Point &lp){

		Line ep,en;
		bool blp,bln;
		lp=rp=p[0];
		for(int i=1;i<n;++i){
			ep=Line(p[(i+n-1)%n],p[i]);
			en=Line(p[i],p[(i+1)%n]);
			blp=cross(ep.s,P,ep.e)>=0; 

			bln=cross(en.s,P,en.e)>=0; 

			if(!blp&&bln){
				if(cross(P,rp,p[i])>0)rp=p[i]; 

			}if(blp&&!bln){
				if(cross(P,p[i],lp)>0)lp=p[i]; 

			}
		}
	}
};
struct halfplane:public Line{
	double angle;
	halfplane(){}

	halfplane(Point _s,Point _e){s=_s,e=_e;}
	halfplane(Line v){s=v.s,e=v.e;}
	void calcangle(){angle=atan2(e.y-s.y,e.x-s.x);}
	bool operator <(const halfplane &b)const{return angle<b.angle;}
};
struct halfplanes{
	halfplane hp[maxp];
	Point p[maxp];
	int n,st,ed;
	int que[maxp];
	void push(halfplane tmp){hp[n++]=tmp;}

	void unique(){

		int m=1;
		for(int i=1;i<n;++i)
			if(sgn(hp[i].angle-hp[i-1].angle))hp[m++]=hp[i];
			else if(sgn((hp[m-1].e-hp[m-1].s)^(hp[i].s-hp[m-1].s))>0)hp[m-1]=hp[i];
		n=m;
	}
	bool halfplaneinsert(){
		for(int i=0;i<n;++i)hp[i].calcangle();
		sort(hp,hp+n),unique();
		que[st=0]=0,que[ed=1]=1;
		p[1]=hp[0].crosspoint(hp[1]);
		for(int i=2;i<n;++i){
			while(st<ed&&sgn((hp[i].e-hp[i].s)^(p[ed]-hp[i].s))<0)--ed;
			while(st<ed&&sgn((hp[i].e-hp[i].s)^(p[st+1]-hp[i].s))<0)++st;
			que[++ed]=i;
			if(hp[i].parallel(hp[que[ed-1]]))return false;
			p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
		}while(st<ed&&sgn((hp[que[st]].e-hp[que[st]].s)^(p[ed]-hp[que[st]].s))<0)--ed;
		while(st<ed&&sgn((hp[que[ed]].e-hp[que[ed]].s)^(p[st+1]-hp[que[ed]].s))<0)++st;
		if(st+1>=ed)return false;
		return true;
	}

	void getconvex(polygon &con){
		p[st]=hp[que[st]].crosspoint(hp[que[ed]]);
		con.n=ed-st+1;
		for(int j=st,i=0;j<=ed;++i,++j)con.p[i]=p[j];
	}
};
const int maxn=1010;
struct circles{
	circle c[maxn];
	double ans[maxn];

	double pre[maxn];
	int n;
	circles(){}
	void add(circle cc){c[n++]=cc;}
	bool inner(circle x,circle y){

		if(x.relationcircle(y)!=1)return 0;
		return sgn(x.r-y.r)<=0?1:0;
	}
	void init_or(){

		int i,j,k=0;
		bool mark[maxn]={0};
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)if(i!=j&&!mark[j]){if((c[i]==c[j])||inner(c[i],c[j]))break;}
			if(j<n)mark[i]=1;
		}
		for(i=0;i<n;++i)if(!mark[i])c[k++]=c[i];
		n=k;
	}
	void init_add(){

		int i,j,k;
		bool mark[maxn]={0};
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)if(i!=j&&!mark[j]){if((c[i]==c[j])||inner(c[j],c[i]))break;}
			if(j<n)mark[i]=1;
		}
		for(i=0;i<n;++i)if(!mark[i])c[k++]=c[i];
		n=k;
	}
	double areaarc(double th,double r){return 0.5*r*r*(th-sin(th));}

	

	

	

	

	

	void getarea(){
		memset(ans,0,sizeof(ans));
		vector<pair<double,int> >v;
		for(int i=0;i<n;++i){
			v.clear();
			v.push_back(make_pair(-pi,1));
			v.push_back(make_pair(pi,-1));
			for(int j=0;j<n;++j)if(i^j){
				Point q=(c[j].p-c[i].p);
				double ab=q.len(),ac=c[i].r,bc=c[j].r;
				if(sgn(ab+ac-bc)<=0){
					v.push_back(make_pair(-pi,1));
					v.push_back(make_pair(pi,-1));continue;
				}if(sgn(ab+bc-ac)<=0)continue;
				if(sgn(ab-ac-bc)>0)continue;
				double th=atan2(q.y,q.x),fai=acos((ac*ac+ab*ab-bc*bc)/(2.0*ac*ab));
				double a0=th-fai,a1=th+fai;
				if(sgn(a0+pi)<0)a0+=2*pi;
				if(sgn(a1-pi)>0)a1-=2*pi;
				if(sgn(a0-a1)>0){
					v.push_back(make_pair(a0,1));
					v.push_back(make_pair(pi,-1));
					v.push_back(make_pair(-pi,1));
					v.push_back(make_pair(a1,-1));
				}else{
					v.push_back(make_pair(a0,1));
					v.push_back(make_pair(a1,-1));
				}
			}sort(v.begin(),v.end());
			int cur=0,vs=v.size();
			for(int j=0;j<vs;++j){
				if(cur&&sgn(v[j].first-pre[cur])){
					ans[cur]+=areaarc(v[j].first-pre[cur],c[i].r);
					ans[cur]+=0.5*(Point(c[i].p.x+c[i].r*cos(pre[cur]),c[i].p.y+c[i].r*sin(pre[cur]))^
					Point(c[i].p.x+c[i].r*cos(v[j].first),c[i].p.y+c[i].r*sin(v[j].first)));
				}cur+=v[j].second;pre[cur]=v[j].first;
			}
		}
		for(int i=1;i<n;++i)ans[i]-=ans[i+1];
	}
};
circle mincovercircle(Point *p,int n){

	random_shuffle(p,p+n);
	circle ans(p[0],0);
	for(int i=1;i<n;++i)
		if(!ans.relation(p[i])){

			ans=circle(p[i],0);
			for(int j=0;j<i;++j)if(!ans.relation(p[j])){

				Point O=(p[i]+p[j])/2;
				ans=circle(O,p[i].distance(O));
				for(int k=0;k<j;++k)if(!ans.relation(p[k])){

					O=circle(p[i],p[j],p[k]).p;

					ans=circle(O,p[i].distance(O));
				}
			}
		}
	return ans;
}
int check(ll y,double x){
	if(x==floor(x)){
		ll x1=(ll)floor(x);
		if(__gcd(x1*x1,y*y)==1&&x1*x1!=y*y)return 1;
	}return 0;
}
ll circleintpoint(ll r){

	ll d=r<<1ll,n=sqrt(d),ans=0;
	for(ll i=1;i<=n;++i)if(d%i==0){
		ll m=sqrt(r/i);
		for(ll a=1;a<=m;++a){
			double b=sqrt(d/i-a*a);
			if(check(a,b))++ans;
		}
		m=sqrt(i>>1ll);
		if(i!=d/i)for(ll a=1;a<=m;++a){
			double b=sqrt(i-a*a);
			if(check(a,b))++ans;
                }
        }
        return (ans<<2ll)+4ll;
}
polygon A,B,C;
int main(){
	double w,h,a;
	scanf("%lf%lf%lf",&w,&h,&a);
	a*=pi/180.0;
	w/=2.0,h/=2.0;
	A.add(Point(w,h));
	A.add(Point(-w,h));
	A.add(Point(-w,-h));
	A.add(Point(w,-h));
	for(int i=0;i<4;++i)B.add(A.p[i].rotate(a));
	printf("%.9lf\n",C.SPIA(A.p,B.p,4,4));
	return 0;
}
