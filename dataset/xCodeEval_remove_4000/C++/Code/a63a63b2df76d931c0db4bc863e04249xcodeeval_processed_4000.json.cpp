


using namespace std;
const double eps=1e-8;
const double inf=1e20;
const double pi=acos(-1.0);
const int maxp=1010;


int sgn(double x) {
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	else return 1;
}


inline double sqr(double x) {
	return x*x;
}
struct Point {
	double x,y;
	Point() {}
	Point(double x,double y):x(x),y(y) {}
	void input() {
		scanf("%lf%lf",&x,&y);
	}
	void output() {
		printf("%.2f.%.2f\n",x,y);   

	}

	bool operator==(Point b)const {
		return sgn(x-b.x)==0&&sgn(y-b.y)==0;
	}
	

	

	bool operator<(Point b)const {
		return sgn(x-b.x)==0?sgn(y-b.y)<0:x<b.x;
	}
	

	double operator^(const Point &b)const {
		return x*b.y-y*b.x;
	}
	

	double operator*(const Point &b)const {
		return x*b.x+y*b.y;
	}
	

	double len() {
		return sqrt(x*x+y*y);   

	}
	

	double len2() {
		return x*x+y*y;
	}
	

	double distance(Point p) {
		return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	}
	

	Point operator+(const Point &b)const {
		return Point(x+b.x,y+b.y);
	}
	

	Point operator-(const Point &b)const {
		return Point(x-b.x,y-b.y);
	}
	

	Point operator*(const double &k)const {
		return Point(x*k,y*k);
	}
	

	Point operator/(const double &k)const {
		return Point(x/k,y/k);
	}
	

	

	

	double rad(Point a,Point b) {
		Point p = *this;
		return fabs(atan2(fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}
	

	Point trunc(double r) {
		double l=len();
		if(!sgn(l))return *this;
		r/=l;
		return Point(x*r,y*r);
	}
	

	Point rotleft() {
		return Point(-y,x);
	}
	

	Point rotright() {
		return Point(y,-x);
	}
	

	Point rotate(Point p,double angle) {
		Point v=(*this)-p;
		double c=cos(angle),s=sin(angle);
		return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
	}
	

	Point rotate(double angle) {
		double c=cos(angle),s=sin(angle);
		return Point(x*c-y*s,x*s+y*c);
	}
	

	

	

	

	double getangle(Point p) {
		if(sgn(len())==0||sgn(p.len())==0) return 0; 

		double res=acos((*this)*p/(len()*p.len()));

		if(sgn(*(this)^p)<0)return res*(-1);
		else return res;
		





	}
};


struct Line {
	Point s,e;
	Line() {}
	Line(Point s,Point e):s(s),e(e) {}
	

	bool operator==(Line v) {
		return (s==v.s)&&(e==v.e);
	}
	

	Line(Point p,double angle) {
		s=p;
		if(sgn(angle-pi/2)==0) {
			e=(s+Point(0,1));
		} else {
			e=(s+Point(1,tan(angle)));
		}
	}
	

	Line(double a,double b,double c) {
		if(sgn(a)==0) {
			s=Point(0,-c/b);
			e=Point(1,-c/b);
		} else if(sgn(b)==0) {
			s=Point(-c/a,0);
			e=Point(-c/a,1);
		} else {
			s=Point(0,-c/b);
			e=Point(1,(-c-a)/b);
		}
	}
	void Get_equation(Point p1,Point p2,double &a,double &b,double &c) {
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = p2.x*p1.y - p1.x*p2.y;
	}
	void input() {
		s.input();
		e.input();
	}

	void adjust() {
		if(e<s)swap(s,e);
	}
	

	double length() {
		return s.distance(e);
	}
	

	

	double angle() {
		double k = atan2(e.y-s.y,e.x-s.x);
		if(sgn(k)<0)k+=pi;
		if(sgn(k-pi)==0)k-=pi;
		return k;
	}
	

	

	

	

	

	int relation(Point p) {
		int c=sgn((p-s)^(e-s));
		if(c<0)return 1;
		else if(c>0)return 2;
		else return 3;
	}
	

	bool pointonseg(Point p) {
		return sgn((p-s)^(e-s))==0&&sgn((p-s)*(p-e))<=0;
	}
	

	bool parallel(Line v) {
		return sgn((e-s)^(v.e-v.s))==0;
	}
	

	

	

	

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
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		if((d1^d2)==-2) return 2;
		return (d1==0||d2==0);
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
	

	double dispointtoline(Point p) {
		return fabs((p-s)^(e-s))/length();
	}
	

	double dispointtoseg(Point p) {
		if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)  

			return min(p.distance(s),p.distance(e));
		return dispointtoline(p);
	}

	

	

	Point NearestPointToLineSeg(Point P) {
		Point result;
		Line L=*this;
		double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
		if(t>=0&&t<=1) {
			result.x = L.s.x + (L.e.x - L.s.x)*t;
			result.y = L.s.y + (L.e.y - L.s.y)*t;
		} else {
			if(P.distance(L.s)<P.distance(L.e))
				result = L.s;
			else result = L.e;
		}
		return result;
	}
	

	

	double dissegtoseg(Line v) {
		return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v
		           .dispointtoseg(s),v.dispointtoseg(e)));
	}
	

	Point lineprog(Point p) {
		return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
	

	Point symmetrypoint(Point p) {
		Point q = lineprog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}
	

	

	Line translate(double mid) {
		Line res;
		res.s=s+(e-s).trunc(mid).rotleft();
		res.e=e+(e-s).trunc(mid).rotleft();
		return res;
	}

};














