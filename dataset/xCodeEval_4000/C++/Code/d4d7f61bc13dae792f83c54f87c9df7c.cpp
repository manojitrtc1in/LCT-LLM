#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000
const double PI = 2.0*acos(0.0);
double EPS = 1e-9; 


struct PT
{
    double x,y;
    double length() {return sqrt(x*x+y*y);}
    int normalize() {
    

        double l = length();
        if(fabs(l)<EPS) return -1;
        x/=l; y/=l;
        return 0;
    }   
    PT operator-(PT a) {
        PT r;
        r.x=x-a.x; r.y=y-a.y;
        return r;
    }   
    PT operator+(PT a) {
        PT r;
        r.x=x+a.x; r.y=y+a.y;
        return r;
    }
    PT operator*(double sc) {
        PT r;
        r.x=x*sc; r.y=y*sc;
        return r;
    }
};

bool operator<(const PT& a,const PT& b) {
    if(fabs(a.x-b.x)<EPS) return a.y<b.y;
    return a.x<b.x;
}

double dist(PT& a, PT& b) {
    

    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double dot(PT& a, PT& b) {
    

    return(a.x*b.x+a.y*b.y);
}






int sideSign(PT& p1,PT& p2,PT& p3) {
    

    double sg = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y - p3.y)*(p2.x-p3.x);
    if(fabs(sg)<EPS) return 0;
    if(sg>0)return 1;
    return -1;
}

bool better(PT& p1,PT& p2,PT& p3) {
    

    double sg = (p1.y - p3.y)*(p2.x-p3.x)-(p1.x-p3.x)*(p2.y-p3.y);
    

    if(fabs(sg)<EPS) {
        if(dist(p3,p1)>dist(p3,p2))return true;
        else return false;
    }
    if(sg<0) return true;
    return false;
}


void vex(vector<PT>& vin,vector<PT>& vout) {
    vout.clear();
    int n=vin.size();
    int st=0;
    int i;
    for(i=1;i<n;i++) if(vin[i]<vin[st]) st=i;
    vector<int> used;
    

    used.push_back(st);
    int idx=st; int next;
    do{
        next=0;
        for(i=1;i<n;i++)
        if(better(vin[i],vin[next],vin[idx]))next=i;
        idx=next;
        used.push_back(idx);
    }while(idx!=st);
    for(i=0;i+1<(int)used.size();i++) vout.push_back(vin[used[i]]);
}


void vex2(vector<PT> vin,vector<PT>& vout) {
    

    vout.clear();
    int n=vin.size();
    sort(vin.begin(),vin.end());
    PT stk[MAX_SIZE];
    int pstk, i;
    

    stk[0] = vin[0];
    stk[1] = vin[1];
    pstk = 2;
    for(i=2; i<n; i++) {
        if(dist(vin[i], vin[i-1])<EPS) continue;
        while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2])) pstk--;
        stk[pstk] = vin[i];
        pstk++;
    }
    for(i=0; i<pstk; i++) vout.push_back(stk[i]);
    

    for(i=0; i<n; i++) {
        vin[i].y = -vin[i].y;
        vin[i].x = -vin[i].x;
    }
    sort(vin.begin(), vin.end());
    stk[0] = vin[0];
    stk[1] = vin[1];
    pstk = 2;
    for(i=2; i<n; i++) {
        if(dist(vin[i], vin[i-1])<EPS) continue;
        while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2])) pstk--;
        stk[pstk] = vin[i];
        pstk++;
    }
    for(i=1; i<pstk-1; i++) {
        stk[i].x= -stk[i].x; 

        stk[i].y= -stk[i].y;
        vout.push_back(stk[i]);
    }
}

int isConvex(vector<PT>& v) {
    

    

    

    

    

    int i,j,k;
    int c1=0; int c2=0; int c0=0;
    int n=v.size();
    for(i=0;i<n;i++) {
        j=(i+1)%n;
        k=(j+1)%n;
        int s=sideSign(v[i], v[j], v[k]);
        if(s==0) c0++;
        if(s>0) c1++;
        if(s<0) c2++;
    }
    if(c1 && c2) return 0;
    if(c0) return 2;
    return 1;
}






double trap(PT a, PT b) {
    return (0.5*(b.x - a.x)*(b.y + a.y));
}

double area(vector<PT> &vin) {
    

    int n = vin.size();
    double ret = 0.0;
    for(int i = 0; i < n; i++) ret += trap(vin[i], vin[(i+1)%n]);
    return fabs(ret);
}

double peri(vector<PT> &vin) {
    

    int n = vin.size();
    double ret = 0.0;
    for(int i = 0; i < n; i++) ret += dist(vin[i], vin[(i+1)%n]);
    return ret;
}

double triarea(PT a, PT b, PT c) {
    return fabs(trap(a,b)+trap(b,c)+trap(c,a));
}

double height(PT a, PT b, PT c) {
    

    double s3 = dist(c, b);
    double ar=triarea(a,b,c);
    return(2.0*ar/s3);
}






