
using namespace std;

const double eps=1e-8;
const double PI=acos(-1);
inline int sgn(double x){return x<-eps?-1:x>eps;}
inline double sqr(double x){return x*x;}


struct Point{
    void read(){scanf("%lf%lf",&x,&y);}
    void out(){printf("Point(%.7f,%.7f)",x,y);}
    Point(double x=0,double y=0):x(x),y(y){}
    bool operator ==(const Point &B)const{return !sgn(x-B.x)&&!sgn(y-B.y);}
    bool operator <(const Point &B)const{return sgn(x-B.x)<0||(sgn(x-B.x)==0&&sgn(y-B.y)<0);}
    Point operator +(Point b)const{return Point(x+b.x,y+b.y);}
    Point operator -(Point b)const{return Point(x-b.x,y-b.y);}
    Point operator *(double p)const{return Point(x*p,y*p);}
    Point operator /(double p)const{return Point(x/p,y/p);}
    double x,y;
};
typedef Point Vector;


double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
double Dis(Point A,Point B){return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));}
double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}

Vector Rotate(Vector a,double rad){return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}

Vector Normal(Vector a){double L=Length(a);return Vector(-a.y/L,a.x/L);}

Vector Trunc(Vector a,double L){return a/Length(a)*L;}

struct Line{
    void read(){A.read();B.read();ang=atan2(B.y-A.y,B.x-A.x);}
    void out(){printf("Line(Point(%.7f,%.7f),Point(%.7f,%.7f))",A.x,A.y,B.x,B.y);}
    Line()=default;
    Line(Point A,Point B):A(A),B(B),ang(atan2(B.y-A.y,B.x-A.x)){}
    bool operator<(const Line &L)const{return ang<L.ang;}
    Point A,B;
    double ang;
};
typedef Line Seg;
void StdLine(Line L,double &A,double &B,double &C){
    A=L.B.y-L.A.y;
    B=L.A.x-L.B.x;
    C=L.B.x*L.A.y-L.A.x*L.B.y;
}
Point id2(Point P,Vector v,Point Q,Vector w){

    double t=Cross(w,P-Q)/Cross(v,w);
    return P+v*t;
}
Point id2(Line L1,Line L2){

    return id2(L1.A,L1.B-L1.A,L2.A,L2.B-L2.A);
}
Line id12(Line L){

    return Line(Point((L.A+L.B)/2),Point((L.A+L.B)/2)+Normal(L.B-L.A));
}
double DisPL(Point P,Line L){
    return fabs(Cross(L.B-L.A,P-L.A))/Dis(L.A,L.B);
}
double DisPS(Point P,Seg S){
    if(S.A==S.B)return Dis(S.A,P);
    Vector v1=S.B-S.A,v2=P-S.A,v3=P-S.B;
    if(sgn(Dot(v1,v2))<0)return Length(v2);
    if(sgn(Dot(v1,v3))>0)return Length(v3);
    return fabs(Cross(v1,v2))/Length(v1);
}
Point id1(Point P,Line L){

    Vector v=L.B-L.A;
    return L.A+v*(Dot(v,P-L.A)/Dot(v,v));
}


int RelationPL(Point P,Line L){
    return sgn(Cross(L.B-L.A,P-L.A));
}


int RelationPS(Point P,Seg S){
    if(P==S.A||P==S.B)return 2;
    return !sgn(Cross(S.A-P,S.B-P))&&Dot(S.A-P,S.B-P)<0;
}


int RelationSS(Seg S1,Seg S2){
    if(!(min(S1.A.x,S1.B.x)<=max(S2.A.x,S2.B.x)&&min(S2.A.x,S2.B.x)<=max(S1.A.x,S1.B.x)&&

         min(S1.A.y,S1.B.y)<=max(S2.A.y,S2.B.y)&&min(S2.A.y,S2.B.y)<=max(S1.A.y,S1.B.y)))return 0;
    int c1=sgn(Cross(S1.B-S1.A,S2.A-S1.A)),c2=sgn(Cross(S1.B-S1.A,S2.B-S1.A)),
        c3=sgn(Cross(S2.B-S2.A,S1.A-S2.A)),c4=sgn(Cross(S2.B-S2.A,S1.B-S2.A));
    if((c1^c2)==-2&&(c3^c4)==-2)return 1;
    if(c1*c2<=0&&c3*c4<=0)return 2;
    return 0;
}
struct Circle{
    Circle()=default;
    Circle(Point C,double r):C(C),r(r){}
    void read(){C.read();scanf("%lf",&r);}
    Point point(double a){return Point(C.x+cos(a)*r,C.y+sin(a)*r);}
    Point C;
    double r;
};