int id0(Point a,Point p[],int n) {
	Line line;
	for(int i = 0; i < n; i++) {
		if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
		else {
			line.s=p[i],line.e=p[(i+1)%n];
			if(line.pointonseg(a)) return 0;

		}
	}
	return 1;
}












int inPoly(Point p,Point poly[],int n) {
	int cnt;
	Line ray,side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -100000000000.0;


	for(int i = 0; i < n; i++) {
		side.s = poly[i];
		side.e = poly[(i+1)%n];

		if(side.pointonseg(p))return 0;

		

		if(sgn(side.s.y - side.e.y) == 0)
			continue;

		if(ray.pointonseg(side.s)) {
			if(sgn(side.s.y - side.e.y) > 0)cnt++;
		} else if(ray.pointonseg(side.e)) {
			if(sgn(side.e.y - side.s.y) > 0)cnt++;
		} else if(side.segcrossseg(ray))
			cnt++;
	}
	if(cnt % 2 == 1)return 1;
	else return -1;
}

struct circle {
	Point p;

	double r;

	circle() {}
	circle(Point p,double r):p(p),r(r) {}
	circle(double x,double y,double r):p(Point(x,y)),r(r) {}

	

	

	

	

	circle(Point a,Point b,Point c) {
		Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
		Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
		p = u.crosspoint(v);
		r = p.distance(a);
	}
	

	

	