int intersection( PT p1, PT p2, PT p3, PT p4, PT &r ) {
    

    

    double d = (p4.y - p3.y)*(p2.x-p1.x) - (p4.x - p3.x)*(p2.y - p1.y);
    if( fabs( d ) < EPS ) return -1;
    

    double ua;
    ua = (p4.x - p3.x)*(p1.y-p3.y) - (p4.y-p3.y)*(p1.x-p3.x);
    ua /= d;
    

    

    r = p1 + (p2-p1)*ua;
    return 0;
}

void closestpt( PT p1, PT p2, PT p3, PT &r ) {
    

    if( fabs( triarea( p1, p2, p3 ) ) < EPS ) { r = p3; return; }
    PT v = p2-p1;
    v.normalize();
    double pr; 

    pr = (p3.y-p1.y)*v.y + (p3.x-p1.x)*v.x;
    r = p1+v*pr;
}

int hcenter( PT p1, PT p2, PT p3, PT& r ) {
    

    if( triarea( p1, p2, p3 ) < EPS ) return -1;
    PT a1, a2;
    closestpt( p2, p3, p1, a1 );
    closestpt( p1, p3, p2, a2 );
    intersection( p1, a1, p2, a2, r );
    return 0;
}

int center( PT p1, PT p2, PT p3, PT& r ) {
    

    if( triarea( p1, p2, p3 ) < EPS ) return -1;
    PT a1, a2, b1, b2;
    a1 = (p2+p3)*0.5;
    a2 = (p1+p3)*0.5;
    b1.x = a1.x - (p3.y-p2.y);
    b1.y = a1.y + (p3.x-p2.x);
    b2.x = a2.x - (p3.y-p1.y);
    b2.y = a2.y + (p3.x-p1.x);
    intersection( a1, b1, a2, b2, r );
    return 0;
}

int bcenter( PT p1, PT p2, PT p3, PT& r ) {
    

    if( triarea( p1, p2, p3 ) < EPS ) return -1;
    double s1, s2, s3;
    s1 = dist( p2, p3 );
    s2 = dist( p1, p3 );
    s3 = dist( p1, p2 );
    double rt = s2/(s2+s3);
    PT a1,a2;
    a1 = p2*rt+p3*(1.0-rt);
    rt = s1/(s1+s3);
    a2 = p1*rt+p3*(1.0-rt);
    intersection( a1,p1, a2,p2, r );
    return 0;
}






double angle(PT& p1, PT& p2, PT& p3) {
    

    PT va = p2-p1;
    va.normalize();
    PT vb; vb.x=-va.y; vb.y=va.x;
    PT v = p3-p1;
    double x,y;
    x=dot(v, va);
    y=dot(v, vb);
    return(atan2(y,x));
}

double angle(double a, double b, double c) {
    

    

    double cs=(b*b+c*c-a*a)/(2.0*b*c);
    return(acos(cs));
}

void rotate(PT p0, PT p1, double a, PT& r) {
    

    

    p1 = p1-p0;
    r.x = cos(a)*p1.x-sin(a)*p1.y;
    r.y = sin(a)*p1.x+cos(a)*p1.y;
    r = r+p0;
}

void reflect(PT& p1, PT& p2, PT p3, PT& r) {
    

    if(dist(p1, p3)<EPS) {r=p3; return;}
    double a=angle(p1, p2, p3);
    r=p3;
    rotate(p1, r, -2.0*a, r);
}






int pAndSeg(PT& p1, PT& p2, PT& p) {
    

    

    double s=triarea(p, p1, p2);
    if(s>EPS) return(0);
    double sg=(p.x-p1.x)*(p.x-p2.x);
    if(sg>EPS) return(-1);
    sg=(p.y-p1.y)*(p.y-p2.y);
    if(sg>EPS) return(-1);
    return(1);
}

int lineAndCircle(PT& oo, double r, PT& p1, PT& p2, PT& r1, PT& r2) {
    

    

    PT m;
    closestpt(p1,p2,oo,m);
    PT v = p2-p1;
    v.normalize();
    double r0=dist(oo, m);
    if(r0>r+EPS) return -1;
    if(fabs(r0-r)<EPS) {
        r1=r2=m;
        return 1;
    }
    double dd = sqrt(r*r-r0*r0);
    r1 = m-v*dd; r2 = m+v*dd;
    return 0;
}
int CAndC(PT o1, double r1, PT o2, double r2, PT& q1, PT& q2) {
    

    

    

    double r=dist(o1,o2);
    if(r1<r2) { swap(o1,o2); swap(r1,r2); }
    if(r<EPS) return(-1);
    if(r>r1+r2+EPS) return(-1);
    if(r<r1-r2-EPS) return(-1);
    PT v = o2-o1; v.normalize();
    q1 = o1+v*r1;
    if(fabs(r-r1-r2)<EPS || fabs(r+r2-r1)<EPS) { q2=q1; return(1); }
    double a=angle(r2, r, r1);
    q2=q1;
    rotate(o1, q1, a, q1);
    rotate(o1, q2, -a, q2);
    return 0;
}
int pAndPoly(vector<PT> pv, PT p) {
    

    

    int i, j;
    int n=pv.size();
    pv.push_back(pv[0]);
    for(i=0;i<n;i++)
    if(pAndSeg(pv[i], pv[i+1], p)==1) return(-1);
    for(i=0;i<n;i++)
    pv[i] = pv[i]-p;
    p.x=p.y=0.0;
    double a, y;
    while(1) {
        a=(double)rand()/10000.00;
        j=0;
        for(i=0;i<n;i++) {
            rotate(p, pv[i], a, pv[i]);
            if(fabs(pv[i].x)<EPS) j=1;
        }
        if(j==0) {
            pv[n]=pv[0];
            j=0;
            for(i=0;i<n;i++) if(pv[i].x*pv[i+1].x < -EPS) {
                y=pv[i+1].y-pv[i+1].x*(pv[i].y-pv[i+1].y)/(pv[i].x-pv[i+1].x);
                if(y>0) j++;
            }
            return(j%2);
        }
    }
    return 1;
}

