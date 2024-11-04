#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
#define db double
#define pb push_back
#define mem(a, b) memset(a, b, sizeof (a))
using namespace std;


const db eps = 1e-10;
const db pi = acos(-1);
int sign(db x){ if(fabs(x) < eps) return 0;  return x > 0 ? 1 : -1; }
int cmp(db k1, db k2){ return sign(k1-k2); }
int inmid(db k1, db k2, db k3){ return sign(k2-k1)*sign(k3-k1) <= 0; }

int intersect(db l1,db r1,db l2,db r2){

    if(l1>r1) swap(l1,r1); if(l2>r2) swap(l2,r2); return cmp(r1,l2)!=-1 && cmp(r2,l1)!=-1;
}


struct point{
	db x, y;
	point(){}
	point(db k1, db k2){ x = k1, y = k2; }
	point operator + (const point &k1) const { return point(x+k1.x, y+k1.y); }

	point operator - (const point &k1) const { return point(x-k1.x, y-k1.y); }

	point operator * (db k1) const { return (point){x*k1, y*k1}; }

    point operator / (db k1) const { return (point){x/k1, y/k1}; }

    int operator == (const point &k1) const { return cmp(x,k1.x)==0 && cmp(y,k1.y)==0; }

    point turn(db k1){return (point){x*cos(k1)-y*sin(k1), x*sin(k1)+y*cos(k1)};}

    point turn90(){return (point){-y, x};}

    bool operator < (const point k1) const{
        int a = cmp(x, k1.x);
        if(a == -1) return 1; else if(a == 1) return 0; else return cmp(y,k1.y)==-1;
    }

    db len(){ return sqrt(x*x+y*y); }

    db len2(){ return x*x+y*y; }

    point unit(){ db k = len(); return point(x/k, y/k); }
    db angle() { return atan2(y, x); }
    point getdel(){if (sign(x)==-1||(sign(x)==0&&sign(y)==-1)) return (*this)*(-1); else return (*this);}
    

    int getp() const { return sign(y)==1 || (sign(y)==0&&sign(x)==-1); }
	

    void scan(){ scanf("%lf%lf", &x, &y); };
    void print(){ printf("%.3f %.3f\n", x, y); }
};
int inmid(point k1, point k2, point k3){ return inmid(k1.x,k2.x,k3.x) && inmid(k1.y,k2.y,k3.y); }

point midpo(point k1, point k2){ return (k1+k2)/2; }

db dis2(point k1, point k2){ return (k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y); }
db dis(point k1, point k2){ return sqrt(dis2(k1, k2)); }
db cross(point k1, point k2){ return k1.x*k2.y - k1.y*k2.x; }

db dot(point k1, point k2){ return k1.x*k2.x + k1.y*k2.y; }

db rad(point k1, point k2){ return atan2(cross(k1,k2), dot(k1,k2)); }

int compareangle (point k1,point k2){

    return k1.getp()<k2.getp() || (k1.getp()==k2.getp() && sign(cross(k1,k2))>0);
}
int clockwise(point k1,point k2,point k3){ return sign(cross(k2-k1,k3-k1)); }



struct line{

    point p[2];
    line(){}
    line(point k1,point k2){p[0]=k1; p[1]=k2;}
    point& operator [] (int k){return p[k];}
    int include(point k){ return sign(cross(p[1]-p[0],k-p[0]))>=0; }

    point dir(){return p[1]-p[0];}

    line push(){ 

        point delta=(p[1]-p[0]).turn90().unit()*eps;
        return {p[0]-delta, p[1]-delta};
    }
};
struct segment{
    point p[2];
    segment(){}
    segment(point a, point b){ p[0]= a, p[1] = b; }
    point& operator [] (int k){ return p[k]; }
};
point proj(point q, point k1, point k2){ point k=k2-k1; return k1+k*(dot(q-k1,k)/k.len2()); }

point reflect(point q, point k1, point k2){ return proj(q,k1,k2)*2-q; }

int checkons(point q,point k1,point k2){ return inmid(q,k1,k2) && sign(cross(k1-q, k2-k1))==0; }