	circle(Point a,Point b,Point c,bool t) {
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
	

	void input() {
		p.input();
		scanf("%lf",&r);
	}
	

	void output() {
		printf("%.2lf.%.2lf.%.2lf\n",p.x,p.y,r);
	}
	

	bool operator==(circle v) {
		return (p==v.p) && sgn(r-v.r)==0;
	}
	

	bool operator<(circle v)const {
		return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0));
	}
	

	double area() {
		return pi*r*r;
	}
	

	double circumference() {
		return 2*pi*r;
	}

	

	

	

	

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
		c1.r = c2.r = r;
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
		

		

		

		Line u1 = Line((u.s + (u.e-u.s).rotleft().trunc(r1)),(u.e +
		               (u.e-u.s).rotleft().trunc(r1)));
		Line u2 = Line((u.s + (u.e-u.s).rotright().trunc(r1)),(u.e
		               + (u.e-u.s).rotright().trunc(r1)));
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
	

	

	

	int getcircle(Line u,Line v,double r1,circle &c1,circle &c2,
	              circle &c3,circle &c4) {
		if(u.parallel(v))return 0;

		Line u1 = Line(u.s + (u.e-u.s).rotleft().trunc(r1),u.e + (u
		               .e-u.s).rotleft().trunc(r1));
		Line u2 = Line(u.s + (u.e-u.s).rotright().trunc(r1),u.e + (
		                   u.e-u.s).rotright().trunc(r1));
		Line v1 = Line(v.s + (v.e-v.s).rotleft().trunc(r1),v.e + (v
		               .e-v.s).rotleft().trunc(r1));
		Line v2 = Line(v.s + (v.e-v.s).rotright().trunc(r1),v.e + (
		                   v.e-v.s).rotright().trunc(r1));
		c1.r = c2.r = c3.r = c4.r = r1;
		c1.p = u1.crosspoint(v1);
		c2.p = u1.crosspoint(v2);
		c3.p = u2.crosspoint(v1);
		c4.p = u2.crosspoint(v2);
		return 4;
	}
	

	

	

	int getcircle(circle cx,circle cy,double r1,circle &c1,circle &
	              c2) {
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
	



	double areatriangle(Point a,Point b) {
		if(sgn((p-a)^(p-b)) == 0)return 0.0;
		Point q[5];
		int len = 0;
		q[len++] = a;
		Line l(a,b);
		Point p1,p2;
		if(pointcrossline(l,q[1],q[2])==2) {
			if(sgn((a-q[1])*(b-q[1]))<0)q[len++] = q[1];
			if(sgn((a-q[2])*(b-q[2]))<0)q[len++] = q[2];
		}
		q[len++] = b;
		if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q[2]);
		double res = 0;
		for(int i = 0; i < len-1; i++) {
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




struct cmp {
	Point p;
	cmp(const Point &p0) {
		p = p0;
	}
	bool operator()(const Point &aa,const Point &bb) {
		Point a = aa, b = bb;
		int d = sgn((a-p)^(b-p));
		if(d == 0) {
			return sgn(a.distance(p)-b.distance(p)) < 0;
		}
		return d > 0;
	}
};
struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n) {
		n = _n;
		for(int i = 0; i < n; i++)
			p[i].input();
	}
	void add(Point q) {
		p[n++] = q;
	}
	

	void getline() {
		for(int i = 0; i < n; i++) {
			l[i] = Line(p[i],p[(i+1)%n]);

		}
	}
	

	

	

	void norm() {
		Point mi = p[0];
		for(int i = 1; i < n; i++)mi = min(mi,p[i]);
		sort(p,p+n,cmp(mi));
	}
	

	

	

	

	

	

	

	

	

	void getconvex(polygon &convex) {
		sort(p,p+n);
		convex.n = n;
		for(int i = 0; i < min(n,2); i++) {
			convex.p[i] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;

		if(n <= 2)return;
		int &top = convex.n;
		top = 1;
		for(int i = 2; i < n; i++) {
			while(top && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i])) <= 0)top--;

			convex.p[++top] = p[i];
		}
		int temp = top;
		convex.p[++top] = p[n-2];
		for(int i = n-3; i >= 0; i--) {
			while(top != temp && sgn((convex.p[top]-p[i])^(convex.p
			                         [top-1]-p[i])) <= 0)

				top--;
			convex.p[++top] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;

		convex.norm();

	}
	

	

	

	

	

	

	

	

	void Graham(polygon &convex) {
		norm();
		int &top = convex.n;
		top = 0;
		if(n == 1) {
			top = 1;
			convex.p[0] = p[0];
			return;
		}
		if(n == 2) {
			top = 2;
			convex.p[0] = p[0];
			convex.p[1] = p[1];
			if(convex.p[0] == convex.p[1])top--;
			return;
		}
		convex.p[0] = p[0];
		convex.p[1] = p[1];
		top = 2;
		for(int i = 2; i < n; i++) {
			while( top > 1 && sgn((convex.p[top-1]-convex.p[top-2])
			                      ^(p[i]-convex.p[top-2])) <= 0 )top--;
			convex.p[top++] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;

	}
	

	

	

	

	

	
	bool isconvex() {
		bool s[5];
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

	

	

	

	void convexcut(double a,double b,double c,Point p[],int &n) {
		int tmp=0;
		Point tp[maxp];
		Line line(a,b,c);
		for(int i=0; i<n; i++) {
			if(sgn(a*p[i].x+b*p[i].y+c)>=0) tp[++tmp]=p[i];  

			else {
				if(sgn(a*p[(i-1)%n].x+b*p[(i-1)%n].y+c)>=0)  

					tp[++tmp]=line.crosspoint(Line(p[(i-1)%n],p[i]));
				if(sgn(a*p[(i+1)%n].x+b*p[(i+1)%n].y+c)>=0)
					tp[++tmp]=line.crosspoint(Line(p[i],p[(i+1)%n]));
			}
		}
		for(int i=0; i<n; i++)
			p[i]=tp[i];
		n=tmp;
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
	

	

	

	

	void adjust() {
		for(int i=1; i<=n/2; i++) {
			swap(p[i],p[n-i]);
		}
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
	

	

	

	

	void Graham(polygon &convex,int *stk) {
		norm();
		int &top = convex.n;
		top = 0;
		if(n == 1) {
			top = 1;
			convex.p[0] = p[0];
			stk[0]=0;
			return;
		}
		if(n == 2) {
			top = 2;
			convex.p[0] = p[0];
			convex.p[1] = p[1];
			stk[0]=0,stk[1]=1;
			if(convex.p[0] == convex.p[1])top--;
			return;
		}
		convex.p[0] = p[0];
		stk[0]=0;
		convex.p[1] = p[1];
		stk[1]=1;
		top = 2;
		for(int i = 2; i < n; i++) {
			while( top > 1 && sgn((convex.p[top-1]-convex.p[top-2])
			                      ^(p[i]-convex.p[top-2])) <= 0 )top--;
			convex.p[top] = p[i];
			stk[top]=i;
			top++;
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;

	}
	

	

	

	

	

	

	

	

	int isstableconvex() {
		

		

		

		

		

		polygon c;
		int stk[maxp];
		Graham(c,stk);
		if(c.n<=2)return 0;

		if(n<6)return 1;

		

		

		bool f=1;
		for(int i=1; i<c.n; i++) {
			if(stk[i]-stk[i-1]==1) {
				f=0;
				break;
			}
		}
		if(f==0)return 1;
		

		

		int i=0,cnt1=0,cnt2=0;
		for(; i<n; i++) {
			if(cnt1<=2&&sgn((c.p[0]-c.p[c.n-1])^(c.p[0]-p[i]))==0) {
				cnt1++;
			}
			if(cnt2<=2&&sgn((c.p[c.n-2]-c.p[c.n-1])^(c.p[c.n-2]-p[i]))==0) {
				cnt2++;
			}
			if(cnt1>2&&cnt2>2)break;
		}
		if(cnt1>2&&cnt2>2)return 2;
		else return 1;
	}
	

	

	

	

	

	int onedge() {
		int cnt=0;
		for(int i=0; i<n; i++) {
			int j=(i+1)%n;
			int x=floor(fabs(p[j].x-p[i].x)+eps);
			int y=floor(fabs(p[j].y-p[i].y)+eps);
			cnt+=__gcd(x,y)-1;

		}
		cnt+=n;

		return cnt;
	}
	

	

	

	

	

	

	

	

	

	int pick() {
		int S=floor(getarea()+eps);
		return S-onedge()/2+1;
	}

};






struct halfplane:public Line {
	double angle;
	halfplane() {}


	halfplane(Point _s,Point _e) {
		s = _s;
		e = _e;
	}
	halfplane(Line v) {
		s = v.s;
		e = v.e;
	}
	void calcangle() {
		angle = atan2(e.y-s.y,e.x-s.x);
	}
	bool operator <(const halfplane &b)const {
		return angle < b.angle;
	}
};
struct halfplanes {
	int n;
	halfplane hp[maxp];
	Point p[maxp];
	int que[maxp];
	int st,ed;
	void push(halfplane tmp) {
		hp[n++] = tmp;
	}


	void unique() {
		int m = 1;
		for(int i = 1; i < n; i++) {
			if(sgn(hp[i].angle-hp[i-1].angle) != 0)
				hp[m++] = hp[i];
			else if(sgn( (hp[m-1].e-hp[m-1].s)^(hp[i].s-hp[m-1].s)
			           ) > 0)
				hp[m-1] = hp[i];
		}
		n = m;
	}
	

	

	bool halfplaneinsert() {
		for(int i = 0; i < n; i++)hp[i].calcangle();
		sort(hp,hp+n);
		unique();
		que[st=0] = 0;
		que[ed=1] = 1;
		p[1] = hp[0].crosspoint(hp[1]);
		for(int i = 2; i < n; i++) {
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[ed]-hp[i].s))
			        <0)ed--;
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[st+1]-hp[i].s))
			        <0)st++;
			que[++ed] = i;
			if(hp[i].parallel(hp[que[ed-1]]))return false;
			p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
		}
		while(st<ed && sgn((hp[que[st]].e-hp[que[st]].s)^(p[ed]-hp[
		                       que[st]].s))<0)ed--;
		while(st<ed && sgn((hp[que[ed]].e-hp[que[ed]].s)^(p[st+1]-
		                   hp[que[ed]].s))<0)st++;
		if(st+1>=ed)return false;
		return true;
	}






	void getconvex(polygon &con) {
		p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
		con.n = ed-st+1;
		for(int j = st,i = 0; j <= ed; i++,j++)
			con.p[i] = p[j];
	}
};

