void show(PT& p) {
    cout<<"("<<p.x<<", "<<p.y<<")"<<endl;
}

void show(vector<PT>& p) {
    int i,n=p.size();
    for(i=0;i<n;i++) show(p[i]);
    cout<<":)"<<endl;
}

void cutPoly(vector<PT>& pol, PT& p1, PT& p2, vector<PT>& pol1, vector<PT>& pol2) {
    

    

    vector<PT> pp,pn;
    pp.clear(); pn.clear();
    int i, sg, n=pol.size();
    PT q1,q2,r;
    for(i=0;i<n;i++) {
        q1=pol[i]; q2=pol[(i+1)%n];
        sg=sideSign(p1, p2, q1);
        if(sg>=0) pp.push_back(q1);
        if(sg<=0) pn.push_back(q1);
        if(intersection(p1, p2, q1, q2,r)>=0) {
            if(pAndSeg(q1, q2, r)==1) {
                pp.push_back(r);
                pn.push_back(r);
            }
        }
    }
    pol1.clear(); pol2.clear();
    if(pp.size()>2) vex2(pp, pol1);
    if(pn.size()>2) vex2(pn, pol2);
    

    

}








int PInterP(vector<PT>& p1, vector<PT>& p2, vector<PT>& p3) {
    vector<PT> pts;
    PT pp;
    pts.clear();
    int m=p1.size();
    int n=p2.size();
    int i, j;
    for(i=0;i<m;i++) if(pAndPoly(p2, p1[i])!=0) pts.push_back(p1[i]);
    for(i=0;i<n;i++) if(pAndPoly(p1, p2[i])!=0) pts.push_back(p2[i]);
    if(m>1 && n>1) for(i=0;i<m;i++) for(j=0;j<n;j++) if(intersection(p1[i], p1[(i+1)%m], p2[j], p2[(j+1)%n], pp)==0) {
        

        if(pAndSeg(p1[i], p1[(i+1)%m], pp)!=1) continue;
        if(pAndSeg(p2[j], p2[(j+1)%n], pp)!=1) continue;
        pts.push_back(pp);
    }
    if(pts.size()<=1) {
        p3.resize(1);
        p3[0].x=p3[0].y=0.0;
        return(1);
    }
    

    vex2(pts, p3); 

    return(0);
}

PT A[3], B[3];

bool touch(int i, int j) {
    bool flag=false;
    PT X, Y, Z;
    if (dist(A[i], A[j])<EPS) X=A[i], Y=B[i], Z=B[j], flag=true;
    if (dist(A[i], B[j])<EPS) X=A[i], Y=B[i], Z=A[j], flag=true;
    if (dist(B[i], A[j])<EPS) X=B[i], Y=A[i], Z=B[j], flag=true;
    if (dist(B[i], B[j])<EPS) X=B[i], Y=A[i], Z=A[j], flag=true;
    if (!flag) return false;
    double ang=fabs(angle(X, Y, Z));
    return ang>EPS and ang<PI/2+EPS;
}

bool f(int i, int j) {
    PT X;
    bool flag=false;
    if (pAndSeg(A[i], B[i], A[j])==1) X=A[j], flag=true;
    if (pAndSeg(A[i], B[i], B[j])==1) X=B[j], flag=true;
    if (!flag) return false;
    double da=dist(A[i], X), db=dist(B[i], X);
    

    

    return min(da, db)/max(da, db)>0.25-EPS;
}

void solve() {
    for (int i=0; i<3; i++) scanf("%lf %lf %lf %lf", &A[i].x, &A[i].y, &B[i].x, &B[i].y);
    bool ans=false;
    for (int i=0; i<3; i++) for (int j=i+1; j<3; j++) if (touch(i, j)) for (int k=0; k<3; k++) if (k!=i and k!=j and f(i, k) and f(j, k)) ans=true;
    puts(ans?"YES":"NO");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