int parallel(line k1,line k2){ return sign(cross(k1.dir(),k2.dir()))==0; }

int samedir(line k1,line k2){ return parallel(k1,k2)&&sign(dot(k1.dir(),k2.dir()))==1; }

int operator < (line k1,line k2){

    if (samedir(k1,k2)) return k2.include(k1[0]);
    return compareangle(k1.dir(),k2.dir());
}
int checkll(point k1,point k2,point k3,point k4){

    return cmp(cross(k3-k1,k4-k1),cross(k3-k2,k4-k2))!=0;
}
int checkll(line k1,line k2){ return checkll(k1[0],k1[1],k2[0],k2[1]); }

point getll(point k1,point k2,point k3,point k4){

    db w1=cross(k1-k3,k4-k3),w2=cross(k4-k3,k2-k3); return (k1*w2+k2*w1)/(w1+w2);
}
point getll(line k1,line k2){ return getll(k1[0],k1[1],k2[0],k2[1]); }

int checkls(point k1, point k2, point k3, point k4){

    return sign(cross(k1-k3, k2-k3)) * sign(cross(k1-k4, k2-k4)) <= 0;
}
int checkss(point k1,point k2,point k3,point k4){

    return intersect(k1.x,k2.x,k3.x,k4.x)&&intersect(k1.y,k2.y,k3.y,k4.y) &&
    sign(cross(k3-k1,k4-k1))*sign(cross(k3-k2,k4-k2))<=0 &&
    sign(cross(k1-k3,k2-k3))*sign(cross(k1-k4,k2-k4))<=0;
}
int checkss(segment k1, segment k2){ return checkss(k1[0], k1[1], k2[0], k2[1]); }
int strictcheckss(point k1, point k2, point k3, point k4){

    return sign(cross(k3-k1,k4-k1))*sign(cross(k3-k2,k4-k2))<0 &&
    sign(cross(k1-k3,k2-k3))*sign(cross(k1-k4,k2-k4))<0;
}
int strictcheckss(segment k1, segment k2){ return strictcheckss(k1[0], k1[1], k2[0], k2[1]); }
db displ(point q, point k1, point k2){

    return fabs(cross(k2-k1, q-k1)) / (k2-k1).len();
}
db displ(point q, line l){ return displ(q, l[0], l[1]); }
db disps(point q,point k1,point k2){

    point k3 = proj(q,k1,k2);
    if (inmid(k3,k1,k2)) return dis(q, k3); else return min(dis(q, k1),dis(q, k2));
}
db disps(point q, segment k1){ return disps(q, k1[0], k1[0]); }
db disss(point k1,point k2,point k3,point k4){

    if (checkss(k1,k2,k3,k4)) return 0;
    else return min(min(disps(k3,k1,k2), disps(k4,k1,k2)), min(disps(k1,k3,k4), disps(k2,k3,k4)));
}
db disss(segment k1, segment k2){ return disss(k1[0], k1[1], k2[0], k2[1]); }