double RC(Point p[],int n) {
	double ans=0;
	Point v;
	int cur=1;
	for(int i=0; i<n; i++) {
		while(sgn(p[i]-p[(i+1)%n]^(p[(cur+1)%n]-p[cur]))<0)
			cur=(cur+1)%n;
		double d1=p[i].distance(p[cur]),d2=p[(i+1)%n].distance(p[(cur+1)%n]);
		if(sgn(ans-d1)<0)ans=d1;
		if(sgn(ans-d2)<0)ans=d2;
	}
	return ans;
}

const int maxn = 1010;
struct circles {
	circle c[maxn];
	double ans[maxn];

	double pre[maxn];
	int n;
	circles() {}
	void add(circle cc) {
		c[n++] = cc;
	}


	bool inner(circle x,circle y) {
		if(x.relationcircle(y) != 1)return 0;
		return sgn(x.r-y.r)<=0?1:0;
	}


	void init_or() {
		bool mark[maxn] = {0};
		int i,j,k=0;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++)
				if(i != j && !mark[j]) {
					if( (c[i]==c[j])||inner(c[i],c[j]) )break;
				}
			if(j < n)mark[i] = 1;
		}
		for(i = 0; i < n; i++)
			if(!mark[i])
				c[k++] = c[i];
		n = k;
	}


	void init_add() {
		int i,j,k=0;
		bool mark[maxn] = {0};
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++)
				if(i != j && !mark[j]) {
					if( (c[i]==c[j])||inner(c[j],c[i]) )break;
				}
			if(j < n)mark[i] = 1;
		}
		for(i = 0; i < n; i++)
			if(!mark[i])
				c[k++] = c[i];
		n = k;
	}


	double areaarc(double th,double r) {
		return 0.5*r*r*(th-sin(th));
	}
















	void getarea() {
		memset(ans,0,sizeof(ans));
		vector<pair<double,int> >v;
		for(int i = 0; i < n; i++) {
			v.clear();
			v.push_back(make_pair(-pi,1));
			v.push_back(make_pair(pi,-1));
			for(int j = 0; j < n; j++)
				if(i != j) {
					Point q = (c[j].p - c[i].p);
					double ab = q.len(),ac = c[i].r, bc = c[j].r;
					if(sgn(ab+ac-bc)<=0) {

						v.push_back(make_pair(-pi,1));
						v.push_back(make_pair(pi,-1));
						continue;
					}
					if(sgn(ab+bc-ac)<=0)continue;
					if(sgn(ab-ac-bc)>0)continue;
					double th = atan2(q.y,q.x), fai = acos((ac*ac+
					                                        ab*ab-bc*bc)/(2.0*ac*ab));
					double a0 = th-fai;
					if(sgn(a0+pi)<0)a0+=2*pi;
					double a1 = th+fai;
					if(sgn(a1-pi)>0)a1-=2*pi;
					if(sgn(a0-a1)>0) {
						v.push_back(make_pair(a0,1));
						v.push_back(make_pair(pi,-1));
						v.push_back(make_pair(-pi,1));
						v.push_back(make_pair(a1,-1));
					} else {
						v.push_back(make_pair(a0,1));
						v.push_back(make_pair(a1,-1));
					}
				}
			sort(v.begin(),v.end());
			int cur = 0;
			for(int j = 0; j < v.size(); j++) {
				if(cur && sgn(v[j].first-pre[cur])) {
					ans[cur] += areaarc(v[j].first-pre[cur],c[i].r);
					ans[cur] += 0.5*(Point(c[i].p.x+c[i].r*cos(pre[
					                           cur]),c[i].p.y+c[i].r*sin(pre[cur]))^Point(c
					                                   [i].p.x+c[i].r*cos(v[j].first),c[i].p.y
													   +c[i].r*sin(v[j].first)));
				}
				cur += v[j].second;
				pre[cur] = v[j].first;
			}
		}
		for(int i = 1; i < n; i++)
			ans[i] -= ans[i+1];
	}
};

