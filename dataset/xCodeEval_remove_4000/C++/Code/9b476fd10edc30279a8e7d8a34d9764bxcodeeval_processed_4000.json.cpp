














using namespace std;







for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)









const double EPS =10e-11; 

const double PI = acos(-1);

class id0{
public:
	double vd;
	id0(){ vd=nan(""); }
	id0(const double d){ vd=d; }
	inline id0 operator-()const{ return id0(-vd); }
	inline id0 operator+(const id0 VD)const{ return id0(vd+VD.vd); }
	inline id0 operator-(const id0 VD)const{ return id0(vd-VD.vd); }
	inline id0 operator*(const id0 VD)const{ return id0(vd*VD.vd); }
	inline id0 operator/(const id0 VD)const{ return id0(vd/VD.vd); }
	inline id0 operator+(const double d)const{ return id0(vd+d); }
	inline id0 operator-(const double d)const{ return id0(vd-d); }
	inline id0 operator*(const double d)const{ return id0(vd*d); }
	inline id0 operator/(const double d)const{ return id0(vd/d); }
	inline bool operator< (const id0 VD)const{ return vd+EPS<VD.vd && vd+EPS*abs(vd)<VD.vd; }
	inline bool operator> (const id0 VD)const{ return vd-EPS>VD.vd && vd-EPS*abs(vd)>VD.vd; }
	inline bool operator==(const id0 VD)const{ return !(*this<VD)&&!(*this>VD); }
	inline bool operator!=(const id0 VD)const{ return  (*this<VD)|| (*this>VD); }
	inline bool operator<=(const id0 VD)const{ return !(*this>VD); }
	inline bool operator>=(const id0 VD)const{ return !(*this<VD); }
	inline bool operator< (const double d)const{ return *this< id0(d); }
	inline bool operator> (const double d)const{ return *this> id0(d); }
	inline bool operator==(const double d)const{ return *this==id0(d); }
	inline bool operator!=(const double d)const{ return *this!=id0(d); }
	inline bool operator<=(const double d)const{ return *this<=id0(d); }
	inline bool operator>=(const double d)const{ return *this>=id0(d); }
	inline void operator+=(const id0 VD){ *this=*this+VD; }
	inline void operator-=(const id0 VD){ *this=*this-VD; }
	inline void operator*=(const id0 VD){ *this=*this*VD; }
	inline void operator/=(const id0 VD){ *this=*this/VD; }
	inline friend id0 operator+(const double d,const id0 &VD){ return id0(d+VD.vd); }
	inline friend id0 operator-(const double d,const id0 &VD){ return id0(d-VD.vd); }
	inline friend id0 operator*(const double d,const id0 &VD){ return id0(d*VD.vd); }
	inline friend id0 operator/(const double d,const id0 &VD){ return id0(d/VD.vd); }
	inline friend bool operator< (const double d,const id0 &VD){ return id0(d)< VD; }
	inline friend bool operator> (const double d,const id0 &VD){ return id0(d)> VD; }
	inline friend bool operator==(const double d,const id0 &VD){ return id0(d)==VD; }
	inline friend bool operator<=(const double d,const id0 &VD){ return id0(d)<=VD; }
	inline friend bool operator>=(const double d,const id0 &VD){ return id0(d)>=VD; }
	inline friend std::ostream& operator<<(std::ostream& os,const id0 VD){ os<<VD.vd; return os; }
	inline friend std::istream& operator>>(std::istream& is,id0 &VD){ double d; is>>d; VD=id0(d); return is; }
	inline friend id0 abs(id0 VD){ return (VD.vd<0)?(-VD.vd):VD.vd; }
	inline friend id0 sqr(id0 VD){ return VD.vd*VD.vd; }
	inline friend id0 sqr(double d){ return d*d; }
	inline friend id0 sqrt(id0 VD){ return id0(sqrt(VD.vd)); }
	inline friend bool isnan(id0 VD){ return isnan(VD.vd); }
	
	inline double to_double(){ return vd; }
};