struct circle{
    point o; db r;
    circle(){}
    circle(point _o, db _r){ o = _o, r = _r; }
    bool include(point k){ return cmp(dis(o, k), r) <= 0; }

};
vector<point> getcl(circle k1,point k2,point k3){ 

    point k=proj(k2,k3,k1.o);
    db d=k1.r*k1.r-(k-k1.o).len2();
    if (sign(d)==-1) return {};
    point del=(k3-k2).unit()*sqrt(max((db)0.0, d));
    vector<point>res;
    res.pb(k-del);
    res.pb(k+del);
    return res;
}
int checkposcc(circle k1,circle k2){

    if (cmp(k1.r,k2.r)==-1) swap(k1,k2);
    db d=dis(k1.o,k2.o);  int w1=cmp(d,k1.r+k2.r),w2=cmp(d,k1.r-k2.r);
    if (w1>0) return 4;

    else if (w1==0) return 3;

    else if (w2>0) return 2; 

    else if (w2==0) return 1; 

    else return 0;

}
vector<point> getcc(circle k1,circle k2){

    int pd=checkposcc(k1,k2);
    if(pd==0||pd==4) return {};
    db a=(k2.o-k1.o).len2();
    db cosA=(k1.r*k1.r+a-k2.r*k2.r)/(2*k1.r*sqrt(max(a,(db)0.0)));
    db b=k1.r*cosA;
    db c=sqrt(max((db)0.0,k1.r*k1.r-b*b));
    point k=(k2.o-k1.o).unit(), m=k1.o+k*b, del=k.turn90()*c;
    vector<point>res;
    res.pb(m-del);
    res.pb(m+del);
    return res;
}
vector<point> tangentcp(circle k1,point k2){

    db a=(k2-k1.o).len(),b=k1.r*k1.r/a,c=sqrt(max((db)0.0,k1.r*k1.r-b*b));
    point k=(k2-k1.o).unit(),m=k1.o+k*b,del=k.turn90()*c;
    vector<point>res;
    res.pb(m-del);
    res.pb(m+del);
    return res;
}
db circleinsarea(circle k1,point k2,point k3){

    point k=k1.o; k1.o=k1.o-k; k2=k2-k; k3=k3-k;
    int pd1=k1.include(k2),pd2=k1.include(k3);
    vector<point>A=getcl(k1,k2,k3);
    if (pd1>=0){

        if (pd2>=0) return cross(k2,k3)/2;

        else return k1.r*k1.r*rad(A[1],k3)/2+cross(k2,A[1])/2;

    } else if (pd2>=0){

        return k1.r*k1.r*rad(k2,A[0])/2+cross(A[0],k3)/2;
    }else {

        int pd=cmp(k1.r,disps(k1.o,k2,k3));
        if (pd<=0) return k1.r*k1.r*rad(k2,k3)/2;

        else return cross(A[0],A[1])/2+k1.r*k1.r*(rad(k2,A[0])+rad(A[1],k3))/2;

    }
}
circle getexcir2(point k1, point k2){
    point c = midpo(k1, k2);
    db r = dis(c, k1);
    return circle(c, r);
}
circle getexcir3(point k1, point k2, point k3){
    point c = getll(midpo(k1, k2), (k1-k2).turn90()+midpo(k1, k2), midpo(k1, k3), (k1-k3).turn90()+midpo(k1, k3));
    db r = dis(c, k1);
    return circle(c, r);
}
circle mincircover(vector<point>A){

    random_shuffle(A.begin(), A.end()); int n = A.size();
    circle now = circle(A[0], 0);
    for(int i = 0; i < n; i++){
        if(!now.include(A[i])){
            now = circle(A[i], 0);
            for(int j = 0; j < i; j++){
                if(!now.include(A[j])){
                    now = getexcir2(A[i], A[j]);
                    for(int k = 0; k < j; k++){
                        if(!now.include(A[k])){
                            now = getexcir3(A[i], A[j], A[k]);
                        }
                    }
                }
            }
        }
    }
    return now;
}