struct polygons
{
    vector<polygon>p;
    polygons()
    {
        p.clear();
    }
    void clear()
    {
        p.clear();
    }
    void push(polygon q)
    {
        if (sgn(q.getarea()))p.pb(q);
    }
    vector<pair<double,int> >e;
    void ins(Point s,Point t,Point X,int i)
    {
        double r=fabs(t.x-s.x)>eps?(X.x-s.x)/(t.x-s.x):(X.y-s.y)/(t.y-s.y);
        r=min(r,1.0);r=max(r,0.0);
        e.pb(mp(r,i));
    }
    

    double polyareaunion()
    {
        double ans=0.0;
        int c0,c1,c2,i,j,k,w;
        for (i=0;i<p.size();i++)
        {
            if (p[i].getdir()==0)reverse(p[i].p,p[i].p+p[i].n);
        }
        for (i=0;i<p.size();i++)
        {
            for (k=0;k<p[i].n;k++)
            {
                Point &s=p[i].p[k],&t=p[i].p[(k+1)%p[i].n];
                if (!sgn(s^t))continue;
                e.clear();
                e.pb(mp(0.0,1));
                e.pb(mp(1.0,-1));
                for (j=0;j<p.size();j++)if (i!=j)
                {
                    for (w=0;w<p[j].n;w++)
                    {
                        Point a=p[j].p[w],b=p[j].p[(w+1)%p[j].n],c=p[j].p[(w-1+p[j].n)%p[j].n];
                        c0=sgn((t-s)^(c-s));
                        c1=sgn((t-s)^(a-s));
                        c2=sgn((t-s)^(b-s));
                        if (c1*c2<0)ins(s,t,Line(s,t).crosspoint(Line(a,b)),-c2);
                        else if (!c1&&c0*c2<0)ins(s,t,a,-c2);
                        else if (!c1&&!c2)
                        {
                            int c3=sgn((t-s)^(p[j].p[(w+2)%p[j].n]-s));
                            int dp=sgn((t-s)*(b-a));
                            if (dp&&c0)ins(s,t,a,dp>0?c0*((j>i)^(c0<0)):-(c0<0));
                            if (dp&&c3)ins(s,t,b,dp>0?-c3*((j>i)^(c3<0)):c3<0);
                        }
                    }
                }
                sort(e.begin(),e.end());
                int ct=0;
                double tot=0.0,last;
                for (j=0;j<e.size();j++)
                {
                    if (ct==1)tot+=e[j].first-last;
                    ct+=e[j].second;
                    last=e[j].first;
                }
                ans+=s^t*tot;
            }
        }
        return fabs(ans)*0.5;
    }
}ps;
int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);
    double ans=0;
    for (i=0;i<n;i++)
    {
        polygon pl;
       

        pl.input(4);
        ans+=pl.getarea();
        ps.push(pl);
    }
   



    printf("%.12lf\n",ans/ps.polyareaunion());
    return 0;
}