class P{
public:
	id0 x,y;
	P(){ x=nan(""); y=nan(""); }
	P(double _x,double _y){ x=_x; y=_y; }
	P(id0 _x,id0 _y){ x=_x; y=_y; }
	inline P operator-()const{ return P(-x,-y); }
	inline P operator+(const P p)const{ return P(x+p.x,y+p.y); }
	inline P operator-(const P p)const{ return P(x-p.x,y-p.y); }
	inline P operator*(const double d)const{ return P(x*d,y*d); }
	inline P operator/(const double d)const{ return P(x/d,y/d); }
	inline bool operator< (const P &p)const{ return (x<p.x || (x==p.x && y<p.y)); }
	inline bool operator> (const P &p)const{ return (x>p.x || (x==p.x && y>p.y)); }
	inline bool operator==(const P &p)const{ return (x==p.x)&&(y==p.y); }
	inline bool operator!=(const P &p)const{ return (x!=p.x)||(y!=p.y); }
	inline void operator+=(const P &p){ *this=*this+p; }
	inline void operator-=(const P &p){ *this=*this-p; }
	inline void operator*=(const double &p){ *this=*this*p; }
	inline void operator/=(const double &p){ *this=*this/p; }	
	inline id0 operator*(const P p)const{ return x*p.x+y*p.y; }
	inline id0 operator^(const P p)const{ return x*p.y-y*p.x; }
	friend std::ostream& operator<<(std::ostream& os,const P &p){ os<<p.x.vd<<","<<p.y.vd; return os; }
	friend std::istream& operator>>(std::istream& is,P &p){ double _x,_y; is>>_x>>_y; p=P(_x,_y); return is; }
	inline id0 length(){ return sqrt(x*x+y*y); }
	inline friend id0 area(P p0,P p1,P p2){ return abs((p1-p0)^(p2-p0))*0.5; }
	inline friend bool isnan(P p){ return isnan(p.x); }

};

inline id0 dist(P p0,P p1){
	id0 dx=p0.x-p1.x;
	id0 dy=p0.y-p1.y;
	return sqrt(dx*dx+dy*dy);
}

id0 distPL(P l0,P l1,P p){ 
	if(l0==l1) return dist(l0,p);
	return abs((p-l0)^(l1-l0))/dist(l0,l1); 
}




id0 angle(P from0,P to0,P from1,P to1){ 

	P v0=to0-from0,v1=to1-from1;
	id0 res=atan2(v1.y.vd,v1.x.vd)-atan2(v0.y.vd,v0.x.vd);
	if(0<=res) return res;
	return res+PI*2.0;
}
	
bool onLine(P l0,P l1,P p){
	if(p.x<min(l0.x,l1.x) || max(l0.x,l1.x)<p.x) return false;
	if(p.y<min(l0.y,l1.y) || max(l0.y,l1.y)<p.y) return false;
	return distPL(l0,l1,p)==0;
}

P id3(P l0,P l1,id0 x){
	id0 dx=l0.x-l1.x;
	id0 dy=l0.y-l1.y;
	if(dx==0) return P();
	id0 d = 1.0/dx;
	return P(x,x*dy*d+(l0.y-l0.x*dy*d));
}

P id1(P l0,P l1,id0 y){
	id0 dx=l0.x-l1.x;
	id0 dy=l0.y-l1.y;
	if(dy==0) return P();
	id0 d = 1.0/dy;
	return P(y*dx*d+(l0.x-l0.y*dx*d),y);
}


P id2(P a0,P a1,P b0,P b1){
	id0 dx0=a1.x-a0.x;
	id0 dy0=a1.y-a0.y;
	id0 dx1=b1.x-b0.x;
	id0 dy1=b1.y-b0.y;
	id0 den=dx1*dy0-dy1*dx0;
	if(den==0) return P();
	id0 da=((a0.x-b0.x)*dy0-(a0.y-b0.y)*dx0)/den;
	return P(b0.x+dx1*da,b0.y+dy1*da);
}

		
P id4(P a0,P a1,P b0,P b1){
	id0 dx0=a1.x-a0.x;
	id0 dy0=a1.y-a0.y;
	id0 dx1=b1.x-b0.x;
	id0 dy1=b1.y-b0.y;
	id0 den=dx1*dy0-dy1*dx0;
	if(den==0) return P();
	id0 da=((a0.x-b0.x)*dy0-(a0.y-b0.y)*dx0)/den;
	if(da<0 || 1<da) return P();
	P res=P(b0.x+dx1*da,b0.y+dy1*da);
	if(res.x<min(a0.x,a1.x) || max(a0.x,a1.x)<res.x) return P();
	if(res.y<min(a0.y,a1.y) || max(a0.y,a1.y)<res.y) return P();
	return res;
}



class Polygon{
public:
	vector<P> points;
	