db polyarea(vector<point>A){ 

    db ans = 0;
    for(int i=0;i<A.size();i++) ans += cross(A[i],A[(i+1)%A.size()]);
    return ans/2;
}
db polyperimeter(vector<point>A){ 

    db ans = 0;
    for(int i = 0; i < A.size(); i++) ans += dis(A[i], A[(i+1)%A.size()]);
    return ans;
}
point polyfocus(vector<point>A){ 

    int n = A.size();
    db sumx= 0, sumy = 0, sumarea = 0, area;
    for(int i = 1; i+1 < n; i++){
        area = cross(A[i]-A[0], A[i+1]-A[0])/2.0;
        sumarea += area;
        sumx += (A[0].x+A[i].x+A[i+1].x)*area;
        sumy += (A[0].y+A[i].y+A[i+1].y)*area;
    }
    return point(sumx/sumarea/3.0, sumy/sumarea/3.0);
}
int contain(vector<point>A, point q){ 

    int pd=0; A.push_back(A[0]);
    for (int i=1;i<A.size();i++){
        point u=A[i-1], v=A[i];
        if (checkons(q,u,v)) return 1;
        if (cmp(u.y,v.y)>0) swap(u,v);
        if (cmp(u.y,q.y)>=0||cmp(v.y,q.y)<0) continue;
        if (sign(cross(u-v,q-v))<0) pd^=1;
    }
    return pd<<1;
    
}
int checkconvex(vector<point>A){ 

    int n=A.size(); A.pb(A[0]); A.pb(A[1]);
    for (int i=0;i<n;i++) if(sign(cross(A[i+1]-A[i],A[i+2]-A[i]))==-1) return 0;
    return 1;
}
vector<point> convexhull(vector<point>A, int flag=1){ 

    int n=A.size(); vector<point>ans(n*2);
    sort(A.begin(), A.end());
    int now=-1;
    for(int i=0;i<n;i++){

        while(now>0 && sign(cross(ans[now]-ans[now-1], A[i]-ans[now-1])) < flag) now--;
        ans[++now]=A[i];
    }
    int pre=now;
    for(int i=n-2;i>=0;i--){

        while(now>pre && sign(cross(ans[now]-ans[now-1], A[i]-ans[now-1])) < flag) now--;
        ans[++now]=A[i];
    }
    ans.resize(now);

    return ans;
}
vector<point> convexcut(vector<point>A,point k1,point k2){

    int n=A.size(); A.push_back(A[0]); vector<point>ans;
    for(int i=0;i<n;i++){
        int w1=clockwise(k1,k2,A[i]), w2=clockwise(k1,k2,A[i+1]);
        if (w1>=0) ans.push_back(A[i]);
        if (w1*w2<0) ans.push_back(getll(k1,k2,A[i],A[i+1]));
    }
    return ans;
}
vector<point> gethalf(vector<line> L){ 

    int n = L.size();
    sort(L.begin(), L.end());
    int first = 0, last = 0;

    line *q = new line[n];

    point *p = new point[n];

    q[last] = L[0];

    for(int i = 0; i < n; i++){
        while(first < last && !L[i].include(p[last-1])) last--;
        while(first < last && !L[i].include(p[first])) first++;
        q[++last] = L[i];
        if(samedir(q[last], q[last-1])) last--;
        if(first < last) p[last-1] = getll(q[last], q[last-1]);
    }
    while(first < last && !q[first].include(p[last-1])) last--;
    vector<point>ans;
    if(last - first <= 1) return ans;
    p[last] = getll(q[last], q[first]);
    for(int i = first; i <= last; i++) ans.pb(p[i]);
    return ans;
}

point c1, c2;
db convexdiameter(vector<point>A){

    int n = A.size();
    int now = 1;
    db res = -1;
    for(int i = 0; i < n; i++){
        while(cross(A[i]-A[(i+1)%n], A[i]-A[(now+1)%n]) > cross(A[i]-A[(i+1)%n], A[i]-A[now])){
            now = (now+1)%n;
        }
        if(dis(A[now], A[i]) > res){
            res = dis(A[now], A[i]);
            c1 = A[now];
            c2 = A[i];
        }
    }
    return res;
}
db maxtriangle(vector<point>A){

    int m = A.size();
    int a = 1, b = 2;
    db res = 0;
    for(int i = 0; i < m; i++){
		while(cross(A[a]-A[i], A[(b+1)%m]-A[i]) > cross(A[a]-A[i], A[b]-A[i]))
			b = (b + 1) % m;
		res = max(res, cross(A[a]-A[i], A[b]-A[i]) / 2.0);
		while(cross(A[(a+1)%m]-A[i], A[b]-A[i]) > cross(A[a]-A[i], A[b]-A[i]))
			a = (a + 1) % m;
		res = max(res, cross(A[a]-A[i], A[b]-A[i]) / 2.0);
	}
    return res;
}

int n;
vector<point>poly;

int main(){
    cin >> n;
    point tmp;
    for(int i = 0; i < n; i++){
        tmp.scan();
        poly.pb(tmp);
    }
    db ans = -1;
    for(int i = 0; i < n; i++){
        point l = poly[(i-1+n)%n];
        point r = poly[(i+1)%n];
        db d = disps(poly[i], l, r)/2;
        if(ans < 0) ans = d;
        else ans = min(ans, d);
    }
    printf("%.11f\n", ans);
}