int RelationPC(Point P,Circle C){
    return sgn(Dis(C.C,P)-C.r)+1;
}


int RelationLC(Line L,Circle C){
    return sgn(C.r-DisPL(C.C,L))+1;
}


int RelationCC(Circle C1,Circle C2){
    if(C1.C==C2.C&&C1.r==C2.r)return -1;
    double d=Dis(C1.C,C2.C);
    int cmp=sgn(d-fabs(C1.r-C2.r));
    if(cmp<1)return cmp+1;
    cmp=sgn(d-C1.r-C2.r);
    return cmp+3;
}


int id6(Line L,Circle C,Point &P1,Point &P2){
    Point P=id1(C.C,L);
    double d=sqr(C.r)-sqr(Dis(C.C,P));
    if(sgn(d)<0)return 0;
    if(sgn(d)==0){P1=P2=P;return 1;}
    d=sqrt(d);

    Vector v=(L.B-L.A)/Dis(L.A,L.B);
    P1=P+v*d;P2=P-v*d;
    return P1==P2?1:2;
}


int id9(Circle C1,Circle C2,Point &P1,Point &P2){
    if(C1.C==C2.C&&C1.r==C2.r)return -1;
    double d=Dis(C1.C,C2.C);
    if(sgn(C1.r+C2.r-d)<0||sgn(d-fabs(C1.r-C2.r))<0)return 0;
    double h=(d+(sqr(C1.r)-sqr(C2.r))/d)/2;
    Vector v=C2.C-C1.C;
    Point P=C1.C+Trunc(v,h);
    h=sqrt(fabs(sqr(C1.r)-sqr(h)));

    P1=P+Normal(v)*h;
    P2=P-Normal(v)*h;
    return (sgn(C1.r+C2.r-d)==0||sgn(d-fabs(C1.r-C2.r))==0||P1==P2)?1:2;
}


int id5(Point P,Circle C,Point &P1,Point &P2){
    int rel=RelationPC(P,C);
    if(rel==0)return 0;
    if(rel==1){P1=P2=P;return 1;}
    double d=Dis(C.C,P),l=C.r*C.r/d,h=sqrt(C.r*C.r-l*l);
    Vector v=P-C.C;
    P1=C.C+Trunc(v,l)+Normal(v)*h;
    P2=C.C+Trunc(v,l)-Normal(v)*h;
    return P1==P2?1:2;
}


int id5(Point P,Circle C,Line &L1,Line &L2){
    int rel=RelationPC(P,C);
    if(rel==0)return 0;
    if(rel==1){
        L1=L2=Line(P,P+Normal(P-C.C));
        return 1;
    }
    double d=Dis(C.C,P),l=C.r*C.r/d,h=sqrt(C.r*C.r-l*l);
    Vector v=P-C.C;
    L1=Line(P,C.C+Trunc(v,l)+Normal(v)*h);
    L2=Line(P,C.C+Trunc(v,l)-Normal(v)*h);
    return 2;
}


int id3(Circle C1,Circle C2,Point *p1,Point *p2){
    int rel=RelationCC(C1,C2);
    if(rel<1)return rel;
    if(C1.r<C2.r){swap(C1,C2);swap(p1,p2);}
    int cnt=0;
    if(rel==1){

        p1[cnt]=p2[cnt]=C1.C+Trunc(C2.C-C1.C,C1.r);
        return ++cnt;
    }
    double d=Dis(C1.C,C2.C),ang=acos((C1.r-C2.r)/d);
    double base=atan2(C2.C.y-C1.C.y,C2.C.x-C1.C.x);
    p1[cnt]=C1.point(base+ang);p2[cnt++]=C2.point(base+ang);
    p1[cnt]=C1.point(base-ang);p2[cnt++]=C2.point(base-ang);
    if(rel==3){p1[cnt]=p2[cnt]=C1.C+Trunc(C2.C-C1.C,C1.r);++cnt;}

    if(rel!=4)return cnt;
    ang=acos((C1.r+C2.r)/d);
    p1[cnt]=C1.point(base+ang);p2[cnt++]=C2.point(base+ang+PI);
    p1[cnt]=C1.point(base-ang);p2[cnt++]=C2.point(base-ang+PI);
    return cnt;
}


Circle id0(Point A,Point B,Point C){
    Line L1=id12(Line(A,B));
    Line L2=id12(Line(B,C));
    Point P=id2(L1,L2);
    return Circle(P,DisPL(P,L1));
}


Circle id8(Point A,Point B,Point C){
    double a=Dis(B,C),b=Dis(A,C),c=Dis(A,B);
    Point P((A*a+B*b+C*c)/(a+b+c));
    return Circle(P,DisPL(P,Line(A,B)));
}