	Polygon(){}
	Polygon(vector<P> vec){ points=vec; }
	Polygon(li num){ points.resize(num); }
	friend std::ostream& operator<<(std::ostream& os,Polygon &poly){ rep(i,sz(poly)) os<<poly[i]<<" "; return os; }
	friend std::istream& operator>>(std::istream& is,Polygon &poly){ rep(i,sz(poly)) is>>poly[i]; return is; }
	li size(){ return sz(points); }
	P& operator[](li pos){ return points[pos]; }

	bool onPoly(P p){
		li n=sz(points);
		if(n==0) return false;
		if(onLine(points[n-1],points[0],p)) return true;
		rep(i,n-1)if(onLine(points[i],points[i+1],p)) return true;
		return false;
	}
	
	bool inPoly(P p){
		li n=sz(points),cnt=0;
		if(n==0) return false;
		P right_point=p;
		rep(i,n) right_point.x=max(right_point.x,points[i].x);
		if(right_point==p) return false;
		for(li i=0,next=1;i<n;i++,next++){
			if(next==n) next=0;
			if(0<(points[i].y-p.y)*(points[next].y-p.y)) continue;
			P cross=id4(points[i],points[next],p,right_point);
			if(isnan(cross)) continue;
			cnt++;
			if(cross==p) return true;
			if(points[i].y==p.y && onLine(p,right_point,points[i])){
				li prev=(i==0)?(n-1):(i-1);
				id0 dy0=points[prev].y-p.y;
				id0 dy1=points[next].y-p.y;
				if(dy0*dy1<0) cnt++;
			}
		}
		return (cnt&1);
	}
	
	bool outPoly(P p){ return !inPoly(p); }
	
	void convexReform(){ 

		li k=0;
		if(sz(points)<=1) return;
		sort(points.begin(),points.end());
		vector<P> ans(2*sz(points));
		for(li i=0;i<sz(points);ans[k++]=points[i++]){
			while(2<=k && 0<=((ans[k-1]-ans[k-2])^(points[i]-ans[k-2]))) k--;
		}
		for(li i=sz(points)-2,t=k+1;0<=i;ans[k++]=points[i--]){
			while(t<=k && 0<=((ans[k-1]-ans[k-2])^(points[i]-ans[k-2]))) k--;
		}
		ans.resize(k-1);
		points=ans;
	}
	
	id0 convexArea(){
		id0 res=0;
		rep(i,sz(points)-1) res+=area(points[0],points[i],points[i+1]);
		return res;
	}
};

class Circle{
public:
	P center;
	id0 radius;
	
	Circle(P _center,id0 _r){ center=_center; radius=_r; };
	Circle(P p0,P p1,P p2){ 
		if(p0==p1){ center=(p0+p2)*0.5; radius=dist(p0,p2)*0.5; return; }
		if(p0==p2){ center=(p0+p1)*0.5; radius=dist(p0,p2)*0.5; return; }
		if(p1==p2){ center=(p0+p2)*0.5; radius=dist(p0,p2)*0.5; return; }
		P mid0=(p0+p1)*0.5;
		P mid1=(p0+p2)*0.5;
		P _mid0=mid0+P((p1-p0).y,(p0-p1).x);
		P _mid1=mid1+P((p2-p0).y,(p0-p2).x);
		center=id2(mid0,_mid0,mid1,_mid1);
		radius=dist(center,p0);
	}
};







id0 res=10e100;
void cal(li num,vector<P> &base,li n){
	vector<id0> sum(n*2+5);
	sum[0]=0;
	rep(i,n*2-1) sum[i+1]=sum[i]+area(base[num],base[i%n],base[(i+1)%n]);
	li right=0;
	rep(i,n){
		while(angle(base[right],base[right+1],base[i],base[i+1])*2.0<PI) right++;
		id0 d=area(base[num],base[i],base[right])-(sum[right]-sum[i]);
		id0 dis=distPL(base[i],base[i+1],base[right]);
		d+=dis*dist(base[i],base[right])*cos(angle(base[i],base[right],base[i],base[i+1]).to_double())*0.5;
		res=min(res,d);
	}
}



int main(){
	li n;
	cin>>n;
	Polygon poly(n);
	rep(i,n) cin>>poly[i];
	rep(i,n) swap(poly[i],poly[rand()%n]);
	rep(stage,2){
		rep(i,sz(poly)) poly[i].x=-poly[i].x;
		poly.convexReform();
		n=sz(poly);
		vector<P> base(n*2);
		rep(i,n) base[i+n]=base[i]=poly[i];
		cal(0,base,n);
		li best=0;
		rep(i,n)if(base[best].x<base[i].x) best=i;
		cal(best,base,n);
	}
	printf("%0.20lf\n",res.to_double());
}