typedef vector<Point> Poly;
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}



double AreaPoly(Poly &p){
    int n=p.size();
    double area=0;
    for(int i=1;i<n-1;++i)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}


int id7(Point A,Poly &p){
    int n=p.size(),wn=0;

    for(int i=0;i<n;++i){
        if(RelationPS(A,Seg(p[i],p[(i+1)%n]))!=0)return -1;
        int k=sgn(Cross(p[(i+1)%n]-p[i],A-p[i]));

        int d1=sgn(p[i].y-A.y),d2=sgn(p[(i+1)%n].y-A.y);
        if(k>0&&d1<=0&&d2>0)++wn;
        if(k<0&&d2<=0&&d1>0)--wn;
    }
    return wn!=0;

}


Poly id11(Poly &p){
    int n=p.size(),m=0;
    Poly ch(n+1);
    sort(p.begin(),p.end());
    for(int i=0;i<n;++i){
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)--m;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i){
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)--m;
        ch[m++]=p[i];
    }
    ch.resize(m>1?m-1:m);

    return ch;
}


Poly id4(Line L,Poly p){
    Poly newpoly;
    int n=p.size();
    Point A=L.A,B=L.B,C,D,ip;
    for(int i=0;i<n;++i){
        C=p[i];D=p[(i+1)%n];
        if(sgn(Cross(B-A,C-A))>=0)newpoly.push_back(C);

        if(!sgn(Cross(B-A,D-C)))continue;

        ip=id2(Line(A,B),Line(C,D));
        if(RelationPS(ip,Seg(C,D))==1)

            newpoly.push_back(ip);
    }
    return newpoly;
}




Poly Halfplane(Line *L,int n){
    sort(L,L+n);
    Point *p=new Point[n];
    Line *q=new Line[n];
    int s=0,t=0;
    q[0]=L[0];
    for(int i=1;i<n;++i){
        while(s<t&&RelationPL(p[t-1],L[i])!=1)--t;
        while(s<t&&RelationPL(p[s],L[i])!=1)++s;
        q[++t]=L[i];
        if(sgn(q[t].ang-q[t-1].ang)==0)if(RelationPL(L[i].A,q[--t])==1)q[t]=L[i];

        if(s<t)p[t-1]=id2(q[t],q[t-1]);
    }
    while(s<t&&RelationPL(p[t-1],q[s])!=1)--t;

    

    if(t-s>1)p[t++]=id2(q[s],q[t]);

    else s=t=0;
    Poly poly(p+s,p+t);
    delete[] p;delete[] q;
    return poly;
}



Poly id10(Poly &pa,Poly &pb){
    int na=pa.size(),nb=pb.size(),tot=0,ia=0,ib=0;
    Vector *va=new Vector[na],*vb=new Vector[nb];
    for(int i=0;i<na;++i)va[i]=pa[(i+1)%na]-pa[i];
    for(int i=0;i<nb;++i)vb[i]=pb[(i+1)%nb]-pb[i];
    Poly p(na+nb+1);
    p[tot++]=pa[0]+pb[0];
    while(ia<na&&ib<nb)p[tot]=p[tot-1]+(Cross(va[ia],vb[ib])>0?va[ia++]:vb[ib++]),++tot;
    while(ia<na)p[tot]=p[tot-1]+va[ia++],++tot;
    while(ib<nb)p[tot]=p[tot-1]+vb[ib++],++tot;
    delete[] va;delete[] vb;
    

    {
        int x=1;
        for(int i=2;i<tot;++i)
            if(sgn(Cross(p[x]-p[x-1],p[i]-p[i-1]))==0)p[x]=p[i];
            else p[++x]=p[i];
        tot=x+1;
    }
    p.resize(tot-1);

    return p;
}

const int N=1e5+10;
int main(){
    Poly a,b,c;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        Point p;
        p.read();
        a.push_back(p);
        p.x=-p.x;p.y=-p.y;
        b.push_back(p);
    }
    a=id11(a);
    b=id11(b);
    c=id10(a,b);
    bool flag=1;
    n=a.size();
    if(n!=c.size())flag=0;
    if(flag){
        double k=Dis(a[0],a[1])/Dis(c[0],c[1]);
        for(int i=0;i<n;++i)
            if(sgn(Dis(a[i],a[(i+1)%n])/Dis(c[i],c[(i+1)%n])-k)!=0||sgn(Cross(a[(i+1)%n]-a[i],c[(i+1)%n]-c[i]))!=0){
                flag=0;break;
            }
    }
    puts(flag?"YES":"NO");
    return 0;
}